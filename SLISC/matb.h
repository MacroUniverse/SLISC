// binary version of matt.h
// always use Llong when reading and writing index in matb file

#pragma once
#include "matt.h"
#include "Bit.h"

#if !(defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(__MSYS__))

namespace slisc {

// all non-data intergers in file are Llong
class Matb {
public:
	Matb();
	Matb(Str_I fname, Str_I rw, Bool_I replace = false);
	Str m_rw; // "r" for read "w" for write
	ifstream m_in; // read file
	ofstream m_out; // write file
	Llong m_filesize; // file size
	Str m_fname; // name of the opened file
	vecStr m_name; // variable names
	vecStr m_data; // data cache, only useful in "m" mode
	vecLong m_type; // variable types
	vector<vecLong> m_size; // variable dimensions
	vecLlong m_ind; // variable positions (from the first byte of file)

	// open a file
	void open(Str_I fname, Str_I rw, Bool_I replace = false);

	// check if file is open
	Bool isopen();

	// read all data into cache
	void read_data();
	void write_data(Str_I fname);

	// close a file, if not called, will be called in destructor
	void close();

	// ===== internal functions =====

	// get var names and positions from the end of the file
	Long size() const;
	Long data_size(Long_I i) const;
	void get_profile();
	Long data_pos(Long_I var_ind) const; // find position of the ind-th variable, i.e. seekg() of the first element

	// search a variable by name, return index to m_name[i]
	// return -1 if not found
	Long search(Str_I name);

	~Matb();
};

typedef const Matb &Matb_I;
typedef Matb &Matb_O, &Matb_IO;

struct Matb_file_not_complete {};

// read the last Llong
// pointer will be moved to the beginning of the last Llong
inline Llong lastLlong(ifstream &fin)
{
	Llong p = Llong(fin.tellg()) - 8;
	Llong num;
	fin.seekg(p);
	read(fin, num);
	fin.seekg(p);
	return num;
}

inline Long Matb::size() const
{
	return m_ind.size();
}

inline void Matb::get_profile()
{
	Str name;
	ifstream &fin = m_in;

	// read number of variables and their positions
	fin.seekg(0, fin.end);
	m_filesize = fin.tellg();
	// check end of file mark
	fin.seekg(m_filesize-strlen("Matb_End_of_File"));
	Str mark; mark.resize(strlen("Matb_End_of_File"));
	read(fin, mark);
	if (mark != "Matb_End_of_File")
	    throw Matb_file_not_complete();
	fin.seekg(m_filesize-strlen("Matb_End_of_File"));
	Long Nvar = lastLlong(fin);
	if (Nvar < 1)
	    SLS_ERR("unknown!");
	m_ind.resize(Nvar);
	for (Long i = 0; i < Nvar; ++i) {
	    m_ind[i] = lastLlong(fin);
	    if (m_ind[i] >= m_filesize || m_ind[i] < 0)
	        SLS_ERR("unknown!");
	    if (i > 0 && m_ind[i] <= m_ind[i-1])
	        SLS_ERR("unknown!");
	}

	// loop through each variable
	m_size.resize(Nvar);
	for (Long i = 0; i < Nvar; ++i) {
	    fin.seekg(m_ind[i]);
	    // read var name
	    Llong n;
	    read(fin, n);
	    name.resize(n);
	    read(fin, name);
	    m_name.push_back(name);
	    // read var type
	    read(fin, n);
	    if (n < 0)
	        SLS_ERR("unknown!");
	    m_type.push_back(n);
	    // read var dim
	    read(fin, n);
	    if (n < 0)
	        SLS_ERR("unknown!");
	    m_size[i].resize(n);
	    for (Long j = 0; j < n; ++j) {
	        Llong tmp;
	        read(fin, tmp); m_size[i][j] = tmp;
	        if (m_size[i][j] < 0)
	            SLS_ERR("unknown!");
	    }
	}
}

inline Long Matb::data_pos(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <0 || i >= size())
	    SLS_ERR("out of bound!");
#endif
	return m_ind[i] + 8 + m_name[i].size() + 8 + 8 + (Long)m_size[i].size() * 8;
}

