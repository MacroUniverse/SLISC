#pragma once

namespace slisc {
class DcmatCharC
{
protected:
	const Char *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatCharC();
	DcmatCharC(const Char *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const Char *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatCharC &sli);


	const Char& operator[](Long_I i) const;
	const Char& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	const Char *p() const;
};

inline DcmatCharC::DcmatCharC() {}

inline DcmatCharC::DcmatCharC(const Char *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatCharC::set(const Char *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatCharC::set(const DcmatCharC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Char &DcmatCharC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline const Char &DcmatCharC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatCharC::n0() const
{
	return m_N0;
}

inline Long DcmatCharC::n1() const
{
	return m_N1;
}

inline Long DcmatCharC::lda() const
{
	return m_lda;
}

inline Long DcmatCharC::size() const
{
	return m_N;
}

inline const Char * DcmatCharC::p() const
{
	return m_p;
}

typedef const DcmatCharC &DcmatChar_I;

class DcmatChar
{
protected:
	Char *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatChar();
	DcmatChar(Char *p, Long_I N0, Long_I N1, Long_I lda);
	void set(Char *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatChar &sli);

	operator DcmatCharC() const;
	Char& operator[](Long_I i);
	Char& operator()(Long_I i, Long_I j);

	Char& operator[](Long_I i) const;
	Char& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	Char *p() const;
};

inline DcmatChar::DcmatChar() {}

inline DcmatChar::DcmatChar(Char *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatChar::set(Char *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatChar::set(const DcmatChar &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatChar::operator DcmatCharC() const
{
	return *((DcmatCharC *)this);
}

inline Char &DcmatChar::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Char &DcmatChar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Char &DcmatChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Char &DcmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatChar::n0() const
{
	return m_N0;
}

inline Long DcmatChar::n1() const
{
	return m_N1;
}

inline Long DcmatChar::lda() const
{
	return m_lda;
}

inline Long DcmatChar::size() const
{
	return m_N;
}

inline Char * DcmatChar::p() const
{
	return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatChar &DcmatChar_O, &DcmatChar_IO;

class DcmatUcharC
{
protected:
	const Uchar *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatUcharC();
	DcmatUcharC(const Uchar *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const Uchar *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatUcharC &sli);


	const Uchar& operator[](Long_I i) const;
	const Uchar& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	const Uchar *p() const;
};

inline DcmatUcharC::DcmatUcharC() {}

inline DcmatUcharC::DcmatUcharC(const Uchar *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatUcharC::set(const Uchar *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatUcharC::set(const DcmatUcharC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Uchar &DcmatUcharC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline const Uchar &DcmatUcharC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatUcharC::n0() const
{
	return m_N0;
}

inline Long DcmatUcharC::n1() const
{
	return m_N1;
}

inline Long DcmatUcharC::lda() const
{
	return m_lda;
}

inline Long DcmatUcharC::size() const
{
	return m_N;
}

inline const Uchar * DcmatUcharC::p() const
{
	return m_p;
}

typedef const DcmatUcharC &DcmatUchar_I;

class DcmatUchar
{
protected:
	Uchar *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatUchar();
	DcmatUchar(Uchar *p, Long_I N0, Long_I N1, Long_I lda);
	void set(Uchar *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatUchar &sli);

	operator DcmatUcharC() const;
	Uchar& operator[](Long_I i);
	Uchar& operator()(Long_I i, Long_I j);

	Uchar& operator[](Long_I i) const;
	Uchar& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	Uchar *p() const;
};

inline DcmatUchar::DcmatUchar() {}

inline DcmatUchar::DcmatUchar(Uchar *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatUchar::set(Uchar *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatUchar::set(const DcmatUchar &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatUchar::operator DcmatUcharC() const
{
	return *((DcmatUcharC *)this);
}

inline Uchar &DcmatUchar::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Uchar &DcmatUchar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Uchar &DcmatUchar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Uchar &DcmatUchar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatUchar::n0() const
{
	return m_N0;
}

inline Long DcmatUchar::n1() const
{
	return m_N1;
}

inline Long DcmatUchar::lda() const
{
	return m_lda;
}

inline Long DcmatUchar::size() const
{
	return m_N;
}

inline Uchar * DcmatUchar::p() const
{
	return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatUchar &DcmatUchar_O, &DcmatUchar_IO;

class DcmatIntC
{
protected:
	const Int *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatIntC();
	DcmatIntC(const Int *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const Int *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatIntC &sli);


	const Int& operator[](Long_I i) const;
	const Int& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	const Int *p() const;
};

inline DcmatIntC::DcmatIntC() {}

inline DcmatIntC::DcmatIntC(const Int *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatIntC::set(const Int *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatIntC::set(const DcmatIntC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Int &DcmatIntC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline const Int &DcmatIntC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatIntC::n0() const
{
	return m_N0;
}

inline Long DcmatIntC::n1() const
{
	return m_N1;
}

inline Long DcmatIntC::lda() const
{
	return m_lda;
}

inline Long DcmatIntC::size() const
{
	return m_N;
}

inline const Int * DcmatIntC::p() const
{
	return m_p;
}

typedef const DcmatIntC &DcmatInt_I;

class DcmatInt
{
protected:
	Int *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatInt();
	DcmatInt(Int *p, Long_I N0, Long_I N1, Long_I lda);
	void set(Int *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatInt &sli);

	operator DcmatIntC() const;
	Int& operator[](Long_I i);
	Int& operator()(Long_I i, Long_I j);

	Int& operator[](Long_I i) const;
	Int& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	Int *p() const;
};

inline DcmatInt::DcmatInt() {}

inline DcmatInt::DcmatInt(Int *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatInt::set(Int *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatInt::set(const DcmatInt &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatInt::operator DcmatIntC() const
{
	return *((DcmatIntC *)this);
}

inline Int &DcmatInt::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Int &DcmatInt::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Int &DcmatInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Int &DcmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatInt::n0() const
{
	return m_N0;
}

inline Long DcmatInt::n1() const
{
	return m_N1;
}

inline Long DcmatInt::lda() const
{
	return m_lda;
}

inline Long DcmatInt::size() const
{
	return m_N;
}

inline Int * DcmatInt::p() const
{
	return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatInt &DcmatInt_O, &DcmatInt_IO;

class DcmatLlongC
{
protected:
	const Llong *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatLlongC();
	DcmatLlongC(const Llong *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const Llong *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatLlongC &sli);


	const Llong& operator[](Long_I i) const;
	const Llong& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	const Llong *p() const;
};

inline DcmatLlongC::DcmatLlongC() {}

inline DcmatLlongC::DcmatLlongC(const Llong *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLlongC::set(const Llong *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLlongC::set(const DcmatLlongC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Llong &DcmatLlongC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline const Llong &DcmatLlongC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatLlongC::n0() const
{
	return m_N0;
}

inline Long DcmatLlongC::n1() const
{
	return m_N1;
}

inline Long DcmatLlongC::lda() const
{
	return m_lda;
}

inline Long DcmatLlongC::size() const
{
	return m_N;
}

inline const Llong * DcmatLlongC::p() const
{
	return m_p;
}

typedef const DcmatLlongC &DcmatLlong_I;

class DcmatLlong
{
protected:
	Llong *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatLlong();
	DcmatLlong(Llong *p, Long_I N0, Long_I N1, Long_I lda);
	void set(Llong *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatLlong &sli);

	operator DcmatLlongC() const;
	Llong& operator[](Long_I i);
	Llong& operator()(Long_I i, Long_I j);

	Llong& operator[](Long_I i) const;
	Llong& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	Llong *p() const;
};

inline DcmatLlong::DcmatLlong() {}

inline DcmatLlong::DcmatLlong(Llong *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLlong::set(Llong *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLlong::set(const DcmatLlong &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatLlong::operator DcmatLlongC() const
{
	return *((DcmatLlongC *)this);
}

inline Llong &DcmatLlong::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Llong &DcmatLlong::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Llong &DcmatLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Llong &DcmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatLlong::n0() const
{
	return m_N0;
}

inline Long DcmatLlong::n1() const
{
	return m_N1;
}

inline Long DcmatLlong::lda() const
{
	return m_lda;
}

inline Long DcmatLlong::size() const
{
	return m_N;
}

inline Llong * DcmatLlong::p() const
{
	return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatLlong &DcmatLlong_O, &DcmatLlong_IO;

class DcmatFloatC
{
protected:
	const Float *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatFloatC();
	DcmatFloatC(const Float *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const Float *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatFloatC &sli);


	const Float& operator[](Long_I i) const;
	const Float& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	const Float *p() const;
};

inline DcmatFloatC::DcmatFloatC() {}

inline DcmatFloatC::DcmatFloatC(const Float *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatFloatC::set(const Float *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatFloatC::set(const DcmatFloatC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Float &DcmatFloatC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline const Float &DcmatFloatC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatFloatC::n0() const
{
	return m_N0;
}

inline Long DcmatFloatC::n1() const
{
	return m_N1;
}

inline Long DcmatFloatC::lda() const
{
	return m_lda;
}

inline Long DcmatFloatC::size() const
{
	return m_N;
}

inline const Float * DcmatFloatC::p() const
{
	return m_p;
}

typedef const DcmatFloatC &DcmatFloat_I;

class DcmatFloat
{
protected:
	Float *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatFloat();
	DcmatFloat(Float *p, Long_I N0, Long_I N1, Long_I lda);
	void set(Float *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatFloat &sli);

	operator DcmatFloatC() const;
	Float& operator[](Long_I i);
	Float& operator()(Long_I i, Long_I j);

	Float& operator[](Long_I i) const;
	Float& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	Float *p() const;
};

inline DcmatFloat::DcmatFloat() {}

inline DcmatFloat::DcmatFloat(Float *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatFloat::set(Float *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatFloat::set(const DcmatFloat &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatFloat::operator DcmatFloatC() const
{
	return *((DcmatFloatC *)this);
}

inline Float &DcmatFloat::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Float &DcmatFloat::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Float &DcmatFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Float &DcmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatFloat::n0() const
{
	return m_N0;
}

inline Long DcmatFloat::n1() const
{
	return m_N1;
}

inline Long DcmatFloat::lda() const
{
	return m_lda;
}

inline Long DcmatFloat::size() const
{
	return m_N;
}

inline Float * DcmatFloat::p() const
{
	return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatFloat &DcmatFloat_O, &DcmatFloat_IO;

class DcmatDoubC
{
protected:
	const Doub *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatDoubC();
	DcmatDoubC(const Doub *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const Doub *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatDoubC &sli);


	const Doub& operator[](Long_I i) const;
	const Doub& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	const Doub *p() const;
};

inline DcmatDoubC::DcmatDoubC() {}

inline DcmatDoubC::DcmatDoubC(const Doub *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatDoubC::set(const Doub *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatDoubC::set(const DcmatDoubC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Doub &DcmatDoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline const Doub &DcmatDoubC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatDoubC::n0() const
{
	return m_N0;
}

inline Long DcmatDoubC::n1() const
{
	return m_N1;
}

inline Long DcmatDoubC::lda() const
{
	return m_lda;
}

inline Long DcmatDoubC::size() const
{
	return m_N;
}

inline const Doub * DcmatDoubC::p() const
{
	return m_p;
}

typedef const DcmatDoubC &DcmatDoub_I;

class DcmatDoub
{
protected:
	Doub *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatDoub();
	DcmatDoub(Doub *p, Long_I N0, Long_I N1, Long_I lda);
	void set(Doub *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatDoub &sli);

	operator DcmatDoubC() const;
	Doub& operator[](Long_I i);
	Doub& operator()(Long_I i, Long_I j);

	Doub& operator[](Long_I i) const;
	Doub& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	Doub *p() const;
};

inline DcmatDoub::DcmatDoub() {}

inline DcmatDoub::DcmatDoub(Doub *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatDoub::set(Doub *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatDoub::set(const DcmatDoub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatDoub::operator DcmatDoubC() const
{
	return *((DcmatDoubC *)this);
}

inline Doub &DcmatDoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Doub &DcmatDoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Doub &DcmatDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Doub &DcmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatDoub::n0() const
{
	return m_N0;
}

inline Long DcmatDoub::n1() const
{
	return m_N1;
}

inline Long DcmatDoub::lda() const
{
	return m_lda;
}

inline Long DcmatDoub::size() const
{
	return m_N;
}

inline Doub * DcmatDoub::p() const
{
	return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatDoub &DcmatDoub_O, &DcmatDoub_IO;

class DcmatLdoubC
{
protected:
	const Ldoub *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatLdoubC();
	DcmatLdoubC(const Ldoub *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const Ldoub *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatLdoubC &sli);


	const Ldoub& operator[](Long_I i) const;
	const Ldoub& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	const Ldoub *p() const;
};

inline DcmatLdoubC::DcmatLdoubC() {}

inline DcmatLdoubC::DcmatLdoubC(const Ldoub *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLdoubC::set(const Ldoub *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLdoubC::set(const DcmatLdoubC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Ldoub &DcmatLdoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline const Ldoub &DcmatLdoubC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatLdoubC::n0() const
{
	return m_N0;
}

inline Long DcmatLdoubC::n1() const
{
	return m_N1;
}

inline Long DcmatLdoubC::lda() const
{
	return m_lda;
}

inline Long DcmatLdoubC::size() const
{
	return m_N;
}

inline const Ldoub * DcmatLdoubC::p() const
{
	return m_p;
}

typedef const DcmatLdoubC &DcmatLdoub_I;

class DcmatLdoub
{
protected:
	Ldoub *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatLdoub();
	DcmatLdoub(Ldoub *p, Long_I N0, Long_I N1, Long_I lda);
	void set(Ldoub *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatLdoub &sli);

	operator DcmatLdoubC() const;
	Ldoub& operator[](Long_I i);
	Ldoub& operator()(Long_I i, Long_I j);

	Ldoub& operator[](Long_I i) const;
	Ldoub& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	Ldoub *p() const;
};

inline DcmatLdoub::DcmatLdoub() {}

inline DcmatLdoub::DcmatLdoub(Ldoub *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLdoub::set(Ldoub *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLdoub::set(const DcmatLdoub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatLdoub::operator DcmatLdoubC() const
{
	return *((DcmatLdoubC *)this);
}

inline Ldoub &DcmatLdoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Ldoub &DcmatLdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Ldoub &DcmatLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Ldoub &DcmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatLdoub::n0() const
{
	return m_N0;
}

inline Long DcmatLdoub::n1() const
{
	return m_N1;
}

inline Long DcmatLdoub::lda() const
{
	return m_lda;
}

inline Long DcmatLdoub::size() const
{
	return m_N;
}

inline Ldoub * DcmatLdoub::p() const
{
	return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatLdoub &DcmatLdoub_O, &DcmatLdoub_IO;



class DcmatFcompC
{
protected:
	const Fcomp *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatFcompC();
	DcmatFcompC(const Fcomp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const Fcomp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatFcompC &sli);


	const Fcomp& operator[](Long_I i) const;
	const Fcomp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	const Fcomp *p() const;
};

inline DcmatFcompC::DcmatFcompC() {}

inline DcmatFcompC::DcmatFcompC(const Fcomp *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatFcompC::set(const Fcomp *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatFcompC::set(const DcmatFcompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Fcomp &DcmatFcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline const Fcomp &DcmatFcompC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatFcompC::n0() const
{
	return m_N0;
}

inline Long DcmatFcompC::n1() const
{
	return m_N1;
}

inline Long DcmatFcompC::lda() const
{
	return m_lda;
}

inline Long DcmatFcompC::size() const
{
	return m_N;
}

inline const Fcomp * DcmatFcompC::p() const
{
	return m_p;
}

typedef const DcmatFcompC &DcmatFcomp_I;

class DcmatFcomp
{
protected:
	Fcomp *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatFcomp();
	DcmatFcomp(Fcomp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(Fcomp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatFcomp &sli);

	operator DcmatFcompC() const;
	Fcomp& operator[](Long_I i);
	Fcomp& operator()(Long_I i, Long_I j);

	Fcomp& operator[](Long_I i) const;
	Fcomp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	Fcomp *p() const;
};

inline DcmatFcomp::DcmatFcomp() {}

inline DcmatFcomp::DcmatFcomp(Fcomp *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatFcomp::set(Fcomp *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatFcomp::set(const DcmatFcomp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatFcomp::operator DcmatFcompC() const
{
	return *((DcmatFcompC *)this);
}

inline Fcomp &DcmatFcomp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Fcomp &DcmatFcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Fcomp &DcmatFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Fcomp &DcmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatFcomp::n0() const
{
	return m_N0;
}

inline Long DcmatFcomp::n1() const
{
	return m_N1;
}

inline Long DcmatFcomp::lda() const
{
	return m_lda;
}

inline Long DcmatFcomp::size() const
{
	return m_N;
}

inline Fcomp * DcmatFcomp::p() const
{
	return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatFcomp &DcmatFcomp_O, &DcmatFcomp_IO;

class DcmatCompC
{
protected:
	const Comp *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatCompC();
	DcmatCompC(const Comp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const Comp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatCompC &sli);


	const Comp& operator[](Long_I i) const;
	const Comp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	const Comp *p() const;
};

inline DcmatCompC::DcmatCompC() {}

inline DcmatCompC::DcmatCompC(const Comp *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatCompC::set(const Comp *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatCompC::set(const DcmatCompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Comp &DcmatCompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline const Comp &DcmatCompC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatCompC::n0() const
{
	return m_N0;
}

inline Long DcmatCompC::n1() const
{
	return m_N1;
}

inline Long DcmatCompC::lda() const
{
	return m_lda;
}

inline Long DcmatCompC::size() const
{
	return m_N;
}

inline const Comp * DcmatCompC::p() const
{
	return m_p;
}

typedef const DcmatCompC &DcmatComp_I;

class DcmatComp
{
protected:
	Comp *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatComp();
	DcmatComp(Comp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(Comp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatComp &sli);

	operator DcmatCompC() const;
	Comp& operator[](Long_I i);
	Comp& operator()(Long_I i, Long_I j);

	Comp& operator[](Long_I i) const;
	Comp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	Comp *p() const;
};

inline DcmatComp::DcmatComp() {}

inline DcmatComp::DcmatComp(Comp *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatComp::set(Comp *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatComp::set(const DcmatComp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatComp::operator DcmatCompC() const
{
	return *((DcmatCompC *)this);
}

inline Comp &DcmatComp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Comp &DcmatComp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Comp &DcmatComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Comp &DcmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatComp::n0() const
{
	return m_N0;
}

inline Long DcmatComp::n1() const
{
	return m_N1;
}

inline Long DcmatComp::lda() const
{
	return m_lda;
}

inline Long DcmatComp::size() const
{
	return m_N;
}

inline Comp * DcmatComp::p() const
{
	return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatComp &DcmatComp_O, &DcmatComp_IO;

class DcmatLcompC
{
protected:
	const Lcomp *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatLcompC();
	DcmatLcompC(const Lcomp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const Lcomp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatLcompC &sli);


	const Lcomp& operator[](Long_I i) const;
	const Lcomp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	const Lcomp *p() const;
};

inline DcmatLcompC::DcmatLcompC() {}

inline DcmatLcompC::DcmatLcompC(const Lcomp *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLcompC::set(const Lcomp *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLcompC::set(const DcmatLcompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}


inline const Lcomp &DcmatLcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline const Lcomp &DcmatLcompC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatLcompC::n0() const
{
	return m_N0;
}

inline Long DcmatLcompC::n1() const
{
	return m_N1;
}

inline Long DcmatLcompC::lda() const
{
	return m_lda;
}

inline Long DcmatLcompC::size() const
{
	return m_N;
}

inline const Lcomp * DcmatLcompC::p() const
{
	return m_p;
}

typedef const DcmatLcompC &DcmatLcomp_I;

class DcmatLcomp
{
protected:
	Lcomp *m_p;
	Long m_N;
	Long m_N0, m_N1;
	Long m_lda; // leading dimension (here is m_N0 of host matrix)
public:
	DcmatLcomp();
	DcmatLcomp(Lcomp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(Lcomp *p, Long_I N0, Long_I N1, Long_I lda);
	void set(const DcmatLcomp &sli);

	operator DcmatLcompC() const;
	Lcomp& operator[](Long_I i);
	Lcomp& operator()(Long_I i, Long_I j);

	Lcomp& operator[](Long_I i) const;
	Lcomp& operator()(Long_I i, Long_I j) const;
	Long n0() const;
	Long n1() const;
	Long lda() const;
	Long size() const;
	Lcomp *p() const;
};

inline DcmatLcomp::DcmatLcomp() {}

inline DcmatLcomp::DcmatLcomp(Lcomp *p, Long_I N0, Long_I N1, Long_I lda)
	: m_p(p), m_N0(N0), m_N1(N1), m_N(N0*N1), m_lda(lda)
{}

inline void DcmatLcomp::set(Lcomp *p, Long_I N0, Long_I N1, Long_I lda)
{
	m_p = p; m_N0 = N0; m_N1 = N1; m_N = N0 * N1; m_lda = lda;
}

inline void DcmatLcomp::set(const DcmatLcomp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N0 = sli.m_N0; m_N1 = sli.m_N1; m_lda = sli.m_lda;
}

inline DcmatLcomp::operator DcmatLcompC() const
{
	return *((DcmatLcompC *)this);
}

inline Lcomp &DcmatLcomp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Lcomp &DcmatLcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Lcomp &DcmatLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i%m_N0 + (i/m_N0)*m_lda];
}

inline Lcomp &DcmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_lda * j];
}

inline Long DcmatLcomp::n0() const
{
	return m_N0;
}

inline Long DcmatLcomp::n1() const
{
	return m_N1;
}

inline Long DcmatLcomp::lda() const
{
	return m_lda;
}

inline Long DcmatLcomp::size() const
{
	return m_N;
}

inline Lcomp * DcmatLcomp::p() const
{
	return m_p;
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatLcomp &DcmatLcomp_O, &DcmatLcomp_IO;




#ifdef SLS_USE_INT_AS_LONG
typedef DcmatInt DcmatLong;
typedef DcmatIntC DcmatLongC;
#else
typedef DcmatLlong DcmatLong;
typedef DcmatLlongC DcmatLongC;
#endif

typedef const DcmatLongC &DcmatLong_I;
// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DcmatLong &DcmatLong_O, &DcmatLong_IO;

} // namespace slisc
