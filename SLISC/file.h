#pragma once
#include "global.h"
#if !(defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(__MSYS__))
#include "time.h"
#include "arithmetic.h"
#include "linux.h"
#include <sstream>
#include <fstream>
#include <sys/types.h> // for time_stamp
#include <sys/stat.h> // for time_stamp
#include "unicode.h"
#include "sort.h"
#include "Bit.h"
#ifdef SLS_USE_MSVC
#include "search.h"
#include "string.h"
#endif

namespace slisc {

using std::stringstream;

inline void file_list(vecStr_O names, Str_I path, Bool_I append = false);
inline void read(ifstream &fin, Str_O str);
inline void write(ofstream &fout, Str_I str);
inline void write(Str_I str, Str_I fname);

#ifdef SLS_USE_MSVC
inline Str wstr2utf8(const std::wstring& wstr);
inline std::wstring utf82wstr(Str_I str);

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
// case_sens only works on Windows
inline Bool file_exist(Str_I fname, Bool_I case_sens = true) {
#ifndef SLS_USE_MSVC
	ifstream f(fname);
	return f.good();
#else
	if (case_sens)
	    return file_exist_case(fname);
	else {
	    ifstream f(utf82wstr(fname));
	    return f.good();
}
#endif
}

// not case sensitive on Windows, see file_exist_case()
inline Bool file_exist(Str32_I fname) {
	return file_exist(utf32to8(fname));
}

// remove a file with error handling
inline void file_remove(Str_I fname)
{
#ifndef SLS_USE_MSVC
	if (remove(fname.c_str()) && file_exist(fname))
	    throw Str("failed to remove, file being used? (" + fname + ")");
#else
	if (file_exist(fname) && DeleteFile(utf82wstr(fname).c_str()) == 0)
	    throw Str("failed to remove, file being used? (" + fname + ")");
#endif
}

// check if directory exist
// `path` must end with '/'
inline Bool dir_exist(Str_I path)
{
#ifndef SLS_USE_MSVC
	ofstream file(path + "/sls_test_if_dir_exist");
#else
	ofstream file(utf82wstr(path + "/sls_test_if_dir_exist"));
#endif
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
	Str tmp = path;
	replace(tmp, "\"", "\\\""); // doesn't matter for utf8, multi-byte encoding all bytes > 127
#ifndef SLS_USE_MSVC
	Int ret = system(("mkdir -p \"" + tmp + "\"").c_str()); ret++;
#else
	CreateDirectory(utf82wstr(tmp).c_str(), NULL);
#endif
	if (!dir_exist(tmp))
	    SLS_ERR("mkdir failed: " + tmp);
}

// remove an empty directory
inline void rmdir(Str_I path)
{
#ifndef SLS_USE_MSVC
	Int ret = system(("rmdir " + path).c_str()); ret++;
#else
	if (RemoveDirectory(utf82wstr(path).c_str()) == 0)
	    SLS_ERR("cannot remove directory: " + path);
#endif
}

// make sure the directory (or directory of a file name) exist
// directory must end with '/'
// if not, create the directory
inline void ensure_dir(Str_I dir_or_file)
{
	Long ind = dir_or_file.rfind('/');
	Str dir = dir_or_file.substr(0, ind);
	if (dir_exist(dir))
	    return;
	mkdir(dir);
	if (!dir_exist(dir))
	    SLS_ERR("cannot create directory: " + dir);
}

#ifndef SLS_USE_MSVC
// remove a file
inline void file_rm(Str_I wildcard_name) {
	system(("rm " + wildcard_name).c_str());
}
#endif

// list all files in current directory
// path must end with '/'
// result is sorted
#ifndef SLS_USE_MSVC
inline void file_list(vecStr_O fnames, Str_I path, Bool_I append)
{    
	if (!append)
	    fnames.clear();
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
	sort(fnames);
}
#else
inline void file_list(vecStr_O fnames, Str_I path, Bool_I append)
{
	WIN32_FIND_DATA data;
	HANDLE h = FindFirstFile(utf82wstr(path + "*").c_str(), &data);      // DIRECTORY
	Str fname;
	if (!append)
	    fnames.clear();
	if (h != INVALID_HANDLE_VALUE) {
	    do {
	        std::wstring wstr(data.cFileName);
	        fname = wstr2utf8(wstr);
	        if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	            continue; // ignore directories
	        fnames.push_back(fname);
	    } while (FindNextFile(h, &data));
	    FindClose(h);
	}
	sort(fnames);
}
#endif

// list all files including paths
// path should end with '/'
// result is sorted
inline void file_list_full(vecStr_O fnames, Str_I path, Bool_I append = false)
{
	if (!append)
	    fnames.clear();
	vecStr names;
	file_list(names, path);
	for (Long i = 0; i < size(names); ++i)
	    fnames.push_back(path + names[i]);
}

#ifdef SLS_USE_MSVC

// path should end with '/'
// path can be full, relative or empty (./)
// `folders` will not include `path`
// result is sorted
inline void folder_list(vecStr_O folders, Str_I path, Bool_I append = false)
{
	WIN32_FIND_DATA data;
	HANDLE h = FindFirstFile(utf82wstr(path + "*").c_str(), &data);      // DIRECTORY
	Str fname;
	if (!append)
	    folders.clear();
	if (h != INVALID_HANDLE_VALUE) {
	    do {
	        std::wstring wstr(data.cFileName);
	        fname = wstr2utf8(wstr);
	        if (fname == "." || fname == "..")
	            continue;
	        if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	            folders.push_back(fname + "/"); // only include directories
	    } while (FindNextFile(h, &data));
	    FindClose(h);
	}
	sort(folders);
}

// `path` must end with '/'
// `folders` will include `path`
// result is sorted
inline void folder_list_full(vecStr_O folders, Str_I path, Bool_I append = false)
{
	if (!append)
	    folders.clear();
	vecStr names;
	folder_list(names, path, append);
	for (Long i = 0; i < size(names); ++i)
	    folders.push_back(path + names[i]);
}
#endif

// list all files in a directory recursively (containing relative paths)
// result is sorted
#ifndef SLS_USE_MSVC
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
	sort(fnames);
}
#else
inline void file_list_r(vecStr_O fnames, Str_I path, Bool_I append = false)
{
	if (!append)
	    fnames.clear();
	file_list_full(fnames, path, true);
	vecStr folders;
	folder_list(folders, path, false);
	for (Long i = 0; i < size(folders); ++i)
	    file_list_r(fnames, path + folders[i], true);
	sort(fnames);
}
#endif

