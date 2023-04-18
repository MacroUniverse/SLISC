#pragma once
#include "../global.h"
// "C" means lower level const

namespace slisc {
class DvecCharC
{
protected:
	const Char *m_p;
	Long m_N;
	Long m_step;
public:
	DvecCharC();
	DvecCharC(const Char *p, Long_I N, Long_I step);
	const Char* p() const;
	const Char &operator[](Long_I i) const;
	const Char &end() const;
	const Char &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecCharC &operator=(const DvecCharC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Char *p);
	void set(const Char *p, Long_I N, Long_I step);
	void set(const DvecCharC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecCharC();
};

inline DvecCharC::DvecCharC() {}

inline DvecCharC::DvecCharC(const Char *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Char * DvecCharC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecCharC::size() const
{
	return m_N;
}

inline Long DvecCharC::step() const
{
	return m_step;
}

inline const Char &DvecCharC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Char &DvecCharC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Char &DvecCharC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecCharC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecCharC::set(const Char * p)
{
	m_p = p;
}

inline void DvecCharC::set(const Char * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecCharC::set(const DvecCharC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecCharC::next()
{
	m_p += m_N;
}

inline void DvecCharC::last()
{
	m_p -= m_N;
}

inline void DvecCharC::shift(Long_I N)
{
	m_p += N;
}

inline DvecCharC::~DvecCharC() {}


typedef const DvecCharC &DvecChar_I;

class DvecChar
{
protected:
	Char *m_p;
	Long m_N;
	Long m_step;
public:
	DvecChar();
	DvecChar(Char *p, Long_I N, Long_I step);
	Char* p() const;
	Char &operator[](Long_I i) const;
	Char &end() const;
	Char &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecCharC() const;
	DvecChar &operator=(const DvecChar &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Char *p);
	void set(Char *p, Long_I N, Long_I step);
	void set(const DvecChar &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecChar();
};

inline DvecChar::DvecChar() {}

inline DvecChar::DvecChar(Char *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Char * DvecChar::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecChar::size() const
{
	return m_N;
}

inline Long DvecChar::step() const
{
	return m_step;
}

inline Char &DvecChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Char &DvecChar::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Char &DvecChar::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecChar::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecChar::operator DvecCharC() const
{
	return *((DvecCharC *)this);
}

inline void DvecChar::set(Char * p)
{
	m_p = p;
}

inline void DvecChar::set(Char * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecChar::set(const DvecChar &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecChar::next()
{
	m_p += m_N;
}

inline void DvecChar::last()
{
	m_p -= m_N;
}

inline void DvecChar::shift(Long_I N)
{
	m_p += N;
}

inline DvecChar::~DvecChar() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecChar &DvecChar_O, &DvecChar_IO;

class DvecUcharC
{
protected:
	const Uchar *m_p;
	Long m_N;
	Long m_step;
public:
	DvecUcharC();
	DvecUcharC(const Uchar *p, Long_I N, Long_I step);
	const Uchar* p() const;
	const Uchar &operator[](Long_I i) const;
	const Uchar &end() const;
	const Uchar &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecUcharC &operator=(const DvecUcharC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Uchar *p);
	void set(const Uchar *p, Long_I N, Long_I step);
	void set(const DvecUcharC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecUcharC();
};

inline DvecUcharC::DvecUcharC() {}

inline DvecUcharC::DvecUcharC(const Uchar *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Uchar * DvecUcharC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecUcharC::size() const
{
	return m_N;
}

inline Long DvecUcharC::step() const
{
	return m_step;
}

inline const Uchar &DvecUcharC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Uchar &DvecUcharC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Uchar &DvecUcharC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecUcharC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecUcharC::set(const Uchar * p)
{
	m_p = p;
}

inline void DvecUcharC::set(const Uchar * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecUcharC::set(const DvecUcharC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecUcharC::next()
{
	m_p += m_N;
}

inline void DvecUcharC::last()
{
	m_p -= m_N;
}

inline void DvecUcharC::shift(Long_I N)
{
	m_p += N;
}

inline DvecUcharC::~DvecUcharC() {}


typedef const DvecUcharC &DvecUchar_I;

class DvecUchar
{
protected:
	Uchar *m_p;
	Long m_N;
	Long m_step;
public:
	DvecUchar();
	DvecUchar(Uchar *p, Long_I N, Long_I step);
	Uchar* p() const;
	Uchar &operator[](Long_I i) const;
	Uchar &end() const;
	Uchar &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecUcharC() const;
	DvecUchar &operator=(const DvecUchar &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Uchar *p);
	void set(Uchar *p, Long_I N, Long_I step);
	void set(const DvecUchar &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecUchar();
};

inline DvecUchar::DvecUchar() {}

inline DvecUchar::DvecUchar(Uchar *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Uchar * DvecUchar::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecUchar::size() const
{
	return m_N;
}

inline Long DvecUchar::step() const
{
	return m_step;
}

inline Uchar &DvecUchar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Uchar &DvecUchar::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Uchar &DvecUchar::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecUchar::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecUchar::operator DvecUcharC() const
{
	return *((DvecUcharC *)this);
}

inline void DvecUchar::set(Uchar * p)
{
	m_p = p;
}

inline void DvecUchar::set(Uchar * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecUchar::set(const DvecUchar &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecUchar::next()
{
	m_p += m_N;
}

inline void DvecUchar::last()
{
	m_p -= m_N;
}

inline void DvecUchar::shift(Long_I N)
{
	m_p += N;
}

inline DvecUchar::~DvecUchar() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecUchar &DvecUchar_O, &DvecUchar_IO;

class DvecIntC
{
protected:
	const Int *m_p;
	Long m_N;
	Long m_step;
public:
	DvecIntC();
	DvecIntC(const Int *p, Long_I N, Long_I step);
	const Int* p() const;
	const Int &operator[](Long_I i) const;
	const Int &end() const;
	const Int &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecIntC &operator=(const DvecIntC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Int *p);
	void set(const Int *p, Long_I N, Long_I step);
	void set(const DvecIntC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecIntC();
};

inline DvecIntC::DvecIntC() {}

inline DvecIntC::DvecIntC(const Int *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Int * DvecIntC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecIntC::size() const
{
	return m_N;
}

inline Long DvecIntC::step() const
{
	return m_step;
}

inline const Int &DvecIntC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Int &DvecIntC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Int &DvecIntC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecIntC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecIntC::set(const Int * p)
{
	m_p = p;
}

inline void DvecIntC::set(const Int * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecIntC::set(const DvecIntC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecIntC::next()
{
	m_p += m_N;
}

inline void DvecIntC::last()
{
	m_p -= m_N;
}

inline void DvecIntC::shift(Long_I N)
{
	m_p += N;
}

inline DvecIntC::~DvecIntC() {}


typedef const DvecIntC &DvecInt_I;

class DvecInt
{
protected:
	Int *m_p;
	Long m_N;
	Long m_step;
public:
	DvecInt();
	DvecInt(Int *p, Long_I N, Long_I step);
	Int* p() const;
	Int &operator[](Long_I i) const;
	Int &end() const;
	Int &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecIntC() const;
	DvecInt &operator=(const DvecInt &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Int *p);
	void set(Int *p, Long_I N, Long_I step);
	void set(const DvecInt &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecInt();
};

inline DvecInt::DvecInt() {}

inline DvecInt::DvecInt(Int *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Int * DvecInt::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecInt::size() const
{
	return m_N;
}

inline Long DvecInt::step() const
{
	return m_step;
}

inline Int &DvecInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Int &DvecInt::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Int &DvecInt::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecInt::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecInt::operator DvecIntC() const
{
	return *((DvecIntC *)this);
}

inline void DvecInt::set(Int * p)
{
	m_p = p;
}

inline void DvecInt::set(Int * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecInt::set(const DvecInt &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecInt::next()
{
	m_p += m_N;
}

inline void DvecInt::last()
{
	m_p -= m_N;
}

inline void DvecInt::shift(Long_I N)
{
	m_p += N;
}

inline DvecInt::~DvecInt() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecInt &DvecInt_O, &DvecInt_IO;

class DvecLlongC
{
protected:
	const Llong *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLlongC();
	DvecLlongC(const Llong *p, Long_I N, Long_I step);
	const Llong* p() const;
	const Llong &operator[](Long_I i) const;
	const Llong &end() const;
	const Llong &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecLlongC &operator=(const DvecLlongC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Llong *p);
	void set(const Llong *p, Long_I N, Long_I step);
	void set(const DvecLlongC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecLlongC();
};

inline DvecLlongC::DvecLlongC() {}

inline DvecLlongC::DvecLlongC(const Llong *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Llong * DvecLlongC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecLlongC::size() const
{
	return m_N;
}

inline Long DvecLlongC::step() const
{
	return m_step;
}

inline const Llong &DvecLlongC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Llong &DvecLlongC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Llong &DvecLlongC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecLlongC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecLlongC::set(const Llong * p)
{
	m_p = p;
}

inline void DvecLlongC::set(const Llong * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecLlongC::set(const DvecLlongC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecLlongC::next()
{
	m_p += m_N;
}

inline void DvecLlongC::last()
{
	m_p -= m_N;
}

inline void DvecLlongC::shift(Long_I N)
{
	m_p += N;
}

inline DvecLlongC::~DvecLlongC() {}


typedef const DvecLlongC &DvecLlong_I;

class DvecLlong
{
protected:
	Llong *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLlong();
	DvecLlong(Llong *p, Long_I N, Long_I step);
	Llong* p() const;
	Llong &operator[](Long_I i) const;
	Llong &end() const;
	Llong &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecLlongC() const;
	DvecLlong &operator=(const DvecLlong &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Llong *p);
	void set(Llong *p, Long_I N, Long_I step);
	void set(const DvecLlong &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecLlong();
};

inline DvecLlong::DvecLlong() {}

inline DvecLlong::DvecLlong(Llong *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Llong * DvecLlong::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecLlong::size() const
{
	return m_N;
}

inline Long DvecLlong::step() const
{
	return m_step;
}

inline Llong &DvecLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Llong &DvecLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Llong &DvecLlong::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecLlong::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecLlong::operator DvecLlongC() const
{
	return *((DvecLlongC *)this);
}

inline void DvecLlong::set(Llong * p)
{
	m_p = p;
}

inline void DvecLlong::set(Llong * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecLlong::set(const DvecLlong &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecLlong::next()
{
	m_p += m_N;
}

inline void DvecLlong::last()
{
	m_p -= m_N;
}

inline void DvecLlong::shift(Long_I N)
{
	m_p += N;
}

inline DvecLlong::~DvecLlong() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecLlong &DvecLlong_O, &DvecLlong_IO;

class DvecFloatC
{
protected:
	const Float *m_p;
	Long m_N;
	Long m_step;
public:
	DvecFloatC();
	DvecFloatC(const Float *p, Long_I N, Long_I step);
	const Float* p() const;
	const Float &operator[](Long_I i) const;
	const Float &end() const;
	const Float &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecFloatC &operator=(const DvecFloatC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Float *p);
	void set(const Float *p, Long_I N, Long_I step);
	void set(const DvecFloatC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecFloatC();
};

inline DvecFloatC::DvecFloatC() {}

inline DvecFloatC::DvecFloatC(const Float *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Float * DvecFloatC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecFloatC::size() const
{
	return m_N;
}

inline Long DvecFloatC::step() const
{
	return m_step;
}

inline const Float &DvecFloatC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Float &DvecFloatC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Float &DvecFloatC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecFloatC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecFloatC::set(const Float * p)
{
	m_p = p;
}

inline void DvecFloatC::set(const Float * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecFloatC::set(const DvecFloatC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecFloatC::next()
{
	m_p += m_N;
}

inline void DvecFloatC::last()
{
	m_p -= m_N;
}

inline void DvecFloatC::shift(Long_I N)
{
	m_p += N;
}

inline DvecFloatC::~DvecFloatC() {}


typedef const DvecFloatC &DvecFloat_I;

class DvecFloat
{
protected:
	Float *m_p;
	Long m_N;
	Long m_step;
public:
	DvecFloat();
	DvecFloat(Float *p, Long_I N, Long_I step);
	Float* p() const;
	Float &operator[](Long_I i) const;
	Float &end() const;
	Float &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecFloatC() const;
	DvecFloat &operator=(const DvecFloat &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Float *p);
	void set(Float *p, Long_I N, Long_I step);
	void set(const DvecFloat &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecFloat();
};

inline DvecFloat::DvecFloat() {}

inline DvecFloat::DvecFloat(Float *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Float * DvecFloat::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecFloat::size() const
{
	return m_N;
}

inline Long DvecFloat::step() const
{
	return m_step;
}

inline Float &DvecFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Float &DvecFloat::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Float &DvecFloat::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecFloat::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecFloat::operator DvecFloatC() const
{
	return *((DvecFloatC *)this);
}

inline void DvecFloat::set(Float * p)
{
	m_p = p;
}

inline void DvecFloat::set(Float * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecFloat::set(const DvecFloat &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecFloat::next()
{
	m_p += m_N;
}

inline void DvecFloat::last()
{
	m_p -= m_N;
}

inline void DvecFloat::shift(Long_I N)
{
	m_p += N;
}

inline DvecFloat::~DvecFloat() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecFloat &DvecFloat_O, &DvecFloat_IO;

class DvecDoubC
{
protected:
	const Doub *m_p;
	Long m_N;
	Long m_step;
public:
	DvecDoubC();
	DvecDoubC(const Doub *p, Long_I N, Long_I step);
	const Doub* p() const;
	const Doub &operator[](Long_I i) const;
	const Doub &end() const;
	const Doub &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecDoubC &operator=(const DvecDoubC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Doub *p);
	void set(const Doub *p, Long_I N, Long_I step);
	void set(const DvecDoubC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecDoubC();
};

inline DvecDoubC::DvecDoubC() {}

inline DvecDoubC::DvecDoubC(const Doub *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Doub * DvecDoubC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecDoubC::size() const
{
	return m_N;
}

inline Long DvecDoubC::step() const
{
	return m_step;
}

inline const Doub &DvecDoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Doub &DvecDoubC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Doub &DvecDoubC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecDoubC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecDoubC::set(const Doub * p)
{
	m_p = p;
}

inline void DvecDoubC::set(const Doub * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecDoubC::set(const DvecDoubC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecDoubC::next()
{
	m_p += m_N;
}

inline void DvecDoubC::last()
{
	m_p -= m_N;
}

inline void DvecDoubC::shift(Long_I N)
{
	m_p += N;
}

inline DvecDoubC::~DvecDoubC() {}


typedef const DvecDoubC &DvecDoub_I;

class DvecDoub
{
protected:
	Doub *m_p;
	Long m_N;
	Long m_step;
public:
	DvecDoub();
	DvecDoub(Doub *p, Long_I N, Long_I step);
	Doub* p() const;
	Doub &operator[](Long_I i) const;
	Doub &end() const;
	Doub &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecDoubC() const;
	DvecDoub &operator=(const DvecDoub &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Doub *p);
	void set(Doub *p, Long_I N, Long_I step);
	void set(const DvecDoub &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecDoub();
};

inline DvecDoub::DvecDoub() {}

inline DvecDoub::DvecDoub(Doub *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Doub * DvecDoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecDoub::size() const
{
	return m_N;
}

inline Long DvecDoub::step() const
{
	return m_step;
}

inline Doub &DvecDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Doub &DvecDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Doub &DvecDoub::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecDoub::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecDoub::operator DvecDoubC() const
{
	return *((DvecDoubC *)this);
}

inline void DvecDoub::set(Doub * p)
{
	m_p = p;
}

inline void DvecDoub::set(Doub * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecDoub::set(const DvecDoub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecDoub::next()
{
	m_p += m_N;
}

inline void DvecDoub::last()
{
	m_p -= m_N;
}

inline void DvecDoub::shift(Long_I N)
{
	m_p += N;
}

inline DvecDoub::~DvecDoub() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecDoub &DvecDoub_O, &DvecDoub_IO;

class DvecLdoubC
{
protected:
	const Ldoub *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLdoubC();
	DvecLdoubC(const Ldoub *p, Long_I N, Long_I step);
	const Ldoub* p() const;
	const Ldoub &operator[](Long_I i) const;
	const Ldoub &end() const;
	const Ldoub &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecLdoubC &operator=(const DvecLdoubC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Ldoub *p);
	void set(const Ldoub *p, Long_I N, Long_I step);
	void set(const DvecLdoubC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecLdoubC();
};

inline DvecLdoubC::DvecLdoubC() {}

inline DvecLdoubC::DvecLdoubC(const Ldoub *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Ldoub * DvecLdoubC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecLdoubC::size() const
{
	return m_N;
}

inline Long DvecLdoubC::step() const
{
	return m_step;
}

inline const Ldoub &DvecLdoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Ldoub &DvecLdoubC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Ldoub &DvecLdoubC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecLdoubC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecLdoubC::set(const Ldoub * p)
{
	m_p = p;
}

inline void DvecLdoubC::set(const Ldoub * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecLdoubC::set(const DvecLdoubC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecLdoubC::next()
{
	m_p += m_N;
}

inline void DvecLdoubC::last()
{
	m_p -= m_N;
}

inline void DvecLdoubC::shift(Long_I N)
{
	m_p += N;
}

inline DvecLdoubC::~DvecLdoubC() {}


typedef const DvecLdoubC &DvecLdoub_I;

class DvecLdoub
{
protected:
	Ldoub *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLdoub();
	DvecLdoub(Ldoub *p, Long_I N, Long_I step);
	Ldoub* p() const;
	Ldoub &operator[](Long_I i) const;
	Ldoub &end() const;
	Ldoub &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecLdoubC() const;
	DvecLdoub &operator=(const DvecLdoub &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Ldoub *p);
	void set(Ldoub *p, Long_I N, Long_I step);
	void set(const DvecLdoub &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecLdoub();
};

inline DvecLdoub::DvecLdoub() {}

inline DvecLdoub::DvecLdoub(Ldoub *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Ldoub * DvecLdoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecLdoub::size() const
{
	return m_N;
}

inline Long DvecLdoub::step() const
{
	return m_step;
}

inline Ldoub &DvecLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Ldoub &DvecLdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Ldoub &DvecLdoub::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecLdoub::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecLdoub::operator DvecLdoubC() const
{
	return *((DvecLdoubC *)this);
}

inline void DvecLdoub::set(Ldoub * p)
{
	m_p = p;
}

inline void DvecLdoub::set(Ldoub * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecLdoub::set(const DvecLdoub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecLdoub::next()
{
	m_p += m_N;
}

inline void DvecLdoub::last()
{
	m_p -= m_N;
}

inline void DvecLdoub::shift(Long_I N)
{
	m_p += N;
}

inline DvecLdoub::~DvecLdoub() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecLdoub &DvecLdoub_O, &DvecLdoub_IO;

class DvecQdoubC
{
protected:
	const Qdoub *m_p;
	Long m_N;
	Long m_step;
public:
	DvecQdoubC();
	DvecQdoubC(const Qdoub *p, Long_I N, Long_I step);
	const Qdoub* p() const;
	const Qdoub &operator[](Long_I i) const;
	const Qdoub &end() const;
	const Qdoub &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecQdoubC &operator=(const DvecQdoubC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Qdoub *p);
	void set(const Qdoub *p, Long_I N, Long_I step);
	void set(const DvecQdoubC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecQdoubC();
};

inline DvecQdoubC::DvecQdoubC() {}

inline DvecQdoubC::DvecQdoubC(const Qdoub *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Qdoub * DvecQdoubC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecQdoubC::size() const
{
	return m_N;
}

inline Long DvecQdoubC::step() const
{
	return m_step;
}

inline const Qdoub &DvecQdoubC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Qdoub &DvecQdoubC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Qdoub &DvecQdoubC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecQdoubC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecQdoubC::set(const Qdoub * p)
{
	m_p = p;
}

inline void DvecQdoubC::set(const Qdoub * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecQdoubC::set(const DvecQdoubC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecQdoubC::next()
{
	m_p += m_N;
}

inline void DvecQdoubC::last()
{
	m_p -= m_N;
}

inline void DvecQdoubC::shift(Long_I N)
{
	m_p += N;
}

inline DvecQdoubC::~DvecQdoubC() {}


typedef const DvecQdoubC &DvecQdoub_I;

class DvecQdoub
{
protected:
	Qdoub *m_p;
	Long m_N;
	Long m_step;
public:
	DvecQdoub();
	DvecQdoub(Qdoub *p, Long_I N, Long_I step);
	Qdoub* p() const;
	Qdoub &operator[](Long_I i) const;
	Qdoub &end() const;
	Qdoub &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecQdoubC() const;
	DvecQdoub &operator=(const DvecQdoub &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Qdoub *p);
	void set(Qdoub *p, Long_I N, Long_I step);
	void set(const DvecQdoub &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecQdoub();
};

inline DvecQdoub::DvecQdoub() {}

inline DvecQdoub::DvecQdoub(Qdoub *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Qdoub * DvecQdoub::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecQdoub::size() const
{
	return m_N;
}

inline Long DvecQdoub::step() const
{
	return m_step;
}

inline Qdoub &DvecQdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Qdoub &DvecQdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Qdoub &DvecQdoub::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecQdoub::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecQdoub::operator DvecQdoubC() const
{
	return *((DvecQdoubC *)this);
}

inline void DvecQdoub::set(Qdoub * p)
{
	m_p = p;
}

inline void DvecQdoub::set(Qdoub * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecQdoub::set(const DvecQdoub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecQdoub::next()
{
	m_p += m_N;
}

inline void DvecQdoub::last()
{
	m_p -= m_N;
}

inline void DvecQdoub::shift(Long_I N)
{
	m_p += N;
}

inline DvecQdoub::~DvecQdoub() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecQdoub &DvecQdoub_O, &DvecQdoub_IO;

class DvecFcompC
{
protected:
	const Fcomp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecFcompC();
	DvecFcompC(const Fcomp *p, Long_I N, Long_I step);
	const Fcomp* p() const;
	const Fcomp &operator[](Long_I i) const;
	const Fcomp &end() const;
	const Fcomp &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecFcompC &operator=(const DvecFcompC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Fcomp *p);
	void set(const Fcomp *p, Long_I N, Long_I step);
	void set(const DvecFcompC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecFcompC();
};

inline DvecFcompC::DvecFcompC() {}

inline DvecFcompC::DvecFcompC(const Fcomp *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Fcomp * DvecFcompC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecFcompC::size() const
{
	return m_N;
}

inline Long DvecFcompC::step() const
{
	return m_step;
}

inline const Fcomp &DvecFcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Fcomp &DvecFcompC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Fcomp &DvecFcompC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecFcompC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecFcompC::set(const Fcomp * p)
{
	m_p = p;
}

inline void DvecFcompC::set(const Fcomp * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecFcompC::set(const DvecFcompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecFcompC::next()
{
	m_p += m_N;
}

inline void DvecFcompC::last()
{
	m_p -= m_N;
}

inline void DvecFcompC::shift(Long_I N)
{
	m_p += N;
}

inline DvecFcompC::~DvecFcompC() {}


typedef const DvecFcompC &DvecFcomp_I;

class DvecFcomp
{
protected:
	Fcomp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecFcomp();
	DvecFcomp(Fcomp *p, Long_I N, Long_I step);
	Fcomp* p() const;
	Fcomp &operator[](Long_I i) const;
	Fcomp &end() const;
	Fcomp &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecFcompC() const;
	DvecFcomp &operator=(const DvecFcomp &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Fcomp *p);
	void set(Fcomp *p, Long_I N, Long_I step);
	void set(const DvecFcomp &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecFcomp();
};

inline DvecFcomp::DvecFcomp() {}

inline DvecFcomp::DvecFcomp(Fcomp *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Fcomp * DvecFcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecFcomp::size() const
{
	return m_N;
}

inline Long DvecFcomp::step() const
{
	return m_step;
}

inline Fcomp &DvecFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Fcomp &DvecFcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Fcomp &DvecFcomp::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecFcomp::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecFcomp::operator DvecFcompC() const
{
	return *((DvecFcompC *)this);
}

inline void DvecFcomp::set(Fcomp * p)
{
	m_p = p;
}

inline void DvecFcomp::set(Fcomp * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecFcomp::set(const DvecFcomp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecFcomp::next()
{
	m_p += m_N;
}

inline void DvecFcomp::last()
{
	m_p -= m_N;
}

inline void DvecFcomp::shift(Long_I N)
{
	m_p += N;
}

inline DvecFcomp::~DvecFcomp() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecFcomp &DvecFcomp_O, &DvecFcomp_IO;

class DvecCompC
{
protected:
	const Comp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecCompC();
	DvecCompC(const Comp *p, Long_I N, Long_I step);
	const Comp* p() const;
	const Comp &operator[](Long_I i) const;
	const Comp &end() const;
	const Comp &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecCompC &operator=(const DvecCompC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Comp *p);
	void set(const Comp *p, Long_I N, Long_I step);
	void set(const DvecCompC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecCompC();
};

inline DvecCompC::DvecCompC() {}

inline DvecCompC::DvecCompC(const Comp *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Comp * DvecCompC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecCompC::size() const
{
	return m_N;
}

inline Long DvecCompC::step() const
{
	return m_step;
}

inline const Comp &DvecCompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Comp &DvecCompC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Comp &DvecCompC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecCompC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecCompC::set(const Comp * p)
{
	m_p = p;
}

inline void DvecCompC::set(const Comp * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecCompC::set(const DvecCompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecCompC::next()
{
	m_p += m_N;
}

inline void DvecCompC::last()
{
	m_p -= m_N;
}

inline void DvecCompC::shift(Long_I N)
{
	m_p += N;
}

inline DvecCompC::~DvecCompC() {}


typedef const DvecCompC &DvecComp_I;

class DvecComp
{
protected:
	Comp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecComp();
	DvecComp(Comp *p, Long_I N, Long_I step);
	Comp* p() const;
	Comp &operator[](Long_I i) const;
	Comp &end() const;
	Comp &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecCompC() const;
	DvecComp &operator=(const DvecComp &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Comp *p);
	void set(Comp *p, Long_I N, Long_I step);
	void set(const DvecComp &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecComp();
};

inline DvecComp::DvecComp() {}

inline DvecComp::DvecComp(Comp *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Comp * DvecComp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecComp::size() const
{
	return m_N;
}

inline Long DvecComp::step() const
{
	return m_step;
}

inline Comp &DvecComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Comp &DvecComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Comp &DvecComp::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecComp::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecComp::operator DvecCompC() const
{
	return *((DvecCompC *)this);
}

inline void DvecComp::set(Comp * p)
{
	m_p = p;
}

inline void DvecComp::set(Comp * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecComp::set(const DvecComp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecComp::next()
{
	m_p += m_N;
}

inline void DvecComp::last()
{
	m_p -= m_N;
}

inline void DvecComp::shift(Long_I N)
{
	m_p += N;
}

inline DvecComp::~DvecComp() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecComp &DvecComp_O, &DvecComp_IO;

class DvecLcompC
{
protected:
	const Lcomp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLcompC();
	DvecLcompC(const Lcomp *p, Long_I N, Long_I step);
	const Lcomp* p() const;
	const Lcomp &operator[](Long_I i) const;
	const Lcomp &end() const;
	const Lcomp &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecLcompC &operator=(const DvecLcompC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Lcomp *p);
	void set(const Lcomp *p, Long_I N, Long_I step);
	void set(const DvecLcompC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecLcompC();
};

inline DvecLcompC::DvecLcompC() {}

inline DvecLcompC::DvecLcompC(const Lcomp *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Lcomp * DvecLcompC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecLcompC::size() const
{
	return m_N;
}

inline Long DvecLcompC::step() const
{
	return m_step;
}

inline const Lcomp &DvecLcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Lcomp &DvecLcompC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Lcomp &DvecLcompC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecLcompC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecLcompC::set(const Lcomp * p)
{
	m_p = p;
}

inline void DvecLcompC::set(const Lcomp * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecLcompC::set(const DvecLcompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecLcompC::next()
{
	m_p += m_N;
}

inline void DvecLcompC::last()
{
	m_p -= m_N;
}

inline void DvecLcompC::shift(Long_I N)
{
	m_p += N;
}

inline DvecLcompC::~DvecLcompC() {}


typedef const DvecLcompC &DvecLcomp_I;

class DvecLcomp
{
protected:
	Lcomp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLcomp();
	DvecLcomp(Lcomp *p, Long_I N, Long_I step);
	Lcomp* p() const;
	Lcomp &operator[](Long_I i) const;
	Lcomp &end() const;
	Lcomp &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecLcompC() const;
	DvecLcomp &operator=(const DvecLcomp &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Lcomp *p);
	void set(Lcomp *p, Long_I N, Long_I step);
	void set(const DvecLcomp &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecLcomp();
};

inline DvecLcomp::DvecLcomp() {}

inline DvecLcomp::DvecLcomp(Lcomp *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Lcomp * DvecLcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecLcomp::size() const
{
	return m_N;
}

inline Long DvecLcomp::step() const
{
	return m_step;
}

inline Lcomp &DvecLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Lcomp &DvecLcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Lcomp &DvecLcomp::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecLcomp::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecLcomp::operator DvecLcompC() const
{
	return *((DvecLcompC *)this);
}

inline void DvecLcomp::set(Lcomp * p)
{
	m_p = p;
}

inline void DvecLcomp::set(Lcomp * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecLcomp::set(const DvecLcomp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecLcomp::next()
{
	m_p += m_N;
}

inline void DvecLcomp::last()
{
	m_p -= m_N;
}

inline void DvecLcomp::shift(Long_I N)
{
	m_p += N;
}

inline DvecLcomp::~DvecLcomp() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecLcomp &DvecLcomp_O, &DvecLcomp_IO;

class DvecQcompC
{
protected:
	const Qcomp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecQcompC();
	DvecQcompC(const Qcomp *p, Long_I N, Long_I step);
	const Qcomp* p() const;
	const Qcomp &operator[](Long_I i) const;
	const Qcomp &end() const;
	const Qcomp &end(Long_I i) const;
	Long size() const;
	Long step() const;

	DvecQcompC &operator=(const DvecQcompC &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(const Qcomp *p);
	void set(const Qcomp *p, Long_I N, Long_I step);
	void set(const DvecQcompC &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecQcompC();
};

inline DvecQcompC::DvecQcompC() {}

inline DvecQcompC::DvecQcompC(const Qcomp *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline const Qcomp * DvecQcompC::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecQcompC::size() const
{
	return m_N;
}

inline Long DvecQcompC::step() const
{
	return m_step;
}

inline const Qcomp &DvecQcompC::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline const Qcomp &DvecQcompC::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline const Qcomp &DvecQcompC::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecQcompC::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}


inline void DvecQcompC::set(const Qcomp * p)
{
	m_p = p;
}

inline void DvecQcompC::set(const Qcomp * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecQcompC::set(const DvecQcompC &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecQcompC::next()
{
	m_p += m_N;
}

inline void DvecQcompC::last()
{
	m_p -= m_N;
}

inline void DvecQcompC::shift(Long_I N)
{
	m_p += N;
}

inline DvecQcompC::~DvecQcompC() {}


typedef const DvecQcompC &DvecQcomp_I;

class DvecQcomp
{
protected:
	Qcomp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecQcomp();
	DvecQcomp(Qcomp *p, Long_I N, Long_I step);
	Qcomp* p() const;
	Qcomp &operator[](Long_I i) const;
	Qcomp &end() const;
	Qcomp &end(Long_I i) const;
	Long size() const;
	Long step() const;

	operator DvecQcompC() const;
	DvecQcomp &operator=(const DvecQcomp &) = delete;
	// === other member functions ===
	// There is no bound checking, use with care
	void set(Qcomp *p);
	void set(Qcomp *p, Long_I N, Long_I step);
	void set(const DvecQcomp &sli);
	void set(Long_I N);
	void next(); // m_p += m_N
	void last(); // m_p -= m_N
	void shift(Long_I N); // m_p += N;
	
	~DvecQcomp();
};

inline DvecQcomp::DvecQcomp() {}

inline DvecQcomp::DvecQcomp(Qcomp *p, Long_I N, Long_I step)
	: m_p(p), m_N(N), m_step(step) {}

inline Qcomp * DvecQcomp::p() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("using p() for empty container!");
#endif
	return m_p;
}

inline Long DvecQcomp::size() const
{
	return m_N;
}

inline Long DvecQcomp::step() const
{
	return m_step;
}

inline Qcomp &DvecQcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N)
		SLS_ERR("Vbase subscript out of bounds");
#endif
	return m_p[m_step*i];
}

inline Qcomp &DvecQcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
	if (m_N == 0)
		SLS_ERR("tring to use end() on empty vector!");
#endif
	return m_p[m_step*(m_N - 1)];
}

inline Qcomp &DvecQcomp::end(Long_I i) const
{
	return m_p[m_step*(m_N - i)];
}

inline void DvecQcomp::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
	if (N <= 0) SLS_ERR("illegal N!");
#endif
	m_N = N;
}

inline DvecQcomp::operator DvecQcompC() const
{
	return *((DvecQcompC *)this);
}

inline void DvecQcomp::set(Qcomp * p)
{
	m_p = p;
}

inline void DvecQcomp::set(Qcomp * p, Long_I N, Long_I step)
{
	m_p = p; m_N = N; m_step = step;
}

inline void DvecQcomp::set(const DvecQcomp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecQcomp::next()
{
	m_p += m_N;
}

inline void DvecQcomp::last()
{
	m_p -= m_N;
}

inline void DvecQcomp::shift(Long_I N)
{
	m_p += N;
}

inline DvecQcomp::~DvecQcomp() {}


// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecQcomp &DvecQcomp_O, &DvecQcomp_IO;


#ifdef SLS_USE_INT_AS_LONG
typedef DvecInt DvecLong;
typedef DvecIntC DvecLongC;
#else
typedef DvecLlong DvecLong;
typedef DvecLlongC DvecLongC;
#endif
typedef const DvecLongC &DvecLong_I;
// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecLong &DvecLong_O, &DvecLong_IO;

} // namespace slisc
