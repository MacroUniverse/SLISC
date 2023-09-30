#pragma once
#include "../dense/Svec.h"
// "C" means lower level const

namespace slisc {
class ScmatCharC : public SvecCharC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatCharC();
	ScmatCharC(const Char *data, Long_I N0, Long_I N1);


	const Char &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Char *data, Long_I N0, Long_I N1);
	~ScmatCharC();
};

inline ScmatCharC::ScmatCharC() {}

inline ScmatCharC::ScmatCharC(const Char *data, Long_I N0, Long_I N1)
	: SvecCharC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecCharC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatCharC::~ScmatCharC() {}

typedef const ScmatCharC &ScmatChar_I;

// common api for STL and SLISC
inline Long size(ScmatChar_I v) { return v.size(); }

inline const Char *p(ScmatChar_I v) { return v.p(); }


class ScmatChar : public SvecChar
{
protected:
	Long m_N0, m_N1;
public:
	ScmatChar();
	ScmatChar(Char *data, Long_I N0, Long_I N1);

	operator ScmatCharC() const;

	Char &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Char *data, Long_I N0, Long_I N1);
	~ScmatChar();
};

inline ScmatChar::ScmatChar() {}

inline ScmatChar::ScmatChar(Char *data, Long_I N0, Long_I N1)
	: SvecChar(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecChar::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatChar::~ScmatChar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatChar &ScmatChar_O, &ScmatChar_IO;

// common api for STL and SLISC
inline Char *p(ScmatChar &v) { return v.p(); }


class ScmatUcharC : public SvecUcharC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatUcharC();
	ScmatUcharC(const Uchar *data, Long_I N0, Long_I N1);


	const Uchar &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Uchar *data, Long_I N0, Long_I N1);
	~ScmatUcharC();
};

inline ScmatUcharC::ScmatUcharC() {}

inline ScmatUcharC::ScmatUcharC(const Uchar *data, Long_I N0, Long_I N1)
	: SvecUcharC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecUcharC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatUcharC::~ScmatUcharC() {}

typedef const ScmatUcharC &ScmatUchar_I;

// common api for STL and SLISC
inline Long size(ScmatUchar_I v) { return v.size(); }

inline const Uchar *p(ScmatUchar_I v) { return v.p(); }


class ScmatUchar : public SvecUchar
{
protected:
	Long m_N0, m_N1;
public:
	ScmatUchar();
	ScmatUchar(Uchar *data, Long_I N0, Long_I N1);

	operator ScmatUcharC() const;

	Uchar &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Uchar *data, Long_I N0, Long_I N1);
	~ScmatUchar();
};

inline ScmatUchar::ScmatUchar() {}

inline ScmatUchar::ScmatUchar(Uchar *data, Long_I N0, Long_I N1)
	: SvecUchar(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecUchar::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatUchar::~ScmatUchar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatUchar &ScmatUchar_O, &ScmatUchar_IO;

// common api for STL and SLISC
inline Uchar *p(ScmatUchar &v) { return v.p(); }


class ScmatIntC : public SvecIntC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatIntC();
	ScmatIntC(const Int *data, Long_I N0, Long_I N1);


	const Int &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Int *data, Long_I N0, Long_I N1);
	~ScmatIntC();
};

inline ScmatIntC::ScmatIntC() {}

inline ScmatIntC::ScmatIntC(const Int *data, Long_I N0, Long_I N1)
	: SvecIntC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecIntC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatIntC::~ScmatIntC() {}

typedef const ScmatIntC &ScmatInt_I;

// common api for STL and SLISC
inline Long size(ScmatInt_I v) { return v.size(); }

inline const Int *p(ScmatInt_I v) { return v.p(); }


class ScmatInt : public SvecInt
{
protected:
	Long m_N0, m_N1;
public:
	ScmatInt();
	ScmatInt(Int *data, Long_I N0, Long_I N1);

	operator ScmatIntC() const;

	Int &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Int *data, Long_I N0, Long_I N1);
	~ScmatInt();
};

