// Cmat container
#pragma once
#include "../dense/Vbase.h"

namespace slisc {
class CmatChar : public VbaseChar
{
protected:
	typedef VbaseChar Base;
	Long m_N0, m_N1;
public:
	CmatChar(): m_N0(0), m_N1(0) {};
	CmatChar(Long_I N0, Long_I N1);
	CmatChar(const CmatChar &rhs); // copy constructor
	CmatChar(CmatChar &&rhs); // move constructor
	CmatChar &operator=(const CmatChar &rhs); // copy assignment
	CmatChar &operator=(CmatChar &&rhs); // move assignment
	Char& operator()(Long_I i, Long_I j); // double indexing
	const Char& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatChar::CmatChar(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatChar::CmatChar(const CmatChar &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatChar::CmatChar(CmatChar &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatChar &CmatChar::operator=(const CmatChar &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatChar &CmatChar::operator=(CmatChar &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Char &CmatChar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatChar index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Char &CmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatChar index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatChar::n0() const
{ return m_N0; }

inline Long CmatChar::n1() const
{ return m_N1; }

inline void CmatChar::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatChar::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatChar resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatChar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatChar reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatChar &CmatChar_I;
typedef CmatChar &CmatChar_O, &CmatChar_IO;

// common api for STL and SLISC
inline Long size(CmatChar_I v) { return v.size(); }

inline const Char *p(CmatChar_I v) { return v.p(); }

inline Char *p(CmatChar &v) { return v.p(); }


class CmatUchar : public VbaseUchar
{
protected:
	typedef VbaseUchar Base;
	Long m_N0, m_N1;
public:
	CmatUchar(): m_N0(0), m_N1(0) {};
	CmatUchar(Long_I N0, Long_I N1);
	CmatUchar(const CmatUchar &rhs); // copy constructor
	CmatUchar(CmatUchar &&rhs); // move constructor
	CmatUchar &operator=(const CmatUchar &rhs); // copy assignment
	CmatUchar &operator=(CmatUchar &&rhs); // move assignment
	Uchar& operator()(Long_I i, Long_I j); // double indexing
	const Uchar& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatUchar::CmatUchar(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatUchar::CmatUchar(const CmatUchar &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatUchar::CmatUchar(CmatUchar &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatUchar &CmatUchar::operator=(const CmatUchar &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatUchar &CmatUchar::operator=(CmatUchar &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Uchar &CmatUchar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatUchar index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Uchar &CmatUchar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatUchar index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatUchar::n0() const
{ return m_N0; }

inline Long CmatUchar::n1() const
{ return m_N1; }

inline void CmatUchar::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatUchar::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatUchar resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatUchar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatUchar reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatUchar &CmatUchar_I;
typedef CmatUchar &CmatUchar_O, &CmatUchar_IO;

// common api for STL and SLISC
inline Long size(CmatUchar_I v) { return v.size(); }

inline const Uchar *p(CmatUchar_I v) { return v.p(); }

inline Uchar *p(CmatUchar &v) { return v.p(); }


class CmatInt : public VbaseInt
{
protected:
	typedef VbaseInt Base;
	Long m_N0, m_N1;
public:
	CmatInt(): m_N0(0), m_N1(0) {};
	CmatInt(Long_I N0, Long_I N1);
	CmatInt(const CmatInt &rhs); // copy constructor
	CmatInt(CmatInt &&rhs); // move constructor
	CmatInt &operator=(const CmatInt &rhs); // copy assignment
	CmatInt &operator=(CmatInt &&rhs); // move assignment
	Int& operator()(Long_I i, Long_I j); // double indexing
	const Int& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatInt::CmatInt(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatInt::CmatInt(const CmatInt &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatInt::CmatInt(CmatInt &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatInt &CmatInt::operator=(const CmatInt &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatInt &CmatInt::operator=(CmatInt &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Int &CmatInt::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatInt index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Int &CmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatInt index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatInt::n0() const
{ return m_N0; }

inline Long CmatInt::n1() const
{ return m_N1; }

inline void CmatInt::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatInt::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatInt resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatInt::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatInt reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatInt &CmatInt_I;
typedef CmatInt &CmatInt_O, &CmatInt_IO;

// common api for STL and SLISC
inline Long size(CmatInt_I v) { return v.size(); }

inline const Int *p(CmatInt_I v) { return v.p(); }

inline Int *p(CmatInt &v) { return v.p(); }


class CmatLlong : public VbaseLlong
{
protected:
	typedef VbaseLlong Base;
	Long m_N0, m_N1;
public:
	CmatLlong(): m_N0(0), m_N1(0) {};
	CmatLlong(Long_I N0, Long_I N1);
	CmatLlong(const CmatLlong &rhs); // copy constructor
	CmatLlong(CmatLlong &&rhs); // move constructor
	CmatLlong &operator=(const CmatLlong &rhs); // copy assignment
	CmatLlong &operator=(CmatLlong &&rhs); // move assignment
	Llong& operator()(Long_I i, Long_I j); // double indexing
	const Llong& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatLlong::CmatLlong(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatLlong::CmatLlong(const CmatLlong &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatLlong::CmatLlong(CmatLlong &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatLlong &CmatLlong::operator=(const CmatLlong &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatLlong &CmatLlong::operator=(CmatLlong &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Llong &CmatLlong::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatLlong index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Llong &CmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatLlong index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatLlong::n0() const
{ return m_N0; }

inline Long CmatLlong::n1() const
{ return m_N1; }

inline void CmatLlong::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatLlong::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatLlong resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatLlong::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatLlong reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatLlong &CmatLlong_I;
typedef CmatLlong &CmatLlong_O, &CmatLlong_IO;

// common api for STL and SLISC
inline Long size(CmatLlong_I v) { return v.size(); }

inline const Llong *p(CmatLlong_I v) { return v.p(); }

inline Llong *p(CmatLlong &v) { return v.p(); }


class CmatFloat : public VbaseFloat
{
protected:
	typedef VbaseFloat Base;
	Long m_N0, m_N1;
public:
	CmatFloat(): m_N0(0), m_N1(0) {};
	CmatFloat(Long_I N0, Long_I N1);
	CmatFloat(const CmatFloat &rhs); // copy constructor
	CmatFloat(CmatFloat &&rhs); // move constructor
	CmatFloat &operator=(const CmatFloat &rhs); // copy assignment
	CmatFloat &operator=(CmatFloat &&rhs); // move assignment
	Float& operator()(Long_I i, Long_I j); // double indexing
	const Float& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatFloat::CmatFloat(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatFloat::CmatFloat(const CmatFloat &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatFloat::CmatFloat(CmatFloat &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatFloat &CmatFloat::operator=(const CmatFloat &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatFloat &CmatFloat::operator=(CmatFloat &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Float &CmatFloat::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatFloat index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Float &CmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatFloat index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatFloat::n0() const
{ return m_N0; }

inline Long CmatFloat::n1() const
{ return m_N1; }

inline void CmatFloat::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatFloat::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatFloat resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatFloat::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatFloat reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatFloat &CmatFloat_I;
typedef CmatFloat &CmatFloat_O, &CmatFloat_IO;

// common api for STL and SLISC
inline Long size(CmatFloat_I v) { return v.size(); }

inline const Float *p(CmatFloat_I v) { return v.p(); }

inline Float *p(CmatFloat &v) { return v.p(); }


class CmatDoub : public VbaseDoub
{
protected:
	typedef VbaseDoub Base;
	Long m_N0, m_N1;
public:
	CmatDoub(): m_N0(0), m_N1(0) {};
	CmatDoub(Long_I N0, Long_I N1);
	CmatDoub(const CmatDoub &rhs); // copy constructor
	CmatDoub(CmatDoub &&rhs); // move constructor
	CmatDoub &operator=(const CmatDoub &rhs); // copy assignment
	CmatDoub &operator=(CmatDoub &&rhs); // move assignment
	Doub& operator()(Long_I i, Long_I j); // double indexing
	const Doub& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatDoub::CmatDoub(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatDoub::CmatDoub(const CmatDoub &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatDoub::CmatDoub(CmatDoub &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatDoub &CmatDoub::operator=(const CmatDoub &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatDoub &CmatDoub::operator=(CmatDoub &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Doub &CmatDoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatDoub index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Doub &CmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatDoub index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatDoub::n0() const
{ return m_N0; }

inline Long CmatDoub::n1() const
{ return m_N1; }

inline void CmatDoub::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatDoub::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatDoub resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatDoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatDoub reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatDoub &CmatDoub_I;
typedef CmatDoub &CmatDoub_O, &CmatDoub_IO;

// common api for STL and SLISC
inline Long size(CmatDoub_I v) { return v.size(); }

inline const Doub *p(CmatDoub_I v) { return v.p(); }

inline Doub *p(CmatDoub &v) { return v.p(); }


class CmatLdoub : public VbaseLdoub
{
protected:
	typedef VbaseLdoub Base;
	Long m_N0, m_N1;
public:
	CmatLdoub(): m_N0(0), m_N1(0) {};
	CmatLdoub(Long_I N0, Long_I N1);
	CmatLdoub(const CmatLdoub &rhs); // copy constructor
	CmatLdoub(CmatLdoub &&rhs); // move constructor
	CmatLdoub &operator=(const CmatLdoub &rhs); // copy assignment
	CmatLdoub &operator=(CmatLdoub &&rhs); // move assignment
	Ldoub& operator()(Long_I i, Long_I j); // double indexing
	const Ldoub& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatLdoub::CmatLdoub(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatLdoub::CmatLdoub(const CmatLdoub &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatLdoub::CmatLdoub(CmatLdoub &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatLdoub &CmatLdoub::operator=(const CmatLdoub &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatLdoub &CmatLdoub::operator=(CmatLdoub &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Ldoub &CmatLdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatLdoub index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Ldoub &CmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatLdoub index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatLdoub::n0() const
{ return m_N0; }

inline Long CmatLdoub::n1() const
{ return m_N1; }

inline void CmatLdoub::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatLdoub::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatLdoub resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatLdoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatLdoub reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatLdoub &CmatLdoub_I;
typedef CmatLdoub &CmatLdoub_O, &CmatLdoub_IO;

// common api for STL and SLISC
inline Long size(CmatLdoub_I v) { return v.size(); }

inline const Ldoub *p(CmatLdoub_I v) { return v.p(); }

inline Ldoub *p(CmatLdoub &v) { return v.p(); }


class CmatQdoub : public VbaseQdoub
{
protected:
	typedef VbaseQdoub Base;
	Long m_N0, m_N1;
public:
	CmatQdoub(): m_N0(0), m_N1(0) {};
	CmatQdoub(Long_I N0, Long_I N1);
	CmatQdoub(const CmatQdoub &rhs); // copy constructor
	CmatQdoub(CmatQdoub &&rhs); // move constructor
	CmatQdoub &operator=(const CmatQdoub &rhs); // copy assignment
	CmatQdoub &operator=(CmatQdoub &&rhs); // move assignment
	Qdoub& operator()(Long_I i, Long_I j); // double indexing
	const Qdoub& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatQdoub::CmatQdoub(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatQdoub::CmatQdoub(const CmatQdoub &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatQdoub::CmatQdoub(CmatQdoub &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatQdoub &CmatQdoub::operator=(const CmatQdoub &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatQdoub &CmatQdoub::operator=(CmatQdoub &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Qdoub &CmatQdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatQdoub index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Qdoub &CmatQdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatQdoub index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatQdoub::n0() const
{ return m_N0; }

inline Long CmatQdoub::n1() const
{ return m_N1; }

inline void CmatQdoub::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatQdoub::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatQdoub resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatQdoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatQdoub reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatQdoub &CmatQdoub_I;
typedef CmatQdoub &CmatQdoub_O, &CmatQdoub_IO;

// common api for STL and SLISC
inline Long size(CmatQdoub_I v) { return v.size(); }

inline const Qdoub *p(CmatQdoub_I v) { return v.p(); }

inline Qdoub *p(CmatQdoub &v) { return v.p(); }


class CmatFcomp : public VbaseFcomp
{
protected:
	typedef VbaseFcomp Base;
	Long m_N0, m_N1;
public:
	CmatFcomp(): m_N0(0), m_N1(0) {};
	CmatFcomp(Long_I N0, Long_I N1);
	CmatFcomp(const CmatFcomp &rhs); // copy constructor
	CmatFcomp(CmatFcomp &&rhs); // move constructor
	CmatFcomp &operator=(const CmatFcomp &rhs); // copy assignment
	CmatFcomp &operator=(CmatFcomp &&rhs); // move assignment
	Fcomp& operator()(Long_I i, Long_I j); // double indexing
	const Fcomp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatFcomp::CmatFcomp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatFcomp::CmatFcomp(const CmatFcomp &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatFcomp::CmatFcomp(CmatFcomp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatFcomp &CmatFcomp::operator=(const CmatFcomp &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatFcomp &CmatFcomp::operator=(CmatFcomp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Fcomp &CmatFcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatFcomp index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Fcomp &CmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatFcomp index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatFcomp::n0() const
{ return m_N0; }

inline Long CmatFcomp::n1() const
{ return m_N1; }

inline void CmatFcomp::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatFcomp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatFcomp resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatFcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatFcomp reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatFcomp &CmatFcomp_I;
typedef CmatFcomp &CmatFcomp_O, &CmatFcomp_IO;

// common api for STL and SLISC
inline Long size(CmatFcomp_I v) { return v.size(); }

inline const Fcomp *p(CmatFcomp_I v) { return v.p(); }

inline Fcomp *p(CmatFcomp &v) { return v.p(); }


class CmatComp : public VbaseComp
{
protected:
	typedef VbaseComp Base;
	Long m_N0, m_N1;
public:
	CmatComp(): m_N0(0), m_N1(0) {};
	CmatComp(Long_I N0, Long_I N1);
	CmatComp(const CmatComp &rhs); // copy constructor
	CmatComp(CmatComp &&rhs); // move constructor
	CmatComp &operator=(const CmatComp &rhs); // copy assignment
	CmatComp &operator=(CmatComp &&rhs); // move assignment
	Comp& operator()(Long_I i, Long_I j); // double indexing
	const Comp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatComp::CmatComp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatComp::CmatComp(const CmatComp &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatComp::CmatComp(CmatComp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatComp &CmatComp::operator=(const CmatComp &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatComp &CmatComp::operator=(CmatComp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Comp &CmatComp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatComp index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Comp &CmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatComp index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatComp::n0() const
{ return m_N0; }

inline Long CmatComp::n1() const
{ return m_N1; }

inline void CmatComp::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatComp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatComp resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatComp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatComp reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatComp &CmatComp_I;
typedef CmatComp &CmatComp_O, &CmatComp_IO;

// common api for STL and SLISC
inline Long size(CmatComp_I v) { return v.size(); }

inline const Comp *p(CmatComp_I v) { return v.p(); }

inline Comp *p(CmatComp &v) { return v.p(); }


class CmatLcomp : public VbaseLcomp
{
protected:
	typedef VbaseLcomp Base;
	Long m_N0, m_N1;
public:
	CmatLcomp(): m_N0(0), m_N1(0) {};
	CmatLcomp(Long_I N0, Long_I N1);
	CmatLcomp(const CmatLcomp &rhs); // copy constructor
	CmatLcomp(CmatLcomp &&rhs); // move constructor
	CmatLcomp &operator=(const CmatLcomp &rhs); // copy assignment
	CmatLcomp &operator=(CmatLcomp &&rhs); // move assignment
	Lcomp& operator()(Long_I i, Long_I j); // double indexing
	const Lcomp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatLcomp::CmatLcomp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatLcomp::CmatLcomp(const CmatLcomp &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatLcomp::CmatLcomp(CmatLcomp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatLcomp &CmatLcomp::operator=(const CmatLcomp &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatLcomp &CmatLcomp::operator=(CmatLcomp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Lcomp &CmatLcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatLcomp index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Lcomp &CmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatLcomp index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatLcomp::n0() const
{ return m_N0; }

inline Long CmatLcomp::n1() const
{ return m_N1; }

inline void CmatLcomp::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatLcomp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatLcomp resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatLcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatLcomp reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatLcomp &CmatLcomp_I;
typedef CmatLcomp &CmatLcomp_O, &CmatLcomp_IO;

// common api for STL and SLISC
inline Long size(CmatLcomp_I v) { return v.size(); }

inline const Lcomp *p(CmatLcomp_I v) { return v.p(); }

inline Lcomp *p(CmatLcomp &v) { return v.p(); }


class CmatQcomp : public VbaseQcomp
{
protected:
	typedef VbaseQcomp Base;
	Long m_N0, m_N1;
public:
	CmatQcomp(): m_N0(0), m_N1(0) {};
	CmatQcomp(Long_I N0, Long_I N1);
	CmatQcomp(const CmatQcomp &rhs); // copy constructor
	CmatQcomp(CmatQcomp &&rhs); // move constructor
	CmatQcomp &operator=(const CmatQcomp &rhs); // copy assignment
	CmatQcomp &operator=(CmatQcomp &&rhs); // move assignment
	Qcomp& operator()(Long_I i, Long_I j); // double indexing
	const Qcomp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatQcomp::CmatQcomp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatQcomp::CmatQcomp(const CmatQcomp &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatQcomp::CmatQcomp(CmatQcomp &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatQcomp &CmatQcomp::operator=(const CmatQcomp &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatQcomp &CmatQcomp::operator=(CmatQcomp &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Qcomp &CmatQcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatQcomp index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Qcomp &CmatQcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatQcomp index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatQcomp::n0() const
{ return m_N0; }

inline Long CmatQcomp::n1() const
{ return m_N1; }

inline void CmatQcomp::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatQcomp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatQcomp resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatQcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatQcomp reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatQcomp &CmatQcomp_I;
typedef CmatQcomp &CmatQcomp_O, &CmatQcomp_IO;

// common api for STL and SLISC
inline Long size(CmatQcomp_I v) { return v.size(); }

inline const Qcomp *p(CmatQcomp_I v) { return v.p(); }

inline Qcomp *p(CmatQcomp &v) { return v.p(); }


class CmatFimag : public VbaseFimag
{
protected:
	typedef VbaseFimag Base;
	Long m_N0, m_N1;
public:
	CmatFimag(): m_N0(0), m_N1(0) {};
	CmatFimag(Long_I N0, Long_I N1);
	CmatFimag(const CmatFimag &rhs); // copy constructor
	CmatFimag(CmatFimag &&rhs); // move constructor
	CmatFimag &operator=(const CmatFimag &rhs); // copy assignment
	CmatFimag &operator=(CmatFimag &&rhs); // move assignment
	Fimag& operator()(Long_I i, Long_I j); // double indexing
	const Fimag& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatFimag::CmatFimag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatFimag::CmatFimag(const CmatFimag &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatFimag::CmatFimag(CmatFimag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatFimag &CmatFimag::operator=(const CmatFimag &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatFimag &CmatFimag::operator=(CmatFimag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Fimag &CmatFimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatFimag index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Fimag &CmatFimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatFimag index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatFimag::n0() const
{ return m_N0; }

inline Long CmatFimag::n1() const
{ return m_N1; }

inline void CmatFimag::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatFimag::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatFimag resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatFimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatFimag reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatFimag &CmatFimag_I;
typedef CmatFimag &CmatFimag_O, &CmatFimag_IO;

// common api for STL and SLISC
inline Long size(CmatFimag_I v) { return v.size(); }

inline const Fimag *p(CmatFimag_I v) { return v.p(); }

inline Fimag *p(CmatFimag &v) { return v.p(); }


class CmatImag : public VbaseImag
{
protected:
	typedef VbaseImag Base;
	Long m_N0, m_N1;
public:
	CmatImag(): m_N0(0), m_N1(0) {};
	CmatImag(Long_I N0, Long_I N1);
	CmatImag(const CmatImag &rhs); // copy constructor
	CmatImag(CmatImag &&rhs); // move constructor
	CmatImag &operator=(const CmatImag &rhs); // copy assignment
	CmatImag &operator=(CmatImag &&rhs); // move assignment
	Imag& operator()(Long_I i, Long_I j); // double indexing
	const Imag& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatImag::CmatImag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatImag::CmatImag(const CmatImag &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatImag::CmatImag(CmatImag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatImag &CmatImag::operator=(const CmatImag &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatImag &CmatImag::operator=(CmatImag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Imag &CmatImag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatImag index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Imag &CmatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatImag index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatImag::n0() const
{ return m_N0; }

inline Long CmatImag::n1() const
{ return m_N1; }

inline void CmatImag::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatImag::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatImag resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatImag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatImag reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatImag &CmatImag_I;
typedef CmatImag &CmatImag_O, &CmatImag_IO;

// common api for STL and SLISC
inline Long size(CmatImag_I v) { return v.size(); }

inline const Imag *p(CmatImag_I v) { return v.p(); }

inline Imag *p(CmatImag &v) { return v.p(); }


class CmatLimag : public VbaseLimag
{
protected:
	typedef VbaseLimag Base;
	Long m_N0, m_N1;
public:
	CmatLimag(): m_N0(0), m_N1(0) {};
	CmatLimag(Long_I N0, Long_I N1);
	CmatLimag(const CmatLimag &rhs); // copy constructor
	CmatLimag(CmatLimag &&rhs); // move constructor
	CmatLimag &operator=(const CmatLimag &rhs); // copy assignment
	CmatLimag &operator=(CmatLimag &&rhs); // move assignment
	Limag& operator()(Long_I i, Long_I j); // double indexing
	const Limag& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatLimag::CmatLimag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatLimag::CmatLimag(const CmatLimag &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatLimag::CmatLimag(CmatLimag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatLimag &CmatLimag::operator=(const CmatLimag &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatLimag &CmatLimag::operator=(CmatLimag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Limag &CmatLimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatLimag index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Limag &CmatLimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatLimag index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatLimag::n0() const
{ return m_N0; }

inline Long CmatLimag::n1() const
{ return m_N1; }

inline void CmatLimag::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatLimag::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatLimag resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatLimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatLimag reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatLimag &CmatLimag_I;
typedef CmatLimag &CmatLimag_O, &CmatLimag_IO;

// common api for STL and SLISC
inline Long size(CmatLimag_I v) { return v.size(); }

inline const Limag *p(CmatLimag_I v) { return v.p(); }

inline Limag *p(CmatLimag &v) { return v.p(); }


class CmatQimag : public VbaseQimag
{
protected:
	typedef VbaseQimag Base;
	Long m_N0, m_N1;
public:
	CmatQimag(): m_N0(0), m_N1(0) {};
	CmatQimag(Long_I N0, Long_I N1);
	CmatQimag(const CmatQimag &rhs); // copy constructor
	CmatQimag(CmatQimag &&rhs); // move constructor
	CmatQimag &operator=(const CmatQimag &rhs); // copy assignment
	CmatQimag &operator=(CmatQimag &&rhs); // move assignment
	Qimag& operator()(Long_I i, Long_I j); // double indexing
	const Qimag& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (values not preserved)
	void resize(Long_I N); // resize memory only (values not preserved, N > N1*N2)
	void reshape(Long_I N0, Long_I N1); // reshape (N0*N1 <= m_N)
};

inline CmatQimag::CmatQimag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatQimag::CmatQimag(const CmatQimag &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline CmatQimag::CmatQimag(CmatQimag &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatQimag &CmatQimag::operator=(const CmatQimag &rhs)
{
	Base::operator=(rhs);
	resize(rhs.n0(), rhs.n1());
	return *this;
}

inline CmatQimag &CmatQimag::operator=(CmatQimag &&rhs)
{
	Base::operator=(move(rhs));
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
	return *this;
}

inline Qimag &CmatQimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatQimag index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return m_p[i+m_N0*j];
}

inline const Qimag &CmatQimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1) {
		stringstream ss; ss << "CmatQimag index (" << i << ", " << j
			<< ") out of bounds: shape = (" << m_N0 << ", " << m_N1 << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i+m_N0*j];
}

inline Long CmatQimag::n0() const
{ return m_N0; }

inline Long CmatQimag::n1() const
{ return m_N1; }

inline void CmatQimag::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

inline void CmatQimag::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N < m_N0*m_N1) {
		stringstream ss;
		ss  << "CmatQimag resizing from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to "
			<< N << " elements is illegal!";
		SLS_ERR(ss.str());
	}
#endif
	Base::resize(N);
}

inline void CmatQimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 < m_N) {
		stringstream ss;
		ss  << "CmatQimag reshaping from (" << m_N0 << ", " << m_N1
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< num2str(N1) << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

typedef const CmatQimag &CmatQimag_I;
typedef CmatQimag &CmatQimag_O, &CmatQimag_IO;

// common api for STL and SLISC
inline Long size(CmatQimag_I v) { return v.size(); }

inline const Qimag *p(CmatQimag_I v) { return v.p(); }

inline Qimag *p(CmatQimag &v) { return v.p(); }



#ifdef SLS_USE_INT_AS_LONG
typedef CmatInt CmatLong;
#else
typedef CmatLlong CmatLong;
#endif
typedef const CmatLong &CmatLong_I;
typedef CmatLong &CmatLong_O, &CmatLong_IO;

class CmatBool : public VbaseBool
{
protected:
	typedef VbaseBool Base;
	Long m_N0, m_N1;
public:
	CmatBool(): m_N0(0), m_N1(0) {};
	CmatBool(Long_I N0, Long_I N1);
	CmatBool(const CmatBool &rhs); // copy constructor
	CmatBool(CmatBool &&rhs); // move constructor
	CmatBool &operator=(const CmatBool &rhs) = delete;
	CmatBool::ref operator()(Long_I i, Long_I j);    // double indexing
	bool operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
};

inline CmatBool::CmatBool(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatBool::CmatBool(const CmatBool &rhs) : Base(rhs.size()), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
	Long N = size();
	for (Long i = 0; i < N; ++i)
		(*this)[i] = rhs[i];
}

inline CmatBool::CmatBool(CmatBool &&rhs)
	: Base(std::move(rhs)), m_N0(rhs.m_N0), m_N1(rhs.m_N1) {}

inline CmatBool::ref CmatBool::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatBool index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return (*this)[i+m_N0*j];
}

inline bool CmatBool::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("CmatBool index ("+num2str(i)+", "+num2str(j)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
	return (*this)[i+m_N0*j];
}

inline Long CmatBool::n0() const
{ return m_N0; }

inline Long CmatBool::n1() const
{ return m_N1; }

inline void CmatBool::resize(Long_I N0, Long_I N1)
{
	if (N0 != m_N0 || N1 != m_N1) {
		Base::resize(N0*N1);
		m_N0 = N0; m_N1 = N1;
	}
}

typedef const CmatBool &CmatBool_I;
typedef CmatBool &CmatBool_O, &CmatBool_IO;

} // namespace slisc
