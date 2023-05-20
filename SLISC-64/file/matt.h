// save vectors and matrices to ".matt" file

#pragma once
#include "../arith/scalar_arith.h"
#include "../file/file.h"

#if !(defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(__MSYS__))

#ifndef SLS_MATT_DEFAULT_PREC
// 17 digits decimal is enough to represent any double
#define SLS_MATT_DEFAULT_PREC 17
#endif

namespace slisc {
// Matt class for text mode
class Matt {
public:
	Matt();
	Matt(Str_I fname, const char *rw, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false);
	// delimiter between two numbers, can only be ' ' for now.
	static const char dlm = ' ';
	char m_rw; // 'r' for read 'w' for write
	ifstream m_in; // read file
	ofstream m_out; // write file
	Str fname; // name of the opened file
	vector<Str> m_name; // variable names
	vector<Int> m_type; // variable types
	vector<vector<Long>> m_size; // variable dimensions
	vector<Long> m_ind; // variable positions (line indices)

	// open a file
	void open(Str_I fname, const char *rw, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false);

	bool isopen();

	// close a file, if not called, will be called in destructor
	void close();

	// ===== internal functions =====

	// get var names and positions from the end of the file
	Long size();
	void get_profile();
	Long data_pos(Long_I var_ind); // find position of the ind-th variable, i.e. seekg() of the first element

	// search a variable by name, return index to m_name[i]
	// return -1 if not found
	Int search(Str_I name);

