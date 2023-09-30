// basic vector
#pragma once
#include "../global.h"
#include "../arith/Imag.h"
#include "../str/str.h"
#include "Svec.h"

namespace slisc {
class VecChar
{
protected:
	Char *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecChar(); // default constructor
	explicit VecChar(Long_I N);
	VecChar(const VecChar &rhs); // copy constructor
	VecChar(VecChar&&); // move constructor

	VecChar &operator=(const VecChar &); // copy asignment
	VecChar &operator=(VecChar &&); // move asignment

	// get properties
	Char* p(); // get pointer
	const Char* p() const;
	Long size() const;
	void resize(Long_I N);
	Char &operator[](Long_I i);
	const Char &operator[](Long_I i) const;
	Char& end();
	const Char& end() const;
	Char& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Char& end(Long_I i) const;
	operator const SvecCharC&() const; // convert to SvecChar
	operator const SvecChar&();

	~VecChar();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecChar::VecChar() : m_p(nullptr), m_N(0) {}

inline VecChar::VecChar(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Char[N];
	else
		m_p = nullptr;
}

inline VecChar::VecChar(const VecChar &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Char[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Char));
	}
	else
		m_p = nullptr;
}

inline VecChar::VecChar(VecChar &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecChar &VecChar::operator=(const VecChar &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Char)*size());
	return *this;
}

inline VecChar &VecChar::operator=(VecChar &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Char * VecChar::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Char * VecChar::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecChar::size() const
{
	return m_N;
}

inline void VecChar::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Char[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Char[N];
			}
		}
	}
}

inline Char &VecChar::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecChar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Char &VecChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecChar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Char &VecChar::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Char &VecChar::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Char &VecChar::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Char &VecChar::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecChar::operator const SvecCharC&() const {
	return reinterpret_cast<const SvecCharC&>(*this);
}

inline VecChar::operator const SvecChar&() {
	return reinterpret_cast<const SvecChar&>(*this);
}

inline VecChar::~VecChar()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecChar &v) { return v.size(); }

inline const Char *ptr(const VecChar &v) { return v.p(); }

inline Char *ptr(VecChar &v) { return v.p(); }


typedef const VecChar &VecChar_I;
typedef VecChar &VecChar_O, &VecChar_IO;


class VecUchar
{
protected:
	Uchar *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecUchar(); // default constructor
	explicit VecUchar(Long_I N);
	VecUchar(const VecUchar &rhs); // copy constructor
	VecUchar(VecUchar&&); // move constructor

	VecUchar &operator=(const VecUchar &); // copy asignment
	VecUchar &operator=(VecUchar &&); // move asignment

	// get properties
	Uchar* p(); // get pointer
	const Uchar* p() const;
	Long size() const;
	void resize(Long_I N);
	Uchar &operator[](Long_I i);
	const Uchar &operator[](Long_I i) const;
	Uchar& end();
	const Uchar& end() const;
	Uchar& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Uchar& end(Long_I i) const;
	operator const SvecUcharC&() const; // convert to SvecUchar
	operator const SvecUchar&();

	~VecUchar();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecUchar::VecUchar() : m_p(nullptr), m_N(0) {}

inline VecUchar::VecUchar(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Uchar[N];
	else
		m_p = nullptr;
}

inline VecUchar::VecUchar(const VecUchar &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Uchar[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Uchar));
	}
	else
		m_p = nullptr;
}

inline VecUchar::VecUchar(VecUchar &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecUchar &VecUchar::operator=(const VecUchar &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Uchar)*size());
	return *this;
}

inline VecUchar &VecUchar::operator=(VecUchar &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Uchar * VecUchar::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Uchar * VecUchar::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecUchar::size() const
{
	return m_N;
}

inline void VecUchar::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Uchar[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Uchar[N];
			}
		}
	}
}

inline Uchar &VecUchar::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecUchar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Uchar &VecUchar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecUchar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Uchar &VecUchar::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Uchar &VecUchar::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Uchar &VecUchar::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Uchar &VecUchar::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecUchar::operator const SvecUcharC&() const {
	return reinterpret_cast<const SvecUcharC&>(*this);
}

inline VecUchar::operator const SvecUchar&() {
	return reinterpret_cast<const SvecUchar&>(*this);
}

inline VecUchar::~VecUchar()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecUchar &v) { return v.size(); }

inline const Uchar *ptr(const VecUchar &v) { return v.p(); }

inline Uchar *ptr(VecUchar &v) { return v.p(); }


typedef const VecUchar &VecUchar_I;
typedef VecUchar &VecUchar_O, &VecUchar_IO;


class VecInt
{
protected:
	Int *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecInt(); // default constructor
	explicit VecInt(Long_I N);
	VecInt(const VecInt &rhs); // copy constructor
	VecInt(VecInt&&); // move constructor

	VecInt &operator=(const VecInt &); // copy asignment
	VecInt &operator=(VecInt &&); // move asignment

