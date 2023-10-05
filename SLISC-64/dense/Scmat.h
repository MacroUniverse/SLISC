#pragma once
#include "../dense/Svec.h"
#include "../str/str.h"
// "C" means lower level const

namespace slisc {
class ScmatBoolC : public SvbaseBoolC
{
protected:
	Long m_N0;
public:
	ScmatBoolC();
	ScmatBoolC(const Bool *data, Long_I N0, Long_I N1);


	const Bool &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(const Bool *data, Long_I N0, Long_I N1);
	~ScmatBoolC();
};

inline ScmatBoolC::ScmatBoolC() {}

inline ScmatBoolC::ScmatBoolC(const Bool *data, Long_I N0, Long_I N1)
	: SvbaseBoolC(data, N0*N1), m_N0(N0) {}


inline const Bool &ScmatBoolC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatBool index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatBoolC::n0() const
{
	return m_N0;
}

inline Long ScmatBoolC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatBoolC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatBool reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatBoolC::set(const Bool *data, Long_I N0, Long_I N1)
{
	SvbaseBoolC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatBoolC::~ScmatBoolC() {}

typedef const ScmatBoolC &ScmatBool_I;


class ScmatBool : public SvbaseBool
{
protected:
	Long m_N0;
public:
	ScmatBool();
	ScmatBool(Bool *data, Long_I N0, Long_I N1);

	operator const ScmatBoolC &() const;
	operator ScmatBoolC &();

	Bool &operator()(Long_I i, Long_I j) const; // double indexing
	Long n0() const;
	Long n1() const;

	// resize() is a bad idea, don't try to create it!

	// There is no upper bound checking of N, use with care
	void reshape(Long_I N0, Long_I N1);
	void set(Bool *data, Long_I N0, Long_I N1);
	~ScmatBool();
};

inline ScmatBool::ScmatBool() {}

inline ScmatBool::ScmatBool(Bool *data, Long_I N0, Long_I N1)
	: SvbaseBool(data, N0*N1), m_N0(N0) {}

inline ScmatBool::operator const ScmatBoolC &() const
{
	return reinterpret_cast<const ScmatBoolC &>(*this);
}

inline ScmatBool::operator ScmatBoolC &()
{
	return reinterpret_cast<ScmatBoolC &>(*this);
}

inline Bool &ScmatBool::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatBool index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatBool::n0() const
{
	return m_N0;
}

inline Long ScmatBool::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatBool::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatBool reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatBool::set(Bool *data, Long_I N0, Long_I N1)
{
	SvbaseBool::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatBool::~ScmatBool() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatBool &ScmatBool_O, &ScmatBool_IO;


class ScmatCharC : public SvbaseCharC
{
protected:
	Long m_N0;
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
	: SvbaseCharC(data, N0*N1), m_N0(N0) {}


inline const Char &ScmatCharC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatChar index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatCharC::n0() const
{
	return m_N0;
}

inline Long ScmatCharC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatCharC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatChar reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatCharC::set(const Char *data, Long_I N0, Long_I N1)
{
	SvbaseCharC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatCharC::~ScmatCharC() {}

typedef const ScmatCharC &ScmatChar_I;


class ScmatChar : public SvbaseChar
{
protected:
	Long m_N0;
public:
	ScmatChar();
	ScmatChar(Char *data, Long_I N0, Long_I N1);

	operator const ScmatCharC &() const;
	operator ScmatCharC &();

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
	: SvbaseChar(data, N0*N1), m_N0(N0) {}

inline ScmatChar::operator const ScmatCharC &() const
{
	return reinterpret_cast<const ScmatCharC &>(*this);
}

inline ScmatChar::operator ScmatCharC &()
{
	return reinterpret_cast<ScmatCharC &>(*this);
}

inline Char &ScmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatChar index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatChar::n0() const
{
	return m_N0;
}

inline Long ScmatChar::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatChar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatChar reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatChar::set(Char *data, Long_I N0, Long_I N1)
{
	SvbaseChar::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatChar::~ScmatChar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatChar &ScmatChar_O, &ScmatChar_IO;


class ScmatUcharC : public SvbaseUcharC
{
protected:
	Long m_N0;
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
	: SvbaseUcharC(data, N0*N1), m_N0(N0) {}


inline const Uchar &ScmatUcharC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatUchar index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatUcharC::n0() const
{
	return m_N0;
}

inline Long ScmatUcharC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatUcharC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatUchar reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatUcharC::set(const Uchar *data, Long_I N0, Long_I N1)
{
	SvbaseUcharC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatUcharC::~ScmatUcharC() {}

typedef const ScmatUcharC &ScmatUchar_I;


class ScmatUchar : public SvbaseUchar
{
protected:
	Long m_N0;
public:
	ScmatUchar();
	ScmatUchar(Uchar *data, Long_I N0, Long_I N1);

	operator const ScmatUcharC &() const;
	operator ScmatUcharC &();

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
	: SvbaseUchar(data, N0*N1), m_N0(N0) {}

inline ScmatUchar::operator const ScmatUcharC &() const
{
	return reinterpret_cast<const ScmatUcharC &>(*this);
}

inline ScmatUchar::operator ScmatUcharC &()
{
	return reinterpret_cast<ScmatUcharC &>(*this);
}

inline Uchar &ScmatUchar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatUchar index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatUchar::n0() const
{
	return m_N0;
}

inline Long ScmatUchar::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatUchar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatUchar reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatUchar::set(Uchar *data, Long_I N0, Long_I N1)
{
	SvbaseUchar::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatUchar::~ScmatUchar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatUchar &ScmatUchar_O, &ScmatUchar_IO;


class ScmatIntC : public SvbaseIntC
{
protected:
	Long m_N0;
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
	: SvbaseIntC(data, N0*N1), m_N0(N0) {}


inline const Int &ScmatIntC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatInt index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatIntC::n0() const
{
	return m_N0;
}

inline Long ScmatIntC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatIntC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatInt reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatIntC::set(const Int *data, Long_I N0, Long_I N1)
{
	SvbaseIntC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatIntC::~ScmatIntC() {}

typedef const ScmatIntC &ScmatInt_I;


class ScmatInt : public SvbaseInt
{
protected:
	Long m_N0;
public:
	ScmatInt();
	ScmatInt(Int *data, Long_I N0, Long_I N1);

	operator const ScmatIntC &() const;
	operator ScmatIntC &();

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
	: SvbaseInt(data, N0*N1), m_N0(N0) {}

inline ScmatInt::operator const ScmatIntC &() const
{
	return reinterpret_cast<const ScmatIntC &>(*this);
}

inline ScmatInt::operator ScmatIntC &()
{
	return reinterpret_cast<ScmatIntC &>(*this);
}

inline Int &ScmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatInt index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatInt::n0() const
{
	return m_N0;
}

inline Long ScmatInt::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatInt::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatInt reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatInt::set(Int *data, Long_I N0, Long_I N1)
{
	SvbaseInt::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatInt::~ScmatInt() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatInt &ScmatInt_O, &ScmatInt_IO;


class ScmatLlongC : public SvbaseLlongC
{
protected:
	Long m_N0;
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
	: SvbaseLlongC(data, N0*N1), m_N0(N0) {}


inline const Llong &ScmatLlongC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatLlong index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLlongC::n0() const
{
	return m_N0;
}

inline Long ScmatLlongC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatLlongC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatLlong reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatLlongC::set(const Llong *data, Long_I N0, Long_I N1)
{
	SvbaseLlongC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatLlongC::~ScmatLlongC() {}

typedef const ScmatLlongC &ScmatLlong_I;


class ScmatLlong : public SvbaseLlong
{
protected:
	Long m_N0;
public:
	ScmatLlong();
	ScmatLlong(Llong *data, Long_I N0, Long_I N1);

	operator const ScmatLlongC &() const;
	operator ScmatLlongC &();

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
	: SvbaseLlong(data, N0*N1), m_N0(N0) {}

inline ScmatLlong::operator const ScmatLlongC &() const
{
	return reinterpret_cast<const ScmatLlongC &>(*this);
}

inline ScmatLlong::operator ScmatLlongC &()
{
	return reinterpret_cast<ScmatLlongC &>(*this);
}

inline Llong &ScmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatLlong index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLlong::n0() const
{
	return m_N0;
}

inline Long ScmatLlong::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatLlong::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatLlong reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatLlong::set(Llong *data, Long_I N0, Long_I N1)
{
	SvbaseLlong::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatLlong::~ScmatLlong() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLlong &ScmatLlong_O, &ScmatLlong_IO;


class ScmatFloatC : public SvbaseFloatC
{
protected:
	Long m_N0;
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
	: SvbaseFloatC(data, N0*N1), m_N0(N0) {}


inline const Float &ScmatFloatC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatFloat index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFloatC::n0() const
{
	return m_N0;
}

inline Long ScmatFloatC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatFloatC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatFloat reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatFloatC::set(const Float *data, Long_I N0, Long_I N1)
{
	SvbaseFloatC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatFloatC::~ScmatFloatC() {}

typedef const ScmatFloatC &ScmatFloat_I;


class ScmatFloat : public SvbaseFloat
{
protected:
	Long m_N0;
public:
	ScmatFloat();
	ScmatFloat(Float *data, Long_I N0, Long_I N1);

	operator const ScmatFloatC &() const;
	operator ScmatFloatC &();

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
	: SvbaseFloat(data, N0*N1), m_N0(N0) {}

inline ScmatFloat::operator const ScmatFloatC &() const
{
	return reinterpret_cast<const ScmatFloatC &>(*this);
}

inline ScmatFloat::operator ScmatFloatC &()
{
	return reinterpret_cast<ScmatFloatC &>(*this);
}

inline Float &ScmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatFloat index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFloat::n0() const
{
	return m_N0;
}

inline Long ScmatFloat::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatFloat::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatFloat reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatFloat::set(Float *data, Long_I N0, Long_I N1)
{
	SvbaseFloat::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatFloat::~ScmatFloat() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatFloat &ScmatFloat_O, &ScmatFloat_IO;


class ScmatDoubC : public SvbaseDoubC
{
protected:
	Long m_N0;
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
	: SvbaseDoubC(data, N0*N1), m_N0(N0) {}


inline const Doub &ScmatDoubC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatDoub index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatDoubC::n0() const
{
	return m_N0;
}

inline Long ScmatDoubC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatDoubC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatDoub reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatDoubC::set(const Doub *data, Long_I N0, Long_I N1)
{
	SvbaseDoubC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatDoubC::~ScmatDoubC() {}

typedef const ScmatDoubC &ScmatDoub_I;


class ScmatDoub : public SvbaseDoub
{
protected:
	Long m_N0;
public:
	ScmatDoub();
	ScmatDoub(Doub *data, Long_I N0, Long_I N1);

	operator const ScmatDoubC &() const;
	operator ScmatDoubC &();

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
	: SvbaseDoub(data, N0*N1), m_N0(N0) {}

inline ScmatDoub::operator const ScmatDoubC &() const
{
	return reinterpret_cast<const ScmatDoubC &>(*this);
}

inline ScmatDoub::operator ScmatDoubC &()
{
	return reinterpret_cast<ScmatDoubC &>(*this);
}

inline Doub &ScmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatDoub index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatDoub::n0() const
{
	return m_N0;
}

inline Long ScmatDoub::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatDoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatDoub reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatDoub::set(Doub *data, Long_I N0, Long_I N1)
{
	SvbaseDoub::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatDoub::~ScmatDoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatDoub &ScmatDoub_O, &ScmatDoub_IO;


class ScmatLdoubC : public SvbaseLdoubC
{
protected:
	Long m_N0;
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
	: SvbaseLdoubC(data, N0*N1), m_N0(N0) {}


inline const Ldoub &ScmatLdoubC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatLdoub index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLdoubC::n0() const
{
	return m_N0;
}

inline Long ScmatLdoubC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatLdoubC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatLdoub reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatLdoubC::set(const Ldoub *data, Long_I N0, Long_I N1)
{
	SvbaseLdoubC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatLdoubC::~ScmatLdoubC() {}

typedef const ScmatLdoubC &ScmatLdoub_I;


class ScmatLdoub : public SvbaseLdoub
{
protected:
	Long m_N0;
public:
	ScmatLdoub();
	ScmatLdoub(Ldoub *data, Long_I N0, Long_I N1);

	operator const ScmatLdoubC &() const;
	operator ScmatLdoubC &();

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
	: SvbaseLdoub(data, N0*N1), m_N0(N0) {}

inline ScmatLdoub::operator const ScmatLdoubC &() const
{
	return reinterpret_cast<const ScmatLdoubC &>(*this);
}

inline ScmatLdoub::operator ScmatLdoubC &()
{
	return reinterpret_cast<ScmatLdoubC &>(*this);
}

inline Ldoub &ScmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatLdoub index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLdoub::n0() const
{
	return m_N0;
}

inline Long ScmatLdoub::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatLdoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatLdoub reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatLdoub::set(Ldoub *data, Long_I N0, Long_I N1)
{
	SvbaseLdoub::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatLdoub::~ScmatLdoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLdoub &ScmatLdoub_O, &ScmatLdoub_IO;




class ScmatFcompC : public SvbaseFcompC
{
protected:
	Long m_N0;
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
	: SvbaseFcompC(data, N0*N1), m_N0(N0) {}


inline const Fcomp &ScmatFcompC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatFcomp index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFcompC::n0() const
{
	return m_N0;
}

inline Long ScmatFcompC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatFcompC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatFcomp reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatFcompC::set(const Fcomp *data, Long_I N0, Long_I N1)
{
	SvbaseFcompC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatFcompC::~ScmatFcompC() {}

typedef const ScmatFcompC &ScmatFcomp_I;


class ScmatFcomp : public SvbaseFcomp
{
protected:
	Long m_N0;
public:
	ScmatFcomp();
	ScmatFcomp(Fcomp *data, Long_I N0, Long_I N1);

	operator const ScmatFcompC &() const;
	operator ScmatFcompC &();

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
	: SvbaseFcomp(data, N0*N1), m_N0(N0) {}

inline ScmatFcomp::operator const ScmatFcompC &() const
{
	return reinterpret_cast<const ScmatFcompC &>(*this);
}

inline ScmatFcomp::operator ScmatFcompC &()
{
	return reinterpret_cast<ScmatFcompC &>(*this);
}

inline Fcomp &ScmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatFcomp index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFcomp::n0() const
{
	return m_N0;
}

inline Long ScmatFcomp::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatFcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatFcomp reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatFcomp::set(Fcomp *data, Long_I N0, Long_I N1)
{
	SvbaseFcomp::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatFcomp::~ScmatFcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatFcomp &ScmatFcomp_O, &ScmatFcomp_IO;


class ScmatCompC : public SvbaseCompC
{
protected:
	Long m_N0;
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
	: SvbaseCompC(data, N0*N1), m_N0(N0) {}


inline const Comp &ScmatCompC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatComp index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatCompC::n0() const
{
	return m_N0;
}

inline Long ScmatCompC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatCompC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatComp reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatCompC::set(const Comp *data, Long_I N0, Long_I N1)
{
	SvbaseCompC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatCompC::~ScmatCompC() {}

typedef const ScmatCompC &ScmatComp_I;


class ScmatComp : public SvbaseComp
{
protected:
	Long m_N0;
public:
	ScmatComp();
	ScmatComp(Comp *data, Long_I N0, Long_I N1);

	operator const ScmatCompC &() const;
	operator ScmatCompC &();

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
	: SvbaseComp(data, N0*N1), m_N0(N0) {}

inline ScmatComp::operator const ScmatCompC &() const
{
	return reinterpret_cast<const ScmatCompC &>(*this);
}

inline ScmatComp::operator ScmatCompC &()
{
	return reinterpret_cast<ScmatCompC &>(*this);
}

inline Comp &ScmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatComp index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatComp::n0() const
{
	return m_N0;
}

inline Long ScmatComp::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatComp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatComp reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatComp::set(Comp *data, Long_I N0, Long_I N1)
{
	SvbaseComp::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatComp::~ScmatComp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatComp &ScmatComp_O, &ScmatComp_IO;


class ScmatLcompC : public SvbaseLcompC
{
protected:
	Long m_N0;
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
	: SvbaseLcompC(data, N0*N1), m_N0(N0) {}


inline const Lcomp &ScmatLcompC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatLcomp index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLcompC::n0() const
{
	return m_N0;
}

inline Long ScmatLcompC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatLcompC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatLcomp reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatLcompC::set(const Lcomp *data, Long_I N0, Long_I N1)
{
	SvbaseLcompC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatLcompC::~ScmatLcompC() {}

typedef const ScmatLcompC &ScmatLcomp_I;


class ScmatLcomp : public SvbaseLcomp
{
protected:
	Long m_N0;
public:
	ScmatLcomp();
	ScmatLcomp(Lcomp *data, Long_I N0, Long_I N1);

	operator const ScmatLcompC &() const;
	operator ScmatLcompC &();

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
	: SvbaseLcomp(data, N0*N1), m_N0(N0) {}

inline ScmatLcomp::operator const ScmatLcompC &() const
{
	return reinterpret_cast<const ScmatLcompC &>(*this);
}

inline ScmatLcomp::operator ScmatLcompC &()
{
	return reinterpret_cast<ScmatLcompC &>(*this);
}

inline Lcomp &ScmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatLcomp index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLcomp::n0() const
{
	return m_N0;
}

inline Long ScmatLcomp::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatLcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatLcomp reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatLcomp::set(Lcomp *data, Long_I N0, Long_I N1)
{
	SvbaseLcomp::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatLcomp::~ScmatLcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLcomp &ScmatLcomp_O, &ScmatLcomp_IO;




class ScmatFimagC : public SvbaseFimagC
{
protected:
	Long m_N0;
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
	: SvbaseFimagC(data, N0*N1), m_N0(N0) {}


inline const Fimag &ScmatFimagC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatFimag index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFimagC::n0() const
{
	return m_N0;
}

inline Long ScmatFimagC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatFimagC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatFimag reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatFimagC::set(const Fimag *data, Long_I N0, Long_I N1)
{
	SvbaseFimagC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatFimagC::~ScmatFimagC() {}

typedef const ScmatFimagC &ScmatFimag_I;


class ScmatFimag : public SvbaseFimag
{
protected:
	Long m_N0;
public:
	ScmatFimag();
	ScmatFimag(Fimag *data, Long_I N0, Long_I N1);

	operator const ScmatFimagC &() const;
	operator ScmatFimagC &();

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
	: SvbaseFimag(data, N0*N1), m_N0(N0) {}

inline ScmatFimag::operator const ScmatFimagC &() const
{
	return reinterpret_cast<const ScmatFimagC &>(*this);
}

inline ScmatFimag::operator ScmatFimagC &()
{
	return reinterpret_cast<ScmatFimagC &>(*this);
}

inline Fimag &ScmatFimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatFimag index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatFimag::n0() const
{
	return m_N0;
}

inline Long ScmatFimag::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatFimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatFimag reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatFimag::set(Fimag *data, Long_I N0, Long_I N1)
{
	SvbaseFimag::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatFimag::~ScmatFimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatFimag &ScmatFimag_O, &ScmatFimag_IO;


class ScmatImagC : public SvbaseImagC
{
protected:
	Long m_N0;
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
	: SvbaseImagC(data, N0*N1), m_N0(N0) {}


inline const Imag &ScmatImagC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatImag index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatImagC::n0() const
{
	return m_N0;
}

inline Long ScmatImagC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatImagC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatImag reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatImagC::set(const Imag *data, Long_I N0, Long_I N1)
{
	SvbaseImagC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatImagC::~ScmatImagC() {}

typedef const ScmatImagC &ScmatImag_I;


class ScmatImag : public SvbaseImag
{
protected:
	Long m_N0;
public:
	ScmatImag();
	ScmatImag(Imag *data, Long_I N0, Long_I N1);

	operator const ScmatImagC &() const;
	operator ScmatImagC &();

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
	: SvbaseImag(data, N0*N1), m_N0(N0) {}

inline ScmatImag::operator const ScmatImagC &() const
{
	return reinterpret_cast<const ScmatImagC &>(*this);
}

inline ScmatImag::operator ScmatImagC &()
{
	return reinterpret_cast<ScmatImagC &>(*this);
}

inline Imag &ScmatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatImag index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatImag::n0() const
{
	return m_N0;
}

inline Long ScmatImag::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatImag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatImag reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatImag::set(Imag *data, Long_I N0, Long_I N1)
{
	SvbaseImag::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatImag::~ScmatImag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatImag &ScmatImag_O, &ScmatImag_IO;


class ScmatLimagC : public SvbaseLimagC
{
protected:
	Long m_N0;
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
	: SvbaseLimagC(data, N0*N1), m_N0(N0) {}


inline const Limag &ScmatLimagC::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatLimag index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLimagC::n0() const
{
	return m_N0;
}

inline Long ScmatLimagC::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatLimagC::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatLimag reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatLimagC::set(const Limag *data, Long_I N0, Long_I N1)
{
	SvbaseLimagC::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatLimagC::~ScmatLimagC() {}

typedef const ScmatLimagC &ScmatLimag_I;


class ScmatLimag : public SvbaseLimag
{
protected:
	Long m_N0;
public:
	ScmatLimag();
	ScmatLimag(Limag *data, Long_I N0, Long_I N1);

	operator const ScmatLimagC &() const;
	operator ScmatLimagC &();

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
	: SvbaseLimag(data, N0*N1), m_N0(N0) {}

inline ScmatLimag::operator const ScmatLimagC &() const
{
	return reinterpret_cast<const ScmatLimagC &>(*this);
}

inline ScmatLimag::operator ScmatLimagC &()
{
	return reinterpret_cast<ScmatLimagC &>(*this);
}

inline Limag &ScmatLimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1()) {
		stringstream ss; ss << "ScmatLimag index (" << i << ',' << j << ") out of bounds: shape = (" << m_N0 << ',' << n1() << ')';
		SLS_ERR(ss.str());
	}
#endif
	return m_p[i + m_N0 * j];
}

inline Long ScmatLimag::n0() const
{
	return m_N0;
}

inline Long ScmatLimag::n1() const
{
	return m_N0 == 0 ? 0 : m_N/m_N0;
}

inline void ScmatLimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
	if (N0*N1 != m_N) {
		stringstream ss;
		ss  << "ScmatLimag reshaping from (" << m_N0 << ", " << n1()
			<< ") , with " << m_N << "allocated elements, to (" << N0 << ", "
			<< N1 << "), element number not the same!";
		SLS_ERR(ss.str());
	}
#endif
	m_N0 = N0;
}

inline void ScmatLimag::set(Limag *data, Long_I N0, Long_I N1)
{
	SvbaseLimag::set(data, N0*N1);
	m_N0 = N0;
}

inline ScmatLimag::~ScmatLimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const ScmatLimag &ScmatLimag_O, &ScmatLimag_IO;





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
