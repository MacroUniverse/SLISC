#pragma once

namespace slisc {
class DcmatChar_c
{
protected:
    const Char *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatChar_c();
    DcmatChar_c(const Char *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Char *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatChar_c &sli);


    const Char& operator[](Long_I i) const;
    const Char& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Char *p() const;
};

inline DcmatChar_c::DcmatChar_c() {}

inline DcmatChar_c::DcmatChar_c(const Char *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatChar_c::set(const Char *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatChar_c::set(const DcmatChar_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Char &DcmatChar_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Char &DcmatChar_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatChar_c::n0() const
{
    return m_N0;
}

inline Long DcmatChar_c::n1() const
{
    return m_N1;
}

inline Long DcmatChar_c::lda() const
{
    return m_lda;
}

inline Long DcmatChar_c::size() const
{
    return m_N;
}

inline const Char * DcmatChar_c::p() const
{
    return m_p;
}

typedef const DcmatChar_c &DcmatChar_I;

class DcmatChar
{
protected:
    Char *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatChar();
    DcmatChar(Char *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Char *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatChar &sli);

    operator DcmatChar_c() const;

    Char& operator[](Long_I i) const;
    Char& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Char *p() const;
};

inline DcmatChar::DcmatChar() {}

inline DcmatChar::DcmatChar(Char *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatChar::set(Char *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatChar::set(const DcmatChar &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatChar::operator DcmatChar_c() const
{
    return *((DcmatChar_c *)this);
}

inline Char &DcmatChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Char &DcmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatChar::n0() const
{
    return m_N0;
}

inline Long DcmatChar::n1() const
{
    return m_N1;
}

inline Long DcmatChar::lda() const
{
    return m_lda;
}

inline Long DcmatChar::size() const
{
    return m_N;
}

inline Char * DcmatChar::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatChar &DcmatChar_O, &DcmatChar_IO;

class DcmatUchar_c
{
protected:
    const Uchar *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatUchar_c();
    DcmatUchar_c(const Uchar *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Uchar *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatUchar_c &sli);


    const Uchar& operator[](Long_I i) const;
    const Uchar& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Uchar *p() const;
};

inline DcmatUchar_c::DcmatUchar_c() {}

inline DcmatUchar_c::DcmatUchar_c(const Uchar *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatUchar_c::set(const Uchar *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatUchar_c::set(const DcmatUchar_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Uchar &DcmatUchar_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Uchar &DcmatUchar_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatUchar_c::n0() const
{
    return m_N0;
}

inline Long DcmatUchar_c::n1() const
{
    return m_N1;
}

inline Long DcmatUchar_c::lda() const
{
    return m_lda;
}

inline Long DcmatUchar_c::size() const
{
    return m_N;
}

inline const Uchar * DcmatUchar_c::p() const
{
    return m_p;
}

typedef const DcmatUchar_c &DcmatUchar_I;

class DcmatUchar
{
protected:
    Uchar *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatUchar();
    DcmatUchar(Uchar *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Uchar *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatUchar &sli);

    operator DcmatUchar_c() const;

    Uchar& operator[](Long_I i) const;
    Uchar& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Uchar *p() const;
};

inline DcmatUchar::DcmatUchar() {}

inline DcmatUchar::DcmatUchar(Uchar *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatUchar::set(Uchar *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatUchar::set(const DcmatUchar &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatUchar::operator DcmatUchar_c() const
{
    return *((DcmatUchar_c *)this);
}

inline Uchar &DcmatUchar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Uchar &DcmatUchar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatUchar::n0() const
{
    return m_N0;
}

inline Long DcmatUchar::n1() const
{
    return m_N1;
}

inline Long DcmatUchar::lda() const
{
    return m_lda;
}

inline Long DcmatUchar::size() const
{
    return m_N;
}

inline Uchar * DcmatUchar::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatUchar &DcmatUchar_O, &DcmatUchar_IO;

class DcmatInt_c
{
protected:
    const Int *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatInt_c();
    DcmatInt_c(const Int *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Int *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatInt_c &sli);


    const Int& operator[](Long_I i) const;
    const Int& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Int *p() const;
};

inline DcmatInt_c::DcmatInt_c() {}

inline DcmatInt_c::DcmatInt_c(const Int *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatInt_c::set(const Int *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatInt_c::set(const DcmatInt_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Int &DcmatInt_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Int &DcmatInt_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatInt_c::n0() const
{
    return m_N0;
}

inline Long DcmatInt_c::n1() const
{
    return m_N1;
}

inline Long DcmatInt_c::lda() const
{
    return m_lda;
}

inline Long DcmatInt_c::size() const
{
    return m_N;
}

inline const Int * DcmatInt_c::p() const
{
    return m_p;
}

typedef const DcmatInt_c &DcmatInt_I;

class DcmatInt
{
protected:
    Int *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatInt();
    DcmatInt(Int *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Int *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatInt &sli);

    operator DcmatInt_c() const;

    Int& operator[](Long_I i) const;
    Int& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Int *p() const;
};

inline DcmatInt::DcmatInt() {}

inline DcmatInt::DcmatInt(Int *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatInt::set(Int *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatInt::set(const DcmatInt &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatInt::operator DcmatInt_c() const
{
    return *((DcmatInt_c *)this);
}

inline Int &DcmatInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Int &DcmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatInt::n0() const
{
    return m_N0;
}

inline Long DcmatInt::n1() const
{
    return m_N1;
}

inline Long DcmatInt::lda() const
{
    return m_lda;
}

inline Long DcmatInt::size() const
{
    return m_N;
}

inline Int * DcmatInt::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatInt &DcmatInt_O, &DcmatInt_IO;

class DcmatLlong_c
{
protected:
    const Llong *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatLlong_c();
    DcmatLlong_c(const Llong *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Llong *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatLlong_c &sli);


    const Llong& operator[](Long_I i) const;
    const Llong& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Llong *p() const;
};

inline DcmatLlong_c::DcmatLlong_c() {}

inline DcmatLlong_c::DcmatLlong_c(const Llong *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLlong_c::set(const Llong *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLlong_c::set(const DcmatLlong_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Llong &DcmatLlong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Llong &DcmatLlong_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLlong_c::n0() const
{
    return m_N0;
}

inline Long DcmatLlong_c::n1() const
{
    return m_N1;
}

inline Long DcmatLlong_c::lda() const
{
    return m_lda;
}

inline Long DcmatLlong_c::size() const
{
    return m_N;
}

inline const Llong * DcmatLlong_c::p() const
{
    return m_p;
}

typedef const DcmatLlong_c &DcmatLlong_I;

class DcmatLlong
{
protected:
    Llong *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatLlong();
    DcmatLlong(Llong *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Llong *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatLlong &sli);

    operator DcmatLlong_c() const;

    Llong& operator[](Long_I i) const;
    Llong& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Llong *p() const;
};

inline DcmatLlong::DcmatLlong() {}

inline DcmatLlong::DcmatLlong(Llong *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLlong::set(Llong *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLlong::set(const DcmatLlong &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatLlong::operator DcmatLlong_c() const
{
    return *((DcmatLlong_c *)this);
}

inline Llong &DcmatLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Llong &DcmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLlong::n0() const
{
    return m_N0;
}

inline Long DcmatLlong::n1() const
{
    return m_N1;
}

inline Long DcmatLlong::lda() const
{
    return m_lda;
}

inline Long DcmatLlong::size() const
{
    return m_N;
}

inline Llong * DcmatLlong::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatLlong &DcmatLlong_O, &DcmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef DcmatInt_c DcmatLong_c;
#else
typedef DcmatLlong_c DcmatLong_c;
#endif

typedef const DcmatLong_c &DcmatLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef DcmatInt DcmatLong;
#else
typedef DcmatLlong DcmatLong;
#endif

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatLong &DcmatLong_O, &DcmatLong_IO;

class DcmatFloat_c
{
protected:
    const Float *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatFloat_c();
    DcmatFloat_c(const Float *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Float *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatFloat_c &sli);


    const Float& operator[](Long_I i) const;
    const Float& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Float *p() const;
};

inline DcmatFloat_c::DcmatFloat_c() {}

inline DcmatFloat_c::DcmatFloat_c(const Float *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatFloat_c::set(const Float *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatFloat_c::set(const DcmatFloat_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Float &DcmatFloat_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Float &DcmatFloat_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatFloat_c::n0() const
{
    return m_N0;
}

inline Long DcmatFloat_c::n1() const
{
    return m_N1;
}

inline Long DcmatFloat_c::lda() const
{
    return m_lda;
}

inline Long DcmatFloat_c::size() const
{
    return m_N;
}

inline const Float * DcmatFloat_c::p() const
{
    return m_p;
}

typedef const DcmatFloat_c &DcmatFloat_I;

class DcmatFloat
{
protected:
    Float *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatFloat();
    DcmatFloat(Float *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Float *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatFloat &sli);

    operator DcmatFloat_c() const;

    Float& operator[](Long_I i) const;
    Float& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Float *p() const;
};

inline DcmatFloat::DcmatFloat() {}

inline DcmatFloat::DcmatFloat(Float *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatFloat::set(Float *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatFloat::set(const DcmatFloat &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatFloat::operator DcmatFloat_c() const
{
    return *((DcmatFloat_c *)this);
}

inline Float &DcmatFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Float &DcmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatFloat::n0() const
{
    return m_N0;
}

inline Long DcmatFloat::n1() const
{
    return m_N1;
}

inline Long DcmatFloat::lda() const
{
    return m_lda;
}

inline Long DcmatFloat::size() const
{
    return m_N;
}

inline Float * DcmatFloat::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatFloat &DcmatFloat_O, &DcmatFloat_IO;

class DcmatDoub_c
{
protected:
    const Doub *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatDoub_c();
    DcmatDoub_c(const Doub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Doub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatDoub_c &sli);


    const Doub& operator[](Long_I i) const;
    const Doub& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Doub *p() const;
};

inline DcmatDoub_c::DcmatDoub_c() {}

inline DcmatDoub_c::DcmatDoub_c(const Doub *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatDoub_c::set(const Doub *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatDoub_c::set(const DcmatDoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Doub &DcmatDoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Doub &DcmatDoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatDoub_c::n0() const
{
    return m_N0;
}

inline Long DcmatDoub_c::n1() const
{
    return m_N1;
}

inline Long DcmatDoub_c::lda() const
{
    return m_lda;
}

inline Long DcmatDoub_c::size() const
{
    return m_N;
}

inline const Doub * DcmatDoub_c::p() const
{
    return m_p;
}

typedef const DcmatDoub_c &DcmatDoub_I;

class DcmatDoub
{
protected:
    Doub *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatDoub();
    DcmatDoub(Doub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Doub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatDoub &sli);

    operator DcmatDoub_c() const;

    Doub& operator[](Long_I i) const;
    Doub& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Doub *p() const;
};

inline DcmatDoub::DcmatDoub() {}

inline DcmatDoub::DcmatDoub(Doub *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatDoub::set(Doub *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatDoub::set(const DcmatDoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatDoub::operator DcmatDoub_c() const
{
    return *((DcmatDoub_c *)this);
}

inline Doub &DcmatDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Doub &DcmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatDoub::n0() const
{
    return m_N0;
}

inline Long DcmatDoub::n1() const
{
    return m_N1;
}

inline Long DcmatDoub::lda() const
{
    return m_lda;
}

inline Long DcmatDoub::size() const
{
    return m_N;
}

inline Doub * DcmatDoub::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatDoub &DcmatDoub_O, &DcmatDoub_IO;

class DcmatLdoub_c
{
protected:
    const Ldoub *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatLdoub_c();
    DcmatLdoub_c(const Ldoub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Ldoub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatLdoub_c &sli);


    const Ldoub& operator[](Long_I i) const;
    const Ldoub& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Ldoub *p() const;
};

inline DcmatLdoub_c::DcmatLdoub_c() {}

inline DcmatLdoub_c::DcmatLdoub_c(const Ldoub *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLdoub_c::set(const Ldoub *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLdoub_c::set(const DcmatLdoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Ldoub &DcmatLdoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Ldoub &DcmatLdoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLdoub_c::n0() const
{
    return m_N0;
}

inline Long DcmatLdoub_c::n1() const
{
    return m_N1;
}

inline Long DcmatLdoub_c::lda() const
{
    return m_lda;
}

inline Long DcmatLdoub_c::size() const
{
    return m_N;
}

inline const Ldoub * DcmatLdoub_c::p() const
{
    return m_p;
}

typedef const DcmatLdoub_c &DcmatLdoub_I;

class DcmatLdoub
{
protected:
    Ldoub *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatLdoub();
    DcmatLdoub(Ldoub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Ldoub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatLdoub &sli);

    operator DcmatLdoub_c() const;

    Ldoub& operator[](Long_I i) const;
    Ldoub& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Ldoub *p() const;
};

inline DcmatLdoub::DcmatLdoub() {}

inline DcmatLdoub::DcmatLdoub(Ldoub *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLdoub::set(Ldoub *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLdoub::set(const DcmatLdoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatLdoub::operator DcmatLdoub_c() const
{
    return *((DcmatLdoub_c *)this);
}

inline Ldoub &DcmatLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Ldoub &DcmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLdoub::n0() const
{
    return m_N0;
}

inline Long DcmatLdoub::n1() const
{
    return m_N1;
}

inline Long DcmatLdoub::lda() const
{
    return m_lda;
}

inline Long DcmatLdoub::size() const
{
    return m_N;
}

inline Ldoub * DcmatLdoub::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatLdoub &DcmatLdoub_O, &DcmatLdoub_IO;

class DcmatQdoub_c
{
protected:
    const Qdoub *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatQdoub_c();
    DcmatQdoub_c(const Qdoub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Qdoub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatQdoub_c &sli);


    const Qdoub& operator[](Long_I i) const;
    const Qdoub& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Qdoub *p() const;
};

inline DcmatQdoub_c::DcmatQdoub_c() {}

inline DcmatQdoub_c::DcmatQdoub_c(const Qdoub *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatQdoub_c::set(const Qdoub *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatQdoub_c::set(const DcmatQdoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Qdoub &DcmatQdoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Qdoub &DcmatQdoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatQdoub_c::n0() const
{
    return m_N0;
}

inline Long DcmatQdoub_c::n1() const
{
    return m_N1;
}

inline Long DcmatQdoub_c::lda() const
{
    return m_lda;
}

inline Long DcmatQdoub_c::size() const
{
    return m_N;
}

inline const Qdoub * DcmatQdoub_c::p() const
{
    return m_p;
}

typedef const DcmatQdoub_c &DcmatQdoub_I;

class DcmatQdoub
{
protected:
    Qdoub *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatQdoub();
    DcmatQdoub(Qdoub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Qdoub *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatQdoub &sli);

    operator DcmatQdoub_c() const;

    Qdoub& operator[](Long_I i) const;
    Qdoub& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Qdoub *p() const;
};

inline DcmatQdoub::DcmatQdoub() {}

inline DcmatQdoub::DcmatQdoub(Qdoub *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatQdoub::set(Qdoub *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatQdoub::set(const DcmatQdoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatQdoub::operator DcmatQdoub_c() const
{
    return *((DcmatQdoub_c *)this);
}

inline Qdoub &DcmatQdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Qdoub &DcmatQdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatQdoub::n0() const
{
    return m_N0;
}

inline Long DcmatQdoub::n1() const
{
    return m_N1;
}

inline Long DcmatQdoub::lda() const
{
    return m_lda;
}

inline Long DcmatQdoub::size() const
{
    return m_N;
}

inline Qdoub * DcmatQdoub::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatQdoub &DcmatQdoub_O, &DcmatQdoub_IO;

class DcmatFcomp_c
{
protected:
    const Fcomp *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatFcomp_c();
    DcmatFcomp_c(const Fcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Fcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatFcomp_c &sli);


    const Fcomp& operator[](Long_I i) const;
    const Fcomp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Fcomp *p() const;
};

inline DcmatFcomp_c::DcmatFcomp_c() {}

inline DcmatFcomp_c::DcmatFcomp_c(const Fcomp *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatFcomp_c::set(const Fcomp *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatFcomp_c::set(const DcmatFcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Fcomp &DcmatFcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Fcomp &DcmatFcomp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatFcomp_c::n0() const
{
    return m_N0;
}

inline Long DcmatFcomp_c::n1() const
{
    return m_N1;
}

inline Long DcmatFcomp_c::lda() const
{
    return m_lda;
}

inline Long DcmatFcomp_c::size() const
{
    return m_N;
}

inline const Fcomp * DcmatFcomp_c::p() const
{
    return m_p;
}

typedef const DcmatFcomp_c &DcmatFcomp_I;

class DcmatFcomp
{
protected:
    Fcomp *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatFcomp();
    DcmatFcomp(Fcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Fcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatFcomp &sli);

    operator DcmatFcomp_c() const;

    Fcomp& operator[](Long_I i) const;
    Fcomp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Fcomp *p() const;
};

inline DcmatFcomp::DcmatFcomp() {}

inline DcmatFcomp::DcmatFcomp(Fcomp *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatFcomp::set(Fcomp *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatFcomp::set(const DcmatFcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatFcomp::operator DcmatFcomp_c() const
{
    return *((DcmatFcomp_c *)this);
}

inline Fcomp &DcmatFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Fcomp &DcmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatFcomp::n0() const
{
    return m_N0;
}

inline Long DcmatFcomp::n1() const
{
    return m_N1;
}

inline Long DcmatFcomp::lda() const
{
    return m_lda;
}

inline Long DcmatFcomp::size() const
{
    return m_N;
}

inline Fcomp * DcmatFcomp::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatFcomp &DcmatFcomp_O, &DcmatFcomp_IO;

class DcmatComp_c
{
protected:
    const Comp *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatComp_c();
    DcmatComp_c(const Comp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Comp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatComp_c &sli);


    const Comp& operator[](Long_I i) const;
    const Comp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Comp *p() const;
};

inline DcmatComp_c::DcmatComp_c() {}

inline DcmatComp_c::DcmatComp_c(const Comp *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatComp_c::set(const Comp *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatComp_c::set(const DcmatComp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Comp &DcmatComp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Comp &DcmatComp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatComp_c::n0() const
{
    return m_N0;
}

inline Long DcmatComp_c::n1() const
{
    return m_N1;
}

inline Long DcmatComp_c::lda() const
{
    return m_lda;
}

inline Long DcmatComp_c::size() const
{
    return m_N;
}

inline const Comp * DcmatComp_c::p() const
{
    return m_p;
}

typedef const DcmatComp_c &DcmatComp_I;

class DcmatComp
{
protected:
    Comp *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatComp();
    DcmatComp(Comp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Comp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatComp &sli);

    operator DcmatComp_c() const;

    Comp& operator[](Long_I i) const;
    Comp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Comp *p() const;
};

inline DcmatComp::DcmatComp() {}

inline DcmatComp::DcmatComp(Comp *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatComp::set(Comp *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatComp::set(const DcmatComp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatComp::operator DcmatComp_c() const
{
    return *((DcmatComp_c *)this);
}

inline Comp &DcmatComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Comp &DcmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatComp::n0() const
{
    return m_N0;
}

inline Long DcmatComp::n1() const
{
    return m_N1;
}

inline Long DcmatComp::lda() const
{
    return m_lda;
}

inline Long DcmatComp::size() const
{
    return m_N;
}

inline Comp * DcmatComp::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatComp &DcmatComp_O, &DcmatComp_IO;

class DcmatLcomp_c
{
protected:
    const Lcomp *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatLcomp_c();
    DcmatLcomp_c(const Lcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Lcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatLcomp_c &sli);


    const Lcomp& operator[](Long_I i) const;
    const Lcomp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Lcomp *p() const;
};

inline DcmatLcomp_c::DcmatLcomp_c() {}

inline DcmatLcomp_c::DcmatLcomp_c(const Lcomp *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLcomp_c::set(const Lcomp *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLcomp_c::set(const DcmatLcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Lcomp &DcmatLcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Lcomp &DcmatLcomp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLcomp_c::n0() const
{
    return m_N0;
}

inline Long DcmatLcomp_c::n1() const
{
    return m_N1;
}

inline Long DcmatLcomp_c::lda() const
{
    return m_lda;
}

inline Long DcmatLcomp_c::size() const
{
    return m_N;
}

inline const Lcomp * DcmatLcomp_c::p() const
{
    return m_p;
}

typedef const DcmatLcomp_c &DcmatLcomp_I;

class DcmatLcomp
{
protected:
    Lcomp *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatLcomp();
    DcmatLcomp(Lcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Lcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatLcomp &sli);

    operator DcmatLcomp_c() const;

    Lcomp& operator[](Long_I i) const;
    Lcomp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Lcomp *p() const;
};

inline DcmatLcomp::DcmatLcomp() {}

inline DcmatLcomp::DcmatLcomp(Lcomp *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLcomp::set(Lcomp *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLcomp::set(const DcmatLcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatLcomp::operator DcmatLcomp_c() const
{
    return *((DcmatLcomp_c *)this);
}

inline Lcomp &DcmatLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Lcomp &DcmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLcomp::n0() const
{
    return m_N0;
}

inline Long DcmatLcomp::n1() const
{
    return m_N1;
}

inline Long DcmatLcomp::lda() const
{
    return m_lda;
}

inline Long DcmatLcomp::size() const
{
    return m_N;
}

inline Lcomp * DcmatLcomp::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatLcomp &DcmatLcomp_O, &DcmatLcomp_IO;

class DcmatQcomp_c
{
protected:
    const Qcomp *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatQcomp_c();
    DcmatQcomp_c(const Qcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const Qcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatQcomp_c &sli);


    const Qcomp& operator[](Long_I i) const;
    const Qcomp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    const Qcomp *p() const;
};

inline DcmatQcomp_c::DcmatQcomp_c() {}

inline DcmatQcomp_c::DcmatQcomp_c(const Qcomp *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatQcomp_c::set(const Qcomp *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatQcomp_c::set(const DcmatQcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Qcomp &DcmatQcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline const Qcomp &DcmatQcomp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatQcomp_c::n0() const
{
    return m_N0;
}

inline Long DcmatQcomp_c::n1() const
{
    return m_N1;
}

inline Long DcmatQcomp_c::lda() const
{
    return m_lda;
}

inline Long DcmatQcomp_c::size() const
{
    return m_N;
}

inline const Qcomp * DcmatQcomp_c::p() const
{
    return m_p;
}

typedef const DcmatQcomp_c &DcmatQcomp_I;

class DcmatQcomp
{
protected:
    Qcomp *m_p;
    Long m_N;
    Long m_N0, m_N1;
    Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
    DcmatQcomp();
    DcmatQcomp(Qcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(Qcomp *p, Long_I N0, Long_I N1, Long_I lda);
    void set(const DcmatQcomp &sli);

    operator DcmatQcomp_c() const;

    Qcomp& operator[](Long_I i) const;
    Qcomp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    Long lda() const;
    Long size() const;
    Qcomp *p() const;
};

inline DcmatQcomp::DcmatQcomp() {}

inline DcmatQcomp::DcmatQcomp(Qcomp *p, Long_I N0, Long_I N1, Long_I lda)
    : m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatQcomp::set(Qcomp *p, Long_I N0, Long_I N1, Long_I lda)
{
    m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatQcomp::set(const DcmatQcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatQcomp::operator DcmatQcomp_c() const
{
    return *((DcmatQcomp_c *)this);
}

inline Qcomp &DcmatQcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N1 + m_lda * i / m_N1];
}

inline Qcomp &DcmatQcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatQcomp::n0() const
{
    return m_N0;
}

inline Long DcmatQcomp::n1() const
{
    return m_N1;
}

inline Long DcmatQcomp::lda() const
{
    return m_lda;
}

inline Long DcmatQcomp::size() const
{
    return m_N;
}

inline Qcomp * DcmatQcomp::p() const
{
    return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatQcomp &DcmatQcomp_O, &DcmatQcomp_IO;

} // namespace slisc
