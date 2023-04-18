#pragma once
#include "../dense/Svec.h"

namespace slisc {
class Scmat3CharC : public SvbaseCharC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3CharC();
	Scmat3CharC(const Char *data, Long_I N0, Long_I N1, Long_I N2);


	const Char &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Char *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3CharC &sli);
	~Scmat3CharC();
};

inline Scmat3CharC::Scmat3CharC() {}

inline Scmat3CharC::Scmat3CharC(const Char *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseCharC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Char &Scmat3CharC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3CharC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3CharC::set(const Char *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseCharC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3CharC::set(const Scmat3CharC &sli)
{
	SvbaseCharC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3CharC::~Scmat3CharC() {}

typedef const Scmat3CharC &Scmat3Char_I;

// common api for STL and SLISC
inline Long size(Scmat3Char_I v) { return v.size(); }

inline const Char *p(Scmat3Char_I v) { return v.p(); }


class Scmat3Char : public SvbaseChar
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Char();
	Scmat3Char(Char *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3CharC() const;

	Char &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Char *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Char &sli);
	~Scmat3Char();
};

inline Scmat3Char::Scmat3Char() {}

inline Scmat3Char::Scmat3Char(Char *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseChar(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Char::operator Scmat3CharC() const
{
	return *((Scmat3CharC *)this);
}

inline Char &Scmat3Char::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Char::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Char::set(Char *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseChar::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Char::set(const Scmat3Char &sli)
{
	SvbaseChar::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Char::~Scmat3Char() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Char &Scmat3Char_O, &Scmat3Char_IO;

// common api for STL and SLISC
inline Char *p(Scmat3Char &v) { return v.p(); }


class Scmat3IntC : public SvbaseIntC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3IntC();
	Scmat3IntC(const Int *data, Long_I N0, Long_I N1, Long_I N2);


	const Int &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Int *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3IntC &sli);
	~Scmat3IntC();
};

inline Scmat3IntC::Scmat3IntC() {}

inline Scmat3IntC::Scmat3IntC(const Int *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseIntC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Int &Scmat3IntC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3IntC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3IntC::set(const Int *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseIntC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3IntC::set(const Scmat3IntC &sli)
{
	SvbaseIntC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3IntC::~Scmat3IntC() {}

typedef const Scmat3IntC &Scmat3Int_I;

// common api for STL and SLISC
inline Long size(Scmat3Int_I v) { return v.size(); }

inline const Int *p(Scmat3Int_I v) { return v.p(); }


class Scmat3Int : public SvbaseInt
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Int();
	Scmat3Int(Int *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3IntC() const;

	Int &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Int *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Int &sli);
	~Scmat3Int();
};

inline Scmat3Int::Scmat3Int() {}

inline Scmat3Int::Scmat3Int(Int *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseInt(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Int::operator Scmat3IntC() const
{
	return *((Scmat3IntC *)this);
}

inline Int &Scmat3Int::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Int::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Int::set(Int *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseInt::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Int::set(const Scmat3Int &sli)
{
	SvbaseInt::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Int::~Scmat3Int() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Int &Scmat3Int_O, &Scmat3Int_IO;

// common api for STL and SLISC
inline Int *p(Scmat3Int &v) { return v.p(); }


class Scmat3LlongC : public SvbaseLlongC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3LlongC();
	Scmat3LlongC(const Llong *data, Long_I N0, Long_I N1, Long_I N2);


	const Llong &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Llong *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3LlongC &sli);
	~Scmat3LlongC();
};

inline Scmat3LlongC::Scmat3LlongC() {}

inline Scmat3LlongC::Scmat3LlongC(const Llong *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLlongC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Llong &Scmat3LlongC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3LlongC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LlongC::set(const Llong *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLlongC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LlongC::set(const Scmat3LlongC &sli)
{
	SvbaseLlongC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3LlongC::~Scmat3LlongC() {}

typedef const Scmat3LlongC &Scmat3Llong_I;

// common api for STL and SLISC
inline Long size(Scmat3Llong_I v) { return v.size(); }

inline const Llong *p(Scmat3Llong_I v) { return v.p(); }


class Scmat3Llong : public SvbaseLlong
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Llong();
	Scmat3Llong(Llong *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3LlongC() const;

	Llong &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Llong *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Llong &sli);
	~Scmat3Llong();
};

inline Scmat3Llong::Scmat3Llong() {}

inline Scmat3Llong::Scmat3Llong(Llong *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLlong(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Llong::operator Scmat3LlongC() const
{
	return *((Scmat3LlongC *)this);
}

inline Llong &Scmat3Llong::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Llong::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Llong::set(Llong *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLlong::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Llong::set(const Scmat3Llong &sli)
{
	SvbaseLlong::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Llong::~Scmat3Llong() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Llong &Scmat3Llong_O, &Scmat3Llong_IO;

// common api for STL and SLISC
inline Llong *p(Scmat3Llong &v) { return v.p(); }


class Scmat3FloatC : public SvbaseFloatC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3FloatC();
	Scmat3FloatC(const Float *data, Long_I N0, Long_I N1, Long_I N2);


	const Float &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Float *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3FloatC &sli);
	~Scmat3FloatC();
};

inline Scmat3FloatC::Scmat3FloatC() {}

inline Scmat3FloatC::Scmat3FloatC(const Float *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFloatC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Float &Scmat3FloatC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3FloatC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3FloatC::set(const Float *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFloatC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3FloatC::set(const Scmat3FloatC &sli)
{
	SvbaseFloatC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3FloatC::~Scmat3FloatC() {}

typedef const Scmat3FloatC &Scmat3Float_I;

// common api for STL and SLISC
inline Long size(Scmat3Float_I v) { return v.size(); }

inline const Float *p(Scmat3Float_I v) { return v.p(); }


class Scmat3Float : public SvbaseFloat
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Float();
	Scmat3Float(Float *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3FloatC() const;

	Float &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Float *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Float &sli);
	~Scmat3Float();
};

inline Scmat3Float::Scmat3Float() {}

inline Scmat3Float::Scmat3Float(Float *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFloat(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Float::operator Scmat3FloatC() const
{
	return *((Scmat3FloatC *)this);
}

inline Float &Scmat3Float::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Float::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Float::set(Float *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFloat::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Float::set(const Scmat3Float &sli)
{
	SvbaseFloat::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Float::~Scmat3Float() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Float &Scmat3Float_O, &Scmat3Float_IO;

// common api for STL and SLISC
inline Float *p(Scmat3Float &v) { return v.p(); }


class Scmat3DoubC : public SvbaseDoubC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3DoubC();
	Scmat3DoubC(const Doub *data, Long_I N0, Long_I N1, Long_I N2);


	const Doub &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Doub *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3DoubC &sli);
	~Scmat3DoubC();
};

inline Scmat3DoubC::Scmat3DoubC() {}

inline Scmat3DoubC::Scmat3DoubC(const Doub *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseDoubC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Doub &Scmat3DoubC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3DoubC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3DoubC::set(const Doub *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseDoubC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3DoubC::set(const Scmat3DoubC &sli)
{
	SvbaseDoubC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3DoubC::~Scmat3DoubC() {}

typedef const Scmat3DoubC &Scmat3Doub_I;

// common api for STL and SLISC
inline Long size(Scmat3Doub_I v) { return v.size(); }

inline const Doub *p(Scmat3Doub_I v) { return v.p(); }


class Scmat3Doub : public SvbaseDoub
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Doub();
	Scmat3Doub(Doub *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3DoubC() const;

	Doub &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Doub *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Doub &sli);
	~Scmat3Doub();
};

inline Scmat3Doub::Scmat3Doub() {}

inline Scmat3Doub::Scmat3Doub(Doub *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseDoub(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Doub::operator Scmat3DoubC() const
{
	return *((Scmat3DoubC *)this);
}

inline Doub &Scmat3Doub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Doub::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Doub::set(Doub *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseDoub::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Doub::set(const Scmat3Doub &sli)
{
	SvbaseDoub::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Doub::~Scmat3Doub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Doub &Scmat3Doub_O, &Scmat3Doub_IO;

// common api for STL and SLISC
inline Doub *p(Scmat3Doub &v) { return v.p(); }




class Scmat3LdoubC : public SvbaseLdoubC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3LdoubC();
	Scmat3LdoubC(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2);


	const Ldoub &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3LdoubC &sli);
	~Scmat3LdoubC();
};

inline Scmat3LdoubC::Scmat3LdoubC() {}

inline Scmat3LdoubC::Scmat3LdoubC(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLdoubC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Ldoub &Scmat3LdoubC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3LdoubC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LdoubC::set(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLdoubC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LdoubC::set(const Scmat3LdoubC &sli)
{
	SvbaseLdoubC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3LdoubC::~Scmat3LdoubC() {}

typedef const Scmat3LdoubC &Scmat3Ldoub_I;

// common api for STL and SLISC
inline Long size(Scmat3Ldoub_I v) { return v.size(); }

inline const Ldoub *p(Scmat3Ldoub_I v) { return v.p(); }


class Scmat3Ldoub : public SvbaseLdoub
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Ldoub();
	Scmat3Ldoub(Ldoub *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3LdoubC() const;

	Ldoub &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Ldoub *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Ldoub &sli);
	~Scmat3Ldoub();
};

inline Scmat3Ldoub::Scmat3Ldoub() {}

inline Scmat3Ldoub::Scmat3Ldoub(Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLdoub(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Ldoub::operator Scmat3LdoubC() const
{
	return *((Scmat3LdoubC *)this);
}

inline Ldoub &Scmat3Ldoub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Ldoub::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Ldoub::set(Ldoub *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLdoub::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Ldoub::set(const Scmat3Ldoub &sli)
{
	SvbaseLdoub::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Ldoub::~Scmat3Ldoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Ldoub &Scmat3Ldoub_O, &Scmat3Ldoub_IO;

// common api for STL and SLISC
inline Ldoub *p(Scmat3Ldoub &v) { return v.p(); }


class Scmat3FcompC : public SvbaseFcompC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3FcompC();
	Scmat3FcompC(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2);


	const Fcomp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3FcompC &sli);
	~Scmat3FcompC();
};

inline Scmat3FcompC::Scmat3FcompC() {}

inline Scmat3FcompC::Scmat3FcompC(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFcompC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Fcomp &Scmat3FcompC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3FcompC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3FcompC::set(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFcompC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3FcompC::set(const Scmat3FcompC &sli)
{
	SvbaseFcompC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3FcompC::~Scmat3FcompC() {}

typedef const Scmat3FcompC &Scmat3Fcomp_I;

// common api for STL and SLISC
inline Long size(Scmat3Fcomp_I v) { return v.size(); }

inline const Fcomp *p(Scmat3Fcomp_I v) { return v.p(); }


class Scmat3Fcomp : public SvbaseFcomp
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Fcomp();
	Scmat3Fcomp(Fcomp *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3FcompC() const;

	Fcomp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Fcomp *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Fcomp &sli);
	~Scmat3Fcomp();
};

inline Scmat3Fcomp::Scmat3Fcomp() {}

inline Scmat3Fcomp::Scmat3Fcomp(Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFcomp(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Fcomp::operator Scmat3FcompC() const
{
	return *((Scmat3FcompC *)this);
}

inline Fcomp &Scmat3Fcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Fcomp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fcomp::set(Fcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFcomp::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fcomp::set(const Scmat3Fcomp &sli)
{
	SvbaseFcomp::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Fcomp::~Scmat3Fcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Fcomp &Scmat3Fcomp_O, &Scmat3Fcomp_IO;

// common api for STL and SLISC
inline Fcomp *p(Scmat3Fcomp &v) { return v.p(); }


class Scmat3CompC : public SvbaseCompC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3CompC();
	Scmat3CompC(const Comp *data, Long_I N0, Long_I N1, Long_I N2);


	const Comp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Comp *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3CompC &sli);
	~Scmat3CompC();
};

inline Scmat3CompC::Scmat3CompC() {}

inline Scmat3CompC::Scmat3CompC(const Comp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseCompC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Comp &Scmat3CompC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3CompC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3CompC::set(const Comp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseCompC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3CompC::set(const Scmat3CompC &sli)
{
	SvbaseCompC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3CompC::~Scmat3CompC() {}

typedef const Scmat3CompC &Scmat3Comp_I;

// common api for STL and SLISC
inline Long size(Scmat3Comp_I v) { return v.size(); }

inline const Comp *p(Scmat3Comp_I v) { return v.p(); }


class Scmat3Comp : public SvbaseComp
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Comp();
	Scmat3Comp(Comp *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3CompC() const;

	Comp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Comp *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Comp &sli);
	~Scmat3Comp();
};

inline Scmat3Comp::Scmat3Comp() {}

inline Scmat3Comp::Scmat3Comp(Comp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseComp(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Comp::operator Scmat3CompC() const
{
	return *((Scmat3CompC *)this);
}

inline Comp &Scmat3Comp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Comp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Comp::set(Comp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseComp::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Comp::set(const Scmat3Comp &sli)
{
	SvbaseComp::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Comp::~Scmat3Comp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Comp &Scmat3Comp_O, &Scmat3Comp_IO;

// common api for STL and SLISC
inline Comp *p(Scmat3Comp &v) { return v.p(); }


class Scmat3LcompC : public SvbaseLcompC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3LcompC();
	Scmat3LcompC(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2);


	const Lcomp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3LcompC &sli);
	~Scmat3LcompC();
};

inline Scmat3LcompC::Scmat3LcompC() {}

inline Scmat3LcompC::Scmat3LcompC(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLcompC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Lcomp &Scmat3LcompC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3LcompC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LcompC::set(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLcompC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LcompC::set(const Scmat3LcompC &sli)
{
	SvbaseLcompC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3LcompC::~Scmat3LcompC() {}

typedef const Scmat3LcompC &Scmat3Lcomp_I;

// common api for STL and SLISC
inline Long size(Scmat3Lcomp_I v) { return v.size(); }

inline const Lcomp *p(Scmat3Lcomp_I v) { return v.p(); }


class Scmat3Lcomp : public SvbaseLcomp
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Lcomp();
	Scmat3Lcomp(Lcomp *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3LcompC() const;

	Lcomp &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Lcomp *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Lcomp &sli);
	~Scmat3Lcomp();
};

inline Scmat3Lcomp::Scmat3Lcomp() {}

inline Scmat3Lcomp::Scmat3Lcomp(Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLcomp(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Lcomp::operator Scmat3LcompC() const
{
	return *((Scmat3LcompC *)this);
}

inline Lcomp &Scmat3Lcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Lcomp::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Lcomp::set(Lcomp *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLcomp::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Lcomp::set(const Scmat3Lcomp &sli)
{
	SvbaseLcomp::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Lcomp::~Scmat3Lcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Lcomp &Scmat3Lcomp_O, &Scmat3Lcomp_IO;

// common api for STL and SLISC
inline Lcomp *p(Scmat3Lcomp &v) { return v.p(); }




class Scmat3FimagC : public SvbaseFimagC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3FimagC();
	Scmat3FimagC(const Fimag *data, Long_I N0, Long_I N1, Long_I N2);


	const Fimag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Fimag *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3FimagC &sli);
	~Scmat3FimagC();
};

inline Scmat3FimagC::Scmat3FimagC() {}

inline Scmat3FimagC::Scmat3FimagC(const Fimag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFimagC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Fimag &Scmat3FimagC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3FimagC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3FimagC::set(const Fimag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFimagC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3FimagC::set(const Scmat3FimagC &sli)
{
	SvbaseFimagC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3FimagC::~Scmat3FimagC() {}

typedef const Scmat3FimagC &Scmat3Fimag_I;

// common api for STL and SLISC
inline Long size(Scmat3Fimag_I v) { return v.size(); }

inline const Fimag *p(Scmat3Fimag_I v) { return v.p(); }


class Scmat3Fimag : public SvbaseFimag
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Fimag();
	Scmat3Fimag(Fimag *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3FimagC() const;

	Fimag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Fimag *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Fimag &sli);
	~Scmat3Fimag();
};

inline Scmat3Fimag::Scmat3Fimag() {}

inline Scmat3Fimag::Scmat3Fimag(Fimag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseFimag(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Fimag::operator Scmat3FimagC() const
{
	return *((Scmat3FimagC *)this);
}

inline Fimag &Scmat3Fimag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Fimag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fimag::set(Fimag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseFimag::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fimag::set(const Scmat3Fimag &sli)
{
	SvbaseFimag::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Fimag::~Scmat3Fimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Fimag &Scmat3Fimag_O, &Scmat3Fimag_IO;

// common api for STL and SLISC
inline Fimag *p(Scmat3Fimag &v) { return v.p(); }


class Scmat3ImagC : public SvbaseImagC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3ImagC();
	Scmat3ImagC(const Imag *data, Long_I N0, Long_I N1, Long_I N2);


	const Imag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Imag *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3ImagC &sli);
	~Scmat3ImagC();
};

inline Scmat3ImagC::Scmat3ImagC() {}

inline Scmat3ImagC::Scmat3ImagC(const Imag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseImagC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Imag &Scmat3ImagC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3ImagC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3ImagC::set(const Imag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseImagC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3ImagC::set(const Scmat3ImagC &sli)
{
	SvbaseImagC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3ImagC::~Scmat3ImagC() {}

typedef const Scmat3ImagC &Scmat3Imag_I;

// common api for STL and SLISC
inline Long size(Scmat3Imag_I v) { return v.size(); }

inline const Imag *p(Scmat3Imag_I v) { return v.p(); }


class Scmat3Imag : public SvbaseImag
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Imag();
	Scmat3Imag(Imag *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3ImagC() const;

	Imag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Imag *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Imag &sli);
	~Scmat3Imag();
};

inline Scmat3Imag::Scmat3Imag() {}

inline Scmat3Imag::Scmat3Imag(Imag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseImag(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Imag::operator Scmat3ImagC() const
{
	return *((Scmat3ImagC *)this);
}

inline Imag &Scmat3Imag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Imag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Imag::set(Imag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseImag::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Imag::set(const Scmat3Imag &sli)
{
	SvbaseImag::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Imag::~Scmat3Imag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Imag &Scmat3Imag_O, &Scmat3Imag_IO;

// common api for STL and SLISC
inline Imag *p(Scmat3Imag &v) { return v.p(); }


class Scmat3LimagC : public SvbaseLimagC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3LimagC();
	Scmat3LimagC(const Limag *data, Long_I N0, Long_I N1, Long_I N2);


	const Limag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(const Limag *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3LimagC &sli);
	~Scmat3LimagC();
};

inline Scmat3LimagC::Scmat3LimagC() {}

inline Scmat3LimagC::Scmat3LimagC(const Limag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLimagC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}


inline const Limag &Scmat3LimagC::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3LimagC::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LimagC::set(const Limag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLimagC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LimagC::set(const Scmat3LimagC &sli)
{
	SvbaseLimagC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3LimagC::~Scmat3LimagC() {}

typedef const Scmat3LimagC &Scmat3Limag_I;

// common api for STL and SLISC
inline Long size(Scmat3Limag_I v) { return v.size(); }

inline const Limag *p(Scmat3Limag_I v) { return v.p(); }


class Scmat3Limag : public SvbaseLimag
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Limag();
	Scmat3Limag(Limag *data, Long_I N0, Long_I N1, Long_I N2);

	operator Scmat3LimagC() const;

	Limag &operator()(Long_I i, Long_I j, Long_I k) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2);
	void set(Limag *data, Long_I N0, Long_I N1, Long_I N2);
	void set(const Scmat3Limag &sli);
	~Scmat3Limag();
};

inline Scmat3Limag::Scmat3Limag() {}

inline Scmat3Limag::Scmat3Limag(Limag *data, Long_I N0, Long_I N1, Long_I N2)
	: SvbaseLimag(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Limag::operator Scmat3LimagC() const
{
	return *((Scmat3LimagC *)this);
}

inline Limag &Scmat3Limag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2)
		SLS_ERR("Matrix subscript out of bounds");
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
	return m_N2;
}

inline void Scmat3Limag::reshape(Long_I N0, Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Limag::set(Limag *data, Long_I N0, Long_I N1, Long_I N2)
{
	SvbaseLimag::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Limag::set(const Scmat3Limag &sli)
{
	SvbaseLimag::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Limag::~Scmat3Limag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Limag &Scmat3Limag_O, &Scmat3Limag_IO;

// common api for STL and SLISC
inline Limag *p(Scmat3Limag &v) { return v.p(); }



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
