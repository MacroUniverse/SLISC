// basic vector
#pragma once
#include "global.h"
#include "Imag.h"

namespace slisc {
class VbaseChar
{
protected:
    Char *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Char value_type;
    // constructors
    VbaseChar();
    explicit VbaseChar(Long_I N);
    VbaseChar(const VbaseChar &rhs); // copy constructor

    // get properties
    Char* ptr(); // get pointer
    const Char* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Char & operator[](Long_I i);
    const Char & operator[](Long_I i) const;
    Char & operator()(Long_I i);
    const Char & operator()(Long_I i) const;
    Char& end();
    const Char& end() const;
    Char& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Char& end(Long_I i) const;
    void operator<<(VbaseChar &rhs); // move data
    ~VbaseChar();
};

inline VbaseChar::VbaseChar() : m_N(0) {}

inline VbaseChar::VbaseChar(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Char[N];
}

inline VbaseChar::VbaseChar(const VbaseChar &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Char[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Char * VbaseChar::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Char * VbaseChar::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseChar::size() const
{
    return m_N;
}

inline void VbaseChar::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Char[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Char[N];
            }
        }
    }
}

inline void VbaseChar::operator<<(VbaseChar &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Char & VbaseChar::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseChar subscript out of bounds");
#endif
    return m_p[i];
}

inline const Char & VbaseChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseChar subscript out of bounds");
#endif
    return m_p[i];
}

inline Char & VbaseChar::operator()(Long_I i)
{ return (*this)[i]; }

inline const Char & VbaseChar::operator()(Long_I i) const
{ return (*this)[i]; }

inline Char & VbaseChar::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Char & VbaseChar::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Char & VbaseChar::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Char & VbaseChar::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseChar::~VbaseChar()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseInt
{
protected:
    Int *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Int value_type;
    // constructors
    VbaseInt();
    explicit VbaseInt(Long_I N);
    VbaseInt(const VbaseInt &rhs); // copy constructor

    // get properties
    Int* ptr(); // get pointer
    const Int* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Int & operator[](Long_I i);
    const Int & operator[](Long_I i) const;
    Int & operator()(Long_I i);
    const Int & operator()(Long_I i) const;
    Int& end();
    const Int& end() const;
    Int& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Int& end(Long_I i) const;
    void operator<<(VbaseInt &rhs); // move data
    ~VbaseInt();
};

inline VbaseInt::VbaseInt() : m_N(0) {}

inline VbaseInt::VbaseInt(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Int[N];
}

inline VbaseInt::VbaseInt(const VbaseInt &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Int[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Int * VbaseInt::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Int * VbaseInt::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseInt::size() const
{
    return m_N;
}

inline void VbaseInt::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Int[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Int[N];
            }
        }
    }
}

inline void VbaseInt::operator<<(VbaseInt &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Int & VbaseInt::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseInt subscript out of bounds");
#endif
    return m_p[i];
}

inline const Int & VbaseInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseInt subscript out of bounds");
#endif
    return m_p[i];
}

inline Int & VbaseInt::operator()(Long_I i)
{ return (*this)[i]; }

inline const Int & VbaseInt::operator()(Long_I i) const
{ return (*this)[i]; }

inline Int & VbaseInt::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Int & VbaseInt::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Int & VbaseInt::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Int & VbaseInt::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseInt::~VbaseInt()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseLlong
{
protected:
    Llong *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Llong value_type;
    // constructors
    VbaseLlong();
    explicit VbaseLlong(Long_I N);
    VbaseLlong(const VbaseLlong &rhs); // copy constructor

    // get properties
    Llong* ptr(); // get pointer
    const Llong* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Llong & operator[](Long_I i);
    const Llong & operator[](Long_I i) const;
    Llong & operator()(Long_I i);
    const Llong & operator()(Long_I i) const;
    Llong& end();
    const Llong& end() const;
    Llong& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Llong& end(Long_I i) const;
    void operator<<(VbaseLlong &rhs); // move data
    ~VbaseLlong();
};