// choose files with a given extension from a list of files
inline void file_ext(vecStr_O fnames_ext, vecStr_I fnames, Str_I ext, Bool_I keep_ext = true, Bool_I append = false)
{
	if (!append)
	    fnames_ext.clear();
	Long N_ext = ext.size();
	for (Long i = 0; i < size(fnames); ++i) {
	    const Str &str = fnames[i];
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
// result is sorted
inline void file_list_ext(vecStr_O fnames, Str_I path, Str_I ext, Bool_I keep_ext = true, Bool_I append = false)
{
	vecStr fnames0;
	file_list(fnames0, path);
	file_ext(fnames, fnames0, ext, keep_ext, append);
}

// list all files in current directory, with a given extension
inline void file_list_ext(vecStr32_O fnames, Str32_I path, Str32_I ext, Bool_I keep_ext = true, Bool_I append = false)
{
	vecStr fnames8;
	if (!append)
	    fnames.clear();
	file_list_ext(fnames8, utf32to8(path), utf32to8(ext), keep_ext);
	for (Long i = 0; i < size(fnames8); ++i)
	    fnames.push_back(utf8to32(fnames8[i]));
}

// copy a file (read then write)
// use default fstream buffer, not sure about performance
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
	if (!fout.good())
	    SLS_ERR("failed to open file, directory not exist? (" + fname_out + ")");
	fout << fin.rdbuf();
	fin.close();
	fout.close();
}

inline void file_copy(Str32_I fname_out, Str32_I fname_in, Bool_I replace = false)
{
	file_copy(utf32to8(fname_out), utf32to8(fname_in), replace);
}

// file copy with user buffer (larger buffer is faster)
// buffer size used is `buffer.capacity()`, not `buffer.size()`
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
inline void file_move(Str_I fname_out, Str_I fname_in, Bool_I replace = false)
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
	if (rename(fname_in.c_str(), fname_out.c_str())) {
		// rename() failed (probably differen filesystems/deives are involved)
		file_copy(fname_out, fname_in, replace);
		file_remove(fname_in);
	}
}

// file_move() with user buffer
inline void file_move(Str_I fname_out, Str_I fname_in, Str_IO buffer, Bool_I replace = false)
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
	if (rename(fname_in.c_str(), fname_out.c_str())) {
		// rename() failed (probably differen filesystems/deives are involved)
		file_copy(fname_out, fname_in, buffer, replace);
		file_remove(fname_in);
	}
}

// get number of bytes in file
// return -1 if file not found
inline Long file_size(Str_I fname)
{
	if (!file_exist(fname))
	    return -1;
#ifndef SLS_USE_MSVC
	ifstream fin(fname, ifstream::ate | ifstream::binary);
#else
	ifstream fin(utf82wstr(fname), ifstream::ate | ifstream::binary);
#endif
	return fin.tellg();
}

// open binary file to write
inline void open_bin(ofstream &fout, Str_I fname)
{
	if (fout.is_open())
	    fout.close();
#ifndef SLS_USE_MSVC
	fout.open(fname, std::ios::out | std::ios::binary);
#else
	fout.open(utf82wstr(fname), std::ios::out | std::ios::binary);
#endif
}

