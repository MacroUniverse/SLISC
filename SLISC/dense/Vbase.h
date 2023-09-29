// basic vector
#pragma once
#include "../global.h"
#include "../arith/Imag.h"
#include "../str/str.h"

namespace slisc {
class VbaseChar
{
protected:
	Char *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseChar(); // default constructor
	explicit VbaseChar(Long_I N);
	VbaseChar(const VbaseChar &rhs); // copy constructor
	VbaseChar(VbaseChar&&); // move constructor

	VbaseChar &operator=(const VbaseChar &); // copy asignment
	VbaseChar &operator=(VbaseChar &&); // move asignment

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
	~VbaseChar();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseChar::VbaseChar() : m_p(nullptr), m_N(0) {}

inline VbaseChar::VbaseChar(Long_I N)
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

inline VbaseChar::VbaseChar(const VbaseChar &rhs)
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

inline VbaseChar::VbaseChar(VbaseChar &&rhs)
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

inline VbaseChar &VbaseChar::operator=(const VbaseChar &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Char)*size());
	return *this;
}

inline VbaseChar &VbaseChar::operator=(VbaseChar &&rhs)
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

inline Char * VbaseChar::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Char * VbaseChar::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseChar::size() const
{
	return m_N;
}

inline void VbaseChar::resize(Long_I N)
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

inline Char &VbaseChar::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseChar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Char &VbaseChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseChar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Char &VbaseChar::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Char &VbaseChar::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Char &VbaseChar::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Char &VbaseChar::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseChar::~VbaseChar()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseChar &v) { return v.size(); }

inline const Char *ptr(const VbaseChar &v) { return v.p(); }

inline Char *ptr(VbaseChar &v) { return v.p(); }

class VbaseUchar
{
protected:
	Uchar *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseUchar(); // default constructor
	explicit VbaseUchar(Long_I N);
	VbaseUchar(const VbaseUchar &rhs); // copy constructor
	VbaseUchar(VbaseUchar&&); // move constructor

	VbaseUchar &operator=(const VbaseUchar &); // copy asignment
	VbaseUchar &operator=(VbaseUchar &&); // move asignment

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
	~VbaseUchar();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseUchar::VbaseUchar() : m_p(nullptr), m_N(0) {}

inline VbaseUchar::VbaseUchar(Long_I N)
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

inline VbaseUchar::VbaseUchar(const VbaseUchar &rhs)
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

inline VbaseUchar::VbaseUchar(VbaseUchar &&rhs)
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

inline VbaseUchar &VbaseUchar::operator=(const VbaseUchar &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Uchar)*size());
	return *this;
}

inline VbaseUchar &VbaseUchar::operator=(VbaseUchar &&rhs)
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

inline Uchar * VbaseUchar::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Uchar * VbaseUchar::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseUchar::size() const
{
	return m_N;
}

inline void VbaseUchar::resize(Long_I N)
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

inline Uchar &VbaseUchar::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseUchar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Uchar &VbaseUchar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseUchar index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Uchar &VbaseUchar::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Uchar &VbaseUchar::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Uchar &VbaseUchar::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Uchar &VbaseUchar::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseUchar::~VbaseUchar()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseUchar &v) { return v.size(); }

inline const Uchar *ptr(const VbaseUchar &v) { return v.p(); }

inline Uchar *ptr(VbaseUchar &v) { return v.p(); }

class VbaseInt
{
protected:
	Int *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseInt(); // default constructor
	explicit VbaseInt(Long_I N);
	VbaseInt(const VbaseInt &rhs); // copy constructor
	VbaseInt(VbaseInt&&); // move constructor

	VbaseInt &operator=(const VbaseInt &); // copy asignment
	VbaseInt &operator=(VbaseInt &&); // move asignment

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
	~VbaseInt();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseInt::VbaseInt() : m_p(nullptr), m_N(0) {}

inline VbaseInt::VbaseInt(Long_I N)
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

inline VbaseInt::VbaseInt(const VbaseInt &rhs)
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

inline VbaseInt::VbaseInt(VbaseInt &&rhs)
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

inline VbaseInt &VbaseInt::operator=(const VbaseInt &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Int)*size());
	return *this;
}