// search variable in file by name
// return index of m_name, return -1 if not found
inline Long Matb::search(Str_I name)
{
	for (Long i = 0; i < size(); ++i)
	    if (name == m_name[i])
	        return i;
	return -1;
}

inline Matb::Matb() {}

inline Matb::Matb(Str_I fname, Str_I rw, Bool_I replace)
{ open(fname, rw, replace); }

inline void Matb::open(Str_I fname, Str_I rw, Bool_I replace)
{
	if (!little_endian())
	    SLS_ERR("only support little endian for now!");
	if (isopen())
	    close();
	if (fname.substr(fname.size()-5) != ".matb")
	    SLS_ERR("file must have \".matb\" extension!");
	m_rw = rw;
	m_fname = fname;
	if (rw == "w") {
#ifndef SLS_MATB_REPLACE
	    if (!replace && file_exist(m_fname)) {
	        while (true) {
	            if (file_exist(m_fname)) {
	                SLS_WARN("\n\nfile [" + m_fname + "] already exist! delete file to continue...\n"
	                    "  (define SLS_MATB_REPLACE to replace file by default)\n\n");
	            }
	            else {
	                break;
	            }
	            pause(10);
	        }
	    }
#endif
	    open_bin(m_out, m_fname);
	    if (!m_out.good())
	        SLS_ERR("error: file not created (does directory exist?): " + m_fname);
	}
	else if (rw == "r" || "m") {
	    open_bin(m_in, m_fname);
	    if (!m_in.good())
	        SLS_ERR("error: file not found: " + m_fname);
	    get_profile(); // get var names
	}
	else
	    SLS_ERR("illegal mode!");
}

inline Long Matb::data_size(Long_I i) const
{
	Long len;
	if (i+1 < size())
	    len = m_ind[i+1] - data_pos(i);
	else {
	    Long end = m_filesize - strlen("Matb_End_of_File") - 8*(size() + 1);
	    len = end - data_pos(i);
	}
	return len;
}

inline Bool Matb::isopen()
{
	return m_in.is_open() != m_out.is_open();
}

inline void Matb::read_data()
{
	if (m_rw != "m")
	    SLS_ERR("read_data() can only be used in \"m\" mode!");
	for (Long i = 0; i < size(); ++i) {
	    m_data.push_back(Str()); m_data[i].resize(data_size(i));
	    m_in.seekg(data_pos(i));
	    read(m_in, m_data[i]);
	    if (Long(m_data[i].size()) != data_size(i))
	        SLS_ERR("unknown!");
	}
}

inline void Matb::write_data(Str_I fname)
{
	if (m_rw != "m")
	    SLS_ERR("write_data() can only be used in \"m\" mode!");
	m_in.close();
	open_bin(m_out, fname);
	m_out.seekp(0, std::ios::beg);
	for (Long i = 0; i < size(); ++i) {
	    // debug
	    if (m_ind[i] != m_out.tellp())
	        SLS_ERR("unknown!");
	    write(m_out, (Llong)m_name[i].size());
	    write(m_out, m_name[i]); // name
	    write(m_out, (Llong)m_type[i]);
	    Long Ndim = m_size[i].size();
	    write(m_out, (Llong)Ndim); // dim
	    for (Long j = 0; j < Ndim; ++j)
	        write(m_out, (Llong)m_size[i][j]);
	    write(m_out, m_data[i]);
	}
	// write position of variables
	for (Long i = size() - 1; i >= 0; --i)
	    write(m_out, m_ind[i]);
	// write number of variables
	write(m_out, (Llong)size());
	// mark end-of-file
	write(m_out, "Matb_End_of_File");
	m_out.close();
	open_bin(m_in, m_fname);
}

inline void Matb::close()
{
	if (m_rw == "w") {
	    // write position of variables
	    for (Long i = m_ind.size() - 1; i >= 0; --i)
	        write(m_out, m_ind[i]);
	    // write number of variables
	    write(m_out, (Llong)size());
	    // mark end-of-file
	    write(m_out, "Matb_End_of_File");
	    m_out.close();
	}
	else {
	    m_in.close();
	}
	m_rw = '\0';
	m_name.clear();
	m_type.clear();
	m_size.clear();
	m_ind.clear();
}

