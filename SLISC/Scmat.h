#pragma once
#include "Svec.h"

namespace slisc {
class ScmatChar_c : public SvecChar_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatChar_c();
    ScmatChar_c(Long_I N1, Long_I N2);
    ScmatChar_c(const Char *ptr, Long_I N1, Long_I N2);

    ScmatChar_c &operator=(const ScmatChar_c &) = delete;

    // === Cmat functions ===
    const Char& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Char *ptr, Long_I N1, Long_I N2);
    void set(const ScmatChar_c &sli);
    ~ScmatChar_c();
};

inline ScmatChar_c::ScmatChar_c() {}

inline ScmatChar_c::ScmatChar_c(Long_I N1, Long_I N2)
    : SvecChar_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatChar_c::ScmatChar_c(const Char *ptr, Long_I N1, Long_I N2)
    : ScmatChar_c(N1, N2)
{
    m_p = ptr;
}


inline const Char & ScmatChar_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatChar_c::n1() const
{
    return m_N1;
}

inline Long ScmatChar_c::n2() const
{
    return m_N2;
}

inline void ScmatChar_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatChar_c::set(const Char * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatChar_c::set(const ScmatChar_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatChar_c::~ScmatChar_c() {}

typedef const ScmatChar_c & ScmatChar_I;

class ScmatChar : public SvecChar
{
protected:
    Long m_N1, m_N2;
public:
    ScmatChar();
    ScmatChar(Long_I N1, Long_I N2);
    ScmatChar(Char *ptr, Long_I N1, Long_I N2);

    operator ScmatChar_c() const;
    ScmatChar &operator=(const ScmatChar &) = delete;

    // === Cmat functions ===
    Char& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Char *ptr, Long_I N1, Long_I N2);
    void set(const ScmatChar &sli);
    ~ScmatChar();
};

inline ScmatChar::ScmatChar() {}

inline ScmatChar::ScmatChar(Long_I N1, Long_I N2)
    : SvecChar(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatChar::ScmatChar(Char *ptr, Long_I N1, Long_I N2)
    : ScmatChar(N1, N2)
{
    m_p = ptr;
}

inline ScmatChar::operator ScmatChar_c() const
{
    return *((ScmatChar_c *)this);
}

inline Char & ScmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatChar::n1() const
{
    return m_N1;
}

inline Long ScmatChar::n2() const
{
    return m_N2;
}

inline void ScmatChar::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatChar::set(Char * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatChar::set(const ScmatChar &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatChar::~ScmatChar() {}

typedef const ScmatChar & ScmatChar_O, & ScmatChar_IO;

class ScmatInt_c : public SvecInt_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatInt_c();
    ScmatInt_c(Long_I N1, Long_I N2);
    ScmatInt_c(const Int *ptr, Long_I N1, Long_I N2);

    ScmatInt_c &operator=(const ScmatInt_c &) = delete;

    // === Cmat functions ===
    const Int& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Int *ptr, Long_I N1, Long_I N2);
    void set(const ScmatInt_c &sli);
    ~ScmatInt_c();
};

inline ScmatInt_c::ScmatInt_c() {}

inline ScmatInt_c::ScmatInt_c(Long_I N1, Long_I N2)
    : SvecInt_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatInt_c::ScmatInt_c(const Int *ptr, Long_I N1, Long_I N2)
    : ScmatInt_c(N1, N2)
{
    m_p = ptr;
}


inline const Int & ScmatInt_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatInt_c::n1() const
{
    return m_N1;
}

inline Long ScmatInt_c::n2() const
{
    return m_N2;
}

inline void ScmatInt_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatInt_c::set(const Int * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatInt_c::set(const ScmatInt_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatInt_c::~ScmatInt_c() {}

typedef const ScmatInt_c & ScmatInt_I;

class ScmatInt : public SvecInt
{
protected:
    Long m_N1, m_N2;
public:
    ScmatInt();
    ScmatInt(Long_I N1, Long_I N2);
    ScmatInt(Int *ptr, Long_I N1, Long_I N2);

    operator ScmatInt_c() const;
    ScmatInt &operator=(const ScmatInt &) = delete;

    // === Cmat functions ===
    Int& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Int *ptr, Long_I N1, Long_I N2);
    void set(const ScmatInt &sli);
    ~ScmatInt();
};

inline ScmatInt::ScmatInt() {}

inline ScmatInt::ScmatInt(Long_I N1, Long_I N2)
    : SvecInt(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatInt::ScmatInt(Int *ptr, Long_I N1, Long_I N2)
    : ScmatInt(N1, N2)
{
    m_p = ptr;
}

inline ScmatInt::operator ScmatInt_c() const
{
    return *((ScmatInt_c *)this);
}

inline Int & ScmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatInt::n1() const
{
    return m_N1;
}

inline Long ScmatInt::n2() const
{
    return m_N2;
}

inline void ScmatInt::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatInt::set(Int * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatInt::set(const ScmatInt &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatInt::~ScmatInt() {}

typedef const ScmatInt & ScmatInt_O, & ScmatInt_IO;

class ScmatLlong_c : public SvecLlong_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatLlong_c();
    ScmatLlong_c(Long_I N1, Long_I N2);
    ScmatLlong_c(const Llong *ptr, Long_I N1, Long_I N2);

    ScmatLlong_c &operator=(const ScmatLlong_c &) = delete;

    // === Cmat functions ===
    const Llong& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Llong *ptr, Long_I N1, Long_I N2);
    void set(const ScmatLlong_c &sli);
    ~ScmatLlong_c();
};

inline ScmatLlong_c::ScmatLlong_c() {}

inline ScmatLlong_c::ScmatLlong_c(Long_I N1, Long_I N2)
    : SvecLlong_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLlong_c::ScmatLlong_c(const Llong *ptr, Long_I N1, Long_I N2)
    : ScmatLlong_c(N1, N2)
{
    m_p = ptr;
}


inline const Llong & ScmatLlong_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLlong_c::n1() const
{
    return m_N1;
}

inline Long ScmatLlong_c::n2() const
{
    return m_N2;
}

inline void ScmatLlong_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLlong_c::set(const Llong * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLlong_c::set(const ScmatLlong_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatLlong_c::~ScmatLlong_c() {}

typedef const ScmatLlong_c & ScmatLlong_I;

class ScmatLlong : public SvecLlong
{
protected:
    Long m_N1, m_N2;
public:
    ScmatLlong();
    ScmatLlong(Long_I N1, Long_I N2);
    ScmatLlong(Llong *ptr, Long_I N1, Long_I N2);

    operator ScmatLlong_c() const;
    ScmatLlong &operator=(const ScmatLlong &) = delete;

    // === Cmat functions ===
    Llong& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Llong *ptr, Long_I N1, Long_I N2);
    void set(const ScmatLlong &sli);
    ~ScmatLlong();
};

inline ScmatLlong::ScmatLlong() {}

inline ScmatLlong::ScmatLlong(Long_I N1, Long_I N2)
    : SvecLlong(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLlong::ScmatLlong(Llong *ptr, Long_I N1, Long_I N2)
    : ScmatLlong(N1, N2)
{
    m_p = ptr;
}

inline ScmatLlong::operator ScmatLlong_c() const
{
    return *((ScmatLlong_c *)this);
}

inline Llong & ScmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLlong::n1() const
{
    return m_N1;
}

inline Long ScmatLlong::n2() const
{
    return m_N2;
}

inline void ScmatLlong::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLlong::set(Llong * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLlong::set(const ScmatLlong &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatLlong::~ScmatLlong() {}

typedef const ScmatLlong & ScmatLlong_O, & ScmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef ScmatInt_c ScmatLong_c;
#else
typedef ScmatLlong_c ScmatLong_c;
#endif

typedef const ScmatLong_c & ScmatLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef ScmatInt ScmatLong;
#else
typedef ScmatLlong ScmatLong;
#endif

typedef const ScmatLong & ScmatLong_O, & ScmatLong_IO;

class ScmatFloat_c : public SvecFloat_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatFloat_c();
    ScmatFloat_c(Long_I N1, Long_I N2);
    ScmatFloat_c(const Float *ptr, Long_I N1, Long_I N2);

    ScmatFloat_c &operator=(const ScmatFloat_c &) = delete;

    // === Cmat functions ===
    const Float& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Float *ptr, Long_I N1, Long_I N2);
    void set(const ScmatFloat_c &sli);
    ~ScmatFloat_c();
};

inline ScmatFloat_c::ScmatFloat_c() {}

inline ScmatFloat_c::ScmatFloat_c(Long_I N1, Long_I N2)
    : SvecFloat_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatFloat_c::ScmatFloat_c(const Float *ptr, Long_I N1, Long_I N2)
    : ScmatFloat_c(N1, N2)
{
    m_p = ptr;
}


inline const Float & ScmatFloat_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatFloat_c::n1() const
{
    return m_N1;
}

inline Long ScmatFloat_c::n2() const
{
    return m_N2;
}

inline void ScmatFloat_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFloat_c::set(const Float * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFloat_c::set(const ScmatFloat_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatFloat_c::~ScmatFloat_c() {}

typedef const ScmatFloat_c & ScmatFloat_I;

class ScmatFloat : public SvecFloat
{
protected:
    Long m_N1, m_N2;
public:
    ScmatFloat();
    ScmatFloat(Long_I N1, Long_I N2);
    ScmatFloat(Float *ptr, Long_I N1, Long_I N2);

    operator ScmatFloat_c() const;
    ScmatFloat &operator=(const ScmatFloat &) = delete;

    // === Cmat functions ===
    Float& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Float *ptr, Long_I N1, Long_I N2);
    void set(const ScmatFloat &sli);
    ~ScmatFloat();
};

inline ScmatFloat::ScmatFloat() {}

inline ScmatFloat::ScmatFloat(Long_I N1, Long_I N2)
    : SvecFloat(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatFloat::ScmatFloat(Float *ptr, Long_I N1, Long_I N2)
    : ScmatFloat(N1, N2)
{
    m_p = ptr;
}

inline ScmatFloat::operator ScmatFloat_c() const
{
    return *((ScmatFloat_c *)this);
}

inline Float & ScmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatFloat::n1() const
{
    return m_N1;
}

inline Long ScmatFloat::n2() const
{
    return m_N2;
}

inline void ScmatFloat::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFloat::set(Float * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFloat::set(const ScmatFloat &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatFloat::~ScmatFloat() {}

typedef const ScmatFloat & ScmatFloat_O, & ScmatFloat_IO;

class ScmatDoub_c : public SvecDoub_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatDoub_c();
    ScmatDoub_c(Long_I N1, Long_I N2);
    ScmatDoub_c(const Doub *ptr, Long_I N1, Long_I N2);

    ScmatDoub_c &operator=(const ScmatDoub_c &) = delete;

    // === Cmat functions ===
    const Doub& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Doub *ptr, Long_I N1, Long_I N2);
    void set(const ScmatDoub_c &sli);
    ~ScmatDoub_c();
};

inline ScmatDoub_c::ScmatDoub_c() {}

inline ScmatDoub_c::ScmatDoub_c(Long_I N1, Long_I N2)
    : SvecDoub_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatDoub_c::ScmatDoub_c(const Doub *ptr, Long_I N1, Long_I N2)
    : ScmatDoub_c(N1, N2)
{
    m_p = ptr;
}


inline const Doub & ScmatDoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatDoub_c::n1() const
{
    return m_N1;
}

inline Long ScmatDoub_c::n2() const
{
    return m_N2;
}

inline void ScmatDoub_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatDoub_c::set(const Doub * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatDoub_c::set(const ScmatDoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatDoub_c::~ScmatDoub_c() {}

typedef const ScmatDoub_c & ScmatDoub_I;

class ScmatDoub : public SvecDoub
{
protected:
    Long m_N1, m_N2;
public:
    ScmatDoub();
    ScmatDoub(Long_I N1, Long_I N2);
    ScmatDoub(Doub *ptr, Long_I N1, Long_I N2);

    operator ScmatDoub_c() const;
    ScmatDoub &operator=(const ScmatDoub &) = delete;

    // === Cmat functions ===
    Doub& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Doub *ptr, Long_I N1, Long_I N2);
    void set(const ScmatDoub &sli);
    ~ScmatDoub();
};

inline ScmatDoub::ScmatDoub() {}

inline ScmatDoub::ScmatDoub(Long_I N1, Long_I N2)
    : SvecDoub(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatDoub::ScmatDoub(Doub *ptr, Long_I N1, Long_I N2)
    : ScmatDoub(N1, N2)
{
    m_p = ptr;
}

inline ScmatDoub::operator ScmatDoub_c() const
{
    return *((ScmatDoub_c *)this);
}

inline Doub & ScmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatDoub::n1() const
{
    return m_N1;
}

inline Long ScmatDoub::n2() const
{
    return m_N2;
}

inline void ScmatDoub::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatDoub::set(Doub * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatDoub::set(const ScmatDoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatDoub::~ScmatDoub() {}

typedef const ScmatDoub & ScmatDoub_O, & ScmatDoub_IO;

class ScmatLdoub_c : public SvecLdoub_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatLdoub_c();
    ScmatLdoub_c(Long_I N1, Long_I N2);
    ScmatLdoub_c(const Ldoub *ptr, Long_I N1, Long_I N2);

    ScmatLdoub_c &operator=(const ScmatLdoub_c &) = delete;

    // === Cmat functions ===
    const Ldoub& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Ldoub *ptr, Long_I N1, Long_I N2);
    void set(const ScmatLdoub_c &sli);
    ~ScmatLdoub_c();
};

inline ScmatLdoub_c::ScmatLdoub_c() {}

inline ScmatLdoub_c::ScmatLdoub_c(Long_I N1, Long_I N2)
    : SvecLdoub_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLdoub_c::ScmatLdoub_c(const Ldoub *ptr, Long_I N1, Long_I N2)
    : ScmatLdoub_c(N1, N2)
{
    m_p = ptr;
}


inline const Ldoub & ScmatLdoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLdoub_c::n1() const
{
    return m_N1;
}

inline Long ScmatLdoub_c::n2() const
{
    return m_N2;
}

inline void ScmatLdoub_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLdoub_c::set(const Ldoub * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLdoub_c::set(const ScmatLdoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatLdoub_c::~ScmatLdoub_c() {}

typedef const ScmatLdoub_c & ScmatLdoub_I;

class ScmatLdoub : public SvecLdoub
{
protected:
    Long m_N1, m_N2;
public:
    ScmatLdoub();
    ScmatLdoub(Long_I N1, Long_I N2);
    ScmatLdoub(Ldoub *ptr, Long_I N1, Long_I N2);

    operator ScmatLdoub_c() const;
    ScmatLdoub &operator=(const ScmatLdoub &) = delete;

    // === Cmat functions ===
    Ldoub& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Ldoub *ptr, Long_I N1, Long_I N2);
    void set(const ScmatLdoub &sli);
    ~ScmatLdoub();
};

inline ScmatLdoub::ScmatLdoub() {}

inline ScmatLdoub::ScmatLdoub(Long_I N1, Long_I N2)
    : SvecLdoub(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLdoub::ScmatLdoub(Ldoub *ptr, Long_I N1, Long_I N2)
    : ScmatLdoub(N1, N2)
{
    m_p = ptr;
}

inline ScmatLdoub::operator ScmatLdoub_c() const
{
    return *((ScmatLdoub_c *)this);
}

inline Ldoub & ScmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLdoub::n1() const
{
    return m_N1;
}

inline Long ScmatLdoub::n2() const
{
    return m_N2;
}

inline void ScmatLdoub::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLdoub::set(Ldoub * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLdoub::set(const ScmatLdoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatLdoub::~ScmatLdoub() {}

typedef const ScmatLdoub & ScmatLdoub_O, & ScmatLdoub_IO;

class ScmatFcomp_c : public SvecFcomp_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatFcomp_c();
    ScmatFcomp_c(Long_I N1, Long_I N2);
    ScmatFcomp_c(const Fcomp *ptr, Long_I N1, Long_I N2);

    ScmatFcomp_c &operator=(const ScmatFcomp_c &) = delete;

    // === Cmat functions ===
    const Fcomp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Fcomp *ptr, Long_I N1, Long_I N2);
    void set(const ScmatFcomp_c &sli);
    ~ScmatFcomp_c();
};

inline ScmatFcomp_c::ScmatFcomp_c() {}

inline ScmatFcomp_c::ScmatFcomp_c(Long_I N1, Long_I N2)
    : SvecFcomp_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatFcomp_c::ScmatFcomp_c(const Fcomp *ptr, Long_I N1, Long_I N2)
    : ScmatFcomp_c(N1, N2)
{
    m_p = ptr;
}


inline const Fcomp & ScmatFcomp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatFcomp_c::n1() const
{
    return m_N1;
}

inline Long ScmatFcomp_c::n2() const
{
    return m_N2;
}

inline void ScmatFcomp_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFcomp_c::set(const Fcomp * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFcomp_c::set(const ScmatFcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatFcomp_c::~ScmatFcomp_c() {}

typedef const ScmatFcomp_c & ScmatFcomp_I;

class ScmatFcomp : public SvecFcomp
{
protected:
    Long m_N1, m_N2;
public:
    ScmatFcomp();
    ScmatFcomp(Long_I N1, Long_I N2);
    ScmatFcomp(Fcomp *ptr, Long_I N1, Long_I N2);

    operator ScmatFcomp_c() const;
    ScmatFcomp &operator=(const ScmatFcomp &) = delete;

    // === Cmat functions ===
    Fcomp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Fcomp *ptr, Long_I N1, Long_I N2);
    void set(const ScmatFcomp &sli);
    ~ScmatFcomp();
};

inline ScmatFcomp::ScmatFcomp() {}

inline ScmatFcomp::ScmatFcomp(Long_I N1, Long_I N2)
    : SvecFcomp(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatFcomp::ScmatFcomp(Fcomp *ptr, Long_I N1, Long_I N2)
    : ScmatFcomp(N1, N2)
{
    m_p = ptr;
}

inline ScmatFcomp::operator ScmatFcomp_c() const
{
    return *((ScmatFcomp_c *)this);
}

inline Fcomp & ScmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatFcomp::n1() const
{
    return m_N1;
}

inline Long ScmatFcomp::n2() const
{
    return m_N2;
}

inline void ScmatFcomp::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFcomp::set(Fcomp * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFcomp::set(const ScmatFcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatFcomp::~ScmatFcomp() {}

typedef const ScmatFcomp & ScmatFcomp_O, & ScmatFcomp_IO;

class ScmatComp_c : public SvecComp_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatComp_c();
    ScmatComp_c(Long_I N1, Long_I N2);
    ScmatComp_c(const Comp *ptr, Long_I N1, Long_I N2);

    ScmatComp_c &operator=(const ScmatComp_c &) = delete;

    // === Cmat functions ===
    const Comp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Comp *ptr, Long_I N1, Long_I N2);
    void set(const ScmatComp_c &sli);
    ~ScmatComp_c();
};

inline ScmatComp_c::ScmatComp_c() {}

inline ScmatComp_c::ScmatComp_c(Long_I N1, Long_I N2)
    : SvecComp_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatComp_c::ScmatComp_c(const Comp *ptr, Long_I N1, Long_I N2)
    : ScmatComp_c(N1, N2)
{
    m_p = ptr;
}


inline const Comp & ScmatComp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatComp_c::n1() const
{
    return m_N1;
}

inline Long ScmatComp_c::n2() const
{
    return m_N2;
}

inline void ScmatComp_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatComp_c::set(const Comp * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatComp_c::set(const ScmatComp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatComp_c::~ScmatComp_c() {}

typedef const ScmatComp_c & ScmatComp_I;

class ScmatComp : public SvecComp
{
protected:
    Long m_N1, m_N2;
public:
    ScmatComp();
    ScmatComp(Long_I N1, Long_I N2);
    ScmatComp(Comp *ptr, Long_I N1, Long_I N2);

    operator ScmatComp_c() const;
    ScmatComp &operator=(const ScmatComp &) = delete;

    // === Cmat functions ===
    Comp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Comp *ptr, Long_I N1, Long_I N2);
    void set(const ScmatComp &sli);
    ~ScmatComp();
};

inline ScmatComp::ScmatComp() {}

inline ScmatComp::ScmatComp(Long_I N1, Long_I N2)
    : SvecComp(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatComp::ScmatComp(Comp *ptr, Long_I N1, Long_I N2)
    : ScmatComp(N1, N2)
{
    m_p = ptr;
}

inline ScmatComp::operator ScmatComp_c() const
{
    return *((ScmatComp_c *)this);
}

inline Comp & ScmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatComp::n1() const
{
    return m_N1;
}

inline Long ScmatComp::n2() const
{
    return m_N2;
}

inline void ScmatComp::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatComp::set(Comp * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatComp::set(const ScmatComp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatComp::~ScmatComp() {}

typedef const ScmatComp & ScmatComp_O, & ScmatComp_IO;

class ScmatLcomp_c : public SvecLcomp_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatLcomp_c();
    ScmatLcomp_c(Long_I N1, Long_I N2);
    ScmatLcomp_c(const Lcomp *ptr, Long_I N1, Long_I N2);

    ScmatLcomp_c &operator=(const ScmatLcomp_c &) = delete;

    // === Cmat functions ===
    const Lcomp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Lcomp *ptr, Long_I N1, Long_I N2);
    void set(const ScmatLcomp_c &sli);
    ~ScmatLcomp_c();
};

inline ScmatLcomp_c::ScmatLcomp_c() {}

inline ScmatLcomp_c::ScmatLcomp_c(Long_I N1, Long_I N2)
    : SvecLcomp_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLcomp_c::ScmatLcomp_c(const Lcomp *ptr, Long_I N1, Long_I N2)
    : ScmatLcomp_c(N1, N2)
{
    m_p = ptr;
}


inline const Lcomp & ScmatLcomp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLcomp_c::n1() const
{
    return m_N1;
}

inline Long ScmatLcomp_c::n2() const
{
    return m_N2;
}

inline void ScmatLcomp_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLcomp_c::set(const Lcomp * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLcomp_c::set(const ScmatLcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatLcomp_c::~ScmatLcomp_c() {}

typedef const ScmatLcomp_c & ScmatLcomp_I;

class ScmatLcomp : public SvecLcomp
{
protected:
    Long m_N1, m_N2;
public:
    ScmatLcomp();
    ScmatLcomp(Long_I N1, Long_I N2);
    ScmatLcomp(Lcomp *ptr, Long_I N1, Long_I N2);

    operator ScmatLcomp_c() const;
    ScmatLcomp &operator=(const ScmatLcomp &) = delete;

    // === Cmat functions ===
    Lcomp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Lcomp *ptr, Long_I N1, Long_I N2);
    void set(const ScmatLcomp &sli);
    ~ScmatLcomp();
};

inline ScmatLcomp::ScmatLcomp() {}

inline ScmatLcomp::ScmatLcomp(Long_I N1, Long_I N2)
    : SvecLcomp(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLcomp::ScmatLcomp(Lcomp *ptr, Long_I N1, Long_I N2)
    : ScmatLcomp(N1, N2)
{
    m_p = ptr;
}

inline ScmatLcomp::operator ScmatLcomp_c() const
{
    return *((ScmatLcomp_c *)this);
}

inline Lcomp & ScmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLcomp::n1() const
{
    return m_N1;
}

inline Long ScmatLcomp::n2() const
{
    return m_N2;
}

inline void ScmatLcomp::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLcomp::set(Lcomp * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLcomp::set(const ScmatLcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatLcomp::~ScmatLcomp() {}

typedef const ScmatLcomp & ScmatLcomp_O, & ScmatLcomp_IO;

class ScmatFimag_c : public SvecFimag_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatFimag_c();
    ScmatFimag_c(Long_I N1, Long_I N2);
    ScmatFimag_c(const Fimag *ptr, Long_I N1, Long_I N2);

    ScmatFimag_c &operator=(const ScmatFimag_c &) = delete;

    // === Cmat functions ===
    const Fimag& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Fimag *ptr, Long_I N1, Long_I N2);
    void set(const ScmatFimag_c &sli);
    ~ScmatFimag_c();
};

inline ScmatFimag_c::ScmatFimag_c() {}

inline ScmatFimag_c::ScmatFimag_c(Long_I N1, Long_I N2)
    : SvecFimag_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatFimag_c::ScmatFimag_c(const Fimag *ptr, Long_I N1, Long_I N2)
    : ScmatFimag_c(N1, N2)
{
    m_p = ptr;
}


inline const Fimag & ScmatFimag_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatFimag_c::n1() const
{
    return m_N1;
}

inline Long ScmatFimag_c::n2() const
{
    return m_N2;
}

inline void ScmatFimag_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFimag_c::set(const Fimag * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFimag_c::set(const ScmatFimag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatFimag_c::~ScmatFimag_c() {}

typedef const ScmatFimag_c & ScmatFimag_I;

class ScmatFimag : public SvecFimag
{
protected:
    Long m_N1, m_N2;
public:
    ScmatFimag();
    ScmatFimag(Long_I N1, Long_I N2);
    ScmatFimag(Fimag *ptr, Long_I N1, Long_I N2);

    operator ScmatFimag_c() const;
    ScmatFimag &operator=(const ScmatFimag &) = delete;

    // === Cmat functions ===
    Fimag& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Fimag *ptr, Long_I N1, Long_I N2);
    void set(const ScmatFimag &sli);
    ~ScmatFimag();
};

inline ScmatFimag::ScmatFimag() {}

inline ScmatFimag::ScmatFimag(Long_I N1, Long_I N2)
    : SvecFimag(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatFimag::ScmatFimag(Fimag *ptr, Long_I N1, Long_I N2)
    : ScmatFimag(N1, N2)
{
    m_p = ptr;
}

inline ScmatFimag::operator ScmatFimag_c() const
{
    return *((ScmatFimag_c *)this);
}

inline Fimag & ScmatFimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatFimag::n1() const
{
    return m_N1;
}

inline Long ScmatFimag::n2() const
{
    return m_N2;
}

inline void ScmatFimag::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFimag::set(Fimag * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatFimag::set(const ScmatFimag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatFimag::~ScmatFimag() {}

typedef const ScmatFimag & ScmatFimag_O, & ScmatFimag_IO;

class ScmatImag_c : public SvecImag_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatImag_c();
    ScmatImag_c(Long_I N1, Long_I N2);
    ScmatImag_c(const Imag *ptr, Long_I N1, Long_I N2);

    ScmatImag_c &operator=(const ScmatImag_c &) = delete;

    // === Cmat functions ===
    const Imag& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Imag *ptr, Long_I N1, Long_I N2);
    void set(const ScmatImag_c &sli);
    ~ScmatImag_c();
};

inline ScmatImag_c::ScmatImag_c() {}

inline ScmatImag_c::ScmatImag_c(Long_I N1, Long_I N2)
    : SvecImag_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatImag_c::ScmatImag_c(const Imag *ptr, Long_I N1, Long_I N2)
    : ScmatImag_c(N1, N2)
{
    m_p = ptr;
}


inline const Imag & ScmatImag_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatImag_c::n1() const
{
    return m_N1;
}

inline Long ScmatImag_c::n2() const
{
    return m_N2;
}

inline void ScmatImag_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatImag_c::set(const Imag * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatImag_c::set(const ScmatImag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatImag_c::~ScmatImag_c() {}

typedef const ScmatImag_c & ScmatImag_I;

class ScmatImag : public SvecImag
{
protected:
    Long m_N1, m_N2;
public:
    ScmatImag();
    ScmatImag(Long_I N1, Long_I N2);
    ScmatImag(Imag *ptr, Long_I N1, Long_I N2);

    operator ScmatImag_c() const;
    ScmatImag &operator=(const ScmatImag &) = delete;

    // === Cmat functions ===
    Imag& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Imag *ptr, Long_I N1, Long_I N2);
    void set(const ScmatImag &sli);
    ~ScmatImag();
};

inline ScmatImag::ScmatImag() {}

inline ScmatImag::ScmatImag(Long_I N1, Long_I N2)
    : SvecImag(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatImag::ScmatImag(Imag *ptr, Long_I N1, Long_I N2)
    : ScmatImag(N1, N2)
{
    m_p = ptr;
}

inline ScmatImag::operator ScmatImag_c() const
{
    return *((ScmatImag_c *)this);
}

inline Imag & ScmatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatImag::n1() const
{
    return m_N1;
}

inline Long ScmatImag::n2() const
{
    return m_N2;
}

inline void ScmatImag::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatImag::set(Imag * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatImag::set(const ScmatImag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatImag::~ScmatImag() {}

typedef const ScmatImag & ScmatImag_O, & ScmatImag_IO;

class ScmatLimag_c : public SvecLimag_c
{
protected:
    Long m_N1, m_N2;
public:
    ScmatLimag_c();
    ScmatLimag_c(Long_I N1, Long_I N2);
    ScmatLimag_c(const Limag *ptr, Long_I N1, Long_I N2);

    ScmatLimag_c &operator=(const ScmatLimag_c &) = delete;

    // === Cmat functions ===
    const Limag& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(const Limag *ptr, Long_I N1, Long_I N2);
    void set(const ScmatLimag_c &sli);
    ~ScmatLimag_c();
};

inline ScmatLimag_c::ScmatLimag_c() {}

inline ScmatLimag_c::ScmatLimag_c(Long_I N1, Long_I N2)
    : SvecLimag_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLimag_c::ScmatLimag_c(const Limag *ptr, Long_I N1, Long_I N2)
    : ScmatLimag_c(N1, N2)
{
    m_p = ptr;
}


inline const Limag & ScmatLimag_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLimag_c::n1() const
{
    return m_N1;
}

inline Long ScmatLimag_c::n2() const
{
    return m_N2;
}

inline void ScmatLimag_c::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLimag_c::set(const Limag * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLimag_c::set(const ScmatLimag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatLimag_c::~ScmatLimag_c() {}

typedef const ScmatLimag_c & ScmatLimag_I;

class ScmatLimag : public SvecLimag
{
protected:
    Long m_N1, m_N2;
public:
    ScmatLimag();
    ScmatLimag(Long_I N1, Long_I N2);
    ScmatLimag(Limag *ptr, Long_I N1, Long_I N2);

    operator ScmatLimag_c() const;
    ScmatLimag &operator=(const ScmatLimag &) = delete;

    // === Cmat functions ===
    Limag& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2);
    void set(Limag *ptr, Long_I N1, Long_I N2);
    void set(const ScmatLimag &sli);
    ~ScmatLimag();
};

inline ScmatLimag::ScmatLimag() {}

inline ScmatLimag::ScmatLimag(Long_I N1, Long_I N2)
    : SvecLimag(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLimag::ScmatLimag(Limag *ptr, Long_I N1, Long_I N2)
    : ScmatLimag(N1, N2)
{
    m_p = ptr;
}

inline ScmatLimag::operator ScmatLimag_c() const
{
    return *((ScmatLimag_c *)this);
}

inline Limag & ScmatLimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLimag::n1() const
{
    return m_N1;
}

inline Long ScmatLimag::n2() const
{
    return m_N2;
}

inline void ScmatLimag::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLimag::set(Limag * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLimag::set(const ScmatLimag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatLimag::~ScmatLimag() {}

typedef const ScmatLimag & ScmatLimag_O, & ScmatLimag_IO;

} // namespace slisc
