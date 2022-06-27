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
    // constructors
    VbaseChar();
    explicit VbaseChar(Long_I N);
    VbaseChar(const VbaseChar &rhs); // copy constructor

    // get properties
    Char* p(); // get pointer
    const Char* p() const;
    Long size() const;
    void resize(Long_I N);
    Char &operator[](Long_I i);
    const Char &operator[](Long_I i) const;
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
#ifdef SLS_CHECK_SHAPES
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
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Char * VbaseChar::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Char * VbaseChar::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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
        if (m_N == 0) { // N != 0
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

inline Char &VbaseChar::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseChar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Char &VbaseChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseChar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Char &VbaseChar::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Char &VbaseChar::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Char &VbaseChar::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Char &VbaseChar::end(Long_I i) const
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

class VbaseUchar
{
protected:
    Uchar *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    // constructors
    VbaseUchar();
    explicit VbaseUchar(Long_I N);
    VbaseUchar(const VbaseUchar &rhs); // copy constructor

    // get properties
    Uchar* p(); // get pointer
    const Uchar* p() const;
    Long size() const;
    void resize(Long_I N);
    Uchar &operator[](Long_I i);
    const Uchar &operator[](Long_I i) const;
    Uchar& end();
    const Uchar& end() const;
    Uchar& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Uchar& end(Long_I i) const;
    void operator<<(VbaseUchar &rhs); // move data
    ~VbaseUchar();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseUchar::VbaseUchar() : m_N(0), m_p(nullptr) {}

inline VbaseUchar::VbaseUchar(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Uchar[N];
}

// copy constructor
inline VbaseUchar::VbaseUchar(const VbaseUchar &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Uchar[m_N];
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Uchar * VbaseUchar::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Uchar * VbaseUchar::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long VbaseUchar::size() const
{
    return m_N;
}

inline void VbaseUchar::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) { // N != 0
            m_N = N; m_p = new Uchar[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Uchar[N];
            }
        }
    }
}