inline ScmatInt::ScmatInt() {}

inline ScmatInt::ScmatInt(Int *data, Long_I N0, Long_I N1)
	: SvecInt(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecInt::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatInt::~ScmatInt() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatInt &ScmatInt_O, &ScmatInt_IO;

// common api for STL and SLISC
inline Int *p(ScmatInt &v) { return v.p(); }


class ScmatLlongC : public SvecLlongC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLlongC();
	ScmatLlongC(const Llong *data, Long_I N0, Long_I N1);


	const Llong &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Llong *data, Long_I N0, Long_I N1);
	~ScmatLlongC();
};

inline ScmatLlongC::ScmatLlongC() {}

inline ScmatLlongC::ScmatLlongC(const Llong *data, Long_I N0, Long_I N1)
	: SvecLlongC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecLlongC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatLlongC::~ScmatLlongC() {}

typedef const ScmatLlongC &ScmatLlong_I;

// common api for STL and SLISC
inline Long size(ScmatLlong_I v) { return v.size(); }

inline const Llong *p(ScmatLlong_I v) { return v.p(); }


class ScmatLlong : public SvecLlong
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLlong();
	ScmatLlong(Llong *data, Long_I N0, Long_I N1);

	operator ScmatLlongC() const;

	Llong &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Llong *data, Long_I N0, Long_I N1);
	~ScmatLlong();
};

inline ScmatLlong::ScmatLlong() {}

inline ScmatLlong::ScmatLlong(Llong *data, Long_I N0, Long_I N1)
	: SvecLlong(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecLlong::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatLlong::~ScmatLlong() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLlong &ScmatLlong_O, &ScmatLlong_IO;

// common api for STL and SLISC
inline Llong *p(ScmatLlong &v) { return v.p(); }


class ScmatFloatC : public SvecFloatC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFloatC();
	ScmatFloatC(const Float *data, Long_I N0, Long_I N1);


	const Float &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Float *data, Long_I N0, Long_I N1);
	~ScmatFloatC();
};

inline ScmatFloatC::ScmatFloatC() {}

inline ScmatFloatC::ScmatFloatC(const Float *data, Long_I N0, Long_I N1)
	: SvecFloatC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecFloatC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatFloatC::~ScmatFloatC() {}

typedef const ScmatFloatC &ScmatFloat_I;

// common api for STL and SLISC
inline Long size(ScmatFloat_I v) { return v.size(); }

inline const Float *p(ScmatFloat_I v) { return v.p(); }


class ScmatFloat : public SvecFloat
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFloat();
	ScmatFloat(Float *data, Long_I N0, Long_I N1);

	operator ScmatFloatC() const;

	Float &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Float *data, Long_I N0, Long_I N1);
	~ScmatFloat();
};

inline ScmatFloat::ScmatFloat() {}

inline ScmatFloat::ScmatFloat(Float *data, Long_I N0, Long_I N1)
	: SvecFloat(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecFloat::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatFloat::~ScmatFloat() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatFloat &ScmatFloat_O, &ScmatFloat_IO;

// common api for STL and SLISC
inline Float *p(ScmatFloat &v) { return v.p(); }


class ScmatDoubC : public SvecDoubC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatDoubC();
	ScmatDoubC(const Doub *data, Long_I N0, Long_I N1);


	const Doub &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Doub *data, Long_I N0, Long_I N1);
	~ScmatDoubC();
};

inline ScmatDoubC::ScmatDoubC() {}

inline ScmatDoubC::ScmatDoubC(const Doub *data, Long_I N0, Long_I N1)
	: SvecDoubC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecDoubC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatDoubC::~ScmatDoubC() {}

typedef const ScmatDoubC &ScmatDoub_I;

// common api for STL and SLISC
inline Long size(ScmatDoub_I v) { return v.size(); }

inline const Doub *p(ScmatDoub_I v) { return v.p(); }