inline VbaseLlong::VbaseLlong() : m_N(0) {}

inline VbaseLlong::VbaseLlong(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Llong[N];
}

inline VbaseLlong::VbaseLlong(const VbaseLlong &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Llong[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Llong * VbaseLlong::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Llong * VbaseLlong::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseLlong::size() const
{
    return m_N;
}

inline void VbaseLlong::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Llong[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Llong[N];
            }
        }
    }
}

inline void VbaseLlong::operator<<(VbaseLlong &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Llong & VbaseLlong::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseLlong subscript out of bounds");
#endif
    return m_p[i];
}

inline const Llong & VbaseLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseLlong subscript out of bounds");
#endif
    return m_p[i];
}

inline Llong & VbaseLlong::operator()(Long_I i)
{ return (*this)[i]; }

inline const Llong & VbaseLlong::operator()(Long_I i) const
{ return (*this)[i]; }

inline Llong & VbaseLlong::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Llong & VbaseLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Llong & VbaseLlong::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Llong & VbaseLlong::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseLlong::~VbaseLlong()
{
    if (m_N != 0)
        delete[] m_p;
}

#ifdef SLS_USE_INT_AS_LONG
typedef VbaseInt VbaseLong;
#else
typedef VbaseLlong VbaseLong;
#endif

class VbaseFloat
{
protected:
    Float *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Float value_type;
    // constructors
    VbaseFloat();
    explicit VbaseFloat(Long_I N);
    VbaseFloat(const VbaseFloat &rhs); // copy constructor

    // get properties
    Float* ptr(); // get pointer
    const Float* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Float & operator[](Long_I i);
    const Float & operator[](Long_I i) const;
    Float & operator()(Long_I i);
    const Float & operator()(Long_I i) const;
    Float& end();
    const Float& end() const;
    Float& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Float& end(Long_I i) const;
    void operator<<(VbaseFloat &rhs); // move data
    ~VbaseFloat();
};

inline VbaseFloat::VbaseFloat() : m_N(0) {}

inline VbaseFloat::VbaseFloat(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Float[N];
}

inline VbaseFloat::VbaseFloat(const VbaseFloat &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Float[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Float * VbaseFloat::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Float * VbaseFloat::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseFloat::size() const
{
    return m_N;
}

inline void VbaseFloat::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Float[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Float[N];
            }
        }
    }
}

inline void VbaseFloat::operator<<(VbaseFloat &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Float & VbaseFloat::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseFloat subscript out of bounds");
#endif
    return m_p[i];
}

inline const Float & VbaseFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseFloat subscript out of bounds");
#endif
    return m_p[i];
}

inline Float & VbaseFloat::operator()(Long_I i)
{ return (*this)[i]; }

inline const Float & VbaseFloat::operator()(Long_I i) const
{ return (*this)[i]; }

inline Float & VbaseFloat::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Float & VbaseFloat::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Float & VbaseFloat::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Float & VbaseFloat::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseFloat::~VbaseFloat()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseDoub
{
protected:
    Doub *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Doub value_type;
    // constructors
    VbaseDoub();
    explicit VbaseDoub(Long_I N);
    VbaseDoub(const VbaseDoub &rhs); // copy constructor

    // get properties
    Doub* ptr(); // get pointer
    const Doub* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Doub & operator[](Long_I i);
    const Doub & operator[](Long_I i) const;
    Doub & operator()(Long_I i);
    const Doub & operator()(Long_I i) const;
    Doub& end();
    const Doub& end() const;
    Doub& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Doub& end(Long_I i) const;
    void operator<<(VbaseDoub &rhs); // move data
    ~VbaseDoub();
};

inline VbaseDoub::VbaseDoub() : m_N(0) {}

inline VbaseDoub::VbaseDoub(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Doub[N];
}

inline VbaseDoub::VbaseDoub(const VbaseDoub &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Doub[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Doub * VbaseDoub::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Doub * VbaseDoub::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseDoub::size() const
{
    return m_N;
}

inline void VbaseDoub::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Doub[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Doub[N];
            }
        }
    }
}

