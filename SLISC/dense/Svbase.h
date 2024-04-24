#pragma once
#include "../global.h"
#include "../arith/Imag.h"

// this class is not memory safe!
// "C" means lower level const

namespace slisc {
class SvbaseBoolC
{
protected:
	const Bool *m_p;
	Long m_N;
public:
	SvbaseBoolC();
	explicit SvbaseBoolC(Long_I N);
	SvbaseBoolC(const Bool *data, Long_I N);
	SvbaseBoolC(const SvbaseBoolC &v) = default; // copy constructor (shalow)

	SvbaseBoolC &operator=(const SvbaseBoolC &v) = default; // copy assignment (shalow)

	const Bool* p() const;
	Long size() const;
	const Bool &operator[](Long_I i) const;
	const Bool &end() const;
	const Bool &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Bool *data);
	void set(Long_I N);
	void set(const Bool *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseBoolC();
};

inline SvbaseBoolC::SvbaseBoolC() {}

inline SvbaseBoolC::SvbaseBoolC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseBoolC::SvbaseBoolC(const Bool *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Bool * SvbaseBoolC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseBoolC::size() const
{
	return m_N;
}

inline const Bool &SvbaseBoolC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Bool &SvbaseBoolC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Bool &SvbaseBoolC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseBoolC::set(const Bool *data) {
	m_p = data;
}

inline void SvbaseBoolC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseBoolC::set(const Bool *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseBoolC::next() {
	m_p += m_N;
}

inline void SvbaseBoolC::last() {
	m_p -= m_N;
}

inline void SvbaseBoolC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseBoolC::~SvbaseBoolC() {}

typedef const SvbaseBoolC &SvbaseBool_I;
// common api for STL and SLISC
inline Long size(SvbaseBool_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseBoolC &` makes it ambiguous
inline const Bool *cptr(SvbaseBool_I v) { return v.p(); }

class SvbaseBool
{
protected:
	Bool *m_p;
	Long m_N;
public:
	SvbaseBool();
	explicit SvbaseBool(Long_I N);
	SvbaseBool(Bool *data, Long_I N);
	SvbaseBool(const SvbaseBool &v) = default; // copy constructor (shalow)

	SvbaseBool &operator=(const SvbaseBool &v) = default; // copy assignment (shalow)

	Bool* p() const;
	Long size() const;
	Bool &operator[](Long_I i) const;
	Bool &end() const;
	Bool &end(Long_I i) const;

	operator const SvbaseBoolC &() const;
	operator SvbaseBoolC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Bool *data);
	void set(Long_I N);
	void set(Bool *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseBool();
};

inline SvbaseBool::SvbaseBool() {}

inline SvbaseBool::SvbaseBool(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseBool::SvbaseBool(Bool *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Bool * SvbaseBool::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseBool::size() const
{
	return m_N;
}

inline Bool &SvbaseBool::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Bool &SvbaseBool::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Bool &SvbaseBool::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseBool::operator const SvbaseBoolC &() const
{
	return reinterpret_cast<const SvbaseBoolC &>(*this);
}

inline SvbaseBool::operator SvbaseBoolC &()
{
	return reinterpret_cast<SvbaseBoolC &>(*this);
}

inline void SvbaseBool::set(Bool *data) {
	m_p = data;
}

inline void SvbaseBool::set(Long_I N) {
	m_N = N;
}

inline void SvbaseBool::set(Bool *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseBool::next() {
	m_p += m_N;
}

inline void SvbaseBool::last() {
	m_p -= m_N;
}

inline void SvbaseBool::shift(Long_I N) {
	m_p += N;
}

inline SvbaseBool::~SvbaseBool() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseBool &SvbaseBool_O, &SvbaseBool_IO;
// common api for STL and SLISC
inline Bool *ptr(const SvbaseBool &v) { return v.p(); }

class SvbaseCharC
{
protected:
	const Char *m_p;
	Long m_N;
public:
	SvbaseCharC();
	explicit SvbaseCharC(Long_I N);
	SvbaseCharC(const Char *data, Long_I N);
	SvbaseCharC(const SvbaseCharC &v) = default; // copy constructor (shalow)

	SvbaseCharC &operator=(const SvbaseCharC &v) = default; // copy assignment (shalow)

	const Char* p() const;
	Long size() const;
	const Char &operator[](Long_I i) const;
	const Char &end() const;
	const Char &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Char *data);
	void set(Long_I N);
	void set(const Char *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseCharC();
};

inline SvbaseCharC::SvbaseCharC() {}

inline SvbaseCharC::SvbaseCharC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseCharC::SvbaseCharC(const Char *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Char * SvbaseCharC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseCharC::size() const
{
	return m_N;
}

inline const Char &SvbaseCharC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Char &SvbaseCharC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Char &SvbaseCharC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseCharC::set(const Char *data) {
	m_p = data;
}

inline void SvbaseCharC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseCharC::set(const Char *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseCharC::next() {
	m_p += m_N;
}

inline void SvbaseCharC::last() {
	m_p -= m_N;
}

inline void SvbaseCharC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseCharC::~SvbaseCharC() {}

typedef const SvbaseCharC &SvbaseChar_I;
// common api for STL and SLISC
inline Long size(SvbaseChar_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseCharC &` makes it ambiguous
inline const Char *cptr(SvbaseChar_I v) { return v.p(); }

class SvbaseChar
{
protected:
	Char *m_p;
	Long m_N;
public:
	SvbaseChar();
	explicit SvbaseChar(Long_I N);
	SvbaseChar(Char *data, Long_I N);
	SvbaseChar(const SvbaseChar &v) = default; // copy constructor (shalow)

	SvbaseChar &operator=(const SvbaseChar &v) = default; // copy assignment (shalow)

	Char* p() const;
	Long size() const;
	Char &operator[](Long_I i) const;
	Char &end() const;
	Char &end(Long_I i) const;

	operator const SvbaseCharC &() const;
	operator SvbaseCharC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Char *data);
	void set(Long_I N);
	void set(Char *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseChar();
};

inline SvbaseChar::SvbaseChar() {}

inline SvbaseChar::SvbaseChar(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseChar::SvbaseChar(Char *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Char * SvbaseChar::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseChar::size() const
{
	return m_N;
}

inline Char &SvbaseChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Char &SvbaseChar::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Char &SvbaseChar::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseChar::operator const SvbaseCharC &() const
{
	return reinterpret_cast<const SvbaseCharC &>(*this);
}

inline SvbaseChar::operator SvbaseCharC &()
{
	return reinterpret_cast<SvbaseCharC &>(*this);
}

inline void SvbaseChar::set(Char *data) {
	m_p = data;
}

inline void SvbaseChar::set(Long_I N) {
	m_N = N;
}

inline void SvbaseChar::set(Char *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseChar::next() {
	m_p += m_N;
}

inline void SvbaseChar::last() {
	m_p -= m_N;
}

inline void SvbaseChar::shift(Long_I N) {
	m_p += N;
}

inline SvbaseChar::~SvbaseChar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseChar &SvbaseChar_O, &SvbaseChar_IO;
// common api for STL and SLISC
inline Char *ptr(const SvbaseChar &v) { return v.p(); }

class SvbaseUcharC
{
protected:
	const Uchar *m_p;
	Long m_N;
public:
	SvbaseUcharC();
	explicit SvbaseUcharC(Long_I N);
	SvbaseUcharC(const Uchar *data, Long_I N);
	SvbaseUcharC(const SvbaseUcharC &v) = default; // copy constructor (shalow)

	SvbaseUcharC &operator=(const SvbaseUcharC &v) = default; // copy assignment (shalow)

	const Uchar* p() const;
	Long size() const;
	const Uchar &operator[](Long_I i) const;
	const Uchar &end() const;
	const Uchar &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Uchar *data);
	void set(Long_I N);
	void set(const Uchar *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseUcharC();
};

inline SvbaseUcharC::SvbaseUcharC() {}

inline SvbaseUcharC::SvbaseUcharC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseUcharC::SvbaseUcharC(const Uchar *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Uchar * SvbaseUcharC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseUcharC::size() const
{
	return m_N;
}

inline const Uchar &SvbaseUcharC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Uchar &SvbaseUcharC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Uchar &SvbaseUcharC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseUcharC::set(const Uchar *data) {
	m_p = data;
}

inline void SvbaseUcharC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseUcharC::set(const Uchar *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseUcharC::next() {
	m_p += m_N;
}

inline void SvbaseUcharC::last() {
	m_p -= m_N;
}

inline void SvbaseUcharC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseUcharC::~SvbaseUcharC() {}

typedef const SvbaseUcharC &SvbaseUchar_I;
// common api for STL and SLISC
inline Long size(SvbaseUchar_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseUcharC &` makes it ambiguous
inline const Uchar *cptr(SvbaseUchar_I v) { return v.p(); }

class SvbaseUchar
{
protected:
	Uchar *m_p;
	Long m_N;
public:
	SvbaseUchar();
	explicit SvbaseUchar(Long_I N);
	SvbaseUchar(Uchar *data, Long_I N);
	SvbaseUchar(const SvbaseUchar &v) = default; // copy constructor (shalow)

	SvbaseUchar &operator=(const SvbaseUchar &v) = default; // copy assignment (shalow)

	Uchar* p() const;
	Long size() const;
	Uchar &operator[](Long_I i) const;
	Uchar &end() const;
	Uchar &end(Long_I i) const;

	operator const SvbaseUcharC &() const;
	operator SvbaseUcharC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Uchar *data);
	void set(Long_I N);
	void set(Uchar *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseUchar();
};

inline SvbaseUchar::SvbaseUchar() {}

inline SvbaseUchar::SvbaseUchar(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseUchar::SvbaseUchar(Uchar *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Uchar * SvbaseUchar::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseUchar::size() const
{
	return m_N;
}

inline Uchar &SvbaseUchar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Uchar &SvbaseUchar::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Uchar &SvbaseUchar::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseUchar::operator const SvbaseUcharC &() const
{
	return reinterpret_cast<const SvbaseUcharC &>(*this);
}

inline SvbaseUchar::operator SvbaseUcharC &()
{
	return reinterpret_cast<SvbaseUcharC &>(*this);
}

inline void SvbaseUchar::set(Uchar *data) {
	m_p = data;
}

inline void SvbaseUchar::set(Long_I N) {
	m_N = N;
}

inline void SvbaseUchar::set(Uchar *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseUchar::next() {
	m_p += m_N;
}

inline void SvbaseUchar::last() {
	m_p -= m_N;
}

inline void SvbaseUchar::shift(Long_I N) {
	m_p += N;
}

inline SvbaseUchar::~SvbaseUchar() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseUchar &SvbaseUchar_O, &SvbaseUchar_IO;
// common api for STL and SLISC
inline Uchar *ptr(const SvbaseUchar &v) { return v.p(); }

class SvbaseIntC
{
protected:
	const Int *m_p;
	Long m_N;
public:
	SvbaseIntC();
	explicit SvbaseIntC(Long_I N);
	SvbaseIntC(const Int *data, Long_I N);
	SvbaseIntC(const SvbaseIntC &v) = default; // copy constructor (shalow)

	SvbaseIntC &operator=(const SvbaseIntC &v) = default; // copy assignment (shalow)

	const Int* p() const;
	Long size() const;
	const Int &operator[](Long_I i) const;
	const Int &end() const;
	const Int &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Int *data);
	void set(Long_I N);
	void set(const Int *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseIntC();
};

inline SvbaseIntC::SvbaseIntC() {}

inline SvbaseIntC::SvbaseIntC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseIntC::SvbaseIntC(const Int *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Int * SvbaseIntC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseIntC::size() const
{
	return m_N;
}

inline const Int &SvbaseIntC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Int &SvbaseIntC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Int &SvbaseIntC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseIntC::set(const Int *data) {
	m_p = data;
}

inline void SvbaseIntC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseIntC::set(const Int *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseIntC::next() {
	m_p += m_N;
}

inline void SvbaseIntC::last() {
	m_p -= m_N;
}

inline void SvbaseIntC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseIntC::~SvbaseIntC() {}

typedef const SvbaseIntC &SvbaseInt_I;
// common api for STL and SLISC
inline Long size(SvbaseInt_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseIntC &` makes it ambiguous
inline const Int *cptr(SvbaseInt_I v) { return v.p(); }

class SvbaseInt
{
protected:
	Int *m_p;
	Long m_N;
public:
	SvbaseInt();
	explicit SvbaseInt(Long_I N);
	SvbaseInt(Int *data, Long_I N);
	SvbaseInt(const SvbaseInt &v) = default; // copy constructor (shalow)

	SvbaseInt &operator=(const SvbaseInt &v) = default; // copy assignment (shalow)

	Int* p() const;
	Long size() const;
	Int &operator[](Long_I i) const;
	Int &end() const;
	Int &end(Long_I i) const;

	operator const SvbaseIntC &() const;
	operator SvbaseIntC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Int *data);
	void set(Long_I N);
	void set(Int *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseInt();
};

inline SvbaseInt::SvbaseInt() {}

inline SvbaseInt::SvbaseInt(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseInt::SvbaseInt(Int *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Int * SvbaseInt::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseInt::size() const
{
	return m_N;
}

inline Int &SvbaseInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Int &SvbaseInt::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Int &SvbaseInt::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseInt::operator const SvbaseIntC &() const
{
	return reinterpret_cast<const SvbaseIntC &>(*this);
}

inline SvbaseInt::operator SvbaseIntC &()
{
	return reinterpret_cast<SvbaseIntC &>(*this);
}

inline void SvbaseInt::set(Int *data) {
	m_p = data;
}

inline void SvbaseInt::set(Long_I N) {
	m_N = N;
}

inline void SvbaseInt::set(Int *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseInt::next() {
	m_p += m_N;
}

inline void SvbaseInt::last() {
	m_p -= m_N;
}

inline void SvbaseInt::shift(Long_I N) {
	m_p += N;
}

inline SvbaseInt::~SvbaseInt() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseInt &SvbaseInt_O, &SvbaseInt_IO;
// common api for STL and SLISC
inline Int *ptr(const SvbaseInt &v) { return v.p(); }

class SvbaseLlongC
{
protected:
	const Llong *m_p;
	Long m_N;
public:
	SvbaseLlongC();
	explicit SvbaseLlongC(Long_I N);
	SvbaseLlongC(const Llong *data, Long_I N);
	SvbaseLlongC(const SvbaseLlongC &v) = default; // copy constructor (shalow)

	SvbaseLlongC &operator=(const SvbaseLlongC &v) = default; // copy assignment (shalow)

	const Llong* p() const;
	Long size() const;
	const Llong &operator[](Long_I i) const;
	const Llong &end() const;
	const Llong &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Llong *data);
	void set(Long_I N);
	void set(const Llong *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLlongC();
};

inline SvbaseLlongC::SvbaseLlongC() {}

inline SvbaseLlongC::SvbaseLlongC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLlongC::SvbaseLlongC(const Llong *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Llong * SvbaseLlongC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLlongC::size() const
{
	return m_N;
}

inline const Llong &SvbaseLlongC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Llong &SvbaseLlongC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Llong &SvbaseLlongC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseLlongC::set(const Llong *data) {
	m_p = data;
}

inline void SvbaseLlongC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseLlongC::set(const Llong *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseLlongC::next() {
	m_p += m_N;
}

inline void SvbaseLlongC::last() {
	m_p -= m_N;
}

inline void SvbaseLlongC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseLlongC::~SvbaseLlongC() {}

typedef const SvbaseLlongC &SvbaseLlong_I;
// common api for STL and SLISC
inline Long size(SvbaseLlong_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseLlongC &` makes it ambiguous
inline const Llong *cptr(SvbaseLlong_I v) { return v.p(); }

class SvbaseLlong
{
protected:
	Llong *m_p;
	Long m_N;
public:
	SvbaseLlong();
	explicit SvbaseLlong(Long_I N);
	SvbaseLlong(Llong *data, Long_I N);
	SvbaseLlong(const SvbaseLlong &v) = default; // copy constructor (shalow)

	SvbaseLlong &operator=(const SvbaseLlong &v) = default; // copy assignment (shalow)

	Llong* p() const;
	Long size() const;
	Llong &operator[](Long_I i) const;
	Llong &end() const;
	Llong &end(Long_I i) const;

	operator const SvbaseLlongC &() const;
	operator SvbaseLlongC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Llong *data);
	void set(Long_I N);
	void set(Llong *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLlong();
};

inline SvbaseLlong::SvbaseLlong() {}

inline SvbaseLlong::SvbaseLlong(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLlong::SvbaseLlong(Llong *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Llong * SvbaseLlong::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLlong::size() const
{
	return m_N;
}

inline Llong &SvbaseLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Llong &SvbaseLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Llong &SvbaseLlong::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseLlong::operator const SvbaseLlongC &() const
{
	return reinterpret_cast<const SvbaseLlongC &>(*this);
}

inline SvbaseLlong::operator SvbaseLlongC &()
{
	return reinterpret_cast<SvbaseLlongC &>(*this);
}

inline void SvbaseLlong::set(Llong *data) {
	m_p = data;
}

inline void SvbaseLlong::set(Long_I N) {
	m_N = N;
}

inline void SvbaseLlong::set(Llong *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseLlong::next() {
	m_p += m_N;
}

inline void SvbaseLlong::last() {
	m_p -= m_N;
}

inline void SvbaseLlong::shift(Long_I N) {
	m_p += N;
}

inline SvbaseLlong::~SvbaseLlong() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseLlong &SvbaseLlong_O, &SvbaseLlong_IO;
// common api for STL and SLISC
inline Llong *ptr(const SvbaseLlong &v) { return v.p(); }

class SvbaseFloatC
{
protected:
	const Float *m_p;
	Long m_N;
public:
	SvbaseFloatC();
	explicit SvbaseFloatC(Long_I N);
	SvbaseFloatC(const Float *data, Long_I N);
	SvbaseFloatC(const SvbaseFloatC &v) = default; // copy constructor (shalow)

	SvbaseFloatC &operator=(const SvbaseFloatC &v) = default; // copy assignment (shalow)

	const Float* p() const;
	Long size() const;
	const Float &operator[](Long_I i) const;
	const Float &end() const;
	const Float &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Float *data);
	void set(Long_I N);
	void set(const Float *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseFloatC();
};

inline SvbaseFloatC::SvbaseFloatC() {}

inline SvbaseFloatC::SvbaseFloatC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseFloatC::SvbaseFloatC(const Float *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Float * SvbaseFloatC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseFloatC::size() const
{
	return m_N;
}

inline const Float &SvbaseFloatC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Float &SvbaseFloatC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Float &SvbaseFloatC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseFloatC::set(const Float *data) {
	m_p = data;
}

inline void SvbaseFloatC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseFloatC::set(const Float *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseFloatC::next() {
	m_p += m_N;
}

inline void SvbaseFloatC::last() {
	m_p -= m_N;
}

inline void SvbaseFloatC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseFloatC::~SvbaseFloatC() {}

typedef const SvbaseFloatC &SvbaseFloat_I;
// common api for STL and SLISC
inline Long size(SvbaseFloat_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseFloatC &` makes it ambiguous
inline const Float *cptr(SvbaseFloat_I v) { return v.p(); }

class SvbaseFloat
{
protected:
	Float *m_p;
	Long m_N;
public:
	SvbaseFloat();
	explicit SvbaseFloat(Long_I N);
	SvbaseFloat(Float *data, Long_I N);
	SvbaseFloat(const SvbaseFloat &v) = default; // copy constructor (shalow)

	SvbaseFloat &operator=(const SvbaseFloat &v) = default; // copy assignment (shalow)

	Float* p() const;
	Long size() const;
	Float &operator[](Long_I i) const;
	Float &end() const;
	Float &end(Long_I i) const;

	operator const SvbaseFloatC &() const;
	operator SvbaseFloatC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Float *data);
	void set(Long_I N);
	void set(Float *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseFloat();
};

inline SvbaseFloat::SvbaseFloat() {}

inline SvbaseFloat::SvbaseFloat(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseFloat::SvbaseFloat(Float *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Float * SvbaseFloat::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseFloat::size() const
{
	return m_N;
}

inline Float &SvbaseFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Float &SvbaseFloat::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Float &SvbaseFloat::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseFloat::operator const SvbaseFloatC &() const
{
	return reinterpret_cast<const SvbaseFloatC &>(*this);
}

inline SvbaseFloat::operator SvbaseFloatC &()
{
	return reinterpret_cast<SvbaseFloatC &>(*this);
}

inline void SvbaseFloat::set(Float *data) {
	m_p = data;
}

inline void SvbaseFloat::set(Long_I N) {
	m_N = N;
}

inline void SvbaseFloat::set(Float *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseFloat::next() {
	m_p += m_N;
}

inline void SvbaseFloat::last() {
	m_p -= m_N;
}

inline void SvbaseFloat::shift(Long_I N) {
	m_p += N;
}

inline SvbaseFloat::~SvbaseFloat() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseFloat &SvbaseFloat_O, &SvbaseFloat_IO;
// common api for STL and SLISC
inline Float *ptr(const SvbaseFloat &v) { return v.p(); }

class SvbaseDoubC
{
protected:
	const Doub *m_p;
	Long m_N;
public:
	SvbaseDoubC();
	explicit SvbaseDoubC(Long_I N);
	SvbaseDoubC(const Doub *data, Long_I N);
	SvbaseDoubC(const SvbaseDoubC &v) = default; // copy constructor (shalow)

	SvbaseDoubC &operator=(const SvbaseDoubC &v) = default; // copy assignment (shalow)

	const Doub* p() const;
	Long size() const;
	const Doub &operator[](Long_I i) const;
	const Doub &end() const;
	const Doub &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Doub *data);
	void set(Long_I N);
	void set(const Doub *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseDoubC();
};

inline SvbaseDoubC::SvbaseDoubC() {}

inline SvbaseDoubC::SvbaseDoubC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseDoubC::SvbaseDoubC(const Doub *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Doub * SvbaseDoubC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseDoubC::size() const
{
	return m_N;
}

inline const Doub &SvbaseDoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Doub &SvbaseDoubC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Doub &SvbaseDoubC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseDoubC::set(const Doub *data) {
	m_p = data;
}

inline void SvbaseDoubC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseDoubC::set(const Doub *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseDoubC::next() {
	m_p += m_N;
}

inline void SvbaseDoubC::last() {
	m_p -= m_N;
}

inline void SvbaseDoubC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseDoubC::~SvbaseDoubC() {}

typedef const SvbaseDoubC &SvbaseDoub_I;
// common api for STL and SLISC
inline Long size(SvbaseDoub_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseDoubC &` makes it ambiguous
inline const Doub *cptr(SvbaseDoub_I v) { return v.p(); }

class SvbaseDoub
{
protected:
	Doub *m_p;
	Long m_N;
public:
	SvbaseDoub();
	explicit SvbaseDoub(Long_I N);
	SvbaseDoub(Doub *data, Long_I N);
	SvbaseDoub(const SvbaseDoub &v) = default; // copy constructor (shalow)

	SvbaseDoub &operator=(const SvbaseDoub &v) = default; // copy assignment (shalow)

	Doub* p() const;
	Long size() const;
	Doub &operator[](Long_I i) const;
	Doub &end() const;
	Doub &end(Long_I i) const;

	operator const SvbaseDoubC &() const;
	operator SvbaseDoubC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Doub *data);
	void set(Long_I N);
	void set(Doub *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseDoub();
};

inline SvbaseDoub::SvbaseDoub() {}

inline SvbaseDoub::SvbaseDoub(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseDoub::SvbaseDoub(Doub *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Doub * SvbaseDoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseDoub::size() const
{
	return m_N;
}

inline Doub &SvbaseDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Doub &SvbaseDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Doub &SvbaseDoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseDoub::operator const SvbaseDoubC &() const
{
	return reinterpret_cast<const SvbaseDoubC &>(*this);
}

inline SvbaseDoub::operator SvbaseDoubC &()
{
	return reinterpret_cast<SvbaseDoubC &>(*this);
}

inline void SvbaseDoub::set(Doub *data) {
	m_p = data;
}

inline void SvbaseDoub::set(Long_I N) {
	m_N = N;
}

inline void SvbaseDoub::set(Doub *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseDoub::next() {
	m_p += m_N;
}

inline void SvbaseDoub::last() {
	m_p -= m_N;
}

inline void SvbaseDoub::shift(Long_I N) {
	m_p += N;
}

inline SvbaseDoub::~SvbaseDoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseDoub &SvbaseDoub_O, &SvbaseDoub_IO;
// common api for STL and SLISC
inline Doub *ptr(const SvbaseDoub &v) { return v.p(); }

class SvbaseLdoubC
{
protected:
	const Ldoub *m_p;
	Long m_N;
public:
	SvbaseLdoubC();
	explicit SvbaseLdoubC(Long_I N);
	SvbaseLdoubC(const Ldoub *data, Long_I N);
	SvbaseLdoubC(const SvbaseLdoubC &v) = default; // copy constructor (shalow)

	SvbaseLdoubC &operator=(const SvbaseLdoubC &v) = default; // copy assignment (shalow)

	const Ldoub* p() const;
	Long size() const;
	const Ldoub &operator[](Long_I i) const;
	const Ldoub &end() const;
	const Ldoub &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Ldoub *data);
	void set(Long_I N);
	void set(const Ldoub *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLdoubC();
};

inline SvbaseLdoubC::SvbaseLdoubC() {}

inline SvbaseLdoubC::SvbaseLdoubC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLdoubC::SvbaseLdoubC(const Ldoub *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Ldoub * SvbaseLdoubC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLdoubC::size() const
{
	return m_N;
}

inline const Ldoub &SvbaseLdoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Ldoub &SvbaseLdoubC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Ldoub &SvbaseLdoubC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseLdoubC::set(const Ldoub *data) {
	m_p = data;
}

inline void SvbaseLdoubC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseLdoubC::set(const Ldoub *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseLdoubC::next() {
	m_p += m_N;
}

inline void SvbaseLdoubC::last() {
	m_p -= m_N;
}

inline void SvbaseLdoubC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseLdoubC::~SvbaseLdoubC() {}

typedef const SvbaseLdoubC &SvbaseLdoub_I;
// common api for STL and SLISC
inline Long size(SvbaseLdoub_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseLdoubC &` makes it ambiguous
inline const Ldoub *cptr(SvbaseLdoub_I v) { return v.p(); }

class SvbaseLdoub
{
protected:
	Ldoub *m_p;
	Long m_N;
public:
	SvbaseLdoub();
	explicit SvbaseLdoub(Long_I N);
	SvbaseLdoub(Ldoub *data, Long_I N);
	SvbaseLdoub(const SvbaseLdoub &v) = default; // copy constructor (shalow)

	SvbaseLdoub &operator=(const SvbaseLdoub &v) = default; // copy assignment (shalow)

	Ldoub* p() const;
	Long size() const;
	Ldoub &operator[](Long_I i) const;
	Ldoub &end() const;
	Ldoub &end(Long_I i) const;

	operator const SvbaseLdoubC &() const;
	operator SvbaseLdoubC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Ldoub *data);
	void set(Long_I N);
	void set(Ldoub *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLdoub();
};

inline SvbaseLdoub::SvbaseLdoub() {}

inline SvbaseLdoub::SvbaseLdoub(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLdoub::SvbaseLdoub(Ldoub *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Ldoub * SvbaseLdoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLdoub::size() const
{
	return m_N;
}

inline Ldoub &SvbaseLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Ldoub &SvbaseLdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Ldoub &SvbaseLdoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseLdoub::operator const SvbaseLdoubC &() const
{
	return reinterpret_cast<const SvbaseLdoubC &>(*this);
}

inline SvbaseLdoub::operator SvbaseLdoubC &()
{
	return reinterpret_cast<SvbaseLdoubC &>(*this);
}

inline void SvbaseLdoub::set(Ldoub *data) {
	m_p = data;
}

inline void SvbaseLdoub::set(Long_I N) {
	m_N = N;
}

inline void SvbaseLdoub::set(Ldoub *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseLdoub::next() {
	m_p += m_N;
}

inline void SvbaseLdoub::last() {
	m_p -= m_N;
}

inline void SvbaseLdoub::shift(Long_I N) {
	m_p += N;
}

inline SvbaseLdoub::~SvbaseLdoub() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseLdoub &SvbaseLdoub_O, &SvbaseLdoub_IO;
// common api for STL and SLISC
inline Ldoub *ptr(const SvbaseLdoub &v) { return v.p(); }



class SvbaseFcompC
{
protected:
	const Fcomp *m_p;
	Long m_N;
public:
	SvbaseFcompC();
	explicit SvbaseFcompC(Long_I N);
	SvbaseFcompC(const Fcomp *data, Long_I N);
	SvbaseFcompC(const SvbaseFcompC &v) = default; // copy constructor (shalow)

	SvbaseFcompC &operator=(const SvbaseFcompC &v) = default; // copy assignment (shalow)

	const Fcomp* p() const;
	Long size() const;
	const Fcomp &operator[](Long_I i) const;
	const Fcomp &end() const;
	const Fcomp &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Fcomp *data);
	void set(Long_I N);
	void set(const Fcomp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseFcompC();
};

inline SvbaseFcompC::SvbaseFcompC() {}

inline SvbaseFcompC::SvbaseFcompC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseFcompC::SvbaseFcompC(const Fcomp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Fcomp * SvbaseFcompC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseFcompC::size() const
{
	return m_N;
}

inline const Fcomp &SvbaseFcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Fcomp &SvbaseFcompC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Fcomp &SvbaseFcompC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseFcompC::set(const Fcomp *data) {
	m_p = data;
}

inline void SvbaseFcompC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseFcompC::set(const Fcomp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseFcompC::next() {
	m_p += m_N;
}

inline void SvbaseFcompC::last() {
	m_p -= m_N;
}

inline void SvbaseFcompC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseFcompC::~SvbaseFcompC() {}

typedef const SvbaseFcompC &SvbaseFcomp_I;
// common api for STL and SLISC
inline Long size(SvbaseFcomp_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseFcompC &` makes it ambiguous
inline const Fcomp *cptr(SvbaseFcomp_I v) { return v.p(); }

class SvbaseFcomp
{
protected:
	Fcomp *m_p;
	Long m_N;
public:
	SvbaseFcomp();
	explicit SvbaseFcomp(Long_I N);
	SvbaseFcomp(Fcomp *data, Long_I N);
	SvbaseFcomp(const SvbaseFcomp &v) = default; // copy constructor (shalow)

	SvbaseFcomp &operator=(const SvbaseFcomp &v) = default; // copy assignment (shalow)

	Fcomp* p() const;
	Long size() const;
	Fcomp &operator[](Long_I i) const;
	Fcomp &end() const;
	Fcomp &end(Long_I i) const;

	operator const SvbaseFcompC &() const;
	operator SvbaseFcompC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Fcomp *data);
	void set(Long_I N);
	void set(Fcomp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseFcomp();
};

inline SvbaseFcomp::SvbaseFcomp() {}

inline SvbaseFcomp::SvbaseFcomp(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseFcomp::SvbaseFcomp(Fcomp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Fcomp * SvbaseFcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseFcomp::size() const
{
	return m_N;
}

inline Fcomp &SvbaseFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Fcomp &SvbaseFcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Fcomp &SvbaseFcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseFcomp::operator const SvbaseFcompC &() const
{
	return reinterpret_cast<const SvbaseFcompC &>(*this);
}

inline SvbaseFcomp::operator SvbaseFcompC &()
{
	return reinterpret_cast<SvbaseFcompC &>(*this);
}

inline void SvbaseFcomp::set(Fcomp *data) {
	m_p = data;
}

inline void SvbaseFcomp::set(Long_I N) {
	m_N = N;
}

inline void SvbaseFcomp::set(Fcomp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseFcomp::next() {
	m_p += m_N;
}

inline void SvbaseFcomp::last() {
	m_p -= m_N;
}

inline void SvbaseFcomp::shift(Long_I N) {
	m_p += N;
}

inline SvbaseFcomp::~SvbaseFcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseFcomp &SvbaseFcomp_O, &SvbaseFcomp_IO;
// common api for STL and SLISC
inline Fcomp *ptr(const SvbaseFcomp &v) { return v.p(); }

class SvbaseCompC
{
protected:
	const Comp *m_p;
	Long m_N;
public:
	SvbaseCompC();
	explicit SvbaseCompC(Long_I N);
	SvbaseCompC(const Comp *data, Long_I N);
	SvbaseCompC(const SvbaseCompC &v) = default; // copy constructor (shalow)

	SvbaseCompC &operator=(const SvbaseCompC &v) = default; // copy assignment (shalow)

	const Comp* p() const;
	Long size() const;
	const Comp &operator[](Long_I i) const;
	const Comp &end() const;
	const Comp &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Comp *data);
	void set(Long_I N);
	void set(const Comp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseCompC();
};

inline SvbaseCompC::SvbaseCompC() {}

inline SvbaseCompC::SvbaseCompC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseCompC::SvbaseCompC(const Comp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Comp * SvbaseCompC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseCompC::size() const
{
	return m_N;
}

inline const Comp &SvbaseCompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Comp &SvbaseCompC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Comp &SvbaseCompC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseCompC::set(const Comp *data) {
	m_p = data;
}

inline void SvbaseCompC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseCompC::set(const Comp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseCompC::next() {
	m_p += m_N;
}

inline void SvbaseCompC::last() {
	m_p -= m_N;
}

inline void SvbaseCompC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseCompC::~SvbaseCompC() {}

typedef const SvbaseCompC &SvbaseComp_I;
// common api for STL and SLISC
inline Long size(SvbaseComp_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseCompC &` makes it ambiguous
inline const Comp *cptr(SvbaseComp_I v) { return v.p(); }

class SvbaseComp
{
protected:
	Comp *m_p;
	Long m_N;
public:
	SvbaseComp();
	explicit SvbaseComp(Long_I N);
	SvbaseComp(Comp *data, Long_I N);
	SvbaseComp(const SvbaseComp &v) = default; // copy constructor (shalow)

	SvbaseComp &operator=(const SvbaseComp &v) = default; // copy assignment (shalow)

	Comp* p() const;
	Long size() const;
	Comp &operator[](Long_I i) const;
	Comp &end() const;
	Comp &end(Long_I i) const;

	operator const SvbaseCompC &() const;
	operator SvbaseCompC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Comp *data);
	void set(Long_I N);
	void set(Comp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseComp();
};

inline SvbaseComp::SvbaseComp() {}

inline SvbaseComp::SvbaseComp(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseComp::SvbaseComp(Comp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Comp * SvbaseComp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseComp::size() const
{
	return m_N;
}

inline Comp &SvbaseComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Comp &SvbaseComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Comp &SvbaseComp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseComp::operator const SvbaseCompC &() const
{
	return reinterpret_cast<const SvbaseCompC &>(*this);
}

inline SvbaseComp::operator SvbaseCompC &()
{
	return reinterpret_cast<SvbaseCompC &>(*this);
}

inline void SvbaseComp::set(Comp *data) {
	m_p = data;
}

inline void SvbaseComp::set(Long_I N) {
	m_N = N;
}

inline void SvbaseComp::set(Comp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseComp::next() {
	m_p += m_N;
}

inline void SvbaseComp::last() {
	m_p -= m_N;
}

inline void SvbaseComp::shift(Long_I N) {
	m_p += N;
}

inline SvbaseComp::~SvbaseComp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseComp &SvbaseComp_O, &SvbaseComp_IO;
// common api for STL and SLISC
inline Comp *ptr(const SvbaseComp &v) { return v.p(); }

class SvbaseLcompC
{
protected:
	const Lcomp *m_p;
	Long m_N;
public:
	SvbaseLcompC();
	explicit SvbaseLcompC(Long_I N);
	SvbaseLcompC(const Lcomp *data, Long_I N);
	SvbaseLcompC(const SvbaseLcompC &v) = default; // copy constructor (shalow)

	SvbaseLcompC &operator=(const SvbaseLcompC &v) = default; // copy assignment (shalow)

	const Lcomp* p() const;
	Long size() const;
	const Lcomp &operator[](Long_I i) const;
	const Lcomp &end() const;
	const Lcomp &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Lcomp *data);
	void set(Long_I N);
	void set(const Lcomp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLcompC();
};

inline SvbaseLcompC::SvbaseLcompC() {}

inline SvbaseLcompC::SvbaseLcompC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLcompC::SvbaseLcompC(const Lcomp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Lcomp * SvbaseLcompC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLcompC::size() const
{
	return m_N;
}

inline const Lcomp &SvbaseLcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Lcomp &SvbaseLcompC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Lcomp &SvbaseLcompC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseLcompC::set(const Lcomp *data) {
	m_p = data;
}

inline void SvbaseLcompC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseLcompC::set(const Lcomp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseLcompC::next() {
	m_p += m_N;
}

inline void SvbaseLcompC::last() {
	m_p -= m_N;
}

inline void SvbaseLcompC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseLcompC::~SvbaseLcompC() {}

typedef const SvbaseLcompC &SvbaseLcomp_I;
// common api for STL and SLISC
inline Long size(SvbaseLcomp_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseLcompC &` makes it ambiguous
inline const Lcomp *cptr(SvbaseLcomp_I v) { return v.p(); }

class SvbaseLcomp
{
protected:
	Lcomp *m_p;
	Long m_N;
public:
	SvbaseLcomp();
	explicit SvbaseLcomp(Long_I N);
	SvbaseLcomp(Lcomp *data, Long_I N);
	SvbaseLcomp(const SvbaseLcomp &v) = default; // copy constructor (shalow)

	SvbaseLcomp &operator=(const SvbaseLcomp &v) = default; // copy assignment (shalow)

	Lcomp* p() const;
	Long size() const;
	Lcomp &operator[](Long_I i) const;
	Lcomp &end() const;
	Lcomp &end(Long_I i) const;

	operator const SvbaseLcompC &() const;
	operator SvbaseLcompC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Lcomp *data);
	void set(Long_I N);
	void set(Lcomp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLcomp();
};

inline SvbaseLcomp::SvbaseLcomp() {}

inline SvbaseLcomp::SvbaseLcomp(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLcomp::SvbaseLcomp(Lcomp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Lcomp * SvbaseLcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLcomp::size() const
{
	return m_N;
}

inline Lcomp &SvbaseLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Lcomp &SvbaseLcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Lcomp &SvbaseLcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseLcomp::operator const SvbaseLcompC &() const
{
	return reinterpret_cast<const SvbaseLcompC &>(*this);
}

inline SvbaseLcomp::operator SvbaseLcompC &()
{
	return reinterpret_cast<SvbaseLcompC &>(*this);
}

inline void SvbaseLcomp::set(Lcomp *data) {
	m_p = data;
}

inline void SvbaseLcomp::set(Long_I N) {
	m_N = N;
}

inline void SvbaseLcomp::set(Lcomp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseLcomp::next() {
	m_p += m_N;
}

inline void SvbaseLcomp::last() {
	m_p -= m_N;
}

inline void SvbaseLcomp::shift(Long_I N) {
	m_p += N;
}

inline SvbaseLcomp::~SvbaseLcomp() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseLcomp &SvbaseLcomp_O, &SvbaseLcomp_IO;
// common api for STL and SLISC
inline Lcomp *ptr(const SvbaseLcomp &v) { return v.p(); }



class SvbaseFimagC
{
protected:
	const Fimag *m_p;
	Long m_N;
public:
	SvbaseFimagC();
	explicit SvbaseFimagC(Long_I N);
	SvbaseFimagC(const Fimag *data, Long_I N);
	SvbaseFimagC(const SvbaseFimagC &v) = default; // copy constructor (shalow)

	SvbaseFimagC &operator=(const SvbaseFimagC &v) = default; // copy assignment (shalow)

	const Fimag* p() const;
	Long size() const;
	const Fimag &operator[](Long_I i) const;
	const Fimag &end() const;
	const Fimag &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Fimag *data);
	void set(Long_I N);
	void set(const Fimag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseFimagC();
};

inline SvbaseFimagC::SvbaseFimagC() {}

inline SvbaseFimagC::SvbaseFimagC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseFimagC::SvbaseFimagC(const Fimag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Fimag * SvbaseFimagC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseFimagC::size() const
{
	return m_N;
}

inline const Fimag &SvbaseFimagC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Fimag &SvbaseFimagC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Fimag &SvbaseFimagC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseFimagC::set(const Fimag *data) {
	m_p = data;
}

inline void SvbaseFimagC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseFimagC::set(const Fimag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseFimagC::next() {
	m_p += m_N;
}

inline void SvbaseFimagC::last() {
	m_p -= m_N;
}

inline void SvbaseFimagC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseFimagC::~SvbaseFimagC() {}

typedef const SvbaseFimagC &SvbaseFimag_I;
// common api for STL and SLISC
inline Long size(SvbaseFimag_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseFimagC &` makes it ambiguous
inline const Fimag *cptr(SvbaseFimag_I v) { return v.p(); }

class SvbaseFimag
{
protected:
	Fimag *m_p;
	Long m_N;
public:
	SvbaseFimag();
	explicit SvbaseFimag(Long_I N);
	SvbaseFimag(Fimag *data, Long_I N);
	SvbaseFimag(const SvbaseFimag &v) = default; // copy constructor (shalow)

	SvbaseFimag &operator=(const SvbaseFimag &v) = default; // copy assignment (shalow)

	Fimag* p() const;
	Long size() const;
	Fimag &operator[](Long_I i) const;
	Fimag &end() const;
	Fimag &end(Long_I i) const;

	operator const SvbaseFimagC &() const;
	operator SvbaseFimagC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Fimag *data);
	void set(Long_I N);
	void set(Fimag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseFimag();
};

inline SvbaseFimag::SvbaseFimag() {}

inline SvbaseFimag::SvbaseFimag(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseFimag::SvbaseFimag(Fimag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Fimag * SvbaseFimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseFimag::size() const
{
	return m_N;
}

inline Fimag &SvbaseFimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Fimag &SvbaseFimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Fimag &SvbaseFimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseFimag::operator const SvbaseFimagC &() const
{
	return reinterpret_cast<const SvbaseFimagC &>(*this);
}

inline SvbaseFimag::operator SvbaseFimagC &()
{
	return reinterpret_cast<SvbaseFimagC &>(*this);
}

inline void SvbaseFimag::set(Fimag *data) {
	m_p = data;
}

inline void SvbaseFimag::set(Long_I N) {
	m_N = N;
}

inline void SvbaseFimag::set(Fimag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseFimag::next() {
	m_p += m_N;
}

inline void SvbaseFimag::last() {
	m_p -= m_N;
}

inline void SvbaseFimag::shift(Long_I N) {
	m_p += N;
}

inline SvbaseFimag::~SvbaseFimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseFimag &SvbaseFimag_O, &SvbaseFimag_IO;
// common api for STL and SLISC
inline Fimag *ptr(const SvbaseFimag &v) { return v.p(); }

class SvbaseImagC
{
protected:
	const Imag *m_p;
	Long m_N;
public:
	SvbaseImagC();
	explicit SvbaseImagC(Long_I N);
	SvbaseImagC(const Imag *data, Long_I N);
	SvbaseImagC(const SvbaseImagC &v) = default; // copy constructor (shalow)

	SvbaseImagC &operator=(const SvbaseImagC &v) = default; // copy assignment (shalow)

	const Imag* p() const;
	Long size() const;
	const Imag &operator[](Long_I i) const;
	const Imag &end() const;
	const Imag &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Imag *data);
	void set(Long_I N);
	void set(const Imag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseImagC();
};

inline SvbaseImagC::SvbaseImagC() {}

inline SvbaseImagC::SvbaseImagC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseImagC::SvbaseImagC(const Imag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Imag * SvbaseImagC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseImagC::size() const
{
	return m_N;
}

inline const Imag &SvbaseImagC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Imag &SvbaseImagC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Imag &SvbaseImagC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseImagC::set(const Imag *data) {
	m_p = data;
}

inline void SvbaseImagC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseImagC::set(const Imag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseImagC::next() {
	m_p += m_N;
}

inline void SvbaseImagC::last() {
	m_p -= m_N;
}

inline void SvbaseImagC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseImagC::~SvbaseImagC() {}

typedef const SvbaseImagC &SvbaseImag_I;
// common api for STL and SLISC
inline Long size(SvbaseImag_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseImagC &` makes it ambiguous
inline const Imag *cptr(SvbaseImag_I v) { return v.p(); }

class SvbaseImag
{
protected:
	Imag *m_p;
	Long m_N;
public:
	SvbaseImag();
	explicit SvbaseImag(Long_I N);
	SvbaseImag(Imag *data, Long_I N);
	SvbaseImag(const SvbaseImag &v) = default; // copy constructor (shalow)

	SvbaseImag &operator=(const SvbaseImag &v) = default; // copy assignment (shalow)

	Imag* p() const;
	Long size() const;
	Imag &operator[](Long_I i) const;
	Imag &end() const;
	Imag &end(Long_I i) const;

	operator const SvbaseImagC &() const;
	operator SvbaseImagC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Imag *data);
	void set(Long_I N);
	void set(Imag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseImag();
};

inline SvbaseImag::SvbaseImag() {}

inline SvbaseImag::SvbaseImag(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseImag::SvbaseImag(Imag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Imag * SvbaseImag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseImag::size() const
{
	return m_N;
}

inline Imag &SvbaseImag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Imag &SvbaseImag::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Imag &SvbaseImag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseImag::operator const SvbaseImagC &() const
{
	return reinterpret_cast<const SvbaseImagC &>(*this);
}

inline SvbaseImag::operator SvbaseImagC &()
{
	return reinterpret_cast<SvbaseImagC &>(*this);
}

inline void SvbaseImag::set(Imag *data) {
	m_p = data;
}

inline void SvbaseImag::set(Long_I N) {
	m_N = N;
}

inline void SvbaseImag::set(Imag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseImag::next() {
	m_p += m_N;
}

inline void SvbaseImag::last() {
	m_p -= m_N;
}

inline void SvbaseImag::shift(Long_I N) {
	m_p += N;
}

inline SvbaseImag::~SvbaseImag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseImag &SvbaseImag_O, &SvbaseImag_IO;
// common api for STL and SLISC
inline Imag *ptr(const SvbaseImag &v) { return v.p(); }

class SvbaseLimagC
{
protected:
	const Limag *m_p;
	Long m_N;
public:
	SvbaseLimagC();
	explicit SvbaseLimagC(Long_I N);
	SvbaseLimagC(const Limag *data, Long_I N);
	SvbaseLimagC(const SvbaseLimagC &v) = default; // copy constructor (shalow)

	SvbaseLimagC &operator=(const SvbaseLimagC &v) = default; // copy assignment (shalow)

	const Limag* p() const;
	Long size() const;
	const Limag &operator[](Long_I i) const;
	const Limag &end() const;
	const Limag &end(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Limag *data);
	void set(Long_I N);
	void set(const Limag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLimagC();
};

inline SvbaseLimagC::SvbaseLimagC() {}

inline SvbaseLimagC::SvbaseLimagC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLimagC::SvbaseLimagC(const Limag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Limag * SvbaseLimagC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLimagC::size() const
{
	return m_N;
}

inline const Limag &SvbaseLimagC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Limag &SvbaseLimagC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Limag &SvbaseLimagC::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseLimagC::set(const Limag *data) {
	m_p = data;
}

inline void SvbaseLimagC::set(Long_I N) {
	m_N = N;
}

inline void SvbaseLimagC::set(const Limag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseLimagC::next() {
	m_p += m_N;
}

inline void SvbaseLimagC::last() {
	m_p -= m_N;
}

inline void SvbaseLimagC::shift(Long_I N) {
	m_p += N;
}

inline SvbaseLimagC::~SvbaseLimagC() {}

typedef const SvbaseLimagC &SvbaseLimag_I;
// common api for STL and SLISC
inline Long size(SvbaseLimag_I v) { return v.size(); }
	// cannot overload ptr() because auto cast `const SvbaseLimagC &` makes it ambiguous
inline const Limag *cptr(SvbaseLimag_I v) { return v.p(); }

class SvbaseLimag
{
protected:
	Limag *m_p;
	Long m_N;
public:
	SvbaseLimag();
	explicit SvbaseLimag(Long_I N);
	SvbaseLimag(Limag *data, Long_I N);
	SvbaseLimag(const SvbaseLimag &v) = default; // copy constructor (shalow)

	SvbaseLimag &operator=(const SvbaseLimag &v) = default; // copy assignment (shalow)

	Limag* p() const;
	Long size() const;
	Limag &operator[](Long_I i) const;
	Limag &end() const;
	Limag &end(Long_I i) const;

	operator const SvbaseLimagC &() const;
	operator SvbaseLimagC &();

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Limag *data);
	void set(Long_I N);
	void set(Limag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLimag();
};

inline SvbaseLimag::SvbaseLimag() {}

inline SvbaseLimag::SvbaseLimag(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLimag::SvbaseLimag(Limag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Limag * SvbaseLimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLimag::size() const
{
	return m_N;
}

inline Limag &SvbaseLimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Limag &SvbaseLimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Limag &SvbaseLimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvbaseLimag::operator const SvbaseLimagC &() const
{
	return reinterpret_cast<const SvbaseLimagC &>(*this);
}

inline SvbaseLimag::operator SvbaseLimagC &()
{
	return reinterpret_cast<SvbaseLimagC &>(*this);
}

inline void SvbaseLimag::set(Limag *data) {
	m_p = data;
}

inline void SvbaseLimag::set(Long_I N) {
	m_N = N;
}

inline void SvbaseLimag::set(Limag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvbaseLimag::next() {
	m_p += m_N;
}

inline void SvbaseLimag::last() {
	m_p -= m_N;
}

inline void SvbaseLimag::shift(Long_I N) {
	m_p += N;
}

inline SvbaseLimag::~SvbaseLimag() {}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvbaseLimag &SvbaseLimag_O, &SvbaseLimag_IO;
// common api for STL and SLISC
inline Limag *ptr(const SvbaseLimag &v) { return v.p(); }




} // namespace slisc