class ScmatDoub : public SvecDoub
{
protected:
	Long m_N0, m_N1;
public:
	ScmatDoub();
	ScmatDoub(Doub *data, Long_I N0, Long_I N1);

	operator ScmatDoubC() const;

	Doub &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Doub *data, Long_I N0, Long_I N1);
	~ScmatDoub();
};

inline ScmatDoub::ScmatDoub() {}

inline ScmatDoub::ScmatDoub(Doub *data, Long_I N0, Long_I N1)
	: SvecDoub(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecDoub::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatDoub::~ScmatDoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatDoub &ScmatDoub_O, &ScmatDoub_IO;

// common api for STL and SLISC
inline Doub *p(ScmatDoub &v) { return v.p(); }


class ScmatLdoubC : public SvecLdoubC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLdoubC();
	ScmatLdoubC(const Ldoub *data, Long_I N0, Long_I N1);


	const Ldoub &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Ldoub *data, Long_I N0, Long_I N1);
	~ScmatLdoubC();
};

inline ScmatLdoubC::ScmatLdoubC() {}

inline ScmatLdoubC::ScmatLdoubC(const Ldoub *data, Long_I N0, Long_I N1)
	: SvecLdoubC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecLdoubC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatLdoubC::~ScmatLdoubC() {}

typedef const ScmatLdoubC &ScmatLdoub_I;

// common api for STL and SLISC
inline Long size(ScmatLdoub_I v) { return v.size(); }

inline const Ldoub *p(ScmatLdoub_I v) { return v.p(); }


class ScmatLdoub : public SvecLdoub
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLdoub();
	ScmatLdoub(Ldoub *data, Long_I N0, Long_I N1);

	operator ScmatLdoubC() const;

	Ldoub &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Ldoub *data, Long_I N0, Long_I N1);
	~ScmatLdoub();
};

inline ScmatLdoub::ScmatLdoub() {}

inline ScmatLdoub::ScmatLdoub(Ldoub *data, Long_I N0, Long_I N1)
	: SvecLdoub(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecLdoub::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatLdoub::~ScmatLdoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLdoub &ScmatLdoub_O, &ScmatLdoub_IO;

// common api for STL and SLISC
inline Ldoub *p(ScmatLdoub &v) { return v.p(); }


class ScmatQdoubC : public SvecQdoubC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatQdoubC();
	ScmatQdoubC(const Qdoub *data, Long_I N0, Long_I N1);


	const Qdoub &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Qdoub *data, Long_I N0, Long_I N1);
	~ScmatQdoubC();
};

inline ScmatQdoubC::ScmatQdoubC() {}

inline ScmatQdoubC::ScmatQdoubC(const Qdoub *data, Long_I N0, Long_I N1)
	: SvecQdoubC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Qdoub &ScmatQdoubC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatQdoubC::n0() const
{
	return m_N0;
}

inline Long ScmatQdoubC::n1() const
{
	return m_N1;
}

inline void ScmatQdoubC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatQdoubC::set(const Qdoub *data, Long_I N0, Long_I N1)
{
	SvecQdoubC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatQdoubC::~ScmatQdoubC() {}

typedef const ScmatQdoubC &ScmatQdoub_I;

// common api for STL and SLISC
inline Long size(ScmatQdoub_I v) { return v.size(); }

inline const Qdoub *p(ScmatQdoub_I v) { return v.p(); }


class ScmatQdoub : public SvecQdoub
{
protected:
	Long m_N0, m_N1;
public:
	ScmatQdoub();
	ScmatQdoub(Qdoub *data, Long_I N0, Long_I N1);

	operator ScmatQdoubC() const;

	Qdoub &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Qdoub *data, Long_I N0, Long_I N1);
	~ScmatQdoub();
};

inline ScmatQdoub::ScmatQdoub() {}