inline VbaseInt &VbaseInt::operator=(VbaseInt &&rhs)
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

inline Int * VbaseInt::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Int * VbaseInt::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseInt::size() const
{
	return m_N;
}

inline void VbaseInt::resize(Long_I N)
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

inline Int &VbaseInt::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseInt index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Int &VbaseInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseInt index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Int &VbaseInt::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Int &VbaseInt::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Int &VbaseInt::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Int &VbaseInt::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseInt::~VbaseInt()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseInt &v) { return v.size(); }

inline const Int *ptr(const VbaseInt &v) { return v.p(); }

inline Int *ptr(VbaseInt &v) { return v.p(); }

class VbaseLlong
{
protected:
	Llong *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseLlong(); // default constructor
	explicit VbaseLlong(Long_I N);
	VbaseLlong(const VbaseLlong &rhs); // copy constructor
	VbaseLlong(VbaseLlong&&); // move constructor

	VbaseLlong &operator=(const VbaseLlong &); // copy asignment
	VbaseLlong &operator=(VbaseLlong &&); // move asignment

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
	~VbaseLlong();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseLlong::VbaseLlong() : m_p(nullptr), m_N(0) {}

inline VbaseLlong::VbaseLlong(Long_I N)
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

inline VbaseLlong::VbaseLlong(const VbaseLlong &rhs)
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

inline VbaseLlong::VbaseLlong(VbaseLlong &&rhs)
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

inline VbaseLlong &VbaseLlong::operator=(const VbaseLlong &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Llong)*size());
	return *this;
}

inline VbaseLlong &VbaseLlong::operator=(VbaseLlong &&rhs)
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

inline Llong * VbaseLlong::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Llong * VbaseLlong::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseLlong::size() const
{
	return m_N;
}

inline void VbaseLlong::resize(Long_I N)
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

inline Llong &VbaseLlong::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseLlong index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Llong &VbaseLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseLlong index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Llong &VbaseLlong::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Llong &VbaseLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Llong &VbaseLlong::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Llong &VbaseLlong::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseLlong::~VbaseLlong()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseLlong &v) { return v.size(); }

inline const Llong *ptr(const VbaseLlong &v) { return v.p(); }

inline Llong *ptr(VbaseLlong &v) { return v.p(); }

class VbaseFloat
{
protected:
	Float *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseFloat(); // default constructor
	explicit VbaseFloat(Long_I N);
	VbaseFloat(const VbaseFloat &rhs); // copy constructor
	VbaseFloat(VbaseFloat&&); // move constructor

	VbaseFloat &operator=(const VbaseFloat &); // copy asignment
	VbaseFloat &operator=(VbaseFloat &&); // move asignment

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
	~VbaseFloat();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseFloat::VbaseFloat() : m_p(nullptr), m_N(0) {}

inline VbaseFloat::VbaseFloat(Long_I N)
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

inline VbaseFloat::VbaseFloat(const VbaseFloat &rhs)
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

inline VbaseFloat::VbaseFloat(VbaseFloat &&rhs)
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

inline VbaseFloat &VbaseFloat::operator=(const VbaseFloat &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Float)*size());
	return *this;
}

inline VbaseFloat &VbaseFloat::operator=(VbaseFloat &&rhs)
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

inline Float * VbaseFloat::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Float * VbaseFloat::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseFloat::size() const
{
	return m_N;
}

inline void VbaseFloat::resize(Long_I N)
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

inline Float &VbaseFloat::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseFloat index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Float &VbaseFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseFloat index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Float &VbaseFloat::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Float &VbaseFloat::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Float &VbaseFloat::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Float &VbaseFloat::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseFloat::~VbaseFloat()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseFloat &v) { return v.size(); }

