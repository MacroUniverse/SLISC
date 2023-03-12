#pragma once
#include "global.h"
#include "Imag.h"

// this class is not memory safe!
// "_c" means lower level const

namespace slisc {
class SvbaseChar_c
{
protected:
	const Char *m_p;
	Long m_N;
public:
	SvbaseChar_c();
	explicit SvbaseChar_c(Long_I N);
	SvbaseChar_c(const Char *data, Long_I N); // unsafe
	const Char* p() const;
	Long size() const;
	SvbaseChar_c &operator=(const SvbaseChar_c &rhs) = delete;
	const Char &operator[](Long_I i) const;
	const Char &end() const;
	const Char &end(Long_I i) const;
	void set(const SvbaseChar_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Char *data);
	void set(Long_I N);
	void set(const Char *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseChar_c();
};

inline SvbaseChar_c::SvbaseChar_c() {}

inline SvbaseChar_c::SvbaseChar_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseChar_c::SvbaseChar_c(const Char *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Char * SvbaseChar_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseChar_c::size() const
{
	return m_N;
}

inline const Char &SvbaseChar_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Char &SvbaseChar_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Char &SvbaseChar_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseChar_c::set(const Char *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseChar_c::set(const Char *data)
{
	m_p = data;
}

inline void SvbaseChar_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseChar_c::next()
{
	m_p += m_N;
}

inline void SvbaseChar_c::last()
{
	m_p -= m_N;
}

inline void SvbaseChar_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseChar_c::set(const SvbaseChar_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseChar_c::~SvbaseChar_c() {}

class SvbaseChar
{
protected:
	Char *m_p;
	Long m_N;
public:
	SvbaseChar();
	explicit SvbaseChar(Long_I N);
	SvbaseChar(Char *data, Long_I N); // unsafe
	Char* p() const;
	Long size() const;
	SvbaseChar &operator=(const SvbaseChar &rhs) = delete;
	Char &operator[](Long_I i) const;
	Char &end() const;
	Char &end(Long_I i) const;
	operator SvbaseChar_c() const;
	void set(const SvbaseChar &sli);
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

inline SvbaseChar::operator SvbaseChar_c() const
{
	return *((SvbaseChar_c *)this);
}

inline void SvbaseChar::set(Char *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseChar::set(Char *data)
{
	m_p = data;
}

inline void SvbaseChar::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseChar::next()
{
	m_p += m_N;
}

inline void SvbaseChar::last()
{
	m_p -= m_N;
}

inline void SvbaseChar::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseChar::set(const SvbaseChar &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseChar::~SvbaseChar() {}

class SvbaseUchar_c
{
protected:
	const Uchar *m_p;
	Long m_N;
public:
	SvbaseUchar_c();
	explicit SvbaseUchar_c(Long_I N);
	SvbaseUchar_c(const Uchar *data, Long_I N); // unsafe
	const Uchar* p() const;
	Long size() const;
	SvbaseUchar_c &operator=(const SvbaseUchar_c &rhs) = delete;
	const Uchar &operator[](Long_I i) const;
	const Uchar &end() const;
	const Uchar &end(Long_I i) const;
	void set(const SvbaseUchar_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Uchar *data);
	void set(Long_I N);
	void set(const Uchar *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseUchar_c();
};

inline SvbaseUchar_c::SvbaseUchar_c() {}

inline SvbaseUchar_c::SvbaseUchar_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseUchar_c::SvbaseUchar_c(const Uchar *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Uchar * SvbaseUchar_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseUchar_c::size() const
{
	return m_N;
}

inline const Uchar &SvbaseUchar_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Uchar &SvbaseUchar_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Uchar &SvbaseUchar_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseUchar_c::set(const Uchar *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseUchar_c::set(const Uchar *data)
{
	m_p = data;
}

inline void SvbaseUchar_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseUchar_c::next()
{
	m_p += m_N;
}

inline void SvbaseUchar_c::last()
{
	m_p -= m_N;
}

inline void SvbaseUchar_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseUchar_c::set(const SvbaseUchar_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseUchar_c::~SvbaseUchar_c() {}

class SvbaseUchar
{
protected:
	Uchar *m_p;
	Long m_N;
public:
	SvbaseUchar();
	explicit SvbaseUchar(Long_I N);
	SvbaseUchar(Uchar *data, Long_I N); // unsafe
	Uchar* p() const;
	Long size() const;
	SvbaseUchar &operator=(const SvbaseUchar &rhs) = delete;
	Uchar &operator[](Long_I i) const;
	Uchar &end() const;
	Uchar &end(Long_I i) const;
	operator SvbaseUchar_c() const;
	void set(const SvbaseUchar &sli);
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

inline SvbaseUchar::operator SvbaseUchar_c() const
{
	return *((SvbaseUchar_c *)this);
}

inline void SvbaseUchar::set(Uchar *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseUchar::set(Uchar *data)
{
	m_p = data;
}

inline void SvbaseUchar::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseUchar::next()
{
	m_p += m_N;
}

inline void SvbaseUchar::last()
{
	m_p -= m_N;
}

inline void SvbaseUchar::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseUchar::set(const SvbaseUchar &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseUchar::~SvbaseUchar() {}

class SvbaseInt_c
{
protected:
	const Int *m_p;
	Long m_N;
public:
	SvbaseInt_c();
	explicit SvbaseInt_c(Long_I N);
	SvbaseInt_c(const Int *data, Long_I N); // unsafe
	const Int* p() const;
	Long size() const;
	SvbaseInt_c &operator=(const SvbaseInt_c &rhs) = delete;
	const Int &operator[](Long_I i) const;
	const Int &end() const;
	const Int &end(Long_I i) const;
	void set(const SvbaseInt_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Int *data);
	void set(Long_I N);
	void set(const Int *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseInt_c();
};

inline SvbaseInt_c::SvbaseInt_c() {}

inline SvbaseInt_c::SvbaseInt_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseInt_c::SvbaseInt_c(const Int *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Int * SvbaseInt_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseInt_c::size() const
{
	return m_N;
}

inline const Int &SvbaseInt_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Int &SvbaseInt_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Int &SvbaseInt_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseInt_c::set(const Int *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseInt_c::set(const Int *data)
{
	m_p = data;
}

inline void SvbaseInt_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseInt_c::next()
{
	m_p += m_N;
}

inline void SvbaseInt_c::last()
{
	m_p -= m_N;
}

inline void SvbaseInt_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseInt_c::set(const SvbaseInt_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseInt_c::~SvbaseInt_c() {}

class SvbaseInt
{
protected:
	Int *m_p;
	Long m_N;
public:
	SvbaseInt();
	explicit SvbaseInt(Long_I N);
	SvbaseInt(Int *data, Long_I N); // unsafe
	Int* p() const;
	Long size() const;
	SvbaseInt &operator=(const SvbaseInt &rhs) = delete;
	Int &operator[](Long_I i) const;
	Int &end() const;
	Int &end(Long_I i) const;
	operator SvbaseInt_c() const;
	void set(const SvbaseInt &sli);
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

inline SvbaseInt::operator SvbaseInt_c() const
{
	return *((SvbaseInt_c *)this);
}

inline void SvbaseInt::set(Int *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseInt::set(Int *data)
{
	m_p = data;
}

inline void SvbaseInt::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseInt::next()
{
	m_p += m_N;
}

inline void SvbaseInt::last()
{
	m_p -= m_N;
}

inline void SvbaseInt::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseInt::set(const SvbaseInt &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseInt::~SvbaseInt() {}

class SvbaseLlong_c
{
protected:
	const Llong *m_p;
	Long m_N;
public:
	SvbaseLlong_c();
	explicit SvbaseLlong_c(Long_I N);
	SvbaseLlong_c(const Llong *data, Long_I N); // unsafe
	const Llong* p() const;
	Long size() const;
	SvbaseLlong_c &operator=(const SvbaseLlong_c &rhs) = delete;
	const Llong &operator[](Long_I i) const;
	const Llong &end() const;
	const Llong &end(Long_I i) const;
	void set(const SvbaseLlong_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Llong *data);
	void set(Long_I N);
	void set(const Llong *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLlong_c();
};

inline SvbaseLlong_c::SvbaseLlong_c() {}

inline SvbaseLlong_c::SvbaseLlong_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLlong_c::SvbaseLlong_c(const Llong *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Llong * SvbaseLlong_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLlong_c::size() const
{
	return m_N;
}

inline const Llong &SvbaseLlong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Llong &SvbaseLlong_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Llong &SvbaseLlong_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseLlong_c::set(const Llong *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLlong_c::set(const Llong *data)
{
	m_p = data;
}

inline void SvbaseLlong_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLlong_c::next()
{
	m_p += m_N;
}

inline void SvbaseLlong_c::last()
{
	m_p -= m_N;
}

inline void SvbaseLlong_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLlong_c::set(const SvbaseLlong_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLlong_c::~SvbaseLlong_c() {}

class SvbaseLlong
{
protected:
	Llong *m_p;
	Long m_N;
public:
	SvbaseLlong();
	explicit SvbaseLlong(Long_I N);
	SvbaseLlong(Llong *data, Long_I N); // unsafe
	Llong* p() const;
	Long size() const;
	SvbaseLlong &operator=(const SvbaseLlong &rhs) = delete;
	Llong &operator[](Long_I i) const;
	Llong &end() const;
	Llong &end(Long_I i) const;
	operator SvbaseLlong_c() const;
	void set(const SvbaseLlong &sli);
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

inline SvbaseLlong::operator SvbaseLlong_c() const
{
	return *((SvbaseLlong_c *)this);
}

inline void SvbaseLlong::set(Llong *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLlong::set(Llong *data)
{
	m_p = data;
}

inline void SvbaseLlong::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLlong::next()
{
	m_p += m_N;
}

inline void SvbaseLlong::last()
{
	m_p -= m_N;
}

inline void SvbaseLlong::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLlong::set(const SvbaseLlong &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLlong::~SvbaseLlong() {}

class SvbaseFloat_c
{
protected:
	const Float *m_p;
	Long m_N;
public:
	SvbaseFloat_c();
	explicit SvbaseFloat_c(Long_I N);
	SvbaseFloat_c(const Float *data, Long_I N); // unsafe
	const Float* p() const;
	Long size() const;
	SvbaseFloat_c &operator=(const SvbaseFloat_c &rhs) = delete;
	const Float &operator[](Long_I i) const;
	const Float &end() const;
	const Float &end(Long_I i) const;
	void set(const SvbaseFloat_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Float *data);
	void set(Long_I N);
	void set(const Float *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseFloat_c();
};

inline SvbaseFloat_c::SvbaseFloat_c() {}

inline SvbaseFloat_c::SvbaseFloat_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseFloat_c::SvbaseFloat_c(const Float *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Float * SvbaseFloat_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseFloat_c::size() const
{
	return m_N;
}

inline const Float &SvbaseFloat_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Float &SvbaseFloat_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Float &SvbaseFloat_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseFloat_c::set(const Float *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseFloat_c::set(const Float *data)
{
	m_p = data;
}

inline void SvbaseFloat_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseFloat_c::next()
{
	m_p += m_N;
}

inline void SvbaseFloat_c::last()
{
	m_p -= m_N;
}

inline void SvbaseFloat_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseFloat_c::set(const SvbaseFloat_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseFloat_c::~SvbaseFloat_c() {}

class SvbaseFloat
{
protected:
	Float *m_p;
	Long m_N;
public:
	SvbaseFloat();
	explicit SvbaseFloat(Long_I N);
	SvbaseFloat(Float *data, Long_I N); // unsafe
	Float* p() const;
	Long size() const;
	SvbaseFloat &operator=(const SvbaseFloat &rhs) = delete;
	Float &operator[](Long_I i) const;
	Float &end() const;
	Float &end(Long_I i) const;
	operator SvbaseFloat_c() const;
	void set(const SvbaseFloat &sli);
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

inline SvbaseFloat::operator SvbaseFloat_c() const
{
	return *((SvbaseFloat_c *)this);
}

inline void SvbaseFloat::set(Float *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseFloat::set(Float *data)
{
	m_p = data;
}

inline void SvbaseFloat::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseFloat::next()
{
	m_p += m_N;
}

inline void SvbaseFloat::last()
{
	m_p -= m_N;
}

inline void SvbaseFloat::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseFloat::set(const SvbaseFloat &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseFloat::~SvbaseFloat() {}

class SvbaseDoub_c
{
protected:
	const Doub *m_p;
	Long m_N;
public:
	SvbaseDoub_c();
	explicit SvbaseDoub_c(Long_I N);
	SvbaseDoub_c(const Doub *data, Long_I N); // unsafe
	const Doub* p() const;
	Long size() const;
	SvbaseDoub_c &operator=(const SvbaseDoub_c &rhs) = delete;
	const Doub &operator[](Long_I i) const;
	const Doub &end() const;
	const Doub &end(Long_I i) const;
	void set(const SvbaseDoub_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Doub *data);
	void set(Long_I N);
	void set(const Doub *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseDoub_c();
};

inline SvbaseDoub_c::SvbaseDoub_c() {}

inline SvbaseDoub_c::SvbaseDoub_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseDoub_c::SvbaseDoub_c(const Doub *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Doub * SvbaseDoub_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseDoub_c::size() const
{
	return m_N;
}

inline const Doub &SvbaseDoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Doub &SvbaseDoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Doub &SvbaseDoub_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseDoub_c::set(const Doub *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseDoub_c::set(const Doub *data)
{
	m_p = data;
}

inline void SvbaseDoub_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseDoub_c::next()
{
	m_p += m_N;
}

inline void SvbaseDoub_c::last()
{
	m_p -= m_N;
}

inline void SvbaseDoub_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseDoub_c::set(const SvbaseDoub_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseDoub_c::~SvbaseDoub_c() {}

class SvbaseDoub
{
protected:
	Doub *m_p;
	Long m_N;
public:
	SvbaseDoub();
	explicit SvbaseDoub(Long_I N);
	SvbaseDoub(Doub *data, Long_I N); // unsafe
	Doub* p() const;
	Long size() const;
	SvbaseDoub &operator=(const SvbaseDoub &rhs) = delete;
	Doub &operator[](Long_I i) const;
	Doub &end() const;
	Doub &end(Long_I i) const;
	operator SvbaseDoub_c() const;
	void set(const SvbaseDoub &sli);
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

inline SvbaseDoub::operator SvbaseDoub_c() const
{
	return *((SvbaseDoub_c *)this);
}

inline void SvbaseDoub::set(Doub *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseDoub::set(Doub *data)
{
	m_p = data;
}

inline void SvbaseDoub::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseDoub::next()
{
	m_p += m_N;
}

inline void SvbaseDoub::last()
{
	m_p -= m_N;
}

inline void SvbaseDoub::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseDoub::set(const SvbaseDoub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseDoub::~SvbaseDoub() {}

class SvbaseLdoub_c
{
protected:
	const Ldoub *m_p;
	Long m_N;
public:
	SvbaseLdoub_c();
	explicit SvbaseLdoub_c(Long_I N);
	SvbaseLdoub_c(const Ldoub *data, Long_I N); // unsafe
	const Ldoub* p() const;
	Long size() const;
	SvbaseLdoub_c &operator=(const SvbaseLdoub_c &rhs) = delete;
	const Ldoub &operator[](Long_I i) const;
	const Ldoub &end() const;
	const Ldoub &end(Long_I i) const;
	void set(const SvbaseLdoub_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Ldoub *data);
	void set(Long_I N);
	void set(const Ldoub *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLdoub_c();
};

inline SvbaseLdoub_c::SvbaseLdoub_c() {}

inline SvbaseLdoub_c::SvbaseLdoub_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLdoub_c::SvbaseLdoub_c(const Ldoub *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Ldoub * SvbaseLdoub_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLdoub_c::size() const
{
	return m_N;
}

inline const Ldoub &SvbaseLdoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Ldoub &SvbaseLdoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Ldoub &SvbaseLdoub_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseLdoub_c::set(const Ldoub *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLdoub_c::set(const Ldoub *data)
{
	m_p = data;
}

inline void SvbaseLdoub_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLdoub_c::next()
{
	m_p += m_N;
}

inline void SvbaseLdoub_c::last()
{
	m_p -= m_N;
}

inline void SvbaseLdoub_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLdoub_c::set(const SvbaseLdoub_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLdoub_c::~SvbaseLdoub_c() {}

class SvbaseLdoub
{
protected:
	Ldoub *m_p;
	Long m_N;
public:
	SvbaseLdoub();
	explicit SvbaseLdoub(Long_I N);
	SvbaseLdoub(Ldoub *data, Long_I N); // unsafe
	Ldoub* p() const;
	Long size() const;
	SvbaseLdoub &operator=(const SvbaseLdoub &rhs) = delete;
	Ldoub &operator[](Long_I i) const;
	Ldoub &end() const;
	Ldoub &end(Long_I i) const;
	operator SvbaseLdoub_c() const;
	void set(const SvbaseLdoub &sli);
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

inline SvbaseLdoub::operator SvbaseLdoub_c() const
{
	return *((SvbaseLdoub_c *)this);
}

inline void SvbaseLdoub::set(Ldoub *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLdoub::set(Ldoub *data)
{
	m_p = data;
}

inline void SvbaseLdoub::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLdoub::next()
{
	m_p += m_N;
}

inline void SvbaseLdoub::last()
{
	m_p -= m_N;
}

inline void SvbaseLdoub::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLdoub::set(const SvbaseLdoub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLdoub::~SvbaseLdoub() {}



class SvbaseFcomp_c
{
protected:
	const Fcomp *m_p;
	Long m_N;
public:
	SvbaseFcomp_c();
	explicit SvbaseFcomp_c(Long_I N);
	SvbaseFcomp_c(const Fcomp *data, Long_I N); // unsafe
	const Fcomp* p() const;
	Long size() const;
	SvbaseFcomp_c &operator=(const SvbaseFcomp_c &rhs) = delete;
	const Fcomp &operator[](Long_I i) const;
	const Fcomp &end() const;
	const Fcomp &end(Long_I i) const;
	void set(const SvbaseFcomp_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Fcomp *data);
	void set(Long_I N);
	void set(const Fcomp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseFcomp_c();
};

inline SvbaseFcomp_c::SvbaseFcomp_c() {}

inline SvbaseFcomp_c::SvbaseFcomp_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseFcomp_c::SvbaseFcomp_c(const Fcomp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Fcomp * SvbaseFcomp_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseFcomp_c::size() const
{
	return m_N;
}

inline const Fcomp &SvbaseFcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Fcomp &SvbaseFcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Fcomp &SvbaseFcomp_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseFcomp_c::set(const Fcomp *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseFcomp_c::set(const Fcomp *data)
{
	m_p = data;
}

inline void SvbaseFcomp_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseFcomp_c::next()
{
	m_p += m_N;
}

inline void SvbaseFcomp_c::last()
{
	m_p -= m_N;
}

inline void SvbaseFcomp_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseFcomp_c::set(const SvbaseFcomp_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseFcomp_c::~SvbaseFcomp_c() {}

class SvbaseFcomp
{
protected:
	Fcomp *m_p;
	Long m_N;
public:
	SvbaseFcomp();
	explicit SvbaseFcomp(Long_I N);
	SvbaseFcomp(Fcomp *data, Long_I N); // unsafe
	Fcomp* p() const;
	Long size() const;
	SvbaseFcomp &operator=(const SvbaseFcomp &rhs) = delete;
	Fcomp &operator[](Long_I i) const;
	Fcomp &end() const;
	Fcomp &end(Long_I i) const;
	operator SvbaseFcomp_c() const;
	void set(const SvbaseFcomp &sli);
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

inline SvbaseFcomp::operator SvbaseFcomp_c() const
{
	return *((SvbaseFcomp_c *)this);
}

inline void SvbaseFcomp::set(Fcomp *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseFcomp::set(Fcomp *data)
{
	m_p = data;
}

inline void SvbaseFcomp::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseFcomp::next()
{
	m_p += m_N;
}

inline void SvbaseFcomp::last()
{
	m_p -= m_N;
}

inline void SvbaseFcomp::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseFcomp::set(const SvbaseFcomp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseFcomp::~SvbaseFcomp() {}

class SvbaseComp_c
{
protected:
	const Comp *m_p;
	Long m_N;
public:
	SvbaseComp_c();
	explicit SvbaseComp_c(Long_I N);
	SvbaseComp_c(const Comp *data, Long_I N); // unsafe
	const Comp* p() const;
	Long size() const;
	SvbaseComp_c &operator=(const SvbaseComp_c &rhs) = delete;
	const Comp &operator[](Long_I i) const;
	const Comp &end() const;
	const Comp &end(Long_I i) const;
	void set(const SvbaseComp_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Comp *data);
	void set(Long_I N);
	void set(const Comp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseComp_c();
};

inline SvbaseComp_c::SvbaseComp_c() {}

inline SvbaseComp_c::SvbaseComp_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseComp_c::SvbaseComp_c(const Comp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Comp * SvbaseComp_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseComp_c::size() const
{
	return m_N;
}

inline const Comp &SvbaseComp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Comp &SvbaseComp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Comp &SvbaseComp_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseComp_c::set(const Comp *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseComp_c::set(const Comp *data)
{
	m_p = data;
}

inline void SvbaseComp_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseComp_c::next()
{
	m_p += m_N;
}

inline void SvbaseComp_c::last()
{
	m_p -= m_N;
}

inline void SvbaseComp_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseComp_c::set(const SvbaseComp_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseComp_c::~SvbaseComp_c() {}

class SvbaseComp
{
protected:
	Comp *m_p;
	Long m_N;
public:
	SvbaseComp();
	explicit SvbaseComp(Long_I N);
	SvbaseComp(Comp *data, Long_I N); // unsafe
	Comp* p() const;
	Long size() const;
	SvbaseComp &operator=(const SvbaseComp &rhs) = delete;
	Comp &operator[](Long_I i) const;
	Comp &end() const;
	Comp &end(Long_I i) const;
	operator SvbaseComp_c() const;
	void set(const SvbaseComp &sli);
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

inline SvbaseComp::operator SvbaseComp_c() const
{
	return *((SvbaseComp_c *)this);
}

inline void SvbaseComp::set(Comp *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseComp::set(Comp *data)
{
	m_p = data;
}

inline void SvbaseComp::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseComp::next()
{
	m_p += m_N;
}

inline void SvbaseComp::last()
{
	m_p -= m_N;
}

inline void SvbaseComp::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseComp::set(const SvbaseComp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseComp::~SvbaseComp() {}

class SvbaseLcomp_c
{
protected:
	const Lcomp *m_p;
	Long m_N;
public:
	SvbaseLcomp_c();
	explicit SvbaseLcomp_c(Long_I N);
	SvbaseLcomp_c(const Lcomp *data, Long_I N); // unsafe
	const Lcomp* p() const;
	Long size() const;
	SvbaseLcomp_c &operator=(const SvbaseLcomp_c &rhs) = delete;
	const Lcomp &operator[](Long_I i) const;
	const Lcomp &end() const;
	const Lcomp &end(Long_I i) const;
	void set(const SvbaseLcomp_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Lcomp *data);
	void set(Long_I N);
	void set(const Lcomp *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLcomp_c();
};

inline SvbaseLcomp_c::SvbaseLcomp_c() {}

inline SvbaseLcomp_c::SvbaseLcomp_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLcomp_c::SvbaseLcomp_c(const Lcomp *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Lcomp * SvbaseLcomp_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLcomp_c::size() const
{
	return m_N;
}

inline const Lcomp &SvbaseLcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Lcomp &SvbaseLcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Lcomp &SvbaseLcomp_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseLcomp_c::set(const Lcomp *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLcomp_c::set(const Lcomp *data)
{
	m_p = data;
}

inline void SvbaseLcomp_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLcomp_c::next()
{
	m_p += m_N;
}

inline void SvbaseLcomp_c::last()
{
	m_p -= m_N;
}

inline void SvbaseLcomp_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLcomp_c::set(const SvbaseLcomp_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLcomp_c::~SvbaseLcomp_c() {}

class SvbaseLcomp
{
protected:
	Lcomp *m_p;
	Long m_N;
public:
	SvbaseLcomp();
	explicit SvbaseLcomp(Long_I N);
	SvbaseLcomp(Lcomp *data, Long_I N); // unsafe
	Lcomp* p() const;
	Long size() const;
	SvbaseLcomp &operator=(const SvbaseLcomp &rhs) = delete;
	Lcomp &operator[](Long_I i) const;
	Lcomp &end() const;
	Lcomp &end(Long_I i) const;
	operator SvbaseLcomp_c() const;
	void set(const SvbaseLcomp &sli);
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

inline SvbaseLcomp::operator SvbaseLcomp_c() const
{
	return *((SvbaseLcomp_c *)this);
}

inline void SvbaseLcomp::set(Lcomp *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLcomp::set(Lcomp *data)
{
	m_p = data;
}

inline void SvbaseLcomp::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLcomp::next()
{
	m_p += m_N;
}

inline void SvbaseLcomp::last()
{
	m_p -= m_N;
}

inline void SvbaseLcomp::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLcomp::set(const SvbaseLcomp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLcomp::~SvbaseLcomp() {}



class SvbaseFimag_c
{
protected:
	const Fimag *m_p;
	Long m_N;
public:
	SvbaseFimag_c();
	explicit SvbaseFimag_c(Long_I N);
	SvbaseFimag_c(const Fimag *data, Long_I N); // unsafe
	const Fimag* p() const;
	Long size() const;
	SvbaseFimag_c &operator=(const SvbaseFimag_c &rhs) = delete;
	const Fimag &operator[](Long_I i) const;
	const Fimag &end() const;
	const Fimag &end(Long_I i) const;
	void set(const SvbaseFimag_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Fimag *data);
	void set(Long_I N);
	void set(const Fimag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseFimag_c();
};

inline SvbaseFimag_c::SvbaseFimag_c() {}

inline SvbaseFimag_c::SvbaseFimag_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseFimag_c::SvbaseFimag_c(const Fimag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Fimag * SvbaseFimag_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseFimag_c::size() const
{
	return m_N;
}

inline const Fimag &SvbaseFimag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Fimag &SvbaseFimag_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Fimag &SvbaseFimag_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseFimag_c::set(const Fimag *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseFimag_c::set(const Fimag *data)
{
	m_p = data;
}

inline void SvbaseFimag_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseFimag_c::next()
{
	m_p += m_N;
}

inline void SvbaseFimag_c::last()
{
	m_p -= m_N;
}

inline void SvbaseFimag_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseFimag_c::set(const SvbaseFimag_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseFimag_c::~SvbaseFimag_c() {}

class SvbaseFimag
{
protected:
	Fimag *m_p;
	Long m_N;
public:
	SvbaseFimag();
	explicit SvbaseFimag(Long_I N);
	SvbaseFimag(Fimag *data, Long_I N); // unsafe
	Fimag* p() const;
	Long size() const;
	SvbaseFimag &operator=(const SvbaseFimag &rhs) = delete;
	Fimag &operator[](Long_I i) const;
	Fimag &end() const;
	Fimag &end(Long_I i) const;
	operator SvbaseFimag_c() const;
	void set(const SvbaseFimag &sli);
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

inline SvbaseFimag::operator SvbaseFimag_c() const
{
	return *((SvbaseFimag_c *)this);
}

inline void SvbaseFimag::set(Fimag *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseFimag::set(Fimag *data)
{
	m_p = data;
}

inline void SvbaseFimag::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseFimag::next()
{
	m_p += m_N;
}

inline void SvbaseFimag::last()
{
	m_p -= m_N;
}

inline void SvbaseFimag::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseFimag::set(const SvbaseFimag &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseFimag::~SvbaseFimag() {}

class SvbaseImag_c
{
protected:
	const Imag *m_p;
	Long m_N;
public:
	SvbaseImag_c();
	explicit SvbaseImag_c(Long_I N);
	SvbaseImag_c(const Imag *data, Long_I N); // unsafe
	const Imag* p() const;
	Long size() const;
	SvbaseImag_c &operator=(const SvbaseImag_c &rhs) = delete;
	const Imag &operator[](Long_I i) const;
	const Imag &end() const;
	const Imag &end(Long_I i) const;
	void set(const SvbaseImag_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Imag *data);
	void set(Long_I N);
	void set(const Imag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseImag_c();
};

inline SvbaseImag_c::SvbaseImag_c() {}

inline SvbaseImag_c::SvbaseImag_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseImag_c::SvbaseImag_c(const Imag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Imag * SvbaseImag_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseImag_c::size() const
{
	return m_N;
}

inline const Imag &SvbaseImag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Imag &SvbaseImag_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Imag &SvbaseImag_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseImag_c::set(const Imag *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseImag_c::set(const Imag *data)
{
	m_p = data;
}

inline void SvbaseImag_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseImag_c::next()
{
	m_p += m_N;
}

inline void SvbaseImag_c::last()
{
	m_p -= m_N;
}

inline void SvbaseImag_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseImag_c::set(const SvbaseImag_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseImag_c::~SvbaseImag_c() {}

class SvbaseImag
{
protected:
	Imag *m_p;
	Long m_N;
public:
	SvbaseImag();
	explicit SvbaseImag(Long_I N);
	SvbaseImag(Imag *data, Long_I N); // unsafe
	Imag* p() const;
	Long size() const;
	SvbaseImag &operator=(const SvbaseImag &rhs) = delete;
	Imag &operator[](Long_I i) const;
	Imag &end() const;
	Imag &end(Long_I i) const;
	operator SvbaseImag_c() const;
	void set(const SvbaseImag &sli);
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

inline SvbaseImag::operator SvbaseImag_c() const
{
	return *((SvbaseImag_c *)this);
}

inline void SvbaseImag::set(Imag *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseImag::set(Imag *data)
{
	m_p = data;
}

inline void SvbaseImag::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseImag::next()
{
	m_p += m_N;
}

inline void SvbaseImag::last()
{
	m_p -= m_N;
}

inline void SvbaseImag::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseImag::set(const SvbaseImag &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseImag::~SvbaseImag() {}

class SvbaseLimag_c
{
protected:
	const Limag *m_p;
	Long m_N;
public:
	SvbaseLimag_c();
	explicit SvbaseLimag_c(Long_I N);
	SvbaseLimag_c(const Limag *data, Long_I N); // unsafe
	const Limag* p() const;
	Long size() const;
	SvbaseLimag_c &operator=(const SvbaseLimag_c &rhs) = delete;
	const Limag &operator[](Long_I i) const;
	const Limag &end() const;
	const Limag &end(Long_I i) const;
	void set(const SvbaseLimag_c &sli);
	void next(); // m_p += m_N
	
	// === unsafe operations (unsafe) ===
	void set(const Limag *data);
	void set(Long_I N);
	void set(const Limag *data, Long_I N);
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N

	~SvbaseLimag_c();
};

inline SvbaseLimag_c::SvbaseLimag_c() {}

inline SvbaseLimag_c::SvbaseLimag_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
	m_p = nullptr;
#endif
}

inline SvbaseLimag_c::SvbaseLimag_c(const Limag *data, Long_I N)
	: m_p(data), m_N(N) {}

inline const Limag * SvbaseLimag_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long SvbaseLimag_c::size() const
{
	return m_N;
}

inline const Limag &SvbaseLimag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
	    SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[i];
}

inline const Limag &SvbaseLimag_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
	    SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_N - 1];
}

inline const Limag &SvbaseLimag_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i <= 0 || i > m_N)
	    SLS_ERR("index out of bound");
#endif
	return m_p[m_N - i];
}


inline void SvbaseLimag_c::set(const Limag *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLimag_c::set(const Limag *data)
{
	m_p = data;
}

inline void SvbaseLimag_c::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLimag_c::next()
{
	m_p += m_N;
}

inline void SvbaseLimag_c::last()
{
	m_p -= m_N;
}

inline void SvbaseLimag_c::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLimag_c::set(const SvbaseLimag_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLimag_c::~SvbaseLimag_c() {}

class SvbaseLimag
{
protected:
	Limag *m_p;
	Long m_N;
public:
	SvbaseLimag();
	explicit SvbaseLimag(Long_I N);
	SvbaseLimag(Limag *data, Long_I N); // unsafe
	Limag* p() const;
	Long size() const;
	SvbaseLimag &operator=(const SvbaseLimag &rhs) = delete;
	Limag &operator[](Long_I i) const;
	Limag &end() const;
	Limag &end(Long_I i) const;
	operator SvbaseLimag_c() const;
	void set(const SvbaseLimag &sli);
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

inline SvbaseLimag::operator SvbaseLimag_c() const
{
	return *((SvbaseLimag_c *)this);
}

inline void SvbaseLimag::set(Limag *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLimag::set(Limag *data)
{
	m_p = data;
}

inline void SvbaseLimag::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLimag::next()
{
	m_p += m_N;
}

inline void SvbaseLimag::last()
{
	m_p -= m_N;
}

inline void SvbaseLimag::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLimag::set(const SvbaseLimag &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLimag::~SvbaseLimag() {}


#ifdef SLS_USE_INT_AS_LONG
typedef SvbaseInt SvbaseLong;
typedef SvbaseInt_c SvbaseLong_c;
#else
typedef SvbaseLlong SvbaseLong;
typedef SvbaseLlong_c SvbaseLong_c;
#endif

class SvecChar_c : public SvbaseChar_c
{
public:
	SvecChar_c() = default;
	explicit SvecChar_c(Long_I N);
	SvecChar_c(const Char *data, Long_I N); // unsafe
	SvecChar_c &operator=(const SvecChar_c &rhs) = delete;
};

inline SvecChar_c::SvecChar_c(Long_I N) : SvbaseChar_c(N)
{}

inline SvecChar_c::SvecChar_c(const Char *data, Long_I N)
	: SvbaseChar_c(data, N) {}


typedef const SvecChar_c &SvecChar_I;

class SvecChar : public SvbaseChar
{
public:
	SvecChar() = default;
	explicit SvecChar(Long_I N);
	SvecChar(Char *data, Long_I N); // unsafe
	SvecChar &operator=(const SvecChar &rhs) = delete;
	operator SvecChar_c() const;
};

inline SvecChar::SvecChar(Long_I N) : SvbaseChar(N)
{}

inline SvecChar::SvecChar(Char *data, Long_I N)
	: SvbaseChar(data, N) {}

inline SvecChar::operator SvecChar_c() const
{
	return *((SvecChar_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecChar &SvecChar_O, &SvecChar_IO;

class SvecUchar_c : public SvbaseUchar_c
{
public:
	SvecUchar_c() = default;
	explicit SvecUchar_c(Long_I N);
	SvecUchar_c(const Uchar *data, Long_I N); // unsafe
	SvecUchar_c &operator=(const SvecUchar_c &rhs) = delete;
};

inline SvecUchar_c::SvecUchar_c(Long_I N) : SvbaseUchar_c(N)
{}

inline SvecUchar_c::SvecUchar_c(const Uchar *data, Long_I N)
	: SvbaseUchar_c(data, N) {}


typedef const SvecUchar_c &SvecUchar_I;

class SvecUchar : public SvbaseUchar
{
public:
	SvecUchar() = default;
	explicit SvecUchar(Long_I N);
	SvecUchar(Uchar *data, Long_I N); // unsafe
	SvecUchar &operator=(const SvecUchar &rhs) = delete;
	operator SvecUchar_c() const;
};

inline SvecUchar::SvecUchar(Long_I N) : SvbaseUchar(N)
{}

inline SvecUchar::SvecUchar(Uchar *data, Long_I N)
	: SvbaseUchar(data, N) {}

inline SvecUchar::operator SvecUchar_c() const
{
	return *((SvecUchar_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecUchar &SvecUchar_O, &SvecUchar_IO;

class SvecInt_c : public SvbaseInt_c
{
public:
	SvecInt_c() = default;
	explicit SvecInt_c(Long_I N);
	SvecInt_c(const Int *data, Long_I N); // unsafe
	SvecInt_c &operator=(const SvecInt_c &rhs) = delete;
};

inline SvecInt_c::SvecInt_c(Long_I N) : SvbaseInt_c(N)
{}

inline SvecInt_c::SvecInt_c(const Int *data, Long_I N)
	: SvbaseInt_c(data, N) {}


typedef const SvecInt_c &SvecInt_I;

class SvecInt : public SvbaseInt
{
public:
	SvecInt() = default;
	explicit SvecInt(Long_I N);
	SvecInt(Int *data, Long_I N); // unsafe
	SvecInt &operator=(const SvecInt &rhs) = delete;
	operator SvecInt_c() const;
};

inline SvecInt::SvecInt(Long_I N) : SvbaseInt(N)
{}

inline SvecInt::SvecInt(Int *data, Long_I N)
	: SvbaseInt(data, N) {}

inline SvecInt::operator SvecInt_c() const
{
	return *((SvecInt_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecInt &SvecInt_O, &SvecInt_IO;

class SvecLlong_c : public SvbaseLlong_c
{
public:
	SvecLlong_c() = default;
	explicit SvecLlong_c(Long_I N);
	SvecLlong_c(const Llong *data, Long_I N); // unsafe
	SvecLlong_c &operator=(const SvecLlong_c &rhs) = delete;
};

inline SvecLlong_c::SvecLlong_c(Long_I N) : SvbaseLlong_c(N)
{}

inline SvecLlong_c::SvecLlong_c(const Llong *data, Long_I N)
	: SvbaseLlong_c(data, N) {}


typedef const SvecLlong_c &SvecLlong_I;

class SvecLlong : public SvbaseLlong
{
public:
	SvecLlong() = default;
	explicit SvecLlong(Long_I N);
	SvecLlong(Llong *data, Long_I N); // unsafe
	SvecLlong &operator=(const SvecLlong &rhs) = delete;
	operator SvecLlong_c() const;
};

inline SvecLlong::SvecLlong(Long_I N) : SvbaseLlong(N)
{}

inline SvecLlong::SvecLlong(Llong *data, Long_I N)
	: SvbaseLlong(data, N) {}

inline SvecLlong::operator SvecLlong_c() const
{
	return *((SvecLlong_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLlong &SvecLlong_O, &SvecLlong_IO;

class SvecFloat_c : public SvbaseFloat_c
{
public:
	SvecFloat_c() = default;
	explicit SvecFloat_c(Long_I N);
	SvecFloat_c(const Float *data, Long_I N); // unsafe
	SvecFloat_c &operator=(const SvecFloat_c &rhs) = delete;
};

inline SvecFloat_c::SvecFloat_c(Long_I N) : SvbaseFloat_c(N)
{}

inline SvecFloat_c::SvecFloat_c(const Float *data, Long_I N)
	: SvbaseFloat_c(data, N) {}


typedef const SvecFloat_c &SvecFloat_I;

class SvecFloat : public SvbaseFloat
{
public:
	SvecFloat() = default;
	explicit SvecFloat(Long_I N);
	SvecFloat(Float *data, Long_I N); // unsafe
	SvecFloat &operator=(const SvecFloat &rhs) = delete;
	operator SvecFloat_c() const;
};

inline SvecFloat::SvecFloat(Long_I N) : SvbaseFloat(N)
{}

inline SvecFloat::SvecFloat(Float *data, Long_I N)
	: SvbaseFloat(data, N) {}

inline SvecFloat::operator SvecFloat_c() const
{
	return *((SvecFloat_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecFloat &SvecFloat_O, &SvecFloat_IO;

class SvecDoub_c : public SvbaseDoub_c
{
public:
	SvecDoub_c() = default;
	explicit SvecDoub_c(Long_I N);
	SvecDoub_c(const Doub *data, Long_I N); // unsafe
	SvecDoub_c &operator=(const SvecDoub_c &rhs) = delete;
};

inline SvecDoub_c::SvecDoub_c(Long_I N) : SvbaseDoub_c(N)
{}

inline SvecDoub_c::SvecDoub_c(const Doub *data, Long_I N)
	: SvbaseDoub_c(data, N) {}


typedef const SvecDoub_c &SvecDoub_I;

class SvecDoub : public SvbaseDoub
{
public:
	SvecDoub() = default;
	explicit SvecDoub(Long_I N);
	SvecDoub(Doub *data, Long_I N); // unsafe
	SvecDoub &operator=(const SvecDoub &rhs) = delete;
	operator SvecDoub_c() const;
};

inline SvecDoub::SvecDoub(Long_I N) : SvbaseDoub(N)
{}

inline SvecDoub::SvecDoub(Doub *data, Long_I N)
	: SvbaseDoub(data, N) {}

inline SvecDoub::operator SvecDoub_c() const
{
	return *((SvecDoub_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecDoub &SvecDoub_O, &SvecDoub_IO;

class SvecLdoub_c : public SvbaseLdoub_c
{
public:
	SvecLdoub_c() = default;
	explicit SvecLdoub_c(Long_I N);
	SvecLdoub_c(const Ldoub *data, Long_I N); // unsafe
	SvecLdoub_c &operator=(const SvecLdoub_c &rhs) = delete;
};

inline SvecLdoub_c::SvecLdoub_c(Long_I N) : SvbaseLdoub_c(N)
{}

inline SvecLdoub_c::SvecLdoub_c(const Ldoub *data, Long_I N)
	: SvbaseLdoub_c(data, N) {}


typedef const SvecLdoub_c &SvecLdoub_I;

class SvecLdoub : public SvbaseLdoub
{
public:
	SvecLdoub() = default;
	explicit SvecLdoub(Long_I N);
	SvecLdoub(Ldoub *data, Long_I N); // unsafe
	SvecLdoub &operator=(const SvecLdoub &rhs) = delete;
	operator SvecLdoub_c() const;
};

inline SvecLdoub::SvecLdoub(Long_I N) : SvbaseLdoub(N)
{}

inline SvecLdoub::SvecLdoub(Ldoub *data, Long_I N)
	: SvbaseLdoub(data, N) {}

inline SvecLdoub::operator SvecLdoub_c() const
{
	return *((SvecLdoub_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLdoub &SvecLdoub_O, &SvecLdoub_IO;



class SvecFcomp_c : public SvbaseFcomp_c
{
public:
	SvecFcomp_c() = default;
	explicit SvecFcomp_c(Long_I N);
	SvecFcomp_c(const Fcomp *data, Long_I N); // unsafe
	SvecFcomp_c &operator=(const SvecFcomp_c &rhs) = delete;
};

inline SvecFcomp_c::SvecFcomp_c(Long_I N) : SvbaseFcomp_c(N)
{}

inline SvecFcomp_c::SvecFcomp_c(const Fcomp *data, Long_I N)
	: SvbaseFcomp_c(data, N) {}


typedef const SvecFcomp_c &SvecFcomp_I;

class SvecFcomp : public SvbaseFcomp
{
public:
	SvecFcomp() = default;
	explicit SvecFcomp(Long_I N);
	SvecFcomp(Fcomp *data, Long_I N); // unsafe
	SvecFcomp &operator=(const SvecFcomp &rhs) = delete;
	operator SvecFcomp_c() const;
};

inline SvecFcomp::SvecFcomp(Long_I N) : SvbaseFcomp(N)
{}

inline SvecFcomp::SvecFcomp(Fcomp *data, Long_I N)
	: SvbaseFcomp(data, N) {}

inline SvecFcomp::operator SvecFcomp_c() const
{
	return *((SvecFcomp_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecFcomp &SvecFcomp_O, &SvecFcomp_IO;

class SvecComp_c : public SvbaseComp_c
{
public:
	SvecComp_c() = default;
	explicit SvecComp_c(Long_I N);
	SvecComp_c(const Comp *data, Long_I N); // unsafe
	SvecComp_c &operator=(const SvecComp_c &rhs) = delete;
};

inline SvecComp_c::SvecComp_c(Long_I N) : SvbaseComp_c(N)
{}

inline SvecComp_c::SvecComp_c(const Comp *data, Long_I N)
	: SvbaseComp_c(data, N) {}


typedef const SvecComp_c &SvecComp_I;

class SvecComp : public SvbaseComp
{
public:
	SvecComp() = default;
	explicit SvecComp(Long_I N);
	SvecComp(Comp *data, Long_I N); // unsafe
	SvecComp &operator=(const SvecComp &rhs) = delete;
	operator SvecComp_c() const;
};

inline SvecComp::SvecComp(Long_I N) : SvbaseComp(N)
{}

inline SvecComp::SvecComp(Comp *data, Long_I N)
	: SvbaseComp(data, N) {}

inline SvecComp::operator SvecComp_c() const
{
	return *((SvecComp_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecComp &SvecComp_O, &SvecComp_IO;

class SvecLcomp_c : public SvbaseLcomp_c
{
public:
	SvecLcomp_c() = default;
	explicit SvecLcomp_c(Long_I N);
	SvecLcomp_c(const Lcomp *data, Long_I N); // unsafe
	SvecLcomp_c &operator=(const SvecLcomp_c &rhs) = delete;
};

inline SvecLcomp_c::SvecLcomp_c(Long_I N) : SvbaseLcomp_c(N)
{}

inline SvecLcomp_c::SvecLcomp_c(const Lcomp *data, Long_I N)
	: SvbaseLcomp_c(data, N) {}


typedef const SvecLcomp_c &SvecLcomp_I;

class SvecLcomp : public SvbaseLcomp
{
public:
	SvecLcomp() = default;
	explicit SvecLcomp(Long_I N);
	SvecLcomp(Lcomp *data, Long_I N); // unsafe
	SvecLcomp &operator=(const SvecLcomp &rhs) = delete;
	operator SvecLcomp_c() const;
};

inline SvecLcomp::SvecLcomp(Long_I N) : SvbaseLcomp(N)
{}

inline SvecLcomp::SvecLcomp(Lcomp *data, Long_I N)
	: SvbaseLcomp(data, N) {}

inline SvecLcomp::operator SvecLcomp_c() const
{
	return *((SvecLcomp_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLcomp &SvecLcomp_O, &SvecLcomp_IO;



class SvecFimag_c : public SvbaseFimag_c
{
public:
	SvecFimag_c() = default;
	explicit SvecFimag_c(Long_I N);
	SvecFimag_c(const Fimag *data, Long_I N); // unsafe
	SvecFimag_c &operator=(const SvecFimag_c &rhs) = delete;
};

inline SvecFimag_c::SvecFimag_c(Long_I N) : SvbaseFimag_c(N)
{}

inline SvecFimag_c::SvecFimag_c(const Fimag *data, Long_I N)
	: SvbaseFimag_c(data, N) {}


typedef const SvecFimag_c &SvecFimag_I;

class SvecFimag : public SvbaseFimag
{
public:
	SvecFimag() = default;
	explicit SvecFimag(Long_I N);
	SvecFimag(Fimag *data, Long_I N); // unsafe
	SvecFimag &operator=(const SvecFimag &rhs) = delete;
	operator SvecFimag_c() const;
};

inline SvecFimag::SvecFimag(Long_I N) : SvbaseFimag(N)
{}

inline SvecFimag::SvecFimag(Fimag *data, Long_I N)
	: SvbaseFimag(data, N) {}

inline SvecFimag::operator SvecFimag_c() const
{
	return *((SvecFimag_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecFimag &SvecFimag_O, &SvecFimag_IO;

class SvecImag_c : public SvbaseImag_c
{
public:
	SvecImag_c() = default;
	explicit SvecImag_c(Long_I N);
	SvecImag_c(const Imag *data, Long_I N); // unsafe
	SvecImag_c &operator=(const SvecImag_c &rhs) = delete;
};

inline SvecImag_c::SvecImag_c(Long_I N) : SvbaseImag_c(N)
{}

inline SvecImag_c::SvecImag_c(const Imag *data, Long_I N)
	: SvbaseImag_c(data, N) {}


typedef const SvecImag_c &SvecImag_I;

class SvecImag : public SvbaseImag
{
public:
	SvecImag() = default;
	explicit SvecImag(Long_I N);
	SvecImag(Imag *data, Long_I N); // unsafe
	SvecImag &operator=(const SvecImag &rhs) = delete;
	operator SvecImag_c() const;
};

inline SvecImag::SvecImag(Long_I N) : SvbaseImag(N)
{}

inline SvecImag::SvecImag(Imag *data, Long_I N)
	: SvbaseImag(data, N) {}

inline SvecImag::operator SvecImag_c() const
{
	return *((SvecImag_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecImag &SvecImag_O, &SvecImag_IO;

class SvecLimag_c : public SvbaseLimag_c
{
public:
	SvecLimag_c() = default;
	explicit SvecLimag_c(Long_I N);
	SvecLimag_c(const Limag *data, Long_I N); // unsafe
	SvecLimag_c &operator=(const SvecLimag_c &rhs) = delete;
};

inline SvecLimag_c::SvecLimag_c(Long_I N) : SvbaseLimag_c(N)
{}

inline SvecLimag_c::SvecLimag_c(const Limag *data, Long_I N)
	: SvbaseLimag_c(data, N) {}


typedef const SvecLimag_c &SvecLimag_I;

class SvecLimag : public SvbaseLimag
{
public:
	SvecLimag() = default;
	explicit SvecLimag(Long_I N);
	SvecLimag(Limag *data, Long_I N); // unsafe
	SvecLimag &operator=(const SvecLimag &rhs) = delete;
	operator SvecLimag_c() const;
};

inline SvecLimag::SvecLimag(Long_I N) : SvbaseLimag(N)
{}

inline SvecLimag::SvecLimag(Limag *data, Long_I N)
	: SvbaseLimag(data, N) {}

inline SvecLimag::operator SvecLimag_c() const
{
	return *((SvecLimag_c *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLimag &SvecLimag_O, &SvecLimag_IO;


#ifdef SLS_USE_INT_AS_LONG
typedef SvecInt SvecLong;
typedef SvecInt_c SvecLong_c;
#else
typedef SvecLlong SvecLong;
typedef SvecLlong_c SvecLong_c;
#endif
typedef const SvecLong_c &SvecLong_I;
// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLong &SvecLong_O, &SvecLong_IO;

} // namespace slisc
