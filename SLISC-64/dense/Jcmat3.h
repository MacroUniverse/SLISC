#pragma once
#include "../global.h"
// "C" means lower level const

namespace slisc {
class Jcmat3CharC
{
protected:
	const Char *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3CharC();
	Jcmat3CharC(const Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3CharC &sli);
	Jcmat3CharC &operator=(const Jcmat3CharC &) = delete;
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

inline Jcmat3CharC::Jcmat3CharC() {}

inline Jcmat3CharC::Jcmat3CharC(const Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3CharC::set(const Char *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3CharC::set(const Jcmat3CharC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Char &Jcmat3CharC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Char &Jcmat3CharC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3CharC::n0() const
{
	return m_N0;
}

inline Long Jcmat3CharC::n1() const
{
	return m_N1;
}

inline Long Jcmat3CharC::n2() const
{
	return m_N2;
}

inline Long Jcmat3CharC::step1() const
{
	return m_step1;
}

inline Long Jcmat3CharC::step2() const
{
	return m_step2;
}

inline Long Jcmat3CharC::step3() const
{
	return m_step3;
}

inline Long Jcmat3CharC::size() const
{
	return m_N;
}

inline const Char *Jcmat3CharC::p() const
{
	return m_p;
}

typedef const Jcmat3CharC &Jcmat3Char_I;

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
	operator Jcmat3CharC() const;
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

inline Jcmat3Char::operator Jcmat3CharC() const
{
	return *((Jcmat3CharC *)this);
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

class Jcmat3IntC
{
protected:
	const Int *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3IntC();
	Jcmat3IntC(const Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3IntC &sli);
	Jcmat3IntC &operator=(const Jcmat3IntC &) = delete;
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

inline Jcmat3IntC::Jcmat3IntC() {}

inline Jcmat3IntC::Jcmat3IntC(const Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3IntC::set(const Int *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3IntC::set(const Jcmat3IntC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Int &Jcmat3IntC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Int &Jcmat3IntC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3IntC::n0() const
{
	return m_N0;
}

inline Long Jcmat3IntC::n1() const
{
	return m_N1;
}

inline Long Jcmat3IntC::n2() const
{
	return m_N2;
}

inline Long Jcmat3IntC::step1() const
{
	return m_step1;
}

inline Long Jcmat3IntC::step2() const
{
	return m_step2;
}

inline Long Jcmat3IntC::step3() const
{
	return m_step3;
}

inline Long Jcmat3IntC::size() const
{
	return m_N;
}

inline const Int *Jcmat3IntC::p() const
{
	return m_p;
}

typedef const Jcmat3IntC &Jcmat3Int_I;

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
	operator Jcmat3IntC() const;
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

inline Jcmat3Int::operator Jcmat3IntC() const
{
	return *((Jcmat3IntC *)this);
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

class Jcmat3LlongC
{
protected:
	const Llong *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3LlongC();
	Jcmat3LlongC(const Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3LlongC &sli);
	Jcmat3LlongC &operator=(const Jcmat3LlongC &) = delete;
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

inline Jcmat3LlongC::Jcmat3LlongC() {}

inline Jcmat3LlongC::Jcmat3LlongC(const Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3LlongC::set(const Llong *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3LlongC::set(const Jcmat3LlongC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Llong &Jcmat3LlongC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Llong &Jcmat3LlongC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3LlongC::n0() const
{
	return m_N0;
}

inline Long Jcmat3LlongC::n1() const
{
	return m_N1;
}

inline Long Jcmat3LlongC::n2() const
{
	return m_N2;
}

inline Long Jcmat3LlongC::step1() const
{
	return m_step1;
}

inline Long Jcmat3LlongC::step2() const
{
	return m_step2;
}

inline Long Jcmat3LlongC::step3() const
{
	return m_step3;
}

inline Long Jcmat3LlongC::size() const
{
	return m_N;
}

inline const Llong *Jcmat3LlongC::p() const
{
	return m_p;
}

typedef const Jcmat3LlongC &Jcmat3Llong_I;

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
	operator Jcmat3LlongC() const;
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

inline Jcmat3Llong::operator Jcmat3LlongC() const
{
	return *((Jcmat3LlongC *)this);
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

class Jcmat3FloatC
{
protected:
	const Float *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3FloatC();
	Jcmat3FloatC(const Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3FloatC &sli);
	Jcmat3FloatC &operator=(const Jcmat3FloatC &) = delete;
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

inline Jcmat3FloatC::Jcmat3FloatC() {}

inline Jcmat3FloatC::Jcmat3FloatC(const Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3FloatC::set(const Float *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3FloatC::set(const Jcmat3FloatC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Float &Jcmat3FloatC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Float &Jcmat3FloatC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3FloatC::n0() const
{
	return m_N0;
}

inline Long Jcmat3FloatC::n1() const
{
	return m_N1;
}

inline Long Jcmat3FloatC::n2() const
{
	return m_N2;
}

inline Long Jcmat3FloatC::step1() const
{
	return m_step1;
}

inline Long Jcmat3FloatC::step2() const
{
	return m_step2;
}

inline Long Jcmat3FloatC::step3() const
{
	return m_step3;
}

inline Long Jcmat3FloatC::size() const
{
	return m_N;
}

inline const Float *Jcmat3FloatC::p() const
{
	return m_p;
}

typedef const Jcmat3FloatC &Jcmat3Float_I;

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
	operator Jcmat3FloatC() const;
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

inline Jcmat3Float::operator Jcmat3FloatC() const
{
	return *((Jcmat3FloatC *)this);
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

class Jcmat3DoubC
{
protected:
	const Doub *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3DoubC();
	Jcmat3DoubC(const Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3DoubC &sli);
	Jcmat3DoubC &operator=(const Jcmat3DoubC &) = delete;
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

inline Jcmat3DoubC::Jcmat3DoubC() {}

inline Jcmat3DoubC::Jcmat3DoubC(const Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3DoubC::set(const Doub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3DoubC::set(const Jcmat3DoubC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Doub &Jcmat3DoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Doub &Jcmat3DoubC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3DoubC::n0() const
{
	return m_N0;
}

inline Long Jcmat3DoubC::n1() const
{
	return m_N1;
}

inline Long Jcmat3DoubC::n2() const
{
	return m_N2;
}

inline Long Jcmat3DoubC::step1() const
{
	return m_step1;
}

inline Long Jcmat3DoubC::step2() const
{
	return m_step2;
}

inline Long Jcmat3DoubC::step3() const
{
	return m_step3;
}

inline Long Jcmat3DoubC::size() const
{
	return m_N;
}

inline const Doub *Jcmat3DoubC::p() const
{
	return m_p;
}

typedef const Jcmat3DoubC &Jcmat3Doub_I;

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
	operator Jcmat3DoubC() const;
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

inline Jcmat3Doub::operator Jcmat3DoubC() const
{
	return *((Jcmat3DoubC *)this);
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

class Jcmat3LdoubC
{
protected:
	const Ldoub *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3LdoubC();
	Jcmat3LdoubC(const Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3LdoubC &sli);
	Jcmat3LdoubC &operator=(const Jcmat3LdoubC &) = delete;
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

inline Jcmat3LdoubC::Jcmat3LdoubC() {}

inline Jcmat3LdoubC::Jcmat3LdoubC(const Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3LdoubC::set(const Ldoub *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3LdoubC::set(const Jcmat3LdoubC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Ldoub &Jcmat3LdoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Ldoub &Jcmat3LdoubC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3LdoubC::n0() const
{
	return m_N0;
}

inline Long Jcmat3LdoubC::n1() const
{
	return m_N1;
}

inline Long Jcmat3LdoubC::n2() const
{
	return m_N2;
}

inline Long Jcmat3LdoubC::step1() const
{
	return m_step1;
}

inline Long Jcmat3LdoubC::step2() const
{
	return m_step2;
}

inline Long Jcmat3LdoubC::step3() const
{
	return m_step3;
}

inline Long Jcmat3LdoubC::size() const
{
	return m_N;
}

inline const Ldoub *Jcmat3LdoubC::p() const
{
	return m_p;
}

typedef const Jcmat3LdoubC &Jcmat3Ldoub_I;

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
	operator Jcmat3LdoubC() const;
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

inline Jcmat3Ldoub::operator Jcmat3LdoubC() const
{
	return *((Jcmat3LdoubC *)this);
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



class Jcmat3FcompC
{
protected:
	const Fcomp *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3FcompC();
	Jcmat3FcompC(const Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3FcompC &sli);
	Jcmat3FcompC &operator=(const Jcmat3FcompC &) = delete;
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

inline Jcmat3FcompC::Jcmat3FcompC() {}

inline Jcmat3FcompC::Jcmat3FcompC(const Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3FcompC::set(const Fcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3FcompC::set(const Jcmat3FcompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Fcomp &Jcmat3FcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Fcomp &Jcmat3FcompC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3FcompC::n0() const
{
	return m_N0;
}

inline Long Jcmat3FcompC::n1() const
{
	return m_N1;
}

inline Long Jcmat3FcompC::n2() const
{
	return m_N2;
}

inline Long Jcmat3FcompC::step1() const
{
	return m_step1;
}

inline Long Jcmat3FcompC::step2() const
{
	return m_step2;
}

inline Long Jcmat3FcompC::step3() const
{
	return m_step3;
}

inline Long Jcmat3FcompC::size() const
{
	return m_N;
}

inline const Fcomp *Jcmat3FcompC::p() const
{
	return m_p;
}

typedef const Jcmat3FcompC &Jcmat3Fcomp_I;

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
	operator Jcmat3FcompC() const;
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

inline Jcmat3Fcomp::operator Jcmat3FcompC() const
{
	return *((Jcmat3FcompC *)this);
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

class Jcmat3CompC
{
protected:
	const Comp *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3CompC();
	Jcmat3CompC(const Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3CompC &sli);
	Jcmat3CompC &operator=(const Jcmat3CompC &) = delete;
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

inline Jcmat3CompC::Jcmat3CompC() {}

inline Jcmat3CompC::Jcmat3CompC(const Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3CompC::set(const Comp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3CompC::set(const Jcmat3CompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Comp &Jcmat3CompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Comp &Jcmat3CompC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3CompC::n0() const
{
	return m_N0;
}

inline Long Jcmat3CompC::n1() const
{
	return m_N1;
}

inline Long Jcmat3CompC::n2() const
{
	return m_N2;
}

inline Long Jcmat3CompC::step1() const
{
	return m_step1;
}

inline Long Jcmat3CompC::step2() const
{
	return m_step2;
}

inline Long Jcmat3CompC::step3() const
{
	return m_step3;
}

inline Long Jcmat3CompC::size() const
{
	return m_N;
}

inline const Comp *Jcmat3CompC::p() const
{
	return m_p;
}

typedef const Jcmat3CompC &Jcmat3Comp_I;

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
	operator Jcmat3CompC() const;
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

inline Jcmat3Comp::operator Jcmat3CompC() const
{
	return *((Jcmat3CompC *)this);
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

class Jcmat3LcompC
{
protected:
	const Lcomp *m_p;
	Long m_N;
	Long m_N0, m_N1, m_N2;
	Long m_step1, m_step2, m_step3; // a(i,j,k) = m_p + m_step1*i + m_step2*j + m_step*k
public:
	Jcmat3LcompC();
	Jcmat3LcompC(const Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3);
	void set(const Jcmat3LcompC &sli);
	Jcmat3LcompC &operator=(const Jcmat3LcompC &) = delete;
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

inline Jcmat3LcompC::Jcmat3LcompC() {}

inline Jcmat3LcompC::Jcmat3LcompC(const Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
	: m_p(p), m_N0(N0), m_N1(N1), m_N2(N2), m_N(N0*N1*N2), m_step1(step1), m_step2(step2), m_step3(step3)
{}

inline void Jcmat3LcompC::set(const Lcomp *p, Long_I N0, Long_I N1, Long_I N2, Long_I step1, Long_I step2, Long_I step3)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N2 = N2;
	m_step1 = step1; m_step2 = step2; m_step3 = step3;
	m_N = N0 * N1 * N2;
}

inline void Jcmat3LcompC::set(const Jcmat3LcompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2; m_step1 = sli.m_step1; m_step2 = sli.m_step2; m_step3 = sli.m_step3;
}


inline const Lcomp &Jcmat3LcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("out of bound!");
#endif
	Long N1N2 = m_N0 * m_N1;
	Long i2 = i % N1N2;
	return operator()(i2 % m_N0, i2 / m_N0, i / N1N2);
}

inline const Lcomp &Jcmat3LcompC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k > m_N2)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[m_step1 * i + m_step2 * j + m_step3 * k];
}

inline Long Jcmat3LcompC::n0() const
{
	return m_N0;
}

inline Long Jcmat3LcompC::n1() const
{
	return m_N1;
}

inline Long Jcmat3LcompC::n2() const
{
	return m_N2;
}

inline Long Jcmat3LcompC::step1() const
{
	return m_step1;
}

inline Long Jcmat3LcompC::step2() const
{
	return m_step2;
}

inline Long Jcmat3LcompC::step3() const
{
	return m_step3;
}

inline Long Jcmat3LcompC::size() const
{
	return m_N;
}

inline const Lcomp *Jcmat3LcompC::p() const
{
	return m_p;
}

typedef const Jcmat3LcompC &Jcmat3Lcomp_I;

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
	operator Jcmat3LcompC() const;
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

inline Jcmat3Lcomp::operator Jcmat3LcompC() const
{
	return *((Jcmat3LcompC *)this);
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
typedef Jcmat3IntC Jcmat3LongC;
#else
typedef Jcmat3Llong Jcmat3Long;
typedef Jcmat3LlongC Jcmat3LongC;
#endif
typedef const Jcmat3LongC &Jcmat3Long_I;
typedef const Jcmat3Long &Jcmat3Long_O, &Jcmat3Long_IO;

} // namespace slisc
