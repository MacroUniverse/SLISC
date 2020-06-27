#pragma once
#include "Svec.h"

namespace slisc {
class Scmat3Char_c : public SvecChar_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Char_c();
    Scmat3Char_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Char_c(const Char *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Char_c &operator=(const Scmat3Char_c &) = delete;

    // === Cmat functions ===
    const Char& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Char *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Char_c &sli);
    ~Scmat3Char_c();
};

inline Scmat3Char_c::Scmat3Char_c() {}

inline Scmat3Char_c::Scmat3Char_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecChar_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Char_c::Scmat3Char_c(const Char *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Char_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Char & Scmat3Char_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Char_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Char_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Char_c::n3() const
{
    return m_N3;
}

inline void Scmat3Char_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Char_c::set(const Char * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Char_c::set(const Scmat3Char_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Char_c::~Scmat3Char_c() {}

typedef const Scmat3Char_c & Scmat3Char_I;

class Scmat3Char : public SvecChar
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Char();
    Scmat3Char(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Char(Char *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Char_c() const;
    Scmat3Char &operator=(const Scmat3Char &) = delete;

    // === Cmat functions ===
    Char& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Char *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Char &sli);
    ~Scmat3Char();
};

inline Scmat3Char::Scmat3Char() {}

inline Scmat3Char::Scmat3Char(Long_I N1, Long_I N2, Long_I N3)
    : SvecChar(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Char::Scmat3Char(Char *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Char(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Char::operator Scmat3Char_c() const
{
    return *((Scmat3Char_c *)this);
}

inline Char & Scmat3Char::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Char::n1() const
{
    return m_N1;
}

inline Long Scmat3Char::n2() const
{
    return m_N2;
}

inline Long Scmat3Char::n3() const
{
    return m_N3;
}

inline void Scmat3Char::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Char::set(Char * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Char::set(const Scmat3Char &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Char::~Scmat3Char() {}

typedef const Scmat3Char & Scmat3Char_O, & Scmat3Char_IO;

class Scmat3Int_c : public SvecInt_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Int_c();
    Scmat3Int_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Int_c(const Int *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Int_c &operator=(const Scmat3Int_c &) = delete;

    // === Cmat functions ===
    const Int& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Int *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Int_c &sli);
    ~Scmat3Int_c();
};

inline Scmat3Int_c::Scmat3Int_c() {}

inline Scmat3Int_c::Scmat3Int_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecInt_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Int_c::Scmat3Int_c(const Int *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Int_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Int & Scmat3Int_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Int_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Int_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Int_c::n3() const
{
    return m_N3;
}

inline void Scmat3Int_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Int_c::set(const Int * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Int_c::set(const Scmat3Int_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Int_c::~Scmat3Int_c() {}

typedef const Scmat3Int_c & Scmat3Int_I;

class Scmat3Int : public SvecInt
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Int();
    Scmat3Int(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Int(Int *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Int_c() const;
    Scmat3Int &operator=(const Scmat3Int &) = delete;

    // === Cmat functions ===
    Int& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Int *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Int &sli);
    ~Scmat3Int();
};

inline Scmat3Int::Scmat3Int() {}

inline Scmat3Int::Scmat3Int(Long_I N1, Long_I N2, Long_I N3)
    : SvecInt(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Int::Scmat3Int(Int *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Int(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Int::operator Scmat3Int_c() const
{
    return *((Scmat3Int_c *)this);
}

inline Int & Scmat3Int::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Int::n1() const
{
    return m_N1;
}

inline Long Scmat3Int::n2() const
{
    return m_N2;
}

inline Long Scmat3Int::n3() const
{
    return m_N3;
}

inline void Scmat3Int::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Int::set(Int * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Int::set(const Scmat3Int &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Int::~Scmat3Int() {}

typedef const Scmat3Int & Scmat3Int_O, & Scmat3Int_IO;

class Scmat3Llong_c : public SvecLlong_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Llong_c();
    Scmat3Llong_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Llong_c(const Llong *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Llong_c &operator=(const Scmat3Llong_c &) = delete;

    // === Cmat functions ===
    const Llong& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Llong *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Llong_c &sli);
    ~Scmat3Llong_c();
};

inline Scmat3Llong_c::Scmat3Llong_c() {}

inline Scmat3Llong_c::Scmat3Llong_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecLlong_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Llong_c::Scmat3Llong_c(const Llong *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Llong_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Llong & Scmat3Llong_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Llong_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Llong_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Llong_c::n3() const
{
    return m_N3;
}

inline void Scmat3Llong_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Llong_c::set(const Llong * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Llong_c::set(const Scmat3Llong_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Llong_c::~Scmat3Llong_c() {}

typedef const Scmat3Llong_c & Scmat3Llong_I;

class Scmat3Llong : public SvecLlong
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Llong();
    Scmat3Llong(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Llong(Llong *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Llong_c() const;
    Scmat3Llong &operator=(const Scmat3Llong &) = delete;

    // === Cmat functions ===
    Llong& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Llong *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Llong &sli);
    ~Scmat3Llong();
};

inline Scmat3Llong::Scmat3Llong() {}

inline Scmat3Llong::Scmat3Llong(Long_I N1, Long_I N2, Long_I N3)
    : SvecLlong(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Llong::Scmat3Llong(Llong *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Llong(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Llong::operator Scmat3Llong_c() const
{
    return *((Scmat3Llong_c *)this);
}

inline Llong & Scmat3Llong::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Llong::n1() const
{
    return m_N1;
}

inline Long Scmat3Llong::n2() const
{
    return m_N2;
}

inline Long Scmat3Llong::n3() const
{
    return m_N3;
}

inline void Scmat3Llong::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Llong::set(Llong * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Llong::set(const Scmat3Llong &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Llong::~Scmat3Llong() {}

typedef const Scmat3Llong & Scmat3Llong_O, & Scmat3Llong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef Scmat3Int_c Scmat3Long_c;
#else
typedef Scmat3Llong_c Scmat3Long_c;
#endif

typedef const Scmat3Long_c & Scmat3Long_I;

#ifdef SLS_USE_INT_AS_LONG
typedef Scmat3Int Scmat3Long;
#else
typedef Scmat3Llong Scmat3Long;
#endif

typedef const Scmat3Long & Scmat3Long_O, & Scmat3Long_IO;

class Scmat3Float_c : public SvecFloat_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Float_c();
    Scmat3Float_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Float_c(const Float *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Float_c &operator=(const Scmat3Float_c &) = delete;

    // === Cmat functions ===
    const Float& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Float *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Float_c &sli);
    ~Scmat3Float_c();
};

inline Scmat3Float_c::Scmat3Float_c() {}

inline Scmat3Float_c::Scmat3Float_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecFloat_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Float_c::Scmat3Float_c(const Float *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Float_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Float & Scmat3Float_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Float_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Float_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Float_c::n3() const
{
    return m_N3;
}

inline void Scmat3Float_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Float_c::set(const Float * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Float_c::set(const Scmat3Float_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Float_c::~Scmat3Float_c() {}

typedef const Scmat3Float_c & Scmat3Float_I;

class Scmat3Float : public SvecFloat
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Float();
    Scmat3Float(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Float(Float *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Float_c() const;
    Scmat3Float &operator=(const Scmat3Float &) = delete;

    // === Cmat functions ===
    Float& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Float *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Float &sli);
    ~Scmat3Float();
};

inline Scmat3Float::Scmat3Float() {}

inline Scmat3Float::Scmat3Float(Long_I N1, Long_I N2, Long_I N3)
    : SvecFloat(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Float::Scmat3Float(Float *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Float(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Float::operator Scmat3Float_c() const
{
    return *((Scmat3Float_c *)this);
}

inline Float & Scmat3Float::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Float::n1() const
{
    return m_N1;
}

inline Long Scmat3Float::n2() const
{
    return m_N2;
}

inline Long Scmat3Float::n3() const
{
    return m_N3;
}

inline void Scmat3Float::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Float::set(Float * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Float::set(const Scmat3Float &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Float::~Scmat3Float() {}

typedef const Scmat3Float & Scmat3Float_O, & Scmat3Float_IO;

class Scmat3Doub_c : public SvecDoub_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Doub_c();
    Scmat3Doub_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Doub_c(const Doub *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Doub_c &operator=(const Scmat3Doub_c &) = delete;

    // === Cmat functions ===
    const Doub& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Doub *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Doub_c &sli);
    ~Scmat3Doub_c();
};

inline Scmat3Doub_c::Scmat3Doub_c() {}

inline Scmat3Doub_c::Scmat3Doub_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecDoub_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Doub_c::Scmat3Doub_c(const Doub *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Doub_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Doub & Scmat3Doub_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Doub_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Doub_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Doub_c::n3() const
{
    return m_N3;
}

inline void Scmat3Doub_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Doub_c::set(const Doub * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Doub_c::set(const Scmat3Doub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Doub_c::~Scmat3Doub_c() {}

typedef const Scmat3Doub_c & Scmat3Doub_I;

class Scmat3Doub : public SvecDoub
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Doub();
    Scmat3Doub(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Doub(Doub *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Doub_c() const;
    Scmat3Doub &operator=(const Scmat3Doub &) = delete;

    // === Cmat functions ===
    Doub& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Doub *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Doub &sli);
    ~Scmat3Doub();
};

inline Scmat3Doub::Scmat3Doub() {}

inline Scmat3Doub::Scmat3Doub(Long_I N1, Long_I N2, Long_I N3)
    : SvecDoub(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Doub::Scmat3Doub(Doub *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Doub(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Doub::operator Scmat3Doub_c() const
{
    return *((Scmat3Doub_c *)this);
}

inline Doub & Scmat3Doub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Doub::n1() const
{
    return m_N1;
}

inline Long Scmat3Doub::n2() const
{
    return m_N2;
}

inline Long Scmat3Doub::n3() const
{
    return m_N3;
}

inline void Scmat3Doub::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Doub::set(Doub * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Doub::set(const Scmat3Doub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Doub::~Scmat3Doub() {}

typedef const Scmat3Doub & Scmat3Doub_O, & Scmat3Doub_IO;

class Scmat3Ldoub_c : public SvecLdoub_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Ldoub_c();
    Scmat3Ldoub_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Ldoub_c(const Ldoub *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Ldoub_c &operator=(const Scmat3Ldoub_c &) = delete;

    // === Cmat functions ===
    const Ldoub& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Ldoub *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Ldoub_c &sli);
    ~Scmat3Ldoub_c();
};

inline Scmat3Ldoub_c::Scmat3Ldoub_c() {}

inline Scmat3Ldoub_c::Scmat3Ldoub_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecLdoub_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Ldoub_c::Scmat3Ldoub_c(const Ldoub *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Ldoub_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Ldoub & Scmat3Ldoub_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Ldoub_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Ldoub_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Ldoub_c::n3() const
{
    return m_N3;
}

inline void Scmat3Ldoub_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Ldoub_c::set(const Ldoub * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Ldoub_c::set(const Scmat3Ldoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Ldoub_c::~Scmat3Ldoub_c() {}

typedef const Scmat3Ldoub_c & Scmat3Ldoub_I;

class Scmat3Ldoub : public SvecLdoub
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Ldoub();
    Scmat3Ldoub(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Ldoub(Ldoub *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Ldoub_c() const;
    Scmat3Ldoub &operator=(const Scmat3Ldoub &) = delete;

    // === Cmat functions ===
    Ldoub& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Ldoub *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Ldoub &sli);
    ~Scmat3Ldoub();
};

inline Scmat3Ldoub::Scmat3Ldoub() {}

inline Scmat3Ldoub::Scmat3Ldoub(Long_I N1, Long_I N2, Long_I N3)
    : SvecLdoub(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Ldoub::Scmat3Ldoub(Ldoub *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Ldoub(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Ldoub::operator Scmat3Ldoub_c() const
{
    return *((Scmat3Ldoub_c *)this);
}

inline Ldoub & Scmat3Ldoub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Ldoub::n1() const
{
    return m_N1;
}

inline Long Scmat3Ldoub::n2() const
{
    return m_N2;
}

inline Long Scmat3Ldoub::n3() const
{
    return m_N3;
}

inline void Scmat3Ldoub::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Ldoub::set(Ldoub * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Ldoub::set(const Scmat3Ldoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Ldoub::~Scmat3Ldoub() {}

typedef const Scmat3Ldoub & Scmat3Ldoub_O, & Scmat3Ldoub_IO;

class Scmat3Fcomp_c : public SvecFcomp_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Fcomp_c();
    Scmat3Fcomp_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Fcomp_c(const Fcomp *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Fcomp_c &operator=(const Scmat3Fcomp_c &) = delete;

    // === Cmat functions ===
    const Fcomp& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Fcomp *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Fcomp_c &sli);
    ~Scmat3Fcomp_c();
};

inline Scmat3Fcomp_c::Scmat3Fcomp_c() {}

inline Scmat3Fcomp_c::Scmat3Fcomp_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecFcomp_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Fcomp_c::Scmat3Fcomp_c(const Fcomp *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Fcomp_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Fcomp & Scmat3Fcomp_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Fcomp_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Fcomp_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Fcomp_c::n3() const
{
    return m_N3;
}

inline void Scmat3Fcomp_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Fcomp_c::set(const Fcomp * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Fcomp_c::set(const Scmat3Fcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Fcomp_c::~Scmat3Fcomp_c() {}

typedef const Scmat3Fcomp_c & Scmat3Fcomp_I;

class Scmat3Fcomp : public SvecFcomp
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Fcomp();
    Scmat3Fcomp(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Fcomp(Fcomp *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Fcomp_c() const;
    Scmat3Fcomp &operator=(const Scmat3Fcomp &) = delete;

    // === Cmat functions ===
    Fcomp& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Fcomp *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Fcomp &sli);
    ~Scmat3Fcomp();
};

inline Scmat3Fcomp::Scmat3Fcomp() {}

inline Scmat3Fcomp::Scmat3Fcomp(Long_I N1, Long_I N2, Long_I N3)
    : SvecFcomp(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Fcomp::Scmat3Fcomp(Fcomp *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Fcomp(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Fcomp::operator Scmat3Fcomp_c() const
{
    return *((Scmat3Fcomp_c *)this);
}

inline Fcomp & Scmat3Fcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Fcomp::n1() const
{
    return m_N1;
}

inline Long Scmat3Fcomp::n2() const
{
    return m_N2;
}

inline Long Scmat3Fcomp::n3() const
{
    return m_N3;
}

inline void Scmat3Fcomp::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Fcomp::set(Fcomp * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Fcomp::set(const Scmat3Fcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Fcomp::~Scmat3Fcomp() {}

typedef const Scmat3Fcomp & Scmat3Fcomp_O, & Scmat3Fcomp_IO;

class Scmat3Comp_c : public SvecComp_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Comp_c();
    Scmat3Comp_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Comp_c(const Comp *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Comp_c &operator=(const Scmat3Comp_c &) = delete;

    // === Cmat functions ===
    const Comp& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Comp *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Comp_c &sli);
    ~Scmat3Comp_c();
};

inline Scmat3Comp_c::Scmat3Comp_c() {}

inline Scmat3Comp_c::Scmat3Comp_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecComp_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Comp_c::Scmat3Comp_c(const Comp *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Comp_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Comp & Scmat3Comp_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Comp_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Comp_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Comp_c::n3() const
{
    return m_N3;
}

inline void Scmat3Comp_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Comp_c::set(const Comp * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Comp_c::set(const Scmat3Comp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Comp_c::~Scmat3Comp_c() {}

typedef const Scmat3Comp_c & Scmat3Comp_I;

class Scmat3Comp : public SvecComp
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Comp();
    Scmat3Comp(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Comp(Comp *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Comp_c() const;
    Scmat3Comp &operator=(const Scmat3Comp &) = delete;

    // === Cmat functions ===
    Comp& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Comp *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Comp &sli);
    ~Scmat3Comp();
};

inline Scmat3Comp::Scmat3Comp() {}

inline Scmat3Comp::Scmat3Comp(Long_I N1, Long_I N2, Long_I N3)
    : SvecComp(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Comp::Scmat3Comp(Comp *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Comp(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Comp::operator Scmat3Comp_c() const
{
    return *((Scmat3Comp_c *)this);
}

inline Comp & Scmat3Comp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Comp::n1() const
{
    return m_N1;
}

inline Long Scmat3Comp::n2() const
{
    return m_N2;
}

inline Long Scmat3Comp::n3() const
{
    return m_N3;
}

inline void Scmat3Comp::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Comp::set(Comp * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Comp::set(const Scmat3Comp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Comp::~Scmat3Comp() {}

typedef const Scmat3Comp & Scmat3Comp_O, & Scmat3Comp_IO;

class Scmat3Lcomp_c : public SvecLcomp_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Lcomp_c();
    Scmat3Lcomp_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Lcomp_c(const Lcomp *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Lcomp_c &operator=(const Scmat3Lcomp_c &) = delete;

    // === Cmat functions ===
    const Lcomp& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Lcomp *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Lcomp_c &sli);
    ~Scmat3Lcomp_c();
};

inline Scmat3Lcomp_c::Scmat3Lcomp_c() {}

inline Scmat3Lcomp_c::Scmat3Lcomp_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecLcomp_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Lcomp_c::Scmat3Lcomp_c(const Lcomp *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Lcomp_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Lcomp & Scmat3Lcomp_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Lcomp_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Lcomp_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Lcomp_c::n3() const
{
    return m_N3;
}

inline void Scmat3Lcomp_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Lcomp_c::set(const Lcomp * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Lcomp_c::set(const Scmat3Lcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Lcomp_c::~Scmat3Lcomp_c() {}

typedef const Scmat3Lcomp_c & Scmat3Lcomp_I;

class Scmat3Lcomp : public SvecLcomp
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Lcomp();
    Scmat3Lcomp(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Lcomp(Lcomp *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Lcomp_c() const;
    Scmat3Lcomp &operator=(const Scmat3Lcomp &) = delete;

    // === Cmat functions ===
    Lcomp& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Lcomp *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Lcomp &sli);
    ~Scmat3Lcomp();
};

inline Scmat3Lcomp::Scmat3Lcomp() {}

inline Scmat3Lcomp::Scmat3Lcomp(Long_I N1, Long_I N2, Long_I N3)
    : SvecLcomp(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Lcomp::Scmat3Lcomp(Lcomp *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Lcomp(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Lcomp::operator Scmat3Lcomp_c() const
{
    return *((Scmat3Lcomp_c *)this);
}

inline Lcomp & Scmat3Lcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Lcomp::n1() const
{
    return m_N1;
}

inline Long Scmat3Lcomp::n2() const
{
    return m_N2;
}

inline Long Scmat3Lcomp::n3() const
{
    return m_N3;
}

inline void Scmat3Lcomp::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Lcomp::set(Lcomp * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Lcomp::set(const Scmat3Lcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Lcomp::~Scmat3Lcomp() {}

typedef const Scmat3Lcomp & Scmat3Lcomp_O, & Scmat3Lcomp_IO;

class Scmat3Fimag_c : public SvecFimag_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Fimag_c();
    Scmat3Fimag_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Fimag_c(const Fimag *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Fimag_c &operator=(const Scmat3Fimag_c &) = delete;

    // === Cmat functions ===
    const Fimag& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Fimag *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Fimag_c &sli);
    ~Scmat3Fimag_c();
};

inline Scmat3Fimag_c::Scmat3Fimag_c() {}

inline Scmat3Fimag_c::Scmat3Fimag_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecFimag_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Fimag_c::Scmat3Fimag_c(const Fimag *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Fimag_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Fimag & Scmat3Fimag_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Fimag_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Fimag_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Fimag_c::n3() const
{
    return m_N3;
}

inline void Scmat3Fimag_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Fimag_c::set(const Fimag * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Fimag_c::set(const Scmat3Fimag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Fimag_c::~Scmat3Fimag_c() {}

typedef const Scmat3Fimag_c & Scmat3Fimag_I;

class Scmat3Fimag : public SvecFimag
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Fimag();
    Scmat3Fimag(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Fimag(Fimag *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Fimag_c() const;
    Scmat3Fimag &operator=(const Scmat3Fimag &) = delete;

    // === Cmat functions ===
    Fimag& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Fimag *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Fimag &sli);
    ~Scmat3Fimag();
};

inline Scmat3Fimag::Scmat3Fimag() {}

inline Scmat3Fimag::Scmat3Fimag(Long_I N1, Long_I N2, Long_I N3)
    : SvecFimag(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Fimag::Scmat3Fimag(Fimag *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Fimag(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Fimag::operator Scmat3Fimag_c() const
{
    return *((Scmat3Fimag_c *)this);
}

inline Fimag & Scmat3Fimag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Fimag::n1() const
{
    return m_N1;
}

inline Long Scmat3Fimag::n2() const
{
    return m_N2;
}

inline Long Scmat3Fimag::n3() const
{
    return m_N3;
}

inline void Scmat3Fimag::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Fimag::set(Fimag * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Fimag::set(const Scmat3Fimag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Fimag::~Scmat3Fimag() {}

typedef const Scmat3Fimag & Scmat3Fimag_O, & Scmat3Fimag_IO;

class Scmat3Imag_c : public SvecImag_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Imag_c();
    Scmat3Imag_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Imag_c(const Imag *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Imag_c &operator=(const Scmat3Imag_c &) = delete;

    // === Cmat functions ===
    const Imag& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Imag *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Imag_c &sli);
    ~Scmat3Imag_c();
};

inline Scmat3Imag_c::Scmat3Imag_c() {}

inline Scmat3Imag_c::Scmat3Imag_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecImag_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Imag_c::Scmat3Imag_c(const Imag *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Imag_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Imag & Scmat3Imag_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Imag_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Imag_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Imag_c::n3() const
{
    return m_N3;
}

inline void Scmat3Imag_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Imag_c::set(const Imag * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Imag_c::set(const Scmat3Imag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Imag_c::~Scmat3Imag_c() {}

typedef const Scmat3Imag_c & Scmat3Imag_I;

class Scmat3Imag : public SvecImag
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Imag();
    Scmat3Imag(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Imag(Imag *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Imag_c() const;
    Scmat3Imag &operator=(const Scmat3Imag &) = delete;

    // === Cmat functions ===
    Imag& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Imag *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Imag &sli);
    ~Scmat3Imag();
};

inline Scmat3Imag::Scmat3Imag() {}

inline Scmat3Imag::Scmat3Imag(Long_I N1, Long_I N2, Long_I N3)
    : SvecImag(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Imag::Scmat3Imag(Imag *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Imag(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Imag::operator Scmat3Imag_c() const
{
    return *((Scmat3Imag_c *)this);
}

inline Imag & Scmat3Imag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Imag::n1() const
{
    return m_N1;
}

inline Long Scmat3Imag::n2() const
{
    return m_N2;
}

inline Long Scmat3Imag::n3() const
{
    return m_N3;
}

inline void Scmat3Imag::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Imag::set(Imag * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Imag::set(const Scmat3Imag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Imag::~Scmat3Imag() {}

typedef const Scmat3Imag & Scmat3Imag_O, & Scmat3Imag_IO;

class Scmat3Limag_c : public SvecLimag_c
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Limag_c();
    Scmat3Limag_c(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Limag_c(const Limag *ptr, Long_I N1, Long_I N2, Long_I N3);

    Scmat3Limag_c &operator=(const Scmat3Limag_c &) = delete;

    // === Cmat functions ===
    const Limag& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(const Limag *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Limag_c &sli);
    ~Scmat3Limag_c();
};

inline Scmat3Limag_c::Scmat3Limag_c() {}

inline Scmat3Limag_c::Scmat3Limag_c(Long_I N1, Long_I N2, Long_I N3)
    : SvecLimag_c(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Limag_c::Scmat3Limag_c(const Limag *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Limag_c(N1, N2, N3)
{
    m_p = ptr;
}


inline const Limag & Scmat3Limag_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Limag_c::n1() const
{
    return m_N1;
}

inline Long Scmat3Limag_c::n2() const
{
    return m_N2;
}

inline Long Scmat3Limag_c::n3() const
{
    return m_N3;
}

inline void Scmat3Limag_c::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Limag_c::set(const Limag * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Limag_c::set(const Scmat3Limag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Limag_c::~Scmat3Limag_c() {}

typedef const Scmat3Limag_c & Scmat3Limag_I;

class Scmat3Limag : public SvecLimag
{
protected:
    Long m_N1, m_N2, m_N3;
public:
    Scmat3Limag();
    Scmat3Limag(Long_I N1, Long_I N2, Long_I N3);
    Scmat3Limag(Limag *ptr, Long_I N1, Long_I N2, Long_I N3);

    operator Scmat3Limag_c() const;
    Scmat3Limag &operator=(const Scmat3Limag &) = delete;

    // === Cmat functions ===
    Limag& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void reshape(Long_I N1, Long_I N2, Long_I N3);
    void set(Limag *ptr, Long_I N1, Long_I N2, Long_I N3);
    void set(const Scmat3Limag &sli);
    ~Scmat3Limag();
};

inline Scmat3Limag::Scmat3Limag() {}

inline Scmat3Limag::Scmat3Limag(Long_I N1, Long_I N2, Long_I N3)
    : SvecLimag(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat3Limag::Scmat3Limag(Limag *ptr, Long_I N1, Long_I N2, Long_I N3)
    : Scmat3Limag(N1, N2, N3)
{
    m_p = ptr;
}

inline Scmat3Limag::operator Scmat3Limag_c() const
{
    return *((Scmat3Limag_c *)this);
}

inline Limag & Scmat3Limag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Scmat3Limag::n1() const
{
    return m_N1;
}

inline Long Scmat3Limag::n2() const
{
    return m_N2;
}

inline Long Scmat3Limag::n3() const
{
    return m_N3;
}

inline void Scmat3Limag::reshape(Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0 || N3 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Limag::set(Limag * ptr, Long_I N1, Long_I N2, Long_I N3)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N = N1 * N2 * N3;
}

inline void Scmat3Limag::set(const Scmat3Limag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
    m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3;
}

inline Scmat3Limag::~Scmat3Limag() {}

typedef const Scmat3Limag & Scmat3Limag_O, & Scmat3Limag_IO;

} // namespace slisc