inline const Float *ptr(const VbaseFloat &v) { return v.p(); }

inline Float *ptr(VbaseFloat &v) { return v.p(); }

class VbaseDoub
{
protected:
	Doub *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseDoub(); // default constructor
	explicit VbaseDoub(Long_I N);
	VbaseDoub(const VbaseDoub &rhs); // copy constructor
	VbaseDoub(VbaseDoub&&); // move constructor

	VbaseDoub &operator=(const VbaseDoub &); // copy asignment
	VbaseDoub &operator=(VbaseDoub &&); // move asignment

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
	~VbaseDoub();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseDoub::VbaseDoub() : m_p(nullptr), m_N(0) {}

inline VbaseDoub::VbaseDoub(Long_I N)
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

inline VbaseDoub::VbaseDoub(const VbaseDoub &rhs)
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

inline VbaseDoub::VbaseDoub(VbaseDoub &&rhs)
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

inline VbaseDoub &VbaseDoub::operator=(const VbaseDoub &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Doub)*size());
	return *this;
}

inline VbaseDoub &VbaseDoub::operator=(VbaseDoub &&rhs)
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

inline Doub * VbaseDoub::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Doub * VbaseDoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseDoub::size() const
{
	return m_N;
}

inline void VbaseDoub::resize(Long_I N)
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

inline Doub &VbaseDoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseDoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Doub &VbaseDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseDoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Doub &VbaseDoub::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Doub &VbaseDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Doub &VbaseDoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Doub &VbaseDoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseDoub::~VbaseDoub()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseDoub &v) { return v.size(); }

inline const Doub *ptr(const VbaseDoub &v) { return v.p(); }

inline Doub *ptr(VbaseDoub &v) { return v.p(); }

class VbaseLdoub
{
protected:
	Ldoub *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseLdoub(); // default constructor
	explicit VbaseLdoub(Long_I N);
	VbaseLdoub(const VbaseLdoub &rhs); // copy constructor
	VbaseLdoub(VbaseLdoub&&); // move constructor

	VbaseLdoub &operator=(const VbaseLdoub &); // copy asignment
	VbaseLdoub &operator=(VbaseLdoub &&); // move asignment

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
	~VbaseLdoub();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseLdoub::VbaseLdoub() : m_p(nullptr), m_N(0) {}

inline VbaseLdoub::VbaseLdoub(Long_I N)
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

inline VbaseLdoub::VbaseLdoub(const VbaseLdoub &rhs)
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

inline VbaseLdoub::VbaseLdoub(VbaseLdoub &&rhs)
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

inline VbaseLdoub &VbaseLdoub::operator=(const VbaseLdoub &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Ldoub)*size());
	return *this;
}

inline VbaseLdoub &VbaseLdoub::operator=(VbaseLdoub &&rhs)
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

inline Ldoub * VbaseLdoub::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Ldoub * VbaseLdoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseLdoub::size() const
{
	return m_N;
}

inline void VbaseLdoub::resize(Long_I N)
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

inline Ldoub &VbaseLdoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseLdoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Ldoub &VbaseLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseLdoub index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Ldoub &VbaseLdoub::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Ldoub &VbaseLdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Ldoub &VbaseLdoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Ldoub &VbaseLdoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseLdoub::~VbaseLdoub()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseLdoub &v) { return v.size(); }

inline const Ldoub *ptr(const VbaseLdoub &v) { return v.p(); }

inline Ldoub *ptr(VbaseLdoub &v) { return v.p(); }


class VbaseFcomp
{
protected:
	Fcomp *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseFcomp(); // default constructor
	explicit VbaseFcomp(Long_I N);
	VbaseFcomp(const VbaseFcomp &rhs); // copy constructor
	VbaseFcomp(VbaseFcomp&&); // move constructor

