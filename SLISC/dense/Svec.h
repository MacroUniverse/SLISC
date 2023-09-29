#pragma once
#include "../global.h"
#include "../arith/Imag.h"
#include "../dense/Vec.h"

// this class is not memory safe!
// "C" means lower level const

namespace slisc {
class SvecCharC
{
protected:
	const Char *m_p;
	Long m_N;
public:
	SvecCharC();
	explicit SvecCharC(Long_I N);
	SvecCharC(const Char *data, Long_I N);
	SvecCharC(const SvecCharC &v) = default; // copy constructor (shalow)

	SvecCharC &operator=(const SvecCharC &v) = default; // copy assignment (shalow)

	const Char* p() const;
	Long size() const;
	const Char &operator[](Long_I i) const;
	const Char &back() const;
	const Char &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Char *data);
	void set(Long_I N);
	void set(const Char *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecCharC();
};

inline SvecCharC::SvecCharC() {}

inline SvecCharC::SvecCharC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecCharC::SvecCharC(const Char *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Char * SvecCharC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecCharC::size() const
{
	return m_N;
}

inline const Char &SvecCharC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Char &SvecCharC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Char &SvecCharC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecCharC::set(const Char *data) {
	m_p = data;
}

inline void SvecCharC::set(Long_I N) {
	m_N = N;
}

inline void SvecCharC::set(const Char *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecCharC::next() {
	m_p += m_N;
}

inline void SvecCharC::last() {
	m_p -= m_N;
}

inline void SvecCharC::shift(Long_I N) {
	m_p += N;
}

inline void SvecCharC::set(const SvecCharC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecCharC::~SvecCharC() {}

// common api for STL and SLISC
inline Long size(const SvecCharC &v) { return v.size(); }

inline const Char *ptr(const SvecCharC &v) { return v.p(); }

class SvecChar
{
protected:
	Char *m_p;
	Long m_N;
public:
	SvecChar();
	explicit SvecChar(Long_I N);
	SvecChar(Char *data, Long_I N);
	SvecChar(const SvecChar &v) = default; // copy constructor (shalow)

	SvecChar &operator=(const SvecChar &v) = default; // copy assignment (shalow)

	Char* p() const;
	Long size() const;
	Char &operator[](Long_I i) const;
	Char &back() const;
	Char &back(Long_I i) const;

	operator SvecCharC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Char *data);
	void set(Long_I N);
	void set(Char *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecChar();
};

inline SvecChar::SvecChar() {}

inline SvecChar::SvecChar(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecChar::SvecChar(Char *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Char * SvecChar::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecChar::size() const
{
	return m_N;
}

inline Char &SvecChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Char &SvecChar::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Char &SvecChar::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecChar::operator SvecCharC() const {
	return *((SvecCharC *)this);
}

inline void SvecChar::set(Char *data) {
	m_p = data;
}

inline void SvecChar::set(Long_I N) {
	m_N = N;
}

inline void SvecChar::set(Char *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecChar::next() {
	m_p += m_N;
}

inline void SvecChar::last() {
	m_p -= m_N;
}

inline void SvecChar::shift(Long_I N) {
	m_p += N;
}

inline void SvecChar::set(const SvecChar &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecChar::~SvecChar() {}

// common api for STL and SLISC
inline Long size(const SvecChar &v) { return v.size(); }

inline Char *ptr(SvecChar &v) { return v.p(); }

class SvecUcharC
{
protected:
	const Uchar *m_p;
	Long m_N;
public:
	SvecUcharC();
	explicit SvecUcharC(Long_I N);
	SvecUcharC(const Uchar *data, Long_I N);
	SvecUcharC(const SvecUcharC &v) = default; // copy constructor (shalow)

	SvecUcharC &operator=(const SvecUcharC &v) = default; // copy assignment (shalow)

	const Uchar* p() const;
	Long size() const;
	const Uchar &operator[](Long_I i) const;
	const Uchar &back() const;
	const Uchar &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Uchar *data);
	void set(Long_I N);
	void set(const Uchar *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecUcharC();
};

inline SvecUcharC::SvecUcharC() {}

inline SvecUcharC::SvecUcharC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecUcharC::SvecUcharC(const Uchar *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Uchar * SvecUcharC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecUcharC::size() const
{
	return m_N;
}

inline const Uchar &SvecUcharC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Uchar &SvecUcharC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Uchar &SvecUcharC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecUcharC::set(const Uchar *data) {
	m_p = data;
}

inline void SvecUcharC::set(Long_I N) {
	m_N = N;
}

inline void SvecUcharC::set(const Uchar *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecUcharC::next() {
	m_p += m_N;
}

inline void SvecUcharC::last() {
	m_p -= m_N;
}

inline void SvecUcharC::shift(Long_I N) {
	m_p += N;
}

inline void SvecUcharC::set(const SvecUcharC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecUcharC::~SvecUcharC() {}

// common api for STL and SLISC
inline Long size(const SvecUcharC &v) { return v.size(); }

inline const Uchar *ptr(const SvecUcharC &v) { return v.p(); }

class SvecUchar
{
protected:
	Uchar *m_p;
	Long m_N;
public:
	SvecUchar();
	explicit SvecUchar(Long_I N);
	SvecUchar(Uchar *data, Long_I N);
	SvecUchar(const SvecUchar &v) = default; // copy constructor (shalow)

	SvecUchar &operator=(const SvecUchar &v) = default; // copy assignment (shalow)

	Uchar* p() const;
	Long size() const;
	Uchar &operator[](Long_I i) const;
	Uchar &back() const;
	Uchar &back(Long_I i) const;

	operator SvecUcharC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Uchar *data);
	void set(Long_I N);
	void set(Uchar *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecUchar();
};

inline SvecUchar::SvecUchar() {}

inline SvecUchar::SvecUchar(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecUchar::SvecUchar(Uchar *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Uchar * SvecUchar::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecUchar::size() const
{
	return m_N;
}

inline Uchar &SvecUchar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Uchar &SvecUchar::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Uchar &SvecUchar::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecUchar::operator SvecUcharC() const {
	return *((SvecUcharC *)this);
}

inline void SvecUchar::set(Uchar *data) {
	m_p = data;
}

inline void SvecUchar::set(Long_I N) {
	m_N = N;
}

inline void SvecUchar::set(Uchar *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecUchar::next() {
	m_p += m_N;
}

inline void SvecUchar::last() {
	m_p -= m_N;
}

inline void SvecUchar::shift(Long_I N) {
	m_p += N;
}

inline void SvecUchar::set(const SvecUchar &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecUchar::~SvecUchar() {}

// common api for STL and SLISC
inline Long size(const SvecUchar &v) { return v.size(); }

inline Uchar *ptr(SvecUchar &v) { return v.p(); }

class SvecIntC
{
protected:
	const Int *m_p;
	Long m_N;
public:
	SvecIntC();
	explicit SvecIntC(Long_I N);
	SvecIntC(const Int *data, Long_I N);
	SvecIntC(const SvecIntC &v) = default; // copy constructor (shalow)

	SvecIntC &operator=(const SvecIntC &v) = default; // copy assignment (shalow)

	const Int* p() const;
	Long size() const;
	const Int &operator[](Long_I i) const;
	const Int &back() const;
	const Int &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Int *data);
	void set(Long_I N);
	void set(const Int *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecIntC();
};

inline SvecIntC::SvecIntC() {}

inline SvecIntC::SvecIntC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecIntC::SvecIntC(const Int *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Int * SvecIntC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecIntC::size() const
{
	return m_N;
}

inline const Int &SvecIntC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Int &SvecIntC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Int &SvecIntC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecIntC::set(const Int *data) {
	m_p = data;
}

inline void SvecIntC::set(Long_I N) {
	m_N = N;
}

inline void SvecIntC::set(const Int *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecIntC::next() {
	m_p += m_N;
}

inline void SvecIntC::last() {
	m_p -= m_N;
}

inline void SvecIntC::shift(Long_I N) {
	m_p += N;
}

inline void SvecIntC::set(const SvecIntC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecIntC::~SvecIntC() {}

// common api for STL and SLISC
inline Long size(const SvecIntC &v) { return v.size(); }

inline const Int *ptr(const SvecIntC &v) { return v.p(); }

class SvecInt
{
protected:
	Int *m_p;
	Long m_N;
public:
	SvecInt();
	explicit SvecInt(Long_I N);
	SvecInt(Int *data, Long_I N);
	SvecInt(const SvecInt &v) = default; // copy constructor (shalow)

	SvecInt &operator=(const SvecInt &v) = default; // copy assignment (shalow)

	Int* p() const;
	Long size() const;
	Int &operator[](Long_I i) const;
	Int &back() const;
	Int &back(Long_I i) const;

	operator SvecIntC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Int *data);
	void set(Long_I N);
	void set(Int *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecInt();
};

inline SvecInt::SvecInt() {}

inline SvecInt::SvecInt(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecInt::SvecInt(Int *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Int * SvecInt::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecInt::size() const
{
	return m_N;
}

inline Int &SvecInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Int &SvecInt::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Int &SvecInt::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecInt::operator SvecIntC() const {
	return *((SvecIntC *)this);
}

inline void SvecInt::set(Int *data) {
	m_p = data;
}

inline void SvecInt::set(Long_I N) {
	m_N = N;
}

inline void SvecInt::set(Int *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecInt::next() {
	m_p += m_N;
}

inline void SvecInt::last() {
	m_p -= m_N;
}

inline void SvecInt::shift(Long_I N) {
	m_p += N;
}

inline void SvecInt::set(const SvecInt &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecInt::~SvecInt() {}

// common api for STL and SLISC
inline Long size(const SvecInt &v) { return v.size(); }

inline Int *ptr(SvecInt &v) { return v.p(); }

class SvecLlongC
{
protected:
	const Llong *m_p;
	Long m_N;
public:
	SvecLlongC();
	explicit SvecLlongC(Long_I N);
	SvecLlongC(const Llong *data, Long_I N);
	SvecLlongC(const SvecLlongC &v) = default; // copy constructor (shalow)

	SvecLlongC &operator=(const SvecLlongC &v) = default; // copy assignment (shalow)

	const Llong* p() const;
	Long size() const;
	const Llong &operator[](Long_I i) const;
	const Llong &back() const;
	const Llong &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Llong *data);
	void set(Long_I N);
	void set(const Llong *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecLlongC();
};

inline SvecLlongC::SvecLlongC() {}

inline SvecLlongC::SvecLlongC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecLlongC::SvecLlongC(const Llong *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Llong * SvecLlongC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecLlongC::size() const
{
	return m_N;
}

inline const Llong &SvecLlongC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Llong &SvecLlongC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Llong &SvecLlongC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecLlongC::set(const Llong *data) {
	m_p = data;
}

inline void SvecLlongC::set(Long_I N) {
	m_N = N;
}

inline void SvecLlongC::set(const Llong *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecLlongC::next() {
	m_p += m_N;
}

inline void SvecLlongC::last() {
	m_p -= m_N;
}

inline void SvecLlongC::shift(Long_I N) {
	m_p += N;
}

inline void SvecLlongC::set(const SvecLlongC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLlongC::~SvecLlongC() {}

// common api for STL and SLISC
inline Long size(const SvecLlongC &v) { return v.size(); }

inline const Llong *ptr(const SvecLlongC &v) { return v.p(); }

class SvecLlong
{
protected:
	Llong *m_p;
	Long m_N;
public:
	SvecLlong();
	explicit SvecLlong(Long_I N);
	SvecLlong(Llong *data, Long_I N);
	SvecLlong(const SvecLlong &v) = default; // copy constructor (shalow)

	SvecLlong &operator=(const SvecLlong &v) = default; // copy assignment (shalow)

	Llong* p() const;
	Long size() const;
	Llong &operator[](Long_I i) const;
	Llong &back() const;
	Llong &back(Long_I i) const;

	operator SvecLlongC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Llong *data);
	void set(Long_I N);
	void set(Llong *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecLlong();
};

inline SvecLlong::SvecLlong() {}

inline SvecLlong::SvecLlong(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecLlong::SvecLlong(Llong *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Llong * SvecLlong::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecLlong::size() const
{
	return m_N;
}

inline Llong &SvecLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Llong &SvecLlong::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Llong &SvecLlong::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecLlong::operator SvecLlongC() const {
	return *((SvecLlongC *)this);
}

inline void SvecLlong::set(Llong *data) {
	m_p = data;
}

inline void SvecLlong::set(Long_I N) {
	m_N = N;
}

inline void SvecLlong::set(Llong *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecLlong::next() {
	m_p += m_N;
}

inline void SvecLlong::last() {
	m_p -= m_N;
}

inline void SvecLlong::shift(Long_I N) {
	m_p += N;
}

inline void SvecLlong::set(const SvecLlong &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLlong::~SvecLlong() {}

// common api for STL and SLISC
inline Long size(const SvecLlong &v) { return v.size(); }

inline Llong *ptr(SvecLlong &v) { return v.p(); }

class SvecFloatC
{
protected:
	const Float *m_p;
	Long m_N;
public:
	SvecFloatC();
	explicit SvecFloatC(Long_I N);
	SvecFloatC(const Float *data, Long_I N);
	SvecFloatC(const SvecFloatC &v) = default; // copy constructor (shalow)

	SvecFloatC &operator=(const SvecFloatC &v) = default; // copy assignment (shalow)

	const Float* p() const;
	Long size() const;
	const Float &operator[](Long_I i) const;
	const Float &back() const;
	const Float &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Float *data);
	void set(Long_I N);
	void set(const Float *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecFloatC();
};

inline SvecFloatC::SvecFloatC() {}

inline SvecFloatC::SvecFloatC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecFloatC::SvecFloatC(const Float *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Float * SvecFloatC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecFloatC::size() const
{
	return m_N;
}

inline const Float &SvecFloatC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Float &SvecFloatC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Float &SvecFloatC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecFloatC::set(const Float *data) {
	m_p = data;
}

inline void SvecFloatC::set(Long_I N) {
	m_N = N;
}

inline void SvecFloatC::set(const Float *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecFloatC::next() {
	m_p += m_N;
}

inline void SvecFloatC::last() {
	m_p -= m_N;
}

inline void SvecFloatC::shift(Long_I N) {
	m_p += N;
}

inline void SvecFloatC::set(const SvecFloatC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFloatC::~SvecFloatC() {}

// common api for STL and SLISC
inline Long size(const SvecFloatC &v) { return v.size(); }

inline const Float *ptr(const SvecFloatC &v) { return v.p(); }

class SvecFloat
{
protected:
	Float *m_p;
	Long m_N;
public:
	SvecFloat();
	explicit SvecFloat(Long_I N);
	SvecFloat(Float *data, Long_I N);
	SvecFloat(const SvecFloat &v) = default; // copy constructor (shalow)

	SvecFloat &operator=(const SvecFloat &v) = default; // copy assignment (shalow)

	Float* p() const;
	Long size() const;
	Float &operator[](Long_I i) const;
	Float &back() const;
	Float &back(Long_I i) const;

	operator SvecFloatC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Float *data);
	void set(Long_I N);
	void set(Float *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecFloat();
};

inline SvecFloat::SvecFloat() {}

inline SvecFloat::SvecFloat(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecFloat::SvecFloat(Float *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Float * SvecFloat::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecFloat::size() const
{
	return m_N;
}

inline Float &SvecFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Float &SvecFloat::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Float &SvecFloat::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecFloat::operator SvecFloatC() const {
	return *((SvecFloatC *)this);
}

inline void SvecFloat::set(Float *data) {
	m_p = data;
}

inline void SvecFloat::set(Long_I N) {
	m_N = N;
}

inline void SvecFloat::set(Float *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecFloat::next() {
	m_p += m_N;
}

inline void SvecFloat::last() {
	m_p -= m_N;
}

inline void SvecFloat::shift(Long_I N) {
	m_p += N;
}

inline void SvecFloat::set(const SvecFloat &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFloat::~SvecFloat() {}

// common api for STL and SLISC
inline Long size(const SvecFloat &v) { return v.size(); }

inline Float *ptr(SvecFloat &v) { return v.p(); }

class SvecDoubC
{
protected:
	const Doub *m_p;
	Long m_N;
public:
	SvecDoubC();
	explicit SvecDoubC(Long_I N);
	SvecDoubC(const Doub *data, Long_I N);
	SvecDoubC(const SvecDoubC &v) = default; // copy constructor (shalow)

	SvecDoubC &operator=(const SvecDoubC &v) = default; // copy assignment (shalow)

	const Doub* p() const;
	Long size() const;
	const Doub &operator[](Long_I i) const;
	const Doub &back() const;
	const Doub &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Doub *data);
	void set(Long_I N);
	void set(const Doub *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecDoubC();
};

inline SvecDoubC::SvecDoubC() {}

inline SvecDoubC::SvecDoubC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecDoubC::SvecDoubC(const Doub *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Doub * SvecDoubC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecDoubC::size() const
{
	return m_N;
}

inline const Doub &SvecDoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Doub &SvecDoubC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Doub &SvecDoubC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecDoubC::set(const Doub *data) {
	m_p = data;
}

inline void SvecDoubC::set(Long_I N) {
	m_N = N;
}

inline void SvecDoubC::set(const Doub *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecDoubC::next() {
	m_p += m_N;
}

inline void SvecDoubC::last() {
	m_p -= m_N;
}

inline void SvecDoubC::shift(Long_I N) {
	m_p += N;
}

inline void SvecDoubC::set(const SvecDoubC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecDoubC::~SvecDoubC() {}

// common api for STL and SLISC
inline Long size(const SvecDoubC &v) { return v.size(); }

inline const Doub *ptr(const SvecDoubC &v) { return v.p(); }

class SvecDoub
{
protected:
	Doub *m_p;
	Long m_N;
public:
	SvecDoub();
	explicit SvecDoub(Long_I N);
	SvecDoub(Doub *data, Long_I N);
	SvecDoub(const SvecDoub &v) = default; // copy constructor (shalow)

	SvecDoub &operator=(const SvecDoub &v) = default; // copy assignment (shalow)

	Doub* p() const;
	Long size() const;
	Doub &operator[](Long_I i) const;
	Doub &back() const;
	Doub &back(Long_I i) const;

	operator SvecDoubC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Doub *data);
	void set(Long_I N);
	void set(Doub *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecDoub();
};

inline SvecDoub::SvecDoub() {}

inline SvecDoub::SvecDoub(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecDoub::SvecDoub(Doub *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Doub * SvecDoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecDoub::size() const
{
	return m_N;
}

inline Doub &SvecDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Doub &SvecDoub::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Doub &SvecDoub::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecDoub::operator SvecDoubC() const {
	return *((SvecDoubC *)this);
}

inline void SvecDoub::set(Doub *data) {
	m_p = data;
}

inline void SvecDoub::set(Long_I N) {
	m_N = N;
}

inline void SvecDoub::set(Doub *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecDoub::next() {
	m_p += m_N;
}

inline void SvecDoub::last() {
	m_p -= m_N;
}

inline void SvecDoub::shift(Long_I N) {
	m_p += N;
}

inline void SvecDoub::set(const SvecDoub &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecDoub::~SvecDoub() {}

// common api for STL and SLISC
inline Long size(const SvecDoub &v) { return v.size(); }

inline Doub *ptr(SvecDoub &v) { return v.p(); }

class SvecLdoubC
{
protected:
	const Ldoub *m_p;
	Long m_N;
public:
	SvecLdoubC();
	explicit SvecLdoubC(Long_I N);
	SvecLdoubC(const Ldoub *data, Long_I N);
	SvecLdoubC(const SvecLdoubC &v) = default; // copy constructor (shalow)

	SvecLdoubC &operator=(const SvecLdoubC &v) = default; // copy assignment (shalow)

	const Ldoub* p() const;
	Long size() const;
	const Ldoub &operator[](Long_I i) const;
	const Ldoub &back() const;
	const Ldoub &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Ldoub *data);
	void set(Long_I N);
	void set(const Ldoub *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecLdoubC();
};

inline SvecLdoubC::SvecLdoubC() {}

inline SvecLdoubC::SvecLdoubC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecLdoubC::SvecLdoubC(const Ldoub *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Ldoub * SvecLdoubC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecLdoubC::size() const
{
	return m_N;
}

inline const Ldoub &SvecLdoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Ldoub &SvecLdoubC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Ldoub &SvecLdoubC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecLdoubC::set(const Ldoub *data) {
	m_p = data;
}

inline void SvecLdoubC::set(Long_I N) {
	m_N = N;
}

inline void SvecLdoubC::set(const Ldoub *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecLdoubC::next() {
	m_p += m_N;
}

inline void SvecLdoubC::last() {
	m_p -= m_N;
}

inline void SvecLdoubC::shift(Long_I N) {
	m_p += N;
}

inline void SvecLdoubC::set(const SvecLdoubC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLdoubC::~SvecLdoubC() {}

// common api for STL and SLISC
inline Long size(const SvecLdoubC &v) { return v.size(); }

inline const Ldoub *ptr(const SvecLdoubC &v) { return v.p(); }

class SvecLdoub
{
protected:
	Ldoub *m_p;
	Long m_N;
public:
	SvecLdoub();
	explicit SvecLdoub(Long_I N);
	SvecLdoub(Ldoub *data, Long_I N);
	SvecLdoub(const SvecLdoub &v) = default; // copy constructor (shalow)

	SvecLdoub &operator=(const SvecLdoub &v) = default; // copy assignment (shalow)

	Ldoub* p() const;
	Long size() const;
	Ldoub &operator[](Long_I i) const;
	Ldoub &back() const;
	Ldoub &back(Long_I i) const;

	operator SvecLdoubC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Ldoub *data);
	void set(Long_I N);
	void set(Ldoub *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecLdoub();
};

inline SvecLdoub::SvecLdoub() {}

inline SvecLdoub::SvecLdoub(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecLdoub::SvecLdoub(Ldoub *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Ldoub * SvecLdoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecLdoub::size() const
{
	return m_N;
}

inline Ldoub &SvecLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Ldoub &SvecLdoub::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Ldoub &SvecLdoub::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecLdoub::operator SvecLdoubC() const {
	return *((SvecLdoubC *)this);
}

inline void SvecLdoub::set(Ldoub *data) {
	m_p = data;
}

inline void SvecLdoub::set(Long_I N) {
	m_N = N;
}

inline void SvecLdoub::set(Ldoub *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecLdoub::next() {
	m_p += m_N;
}

inline void SvecLdoub::last() {
	m_p -= m_N;
}

inline void SvecLdoub::shift(Long_I N) {
	m_p += N;
}

inline void SvecLdoub::set(const SvecLdoub &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLdoub::~SvecLdoub() {}

// common api for STL and SLISC
inline Long size(const SvecLdoub &v) { return v.size(); }

inline Ldoub *ptr(SvecLdoub &v) { return v.p(); }



class SvecFcompC
{
protected:
	const Fcomp *m_p;
	Long m_N;
public:
	SvecFcompC();
	explicit SvecFcompC(Long_I N);
	SvecFcompC(const Fcomp *data, Long_I N);
	SvecFcompC(const SvecFcompC &v) = default; // copy constructor (shalow)

	SvecFcompC &operator=(const SvecFcompC &v) = default; // copy assignment (shalow)

	const Fcomp* p() const;
	Long size() const;
	const Fcomp &operator[](Long_I i) const;
	const Fcomp &back() const;
	const Fcomp &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Fcomp *data);
	void set(Long_I N);
	void set(const Fcomp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecFcompC();
};

inline SvecFcompC::SvecFcompC() {}

inline SvecFcompC::SvecFcompC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecFcompC::SvecFcompC(const Fcomp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Fcomp * SvecFcompC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecFcompC::size() const
{
	return m_N;
}

inline const Fcomp &SvecFcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Fcomp &SvecFcompC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Fcomp &SvecFcompC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecFcompC::set(const Fcomp *data) {
	m_p = data;
}

inline void SvecFcompC::set(Long_I N) {
	m_N = N;
}

inline void SvecFcompC::set(const Fcomp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecFcompC::next() {
	m_p += m_N;
}

inline void SvecFcompC::last() {
	m_p -= m_N;
}

inline void SvecFcompC::shift(Long_I N) {
	m_p += N;
}

inline void SvecFcompC::set(const SvecFcompC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFcompC::~SvecFcompC() {}

// common api for STL and SLISC
inline Long size(const SvecFcompC &v) { return v.size(); }

inline const Fcomp *ptr(const SvecFcompC &v) { return v.p(); }

class SvecFcomp
{
protected:
	Fcomp *m_p;
	Long m_N;
public:
	SvecFcomp();
	explicit SvecFcomp(Long_I N);
	SvecFcomp(Fcomp *data, Long_I N);
	SvecFcomp(const SvecFcomp &v) = default; // copy constructor (shalow)

	SvecFcomp &operator=(const SvecFcomp &v) = default; // copy assignment (shalow)

	Fcomp* p() const;
	Long size() const;
	Fcomp &operator[](Long_I i) const;
	Fcomp &back() const;
	Fcomp &back(Long_I i) const;

	operator SvecFcompC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Fcomp *data);
	void set(Long_I N);
	void set(Fcomp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecFcomp();
};

inline SvecFcomp::SvecFcomp() {}

inline SvecFcomp::SvecFcomp(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecFcomp::SvecFcomp(Fcomp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Fcomp * SvecFcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecFcomp::size() const
{
	return m_N;
}

inline Fcomp &SvecFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Fcomp &SvecFcomp::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Fcomp &SvecFcomp::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecFcomp::operator SvecFcompC() const {
	return *((SvecFcompC *)this);
}

inline void SvecFcomp::set(Fcomp *data) {
	m_p = data;
}

inline void SvecFcomp::set(Long_I N) {
	m_N = N;
}

inline void SvecFcomp::set(Fcomp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecFcomp::next() {
	m_p += m_N;
}

inline void SvecFcomp::last() {
	m_p -= m_N;
}

inline void SvecFcomp::shift(Long_I N) {
	m_p += N;
}

inline void SvecFcomp::set(const SvecFcomp &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFcomp::~SvecFcomp() {}

// common api for STL and SLISC
inline Long size(const SvecFcomp &v) { return v.size(); }

inline Fcomp *ptr(SvecFcomp &v) { return v.p(); }

class SvecCompC
{
protected:
	const Comp *m_p;
	Long m_N;
public:
	SvecCompC();
	explicit SvecCompC(Long_I N);
	SvecCompC(const Comp *data, Long_I N);
	SvecCompC(const SvecCompC &v) = default; // copy constructor (shalow)

	SvecCompC &operator=(const SvecCompC &v) = default; // copy assignment (shalow)

	const Comp* p() const;
	Long size() const;
	const Comp &operator[](Long_I i) const;
	const Comp &back() const;
	const Comp &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Comp *data);
	void set(Long_I N);
	void set(const Comp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecCompC();
};

inline SvecCompC::SvecCompC() {}

inline SvecCompC::SvecCompC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecCompC::SvecCompC(const Comp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Comp * SvecCompC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecCompC::size() const
{
	return m_N;
}

inline const Comp &SvecCompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Comp &SvecCompC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Comp &SvecCompC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecCompC::set(const Comp *data) {
	m_p = data;
}

inline void SvecCompC::set(Long_I N) {
	m_N = N;
}

inline void SvecCompC::set(const Comp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecCompC::next() {
	m_p += m_N;
}

inline void SvecCompC::last() {
	m_p -= m_N;
}

inline void SvecCompC::shift(Long_I N) {
	m_p += N;
}

inline void SvecCompC::set(const SvecCompC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecCompC::~SvecCompC() {}

// common api for STL and SLISC
inline Long size(const SvecCompC &v) { return v.size(); }

inline const Comp *ptr(const SvecCompC &v) { return v.p(); }

class SvecComp
{
protected:
	Comp *m_p;
	Long m_N;
public:
	SvecComp();
	explicit SvecComp(Long_I N);
	SvecComp(Comp *data, Long_I N);
	SvecComp(const SvecComp &v) = default; // copy constructor (shalow)

	SvecComp &operator=(const SvecComp &v) = default; // copy assignment (shalow)

	Comp* p() const;
	Long size() const;
	Comp &operator[](Long_I i) const;
	Comp &back() const;
	Comp &back(Long_I i) const;

	operator SvecCompC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Comp *data);
	void set(Long_I N);
	void set(Comp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecComp();
};

inline SvecComp::SvecComp() {}

inline SvecComp::SvecComp(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecComp::SvecComp(Comp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Comp * SvecComp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecComp::size() const
{
	return m_N;
}

inline Comp &SvecComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Comp &SvecComp::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Comp &SvecComp::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecComp::operator SvecCompC() const {
	return *((SvecCompC *)this);
}

inline void SvecComp::set(Comp *data) {
	m_p = data;
}

inline void SvecComp::set(Long_I N) {
	m_N = N;
}

inline void SvecComp::set(Comp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecComp::next() {
	m_p += m_N;
}

inline void SvecComp::last() {
	m_p -= m_N;
}

inline void SvecComp::shift(Long_I N) {
	m_p += N;
}

inline void SvecComp::set(const SvecComp &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecComp::~SvecComp() {}

// common api for STL and SLISC
inline Long size(const SvecComp &v) { return v.size(); }

inline Comp *ptr(SvecComp &v) { return v.p(); }

class SvecLcompC
{
protected:
	const Lcomp *m_p;
	Long m_N;
public:
	SvecLcompC();
	explicit SvecLcompC(Long_I N);
	SvecLcompC(const Lcomp *data, Long_I N);
	SvecLcompC(const SvecLcompC &v) = default; // copy constructor (shalow)

	SvecLcompC &operator=(const SvecLcompC &v) = default; // copy assignment (shalow)

	const Lcomp* p() const;
	Long size() const;
	const Lcomp &operator[](Long_I i) const;
	const Lcomp &back() const;
	const Lcomp &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Lcomp *data);
	void set(Long_I N);
	void set(const Lcomp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecLcompC();
};

inline SvecLcompC::SvecLcompC() {}

inline SvecLcompC::SvecLcompC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecLcompC::SvecLcompC(const Lcomp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Lcomp * SvecLcompC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecLcompC::size() const
{
	return m_N;
}

inline const Lcomp &SvecLcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Lcomp &SvecLcompC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Lcomp &SvecLcompC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecLcompC::set(const Lcomp *data) {
	m_p = data;
}

inline void SvecLcompC::set(Long_I N) {
	m_N = N;
}

inline void SvecLcompC::set(const Lcomp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecLcompC::next() {
	m_p += m_N;
}

inline void SvecLcompC::last() {
	m_p -= m_N;
}

inline void SvecLcompC::shift(Long_I N) {
	m_p += N;
}

inline void SvecLcompC::set(const SvecLcompC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLcompC::~SvecLcompC() {}

// common api for STL and SLISC
inline Long size(const SvecLcompC &v) { return v.size(); }

inline const Lcomp *ptr(const SvecLcompC &v) { return v.p(); }

class SvecLcomp
{
protected:
	Lcomp *m_p;
	Long m_N;
public:
	SvecLcomp();
	explicit SvecLcomp(Long_I N);
	SvecLcomp(Lcomp *data, Long_I N);
	SvecLcomp(const SvecLcomp &v) = default; // copy constructor (shalow)

	SvecLcomp &operator=(const SvecLcomp &v) = default; // copy assignment (shalow)

	Lcomp* p() const;
	Long size() const;
	Lcomp &operator[](Long_I i) const;
	Lcomp &back() const;
	Lcomp &back(Long_I i) const;

	operator SvecLcompC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Lcomp *data);
	void set(Long_I N);
	void set(Lcomp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecLcomp();
};

inline SvecLcomp::SvecLcomp() {}

inline SvecLcomp::SvecLcomp(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecLcomp::SvecLcomp(Lcomp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Lcomp * SvecLcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecLcomp::size() const
{
	return m_N;
}

inline Lcomp &SvecLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Lcomp &SvecLcomp::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Lcomp &SvecLcomp::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecLcomp::operator SvecLcompC() const {
	return *((SvecLcompC *)this);
}

inline void SvecLcomp::set(Lcomp *data) {
	m_p = data;
}

inline void SvecLcomp::set(Long_I N) {
	m_N = N;
}

inline void SvecLcomp::set(Lcomp *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecLcomp::next() {
	m_p += m_N;
}

inline void SvecLcomp::last() {
	m_p -= m_N;
}

inline void SvecLcomp::shift(Long_I N) {
	m_p += N;
}

inline void SvecLcomp::set(const SvecLcomp &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLcomp::~SvecLcomp() {}

// common api for STL and SLISC
inline Long size(const SvecLcomp &v) { return v.size(); }

inline Lcomp *ptr(SvecLcomp &v) { return v.p(); }



class SvecFimagC
{
protected:
	const Fimag *m_p;
	Long m_N;
public:
	SvecFimagC();
	explicit SvecFimagC(Long_I N);
	SvecFimagC(const Fimag *data, Long_I N);
	SvecFimagC(const SvecFimagC &v) = default; // copy constructor (shalow)

	SvecFimagC &operator=(const SvecFimagC &v) = default; // copy assignment (shalow)

	const Fimag* p() const;
	Long size() const;
	const Fimag &operator[](Long_I i) const;
	const Fimag &back() const;
	const Fimag &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Fimag *data);
	void set(Long_I N);
	void set(const Fimag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecFimagC();
};

inline SvecFimagC::SvecFimagC() {}

inline SvecFimagC::SvecFimagC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecFimagC::SvecFimagC(const Fimag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Fimag * SvecFimagC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecFimagC::size() const
{
	return m_N;
}

inline const Fimag &SvecFimagC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Fimag &SvecFimagC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Fimag &SvecFimagC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecFimagC::set(const Fimag *data) {
	m_p = data;
}

inline void SvecFimagC::set(Long_I N) {
	m_N = N;
}

inline void SvecFimagC::set(const Fimag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecFimagC::next() {
	m_p += m_N;
}

inline void SvecFimagC::last() {
	m_p -= m_N;
}

inline void SvecFimagC::shift(Long_I N) {
	m_p += N;
}

inline void SvecFimagC::set(const SvecFimagC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFimagC::~SvecFimagC() {}

// common api for STL and SLISC
inline Long size(const SvecFimagC &v) { return v.size(); }

inline const Fimag *ptr(const SvecFimagC &v) { return v.p(); }

class SvecFimag
{
protected:
	Fimag *m_p;
	Long m_N;
public:
	SvecFimag();
	explicit SvecFimag(Long_I N);
	SvecFimag(Fimag *data, Long_I N);
	SvecFimag(const SvecFimag &v) = default; // copy constructor (shalow)

	SvecFimag &operator=(const SvecFimag &v) = default; // copy assignment (shalow)

	Fimag* p() const;
	Long size() const;
	Fimag &operator[](Long_I i) const;
	Fimag &back() const;
	Fimag &back(Long_I i) const;

	operator SvecFimagC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Fimag *data);
	void set(Long_I N);
	void set(Fimag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecFimag();
};

inline SvecFimag::SvecFimag() {}

inline SvecFimag::SvecFimag(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecFimag::SvecFimag(Fimag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Fimag * SvecFimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecFimag::size() const
{
	return m_N;
}

inline Fimag &SvecFimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Fimag &SvecFimag::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Fimag &SvecFimag::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecFimag::operator SvecFimagC() const {
	return *((SvecFimagC *)this);
}

inline void SvecFimag::set(Fimag *data) {
	m_p = data;
}

inline void SvecFimag::set(Long_I N) {
	m_N = N;
}

inline void SvecFimag::set(Fimag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecFimag::next() {
	m_p += m_N;
}

inline void SvecFimag::last() {
	m_p -= m_N;
}

inline void SvecFimag::shift(Long_I N) {
	m_p += N;
}

inline void SvecFimag::set(const SvecFimag &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFimag::~SvecFimag() {}

// common api for STL and SLISC
inline Long size(const SvecFimag &v) { return v.size(); }

inline Fimag *ptr(SvecFimag &v) { return v.p(); }

class SvecImagC
{
protected:
	const Imag *m_p;
	Long m_N;
public:
	SvecImagC();
	explicit SvecImagC(Long_I N);
	SvecImagC(const Imag *data, Long_I N);
	SvecImagC(const SvecImagC &v) = default; // copy constructor (shalow)

	SvecImagC &operator=(const SvecImagC &v) = default; // copy assignment (shalow)

	const Imag* p() const;
	Long size() const;
	const Imag &operator[](Long_I i) const;
	const Imag &back() const;
	const Imag &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Imag *data);
	void set(Long_I N);
	void set(const Imag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecImagC();
};

inline SvecImagC::SvecImagC() {}

inline SvecImagC::SvecImagC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecImagC::SvecImagC(const Imag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Imag * SvecImagC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecImagC::size() const
{
	return m_N;
}

inline const Imag &SvecImagC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Imag &SvecImagC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Imag &SvecImagC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecImagC::set(const Imag *data) {
	m_p = data;
}

inline void SvecImagC::set(Long_I N) {
	m_N = N;
}

inline void SvecImagC::set(const Imag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecImagC::next() {
	m_p += m_N;
}

inline void SvecImagC::last() {
	m_p -= m_N;
}

inline void SvecImagC::shift(Long_I N) {
	m_p += N;
}

inline void SvecImagC::set(const SvecImagC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecImagC::~SvecImagC() {}

// common api for STL and SLISC
inline Long size(const SvecImagC &v) { return v.size(); }

inline const Imag *ptr(const SvecImagC &v) { return v.p(); }

class SvecImag
{
protected:
	Imag *m_p;
	Long m_N;
public:
	SvecImag();
	explicit SvecImag(Long_I N);
	SvecImag(Imag *data, Long_I N);
	SvecImag(const SvecImag &v) = default; // copy constructor (shalow)

	SvecImag &operator=(const SvecImag &v) = default; // copy assignment (shalow)

	Imag* p() const;
	Long size() const;
	Imag &operator[](Long_I i) const;
	Imag &back() const;
	Imag &back(Long_I i) const;

	operator SvecImagC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Imag *data);
	void set(Long_I N);
	void set(Imag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecImag();
};

inline SvecImag::SvecImag() {}

inline SvecImag::SvecImag(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecImag::SvecImag(Imag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Imag * SvecImag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecImag::size() const
{
	return m_N;
}

inline Imag &SvecImag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Imag &SvecImag::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Imag &SvecImag::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecImag::operator SvecImagC() const {
	return *((SvecImagC *)this);
}

inline void SvecImag::set(Imag *data) {
	m_p = data;
}

inline void SvecImag::set(Long_I N) {
	m_N = N;
}

inline void SvecImag::set(Imag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecImag::next() {
	m_p += m_N;
}

inline void SvecImag::last() {
	m_p -= m_N;
}

inline void SvecImag::shift(Long_I N) {
	m_p += N;
}

inline void SvecImag::set(const SvecImag &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecImag::~SvecImag() {}

// common api for STL and SLISC
inline Long size(const SvecImag &v) { return v.size(); }

inline Imag *ptr(SvecImag &v) { return v.p(); }

class SvecLimagC
{
protected:
	const Limag *m_p;
	Long m_N;
public:
	SvecLimagC();
	explicit SvecLimagC(Long_I N);
	SvecLimagC(const Limag *data, Long_I N);
	SvecLimagC(const SvecLimagC &v) = default; // copy constructor (shalow)

	SvecLimagC &operator=(const SvecLimagC &v) = default; // copy assignment (shalow)

	const Limag* p() const;
	Long size() const;
	const Limag &operator[](Long_I i) const;
	const Limag &back() const;
	const Limag &back(Long_I i) const;


	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Limag *data);
	void set(Long_I N);
	void set(const Limag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecLimagC();
};

inline SvecLimagC::SvecLimagC() {}

inline SvecLimagC::SvecLimagC(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecLimagC::SvecLimagC(const Limag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Limag * SvecLimagC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecLimagC::size() const
{
	return m_N;
}

inline const Limag &SvecLimagC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Limag &SvecLimagC::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Limag &SvecLimagC::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvecLimagC::set(const Limag *data) {
	m_p = data;
}

inline void SvecLimagC::set(Long_I N) {
	m_N = N;
}

inline void SvecLimagC::set(const Limag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecLimagC::next() {
	m_p += m_N;
}

inline void SvecLimagC::last() {
	m_p -= m_N;
}

inline void SvecLimagC::shift(Long_I N) {
	m_p += N;
}

inline void SvecLimagC::set(const SvecLimagC &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLimagC::~SvecLimagC() {}

// common api for STL and SLISC
inline Long size(const SvecLimagC &v) { return v.size(); }

inline const Limag *ptr(const SvecLimagC &v) { return v.p(); }

class SvecLimag
{
protected:
	Limag *m_p;
	Long m_N;
public:
	SvecLimag();
	explicit SvecLimag(Long_I N);
	SvecLimag(Limag *data, Long_I N);
	SvecLimag(const SvecLimag &v) = default; // copy constructor (shalow)

	SvecLimag &operator=(const SvecLimag &v) = default; // copy assignment (shalow)

	Limag* p() const;
	Long size() const;
	Limag &operator[](Long_I i) const;
	Limag &back() const;
	Limag &back(Long_I i) const;

	operator SvecLimagC() const;

	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(Limag *data);
	void set(Long_I N);
	void set(Limag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvecLimag();
};

inline SvecLimag::SvecLimag() {}

inline SvecLimag::SvecLimag(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvecLimag::SvecLimag(Limag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline Limag * SvecLimag::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvecLimag::size() const
{
	return m_N;
}

inline Limag &SvecLimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline Limag &SvecLimag::back() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use back() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline Limag &SvecLimag::back(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
		SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}

inline SvecLimag::operator SvecLimagC() const {
	return *((SvecLimagC *)this);
}

inline void SvecLimag::set(Limag *data) {
	m_p = data;
}

inline void SvecLimag::set(Long_I N) {
	m_N = N;
}

inline void SvecLimag::set(Limag *data, Long_I N) {
	m_p = data; m_N = N;
}

inline void SvecLimag::next() {
	m_p += m_N;
}

inline void SvecLimag::last() {
	m_p -= m_N;
}

inline void SvecLimag::shift(Long_I N) {
	m_p += N;
}

inline void SvecLimag::set(const SvecLimag &sli) {
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLimag::~SvecLimag() {}

// common api for STL and SLISC
inline Long size(const SvecLimag &v) { return v.size(); }

inline Limag *ptr(SvecLimag &v) { return v.p(); }




#ifdef SLS_USE_INT_AS_LONG
typedef SvecInt SvecLong;
typedef SvecIntC SvecLongC;
#else
typedef SvecLlong SvecLong;
typedef SvecLlongC SvecLongC;
#endif

} // namespace slisc
