#pragma once
#include "global.h"

namespace slisc {
class Jcmat3Int_c
{
private:
    const Int *m_p;
    Long m_N;
    Long m_N1, m_N2, m_N3;
    Long m_step1, m_step2, m_step3; // a(i,j) = m_p + m_step1*i + m_step2*j + m_step*k
public:
    Jcmat3Int_c();
    Jcmat3Int_c(const Int *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
    void set(const Int *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Int_c &sli);
	Jcmat3Int_c &operator=(const Jcmat3Int_c &) = delete;
    const Int& operator[](Long_I i) const;
    const Int& operator()(Long_I i) const;
    const Int& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long step1() const;
    Long step2() const;
    Long step3() const;
    Long size() const;

    const Int *ptr() const;
};

inline Jcmat3Int_c::Jcmat3Int_c() {}

inline Jcmat3Int_c::Jcmat3Int_c(const Int *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N3(N3), m_N(N1*N2*N3), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Int_c::set(const Int *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N3 = N3;
    m_step1 = step1; m_step2 = step2; m_step3 = step3;
    m_N = N1 * N2 * N3;
}

inline void Jcmat3Int_c::set(const Jcmat3Int_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Int & Jcmat3Int_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("out of bound!");
#endif
    Long N1N2 = m_N1 * m_N2;
    Long i2 = i % N1N2;
    return operator()(i2 % m_N1, i2 / m_N1, i / N1N2);
}

inline const Int & Jcmat3Int_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Int & Jcmat3Int_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k > m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Int_c::n1() const
{
    return m_N1;
}

inline Long Jcmat3Int_c::n2() const
{
    return m_N2;
}

inline Long Jcmat3Int_c::n3() const
{
    return m_N3;
}

inline Long Jcmat3Int_c::step1() const
{
    return m_step1;
}

inline Long Jcmat3Int_c::step2() const
{
    return m_step2;
}

inline Long Jcmat3Int_c::step3() const
{
    return m_step3;
}

inline Long Jcmat3Int_c::size() const
{
    return m_N;
}

inline const Int * Jcmat3Int_c::ptr() const
{
    return m_p;
}

typedef const Jcmat3Int_c & Jcmat3Int_I;

class Jcmat3Int
{
private:
    Int *m_p;
    Long m_N;
    Long m_N1, m_N2, m_N3;
    Long m_step1, m_step2, m_step3; // a(i,j) = m_p + m_step1*i + m_step2*j + m_step*k
public:
    Jcmat3Int();
    Jcmat3Int(Int *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
    void set(Int *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Int &sli);
	operator Jcmat3Int_c() const;
	Jcmat3Int &operator=(const Jcmat3Int &) = delete;
    Int& operator[](Long_I i) const;
    Int& operator()(Long_I i) const;
    Int& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long step1() const;
    Long step2() const;
    Long step3() const;
    Long size() const;

    Int *ptr() const;
};

inline Jcmat3Int::Jcmat3Int() {}

inline Jcmat3Int::Jcmat3Int(Int *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N3(N3), m_N(N1*N2*N3), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Int::set(Int *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N3 = N3;
    m_step1 = step1; m_step2 = step2; m_step3 = step3;
    m_N = N1 * N2 * N3;
}

inline void Jcmat3Int::set(const Jcmat3Int &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Int::operator Jcmat3Int_c() const
{
	return *((Jcmat3Int_c *)this);
}

inline Int & Jcmat3Int::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("out of bound!");
#endif
    Long N1N2 = m_N1 * m_N2;
    Long i2 = i % N1N2;
    return operator()(i2 % m_N1, i2 / m_N1, i / N1N2);
}

inline Int & Jcmat3Int::operator()(Long_I i) const
{
    return operator[](i);
}

inline Int & Jcmat3Int::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k > m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Int::n1() const
{
    return m_N1;
}

inline Long Jcmat3Int::n2() const
{
    return m_N2;
}

inline Long Jcmat3Int::n3() const
{
    return m_N3;
}

inline Long Jcmat3Int::step1() const
{
    return m_step1;
}

inline Long Jcmat3Int::step2() const
{
    return m_step2;
}

inline Long Jcmat3Int::step3() const
{
    return m_step3;
}

inline Long Jcmat3Int::size() const
{
    return m_N;
}

inline Int * Jcmat3Int::ptr() const
{
    return m_p;
}

typedef const Jcmat3Int & Jcmat3Int_O, & Jcmat3Int_IO;

class Jcmat3Llong_c
{
private:
    const Llong *m_p;
    Long m_N;
    Long m_N1, m_N2, m_N3;
    Long m_step1, m_step2, m_step3; // a(i,j) = m_p + m_step1*i + m_step2*j + m_step*k
public:
    Jcmat3Llong_c();
    Jcmat3Llong_c(const Llong *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
    void set(const Llong *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Llong_c &sli);
	Jcmat3Llong_c &operator=(const Jcmat3Llong_c &) = delete;
    const Llong& operator[](Long_I i) const;
    const Llong& operator()(Long_I i) const;
    const Llong& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long step1() const;
    Long step2() const;
    Long step3() const;
    Long size() const;

    const Llong *ptr() const;
};

inline Jcmat3Llong_c::Jcmat3Llong_c() {}

inline Jcmat3Llong_c::Jcmat3Llong_c(const Llong *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N3(N3), m_N(N1*N2*N3), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Llong_c::set(const Llong *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N3 = N3;
    m_step1 = step1; m_step2 = step2; m_step3 = step3;
    m_N = N1 * N2 * N3;
}

inline void Jcmat3Llong_c::set(const Jcmat3Llong_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Llong & Jcmat3Llong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("out of bound!");
#endif
    Long N1N2 = m_N1 * m_N2;
    Long i2 = i % N1N2;
    return operator()(i2 % m_N1, i2 / m_N1, i / N1N2);
}

inline const Llong & Jcmat3Llong_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Llong & Jcmat3Llong_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k > m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Llong_c::n1() const
{
    return m_N1;
}

inline Long Jcmat3Llong_c::n2() const
{
    return m_N2;
}

inline Long Jcmat3Llong_c::n3() const
{
    return m_N3;
}

inline Long Jcmat3Llong_c::step1() const
{
    return m_step1;
}

inline Long Jcmat3Llong_c::step2() const
{
    return m_step2;
}

inline Long Jcmat3Llong_c::step3() const
{
    return m_step3;
}

inline Long Jcmat3Llong_c::size() const
{
    return m_N;
}

inline const Llong * Jcmat3Llong_c::ptr() const
{
    return m_p;
}

typedef const Jcmat3Llong_c & Jcmat3Llong_I;

class Jcmat3Llong
{
private:
    Llong *m_p;
    Long m_N;
    Long m_N1, m_N2, m_N3;
    Long m_step1, m_step2, m_step3; // a(i,j) = m_p + m_step1*i + m_step2*j + m_step*k
public:
    Jcmat3Llong();
    Jcmat3Llong(Llong *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
    void set(Llong *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Llong &sli);
	operator Jcmat3Llong_c() const;
	Jcmat3Llong &operator=(const Jcmat3Llong &) = delete;
    Llong& operator[](Long_I i) const;
    Llong& operator()(Long_I i) const;
    Llong& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long step1() const;
    Long step2() const;
    Long step3() const;
    Long size() const;

    Llong *ptr() const;
};

inline Jcmat3Llong::Jcmat3Llong() {}

inline Jcmat3Llong::Jcmat3Llong(Llong *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N3(N3), m_N(N1*N2*N3), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Llong::set(Llong *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N3 = N3;
    m_step1 = step1; m_step2 = step2; m_step3 = step3;
    m_N = N1 * N2 * N3;
}

inline void Jcmat3Llong::set(const Jcmat3Llong &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Llong::operator Jcmat3Llong_c() const
{
	return *((Jcmat3Llong_c *)this);
}

inline Llong & Jcmat3Llong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("out of bound!");
#endif
    Long N1N2 = m_N1 * m_N2;
    Long i2 = i % N1N2;
    return operator()(i2 % m_N1, i2 / m_N1, i / N1N2);
}

inline Llong & Jcmat3Llong::operator()(Long_I i) const
{
    return operator[](i);
}

inline Llong & Jcmat3Llong::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k > m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Llong::n1() const
{
    return m_N1;
}

inline Long Jcmat3Llong::n2() const
{
    return m_N2;
}

inline Long Jcmat3Llong::n3() const
{
    return m_N3;
}

inline Long Jcmat3Llong::step1() const
{
    return m_step1;
}

inline Long Jcmat3Llong::step2() const
{
    return m_step2;
}

inline Long Jcmat3Llong::step3() const
{
    return m_step3;
}

inline Long Jcmat3Llong::size() const
{
    return m_N;
}

inline Llong * Jcmat3Llong::ptr() const
{
    return m_p;
}

typedef const Jcmat3Llong & Jcmat3Llong_O, & Jcmat3Llong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef Jcmat3Int_c Jcmat3Long_c;
#else
typedef Jcmat3Llong_c Jcmat3Long_c;
#endif

typedef const Jcmat3Long_c & Jcmat3Long_I;

#ifdef SLS_USE_INT_AS_LONG
typedef Jcmat3Int Jcmat3Long;
#else
typedef Jcmat3Llong Jcmat3Long;
#endif

typedef const Jcmat3Long & Jcmat3Long_O, & Jcmat3Long_IO;

class Jcmat3Doub_c
{
private:
    const Doub *m_p;
    Long m_N;
    Long m_N1, m_N2, m_N3;
    Long m_step1, m_step2, m_step3; // a(i,j) = m_p + m_step1*i + m_step2*j + m_step*k
public:
    Jcmat3Doub_c();
    Jcmat3Doub_c(const Doub *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
    void set(const Doub *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Doub_c &sli);
	Jcmat3Doub_c &operator=(const Jcmat3Doub_c &) = delete;
    const Doub& operator[](Long_I i) const;
    const Doub& operator()(Long_I i) const;
    const Doub& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long step1() const;
    Long step2() const;
    Long step3() const;
    Long size() const;

    const Doub *ptr() const;
};

inline Jcmat3Doub_c::Jcmat3Doub_c() {}

inline Jcmat3Doub_c::Jcmat3Doub_c(const Doub *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N3(N3), m_N(N1*N2*N3), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Doub_c::set(const Doub *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N3 = N3;
    m_step1 = step1; m_step2 = step2; m_step3 = step3;
    m_N = N1 * N2 * N3;
}

inline void Jcmat3Doub_c::set(const Jcmat3Doub_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Doub & Jcmat3Doub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("out of bound!");
#endif
    Long N1N2 = m_N1 * m_N2;
    Long i2 = i % N1N2;
    return operator()(i2 % m_N1, i2 / m_N1, i / N1N2);
}

inline const Doub & Jcmat3Doub_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Doub & Jcmat3Doub_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k > m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Doub_c::n1() const
{
    return m_N1;
}

inline Long Jcmat3Doub_c::n2() const
{
    return m_N2;
}

inline Long Jcmat3Doub_c::n3() const
{
    return m_N3;
}

inline Long Jcmat3Doub_c::step1() const
{
    return m_step1;
}

inline Long Jcmat3Doub_c::step2() const
{
    return m_step2;
}

inline Long Jcmat3Doub_c::step3() const
{
    return m_step3;
}

inline Long Jcmat3Doub_c::size() const
{
    return m_N;
}

inline const Doub * Jcmat3Doub_c::ptr() const
{
    return m_p;
}

typedef const Jcmat3Doub_c & Jcmat3Doub_I;

class Jcmat3Doub
{
private:
    Doub *m_p;
    Long m_N;
    Long m_N1, m_N2, m_N3;
    Long m_step1, m_step2, m_step3; // a(i,j) = m_p + m_step1*i + m_step2*j + m_step*k
public:
    Jcmat3Doub();
    Jcmat3Doub(Doub *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
    void set(Doub *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Doub &sli);
	operator Jcmat3Doub_c() const;
	Jcmat3Doub &operator=(const Jcmat3Doub &) = delete;
    Doub& operator[](Long_I i) const;
    Doub& operator()(Long_I i) const;
    Doub& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long step1() const;
    Long step2() const;
    Long step3() const;
    Long size() const;

    Doub *ptr() const;
};

inline Jcmat3Doub::Jcmat3Doub() {}

inline Jcmat3Doub::Jcmat3Doub(Doub *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N3(N3), m_N(N1*N2*N3), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Doub::set(Doub *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N3 = N3;
    m_step1 = step1; m_step2 = step2; m_step3 = step3;
    m_N = N1 * N2 * N3;
}

inline void Jcmat3Doub::set(const Jcmat3Doub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Doub::operator Jcmat3Doub_c() const
{
	return *((Jcmat3Doub_c *)this);
}

inline Doub & Jcmat3Doub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("out of bound!");
#endif
    Long N1N2 = m_N1 * m_N2;
    Long i2 = i % N1N2;
    return operator()(i2 % m_N1, i2 / m_N1, i / N1N2);
}

inline Doub & Jcmat3Doub::operator()(Long_I i) const
{
    return operator[](i);
}

inline Doub & Jcmat3Doub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k > m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Doub::n1() const
{
    return m_N1;
}

inline Long Jcmat3Doub::n2() const
{
    return m_N2;
}

inline Long Jcmat3Doub::n3() const
{
    return m_N3;
}

inline Long Jcmat3Doub::step1() const
{
    return m_step1;
}

inline Long Jcmat3Doub::step2() const
{
    return m_step2;
}

inline Long Jcmat3Doub::step3() const
{
    return m_step3;
}

inline Long Jcmat3Doub::size() const
{
    return m_N;
}

inline Doub * Jcmat3Doub::ptr() const
{
    return m_p;
}

typedef const Jcmat3Doub & Jcmat3Doub_O, & Jcmat3Doub_IO;

class Jcmat3Comp_c
{
private:
    const Comp *m_p;
    Long m_N;
    Long m_N1, m_N2, m_N3;
    Long m_step1, m_step2, m_step3; // a(i,j) = m_p + m_step1*i + m_step2*j + m_step*k
public:
    Jcmat3Comp_c();
    Jcmat3Comp_c(const Comp *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
    void set(const Comp *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Comp_c &sli);
	Jcmat3Comp_c &operator=(const Jcmat3Comp_c &) = delete;
    const Comp& operator[](Long_I i) const;
    const Comp& operator()(Long_I i) const;
    const Comp& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long step1() const;
    Long step2() const;
    Long step3() const;
    Long size() const;

    const Comp *ptr() const;
};

inline Jcmat3Comp_c::Jcmat3Comp_c() {}

inline Jcmat3Comp_c::Jcmat3Comp_c(const Comp *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N3(N3), m_N(N1*N2*N3), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Comp_c::set(const Comp *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N3 = N3;
    m_step1 = step1; m_step2 = step2; m_step3 = step3;
    m_N = N1 * N2 * N3;
}

inline void Jcmat3Comp_c::set(const Jcmat3Comp_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Comp & Jcmat3Comp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("out of bound!");
#endif
    Long N1N2 = m_N1 * m_N2;
    Long i2 = i % N1N2;
    return operator()(i2 % m_N1, i2 / m_N1, i / N1N2);
}

inline const Comp & Jcmat3Comp_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Comp & Jcmat3Comp_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k > m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Comp_c::n1() const
{
    return m_N1;
}

inline Long Jcmat3Comp_c::n2() const
{
    return m_N2;
}

inline Long Jcmat3Comp_c::n3() const
{
    return m_N3;
}

inline Long Jcmat3Comp_c::step1() const
{
    return m_step1;
}

inline Long Jcmat3Comp_c::step2() const
{
    return m_step2;
}

inline Long Jcmat3Comp_c::step3() const
{
    return m_step3;
}

inline Long Jcmat3Comp_c::size() const
{
    return m_N;
}

inline const Comp * Jcmat3Comp_c::ptr() const
{
    return m_p;
}

typedef const Jcmat3Comp_c & Jcmat3Comp_I;

class Jcmat3Comp
{
private:
    Comp *m_p;
    Long m_N;
    Long m_N1, m_N2, m_N3;
    Long m_step1, m_step2, m_step3; // a(i,j) = m_p + m_step1*i + m_step2*j + m_step*k
public:
    Jcmat3Comp();
    Jcmat3Comp(Comp *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
    void set(Comp *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Comp &sli);
	operator Jcmat3Comp_c() const;
	Jcmat3Comp &operator=(const Jcmat3Comp &) = delete;
    Comp& operator[](Long_I i) const;
    Comp& operator()(Long_I i) const;
    Comp& operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long step1() const;
    Long step2() const;
    Long step3() const;
    Long size() const;

    Comp *ptr() const;
};

inline Jcmat3Comp::Jcmat3Comp() {}

inline Jcmat3Comp::Jcmat3Comp(Comp *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N3(N3), m_N(N1*N2*N3), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Comp::set(Comp *ptr, Long_I N1, Long_I N2, Long_I N3, Long_I step1, Long_I step2, Long_I step3)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N3 = N3;
    m_step1 = step1; m_step2 = step2; m_step3 = step3;
    m_N = N1 * N2 * N3;
}

inline void Jcmat3Comp::set(const Jcmat3Comp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_N3 = sli.m_N3; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Comp::operator Jcmat3Comp_c() const
{
	return *((Jcmat3Comp_c *)this);
}

inline Comp & Jcmat3Comp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("out of bound!");
#endif
    Long N1N2 = m_N1 * m_N2;
    Long i2 = i % N1N2;
    return operator()(i2 % m_N1, i2 / m_N1, i / N1N2);
}

inline Comp & Jcmat3Comp::operator()(Long_I i) const
{
    return operator[](i);
}

inline Comp & Jcmat3Comp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k > m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Comp::n1() const
{
    return m_N1;
}

inline Long Jcmat3Comp::n2() const
{
    return m_N2;
}

inline Long Jcmat3Comp::n3() const
{
    return m_N3;
}

inline Long Jcmat3Comp::step1() const
{
    return m_step1;
}

inline Long Jcmat3Comp::step2() const
{
    return m_step2;
}

inline Long Jcmat3Comp::step3() const
{
    return m_step3;
}

inline Long Jcmat3Comp::size() const
{
    return m_N;
}

inline Comp * Jcmat3Comp::ptr() const
{
    return m_p;
}

typedef const Jcmat3Comp & Jcmat3Comp_O, & Jcmat3Comp_IO;

} // namespace slisc