inline void VbaseDoub::operator<<(VbaseDoub &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Doub & VbaseDoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseDoub subscript out of bounds");
#endif
    return m_p[i];
}

inline const Doub & VbaseDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseDoub subscript out of bounds");
#endif
    return m_p[i];
}

inline Doub & VbaseDoub::operator()(Long_I i)
{ return (*this)[i]; }

inline const Doub & VbaseDoub::operator()(Long_I i) const
{ return (*this)[i]; }

inline Doub & VbaseDoub::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Doub & VbaseDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Doub & VbaseDoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Doub & VbaseDoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseDoub::~VbaseDoub()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseComp
{
protected:
    Comp *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Comp value_type;
    // constructors
    VbaseComp();
    explicit VbaseComp(Long_I N);
    VbaseComp(const VbaseComp &rhs); // copy constructor

    // get properties
    Comp* ptr(); // get pointer
    const Comp* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Comp & operator[](Long_I i);
    const Comp & operator[](Long_I i) const;
    Comp & operator()(Long_I i);
    const Comp & operator()(Long_I i) const;
    Comp& end();
    const Comp& end() const;
    Comp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Comp& end(Long_I i) const;
    void operator<<(VbaseComp &rhs); // move data
    ~VbaseComp();
};

inline VbaseComp::VbaseComp() : m_N(0) {}

inline VbaseComp::VbaseComp(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Comp[N];
}

inline VbaseComp::VbaseComp(const VbaseComp &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Comp[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Comp * VbaseComp::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Comp * VbaseComp::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseComp::size() const
{
    return m_N;
}

inline void VbaseComp::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Comp[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Comp[N];
            }
        }
    }
}

inline void VbaseComp::operator<<(VbaseComp &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Comp & VbaseComp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseComp subscript out of bounds");
#endif
    return m_p[i];
}

inline const Comp & VbaseComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseComp subscript out of bounds");
#endif
    return m_p[i];
}

inline Comp & VbaseComp::operator()(Long_I i)
{ return (*this)[i]; }

inline const Comp & VbaseComp::operator()(Long_I i) const
{ return (*this)[i]; }

inline Comp & VbaseComp::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Comp & VbaseComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Comp & VbaseComp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Comp & VbaseComp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseComp::~VbaseComp()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseImag
{
protected:
    Imag *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Imag value_type;
    // constructors
    VbaseImag();
    explicit VbaseImag(Long_I N);
    VbaseImag(const VbaseImag &rhs); // copy constructor

    // get properties
    Imag* ptr(); // get pointer
    const Imag* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Imag & operator[](Long_I i);
    const Imag & operator[](Long_I i) const;
    Imag & operator()(Long_I i);
    const Imag & operator()(Long_I i) const;
    Imag& end();
    const Imag& end() const;
    Imag& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Imag& end(Long_I i) const;
    void operator<<(VbaseImag &rhs); // move data
    ~VbaseImag();
};

inline VbaseImag::VbaseImag() : m_N(0) {}

inline VbaseImag::VbaseImag(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Imag[N];
}

inline VbaseImag::VbaseImag(const VbaseImag &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Imag[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Imag * VbaseImag::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Imag * VbaseImag::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseImag::size() const
{
    return m_N;
}

inline void VbaseImag::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Imag[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Imag[N];
            }
        }
    }
}

inline void VbaseImag::operator<<(VbaseImag &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Imag & VbaseImag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseImag subscript out of bounds");
#endif
    return m_p[i];
}

inline const Imag & VbaseImag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseImag subscript out of bounds");
#endif
    return m_p[i];
}

inline Imag & VbaseImag::operator()(Long_I i)
{ return (*this)[i]; }

inline const Imag & VbaseImag::operator()(Long_I i) const
{ return (*this)[i]; }

inline Imag & VbaseImag::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Imag & VbaseImag::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Imag & VbaseImag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Imag & VbaseImag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseImag::~VbaseImag()
{
    if (m_N != 0)
        delete[] m_p;
}

} // namespace slisc
