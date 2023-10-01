// Cmat container
#pragma once
#include "../dense/Vec.h"
#include "Scmat4.h"

namespace slisc {
class Cmat4Char : protected VecChar
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Char &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Char &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4CharC&() const;
	operator const Scmat4Char&();
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

inline void Cmat4Char::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Char::operator const Scmat4CharC&() const {
	return reinterpret_cast<const Scmat4CharC&>(*this);
}

inline Cmat4Char::operator const Scmat4Char&() {
	return reinterpret_cast<const Scmat4Char&>(*this);
}

typedef const Cmat4Char &Cmat4Char_I;
typedef Cmat4Char &Cmat4Char_O, &Cmat4Char_IO;


class Cmat4Int : protected VecInt
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Int &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Int &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4IntC&() const;
	operator const Scmat4Int&();
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

inline void Cmat4Int::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Int::operator const Scmat4IntC&() const {
	return reinterpret_cast<const Scmat4IntC&>(*this);
}

inline Cmat4Int::operator const Scmat4Int&() {
	return reinterpret_cast<const Scmat4Int&>(*this);
}

typedef const Cmat4Int &Cmat4Int_I;
typedef Cmat4Int &Cmat4Int_O, &Cmat4Int_IO;


class Cmat4Llong : protected VecLlong
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Llong &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Llong &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4LlongC&() const;
	operator const Scmat4Llong&();
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

inline void Cmat4Llong::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Llong::operator const Scmat4LlongC&() const {
	return reinterpret_cast<const Scmat4LlongC&>(*this);
}

inline Cmat4Llong::operator const Scmat4Llong&() {
	return reinterpret_cast<const Scmat4Llong&>(*this);
}

typedef const Cmat4Llong &Cmat4Llong_I;
typedef Cmat4Llong &Cmat4Llong_O, &Cmat4Llong_IO;


class Cmat4Float : protected VecFloat
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Float &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Float &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4FloatC&() const;
	operator const Scmat4Float&();
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

inline void Cmat4Float::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Float::operator const Scmat4FloatC&() const {
	return reinterpret_cast<const Scmat4FloatC&>(*this);
}

inline Cmat4Float::operator const Scmat4Float&() {
	return reinterpret_cast<const Scmat4Float&>(*this);
}

typedef const Cmat4Float &Cmat4Float_I;
typedef Cmat4Float &Cmat4Float_O, &Cmat4Float_IO;


class Cmat4Doub : protected VecDoub
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Doub &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Doub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4DoubC&() const;
	operator const Scmat4Doub&();
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

inline void Cmat4Doub::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Doub::operator const Scmat4DoubC&() const {
	return reinterpret_cast<const Scmat4DoubC&>(*this);
}

inline Cmat4Doub::operator const Scmat4Doub&() {
	return reinterpret_cast<const Scmat4Doub&>(*this);
}

typedef const Cmat4Doub &Cmat4Doub_I;
typedef Cmat4Doub &Cmat4Doub_O, &Cmat4Doub_IO;


class Cmat4Ldoub : protected VecLdoub
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Ldoub &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Ldoub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4LdoubC&() const;
	operator const Scmat4Ldoub&();
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

inline void Cmat4Ldoub::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Ldoub::operator const Scmat4LdoubC&() const {
	return reinterpret_cast<const Scmat4LdoubC&>(*this);
}

inline Cmat4Ldoub::operator const Scmat4Ldoub&() {
	return reinterpret_cast<const Scmat4Ldoub&>(*this);
}

typedef const Cmat4Ldoub &Cmat4Ldoub_I;
typedef Cmat4Ldoub &Cmat4Ldoub_O, &Cmat4Ldoub_IO;



class Cmat4Fcomp : protected VecFcomp
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Fcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Fcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4FcompC&() const;
	operator const Scmat4Fcomp&();
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

inline void Cmat4Fcomp::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Fcomp::operator const Scmat4FcompC&() const {
	return reinterpret_cast<const Scmat4FcompC&>(*this);
}

inline Cmat4Fcomp::operator const Scmat4Fcomp&() {
	return reinterpret_cast<const Scmat4Fcomp&>(*this);
}

typedef const Cmat4Fcomp &Cmat4Fcomp_I;
typedef Cmat4Fcomp &Cmat4Fcomp_O, &Cmat4Fcomp_IO;


class Cmat4Comp : protected VecComp
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Comp &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Comp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4CompC&() const;
	operator const Scmat4Comp&();
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

inline void Cmat4Comp::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Comp::operator const Scmat4CompC&() const {
	return reinterpret_cast<const Scmat4CompC&>(*this);
}

inline Cmat4Comp::operator const Scmat4Comp&() {
	return reinterpret_cast<const Scmat4Comp&>(*this);
}

typedef const Cmat4Comp &Cmat4Comp_I;
typedef Cmat4Comp &Cmat4Comp_O, &Cmat4Comp_IO;


class Cmat4Lcomp : protected VecLcomp
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Lcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Lcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4LcompC&() const;
	operator const Scmat4Lcomp&();
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

inline void Cmat4Lcomp::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Lcomp::operator const Scmat4LcompC&() const {
	return reinterpret_cast<const Scmat4LcompC&>(*this);
}

inline Cmat4Lcomp::operator const Scmat4Lcomp&() {
	return reinterpret_cast<const Scmat4Lcomp&>(*this);
}

typedef const Cmat4Lcomp &Cmat4Lcomp_I;
typedef Cmat4Lcomp &Cmat4Lcomp_O, &Cmat4Lcomp_IO;



class Cmat4Fimag : protected VecFimag
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Fimag &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Fimag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4FimagC&() const;
	operator const Scmat4Fimag&();
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

inline void Cmat4Fimag::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Fimag::operator const Scmat4FimagC&() const {
	return reinterpret_cast<const Scmat4FimagC&>(*this);
}

inline Cmat4Fimag::operator const Scmat4Fimag&() {
	return reinterpret_cast<const Scmat4Fimag&>(*this);
}

typedef const Cmat4Fimag &Cmat4Fimag_I;
typedef Cmat4Fimag &Cmat4Fimag_O, &Cmat4Fimag_IO;


class Cmat4Imag : protected VecImag
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Imag &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Imag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4ImagC&() const;
	operator const Scmat4Imag&();
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

inline void Cmat4Imag::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Imag::operator const Scmat4ImagC&() const {
	return reinterpret_cast<const Scmat4ImagC&>(*this);
}

inline Cmat4Imag::operator const Scmat4Imag&() {
	return reinterpret_cast<const Scmat4Imag&>(*this);
}

typedef const Cmat4Imag &Cmat4Imag_I;
typedef Cmat4Imag &Cmat4Imag_O, &Cmat4Imag_IO;


class Cmat4Limag : protected VecLimag
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
	using Base::p;
	using Base::size;
	using Base::operator[];
	void resize(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	inline void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	Limag &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
	const Limag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	operator const Scmat4LimagC&() const;
	operator const Scmat4Limag&();
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

inline void Cmat4Limag::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N2 != m_N) {
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

inline Cmat4Limag::operator const Scmat4LimagC&() const {
	return reinterpret_cast<const Scmat4LimagC&>(*this);
}

inline Cmat4Limag::operator const Scmat4Limag&() {
	return reinterpret_cast<const Scmat4Limag&>(*this);
}

typedef const Cmat4Limag &Cmat4Limag_I;
typedef Cmat4Limag &Cmat4Limag_O, &Cmat4Limag_IO;




#ifdef SLS_USE_INT_AS_LONG
typedef Cmat4Int Cmat4Long;
#else
typedef Cmat4Llong Cmat4Long;
#endif
typedef const Cmat4Long &Cmat4Long_I;
typedef Cmat4Long &Cmat4Long_O, &Cmat4Long_IO;

} // namespace slisc