inline void VbaseUchar::operator<<(VbaseUchar &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Uchar &VbaseUchar::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseUchar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Uchar &VbaseUchar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseUchar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Uchar &VbaseUchar::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Uchar &VbaseUchar::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Uchar &VbaseUchar::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Uchar &VbaseUchar::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline VbaseUchar::~VbaseUchar()
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
    // constructors
    VbaseInt();
    explicit VbaseInt(Long_I N);
    VbaseInt(const VbaseInt &rhs); // copy constructor

    // get properties
    Int* p(); // get pointer
    const Int* p() const;
    Long size() const;
    void resize(Long_I N);
    Int &operator[](Long_I i);
    const Int &operator[](Long_I i) const;
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
#ifdef SLS_CHECK_SHAPES
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
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Int * VbaseInt::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Int * VbaseInt::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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
        if (m_N == 0) { // N != 0
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

inline Int &VbaseInt::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseInt index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Int &VbaseInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseInt index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Int &VbaseInt::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Int &VbaseInt::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Int &VbaseInt::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Int &VbaseInt::end(Long_I i) const
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
    // constructors
    VbaseLlong();
    explicit VbaseLlong(Long_I N);
    VbaseLlong(const VbaseLlong &rhs); // copy constructor

    // get properties
    Llong* p(); // get pointer
    const Llong* p() const;
    Long size() const;
    void resize(Long_I N);
    Llong &operator[](Long_I i);
    const Llong &operator[](Long_I i) const;
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
#ifdef SLS_CHECK_SHAPES
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
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Llong * VbaseLlong::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Llong * VbaseLlong::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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
        if (m_N == 0) { // N != 0
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

inline Llong &VbaseLlong::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseLlong index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Llong &VbaseLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseLlong index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Llong &VbaseLlong::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Llong &VbaseLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Llong &VbaseLlong::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Llong &VbaseLlong::end(Long_I i) const
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
    // constructors
    VbaseFloat();
    explicit VbaseFloat(Long_I N);
    VbaseFloat(const VbaseFloat &rhs); // copy constructor

    // get properties
    Float* p(); // get pointer
    const Float* p() const;
    Long size() const;
    void resize(Long_I N);
    Float &operator[](Long_I i);
    const Float &operator[](Long_I i) const;
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
#ifdef SLS_CHECK_SHAPES
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
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Float * VbaseFloat::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Float * VbaseFloat::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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
        if (m_N == 0) { // N != 0
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

inline Float &VbaseFloat::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseFloat index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Float &VbaseFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseFloat index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Float &VbaseFloat::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Float &VbaseFloat::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Float &VbaseFloat::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Float &VbaseFloat::end(Long_I i) const
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
    // constructors
    VbaseDoub();
    explicit VbaseDoub(Long_I N);
    VbaseDoub(const VbaseDoub &rhs); // copy constructor

    // get properties
    Doub* p(); // get pointer
    const Doub* p() const;
    Long size() const;
    void resize(Long_I N);
    Doub &operator[](Long_I i);
    const Doub &operator[](Long_I i) const;
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
#ifdef SLS_CHECK_SHAPES
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
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Doub * VbaseDoub::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Doub * VbaseDoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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
        if (m_N == 0) { // N != 0
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

inline Doub &VbaseDoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseDoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Doub &VbaseDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseDoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Doub &VbaseDoub::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Doub &VbaseDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Doub &VbaseDoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Doub &VbaseDoub::end(Long_I i) const
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

class VbaseLdoub
{
protected:
    Ldoub *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    // constructors
    VbaseLdoub();
    explicit VbaseLdoub(Long_I N);
    VbaseLdoub(const VbaseLdoub &rhs); // copy constructor

    // get properties
    Ldoub* p(); // get pointer
    const Ldoub* p() const;
    Long size() const;
    void resize(Long_I N);
    Ldoub &operator[](Long_I i);
    const Ldoub &operator[](Long_I i) const;
    Ldoub& end();
    const Ldoub& end() const;
    Ldoub& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Ldoub& end(Long_I i) const;
    void operator<<(VbaseLdoub &rhs); // move data
    ~VbaseLdoub();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseLdoub::VbaseLdoub() : m_N(0), m_p(nullptr) {}

inline VbaseLdoub::VbaseLdoub(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Ldoub[N];
}

// copy constructor
inline VbaseLdoub::VbaseLdoub(const VbaseLdoub &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Ldoub[m_N];
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Ldoub * VbaseLdoub::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Ldoub * VbaseLdoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long VbaseLdoub::size() const
{
    return m_N;
}

inline void VbaseLdoub::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) { // N != 0
            m_N = N; m_p = new Ldoub[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Ldoub[N];
            }
        }
    }
}

inline void VbaseLdoub::operator<<(VbaseLdoub &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Ldoub &VbaseLdoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseLdoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Ldoub &VbaseLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseLdoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Ldoub &VbaseLdoub::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Ldoub &VbaseLdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Ldoub &VbaseLdoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Ldoub &VbaseLdoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline VbaseLdoub::~VbaseLdoub()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseQdoub
{
protected:
    Qdoub *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    // constructors
    VbaseQdoub();
    explicit VbaseQdoub(Long_I N);
    VbaseQdoub(const VbaseQdoub &rhs); // copy constructor

    // get properties
    Qdoub* p(); // get pointer
    const Qdoub* p() const;
    Long size() const;
    void resize(Long_I N);
    Qdoub &operator[](Long_I i);
    const Qdoub &operator[](Long_I i) const;
    Qdoub& end();
    const Qdoub& end() const;
    Qdoub& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Qdoub& end(Long_I i) const;
    void operator<<(VbaseQdoub &rhs); // move data
    ~VbaseQdoub();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseQdoub::VbaseQdoub() : m_N(0), m_p(nullptr) {}

inline VbaseQdoub::VbaseQdoub(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Qdoub[N];
}

// copy constructor
inline VbaseQdoub::VbaseQdoub(const VbaseQdoub &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Qdoub[m_N];
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Qdoub * VbaseQdoub::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Qdoub * VbaseQdoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long VbaseQdoub::size() const
{
    return m_N;
}

inline void VbaseQdoub::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) { // N != 0
            m_N = N; m_p = new Qdoub[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Qdoub[N];
            }
        }
    }
}

inline void VbaseQdoub::operator<<(VbaseQdoub &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Qdoub &VbaseQdoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseQdoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Qdoub &VbaseQdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseQdoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Qdoub &VbaseQdoub::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Qdoub &VbaseQdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Qdoub &VbaseQdoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Qdoub &VbaseQdoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline VbaseQdoub::~VbaseQdoub()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseFcomp
{
protected:
    Fcomp *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    // constructors
    VbaseFcomp();
    explicit VbaseFcomp(Long_I N);
    VbaseFcomp(const VbaseFcomp &rhs); // copy constructor

    // get properties
    Fcomp* p(); // get pointer
    const Fcomp* p() const;
    Long size() const;
    void resize(Long_I N);
    Fcomp &operator[](Long_I i);
    const Fcomp &operator[](Long_I i) const;
    Fcomp& end();
    const Fcomp& end() const;
    Fcomp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Fcomp& end(Long_I i) const;
    void operator<<(VbaseFcomp &rhs); // move data
    ~VbaseFcomp();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseFcomp::VbaseFcomp() : m_N(0), m_p(nullptr) {}

inline VbaseFcomp::VbaseFcomp(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Fcomp[N];
}

// copy constructor
inline VbaseFcomp::VbaseFcomp(const VbaseFcomp &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Fcomp[m_N];
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Fcomp * VbaseFcomp::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Fcomp * VbaseFcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long VbaseFcomp::size() const
{
    return m_N;
}

inline void VbaseFcomp::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) { // N != 0
            m_N = N; m_p = new Fcomp[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Fcomp[N];
            }
        }
    }
}

inline void VbaseFcomp::operator<<(VbaseFcomp &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Fcomp &VbaseFcomp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseFcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Fcomp &VbaseFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseFcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Fcomp &VbaseFcomp::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Fcomp &VbaseFcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Fcomp &VbaseFcomp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Fcomp &VbaseFcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline VbaseFcomp::~VbaseFcomp()
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
    // constructors
    VbaseComp();
    explicit VbaseComp(Long_I N);
    VbaseComp(const VbaseComp &rhs); // copy constructor

    // get properties
    Comp* p(); // get pointer
    const Comp* p() const;
    Long size() const;
    void resize(Long_I N);
    Comp &operator[](Long_I i);
    const Comp &operator[](Long_I i) const;
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
#ifdef SLS_CHECK_SHAPES
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
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Comp * VbaseComp::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Comp * VbaseComp::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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
        if (m_N == 0) { // N != 0
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

inline Comp &VbaseComp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseComp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Comp &VbaseComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseComp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Comp &VbaseComp::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Comp &VbaseComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Comp &VbaseComp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Comp &VbaseComp::end(Long_I i) const
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

class VbaseLcomp
{
protected:
    Lcomp *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    // constructors
    VbaseLcomp();
    explicit VbaseLcomp(Long_I N);
    VbaseLcomp(const VbaseLcomp &rhs); // copy constructor

    // get properties
    Lcomp* p(); // get pointer
    const Lcomp* p() const;
    Long size() const;
    void resize(Long_I N);
    Lcomp &operator[](Long_I i);
    const Lcomp &operator[](Long_I i) const;
    Lcomp& end();
    const Lcomp& end() const;
    Lcomp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Lcomp& end(Long_I i) const;
    void operator<<(VbaseLcomp &rhs); // move data
    ~VbaseLcomp();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseLcomp::VbaseLcomp() : m_N(0), m_p(nullptr) {}

inline VbaseLcomp::VbaseLcomp(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Lcomp[N];
}

// copy constructor
inline VbaseLcomp::VbaseLcomp(const VbaseLcomp &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Lcomp[m_N];
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Lcomp * VbaseLcomp::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Lcomp * VbaseLcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long VbaseLcomp::size() const
{
    return m_N;
}

inline void VbaseLcomp::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) { // N != 0
            m_N = N; m_p = new Lcomp[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Lcomp[N];
            }
        }
    }
}

inline void VbaseLcomp::operator<<(VbaseLcomp &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Lcomp &VbaseLcomp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseLcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Lcomp &VbaseLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseLcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Lcomp &VbaseLcomp::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Lcomp &VbaseLcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Lcomp &VbaseLcomp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Lcomp &VbaseLcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline VbaseLcomp::~VbaseLcomp()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseQcomp
{
protected:
    Qcomp *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    // constructors
    VbaseQcomp();
    explicit VbaseQcomp(Long_I N);
    VbaseQcomp(const VbaseQcomp &rhs); // copy constructor

    // get properties
    Qcomp* p(); // get pointer
    const Qcomp* p() const;
    Long size() const;
    void resize(Long_I N);
    Qcomp &operator[](Long_I i);
    const Qcomp &operator[](Long_I i) const;
    Qcomp& end();
    const Qcomp& end() const;
    Qcomp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Qcomp& end(Long_I i) const;
    void operator<<(VbaseQcomp &rhs); // move data
    ~VbaseQcomp();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseQcomp::VbaseQcomp() : m_N(0), m_p(nullptr) {}

inline VbaseQcomp::VbaseQcomp(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Qcomp[N];
}

// copy constructor
inline VbaseQcomp::VbaseQcomp(const VbaseQcomp &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Qcomp[m_N];
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Qcomp * VbaseQcomp::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Qcomp * VbaseQcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long VbaseQcomp::size() const
{
    return m_N;
}

inline void VbaseQcomp::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) { // N != 0
            m_N = N; m_p = new Qcomp[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Qcomp[N];
            }
        }
    }
}

inline void VbaseQcomp::operator<<(VbaseQcomp &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Qcomp &VbaseQcomp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseQcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Qcomp &VbaseQcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseQcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Qcomp &VbaseQcomp::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Qcomp &VbaseQcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Qcomp &VbaseQcomp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Qcomp &VbaseQcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline VbaseQcomp::~VbaseQcomp()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseFimag
{
protected:
    Fimag *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    // constructors
    VbaseFimag();
    explicit VbaseFimag(Long_I N);
    VbaseFimag(const VbaseFimag &rhs); // copy constructor

    // get properties
    Fimag* p(); // get pointer
    const Fimag* p() const;
    Long size() const;
    void resize(Long_I N);
    Fimag &operator[](Long_I i);
    const Fimag &operator[](Long_I i) const;
    Fimag& end();
    const Fimag& end() const;
    Fimag& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Fimag& end(Long_I i) const;
    void operator<<(VbaseFimag &rhs); // move data
    ~VbaseFimag();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseFimag::VbaseFimag() : m_N(0), m_p(nullptr) {}

inline VbaseFimag::VbaseFimag(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Fimag[N];
}

// copy constructor
inline VbaseFimag::VbaseFimag(const VbaseFimag &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Fimag[m_N];
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Fimag * VbaseFimag::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Fimag * VbaseFimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long VbaseFimag::size() const
{
    return m_N;
}

inline void VbaseFimag::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) { // N != 0
            m_N = N; m_p = new Fimag[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Fimag[N];
            }
        }
    }
}

inline void VbaseFimag::operator<<(VbaseFimag &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Fimag &VbaseFimag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseFimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Fimag &VbaseFimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseFimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Fimag &VbaseFimag::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Fimag &VbaseFimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Fimag &VbaseFimag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Fimag &VbaseFimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline VbaseFimag::~VbaseFimag()
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
    // constructors
    VbaseImag();
    explicit VbaseImag(Long_I N);
    VbaseImag(const VbaseImag &rhs); // copy constructor

    // get properties
    Imag* p(); // get pointer
    const Imag* p() const;
    Long size() const;
    void resize(Long_I N);
    Imag &operator[](Long_I i);
    const Imag &operator[](Long_I i) const;
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
#ifdef SLS_CHECK_SHAPES
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
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Imag * VbaseImag::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Imag * VbaseImag::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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
        if (m_N == 0) { // N != 0
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

inline Imag &VbaseImag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseImag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Imag &VbaseImag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseImag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Imag &VbaseImag::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Imag &VbaseImag::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Imag &VbaseImag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Imag &VbaseImag::end(Long_I i) const
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

class VbaseLimag
{
protected:
    Limag *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    // constructors
    VbaseLimag();
    explicit VbaseLimag(Long_I N);
    VbaseLimag(const VbaseLimag &rhs); // copy constructor

    // get properties
    Limag* p(); // get pointer
    const Limag* p() const;
    Long size() const;
    void resize(Long_I N);
    Limag &operator[](Long_I i);
    const Limag &operator[](Long_I i) const;
    Limag& end();
    const Limag& end() const;
    Limag& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Limag& end(Long_I i) const;
    void operator<<(VbaseLimag &rhs); // move data
    ~VbaseLimag();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseLimag::VbaseLimag() : m_N(0), m_p(nullptr) {}

inline VbaseLimag::VbaseLimag(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N < 0)
        SLS_ERR("size less than 0!");
#endif
    m_N = N;
    if (N > 0)
        m_p = new Limag[N];
}

// copy constructor
inline VbaseLimag::VbaseLimag(const VbaseLimag &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    m_N = rhs.m_N;
    if (m_N > 0) {
        m_p = new Limag[m_N];
        memcpy(m_p, rhs.p(), m_N);
    }
}

inline Limag * VbaseLimag::p()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline const Limag * VbaseLimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long VbaseLimag::size() const
{
    return m_N;
}

inline void VbaseLimag::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) { // N != 0
            m_N = N; m_p = new Limag[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Limag[N];
            }
        }
    }
}

inline void VbaseLimag::operator<<(VbaseLimag &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Limag &VbaseLimag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseLimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline const Limag &VbaseLimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseLimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
    return m_p[i];
}

inline Limag &VbaseLimag::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Limag &VbaseLimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Limag &VbaseLimag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline const Limag &VbaseLimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
    return m_p[m_N - i];
}

inline VbaseLimag::~VbaseLimag()
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
    ref operator[](Long_I i);
    Bool operator[](Long_I i) const;
    ref end();
    Bool end() const;
    ref end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    Bool end(Long_I i) const;
    void operator<<(VbaseBool &rhs); // move data
};

inline VbaseBool::VbaseBool(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
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