inline ScmatQdoub::ScmatQdoub(Qdoub *data, Long_I N0, Long_I N1)
	: SvecQdoub(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatQdoub::operator ScmatQdoubC() const
{
	return *((ScmatQdoubC *)this);
}

inline Qdoub &ScmatQdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatQdoub::n0() const
{
	return m_N0;
}

inline Long ScmatQdoub::n1() const
{
	return m_N1;
}

inline void ScmatQdoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatQdoub::set(Qdoub *data, Long_I N0, Long_I N1)
{
	SvecQdoub::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatQdoub::~ScmatQdoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatQdoub &ScmatQdoub_O, &ScmatQdoub_IO;

// common api for STL and SLISC
inline Qdoub *p(ScmatQdoub &v) { return v.p(); }


class ScmatFcompC : public SvecFcompC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFcompC();
	ScmatFcompC(const Fcomp *data, Long_I N0, Long_I N1);


	const Fcomp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Fcomp *data, Long_I N0, Long_I N1);
	~ScmatFcompC();
};

inline ScmatFcompC::ScmatFcompC() {}

inline ScmatFcompC::ScmatFcompC(const Fcomp *data, Long_I N0, Long_I N1)
	: SvecFcompC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecFcompC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatFcompC::~ScmatFcompC() {}

typedef const ScmatFcompC &ScmatFcomp_I;

// common api for STL and SLISC
inline Long size(ScmatFcomp_I v) { return v.size(); }

inline const Fcomp *p(ScmatFcomp_I v) { return v.p(); }


class ScmatFcomp : public SvecFcomp
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFcomp();
	ScmatFcomp(Fcomp *data, Long_I N0, Long_I N1);

	operator ScmatFcompC() const;

	Fcomp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Fcomp *data, Long_I N0, Long_I N1);
	~ScmatFcomp();
};

inline ScmatFcomp::ScmatFcomp() {}

inline ScmatFcomp::ScmatFcomp(Fcomp *data, Long_I N0, Long_I N1)
	: SvecFcomp(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecFcomp::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatFcomp::~ScmatFcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatFcomp &ScmatFcomp_O, &ScmatFcomp_IO;

// common api for STL and SLISC
inline Fcomp *p(ScmatFcomp &v) { return v.p(); }


class ScmatCompC : public SvecCompC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatCompC();
	ScmatCompC(const Comp *data, Long_I N0, Long_I N1);


	const Comp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Comp *data, Long_I N0, Long_I N1);
	~ScmatCompC();
};

inline ScmatCompC::ScmatCompC() {}

inline ScmatCompC::ScmatCompC(const Comp *data, Long_I N0, Long_I N1)
	: SvecCompC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecCompC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatCompC::~ScmatCompC() {}

typedef const ScmatCompC &ScmatComp_I;

// common api for STL and SLISC
inline Long size(ScmatComp_I v) { return v.size(); }

inline const Comp *p(ScmatComp_I v) { return v.p(); }


class ScmatComp : public SvecComp
{
protected:
	Long m_N0, m_N1;
public:
	ScmatComp();
	ScmatComp(Comp *data, Long_I N0, Long_I N1);

	operator ScmatCompC() const;

	Comp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Comp *data, Long_I N0, Long_I N1);
	~ScmatComp();
};

inline ScmatComp::ScmatComp() {}

inline ScmatComp::ScmatComp(Comp *data, Long_I N0, Long_I N1)
	: SvecComp(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecComp::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatComp::~ScmatComp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatComp &ScmatComp_O, &ScmatComp_IO;

// common api for STL and SLISC
inline Comp *p(ScmatComp &v) { return v.p(); }


class ScmatLcompC : public SvecLcompC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLcompC();
	ScmatLcompC(const Lcomp *data, Long_I N0, Long_I N1);


	const Lcomp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Lcomp *data, Long_I N0, Long_I N1);
	~ScmatLcompC();
};

inline ScmatLcompC::ScmatLcompC() {}

inline ScmatLcompC::ScmatLcompC(const Lcomp *data, Long_I N0, Long_I N1)
	: SvecLcompC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecLcompC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatLcompC::~ScmatLcompC() {}

