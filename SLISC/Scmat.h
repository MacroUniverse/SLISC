#pragma once
#include "Svec.h"
// "_c" means lower level const

namespace slisc {
class ScmatChar_c : public SvecChar_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatChar_c();
    ScmatChar_c(const Char *data, Long_I N0, Long_I N1); // unsafe


    const Char &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatChar_c &sli);
    void set(const Char *data, Long_I N0, Long_I N1);
    ~ScmatChar_c();
};

inline ScmatChar_c::ScmatChar_c() {}

inline ScmatChar_c::ScmatChar_c(const Char *data, Long_I N0, Long_I N1)
    : SvecChar_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Char &ScmatChar_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatChar_c::n1() const
{
    return m_N0;
}

inline Long ScmatChar_c::n2() const
{
    return m_N1;
}

inline void ScmatChar_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatChar_c::set(const Char *data, Long_I N0, Long_I N1)
{
    SvecChar_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatChar_c::set(const ScmatChar_c &sli)
{
    SvecChar_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatChar_c::~ScmatChar_c() {}

typedef const ScmatChar_c &ScmatChar_I;

class ScmatChar : public SvecChar
{
protected:
    Long m_N0, m_N1;
public:
    ScmatChar();
    ScmatChar(Char *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatChar_c() const;

    Char &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatChar &sli);
    void set(Char *data, Long_I N0, Long_I N1);
    ~ScmatChar();
};

inline ScmatChar::ScmatChar() {}

inline ScmatChar::ScmatChar(Char *data, Long_I N0, Long_I N1)
    : SvecChar(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatChar::operator ScmatChar_c() const
{
    return *((ScmatChar_c *)this);
}

inline Char &ScmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatChar::n1() const
{
    return m_N0;
}

inline Long ScmatChar::n2() const
{
    return m_N1;
}

inline void ScmatChar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatChar::set(Char *data, Long_I N0, Long_I N1)
{
    SvecChar::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatChar::set(const ScmatChar &sli)
{
    SvecChar::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatChar::~ScmatChar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatChar &ScmatChar_O, &ScmatChar_IO;

class ScmatInt_c : public SvecInt_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatInt_c();
    ScmatInt_c(const Int *data, Long_I N0, Long_I N1); // unsafe


    const Int &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatInt_c &sli);
    void set(const Int *data, Long_I N0, Long_I N1);
    ~ScmatInt_c();
};

inline ScmatInt_c::ScmatInt_c() {}

inline ScmatInt_c::ScmatInt_c(const Int *data, Long_I N0, Long_I N1)
    : SvecInt_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Int &ScmatInt_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatInt_c::n1() const
{
    return m_N0;
}

inline Long ScmatInt_c::n2() const
{
    return m_N1;
}

inline void ScmatInt_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatInt_c::set(const Int *data, Long_I N0, Long_I N1)
{
    SvecInt_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatInt_c::set(const ScmatInt_c &sli)
{
    SvecInt_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatInt_c::~ScmatInt_c() {}

typedef const ScmatInt_c &ScmatInt_I;

class ScmatInt : public SvecInt
{
protected:
    Long m_N0, m_N1;
public:
    ScmatInt();
    ScmatInt(Int *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatInt_c() const;

    Int &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatInt &sli);
    void set(Int *data, Long_I N0, Long_I N1);
    ~ScmatInt();
};

inline ScmatInt::ScmatInt() {}

inline ScmatInt::ScmatInt(Int *data, Long_I N0, Long_I N1)
    : SvecInt(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatInt::operator ScmatInt_c() const
{
    return *((ScmatInt_c *)this);
}

inline Int &ScmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatInt::n1() const
{
    return m_N0;
}

inline Long ScmatInt::n2() const
{
    return m_N1;
}

inline void ScmatInt::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatInt::set(Int *data, Long_I N0, Long_I N1)
{
    SvecInt::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatInt::set(const ScmatInt &sli)
{
    SvecInt::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatInt::~ScmatInt() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatInt &ScmatInt_O, &ScmatInt_IO;

class ScmatLlong_c : public SvecLlong_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatLlong_c();
    ScmatLlong_c(const Llong *data, Long_I N0, Long_I N1); // unsafe


    const Llong &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatLlong_c &sli);
    void set(const Llong *data, Long_I N0, Long_I N1);
    ~ScmatLlong_c();
};

inline ScmatLlong_c::ScmatLlong_c() {}

inline ScmatLlong_c::ScmatLlong_c(const Llong *data, Long_I N0, Long_I N1)
    : SvecLlong_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Llong &ScmatLlong_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatLlong_c::n1() const
{
    return m_N0;
}

inline Long ScmatLlong_c::n2() const
{
    return m_N1;
}

inline void ScmatLlong_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLlong_c::set(const Llong *data, Long_I N0, Long_I N1)
{
    SvecLlong_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLlong_c::set(const ScmatLlong_c &sli)
{
    SvecLlong_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLlong_c::~ScmatLlong_c() {}

typedef const ScmatLlong_c &ScmatLlong_I;

class ScmatLlong : public SvecLlong
{
protected:
    Long m_N0, m_N1;
public:
    ScmatLlong();
    ScmatLlong(Llong *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatLlong_c() const;

    Llong &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatLlong &sli);
    void set(Llong *data, Long_I N0, Long_I N1);
    ~ScmatLlong();
};

inline ScmatLlong::ScmatLlong() {}

inline ScmatLlong::ScmatLlong(Llong *data, Long_I N0, Long_I N1)
    : SvecLlong(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatLlong::operator ScmatLlong_c() const
{
    return *((ScmatLlong_c *)this);
}

inline Llong &ScmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatLlong::n1() const
{
    return m_N0;
}

inline Long ScmatLlong::n2() const
{
    return m_N1;
}

inline void ScmatLlong::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLlong::set(Llong *data, Long_I N0, Long_I N1)
{
    SvecLlong::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLlong::set(const ScmatLlong &sli)
{
    SvecLlong::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLlong::~ScmatLlong() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatLlong &ScmatLlong_O, &ScmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef ScmatInt_c ScmatLong_c;
#else
typedef ScmatLlong_c ScmatLong_c;
#endif

typedef const ScmatLong_c &ScmatLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef ScmatInt ScmatLong;
#else
typedef ScmatLlong ScmatLong;
#endif

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatLong &ScmatLong_O, &ScmatLong_IO;

class ScmatFloat_c : public SvecFloat_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatFloat_c();
    ScmatFloat_c(const Float *data, Long_I N0, Long_I N1); // unsafe


    const Float &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatFloat_c &sli);
    void set(const Float *data, Long_I N0, Long_I N1);
    ~ScmatFloat_c();
};

inline ScmatFloat_c::ScmatFloat_c() {}

inline ScmatFloat_c::ScmatFloat_c(const Float *data, Long_I N0, Long_I N1)
    : SvecFloat_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Float &ScmatFloat_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatFloat_c::n1() const
{
    return m_N0;
}

inline Long ScmatFloat_c::n2() const
{
    return m_N1;
}

inline void ScmatFloat_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFloat_c::set(const Float *data, Long_I N0, Long_I N1)
{
    SvecFloat_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFloat_c::set(const ScmatFloat_c &sli)
{
    SvecFloat_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFloat_c::~ScmatFloat_c() {}

typedef const ScmatFloat_c &ScmatFloat_I;

class ScmatFloat : public SvecFloat
{
protected:
    Long m_N0, m_N1;
public:
    ScmatFloat();
    ScmatFloat(Float *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatFloat_c() const;

    Float &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatFloat &sli);
    void set(Float *data, Long_I N0, Long_I N1);
    ~ScmatFloat();
};

inline ScmatFloat::ScmatFloat() {}

inline ScmatFloat::ScmatFloat(Float *data, Long_I N0, Long_I N1)
    : SvecFloat(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatFloat::operator ScmatFloat_c() const
{
    return *((ScmatFloat_c *)this);
}

inline Float &ScmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatFloat::n1() const
{
    return m_N0;
}

inline Long ScmatFloat::n2() const
{
    return m_N1;
}

inline void ScmatFloat::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFloat::set(Float *data, Long_I N0, Long_I N1)
{
    SvecFloat::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFloat::set(const ScmatFloat &sli)
{
    SvecFloat::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFloat::~ScmatFloat() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatFloat &ScmatFloat_O, &ScmatFloat_IO;

class ScmatDoub_c : public SvecDoub_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatDoub_c();
    ScmatDoub_c(const Doub *data, Long_I N0, Long_I N1); // unsafe


    const Doub &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatDoub_c &sli);
    void set(const Doub *data, Long_I N0, Long_I N1);
    ~ScmatDoub_c();
};

inline ScmatDoub_c::ScmatDoub_c() {}

inline ScmatDoub_c::ScmatDoub_c(const Doub *data, Long_I N0, Long_I N1)
    : SvecDoub_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Doub &ScmatDoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatDoub_c::n1() const
{
    return m_N0;
}

inline Long ScmatDoub_c::n2() const
{
    return m_N1;
}

inline void ScmatDoub_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatDoub_c::set(const Doub *data, Long_I N0, Long_I N1)
{
    SvecDoub_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatDoub_c::set(const ScmatDoub_c &sli)
{
    SvecDoub_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatDoub_c::~ScmatDoub_c() {}

typedef const ScmatDoub_c &ScmatDoub_I;

class ScmatDoub : public SvecDoub
{
protected:
    Long m_N0, m_N1;
public:
    ScmatDoub();
    ScmatDoub(Doub *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatDoub_c() const;

    Doub &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatDoub &sli);
    void set(Doub *data, Long_I N0, Long_I N1);
    ~ScmatDoub();
};

inline ScmatDoub::ScmatDoub() {}

inline ScmatDoub::ScmatDoub(Doub *data, Long_I N0, Long_I N1)
    : SvecDoub(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatDoub::operator ScmatDoub_c() const
{
    return *((ScmatDoub_c *)this);
}

inline Doub &ScmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatDoub::n1() const
{
    return m_N0;
}

inline Long ScmatDoub::n2() const
{
    return m_N1;
}

inline void ScmatDoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatDoub::set(Doub *data, Long_I N0, Long_I N1)
{
    SvecDoub::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatDoub::set(const ScmatDoub &sli)
{
    SvecDoub::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatDoub::~ScmatDoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatDoub &ScmatDoub_O, &ScmatDoub_IO;

class ScmatLdoub_c : public SvecLdoub_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatLdoub_c();
    ScmatLdoub_c(const Ldoub *data, Long_I N0, Long_I N1); // unsafe


    const Ldoub &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatLdoub_c &sli);
    void set(const Ldoub *data, Long_I N0, Long_I N1);
    ~ScmatLdoub_c();
};

inline ScmatLdoub_c::ScmatLdoub_c() {}

inline ScmatLdoub_c::ScmatLdoub_c(const Ldoub *data, Long_I N0, Long_I N1)
    : SvecLdoub_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Ldoub &ScmatLdoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatLdoub_c::n1() const
{
    return m_N0;
}

inline Long ScmatLdoub_c::n2() const
{
    return m_N1;
}

inline void ScmatLdoub_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLdoub_c::set(const Ldoub *data, Long_I N0, Long_I N1)
{
    SvecLdoub_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLdoub_c::set(const ScmatLdoub_c &sli)
{
    SvecLdoub_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLdoub_c::~ScmatLdoub_c() {}

typedef const ScmatLdoub_c &ScmatLdoub_I;

class ScmatLdoub : public SvecLdoub
{
protected:
    Long m_N0, m_N1;
public:
    ScmatLdoub();
    ScmatLdoub(Ldoub *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatLdoub_c() const;

    Ldoub &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatLdoub &sli);
    void set(Ldoub *data, Long_I N0, Long_I N1);
    ~ScmatLdoub();
};

inline ScmatLdoub::ScmatLdoub() {}

inline ScmatLdoub::ScmatLdoub(Ldoub *data, Long_I N0, Long_I N1)
    : SvecLdoub(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatLdoub::operator ScmatLdoub_c() const
{
    return *((ScmatLdoub_c *)this);
}

inline Ldoub &ScmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatLdoub::n1() const
{
    return m_N0;
}

inline Long ScmatLdoub::n2() const
{
    return m_N1;
}

inline void ScmatLdoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLdoub::set(Ldoub *data, Long_I N0, Long_I N1)
{
    SvecLdoub::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLdoub::set(const ScmatLdoub &sli)
{
    SvecLdoub::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLdoub::~ScmatLdoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatLdoub &ScmatLdoub_O, &ScmatLdoub_IO;

class ScmatFcomp_c : public SvecFcomp_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatFcomp_c();
    ScmatFcomp_c(const Fcomp *data, Long_I N0, Long_I N1); // unsafe


    const Fcomp &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatFcomp_c &sli);
    void set(const Fcomp *data, Long_I N0, Long_I N1);
    ~ScmatFcomp_c();
};

inline ScmatFcomp_c::ScmatFcomp_c() {}

inline ScmatFcomp_c::ScmatFcomp_c(const Fcomp *data, Long_I N0, Long_I N1)
    : SvecFcomp_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Fcomp &ScmatFcomp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatFcomp_c::n1() const
{
    return m_N0;
}

inline Long ScmatFcomp_c::n2() const
{
    return m_N1;
}

inline void ScmatFcomp_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFcomp_c::set(const Fcomp *data, Long_I N0, Long_I N1)
{
    SvecFcomp_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFcomp_c::set(const ScmatFcomp_c &sli)
{
    SvecFcomp_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFcomp_c::~ScmatFcomp_c() {}

typedef const ScmatFcomp_c &ScmatFcomp_I;

class ScmatFcomp : public SvecFcomp
{
protected:
    Long m_N0, m_N1;
public:
    ScmatFcomp();
    ScmatFcomp(Fcomp *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatFcomp_c() const;

    Fcomp &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatFcomp &sli);
    void set(Fcomp *data, Long_I N0, Long_I N1);
    ~ScmatFcomp();
};

inline ScmatFcomp::ScmatFcomp() {}

inline ScmatFcomp::ScmatFcomp(Fcomp *data, Long_I N0, Long_I N1)
    : SvecFcomp(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatFcomp::operator ScmatFcomp_c() const
{
    return *((ScmatFcomp_c *)this);
}

inline Fcomp &ScmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatFcomp::n1() const
{
    return m_N0;
}

inline Long ScmatFcomp::n2() const
{
    return m_N1;
}

inline void ScmatFcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFcomp::set(Fcomp *data, Long_I N0, Long_I N1)
{
    SvecFcomp::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFcomp::set(const ScmatFcomp &sli)
{
    SvecFcomp::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFcomp::~ScmatFcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatFcomp &ScmatFcomp_O, &ScmatFcomp_IO;

class ScmatComp_c : public SvecComp_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatComp_c();
    ScmatComp_c(const Comp *data, Long_I N0, Long_I N1); // unsafe


    const Comp &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatComp_c &sli);
    void set(const Comp *data, Long_I N0, Long_I N1);
    ~ScmatComp_c();
};

inline ScmatComp_c::ScmatComp_c() {}

inline ScmatComp_c::ScmatComp_c(const Comp *data, Long_I N0, Long_I N1)
    : SvecComp_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Comp &ScmatComp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatComp_c::n1() const
{
    return m_N0;
}

inline Long ScmatComp_c::n2() const
{
    return m_N1;
}

inline void ScmatComp_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatComp_c::set(const Comp *data, Long_I N0, Long_I N1)
{
    SvecComp_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatComp_c::set(const ScmatComp_c &sli)
{
    SvecComp_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatComp_c::~ScmatComp_c() {}

typedef const ScmatComp_c &ScmatComp_I;

class ScmatComp : public SvecComp
{
protected:
    Long m_N0, m_N1;
public:
    ScmatComp();
    ScmatComp(Comp *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatComp_c() const;

    Comp &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatComp &sli);
    void set(Comp *data, Long_I N0, Long_I N1);
    ~ScmatComp();
};

inline ScmatComp::ScmatComp() {}

inline ScmatComp::ScmatComp(Comp *data, Long_I N0, Long_I N1)
    : SvecComp(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatComp::operator ScmatComp_c() const
{
    return *((ScmatComp_c *)this);
}

inline Comp &ScmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatComp::n1() const
{
    return m_N0;
}

inline Long ScmatComp::n2() const
{
    return m_N1;
}

inline void ScmatComp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatComp::set(Comp *data, Long_I N0, Long_I N1)
{
    SvecComp::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatComp::set(const ScmatComp &sli)
{
    SvecComp::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatComp::~ScmatComp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatComp &ScmatComp_O, &ScmatComp_IO;

class ScmatLcomp_c : public SvecLcomp_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatLcomp_c();
    ScmatLcomp_c(const Lcomp *data, Long_I N0, Long_I N1); // unsafe


    const Lcomp &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatLcomp_c &sli);
    void set(const Lcomp *data, Long_I N0, Long_I N1);
    ~ScmatLcomp_c();
};

inline ScmatLcomp_c::ScmatLcomp_c() {}

inline ScmatLcomp_c::ScmatLcomp_c(const Lcomp *data, Long_I N0, Long_I N1)
    : SvecLcomp_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Lcomp &ScmatLcomp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatLcomp_c::n1() const
{
    return m_N0;
}

inline Long ScmatLcomp_c::n2() const
{
    return m_N1;
}

inline void ScmatLcomp_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLcomp_c::set(const Lcomp *data, Long_I N0, Long_I N1)
{
    SvecLcomp_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLcomp_c::set(const ScmatLcomp_c &sli)
{
    SvecLcomp_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLcomp_c::~ScmatLcomp_c() {}

typedef const ScmatLcomp_c &ScmatLcomp_I;

class ScmatLcomp : public SvecLcomp
{
protected:
    Long m_N0, m_N1;
public:
    ScmatLcomp();
    ScmatLcomp(Lcomp *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatLcomp_c() const;

    Lcomp &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatLcomp &sli);
    void set(Lcomp *data, Long_I N0, Long_I N1);
    ~ScmatLcomp();
};

inline ScmatLcomp::ScmatLcomp() {}

inline ScmatLcomp::ScmatLcomp(Lcomp *data, Long_I N0, Long_I N1)
    : SvecLcomp(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatLcomp::operator ScmatLcomp_c() const
{
    return *((ScmatLcomp_c *)this);
}

inline Lcomp &ScmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatLcomp::n1() const
{
    return m_N0;
}

inline Long ScmatLcomp::n2() const
{
    return m_N1;
}

inline void ScmatLcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLcomp::set(Lcomp *data, Long_I N0, Long_I N1)
{
    SvecLcomp::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLcomp::set(const ScmatLcomp &sli)
{
    SvecLcomp::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLcomp::~ScmatLcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatLcomp &ScmatLcomp_O, &ScmatLcomp_IO;

class ScmatFimag_c : public SvecFimag_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatFimag_c();
    ScmatFimag_c(const Fimag *data, Long_I N0, Long_I N1); // unsafe


    const Fimag &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatFimag_c &sli);
    void set(const Fimag *data, Long_I N0, Long_I N1);
    ~ScmatFimag_c();
};

inline ScmatFimag_c::ScmatFimag_c() {}

inline ScmatFimag_c::ScmatFimag_c(const Fimag *data, Long_I N0, Long_I N1)
    : SvecFimag_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Fimag &ScmatFimag_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatFimag_c::n1() const
{
    return m_N0;
}

inline Long ScmatFimag_c::n2() const
{
    return m_N1;
}

inline void ScmatFimag_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFimag_c::set(const Fimag *data, Long_I N0, Long_I N1)
{
    SvecFimag_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFimag_c::set(const ScmatFimag_c &sli)
{
    SvecFimag_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFimag_c::~ScmatFimag_c() {}

typedef const ScmatFimag_c &ScmatFimag_I;

class ScmatFimag : public SvecFimag
{
protected:
    Long m_N0, m_N1;
public:
    ScmatFimag();
    ScmatFimag(Fimag *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatFimag_c() const;

    Fimag &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatFimag &sli);
    void set(Fimag *data, Long_I N0, Long_I N1);
    ~ScmatFimag();
};

inline ScmatFimag::ScmatFimag() {}

inline ScmatFimag::ScmatFimag(Fimag *data, Long_I N0, Long_I N1)
    : SvecFimag(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatFimag::operator ScmatFimag_c() const
{
    return *((ScmatFimag_c *)this);
}

inline Fimag &ScmatFimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatFimag::n1() const
{
    return m_N0;
}

inline Long ScmatFimag::n2() const
{
    return m_N1;
}

inline void ScmatFimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFimag::set(Fimag *data, Long_I N0, Long_I N1)
{
    SvecFimag::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatFimag::set(const ScmatFimag &sli)
{
    SvecFimag::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFimag::~ScmatFimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatFimag &ScmatFimag_O, &ScmatFimag_IO;

class ScmatImag_c : public SvecImag_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatImag_c();
    ScmatImag_c(const Imag *data, Long_I N0, Long_I N1); // unsafe


    const Imag &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatImag_c &sli);
    void set(const Imag *data, Long_I N0, Long_I N1);
    ~ScmatImag_c();
};

inline ScmatImag_c::ScmatImag_c() {}

inline ScmatImag_c::ScmatImag_c(const Imag *data, Long_I N0, Long_I N1)
    : SvecImag_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Imag &ScmatImag_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatImag_c::n1() const
{
    return m_N0;
}

inline Long ScmatImag_c::n2() const
{
    return m_N1;
}

inline void ScmatImag_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatImag_c::set(const Imag *data, Long_I N0, Long_I N1)
{
    SvecImag_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatImag_c::set(const ScmatImag_c &sli)
{
    SvecImag_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatImag_c::~ScmatImag_c() {}

typedef const ScmatImag_c &ScmatImag_I;

class ScmatImag : public SvecImag
{
protected:
    Long m_N0, m_N1;
public:
    ScmatImag();
    ScmatImag(Imag *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatImag_c() const;

    Imag &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatImag &sli);
    void set(Imag *data, Long_I N0, Long_I N1);
    ~ScmatImag();
};

inline ScmatImag::ScmatImag() {}

inline ScmatImag::ScmatImag(Imag *data, Long_I N0, Long_I N1)
    : SvecImag(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatImag::operator ScmatImag_c() const
{
    return *((ScmatImag_c *)this);
}

inline Imag &ScmatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatImag::n1() const
{
    return m_N0;
}

inline Long ScmatImag::n2() const
{
    return m_N1;
}

inline void ScmatImag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatImag::set(Imag *data, Long_I N0, Long_I N1)
{
    SvecImag::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatImag::set(const ScmatImag &sli)
{
    SvecImag::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatImag::~ScmatImag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatImag &ScmatImag_O, &ScmatImag_IO;

class ScmatLimag_c : public SvecLimag_c
{
protected:
    Long m_N0, m_N1;
public:
    ScmatLimag_c();
    ScmatLimag_c(const Limag *data, Long_I N0, Long_I N1); // unsafe


    const Limag &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatLimag_c &sli);
    void set(const Limag *data, Long_I N0, Long_I N1);
    ~ScmatLimag_c();
};

inline ScmatLimag_c::ScmatLimag_c() {}

inline ScmatLimag_c::ScmatLimag_c(const Limag *data, Long_I N0, Long_I N1)
    : SvecLimag_c(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Limag &ScmatLimag_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatLimag_c::n1() const
{
    return m_N0;
}

inline Long ScmatLimag_c::n2() const
{
    return m_N1;
}

inline void ScmatLimag_c::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLimag_c::set(const Limag *data, Long_I N0, Long_I N1)
{
    SvecLimag_c::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLimag_c::set(const ScmatLimag_c &sli)
{
    SvecLimag_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLimag_c::~ScmatLimag_c() {}

typedef const ScmatLimag_c &ScmatLimag_I;

class ScmatLimag : public SvecLimag
{
protected:
    Long m_N0, m_N1;
public:
    ScmatLimag();
    ScmatLimag(Limag *data, Long_I N0, Long_I N1); // unsafe

    operator ScmatLimag_c() const;

    Limag &operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N0, Long_I N1);
    void set(const ScmatLimag &sli);
    void set(Limag *data, Long_I N0, Long_I N1);
    ~ScmatLimag();
};

inline ScmatLimag::ScmatLimag() {}

inline ScmatLimag::ScmatLimag(Limag *data, Long_I N0, Long_I N1)
    : SvecLimag(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatLimag::operator ScmatLimag_c() const
{
    return *((ScmatLimag_c *)this);
}

inline Limag &ScmatLimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0 * j];
}

inline Long ScmatLimag::n1() const
{
    return m_N0;
}

inline Long ScmatLimag::n2() const
{
    return m_N1;
}

inline void ScmatLimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLimag::set(Limag *data, Long_I N0, Long_I N1)
{
    SvecLimag::set(data, N0*N1);
    m_N0 = N0; m_N1 = N1;
}

inline void ScmatLimag::set(const ScmatLimag &sli)
{
    SvecLimag::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLimag::~ScmatLimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut1(a), cut1(b))
typedef const ScmatLimag &ScmatLimag_O, &ScmatLimag_IO;

} // namespace slisc
