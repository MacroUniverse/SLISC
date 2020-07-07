#pragma once
#include "Vec.h"

namespace slisc {
class McooChar : public VbaseChar
{
private:
    typedef VbaseChar Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
public:
    using Base::ptr;
    McooChar(Long_I Nr, Long_I Nc);
    McooChar(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooChar(const McooChar &rhs) = delete;  // Copy constructor
    McooChar &operator=(const McooChar &rhs) = delete;// copy assignment
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    // inline void operator<<(McooChar &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(Char_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Char_I s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    Char & ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    Char operator()(Long_I i, Long_I j) const;
    Char &operator()(Long_I ind); // return element
    Char operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
};

typedef const McooChar &McooChar_I;
typedef McooChar &McooChar_O, &McooChar_IO;

inline McooChar::McooChar(Long_I Nr, Long_I Nc)
    : Base(0), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

inline McooChar::McooChar(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline Long * McooChar::row_ptr()
{
    return m_row.ptr();
}

inline const Long *McooChar::row_ptr() const
{
    return m_row.ptr();
}

inline Long * McooChar::col_ptr()
{
    return m_col.ptr();
}

inline const Long *McooChar::col_ptr() const
{
    return m_col.ptr();
}

inline Long McooChar::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

inline Char& McooChar::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooChar::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("McooChar::operator()(i,j): element does not exist!");
    return m_p[n];
}

inline Char McooChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooChar::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return 0; // never return a (const) reference to a temporary
    return m_p[n];
}

inline void McooChar::push(Char_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("McooChar::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("McooChar::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("McooChar::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

inline void McooChar::set(Char_I s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("McooChar::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

inline Long McooChar::n1() const
{
    return m_Nr;
}

inline Long McooChar::n2() const
{
    return m_Nc;
}

inline Long McooChar::size() const
{
    return m_Nr * m_Nc;
}

inline Long McooChar::nnz() const
{
    return m_Nnz;
}

inline Long McooChar::capacity() const
{
    return Base::size();
}

inline Char & McooChar::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooChar::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

inline Char McooChar::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooChar::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

inline Long McooChar::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooChar::row() subscript out of bounds");
#endif
    return m_row[ind];
}

inline Long McooChar::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("McooChar::col() subscript out of bounds");
#endif
    return m_col[ind];
}

inline void McooChar::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
    if (Nnz < 0)
        SLS_ERR("McooChar::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("McooChar::trim(): Nnz > m_Nnz!");
}

inline void McooChar::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_N)
        SLS_ERR("not enough capacity!");
#endif
    m_Nnz = N;
}

inline void McooChar::reserve(Long_I N)
{
    Base::resize(N);
    m_row.resize(N);
    m_col.resize(N);
    m_Nnz = 0;
}

inline void McooChar::reshape(Long_I Nr, Long_I Nc)
{
    m_Nr = Nr; m_Nc = Nc;
}

class McooInt : public VbaseInt
{
private:
    typedef VbaseInt Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
public:
    using Base::ptr;
    McooInt(Long_I Nr, Long_I Nc);
    McooInt(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooInt(const McooInt &rhs) = delete;  // Copy constructor
    McooInt &operator=(const McooInt &rhs) = delete;// copy assignment
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    // inline void operator<<(McooInt &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(Int_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Int_I s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    Int & ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    Int operator()(Long_I i, Long_I j) const;
    Int &operator()(Long_I ind); // return element
    Int operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
};

typedef const McooInt &McooInt_I;
typedef McooInt &McooInt_O, &McooInt_IO;

inline McooInt::McooInt(Long_I Nr, Long_I Nc)
    : Base(0), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

inline McooInt::McooInt(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline Long * McooInt::row_ptr()
{
    return m_row.ptr();
}

inline const Long *McooInt::row_ptr() const
{
    return m_row.ptr();
}

inline Long * McooInt::col_ptr()
{
    return m_col.ptr();
}

inline const Long *McooInt::col_ptr() const
{
    return m_col.ptr();
}

inline Long McooInt::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

inline Int& McooInt::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooInt::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("McooInt::operator()(i,j): element does not exist!");
    return m_p[n];
}

inline Int McooInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooInt::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return 0; // never return a (const) reference to a temporary
    return m_p[n];
}

inline void McooInt::push(Int_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("McooInt::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("McooInt::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("McooInt::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

inline void McooInt::set(Int_I s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("McooInt::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

inline Long McooInt::n1() const
{
    return m_Nr;
}

inline Long McooInt::n2() const
{
    return m_Nc;
}

inline Long McooInt::size() const
{
    return m_Nr * m_Nc;
}

inline Long McooInt::nnz() const
{
    return m_Nnz;
}

inline Long McooInt::capacity() const
{
    return Base::size();
}

inline Int & McooInt::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooInt::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

inline Int McooInt::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooInt::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

inline Long McooInt::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooInt::row() subscript out of bounds");
#endif
    return m_row[ind];
}

inline Long McooInt::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("McooInt::col() subscript out of bounds");
#endif
    return m_col[ind];
}

inline void McooInt::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
    if (Nnz < 0)
        SLS_ERR("McooInt::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("McooInt::trim(): Nnz > m_Nnz!");
}

inline void McooInt::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_N)
        SLS_ERR("not enough capacity!");
#endif
    m_Nnz = N;
}

inline void McooInt::reserve(Long_I N)
{
    Base::resize(N);
    m_row.resize(N);
    m_col.resize(N);
    m_Nnz = 0;
}

inline void McooInt::reshape(Long_I Nr, Long_I Nc)
{
    m_Nr = Nr; m_Nc = Nc;
}

class McooLlong : public VbaseLlong
{
private:
    typedef VbaseLlong Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
public:
    using Base::ptr;
    McooLlong(Long_I Nr, Long_I Nc);
    McooLlong(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooLlong(const McooLlong &rhs) = delete;  // Copy constructor
    McooLlong &operator=(const McooLlong &rhs) = delete;// copy assignment
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    // inline void operator<<(McooLlong &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(Llong_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Llong_I s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    Llong & ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    Llong operator()(Long_I i, Long_I j) const;
    Llong &operator()(Long_I ind); // return element
    Llong operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
};

typedef const McooLlong &McooLlong_I;
typedef McooLlong &McooLlong_O, &McooLlong_IO;

inline McooLlong::McooLlong(Long_I Nr, Long_I Nc)
    : Base(0), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

inline McooLlong::McooLlong(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline Long * McooLlong::row_ptr()
{
    return m_row.ptr();
}

inline const Long *McooLlong::row_ptr() const
{
    return m_row.ptr();
}

inline Long * McooLlong::col_ptr()
{
    return m_col.ptr();
}

inline const Long *McooLlong::col_ptr() const
{
    return m_col.ptr();
}

inline Long McooLlong::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

inline Llong& McooLlong::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooLlong::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("McooLlong::operator()(i,j): element does not exist!");
    return m_p[n];
}

inline Llong McooLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooLlong::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return 0; // never return a (const) reference to a temporary
    return m_p[n];
}

inline void McooLlong::push(Llong_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("McooLlong::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("McooLlong::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("McooLlong::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

inline void McooLlong::set(Llong_I s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("McooLlong::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

inline Long McooLlong::n1() const
{
    return m_Nr;
}

inline Long McooLlong::n2() const
{
    return m_Nc;
}

inline Long McooLlong::size() const
{
    return m_Nr * m_Nc;
}

inline Long McooLlong::nnz() const
{
    return m_Nnz;
}

inline Long McooLlong::capacity() const
{
    return Base::size();
}

inline Llong & McooLlong::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooLlong::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

inline Llong McooLlong::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooLlong::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

inline Long McooLlong::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooLlong::row() subscript out of bounds");
#endif
    return m_row[ind];
}

inline Long McooLlong::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("McooLlong::col() subscript out of bounds");
#endif
    return m_col[ind];
}

inline void McooLlong::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
    if (Nnz < 0)
        SLS_ERR("McooLlong::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("McooLlong::trim(): Nnz > m_Nnz!");
}

inline void McooLlong::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_N)
        SLS_ERR("not enough capacity!");
#endif
    m_Nnz = N;
}

inline void McooLlong::reserve(Long_I N)
{
    Base::resize(N);
    m_row.resize(N);
    m_col.resize(N);
    m_Nnz = 0;
}

inline void McooLlong::reshape(Long_I Nr, Long_I Nc)
{
    m_Nr = Nr; m_Nc = Nc;
}

class McooDoub : public VbaseDoub
{
private:
    typedef VbaseDoub Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
public:
    using Base::ptr;
    McooDoub(Long_I Nr, Long_I Nc);
    McooDoub(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooDoub(const McooDoub &rhs) = delete;  // Copy constructor
    McooDoub &operator=(const McooDoub &rhs) = delete;// copy assignment
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    // inline void operator<<(McooDoub &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(Doub_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Doub_I s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    Doub & ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    Doub operator()(Long_I i, Long_I j) const;
    Doub &operator()(Long_I ind); // return element
    Doub operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
};

typedef const McooDoub &McooDoub_I;
typedef McooDoub &McooDoub_O, &McooDoub_IO;

inline McooDoub::McooDoub(Long_I Nr, Long_I Nc)
    : Base(0), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

inline McooDoub::McooDoub(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline Long * McooDoub::row_ptr()
{
    return m_row.ptr();
}

inline const Long *McooDoub::row_ptr() const
{
    return m_row.ptr();
}

inline Long * McooDoub::col_ptr()
{
    return m_col.ptr();
}

inline const Long *McooDoub::col_ptr() const
{
    return m_col.ptr();
}

inline Long McooDoub::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

inline Doub& McooDoub::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooDoub::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("McooDoub::operator()(i,j): element does not exist!");
    return m_p[n];
}

inline Doub McooDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooDoub::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return 0; // never return a (const) reference to a temporary
    return m_p[n];
}

inline void McooDoub::push(Doub_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("McooDoub::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("McooDoub::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("McooDoub::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

inline void McooDoub::set(Doub_I s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("McooDoub::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

inline Long McooDoub::n1() const
{
    return m_Nr;
}

inline Long McooDoub::n2() const
{
    return m_Nc;
}

inline Long McooDoub::size() const
{
    return m_Nr * m_Nc;
}

inline Long McooDoub::nnz() const
{
    return m_Nnz;
}

inline Long McooDoub::capacity() const
{
    return Base::size();
}

inline Doub & McooDoub::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooDoub::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

inline Doub McooDoub::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooDoub::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

inline Long McooDoub::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooDoub::row() subscript out of bounds");
#endif
    return m_row[ind];
}

inline Long McooDoub::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("McooDoub::col() subscript out of bounds");
#endif
    return m_col[ind];
}

inline void McooDoub::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
    if (Nnz < 0)
        SLS_ERR("McooDoub::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("McooDoub::trim(): Nnz > m_Nnz!");
}

inline void McooDoub::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_N)
        SLS_ERR("not enough capacity!");
#endif
    m_Nnz = N;
}

inline void McooDoub::reserve(Long_I N)
{
    Base::resize(N);
    m_row.resize(N);
    m_col.resize(N);
    m_Nnz = 0;
}

inline void McooDoub::reshape(Long_I Nr, Long_I Nc)
{
    m_Nr = Nr; m_Nc = Nc;
}

class McooComp : public VbaseComp
{
private:
    typedef VbaseComp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
public:
    using Base::ptr;
    McooComp(Long_I Nr, Long_I Nc);
    McooComp(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooComp(const McooComp &rhs) = delete;  // Copy constructor
    McooComp &operator=(const McooComp &rhs) = delete;// copy assignment
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    // inline void operator<<(McooComp &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(Comp_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Comp_I s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    Comp & ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    Comp operator()(Long_I i, Long_I j) const;
    Comp &operator()(Long_I ind); // return element
    Comp operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
};

typedef const McooComp &McooComp_I;
typedef McooComp &McooComp_O, &McooComp_IO;

inline McooComp::McooComp(Long_I Nr, Long_I Nc)
    : Base(0), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

inline McooComp::McooComp(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline Long * McooComp::row_ptr()
{
    return m_row.ptr();
}

inline const Long *McooComp::row_ptr() const
{
    return m_row.ptr();
}

inline Long * McooComp::col_ptr()
{
    return m_col.ptr();
}

inline const Long *McooComp::col_ptr() const
{
    return m_col.ptr();
}

inline Long McooComp::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

inline Comp& McooComp::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooComp::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("McooComp::operator()(i,j): element does not exist!");
    return m_p[n];
}

inline Comp McooComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooComp::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return 0; // never return a (const) reference to a temporary
    return m_p[n];
}

inline void McooComp::push(Comp_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("McooComp::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("McooComp::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("McooComp::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

inline void McooComp::set(Comp_I s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("McooComp::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

inline Long McooComp::n1() const
{
    return m_Nr;
}

inline Long McooComp::n2() const
{
    return m_Nc;
}

inline Long McooComp::size() const
{
    return m_Nr * m_Nc;
}

inline Long McooComp::nnz() const
{
    return m_Nnz;
}

inline Long McooComp::capacity() const
{
    return Base::size();
}

inline Comp & McooComp::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooComp::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

inline Comp McooComp::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooComp::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

inline Long McooComp::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooComp::row() subscript out of bounds");
#endif
    return m_row[ind];
}

inline Long McooComp::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("McooComp::col() subscript out of bounds");
#endif
    return m_col[ind];
}

inline void McooComp::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
    if (Nnz < 0)
        SLS_ERR("McooComp::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("McooComp::trim(): Nnz > m_Nnz!");
}

inline void McooComp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_N)
        SLS_ERR("not enough capacity!");
#endif
    m_Nnz = N;
}

inline void McooComp::reserve(Long_I N)
{
    Base::resize(N);
    m_row.resize(N);
    m_col.resize(N);
    m_Nnz = 0;
}

inline void McooComp::reshape(Long_I Nr, Long_I Nc)
{
    m_Nr = Nr; m_Nc = Nc;
}

} // namespace slisc
