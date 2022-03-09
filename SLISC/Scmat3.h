#pragma once
#include "Svec.h"

namespace slisc {
class Scmat3Char_c : public SvbaseChar_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Char_c();
    Scmat3Char_c(const Char *data, Long_I N0, Long_I N1, Long_I N2);


    const Char &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Char *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Char_c &sli);
    ~Scmat3Char_c();
};

inline Scmat3Char_c::Scmat3Char_c() {}

inline Scmat3Char_c::Scmat3Char_c(const Char *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseChar_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Char &Scmat3Char_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Char_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Char_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Char_c::n2() const
{
    return m_N2;
}

inline void Scmat3Char_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Char_c::set(const Char *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseChar_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Char_c::set(const Scmat3Char_c &sli)
{
    SvbaseChar_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Char_c::~Scmat3Char_c() {}

typedef const Scmat3Char_c &Scmat3Char_I;

class Scmat3Char : public SvbaseChar
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Char();
    Scmat3Char(Char *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Char_c() const;

    Char &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Char *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Char &sli);
    ~Scmat3Char();
};

inline Scmat3Char::Scmat3Char() {}

inline Scmat3Char::Scmat3Char(Char *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseChar(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Char::operator Scmat3Char_c() const
{
    return *((Scmat3Char_c *)this);
}

inline Char &Scmat3Char::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Char::n0() const
{
    return m_N0;
}

inline Long Scmat3Char::n1() const
{
    return m_N1;
}

inline Long Scmat3Char::n2() const
{
    return m_N2;
}

inline void Scmat3Char::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Char::set(Char *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseChar::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Char::set(const Scmat3Char &sli)
{
    SvbaseChar::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Char::~Scmat3Char() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Char &Scmat3Char_O, &Scmat3Char_IO;

class Scmat3Int_c : public SvbaseInt_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Int_c();
    Scmat3Int_c(const Int *data, Long_I N0, Long_I N1, Long_I N2);


    const Int &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Int *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Int_c &sli);
    ~Scmat3Int_c();
};

inline Scmat3Int_c::Scmat3Int_c() {}

inline Scmat3Int_c::Scmat3Int_c(const Int *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseInt_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Int &Scmat3Int_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Int_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Int_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Int_c::n2() const
{
    return m_N2;
}

inline void Scmat3Int_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Int_c::set(const Int *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseInt_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Int_c::set(const Scmat3Int_c &sli)
{
    SvbaseInt_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Int_c::~Scmat3Int_c() {}

typedef const Scmat3Int_c &Scmat3Int_I;

class Scmat3Int : public SvbaseInt
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Int();
    Scmat3Int(Int *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Int_c() const;

    Int &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Int *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Int &sli);
    ~Scmat3Int();
};

inline Scmat3Int::Scmat3Int() {}

inline Scmat3Int::Scmat3Int(Int *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseInt(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Int::operator Scmat3Int_c() const
{
    return *((Scmat3Int_c *)this);
}

inline Int &Scmat3Int::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Int::n0() const
{
    return m_N0;
}

inline Long Scmat3Int::n1() const
{
    return m_N1;
}

inline Long Scmat3Int::n2() const
{
    return m_N2;
}

inline void Scmat3Int::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Int::set(Int *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseInt::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Int::set(const Scmat3Int &sli)
{
    SvbaseInt::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Int::~Scmat3Int() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Int &Scmat3Int_O, &Scmat3Int_IO;

class Scmat3Llong_c : public SvbaseLlong_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Llong_c();
    Scmat3Llong_c(const Llong *data, Long_I N0, Long_I N1, Long_I N2);


    const Llong &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Llong *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Llong_c &sli);
    ~Scmat3Llong_c();
};

inline Scmat3Llong_c::Scmat3Llong_c() {}

inline Scmat3Llong_c::Scmat3Llong_c(const Llong *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseLlong_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Llong &Scmat3Llong_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Llong_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Llong_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Llong_c::n2() const
{
    return m_N2;
}

inline void Scmat3Llong_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Llong_c::set(const Llong *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseLlong_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Llong_c::set(const Scmat3Llong_c &sli)
{
    SvbaseLlong_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Llong_c::~Scmat3Llong_c() {}

typedef const Scmat3Llong_c &Scmat3Llong_I;

class Scmat3Llong : public SvbaseLlong
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Llong();
    Scmat3Llong(Llong *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Llong_c() const;

    Llong &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Llong *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Llong &sli);
    ~Scmat3Llong();
};

inline Scmat3Llong::Scmat3Llong() {}

inline Scmat3Llong::Scmat3Llong(Llong *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseLlong(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Llong::operator Scmat3Llong_c() const
{
    return *((Scmat3Llong_c *)this);
}

inline Llong &Scmat3Llong::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Llong::n0() const
{
    return m_N0;
}

inline Long Scmat3Llong::n1() const
{
    return m_N1;
}

inline Long Scmat3Llong::n2() const
{
    return m_N2;
}

inline void Scmat3Llong::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Llong::set(Llong *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseLlong::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Llong::set(const Scmat3Llong &sli)
{
    SvbaseLlong::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Llong::~Scmat3Llong() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Llong &Scmat3Llong_O, &Scmat3Llong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef Scmat3Int_c Scmat3Long_c;
#else
typedef Scmat3Llong_c Scmat3Long_c;
#endif

typedef const Scmat3Long_c &Scmat3Long_I;

#ifdef SLS_USE_INT_AS_LONG
typedef Scmat3Int Scmat3Long;
#else
typedef Scmat3Llong Scmat3Long;
#endif

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Long &Scmat3Long_O, &Scmat3Long_IO;

class Scmat3Float_c : public SvbaseFloat_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Float_c();
    Scmat3Float_c(const Float *data, Long_I N0, Long_I N1, Long_I N2);


    const Float &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Float *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Float_c &sli);
    ~Scmat3Float_c();
};

inline Scmat3Float_c::Scmat3Float_c() {}

inline Scmat3Float_c::Scmat3Float_c(const Float *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseFloat_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Float &Scmat3Float_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Float_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Float_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Float_c::n2() const
{
    return m_N2;
}

inline void Scmat3Float_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Float_c::set(const Float *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseFloat_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Float_c::set(const Scmat3Float_c &sli)
{
    SvbaseFloat_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Float_c::~Scmat3Float_c() {}

typedef const Scmat3Float_c &Scmat3Float_I;

class Scmat3Float : public SvbaseFloat
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Float();
    Scmat3Float(Float *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Float_c() const;

    Float &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Float *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Float &sli);
    ~Scmat3Float();
};

inline Scmat3Float::Scmat3Float() {}

inline Scmat3Float::Scmat3Float(Float *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseFloat(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Float::operator Scmat3Float_c() const
{
    return *((Scmat3Float_c *)this);
}

inline Float &Scmat3Float::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Float::n0() const
{
    return m_N0;
}

inline Long Scmat3Float::n1() const
{
    return m_N1;
}

inline Long Scmat3Float::n2() const
{
    return m_N2;
}

inline void Scmat3Float::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Float::set(Float *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseFloat::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Float::set(const Scmat3Float &sli)
{
    SvbaseFloat::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Float::~Scmat3Float() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Float &Scmat3Float_O, &Scmat3Float_IO;

class Scmat3Doub_c : public SvbaseDoub_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Doub_c();
    Scmat3Doub_c(const Doub *data, Long_I N0, Long_I N1, Long_I N2);


    const Doub &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Doub *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Doub_c &sli);
    ~Scmat3Doub_c();
};

inline Scmat3Doub_c::Scmat3Doub_c() {}

inline Scmat3Doub_c::Scmat3Doub_c(const Doub *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseDoub_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Doub &Scmat3Doub_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Doub_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Doub_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Doub_c::n2() const
{
    return m_N2;
}

inline void Scmat3Doub_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Doub_c::set(const Doub *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseDoub_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Doub_c::set(const Scmat3Doub_c &sli)
{
    SvbaseDoub_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Doub_c::~Scmat3Doub_c() {}

typedef const Scmat3Doub_c &Scmat3Doub_I;

class Scmat3Doub : public SvbaseDoub
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Doub();
    Scmat3Doub(Doub *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Doub_c() const;

    Doub &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Doub *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Doub &sli);
    ~Scmat3Doub();
};

inline Scmat3Doub::Scmat3Doub() {}

inline Scmat3Doub::Scmat3Doub(Doub *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseDoub(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Doub::operator Scmat3Doub_c() const
{
    return *((Scmat3Doub_c *)this);
}

inline Doub &Scmat3Doub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Doub::n0() const
{
    return m_N0;
}

inline Long Scmat3Doub::n1() const
{
    return m_N1;
}

inline Long Scmat3Doub::n2() const
{
    return m_N2;
}

inline void Scmat3Doub::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Doub::set(Doub *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseDoub::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Doub::set(const Scmat3Doub &sli)
{
    SvbaseDoub::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Doub::~Scmat3Doub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Doub &Scmat3Doub_O, &Scmat3Doub_IO;

class Scmat3Ldoub_c : public SvbaseLdoub_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Ldoub_c();
    Scmat3Ldoub_c(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2);


    const Ldoub &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Ldoub_c &sli);
    ~Scmat3Ldoub_c();
};

inline Scmat3Ldoub_c::Scmat3Ldoub_c() {}

inline Scmat3Ldoub_c::Scmat3Ldoub_c(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseLdoub_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Ldoub &Scmat3Ldoub_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Ldoub_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Ldoub_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Ldoub_c::n2() const
{
    return m_N2;
}

inline void Scmat3Ldoub_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Ldoub_c::set(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseLdoub_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Ldoub_c::set(const Scmat3Ldoub_c &sli)
{
    SvbaseLdoub_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Ldoub_c::~Scmat3Ldoub_c() {}

typedef const Scmat3Ldoub_c &Scmat3Ldoub_I;

class Scmat3Ldoub : public SvbaseLdoub
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Ldoub();
    Scmat3Ldoub(Ldoub *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Ldoub_c() const;

    Ldoub &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Ldoub *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Ldoub &sli);
    ~Scmat3Ldoub();
};

inline Scmat3Ldoub::Scmat3Ldoub() {}

inline Scmat3Ldoub::Scmat3Ldoub(Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseLdoub(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Ldoub::operator Scmat3Ldoub_c() const
{
    return *((Scmat3Ldoub_c *)this);
}

inline Ldoub &Scmat3Ldoub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Ldoub::n0() const
{
    return m_N0;
}

inline Long Scmat3Ldoub::n1() const
{
    return m_N1;
}

inline Long Scmat3Ldoub::n2() const
{
    return m_N2;
}

inline void Scmat3Ldoub::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Ldoub::set(Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseLdoub::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Ldoub::set(const Scmat3Ldoub &sli)
{
    SvbaseLdoub::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Ldoub::~Scmat3Ldoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Ldoub &Scmat3Ldoub_O, &Scmat3Ldoub_IO;

class Scmat3Fcomp_c : public SvbaseFcomp_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Fcomp_c();
    Scmat3Fcomp_c(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2);


    const Fcomp &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Fcomp_c &sli);
    ~Scmat3Fcomp_c();
};

inline Scmat3Fcomp_c::Scmat3Fcomp_c() {}

inline Scmat3Fcomp_c::Scmat3Fcomp_c(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseFcomp_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Fcomp &Scmat3Fcomp_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Fcomp_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Fcomp_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Fcomp_c::n2() const
{
    return m_N2;
}

inline void Scmat3Fcomp_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fcomp_c::set(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseFcomp_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fcomp_c::set(const Scmat3Fcomp_c &sli)
{
    SvbaseFcomp_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Fcomp_c::~Scmat3Fcomp_c() {}

typedef const Scmat3Fcomp_c &Scmat3Fcomp_I;

class Scmat3Fcomp : public SvbaseFcomp
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Fcomp();
    Scmat3Fcomp(Fcomp *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Fcomp_c() const;

    Fcomp &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Fcomp *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Fcomp &sli);
    ~Scmat3Fcomp();
};

inline Scmat3Fcomp::Scmat3Fcomp() {}

inline Scmat3Fcomp::Scmat3Fcomp(Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseFcomp(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Fcomp::operator Scmat3Fcomp_c() const
{
    return *((Scmat3Fcomp_c *)this);
}

inline Fcomp &Scmat3Fcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Fcomp::n0() const
{
    return m_N0;
}

inline Long Scmat3Fcomp::n1() const
{
    return m_N1;
}

inline Long Scmat3Fcomp::n2() const
{
    return m_N2;
}

inline void Scmat3Fcomp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fcomp::set(Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseFcomp::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fcomp::set(const Scmat3Fcomp &sli)
{
    SvbaseFcomp::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Fcomp::~Scmat3Fcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Fcomp &Scmat3Fcomp_O, &Scmat3Fcomp_IO;

class Scmat3Comp_c : public SvbaseComp_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Comp_c();
    Scmat3Comp_c(const Comp *data, Long_I N0, Long_I N1, Long_I N2);


    const Comp &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Comp *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Comp_c &sli);
    ~Scmat3Comp_c();
};

inline Scmat3Comp_c::Scmat3Comp_c() {}

inline Scmat3Comp_c::Scmat3Comp_c(const Comp *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseComp_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Comp &Scmat3Comp_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Comp_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Comp_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Comp_c::n2() const
{
    return m_N2;
}

inline void Scmat3Comp_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Comp_c::set(const Comp *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseComp_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Comp_c::set(const Scmat3Comp_c &sli)
{
    SvbaseComp_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Comp_c::~Scmat3Comp_c() {}

typedef const Scmat3Comp_c &Scmat3Comp_I;

class Scmat3Comp : public SvbaseComp
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Comp();
    Scmat3Comp(Comp *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Comp_c() const;

    Comp &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Comp *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Comp &sli);
    ~Scmat3Comp();
};

inline Scmat3Comp::Scmat3Comp() {}

inline Scmat3Comp::Scmat3Comp(Comp *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseComp(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Comp::operator Scmat3Comp_c() const
{
    return *((Scmat3Comp_c *)this);
}

inline Comp &Scmat3Comp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Comp::n0() const
{
    return m_N0;
}

inline Long Scmat3Comp::n1() const
{
    return m_N1;
}

inline Long Scmat3Comp::n2() const
{
    return m_N2;
}

inline void Scmat3Comp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Comp::set(Comp *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseComp::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Comp::set(const Scmat3Comp &sli)
{
    SvbaseComp::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Comp::~Scmat3Comp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Comp &Scmat3Comp_O, &Scmat3Comp_IO;

class Scmat3Lcomp_c : public SvbaseLcomp_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Lcomp_c();
    Scmat3Lcomp_c(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2);


    const Lcomp &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Lcomp_c &sli);
    ~Scmat3Lcomp_c();
};

inline Scmat3Lcomp_c::Scmat3Lcomp_c() {}

inline Scmat3Lcomp_c::Scmat3Lcomp_c(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseLcomp_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Lcomp &Scmat3Lcomp_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Lcomp_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Lcomp_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Lcomp_c::n2() const
{
    return m_N2;
}

inline void Scmat3Lcomp_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Lcomp_c::set(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseLcomp_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Lcomp_c::set(const Scmat3Lcomp_c &sli)
{
    SvbaseLcomp_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Lcomp_c::~Scmat3Lcomp_c() {}

typedef const Scmat3Lcomp_c &Scmat3Lcomp_I;

class Scmat3Lcomp : public SvbaseLcomp
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Lcomp();
    Scmat3Lcomp(Lcomp *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Lcomp_c() const;

    Lcomp &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Lcomp *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Lcomp &sli);
    ~Scmat3Lcomp();
};

inline Scmat3Lcomp::Scmat3Lcomp() {}

inline Scmat3Lcomp::Scmat3Lcomp(Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseLcomp(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Lcomp::operator Scmat3Lcomp_c() const
{
    return *((Scmat3Lcomp_c *)this);
}

inline Lcomp &Scmat3Lcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Lcomp::n0() const
{
    return m_N0;
}

inline Long Scmat3Lcomp::n1() const
{
    return m_N1;
}

inline Long Scmat3Lcomp::n2() const
{
    return m_N2;
}

inline void Scmat3Lcomp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Lcomp::set(Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseLcomp::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Lcomp::set(const Scmat3Lcomp &sli)
{
    SvbaseLcomp::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Lcomp::~Scmat3Lcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Lcomp &Scmat3Lcomp_O, &Scmat3Lcomp_IO;

class Scmat3Fimag_c : public SvbaseFimag_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Fimag_c();
    Scmat3Fimag_c(const Fimag *data, Long_I N0, Long_I N1, Long_I N2);


    const Fimag &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Fimag *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Fimag_c &sli);
    ~Scmat3Fimag_c();
};

inline Scmat3Fimag_c::Scmat3Fimag_c() {}

inline Scmat3Fimag_c::Scmat3Fimag_c(const Fimag *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseFimag_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Fimag &Scmat3Fimag_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Fimag_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Fimag_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Fimag_c::n2() const
{
    return m_N2;
}

inline void Scmat3Fimag_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fimag_c::set(const Fimag *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseFimag_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fimag_c::set(const Scmat3Fimag_c &sli)
{
    SvbaseFimag_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Fimag_c::~Scmat3Fimag_c() {}

typedef const Scmat3Fimag_c &Scmat3Fimag_I;

class Scmat3Fimag : public SvbaseFimag
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Fimag();
    Scmat3Fimag(Fimag *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Fimag_c() const;

    Fimag &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Fimag *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Fimag &sli);
    ~Scmat3Fimag();
};

inline Scmat3Fimag::Scmat3Fimag() {}

inline Scmat3Fimag::Scmat3Fimag(Fimag *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseFimag(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Fimag::operator Scmat3Fimag_c() const
{
    return *((Scmat3Fimag_c *)this);
}

inline Fimag &Scmat3Fimag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Fimag::n0() const
{
    return m_N0;
}

inline Long Scmat3Fimag::n1() const
{
    return m_N1;
}

inline Long Scmat3Fimag::n2() const
{
    return m_N2;
}

inline void Scmat3Fimag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fimag::set(Fimag *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseFimag::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fimag::set(const Scmat3Fimag &sli)
{
    SvbaseFimag::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Fimag::~Scmat3Fimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Fimag &Scmat3Fimag_O, &Scmat3Fimag_IO;

class Scmat3Imag_c : public SvbaseImag_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Imag_c();
    Scmat3Imag_c(const Imag *data, Long_I N0, Long_I N1, Long_I N2);


    const Imag &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Imag *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Imag_c &sli);
    ~Scmat3Imag_c();
};

inline Scmat3Imag_c::Scmat3Imag_c() {}

inline Scmat3Imag_c::Scmat3Imag_c(const Imag *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseImag_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Imag &Scmat3Imag_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Imag_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Imag_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Imag_c::n2() const
{
    return m_N2;
}

inline void Scmat3Imag_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Imag_c::set(const Imag *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseImag_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Imag_c::set(const Scmat3Imag_c &sli)
{
    SvbaseImag_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Imag_c::~Scmat3Imag_c() {}

typedef const Scmat3Imag_c &Scmat3Imag_I;

class Scmat3Imag : public SvbaseImag
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Imag();
    Scmat3Imag(Imag *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Imag_c() const;

    Imag &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Imag *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Imag &sli);
    ~Scmat3Imag();
};

inline Scmat3Imag::Scmat3Imag() {}

inline Scmat3Imag::Scmat3Imag(Imag *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseImag(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Imag::operator Scmat3Imag_c() const
{
    return *((Scmat3Imag_c *)this);
}

inline Imag &Scmat3Imag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Imag::n0() const
{
    return m_N0;
}

inline Long Scmat3Imag::n1() const
{
    return m_N1;
}

inline Long Scmat3Imag::n2() const
{
    return m_N2;
}

inline void Scmat3Imag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Imag::set(Imag *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseImag::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Imag::set(const Scmat3Imag &sli)
{
    SvbaseImag::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Imag::~Scmat3Imag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Imag &Scmat3Imag_O, &Scmat3Imag_IO;

class Scmat3Limag_c : public SvbaseLimag_c
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Limag_c();
    Scmat3Limag_c(const Limag *data, Long_I N0, Long_I N1, Long_I N2);


    const Limag &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(const Limag *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Limag_c &sli);
    ~Scmat3Limag_c();
};

inline Scmat3Limag_c::Scmat3Limag_c() {}

inline Scmat3Limag_c::Scmat3Limag_c(const Limag *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseLimag_c(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Limag &Scmat3Limag_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Limag_c::n0() const
{
    return m_N0;
}

inline Long Scmat3Limag_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Limag_c::n2() const
{
    return m_N2;
}

inline void Scmat3Limag_c::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Limag_c::set(const Limag *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseLimag_c::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Limag_c::set(const Scmat3Limag_c &sli)
{
    SvbaseLimag_c::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Limag_c::~Scmat3Limag_c() {}

typedef const Scmat3Limag_c &Scmat3Limag_I;

class Scmat3Limag : public SvbaseLimag
{
protected:
    Long m_N0, m_N1, m_N2;
public:
    Scmat3Limag();
    Scmat3Limag(Limag *data, Long_I N0, Long_I N1, Long_I N2);

    operator Scmat3Limag_c() const;

    Limag &operator()(Long_I i, Long_I j, Long_I k) const;

    Long n0() const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!
    void reshape(Long_I N0, Long_I N1, Long_I N2);
    void set(Limag *data, Long_I N0, Long_I N1, Long_I N2);
    void set(const Scmat3Limag &sli);
    ~Scmat3Limag();
};

inline Scmat3Limag::Scmat3Limag() {}

inline Scmat3Limag::Scmat3Limag(Limag *data, Long_I N0, Long_I N1, Long_I N2)
    : SvbaseLimag(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Limag::operator Scmat3Limag_c() const
{
    return *((Scmat3Limag_c *)this);
}

inline Limag &Scmat3Limag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Limag::n0() const
{
    return m_N0;
}

inline Long Scmat3Limag::n1() const
{
    return m_N1;
}

inline Long Scmat3Limag::n2() const
{
    return m_N2;
}

inline void Scmat3Limag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
    if (N0*N1*N2 != m_N)
        SLS_ERR("illegal reshape!");
#endif
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Limag::set(Limag *data, Long_I N0, Long_I N1, Long_I N2)
{
    SvbaseLimag::set(data, N0*N1*N2);
    m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Limag::set(const Scmat3Limag &sli)
{
    SvbaseLimag::set(sli);
    m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Limag::~Scmat3Limag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Limag &Scmat3Limag_O, &Scmat3Limag_IO;

} // namespace slisc