	// get properties
	Int* p(); // get pointer
	const Int* p() const;
	Long size() const;
	void resize(Long_I N);
	Int &operator[](Long_I i);
	const Int &operator[](Long_I i) const;
	Int& end();
	const Int& end() const;
	Int& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Int& end(Long_I i) const;
	operator const SvecIntC&() const; // convert to SvecInt
	operator const SvecInt&();

	~VecInt();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecInt::VecInt() : m_p(nullptr), m_N(0) {}

inline VecInt::VecInt(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Int[N];
	else
		m_p = nullptr;
}

inline VecInt::VecInt(const VecInt &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Int[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Int));
	}
	else
		m_p = nullptr;
}

inline VecInt::VecInt(VecInt &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecInt &VecInt::operator=(const VecInt &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Int)*size());
	return *this;
}

inline VecInt &VecInt::operator=(VecInt &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Int * VecInt::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Int * VecInt::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecInt::size() const
{
	return m_N;
}

inline void VecInt::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Int[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Int[N];
			}
		}
	}
}

inline Int &VecInt::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecInt index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Int &VecInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecInt index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Int &VecInt::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Int &VecInt::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Int &VecInt::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Int &VecInt::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecInt::operator const SvecIntC&() const {
	return reinterpret_cast<const SvecIntC&>(*this);
}

inline VecInt::operator const SvecInt&() {
	return reinterpret_cast<const SvecInt&>(*this);
}

inline VecInt::~VecInt()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecInt &v) { return v.size(); }

inline const Int *ptr(const VecInt &v) { return v.p(); }

inline Int *ptr(VecInt &v) { return v.p(); }


typedef const VecInt &VecInt_I;
typedef VecInt &VecInt_O, &VecInt_IO;


class VecLlong
{
protected:
	Llong *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecLlong(); // default constructor
	explicit VecLlong(Long_I N);
	VecLlong(const VecLlong &rhs); // copy constructor
	VecLlong(VecLlong&&); // move constructor

	VecLlong &operator=(const VecLlong &); // copy asignment
	VecLlong &operator=(VecLlong &&); // move asignment

	// get properties
	Llong* p(); // get pointer
	const Llong* p() const;
	Long size() const;
	void resize(Long_I N);
	Llong &operator[](Long_I i);
	const Llong &operator[](Long_I i) const;
	Llong& end();
	const Llong& end() const;
	Llong& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Llong& end(Long_I i) const;
	operator const SvecLlongC&() const; // convert to SvecLlong
	operator const SvecLlong&();

	~VecLlong();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecLlong::VecLlong() : m_p(nullptr), m_N(0) {}

inline VecLlong::VecLlong(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Llong[N];
	else
		m_p = nullptr;
}

inline VecLlong::VecLlong(const VecLlong &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Llong[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Llong));
	}
	else
		m_p = nullptr;
}

inline VecLlong::VecLlong(VecLlong &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecLlong &VecLlong::operator=(const VecLlong &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Llong)*size());
	return *this;
}

inline VecLlong &VecLlong::operator=(VecLlong &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Llong * VecLlong::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Llong * VecLlong::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecLlong::size() const
{
	return m_N;
}

inline void VecLlong::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Llong[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Llong[N];
			}
		}
	}
}

inline Llong &VecLlong::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecLlong index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Llong &VecLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecLlong index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Llong &VecLlong::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Llong &VecLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Llong &VecLlong::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Llong &VecLlong::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecLlong::operator const SvecLlongC&() const {
	return reinterpret_cast<const SvecLlongC&>(*this);
}

inline VecLlong::operator const SvecLlong&() {
	return reinterpret_cast<const SvecLlong&>(*this);
}

inline VecLlong::~VecLlong()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecLlong &v) { return v.size(); }

inline const Llong *ptr(const VecLlong &v) { return v.p(); }

inline Llong *ptr(VecLlong &v) { return v.p(); }


typedef const VecLlong &VecLlong_I;
typedef VecLlong &VecLlong_O, &VecLlong_IO;


class VecFloat
{
protected:
	Float *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecFloat(); // default constructor
	explicit VecFloat(Long_I N);
	VecFloat(const VecFloat &rhs); // copy constructor
	VecFloat(VecFloat&&); // move constructor

	VecFloat &operator=(const VecFloat &); // copy asignment
	VecFloat &operator=(VecFloat &&); // move asignment

	// get properties
	Float* p(); // get pointer
	const Float* p() const;
	Long size() const;
	void resize(Long_I N);
	Float &operator[](Long_I i);
	const Float &operator[](Long_I i) const;
	Float& end();
	const Float& end() const;
	Float& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Float& end(Long_I i) const;
	operator const SvecFloatC&() const; // convert to SvecFloat
	operator const SvecFloat&();

	~VecFloat();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecFloat::VecFloat() : m_p(nullptr), m_N(0) {}

inline VecFloat::VecFloat(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Float[N];
	else
		m_p = nullptr;
}

inline VecFloat::VecFloat(const VecFloat &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Float[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Float));
	}
	else
		m_p = nullptr;
}

