// binary version of matb.h

#pragma once
#include "file.h"
#include "bits.h"

namespace slisc {

// all non-data intergers in file are Llong
class Matb {
public:
    Matb();
    Matb(Str_I fname, Char_I rw);
    Char m_rw; // 'r' for read 'w' for write
    ifstream m_in; // read file
    ofstream m_out; // write file
    Llong m_n; // variable numbers
    Str fname; // name of the opened file
    vecStr m_name; // variable names
    vector<Llong> m_type; // variable types
    vector<vector<Llong>> m_size; // variable dimensions
    vector<Llong> m_ind; // variable positions (line indices)

    // open a file
    void open(Str_I fname, Char_I rw);

    Bool isopen();

    // close a file, if not called, will be called in destructor
    void close();

    // ===== internal functions =====

    // get var names and positions from the end of the file
    // after return, matb.m_ind[i] points to the first matrix element
    void get_profile();

    // search a variable by name, return index to m_name[i]
    // return -1 if not found
    Long search(Str_I name);

    ~Matb();
};

typedef const Matb &Matb_I;
typedef Matb &Matb_O, &Matb_IO;

struct Matt_file_not_complete {};

// read the last Llong
// pointer will be moved to the beginning of the last Llong
Llong lastLlong(ifstream &fin)
{
    Llong p = Llong(fin.tellg()) - 8;
    Llong num;
    fin.seekg(p);
    read(fin, num);
    fin.seekg(p);
    return num;
}

inline void Matb::get_profile()
{
    vector<Llong> size;
    Str name;
    ifstream &fin = m_in;

    // read number of variables and their positions
    fin.seekg(0, fin.end);
    Long gmax = fin.tellg();
    // check end of file mark
    fin.seekg(gmax-strlen("Matb_End_of_File"));
    Str mark; read(fin, mark);
    if (mark != "Matb_End_of_File")
        throw Matt_file_not_complete();
    fin.seekg(gmax-strlen("Matb_End_of_File"));
    m_n = lastLlong(fin);
    if (m_n < 1)
        SLS_ERR("unknown!");
    m_ind.resize(m_n);
    for (Long i = 0; i < m_n; ++i) {
        m_ind[i] = lastLlong(fin);
        if (m_ind[i] >= gmax || m_ind[i] < 0)
            SLS_ERR("unknown!");
        if (i > 0 && m_ind[i] <= m_ind[i-1])
            SLS_ERR("unknown!");
    }

    // loop through each variable
    m_size.resize(m_n);
    for (Long i = 0; i < m_n; ++i) {
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
        size.resize(n);
        for (Long j = 0; j < n; ++j) {
            Llong temp;
            read(fin, temp);
            if (temp < 0)
                SLS_ERR("unknown!");
            size[j] = temp;
        }
        m_size[i] = size;
        m_ind[i] = fin.tellg();
    }
}

// search variable in file by name
// return index of m_name, return -1 if not found
inline Long Matb::search(Str_I name)
{
    for (Long i = 0; i < m_n; ++i)
        if (name == m_name[i])
            return i;
    return -1;
}

inline Matb::Matb() {}

inline Matb::Matb(Str_I fname, Char_I rw)
{ open(fname, rw); }

inline void Matb::open(Str_I fname, Char_I rw)
{
    if (!little_endian())
        SLS_ERR("only support little endian for now!");
    if (isopen())
        close();
    this->fname = fname;
    if (rw == 'w') {
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
        open_bin(m_out, fname);
        if (!m_out.good())
            SLS_ERR("error: file not created (directory does not exist ?): " + fname);
    }
    else {
        m_rw = 'r';
        open_bin(m_in, fname);
        if (!m_in.good())
            SLS_ERR("error: file not found: " + fname);
        get_profile(); // get var names
    }
}

inline Bool Matb::isopen()
{
    return m_in.is_open() != m_out.is_open();
}

inline void Matb::close()
{
    if (m_rw == 'w') {
        // write position of variables
        for (Long i = m_ind.size() - 1; i >= 0; --i)
            write(m_out, m_ind[i]);
        // write number of variables
        write(m_out, m_n);
        // mark end-of-file
        write(m_out, "Matb_End_of_File");
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
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open: " + matb.fname);
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname));
    write(fout, varname);
    // write data type info
    write(fout, Llong(1));
    // write dimension info
    write(fout, Llong(0));
    // write matrix data
    write(fout, s);
}