	VbaseFcomp &operator=(const VbaseFcomp &); // copy asignment
	VbaseFcomp &operator=(VbaseFcomp &&); // move asignment

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
	~VbaseFcomp();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseFcomp::VbaseFcomp() : m_p(nullptr), m_N(0) {}

inline VbaseFcomp::VbaseFcomp(Long_I N)
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

inline VbaseFcomp::VbaseFcomp(const VbaseFcomp &rhs)
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

inline VbaseFcomp::VbaseFcomp(VbaseFcomp &&rhs)
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

inline VbaseFcomp &VbaseFcomp::operator=(const VbaseFcomp &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Fcomp)*size());
	return *this;
}

inline VbaseFcomp &VbaseFcomp::operator=(VbaseFcomp &&rhs)
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

inline Fcomp * VbaseFcomp::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Fcomp * VbaseFcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseFcomp::size() const
{
	return m_N;
}

inline void VbaseFcomp::resize(Long_I N)
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

inline Fcomp &VbaseFcomp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseFcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Fcomp &VbaseFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseFcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Fcomp &VbaseFcomp::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Fcomp &VbaseFcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Fcomp &VbaseFcomp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Fcomp &VbaseFcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseFcomp::~VbaseFcomp()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseFcomp &v) { return v.size(); }

inline const Fcomp *ptr(const VbaseFcomp &v) { return v.p(); }

inline Fcomp *ptr(VbaseFcomp &v) { return v.p(); }

class VbaseComp
{
protected:
	Comp *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseComp(); // default constructor
	explicit VbaseComp(Long_I N);
	VbaseComp(const VbaseComp &rhs); // copy constructor
	VbaseComp(VbaseComp&&); // move constructor

	VbaseComp &operator=(const VbaseComp &); // copy asignment
	VbaseComp &operator=(VbaseComp &&); // move asignment

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
	~VbaseComp();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseComp::VbaseComp() : m_p(nullptr), m_N(0) {}

inline VbaseComp::VbaseComp(Long_I N)
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

inline VbaseComp::VbaseComp(const VbaseComp &rhs)
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

inline VbaseComp::VbaseComp(VbaseComp &&rhs)
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

inline VbaseComp &VbaseComp::operator=(const VbaseComp &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Comp)*size());
	return *this;
}

inline VbaseComp &VbaseComp::operator=(VbaseComp &&rhs)
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

inline Comp * VbaseComp::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Comp * VbaseComp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseComp::size() const
{
	return m_N;
}

inline void VbaseComp::resize(Long_I N)
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

inline Comp &VbaseComp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseComp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Comp &VbaseComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseComp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Comp &VbaseComp::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Comp &VbaseComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Comp &VbaseComp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Comp &VbaseComp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseComp::~VbaseComp()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseComp &v) { return v.size(); }

inline const Comp *ptr(const VbaseComp &v) { return v.p(); }

inline Comp *ptr(VbaseComp &v) { return v.p(); }

class VbaseLcomp
{
protected:
	Lcomp *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseLcomp(); // default constructor
	explicit VbaseLcomp(Long_I N);
	VbaseLcomp(const VbaseLcomp &rhs); // copy constructor
	VbaseLcomp(VbaseLcomp&&); // move constructor

	VbaseLcomp &operator=(const VbaseLcomp &); // copy asignment
	VbaseLcomp &operator=(VbaseLcomp &&); // move asignment

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
	~VbaseLcomp();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseLcomp::VbaseLcomp() : m_p(nullptr), m_N(0) {}

inline VbaseLcomp::VbaseLcomp(Long_I N)
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

inline VbaseLcomp::VbaseLcomp(const VbaseLcomp &rhs)
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

inline VbaseLcomp::VbaseLcomp(VbaseLcomp &&rhs)
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

inline VbaseLcomp &VbaseLcomp::operator=(const VbaseLcomp &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Lcomp)*size());
	return *this;
}

inline VbaseLcomp &VbaseLcomp::operator=(VbaseLcomp &&rhs)
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

inline Lcomp * VbaseLcomp::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Lcomp * VbaseLcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseLcomp::size() const
{
	return m_N;
}

inline void VbaseLcomp::resize(Long_I N)
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

