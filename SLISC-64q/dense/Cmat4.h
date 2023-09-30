// Cmat container
#pragma once
#include "../dense/Vec.h"

namespace slisc {
class Cmat4Char : public VecChar
{
protected:
	typedef VecChar Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Char(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Char(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Char(const Cmat4Char &rhs);   // copy constructor
	Cmat4Char(Cmat4Char &&rhs);   // move constructor
	Cmat4Char &operator=(const Cmat4Char &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Char &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Char &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Char::Cmat4Char(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Char::Cmat4Char(const Cmat4Char &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Char::Cmat4Char(Cmat4Char &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Char &Cmat4Char::operator=(const Cmat4Char &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Char::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Char::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Char resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Char::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Char reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Char &Cmat4Char::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Char &Cmat4Char::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Char::n0() const {
	return m_N0;
}

inline Long Cmat4Char::n1() const {
	return m_N1;
}

inline Long Cmat4Char::n2() const {
	return m_N2;
}

inline Long Cmat4Char::n3() const {
	return m_N3;
}

typedef const Cmat4Char &Cmat4Char_I;
typedef Cmat4Char &Cmat4Char_O, &Cmat4Char_IO;


class Cmat4Int : public VecInt
{
protected:
	typedef VecInt Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Int(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Int(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Int(const Cmat4Int &rhs);   // copy constructor
	Cmat4Int(Cmat4Int &&rhs);   // move constructor
	Cmat4Int &operator=(const Cmat4Int &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Int &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Int &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Int::Cmat4Int(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Int::Cmat4Int(const Cmat4Int &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Int::Cmat4Int(Cmat4Int &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Int &Cmat4Int::operator=(const Cmat4Int &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Int::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Int::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Int resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Int::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Int reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Int &Cmat4Int::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Int &Cmat4Int::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Int::n0() const {
	return m_N0;
}

inline Long Cmat4Int::n1() const {
	return m_N1;
}

inline Long Cmat4Int::n2() const {
	return m_N2;
}

inline Long Cmat4Int::n3() const {
	return m_N3;
}

typedef const Cmat4Int &Cmat4Int_I;
typedef Cmat4Int &Cmat4Int_O, &Cmat4Int_IO;


class Cmat4Llong : public VecLlong
{
protected:
	typedef VecLlong Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Llong(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Llong(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Llong(const Cmat4Llong &rhs);   // copy constructor
	Cmat4Llong(Cmat4Llong &&rhs);   // move constructor
	Cmat4Llong &operator=(const Cmat4Llong &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Llong &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Llong &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Llong::Cmat4Llong(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Llong::Cmat4Llong(const Cmat4Llong &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Llong::Cmat4Llong(Cmat4Llong &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Llong &Cmat4Llong::operator=(const Cmat4Llong &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Llong::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Llong::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Llong resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Llong::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Llong reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Llong &Cmat4Llong::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Llong &Cmat4Llong::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Llong::n0() const {
	return m_N0;
}

inline Long Cmat4Llong::n1() const {
	return m_N1;
}

inline Long Cmat4Llong::n2() const {
	return m_N2;
}

inline Long Cmat4Llong::n3() const {
	return m_N3;
}

typedef const Cmat4Llong &Cmat4Llong_I;
typedef Cmat4Llong &Cmat4Llong_O, &Cmat4Llong_IO;


class Cmat4Float : public VecFloat
{
protected:
	typedef VecFloat Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Float(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Float(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Float(const Cmat4Float &rhs);   // copy constructor
	Cmat4Float(Cmat4Float &&rhs);   // move constructor
	Cmat4Float &operator=(const Cmat4Float &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Float &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Float &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Float::Cmat4Float(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Float::Cmat4Float(const Cmat4Float &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Float::Cmat4Float(Cmat4Float &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Float &Cmat4Float::operator=(const Cmat4Float &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Float::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Float::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Float resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Float::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Float reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Float &Cmat4Float::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Float &Cmat4Float::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Float::n0() const {
	return m_N0;
}

inline Long Cmat4Float::n1() const {
	return m_N1;
}

inline Long Cmat4Float::n2() const {
	return m_N2;
}

inline Long Cmat4Float::n3() const {
	return m_N3;
}

typedef const Cmat4Float &Cmat4Float_I;
typedef Cmat4Float &Cmat4Float_O, &Cmat4Float_IO;


class Cmat4Doub : public VecDoub
{
protected:
	typedef VecDoub Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Doub(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Doub(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Doub(const Cmat4Doub &rhs);   // copy constructor
	Cmat4Doub(Cmat4Doub &&rhs);   // move constructor
	Cmat4Doub &operator=(const Cmat4Doub &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Doub &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Doub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Doub::Cmat4Doub(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Doub::Cmat4Doub(const Cmat4Doub &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Doub::Cmat4Doub(Cmat4Doub &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Doub &Cmat4Doub::operator=(const Cmat4Doub &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Doub::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Doub::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Doub resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Doub::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Doub reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Doub &Cmat4Doub::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Doub &Cmat4Doub::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Doub::n0() const {
	return m_N0;
}

inline Long Cmat4Doub::n1() const {
	return m_N1;
}

inline Long Cmat4Doub::n2() const {
	return m_N2;
}

inline Long Cmat4Doub::n3() const {
	return m_N3;
}

typedef const Cmat4Doub &Cmat4Doub_I;
typedef Cmat4Doub &Cmat4Doub_O, &Cmat4Doub_IO;


class Cmat4Ldoub : public VecLdoub
{
protected:
	typedef VecLdoub Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Ldoub(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Ldoub(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Ldoub(const Cmat4Ldoub &rhs);   // copy constructor
	Cmat4Ldoub(Cmat4Ldoub &&rhs);   // move constructor
	Cmat4Ldoub &operator=(const Cmat4Ldoub &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Ldoub &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Ldoub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Ldoub::Cmat4Ldoub(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Ldoub::Cmat4Ldoub(const Cmat4Ldoub &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Ldoub::Cmat4Ldoub(Cmat4Ldoub &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Ldoub &Cmat4Ldoub::operator=(const Cmat4Ldoub &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Ldoub::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Ldoub::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Ldoub resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Ldoub::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Ldoub reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Ldoub &Cmat4Ldoub::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Ldoub &Cmat4Ldoub::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Ldoub::n0() const {
	return m_N0;
}

inline Long Cmat4Ldoub::n1() const {
	return m_N1;
}

inline Long Cmat4Ldoub::n2() const {
	return m_N2;
}

inline Long Cmat4Ldoub::n3() const {
	return m_N3;
}

typedef const Cmat4Ldoub &Cmat4Ldoub_I;
typedef Cmat4Ldoub &Cmat4Ldoub_O, &Cmat4Ldoub_IO;


class Cmat4Qdoub : public VecQdoub
{
protected:
	typedef VecQdoub Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Qdoub(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Qdoub(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Qdoub(const Cmat4Qdoub &rhs);   // copy constructor
	Cmat4Qdoub(Cmat4Qdoub &&rhs);   // move constructor
	Cmat4Qdoub &operator=(const Cmat4Qdoub &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Qdoub &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Qdoub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Qdoub::Cmat4Qdoub(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Qdoub::Cmat4Qdoub(const Cmat4Qdoub &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Qdoub::Cmat4Qdoub(Cmat4Qdoub &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Qdoub &Cmat4Qdoub::operator=(const Cmat4Qdoub &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Qdoub::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Qdoub::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Qdoub resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Qdoub::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Qdoub reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Qdoub &Cmat4Qdoub::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Qdoub &Cmat4Qdoub::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Qdoub::n0() const {
	return m_N0;
}

inline Long Cmat4Qdoub::n1() const {
	return m_N1;
}

inline Long Cmat4Qdoub::n2() const {
	return m_N2;
}

inline Long Cmat4Qdoub::n3() const {
	return m_N3;
}

typedef const Cmat4Qdoub &Cmat4Qdoub_I;
typedef Cmat4Qdoub &Cmat4Qdoub_O, &Cmat4Qdoub_IO;


class Cmat4Fcomp : public VecFcomp
{
protected:
	typedef VecFcomp Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Fcomp(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Fcomp(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Fcomp(const Cmat4Fcomp &rhs);   // copy constructor
	Cmat4Fcomp(Cmat4Fcomp &&rhs);   // move constructor
	Cmat4Fcomp &operator=(const Cmat4Fcomp &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Fcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Fcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Fcomp::Cmat4Fcomp(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Fcomp::Cmat4Fcomp(const Cmat4Fcomp &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Fcomp::Cmat4Fcomp(Cmat4Fcomp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Fcomp &Cmat4Fcomp::operator=(const Cmat4Fcomp &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Fcomp::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Fcomp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Fcomp resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Fcomp::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Fcomp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Fcomp &Cmat4Fcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Fcomp &Cmat4Fcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Fcomp::n0() const {
	return m_N0;
}

inline Long Cmat4Fcomp::n1() const {
	return m_N1;
}

inline Long Cmat4Fcomp::n2() const {
	return m_N2;
}

inline Long Cmat4Fcomp::n3() const {
	return m_N3;
}

typedef const Cmat4Fcomp &Cmat4Fcomp_I;
typedef Cmat4Fcomp &Cmat4Fcomp_O, &Cmat4Fcomp_IO;


class Cmat4Comp : public VecComp
{
protected:
	typedef VecComp Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Comp(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Comp(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Comp(const Cmat4Comp &rhs);   // copy constructor
	Cmat4Comp(Cmat4Comp &&rhs);   // move constructor
	Cmat4Comp &operator=(const Cmat4Comp &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Comp &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Comp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Comp::Cmat4Comp(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Comp::Cmat4Comp(const Cmat4Comp &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Comp::Cmat4Comp(Cmat4Comp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Comp &Cmat4Comp::operator=(const Cmat4Comp &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Comp::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Comp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Comp resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Comp::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Comp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Comp &Cmat4Comp::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Comp &Cmat4Comp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Comp::n0() const {
	return m_N0;
}

inline Long Cmat4Comp::n1() const {
	return m_N1;
}

inline Long Cmat4Comp::n2() const {
	return m_N2;
}

inline Long Cmat4Comp::n3() const {
	return m_N3;
}

typedef const Cmat4Comp &Cmat4Comp_I;
typedef Cmat4Comp &Cmat4Comp_O, &Cmat4Comp_IO;


class Cmat4Lcomp : public VecLcomp
{
protected:
	typedef VecLcomp Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Lcomp(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Lcomp(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Lcomp(const Cmat4Lcomp &rhs);   // copy constructor
	Cmat4Lcomp(Cmat4Lcomp &&rhs);   // move constructor
	Cmat4Lcomp &operator=(const Cmat4Lcomp &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Lcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Lcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Lcomp::Cmat4Lcomp(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Lcomp::Cmat4Lcomp(const Cmat4Lcomp &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Lcomp::Cmat4Lcomp(Cmat4Lcomp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Lcomp &Cmat4Lcomp::operator=(const Cmat4Lcomp &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Lcomp::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Lcomp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Lcomp resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Lcomp::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Lcomp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Lcomp &Cmat4Lcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Lcomp &Cmat4Lcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Lcomp::n0() const {
	return m_N0;
}

inline Long Cmat4Lcomp::n1() const {
	return m_N1;
}

inline Long Cmat4Lcomp::n2() const {
	return m_N2;
}

inline Long Cmat4Lcomp::n3() const {
	return m_N3;
}

typedef const Cmat4Lcomp &Cmat4Lcomp_I;
typedef Cmat4Lcomp &Cmat4Lcomp_O, &Cmat4Lcomp_IO;


class Cmat4Qcomp : public VecQcomp
{
protected:
	typedef VecQcomp Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Qcomp(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Qcomp(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Qcomp(const Cmat4Qcomp &rhs);   // copy constructor
	Cmat4Qcomp(Cmat4Qcomp &&rhs);   // move constructor
	Cmat4Qcomp &operator=(const Cmat4Qcomp &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Qcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Qcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Qcomp::Cmat4Qcomp(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Qcomp::Cmat4Qcomp(const Cmat4Qcomp &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Qcomp::Cmat4Qcomp(Cmat4Qcomp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Qcomp &Cmat4Qcomp::operator=(const Cmat4Qcomp &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Qcomp::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Qcomp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Qcomp resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Qcomp::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Qcomp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Qcomp &Cmat4Qcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Qcomp &Cmat4Qcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Qcomp::n0() const {
	return m_N0;
}

inline Long Cmat4Qcomp::n1() const {
	return m_N1;
}

inline Long Cmat4Qcomp::n2() const {
	return m_N2;
}

inline Long Cmat4Qcomp::n3() const {
	return m_N3;
}

typedef const Cmat4Qcomp &Cmat4Qcomp_I;
typedef Cmat4Qcomp &Cmat4Qcomp_O, &Cmat4Qcomp_IO;


class Cmat4Fimag : public VecFimag
{
protected:
	typedef VecFimag Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Fimag(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Fimag(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Fimag(const Cmat4Fimag &rhs);   // copy constructor
	Cmat4Fimag(Cmat4Fimag &&rhs);   // move constructor
	Cmat4Fimag &operator=(const Cmat4Fimag &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Fimag &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Fimag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Fimag::Cmat4Fimag(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Fimag::Cmat4Fimag(const Cmat4Fimag &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Fimag::Cmat4Fimag(Cmat4Fimag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Fimag &Cmat4Fimag::operator=(const Cmat4Fimag &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Fimag::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Fimag::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Fimag resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Fimag::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Fimag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Fimag &Cmat4Fimag::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Fimag &Cmat4Fimag::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Fimag::n0() const {
	return m_N0;
}

inline Long Cmat4Fimag::n1() const {
	return m_N1;
}

inline Long Cmat4Fimag::n2() const {
	return m_N2;
}

inline Long Cmat4Fimag::n3() const {
	return m_N3;
}

typedef const Cmat4Fimag &Cmat4Fimag_I;
typedef Cmat4Fimag &Cmat4Fimag_O, &Cmat4Fimag_IO;


class Cmat4Imag : public VecImag
{
protected:
	typedef VecImag Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Imag(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Imag(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Imag(const Cmat4Imag &rhs);   // copy constructor
	Cmat4Imag(Cmat4Imag &&rhs);   // move constructor
	Cmat4Imag &operator=(const Cmat4Imag &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Imag &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Imag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Imag::Cmat4Imag(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Imag::Cmat4Imag(const Cmat4Imag &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Imag::Cmat4Imag(Cmat4Imag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Imag &Cmat4Imag::operator=(const Cmat4Imag &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Imag::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Imag::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Imag resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Imag::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Imag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Imag &Cmat4Imag::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Imag &Cmat4Imag::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Imag::n0() const {
	return m_N0;
}

inline Long Cmat4Imag::n1() const {
	return m_N1;
}

inline Long Cmat4Imag::n2() const {
	return m_N2;
}

inline Long Cmat4Imag::n3() const {
	return m_N3;
}

typedef const Cmat4Imag &Cmat4Imag_I;
typedef Cmat4Imag &Cmat4Imag_O, &Cmat4Imag_IO;


class Cmat4Limag : public VecLimag
{
protected:
	typedef VecLimag Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Limag(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Limag(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Limag(const Cmat4Limag &rhs);   // copy constructor
	Cmat4Limag(Cmat4Limag &&rhs);   // move constructor
	Cmat4Limag &operator=(const Cmat4Limag &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Limag &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Limag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Limag::Cmat4Limag(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Limag::Cmat4Limag(const Cmat4Limag &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Limag::Cmat4Limag(Cmat4Limag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Limag &Cmat4Limag::operator=(const Cmat4Limag &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Limag::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Limag::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Limag resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Limag::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Limag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Limag &Cmat4Limag::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Limag &Cmat4Limag::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Limag::n0() const {
	return m_N0;
}

inline Long Cmat4Limag::n1() const {
	return m_N1;
}

inline Long Cmat4Limag::n2() const {
	return m_N2;
}

inline Long Cmat4Limag::n3() const {
	return m_N3;
}

typedef const Cmat4Limag &Cmat4Limag_I;
typedef Cmat4Limag &Cmat4Limag_O, &Cmat4Limag_IO;


class Cmat4Qimag : public VecQimag
{
protected:
	typedef VecQimag Base;
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Cmat4Qimag(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
	Cmat4Qimag(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Cmat4Qimag(const Cmat4Qimag &rhs);   // copy constructor
	Cmat4Qimag(Cmat4Qimag &&rhs);   // move constructor
	Cmat4Qimag &operator=(const Cmat4Qimag &rhs); // copy assignment
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void resize(Long_I N);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Qimag &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Qimag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;
};

inline Cmat4Qimag::Cmat4Qimag(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: Base(N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

// Copy constructor
inline Cmat4Qimag::Cmat4Qimag(const Cmat4Qimag &rhs): Base(rhs),
	m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat4Qimag::Cmat4Qimag(Cmat4Qimag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3) {}

inline Cmat4Qimag &Cmat4Qimag::operator=(const Cmat4Qimag &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
	return *this;
}

inline void Cmat4Qimag::resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
		Base::resize(N0*N1*N2*N3);
		m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
	}
}

inline void Cmat4Qimag::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1*m_N2*m_N3) {
		stringstream ss;
		ss  << "Cmat4Qimag resizing from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void Cmat4Qimag::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 < m_N) {
		stringstream ss;
		ss  << "Cmat4Qimag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << ") , with " << m_N << "allocated elements, to (" << m_N0 << ',' << m_N1
			<< ',' << m_N2 << ',' << m_N3 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
	m_N2 = N2; m_N3 = N3;
}

inline Qimag &Cmat4Qimag::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Qimag &Cmat4Qimag::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
		k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	Long N1N2 = m_N0 * m_N1;
	return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Qimag::n0() const {
	return m_N0;
}

inline Long Cmat4Qimag::n1() const {
	return m_N1;
}

inline Long Cmat4Qimag::n2() const {
	return m_N2;
}

inline Long Cmat4Qimag::n3() const {
	return m_N3;
}

typedef const Cmat4Qimag &Cmat4Qimag_I;
typedef Cmat4Qimag &Cmat4Qimag_O, &Cmat4Qimag_IO;



#ifdef SLS_USE_INT_AS_LONG
typedef Cmat4Int Cmat4Long;
#else
typedef Cmat4Llong Cmat4Long;
#endif
typedef const Cmat4Long &Cmat4Long_I;
typedef Cmat4Long &Cmat4Long_O, &Cmat4Long_IO;

} // namespace slisc
