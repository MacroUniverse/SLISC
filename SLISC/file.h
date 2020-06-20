#pragma once
#include "time.h"
#include "arithmetic.h"
#include "linux.h"
#include <sstream>
#include <fstream>
#ifdef SLS_HAS_FILESYSTEM
#include <filesystem>
#include "search.h"
#endif
#include <sys/types.h> // for time_stamp
#include <sys/stat.h> // for time_stamp

namespace slisc {

using std::stringstream;

inline void file_list(vecStr_O names, Str_I path, Bool_I append = false);
inline void read(ifstream &fin, Str_O str);
inline void write(ofstream &fout, Str_I str);

#ifdef SLS_HAS_FILESYSTEM
// check if a file exist on Windws (case sensitive)
inline Bool file_exist_case(Str_I fname)
{
    Long ind = max((Long)fname.rfind('/'), (Long)fname.rfind('\\'));
    Str path, name;
    if (ind < 0) {
        path = "./";
        name = fname;
    }
    else {
        path = fname.substr(0, ind + 1);
        name = fname.substr(ind + 1);
    }
    vecStr names;
    file_list(names, path);
    if (search(name, names) >= 0)
        return true;
    else
        return false;
}
#endif

// check if a file exist, default is case sensitive
inline Bool file_exist(Str_I fname, Bool_I case_sens = true) {
#ifndef SLS_HAS_FILESYSTEM
    ifstream f(fname);
    return f.good();
#else
    if (case_sens)
        return file_exist_case(fname);
    else {
        ifstream f(fname);
        return f.good();
    }
#endif
}

// remove a file with error handling
inline void file_remove(Str_I fname)
{
    if (remove(fname.c_str()))
        SLS_ERR("failed to remove, file being used? (" + fname + ")");
}

// check if directory exist
// `path` must end with '/'
inline Bool dir_exist(Str_I path)
{
    ofstream file;
    file.open(path + "/sls_test_if_dir_exist");
    if (file.good()) {
        file.close();
        file_remove(path + "/sls_test_if_dir_exist");
        return true;
    }
    else {
        return false;
    }
}

// get directory from filename
inline Str path2dir(Str_I fname)
{
    Llong ind = fname.rfind("/");
    if (ind < 0)
        return "./";
    else
        return fname.substr(0, ind+1);
}

// make multiple level of directory
inline void mkdir(Str_I path)
{
    Long ind = path.find("\"");
    if (ind >= 0)
        SLS_ERR("folder name should not contain double quote: " + path);
    Int ret = system(("mkdir -p \"" + path + "\"").c_str()); ret++;
    if (!dir_exist(path))
        SLS_ERR("mkdir failed: " + path);
}

// remove an empty directory
inline void rmdir(Str_I path)
{
    Int ret = system(("rmdir " + path).c_str()); ret++;
}

// make sure the directory (or directory of a file name) exist
// directory must end with '/'
// if not, create the directory
inline void ensure_dir(Str_I dir_or_file)
{
    Long ind = dir_or_file.rfind('/');
    if (dir_exist(dir_or_file.substr(0, ind)))
        return;
    mkdir(dir_or_file.substr(0, ind));
}

// remove a file
inline void file_rm(Str_I wildcard_name) {
    system(("rm " + wildcard_name).c_str());
}

// list all files in current directory
// only works for linux
#ifdef __GNUC__
inline void file_list(vecStr_O fnames, Str_I path, Bool_I append)
{
    if (!append)
        fnames.resize(0);
    // save a list of all files (no folder) to temporary file
    std::istringstream iss(exec_str(("ls -p " + path + " | grep -v /").c_str()));
    
    // read the temporary file
    Str name;
    while (true) {
        std::getline(iss, name);
        if (iss.eof())
            break;
        fnames.push_back(name);
    }
}
#else
#ifdef SLS_HAS_FILESYSTEM
// std::filesystem implementation of file_list()
// works in Visual Studio, not gcc 8
// directory example: "C:/Users/addis/Documents/GitHub/SLISC/"
inline void file_list(vecStr_O names, Str_I path, Bool_I append)
{
    if (!append)
        names.resize(0);
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::stringstream ss;
        if (entry.is_directory())
            continue;
        auto temp = entry.path().filename();
        ss << temp;
        string str = ss.str();
        str = str.substr(1, str.size() - 2);
        // str = str.substr(path.size(), str.size()); // remove " " and path
        names.push_back(str);
    }
}
#else
inline void file_list(vecStr_O fnames, Str_I path, Bool_I append = false)
{
    SLS_ERR("not implemented");
}
#endif
#endif