inline Lcomp &VbaseLcomp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseLcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Lcomp &VbaseLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseLcomp index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Lcomp &VbaseLcomp::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Lcomp &VbaseLcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Lcomp &VbaseLcomp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Lcomp &VbaseLcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseLcomp::~VbaseLcomp()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseLcomp &v) { return v.size(); }

inline const Lcomp *ptr(const VbaseLcomp &v) { return v.p(); }

inline Lcomp *ptr(VbaseLcomp &v) { return v.p(); }


class VbaseFimag
{
protected:
	Fimag *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseFimag(); // default constructor
	explicit VbaseFimag(Long_I N);
	VbaseFimag(const VbaseFimag &rhs); // copy constructor
	VbaseFimag(VbaseFimag&&); // move constructor

	VbaseFimag &operator=(const VbaseFimag &); // copy asignment
	VbaseFimag &operator=(VbaseFimag &&); // move asignment

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
	~VbaseFimag();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseFimag::VbaseFimag() : m_p(nullptr), m_N(0) {}

inline VbaseFimag::VbaseFimag(Long_I N)
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

inline VbaseFimag::VbaseFimag(const VbaseFimag &rhs)
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

inline VbaseFimag::VbaseFimag(VbaseFimag &&rhs)
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

inline VbaseFimag &VbaseFimag::operator=(const VbaseFimag &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Fimag)*size());
	return *this;
}

inline VbaseFimag &VbaseFimag::operator=(VbaseFimag &&rhs)
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

inline Fimag * VbaseFimag::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Fimag * VbaseFimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseFimag::size() const
{
	return m_N;
}

inline void VbaseFimag::resize(Long_I N)
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

inline Fimag &VbaseFimag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseFimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Fimag &VbaseFimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseFimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Fimag &VbaseFimag::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Fimag &VbaseFimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Fimag &VbaseFimag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Fimag &VbaseFimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseFimag::~VbaseFimag()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseFimag &v) { return v.size(); }

inline const Fimag *ptr(const VbaseFimag &v) { return v.p(); }

inline Fimag *ptr(VbaseFimag &v) { return v.p(); }

class VbaseImag
{
protected:
	Imag *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseImag(); // default constructor
	explicit VbaseImag(Long_I N);
	VbaseImag(const VbaseImag &rhs); // copy constructor
	VbaseImag(VbaseImag&&); // move constructor

	VbaseImag &operator=(const VbaseImag &); // copy asignment
	VbaseImag &operator=(VbaseImag &&); // move asignment

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
	~VbaseImag();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseImag::VbaseImag() : m_p(nullptr), m_N(0) {}

inline VbaseImag::VbaseImag(Long_I N)
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

inline VbaseImag::VbaseImag(const VbaseImag &rhs)
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

inline VbaseImag::VbaseImag(VbaseImag &&rhs)
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

inline VbaseImag &VbaseImag::operator=(const VbaseImag &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Imag)*size());
	return *this;
}

inline VbaseImag &VbaseImag::operator=(VbaseImag &&rhs)
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

inline Imag * VbaseImag::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Imag * VbaseImag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseImag::size() const
{
	return m_N;
}

inline void VbaseImag::resize(Long_I N)
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

inline Imag &VbaseImag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseImag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Imag &VbaseImag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseImag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Imag &VbaseImag::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Imag &VbaseImag::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Imag &VbaseImag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Imag &VbaseImag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseImag::~VbaseImag()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseImag &v) { return v.size(); }

inline const Imag *ptr(const VbaseImag &v) { return v.p(); }

inline Imag *ptr(VbaseImag &v) { return v.p(); }

class VbaseLimag
{
protected:
	Limag *m_p; // pointer to the first element
	Long m_N; // number of elements
public:
	// constructors
	VbaseLimag(); // default constructor
	explicit VbaseLimag(Long_I N);
	VbaseLimag(const VbaseLimag &rhs); // copy constructor
	VbaseLimag(VbaseLimag&&); // move constructor