inline VecFloat::VecFloat(VecFloat &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecFloat &VecFloat::operator=(const VecFloat &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Float)*size());
	return *this;
}

inline VecFloat &VecFloat::operator=(VecFloat &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Float * VecFloat::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Float * VecFloat::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecFloat::size() const
{
	return m_N;
}

inline void VecFloat::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Float[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Float[N];
			}
		}
	}
}

inline Float &VecFloat::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecFloat index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Float &VecFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecFloat index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Float &VecFloat::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Float &VecFloat::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Float &VecFloat::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Float &VecFloat::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecFloat::operator const SvecFloatC&() const {
	return reinterpret_cast<const SvecFloatC&>(*this);
}

inline VecFloat::operator const SvecFloat&() {
	return reinterpret_cast<const SvecFloat&>(*this);
}

inline VecFloat::~VecFloat()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecFloat &v) { return v.size(); }

inline const Float *ptr(const VecFloat &v) { return v.p(); }

inline Float *ptr(VecFloat &v) { return v.p(); }


typedef const VecFloat &VecFloat_I;
typedef VecFloat &VecFloat_O, &VecFloat_IO;


class VecDoub
{
protected:
	Doub *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecDoub(); // default constructor
	explicit VecDoub(Long_I N);
	VecDoub(const VecDoub &rhs); // copy constructor
	VecDoub(VecDoub&&); // move constructor

	VecDoub &operator=(const VecDoub &); // copy asignment
	VecDoub &operator=(VecDoub &&); // move asignment

	// get properties
	Doub* p(); // get pointer
	const Doub* p() const;
	Long size() const;
	void resize(Long_I N);
	Doub &operator[](Long_I i);
	const Doub &operator[](Long_I i) const;
	Doub& end();
	const Doub& end() const;
	Doub& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Doub& end(Long_I i) const;
	operator const SvecDoubC&() const; // convert to SvecDoub
	operator const SvecDoub&();

	~VecDoub();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecDoub::VecDoub() : m_p(nullptr), m_N(0) {}

inline VecDoub::VecDoub(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Doub[N];
	else
		m_p = nullptr;
}

inline VecDoub::VecDoub(const VecDoub &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Doub[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Doub));
	}
	else
		m_p = nullptr;
}

inline VecDoub::VecDoub(VecDoub &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecDoub &VecDoub::operator=(const VecDoub &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Doub)*size());
	return *this;
}

inline VecDoub &VecDoub::operator=(VecDoub &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Doub * VecDoub::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Doub * VecDoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecDoub::size() const
{
	return m_N;
}

inline void VecDoub::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Doub[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Doub[N];
			}
		}
	}
}

inline Doub &VecDoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecDoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Doub &VecDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecDoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Doub &VecDoub::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Doub &VecDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Doub &VecDoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Doub &VecDoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecDoub::operator const SvecDoubC&() const {
	return reinterpret_cast<const SvecDoubC&>(*this);
}

inline VecDoub::operator const SvecDoub&() {
	return reinterpret_cast<const SvecDoub&>(*this);
}

inline VecDoub::~VecDoub()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecDoub &v) { return v.size(); }

inline const Doub *ptr(const VecDoub &v) { return v.p(); }

inline Doub *ptr(VecDoub &v) { return v.p(); }


typedef const VecDoub &VecDoub_I;
typedef VecDoub &VecDoub_O, &VecDoub_IO;


class VecLdoub
{
protected:
	Ldoub *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecLdoub(); // default constructor
	explicit VecLdoub(Long_I N);
	VecLdoub(const VecLdoub &rhs); // copy constructor
	VecLdoub(VecLdoub&&); // move constructor

	VecLdoub &operator=(const VecLdoub &); // copy asignment
	VecLdoub &operator=(VecLdoub &&); // move asignment

	// get properties
	Ldoub* p(); // get pointer
	const Ldoub* p() const;
	Long size() const;
	void resize(Long_I N);
	Ldoub &operator[](Long_I i);
	const Ldoub &operator[](Long_I i) const;
	Ldoub& end();
	const Ldoub& end() const;
	Ldoub& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Ldoub& end(Long_I i) const;
	operator const SvecLdoubC&() const; // convert to SvecLdoub
	operator const SvecLdoub&();

	~VecLdoub();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecLdoub::VecLdoub() : m_p(nullptr), m_N(0) {}

inline VecLdoub::VecLdoub(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Ldoub[N];
	else
		m_p = nullptr;
}

inline VecLdoub::VecLdoub(const VecLdoub &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Ldoub[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Ldoub));
	}
	else
		m_p = nullptr;
}

inline VecLdoub::VecLdoub(VecLdoub &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecLdoub &VecLdoub::operator=(const VecLdoub &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Ldoub)*size());
	return *this;
}

