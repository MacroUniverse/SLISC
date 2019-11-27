// row-major matrix container
#pragma once
#include "vector.h"

namespace slisc {
// Matrix Class

template <class T>
class Matrix : public Vbase<T>
{
private:
    typedef Vbase<T> Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
    Matrix(); // default constructor: uninitialized
public:
    using Base::ptr;
    using Base::operator();
    Matrix(Long_I Nr, Long_I Nc);
    Matrix(Long_I Nr, Long_I Nc, const T &s);    //Initialize to constant
    Matrix(Long_I Nr, Long_I Nc, const T *ptr);    // Initialize to array
    Matrix(const Matrix &rhs);        // Copy constructor
#ifdef _CUSLISC_
    Matrix & operator=(const Gmatrix<T> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
    void operator<<(Matrix &rhs); // move data and rhs.resize(0, 0)
    T& operator()(Long_I i, Long_I j); // double indexing
    const T& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
    template <class T1>
    void resize(const Matrix<T1> &a);
};

template <class T>
Matrix<T>::Matrix() {}

template <class T>
Matrix<T>::Matrix(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

template <class T>
Matrix<T>::Matrix(Long_I Nr, Long_I Nc, const T &s) : Matrix(Nr, Nc)
{ copy(*this, s); }

template <class T>
Matrix<T>::Matrix(Long_I Nr, Long_I Nc, const T *ptr) : Matrix(Nr, Nc)
{ memcpy(m_p, ptr, m_N*sizeof(T)); }

template <class T>
Matrix<T>::Matrix(const Matrix<T> &rhs) : Matrix()
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

template <class T>
inline void Matrix<T>::operator<<(Matrix<T> &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

template <class T>
inline T& Matrix<T>::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

template <class T>
inline const T & Matrix<T>::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

template <class T>
inline Long Matrix<T>::n1() const
{ return m_Nr; }

template <class T>
inline Long Matrix<T>::n2() const
{ return m_Nc; }

template <class T>
inline void Matrix<T>::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

template <class T>
template <class T1>
inline void Matrix<T>::resize(const Matrix<T1> &a)
{ resize(a.n1(), a.n2()); }
}