// list all files in a directory recursively (containing relative paths)
#ifdef __GNUC__
inline void file_list_r(vecStr_O fnames, Str_I path, Bool_I append = false)
{
    if (!append)
        fnames.resize(0);
    // save a list of all files (no folder) to temporary file
    std::istringstream iss(exec_str(("find " + path + " -type f").c_str()));
    
    // read the temporary file
    Str name;
    while (true) {
        std::getline(iss, name);
        if (iss.eof())
            break;
        fnames.push_back(name);
    }
}
#endif

// choose files with a given extension from a list of files
inline void file_ext(vecStr_O fnames_ext, vecStr_I fnames, Str_I ext, Bool_I keep_ext = true, Bool_I append = false)
{
    if (!append)
        fnames_ext.resize(0);
    Long N_ext = ext.size();
    for (Long i = 0; i < size(fnames); ++i) {
        const Str & str = fnames[i];
        // check position of '.'
        Long ind = fnames[i].size() - N_ext - 1;
        if (ind < 0 || str[ind] != '.')
            continue;
        // match extension
        if (str.rfind(ext) != str.size() - ext.size())
            continue;
        if (keep_ext)
            fnames_ext.push_back(str);
        else
            fnames_ext.push_back(str.substr(0, str.size() - N_ext - 1));
    }
}

// list all files in current directory, with a given extension
inline void file_list_ext(vecStr_O fnames, Str_I path, Str_I ext, Bool_I keep_ext = true, Bool_I append = false)
{
    vecStr fnames0;
    if (!append)
        fnames.resize(0);
    file_list(fnames0, path);
    file_ext(fnames, fnames0, ext, keep_ext);
}

// copy a file (read then write)
// use default fstream buffer, not sure about performance
inline void file_copy(Str_I fname_out, Str_I fname_in, Bool_I replace = false)
{
    if (!file_exist(fname_in))
        SLS_ERR("file not found: " + fname_in);
    if (file_exist(fname_out) && !replace) {
        while (true) {
            if (file_exist(fname_out)) {
                SLS_WARN("\n\nfile [" + fname_out + "] already exist! delete file to continue...\n"
                    "  (set argument `replace = false` to replace file by default)\n\n");
            }
            else {
                break;
            }
            pause(10);
        }
    }
    ifstream fin(fname_in, std::ios::binary);
    ofstream fout(fname_out, std::ios::binary);
    if (!fout.good())
        SLS_ERR("failed to open file, directory not exist? (" + fname_out + ")");
    fout << fin.rdbuf();
    fin.close();
    fout.close();
}

// file copy with user buffer (larger buffer is faster)
// buffer size used is `buffer.capacity()`, not `buffer.size()`
// `buffer` resized to 0 after return
inline void file_copy(Str_I fname_out, Str_I fname_in, Str_IO buffer, Bool_I replace = false)
{
    // checking
    if (!file_exist(fname_in))
        SLS_ERR("file not found!");
    if (file_exist(fname_out) && !replace) {
        while (true) {
            if (file_exist(fname_out)) {
                SLS_WARN("\n\nfile [" + fname_out + "] already exist! delete file to continue...\n"
                    "  (set argument `replace = false` to replace file by default)\n\n");
            }
            else {
                break;
            }
            pause(10);
        }
    }
    
    // copy using buffer
    ifstream fin(fname_in, std::ios::binary);
    ofstream fout(fname_out, std::ios::binary);
    if (!fout.good())
        SLS_ERR("failed to open file, directory not exist? (" + fname_out + ")");
    Long buf_size = buffer.capacity();
    buffer.resize(buf_size);
    while (buffer.size() > 0) {
        read(fin, buffer);
        write(fout, buffer);
    }
}

