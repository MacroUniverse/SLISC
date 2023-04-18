#pragma once
#include "../dense/Svec.h"
// "C" means lower level const

namespace slisc {
class ScmatCharC : public SvbaseCharC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatCharC();
	ScmatCharC(const Char *data, Long_I N0, Long_I N1); // unsafe


	const Char &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatCharC &sli);
	void set(const Char *data, Long_I N0, Long_I N1);
	~ScmatCharC();
};

inline ScmatCharC::ScmatCharC() {}

inline ScmatCharC::ScmatCharC(const Char *data, Long_I N0, Long_I N1)
	: SvbaseCharC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Char &ScmatCharC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatCharC::n0() const
{
	return m_N0;
}

inline Long ScmatCharC::n1() const
{
	return m_N1;
}

inline void ScmatCharC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatCharC::set(const Char *data, Long_I N0, Long_I N1)
{
	SvbaseCharC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatCharC::set(const ScmatCharC &sli)
{
	SvbaseCharC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatCharC::~ScmatCharC() {}

typedef const ScmatCharC &ScmatChar_I;

// common api for STL and SLISC
inline Long size(ScmatChar_I v) { return v.size(); }

inline const Char *p(ScmatChar_I v) { return v.p(); }


class ScmatChar : public SvbaseChar
{
protected:
	Long m_N0, m_N1;
public:
	ScmatChar();
	ScmatChar(Char *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatCharC() const;

	Char &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatChar &sli);
	void set(Char *data, Long_I N0, Long_I N1);
	~ScmatChar();
};

inline ScmatChar::ScmatChar() {}

inline ScmatChar::ScmatChar(Char *data, Long_I N0, Long_I N1)
	: SvbaseChar(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatChar::operator ScmatCharC() const
{
	return *((ScmatCharC *)this);
}

inline Char &ScmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatChar::n0() const
{
	return m_N0;
}

inline Long ScmatChar::n1() const
{
	return m_N1;
}

inline void ScmatChar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatChar::set(Char *data, Long_I N0, Long_I N1)
{
	SvbaseChar::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatChar::set(const ScmatChar &sli)
{
	SvbaseChar::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatChar::~ScmatChar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatChar &ScmatChar_O, &ScmatChar_IO;

// common api for STL and SLISC
inline Char *p(ScmatChar &v) { return v.p(); }


class ScmatUcharC : public SvbaseUcharC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatUcharC();
	ScmatUcharC(const Uchar *data, Long_I N0, Long_I N1); // unsafe


	const Uchar &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatUcharC &sli);
	void set(const Uchar *data, Long_I N0, Long_I N1);
	~ScmatUcharC();
};

inline ScmatUcharC::ScmatUcharC() {}

inline ScmatUcharC::ScmatUcharC(const Uchar *data, Long_I N0, Long_I N1)
	: SvbaseUcharC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Uchar &ScmatUcharC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatUcharC::n0() const
{
	return m_N0;
}

inline Long ScmatUcharC::n1() const
{
	return m_N1;
}

inline void ScmatUcharC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatUcharC::set(const Uchar *data, Long_I N0, Long_I N1)
{
	SvbaseUcharC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatUcharC::set(const ScmatUcharC &sli)
{
	SvbaseUcharC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatUcharC::~ScmatUcharC() {}

typedef const ScmatUcharC &ScmatUchar_I;

// common api for STL and SLISC
inline Long size(ScmatUchar_I v) { return v.size(); }

inline const Uchar *p(ScmatUchar_I v) { return v.p(); }


class ScmatUchar : public SvbaseUchar
{
protected:
	Long m_N0, m_N1;
public:
	ScmatUchar();
	ScmatUchar(Uchar *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatUcharC() const;

	Uchar &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatUchar &sli);
	void set(Uchar *data, Long_I N0, Long_I N1);
	~ScmatUchar();
};

inline ScmatUchar::ScmatUchar() {}

inline ScmatUchar::ScmatUchar(Uchar *data, Long_I N0, Long_I N1)
	: SvbaseUchar(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatUchar::operator ScmatUcharC() const
{
	return *((ScmatUcharC *)this);
}

inline Uchar &ScmatUchar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatUchar::n0() const
{
	return m_N0;
}

inline Long ScmatUchar::n1() const
{
	return m_N1;
}

inline void ScmatUchar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatUchar::set(Uchar *data, Long_I N0, Long_I N1)
{
	SvbaseUchar::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatUchar::set(const ScmatUchar &sli)
{
	SvbaseUchar::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatUchar::~ScmatUchar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatUchar &ScmatUchar_O, &ScmatUchar_IO;

// common api for STL and SLISC
inline Uchar *p(ScmatUchar &v) { return v.p(); }


class ScmatIntC : public SvbaseIntC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatIntC();
	ScmatIntC(const Int *data, Long_I N0, Long_I N1); // unsafe


	const Int &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatIntC &sli);
	void set(const Int *data, Long_I N0, Long_I N1);
	~ScmatIntC();
};

inline ScmatIntC::ScmatIntC() {}

inline ScmatIntC::ScmatIntC(const Int *data, Long_I N0, Long_I N1)
	: SvbaseIntC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Int &ScmatIntC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatIntC::n0() const
{
	return m_N0;
}

inline Long ScmatIntC::n1() const
{
	return m_N1;
}

inline void ScmatIntC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatIntC::set(const Int *data, Long_I N0, Long_I N1)
{
	SvbaseIntC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatIntC::set(const ScmatIntC &sli)
{
	SvbaseIntC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatIntC::~ScmatIntC() {}

typedef const ScmatIntC &ScmatInt_I;

// common api for STL and SLISC
inline Long size(ScmatInt_I v) { return v.size(); }

inline const Int *p(ScmatInt_I v) { return v.p(); }


class ScmatInt : public SvbaseInt
{
protected:
	Long m_N0, m_N1;
public:
	ScmatInt();
	ScmatInt(Int *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatIntC() const;

	Int &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatInt &sli);
	void set(Int *data, Long_I N0, Long_I N1);
	~ScmatInt();
};

inline ScmatInt::ScmatInt() {}

inline ScmatInt::ScmatInt(Int *data, Long_I N0, Long_I N1)
	: SvbaseInt(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatInt::operator ScmatIntC() const
{
	return *((ScmatIntC *)this);
}

inline Int &ScmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatInt::n0() const
{
	return m_N0;
}

inline Long ScmatInt::n1() const
{
	return m_N1;
}

inline void ScmatInt::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatInt::set(Int *data, Long_I N0, Long_I N1)
{
	SvbaseInt::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatInt::set(const ScmatInt &sli)
{
	SvbaseInt::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatInt::~ScmatInt() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatInt &ScmatInt_O, &ScmatInt_IO;

// common api for STL and SLISC
inline Int *p(ScmatInt &v) { return v.p(); }


class ScmatLlongC : public SvbaseLlongC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLlongC();
	ScmatLlongC(const Llong *data, Long_I N0, Long_I N1); // unsafe


	const Llong &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatLlongC &sli);
	void set(const Llong *data, Long_I N0, Long_I N1);
	~ScmatLlongC();
};

inline ScmatLlongC::ScmatLlongC() {}

inline ScmatLlongC::ScmatLlongC(const Llong *data, Long_I N0, Long_I N1)
	: SvbaseLlongC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Llong &ScmatLlongC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLlongC::n0() const
{
	return m_N0;
}

inline Long ScmatLlongC::n1() const
{
	return m_N1;
}

inline void ScmatLlongC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLlongC::set(const Llong *data, Long_I N0, Long_I N1)
{
	SvbaseLlongC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLlongC::set(const ScmatLlongC &sli)
{
	SvbaseLlongC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLlongC::~ScmatLlongC() {}

typedef const ScmatLlongC &ScmatLlong_I;

// common api for STL and SLISC
inline Long size(ScmatLlong_I v) { return v.size(); }

inline const Llong *p(ScmatLlong_I v) { return v.p(); }


class ScmatLlong : public SvbaseLlong
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLlong();
	ScmatLlong(Llong *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatLlongC() const;

	Llong &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatLlong &sli);
	void set(Llong *data, Long_I N0, Long_I N1);
	~ScmatLlong();
};

inline ScmatLlong::ScmatLlong() {}

inline ScmatLlong::ScmatLlong(Llong *data, Long_I N0, Long_I N1)
	: SvbaseLlong(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatLlong::operator ScmatLlongC() const
{
	return *((ScmatLlongC *)this);
}

inline Llong &ScmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLlong::n0() const
{
	return m_N0;
}

inline Long ScmatLlong::n1() const
{
	return m_N1;
}

inline void ScmatLlong::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLlong::set(Llong *data, Long_I N0, Long_I N1)
{
	SvbaseLlong::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLlong::set(const ScmatLlong &sli)
{
	SvbaseLlong::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLlong::~ScmatLlong() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLlong &ScmatLlong_O, &ScmatLlong_IO;

// common api for STL and SLISC
inline Llong *p(ScmatLlong &v) { return v.p(); }


class ScmatFloatC : public SvbaseFloatC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFloatC();
	ScmatFloatC(const Float *data, Long_I N0, Long_I N1); // unsafe


	const Float &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatFloatC &sli);
	void set(const Float *data, Long_I N0, Long_I N1);
	~ScmatFloatC();
};

inline ScmatFloatC::ScmatFloatC() {}

inline ScmatFloatC::ScmatFloatC(const Float *data, Long_I N0, Long_I N1)
	: SvbaseFloatC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Float &ScmatFloatC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFloatC::n0() const
{
	return m_N0;
}

inline Long ScmatFloatC::n1() const
{
	return m_N1;
}

inline void ScmatFloatC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFloatC::set(const Float *data, Long_I N0, Long_I N1)
{
	SvbaseFloatC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFloatC::set(const ScmatFloatC &sli)
{
	SvbaseFloatC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFloatC::~ScmatFloatC() {}

typedef const ScmatFloatC &ScmatFloat_I;

// common api for STL and SLISC
inline Long size(ScmatFloat_I v) { return v.size(); }

inline const Float *p(ScmatFloat_I v) { return v.p(); }


class ScmatFloat : public SvbaseFloat
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFloat();
	ScmatFloat(Float *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatFloatC() const;

	Float &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatFloat &sli);
	void set(Float *data, Long_I N0, Long_I N1);
	~ScmatFloat();
};

inline ScmatFloat::ScmatFloat() {}

inline ScmatFloat::ScmatFloat(Float *data, Long_I N0, Long_I N1)
	: SvbaseFloat(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatFloat::operator ScmatFloatC() const
{
	return *((ScmatFloatC *)this);
}

inline Float &ScmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFloat::n0() const
{
	return m_N0;
}

inline Long ScmatFloat::n1() const
{
	return m_N1;
}

inline void ScmatFloat::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFloat::set(Float *data, Long_I N0, Long_I N1)
{
	SvbaseFloat::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFloat::set(const ScmatFloat &sli)
{
	SvbaseFloat::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFloat::~ScmatFloat() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatFloat &ScmatFloat_O, &ScmatFloat_IO;

// common api for STL and SLISC
inline Float *p(ScmatFloat &v) { return v.p(); }


class ScmatDoubC : public SvbaseDoubC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatDoubC();
	ScmatDoubC(const Doub *data, Long_I N0, Long_I N1); // unsafe


	const Doub &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatDoubC &sli);
	void set(const Doub *data, Long_I N0, Long_I N1);
	~ScmatDoubC();
};

inline ScmatDoubC::ScmatDoubC() {}

inline ScmatDoubC::ScmatDoubC(const Doub *data, Long_I N0, Long_I N1)
	: SvbaseDoubC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Doub &ScmatDoubC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatDoubC::n0() const
{
	return m_N0;
}

inline Long ScmatDoubC::n1() const
{
	return m_N1;
}

inline void ScmatDoubC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatDoubC::set(const Doub *data, Long_I N0, Long_I N1)
{
	SvbaseDoubC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatDoubC::set(const ScmatDoubC &sli)
{
	SvbaseDoubC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatDoubC::~ScmatDoubC() {}

typedef const ScmatDoubC &ScmatDoub_I;

// common api for STL and SLISC
inline Long size(ScmatDoub_I v) { return v.size(); }

inline const Doub *p(ScmatDoub_I v) { return v.p(); }


class ScmatDoub : public SvbaseDoub
{
protected:
	Long m_N0, m_N1;
public:
	ScmatDoub();
	ScmatDoub(Doub *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatDoubC() const;

	Doub &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatDoub &sli);
	void set(Doub *data, Long_I N0, Long_I N1);
	~ScmatDoub();
};

inline ScmatDoub::ScmatDoub() {}

inline ScmatDoub::ScmatDoub(Doub *data, Long_I N0, Long_I N1)
	: SvbaseDoub(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatDoub::operator ScmatDoubC() const
{
	return *((ScmatDoubC *)this);
}

inline Doub &ScmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatDoub::n0() const
{
	return m_N0;
}

inline Long ScmatDoub::n1() const
{
	return m_N1;
}

inline void ScmatDoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatDoub::set(Doub *data, Long_I N0, Long_I N1)
{
	SvbaseDoub::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatDoub::set(const ScmatDoub &sli)
{
	SvbaseDoub::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatDoub::~ScmatDoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatDoub &ScmatDoub_O, &ScmatDoub_IO;

// common api for STL and SLISC
inline Doub *p(ScmatDoub &v) { return v.p(); }


class ScmatLdoubC : public SvbaseLdoubC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLdoubC();
	ScmatLdoubC(const Ldoub *data, Long_I N0, Long_I N1); // unsafe


	const Ldoub &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatLdoubC &sli);
	void set(const Ldoub *data, Long_I N0, Long_I N1);
	~ScmatLdoubC();
};

inline ScmatLdoubC::ScmatLdoubC() {}

inline ScmatLdoubC::ScmatLdoubC(const Ldoub *data, Long_I N0, Long_I N1)
	: SvbaseLdoubC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Ldoub &ScmatLdoubC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLdoubC::n0() const
{
	return m_N0;
}

inline Long ScmatLdoubC::n1() const
{
	return m_N1;
}

inline void ScmatLdoubC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLdoubC::set(const Ldoub *data, Long_I N0, Long_I N1)
{
	SvbaseLdoubC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLdoubC::set(const ScmatLdoubC &sli)
{
	SvbaseLdoubC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLdoubC::~ScmatLdoubC() {}

typedef const ScmatLdoubC &ScmatLdoub_I;

// common api for STL and SLISC
inline Long size(ScmatLdoub_I v) { return v.size(); }

inline const Ldoub *p(ScmatLdoub_I v) { return v.p(); }


class ScmatLdoub : public SvbaseLdoub
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLdoub();
	ScmatLdoub(Ldoub *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatLdoubC() const;

	Ldoub &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatLdoub &sli);
	void set(Ldoub *data, Long_I N0, Long_I N1);
	~ScmatLdoub();
};

inline ScmatLdoub::ScmatLdoub() {}

inline ScmatLdoub::ScmatLdoub(Ldoub *data, Long_I N0, Long_I N1)
	: SvbaseLdoub(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatLdoub::operator ScmatLdoubC() const
{
	return *((ScmatLdoubC *)this);
}

inline Ldoub &ScmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLdoub::n0() const
{
	return m_N0;
}

inline Long ScmatLdoub::n1() const
{
	return m_N1;
}

inline void ScmatLdoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLdoub::set(Ldoub *data, Long_I N0, Long_I N1)
{
	SvbaseLdoub::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLdoub::set(const ScmatLdoub &sli)
{
	SvbaseLdoub::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLdoub::~ScmatLdoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLdoub &ScmatLdoub_O, &ScmatLdoub_IO;

// common api for STL and SLISC
inline Ldoub *p(ScmatLdoub &v) { return v.p(); }




class ScmatFcompC : public SvbaseFcompC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFcompC();
	ScmatFcompC(const Fcomp *data, Long_I N0, Long_I N1); // unsafe


	const Fcomp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatFcompC &sli);
	void set(const Fcomp *data, Long_I N0, Long_I N1);
	~ScmatFcompC();
};

inline ScmatFcompC::ScmatFcompC() {}

inline ScmatFcompC::ScmatFcompC(const Fcomp *data, Long_I N0, Long_I N1)
	: SvbaseFcompC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Fcomp &ScmatFcompC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFcompC::n0() const
{
	return m_N0;
}

inline Long ScmatFcompC::n1() const
{
	return m_N1;
}

inline void ScmatFcompC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFcompC::set(const Fcomp *data, Long_I N0, Long_I N1)
{
	SvbaseFcompC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFcompC::set(const ScmatFcompC &sli)
{
	SvbaseFcompC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFcompC::~ScmatFcompC() {}

typedef const ScmatFcompC &ScmatFcomp_I;

// common api for STL and SLISC
inline Long size(ScmatFcomp_I v) { return v.size(); }

inline const Fcomp *p(ScmatFcomp_I v) { return v.p(); }


class ScmatFcomp : public SvbaseFcomp
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFcomp();
	ScmatFcomp(Fcomp *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatFcompC() const;

	Fcomp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatFcomp &sli);
	void set(Fcomp *data, Long_I N0, Long_I N1);
	~ScmatFcomp();
};

inline ScmatFcomp::ScmatFcomp() {}

inline ScmatFcomp::ScmatFcomp(Fcomp *data, Long_I N0, Long_I N1)
	: SvbaseFcomp(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatFcomp::operator ScmatFcompC() const
{
	return *((ScmatFcompC *)this);
}

inline Fcomp &ScmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFcomp::n0() const
{
	return m_N0;
}

inline Long ScmatFcomp::n1() const
{
	return m_N1;
}

inline void ScmatFcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFcomp::set(Fcomp *data, Long_I N0, Long_I N1)
{
	SvbaseFcomp::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFcomp::set(const ScmatFcomp &sli)
{
	SvbaseFcomp::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFcomp::~ScmatFcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatFcomp &ScmatFcomp_O, &ScmatFcomp_IO;

// common api for STL and SLISC
inline Fcomp *p(ScmatFcomp &v) { return v.p(); }


class ScmatCompC : public SvbaseCompC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatCompC();
	ScmatCompC(const Comp *data, Long_I N0, Long_I N1); // unsafe


	const Comp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatCompC &sli);
	void set(const Comp *data, Long_I N0, Long_I N1);
	~ScmatCompC();
};

inline ScmatCompC::ScmatCompC() {}

inline ScmatCompC::ScmatCompC(const Comp *data, Long_I N0, Long_I N1)
	: SvbaseCompC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Comp &ScmatCompC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatCompC::n0() const
{
	return m_N0;
}

inline Long ScmatCompC::n1() const
{
	return m_N1;
}

inline void ScmatCompC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatCompC::set(const Comp *data, Long_I N0, Long_I N1)
{
	SvbaseCompC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatCompC::set(const ScmatCompC &sli)
{
	SvbaseCompC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatCompC::~ScmatCompC() {}

typedef const ScmatCompC &ScmatComp_I;

// common api for STL and SLISC
inline Long size(ScmatComp_I v) { return v.size(); }

inline const Comp *p(ScmatComp_I v) { return v.p(); }


class ScmatComp : public SvbaseComp
{
protected:
	Long m_N0, m_N1;
public:
	ScmatComp();
	ScmatComp(Comp *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatCompC() const;

	Comp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatComp &sli);
	void set(Comp *data, Long_I N0, Long_I N1);
	~ScmatComp();
};

inline ScmatComp::ScmatComp() {}

inline ScmatComp::ScmatComp(Comp *data, Long_I N0, Long_I N1)
	: SvbaseComp(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatComp::operator ScmatCompC() const
{
	return *((ScmatCompC *)this);
}

inline Comp &ScmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatComp::n0() const
{
	return m_N0;
}

inline Long ScmatComp::n1() const
{
	return m_N1;
}

inline void ScmatComp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatComp::set(Comp *data, Long_I N0, Long_I N1)
{
	SvbaseComp::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatComp::set(const ScmatComp &sli)
{
	SvbaseComp::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatComp::~ScmatComp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatComp &ScmatComp_O, &ScmatComp_IO;

// common api for STL and SLISC
inline Comp *p(ScmatComp &v) { return v.p(); }


class ScmatLcompC : public SvbaseLcompC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLcompC();
	ScmatLcompC(const Lcomp *data, Long_I N0, Long_I N1); // unsafe


	const Lcomp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatLcompC &sli);
	void set(const Lcomp *data, Long_I N0, Long_I N1);
	~ScmatLcompC();
};

inline ScmatLcompC::ScmatLcompC() {}

inline ScmatLcompC::ScmatLcompC(const Lcomp *data, Long_I N0, Long_I N1)
	: SvbaseLcompC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Lcomp &ScmatLcompC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLcompC::n0() const
{
	return m_N0;
}

inline Long ScmatLcompC::n1() const
{
	return m_N1;
}

inline void ScmatLcompC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLcompC::set(const Lcomp *data, Long_I N0, Long_I N1)
{
	SvbaseLcompC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLcompC::set(const ScmatLcompC &sli)
{
	SvbaseLcompC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLcompC::~ScmatLcompC() {}

typedef const ScmatLcompC &ScmatLcomp_I;

// common api for STL and SLISC
inline Long size(ScmatLcomp_I v) { return v.size(); }

inline const Lcomp *p(ScmatLcomp_I v) { return v.p(); }


class ScmatLcomp : public SvbaseLcomp
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLcomp();
	ScmatLcomp(Lcomp *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatLcompC() const;

	Lcomp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatLcomp &sli);
	void set(Lcomp *data, Long_I N0, Long_I N1);
	~ScmatLcomp();
};

inline ScmatLcomp::ScmatLcomp() {}

inline ScmatLcomp::ScmatLcomp(Lcomp *data, Long_I N0, Long_I N1)
	: SvbaseLcomp(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatLcomp::operator ScmatLcompC() const
{
	return *((ScmatLcompC *)this);
}

inline Lcomp &ScmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLcomp::n0() const
{
	return m_N0;
}

inline Long ScmatLcomp::n1() const
{
	return m_N1;
}

inline void ScmatLcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLcomp::set(Lcomp *data, Long_I N0, Long_I N1)
{
	SvbaseLcomp::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLcomp::set(const ScmatLcomp &sli)
{
	SvbaseLcomp::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLcomp::~ScmatLcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLcomp &ScmatLcomp_O, &ScmatLcomp_IO;

// common api for STL and SLISC
inline Lcomp *p(ScmatLcomp &v) { return v.p(); }




class ScmatFimagC : public SvbaseFimagC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFimagC();
	ScmatFimagC(const Fimag *data, Long_I N0, Long_I N1); // unsafe


	const Fimag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatFimagC &sli);
	void set(const Fimag *data, Long_I N0, Long_I N1);
	~ScmatFimagC();
};

inline ScmatFimagC::ScmatFimagC() {}

inline ScmatFimagC::ScmatFimagC(const Fimag *data, Long_I N0, Long_I N1)
	: SvbaseFimagC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Fimag &ScmatFimagC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFimagC::n0() const
{
	return m_N0;
}

inline Long ScmatFimagC::n1() const
{
	return m_N1;
}

inline void ScmatFimagC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFimagC::set(const Fimag *data, Long_I N0, Long_I N1)
{
	SvbaseFimagC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFimagC::set(const ScmatFimagC &sli)
{
	SvbaseFimagC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFimagC::~ScmatFimagC() {}

typedef const ScmatFimagC &ScmatFimag_I;

// common api for STL and SLISC
inline Long size(ScmatFimag_I v) { return v.size(); }

inline const Fimag *p(ScmatFimag_I v) { return v.p(); }


class ScmatFimag : public SvbaseFimag
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFimag();
	ScmatFimag(Fimag *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatFimagC() const;

	Fimag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatFimag &sli);
	void set(Fimag *data, Long_I N0, Long_I N1);
	~ScmatFimag();
};

inline ScmatFimag::ScmatFimag() {}

inline ScmatFimag::ScmatFimag(Fimag *data, Long_I N0, Long_I N1)
	: SvbaseFimag(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatFimag::operator ScmatFimagC() const
{
	return *((ScmatFimagC *)this);
}

inline Fimag &ScmatFimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFimag::n0() const
{
	return m_N0;
}

inline Long ScmatFimag::n1() const
{
	return m_N1;
}

inline void ScmatFimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFimag::set(Fimag *data, Long_I N0, Long_I N1)
{
	SvbaseFimag::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatFimag::set(const ScmatFimag &sli)
{
	SvbaseFimag::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatFimag::~ScmatFimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatFimag &ScmatFimag_O, &ScmatFimag_IO;

// common api for STL and SLISC
inline Fimag *p(ScmatFimag &v) { return v.p(); }


class ScmatImagC : public SvbaseImagC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatImagC();
	ScmatImagC(const Imag *data, Long_I N0, Long_I N1); // unsafe


	const Imag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatImagC &sli);
	void set(const Imag *data, Long_I N0, Long_I N1);
	~ScmatImagC();
};

inline ScmatImagC::ScmatImagC() {}

inline ScmatImagC::ScmatImagC(const Imag *data, Long_I N0, Long_I N1)
	: SvbaseImagC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Imag &ScmatImagC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatImagC::n0() const
{
	return m_N0;
}

inline Long ScmatImagC::n1() const
{
	return m_N1;
}

inline void ScmatImagC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatImagC::set(const Imag *data, Long_I N0, Long_I N1)
{
	SvbaseImagC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatImagC::set(const ScmatImagC &sli)
{
	SvbaseImagC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatImagC::~ScmatImagC() {}

typedef const ScmatImagC &ScmatImag_I;

// common api for STL and SLISC
inline Long size(ScmatImag_I v) { return v.size(); }

inline const Imag *p(ScmatImag_I v) { return v.p(); }


class ScmatImag : public SvbaseImag
{
protected:
	Long m_N0, m_N1;
public:
	ScmatImag();
	ScmatImag(Imag *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatImagC() const;

	Imag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatImag &sli);
	void set(Imag *data, Long_I N0, Long_I N1);
	~ScmatImag();
};

inline ScmatImag::ScmatImag() {}

inline ScmatImag::ScmatImag(Imag *data, Long_I N0, Long_I N1)
	: SvbaseImag(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatImag::operator ScmatImagC() const
{
	return *((ScmatImagC *)this);
}

inline Imag &ScmatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatImag::n0() const
{
	return m_N0;
}

inline Long ScmatImag::n1() const
{
	return m_N1;
}

inline void ScmatImag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatImag::set(Imag *data, Long_I N0, Long_I N1)
{
	SvbaseImag::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatImag::set(const ScmatImag &sli)
{
	SvbaseImag::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatImag::~ScmatImag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatImag &ScmatImag_O, &ScmatImag_IO;

// common api for STL and SLISC
inline Imag *p(ScmatImag &v) { return v.p(); }


class ScmatLimagC : public SvbaseLimagC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLimagC();
	ScmatLimagC(const Limag *data, Long_I N0, Long_I N1); // unsafe


	const Limag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatLimagC &sli);
	void set(const Limag *data, Long_I N0, Long_I N1);
	~ScmatLimagC();
};

inline ScmatLimagC::ScmatLimagC() {}

inline ScmatLimagC::ScmatLimagC(const Limag *data, Long_I N0, Long_I N1)
	: SvbaseLimagC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Limag &ScmatLimagC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLimagC::n0() const
{
	return m_N0;
}

inline Long ScmatLimagC::n1() const
{
	return m_N1;
}

inline void ScmatLimagC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLimagC::set(const Limag *data, Long_I N0, Long_I N1)
{
	SvbaseLimagC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLimagC::set(const ScmatLimagC &sli)
{
	SvbaseLimagC::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLimagC::~ScmatLimagC() {}

typedef const ScmatLimagC &ScmatLimag_I;

// common api for STL and SLISC
inline Long size(ScmatLimag_I v) { return v.size(); }

inline const Limag *p(ScmatLimag_I v) { return v.p(); }


class ScmatLimag : public SvbaseLimag
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLimag();
	ScmatLimag(Limag *data, Long_I N0, Long_I N1); // unsafe

	operator ScmatLimagC() const;

	Limag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const ScmatLimag &sli);
	void set(Limag *data, Long_I N0, Long_I N1);
	~ScmatLimag();
};

inline ScmatLimag::ScmatLimag() {}

inline ScmatLimag::ScmatLimag(Limag *data, Long_I N0, Long_I N1)
	: SvbaseLimag(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatLimag::operator ScmatLimagC() const
{
	return *((ScmatLimagC *)this);
}

inline Limag &ScmatLimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLimag::n0() const
{
	return m_N0;
}

inline Long ScmatLimag::n1() const
{
	return m_N1;
}

inline void ScmatLimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLimag::set(Limag *data, Long_I N0, Long_I N1)
{
	SvbaseLimag::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatLimag::set(const ScmatLimag &sli)
{
	SvbaseLimag::set(sli);
	m_N0 = sli.m_N0; m_N1 = sli.m_N1;
}

inline ScmatLimag::~ScmatLimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLimag &ScmatLimag_O, &ScmatLimag_IO;

// common api for STL and SLISC
inline Limag *p(ScmatLimag &v) { return v.p(); }



#ifdef SLS_USE_INT_AS_LONG
typedef ScmatInt ScmatLong;
typedef ScmatIntC ScmatLongC;
#else
typedef ScmatLlong ScmatLong;
typedef ScmatLlongC ScmatLongC;
#endif

typedef const ScmatLongC &ScmatLong_I;
// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLong &ScmatLong_O, &ScmatLong_IO;
} // namespace slisc