inline VecLdoub &VecLdoub::operator=(VecLdoub &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Ldoub * VecLdoub::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Ldoub * VecLdoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecLdoub::size() const
{
	return m_N;
}

inline void VecLdoub::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Ldoub[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Ldoub[N];
			}
		}
	}
}

inline Ldoub &VecLdoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecLdoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Ldoub &VecLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecLdoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Ldoub &VecLdoub::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Ldoub &VecLdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Ldoub &VecLdoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Ldoub &VecLdoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecLdoub::operator const SvecLdoubC&() const {
	return reinterpret_cast<const SvecLdoubC&>(*this);
}

inline VecLdoub::operator const SvecLdoub&() {
	return reinterpret_cast<const SvecLdoub&>(*this);
}

inline VecLdoub::~VecLdoub()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecLdoub &v) { return v.size(); }

inline const Ldoub *ptr(const VecLdoub &v) { return v.p(); }

inline Ldoub *ptr(VecLdoub &v) { return v.p(); }


typedef const VecLdoub &VecLdoub_I;
typedef VecLdoub &VecLdoub_O, &VecLdoub_IO;


class VecQdoub
{
protected:
	Qdoub *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecQdoub(); // default constructor
	explicit VecQdoub(Long_I N);
	VecQdoub(const VecQdoub &rhs); // copy constructor
	VecQdoub(VecQdoub&&); // move constructor

	VecQdoub &operator=(const VecQdoub &); // copy asignment
	VecQdoub &operator=(VecQdoub &&); // move asignment

	// get properties
	Qdoub* p(); // get pointer
	const Qdoub* p() const;
	Long size() const;
	void resize(Long_I N);
	Qdoub &operator[](Long_I i);
	const Qdoub &operator[](Long_I i) const;
	Qdoub& end();
	const Qdoub& end() const;
	Qdoub& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Qdoub& end(Long_I i) const;
	operator const SvecQdoubC&() const; // convert to SvecQdoub
	operator const SvecQdoub&();

	~VecQdoub();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecQdoub::VecQdoub() : m_p(nullptr), m_N(0) {}

inline VecQdoub::VecQdoub(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Qdoub[N];
	else
		m_p = nullptr;
}

inline VecQdoub::VecQdoub(const VecQdoub &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Qdoub[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Qdoub));
	}
	else
		m_p = nullptr;
}

inline VecQdoub::VecQdoub(VecQdoub &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecQdoub &VecQdoub::operator=(const VecQdoub &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Qdoub)*size());
	return *this;
}

inline VecQdoub &VecQdoub::operator=(VecQdoub &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Qdoub * VecQdoub::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Qdoub * VecQdoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecQdoub::size() const
{
	return m_N;
}

inline void VecQdoub::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Qdoub[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Qdoub[N];
			}
		}
	}
}

inline Qdoub &VecQdoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecQdoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Qdoub &VecQdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecQdoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Qdoub &VecQdoub::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Qdoub &VecQdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Qdoub &VecQdoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Qdoub &VecQdoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecQdoub::operator const SvecQdoubC&() const {
	return reinterpret_cast<const SvecQdoubC&>(*this);
}

inline VecQdoub::operator const SvecQdoub&() {
	return reinterpret_cast<const SvecQdoub&>(*this);
}

inline VecQdoub::~VecQdoub()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecQdoub &v) { return v.size(); }

inline const Qdoub *ptr(const VecQdoub &v) { return v.p(); }

inline Qdoub *ptr(VecQdoub &v) { return v.p(); }


typedef const VecQdoub &VecQdoub_I;
typedef VecQdoub &VecQdoub_O, &VecQdoub_IO;


class VecFcomp
{
protected:
	Fcomp *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecFcomp(); // default constructor
	explicit VecFcomp(Long_I N);
	VecFcomp(const VecFcomp &rhs); // copy constructor
	VecFcomp(VecFcomp&&); // move constructor

	VecFcomp &operator=(const VecFcomp &); // copy asignment
	VecFcomp &operator=(VecFcomp &&); // move asignment

	// get properties
	Fcomp* p(); // get pointer
	const Fcomp* p() const;
	Long size() const;
	void resize(Long_I N);
	Fcomp &operator[](Long_I i);
	const Fcomp &operator[](Long_I i) const;
	Fcomp& end();
	const Fcomp& end() const;
	Fcomp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Fcomp& end(Long_I i) const;
	operator const SvecFcompC&() const; // convert to SvecFcomp
	operator const SvecFcomp&();

	~VecFcomp();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecFcomp::VecFcomp() : m_p(nullptr), m_N(0) {}

inline VecFcomp::VecFcomp(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Fcomp[N];
	else
		m_p = nullptr;
}

inline VecFcomp::VecFcomp(const VecFcomp &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Fcomp[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Fcomp));
	}
	else
		m_p = nullptr;
}

inline VecFcomp::VecFcomp(VecFcomp &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecFcomp &VecFcomp::operator=(const VecFcomp &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Fcomp)*size());
	return *this;
}

