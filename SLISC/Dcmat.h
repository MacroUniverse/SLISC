#pragma once

namespace slisc {
class DcmatChar_c
{
protected:
    const Char *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Char value_type;
    DcmatChar_c();
    DcmatChar_c(const Char *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Char *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatChar_c &sli);

    DcmatChar_c &operator=(const DcmatChar_c &) = delete;

    // === Cmat member functions ===
    const Char& operator[](Long_I i) const;
    const Char& operator()(Long_I i) const;
    const Char& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Char *ptr() const;
};

inline DcmatChar_c::DcmatChar_c() {}

inline DcmatChar_c::DcmatChar_c(const Char *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatChar_c::set(const Char *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatChar_c::set(const DcmatChar_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}


inline const Char & DcmatChar_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Char & DcmatChar_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Char & DcmatChar_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatChar_c::n1() const
{
    return m_N1;
}

inline Long DcmatChar_c::n2() const
{
    return m_N2;
}

inline Long DcmatChar_c::lda() const
{
    return m_lda;
}

inline Long DcmatChar_c::size() const
{
    return m_N;
}

inline const Char * DcmatChar_c::ptr() const
{
    return m_p;
}

typedef const DcmatChar_c & DcmatChar_I;

class DcmatChar
{
protected:
    Char *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Char value_type;
    DcmatChar();
    DcmatChar(Char *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Char *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatChar &sli);

    operator DcmatChar_c() const;
    DcmatChar &operator=(const DcmatChar &) = delete;

    // === Cmat member functions ===
    Char& operator[](Long_I i) const;
    Char& operator()(Long_I i) const;
    Char& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Char *ptr() const;
};

inline DcmatChar::DcmatChar() {}

inline DcmatChar::DcmatChar(Char *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatChar::set(Char *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatChar::set(const DcmatChar &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}

inline DcmatChar::operator DcmatChar_c() const
{
    return *((DcmatChar_c *)this);
}

inline Char & DcmatChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Char & DcmatChar::operator()(Long_I i) const
{
    return operator[](i);
}

inline Char & DcmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatChar::n1() const
{
    return m_N1;
}

inline Long DcmatChar::n2() const
{
    return m_N2;
}

inline Long DcmatChar::lda() const
{
    return m_lda;
}

inline Long DcmatChar::size() const
{
    return m_N;
}

inline Char * DcmatChar::ptr() const
{
    return m_p;
}

typedef const DcmatChar & DcmatChar_O, & DcmatChar_IO;

class DcmatInt_c
{
protected:
    const Int *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Int value_type;
    DcmatInt_c();
    DcmatInt_c(const Int *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Int *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatInt_c &sli);

    DcmatInt_c &operator=(const DcmatInt_c &) = delete;

    // === Cmat member functions ===
    const Int& operator[](Long_I i) const;
    const Int& operator()(Long_I i) const;
    const Int& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Int *ptr() const;
};

inline DcmatInt_c::DcmatInt_c() {}

inline DcmatInt_c::DcmatInt_c(const Int *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatInt_c::set(const Int *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatInt_c::set(const DcmatInt_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}


inline const Int & DcmatInt_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Int & DcmatInt_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Int & DcmatInt_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatInt_c::n1() const
{
    return m_N1;
}

inline Long DcmatInt_c::n2() const
{
    return m_N2;
}

inline Long DcmatInt_c::lda() const
{
    return m_lda;
}

inline Long DcmatInt_c::size() const
{
    return m_N;
}

inline const Int * DcmatInt_c::ptr() const
{
    return m_p;
}

typedef const DcmatInt_c & DcmatInt_I;

class DcmatInt
{
protected:
    Int *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Int value_type;
    DcmatInt();
    DcmatInt(Int *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Int *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatInt &sli);

    operator DcmatInt_c() const;
    DcmatInt &operator=(const DcmatInt &) = delete;

    // === Cmat member functions ===
    Int& operator[](Long_I i) const;
    Int& operator()(Long_I i) const;
    Int& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Int *ptr() const;
};

inline DcmatInt::DcmatInt() {}

inline DcmatInt::DcmatInt(Int *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatInt::set(Int *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatInt::set(const DcmatInt &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}

inline DcmatInt::operator DcmatInt_c() const
{
    return *((DcmatInt_c *)this);
}

inline Int & DcmatInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Int & DcmatInt::operator()(Long_I i) const
{
    return operator[](i);
}

inline Int & DcmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatInt::n1() const
{
    return m_N1;
}

inline Long DcmatInt::n2() const
{
    return m_N2;
}

inline Long DcmatInt::lda() const
{
    return m_lda;
}

inline Long DcmatInt::size() const
{
    return m_N;
}

inline Int * DcmatInt::ptr() const
{
    return m_p;
}

typedef const DcmatInt & DcmatInt_O, & DcmatInt_IO;

class DcmatLlong_c
{
protected:
    const Llong *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Llong value_type;
    DcmatLlong_c();
    DcmatLlong_c(const Llong *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Llong *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatLlong_c &sli);

    DcmatLlong_c &operator=(const DcmatLlong_c &) = delete;

    // === Cmat member functions ===
    const Llong& operator[](Long_I i) const;
    const Llong& operator()(Long_I i) const;
    const Llong& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Llong *ptr() const;
};

inline DcmatLlong_c::DcmatLlong_c() {}

inline DcmatLlong_c::DcmatLlong_c(const Llong *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatLlong_c::set(const Llong *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatLlong_c::set(const DcmatLlong_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}


inline const Llong & DcmatLlong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Llong & DcmatLlong_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Llong & DcmatLlong_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLlong_c::n1() const
{
    return m_N1;
}

inline Long DcmatLlong_c::n2() const
{
    return m_N2;
}

inline Long DcmatLlong_c::lda() const
{
    return m_lda;
}

inline Long DcmatLlong_c::size() const
{
    return m_N;
}

inline const Llong * DcmatLlong_c::ptr() const
{
    return m_p;
}

typedef const DcmatLlong_c & DcmatLlong_I;

class DcmatLlong
{
protected:
    Llong *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Llong value_type;
    DcmatLlong();
    DcmatLlong(Llong *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Llong *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatLlong &sli);

    operator DcmatLlong_c() const;
    DcmatLlong &operator=(const DcmatLlong &) = delete;

    // === Cmat member functions ===
    Llong& operator[](Long_I i) const;
    Llong& operator()(Long_I i) const;
    Llong& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Llong *ptr() const;
};

inline DcmatLlong::DcmatLlong() {}

inline DcmatLlong::DcmatLlong(Llong *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatLlong::set(Llong *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatLlong::set(const DcmatLlong &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}

inline DcmatLlong::operator DcmatLlong_c() const
{
    return *((DcmatLlong_c *)this);
}

inline Llong & DcmatLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Llong & DcmatLlong::operator()(Long_I i) const
{
    return operator[](i);
}

inline Llong & DcmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLlong::n1() const
{
    return m_N1;
}

inline Long DcmatLlong::n2() const
{
    return m_N2;
}

inline Long DcmatLlong::lda() const
{
    return m_lda;
}

inline Long DcmatLlong::size() const
{
    return m_N;
}

inline Llong * DcmatLlong::ptr() const
{
    return m_p;
}

typedef const DcmatLlong & DcmatLlong_O, & DcmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef DcmatInt_c DcmatLong_c;
#else
typedef DcmatLlong_c DcmatLong_c;
#endif

typedef const DcmatLong_c & DcmatLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef DcmatInt DcmatLong;
#else
typedef DcmatLlong DcmatLong;
#endif

typedef const DcmatLong & DcmatLong_O, & DcmatLong_IO;

class DcmatFloat_c
{
protected:
    const Float *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Float value_type;
    DcmatFloat_c();
    DcmatFloat_c(const Float *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Float *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatFloat_c &sli);

    DcmatFloat_c &operator=(const DcmatFloat_c &) = delete;

    // === Cmat member functions ===
    const Float& operator[](Long_I i) const;
    const Float& operator()(Long_I i) const;
    const Float& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Float *ptr() const;
};

inline DcmatFloat_c::DcmatFloat_c() {}

inline DcmatFloat_c::DcmatFloat_c(const Float *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatFloat_c::set(const Float *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatFloat_c::set(const DcmatFloat_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}


inline const Float & DcmatFloat_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Float & DcmatFloat_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Float & DcmatFloat_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatFloat_c::n1() const
{
    return m_N1;
}

inline Long DcmatFloat_c::n2() const
{
    return m_N2;
}

inline Long DcmatFloat_c::lda() const
{
    return m_lda;
}

inline Long DcmatFloat_c::size() const
{
    return m_N;
}

inline const Float * DcmatFloat_c::ptr() const
{
    return m_p;
}

typedef const DcmatFloat_c & DcmatFloat_I;

class DcmatFloat
{
protected:
    Float *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Float value_type;
    DcmatFloat();
    DcmatFloat(Float *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Float *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatFloat &sli);

    operator DcmatFloat_c() const;
    DcmatFloat &operator=(const DcmatFloat &) = delete;

    // === Cmat member functions ===
    Float& operator[](Long_I i) const;
    Float& operator()(Long_I i) const;
    Float& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Float *ptr() const;
};

inline DcmatFloat::DcmatFloat() {}

inline DcmatFloat::DcmatFloat(Float *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatFloat::set(Float *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatFloat::set(const DcmatFloat &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}

inline DcmatFloat::operator DcmatFloat_c() const
{
    return *((DcmatFloat_c *)this);
}

inline Float & DcmatFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Float & DcmatFloat::operator()(Long_I i) const
{
    return operator[](i);
}

inline Float & DcmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatFloat::n1() const
{
    return m_N1;
}

inline Long DcmatFloat::n2() const
{
    return m_N2;
}

inline Long DcmatFloat::lda() const
{
    return m_lda;
}

inline Long DcmatFloat::size() const
{
    return m_N;
}

inline Float * DcmatFloat::ptr() const
{
    return m_p;
}

typedef const DcmatFloat & DcmatFloat_O, & DcmatFloat_IO;

class DcmatDoub_c
{
protected:
    const Doub *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Doub value_type;
    DcmatDoub_c();
    DcmatDoub_c(const Doub *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Doub *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatDoub_c &sli);

    DcmatDoub_c &operator=(const DcmatDoub_c &) = delete;

    // === Cmat member functions ===
    const Doub& operator[](Long_I i) const;
    const Doub& operator()(Long_I i) const;
    const Doub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Doub *ptr() const;
};

inline DcmatDoub_c::DcmatDoub_c() {}

inline DcmatDoub_c::DcmatDoub_c(const Doub *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatDoub_c::set(const Doub *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatDoub_c::set(const DcmatDoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}


inline const Doub & DcmatDoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Doub & DcmatDoub_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Doub & DcmatDoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatDoub_c::n1() const
{
    return m_N1;
}

inline Long DcmatDoub_c::n2() const
{
    return m_N2;
}

inline Long DcmatDoub_c::lda() const
{
    return m_lda;
}

inline Long DcmatDoub_c::size() const
{
    return m_N;
}

inline const Doub * DcmatDoub_c::ptr() const
{
    return m_p;
}

typedef const DcmatDoub_c & DcmatDoub_I;

class DcmatDoub
{
protected:
    Doub *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Doub value_type;
    DcmatDoub();
    DcmatDoub(Doub *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Doub *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatDoub &sli);

    operator DcmatDoub_c() const;
    DcmatDoub &operator=(const DcmatDoub &) = delete;

    // === Cmat member functions ===
    Doub& operator[](Long_I i) const;
    Doub& operator()(Long_I i) const;
    Doub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Doub *ptr() const;
};

inline DcmatDoub::DcmatDoub() {}

inline DcmatDoub::DcmatDoub(Doub *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatDoub::set(Doub *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatDoub::set(const DcmatDoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}

inline DcmatDoub::operator DcmatDoub_c() const
{
    return *((DcmatDoub_c *)this);
}

inline Doub & DcmatDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Doub & DcmatDoub::operator()(Long_I i) const
{
    return operator[](i);
}

inline Doub & DcmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatDoub::n1() const
{
    return m_N1;
}

inline Long DcmatDoub::n2() const
{
    return m_N2;
}

inline Long DcmatDoub::lda() const
{
    return m_lda;
}

inline Long DcmatDoub::size() const
{
    return m_N;
}

inline Doub * DcmatDoub::ptr() const
{
    return m_p;
}

typedef const DcmatDoub & DcmatDoub_O, & DcmatDoub_IO;

class DcmatLdoub_c
{
protected:
    const Ldoub *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Ldoub value_type;
    DcmatLdoub_c();
    DcmatLdoub_c(const Ldoub *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Ldoub *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatLdoub_c &sli);

    DcmatLdoub_c &operator=(const DcmatLdoub_c &) = delete;

    // === Cmat member functions ===
    const Ldoub& operator[](Long_I i) const;
    const Ldoub& operator()(Long_I i) const;
    const Ldoub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Ldoub *ptr() const;
};

inline DcmatLdoub_c::DcmatLdoub_c() {}

inline DcmatLdoub_c::DcmatLdoub_c(const Ldoub *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatLdoub_c::set(const Ldoub *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatLdoub_c::set(const DcmatLdoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}


inline const Ldoub & DcmatLdoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Ldoub & DcmatLdoub_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Ldoub & DcmatLdoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLdoub_c::n1() const
{
    return m_N1;
}

inline Long DcmatLdoub_c::n2() const
{
    return m_N2;
}

inline Long DcmatLdoub_c::lda() const
{
    return m_lda;
}

inline Long DcmatLdoub_c::size() const
{
    return m_N;
}

inline const Ldoub * DcmatLdoub_c::ptr() const
{
    return m_p;
}

typedef const DcmatLdoub_c & DcmatLdoub_I;

class DcmatLdoub
{
protected:
    Ldoub *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Ldoub value_type;
    DcmatLdoub();
    DcmatLdoub(Ldoub *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Ldoub *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatLdoub &sli);

    operator DcmatLdoub_c() const;
    DcmatLdoub &operator=(const DcmatLdoub &) = delete;

    // === Cmat member functions ===
    Ldoub& operator[](Long_I i) const;
    Ldoub& operator()(Long_I i) const;
    Ldoub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Ldoub *ptr() const;
};

inline DcmatLdoub::DcmatLdoub() {}

inline DcmatLdoub::DcmatLdoub(Ldoub *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatLdoub::set(Ldoub *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatLdoub::set(const DcmatLdoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}

inline DcmatLdoub::operator DcmatLdoub_c() const
{
    return *((DcmatLdoub_c *)this);
}

inline Ldoub & DcmatLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Ldoub & DcmatLdoub::operator()(Long_I i) const
{
    return operator[](i);
}

inline Ldoub & DcmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLdoub::n1() const
{
    return m_N1;
}

inline Long DcmatLdoub::n2() const
{
    return m_N2;
}

inline Long DcmatLdoub::lda() const
{
    return m_lda;
}

inline Long DcmatLdoub::size() const
{
    return m_N;
}

inline Ldoub * DcmatLdoub::ptr() const
{
    return m_p;
}

typedef const DcmatLdoub & DcmatLdoub_O, & DcmatLdoub_IO;

class DcmatFcomp_c
{
protected:
    const Fcomp *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Fcomp value_type;
    DcmatFcomp_c();
    DcmatFcomp_c(const Fcomp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Fcomp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatFcomp_c &sli);

    DcmatFcomp_c &operator=(const DcmatFcomp_c &) = delete;

    // === Cmat member functions ===
    const Fcomp& operator[](Long_I i) const;
    const Fcomp& operator()(Long_I i) const;
    const Fcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Fcomp *ptr() const;
};

inline DcmatFcomp_c::DcmatFcomp_c() {}

inline DcmatFcomp_c::DcmatFcomp_c(const Fcomp *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatFcomp_c::set(const Fcomp *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatFcomp_c::set(const DcmatFcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}


inline const Fcomp & DcmatFcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Fcomp & DcmatFcomp_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Fcomp & DcmatFcomp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatFcomp_c::n1() const
{
    return m_N1;
}

inline Long DcmatFcomp_c::n2() const
{
    return m_N2;
}

inline Long DcmatFcomp_c::lda() const
{
    return m_lda;
}

inline Long DcmatFcomp_c::size() const
{
    return m_N;
}

inline const Fcomp * DcmatFcomp_c::ptr() const
{
    return m_p;
}

typedef const DcmatFcomp_c & DcmatFcomp_I;

class DcmatFcomp
{
protected:
    Fcomp *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Fcomp value_type;
    DcmatFcomp();
    DcmatFcomp(Fcomp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Fcomp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatFcomp &sli);

    operator DcmatFcomp_c() const;
    DcmatFcomp &operator=(const DcmatFcomp &) = delete;

    // === Cmat member functions ===
    Fcomp& operator[](Long_I i) const;
    Fcomp& operator()(Long_I i) const;
    Fcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Fcomp *ptr() const;
};

inline DcmatFcomp::DcmatFcomp() {}

inline DcmatFcomp::DcmatFcomp(Fcomp *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatFcomp::set(Fcomp *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatFcomp::set(const DcmatFcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}

inline DcmatFcomp::operator DcmatFcomp_c() const
{
    return *((DcmatFcomp_c *)this);
}

inline Fcomp & DcmatFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Fcomp & DcmatFcomp::operator()(Long_I i) const
{
    return operator[](i);
}

inline Fcomp & DcmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatFcomp::n1() const
{
    return m_N1;
}

inline Long DcmatFcomp::n2() const
{
    return m_N2;
}

inline Long DcmatFcomp::lda() const
{
    return m_lda;
}

inline Long DcmatFcomp::size() const
{
    return m_N;
}

inline Fcomp * DcmatFcomp::ptr() const
{
    return m_p;
}

typedef const DcmatFcomp & DcmatFcomp_O, & DcmatFcomp_IO;

class DcmatComp_c
{
protected:
    const Comp *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Comp value_type;
    DcmatComp_c();
    DcmatComp_c(const Comp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Comp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatComp_c &sli);

    DcmatComp_c &operator=(const DcmatComp_c &) = delete;

    // === Cmat member functions ===
    const Comp& operator[](Long_I i) const;
    const Comp& operator()(Long_I i) const;
    const Comp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Comp *ptr() const;
};

inline DcmatComp_c::DcmatComp_c() {}

inline DcmatComp_c::DcmatComp_c(const Comp *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatComp_c::set(const Comp *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatComp_c::set(const DcmatComp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}


inline const Comp & DcmatComp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Comp & DcmatComp_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Comp & DcmatComp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatComp_c::n1() const
{
    return m_N1;
}

inline Long DcmatComp_c::n2() const
{
    return m_N2;
}

inline Long DcmatComp_c::lda() const
{
    return m_lda;
}

inline Long DcmatComp_c::size() const
{
    return m_N;
}

inline const Comp * DcmatComp_c::ptr() const
{
    return m_p;
}

typedef const DcmatComp_c & DcmatComp_I;

class DcmatComp
{
protected:
    Comp *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Comp value_type;
    DcmatComp();
    DcmatComp(Comp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Comp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatComp &sli);

    operator DcmatComp_c() const;
    DcmatComp &operator=(const DcmatComp &) = delete;

    // === Cmat member functions ===
    Comp& operator[](Long_I i) const;
    Comp& operator()(Long_I i) const;
    Comp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Comp *ptr() const;
};

inline DcmatComp::DcmatComp() {}

inline DcmatComp::DcmatComp(Comp *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatComp::set(Comp *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatComp::set(const DcmatComp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}

inline DcmatComp::operator DcmatComp_c() const
{
    return *((DcmatComp_c *)this);
}

inline Comp & DcmatComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Comp & DcmatComp::operator()(Long_I i) const
{
    return operator[](i);
}

inline Comp & DcmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatComp::n1() const
{
    return m_N1;
}

inline Long DcmatComp::n2() const
{
    return m_N2;
}

inline Long DcmatComp::lda() const
{
    return m_lda;
}

inline Long DcmatComp::size() const
{
    return m_N;
}

inline Comp * DcmatComp::ptr() const
{
    return m_p;
}

typedef const DcmatComp & DcmatComp_O, & DcmatComp_IO;

class DcmatLcomp_c
{
protected:
    const Lcomp *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Lcomp value_type;
    DcmatLcomp_c();
    DcmatLcomp_c(const Lcomp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Lcomp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatLcomp_c &sli);

    DcmatLcomp_c &operator=(const DcmatLcomp_c &) = delete;

    // === Cmat member functions ===
    const Lcomp& operator[](Long_I i) const;
    const Lcomp& operator()(Long_I i) const;
    const Lcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Lcomp *ptr() const;
};

inline DcmatLcomp_c::DcmatLcomp_c() {}

inline DcmatLcomp_c::DcmatLcomp_c(const Lcomp *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatLcomp_c::set(const Lcomp *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatLcomp_c::set(const DcmatLcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}


inline const Lcomp & DcmatLcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Lcomp & DcmatLcomp_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Lcomp & DcmatLcomp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLcomp_c::n1() const
{
    return m_N1;
}

inline Long DcmatLcomp_c::n2() const
{
    return m_N2;
}

inline Long DcmatLcomp_c::lda() const
{
    return m_lda;
}

inline Long DcmatLcomp_c::size() const
{
    return m_N;
}

inline const Lcomp * DcmatLcomp_c::ptr() const
{
    return m_p;
}

typedef const DcmatLcomp_c & DcmatLcomp_I;

class DcmatLcomp
{
protected:
    Lcomp *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Lcomp value_type;
    DcmatLcomp();
    DcmatLcomp(Lcomp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Lcomp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const DcmatLcomp &sli);

    operator DcmatLcomp_c() const;
    DcmatLcomp &operator=(const DcmatLcomp &) = delete;

    // === Cmat member functions ===
    Lcomp& operator[](Long_I i) const;
    Lcomp& operator()(Long_I i) const;
    Lcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Lcomp *ptr() const;
};

inline DcmatLcomp::DcmatLcomp() {}

inline DcmatLcomp::DcmatLcomp(Lcomp *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatLcomp::set(Lcomp *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline void DcmatLcomp::set(const DcmatLcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_lda = sli.m_lda;
}

inline DcmatLcomp::operator DcmatLcomp_c() const
{
    return *((DcmatLcomp_c *)this);
}

inline Lcomp & DcmatLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Lcomp & DcmatLcomp::operator()(Long_I i) const
{
    return operator[](i);
}

inline Lcomp & DcmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLcomp::n1() const
{
    return m_N1;
}

inline Long DcmatLcomp::n2() const
{
    return m_N2;
}

inline Long DcmatLcomp::lda() const
{
    return m_lda;
}

inline Long DcmatLcomp::size() const
{
    return m_N;
}

inline Lcomp * DcmatLcomp::ptr() const
{
    return m_p;
}

typedef const DcmatLcomp & DcmatLcomp_O, & DcmatLcomp_IO;

} // namespace slisc