// open binary file to read
inline void open_bin(ifstream &fin, Str_I fname)
{
	if (fin.is_open())
	    fin.close();
#ifndef SLS_USE_MSVC
	fin.open(fname, std::ios::in | std::ios::binary);
#else
	fin.open(utf82wstr(fname), std::ios::in | std::ios::binary);
#endif
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

// write UTF-32 Str32 into a UTF-8 file
inline void write(Str32_I str32, Str_I fname)
{
	write(utf32to8(str32), fname);
}

inline void write(Str32_I str32, Str32_I fname)
{
	write(str32, utf32to8(fname));
}

// write a vector of strings to file
// no `\n` allowed in each string
// file will be ended by a return
inline void write_vec_str(vecStr_I vec_str, Str_I fname)
{
	Str str;
	for (Long i = 0; i < size(vec_str); ++i) {
	    str += vec_str[i] + '\n';
	}
	write(str, fname);
}

inline void write_vec_str(vecStr32_I vec_str, Str32_I fname)
{
	Str32 str;
	for (Long i = 0; i < size(vec_str); ++i) {
	    str += vec_str[i] + U'\n';
	}
	write(str, fname);
}

// read whole file to Str
inline void read(Str_O str, Str_I fname)
{
	str.resize(file_size(fname));
	read(&str[0], str.size(), fname);
}

// read a UTF-8 file into UTF-32 Str32
inline void read(Str32_O str32, Str_I fname)
{
	Str str;
	read(str, fname);
	utf8to32(str32, str);
}

inline void read(Str32_O str32, Str32_I fname)
{
	read(str32, utf32to8(fname));
}

// read the file written by `write_vec_str()`
// file must be ended by a return

inline void read_vec_str(vecStr_O vec_str, Str_I fname)
{
	Str str;
	vec_str.clear();
	read(str, fname);
	if (str.empty())
	    return;
	CRLF_to_LF(str);
	Long ind0 = 0;
	for (Long i = 0; ; ++i) {
	    vec_str.emplace_back();
	    ind0 = get_line(vec_str[i], str, ind0);
	    if (ind0 < 0)
	        return;
	}
}

inline void read_vec_str(vecStr32_O vec_str, Str32_I fname)
{
	Str32 str;
	vec_str.clear();
	read(str, fname);
	if (str.empty())
	    return;
	CRLF_to_LF(str);
	Long ind0 = 0;
	for (Long i = 0; ; ++i) {
	    vec_str.emplace_back();
	    ind0 = get_line(vec_str[i], str, ind0);
	    if (ind0 < 0)
	        return;
	}
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

// read a table from text file
// two numbers should be separated by space
// skipt specific number of lines at the beginning
// matrix will auto-resize
// spaces & new line at the end of file are allowed
inline void read(CmatInt_O mat, Str_I file, Long_I skip_lines = 0)
{
	ifstream input(file);
	if (!input.good())
	    SLS_ERR(file + " does not exist!");
	for (Long i = 0; i < skip_lines; ++i)
	    input.ignore(1000000, '\n');
	// detect the number of columns
	Str line;
	getline(input, line);
	std::istringstream iss(line);
	vector<Int> v;
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

inline void read(CmatLlong_O mat, Str_I file, Long_I skip_lines = 0)
{
	ifstream input(file);
	if (!input.good())
	    SLS_ERR(file + " does not exist!");
	for (Long i = 0; i < skip_lines; ++i)
	    input.ignore(1000000, '\n');
	// detect the number of columns
	Str line;
	getline(input, line);
	std::istringstream iss(line);
	vector<Llong> v;
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

inline void read(CmatDoub_O mat, Str_I file, Long_I skip_lines = 0)
{
	ifstream input(file);
	if (!input.good())
	    SLS_ERR(file + " does not exist!");
	for (Long i = 0; i < skip_lines; ++i)
	    input.ignore(1000000, '\n');
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


// read a vector from a text file
// two numbers should be separated by space or enter
// skipt specific number of lines at the beginning
// vector will auto-resize
// spaces & new line at the end of file are allowed
inline void read(VecDoub_O v, Str_I file, Long_I skip_lines = 0)
{
	ifstream input(file);
	if (!input.good())
	    SLS_ERR(file + " does not exist!");
	for (Long i = 0; i < skip_lines; ++i)
	    input.ignore(1000000, '\n');
	// detect the number of columns
	vector<Doub> v0;
	Doub num;
	while (true) {
	    num = NaN;
	    input >> num;
	    if (isnan(num))
	        break;
	    v0.push_back(num);
	    if (input.eof())
	        break;
	}
	v.resize(v0.size());
	for (Long i = 0; i < size(v0); ++i)
	    v[i] = v0[i];
}

// get time-stamp of a file
#ifndef SLS_USE_MSVC
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

} // namespace slisc
#endif