inline void save(Char_I s, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(s, varname, matb);
    matb.close();
}

inline void save(Int_I s, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open: " + matb.fname);
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname));
    write(fout, varname);
    // write data type info
    write(fout, Llong(2));
    // write dimension info
    write(fout, Llong(0));
    // write matrix data
    write(fout, s);
}

inline void save(Int_I s, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(s, varname, matb);
    matb.close();
}

inline void save(Llong_I s, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open: " + matb.fname);
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname));
    write(fout, varname);
    // write data type info
    write(fout, Llong(3));
    // write dimension info
    write(fout, Llong(0));
    // write matrix data
    write(fout, s);
}

inline void save(Llong_I s, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(s, varname, matb);
    matb.close();
}

inline void save(Doub_I s, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open: " + matb.fname);
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname));
    write(fout, varname);
    // write data type info
    write(fout, Llong(21));
    // write dimension info
    write(fout, Llong(0));
    // write matrix data
    write(fout, s);
}

inline void save(Doub_I s, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(s, varname, matb);
    matb.close();
}

inline void save(Comp_I s, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open: " + matb.fname);
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname));
    write(fout, varname);
    // write data type info
    write(fout, Llong(41));
    // write dimension info
    write(fout, Llong(0));
    // write matrix data
    write(fout, s);
}

inline void save(Comp_I s, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(s, varname, matb);
    matb.close();
}


// save() for containers
inline void save(VecChar_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(1));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(VecChar_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(VecInt_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(2));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(VecInt_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(VecLlong_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(3));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(VecLlong_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(VecDoub_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(21));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(VecDoub_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(VecComp_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(41));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(VecComp_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(SvecChar_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(1));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(SvecChar_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(SvecLlong_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(3));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(SvecLlong_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(SvecDoub_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(21));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(SvecDoub_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(SvecComp_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(41));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(SvecComp_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(DvecLlong_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(3));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(DvecLlong_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(DvecDoub_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(21));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(DvecDoub_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(DvecComp_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(41));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(DvecComp_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(CmatChar_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(1));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(CmatChar_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(CmatInt_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(2));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(CmatInt_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(CmatLlong_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(3));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(CmatLlong_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(CmatDoub_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(21));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(CmatDoub_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(CmatComp_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(41));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(CmatComp_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(MatChar_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(1));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(MatChar_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(MatInt_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(2));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(MatInt_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(MatLlong_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(3));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(MatLlong_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(MatDoub_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(21));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(MatDoub_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(MatComp_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(41));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(MatComp_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(ScmatInt_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(2));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(ScmatInt_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(ScmatLlong_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(3));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(ScmatLlong_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(ScmatDoub_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(21));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(ScmatDoub_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(ScmatComp_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(41));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(ScmatComp_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(DcmatInt_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(2));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(DcmatInt_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(DcmatLlong_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(3));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(DcmatLlong_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(DcmatDoub_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(21));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(DcmatDoub_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(DcmatComp_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(41));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(DcmatComp_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(Cmat3Int_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(2));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(Cmat3Int_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(Cmat3Llong_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(3));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(Cmat3Llong_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(Cmat3Doub_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(21));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(Cmat3Doub_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(Cmat3Comp_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(41));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(Cmat3Comp_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(Mat3Int_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(2));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(Mat3Int_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(Mat3Llong_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(3));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(Mat3Llong_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(Mat3Doub_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(21));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(Mat3Doub_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}

inline void save(Mat3Comp_I v, Str_I varname, Matb_IO matb)
{
    ofstream &fout = matb.m_out;
    if (!fout.is_open())
        SLS_ERR("matb file not open!");
    // record position
    ++matb.m_n; matb.m_ind.push_back(fout.tellp());
    // write variable name info
    write(fout, size(varname)); write(fout, varname);
    // write data type info
    write(fout, Llong(41));
    // write shape info
    write(fout, Llong(2)); write(fout, v.size());
    // write matrix data
}

inline void save(Mat3Comp_I v, Str_I varname, Str_I matt_file)
{
    Matb matb(matt_file, 'w');
    save(v, varname, matb);
    matb.close();
}


// save string as VecChar
inline void save(Str_I str, Str_I varname, Matb_IO matb)
{
    SvecChar_c sli; sli.set(str.data(), str.size());
    save(sli, varname, matb);
}

// TODO: load()

} // namespace slisc
