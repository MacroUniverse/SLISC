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

#include "matt_write_scalar.inl"
#include "matt_read_scalar.inl"

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
#include "matt_save.inl"

// read matt files
// return 0 if successful, -1 if variable not found
#include "matt_load.inl"

} // namespace slisc