inline Matb::~Matb()
{
	if (isopen())
	    close();
	else if (m_in.is_open() && m_out.is_open())
	    SLS_ERR("unknown!");
}

// save() functions

// save() for scalar
inline void save(Char_I s, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open: " + matb.m_fname);
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, Llong(varname.size()));
	write(fout, varname);
	// write data type info
	write(fout, Llong(1));
	// write dimension info
	write(fout, Llong(0));
	// write matrix data
	write(fout, s);
}

inline void save_matb(Char_I s, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(s, varname, matb);
	matb.close();
}

inline void save(Int_I s, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open: " + matb.m_fname);
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, Llong(varname.size()));
	write(fout, varname);
	// write data type info
	write(fout, Llong(2));
	// write dimension info
	write(fout, Llong(0));
	// write matrix data
	write(fout, s);
}

inline void save_matb(Int_I s, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(s, varname, matb);
	matb.close();
}

inline void save(Llong_I s, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open: " + matb.m_fname);
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, Llong(varname.size()));
	write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write dimension info
	write(fout, Llong(0));
	// write matrix data
	write(fout, s);
}

inline void save_matb(Llong_I s, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(s, varname, matb);
	matb.close();
}

inline void save(Doub_I s, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open: " + matb.m_fname);
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, Llong(varname.size()));
	write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write dimension info
	write(fout, Llong(0));
	// write matrix data
	write(fout, s);
}

inline void save_matb(Doub_I s, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(s, varname, matb);
	matb.close();
}


inline void save(Comp_I s, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open: " + matb.m_fname);
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, Llong(varname.size()));
	write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write dimension info
	write(fout, Llong(0));
	// write matrix data
	write(fout, s);
}

inline void save_matb(Comp_I s, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(s, varname, matb);
	matb.close();
}



