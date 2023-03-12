#pragma once
#include "global.h"
// "_c" means lower level const

namespace slisc {
class Jcmat3Char_c
{
protected:
	const Char *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Char_c();
	Jcmat3Char_c(const Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Char_c &sli);
	Jcmat3Char_c &operator=(const Jcmat3Char_c &) = delete;
	const Char &operator[](Long_I i) const;
	const Char &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	const Char *p() const;
};

inline Jcmat3Char_c::Jcmat3Char_c() {}

inline Jcmat3Char_c::Jcmat3Char_c(const Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Char_c::set(const Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Char_c::set(const Jcmat3Char_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Char &Jcmat3Char_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Char &Jcmat3Char_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Char_c::n0() const
{
	return m_N0;
}

inline Long Jcmat3Char_c::n1() const
{
	return m_N1;
}

inline Long Jcmat3Char_c::n2() const
{
	return m_N2;
}

inline Long Jcmat3Char_c::step1() const
{
	return m_step1;
}

inline Long Jcmat3Char_c::step2() const
{
	return m_step2;
}

inline Long Jcmat3Char_c::step3() const
{
	return m_step3;
}

inline Long Jcmat3Char_c::size() const
{
	return m_N;
}

inline const Char *Jcmat3Char_c::p() const
{
	return m_p;
}

typedef const Jcmat3Char_c &Jcmat3Char_I;

class Jcmat3Char
{
protected:
	Char *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Char();
	Jcmat3Char(Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Char &sli);
	operator Jcmat3Char_c() const;
	Jcmat3Char &operator=(const Jcmat3Char &) = delete;
	Char &operator[](Long_I i) const;
	Char &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	Char *p() const;
};

inline Jcmat3Char::Jcmat3Char() {}

inline Jcmat3Char::Jcmat3Char(Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Char::set(Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Char::set(const Jcmat3Char &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Char::operator Jcmat3Char_c() const
{
	return *((Jcmat3Char_c *)this);
}

inline Char &Jcmat3Char::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline Char &Jcmat3Char::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Char::n0() const
{
	return m_N0;
}

inline Long Jcmat3Char::n1() const
{
	return m_N1;
}

inline Long Jcmat3Char::n2() const
{
	return m_N2;
}

inline Long Jcmat3Char::step1() const
{
	return m_step1;
}

inline Long Jcmat3Char::step2() const
{
	return m_step2;
}

inline Long Jcmat3Char::step3() const
{
	return m_step3;
}

inline Long Jcmat3Char::size() const
{
	return m_N;
}

inline Char *Jcmat3Char::p() const
{
	return m_p;
}

typedef const Jcmat3Char &Jcmat3Char_O, &Jcmat3Char_IO;

class Jcmat3Int_c
{
protected:
	const Int *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Int_c();
	Jcmat3Int_c(const Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Int_c &sli);
	Jcmat3Int_c &operator=(const Jcmat3Int_c &) = delete;
	const Int &operator[](Long_I i) const;
	const Int &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	const Int *p() const;
};

inline Jcmat3Int_c::Jcmat3Int_c() {}

inline Jcmat3Int_c::Jcmat3Int_c(const Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Int_c::set(const Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Int_c::set(const Jcmat3Int_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Int &Jcmat3Int_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Int &Jcmat3Int_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Int_c::n0() const
{
	return m_N0;
}

inline Long Jcmat3Int_c::n1() const
{
	return m_N1;
}

inline Long Jcmat3Int_c::n2() const
{
	return m_N2;
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

inline const Int *Jcmat3Int_c::p() const
{
	return m_p;
}

typedef const Jcmat3Int_c &Jcmat3Int_I;

class Jcmat3Int
{
protected:
	Int *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Int();
	Jcmat3Int(Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Int &sli);
	operator Jcmat3Int_c() const;
	Jcmat3Int &operator=(const Jcmat3Int &) = delete;
	Int &operator[](Long_I i) const;
	Int &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	Int *p() const;
};

inline Jcmat3Int::Jcmat3Int() {}

inline Jcmat3Int::Jcmat3Int(Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Int::set(Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Int::set(const Jcmat3Int &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Int::operator Jcmat3Int_c() const
{
	return *((Jcmat3Int_c *)this);
}

inline Int &Jcmat3Int::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline Int &Jcmat3Int::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Int::n0() const
{
	return m_N0;
}

inline Long Jcmat3Int::n1() const
{
	return m_N1;
}

inline Long Jcmat3Int::n2() const
{
	return m_N2;
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

inline Int *Jcmat3Int::p() const
{
	return m_p;
}

typedef const Jcmat3Int &Jcmat3Int_O, &Jcmat3Int_IO;

class Jcmat3Llong_c
{
protected:
	const Llong *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Llong_c();
	Jcmat3Llong_c(const Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Llong_c &sli);
	Jcmat3Llong_c &operator=(const Jcmat3Llong_c &) = delete;
	const Llong &operator[](Long_I i) const;
	const Llong &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	const Llong *p() const;
};

inline Jcmat3Llong_c::Jcmat3Llong_c() {}

inline Jcmat3Llong_c::Jcmat3Llong_c(const Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Llong_c::set(const Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Llong_c::set(const Jcmat3Llong_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Llong &Jcmat3Llong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Llong &Jcmat3Llong_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Llong_c::n0() const
{
	return m_N0;
}

inline Long Jcmat3Llong_c::n1() const
{
	return m_N1;
}

inline Long Jcmat3Llong_c::n2() const
{
	return m_N2;
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

inline const Llong *Jcmat3Llong_c::p() const
{
	return m_p;
}

typedef const Jcmat3Llong_c &Jcmat3Llong_I;

class Jcmat3Llong
{
protected:
	Llong *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Llong();
	Jcmat3Llong(Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Llong &sli);
	operator Jcmat3Llong_c() const;
	Jcmat3Llong &operator=(const Jcmat3Llong &) = delete;
	Llong &operator[](Long_I i) const;
	Llong &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	Llong *p() const;
};

inline Jcmat3Llong::Jcmat3Llong() {}

inline Jcmat3Llong::Jcmat3Llong(Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Llong::set(Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Llong::set(const Jcmat3Llong &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Llong::operator Jcmat3Llong_c() const
{
	return *((Jcmat3Llong_c *)this);
}

inline Llong &Jcmat3Llong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline Llong &Jcmat3Llong::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Llong::n0() const
{
	return m_N0;
}

inline Long Jcmat3Llong::n1() const
{
	return m_N1;
}

inline Long Jcmat3Llong::n2() const
{
	return m_N2;
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

inline Llong *Jcmat3Llong::p() const
{
	return m_p;
}

typedef const Jcmat3Llong &Jcmat3Llong_O, &Jcmat3Llong_IO;

class Jcmat3Float_c
{
protected:
	const Float *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Float_c();
	Jcmat3Float_c(const Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Float_c &sli);
	Jcmat3Float_c &operator=(const Jcmat3Float_c &) = delete;
	const Float &operator[](Long_I i) const;
	const Float &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	const Float *p() const;
};

inline Jcmat3Float_c::Jcmat3Float_c() {}

inline Jcmat3Float_c::Jcmat3Float_c(const Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Float_c::set(const Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Float_c::set(const Jcmat3Float_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Float &Jcmat3Float_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Float &Jcmat3Float_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Float_c::n0() const
{
	return m_N0;
}

inline Long Jcmat3Float_c::n1() const
{
	return m_N1;
}

inline Long Jcmat3Float_c::n2() const
{
	return m_N2;
}

inline Long Jcmat3Float_c::step1() const
{
	return m_step1;
}

inline Long Jcmat3Float_c::step2() const
{
	return m_step2;
}

inline Long Jcmat3Float_c::step3() const
{
	return m_step3;
}

inline Long Jcmat3Float_c::size() const
{
	return m_N;
}

inline const Float *Jcmat3Float_c::p() const
{
	return m_p;
}

typedef const Jcmat3Float_c &Jcmat3Float_I;

class Jcmat3Float
{
protected:
	Float *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Float();
	Jcmat3Float(Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Float &sli);
	operator Jcmat3Float_c() const;
	Jcmat3Float &operator=(const Jcmat3Float &) = delete;
	Float &operator[](Long_I i) const;
	Float &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	Float *p() const;
};

inline Jcmat3Float::Jcmat3Float() {}

inline Jcmat3Float::Jcmat3Float(Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Float::set(Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Float::set(const Jcmat3Float &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Float::operator Jcmat3Float_c() const
{
	return *((Jcmat3Float_c *)this);
}

inline Float &Jcmat3Float::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline Float &Jcmat3Float::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Float::n0() const
{
	return m_N0;
}

inline Long Jcmat3Float::n1() const
{
	return m_N1;
}

inline Long Jcmat3Float::n2() const
{
	return m_N2;
}

inline Long Jcmat3Float::step1() const
{
	return m_step1;
}

inline Long Jcmat3Float::step2() const
{
	return m_step2;
}

inline Long Jcmat3Float::step3() const
{
	return m_step3;
}

inline Long Jcmat3Float::size() const
{
	return m_N;
}

inline Float *Jcmat3Float::p() const
{
	return m_p;
}

typedef const Jcmat3Float &Jcmat3Float_O, &Jcmat3Float_IO;

class Jcmat3Doub_c
{
protected:
	const Doub *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Doub_c();
	Jcmat3Doub_c(const Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Doub_c &sli);
	Jcmat3Doub_c &operator=(const Jcmat3Doub_c &) = delete;
	const Doub &operator[](Long_I i) const;
	const Doub &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	const Doub *p() const;
};

inline Jcmat3Doub_c::Jcmat3Doub_c() {}

inline Jcmat3Doub_c::Jcmat3Doub_c(const Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Doub_c::set(const Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Doub_c::set(const Jcmat3Doub_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Doub &Jcmat3Doub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Doub &Jcmat3Doub_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Doub_c::n0() const
{
	return m_N0;
}

inline Long Jcmat3Doub_c::n1() const
{
	return m_N1;
}

inline Long Jcmat3Doub_c::n2() const
{
	return m_N2;
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

inline const Doub *Jcmat3Doub_c::p() const
{
	return m_p;
}

typedef const Jcmat3Doub_c &Jcmat3Doub_I;

class Jcmat3Doub
{
protected:
	Doub *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Doub();
	Jcmat3Doub(Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Doub &sli);
	operator Jcmat3Doub_c() const;
	Jcmat3Doub &operator=(const Jcmat3Doub &) = delete;
	Doub &operator[](Long_I i) const;
	Doub &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	Doub *p() const;
};

inline Jcmat3Doub::Jcmat3Doub() {}

inline Jcmat3Doub::Jcmat3Doub(Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Doub::set(Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Doub::set(const Jcmat3Doub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Doub::operator Jcmat3Doub_c() const
{
	return *((Jcmat3Doub_c *)this);
}

inline Doub &Jcmat3Doub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline Doub &Jcmat3Doub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Doub::n0() const
{
	return m_N0;
}

inline Long Jcmat3Doub::n1() const
{
	return m_N1;
}

inline Long Jcmat3Doub::n2() const
{
	return m_N2;
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

inline Doub *Jcmat3Doub::p() const
{
	return m_p;
}

typedef const Jcmat3Doub &Jcmat3Doub_O, &Jcmat3Doub_IO;

class Jcmat3Ldoub_c
{
protected:
	const Ldoub *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Ldoub_c();
	Jcmat3Ldoub_c(const Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Ldoub_c &sli);
	Jcmat3Ldoub_c &operator=(const Jcmat3Ldoub_c &) = delete;
	const Ldoub &operator[](Long_I i) const;
	const Ldoub &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	const Ldoub *p() const;
};

inline Jcmat3Ldoub_c::Jcmat3Ldoub_c() {}

inline Jcmat3Ldoub_c::Jcmat3Ldoub_c(const Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Ldoub_c::set(const Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Ldoub_c::set(const Jcmat3Ldoub_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Ldoub &Jcmat3Ldoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Ldoub &Jcmat3Ldoub_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Ldoub_c::n0() const
{
	return m_N0;
}

inline Long Jcmat3Ldoub_c::n1() const
{
	return m_N1;
}

inline Long Jcmat3Ldoub_c::n2() const
{
	return m_N2;
}

inline Long Jcmat3Ldoub_c::step1() const
{
	return m_step1;
}

inline Long Jcmat3Ldoub_c::step2() const
{
	return m_step2;
}

inline Long Jcmat3Ldoub_c::step3() const
{
	return m_step3;
}

inline Long Jcmat3Ldoub_c::size() const
{
	return m_N;
}

inline const Ldoub *Jcmat3Ldoub_c::p() const
{
	return m_p;
}

typedef const Jcmat3Ldoub_c &Jcmat3Ldoub_I;

class Jcmat3Ldoub
{
protected:
	Ldoub *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Ldoub();
	Jcmat3Ldoub(Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Ldoub &sli);
	operator Jcmat3Ldoub_c() const;
	Jcmat3Ldoub &operator=(const Jcmat3Ldoub &) = delete;
	Ldoub &operator[](Long_I i) const;
	Ldoub &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	Ldoub *p() const;
};

inline Jcmat3Ldoub::Jcmat3Ldoub() {}

inline Jcmat3Ldoub::Jcmat3Ldoub(Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Ldoub::set(Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Ldoub::set(const Jcmat3Ldoub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Ldoub::operator Jcmat3Ldoub_c() const
{
	return *((Jcmat3Ldoub_c *)this);
}

inline Ldoub &Jcmat3Ldoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline Ldoub &Jcmat3Ldoub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Ldoub::n0() const
{
	return m_N0;
}

inline Long Jcmat3Ldoub::n1() const
{
	return m_N1;
}

inline Long Jcmat3Ldoub::n2() const
{
	return m_N2;
}

inline Long Jcmat3Ldoub::step1() const
{
	return m_step1;
}

inline Long Jcmat3Ldoub::step2() const
{
	return m_step2;
}

inline Long Jcmat3Ldoub::step3() const
{
	return m_step3;
}

inline Long Jcmat3Ldoub::size() const
{
	return m_N;
}

inline Ldoub *Jcmat3Ldoub::p() const
{
	return m_p;
}

typedef const Jcmat3Ldoub &Jcmat3Ldoub_O, &Jcmat3Ldoub_IO;



class Jcmat3Fcomp_c
{
protected:
	const Fcomp *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Fcomp_c();
	Jcmat3Fcomp_c(const Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Fcomp_c &sli);
	Jcmat3Fcomp_c &operator=(const Jcmat3Fcomp_c &) = delete;
	const Fcomp &operator[](Long_I i) const;
	const Fcomp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	const Fcomp *p() const;
};

inline Jcmat3Fcomp_c::Jcmat3Fcomp_c() {}

inline Jcmat3Fcomp_c::Jcmat3Fcomp_c(const Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Fcomp_c::set(const Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Fcomp_c::set(const Jcmat3Fcomp_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Fcomp &Jcmat3Fcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Fcomp &Jcmat3Fcomp_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Fcomp_c::n0() const
{
	return m_N0;
}

inline Long Jcmat3Fcomp_c::n1() const
{
	return m_N1;
}

inline Long Jcmat3Fcomp_c::n2() const
{
	return m_N2;
}

inline Long Jcmat3Fcomp_c::step1() const
{
	return m_step1;
}

inline Long Jcmat3Fcomp_c::step2() const
{
	return m_step2;
}

inline Long Jcmat3Fcomp_c::step3() const
{
	return m_step3;
}

inline Long Jcmat3Fcomp_c::size() const
{
	return m_N;
}

inline const Fcomp *Jcmat3Fcomp_c::p() const
{
	return m_p;
}

typedef const Jcmat3Fcomp_c &Jcmat3Fcomp_I;

class Jcmat3Fcomp
{
protected:
	Fcomp *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Fcomp();
	Jcmat3Fcomp(Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Fcomp &sli);
	operator Jcmat3Fcomp_c() const;
	Jcmat3Fcomp &operator=(const Jcmat3Fcomp &) = delete;
	Fcomp &operator[](Long_I i) const;
	Fcomp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	Fcomp *p() const;
};

inline Jcmat3Fcomp::Jcmat3Fcomp() {}

inline Jcmat3Fcomp::Jcmat3Fcomp(Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Fcomp::set(Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Fcomp::set(const Jcmat3Fcomp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Fcomp::operator Jcmat3Fcomp_c() const
{
	return *((Jcmat3Fcomp_c *)this);
}

inline Fcomp &Jcmat3Fcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline Fcomp &Jcmat3Fcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Fcomp::n0() const
{
	return m_N0;
}

inline Long Jcmat3Fcomp::n1() const
{
	return m_N1;
}

inline Long Jcmat3Fcomp::n2() const
{
	return m_N2;
}

inline Long Jcmat3Fcomp::step1() const
{
	return m_step1;
}

inline Long Jcmat3Fcomp::step2() const
{
	return m_step2;
}

inline Long Jcmat3Fcomp::step3() const
{
	return m_step3;
}

inline Long Jcmat3Fcomp::size() const
{
	return m_N;
}

inline Fcomp *Jcmat3Fcomp::p() const
{
	return m_p;
}

typedef const Jcmat3Fcomp &Jcmat3Fcomp_O, &Jcmat3Fcomp_IO;

class Jcmat3Comp_c
{
protected:
	const Comp *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Comp_c();
	Jcmat3Comp_c(const Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Comp_c &sli);
	Jcmat3Comp_c &operator=(const Jcmat3Comp_c &) = delete;
	const Comp &operator[](Long_I i) const;
	const Comp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	const Comp *p() const;
};

inline Jcmat3Comp_c::Jcmat3Comp_c() {}

inline Jcmat3Comp_c::Jcmat3Comp_c(const Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Comp_c::set(const Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Comp_c::set(const Jcmat3Comp_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Comp &Jcmat3Comp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Comp &Jcmat3Comp_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Comp_c::n0() const
{
	return m_N0;
}

inline Long Jcmat3Comp_c::n1() const
{
	return m_N1;
}

inline Long Jcmat3Comp_c::n2() const
{
	return m_N2;
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

inline const Comp *Jcmat3Comp_c::p() const
{
	return m_p;
}

typedef const Jcmat3Comp_c &Jcmat3Comp_I;

class Jcmat3Comp
{
protected:
	Comp *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Comp();
	Jcmat3Comp(Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Comp &sli);
	operator Jcmat3Comp_c() const;
	Jcmat3Comp &operator=(const Jcmat3Comp &) = delete;
	Comp &operator[](Long_I i) const;
	Comp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	Comp *p() const;
};

inline Jcmat3Comp::Jcmat3Comp() {}

inline Jcmat3Comp::Jcmat3Comp(Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Comp::set(Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Comp::set(const Jcmat3Comp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Comp::operator Jcmat3Comp_c() const
{
	return *((Jcmat3Comp_c *)this);
}

inline Comp &Jcmat3Comp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline Comp &Jcmat3Comp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Comp::n0() const
{
	return m_N0;
}

inline Long Jcmat3Comp::n1() const
{
	return m_N1;
}

inline Long Jcmat3Comp::n2() const
{
	return m_N2;
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

inline Comp *Jcmat3Comp::p() const
{
	return m_p;
}

typedef const Jcmat3Comp &Jcmat3Comp_O, &Jcmat3Comp_IO;

class Jcmat3Lcomp_c
{
protected:
	const Lcomp *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Lcomp_c();
	Jcmat3Lcomp_c(const Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Lcomp_c &sli);
	Jcmat3Lcomp_c &operator=(const Jcmat3Lcomp_c &) = delete;
	const Lcomp &operator[](Long_I i) const;
	const Lcomp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	const Lcomp *p() const;
};

inline Jcmat3Lcomp_c::Jcmat3Lcomp_c() {}

inline Jcmat3Lcomp_c::Jcmat3Lcomp_c(const Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Lcomp_c::set(const Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Lcomp_c::set(const Jcmat3Lcomp_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Lcomp &Jcmat3Lcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Lcomp &Jcmat3Lcomp_c::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Lcomp_c::n0() const
{
	return m_N0;
}

inline Long Jcmat3Lcomp_c::n1() const
{
	return m_N1;
}

inline Long Jcmat3Lcomp_c::n2() const
{
	return m_N2;
}

inline Long Jcmat3Lcomp_c::step1() const
{
	return m_step1;
}

inline Long Jcmat3Lcomp_c::step2() const
{
	return m_step2;
}

inline Long Jcmat3Lcomp_c::step3() const
{
	return m_step3;
}

inline Long Jcmat3Lcomp_c::size() const
{
	return m_N;
}

inline const Lcomp *Jcmat3Lcomp_c::p() const
{
	return m_p;
}

typedef const Jcmat3Lcomp_c &Jcmat3Lcomp_I;

class Jcmat3Lcomp
{
protected:
	Lcomp *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3Lcomp();
	Jcmat3Lcomp(Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3Lcomp &sli);
	operator Jcmat3Lcomp_c() const;
	Jcmat3Lcomp &operator=(const Jcmat3Lcomp &) = delete;
	Lcomp &operator[](Long_I i) const;
	Lcomp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long step1() const;
	Long step2() const;
	Long step3() const;
	Long size() const;

	Lcomp *p() const;
};

inline Jcmat3Lcomp::Jcmat3Lcomp() {}

inline Jcmat3Lcomp::Jcmat3Lcomp(Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3Lcomp::set(Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3Lcomp::set(const Jcmat3Lcomp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}

inline Jcmat3Lcomp::operator Jcmat3Lcomp_c() const
{
	return *((Jcmat3Lcomp_c *)this);
}

inline Lcomp &Jcmat3Lcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline Lcomp &Jcmat3Lcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
	    SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3Lcomp::n0() const
{
	return m_N0;
}

inline Long Jcmat3Lcomp::n1() const
{
	return m_N1;
}

inline Long Jcmat3Lcomp::n2() const
{
	return m_N2;
}

inline Long Jcmat3Lcomp::step1() const
{
	return m_step1;
}

inline Long Jcmat3Lcomp::step2() const
{
	return m_step2;
}

inline Long Jcmat3Lcomp::step3() const
{
	return m_step3;
}

inline Long Jcmat3Lcomp::size() const
{
	return m_N;
}

inline Lcomp *Jcmat3Lcomp::p() const
{
	return m_p;
}

typedef const Jcmat3Lcomp &Jcmat3Lcomp_O, &Jcmat3Lcomp_IO;




#ifdef SLS_USE_INT_AS_LONG
typedef Jcmat3Int Jcmat3Long;
typedef Jcmat3Int_c Jcmat3Long_c;
#else
typedef Jcmat3Llong Jcmat3Long;
typedef Jcmat3Llong_c Jcmat3Long_c;
#endif
typedef const Jcmat3Long_c &Jcmat3Long_I;
typedef const Jcmat3Long &Jcmat3Long_O, &Jcmat3Long_IO;

} // namespace slisc
