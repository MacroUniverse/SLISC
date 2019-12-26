#pragma once
#include "Svec.h"

namespace slisc {
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
    void set_size(Long_I N1, Long_I N2, Long_I N3);
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

inline void Scmat3Int_c::set_size(Long_I N1, Long_I N2, Long_I N3)
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
    void set_size(Long_I N1, Long_I N2, Long_I N3);
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

inline void Scmat3Int::set_size(Long_I N1, Long_I N2, Long_I N3)
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
    void set_size(Long_I N1, Long_I N2, Long_I N3);
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

inline void Scmat3Llong_c::set_size(Long_I N1, Long_I N2, Long_I N3)
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
    void set_size(Long_I N1, Long_I N2, Long_I N3);
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

inline void Scmat3Llong::set_size(Long_I N1, Long_I N2, Long_I N3)
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
    void set_size(Long_I N1, Long_I N2, Long_I N3);
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

inline void Scmat3Doub_c::set_size(Long_I N1, Long_I N2, Long_I N3)
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
    void set_size(Long_I N1, Long_I N2, Long_I N3);
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

inline void Scmat3Doub::set_size(Long_I N1, Long_I N2, Long_I N3)
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
    void set_size(Long_I N1, Long_I N2, Long_I N3);
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

inline void Scmat3Comp_c::set_size(Long_I N1, Long_I N2, Long_I N3)
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
    void set_size(Long_I N1, Long_I N2, Long_I N3);
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

inline void Scmat3Comp::set_size(Long_I N1, Long_I N2, Long_I N3)
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

} // namespace slisc