	VbaseLimag &operator=(const VbaseLimag &); // copy asignment
	VbaseLimag &operator=(VbaseLimag &&); // move asignment

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
	~VbaseLimag();
};

// m_p doesn't need to be initialized, but g++ will complain
inline VbaseLimag::VbaseLimag() : m_p(nullptr), m_N(0) {}

inline VbaseLimag::VbaseLimag(Long_I N)
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

inline VbaseLimag::VbaseLimag(const VbaseLimag &rhs)
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

inline VbaseLimag::VbaseLimag(VbaseLimag &&rhs)
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

inline VbaseLimag &VbaseLimag::operator=(const VbaseLimag &rhs)
{
#ifndef NDEBUG
	if (this == &rhs) SLS_ERR("self copy assignment forbidden!");
#endif
	resize(rhs.size());
	if (m_N > 0)
		memcpy(m_p, rhs.p(), sizeof(Limag)*size());
	return *this;
}

inline VbaseLimag &VbaseLimag::operator=(VbaseLimag &&rhs)
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

inline Limag * VbaseLimag::p()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline const Limag * VbaseLimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long VbaseLimag::size() const
{
	return m_N;
}

inline void VbaseLimag::resize(Long_I N)
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

inline Limag &VbaseLimag::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
	SLS_ERR("VbaseLimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline const Limag &VbaseLimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N)
		SLS_ERR("VbaseLimag index (" + num2str(i) + ") out of bounds: size = " + num2str(m_N));
#endif
	return m_p[i];
}

inline Limag &VbaseLimag::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Limag &VbaseLimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Limag &VbaseLimag::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline const Limag &VbaseLimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(m_N));
#endif
	return m_p[m_N - i];
}

inline VbaseLimag::~VbaseLimag()
{
	if (m_N != 0)
		delete[] m_p;
}

// common api for STL and SLISC
inline Long size(const VbaseLimag &v) { return v.size(); }

inline const Limag *ptr(const VbaseLimag &v) { return v.p(); }

inline Limag *ptr(VbaseLimag &v) { return v.p(); }



#ifdef SLS_USE_INT_AS_LONG
typedef VbaseInt VbaseLong;
#else
typedef VbaseLlong VbaseLong;
#endif

class VbaseBool : vector<bool>
{
public:
	typedef vector<bool> Base;
	typedef Base::reference ref;
	// constructors
	VbaseBool() = default;
	explicit VbaseBool(Long_I N);
	VbaseBool(const VbaseBool &rhs); // copy constructor
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

inline VbaseBool::VbaseBool(Long_I N) : Base(N)
{
#ifdef SLS_CHECK_SHAPES
	if (N < 0)
		SLS_ERR("size less than 0!");
#endif
}

inline VbaseBool::VbaseBool(const VbaseBool &rhs): Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
}

inline Long VbaseBool::size() const { return Base::size(); }

inline VbaseBool::ref VbaseBool::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=size())
		SLS_ERR("VbaseBool index (" + num2str(i) + ") out of bounds: size = " + num2str(size()));
#endif
	return Base::operator[](i);
}

inline bool VbaseBool::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=size())
		SLS_ERR("VbaseBool index (" + num2str(i) + ") out of bounds: size = " + num2str(size()));
#endif
	return Base::operator[](i);
}

inline VbaseBool::ref VbaseBool::end()
{
#ifdef SLS_CHECK_BOUNDS
	if (Base::empty())
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return Base::back();
}

inline bool VbaseBool::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (Base::empty())
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return Base::back();
}

inline VbaseBool::ref VbaseBool::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > size())
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(size()));
#endif
	return (*this)[size() - i];
}

inline bool VbaseBool::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > size())
		SLS_ERR("end(i) index (i = " + num2str(i) + ") out of bound: size = " + num2str(size()));
#endif
	return (*this)[size() - i];
}

// common api for STL and SLISC
inline Long size(const VbaseBool &v) { return v.size(); }

} // namespace slisc