typedef const ScmatLcompC &ScmatLcomp_I;

// common api for STL and SLISC
inline Long size(ScmatLcomp_I v) { return v.size(); }

inline const Lcomp *p(ScmatLcomp_I v) { return v.p(); }


class ScmatLcomp : public SvecLcomp
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLcomp();
	ScmatLcomp(Lcomp *data, Long_I N0, Long_I N1);

	operator ScmatLcompC() const;

	Lcomp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Lcomp *data, Long_I N0, Long_I N1);
	~ScmatLcomp();
};

inline ScmatLcomp::ScmatLcomp() {}

inline ScmatLcomp::ScmatLcomp(Lcomp *data, Long_I N0, Long_I N1)
	: SvecLcomp(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecLcomp::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatLcomp::~ScmatLcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLcomp &ScmatLcomp_O, &ScmatLcomp_IO;

// common api for STL and SLISC
inline Lcomp *p(ScmatLcomp &v) { return v.p(); }


class ScmatQcompC : public SvecQcompC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatQcompC();
	ScmatQcompC(const Qcomp *data, Long_I N0, Long_I N1);


	const Qcomp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Qcomp *data, Long_I N0, Long_I N1);
	~ScmatQcompC();
};

inline ScmatQcompC::ScmatQcompC() {}

inline ScmatQcompC::ScmatQcompC(const Qcomp *data, Long_I N0, Long_I N1)
	: SvecQcompC(data, N0*N1), m_N0(N0), m_N1(N1) {}


inline const Qcomp &ScmatQcompC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatQcompC::n0() const
{
	return m_N0;
}

inline Long ScmatQcompC::n1() const
{
	return m_N1;
}

inline void ScmatQcompC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatQcompC::set(const Qcomp *data, Long_I N0, Long_I N1)
{
	SvecQcompC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatQcompC::~ScmatQcompC() {}

typedef const ScmatQcompC &ScmatQcomp_I;

// common api for STL and SLISC
inline Long size(ScmatQcomp_I v) { return v.size(); }

inline const Qcomp *p(ScmatQcomp_I v) { return v.p(); }


class ScmatQcomp : public SvecQcomp
{
protected:
	Long m_N0, m_N1;
public:
	ScmatQcomp();
	ScmatQcomp(Qcomp *data, Long_I N0, Long_I N1);

	operator ScmatQcompC() const;

	Qcomp &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Qcomp *data, Long_I N0, Long_I N1);
	~ScmatQcomp();
};

inline ScmatQcomp::ScmatQcomp() {}

inline ScmatQcomp::ScmatQcomp(Qcomp *data, Long_I N0, Long_I N1)
	: SvecQcomp(data, N0*N1), m_N0(N0), m_N1(N1) {}

inline ScmatQcomp::operator ScmatQcompC() const
{
	return *((ScmatQcompC *)this);
}

inline Qcomp &ScmatQcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("Matrix subscript out of bounds");
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatQcomp::n0() const
{
	return m_N0;
}

inline Long ScmatQcomp::n1() const
{
	return m_N1;
}

inline void ScmatQcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N)
		SLS_ERR("illegal reshape!");
#endif
	m_N0 = N0; m_N1 = N1;
}

inline void ScmatQcomp::set(Qcomp *data, Long_I N0, Long_I N1)
{
	SvecQcomp::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatQcomp::~ScmatQcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatQcomp &ScmatQcomp_O, &ScmatQcomp_IO;

// common api for STL and SLISC
inline Qcomp *p(ScmatQcomp &v) { return v.p(); }


class ScmatFimagC : public SvecFimagC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFimagC();
	ScmatFimagC(const Fimag *data, Long_I N0, Long_I N1);


	const Fimag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Fimag *data, Long_I N0, Long_I N1);
	~ScmatFimagC();
};

inline ScmatFimagC::ScmatFimagC() {}

inline ScmatFimagC::ScmatFimagC(const Fimag *data, Long_I N0, Long_I N1)
	: SvecFimagC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecFimagC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatFimagC::~ScmatFimagC() {}

