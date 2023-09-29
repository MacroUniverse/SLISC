#pragma once
#include "../dense/Svec.h"
#include "../dense/Cmat3.h"

namespace slisc {
class Scmat3CharC : public SvecCharC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3CharC();
	Scmat3CharC(const Char *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3CharC(Cmat3Char_I a);


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
	: SvecCharC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3CharC::Scmat3CharC(Cmat3Char_I a)
	: SvecCharC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecCharC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3CharC::set(const Scmat3CharC &sli)
{
	SvecCharC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3CharC::~Scmat3CharC() {}

typedef const Scmat3CharC &Scmat3Char_I;

// common api for STL and SLISC
inline Long size(Scmat3Char_I v) { return v.size(); }

inline const Char *p(Scmat3Char_I v) { return v.p(); }


class Scmat3Char : public SvecChar
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Char();
	Scmat3Char(Char *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Char(Cmat3Char_IO a);

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
	: SvecChar(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Char::Scmat3Char(Cmat3Char_IO a)
	: SvecChar(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecChar::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Char::set(const Scmat3Char &sli)
{
	SvecChar::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Char::~Scmat3Char() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Char &Scmat3Char_O, &Scmat3Char_IO;

// common api for STL and SLISC
inline Char *p(Scmat3Char &v) { return v.p(); }


class Scmat3IntC : public SvecIntC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3IntC();
	Scmat3IntC(const Int *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3IntC(Cmat3Int_I a);


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
	: SvecIntC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3IntC::Scmat3IntC(Cmat3Int_I a)
	: SvecIntC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecIntC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3IntC::set(const Scmat3IntC &sli)
{
	SvecIntC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3IntC::~Scmat3IntC() {}

typedef const Scmat3IntC &Scmat3Int_I;

// common api for STL and SLISC
inline Long size(Scmat3Int_I v) { return v.size(); }

inline const Int *p(Scmat3Int_I v) { return v.p(); }


class Scmat3Int : public SvecInt
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Int();
	Scmat3Int(Int *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Int(Cmat3Int_IO a);

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
	: SvecInt(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Int::Scmat3Int(Cmat3Int_IO a)
	: SvecInt(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecInt::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Int::set(const Scmat3Int &sli)
{
	SvecInt::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Int::~Scmat3Int() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Int &Scmat3Int_O, &Scmat3Int_IO;

// common api for STL and SLISC
inline Int *p(Scmat3Int &v) { return v.p(); }


class Scmat3LlongC : public SvecLlongC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3LlongC();
	Scmat3LlongC(const Llong *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3LlongC(Cmat3Llong_I a);


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
	: SvecLlongC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3LlongC::Scmat3LlongC(Cmat3Llong_I a)
	: SvecLlongC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecLlongC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LlongC::set(const Scmat3LlongC &sli)
{
	SvecLlongC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3LlongC::~Scmat3LlongC() {}

typedef const Scmat3LlongC &Scmat3Llong_I;

// common api for STL and SLISC
inline Long size(Scmat3Llong_I v) { return v.size(); }

inline const Llong *p(Scmat3Llong_I v) { return v.p(); }


class Scmat3Llong : public SvecLlong
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Llong();
	Scmat3Llong(Llong *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Llong(Cmat3Llong_IO a);

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
	: SvecLlong(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Llong::Scmat3Llong(Cmat3Llong_IO a)
	: SvecLlong(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecLlong::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Llong::set(const Scmat3Llong &sli)
{
	SvecLlong::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Llong::~Scmat3Llong() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Llong &Scmat3Llong_O, &Scmat3Llong_IO;

// common api for STL and SLISC
inline Llong *p(Scmat3Llong &v) { return v.p(); }


class Scmat3FloatC : public SvecFloatC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3FloatC();
	Scmat3FloatC(const Float *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3FloatC(Cmat3Float_I a);


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
	: SvecFloatC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3FloatC::Scmat3FloatC(Cmat3Float_I a)
	: SvecFloatC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecFloatC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3FloatC::set(const Scmat3FloatC &sli)
{
	SvecFloatC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3FloatC::~Scmat3FloatC() {}

typedef const Scmat3FloatC &Scmat3Float_I;

// common api for STL and SLISC
inline Long size(Scmat3Float_I v) { return v.size(); }

inline const Float *p(Scmat3Float_I v) { return v.p(); }


class Scmat3Float : public SvecFloat
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Float();
	Scmat3Float(Float *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Float(Cmat3Float_IO a);

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
	: SvecFloat(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Float::Scmat3Float(Cmat3Float_IO a)
	: SvecFloat(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecFloat::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Float::set(const Scmat3Float &sli)
{
	SvecFloat::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Float::~Scmat3Float() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Float &Scmat3Float_O, &Scmat3Float_IO;

// common api for STL and SLISC
inline Float *p(Scmat3Float &v) { return v.p(); }


class Scmat3DoubC : public SvecDoubC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3DoubC();
	Scmat3DoubC(const Doub *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3DoubC(Cmat3Doub_I a);


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
	: SvecDoubC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3DoubC::Scmat3DoubC(Cmat3Doub_I a)
	: SvecDoubC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecDoubC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3DoubC::set(const Scmat3DoubC &sli)
{
	SvecDoubC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3DoubC::~Scmat3DoubC() {}

typedef const Scmat3DoubC &Scmat3Doub_I;

// common api for STL and SLISC
inline Long size(Scmat3Doub_I v) { return v.size(); }

inline const Doub *p(Scmat3Doub_I v) { return v.p(); }


class Scmat3Doub : public SvecDoub
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Doub();
	Scmat3Doub(Doub *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Doub(Cmat3Doub_IO a);

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
	: SvecDoub(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Doub::Scmat3Doub(Cmat3Doub_IO a)
	: SvecDoub(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecDoub::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Doub::set(const Scmat3Doub &sli)
{
	SvecDoub::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Doub::~Scmat3Doub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Doub &Scmat3Doub_O, &Scmat3Doub_IO;

// common api for STL and SLISC
inline Doub *p(Scmat3Doub &v) { return v.p(); }




class Scmat3LdoubC : public SvecLdoubC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3LdoubC();
	Scmat3LdoubC(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3LdoubC(Cmat3Ldoub_I a);


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
	: SvecLdoubC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3LdoubC::Scmat3LdoubC(Cmat3Ldoub_I a)
	: SvecLdoubC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecLdoubC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LdoubC::set(const Scmat3LdoubC &sli)
{
	SvecLdoubC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3LdoubC::~Scmat3LdoubC() {}

typedef const Scmat3LdoubC &Scmat3Ldoub_I;

// common api for STL and SLISC
inline Long size(Scmat3Ldoub_I v) { return v.size(); }

inline const Ldoub *p(Scmat3Ldoub_I v) { return v.p(); }


class Scmat3Ldoub : public SvecLdoub
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Ldoub();
	Scmat3Ldoub(Ldoub *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Ldoub(Cmat3Ldoub_IO a);

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
	: SvecLdoub(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Ldoub::Scmat3Ldoub(Cmat3Ldoub_IO a)
	: SvecLdoub(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecLdoub::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Ldoub::set(const Scmat3Ldoub &sli)
{
	SvecLdoub::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Ldoub::~Scmat3Ldoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Ldoub &Scmat3Ldoub_O, &Scmat3Ldoub_IO;

// common api for STL and SLISC
inline Ldoub *p(Scmat3Ldoub &v) { return v.p(); }


class Scmat3FcompC : public SvecFcompC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3FcompC();
	Scmat3FcompC(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3FcompC(Cmat3Fcomp_I a);


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
	: SvecFcompC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3FcompC::Scmat3FcompC(Cmat3Fcomp_I a)
	: SvecFcompC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecFcompC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3FcompC::set(const Scmat3FcompC &sli)
{
	SvecFcompC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3FcompC::~Scmat3FcompC() {}

typedef const Scmat3FcompC &Scmat3Fcomp_I;

// common api for STL and SLISC
inline Long size(Scmat3Fcomp_I v) { return v.size(); }

inline const Fcomp *p(Scmat3Fcomp_I v) { return v.p(); }


class Scmat3Fcomp : public SvecFcomp
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Fcomp();
	Scmat3Fcomp(Fcomp *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Fcomp(Cmat3Fcomp_IO a);

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
	: SvecFcomp(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Fcomp::Scmat3Fcomp(Cmat3Fcomp_IO a)
	: SvecFcomp(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecFcomp::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fcomp::set(const Scmat3Fcomp &sli)
{
	SvecFcomp::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Fcomp::~Scmat3Fcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Fcomp &Scmat3Fcomp_O, &Scmat3Fcomp_IO;

// common api for STL and SLISC
inline Fcomp *p(Scmat3Fcomp &v) { return v.p(); }


class Scmat3CompC : public SvecCompC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3CompC();
	Scmat3CompC(const Comp *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3CompC(Cmat3Comp_I a);


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
	: SvecCompC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3CompC::Scmat3CompC(Cmat3Comp_I a)
	: SvecCompC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecCompC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3CompC::set(const Scmat3CompC &sli)
{
	SvecCompC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3CompC::~Scmat3CompC() {}

typedef const Scmat3CompC &Scmat3Comp_I;

// common api for STL and SLISC
inline Long size(Scmat3Comp_I v) { return v.size(); }

inline const Comp *p(Scmat3Comp_I v) { return v.p(); }


class Scmat3Comp : public SvecComp
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Comp();
	Scmat3Comp(Comp *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Comp(Cmat3Comp_IO a);

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
	: SvecComp(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Comp::Scmat3Comp(Cmat3Comp_IO a)
	: SvecComp(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecComp::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Comp::set(const Scmat3Comp &sli)
{
	SvecComp::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Comp::~Scmat3Comp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Comp &Scmat3Comp_O, &Scmat3Comp_IO;

// common api for STL and SLISC
inline Comp *p(Scmat3Comp &v) { return v.p(); }


class Scmat3LcompC : public SvecLcompC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3LcompC();
	Scmat3LcompC(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3LcompC(Cmat3Lcomp_I a);


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
	: SvecLcompC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3LcompC::Scmat3LcompC(Cmat3Lcomp_I a)
	: SvecLcompC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecLcompC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LcompC::set(const Scmat3LcompC &sli)
{
	SvecLcompC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3LcompC::~Scmat3LcompC() {}

typedef const Scmat3LcompC &Scmat3Lcomp_I;

// common api for STL and SLISC
inline Long size(Scmat3Lcomp_I v) { return v.size(); }

inline const Lcomp *p(Scmat3Lcomp_I v) { return v.p(); }


class Scmat3Lcomp : public SvecLcomp
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Lcomp();
	Scmat3Lcomp(Lcomp *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Lcomp(Cmat3Lcomp_IO a);

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
	: SvecLcomp(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Lcomp::Scmat3Lcomp(Cmat3Lcomp_IO a)
	: SvecLcomp(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecLcomp::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Lcomp::set(const Scmat3Lcomp &sli)
{
	SvecLcomp::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Lcomp::~Scmat3Lcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Lcomp &Scmat3Lcomp_O, &Scmat3Lcomp_IO;

// common api for STL and SLISC
inline Lcomp *p(Scmat3Lcomp &v) { return v.p(); }




class Scmat3FimagC : public SvecFimagC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3FimagC();
	Scmat3FimagC(const Fimag *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3FimagC(Cmat3Fimag_I a);


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
	: SvecFimagC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3FimagC::Scmat3FimagC(Cmat3Fimag_I a)
	: SvecFimagC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecFimagC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3FimagC::set(const Scmat3FimagC &sli)
{
	SvecFimagC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3FimagC::~Scmat3FimagC() {}

typedef const Scmat3FimagC &Scmat3Fimag_I;

// common api for STL and SLISC
inline Long size(Scmat3Fimag_I v) { return v.size(); }

inline const Fimag *p(Scmat3Fimag_I v) { return v.p(); }


class Scmat3Fimag : public SvecFimag
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Fimag();
	Scmat3Fimag(Fimag *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Fimag(Cmat3Fimag_IO a);

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
	: SvecFimag(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Fimag::Scmat3Fimag(Cmat3Fimag_IO a)
	: SvecFimag(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecFimag::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Fimag::set(const Scmat3Fimag &sli)
{
	SvecFimag::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Fimag::~Scmat3Fimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Fimag &Scmat3Fimag_O, &Scmat3Fimag_IO;

// common api for STL and SLISC
inline Fimag *p(Scmat3Fimag &v) { return v.p(); }


class Scmat3ImagC : public SvecImagC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3ImagC();
	Scmat3ImagC(const Imag *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3ImagC(Cmat3Imag_I a);


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
	: SvecImagC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3ImagC::Scmat3ImagC(Cmat3Imag_I a)
	: SvecImagC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecImagC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3ImagC::set(const Scmat3ImagC &sli)
{
	SvecImagC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3ImagC::~Scmat3ImagC() {}

typedef const Scmat3ImagC &Scmat3Imag_I;

// common api for STL and SLISC
inline Long size(Scmat3Imag_I v) { return v.size(); }

inline const Imag *p(Scmat3Imag_I v) { return v.p(); }


class Scmat3Imag : public SvecImag
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Imag();
	Scmat3Imag(Imag *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Imag(Cmat3Imag_IO a);

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
	: SvecImag(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Imag::Scmat3Imag(Cmat3Imag_IO a)
	: SvecImag(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecImag::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Imag::set(const Scmat3Imag &sli)
{
	SvecImag::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3Imag::~Scmat3Imag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat3Imag &Scmat3Imag_O, &Scmat3Imag_IO;

// common api for STL and SLISC
inline Imag *p(Scmat3Imag &v) { return v.p(); }


class Scmat3LimagC : public SvecLimagC
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3LimagC();
	Scmat3LimagC(const Limag *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3LimagC(Cmat3Limag_I a);


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
	: SvecLimagC(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3LimagC::Scmat3LimagC(Cmat3Limag_I a)
	: SvecLimagC(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}


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
	SvecLimagC::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3LimagC::set(const Scmat3LimagC &sli)
{
	SvecLimagC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline Scmat3LimagC::~Scmat3LimagC() {}

typedef const Scmat3LimagC &Scmat3Limag_I;

// common api for STL and SLISC
inline Long size(Scmat3Limag_I v) { return v.size(); }

inline const Limag *p(Scmat3Limag_I v) { return v.p(); }


class Scmat3Limag : public SvecLimag
{
protected:
	Long m_N0, m_N1, m_N2;
public:
	Scmat3Limag();
	Scmat3Limag(Limag *data, Long_I N0, Long_I N1, Long_I N2);
	Scmat3Limag(Cmat3Limag_IO a);

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
	: SvecLimag(data, N0*N1*N2), m_N0(N0), m_N1(N1), m_N2(N2) {}

inline Scmat3Limag::Scmat3Limag(Cmat3Limag_IO a)
	: SvecLimag(a.p(), a.n0()*a.n1()*a.n2()), m_N0(a.n0()), m_N1(a.n1()), m_N2(a.n2()) {}

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
	SvecLimag::set(data, N0*N1*N2);
	m_N0 = N0; m_N1 = N1; m_N2 = N2;
}

inline void Scmat3Limag::set(const Scmat3Limag &sli)
{
	SvecLimag::set(sli);
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