// save() for containers
inline void save(VecChar_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(1));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(VecChar_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(VecInt_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(2));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(VecInt_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(VecLlong_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(VecLlong_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(VecDoub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(VecDoub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(VecComp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(VecComp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(SvecChar_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(1));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(SvecChar_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(SvecLlong_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(SvecLlong_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(SvecDoub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(SvecDoub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(SvecComp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(SvecComp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(vecInt_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(2));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(vecInt_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(vecLlong_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(vecLlong_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(vecDoub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(vecDoub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(vecComp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(vecComp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(DvecLlong_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(DvecLlong_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(DvecDoub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(DvecDoub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(DvecComp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(1));
	// write matrix data
	write(fout, (Llong)v.size());
	for (Long i = 0; i < (Long)v.size(); ++i)
	    write(fout, v[i]);
}

inline void save_matb(DvecComp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(CmatChar_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(1));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(CmatChar_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(CmatInt_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(2));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(CmatInt_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(CmatLlong_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(CmatLlong_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(CmatDoub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(CmatDoub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(CmatComp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(CmatComp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(MatChar_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(1));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(MatChar_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(MatInt_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(2));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(MatInt_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(MatLlong_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(MatLlong_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(MatDoub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(MatDoub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(MatComp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(MatComp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(ScmatInt_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(2));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(ScmatInt_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(ScmatLlong_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(ScmatLlong_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(ScmatDoub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(ScmatDoub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(ScmatComp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(ScmatComp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(DcmatInt_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(2));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(DcmatInt_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(DcmatLlong_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(DcmatLlong_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(DcmatDoub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(DcmatDoub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(DcmatComp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(2));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	for (Long j = 0; j < v.n1(); ++j)
	    for (Long i = 0; i < v.n0(); ++i)
	        write(fout, v(i, j));
}

inline void save_matb(DcmatComp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(Cmat3Int_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(2));
	// write shape info
	write(fout, Llong(3));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1()); write(fout, (Llong)v.n2());
	for (Long k = 0; k < v.n2(); ++k)
	    for (Long j = 0; j < v.n1(); ++j)
	        for (Long i = 0; i < v.n0(); ++i)
	            write(fout, v(i, j, k));
}

inline void save_matb(Cmat3Int_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(Cmat3Llong_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write shape info
	write(fout, Llong(3));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1()); write(fout, (Llong)v.n2());
	for (Long k = 0; k < v.n2(); ++k)
	    for (Long j = 0; j < v.n1(); ++j)
	        for (Long i = 0; i < v.n0(); ++i)
	            write(fout, v(i, j, k));
}

inline void save_matb(Cmat3Llong_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(Cmat3Doub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(3));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1()); write(fout, (Llong)v.n2());
	for (Long k = 0; k < v.n2(); ++k)
	    for (Long j = 0; j < v.n1(); ++j)
	        for (Long i = 0; i < v.n0(); ++i)
	            write(fout, v(i, j, k));
}

inline void save_matb(Cmat3Doub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(Cmat3Comp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(3));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1()); write(fout, (Llong)v.n2());
	for (Long k = 0; k < v.n2(); ++k)
	    for (Long j = 0; j < v.n1(); ++j)
	        for (Long i = 0; i < v.n0(); ++i)
	            write(fout, v(i, j, k));
}

inline void save_matb(Cmat3Comp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(Mat3Int_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(2));
	// write shape info
	write(fout, Llong(3));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1()); write(fout, (Llong)v.n2());
	for (Long k = 0; k < v.n2(); ++k)
	    for (Long j = 0; j < v.n1(); ++j)
	        for (Long i = 0; i < v.n0(); ++i)
	            write(fout, v(i, j, k));
}

inline void save_matb(Mat3Int_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(Mat3Llong_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(3));
	// write shape info
	write(fout, Llong(3));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1()); write(fout, (Llong)v.n2());
	for (Long k = 0; k < v.n2(); ++k)
	    for (Long j = 0; j < v.n1(); ++j)
	        for (Long i = 0; i < v.n0(); ++i)
	            write(fout, v(i, j, k));
}

inline void save_matb(Mat3Llong_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(Mat3Doub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(3));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1()); write(fout, (Llong)v.n2());
	for (Long k = 0; k < v.n2(); ++k)
	    for (Long j = 0; j < v.n1(); ++j)
	        for (Long i = 0; i < v.n0(); ++i)
	            write(fout, v(i, j, k));
}

inline void save_matb(Mat3Doub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(Mat3Comp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(3));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1()); write(fout, (Llong)v.n2());
	for (Long k = 0; k < v.n2(); ++k)
	    for (Long j = 0; j < v.n1(); ++j)
	        for (Long i = 0; i < v.n0(); ++i)
	            write(fout, v(i, j, k));
}

inline void save_matb(Mat3Comp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}

inline void save(Cmat4Doub_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(21));
	// write shape info
	write(fout, Llong(4));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	write(fout, (Llong)v.n2()); write(fout, (Llong)v.n3());
	for (Long l = 0; l < v.n3(); ++l)
	    for (Long k = 0; k < v.n2(); ++k)
	        for (Long j = 0; j < v.n1(); ++j)
	            for (Long i = 0; i < v.n0(); ++i)
	                write(fout, v(i, j, k, l));
}

inline void save_matb(Cmat4Doub_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}


inline void save(Cmat4Comp_I v, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matb.m_out;
	if (!fout.is_open())
	    SLS_ERR("matb file not open!");
	// record position
	matb.m_name.push_back(varname);
	matb.m_ind.push_back(fout.tellp());
	// write variable name info
	write(fout, (Llong)varname.size()); write(fout, varname);
	// write data type info
	write(fout, Llong(41));
	// write shape info
	write(fout, Llong(4));
	// write matrix data
	write(fout, (Llong)v.n0()); write(fout, (Llong)v.n1());
	write(fout, (Llong)v.n2()); write(fout, (Llong)v.n3());
	for (Long l = 0; l < v.n3(); ++l)
	    for (Long k = 0; k < v.n2(); ++k)
	        for (Long j = 0; j < v.n1(); ++j)
	            for (Long i = 0; i < v.n0(); ++i)
	                write(fout, v(i, j, k, l));
}

inline void save_matb(Cmat4Comp_I v, Str_I varname, Str_I matb_file, Bool_I replace = false)
{
	Matb matb(matb_file, "w", replace);
	save(v, varname, matb);
	matb.close();
}



// save string as VecChar
inline void save(Str_I str, Str_I varname, Matb_IO matb)
{
	if (matb.search(varname) >= 0)
	    SLS_ERR("variable already exist: " + varname);
	SvecChar_c sli; sli.set(str.data(), str.size());
	save(sli, varname, matb);
}


// read matb files
// return 0 if successful, -1 if variable not found
inline void load(Char_O s, Str_I varname, Matb_IO matb)
{
	ifstream &fin = matb.m_in;
	Long i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (1 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 0)
	    SLS_ERR("wrong dimension!");

	read(fin, s);
}

inline void load_matb(Char_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(Int_O s, Str_I varname, Matb_IO matb)
{
	ifstream &fin = matb.m_in;
	Long i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (2 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 0)
	    SLS_ERR("wrong dimension!");

	read(fin, s);
}

inline void load_matb(Int_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(Llong_O s, Str_I varname, Matb_IO matb)
{
	ifstream &fin = matb.m_in;
	Long i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (3 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 0)
	    SLS_ERR("wrong dimension!");

	read(fin, s);
}

inline void load_matb(Llong_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(Doub_O s, Str_I varname, Matb_IO matb)
{
	ifstream &fin = matb.m_in;
	Long i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (21 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 0)
	    SLS_ERR("wrong dimension!");

	read(fin, s);
}

inline void load_matb(Doub_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}


inline void load(Comp_O s, Str_I varname, Matb_IO matb)
{
	ifstream &fin = matb.m_in;
	Long i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (41 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 0)
	    SLS_ERR("wrong dimension!");

	read(fin, s);
}

inline void load_matb(Comp_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}


inline void load(VecChar_O v, Str_I varname, Matb_IO matb)
{
	ifstream &fin = matb.m_in;
	Long i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (1 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 1)
	    SLS_ERR("wrong dimension!");

	Long n = matb.m_size[i][0]; v.resize(n);
	// read var data
	for (Long i = 0; i < n; ++i)
	    read(fin, v[i]);
}

inline void load_matb(VecChar_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(VecInt_O v, Str_I varname, Matb_IO matb)
{
	ifstream &fin = matb.m_in;
	Long i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (2 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 1)
	    SLS_ERR("wrong dimension!");

	Long n = matb.m_size[i][0]; v.resize(n);
	// read var data
	for (Long i = 0; i < n; ++i)
	    read(fin, v[i]);
}

inline void load_matb(VecInt_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(VecLlong_O v, Str_I varname, Matb_IO matb)
{
	ifstream &fin = matb.m_in;
	Long i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (3 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 1)
	    SLS_ERR("wrong dimension!");

	Long n = matb.m_size[i][0]; v.resize(n);
	// read var data
	for (Long i = 0; i < n; ++i)
	    read(fin, v[i]);
}

inline void load_matb(VecLlong_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(VecDoub_O v, Str_I varname, Matb_IO matb)
{
	ifstream &fin = matb.m_in;
	Long i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (21 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 1)
	    SLS_ERR("wrong dimension!");

	Long n = matb.m_size[i][0]; v.resize(n);
	// read var data
	for (Long i = 0; i < n; ++i)
	    read(fin, v[i]);
}

inline void load_matb(VecDoub_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}


inline void load(VecComp_O v, Str_I varname, Matb_IO matb)
{
	ifstream &fin = matb.m_in;
	Long i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (41 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 1)
	    SLS_ERR("wrong dimension!");

	Long n = matb.m_size[i][0]; v.resize(n);
	// read var data
	for (Long i = 0; i < n; ++i)
	    read(fin, v[i]);
}

inline void load_matb(VecComp_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}


inline void load(MatInt_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, m, n;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (2 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 2)
	    SLS_ERR("wrong dimension!");

	m = matb.m_size[i][0]; n = matb.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
	    for (i = 0; i < m; ++i)
	        read(fin, a(i, j));
}

inline void load_matb(MatInt_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(MatLlong_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, m, n;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (3 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 2)
	    SLS_ERR("wrong dimension!");

	m = matb.m_size[i][0]; n = matb.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
	    for (i = 0; i < m; ++i)
	        read(fin, a(i, j));
}

inline void load_matb(MatLlong_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(MatDoub_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, m, n;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (21 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 2)
	    SLS_ERR("wrong dimension!");

	m = matb.m_size[i][0]; n = matb.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
	    for (i = 0; i < m; ++i)
	        read(fin, a(i, j));
}

inline void load_matb(MatDoub_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(MatComp_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, m, n;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (41 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 2)
	    SLS_ERR("wrong dimension!");

	m = matb.m_size[i][0]; n = matb.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
	    for (i = 0; i < m; ++i)
	        read(fin, a(i, j));
}

inline void load_matb(MatComp_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(Mat3Doub_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, k, m, n, q;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (21 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 3)
	    SLS_ERR("wrong dimension!");
	
	m = matb.m_size[i][0]; n = matb.m_size[i][1]; q = matb.m_size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
	    for (j = 0; j < n; ++j)
	        for (i = 0; i < m; ++i)
	            read(fin, a(i, j, k));
}

inline void load_matb(Mat3Doub_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(Mat3Comp_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, k, m, n, q;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (41 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 3)
	    SLS_ERR("wrong dimension!");
	
	m = matb.m_size[i][0]; n = matb.m_size[i][1]; q = matb.m_size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
	    for (j = 0; j < n; ++j)
	        for (i = 0; i < m; ++i)
	            read(fin, a(i, j, k));
}

inline void load_matb(Mat3Comp_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(CmatInt_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, m, n;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (2 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 2)
	    SLS_ERR("wrong dimension!");

	m = matb.m_size[i][0]; n = matb.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
	    for (i = 0; i < m; ++i)
	        read(fin, a(i, j));
}

inline void load_matb(CmatInt_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(CmatLlong_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, m, n;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (3 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 2)
	    SLS_ERR("wrong dimension!");

	m = matb.m_size[i][0]; n = matb.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
	    for (i = 0; i < m; ++i)
	        read(fin, a(i, j));
}

inline void load_matb(CmatLlong_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(CmatDoub_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, m, n;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (21 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 2)
	    SLS_ERR("wrong dimension!");

	m = matb.m_size[i][0]; n = matb.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
	    for (i = 0; i < m; ++i)
	        read(fin, a(i, j));
}

inline void load_matb(CmatDoub_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}


inline void load(CmatComp_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, m, n;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (41 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 2)
	    SLS_ERR("wrong dimension!");

	m = matb.m_size[i][0]; n = matb.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
	    for (i = 0; i < m; ++i)
	        read(fin, a(i, j));
}

inline void load_matb(CmatComp_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}


inline void load(Cmat3Int_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, k, m, n, q;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (2 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 3)
	    SLS_ERR("wrong dimension!");
	
	m = matb.m_size[i][0]; n = matb.m_size[i][1]; q = matb.m_size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
	    for (j = 0; j < n; ++j)
	        for (i = 0; i < m; ++i)
	            read(fin, a(i, j, k));
}

inline void load_matb(Cmat3Int_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(Cmat3Llong_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, k, m, n, q;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (3 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 3)
	    SLS_ERR("wrong dimension!");
	
	m = matb.m_size[i][0]; n = matb.m_size[i][1]; q = matb.m_size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
	    for (j = 0; j < n; ++j)
	        for (i = 0; i < m; ++i)
	            read(fin, a(i, j, k));
}

inline void load_matb(Cmat3Llong_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}

inline void load(Cmat3Doub_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, k, m, n, q;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (21 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 3)
	    SLS_ERR("wrong dimension!");
	
	m = matb.m_size[i][0]; n = matb.m_size[i][1]; q = matb.m_size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
	    for (j = 0; j < n; ++j)
	        for (i = 0; i < m; ++i)
	            read(fin, a(i, j, k));
}

inline void load_matb(Cmat3Doub_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}


inline void load(Cmat3Comp_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, k, m, n, q;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (41 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 3)
	    SLS_ERR("wrong dimension!");
	
	m = matb.m_size[i][0]; n = matb.m_size[i][1]; q = matb.m_size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
	    for (j = 0; j < n; ++j)
	        for (i = 0; i < m; ++i)
	            read(fin, a(i, j, k));
}

inline void load_matb(Cmat3Comp_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}


inline void load(Cmat4Doub_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, k, l, N1, N2, N3, N4;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (21 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 4)
	    SLS_ERR("wrong dimension!");
	
	N1 = matb.m_size[i][0]; N2 = matb.m_size[i][1]; N3 = matb.m_size[i][2]; N4 = matb.m_size[i][3];
	a.resize(N1, N2, N3, N4);
	// read var data
	for (l = 0; l < N4; ++l)
	    for (k = 0; k < N3; ++k)
	        for (j = 0; j < N2; ++j)
	            for (i = 0; i < N1; ++i)
	                read(fin, a(i, j, k, l));
}

inline void load_matb(Cmat4Doub_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}


inline void load(Cmat4Comp_O a, Str_I varname, Matb_IO matb)
{
	Long i, j, k, l, N1, N2, N3, N4;
	ifstream &fin = matb.m_in;
	i = matb.search(varname);
	if (i < 0)
	    throw Str("variable not found!");
	fin.seekg(matb.data_pos(i));

	if (41 != matb.m_type[i])
	    SLS_ERR("wrong type!");
	if (matb.m_size[i].size() != 4)
	    SLS_ERR("wrong dimension!");
	
	N1 = matb.m_size[i][0]; N2 = matb.m_size[i][1]; N3 = matb.m_size[i][2]; N4 = matb.m_size[i][3];
	a.resize(N1, N2, N3, N4);
	// read var data
	for (l = 0; l < N4; ++l)
	    for (k = 0; k < N3; ++k)
	        for (j = 0; j < N2; ++j)
	            for (i = 0; i < N1; ++i)
	                read(fin, a(i, j, k, l));
}

inline void load_matb(Cmat4Comp_O var, Str_I varname, Str_I matb_file)
{
	Matb matb(matb_file, "r");
	load(var, varname, matb);
	matb.close();
}



// convert a single .matb file to .matt file
// if replace = false and destination exists, then nothing will be done
// return 0 if successful, -1 if skipped
inline Long matb2matt(Str_I matb_name, Bool_I replace = false)
{
	Long N = matb_name.size();
	Str matt_name;
	if (matb_name.substr(N-5, 5) != ".matb")
	    SLS_ERR(matb_name + " : file does not have .matb extension!");
	matt_name = matb_name.substr(0, N - 1) + "t";
	if (file_exist(matt_name)) {
	    if (replace)
	        file_remove(matt_name);
	    else
	        return -1;
	}

	Matb matb(matb_name, "r");
	Matt matt(matt_name, "w");
	Long Nvar = matb.m_name.size();
	for (Long i = 0; i < Nvar; ++i) {
	    const Long &type = matb.m_type[i];
	    const Str &name = matb.m_name[i];
	    const Long Ndim = matb.m_size[i].size();
	    if (Ndim == 0) {
// scalars
	        if (type == 1) {
	            Char s;
	            load(s, name, matb); save(s, name, matt);
	            continue;
	        }

	        if (type == 2) {
	            Int s;
	            load(s, name, matb); save(s, name, matt);
	            continue;
	        }

	        if (type == 3) {
	            Llong s;
	            load(s, name, matb); save(s, name, matt);
	            continue;
	        }

	        if (type == 21) {
	            Doub s;
	            load(s, name, matb); save(s, name, matt);
	            continue;
	        }

	        if (type == 41) {
	            Comp s;
	            load(s, name, matb); save(s, name, matt);
	            continue;
	        }

	        SLS_ERR("not implemented!");
	    }

// containers
	    if (type == 1 && Ndim == 1) {
	        VecChar v(0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 2 && Ndim == 1) {
	        VecInt v(0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 3 && Ndim == 1) {
	        VecLlong v(0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 21 && Ndim == 1) {
	        VecDoub v(0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 41 && Ndim == 1) {
	        VecComp v(0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 2 && Ndim == 2) {
	        CmatInt v(0, 0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 3 && Ndim == 2) {
	        CmatLlong v(0, 0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 21 && Ndim == 2) {
	        CmatDoub v(0, 0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 41 && Ndim == 2) {
	        CmatComp v(0, 0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 2 && Ndim == 3) {
	        Cmat3Int v(0, 0, 0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 3 && Ndim == 3) {
	        Cmat3Llong v(0, 0, 0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 21 && Ndim == 3) {
	        Cmat3Doub v(0, 0, 0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 41 && Ndim == 3) {
	        Cmat3Comp v(0, 0, 0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 21 && Ndim == 4) {
	        Cmat4Doub v(0, 0, 0, 0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	    if (type == 41 && Ndim == 4) {
	        Cmat4Comp v(0, 0, 0, 0);
	        load(v, name, matb); save(v, name, matt);
	        continue;
	    }

	}
	matb.close(); matt.close();
	return 0;
}

// convert a single .matb file to .matt file
// if replace = false and destination exists, then nothing will be done
// return 0 if successful, -1 if skipped
inline Long matt2matb(Str_I matt_name, Bool_I replace = false)
{
	Long N = matt_name.size();
	Str matb_name;
	if (matt_name.substr(N-5, 5) != ".matt")
	    SLS_ERR(matt_name + " : file does not have .matt extension!");
	matb_name = matt_name.substr(0, N - 1) + "b";
	if (file_exist(matb_name)) {
	    if (replace)
	        file_remove(matb_name);
	    else
	        return -1;
	}
	Matt matt(matt_name, "r");
	Matb matb(matb_name, "w");
	Long Nvar = matt.m_name.size();
	for (Long i = 0; i < Nvar; ++i) {
	    const Long &type = matt.m_type[i];
	    const Str &name = matt.m_name[i];
	    const Long Ndim = matt.m_size[i].size();
	    if (Ndim == 0) {
// scalars
	        if (type == 1) {
	            Char s{};
	            load(s, name, matt); save(s, name, matb);
	            continue;
	        }

	        if (type == 2) {
	            Int s{};
	            load(s, name, matt); save(s, name, matb);
	            continue;
	        }

	        if (type == 3) {
	            Llong s{};
	            load(s, name, matt); save(s, name, matb);
	            continue;
	        }

	        if (type == 21) {
	            Doub s{};
	            load(s, name, matt); save(s, name, matb);
	            continue;
	        }

	        if (type == 41) {
	            Comp s{};
	            load(s, name, matt); save(s, name, matb);
	            continue;
	        }

	        SLS_ERR("not implemented!");
	    }

// containers
	    if (type == 1 && Ndim == 1) {
	        VecChar v(0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 2 && Ndim == 1) {
	        VecInt v(0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 3 && Ndim == 1) {
	        VecLlong v(0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 21 && Ndim == 1) {
	        VecDoub v(0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 41 && Ndim == 1) {
	        VecComp v(0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 2 && Ndim == 2) {
	        CmatInt v(0, 0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 3 && Ndim == 2) {
	        CmatLlong v(0, 0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 21 && Ndim == 2) {
	        CmatDoub v(0, 0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 41 && Ndim == 2) {
	        CmatComp v(0, 0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 2 && Ndim == 3) {
	        Cmat3Int v(0, 0, 0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 3 && Ndim == 3) {
	        Cmat3Llong v(0, 0, 0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 21 && Ndim == 3) {
	        Cmat3Doub v(0, 0, 0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 41 && Ndim == 3) {
	        Cmat3Comp v(0, 0, 0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 21 && Ndim == 4) {
	        Cmat4Doub v(0, 0, 0, 0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	    if (type == 41 && Ndim == 4) {
	        Cmat4Comp v(0, 0, 0, 0);
	        load(v, name, matt); save(v, name, matb);
	        continue;
	    }

	}
	matt.close(); matb.close();
	return 0;
}

} // namespace slisc
#endif