inline VecFcomp &VecFcomp::operator=(VecFcomp &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Fcomp * VecFcomp::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Fcomp * VecFcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecFcomp::size() const
{
	return m_N;
}

inline void VecFcomp::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Fcomp[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Fcomp[N];
			}
		}
	}
}

inline Fcomp &VecFcomp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecFcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Fcomp &VecFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecFcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Fcomp &VecFcomp::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Fcomp &VecFcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Fcomp &VecFcomp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Fcomp &VecFcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecFcomp::operator const SvecFcompC&() const {
	return reinterpret_cast<const SvecFcompC&>(*this);
}

inline VecFcomp::operator const SvecFcomp&() {
	return reinterpret_cast<const SvecFcomp&>(*this);
}

inline VecFcomp::~VecFcomp()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecFcomp &v) { return v.size(); }

inline const Fcomp *ptr(const VecFcomp &v) { return v.p(); }

inline Fcomp *ptr(VecFcomp &v) { return v.p(); }


typedef const VecFcomp &VecFcomp_I;
typedef VecFcomp &VecFcomp_O, &VecFcomp_IO;


class VecComp
{
protected:
	Comp *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecComp(); // default constructor
	explicit VecComp(Long_I N);
	VecComp(const VecComp &rhs); // copy constructor
	VecComp(VecComp&&); // move constructor

	VecComp &operator=(const VecComp &); // copy asignment
	VecComp &operator=(VecComp &&); // move asignment

	// get properties
	Comp* p(); // get pointer
	const Comp* p() const;
	Long size() const;
	void resize(Long_I N);
	Comp &operator[](Long_I i);
	const Comp &operator[](Long_I i) const;
	Comp& end();
	const Comp& end() const;
	Comp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Comp& end(Long_I i) const;
	operator const SvecCompC&() const; // convert to SvecComp
	operator const SvecComp&();

	~VecComp();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecComp::VecComp() : m_p(nullptr), m_N(0) {}

inline VecComp::VecComp(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Comp[N];
	else
		m_p = nullptr;
}

inline VecComp::VecComp(const VecComp &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Comp[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Comp));
	}
	else
		m_p = nullptr;
}

inline VecComp::VecComp(VecComp &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecComp &VecComp::operator=(const VecComp &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Comp)*size());
	return *this;
}

inline VecComp &VecComp::operator=(VecComp &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Comp * VecComp::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Comp * VecComp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecComp::size() const
{
	return m_N;
}

inline void VecComp::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Comp[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Comp[N];
			}
		}
	}
}

inline Comp &VecComp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecComp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Comp &VecComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecComp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Comp &VecComp::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Comp &VecComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Comp &VecComp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Comp &VecComp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecComp::operator const SvecCompC&() const {
	return reinterpret_cast<const SvecCompC&>(*this);
}

inline VecComp::operator const SvecComp&() {
	return reinterpret_cast<const SvecComp&>(*this);
}

inline VecComp::~VecComp()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecComp &v) { return v.size(); }

inline const Comp *ptr(const VecComp &v) { return v.p(); }

inline Comp *ptr(VecComp &v) { return v.p(); }


typedef const VecComp &VecComp_I;
typedef VecComp &VecComp_O, &VecComp_IO;


class VecLcomp
{
protected:
	Lcomp *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecLcomp(); // default constructor
	explicit VecLcomp(Long_I N);
	VecLcomp(const VecLcomp &rhs); // copy constructor
	VecLcomp(VecLcomp&&); // move constructor

	VecLcomp &operator=(const VecLcomp &); // copy asignment
	VecLcomp &operator=(VecLcomp &&); // move asignment

	// get properties
	Lcomp* p(); // get pointer
	const Lcomp* p() const;
	Long size() const;
	void resize(Long_I N);
	Lcomp &operator[](Long_I i);
	const Lcomp &operator[](Long_I i) const;
	Lcomp& end();
	const Lcomp& end() const;
	Lcomp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Lcomp& end(Long_I i) const;
	operator const SvecLcompC&() const; // convert to SvecLcomp
	operator const SvecLcomp&();

	~VecLcomp();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecLcomp::VecLcomp() : m_p(nullptr), m_N(0) {}

inline VecLcomp::VecLcomp(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Lcomp[N];
	else
		m_p = nullptr;
}

inline VecLcomp::VecLcomp(const VecLcomp &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Lcomp[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Lcomp));
	}
	else
		m_p = nullptr;
}

inline VecLcomp::VecLcomp(VecLcomp &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecLcomp &VecLcomp::operator=(const VecLcomp &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Lcomp)*size());
	return *this;
}

inline VecLcomp &VecLcomp::operator=(VecLcomp &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Lcomp * VecLcomp::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Lcomp * VecLcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecLcomp::size() const
{
	return m_N;
}

inline void VecLcomp::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Lcomp[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Lcomp[N];
			}
		}
	}
}

inline Lcomp &VecLcomp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecLcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Lcomp &VecLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecLcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Lcomp &VecLcomp::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Lcomp &VecLcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Lcomp &VecLcomp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Lcomp &VecLcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecLcomp::operator const SvecLcompC&() const {
	return reinterpret_cast<const SvecLcompC&>(*this);
}