typedef const ScmatFimagC &ScmatFimag_I;

// common api for STL and SLISC
inline Long size(ScmatFimag_I v) { return v.size(); }

inline const Fimag *p(ScmatFimag_I v) { return v.p(); }


class ScmatFimag : public SvecFimag
{
protected:
	Long m_N0, m_N1;
public:
	ScmatFimag();
	ScmatFimag(Fimag *data, Long_I N0, Long_I N1);

	operator ScmatFimagC() const;

	Fimag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Fimag *data, Long_I N0, Long_I N1);
	~ScmatFimag();
};

inline ScmatFimag::ScmatFimag() {}

inline ScmatFimag::ScmatFimag(Fimag *data, Long_I N0, Long_I N1)
	: SvecFimag(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecFimag::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatFimag::~ScmatFimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatFimag &ScmatFimag_O, &ScmatFimag_IO;

// common api for STL and SLISC
inline Fimag *p(ScmatFimag &v) { return v.p(); }


class ScmatImagC : public SvecImagC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatImagC();
	ScmatImagC(const Imag *data, Long_I N0, Long_I N1);


	const Imag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Imag *data, Long_I N0, Long_I N1);
	~ScmatImagC();
};

inline ScmatImagC::ScmatImagC() {}

inline ScmatImagC::ScmatImagC(const Imag *data, Long_I N0, Long_I N1)
	: SvecImagC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecImagC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatImagC::~ScmatImagC() {}

typedef const ScmatImagC &ScmatImag_I;

// common api for STL and SLISC
inline Long size(ScmatImag_I v) { return v.size(); }

inline const Imag *p(ScmatImag_I v) { return v.p(); }


class ScmatImag : public SvecImag
{
protected:
	Long m_N0, m_N1;
public:
	ScmatImag();
	ScmatImag(Imag *data, Long_I N0, Long_I N1);

	operator ScmatImagC() const;

	Imag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Imag *data, Long_I N0, Long_I N1);
	~ScmatImag();
};

inline ScmatImag::ScmatImag() {}

inline ScmatImag::ScmatImag(Imag *data, Long_I N0, Long_I N1)
	: SvecImag(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecImag::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatImag::~ScmatImag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatImag &ScmatImag_O, &ScmatImag_IO;

// common api for STL and SLISC
inline Imag *p(ScmatImag &v) { return v.p(); }


class ScmatLimagC : public SvecLimagC
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLimagC();
	ScmatLimagC(const Limag *data, Long_I N0, Long_I N1);


	const Limag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Limag *data, Long_I N0, Long_I N1);
	~ScmatLimagC();
};

inline ScmatLimagC::ScmatLimagC() {}

inline ScmatLimagC::ScmatLimagC(const Limag *data, Long_I N0, Long_I N1)
	: SvecLimagC(data, N0*N1), m_N0(N0), m_N1(N1) {}


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
	SvecLimagC::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
}

inline ScmatLimagC::~ScmatLimagC() {}

typedef const ScmatLimagC &ScmatLimag_I;

// common api for STL and SLISC
inline Long size(ScmatLimag_I v) { return v.size(); }

inline const Limag *p(ScmatLimag_I v) { return v.p(); }


class ScmatLimag : public SvecLimag
{
protected:
	Long m_N0, m_N1;
public:
	ScmatLimag();
	ScmatLimag(Limag *data, Long_I N0, Long_I N1);

	operator ScmatLimagC() const;

	Limag &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Limag *data, Long_I N0, Long_I N1);
	~ScmatLimag();
};

inline ScmatLimag::ScmatLimag() {}

inline ScmatLimag::ScmatLimag(Limag *data, Long_I N0, Long_I N1)
	: SvecLimag(data, N0*N1), m_N0(N0), m_N1(N1) {}

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
	SvecLimag::set(data, N0*N1);
	m_N0 = N0; m_N1 = N1;
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
