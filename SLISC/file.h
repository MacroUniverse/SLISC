#pragma once
#include "time.h"
#include "arithmetic.h"
#include "linux.h"
#include <sstream>
#include <fstream>
#include <codecvt>
#ifdef SLS_HAS_FILESYSTEM
#include <filesystem>
#endif

namespace slisc {

using std::stringstream;

inline void file_list(vecStr_O names, Str_I path);

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

// read whole file to Str
inline void read_file(Str_O str, Str_I fname)
{
    if (!file_exist(fname))
        SLS_ERR("file \"" + fname + "\" does not exist!");
    ifstream fin(fname, std::ios::binary);
    stringstream ss;
    ss << fin.rdbuf();
    str = ss.str();
}

inline void file_rm(Str_I wildcard_name) {
    system(("rm " + wildcard_name).c_str());
}

// list all files in current directory
// only works for linux
#ifdef __GNUC__
inline void file_list(vecStr_O fnames, Str_I path)
{    
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
inline void file_list(vecStr_O names, Str_I path)
{
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
inline void file_list(vecStr_O fnames, Str_I path)
{
    SLS_ERR("not implemented");
}
#endif
#endif

// choose files with a given extension from a list of files
inline void file_ext(vecStr_O fnames_ext, vecStr_I fnames, Str_I ext, Bool_I keep_ext = true)
{
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
inline void file_list_ext(vecStr_O fnames, Str_I path, Str_I ext, Bool_I keep_ext = true)
{
    vecStr fnames0;
    file_list(fnames0, path);
    file_ext(fnames, fnames0, ext, keep_ext);
}

// copy a file (read then write)
inline void file_copy(Str_I fname_out, Str_I fname_in, Bool_I replace = false)
{
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
    ifstream fin(fname_in, std::ios::binary);
    ofstream fout(fname_out, std::ios::binary);
    fout << fin.rdbuf();
    fin.close();
    fout.close();
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
inline void write_bin(Str_I data, Str_I fname)
{
	ofstream fout; open_bin(fout, fname);
	fout.write(data.c_str(), data.size());
	fout.close();
}

// read binary file (once)
inline void read_bin(Str_O data, Str_I fname)
{
    Long Nbytes = file_size(fname);
    data.resize(Nbytes);
	ifstream fin; open_bin(fin, fname);
	fin.read(&data[0], Nbytes);
    fin.close();
}

// write binary file (multiple times)
inline void write_bin(ofstream &fout, Str_I data)
{
	fout.write(data.c_str(), data.size());
}

// read binary file (multiple times)
// if end of file reached before Nbytes is read, data will be the actual bytes left
// use fin.ignore(N) to skip N bytes
inline void read_bin(Str_O data, ifstream &fin, Long_I Nbytes)
{
    data.resize(Nbytes);
	Long count = fin.read(&data[0], Nbytes).gcount();
    if (count < Nbytes)
        data.resize(count);
}

} // namespace slisc