inline VecLcomp::operator const SvecLcomp&() {
	return reinterpret_cast<const SvecLcomp&>(*this);
}

inline VecLcomp::~VecLcomp()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecLcomp &v) { return v.size(); }

inline const Lcomp *ptr(const VecLcomp &v) { return v.p(); }

inline Lcomp *ptr(VecLcomp &v) { return v.p(); }


typedef const VecLcomp &VecLcomp_I;
typedef VecLcomp &VecLcomp_O, &VecLcomp_IO;


class VecQcomp
{
protected:
	Qcomp *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecQcomp(); // default constructor
	explicit VecQcomp(Long_I N);
	VecQcomp(const VecQcomp &rhs); // copy constructor
	VecQcomp(VecQcomp&&); // move constructor

	VecQcomp &operator=(const VecQcomp &); // copy asignment
	VecQcomp &operator=(VecQcomp &&); // move asignment

	// get properties
	Qcomp* p(); // get pointer
	const Qcomp* p() const;
	Long size() const;
	void resize(Long_I N);
	Qcomp &operator[](Long_I i);
	const Qcomp &operator[](Long_I i) const;
	Qcomp& end();
	const Qcomp& end() const;
	Qcomp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Qcomp& end(Long_I i) const;
	operator const SvecQcompC&() const; // convert to SvecQcomp
	operator const SvecQcomp&();

	~VecQcomp();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecQcomp::VecQcomp() : m_p(nullptr), m_N(0) {}

inline VecQcomp::VecQcomp(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Qcomp[N];
	else
		m_p = nullptr;
}

inline VecQcomp::VecQcomp(const VecQcomp &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Qcomp[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Qcomp));
	}
	else
		m_p = nullptr;
}

inline VecQcomp::VecQcomp(VecQcomp &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecQcomp &VecQcomp::operator=(const VecQcomp &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Qcomp)*size());
	return *this;
}

inline VecQcomp &VecQcomp::operator=(VecQcomp &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Qcomp * VecQcomp::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Qcomp * VecQcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecQcomp::size() const
{
	return m_N;
}

inline void VecQcomp::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Qcomp[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Qcomp[N];
			}
		}
	}
}

inline Qcomp &VecQcomp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecQcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Qcomp &VecQcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecQcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Qcomp &VecQcomp::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Qcomp &VecQcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Qcomp &VecQcomp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Qcomp &VecQcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecQcomp::operator const SvecQcompC&() const {
	return reinterpret_cast<const SvecQcompC&>(*this);
}

inline VecQcomp::operator const SvecQcomp&() {
	return reinterpret_cast<const SvecQcomp&>(*this);
}

inline VecQcomp::~VecQcomp()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecQcomp &v) { return v.size(); }

inline const Qcomp *ptr(const VecQcomp &v) { return v.p(); }

inline Qcomp *ptr(VecQcomp &v) { return v.p(); }


typedef const VecQcomp &VecQcomp_I;
typedef VecQcomp &VecQcomp_O, &VecQcomp_IO;


class VecFimag
{
protected:
	Fimag *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecFimag(); // default constructor
	explicit VecFimag(Long_I N);
	VecFimag(const VecFimag &rhs); // copy constructor
	VecFimag(VecFimag&&); // move constructor

	VecFimag &operator=(const VecFimag &); // copy asignment
	VecFimag &operator=(VecFimag &&); // move asignment

	// get properties
	Fimag* p(); // get pointer
	const Fimag* p() const;
	Long size() const;
	void resize(Long_I N);
	Fimag &operator[](Long_I i);
	const Fimag &operator[](Long_I i) const;
	Fimag& end();
	const Fimag& end() const;
	Fimag& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Fimag& end(Long_I i) const;
	operator const SvecFimagC&() const; // convert to SvecFimag
	operator const SvecFimag&();

	~VecFimag();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecFimag::VecFimag() : m_p(nullptr), m_N(0) {}

inline VecFimag::VecFimag(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Fimag[N];
	else
		m_p = nullptr;
}

inline VecFimag::VecFimag(const VecFimag &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Fimag[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Fimag));
	}
	else
		m_p = nullptr;
}

inline VecFimag::VecFimag(VecFimag &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecFimag &VecFimag::operator=(const VecFimag &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Fimag)*size());
	return *this;
}

inline VecFimag &VecFimag::operator=(VecFimag &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Fimag * VecFimag::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Fimag * VecFimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecFimag::size() const
{
	return m_N;
}

inline void VecFimag::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Fimag[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Fimag[N];
			}
		}
	}
}

inline Fimag &VecFimag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecFimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Fimag &VecFimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecFimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Fimag &VecFimag::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Fimag &VecFimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Fimag &VecFimag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Fimag &VecFimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecFimag::operator const SvecFimagC&() const {
	return reinterpret_cast<const SvecFimagC&>(*this);
}