	~Matt();
};

typedef const Matt &Matt_I;
typedef Matt &Matt_O, &Matt_IO;

inline void matt_write_scalar(Char_I s, ofstream &m_out)
{
	m_out << to_num(s) << Matt::dlm;
}

inline void matt_write_scalar(Int_I s, ofstream &m_out)
{
	m_out << to_num(s) << Matt::dlm;
}

inline void matt_write_scalar(Llong_I s, ofstream &m_out)
{
	m_out << to_num(s) << Matt::dlm;
}

inline void matt_write_scalar(Doub_I s, ofstream &m_out)
{
	if (isinf(s))
		throw Str("infinity is not supported in matt file!");
	if (isnan(s))
		throw Str("NaN is not supported in matt file!");
	m_out << to_num(s) << Matt::dlm;
}

inline void matt_write_scalar(Comp_I s, ofstream &m_out)
{
	if (isinf(real(s)) || isinf(imag(s)))
		throw Str("infinity is not supported in matt file!");
	if (isnan(real(s)) || isnan(imag(s)))
		throw Str("NaN is not supported in matt file!");
	if (imag(s) == 0)
		m_out << real(s) << Matt::dlm;
	else if (imag(s) < 0)
		m_out << real(s) << imag(s) << "i ";
	else
		m_out << real(s) << '+' << imag(s) << "i ";
}


inline void matt_read_scalar(Char_O s, ifstream &m_in)
{
	if (!m_in.good())
		SLS_ERR("unknown!");
	Int temp; m_in >> temp; s = (Char)temp;
}

inline void matt_read_scalar(Int_O s, ifstream &m_in)
{
	if (!m_in.good())
		SLS_ERR("unknown!");
	m_in >> s;
}

inline void matt_read_scalar(Llong_O s, ifstream &m_in)
{
	if (!m_in.good())
		SLS_ERR("unknown!");
	m_in >> s;
}

inline void matt_read_scalar(Doub_O s, ifstream &m_in)
{
	if (!m_in.good())
		SLS_ERR("unknown!");
	m_in >> s;
}

// format : "[Doub][+/-][Doub]i"
inline void matt_read_scalar(Comp_O c, ifstream &m_in)
{
	if (!m_in.good())
		SLS_ERR("unknown! ");
	static Str str;
	m_in >> str;
	if (str.empty()) SLS_ERR("unknown!");
	Long ind = 0;
	Doub x;
	Long ind1 = str2Doub(x, str, ind); c.real(x);
	if (ind1 < 0) SLS_ERR("unknown! " + str.substr(ind));
	if (ind1 == size(str)) return;
	Long ind2 = str2Doub(x, str, ind1); c.imag(x);
	if (ind2 < 0) SLS_ERR("unknown! " + str.substr(ind1));
	if (str.at(ind2) != 'i') SLS_ERR("unknown!");
	m_in.ignore(100, Matt::dlm);
}


// read the next variable after previous delimiter
inline Long scanInverse(ifstream &fin)
{
	char c;
	Long ind, i, N;

	ind = fin.tellg();
	for (i = 2; i < 100; ++i) {
		fin.seekg(ind - i); c = fin.get();
		if (c == Matt::dlm)
			break;
	}
	fin >> N;
	fin.seekg(ind - i);
	return N;
}

struct Matt_file_not_complete {};

inline Long Matt::size()
{
	return m_ind.size();
}

inline void Matt::get_profile()
{
	Int i, j, n, temp;
	vector<Long> size;
	Str name;

	// read number of variables and their positions
	m_in.seekg(0, m_in.end);
	Long gmax = m_in.tellg();
	// check end mark
	m_in.seekg(gmax-2);
	char c1 = m_in.get(), c2 = m_in.get();
	if (c1 != Matt::dlm || c2 != Matt::dlm) {
		throw Matt_file_not_complete();
	}
	m_in.seekg(gmax-2);
	Long Nvar = scanInverse(m_in);
	if (Nvar < 1)
		SLS_ERR("unknown!");
	m_ind.resize(Nvar);
	for (i = 0; i < Nvar; ++i) {
		m_ind[i] = scanInverse(m_in);
		if (m_ind[i] >= gmax || m_ind[i] < 0)
			SLS_ERR("unknown!");
		if (i > 0 && m_ind[i] <= m_ind[i - 1])
			SLS_ERR("unknown!");
	}

	// loop through each variable
	for (i = 0; i < Nvar; ++i) {
		m_in.seekg(m_ind[i]);
		// read var name
		m_in >> n;
		name.resize(0);
		for (j = 0; j < n; ++j) {
			m_in >> temp;
			if (temp <= 0 || temp > 127)
				SLS_ERR("unknown!");
			name.push_back((char)temp);
		}
		m_name.push_back(name);
		// read var type
		m_in >> temp;
		if (temp < 0 || temp > 100)
			SLS_ERR("unknown!");
		m_type.push_back(temp);
		// read var dim
		m_in >> n;
		if (n < 0 || n > 10)
			SLS_ERR("unknown!");
		size.resize(0);
		for (j = 0; j < n; ++j) {
			m_in >> temp;
			if (temp < 0)
				SLS_ERR("unknown!");
			size.push_back(temp);
		}
		m_size.push_back(size);
	}
}

inline Long Matt::data_pos(Long_I i)
{
	Int temp, n;
	if (m_rw != 'r')
		SLS_ERR("not implemented!");
	m_in.seekg(m_ind[i]);
	// read var name
	m_in >> n;
	for (Long j = 0; j < n; ++j)
		m_in >> temp;
	// read var type
	m_in >> temp;
	// read var dim
	m_in >> n;
	for (Long j = 0; j < n; ++j)
		m_in >> temp;
	return m_in.tellg();
}

// search variable in file by name
inline Int Matt::search(Str_I name)
{
	for (Int i = 0; i < size(); ++i)
		if (name == m_name[i])
			return i;
	return -1;
}

inline Matt::Matt() {}

inline Matt::Matt(Str_I fname, const char * rw, Int_I precision, Bool_I replace)
{ open(fname, rw, precision, replace); }

inline void Matt::open(Str_I fname, const char *rw, Int_I precision, Bool_I replace)
{
	if (isopen())
		close();
	this->fname = fname;
	if (fname.substr(fname.size()-5) != ".matt")
		SLS_ERR("file must have \".matt\" extension!");
	if (rw[0] == 'w') {

#ifndef SLS_MATT_REPLACE
		if (!replace && file_exist(fname)) {
			while (true) {
				if (file_exist(fname)) {
					SLS_WARN("\n\nfile [" + fname + "] already exist! delete file to continue...\n"
						"  (define SLS_MATT_REPLACE to replace file by default)\n\n");
				}
				else {
					break;
				}
				pause(10);
			}
		}
#endif
		m_rw = 'w';
		m_out.open(fname);
		if (!m_out.good())
			SLS_ERR("error: file not created (directory does not exist ?): " + fname);
		m_out.precision(precision);
	}
	else {
		m_rw = 'r';
		m_in.open(fname);
		if (!m_in.good())
			SLS_ERR("error: file not found: " + fname);
		m_in.precision(SLS_MATT_DEFAULT_PREC);
		get_profile(); // get var names
	}
}

inline bool Matt::isopen()
{
	return m_in.is_open() != m_out.is_open();
}

inline void Matt::close()
{
	if (m_rw == 'w') {
		ofstream &fout = m_out;
		// write position of variables
		for (Long i = m_ind.size() - 1; i >= 0; --i)
			fout << m_ind[i] << dlm;
		// write number of variables
		fout << size();
		// mark end-of-file
		fout << Matt::dlm << Matt::dlm;
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

inline Matt::~Matt()
{
	if (isopen())
		close();
	else if (m_in.is_open() && m_out.is_open())
		SLS_ERR("unknown!");
}

// save() functions
inline void save(Char_I s, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open: " + matt.fname);
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 1 << Matt::dlm;
	// write dimension info
	fout << 0 << Matt::dlm;
	// write matrix data
	try {matt_write_scalar(s, fout);}
	catch (Str msg) {
		SLS_ERR("error while saving '" + varname + "': " + msg);
	}
}

inline void save_matt(Char_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(Int_I s, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open: " + matt.fname);
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 2 << Matt::dlm;
	// write dimension info
	fout << 0 << Matt::dlm;
	// write matrix data
	try {matt_write_scalar(s, fout);}
	catch (Str msg) {
		SLS_ERR("error while saving '" + varname + "': " + msg);
	}
}

inline void save_matt(Int_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(Llong_I s, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open: " + matt.fname);
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 3 << Matt::dlm;
	// write dimension info
	fout << 0 << Matt::dlm;
	// write matrix data
	try {matt_write_scalar(s, fout);}
	catch (Str msg) {
		SLS_ERR("error while saving '" + varname + "': " + msg);
	}
}

inline void save_matt(Llong_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(Doub_I s, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open: " + matt.fname);
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 21 << Matt::dlm;
	// write dimension info
	fout << 0 << Matt::dlm;
	// write matrix data
	try {matt_write_scalar(s, fout);}
	catch (Str msg) {
		SLS_ERR("error while saving '" + varname + "': " + msg);
	}
}

inline void save_matt(Doub_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(Comp_I s, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open: " + matt.fname);
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 41 << Matt::dlm;
	// write dimension info
	fout << 0 << Matt::dlm;
	// write matrix data
	try {matt_write_scalar(s, fout);}
	catch (Str msg) {
		SLS_ERR("error while saving '" + varname + "': " + msg);
	}
}

inline void save_matt(Comp_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(VecChar_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 1 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(VecChar_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(VecInt_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 2 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(VecInt_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(VecLlong_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 3 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(VecLlong_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(VecDoub_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 21 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(VecDoub_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(VecComp_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 41 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(VecComp_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(SvecChar_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 1 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(SvecChar_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(SvecInt_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 2 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(SvecInt_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(SvecLlong_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 3 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(SvecLlong_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(SvecDoub_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 21 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(SvecDoub_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(SvecComp_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 41 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(SvecComp_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(vecInt_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 2 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(vecInt_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(vecLlong_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 3 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(vecLlong_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(vecDoub_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 21 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(vecDoub_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(vecComp_I v, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 41 << Matt::dlm;
	// write dimension info
	n = v.size();
	fout << 1 << Matt::dlm << n << Matt::dlm;
	// write matrix data
	for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save_matt(vecComp_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(MatInt_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 2 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(MatInt_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(MatLlong_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 3 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(MatLlong_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(MatDoub_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 21 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(MatDoub_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(MatComp_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 41 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(MatComp_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(CmatInt_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 2 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(CmatInt_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(CmatLlong_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 3 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(CmatLlong_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(CmatDoub_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 21 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(CmatDoub_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(CmatComp_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 41 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(CmatComp_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(Cmat3Int_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long i, j, k, N1 = a.n0(), N2 = a.n1(), N3 = a.n2();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 2 << Matt::dlm;
	// write dimension info
	fout << 3 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm << N3 << Matt::dlm;
	// write matrix data
	for (k = 0; k < N3; ++k)
		for (j = 0; j < N2; ++j)
			for (i = 0; i < N1; ++i)
				matt_write_scalar(a(i, j, k), fout);
}

inline void save_matt(Cmat3Int_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(Cmat3Llong_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long i, j, k, N1 = a.n0(), N2 = a.n1(), N3 = a.n2();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 3 << Matt::dlm;
	// write dimension info
	fout << 3 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm << N3 << Matt::dlm;
	// write matrix data
	for (k = 0; k < N3; ++k)
		for (j = 0; j < N2; ++j)
			for (i = 0; i < N1; ++i)
				matt_write_scalar(a(i, j, k), fout);
}

inline void save_matt(Cmat3Llong_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(Cmat3Doub_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long i, j, k, N1 = a.n0(), N2 = a.n1(), N3 = a.n2();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 21 << Matt::dlm;
	// write dimension info
	fout << 3 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm << N3 << Matt::dlm;
	// write matrix data
	for (k = 0; k < N3; ++k)
		for (j = 0; j < N2; ++j)
			for (i = 0; i < N1; ++i)
				matt_write_scalar(a(i, j, k), fout);
}

inline void save_matt(Cmat3Doub_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(Cmat3Comp_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long i, j, k, N1 = a.n0(), N2 = a.n1(), N3 = a.n2();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 41 << Matt::dlm;
	// write dimension info
	fout << 3 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm << N3 << Matt::dlm;
	// write matrix data
	for (k = 0; k < N3; ++k)
		for (j = 0; j < N2; ++j)
			for (i = 0; i < N1; ++i)
				matt_write_scalar(a(i, j, k), fout);
}

inline void save_matt(Cmat3Comp_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(Cmat4Doub_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long i, j, k, l, N1 = a.n0(), N2 = a.n1(), N3 = a.n2(), N4 = a.n3();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 21 << Matt::dlm;
	// write dimension info
	fout << 4 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm << N3 << Matt::dlm << N4 << Matt::dlm;
	// write matrix data
	for (l = 0; l < N4; ++l)
		for (k = 0; k < N3; ++k)
			for (j = 0; j < N2; ++j)
				for (i = 0; i < N1; ++i)
					matt_write_scalar(a(i, j, k, l), fout);
}

inline void save_matt(Cmat4Doub_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(Cmat4Comp_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long i, j, k, l, N1 = a.n0(), N2 = a.n1(), N3 = a.n2(), N4 = a.n3();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (i = 0; i < n; ++i) {
		fout << to_num(varname.at(i)) << Matt::dlm;
	}
	// write data type info
	fout << 41 << Matt::dlm;
	// write dimension info
	fout << 4 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm << N3 << Matt::dlm << N4 << Matt::dlm;
	// write matrix data
	for (l = 0; l < N4; ++l)
		for (k = 0; k < N3; ++k)
			for (j = 0; j < N2; ++j)
				for (i = 0; i < N1; ++i)
					matt_write_scalar(a(i, j, k, l), fout);
}

inline void save_matt(Cmat4Comp_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(ScmatInt_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 2 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(ScmatInt_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(ScmatLlong_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 3 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(ScmatLlong_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(ScmatDoub_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 21 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(ScmatDoub_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(ScmatComp_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 41 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(ScmatComp_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(DcmatInt_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 2 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(DcmatInt_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(DcmatLlong_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 3 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(DcmatLlong_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(DcmatDoub_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 21 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(DcmatDoub_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}

inline void save(DcmatComp_I a, Str_I varname, Matt_IO matt)
{
	if (matt.search(varname) >= 0)
		SLS_ERR("variable already exist: " + varname);
	Long N1 = a.n0(), N2 = a.n1();
	ofstream &fout = matt.m_out;
	if (!fout.is_open())
		SLS_ERR("matt file not open!");
	matt.m_name.push_back(varname);
	matt.m_ind.push_back(fout.tellp());
	// write variable name info
	Long n = varname.size();
	fout << n << Matt::dlm;
	for (Long i = 0; i < n; ++i)
		fout << to_num(varname.at(i)) << Matt::dlm;
	// write data type info
	fout << 41 << Matt::dlm;
	// write dimension info
	fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
	// write matrix data
	for (Long j = 0; j < N2; ++j)
		for (Long i = 0; i < N1; ++i)
			matt_write_scalar(a(i, j), fout);
}

inline void save_matt(DcmatComp_I s, Str_I varname, Str_I matt_file, Int_I precision = SLS_MATT_DEFAULT_PREC, Bool_I replace = false)
{
	Matt matt(matt_file, "w", precision, replace);
	save(s, varname, matt);
	matt.close();
}


inline void save(Str_I str, Str_I varname, Matt_IO matt)
{
	SvecCharC sli; sli.set((Char*)str.data(), str.size());
	save(sli, varname, matt);
}

// read matt files
inline void load(Char_O s, Str_I varname, Matt_IO matt)
{
	Long i;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (1 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 0)
		SLS_ERR("wrong dimension!");

	matt_read_scalar(s, fin);
}

inline void load_matt(Char_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(Int_O s, Str_I varname, Matt_IO matt)
{
	Long i;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (2 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 0)
		SLS_ERR("wrong dimension!");

	matt_read_scalar(s, fin);
}

inline void load_matt(Int_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(Llong_O s, Str_I varname, Matt_IO matt)
{
	Long i;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (3 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 0)
		SLS_ERR("wrong dimension!");

	matt_read_scalar(s, fin);
}

inline void load_matt(Llong_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(Doub_O s, Str_I varname, Matt_IO matt)
{
	Long i;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (21 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 0)
		SLS_ERR("wrong dimension!");

	matt_read_scalar(s, fin);
}

inline void load_matt(Doub_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(Comp_O s, Str_I varname, Matt_IO matt)
{
	Long i;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (41 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 0)
		SLS_ERR("wrong dimension!");

	matt_read_scalar(s, fin);
}

inline void load_matt(Comp_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(VecChar_O v, Str_I varname, Matt_IO matt)
{
	ifstream &fin = matt.m_in;
	Long i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (1 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 1)
		SLS_ERR("wrong dimension!");

	Long n = matt.m_size[i][0]; v.resize(n);
	// read var data
	for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
}

inline void load_matt(VecChar_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(VecInt_O v, Str_I varname, Matt_IO matt)
{
	ifstream &fin = matt.m_in;
	Long i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (2 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 1)
		SLS_ERR("wrong dimension!");

	Long n = matt.m_size[i][0]; v.resize(n);
	// read var data
	for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
}

inline void load_matt(VecInt_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(VecLlong_O v, Str_I varname, Matt_IO matt)
{
	ifstream &fin = matt.m_in;
	Long i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (3 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 1)
		SLS_ERR("wrong dimension!");

	Long n = matt.m_size[i][0]; v.resize(n);
	// read var data
	for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
}

inline void load_matt(VecLlong_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(VecDoub_O v, Str_I varname, Matt_IO matt)
{
	ifstream &fin = matt.m_in;
	Long i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (21 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 1)
		SLS_ERR("wrong dimension!");

	Long n = matt.m_size[i][0]; v.resize(n);
	// read var data
	for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
}

inline void load_matt(VecDoub_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(VecComp_O v, Str_I varname, Matt_IO matt)
{
	ifstream &fin = matt.m_in;
	Long i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (41 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 1)
		SLS_ERR("wrong dimension!");

	Long n = matt.m_size[i][0]; v.resize(n);
	// read var data
	for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
}

inline void load_matt(VecComp_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(MatInt_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, m, n;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (2 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 2)
		SLS_ERR("wrong dimension!");

	m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
}

inline void load_matt(MatInt_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(MatLlong_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, m, n;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (3 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 2)
		SLS_ERR("wrong dimension!");

	m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
}

inline void load_matt(MatLlong_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(MatDoub_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, m, n;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (21 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 2)
		SLS_ERR("wrong dimension!");

	m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
}

inline void load_matt(MatDoub_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(MatComp_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, m, n;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (41 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 2)
		SLS_ERR("wrong dimension!");

	m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
}

inline void load_matt(MatComp_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(CmatInt_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, m, n;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (2 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 2)
		SLS_ERR("wrong dimension!");

	m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
}

inline void load_matt(CmatInt_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(CmatLlong_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, m, n;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (3 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 2)
		SLS_ERR("wrong dimension!");

	m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
}

inline void load_matt(CmatLlong_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(CmatDoub_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, m, n;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (21 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 2)
		SLS_ERR("wrong dimension!");

	m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
}

inline void load_matt(CmatDoub_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(CmatComp_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, m, n;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (41 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 2)
		SLS_ERR("wrong dimension!");

	m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
	// read var data
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
}

inline void load_matt(CmatComp_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(Cmat3Int_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, k, m, n, q;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (2 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 3)
		SLS_ERR("wrong dimension!");
	
	m = matt.m_size[i][0]; n = matt.m_size[i][1]; q = matt.m_size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
		for (j = 0; j < n; ++j)
			for (i = 0; i < m; ++i)
				matt_read_scalar(a(i, j, k), fin);
}

inline void load_matt(Cmat3Int_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(Cmat3Llong_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, k, m, n, q;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (3 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 3)
		SLS_ERR("wrong dimension!");
	
	m = matt.m_size[i][0]; n = matt.m_size[i][1]; q = matt.m_size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
		for (j = 0; j < n; ++j)
			for (i = 0; i < m; ++i)
				matt_read_scalar(a(i, j, k), fin);
}

inline void load_matt(Cmat3Llong_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(Cmat3Doub_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, k, m, n, q;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (21 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 3)
		SLS_ERR("wrong dimension!");
	
	m = matt.m_size[i][0]; n = matt.m_size[i][1]; q = matt.m_size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
		for (j = 0; j < n; ++j)
			for (i = 0; i < m; ++i)
				matt_read_scalar(a(i, j, k), fin);
}

inline void load_matt(Cmat3Doub_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(Cmat3Comp_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, k, m, n, q;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (41 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 3)
		SLS_ERR("wrong dimension!");
	
	m = matt.m_size[i][0]; n = matt.m_size[i][1]; q = matt.m_size[i][2];
	a.resize(m, n, q);
	// read var data
	for (k = 0; k < q; ++k)
		for (j = 0; j < n; ++j)
			for (i = 0; i < m; ++i)
				matt_read_scalar(a(i, j, k), fin);
}

inline void load_matt(Cmat3Comp_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(Cmat4Doub_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, k, l, N1, N2, N3, N4;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (21 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 4)
		SLS_ERR("wrong dimension!");
	
	N1 = matt.m_size[i][0]; N2 = matt.m_size[i][1]; N3 = matt.m_size[i][2]; N4 = matt.m_size[i][3];
	a.resize(N1, N2, N3, N4);
	// read var data
	for (l = 0; l < N4; ++l)
		for (k = 0; k < N3; ++k)
			for (j = 0; j < N2; ++j)
				for (i = 0; i < N1; ++i)
					matt_read_scalar(a(i, j, k, l), fin);
}

inline void load_matt(Cmat4Doub_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

inline void load(Cmat4Comp_O a, Str_I varname, Matt_IO matt)
{
	Long i, j, k, l, N1, N2, N3, N4;
	ifstream &fin = matt.m_in;
	i = matt.search(varname);
	if (i < 0)
		throw Str("variable not found!");
	fin.seekg(matt.data_pos(i));

	if (41 < matt.m_type[i])
		SLS_ERR("wrong type!");
	if (matt.m_size[i].size() != 4)
		SLS_ERR("wrong dimension!");
	
	N1 = matt.m_size[i][0]; N2 = matt.m_size[i][1]; N3 = matt.m_size[i][2]; N4 = matt.m_size[i][3];
	a.resize(N1, N2, N3, N4);
	// read var data
	for (l = 0; l < N4; ++l)
		for (k = 0; k < N3; ++k)
			for (j = 0; j < N2; ++j)
				for (i = 0; i < N1; ++i)
					matt_read_scalar(a(i, j, k, l), fin);
}

inline void load_matt(Cmat4Comp_O var, Str_I varname, Str_I matt_file)
{
	Matt matt(matt_file, "r");
	load(var, varname, matt);
	matt.close();
}

} // namespace slisc

#endif
