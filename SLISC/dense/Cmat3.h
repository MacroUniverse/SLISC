// Cmat container
#pragma once
#include "../dense/Vec.h"
#include "Scmat3.h"

namespace slisc {
class Cmat3Bool : private VbaseBool
{
protected:
	typedef VbaseBool Base;
	Long m_N0, m_N1;
public:
	Cmat3Bool(): m_N0(0), m_N1(0) {};
	Cmat3Bool(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Bool(const Cmat3Bool &rhs); // copy constructor
	Cmat3Bool(Cmat3Bool &&rhs); // move constructor
	Cmat3Bool &operator=(const Cmat3Bool &rhs); // copy assignment
	Cmat3Bool &operator=(Cmat3Bool &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Bool &operator()(Long_I i, Long_I j, Long_I k);
	const Bool &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3BoolC&() const;
	operator const Scmat3Bool&();
};

inline Cmat3Bool::Cmat3Bool(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Bool::Cmat3Bool(const Cmat3Bool &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Bool::Cmat3Bool(Cmat3Bool &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Bool &Cmat3Bool::operator=(const Cmat3Bool &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Bool &Cmat3Bool::operator=(Cmat3Bool &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Bool::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Bool::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Bool reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Bool &Cmat3Bool::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Bool index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Bool &Cmat3Bool::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Bool index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Bool::n0() const {
	return m_N0;
}

inline Long Cmat3Bool::n1() const {
	return m_N1;
}

inline Long Cmat3Bool::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Bool::operator const Scmat3BoolC&() const {
	return reinterpret_cast<const Scmat3BoolC&>(*this);
}

inline Cmat3Bool::operator const Scmat3Bool&() {
	return reinterpret_cast<const Scmat3Bool&>(*this);
}

typedef const Cmat3Bool &Cmat3Bool_I;
typedef Cmat3Bool &Cmat3Bool_O, &Cmat3Bool_IO;


class Cmat3Char : private VbaseChar
{
protected:
	typedef VbaseChar Base;
	Long m_N0, m_N1;
public:
	Cmat3Char(): m_N0(0), m_N1(0) {};
	Cmat3Char(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Char(const Cmat3Char &rhs); // copy constructor
	Cmat3Char(Cmat3Char &&rhs); // move constructor
	Cmat3Char &operator=(const Cmat3Char &rhs); // copy assignment
	Cmat3Char &operator=(Cmat3Char &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Char &operator()(Long_I i, Long_I j, Long_I k);
	const Char &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3CharC&() const;
	operator const Scmat3Char&();
};

inline Cmat3Char::Cmat3Char(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Char::Cmat3Char(const Cmat3Char &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Char::Cmat3Char(Cmat3Char &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Char &Cmat3Char::operator=(const Cmat3Char &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Char &Cmat3Char::operator=(Cmat3Char &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Char::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Char::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Char reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Char &Cmat3Char::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Char index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Char &Cmat3Char::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Char index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Char::n0() const {
	return m_N0;
}

inline Long Cmat3Char::n1() const {
	return m_N1;
}

inline Long Cmat3Char::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Char::operator const Scmat3CharC&() const {
	return reinterpret_cast<const Scmat3CharC&>(*this);
}

inline Cmat3Char::operator const Scmat3Char&() {
	return reinterpret_cast<const Scmat3Char&>(*this);
}

typedef const Cmat3Char &Cmat3Char_I;
typedef Cmat3Char &Cmat3Char_O, &Cmat3Char_IO;


class Cmat3Uchar : private VbaseUchar
{
protected:
	typedef VbaseUchar Base;
	Long m_N0, m_N1;
public:
	Cmat3Uchar(): m_N0(0), m_N1(0) {};
	Cmat3Uchar(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Uchar(const Cmat3Uchar &rhs); // copy constructor
	Cmat3Uchar(Cmat3Uchar &&rhs); // move constructor
	Cmat3Uchar &operator=(const Cmat3Uchar &rhs); // copy assignment
	Cmat3Uchar &operator=(Cmat3Uchar &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Uchar &operator()(Long_I i, Long_I j, Long_I k);
	const Uchar &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3UcharC&() const;
	operator const Scmat3Uchar&();
};

inline Cmat3Uchar::Cmat3Uchar(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Uchar::Cmat3Uchar(const Cmat3Uchar &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Uchar::Cmat3Uchar(Cmat3Uchar &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Uchar &Cmat3Uchar::operator=(const Cmat3Uchar &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Uchar &Cmat3Uchar::operator=(Cmat3Uchar &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Uchar::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Uchar::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Uchar reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Uchar &Cmat3Uchar::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Uchar index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Uchar &Cmat3Uchar::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Uchar index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Uchar::n0() const {
	return m_N0;
}

inline Long Cmat3Uchar::n1() const {
	return m_N1;
}

inline Long Cmat3Uchar::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Uchar::operator const Scmat3UcharC&() const {
	return reinterpret_cast<const Scmat3UcharC&>(*this);
}

inline Cmat3Uchar::operator const Scmat3Uchar&() {
	return reinterpret_cast<const Scmat3Uchar&>(*this);
}

typedef const Cmat3Uchar &Cmat3Uchar_I;
typedef Cmat3Uchar &Cmat3Uchar_O, &Cmat3Uchar_IO;


class Cmat3Int : private VbaseInt
{
protected:
	typedef VbaseInt Base;
	Long m_N0, m_N1;
public:
	Cmat3Int(): m_N0(0), m_N1(0) {};
	Cmat3Int(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Int(const Cmat3Int &rhs); // copy constructor
	Cmat3Int(Cmat3Int &&rhs); // move constructor
	Cmat3Int &operator=(const Cmat3Int &rhs); // copy assignment
	Cmat3Int &operator=(Cmat3Int &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Int &operator()(Long_I i, Long_I j, Long_I k);
	const Int &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3IntC&() const;
	operator const Scmat3Int&();
};

inline Cmat3Int::Cmat3Int(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Int::Cmat3Int(const Cmat3Int &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Int::Cmat3Int(Cmat3Int &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Int &Cmat3Int::operator=(const Cmat3Int &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Int &Cmat3Int::operator=(Cmat3Int &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Int::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Int::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Int reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Int &Cmat3Int::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Int index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Int &Cmat3Int::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Int index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Int::n0() const {
	return m_N0;
}

inline Long Cmat3Int::n1() const {
	return m_N1;
}

inline Long Cmat3Int::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Int::operator const Scmat3IntC&() const {
	return reinterpret_cast<const Scmat3IntC&>(*this);
}

inline Cmat3Int::operator const Scmat3Int&() {
	return reinterpret_cast<const Scmat3Int&>(*this);
}

typedef const Cmat3Int &Cmat3Int_I;
typedef Cmat3Int &Cmat3Int_O, &Cmat3Int_IO;


class Cmat3Llong : private VbaseLlong
{
protected:
	typedef VbaseLlong Base;
	Long m_N0, m_N1;
public:
	Cmat3Llong(): m_N0(0), m_N1(0) {};
	Cmat3Llong(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Llong(const Cmat3Llong &rhs); // copy constructor
	Cmat3Llong(Cmat3Llong &&rhs); // move constructor
	Cmat3Llong &operator=(const Cmat3Llong &rhs); // copy assignment
	Cmat3Llong &operator=(Cmat3Llong &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Llong &operator()(Long_I i, Long_I j, Long_I k);
	const Llong &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3LlongC&() const;
	operator const Scmat3Llong&();
};

inline Cmat3Llong::Cmat3Llong(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Llong::Cmat3Llong(const Cmat3Llong &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Llong::Cmat3Llong(Cmat3Llong &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Llong &Cmat3Llong::operator=(const Cmat3Llong &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Llong &Cmat3Llong::operator=(Cmat3Llong &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Llong::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Llong::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Llong reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Llong &Cmat3Llong::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Llong index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Llong &Cmat3Llong::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Llong index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Llong::n0() const {
	return m_N0;
}

inline Long Cmat3Llong::n1() const {
	return m_N1;
}

inline Long Cmat3Llong::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Llong::operator const Scmat3LlongC&() const {
	return reinterpret_cast<const Scmat3LlongC&>(*this);
}

inline Cmat3Llong::operator const Scmat3Llong&() {
	return reinterpret_cast<const Scmat3Llong&>(*this);
}

typedef const Cmat3Llong &Cmat3Llong_I;
typedef Cmat3Llong &Cmat3Llong_O, &Cmat3Llong_IO;


class Cmat3Float : private VbaseFloat
{
protected:
	typedef VbaseFloat Base;
	Long m_N0, m_N1;
public:
	Cmat3Float(): m_N0(0), m_N1(0) {};
	Cmat3Float(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Float(const Cmat3Float &rhs); // copy constructor
	Cmat3Float(Cmat3Float &&rhs); // move constructor
	Cmat3Float &operator=(const Cmat3Float &rhs); // copy assignment
	Cmat3Float &operator=(Cmat3Float &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Float &operator()(Long_I i, Long_I j, Long_I k);
	const Float &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3FloatC&() const;
	operator const Scmat3Float&();
};

inline Cmat3Float::Cmat3Float(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Float::Cmat3Float(const Cmat3Float &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Float::Cmat3Float(Cmat3Float &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Float &Cmat3Float::operator=(const Cmat3Float &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Float &Cmat3Float::operator=(Cmat3Float &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Float::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Float::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Float reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Float &Cmat3Float::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Float index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Float &Cmat3Float::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Float index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Float::n0() const {
	return m_N0;
}

inline Long Cmat3Float::n1() const {
	return m_N1;
}

inline Long Cmat3Float::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Float::operator const Scmat3FloatC&() const {
	return reinterpret_cast<const Scmat3FloatC&>(*this);
}

inline Cmat3Float::operator const Scmat3Float&() {
	return reinterpret_cast<const Scmat3Float&>(*this);
}

typedef const Cmat3Float &Cmat3Float_I;
typedef Cmat3Float &Cmat3Float_O, &Cmat3Float_IO;


class Cmat3Doub : private VbaseDoub
{
protected:
	typedef VbaseDoub Base;
	Long m_N0, m_N1;
public:
	Cmat3Doub(): m_N0(0), m_N1(0) {};
	Cmat3Doub(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Doub(const Cmat3Doub &rhs); // copy constructor
	Cmat3Doub(Cmat3Doub &&rhs); // move constructor
	Cmat3Doub &operator=(const Cmat3Doub &rhs); // copy assignment
	Cmat3Doub &operator=(Cmat3Doub &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Doub &operator()(Long_I i, Long_I j, Long_I k);
	const Doub &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3DoubC&() const;
	operator const Scmat3Doub&();
};

inline Cmat3Doub::Cmat3Doub(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Doub::Cmat3Doub(const Cmat3Doub &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Doub::Cmat3Doub(Cmat3Doub &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Doub &Cmat3Doub::operator=(const Cmat3Doub &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Doub &Cmat3Doub::operator=(Cmat3Doub &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Doub::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Doub::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Doub reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Doub &Cmat3Doub::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Doub index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Doub &Cmat3Doub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Doub index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Doub::n0() const {
	return m_N0;
}

inline Long Cmat3Doub::n1() const {
	return m_N1;
}

inline Long Cmat3Doub::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Doub::operator const Scmat3DoubC&() const {
	return reinterpret_cast<const Scmat3DoubC&>(*this);
}

inline Cmat3Doub::operator const Scmat3Doub&() {
	return reinterpret_cast<const Scmat3Doub&>(*this);
}

typedef const Cmat3Doub &Cmat3Doub_I;
typedef Cmat3Doub &Cmat3Doub_O, &Cmat3Doub_IO;


class Cmat3Ldoub : private VbaseLdoub
{
protected:
	typedef VbaseLdoub Base;
	Long m_N0, m_N1;
public:
	Cmat3Ldoub(): m_N0(0), m_N1(0) {};
	Cmat3Ldoub(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Ldoub(const Cmat3Ldoub &rhs); // copy constructor
	Cmat3Ldoub(Cmat3Ldoub &&rhs); // move constructor
	Cmat3Ldoub &operator=(const Cmat3Ldoub &rhs); // copy assignment
	Cmat3Ldoub &operator=(Cmat3Ldoub &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Ldoub &operator()(Long_I i, Long_I j, Long_I k);
	const Ldoub &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3LdoubC&() const;
	operator const Scmat3Ldoub&();
};

inline Cmat3Ldoub::Cmat3Ldoub(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Ldoub::Cmat3Ldoub(const Cmat3Ldoub &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Ldoub::Cmat3Ldoub(Cmat3Ldoub &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Ldoub &Cmat3Ldoub::operator=(const Cmat3Ldoub &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Ldoub &Cmat3Ldoub::operator=(Cmat3Ldoub &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Ldoub::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Ldoub::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Ldoub reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Ldoub &Cmat3Ldoub::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Ldoub index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Ldoub &Cmat3Ldoub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Ldoub index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Ldoub::n0() const {
	return m_N0;
}

inline Long Cmat3Ldoub::n1() const {
	return m_N1;
}

inline Long Cmat3Ldoub::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Ldoub::operator const Scmat3LdoubC&() const {
	return reinterpret_cast<const Scmat3LdoubC&>(*this);
}

inline Cmat3Ldoub::operator const Scmat3Ldoub&() {
	return reinterpret_cast<const Scmat3Ldoub&>(*this);
}

typedef const Cmat3Ldoub &Cmat3Ldoub_I;
typedef Cmat3Ldoub &Cmat3Ldoub_O, &Cmat3Ldoub_IO;



class Cmat3Fcomp : private VbaseFcomp
{
protected:
	typedef VbaseFcomp Base;
	Long m_N0, m_N1;
public:
	Cmat3Fcomp(): m_N0(0), m_N1(0) {};
	Cmat3Fcomp(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Fcomp(const Cmat3Fcomp &rhs); // copy constructor
	Cmat3Fcomp(Cmat3Fcomp &&rhs); // move constructor
	Cmat3Fcomp &operator=(const Cmat3Fcomp &rhs); // copy assignment
	Cmat3Fcomp &operator=(Cmat3Fcomp &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Fcomp &operator()(Long_I i, Long_I j, Long_I k);
	const Fcomp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3FcompC&() const;
	operator const Scmat3Fcomp&();
};

inline Cmat3Fcomp::Cmat3Fcomp(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Fcomp::Cmat3Fcomp(const Cmat3Fcomp &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Fcomp::Cmat3Fcomp(Cmat3Fcomp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Fcomp &Cmat3Fcomp::operator=(const Cmat3Fcomp &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Fcomp &Cmat3Fcomp::operator=(Cmat3Fcomp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Fcomp::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Fcomp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Fcomp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Fcomp &Cmat3Fcomp::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Fcomp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Fcomp &Cmat3Fcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Fcomp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Fcomp::n0() const {
	return m_N0;
}

inline Long Cmat3Fcomp::n1() const {
	return m_N1;
}

inline Long Cmat3Fcomp::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Fcomp::operator const Scmat3FcompC&() const {
	return reinterpret_cast<const Scmat3FcompC&>(*this);
}

inline Cmat3Fcomp::operator const Scmat3Fcomp&() {
	return reinterpret_cast<const Scmat3Fcomp&>(*this);
}

typedef const Cmat3Fcomp &Cmat3Fcomp_I;
typedef Cmat3Fcomp &Cmat3Fcomp_O, &Cmat3Fcomp_IO;


class Cmat3Comp : private VbaseComp
{
protected:
	typedef VbaseComp Base;
	Long m_N0, m_N1;
public:
	Cmat3Comp(): m_N0(0), m_N1(0) {};
	Cmat3Comp(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Comp(const Cmat3Comp &rhs); // copy constructor
	Cmat3Comp(Cmat3Comp &&rhs); // move constructor
	Cmat3Comp &operator=(const Cmat3Comp &rhs); // copy assignment
	Cmat3Comp &operator=(Cmat3Comp &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Comp &operator()(Long_I i, Long_I j, Long_I k);
	const Comp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3CompC&() const;
	operator const Scmat3Comp&();
};

inline Cmat3Comp::Cmat3Comp(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Comp::Cmat3Comp(const Cmat3Comp &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Comp::Cmat3Comp(Cmat3Comp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Comp &Cmat3Comp::operator=(const Cmat3Comp &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Comp &Cmat3Comp::operator=(Cmat3Comp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Comp::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Comp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Comp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Comp &Cmat3Comp::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Comp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Comp &Cmat3Comp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Comp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Comp::n0() const {
	return m_N0;
}

inline Long Cmat3Comp::n1() const {
	return m_N1;
}

inline Long Cmat3Comp::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Comp::operator const Scmat3CompC&() const {
	return reinterpret_cast<const Scmat3CompC&>(*this);
}

inline Cmat3Comp::operator const Scmat3Comp&() {
	return reinterpret_cast<const Scmat3Comp&>(*this);
}

typedef const Cmat3Comp &Cmat3Comp_I;
typedef Cmat3Comp &Cmat3Comp_O, &Cmat3Comp_IO;


class Cmat3Lcomp : private VbaseLcomp
{
protected:
	typedef VbaseLcomp Base;
	Long m_N0, m_N1;
public:
	Cmat3Lcomp(): m_N0(0), m_N1(0) {};
	Cmat3Lcomp(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Lcomp(const Cmat3Lcomp &rhs); // copy constructor
	Cmat3Lcomp(Cmat3Lcomp &&rhs); // move constructor
	Cmat3Lcomp &operator=(const Cmat3Lcomp &rhs); // copy assignment
	Cmat3Lcomp &operator=(Cmat3Lcomp &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Lcomp &operator()(Long_I i, Long_I j, Long_I k);
	const Lcomp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3LcompC&() const;
	operator const Scmat3Lcomp&();
};

inline Cmat3Lcomp::Cmat3Lcomp(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Lcomp::Cmat3Lcomp(const Cmat3Lcomp &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Lcomp::Cmat3Lcomp(Cmat3Lcomp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Lcomp &Cmat3Lcomp::operator=(const Cmat3Lcomp &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Lcomp &Cmat3Lcomp::operator=(Cmat3Lcomp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Lcomp::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Lcomp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Lcomp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Lcomp &Cmat3Lcomp::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Lcomp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Lcomp &Cmat3Lcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Lcomp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Lcomp::n0() const {
	return m_N0;
}

inline Long Cmat3Lcomp::n1() const {
	return m_N1;
}

inline Long Cmat3Lcomp::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Lcomp::operator const Scmat3LcompC&() const {
	return reinterpret_cast<const Scmat3LcompC&>(*this);
}

inline Cmat3Lcomp::operator const Scmat3Lcomp&() {
	return reinterpret_cast<const Scmat3Lcomp&>(*this);
}

typedef const Cmat3Lcomp &Cmat3Lcomp_I;
typedef Cmat3Lcomp &Cmat3Lcomp_O, &Cmat3Lcomp_IO;



class Cmat3Fimag : private VbaseFimag
{
protected:
	typedef VbaseFimag Base;
	Long m_N0, m_N1;
public:
	Cmat3Fimag(): m_N0(0), m_N1(0) {};
	Cmat3Fimag(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Fimag(const Cmat3Fimag &rhs); // copy constructor
	Cmat3Fimag(Cmat3Fimag &&rhs); // move constructor
	Cmat3Fimag &operator=(const Cmat3Fimag &rhs); // copy assignment
	Cmat3Fimag &operator=(Cmat3Fimag &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Fimag &operator()(Long_I i, Long_I j, Long_I k);
	const Fimag &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3FimagC&() const;
	operator const Scmat3Fimag&();
};

inline Cmat3Fimag::Cmat3Fimag(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Fimag::Cmat3Fimag(const Cmat3Fimag &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Fimag::Cmat3Fimag(Cmat3Fimag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Fimag &Cmat3Fimag::operator=(const Cmat3Fimag &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Fimag &Cmat3Fimag::operator=(Cmat3Fimag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Fimag::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Fimag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Fimag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Fimag &Cmat3Fimag::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Fimag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Fimag &Cmat3Fimag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Fimag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Fimag::n0() const {
	return m_N0;
}

inline Long Cmat3Fimag::n1() const {
	return m_N1;
}

inline Long Cmat3Fimag::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Fimag::operator const Scmat3FimagC&() const {
	return reinterpret_cast<const Scmat3FimagC&>(*this);
}

inline Cmat3Fimag::operator const Scmat3Fimag&() {
	return reinterpret_cast<const Scmat3Fimag&>(*this);
}

typedef const Cmat3Fimag &Cmat3Fimag_I;
typedef Cmat3Fimag &Cmat3Fimag_O, &Cmat3Fimag_IO;


class Cmat3Imag : private VbaseImag
{
protected:
	typedef VbaseImag Base;
	Long m_N0, m_N1;
public:
	Cmat3Imag(): m_N0(0), m_N1(0) {};
	Cmat3Imag(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Imag(const Cmat3Imag &rhs); // copy constructor
	Cmat3Imag(Cmat3Imag &&rhs); // move constructor
	Cmat3Imag &operator=(const Cmat3Imag &rhs); // copy assignment
	Cmat3Imag &operator=(Cmat3Imag &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Imag &operator()(Long_I i, Long_I j, Long_I k);
	const Imag &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3ImagC&() const;
	operator const Scmat3Imag&();
};

inline Cmat3Imag::Cmat3Imag(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Imag::Cmat3Imag(const Cmat3Imag &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Imag::Cmat3Imag(Cmat3Imag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Imag &Cmat3Imag::operator=(const Cmat3Imag &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Imag &Cmat3Imag::operator=(Cmat3Imag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Imag::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Imag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Imag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Imag &Cmat3Imag::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Imag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Imag &Cmat3Imag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Imag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Imag::n0() const {
	return m_N0;
}

inline Long Cmat3Imag::n1() const {
	return m_N1;
}

inline Long Cmat3Imag::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Imag::operator const Scmat3ImagC&() const {
	return reinterpret_cast<const Scmat3ImagC&>(*this);
}

inline Cmat3Imag::operator const Scmat3Imag&() {
	return reinterpret_cast<const Scmat3Imag&>(*this);
}

typedef const Cmat3Imag &Cmat3Imag_I;
typedef Cmat3Imag &Cmat3Imag_O, &Cmat3Imag_IO;


class Cmat3Limag : private VbaseLimag
{
protected:
	typedef VbaseLimag Base;
	Long m_N0, m_N1;
public:
	Cmat3Limag(): m_N0(0), m_N1(0) {};
	Cmat3Limag(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Limag(const Cmat3Limag &rhs); // copy constructor
	Cmat3Limag(Cmat3Limag &&rhs); // move constructor
	Cmat3Limag &operator=(const Cmat3Limag &rhs); // copy assignment
	Cmat3Limag &operator=(Cmat3Limag &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Limag &operator()(Long_I i, Long_I j, Long_I k);
	const Limag &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
	void resize(Long_I N0, Long_I N1, Long_I N2);  // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1, Long_I N2); // reshape (N0*N1 <= m_N)

	operator const Scmat3LimagC&() const;
	operator const Scmat3Limag&();
};

inline Cmat3Limag::Cmat3Limag(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Cmat3Limag::Cmat3Limag(const Cmat3Limag &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline Cmat3Limag::Cmat3Limag(Cmat3Limag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline Cmat3Limag &Cmat3Limag::operator=(const Cmat3Limag &rhs)
{
	Base::operator=(rhs);
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Cmat3Limag &Cmat3Limag::operator=(Cmat3Limag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline void Cmat3Limag::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != n2()) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void Cmat3Limag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Cmat3Limag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline Limag &Cmat3Limag::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Limag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Limag &Cmat3Limag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Cmat3Limag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Cmat3Limag::n0() const {
	return m_N0;
}

inline Long Cmat3Limag::n1() const {
	return m_N1;
}

inline Long Cmat3Limag::n2() const {
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline Cmat3Limag::operator const Scmat3LimagC&() const {
	return reinterpret_cast<const Scmat3LimagC&>(*this);
}

inline Cmat3Limag::operator const Scmat3Limag&() {
	return reinterpret_cast<const Scmat3Limag&>(*this);
}

typedef const Cmat3Limag &Cmat3Limag_I;
typedef Cmat3Limag &Cmat3Limag_O, &Cmat3Limag_IO;




#ifdef SLS_USE_INT_AS_LONG
typedef Cmat3Int Cmat3Long;
#else
typedef Cmat3Llong Cmat3Long;
#endif
typedef const Cmat3Long &Cmat3Long_I;
typedef Cmat3Long &Cmat3Long_O, &Cmat3Long_IO;

} // namespace slisc