inline VecFimag::operator const SvecFimag&() {
	return reinterpret_cast<const SvecFimag&>(*this);
}

inline VecFimag::~VecFimag()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecFimag &v) { return v.size(); }

inline const Fimag *ptr(const VecFimag &v) { return v.p(); }

inline Fimag *ptr(VecFimag &v) { return v.p(); }


typedef const VecFimag &VecFimag_I;
typedef VecFimag &VecFimag_O, &VecFimag_IO;


class VecImag
{
protected:
	Imag *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecImag(); // default constructor
	explicit VecImag(Long_I N);
	VecImag(const VecImag &rhs); // copy constructor
	VecImag(VecImag&&); // move constructor

	VecImag &operator=(const VecImag &); // copy asignment
	VecImag &operator=(VecImag &&); // move asignment

	// get properties
	Imag* p(); // get pointer
	const Imag* p() const;
	Long size() const;
	void resize(Long_I N);
	Imag &operator[](Long_I i);
	const Imag &operator[](Long_I i) const;
	Imag& end();
	const Imag& end() const;
	Imag& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Imag& end(Long_I i) const;
	operator const SvecImagC&() const; // convert to SvecImag
	operator const SvecImag&();

	~VecImag();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecImag::VecImag() : m_p(nullptr), m_N(0) {}

inline VecImag::VecImag(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Imag[N];
	else
		m_p = nullptr;
}

inline VecImag::VecImag(const VecImag &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Imag[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Imag));
	}
	else
		m_p = nullptr;
}

inline VecImag::VecImag(VecImag &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecImag &VecImag::operator=(const VecImag &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Imag)*size());
	return *this;
}

inline VecImag &VecImag::operator=(VecImag &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Imag * VecImag::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Imag * VecImag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecImag::size() const
{
	return m_N;
}

inline void VecImag::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Imag[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Imag[N];
			}
		}
	}
}

inline Imag &VecImag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecImag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Imag &VecImag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecImag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Imag &VecImag::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Imag &VecImag::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Imag &VecImag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Imag &VecImag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecImag::operator const SvecImagC&() const {
	return reinterpret_cast<const SvecImagC&>(*this);
}

inline VecImag::operator const SvecImag&() {
	return reinterpret_cast<const SvecImag&>(*this);
}

inline VecImag::~VecImag()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecImag &v) { return v.size(); }

inline const Imag *ptr(const VecImag &v) { return v.p(); }

inline Imag *ptr(VecImag &v) { return v.p(); }


typedef const VecImag &VecImag_I;
typedef VecImag &VecImag_O, &VecImag_IO;


class VecLimag
{
protected:
	Limag *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecLimag(); // default constructor
	explicit VecLimag(Long_I N);
	VecLimag(const VecLimag &rhs); // copy constructor
	VecLimag(VecLimag&&); // move constructor

	VecLimag &operator=(const VecLimag &); // copy asignment
	VecLimag &operator=(VecLimag &&); // move asignment

	// get properties
	Limag* p(); // get pointer
	const Limag* p() const;
	Long size() const;
	void resize(Long_I N);
	Limag &operator[](Long_I i);
	const Limag &operator[](Long_I i) const;
	Limag& end();
	const Limag& end() const;
	Limag& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Limag& end(Long_I i) const;
	operator const SvecLimagC&() const; // convert to SvecLimag
	operator const SvecLimag&();

	~VecLimag();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecLimag::VecLimag() : m_p(nullptr), m_N(0) {}

inline VecLimag::VecLimag(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Limag[N];
	else
		m_p = nullptr;
}

inline VecLimag::VecLimag(const VecLimag &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Limag[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Limag));
	}
	else
		m_p = nullptr;
}

inline VecLimag::VecLimag(VecLimag &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecLimag &VecLimag::operator=(const VecLimag &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Limag)*size());
	return *this;
}

inline VecLimag &VecLimag::operator=(VecLimag &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Limag * VecLimag::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Limag * VecLimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecLimag::size() const
{
	return m_N;
}

inline void VecLimag::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Limag[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Limag[N];
			}
		}
	}
}

inline Limag &VecLimag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecLimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Limag &VecLimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecLimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Limag &VecLimag::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Limag &VecLimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Limag &VecLimag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Limag &VecLimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecLimag::operator const SvecLimagC&() const {
	return reinterpret_cast<const SvecLimagC&>(*this);
}

inline VecLimag::operator const SvecLimag&() {
	return reinterpret_cast<const SvecLimag&>(*this);
}

inline VecLimag::~VecLimag()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecLimag &v) { return v.size(); }

inline const Limag *ptr(const VecLimag &v) { return v.p(); }

inline Limag *ptr(VecLimag &v) { return v.p(); }


typedef const VecLimag &VecLimag_I;
typedef VecLimag &VecLimag_O, &VecLimag_IO;


