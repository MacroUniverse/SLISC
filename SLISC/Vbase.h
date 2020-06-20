// basic vector
#pragma once
#include "global.h"
#include "Imag.h"
#include "string.h"

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

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseChar::VbaseChar() : m_N(0), m_p(nullptr) {}

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

// copy constructor
inline VbaseChar::VbaseChar(const VbaseChar &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Char[m_N];
        memcpy(m_p, rhs.ptr(), m_N);
    }
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
    SLS_ERR("VbaseChar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Char & VbaseChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseChar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
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
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Char & VbaseChar::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
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

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseInt::VbaseInt() : m_N(0), m_p(nullptr) {}

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

// copy constructor
inline VbaseInt::VbaseInt(const VbaseInt &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Int[m_N];
        memcpy(m_p, rhs.ptr(), m_N);
    }
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
    SLS_ERR("VbaseInt index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Int & VbaseInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseInt index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
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
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Int & VbaseInt::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
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

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseLlong::VbaseLlong() : m_N(0), m_p(nullptr) {}

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

// copy constructor
inline VbaseLlong::VbaseLlong(const VbaseLlong &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Llong[m_N];
        memcpy(m_p, rhs.ptr(), m_N);
    }
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
    SLS_ERR("VbaseLlong index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Llong & VbaseLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseLlong index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
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
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Llong & VbaseLlong::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
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

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseFloat::VbaseFloat() : m_N(0), m_p(nullptr) {}

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

// copy constructor
inline VbaseFloat::VbaseFloat(const VbaseFloat &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Float[m_N];
        memcpy(m_p, rhs.ptr(), m_N);
    }
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
    SLS_ERR("VbaseFloat index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Float & VbaseFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseFloat index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
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
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Float & VbaseFloat::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
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

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseDoub::VbaseDoub() : m_N(0), m_p(nullptr) {}

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

// copy constructor
inline VbaseDoub::VbaseDoub(const VbaseDoub &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Doub[m_N];
        memcpy(m_p, rhs.ptr(), m_N);
    }
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
    SLS_ERR("VbaseDoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Doub & VbaseDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseDoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
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
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Doub & VbaseDoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
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

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseComp::VbaseComp() : m_N(0), m_p(nullptr) {}

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

// copy constructor
inline VbaseComp::VbaseComp(const VbaseComp &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Comp[m_N];
        memcpy(m_p, rhs.ptr(), m_N);
    }
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
    SLS_ERR("VbaseComp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Comp & VbaseComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseComp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
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
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Comp & VbaseComp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
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

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseImag::VbaseImag() : m_N(0), m_p(nullptr) {}

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

// copy constructor
inline VbaseImag::VbaseImag(const VbaseImag &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Imag[m_N];
        memcpy(m_p, rhs.ptr(), m_N);
    }
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
    SLS_ERR("VbaseImag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Imag & VbaseImag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseImag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
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
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Imag & VbaseImag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline VbaseImag::~VbaseImag()
{
    if (m_N != 0)
        delete[] m_p;
}


class VbaseBool
{
protected:
    std::vector<bool> m_v;
public:
    typedef std::vector<bool>::reference ref;
    // constructors
    VbaseBool() = default;
    explicit VbaseBool(Long_I N);
    VbaseBool(const VbaseBool &rhs); // copy constructor

    // get properties
    Long size() const;
    void resize(Long_I N);
    VbaseBool::ref operator[](Long_I i);
    Bool operator[](Long_I i) const;
    VbaseBool::ref operator()(Long_I i);
    Bool operator()(Long_I i) const;
    VbaseBool::ref end();
    Bool end() const;
    VbaseBool::ref end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    Bool end(Long_I i) const;
    void operator<<(VbaseBool &rhs); // move data
};

inline VbaseBool::VbaseBool(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    if (N > 0)
        m_v.resize(N);
}

inline VbaseBool::VbaseBool(const VbaseBool &rhs): m_v(rhs.m_v)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
}

inline Long VbaseBool::size() const
{
    return m_v.size();
}

inline void VbaseBool::resize(Long_I N)
{
    m_v.resize(N);
}

inline void VbaseBool::operator<<(VbaseBool &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    m_v.swap(rhs.m_v);
}

inline VbaseBool::ref VbaseBool::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=size())
        SLS_ERR("VbaseBool index (" + num2str(i) + ") out of bounds: size = " + num2str(size()));
#endif
    return m_v[i];
}

inline Bool VbaseBool::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=size())
        SLS_ERR("VbaseBool index (" + num2str(i) + ") out of bounds: size = " + num2str(size()));
#endif
    return m_v[i];
}

inline VbaseBool::ref VbaseBool::operator()(Long_I i)
{ return m_v[i]; }

inline Bool VbaseBool::operator()(Long_I i) const
{ return m_v[i]; }

inline VbaseBool::ref VbaseBool::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_v.empty())
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_v.back();
}

inline Bool VbaseBool::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_v.empty())
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_v.back();
}

inline VbaseBool::ref VbaseBool::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > size())
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(size()));
#endif
    return m_v[size() - i];
}

inline Bool VbaseBool::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > size())
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(size()));
#endif
    return m_v[size() - i];
}
} // namespace slisc
