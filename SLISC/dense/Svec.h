#pragma once
#include "../global.h"
#include "../arith/Imag.h"

// this class is not memory safe!
// "C" means lower level const

namespace slisc {
class SvbaseCharC
{
protected:
	const Char *m_p;
	Long m_N;
public:
	SvbaseCharC();
	explicit SvbaseCharC(Long_I N);
	SvbaseCharC(const Char *data, Long_I N); // unsafe
	const Char* p() const;
	Long size() const;
	SvbaseCharC &operator=(const SvbaseCharC &rhs) = delete;
	const Char &operator[](Long_I i) const;
	const Char &end() const;
	const Char &end(Long_I i) const;
	void set(const SvbaseCharC &sli);
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


inline void SvbaseCharC::set(const Char *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseCharC::set(const Char *data)
{
	m_p = data;
}

inline void SvbaseCharC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseCharC::next()
{
	m_p += m_N;
}

inline void SvbaseCharC::last()
{
	m_p -= m_N;
}

inline void SvbaseCharC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseCharC::set(const SvbaseCharC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseCharC::~SvbaseCharC() {}

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
	operator SvbaseCharC() const;
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

inline SvbaseChar::operator SvbaseCharC() const
{
	return *((SvbaseCharC *)this);
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

class SvbaseUcharC
{
protected:
	const Uchar *m_p;
	Long m_N;
public:
	SvbaseUcharC();
	explicit SvbaseUcharC(Long_I N);
	SvbaseUcharC(const Uchar *data, Long_I N); // unsafe
	const Uchar* p() const;
	Long size() const;
	SvbaseUcharC &operator=(const SvbaseUcharC &rhs) = delete;
	const Uchar &operator[](Long_I i) const;
	const Uchar &end() const;
	const Uchar &end(Long_I i) const;
	void set(const SvbaseUcharC &sli);
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


inline void SvbaseUcharC::set(const Uchar *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseUcharC::set(const Uchar *data)
{
	m_p = data;
}

inline void SvbaseUcharC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseUcharC::next()
{
	m_p += m_N;
}

inline void SvbaseUcharC::last()
{
	m_p -= m_N;
}

inline void SvbaseUcharC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseUcharC::set(const SvbaseUcharC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseUcharC::~SvbaseUcharC() {}

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
	operator SvbaseUcharC() const;
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

inline SvbaseUchar::operator SvbaseUcharC() const
{
	return *((SvbaseUcharC *)this);
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

class SvbaseIntC
{
protected:
	const Int *m_p;
	Long m_N;
public:
	SvbaseIntC();
	explicit SvbaseIntC(Long_I N);
	SvbaseIntC(const Int *data, Long_I N); // unsafe
	const Int* p() const;
	Long size() const;
	SvbaseIntC &operator=(const SvbaseIntC &rhs) = delete;
	const Int &operator[](Long_I i) const;
	const Int &end() const;
	const Int &end(Long_I i) const;
	void set(const SvbaseIntC &sli);
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


inline void SvbaseIntC::set(const Int *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseIntC::set(const Int *data)
{
	m_p = data;
}

inline void SvbaseIntC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseIntC::next()
{
	m_p += m_N;
}

inline void SvbaseIntC::last()
{
	m_p -= m_N;
}

inline void SvbaseIntC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseIntC::set(const SvbaseIntC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseIntC::~SvbaseIntC() {}

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
	operator SvbaseIntC() const;
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

inline SvbaseInt::operator SvbaseIntC() const
{
	return *((SvbaseIntC *)this);
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

class SvbaseLlongC
{
protected:
	const Llong *m_p;
	Long m_N;
public:
	SvbaseLlongC();
	explicit SvbaseLlongC(Long_I N);
	SvbaseLlongC(const Llong *data, Long_I N); // unsafe
	const Llong* p() const;
	Long size() const;
	SvbaseLlongC &operator=(const SvbaseLlongC &rhs) = delete;
	const Llong &operator[](Long_I i) const;
	const Llong &end() const;
	const Llong &end(Long_I i) const;
	void set(const SvbaseLlongC &sli);
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


inline void SvbaseLlongC::set(const Llong *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLlongC::set(const Llong *data)
{
	m_p = data;
}

inline void SvbaseLlongC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLlongC::next()
{
	m_p += m_N;
}

inline void SvbaseLlongC::last()
{
	m_p -= m_N;
}

inline void SvbaseLlongC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLlongC::set(const SvbaseLlongC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLlongC::~SvbaseLlongC() {}

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
	operator SvbaseLlongC() const;
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

inline SvbaseLlong::operator SvbaseLlongC() const
{
	return *((SvbaseLlongC *)this);
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

class SvbaseFloatC
{
protected:
	const Float *m_p;
	Long m_N;
public:
	SvbaseFloatC();
	explicit SvbaseFloatC(Long_I N);
	SvbaseFloatC(const Float *data, Long_I N); // unsafe
	const Float* p() const;
	Long size() const;
	SvbaseFloatC &operator=(const SvbaseFloatC &rhs) = delete;
	const Float &operator[](Long_I i) const;
	const Float &end() const;
	const Float &end(Long_I i) const;
	void set(const SvbaseFloatC &sli);
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


inline void SvbaseFloatC::set(const Float *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseFloatC::set(const Float *data)
{
	m_p = data;
}

inline void SvbaseFloatC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseFloatC::next()
{
	m_p += m_N;
}

inline void SvbaseFloatC::last()
{
	m_p -= m_N;
}

inline void SvbaseFloatC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseFloatC::set(const SvbaseFloatC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseFloatC::~SvbaseFloatC() {}

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
	operator SvbaseFloatC() const;
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

inline SvbaseFloat::operator SvbaseFloatC() const
{
	return *((SvbaseFloatC *)this);
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

class SvbaseDoubC
{
protected:
	const Doub *m_p;
	Long m_N;
public:
	SvbaseDoubC();
	explicit SvbaseDoubC(Long_I N);
	SvbaseDoubC(const Doub *data, Long_I N); // unsafe
	const Doub* p() const;
	Long size() const;
	SvbaseDoubC &operator=(const SvbaseDoubC &rhs) = delete;
	const Doub &operator[](Long_I i) const;
	const Doub &end() const;
	const Doub &end(Long_I i) const;
	void set(const SvbaseDoubC &sli);
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


inline void SvbaseDoubC::set(const Doub *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseDoubC::set(const Doub *data)
{
	m_p = data;
}

inline void SvbaseDoubC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseDoubC::next()
{
	m_p += m_N;
}

inline void SvbaseDoubC::last()
{
	m_p -= m_N;
}

inline void SvbaseDoubC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseDoubC::set(const SvbaseDoubC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseDoubC::~SvbaseDoubC() {}

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
	operator SvbaseDoubC() const;
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

inline SvbaseDoub::operator SvbaseDoubC() const
{
	return *((SvbaseDoubC *)this);
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

class SvbaseLdoubC
{
protected:
	const Ldoub *m_p;
	Long m_N;
public:
	SvbaseLdoubC();
	explicit SvbaseLdoubC(Long_I N);
	SvbaseLdoubC(const Ldoub *data, Long_I N); // unsafe
	const Ldoub* p() const;
	Long size() const;
	SvbaseLdoubC &operator=(const SvbaseLdoubC &rhs) = delete;
	const Ldoub &operator[](Long_I i) const;
	const Ldoub &end() const;
	const Ldoub &end(Long_I i) const;
	void set(const SvbaseLdoubC &sli);
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


inline void SvbaseLdoubC::set(const Ldoub *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLdoubC::set(const Ldoub *data)
{
	m_p = data;
}

inline void SvbaseLdoubC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLdoubC::next()
{
	m_p += m_N;
}

inline void SvbaseLdoubC::last()
{
	m_p -= m_N;
}

inline void SvbaseLdoubC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLdoubC::set(const SvbaseLdoubC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLdoubC::~SvbaseLdoubC() {}

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
	operator SvbaseLdoubC() const;
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

inline SvbaseLdoub::operator SvbaseLdoubC() const
{
	return *((SvbaseLdoubC *)this);
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



class SvbaseFcompC
{
protected:
	const Fcomp *m_p;
	Long m_N;
public:
	SvbaseFcompC();
	explicit SvbaseFcompC(Long_I N);
	SvbaseFcompC(const Fcomp *data, Long_I N); // unsafe
	const Fcomp* p() const;
	Long size() const;
	SvbaseFcompC &operator=(const SvbaseFcompC &rhs) = delete;
	const Fcomp &operator[](Long_I i) const;
	const Fcomp &end() const;
	const Fcomp &end(Long_I i) const;
	void set(const SvbaseFcompC &sli);
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


inline void SvbaseFcompC::set(const Fcomp *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseFcompC::set(const Fcomp *data)
{
	m_p = data;
}

inline void SvbaseFcompC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseFcompC::next()
{
	m_p += m_N;
}

inline void SvbaseFcompC::last()
{
	m_p -= m_N;
}

inline void SvbaseFcompC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseFcompC::set(const SvbaseFcompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseFcompC::~SvbaseFcompC() {}

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
	operator SvbaseFcompC() const;
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

inline SvbaseFcomp::operator SvbaseFcompC() const
{
	return *((SvbaseFcompC *)this);
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

class SvbaseCompC
{
protected:
	const Comp *m_p;
	Long m_N;
public:
	SvbaseCompC();
	explicit SvbaseCompC(Long_I N);
	SvbaseCompC(const Comp *data, Long_I N); // unsafe
	const Comp* p() const;
	Long size() const;
	SvbaseCompC &operator=(const SvbaseCompC &rhs) = delete;
	const Comp &operator[](Long_I i) const;
	const Comp &end() const;
	const Comp &end(Long_I i) const;
	void set(const SvbaseCompC &sli);
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


inline void SvbaseCompC::set(const Comp *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseCompC::set(const Comp *data)
{
	m_p = data;
}

inline void SvbaseCompC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseCompC::next()
{
	m_p += m_N;
}

inline void SvbaseCompC::last()
{
	m_p -= m_N;
}

inline void SvbaseCompC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseCompC::set(const SvbaseCompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseCompC::~SvbaseCompC() {}

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
	operator SvbaseCompC() const;
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

inline SvbaseComp::operator SvbaseCompC() const
{
	return *((SvbaseCompC *)this);
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

class SvbaseLcompC
{
protected:
	const Lcomp *m_p;
	Long m_N;
public:
	SvbaseLcompC();
	explicit SvbaseLcompC(Long_I N);
	SvbaseLcompC(const Lcomp *data, Long_I N); // unsafe
	const Lcomp* p() const;
	Long size() const;
	SvbaseLcompC &operator=(const SvbaseLcompC &rhs) = delete;
	const Lcomp &operator[](Long_I i) const;
	const Lcomp &end() const;
	const Lcomp &end(Long_I i) const;
	void set(const SvbaseLcompC &sli);
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


inline void SvbaseLcompC::set(const Lcomp *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLcompC::set(const Lcomp *data)
{
	m_p = data;
}

inline void SvbaseLcompC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLcompC::next()
{
	m_p += m_N;
}

inline void SvbaseLcompC::last()
{
	m_p -= m_N;
}

inline void SvbaseLcompC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLcompC::set(const SvbaseLcompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLcompC::~SvbaseLcompC() {}

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
	operator SvbaseLcompC() const;
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

inline SvbaseLcomp::operator SvbaseLcompC() const
{
	return *((SvbaseLcompC *)this);
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



class SvbaseFimagC
{
protected:
	const Fimag *m_p;
	Long m_N;
public:
	SvbaseFimagC();
	explicit SvbaseFimagC(Long_I N);
	SvbaseFimagC(const Fimag *data, Long_I N); // unsafe
	const Fimag* p() const;
	Long size() const;
	SvbaseFimagC &operator=(const SvbaseFimagC &rhs) = delete;
	const Fimag &operator[](Long_I i) const;
	const Fimag &end() const;
	const Fimag &end(Long_I i) const;
	void set(const SvbaseFimagC &sli);
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


inline void SvbaseFimagC::set(const Fimag *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseFimagC::set(const Fimag *data)
{
	m_p = data;
}

inline void SvbaseFimagC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseFimagC::next()
{
	m_p += m_N;
}

inline void SvbaseFimagC::last()
{
	m_p -= m_N;
}

inline void SvbaseFimagC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseFimagC::set(const SvbaseFimagC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseFimagC::~SvbaseFimagC() {}

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
	operator SvbaseFimagC() const;
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

inline SvbaseFimag::operator SvbaseFimagC() const
{
	return *((SvbaseFimagC *)this);
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

class SvbaseImagC
{
protected:
	const Imag *m_p;
	Long m_N;
public:
	SvbaseImagC();
	explicit SvbaseImagC(Long_I N);
	SvbaseImagC(const Imag *data, Long_I N); // unsafe
	const Imag* p() const;
	Long size() const;
	SvbaseImagC &operator=(const SvbaseImagC &rhs) = delete;
	const Imag &operator[](Long_I i) const;
	const Imag &end() const;
	const Imag &end(Long_I i) const;
	void set(const SvbaseImagC &sli);
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


inline void SvbaseImagC::set(const Imag *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseImagC::set(const Imag *data)
{
	m_p = data;
}

inline void SvbaseImagC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseImagC::next()
{
	m_p += m_N;
}

inline void SvbaseImagC::last()
{
	m_p -= m_N;
}

inline void SvbaseImagC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseImagC::set(const SvbaseImagC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseImagC::~SvbaseImagC() {}

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
	operator SvbaseImagC() const;
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

inline SvbaseImag::operator SvbaseImagC() const
{
	return *((SvbaseImagC *)this);
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

class SvbaseLimagC
{
protected:
	const Limag *m_p;
	Long m_N;
public:
	SvbaseLimagC();
	explicit SvbaseLimagC(Long_I N);
	SvbaseLimagC(const Limag *data, Long_I N); // unsafe
	const Limag* p() const;
	Long size() const;
	SvbaseLimagC &operator=(const SvbaseLimagC &rhs) = delete;
	const Limag &operator[](Long_I i) const;
	const Limag &end() const;
	const Limag &end(Long_I i) const;
	void set(const SvbaseLimagC &sli);
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


inline void SvbaseLimagC::set(const Limag *data, Long_I N)
{
	m_p = data; m_N = N;
}

inline void SvbaseLimagC::set(const Limag *data)
{
	m_p = data;
}

inline void SvbaseLimagC::set(Long_I N)
{
	m_N = N;
}

inline void SvbaseLimagC::next()
{
	m_p += m_N;
}

inline void SvbaseLimagC::last()
{
	m_p -= m_N;
}

inline void SvbaseLimagC::shift(Long_I N)
{
	m_p += N;
}

inline void SvbaseLimagC::set(const SvbaseLimagC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N;
}

inline SvbaseLimagC::~SvbaseLimagC() {}

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
	operator SvbaseLimagC() const;
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

inline SvbaseLimag::operator SvbaseLimagC() const
{
	return *((SvbaseLimagC *)this);
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
typedef SvbaseIntC SvbaseLongC;
#else
typedef SvbaseLlong SvbaseLong;
typedef SvbaseLlongC SvbaseLongC;
#endif

class SvecCharC : public SvbaseCharC
{
public:
	SvecCharC() = default;
	explicit SvecCharC(Long_I N);
	SvecCharC(const Char *data, Long_I N); // unsafe
	SvecCharC &operator=(const SvecCharC &rhs) = delete;
};

inline SvecCharC::SvecCharC(Long_I N) : SvbaseCharC(N)
{}

inline SvecCharC::SvecCharC(const Char *data, Long_I N)
	: SvbaseCharC(data, N) {}


typedef const SvecCharC &SvecChar_I;

// common api for STL and SLISC
inline Long size(SvecChar_I v) { return v.size(); }

inline const Char *p(SvecChar_I v) { return v.p(); }



class SvecChar : public SvbaseChar
{
public:
	SvecChar() = default;
	explicit SvecChar(Long_I N);
	SvecChar(Char *data, Long_I N); // unsafe
	SvecChar &operator=(const SvecChar &rhs) = delete;
	operator SvecCharC() const;
};

inline SvecChar::SvecChar(Long_I N) : SvbaseChar(N)
{}

inline SvecChar::SvecChar(Char *data, Long_I N)
	: SvbaseChar(data, N) {}

inline SvecChar::operator SvecCharC() const
{
	return *((SvecCharC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecChar &SvecChar_O, &SvecChar_IO;

// common api for STL and SLISC
inline Char *p(SvecChar &v) { return v.p(); }


class SvecUcharC : public SvbaseUcharC
{
public:
	SvecUcharC() = default;
	explicit SvecUcharC(Long_I N);
	SvecUcharC(const Uchar *data, Long_I N); // unsafe
	SvecUcharC &operator=(const SvecUcharC &rhs) = delete;
};

inline SvecUcharC::SvecUcharC(Long_I N) : SvbaseUcharC(N)
{}

inline SvecUcharC::SvecUcharC(const Uchar *data, Long_I N)
	: SvbaseUcharC(data, N) {}


typedef const SvecUcharC &SvecUchar_I;

// common api for STL and SLISC
inline Long size(SvecUchar_I v) { return v.size(); }

inline const Uchar *p(SvecUchar_I v) { return v.p(); }



class SvecUchar : public SvbaseUchar
{
public:
	SvecUchar() = default;
	explicit SvecUchar(Long_I N);
	SvecUchar(Uchar *data, Long_I N); // unsafe
	SvecUchar &operator=(const SvecUchar &rhs) = delete;
	operator SvecUcharC() const;
};

inline SvecUchar::SvecUchar(Long_I N) : SvbaseUchar(N)
{}

inline SvecUchar::SvecUchar(Uchar *data, Long_I N)
	: SvbaseUchar(data, N) {}

inline SvecUchar::operator SvecUcharC() const
{
	return *((SvecUcharC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecUchar &SvecUchar_O, &SvecUchar_IO;

// common api for STL and SLISC
inline Uchar *p(SvecUchar &v) { return v.p(); }


class SvecIntC : public SvbaseIntC
{
public:
	SvecIntC() = default;
	explicit SvecIntC(Long_I N);
	SvecIntC(const Int *data, Long_I N); // unsafe
	SvecIntC &operator=(const SvecIntC &rhs) = delete;
};

inline SvecIntC::SvecIntC(Long_I N) : SvbaseIntC(N)
{}

inline SvecIntC::SvecIntC(const Int *data, Long_I N)
	: SvbaseIntC(data, N) {}


typedef const SvecIntC &SvecInt_I;

// common api for STL and SLISC
inline Long size(SvecInt_I v) { return v.size(); }

inline const Int *p(SvecInt_I v) { return v.p(); }



class SvecInt : public SvbaseInt
{
public:
	SvecInt() = default;
	explicit SvecInt(Long_I N);
	SvecInt(Int *data, Long_I N); // unsafe
	SvecInt &operator=(const SvecInt &rhs) = delete;
	operator SvecIntC() const;
};

inline SvecInt::SvecInt(Long_I N) : SvbaseInt(N)
{}

inline SvecInt::SvecInt(Int *data, Long_I N)
	: SvbaseInt(data, N) {}

inline SvecInt::operator SvecIntC() const
{
	return *((SvecIntC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecInt &SvecInt_O, &SvecInt_IO;

// common api for STL and SLISC
inline Int *p(SvecInt &v) { return v.p(); }


class SvecLlongC : public SvbaseLlongC
{
public:
	SvecLlongC() = default;
	explicit SvecLlongC(Long_I N);
	SvecLlongC(const Llong *data, Long_I N); // unsafe
	SvecLlongC &operator=(const SvecLlongC &rhs) = delete;
};

inline SvecLlongC::SvecLlongC(Long_I N) : SvbaseLlongC(N)
{}

inline SvecLlongC::SvecLlongC(const Llong *data, Long_I N)
	: SvbaseLlongC(data, N) {}


typedef const SvecLlongC &SvecLlong_I;

// common api for STL and SLISC
inline Long size(SvecLlong_I v) { return v.size(); }

inline const Llong *p(SvecLlong_I v) { return v.p(); }



class SvecLlong : public SvbaseLlong
{
public:
	SvecLlong() = default;
	explicit SvecLlong(Long_I N);
	SvecLlong(Llong *data, Long_I N); // unsafe
	SvecLlong &operator=(const SvecLlong &rhs) = delete;
	operator SvecLlongC() const;
};

inline SvecLlong::SvecLlong(Long_I N) : SvbaseLlong(N)
{}

inline SvecLlong::SvecLlong(Llong *data, Long_I N)
	: SvbaseLlong(data, N) {}

inline SvecLlong::operator SvecLlongC() const
{
	return *((SvecLlongC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLlong &SvecLlong_O, &SvecLlong_IO;

// common api for STL and SLISC
inline Llong *p(SvecLlong &v) { return v.p(); }


class SvecFloatC : public SvbaseFloatC
{
public:
	SvecFloatC() = default;
	explicit SvecFloatC(Long_I N);
	SvecFloatC(const Float *data, Long_I N); // unsafe
	SvecFloatC &operator=(const SvecFloatC &rhs) = delete;
};

inline SvecFloatC::SvecFloatC(Long_I N) : SvbaseFloatC(N)
{}

inline SvecFloatC::SvecFloatC(const Float *data, Long_I N)
	: SvbaseFloatC(data, N) {}


typedef const SvecFloatC &SvecFloat_I;

// common api for STL and SLISC
inline Long size(SvecFloat_I v) { return v.size(); }

inline const Float *p(SvecFloat_I v) { return v.p(); }



class SvecFloat : public SvbaseFloat
{
public:
	SvecFloat() = default;
	explicit SvecFloat(Long_I N);
	SvecFloat(Float *data, Long_I N); // unsafe
	SvecFloat &operator=(const SvecFloat &rhs) = delete;
	operator SvecFloatC() const;
};

inline SvecFloat::SvecFloat(Long_I N) : SvbaseFloat(N)
{}

inline SvecFloat::SvecFloat(Float *data, Long_I N)
	: SvbaseFloat(data, N) {}

inline SvecFloat::operator SvecFloatC() const
{
	return *((SvecFloatC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecFloat &SvecFloat_O, &SvecFloat_IO;

// common api for STL and SLISC
inline Float *p(SvecFloat &v) { return v.p(); }


class SvecDoubC : public SvbaseDoubC
{
public:
	SvecDoubC() = default;
	explicit SvecDoubC(Long_I N);
	SvecDoubC(const Doub *data, Long_I N); // unsafe
	SvecDoubC &operator=(const SvecDoubC &rhs) = delete;
};

inline SvecDoubC::SvecDoubC(Long_I N) : SvbaseDoubC(N)
{}

inline SvecDoubC::SvecDoubC(const Doub *data, Long_I N)
	: SvbaseDoubC(data, N) {}


typedef const SvecDoubC &SvecDoub_I;

// common api for STL and SLISC
inline Long size(SvecDoub_I v) { return v.size(); }

inline const Doub *p(SvecDoub_I v) { return v.p(); }



class SvecDoub : public SvbaseDoub
{
public:
	SvecDoub() = default;
	explicit SvecDoub(Long_I N);
	SvecDoub(Doub *data, Long_I N); // unsafe
	SvecDoub &operator=(const SvecDoub &rhs) = delete;
	operator SvecDoubC() const;
};

inline SvecDoub::SvecDoub(Long_I N) : SvbaseDoub(N)
{}

inline SvecDoub::SvecDoub(Doub *data, Long_I N)
	: SvbaseDoub(data, N) {}

inline SvecDoub::operator SvecDoubC() const
{
	return *((SvecDoubC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecDoub &SvecDoub_O, &SvecDoub_IO;

// common api for STL and SLISC
inline Doub *p(SvecDoub &v) { return v.p(); }


class SvecLdoubC : public SvbaseLdoubC
{
public:
	SvecLdoubC() = default;
	explicit SvecLdoubC(Long_I N);
	SvecLdoubC(const Ldoub *data, Long_I N); // unsafe
	SvecLdoubC &operator=(const SvecLdoubC &rhs) = delete;
};

inline SvecLdoubC::SvecLdoubC(Long_I N) : SvbaseLdoubC(N)
{}

inline SvecLdoubC::SvecLdoubC(const Ldoub *data, Long_I N)
	: SvbaseLdoubC(data, N) {}


typedef const SvecLdoubC &SvecLdoub_I;

// common api for STL and SLISC
inline Long size(SvecLdoub_I v) { return v.size(); }

inline const Ldoub *p(SvecLdoub_I v) { return v.p(); }



class SvecLdoub : public SvbaseLdoub
{
public:
	SvecLdoub() = default;
	explicit SvecLdoub(Long_I N);
	SvecLdoub(Ldoub *data, Long_I N); // unsafe
	SvecLdoub &operator=(const SvecLdoub &rhs) = delete;
	operator SvecLdoubC() const;
};

inline SvecLdoub::SvecLdoub(Long_I N) : SvbaseLdoub(N)
{}

inline SvecLdoub::SvecLdoub(Ldoub *data, Long_I N)
	: SvbaseLdoub(data, N) {}

inline SvecLdoub::operator SvecLdoubC() const
{
	return *((SvecLdoubC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLdoub &SvecLdoub_O, &SvecLdoub_IO;

// common api for STL and SLISC
inline Ldoub *p(SvecLdoub &v) { return v.p(); }




class SvecFcompC : public SvbaseFcompC
{
public:
	SvecFcompC() = default;
	explicit SvecFcompC(Long_I N);
	SvecFcompC(const Fcomp *data, Long_I N); // unsafe
	SvecFcompC &operator=(const SvecFcompC &rhs) = delete;
};

inline SvecFcompC::SvecFcompC(Long_I N) : SvbaseFcompC(N)
{}

inline SvecFcompC::SvecFcompC(const Fcomp *data, Long_I N)
	: SvbaseFcompC(data, N) {}


typedef const SvecFcompC &SvecFcomp_I;

// common api for STL and SLISC
inline Long size(SvecFcomp_I v) { return v.size(); }

inline const Fcomp *p(SvecFcomp_I v) { return v.p(); }



class SvecFcomp : public SvbaseFcomp
{
public:
	SvecFcomp() = default;
	explicit SvecFcomp(Long_I N);
	SvecFcomp(Fcomp *data, Long_I N); // unsafe
	SvecFcomp &operator=(const SvecFcomp &rhs) = delete;
	operator SvecFcompC() const;
};

inline SvecFcomp::SvecFcomp(Long_I N) : SvbaseFcomp(N)
{}

inline SvecFcomp::SvecFcomp(Fcomp *data, Long_I N)
	: SvbaseFcomp(data, N) {}

inline SvecFcomp::operator SvecFcompC() const
{
	return *((SvecFcompC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecFcomp &SvecFcomp_O, &SvecFcomp_IO;

// common api for STL and SLISC
inline Fcomp *p(SvecFcomp &v) { return v.p(); }


class SvecCompC : public SvbaseCompC
{
public:
	SvecCompC() = default;
	explicit SvecCompC(Long_I N);
	SvecCompC(const Comp *data, Long_I N); // unsafe
	SvecCompC &operator=(const SvecCompC &rhs) = delete;
};

inline SvecCompC::SvecCompC(Long_I N) : SvbaseCompC(N)
{}

inline SvecCompC::SvecCompC(const Comp *data, Long_I N)
	: SvbaseCompC(data, N) {}


typedef const SvecCompC &SvecComp_I;

// common api for STL and SLISC
inline Long size(SvecComp_I v) { return v.size(); }

inline const Comp *p(SvecComp_I v) { return v.p(); }



class SvecComp : public SvbaseComp
{
public:
	SvecComp() = default;
	explicit SvecComp(Long_I N);
	SvecComp(Comp *data, Long_I N); // unsafe
	SvecComp &operator=(const SvecComp &rhs) = delete;
	operator SvecCompC() const;
};

inline SvecComp::SvecComp(Long_I N) : SvbaseComp(N)
{}

inline SvecComp::SvecComp(Comp *data, Long_I N)
	: SvbaseComp(data, N) {}

inline SvecComp::operator SvecCompC() const
{
	return *((SvecCompC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecComp &SvecComp_O, &SvecComp_IO;

// common api for STL and SLISC
inline Comp *p(SvecComp &v) { return v.p(); }


class SvecLcompC : public SvbaseLcompC
{
public:
	SvecLcompC() = default;
	explicit SvecLcompC(Long_I N);
	SvecLcompC(const Lcomp *data, Long_I N); // unsafe
	SvecLcompC &operator=(const SvecLcompC &rhs) = delete;
};

inline SvecLcompC::SvecLcompC(Long_I N) : SvbaseLcompC(N)
{}

inline SvecLcompC::SvecLcompC(const Lcomp *data, Long_I N)
	: SvbaseLcompC(data, N) {}


typedef const SvecLcompC &SvecLcomp_I;

// common api for STL and SLISC
inline Long size(SvecLcomp_I v) { return v.size(); }

inline const Lcomp *p(SvecLcomp_I v) { return v.p(); }



class SvecLcomp : public SvbaseLcomp
{
public:
	SvecLcomp() = default;
	explicit SvecLcomp(Long_I N);
	SvecLcomp(Lcomp *data, Long_I N); // unsafe
	SvecLcomp &operator=(const SvecLcomp &rhs) = delete;
	operator SvecLcompC() const;
};

inline SvecLcomp::SvecLcomp(Long_I N) : SvbaseLcomp(N)
{}

inline SvecLcomp::SvecLcomp(Lcomp *data, Long_I N)
	: SvbaseLcomp(data, N) {}

inline SvecLcomp::operator SvecLcompC() const
{
	return *((SvecLcompC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLcomp &SvecLcomp_O, &SvecLcomp_IO;

// common api for STL and SLISC
inline Lcomp *p(SvecLcomp &v) { return v.p(); }




class SvecFimagC : public SvbaseFimagC
{
public:
	SvecFimagC() = default;
	explicit SvecFimagC(Long_I N);
	SvecFimagC(const Fimag *data, Long_I N); // unsafe
	SvecFimagC &operator=(const SvecFimagC &rhs) = delete;
};

inline SvecFimagC::SvecFimagC(Long_I N) : SvbaseFimagC(N)
{}

inline SvecFimagC::SvecFimagC(const Fimag *data, Long_I N)
	: SvbaseFimagC(data, N) {}


typedef const SvecFimagC &SvecFimag_I;

// common api for STL and SLISC
inline Long size(SvecFimag_I v) { return v.size(); }

inline const Fimag *p(SvecFimag_I v) { return v.p(); }



class SvecFimag : public SvbaseFimag
{
public:
	SvecFimag() = default;
	explicit SvecFimag(Long_I N);
	SvecFimag(Fimag *data, Long_I N); // unsafe
	SvecFimag &operator=(const SvecFimag &rhs) = delete;
	operator SvecFimagC() const;
};

inline SvecFimag::SvecFimag(Long_I N) : SvbaseFimag(N)
{}

inline SvecFimag::SvecFimag(Fimag *data, Long_I N)
	: SvbaseFimag(data, N) {}

inline SvecFimag::operator SvecFimagC() const
{
	return *((SvecFimagC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecFimag &SvecFimag_O, &SvecFimag_IO;

// common api for STL and SLISC
inline Fimag *p(SvecFimag &v) { return v.p(); }


class SvecImagC : public SvbaseImagC
{
public:
	SvecImagC() = default;
	explicit SvecImagC(Long_I N);
	SvecImagC(const Imag *data, Long_I N); // unsafe
	SvecImagC &operator=(const SvecImagC &rhs) = delete;
};

inline SvecImagC::SvecImagC(Long_I N) : SvbaseImagC(N)
{}

inline SvecImagC::SvecImagC(const Imag *data, Long_I N)
	: SvbaseImagC(data, N) {}


typedef const SvecImagC &SvecImag_I;

// common api for STL and SLISC
inline Long size(SvecImag_I v) { return v.size(); }

inline const Imag *p(SvecImag_I v) { return v.p(); }



class SvecImag : public SvbaseImag
{
public:
	SvecImag() = default;
	explicit SvecImag(Long_I N);
	SvecImag(Imag *data, Long_I N); // unsafe
	SvecImag &operator=(const SvecImag &rhs) = delete;
	operator SvecImagC() const;
};

inline SvecImag::SvecImag(Long_I N) : SvbaseImag(N)
{}

inline SvecImag::SvecImag(Imag *data, Long_I N)
	: SvbaseImag(data, N) {}

inline SvecImag::operator SvecImagC() const
{
	return *((SvecImagC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecImag &SvecImag_O, &SvecImag_IO;

// common api for STL and SLISC
inline Imag *p(SvecImag &v) { return v.p(); }


class SvecLimagC : public SvbaseLimagC
{
public:
	SvecLimagC() = default;
	explicit SvecLimagC(Long_I N);
	SvecLimagC(const Limag *data, Long_I N); // unsafe
	SvecLimagC &operator=(const SvecLimagC &rhs) = delete;
};

inline SvecLimagC::SvecLimagC(Long_I N) : SvbaseLimagC(N)
{}

inline SvecLimagC::SvecLimagC(const Limag *data, Long_I N)
	: SvbaseLimagC(data, N) {}


typedef const SvecLimagC &SvecLimag_I;

// common api for STL and SLISC
inline Long size(SvecLimag_I v) { return v.size(); }

inline const Limag *p(SvecLimag_I v) { return v.p(); }



class SvecLimag : public SvbaseLimag
{
public:
	SvecLimag() = default;
	explicit SvecLimag(Long_I N);
	SvecLimag(Limag *data, Long_I N); // unsafe
	SvecLimag &operator=(const SvecLimag &rhs) = delete;
	operator SvecLimagC() const;
};

inline SvecLimag::SvecLimag(Long_I N) : SvbaseLimag(N)
{}

inline SvecLimag::SvecLimag(Limag *data, Long_I N)
	: SvbaseLimag(data, N) {}

inline SvecLimag::operator SvecLimagC() const
{
	return *((SvecLimagC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLimag &SvecLimag_O, &SvecLimag_IO;

// common api for STL and SLISC
inline Limag *p(SvecLimag &v) { return v.p(); }



#ifdef SLS_USE_INT_AS_LONG
typedef SvecInt SvecLong;
typedef SvecIntC SvecLongC;
#else
typedef SvecLlong SvecLong;
typedef SvecLlongC SvecLongC;
#endif
typedef const SvecLongC &SvecLong_I;
// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLong &SvecLong_O, &SvecLong_IO;

} // namespace slisc