class VecQimag
{
protected:
	Qimag *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VecQimag(); // default constructor
	explicit VecQimag(Long_I N);
	VecQimag(const VecQimag &rhs); // copy constructor
	VecQimag(VecQimag&&); // move constructor

	VecQimag &operator=(const VecQimag &); // copy asignment
	VecQimag &operator=(VecQimag &&); // move asignment

	// get properties
	Qimag* p(); // get pointer
	const Qimag* p() const;
	Long size() const;
	void resize(Long_I N);
	Qimag &operator[](Long_I i);
	const Qimag &operator[](Long_I i) const;
	Qimag& end();
	const Qimag& end() const;
	Qimag& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	const Qimag& end(Long_I i) const;
	operator const SvecQimagC&() const; // convert to SvecQimag
	operator const SvecQimag&();

	~VecQimag();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VecQimag::VecQimag() : m_p(nullptr), m_N(0) {}

inline VecQimag::VecQimag(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
	m_N = N;
	if (N > 0)
		m_p = new Qimag[N];
	else
		m_p = nullptr;
}

inline VecQimag::VecQimag(const VecQimag &rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
	m_N = rhs.m_N;
	if (m_N > 0) {
		m_p = new Qimag[m_N];
		memcpy(m_p, rhs.p(), m_N*sizeof(Qimag));
	}
	else
		m_p = nullptr;
}

inline VecQimag::VecQimag(VecQimag &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs)
		SLS_ERR("self move is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
}

inline VecQimag &VecQimag::operator=(const VecQimag &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Qimag)*size());
	return *this;
}

inline VecQimag &VecQimag::operator=(VecQimag &&rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self move assignment is forbidden!");
#endif
	if (m_N != 0)
		delete[] m_p;
	m_N = rhs.m_N; rhs.m_N = 0;
	m_p = rhs.m_p;
	return *this;
}

inline Qimag * VecQimag::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Qimag * VecQimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VecQimag::size() const
{
	return m_N;
}

inline void VecQimag::resize(Long_I N)
{
	if (N != m_N) {
		if (m_N == 0) { // N != 0
			m_N = N; m_p = new Qimag[N];
		}
		else { // m_N != 0
			delete[] m_p;
			if (N == 0)
				m_N = 0;
			else {
				m_N = N;
				m_p = new Qimag[N];
			}
		}
	}
}

inline Qimag &VecQimag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VecQimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Qimag &VecQimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VecQimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Qimag &VecQimag::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Qimag &VecQimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Qimag &VecQimag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Qimag &VecQimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VecQimag::operator const SvecQimagC&() const {
	return reinterpret_cast<const SvecQimagC&>(*this);
}

inline VecQimag::operator const SvecQimag&() {
	return reinterpret_cast<const SvecQimag&>(*this);
}

inline VecQimag::~VecQimag()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VecQimag &v) { return v.size(); }

inline const Qimag *ptr(const VecQimag &v) { return v.p(); }

inline Qimag *ptr(VecQimag &v) { return v.p(); }


typedef const VecQimag &VecQimag_I;
typedef VecQimag &VecQimag_O, &VecQimag_IO;



#ifdef SLS_USE_INT_AS_LONG
typedef VecInt VecLong;
#else
typedef VecLlong VecLong;
#endif
typedef const VecLong &VecLong_I;
typedef VecLong &VecLong_O, &VecLong_IO;


class VecBool : vector<bool>
{
public:
	typedef vector<bool> Base;
	typedef Base::reference ref;
	// constructors
	VecBool() = default;
	explicit VecBool(Long_I N);
	VecBool(const VecBool &rhs); // copy constructor
	// move constructor is inherited
	using Base::operator=;

	// get properties
	Long size() const;
	using Base::resize;
	ref operator[](Long_I i);
	bool operator[](Long_I i) const;
	ref end();
	bool end() const;
	ref end(Long_I i); // i = 1 for the last, i = 2 for the second last...
	bool end(Long_I i) const;
};

inline VecBool::VecBool(Long_I N) : Base(N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
}

inline VecBool::VecBool(const VecBool &rhs): Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
}

inline Long VecBool::size() const { return Base::size(); }

inline VecBool::ref VecBool::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=size())
		SLS_ERR("VecBool index (" + num2str(i) + ") out of bounds: size = " + num2str(size()));
#endif
	return Base::operator[](i);
}

inline bool VecBool::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=size())
		SLS_ERR("VecBool index (" + num2str(i) + ") out of bounds: size = " + num2str(size()));
#endif
	return Base::operator[](i);
}

inline VecBool::ref VecBool::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (Base::empty())
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return Base::back();
}

inline bool VecBool::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (Base::empty())
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return Base::back();
}

inline VecBool::ref VecBool::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > size())
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(size()));
#endif
	return (*this)[size() - i];
}

inline bool VecBool::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > size())
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(size()));
#endif
	return (*this)[size() - i];
}

// common api for STL and SLISC
inline Long size(const VecBool &v) { return v.size(); }

typedef const VecBool &VecBool_I;
typedef VecBool &VecBool_O, &VecBool_IO;

} // namespace slisc
