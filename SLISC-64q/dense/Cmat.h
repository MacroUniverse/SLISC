// Cmat container
#pragma once
#include "../dense/Vec.h"
#include "Scmat.h"

namespace slisc {
class CmatBool : protected VbaseBool
{
protected:
	typedef VbaseBool Base;
	Long m_N0;
public:
	CmatBool(): m_N0(0) {};
	CmatBool(Long_I N0, Long_I N1);
	CmatBool(const CmatBool &rhs); // copy constructor
	CmatBool(CmatBool &&rhs); // move constructor
	CmatBool &operator=(const CmatBool &rhs); // copy assignment
	CmatBool &operator=(CmatBool &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Bool& operator()(Long_I i, Long_I j); // double indexing
	const Bool& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatBoolC&() const;
	operator const ScmatBool&();
};

inline CmatBool::CmatBool(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatBool::CmatBool(const CmatBool &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatBool::CmatBool(CmatBool &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatBool &CmatBool::operator=(const CmatBool &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatBool &CmatBool::operator=(CmatBool &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Bool &CmatBool::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatBool index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Bool &CmatBool::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatBool index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatBool::n0() const
{ return m_N0; }

inline Long CmatBool::n1() const
{ return m_N/m_N0; }

inline void CmatBool::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatBool::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatBool reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatBool::operator const ScmatBoolC&() const {
	return reinterpret_cast<const ScmatBoolC&>(*this);
}

inline CmatBool::operator const ScmatBool&() {
	return reinterpret_cast<const ScmatBool&>(*this);
}

typedef const CmatBool &CmatBool_I;
typedef CmatBool &CmatBool_O, &CmatBool_IO;


class CmatChar : protected VbaseChar
{
protected:
	typedef VbaseChar Base;
	Long m_N0;
public:
	CmatChar(): m_N0(0) {};
	CmatChar(Long_I N0, Long_I N1);
	CmatChar(const CmatChar &rhs); // copy constructor
	CmatChar(CmatChar &&rhs); // move constructor
	CmatChar &operator=(const CmatChar &rhs); // copy assignment
	CmatChar &operator=(CmatChar &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Char& operator()(Long_I i, Long_I j); // double indexing
	const Char& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatCharC&() const;
	operator const ScmatChar&();
};

inline CmatChar::CmatChar(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatChar::CmatChar(const CmatChar &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatChar::CmatChar(CmatChar &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatChar &CmatChar::operator=(const CmatChar &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatChar &CmatChar::operator=(CmatChar &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Char &CmatChar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatChar index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Char &CmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatChar index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatChar::n0() const
{ return m_N0; }

inline Long CmatChar::n1() const
{ return m_N/m_N0; }

inline void CmatChar::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatChar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatChar reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatChar::operator const ScmatCharC&() const {
	return reinterpret_cast<const ScmatCharC&>(*this);
}

inline CmatChar::operator const ScmatChar&() {
	return reinterpret_cast<const ScmatChar&>(*this);
}

typedef const CmatChar &CmatChar_I;
typedef CmatChar &CmatChar_O, &CmatChar_IO;


class CmatUchar : protected VbaseUchar
{
protected:
	typedef VbaseUchar Base;
	Long m_N0;
public:
	CmatUchar(): m_N0(0) {};
	CmatUchar(Long_I N0, Long_I N1);
	CmatUchar(const CmatUchar &rhs); // copy constructor
	CmatUchar(CmatUchar &&rhs); // move constructor
	CmatUchar &operator=(const CmatUchar &rhs); // copy assignment
	CmatUchar &operator=(CmatUchar &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Uchar& operator()(Long_I i, Long_I j); // double indexing
	const Uchar& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatUcharC&() const;
	operator const ScmatUchar&();
};

inline CmatUchar::CmatUchar(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatUchar::CmatUchar(const CmatUchar &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatUchar::CmatUchar(CmatUchar &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatUchar &CmatUchar::operator=(const CmatUchar &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatUchar &CmatUchar::operator=(CmatUchar &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Uchar &CmatUchar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatUchar index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Uchar &CmatUchar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatUchar index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatUchar::n0() const
{ return m_N0; }

inline Long CmatUchar::n1() const
{ return m_N/m_N0; }

inline void CmatUchar::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatUchar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatUchar reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatUchar::operator const ScmatUcharC&() const {
	return reinterpret_cast<const ScmatUcharC&>(*this);
}

inline CmatUchar::operator const ScmatUchar&() {
	return reinterpret_cast<const ScmatUchar&>(*this);
}

typedef const CmatUchar &CmatUchar_I;
typedef CmatUchar &CmatUchar_O, &CmatUchar_IO;


class CmatInt : protected VbaseInt
{
protected:
	typedef VbaseInt Base;
	Long m_N0;
public:
	CmatInt(): m_N0(0) {};
	CmatInt(Long_I N0, Long_I N1);
	CmatInt(const CmatInt &rhs); // copy constructor
	CmatInt(CmatInt &&rhs); // move constructor
	CmatInt &operator=(const CmatInt &rhs); // copy assignment
	CmatInt &operator=(CmatInt &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Int& operator()(Long_I i, Long_I j); // double indexing
	const Int& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatIntC&() const;
	operator const ScmatInt&();
};

inline CmatInt::CmatInt(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatInt::CmatInt(const CmatInt &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatInt::CmatInt(CmatInt &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatInt &CmatInt::operator=(const CmatInt &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatInt &CmatInt::operator=(CmatInt &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Int &CmatInt::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatInt index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Int &CmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatInt index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatInt::n0() const
{ return m_N0; }

inline Long CmatInt::n1() const
{ return m_N/m_N0; }

inline void CmatInt::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatInt::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatInt reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatInt::operator const ScmatIntC&() const {
	return reinterpret_cast<const ScmatIntC&>(*this);
}

inline CmatInt::operator const ScmatInt&() {
	return reinterpret_cast<const ScmatInt&>(*this);
}

typedef const CmatInt &CmatInt_I;
typedef CmatInt &CmatInt_O, &CmatInt_IO;


class CmatLlong : protected VbaseLlong
{
protected:
	typedef VbaseLlong Base;
	Long m_N0;
public:
	CmatLlong(): m_N0(0) {};
	CmatLlong(Long_I N0, Long_I N1);
	CmatLlong(const CmatLlong &rhs); // copy constructor
	CmatLlong(CmatLlong &&rhs); // move constructor
	CmatLlong &operator=(const CmatLlong &rhs); // copy assignment
	CmatLlong &operator=(CmatLlong &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Llong& operator()(Long_I i, Long_I j); // double indexing
	const Llong& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatLlongC&() const;
	operator const ScmatLlong&();
};

inline CmatLlong::CmatLlong(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatLlong::CmatLlong(const CmatLlong &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatLlong::CmatLlong(CmatLlong &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatLlong &CmatLlong::operator=(const CmatLlong &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatLlong &CmatLlong::operator=(CmatLlong &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Llong &CmatLlong::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatLlong index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Llong &CmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatLlong index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatLlong::n0() const
{ return m_N0; }

inline Long CmatLlong::n1() const
{ return m_N/m_N0; }

inline void CmatLlong::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatLlong::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatLlong reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatLlong::operator const ScmatLlongC&() const {
	return reinterpret_cast<const ScmatLlongC&>(*this);
}

inline CmatLlong::operator const ScmatLlong&() {
	return reinterpret_cast<const ScmatLlong&>(*this);
}

typedef const CmatLlong &CmatLlong_I;
typedef CmatLlong &CmatLlong_O, &CmatLlong_IO;


class CmatFloat : protected VbaseFloat
{
protected:
	typedef VbaseFloat Base;
	Long m_N0;
public:
	CmatFloat(): m_N0(0) {};
	CmatFloat(Long_I N0, Long_I N1);
	CmatFloat(const CmatFloat &rhs); // copy constructor
	CmatFloat(CmatFloat &&rhs); // move constructor
	CmatFloat &operator=(const CmatFloat &rhs); // copy assignment
	CmatFloat &operator=(CmatFloat &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Float& operator()(Long_I i, Long_I j); // double indexing
	const Float& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatFloatC&() const;
	operator const ScmatFloat&();
};

inline CmatFloat::CmatFloat(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatFloat::CmatFloat(const CmatFloat &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatFloat::CmatFloat(CmatFloat &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatFloat &CmatFloat::operator=(const CmatFloat &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatFloat &CmatFloat::operator=(CmatFloat &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Float &CmatFloat::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatFloat index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Float &CmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatFloat index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatFloat::n0() const
{ return m_N0; }

inline Long CmatFloat::n1() const
{ return m_N/m_N0; }

inline void CmatFloat::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatFloat::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatFloat reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatFloat::operator const ScmatFloatC&() const {
	return reinterpret_cast<const ScmatFloatC&>(*this);
}

inline CmatFloat::operator const ScmatFloat&() {
	return reinterpret_cast<const ScmatFloat&>(*this);
}

typedef const CmatFloat &CmatFloat_I;
typedef CmatFloat &CmatFloat_O, &CmatFloat_IO;


class CmatDoub : protected VbaseDoub
{
protected:
	typedef VbaseDoub Base;
	Long m_N0;
public:
	CmatDoub(): m_N0(0) {};
	CmatDoub(Long_I N0, Long_I N1);
	CmatDoub(const CmatDoub &rhs); // copy constructor
	CmatDoub(CmatDoub &&rhs); // move constructor
	CmatDoub &operator=(const CmatDoub &rhs); // copy assignment
	CmatDoub &operator=(CmatDoub &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Doub& operator()(Long_I i, Long_I j); // double indexing
	const Doub& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatDoubC&() const;
	operator const ScmatDoub&();
};

inline CmatDoub::CmatDoub(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatDoub::CmatDoub(const CmatDoub &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatDoub::CmatDoub(CmatDoub &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatDoub &CmatDoub::operator=(const CmatDoub &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatDoub &CmatDoub::operator=(CmatDoub &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Doub &CmatDoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatDoub index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Doub &CmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatDoub index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatDoub::n0() const
{ return m_N0; }

inline Long CmatDoub::n1() const
{ return m_N/m_N0; }

inline void CmatDoub::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatDoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatDoub reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatDoub::operator const ScmatDoubC&() const {
	return reinterpret_cast<const ScmatDoubC&>(*this);
}

inline CmatDoub::operator const ScmatDoub&() {
	return reinterpret_cast<const ScmatDoub&>(*this);
}

typedef const CmatDoub &CmatDoub_I;
typedef CmatDoub &CmatDoub_O, &CmatDoub_IO;


class CmatLdoub : protected VbaseLdoub
{
protected:
	typedef VbaseLdoub Base;
	Long m_N0;
public:
	CmatLdoub(): m_N0(0) {};
	CmatLdoub(Long_I N0, Long_I N1);
	CmatLdoub(const CmatLdoub &rhs); // copy constructor
	CmatLdoub(CmatLdoub &&rhs); // move constructor
	CmatLdoub &operator=(const CmatLdoub &rhs); // copy assignment
	CmatLdoub &operator=(CmatLdoub &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Ldoub& operator()(Long_I i, Long_I j); // double indexing
	const Ldoub& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatLdoubC&() const;
	operator const ScmatLdoub&();
};

inline CmatLdoub::CmatLdoub(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatLdoub::CmatLdoub(const CmatLdoub &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatLdoub::CmatLdoub(CmatLdoub &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatLdoub &CmatLdoub::operator=(const CmatLdoub &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatLdoub &CmatLdoub::operator=(CmatLdoub &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Ldoub &CmatLdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatLdoub index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Ldoub &CmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatLdoub index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatLdoub::n0() const
{ return m_N0; }

inline Long CmatLdoub::n1() const
{ return m_N/m_N0; }

inline void CmatLdoub::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatLdoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatLdoub reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatLdoub::operator const ScmatLdoubC&() const {
	return reinterpret_cast<const ScmatLdoubC&>(*this);
}

inline CmatLdoub::operator const ScmatLdoub&() {
	return reinterpret_cast<const ScmatLdoub&>(*this);
}

typedef const CmatLdoub &CmatLdoub_I;
typedef CmatLdoub &CmatLdoub_O, &CmatLdoub_IO;


class CmatQdoub : protected VbaseQdoub
{
protected:
	typedef VbaseQdoub Base;
	Long m_N0;
public:
	CmatQdoub(): m_N0(0) {};
	CmatQdoub(Long_I N0, Long_I N1);
	CmatQdoub(const CmatQdoub &rhs); // copy constructor
	CmatQdoub(CmatQdoub &&rhs); // move constructor
	CmatQdoub &operator=(const CmatQdoub &rhs); // copy assignment
	CmatQdoub &operator=(CmatQdoub &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Qdoub& operator()(Long_I i, Long_I j); // double indexing
	const Qdoub& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatQdoubC&() const;
	operator const ScmatQdoub&();
};

inline CmatQdoub::CmatQdoub(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatQdoub::CmatQdoub(const CmatQdoub &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatQdoub::CmatQdoub(CmatQdoub &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatQdoub &CmatQdoub::operator=(const CmatQdoub &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatQdoub &CmatQdoub::operator=(CmatQdoub &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Qdoub &CmatQdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatQdoub index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Qdoub &CmatQdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatQdoub index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatQdoub::n0() const
{ return m_N0; }

inline Long CmatQdoub::n1() const
{ return m_N/m_N0; }

inline void CmatQdoub::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatQdoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatQdoub reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatQdoub::operator const ScmatQdoubC&() const {
	return reinterpret_cast<const ScmatQdoubC&>(*this);
}

inline CmatQdoub::operator const ScmatQdoub&() {
	return reinterpret_cast<const ScmatQdoub&>(*this);
}

typedef const CmatQdoub &CmatQdoub_I;
typedef CmatQdoub &CmatQdoub_O, &CmatQdoub_IO;


class CmatFcomp : protected VbaseFcomp
{
protected:
	typedef VbaseFcomp Base;
	Long m_N0;
public:
	CmatFcomp(): m_N0(0) {};
	CmatFcomp(Long_I N0, Long_I N1);
	CmatFcomp(const CmatFcomp &rhs); // copy constructor
	CmatFcomp(CmatFcomp &&rhs); // move constructor
	CmatFcomp &operator=(const CmatFcomp &rhs); // copy assignment
	CmatFcomp &operator=(CmatFcomp &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Fcomp& operator()(Long_I i, Long_I j); // double indexing
	const Fcomp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatFcompC&() const;
	operator const ScmatFcomp&();
};

inline CmatFcomp::CmatFcomp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatFcomp::CmatFcomp(const CmatFcomp &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatFcomp::CmatFcomp(CmatFcomp &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatFcomp &CmatFcomp::operator=(const CmatFcomp &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatFcomp &CmatFcomp::operator=(CmatFcomp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Fcomp &CmatFcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatFcomp index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Fcomp &CmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatFcomp index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatFcomp::n0() const
{ return m_N0; }

inline Long CmatFcomp::n1() const
{ return m_N/m_N0; }

inline void CmatFcomp::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatFcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatFcomp reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatFcomp::operator const ScmatFcompC&() const {
	return reinterpret_cast<const ScmatFcompC&>(*this);
}

inline CmatFcomp::operator const ScmatFcomp&() {
	return reinterpret_cast<const ScmatFcomp&>(*this);
}

typedef const CmatFcomp &CmatFcomp_I;
typedef CmatFcomp &CmatFcomp_O, &CmatFcomp_IO;


class CmatComp : protected VbaseComp
{
protected:
	typedef VbaseComp Base;
	Long m_N0;
public:
	CmatComp(): m_N0(0) {};
	CmatComp(Long_I N0, Long_I N1);
	CmatComp(const CmatComp &rhs); // copy constructor
	CmatComp(CmatComp &&rhs); // move constructor
	CmatComp &operator=(const CmatComp &rhs); // copy assignment
	CmatComp &operator=(CmatComp &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Comp& operator()(Long_I i, Long_I j); // double indexing
	const Comp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatCompC&() const;
	operator const ScmatComp&();
};

inline CmatComp::CmatComp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatComp::CmatComp(const CmatComp &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatComp::CmatComp(CmatComp &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatComp &CmatComp::operator=(const CmatComp &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatComp &CmatComp::operator=(CmatComp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Comp &CmatComp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatComp index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Comp &CmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatComp index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatComp::n0() const
{ return m_N0; }

inline Long CmatComp::n1() const
{ return m_N/m_N0; }

inline void CmatComp::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatComp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatComp reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatComp::operator const ScmatCompC&() const {
	return reinterpret_cast<const ScmatCompC&>(*this);
}

inline CmatComp::operator const ScmatComp&() {
	return reinterpret_cast<const ScmatComp&>(*this);
}

typedef const CmatComp &CmatComp_I;
typedef CmatComp &CmatComp_O, &CmatComp_IO;


class CmatLcomp : protected VbaseLcomp
{
protected:
	typedef VbaseLcomp Base;
	Long m_N0;
public:
	CmatLcomp(): m_N0(0) {};
	CmatLcomp(Long_I N0, Long_I N1);
	CmatLcomp(const CmatLcomp &rhs); // copy constructor
	CmatLcomp(CmatLcomp &&rhs); // move constructor
	CmatLcomp &operator=(const CmatLcomp &rhs); // copy assignment
	CmatLcomp &operator=(CmatLcomp &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Lcomp& operator()(Long_I i, Long_I j); // double indexing
	const Lcomp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatLcompC&() const;
	operator const ScmatLcomp&();
};

inline CmatLcomp::CmatLcomp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatLcomp::CmatLcomp(const CmatLcomp &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatLcomp::CmatLcomp(CmatLcomp &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatLcomp &CmatLcomp::operator=(const CmatLcomp &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatLcomp &CmatLcomp::operator=(CmatLcomp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Lcomp &CmatLcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatLcomp index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Lcomp &CmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatLcomp index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatLcomp::n0() const
{ return m_N0; }

inline Long CmatLcomp::n1() const
{ return m_N/m_N0; }

inline void CmatLcomp::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatLcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatLcomp reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatLcomp::operator const ScmatLcompC&() const {
	return reinterpret_cast<const ScmatLcompC&>(*this);
}

inline CmatLcomp::operator const ScmatLcomp&() {
	return reinterpret_cast<const ScmatLcomp&>(*this);
}

typedef const CmatLcomp &CmatLcomp_I;
typedef CmatLcomp &CmatLcomp_O, &CmatLcomp_IO;


class CmatQcomp : protected VbaseQcomp
{
protected:
	typedef VbaseQcomp Base;
	Long m_N0;
public:
	CmatQcomp(): m_N0(0) {};
	CmatQcomp(Long_I N0, Long_I N1);
	CmatQcomp(const CmatQcomp &rhs); // copy constructor
	CmatQcomp(CmatQcomp &&rhs); // move constructor
	CmatQcomp &operator=(const CmatQcomp &rhs); // copy assignment
	CmatQcomp &operator=(CmatQcomp &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Qcomp& operator()(Long_I i, Long_I j); // double indexing
	const Qcomp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatQcompC&() const;
	operator const ScmatQcomp&();
};

inline CmatQcomp::CmatQcomp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatQcomp::CmatQcomp(const CmatQcomp &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatQcomp::CmatQcomp(CmatQcomp &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatQcomp &CmatQcomp::operator=(const CmatQcomp &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatQcomp &CmatQcomp::operator=(CmatQcomp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Qcomp &CmatQcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatQcomp index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Qcomp &CmatQcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatQcomp index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatQcomp::n0() const
{ return m_N0; }

inline Long CmatQcomp::n1() const
{ return m_N/m_N0; }

inline void CmatQcomp::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatQcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatQcomp reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatQcomp::operator const ScmatQcompC&() const {
	return reinterpret_cast<const ScmatQcompC&>(*this);
}

inline CmatQcomp::operator const ScmatQcomp&() {
	return reinterpret_cast<const ScmatQcomp&>(*this);
}

typedef const CmatQcomp &CmatQcomp_I;
typedef CmatQcomp &CmatQcomp_O, &CmatQcomp_IO;


class CmatFimag : protected VbaseFimag
{
protected:
	typedef VbaseFimag Base;
	Long m_N0;
public:
	CmatFimag(): m_N0(0) {};
	CmatFimag(Long_I N0, Long_I N1);
	CmatFimag(const CmatFimag &rhs); // copy constructor
	CmatFimag(CmatFimag &&rhs); // move constructor
	CmatFimag &operator=(const CmatFimag &rhs); // copy assignment
	CmatFimag &operator=(CmatFimag &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Fimag& operator()(Long_I i, Long_I j); // double indexing
	const Fimag& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatFimagC&() const;
	operator const ScmatFimag&();
};

inline CmatFimag::CmatFimag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatFimag::CmatFimag(const CmatFimag &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatFimag::CmatFimag(CmatFimag &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatFimag &CmatFimag::operator=(const CmatFimag &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatFimag &CmatFimag::operator=(CmatFimag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Fimag &CmatFimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatFimag index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Fimag &CmatFimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatFimag index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatFimag::n0() const
{ return m_N0; }

inline Long CmatFimag::n1() const
{ return m_N/m_N0; }

inline void CmatFimag::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatFimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatFimag reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatFimag::operator const ScmatFimagC&() const {
	return reinterpret_cast<const ScmatFimagC&>(*this);
}

inline CmatFimag::operator const ScmatFimag&() {
	return reinterpret_cast<const ScmatFimag&>(*this);
}

typedef const CmatFimag &CmatFimag_I;
typedef CmatFimag &CmatFimag_O, &CmatFimag_IO;


class CmatImag : protected VbaseImag
{
protected:
	typedef VbaseImag Base;
	Long m_N0;
public:
	CmatImag(): m_N0(0) {};
	CmatImag(Long_I N0, Long_I N1);
	CmatImag(const CmatImag &rhs); // copy constructor
	CmatImag(CmatImag &&rhs); // move constructor
	CmatImag &operator=(const CmatImag &rhs); // copy assignment
	CmatImag &operator=(CmatImag &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Imag& operator()(Long_I i, Long_I j); // double indexing
	const Imag& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatImagC&() const;
	operator const ScmatImag&();
};

inline CmatImag::CmatImag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatImag::CmatImag(const CmatImag &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatImag::CmatImag(CmatImag &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatImag &CmatImag::operator=(const CmatImag &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatImag &CmatImag::operator=(CmatImag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Imag &CmatImag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatImag index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Imag &CmatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatImag index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatImag::n0() const
{ return m_N0; }

inline Long CmatImag::n1() const
{ return m_N/m_N0; }

inline void CmatImag::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatImag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatImag reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatImag::operator const ScmatImagC&() const {
	return reinterpret_cast<const ScmatImagC&>(*this);
}

inline CmatImag::operator const ScmatImag&() {
	return reinterpret_cast<const ScmatImag&>(*this);
}

typedef const CmatImag &CmatImag_I;
typedef CmatImag &CmatImag_O, &CmatImag_IO;


class CmatLimag : protected VbaseLimag
{
protected:
	typedef VbaseLimag Base;
	Long m_N0;
public:
	CmatLimag(): m_N0(0) {};
	CmatLimag(Long_I N0, Long_I N1);
	CmatLimag(const CmatLimag &rhs); // copy constructor
	CmatLimag(CmatLimag &&rhs); // move constructor
	CmatLimag &operator=(const CmatLimag &rhs); // copy assignment
	CmatLimag &operator=(CmatLimag &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Limag& operator()(Long_I i, Long_I j); // double indexing
	const Limag& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatLimagC&() const;
	operator const ScmatLimag&();
};

inline CmatLimag::CmatLimag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatLimag::CmatLimag(const CmatLimag &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatLimag::CmatLimag(CmatLimag &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatLimag &CmatLimag::operator=(const CmatLimag &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatLimag &CmatLimag::operator=(CmatLimag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Limag &CmatLimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatLimag index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Limag &CmatLimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatLimag index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatLimag::n0() const
{ return m_N0; }

inline Long CmatLimag::n1() const
{ return m_N/m_N0; }

inline void CmatLimag::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatLimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatLimag reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatLimag::operator const ScmatLimagC&() const {
	return reinterpret_cast<const ScmatLimagC&>(*this);
}

inline CmatLimag::operator const ScmatLimag&() {
	return reinterpret_cast<const ScmatLimag&>(*this);
}

typedef const CmatLimag &CmatLimag_I;
typedef CmatLimag &CmatLimag_O, &CmatLimag_IO;


class CmatQimag : protected VbaseQimag
{
protected:
	typedef VbaseQimag Base;
	Long m_N0;
public:
	CmatQimag(): m_N0(0) {};
	CmatQimag(Long_I N0, Long_I N1);
	CmatQimag(const CmatQimag &rhs); // copy constructor
	CmatQimag(CmatQimag &&rhs); // move constructor
	CmatQimag &operator=(const CmatQimag &rhs); // copy assignment
	CmatQimag &operator=(CmatQimag &&rhs); // move assignment
	using Base::p;
	using Base::size;
	using Base::operator[];
	using Base::end;
	Qimag& operator()(Long_I i, Long_I j); // double indexing
	const Qimag& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 == m_N)

	operator const ScmatQimagC&() const;
	operator const ScmatQimag&();
};

inline CmatQimag::CmatQimag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0) {}

inline CmatQimag::CmatQimag(const CmatQimag &rhs) : Base(rhs), m_N0(rhs.m_N0)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatQimag::CmatQimag(CmatQimag &&rhs)
	: Base(move(rhs)), m_N0(rhs.m_N0) {}

inline CmatQimag &CmatQimag::operator=(const CmatQimag &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatQimag &CmatQimag::operator=(CmatQimag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0;
	return *this;
}

inline Qimag &CmatQimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatQimag index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline const Qimag &CmatQimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "CmatQimag index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatQimag::n0() const
{ return m_N0; }

inline Long CmatQimag::n1() const
{ return m_N/m_N0; }

inline void CmatQimag::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != n1()) {
		Base::resize(N0*N1);
		m_N0 = N0;
	}
}

inline void CmatQimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "CmatQimag reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline CmatQimag::operator const ScmatQimagC&() const {
	return reinterpret_cast<const ScmatQimagC&>(*this);
}

inline CmatQimag::operator const ScmatQimag&() {
	return reinterpret_cast<const ScmatQimag&>(*this);
}

typedef const CmatQimag &CmatQimag_I;
typedef CmatQimag &CmatQimag_O, &CmatQimag_IO;



#ifdef SLS_USE_INT_AS_LONG
typedef CmatInt CmatLong;
#else
typedef CmatLlong CmatLong;
#endif
typedef const CmatLong &CmatLong_I;
typedef CmatLong &CmatLong_O, &CmatLong_IO;

} // namespace slisc