// move a file (copy and delete)
inline void file_move_cp(Str_I fname_out, Str_I fname_in, Bool_I replace = false)
{
    file_copy(fname_out, fname_in, replace);
    file_remove(fname_in);
}

// file_move_cp() with user buffer
inline void file_move_cp(Str_I fname_out, Str_I fname_in, Str_IO buffer, Bool_I replace = false)
{
    file_copy(fname_out, fname_in, buffer, replace);
    file_remove(fname_in);
}

inline void file_move(Str_I fname_out, Str_I fname_in, Bool_I replace = false)
{
    Long ind = fname_in.find("\"");
    if (ind >= 0)
        SLS_ERR("double quote not supported: " + fname_in);
    ind = fname_out.find("\"");
    if (ind >= 0)
        SLS_ERR("double quote not supported: " + fname_out);

    Int ret;
    if (replace)
        ret = system(("mv -n \"" + fname_in + "\" \"" + fname_out + "\"").c_str());
    else
        ret = system(("mv \"" + fname_in + "\" \"" + fname_out + "\"").c_str());
    ++ret;
}

// get number of bytes in file
inline Long file_size(Str_I fname)
{
    if (!file_exist(fname))
        SLS_ERR("file not found: " + fname);
    ifstream fin(fname, ifstream::ate | ifstream::binary);
    return fin.tellg();
}

// open binary file to write
inline void open_bin(ofstream &fout, Str_I fname)
{
    if (fout.is_open())
        fout.close();
    fout.open(fname, std::ios::out | std::ios::binary);
}

// open binary file to read
inline void open_bin(ifstream &fin, Str_I fname)
{
    if (fin.is_open())
        fin.close();
    fin.open(fname, std::ios::in | std::ios::binary);
}

// write binary file (once)
inline void write(const Char *data, Long_I Nbyte, Str_I fname)
{
    ofstream fout; open_bin(fout, fname);
    fout.write(data, Nbyte);
    fout.close();
}

// read binary file (once)
// return the actual bytes read
inline Long read(Char *data, Long_I Nbyte, Str_I fname)
{
    Long Nbyte0 = file_size(fname);
    if (Nbyte0 > Nbyte)
        SLS_ERR("Nbyte too small");
    ifstream fin; open_bin(fin, fname);
    Long count = fin.read(&data[0], Nbyte0).gcount();
    fin.close();
    return count;
}

// write Str to file
inline void write(Str_I str, Str_I fname)
{
    write(str.c_str(), str.size(), fname);
}

// read whole file to Str
inline void read(Str_O str, Str_I fname)
{
    str.resize(file_size(fname));
    read(&str[0], str.size(), fname);
}

// read and write binary data from/to ifstrea/ofstream

//===================================
// `ofstream::write(p_char, Nbytes)`
// `ifstream::read(p_char, Nbytes).gcount()` will return the actual bytes read before end of file
// `fin.ignore(N)` skip N bytes
//===================================

inline void write(ofstream &fout, Char_I s)
{
    fout.write((char*)&s, sizeof(Char));
}

inline void read(ifstream &fin, Char_O s)
{
    fin.read((char*)&s, sizeof(Char));
}

inline void write(ofstream &fout, Int_I s)
{
    fout.write((char*)&s, sizeof(Int));
}

inline void read(ifstream &fin, Int_O s)
{
    fin.read((char*)&s, sizeof(Int));
}

inline void write(ofstream &fout, Llong_I s)
{
    fout.write((char*)&s, sizeof(Llong));
}

inline void read(ifstream &fin, Llong_O s)
{
    fin.read((char*)&s, sizeof(Llong));
}

inline void write(ofstream &fout, Doub_I s)
{
    fout.write((char*)&s, sizeof(Doub));
}

