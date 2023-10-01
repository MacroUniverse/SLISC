#pragma once
#include "../dense/Svec.h"

namespace slisc {
class Scmat4CharC : public SvecCharC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4CharC();
	Scmat4CharC(const Char *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Char &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Char *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4CharC();
};

inline Scmat4CharC::Scmat4CharC() {}

inline Scmat4CharC::Scmat4CharC(const Char *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecCharC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Char &Scmat4CharC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4CharC::n0() const
{
	return m_N0;
}

inline Long Scmat4CharC::n1() const
{
	return m_N1;
}

inline Long Scmat4CharC::n2() const
{
	return m_N2;
}

inline Long Scmat4CharC::n3() const
{
	return m_N3;
}

inline void Scmat4CharC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4CharC::set(const Char *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecCharC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4CharC::~Scmat4CharC() {}

typedef const Scmat4CharC &Scmat4Char_I;


class Scmat4Char : public SvecChar
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Char();
	Scmat4Char(Char *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4CharC &() const;
	operator Scmat4CharC &();

	Char &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Char *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Char();
};

inline Scmat4Char::Scmat4Char() {}

inline Scmat4Char::Scmat4Char(Char *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecChar(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Char::operator const Scmat4CharC &() const
{
	return reinterpret_cast<const Scmat4CharC &>(*this);
}

inline Scmat4Char::operator Scmat4CharC &()
{
	return reinterpret_cast<Scmat4CharC &>(*this);
}

inline Char &Scmat4Char::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Char::n0() const
{
	return m_N0;
}

inline Long Scmat4Char::n1() const
{
	return m_N1;
}

inline Long Scmat4Char::n2() const
{
	return m_N2;
}

inline Long Scmat4Char::n3() const
{
	return m_N3;
}

inline void Scmat4Char::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Char::set(Char *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecChar::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Char::~Scmat4Char() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Char &Scmat4Char_O, &Scmat4Char_IO;


class Scmat4UcharC : public SvecUcharC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4UcharC();
	Scmat4UcharC(const Uchar *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Uchar &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Uchar *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4UcharC();
};

inline Scmat4UcharC::Scmat4UcharC() {}

inline Scmat4UcharC::Scmat4UcharC(const Uchar *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecUcharC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Uchar &Scmat4UcharC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4UcharC::n0() const
{
	return m_N0;
}

inline Long Scmat4UcharC::n1() const
{
	return m_N1;
}

inline Long Scmat4UcharC::n2() const
{
	return m_N2;
}

inline Long Scmat4UcharC::n3() const
{
	return m_N3;
}

inline void Scmat4UcharC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4UcharC::set(const Uchar *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecUcharC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4UcharC::~Scmat4UcharC() {}

typedef const Scmat4UcharC &Scmat4Uchar_I;


class Scmat4Uchar : public SvecUchar
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Uchar();
	Scmat4Uchar(Uchar *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4UcharC &() const;
	operator Scmat4UcharC &();

	Uchar &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Uchar *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Uchar();
};

inline Scmat4Uchar::Scmat4Uchar() {}

inline Scmat4Uchar::Scmat4Uchar(Uchar *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecUchar(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Uchar::operator const Scmat4UcharC &() const
{
	return reinterpret_cast<const Scmat4UcharC &>(*this);
}

inline Scmat4Uchar::operator Scmat4UcharC &()
{
	return reinterpret_cast<Scmat4UcharC &>(*this);
}

inline Uchar &Scmat4Uchar::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Uchar::n0() const
{
	return m_N0;
}

inline Long Scmat4Uchar::n1() const
{
	return m_N1;
}

inline Long Scmat4Uchar::n2() const
{
	return m_N2;
}

inline Long Scmat4Uchar::n3() const
{
	return m_N3;
}

inline void Scmat4Uchar::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Uchar::set(Uchar *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecUchar::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Uchar::~Scmat4Uchar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Uchar &Scmat4Uchar_O, &Scmat4Uchar_IO;


class Scmat4IntC : public SvecIntC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4IntC();
	Scmat4IntC(const Int *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Int &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Int *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4IntC();
};

inline Scmat4IntC::Scmat4IntC() {}

inline Scmat4IntC::Scmat4IntC(const Int *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecIntC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Int &Scmat4IntC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4IntC::n0() const
{
	return m_N0;
}

inline Long Scmat4IntC::n1() const
{
	return m_N1;
}

inline Long Scmat4IntC::n2() const
{
	return m_N2;
}

inline Long Scmat4IntC::n3() const
{
	return m_N3;
}

inline void Scmat4IntC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4IntC::set(const Int *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecIntC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4IntC::~Scmat4IntC() {}

typedef const Scmat4IntC &Scmat4Int_I;


class Scmat4Int : public SvecInt
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Int();
	Scmat4Int(Int *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4IntC &() const;
	operator Scmat4IntC &();

	Int &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Int *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Int();
};

inline Scmat4Int::Scmat4Int() {}

inline Scmat4Int::Scmat4Int(Int *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecInt(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Int::operator const Scmat4IntC &() const
{
	return reinterpret_cast<const Scmat4IntC &>(*this);
}

inline Scmat4Int::operator Scmat4IntC &()
{
	return reinterpret_cast<Scmat4IntC &>(*this);
}

inline Int &Scmat4Int::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Int::n0() const
{
	return m_N0;
}

inline Long Scmat4Int::n1() const
{
	return m_N1;
}

inline Long Scmat4Int::n2() const
{
	return m_N2;
}

inline Long Scmat4Int::n3() const
{
	return m_N3;
}

inline void Scmat4Int::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Int::set(Int *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecInt::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Int::~Scmat4Int() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Int &Scmat4Int_O, &Scmat4Int_IO;


class Scmat4LlongC : public SvecLlongC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4LlongC();
	Scmat4LlongC(const Llong *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Llong &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Llong *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4LlongC();
};

inline Scmat4LlongC::Scmat4LlongC() {}

inline Scmat4LlongC::Scmat4LlongC(const Llong *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecLlongC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Llong &Scmat4LlongC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4LlongC::n0() const
{
	return m_N0;
}

inline Long Scmat4LlongC::n1() const
{
	return m_N1;
}

inline Long Scmat4LlongC::n2() const
{
	return m_N2;
}

inline Long Scmat4LlongC::n3() const
{
	return m_N3;
}

inline void Scmat4LlongC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4LlongC::set(const Llong *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecLlongC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4LlongC::~Scmat4LlongC() {}

typedef const Scmat4LlongC &Scmat4Llong_I;


class Scmat4Llong : public SvecLlong
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Llong();
	Scmat4Llong(Llong *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4LlongC &() const;
	operator Scmat4LlongC &();

	Llong &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Llong *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Llong();
};

inline Scmat4Llong::Scmat4Llong() {}

inline Scmat4Llong::Scmat4Llong(Llong *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecLlong(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Llong::operator const Scmat4LlongC &() const
{
	return reinterpret_cast<const Scmat4LlongC &>(*this);
}

inline Scmat4Llong::operator Scmat4LlongC &()
{
	return reinterpret_cast<Scmat4LlongC &>(*this);
}

inline Llong &Scmat4Llong::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Llong::n0() const
{
	return m_N0;
}

inline Long Scmat4Llong::n1() const
{
	return m_N1;
}

inline Long Scmat4Llong::n2() const
{
	return m_N2;
}

inline Long Scmat4Llong::n3() const
{
	return m_N3;
}

inline void Scmat4Llong::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Llong::set(Llong *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecLlong::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Llong::~Scmat4Llong() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Llong &Scmat4Llong_O, &Scmat4Llong_IO;


class Scmat4FloatC : public SvecFloatC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4FloatC();
	Scmat4FloatC(const Float *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Float &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Float *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4FloatC();
};

inline Scmat4FloatC::Scmat4FloatC() {}

inline Scmat4FloatC::Scmat4FloatC(const Float *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecFloatC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Float &Scmat4FloatC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4FloatC::n0() const
{
	return m_N0;
}

inline Long Scmat4FloatC::n1() const
{
	return m_N1;
}

inline Long Scmat4FloatC::n2() const
{
	return m_N2;
}

inline Long Scmat4FloatC::n3() const
{
	return m_N3;
}

inline void Scmat4FloatC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4FloatC::set(const Float *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecFloatC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4FloatC::~Scmat4FloatC() {}

typedef const Scmat4FloatC &Scmat4Float_I;


class Scmat4Float : public SvecFloat
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Float();
	Scmat4Float(Float *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4FloatC &() const;
	operator Scmat4FloatC &();

	Float &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Float *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Float();
};

inline Scmat4Float::Scmat4Float() {}

inline Scmat4Float::Scmat4Float(Float *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecFloat(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Float::operator const Scmat4FloatC &() const
{
	return reinterpret_cast<const Scmat4FloatC &>(*this);
}

inline Scmat4Float::operator Scmat4FloatC &()
{
	return reinterpret_cast<Scmat4FloatC &>(*this);
}

inline Float &Scmat4Float::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Float::n0() const
{
	return m_N0;
}

inline Long Scmat4Float::n1() const
{
	return m_N1;
}

inline Long Scmat4Float::n2() const
{
	return m_N2;
}

inline Long Scmat4Float::n3() const
{
	return m_N3;
}

inline void Scmat4Float::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Float::set(Float *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecFloat::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Float::~Scmat4Float() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Float &Scmat4Float_O, &Scmat4Float_IO;


class Scmat4DoubC : public SvecDoubC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4DoubC();
	Scmat4DoubC(const Doub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Doub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Doub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4DoubC();
};

inline Scmat4DoubC::Scmat4DoubC() {}

inline Scmat4DoubC::Scmat4DoubC(const Doub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecDoubC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Doub &Scmat4DoubC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4DoubC::n0() const
{
	return m_N0;
}

inline Long Scmat4DoubC::n1() const
{
	return m_N1;
}

inline Long Scmat4DoubC::n2() const
{
	return m_N2;
}

inline Long Scmat4DoubC::n3() const
{
	return m_N3;
}

inline void Scmat4DoubC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4DoubC::set(const Doub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecDoubC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4DoubC::~Scmat4DoubC() {}

typedef const Scmat4DoubC &Scmat4Doub_I;


class Scmat4Doub : public SvecDoub
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Doub();
	Scmat4Doub(Doub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4DoubC &() const;
	operator Scmat4DoubC &();

	Doub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Doub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Doub();
};

inline Scmat4Doub::Scmat4Doub() {}

inline Scmat4Doub::Scmat4Doub(Doub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecDoub(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Doub::operator const Scmat4DoubC &() const
{
	return reinterpret_cast<const Scmat4DoubC &>(*this);
}

inline Scmat4Doub::operator Scmat4DoubC &()
{
	return reinterpret_cast<Scmat4DoubC &>(*this);
}

inline Doub &Scmat4Doub::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Doub::n0() const
{
	return m_N0;
}

inline Long Scmat4Doub::n1() const
{
	return m_N1;
}

inline Long Scmat4Doub::n2() const
{
	return m_N2;
}

inline Long Scmat4Doub::n3() const
{
	return m_N3;
}

inline void Scmat4Doub::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Doub::set(Doub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecDoub::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Doub::~Scmat4Doub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Doub &Scmat4Doub_O, &Scmat4Doub_IO;




class Scmat4LdoubC : public SvecLdoubC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4LdoubC();
	Scmat4LdoubC(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Ldoub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4LdoubC();
};

inline Scmat4LdoubC::Scmat4LdoubC() {}

inline Scmat4LdoubC::Scmat4LdoubC(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecLdoubC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Ldoub &Scmat4LdoubC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4LdoubC::n0() const
{
	return m_N0;
}

inline Long Scmat4LdoubC::n1() const
{
	return m_N1;
}

inline Long Scmat4LdoubC::n2() const
{
	return m_N2;
}

inline Long Scmat4LdoubC::n3() const
{
	return m_N3;
}

inline void Scmat4LdoubC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4LdoubC::set(const Ldoub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecLdoubC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4LdoubC::~Scmat4LdoubC() {}

typedef const Scmat4LdoubC &Scmat4Ldoub_I;


class Scmat4Ldoub : public SvecLdoub
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Ldoub();
	Scmat4Ldoub(Ldoub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4LdoubC &() const;
	operator Scmat4LdoubC &();

	Ldoub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Ldoub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Ldoub();
};

inline Scmat4Ldoub::Scmat4Ldoub() {}

inline Scmat4Ldoub::Scmat4Ldoub(Ldoub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecLdoub(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Ldoub::operator const Scmat4LdoubC &() const
{
	return reinterpret_cast<const Scmat4LdoubC &>(*this);
}

inline Scmat4Ldoub::operator Scmat4LdoubC &()
{
	return reinterpret_cast<Scmat4LdoubC &>(*this);
}

inline Ldoub &Scmat4Ldoub::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Ldoub::n0() const
{
	return m_N0;
}

inline Long Scmat4Ldoub::n1() const
{
	return m_N1;
}

inline Long Scmat4Ldoub::n2() const
{
	return m_N2;
}

inline Long Scmat4Ldoub::n3() const
{
	return m_N3;
}

inline void Scmat4Ldoub::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Ldoub::set(Ldoub *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecLdoub::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Ldoub::~Scmat4Ldoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Ldoub &Scmat4Ldoub_O, &Scmat4Ldoub_IO;


class Scmat4FcompC : public SvecFcompC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4FcompC();
	Scmat4FcompC(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Fcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4FcompC();
};

inline Scmat4FcompC::Scmat4FcompC() {}

inline Scmat4FcompC::Scmat4FcompC(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecFcompC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Fcomp &Scmat4FcompC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4FcompC::n0() const
{
	return m_N0;
}

inline Long Scmat4FcompC::n1() const
{
	return m_N1;
}

inline Long Scmat4FcompC::n2() const
{
	return m_N2;
}

inline Long Scmat4FcompC::n3() const
{
	return m_N3;
}

inline void Scmat4FcompC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4FcompC::set(const Fcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecFcompC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4FcompC::~Scmat4FcompC() {}

typedef const Scmat4FcompC &Scmat4Fcomp_I;


class Scmat4Fcomp : public SvecFcomp
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Fcomp();
	Scmat4Fcomp(Fcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4FcompC &() const;
	operator Scmat4FcompC &();

	Fcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Fcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Fcomp();
};

inline Scmat4Fcomp::Scmat4Fcomp() {}

inline Scmat4Fcomp::Scmat4Fcomp(Fcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecFcomp(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Fcomp::operator const Scmat4FcompC &() const
{
	return reinterpret_cast<const Scmat4FcompC &>(*this);
}

inline Scmat4Fcomp::operator Scmat4FcompC &()
{
	return reinterpret_cast<Scmat4FcompC &>(*this);
}

inline Fcomp &Scmat4Fcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Fcomp::n0() const
{
	return m_N0;
}

inline Long Scmat4Fcomp::n1() const
{
	return m_N1;
}

inline Long Scmat4Fcomp::n2() const
{
	return m_N2;
}

inline Long Scmat4Fcomp::n3() const
{
	return m_N3;
}

inline void Scmat4Fcomp::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Fcomp::set(Fcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecFcomp::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Fcomp::~Scmat4Fcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Fcomp &Scmat4Fcomp_O, &Scmat4Fcomp_IO;


class Scmat4CompC : public SvecCompC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4CompC();
	Scmat4CompC(const Comp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Comp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Comp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4CompC();
};

inline Scmat4CompC::Scmat4CompC() {}

inline Scmat4CompC::Scmat4CompC(const Comp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecCompC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Comp &Scmat4CompC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4CompC::n0() const
{
	return m_N0;
}

inline Long Scmat4CompC::n1() const
{
	return m_N1;
}

inline Long Scmat4CompC::n2() const
{
	return m_N2;
}

inline Long Scmat4CompC::n3() const
{
	return m_N3;
}

inline void Scmat4CompC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4CompC::set(const Comp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecCompC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4CompC::~Scmat4CompC() {}

typedef const Scmat4CompC &Scmat4Comp_I;


class Scmat4Comp : public SvecComp
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Comp();
	Scmat4Comp(Comp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4CompC &() const;
	operator Scmat4CompC &();

	Comp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Comp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Comp();
};

inline Scmat4Comp::Scmat4Comp() {}

inline Scmat4Comp::Scmat4Comp(Comp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecComp(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Comp::operator const Scmat4CompC &() const
{
	return reinterpret_cast<const Scmat4CompC &>(*this);
}

inline Scmat4Comp::operator Scmat4CompC &()
{
	return reinterpret_cast<Scmat4CompC &>(*this);
}

inline Comp &Scmat4Comp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Comp::n0() const
{
	return m_N0;
}

inline Long Scmat4Comp::n1() const
{
	return m_N1;
}

inline Long Scmat4Comp::n2() const
{
	return m_N2;
}

inline Long Scmat4Comp::n3() const
{
	return m_N3;
}

inline void Scmat4Comp::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Comp::set(Comp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecComp::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Comp::~Scmat4Comp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Comp &Scmat4Comp_O, &Scmat4Comp_IO;


class Scmat4LcompC : public SvecLcompC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4LcompC();
	Scmat4LcompC(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Lcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4LcompC();
};

inline Scmat4LcompC::Scmat4LcompC() {}

inline Scmat4LcompC::Scmat4LcompC(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecLcompC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Lcomp &Scmat4LcompC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4LcompC::n0() const
{
	return m_N0;
}

inline Long Scmat4LcompC::n1() const
{
	return m_N1;
}

inline Long Scmat4LcompC::n2() const
{
	return m_N2;
}

inline Long Scmat4LcompC::n3() const
{
	return m_N3;
}

inline void Scmat4LcompC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4LcompC::set(const Lcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecLcompC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4LcompC::~Scmat4LcompC() {}

typedef const Scmat4LcompC &Scmat4Lcomp_I;


class Scmat4Lcomp : public SvecLcomp
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Lcomp();
	Scmat4Lcomp(Lcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4LcompC &() const;
	operator Scmat4LcompC &();

	Lcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Lcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Lcomp();
};

inline Scmat4Lcomp::Scmat4Lcomp() {}

inline Scmat4Lcomp::Scmat4Lcomp(Lcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecLcomp(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Lcomp::operator const Scmat4LcompC &() const
{
	return reinterpret_cast<const Scmat4LcompC &>(*this);
}

inline Scmat4Lcomp::operator Scmat4LcompC &()
{
	return reinterpret_cast<Scmat4LcompC &>(*this);
}

inline Lcomp &Scmat4Lcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Lcomp::n0() const
{
	return m_N0;
}

inline Long Scmat4Lcomp::n1() const
{
	return m_N1;
}

inline Long Scmat4Lcomp::n2() const
{
	return m_N2;
}

inline Long Scmat4Lcomp::n3() const
{
	return m_N3;
}

inline void Scmat4Lcomp::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Lcomp::set(Lcomp *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecLcomp::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Lcomp::~Scmat4Lcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Lcomp &Scmat4Lcomp_O, &Scmat4Lcomp_IO;




class Scmat4FimagC : public SvecFimagC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4FimagC();
	Scmat4FimagC(const Fimag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Fimag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Fimag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4FimagC();
};

inline Scmat4FimagC::Scmat4FimagC() {}

inline Scmat4FimagC::Scmat4FimagC(const Fimag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecFimagC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Fimag &Scmat4FimagC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4FimagC::n0() const
{
	return m_N0;
}

inline Long Scmat4FimagC::n1() const
{
	return m_N1;
}

inline Long Scmat4FimagC::n2() const
{
	return m_N2;
}

inline Long Scmat4FimagC::n3() const
{
	return m_N3;
}

inline void Scmat4FimagC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4FimagC::set(const Fimag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecFimagC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4FimagC::~Scmat4FimagC() {}

typedef const Scmat4FimagC &Scmat4Fimag_I;


class Scmat4Fimag : public SvecFimag
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Fimag();
	Scmat4Fimag(Fimag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4FimagC &() const;
	operator Scmat4FimagC &();

	Fimag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Fimag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Fimag();
};

inline Scmat4Fimag::Scmat4Fimag() {}

inline Scmat4Fimag::Scmat4Fimag(Fimag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecFimag(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Fimag::operator const Scmat4FimagC &() const
{
	return reinterpret_cast<const Scmat4FimagC &>(*this);
}

inline Scmat4Fimag::operator Scmat4FimagC &()
{
	return reinterpret_cast<Scmat4FimagC &>(*this);
}

inline Fimag &Scmat4Fimag::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Fimag::n0() const
{
	return m_N0;
}

inline Long Scmat4Fimag::n1() const
{
	return m_N1;
}

inline Long Scmat4Fimag::n2() const
{
	return m_N2;
}

inline Long Scmat4Fimag::n3() const
{
	return m_N3;
}

inline void Scmat4Fimag::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Fimag::set(Fimag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecFimag::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Fimag::~Scmat4Fimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Fimag &Scmat4Fimag_O, &Scmat4Fimag_IO;


class Scmat4ImagC : public SvecImagC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4ImagC();
	Scmat4ImagC(const Imag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Imag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Imag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4ImagC();
};

inline Scmat4ImagC::Scmat4ImagC() {}

inline Scmat4ImagC::Scmat4ImagC(const Imag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecImagC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Imag &Scmat4ImagC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4ImagC::n0() const
{
	return m_N0;
}

inline Long Scmat4ImagC::n1() const
{
	return m_N1;
}

inline Long Scmat4ImagC::n2() const
{
	return m_N2;
}

inline Long Scmat4ImagC::n3() const
{
	return m_N3;
}

inline void Scmat4ImagC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4ImagC::set(const Imag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecImagC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4ImagC::~Scmat4ImagC() {}

typedef const Scmat4ImagC &Scmat4Imag_I;


class Scmat4Imag : public SvecImag
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Imag();
	Scmat4Imag(Imag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4ImagC &() const;
	operator Scmat4ImagC &();

	Imag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Imag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Imag();
};

inline Scmat4Imag::Scmat4Imag() {}

inline Scmat4Imag::Scmat4Imag(Imag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecImag(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Imag::operator const Scmat4ImagC &() const
{
	return reinterpret_cast<const Scmat4ImagC &>(*this);
}

inline Scmat4Imag::operator Scmat4ImagC &()
{
	return reinterpret_cast<Scmat4ImagC &>(*this);
}

inline Imag &Scmat4Imag::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Imag::n0() const
{
	return m_N0;
}

inline Long Scmat4Imag::n1() const
{
	return m_N1;
}

inline Long Scmat4Imag::n2() const
{
	return m_N2;
}

inline Long Scmat4Imag::n3() const
{
	return m_N3;
}

inline void Scmat4Imag::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Imag::set(Imag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecImag::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Imag::~Scmat4Imag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Imag &Scmat4Imag_O, &Scmat4Imag_IO;


class Scmat4LimagC : public SvecLimagC
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4LimagC();
	Scmat4LimagC(const Limag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);


	const Limag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(const Limag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4LimagC();
};

inline Scmat4LimagC::Scmat4LimagC() {}

inline Scmat4LimagC::Scmat4LimagC(const Limag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecLimagC(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}


inline const Limag &Scmat4LimagC::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4LimagC::n0() const
{
	return m_N0;
}

inline Long Scmat4LimagC::n1() const
{
	return m_N1;
}

inline Long Scmat4LimagC::n2() const
{
	return m_N2;
}

inline Long Scmat4LimagC::n3() const
{
	return m_N3;
}

inline void Scmat4LimagC::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4LimagC::set(const Limag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecLimagC::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4LimagC::~Scmat4LimagC() {}

typedef const Scmat4LimagC &Scmat4Limag_I;


class Scmat4Limag : public SvecLimag
{
protected:
	Long m_N0, m_N1, m_N2, m_N3;
public:
	Scmat4Limag();
	Scmat4Limag(Limag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);

	operator const Scmat4LimagC &() const;
	operator Scmat4LimagC &();

	Limag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;

	Long n0() const;
	Long n1() const;
	Long n2() const;
	Long n3() const;

	// resize() is a bad idea, don't try to create it!
	void reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	void set(Limag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3);
	~Scmat4Limag();
};

inline Scmat4Limag::Scmat4Limag() {}

inline Scmat4Limag::Scmat4Limag(Limag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
	: SvecLimag(data, N0*N1*N2*N3), m_N0(N0), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline Scmat4Limag::operator const Scmat4LimagC &() const
{
	return reinterpret_cast<const Scmat4LimagC &>(*this);
}

inline Scmat4Limag::operator Scmat4LimagC &()
{
	return reinterpret_cast<Scmat4LimagC &>(*this);
}

inline Limag &Scmat4Limag::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 || k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0*j + m_N0*m_N1*k];
}

inline Long Scmat4Limag::n0() const
{
	return m_N0;
}

inline Long Scmat4Limag::n1() const
{
	return m_N1;
}

inline Long Scmat4Limag::n2() const
{
	return m_N2;
}

inline Long Scmat4Limag::n3() const
{
	return m_N3;
}

inline void Scmat4Limag::reshape(Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1*N2*N3 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline void Scmat4Limag::set(Limag *data, Long_I N0, Long_I N1, Long_I N2, Long_I N3)
{
	SvecLimag::set(data, N0*N1*N2*N3);
	m_N0 = N0; m_N1 = N1; m_N2 = N2; m_N3 = N3;
}

inline Scmat4Limag::~Scmat4Limag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Limag &Scmat4Limag_O, &Scmat4Limag_IO;





#ifdef SLS_USE_INT_AS_LONG
typedef Scmat4Int Scmat4Long;
typedef Scmat4IntC Scmat4LongC;
#else
typedef Scmat4Llong Scmat4Long;
typedef Scmat4LlongC Scmat4LongC;
#endif

typedef const Scmat4LongC &Scmat4Long_I;
// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const Scmat4Long &Scmat4Long_O, &Scmat4Long_IO;

} // namespace slisc
