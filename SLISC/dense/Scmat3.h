#pragma once
#include "../dense/Svec.h"

namespace slisc {
class Scmat3BoolC : public SvbaseBoolC
{
protected:
	typedef SvbaseBoolC Base;
	Long m_N0, m_N1;
public:
	Scmat3BoolC();
	Scmat3BoolC(const Bool *data, Long_I N0, Long_I N1, Long_I N2);


	const Bool &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Bool *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3BoolC();
};

inline Scmat3BoolC::Scmat3BoolC() {}

inline Scmat3BoolC::Scmat3BoolC(const Bool *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseBoolC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Bool &Scmat3BoolC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Bool index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3BoolC::n0() const
{
	return m_N0;
}

inline Long Scmat3BoolC::n1() const
{
	return m_N1;
}

inline Long Scmat3BoolC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3BoolC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Bool reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3BoolC::set(const Bool *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseBoolC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3BoolC::~Scmat3BoolC() {}

typedef const Scmat3BoolC &Scmat3Bool_I;


class Scmat3Bool : public SvbaseBool
{
protected:
	typedef SvbaseBool Base;
	Long m_N0, m_N1;
public:
	Scmat3Bool();
	Scmat3Bool(Bool *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3BoolC &() const;
	operator Scmat3BoolC &();

	Bool &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Bool *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Bool();
};

inline Scmat3Bool::Scmat3Bool() {}

inline Scmat3Bool::Scmat3Bool(Bool *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseBool(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Bool::operator const Scmat3BoolC &() const
{
	return reinterpret_cast<const Scmat3BoolC &>(*this);
}

inline Scmat3Bool::operator Scmat3BoolC &()
{
	return reinterpret_cast<Scmat3BoolC &>(*this);
}

inline Bool &Scmat3Bool::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Bool index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Bool::n0() const
{
	return m_N0;
}

inline Long Scmat3Bool::n1() const
{
	return m_N1;
}

inline Long Scmat3Bool::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Bool::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Bool reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Bool::set(Bool *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseBool::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Bool::~Scmat3Bool() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Bool &Scmat3Bool_O, &Scmat3Bool_IO;


class Scmat3CharC : public SvbaseCharC
{
protected:
	typedef SvbaseCharC Base;
	Long m_N0, m_N1;
public:
	Scmat3CharC();
	Scmat3CharC(const Char *data, Long_I N0, Long_I N1, Long_I N2);


	const Char &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Char *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3CharC();
};

inline Scmat3CharC::Scmat3CharC() {}

inline Scmat3CharC::Scmat3CharC(const Char *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseCharC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Char &Scmat3CharC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Char index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3CharC::n0() const
{
	return m_N0;
}

inline Long Scmat3CharC::n1() const
{
	return m_N1;
}

inline Long Scmat3CharC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3CharC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Char reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3CharC::set(const Char *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseCharC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3CharC::~Scmat3CharC() {}

typedef const Scmat3CharC &Scmat3Char_I;


class Scmat3Char : public SvbaseChar
{
protected:
	typedef SvbaseChar Base;
	Long m_N0, m_N1;
public:
	Scmat3Char();
	Scmat3Char(Char *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3CharC &() const;
	operator Scmat3CharC &();

	Char &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Char *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Char();
};

inline Scmat3Char::Scmat3Char() {}

inline Scmat3Char::Scmat3Char(Char *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseChar(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Char::operator const Scmat3CharC &() const
{
	return reinterpret_cast<const Scmat3CharC &>(*this);
}

inline Scmat3Char::operator Scmat3CharC &()
{
	return reinterpret_cast<Scmat3CharC &>(*this);
}

inline Char &Scmat3Char::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Char index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Char::n0() const
{
	return m_N0;
}

inline Long Scmat3Char::n1() const
{
	return m_N1;
}

inline Long Scmat3Char::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Char::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Char reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Char::set(Char *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseChar::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Char::~Scmat3Char() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Char &Scmat3Char_O, &Scmat3Char_IO;


class Scmat3UcharC : public SvbaseUcharC
{
protected:
	typedef SvbaseUcharC Base;
	Long m_N0, m_N1;
public:
	Scmat3UcharC();
	Scmat3UcharC(const Uchar *data, Long_I N0, Long_I N1, Long_I N2);


	const Uchar &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Uchar *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3UcharC();
};

inline Scmat3UcharC::Scmat3UcharC() {}

inline Scmat3UcharC::Scmat3UcharC(const Uchar *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseUcharC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Uchar &Scmat3UcharC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Uchar index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3UcharC::n0() const
{
	return m_N0;
}

inline Long Scmat3UcharC::n1() const
{
	return m_N1;
}

inline Long Scmat3UcharC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3UcharC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Uchar reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3UcharC::set(const Uchar *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseUcharC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3UcharC::~Scmat3UcharC() {}

typedef const Scmat3UcharC &Scmat3Uchar_I;


class Scmat3Uchar : public SvbaseUchar
{
protected:
	typedef SvbaseUchar Base;
	Long m_N0, m_N1;
public:
	Scmat3Uchar();
	Scmat3Uchar(Uchar *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3UcharC &() const;
	operator Scmat3UcharC &();

	Uchar &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Uchar *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Uchar();
};

inline Scmat3Uchar::Scmat3Uchar() {}

inline Scmat3Uchar::Scmat3Uchar(Uchar *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseUchar(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Uchar::operator const Scmat3UcharC &() const
{
	return reinterpret_cast<const Scmat3UcharC &>(*this);
}

inline Scmat3Uchar::operator Scmat3UcharC &()
{
	return reinterpret_cast<Scmat3UcharC &>(*this);
}

inline Uchar &Scmat3Uchar::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Uchar index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Uchar::n0() const
{
	return m_N0;
}

inline Long Scmat3Uchar::n1() const
{
	return m_N1;
}

inline Long Scmat3Uchar::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Uchar::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Uchar reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Uchar::set(Uchar *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseUchar::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Uchar::~Scmat3Uchar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Uchar &Scmat3Uchar_O, &Scmat3Uchar_IO;


class Scmat3IntC : public SvbaseIntC
{
protected:
	typedef SvbaseIntC Base;
	Long m_N0, m_N1;
public:
	Scmat3IntC();
	Scmat3IntC(const Int *data, Long_I N0, Long_I N1, Long_I N2);


	const Int &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Int *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3IntC();
};

inline Scmat3IntC::Scmat3IntC() {}

inline Scmat3IntC::Scmat3IntC(const Int *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseIntC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Int &Scmat3IntC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Int index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3IntC::n0() const
{
	return m_N0;
}

inline Long Scmat3IntC::n1() const
{
	return m_N1;
}

inline Long Scmat3IntC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3IntC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Int reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3IntC::set(const Int *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseIntC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3IntC::~Scmat3IntC() {}

typedef const Scmat3IntC &Scmat3Int_I;


class Scmat3Int : public SvbaseInt
{
protected:
	typedef SvbaseInt Base;
	Long m_N0, m_N1;
public:
	Scmat3Int();
	Scmat3Int(Int *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3IntC &() const;
	operator Scmat3IntC &();

	Int &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Int *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Int();
};

inline Scmat3Int::Scmat3Int() {}

inline Scmat3Int::Scmat3Int(Int *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseInt(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Int::operator const Scmat3IntC &() const
{
	return reinterpret_cast<const Scmat3IntC &>(*this);
}

inline Scmat3Int::operator Scmat3IntC &()
{
	return reinterpret_cast<Scmat3IntC &>(*this);
}

inline Int &Scmat3Int::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Int index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Int::n0() const
{
	return m_N0;
}

inline Long Scmat3Int::n1() const
{
	return m_N1;
}

inline Long Scmat3Int::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Int::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Int reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Int::set(Int *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseInt::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Int::~Scmat3Int() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Int &Scmat3Int_O, &Scmat3Int_IO;


class Scmat3LlongC : public SvbaseLlongC
{
protected:
	typedef SvbaseLlongC Base;
	Long m_N0, m_N1;
public:
	Scmat3LlongC();
	Scmat3LlongC(const Llong *data, Long_I N0, Long_I N1, Long_I N2);


	const Llong &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Llong *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3LlongC();
};

inline Scmat3LlongC::Scmat3LlongC() {}

inline Scmat3LlongC::Scmat3LlongC(const Llong *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLlongC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Llong &Scmat3LlongC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Llong index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3LlongC::n0() const
{
	return m_N0;
}

inline Long Scmat3LlongC::n1() const
{
	return m_N1;
}

inline Long Scmat3LlongC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3LlongC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Llong reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3LlongC::set(const Llong *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLlongC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3LlongC::~Scmat3LlongC() {}

typedef const Scmat3LlongC &Scmat3Llong_I;


class Scmat3Llong : public SvbaseLlong
{
protected:
	typedef SvbaseLlong Base;
	Long m_N0, m_N1;
public:
	Scmat3Llong();
	Scmat3Llong(Llong *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3LlongC &() const;
	operator Scmat3LlongC &();

	Llong &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Llong *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Llong();
};

inline Scmat3Llong::Scmat3Llong() {}

inline Scmat3Llong::Scmat3Llong(Llong *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLlong(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Llong::operator const Scmat3LlongC &() const
{
	return reinterpret_cast<const Scmat3LlongC &>(*this);
}

inline Scmat3Llong::operator Scmat3LlongC &()
{
	return reinterpret_cast<Scmat3LlongC &>(*this);
}

inline Llong &Scmat3Llong::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Llong index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Llong::n0() const
{
	return m_N0;
}

inline Long Scmat3Llong::n1() const
{
	return m_N1;
}

inline Long Scmat3Llong::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Llong::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Llong reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Llong::set(Llong *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLlong::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Llong::~Scmat3Llong() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Llong &Scmat3Llong_O, &Scmat3Llong_IO;


class Scmat3FloatC : public SvbaseFloatC
{
protected:
	typedef SvbaseFloatC Base;
	Long m_N0, m_N1;
public:
	Scmat3FloatC();
	Scmat3FloatC(const Float *data, Long_I N0, Long_I N1, Long_I N2);


	const Float &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Float *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3FloatC();
};

inline Scmat3FloatC::Scmat3FloatC() {}

inline Scmat3FloatC::Scmat3FloatC(const Float *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFloatC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Float &Scmat3FloatC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Float index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3FloatC::n0() const
{
	return m_N0;
}

inline Long Scmat3FloatC::n1() const
{
	return m_N1;
}

inline Long Scmat3FloatC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3FloatC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Float reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3FloatC::set(const Float *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFloatC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3FloatC::~Scmat3FloatC() {}

typedef const Scmat3FloatC &Scmat3Float_I;


class Scmat3Float : public SvbaseFloat
{
protected:
	typedef SvbaseFloat Base;
	Long m_N0, m_N1;
public:
	Scmat3Float();
	Scmat3Float(Float *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3FloatC &() const;
	operator Scmat3FloatC &();

	Float &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Float *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Float();
};

inline Scmat3Float::Scmat3Float() {}

inline Scmat3Float::Scmat3Float(Float *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFloat(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Float::operator const Scmat3FloatC &() const
{
	return reinterpret_cast<const Scmat3FloatC &>(*this);
}

inline Scmat3Float::operator Scmat3FloatC &()
{
	return reinterpret_cast<Scmat3FloatC &>(*this);
}

inline Float &Scmat3Float::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Float index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Float::n0() const
{
	return m_N0;
}

inline Long Scmat3Float::n1() const
{
	return m_N1;
}

inline Long Scmat3Float::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Float::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Float reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Float::set(Float *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFloat::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Float::~Scmat3Float() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Float &Scmat3Float_O, &Scmat3Float_IO;


class Scmat3DoubC : public SvbaseDoubC
{
protected:
	typedef SvbaseDoubC Base;
	Long m_N0, m_N1;
public:
	Scmat3DoubC();
	Scmat3DoubC(const Doub *data, Long_I N0, Long_I N1, Long_I N2);


	const Doub &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Doub *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3DoubC();
};

inline Scmat3DoubC::Scmat3DoubC() {}

inline Scmat3DoubC::Scmat3DoubC(const Doub *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseDoubC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Doub &Scmat3DoubC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Doub index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3DoubC::n0() const
{
	return m_N0;
}

inline Long Scmat3DoubC::n1() const
{
	return m_N1;
}

inline Long Scmat3DoubC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3DoubC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Doub reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3DoubC::set(const Doub *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseDoubC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3DoubC::~Scmat3DoubC() {}

typedef const Scmat3DoubC &Scmat3Doub_I;


class Scmat3Doub : public SvbaseDoub
{
protected:
	typedef SvbaseDoub Base;
	Long m_N0, m_N1;
public:
	Scmat3Doub();
	Scmat3Doub(Doub *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3DoubC &() const;
	operator Scmat3DoubC &();

	Doub &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Doub *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Doub();
};

inline Scmat3Doub::Scmat3Doub() {}

inline Scmat3Doub::Scmat3Doub(Doub *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseDoub(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Doub::operator const Scmat3DoubC &() const
{
	return reinterpret_cast<const Scmat3DoubC &>(*this);
}

inline Scmat3Doub::operator Scmat3DoubC &()
{
	return reinterpret_cast<Scmat3DoubC &>(*this);
}

inline Doub &Scmat3Doub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Doub index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Doub::n0() const
{
	return m_N0;
}

inline Long Scmat3Doub::n1() const
{
	return m_N1;
}

inline Long Scmat3Doub::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Doub::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Doub reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Doub::set(Doub *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseDoub::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Doub::~Scmat3Doub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Doub &Scmat3Doub_O, &Scmat3Doub_IO;




class Scmat3LdoubC : public SvbaseLdoubC
{
protected:
	typedef SvbaseLdoubC Base;
	Long m_N0, m_N1;
public:
	Scmat3LdoubC();
	Scmat3LdoubC(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2);


	const Ldoub &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3LdoubC();
};

inline Scmat3LdoubC::Scmat3LdoubC() {}

inline Scmat3LdoubC::Scmat3LdoubC(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLdoubC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Ldoub &Scmat3LdoubC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Ldoub index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3LdoubC::n0() const
{
	return m_N0;
}

inline Long Scmat3LdoubC::n1() const
{
	return m_N1;
}

inline Long Scmat3LdoubC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3LdoubC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Ldoub reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3LdoubC::set(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLdoubC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3LdoubC::~Scmat3LdoubC() {}

typedef const Scmat3LdoubC &Scmat3Ldoub_I;


class Scmat3Ldoub : public SvbaseLdoub
{
protected:
	typedef SvbaseLdoub Base;
	Long m_N0, m_N1;
public:
	Scmat3Ldoub();
	Scmat3Ldoub(Ldoub *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3LdoubC &() const;
	operator Scmat3LdoubC &();

	Ldoub &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Ldoub *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Ldoub();
};

inline Scmat3Ldoub::Scmat3Ldoub() {}

inline Scmat3Ldoub::Scmat3Ldoub(Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLdoub(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Ldoub::operator const Scmat3LdoubC &() const
{
	return reinterpret_cast<const Scmat3LdoubC &>(*this);
}

inline Scmat3Ldoub::operator Scmat3LdoubC &()
{
	return reinterpret_cast<Scmat3LdoubC &>(*this);
}

inline Ldoub &Scmat3Ldoub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Ldoub index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Ldoub::n0() const
{
	return m_N0;
}

inline Long Scmat3Ldoub::n1() const
{
	return m_N1;
}

inline Long Scmat3Ldoub::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Ldoub::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Ldoub reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Ldoub::set(Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLdoub::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Ldoub::~Scmat3Ldoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Ldoub &Scmat3Ldoub_O, &Scmat3Ldoub_IO;


class Scmat3FcompC : public SvbaseFcompC
{
protected:
	typedef SvbaseFcompC Base;
	Long m_N0, m_N1;
public:
	Scmat3FcompC();
	Scmat3FcompC(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2);


	const Fcomp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3FcompC();
};

inline Scmat3FcompC::Scmat3FcompC() {}

inline Scmat3FcompC::Scmat3FcompC(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFcompC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Fcomp &Scmat3FcompC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Fcomp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3FcompC::n0() const
{
	return m_N0;
}

inline Long Scmat3FcompC::n1() const
{
	return m_N1;
}

inline Long Scmat3FcompC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3FcompC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Fcomp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3FcompC::set(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFcompC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3FcompC::~Scmat3FcompC() {}

typedef const Scmat3FcompC &Scmat3Fcomp_I;


class Scmat3Fcomp : public SvbaseFcomp
{
protected:
	typedef SvbaseFcomp Base;
	Long m_N0, m_N1;
public:
	Scmat3Fcomp();
	Scmat3Fcomp(Fcomp *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3FcompC &() const;
	operator Scmat3FcompC &();

	Fcomp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Fcomp *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Fcomp();
};

inline Scmat3Fcomp::Scmat3Fcomp() {}

inline Scmat3Fcomp::Scmat3Fcomp(Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFcomp(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Fcomp::operator const Scmat3FcompC &() const
{
	return reinterpret_cast<const Scmat3FcompC &>(*this);
}

inline Scmat3Fcomp::operator Scmat3FcompC &()
{
	return reinterpret_cast<Scmat3FcompC &>(*this);
}

inline Fcomp &Scmat3Fcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Fcomp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Fcomp::n0() const
{
	return m_N0;
}

inline Long Scmat3Fcomp::n1() const
{
	return m_N1;
}

inline Long Scmat3Fcomp::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Fcomp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Fcomp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Fcomp::set(Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFcomp::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Fcomp::~Scmat3Fcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Fcomp &Scmat3Fcomp_O, &Scmat3Fcomp_IO;


class Scmat3CompC : public SvbaseCompC
{
protected:
	typedef SvbaseCompC Base;
	Long m_N0, m_N1;
public:
	Scmat3CompC();
	Scmat3CompC(const Comp *data, Long_I N0, Long_I N1, Long_I N2);


	const Comp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Comp *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3CompC();
};

inline Scmat3CompC::Scmat3CompC() {}

inline Scmat3CompC::Scmat3CompC(const Comp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseCompC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Comp &Scmat3CompC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Comp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3CompC::n0() const
{
	return m_N0;
}

inline Long Scmat3CompC::n1() const
{
	return m_N1;
}

inline Long Scmat3CompC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3CompC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Comp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3CompC::set(const Comp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseCompC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3CompC::~Scmat3CompC() {}

typedef const Scmat3CompC &Scmat3Comp_I;


class Scmat3Comp : public SvbaseComp
{
protected:
	typedef SvbaseComp Base;
	Long m_N0, m_N1;
public:
	Scmat3Comp();
	Scmat3Comp(Comp *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3CompC &() const;
	operator Scmat3CompC &();

	Comp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Comp *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Comp();
};

inline Scmat3Comp::Scmat3Comp() {}

inline Scmat3Comp::Scmat3Comp(Comp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseComp(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Comp::operator const Scmat3CompC &() const
{
	return reinterpret_cast<const Scmat3CompC &>(*this);
}

inline Scmat3Comp::operator Scmat3CompC &()
{
	return reinterpret_cast<Scmat3CompC &>(*this);
}

inline Comp &Scmat3Comp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Comp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Comp::n0() const
{
	return m_N0;
}

inline Long Scmat3Comp::n1() const
{
	return m_N1;
}

inline Long Scmat3Comp::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Comp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Comp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Comp::set(Comp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseComp::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Comp::~Scmat3Comp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Comp &Scmat3Comp_O, &Scmat3Comp_IO;


class Scmat3LcompC : public SvbaseLcompC
{
protected:
	typedef SvbaseLcompC Base;
	Long m_N0, m_N1;
public:
	Scmat3LcompC();
	Scmat3LcompC(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2);


	const Lcomp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3LcompC();
};

inline Scmat3LcompC::Scmat3LcompC() {}

inline Scmat3LcompC::Scmat3LcompC(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLcompC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Lcomp &Scmat3LcompC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Lcomp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3LcompC::n0() const
{
	return m_N0;
}

inline Long Scmat3LcompC::n1() const
{
	return m_N1;
}

inline Long Scmat3LcompC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3LcompC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Lcomp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3LcompC::set(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLcompC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3LcompC::~Scmat3LcompC() {}

typedef const Scmat3LcompC &Scmat3Lcomp_I;


class Scmat3Lcomp : public SvbaseLcomp
{
protected:
	typedef SvbaseLcomp Base;
	Long m_N0, m_N1;
public:
	Scmat3Lcomp();
	Scmat3Lcomp(Lcomp *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3LcompC &() const;
	operator Scmat3LcompC &();

	Lcomp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Lcomp *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Lcomp();
};

inline Scmat3Lcomp::Scmat3Lcomp() {}

inline Scmat3Lcomp::Scmat3Lcomp(Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLcomp(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Lcomp::operator const Scmat3LcompC &() const
{
	return reinterpret_cast<const Scmat3LcompC &>(*this);
}

inline Scmat3Lcomp::operator Scmat3LcompC &()
{
	return reinterpret_cast<Scmat3LcompC &>(*this);
}

inline Lcomp &Scmat3Lcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Lcomp index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Lcomp::n0() const
{
	return m_N0;
}

inline Long Scmat3Lcomp::n1() const
{
	return m_N1;
}

inline Long Scmat3Lcomp::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Lcomp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Lcomp reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Lcomp::set(Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLcomp::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Lcomp::~Scmat3Lcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Lcomp &Scmat3Lcomp_O, &Scmat3Lcomp_IO;




class Scmat3FimagC : public SvbaseFimagC
{
protected:
	typedef SvbaseFimagC Base;
	Long m_N0, m_N1;
public:
	Scmat3FimagC();
	Scmat3FimagC(const Fimag *data, Long_I N0, Long_I N1, Long_I N2);


	const Fimag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Fimag *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3FimagC();
};

inline Scmat3FimagC::Scmat3FimagC() {}

inline Scmat3FimagC::Scmat3FimagC(const Fimag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFimagC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Fimag &Scmat3FimagC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Fimag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3FimagC::n0() const
{
	return m_N0;
}

inline Long Scmat3FimagC::n1() const
{
	return m_N1;
}

inline Long Scmat3FimagC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3FimagC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Fimag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3FimagC::set(const Fimag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFimagC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3FimagC::~Scmat3FimagC() {}

typedef const Scmat3FimagC &Scmat3Fimag_I;


class Scmat3Fimag : public SvbaseFimag
{
protected:
	typedef SvbaseFimag Base;
	Long m_N0, m_N1;
public:
	Scmat3Fimag();
	Scmat3Fimag(Fimag *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3FimagC &() const;
	operator Scmat3FimagC &();

	Fimag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Fimag *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Fimag();
};

inline Scmat3Fimag::Scmat3Fimag() {}

inline Scmat3Fimag::Scmat3Fimag(Fimag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFimag(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Fimag::operator const Scmat3FimagC &() const
{
	return reinterpret_cast<const Scmat3FimagC &>(*this);
}

inline Scmat3Fimag::operator Scmat3FimagC &()
{
	return reinterpret_cast<Scmat3FimagC &>(*this);
}

inline Fimag &Scmat3Fimag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Fimag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Fimag::n0() const
{
	return m_N0;
}

inline Long Scmat3Fimag::n1() const
{
	return m_N1;
}

inline Long Scmat3Fimag::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Fimag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Fimag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Fimag::set(Fimag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFimag::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Fimag::~Scmat3Fimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Fimag &Scmat3Fimag_O, &Scmat3Fimag_IO;


class Scmat3ImagC : public SvbaseImagC
{
protected:
	typedef SvbaseImagC Base;
	Long m_N0, m_N1;
public:
	Scmat3ImagC();
	Scmat3ImagC(const Imag *data, Long_I N0, Long_I N1, Long_I N2);


	const Imag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Imag *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3ImagC();
};

inline Scmat3ImagC::Scmat3ImagC() {}

inline Scmat3ImagC::Scmat3ImagC(const Imag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseImagC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Imag &Scmat3ImagC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Imag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3ImagC::n0() const
{
	return m_N0;
}

inline Long Scmat3ImagC::n1() const
{
	return m_N1;
}

inline Long Scmat3ImagC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3ImagC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Imag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3ImagC::set(const Imag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseImagC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3ImagC::~Scmat3ImagC() {}

typedef const Scmat3ImagC &Scmat3Imag_I;


class Scmat3Imag : public SvbaseImag
{
protected:
	typedef SvbaseImag Base;
	Long m_N0, m_N1;
public:
	Scmat3Imag();
	Scmat3Imag(Imag *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3ImagC &() const;
	operator Scmat3ImagC &();

	Imag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Imag *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Imag();
};

inline Scmat3Imag::Scmat3Imag() {}

inline Scmat3Imag::Scmat3Imag(Imag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseImag(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Imag::operator const Scmat3ImagC &() const
{
	return reinterpret_cast<const Scmat3ImagC &>(*this);
}

inline Scmat3Imag::operator Scmat3ImagC &()
{
	return reinterpret_cast<Scmat3ImagC &>(*this);
}

inline Imag &Scmat3Imag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Imag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Imag::n0() const
{
	return m_N0;
}

inline Long Scmat3Imag::n1() const
{
	return m_N1;
}

inline Long Scmat3Imag::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Imag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Imag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Imag::set(Imag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseImag::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Imag::~Scmat3Imag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Imag &Scmat3Imag_O, &Scmat3Imag_IO;


class Scmat3LimagC : public SvbaseLimagC
{
protected:
	typedef SvbaseLimagC Base;
	Long m_N0, m_N1;
public:
	Scmat3LimagC();
	Scmat3LimagC(const Limag *data, Long_I N0, Long_I N1, Long_I N2);


	const Limag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Limag *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3LimagC();
};

inline Scmat3LimagC::Scmat3LimagC() {}

inline Scmat3LimagC::Scmat3LimagC(const Limag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLimagC(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}


inline const Limag &Scmat3LimagC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Limag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3LimagC::n0() const
{
	return m_N0;
}

inline Long Scmat3LimagC::n1() const
{
	return m_N1;
}

inline Long Scmat3LimagC::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3LimagC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Limag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3LimagC::set(const Limag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLimagC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3LimagC::~Scmat3LimagC() {}

typedef const Scmat3LimagC &Scmat3Limag_I;


class Scmat3Limag : public SvbaseLimag
{
protected:
	typedef SvbaseLimag Base;
	Long m_N0, m_N1;
public:
	Scmat3Limag();
	Scmat3Limag(Limag *data, Long_I N0, Long_I N1, Long_I N2);

	operator const Scmat3LimagC &() const;
	operator Scmat3LimagC &();

	Limag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	using Base::p;
	using Base::size;
	using Base::operator[];
	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Limag *data, Long_I N0, Long_I N1, Long_I N2);
	~Scmat3Limag();
};

inline Scmat3Limag::Scmat3Limag() {}

inline Scmat3Limag::Scmat3Limag(Limag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLimag(data, N0*N1*N2), m_N0(N0), m_N1(N1) {}

inline Scmat3Limag::operator const Scmat3LimagC &() const
{
	return reinterpret_cast<const Scmat3LimagC &>(*this);
}

inline Scmat3Limag::operator Scmat3LimagC &()
{
	return reinterpret_cast<Scmat3LimagC &>(*this);
}

inline Limag &Scmat3Limag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= n2()) {
		stringstream ss; ss << "Scmat3Limag index (" << i << ',' << j << ',' << k << ") out of bounds: shape = (" << m_N0 << ',' << m_N1 << ',' << n2() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat3Limag::n0() const
{
	return m_N0;
}

inline Long Scmat3Limag::n1() const
{
	return m_N1;
}

inline Long Scmat3Limag::n2() const
{
	return m_N == 0 ? 0 : m_N/(m_N0*m_N1);
}

inline void Scmat3Limag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N) {
		stringstream ss;
		ss  << "Scmat3Limag reshaping from (" << m_N0 << ',' << m_N1
			<< ',' << n2() << ") , with " << m_N << "allocated elements, to (" << N0 << ',' << N1
			<< ',' << N2 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void Scmat3Limag::set(Limag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLimag::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1;
}

inline Scmat3Limag::~Scmat3Limag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Limag &Scmat3Limag_O, &Scmat3Limag_IO;





#ifdef SLS_USE_INT_AS_LONG
typedef Scmat3Int Scmat3Long;
typedef Scmat3IntC Scmat3LongC;
#else
typedef Scmat3Llong Scmat3Long;
typedef Scmat3LlongC Scmat3LongC;
#endif

typedef const Scmat3LongC &Scmat3Long_I;
// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Long &Scmat3Long_O, &Scmat3Long_IO;

} // namespace slisc