inline void read(ifstream &fin, Doub_O s)
{
    fin.read((char*)&s, sizeof(Doub));
}

inline void write(ofstream &fout, Comp_I s)
{
    fout.write((char*)&s, sizeof(Comp));
}

inline void read(ifstream &fin, Comp_O s)
{
    fin.read((char*)&s, sizeof(Comp));
}


// string
inline void write(ofstream &fout, Str_I str)
{
    fout.write(str.data(), str.size());
}

// if end of file reached before data is filled, it will be resized
inline void read(ifstream &fin, Str_O str)
{
    Long count = fin.read(&str[0], str.size()).gcount();
    if (count < size(str))
        str.resize(count);
}

// string with 32-bit char (usually for UTF32)
inline void write(ofstream &fout, Str32_I str)
{
    fout.write((Char *)str.data(), 4*str.size());
}

// if end of file reached before str is filled, it will be resized
inline void read(ifstream &fin, Str32_O str)
{
    Long count = fin.read((Char *)&str[0], 4*str.size()).gcount();
    count /= 4;
    if (count < size(str))
        str.resize(count);
}

// read a table from file
// two numbers should be separated by space
// skipt specific number of lines at the beginning
// matrix will auto-resize
// 0 to multiple spaces & new line at the end of file are allowed
inline void read(CmatDoub_O mat, Str_I file, Long_I skip_lines = 0)
{
    ifstream input(file);
    if (!input.good())
        SLS_ERR(file + " does not exist!");
    for (Long i = 0; i < skip_lines; ++i)
        input.ignore(100000, '\n');
    // detect the number of columns
    Str line;
    getline(input, line);
    std::istringstream iss(line);
    vector<Doub> v;
    Doub num;
    while (iss >> num)
        v.push_back(num);
    Long N2 = v.size();
    while (true) {
        num = NaN;
        input >> num;
        if (std::isnan(num))
            break;
        v.push_back(num);
        if (input.eof())
            break;
    }
    if (v.size() % N2 != 0)
        SLS_ERR(file + ": each row might not have equal number of columns!");
    Long N1 = v.size() / N2;
    mat.resize(N1, N2);
    for (Long i = 0; i < N1; ++i) {
        for (Long j = 0; j < N2; ++j) {
            mat(i, j) = v[N2*i + j];
        }
    }
}

// get time-stamp of a file
#ifndef _MSC_VER
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
inline void last_modified(Str_O yyyymmddhhmmss, Str_I fname) {
    struct tm *time;
    struct stat attrib;
    stat(fname.c_str(), &attrib);
    time = localtime(&(attrib.st_mtime));
    yyyymmddhhmmss.clear();
    yyyymmddhhmmss += num2str(time->tm_year + 1900) +
        num2str(time->tm_mon + 1, 2) + num2str(time->tm_mday, 2) +
        num2str(time->tm_hour, 2) + num2str(time->tm_min, 2) +
        num2str(time->tm_sec, 2);
}
#else
inline void last_modified(Str_O yymmddhhmmss, Str_I fname) {
    SLS_ERR("not implemented for windows!");
}
#endif

// set write buffer
// can speed up if there are a lot of staggered short reading and writing in the same drive
inline void set_buff(ofstream &fout, Str_IO buffer)
{
    fout.rdbuf()->pubsetbuf(&buffer[0], buffer.size());
}

// test if system use little endian (less significant byte has smaller memory address)
// for example, shot int(1) will be 00000001 0000000 in little endian
// there is no concept of "bit endian" since they are not addressable
// Intel x86 and x64 architechture use little endian
inline Bool little_endian()
{
    short int num = 1;
    Char *b = (Char *)&num;
    return b[0];
}

// convert endianness
inline void change_endian(Char *data, Long_I elm_size, Long_I Nelm)
{
    Long half = elm_size/2;
    for (Long i = 0; i < Nelm; ++i) {
        for (Long j = 0; j < half; ++j) {
            swap(data[j], data[elm_size-j]);
        }
        data += elm_size;
    }
}

} // namespace slisc
