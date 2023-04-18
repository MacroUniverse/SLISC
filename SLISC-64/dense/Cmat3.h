// Cmat container
#pragma once
#include "../dense/Vbase.h"

namespace slisc {
class Cmat3Char : public VbaseChar
{
protected:
	typedef VbaseChar Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Char(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Char(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Char(const Cmat3Char &rhs); // copy constructor
	Cmat3Char &operator=(const Cmat3Char &rhs) = delete;
	void operator<<(Cmat3Char &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Char &operator()(Long_I i, Long_I j, Long_I k);
	const Char &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Char::Cmat3Char(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Char::operator<<(Cmat3Char &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Char::Cmat3Char(const Cmat3Char &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Char::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Char &Cmat3Char::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Char index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Char &Cmat3Char::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Char index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Char &Cmat3Char_I;
typedef Cmat3Char &Cmat3Char_O, &Cmat3Char_IO;

// common api for STL and SLISC
inline Long size(Cmat3Char_I v) { return v.size(); }

inline const Char *p(Cmat3Char_I v) { return v.p(); }

inline Char *p(Cmat3Char &v) { return v.p(); }


class Cmat3Uchar : public VbaseUchar
{
protected:
	typedef VbaseUchar Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Uchar(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Uchar(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Uchar(const Cmat3Uchar &rhs); // copy constructor
	Cmat3Uchar &operator=(const Cmat3Uchar &rhs) = delete;
	void operator<<(Cmat3Uchar &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Uchar &operator()(Long_I i, Long_I j, Long_I k);
	const Uchar &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Uchar::Cmat3Uchar(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Uchar::operator<<(Cmat3Uchar &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Uchar::Cmat3Uchar(const Cmat3Uchar &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Uchar::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Uchar &Cmat3Uchar::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Uchar index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Uchar &Cmat3Uchar::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Uchar index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Uchar &Cmat3Uchar_I;
typedef Cmat3Uchar &Cmat3Uchar_O, &Cmat3Uchar_IO;

// common api for STL and SLISC
inline Long size(Cmat3Uchar_I v) { return v.size(); }

inline const Uchar *p(Cmat3Uchar_I v) { return v.p(); }

inline Uchar *p(Cmat3Uchar &v) { return v.p(); }


class Cmat3Int : public VbaseInt
{
protected:
	typedef VbaseInt Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Int(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Int(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Int(const Cmat3Int &rhs); // copy constructor
	Cmat3Int &operator=(const Cmat3Int &rhs) = delete;
	void operator<<(Cmat3Int &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Int &operator()(Long_I i, Long_I j, Long_I k);
	const Int &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Int::Cmat3Int(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Int::operator<<(Cmat3Int &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Int::Cmat3Int(const Cmat3Int &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Int::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Int &Cmat3Int::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Int index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Int &Cmat3Int::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Int index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Int &Cmat3Int_I;
typedef Cmat3Int &Cmat3Int_O, &Cmat3Int_IO;

// common api for STL and SLISC
inline Long size(Cmat3Int_I v) { return v.size(); }

inline const Int *p(Cmat3Int_I v) { return v.p(); }

inline Int *p(Cmat3Int &v) { return v.p(); }


class Cmat3Llong : public VbaseLlong
{
protected:
	typedef VbaseLlong Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Llong(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Llong(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Llong(const Cmat3Llong &rhs); // copy constructor
	Cmat3Llong &operator=(const Cmat3Llong &rhs) = delete;
	void operator<<(Cmat3Llong &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Llong &operator()(Long_I i, Long_I j, Long_I k);
	const Llong &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Llong::Cmat3Llong(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Llong::operator<<(Cmat3Llong &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Llong::Cmat3Llong(const Cmat3Llong &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Llong::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Llong &Cmat3Llong::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Llong index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Llong &Cmat3Llong::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Llong index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Llong &Cmat3Llong_I;
typedef Cmat3Llong &Cmat3Llong_O, &Cmat3Llong_IO;

// common api for STL and SLISC
inline Long size(Cmat3Llong_I v) { return v.size(); }

inline const Llong *p(Cmat3Llong_I v) { return v.p(); }

inline Llong *p(Cmat3Llong &v) { return v.p(); }


class Cmat3Float : public VbaseFloat
{
protected:
	typedef VbaseFloat Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Float(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Float(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Float(const Cmat3Float &rhs); // copy constructor
	Cmat3Float &operator=(const Cmat3Float &rhs) = delete;
	void operator<<(Cmat3Float &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Float &operator()(Long_I i, Long_I j, Long_I k);
	const Float &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Float::Cmat3Float(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Float::operator<<(Cmat3Float &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Float::Cmat3Float(const Cmat3Float &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Float::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Float &Cmat3Float::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Float index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Float &Cmat3Float::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Float index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Float &Cmat3Float_I;
typedef Cmat3Float &Cmat3Float_O, &Cmat3Float_IO;

// common api for STL and SLISC
inline Long size(Cmat3Float_I v) { return v.size(); }

inline const Float *p(Cmat3Float_I v) { return v.p(); }

inline Float *p(Cmat3Float &v) { return v.p(); }


class Cmat3Doub : public VbaseDoub
{
protected:
	typedef VbaseDoub Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Doub(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Doub(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Doub(const Cmat3Doub &rhs); // copy constructor
	Cmat3Doub &operator=(const Cmat3Doub &rhs) = delete;
	void operator<<(Cmat3Doub &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Doub &operator()(Long_I i, Long_I j, Long_I k);
	const Doub &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Doub::Cmat3Doub(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Doub::operator<<(Cmat3Doub &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Doub::Cmat3Doub(const Cmat3Doub &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Doub::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Doub &Cmat3Doub::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Doub index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Doub &Cmat3Doub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Doub index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Doub &Cmat3Doub_I;
typedef Cmat3Doub &Cmat3Doub_O, &Cmat3Doub_IO;

// common api for STL and SLISC
inline Long size(Cmat3Doub_I v) { return v.size(); }

inline const Doub *p(Cmat3Doub_I v) { return v.p(); }

inline Doub *p(Cmat3Doub &v) { return v.p(); }


class Cmat3Ldoub : public VbaseLdoub
{
protected:
	typedef VbaseLdoub Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Ldoub(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Ldoub(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Ldoub(const Cmat3Ldoub &rhs); // copy constructor
	Cmat3Ldoub &operator=(const Cmat3Ldoub &rhs) = delete;
	void operator<<(Cmat3Ldoub &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Ldoub &operator()(Long_I i, Long_I j, Long_I k);
	const Ldoub &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Ldoub::Cmat3Ldoub(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Ldoub::operator<<(Cmat3Ldoub &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Ldoub::Cmat3Ldoub(const Cmat3Ldoub &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Ldoub::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Ldoub &Cmat3Ldoub::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Ldoub index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Ldoub &Cmat3Ldoub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Ldoub index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Ldoub &Cmat3Ldoub_I;
typedef Cmat3Ldoub &Cmat3Ldoub_O, &Cmat3Ldoub_IO;

// common api for STL and SLISC
inline Long size(Cmat3Ldoub_I v) { return v.size(); }

inline const Ldoub *p(Cmat3Ldoub_I v) { return v.p(); }

inline Ldoub *p(Cmat3Ldoub &v) { return v.p(); }



class Cmat3Fcomp : public VbaseFcomp
{
protected:
	typedef VbaseFcomp Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Fcomp(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Fcomp(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Fcomp(const Cmat3Fcomp &rhs); // copy constructor
	Cmat3Fcomp &operator=(const Cmat3Fcomp &rhs) = delete;
	void operator<<(Cmat3Fcomp &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Fcomp &operator()(Long_I i, Long_I j, Long_I k);
	const Fcomp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Fcomp::Cmat3Fcomp(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Fcomp::operator<<(Cmat3Fcomp &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Fcomp::Cmat3Fcomp(const Cmat3Fcomp &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Fcomp::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Fcomp &Cmat3Fcomp::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Fcomp index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Fcomp &Cmat3Fcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Fcomp index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Fcomp &Cmat3Fcomp_I;
typedef Cmat3Fcomp &Cmat3Fcomp_O, &Cmat3Fcomp_IO;

// common api for STL and SLISC
inline Long size(Cmat3Fcomp_I v) { return v.size(); }

inline const Fcomp *p(Cmat3Fcomp_I v) { return v.p(); }

inline Fcomp *p(Cmat3Fcomp &v) { return v.p(); }


class Cmat3Comp : public VbaseComp
{
protected:
	typedef VbaseComp Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Comp(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Comp(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Comp(const Cmat3Comp &rhs); // copy constructor
	Cmat3Comp &operator=(const Cmat3Comp &rhs) = delete;
	void operator<<(Cmat3Comp &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Comp &operator()(Long_I i, Long_I j, Long_I k);
	const Comp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Comp::Cmat3Comp(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Comp::operator<<(Cmat3Comp &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Comp::Cmat3Comp(const Cmat3Comp &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Comp::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Comp &Cmat3Comp::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Comp index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Comp &Cmat3Comp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Comp index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Comp &Cmat3Comp_I;
typedef Cmat3Comp &Cmat3Comp_O, &Cmat3Comp_IO;

// common api for STL and SLISC
inline Long size(Cmat3Comp_I v) { return v.size(); }

inline const Comp *p(Cmat3Comp_I v) { return v.p(); }

inline Comp *p(Cmat3Comp &v) { return v.p(); }


class Cmat3Lcomp : public VbaseLcomp
{
protected:
	typedef VbaseLcomp Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Lcomp(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Lcomp(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Lcomp(const Cmat3Lcomp &rhs); // copy constructor
	Cmat3Lcomp &operator=(const Cmat3Lcomp &rhs) = delete;
	void operator<<(Cmat3Lcomp &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Lcomp &operator()(Long_I i, Long_I j, Long_I k);
	const Lcomp &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Lcomp::Cmat3Lcomp(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Lcomp::operator<<(Cmat3Lcomp &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Lcomp::Cmat3Lcomp(const Cmat3Lcomp &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Lcomp::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Lcomp &Cmat3Lcomp::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Lcomp index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Lcomp &Cmat3Lcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Lcomp index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Lcomp &Cmat3Lcomp_I;
typedef Cmat3Lcomp &Cmat3Lcomp_O, &Cmat3Lcomp_IO;

// common api for STL and SLISC
inline Long size(Cmat3Lcomp_I v) { return v.size(); }

inline const Lcomp *p(Cmat3Lcomp_I v) { return v.p(); }

inline Lcomp *p(Cmat3Lcomp &v) { return v.p(); }



class Cmat3Fimag : public VbaseFimag
{
protected:
	typedef VbaseFimag Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Fimag(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Fimag(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Fimag(const Cmat3Fimag &rhs); // copy constructor
	Cmat3Fimag &operator=(const Cmat3Fimag &rhs) = delete;
	void operator<<(Cmat3Fimag &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Fimag &operator()(Long_I i, Long_I j, Long_I k);
	const Fimag &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Fimag::Cmat3Fimag(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Fimag::operator<<(Cmat3Fimag &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Fimag::Cmat3Fimag(const Cmat3Fimag &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Fimag::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Fimag &Cmat3Fimag::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Fimag index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Fimag &Cmat3Fimag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Fimag index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Fimag &Cmat3Fimag_I;
typedef Cmat3Fimag &Cmat3Fimag_O, &Cmat3Fimag_IO;

// common api for STL and SLISC
inline Long size(Cmat3Fimag_I v) { return v.size(); }

inline const Fimag *p(Cmat3Fimag_I v) { return v.p(); }

inline Fimag *p(Cmat3Fimag &v) { return v.p(); }


class Cmat3Imag : public VbaseImag
{
protected:
	typedef VbaseImag Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Imag(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Imag(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Imag(const Cmat3Imag &rhs); // copy constructor
	Cmat3Imag &operator=(const Cmat3Imag &rhs) = delete;
	void operator<<(Cmat3Imag &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Imag &operator()(Long_I i, Long_I j, Long_I k);
	const Imag &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Imag::Cmat3Imag(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Imag::operator<<(Cmat3Imag &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Imag::Cmat3Imag(const Cmat3Imag &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Imag::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Imag &Cmat3Imag::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Imag index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Imag &Cmat3Imag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Imag index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Imag &Cmat3Imag_I;
typedef Cmat3Imag &Cmat3Imag_O, &Cmat3Imag_IO;

// common api for STL and SLISC
inline Long size(Cmat3Imag_I v) { return v.size(); }

inline const Imag *p(Cmat3Imag_I v) { return v.p(); }

inline Imag *p(Cmat3Imag &v) { return v.p(); }


class Cmat3Limag : public VbaseLimag
{
protected:
	typedef VbaseLimag Base;
	Long m_N0, m_N1, m_N2;
public:
	Cmat3Limag(): m_N0(0), m_N1(0), m_N2(0) {};
	Cmat3Limag(Long_I N0, Long_I N1, Long_I N2);
	Cmat3Limag(const Cmat3Limag &rhs); // copy constructor
	Cmat3Limag &operator=(const Cmat3Limag &rhs) = delete;
	void operator<<(Cmat3Limag &rhs); // move data and rhs.resize(0, 0, 0)
	void resize(Long_I N0, Long_I N1, Long_I N2);
	Limag &operator()(Long_I i, Long_I j, Long_I k);
	const Limag &operator()(Long_I i, Long_I j, Long_I k) const;
	Long n0() const;
	Long n1() const;
	Long n2() const;
};

inline Cmat3Limag::Cmat3Limag(Long_I N0, Long_I N1, Long_I N2) : Base(N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline void Cmat3Limag::operator<<(Cmat3Limag &rhs)
{
	m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
	rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
	Base::operator<<(rhs);
}

// copy constructor
inline Cmat3Limag::Cmat3Limag(const Cmat3Limag &rhs): Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat3Limag::resize(Long_I N0, Long_I N1, Long_I N2)
{
	if (N0 != m_N0 || N1 != m_N1 || N2 != m_N2) {
		Base::resize(N0*N1*N2);
		m_N0 = N0; m_N1 = N1; m_N2 = N2;
	}
}

inline Limag &Cmat3Limag::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Limag index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline const Limag &Cmat3Limag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Cmat3Limag index ("+num2str(i)+", "+num2str(j)+", "+num2str(k)
			+") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+")");
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
	return m_N2;
}

typedef const Cmat3Limag &Cmat3Limag_I;
typedef Cmat3Limag &Cmat3Limag_O, &Cmat3Limag_IO;

// common api for STL and SLISC
inline Long size(Cmat3Limag_I v) { return v.size(); }

inline const Limag *p(Cmat3Limag_I v) { return v.p(); }

inline Limag *p(Cmat3Limag &v) { return v.p(); }



#ifdef SLS_USE_INT_AS_LONG
typedef Cmat3Int Cmat3Long;
#else
typedef Cmat3Llong Cmat3Long;
#endif
typedef const Cmat3Long &Cmat3Long_I;
typedef Cmat3Long &Cmat3Long_O, &Cmat3Long_IO;

} // namespace slisc
