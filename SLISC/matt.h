// save vectors and matrices defined in "nr3.h" to ".mat" or ".matt" files.
// see README.txt for details

#pragma once
#include "file.h"

namespace slisc {

// Matt class for text mode
class Matt {
public:
    Matt();
    Matt(Str_I fname, Char_I *rw, Int_I precision = 17);
    // delimiter between two numbers, can only be ' ' for now.
    static const Char dlm = ' ';
    Char m_rw; // 'r' for read 'w' for write
    ifstream m_in; // read file
    ofstream m_out; // write file
    Int m_n; // variable numbers
    Str fname; // name of the opened file
    vector<Str> m_name; // variable names
    vector<Int> m_type; // variable types
    vector<vector<Long>> m_size; // variable dimensions
    vector<Long> m_ind; // variable positions (line indices)

    // open a file, return 0 if success
    // return -2 if reading failed (e.g. file is not finished, wrong format)
    Int open(Str_I fname, Char_I *rw, Int_I precision = 17);

	Bool isopen();

    // close a file, if not called, will be called in destructor
    void close();

    // ===== internal functions =====

    // get var names and positions from the end of the file
    // after return, matt.m_ind[i] points to the first matrix element;
    // return 0 if successful, return -1 if failed
    Int get_profile();

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
    m_out << to_num(s) << Matt::dlm;
}

inline void matt_write_scalar(Comp_I s, ofstream &m_out)
{
	if (imag(s) == 0)
		m_out << real(s) << Matt::dlm;
	else if (imag(s) < 0)
		m_out << real(s) << imag(s) << "i ";
	else
		m_out << real(s) << '+' << imag(s) << "i ";
}


inline void matt_read_scalar(Char_O s, ifstream &m_in)
{
    Int temp; m_in >> temp; s = (Char)temp;
}

inline void matt_read_scalar(Int_O s, ifstream &m_in)
{
    m_in >> s;
}

inline void matt_read_scalar(Llong_O s, ifstream &m_in)
{
    m_in >> s;
}

inline void matt_read_scalar(Doub_O s, ifstream &m_in)
{
    m_in >> s;
}

inline void matt_read_scalar(Comp_O c, ifstream &m_in)
{
    Doub cr = 0, ci = 0;
    Char ch;
    m_in >> cr;
    ch = m_in.get();
    if (ch == Matt::dlm) {
        c = cr; return;
    }
    m_in >> ci;
    if (ch == '-')
        ci *= -1.;
    c = Comp(cr, ci);
    m_in.ignore(100, Matt::dlm);
}


// read the next variable after previous delimiter
Long scanInverse(ifstream &fin)
{
    Char c;
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

inline Int Matt::get_profile()
{
    Int i, j, n, temp;
    vector<Long> size;
    Str name;
    ifstream &fin = m_in;

    // read number of variables and their positions
    fin.seekg(0, fin.end);
    Long gmax = fin.tellg();
    m_n = (Int)scanInverse(fin);
    if (m_n < 1)
        return -1;
    m_ind.resize(m_n);
    for (i = 0; i < m_n; ++i) {
        m_ind[i] = scanInverse(fin);
        if (m_ind[i] >= gmax || m_ind[i] < 0)
            return -1;
        if (i > 0 && m_ind[i] <= m_ind[i - 1])
            return -1;
    }

    // loop through each variable
    for (i = 0; i < m_n; ++i) {
        fin.seekg(m_ind[i]);
        // read var name
        fin >> n;
        name.resize(0);
        for (j = 0; j < n; ++j) {
            fin >> temp;
            if (temp <= 0 || temp > 127)
                return -1;
            name.push_back((Char)temp);
        }
        m_name.push_back(name);
        // read var type
        fin >> temp;
        if (temp < 0 || temp > 100)
            return -1;
        m_type.push_back(temp);
        // read var dim
        fin >> n;
        if (n < 0 || n > 10)
            return -1;
        size.resize(0);
        for (j = 0; j < n; ++j) {
            fin >> temp;
            if (temp < 0)
                return -1;
            size.push_back(temp);
        }
        m_size.push_back(size);
        m_ind[i] = fin.tellg();
    }
	return 0;
}

// search variable in file by name
inline Int Matt::search(Str_I name)
{
    for (Int i = 0; i < m_n; ++i)
        if (name == m_name[i])
            return i;
    SLS_WARN("variable name not found: " + name + ", file : " + fname);
    return -1;
}

inline Matt::Matt() {}

inline Matt::Matt(Str_I fname, Char_I * rw, Int_I precision)
{ open(fname, rw, precision); }

Int Matt::open(Str_I fname, Char_I *rw, Int_I precision)
{
	if (isopen())
		close();
    this->fname = fname;
    if (rw[0] == 'w') {

#ifndef SLS_MATT_REPLACE
        if (file_exist(fname)) {
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
        m_n = 0;
        m_out = ofstream(fname);
        if (!m_out.good())
            SLS_ERR("error: file not created (directory does not exist ?): " + fname);
        m_out.precision(precision);
    }
    else {
        m_rw = 'r';
        m_in = ifstream(fname);
        if (!m_in.good())
            SLS_ERR("error: file not found: " + fname);
        m_in.precision(17);
        return get_profile(); // get var names
    }
    return 0;
}

inline Bool Matt::isopen()
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
        fout << m_n;
        m_out.close();
    }
    else {
        m_in.close();
    }
    m_rw = '\0';
    m_n = 0;
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
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open: " + matt.fname);
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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
	matt_write_scalar(s, fout);
}

inline void save(Char_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Int_I s, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open: " + matt.fname);
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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
	matt_write_scalar(s, fout);
}

inline void save(Int_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Llong_I s, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open: " + matt.fname);
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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
	matt_write_scalar(s, fout);
}

inline void save(Llong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Doub_I s, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open: " + matt.fname);
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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
	matt_write_scalar(s, fout);
}

inline void save(Doub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Comp_I s, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open: " + matt.fname);
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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
	matt_write_scalar(s, fout);
}

inline void save(Comp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(VecChar_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(VecChar_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(VecInt_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(VecInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(VecLlong_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(VecLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(VecDoub_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(VecDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(VecComp_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(VecComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(SvecChar_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(SvecChar_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(SvecInt_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(SvecInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(SvecLlong_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(SvecLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(SvecDoub_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(SvecDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(SvecComp_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(SvecComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(MatInt_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(MatInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(MatLlong_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(MatLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(MatDoub_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(MatDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(MatComp_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(MatComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(CmatInt_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(CmatInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(CmatLlong_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(CmatLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(CmatDoub_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(CmatDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(CmatComp_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(CmatComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Cmat3Int_I a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, N1 = a.n1(), N2 = a.n2(), N3 = a.n3();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(Cmat3Int_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Cmat3Llong_I a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, N1 = a.n1(), N2 = a.n2(), N3 = a.n3();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(Cmat3Llong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Cmat3Doub_I a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, N1 = a.n1(), N2 = a.n2(), N3 = a.n3();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(Cmat3Doub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Cmat3Comp_I a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, N1 = a.n1(), N2 = a.n2(), N3 = a.n3();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(Cmat3Comp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(ScmatInt_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(ScmatInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(ScmatLlong_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(ScmatLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(ScmatDoub_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(ScmatDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(ScmatComp_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(ScmatComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(DcmatInt_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(DcmatInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(DcmatLlong_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(DcmatLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(DcmatDoub_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(DcmatDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(DcmatComp_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
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

inline void save(DcmatComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}


inline void save(Str_I str, Str_I varname, Matt_IO matt)
{
    SvecChar_c sli; sli.set(str.data(), str.size());
    save(sli, varname, matt);
}

// read matt files
// return 0 if successful, -1 if variable not found
inline Int load(Char_O s, Str_I varname, Matt_IO matt)
{
    Long i;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (1 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 0)
        SLS_ERR("wrong dimension!");

    matt_read_scalar(s, fin);
    return 0;
}

inline void load(Char_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Int_O s, Str_I varname, Matt_IO matt)
{
    Long i;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (2 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 0)
        SLS_ERR("wrong dimension!");

    matt_read_scalar(s, fin);
    return 0;
}

inline void load(Int_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Llong_O s, Str_I varname, Matt_IO matt)
{
    Long i;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (3 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 0)
        SLS_ERR("wrong dimension!");

    matt_read_scalar(s, fin);
    return 0;
}

inline void load(Llong_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Doub_O s, Str_I varname, Matt_IO matt)
{
    Long i;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (21 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 0)
        SLS_ERR("wrong dimension!");

    matt_read_scalar(s, fin);
    return 0;
}

inline void load(Doub_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Comp_O s, Str_I varname, Matt_IO matt)
{
    Long i;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (41 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 0)
        SLS_ERR("wrong dimension!");

    matt_read_scalar(s, fin);
    return 0;
}

inline void load(Comp_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(VecChar_O v, Str_I varname, Matt_IO matt)
{
    ifstream &fin = matt.m_in;
    Long i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (1 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 1)
        SLS_ERR("wrong dimension!");

    Long n = matt.m_size[i][0]; v.resize(n);
    // read var data
    for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
    return 0;
}

inline void load(VecChar_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(VecInt_O v, Str_I varname, Matt_IO matt)
{
    ifstream &fin = matt.m_in;
    Long i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (2 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 1)
        SLS_ERR("wrong dimension!");

    Long n = matt.m_size[i][0]; v.resize(n);
    // read var data
    for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
    return 0;
}

inline void load(VecInt_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(VecLlong_O v, Str_I varname, Matt_IO matt)
{
    ifstream &fin = matt.m_in;
    Long i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (3 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 1)
        SLS_ERR("wrong dimension!");

    Long n = matt.m_size[i][0]; v.resize(n);
    // read var data
    for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
    return 0;
}

inline void load(VecLlong_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(VecDoub_O v, Str_I varname, Matt_IO matt)
{
    ifstream &fin = matt.m_in;
    Long i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (21 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 1)
        SLS_ERR("wrong dimension!");

    Long n = matt.m_size[i][0]; v.resize(n);
    // read var data
    for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
    return 0;
}

inline void load(VecDoub_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(VecComp_O v, Str_I varname, Matt_IO matt)
{
    ifstream &fin = matt.m_in;
    Long i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (41 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 1)
        SLS_ERR("wrong dimension!");

    Long n = matt.m_size[i][0]; v.resize(n);
    // read var data
    for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
    return 0;
}

inline void load(VecComp_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(MatInt_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (2 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(MatInt_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(MatLlong_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (3 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(MatLlong_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(MatDoub_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (21 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(MatDoub_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(MatComp_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (41 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(MatComp_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(CmatInt_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (2 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(CmatInt_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(CmatLlong_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (3 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(CmatLlong_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(CmatDoub_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (21 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(CmatDoub_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(CmatComp_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (41 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(CmatComp_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Cmat3Llong_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, m, n, q;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

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
    return 0;
}

inline void load(Cmat3Llong_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Cmat3Doub_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, m, n, q;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

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
    return 0;
}

inline void load(Cmat3Doub_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Cmat3Comp_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, m, n, q;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

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
    return 0;
}

inline void load(Cmat3Comp_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}


} // namespace slisc
