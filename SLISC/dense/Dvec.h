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
	DvecCharC(const DvecCharC &v) = default; // copy constructor (shalow)
	DvecCharC &operator=(const DvecCharC &v) = default; // copy assignment (shalow)

	const Char* p() const;
	Long size() const;
	Long step() const;
	const Char &operator[](Long_I i) const;
	const Char &end() const;
	const Char &end(Long_I i) const;


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

inline Long size(const DvecCharC &v) { return v.size(); }

class DvecChar
{
protected:
	Char *m_p;
	Long m_N;
	Long m_step;
public:
	DvecChar();
	DvecChar(Char *p, Long_I N, Long_I step);
	DvecChar(const DvecChar &v) = default; // copy constructor (shalow)
	DvecChar &operator=(const DvecChar &v) = default; // copy assignment (shalow)

	Char* p() const;
	Long size() const;
	Long step() const;
	Char &operator[](Long_I i) const;
	Char &end() const;
	Char &end(Long_I i) const;

	operator DvecCharC() const;

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

inline Long size(const DvecChar &v) { return v.size(); }

class DvecUcharC
{
protected:
	const Uchar *m_p;
	Long m_N;
	Long m_step;
public:
	DvecUcharC();
	DvecUcharC(const Uchar *p, Long_I N, Long_I step);
	DvecUcharC(const DvecUcharC &v) = default; // copy constructor (shalow)
	DvecUcharC &operator=(const DvecUcharC &v) = default; // copy assignment (shalow)

	const Uchar* p() const;
	Long size() const;
	Long step() const;
	const Uchar &operator[](Long_I i) const;
	const Uchar &end() const;
	const Uchar &end(Long_I i) const;


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

inline Long size(const DvecUcharC &v) { return v.size(); }

class DvecUchar
{
protected:
	Uchar *m_p;
	Long m_N;
	Long m_step;
public:
	DvecUchar();
	DvecUchar(Uchar *p, Long_I N, Long_I step);
	DvecUchar(const DvecUchar &v) = default; // copy constructor (shalow)
	DvecUchar &operator=(const DvecUchar &v) = default; // copy assignment (shalow)

	Uchar* p() const;
	Long size() const;
	Long step() const;
	Uchar &operator[](Long_I i) const;
	Uchar &end() const;
	Uchar &end(Long_I i) const;

	operator DvecUcharC() const;

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

inline Long size(const DvecUchar &v) { return v.size(); }

class DvecIntC
{
protected:
	const Int *m_p;
	Long m_N;
	Long m_step;
public:
	DvecIntC();
	DvecIntC(const Int *p, Long_I N, Long_I step);
	DvecIntC(const DvecIntC &v) = default; // copy constructor (shalow)
	DvecIntC &operator=(const DvecIntC &v) = default; // copy assignment (shalow)

	const Int* p() const;
	Long size() const;
	Long step() const;
	const Int &operator[](Long_I i) const;
	const Int &end() const;
	const Int &end(Long_I i) const;


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

inline Long size(const DvecIntC &v) { return v.size(); }

class DvecInt
{
protected:
	Int *m_p;
	Long m_N;
	Long m_step;
public:
	DvecInt();
	DvecInt(Int *p, Long_I N, Long_I step);
	DvecInt(const DvecInt &v) = default; // copy constructor (shalow)
	DvecInt &operator=(const DvecInt &v) = default; // copy assignment (shalow)

	Int* p() const;
	Long size() const;
	Long step() const;
	Int &operator[](Long_I i) const;
	Int &end() const;
	Int &end(Long_I i) const;

	operator DvecIntC() const;

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

inline Long size(const DvecInt &v) { return v.size(); }

class DvecLlongC
{
protected:
	const Llong *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLlongC();
	DvecLlongC(const Llong *p, Long_I N, Long_I step);
	DvecLlongC(const DvecLlongC &v) = default; // copy constructor (shalow)
	DvecLlongC &operator=(const DvecLlongC &v) = default; // copy assignment (shalow)

	const Llong* p() const;
	Long size() const;
	Long step() const;
	const Llong &operator[](Long_I i) const;
	const Llong &end() const;
	const Llong &end(Long_I i) const;


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

inline Long size(const DvecLlongC &v) { return v.size(); }

class DvecLlong
{
protected:
	Llong *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLlong();
	DvecLlong(Llong *p, Long_I N, Long_I step);
	DvecLlong(const DvecLlong &v) = default; // copy constructor (shalow)
	DvecLlong &operator=(const DvecLlong &v) = default; // copy assignment (shalow)

	Llong* p() const;
	Long size() const;
	Long step() const;
	Llong &operator[](Long_I i) const;
	Llong &end() const;
	Llong &end(Long_I i) const;

	operator DvecLlongC() const;

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

inline Long size(const DvecLlong &v) { return v.size(); }

class DvecFloatC
{
protected:
	const Float *m_p;
	Long m_N;
	Long m_step;
public:
	DvecFloatC();
	DvecFloatC(const Float *p, Long_I N, Long_I step);
	DvecFloatC(const DvecFloatC &v) = default; // copy constructor (shalow)
	DvecFloatC &operator=(const DvecFloatC &v) = default; // copy assignment (shalow)

	const Float* p() const;
	Long size() const;
	Long step() const;
	const Float &operator[](Long_I i) const;
	const Float &end() const;
	const Float &end(Long_I i) const;


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

inline Long size(const DvecFloatC &v) { return v.size(); }

class DvecFloat
{
protected:
	Float *m_p;
	Long m_N;
	Long m_step;
public:
	DvecFloat();
	DvecFloat(Float *p, Long_I N, Long_I step);
	DvecFloat(const DvecFloat &v) = default; // copy constructor (shalow)
	DvecFloat &operator=(const DvecFloat &v) = default; // copy assignment (shalow)

	Float* p() const;
	Long size() const;
	Long step() const;
	Float &operator[](Long_I i) const;
	Float &end() const;
	Float &end(Long_I i) const;

	operator DvecFloatC() const;

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

inline Long size(const DvecFloat &v) { return v.size(); }

class DvecDoubC
{
protected:
	const Doub *m_p;
	Long m_N;
	Long m_step;
public:
	DvecDoubC();
	DvecDoubC(const Doub *p, Long_I N, Long_I step);
	DvecDoubC(const DvecDoubC &v) = default; // copy constructor (shalow)
	DvecDoubC &operator=(const DvecDoubC &v) = default; // copy assignment (shalow)

	const Doub* p() const;
	Long size() const;
	Long step() const;
	const Doub &operator[](Long_I i) const;
	const Doub &end() const;
	const Doub &end(Long_I i) const;


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

inline Long size(const DvecDoubC &v) { return v.size(); }

class DvecDoub
{
protected:
	Doub *m_p;
	Long m_N;
	Long m_step;
public:
	DvecDoub();
	DvecDoub(Doub *p, Long_I N, Long_I step);
	DvecDoub(const DvecDoub &v) = default; // copy constructor (shalow)
	DvecDoub &operator=(const DvecDoub &v) = default; // copy assignment (shalow)

	Doub* p() const;
	Long size() const;
	Long step() const;
	Doub &operator[](Long_I i) const;
	Doub &end() const;
	Doub &end(Long_I i) const;

	operator DvecDoubC() const;

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

inline Long size(const DvecDoub &v) { return v.size(); }

class DvecLdoubC
{
protected:
	const Ldoub *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLdoubC();
	DvecLdoubC(const Ldoub *p, Long_I N, Long_I step);
	DvecLdoubC(const DvecLdoubC &v) = default; // copy constructor (shalow)
	DvecLdoubC &operator=(const DvecLdoubC &v) = default; // copy assignment (shalow)

	const Ldoub* p() const;
	Long size() const;
	Long step() const;
	const Ldoub &operator[](Long_I i) const;
	const Ldoub &end() const;
	const Ldoub &end(Long_I i) const;


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

inline Long size(const DvecLdoubC &v) { return v.size(); }

class DvecLdoub
{
protected:
	Ldoub *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLdoub();
	DvecLdoub(Ldoub *p, Long_I N, Long_I step);
	DvecLdoub(const DvecLdoub &v) = default; // copy constructor (shalow)
	DvecLdoub &operator=(const DvecLdoub &v) = default; // copy assignment (shalow)

	Ldoub* p() const;
	Long size() const;
	Long step() const;
	Ldoub &operator[](Long_I i) const;
	Ldoub &end() const;
	Ldoub &end(Long_I i) const;

	operator DvecLdoubC() const;

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

inline Long size(const DvecLdoub &v) { return v.size(); }



class DvecFcompC
{
protected:
	const Fcomp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecFcompC();
	DvecFcompC(const Fcomp *p, Long_I N, Long_I step);
	DvecFcompC(const DvecFcompC &v) = default; // copy constructor (shalow)
	DvecFcompC &operator=(const DvecFcompC &v) = default; // copy assignment (shalow)

	const Fcomp* p() const;
	Long size() const;
	Long step() const;
	const Fcomp &operator[](Long_I i) const;
	const Fcomp &end() const;
	const Fcomp &end(Long_I i) const;


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

inline Long size(const DvecFcompC &v) { return v.size(); }

class DvecFcomp
{
protected:
	Fcomp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecFcomp();
	DvecFcomp(Fcomp *p, Long_I N, Long_I step);
	DvecFcomp(const DvecFcomp &v) = default; // copy constructor (shalow)
	DvecFcomp &operator=(const DvecFcomp &v) = default; // copy assignment (shalow)

	Fcomp* p() const;
	Long size() const;
	Long step() const;
	Fcomp &operator[](Long_I i) const;
	Fcomp &end() const;
	Fcomp &end(Long_I i) const;

	operator DvecFcompC() const;

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

inline Long size(const DvecFcomp &v) { return v.size(); }

class DvecCompC
{
protected:
	const Comp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecCompC();
	DvecCompC(const Comp *p, Long_I N, Long_I step);
	DvecCompC(const DvecCompC &v) = default; // copy constructor (shalow)
	DvecCompC &operator=(const DvecCompC &v) = default; // copy assignment (shalow)

	const Comp* p() const;
	Long size() const;
	Long step() const;
	const Comp &operator[](Long_I i) const;
	const Comp &end() const;
	const Comp &end(Long_I i) const;


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

inline Long size(const DvecCompC &v) { return v.size(); }

class DvecComp
{
protected:
	Comp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecComp();
	DvecComp(Comp *p, Long_I N, Long_I step);
	DvecComp(const DvecComp &v) = default; // copy constructor (shalow)
	DvecComp &operator=(const DvecComp &v) = default; // copy assignment (shalow)

	Comp* p() const;
	Long size() const;
	Long step() const;
	Comp &operator[](Long_I i) const;
	Comp &end() const;
	Comp &end(Long_I i) const;

	operator DvecCompC() const;

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

inline Long size(const DvecComp &v) { return v.size(); }

class DvecLcompC
{
protected:
	const Lcomp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLcompC();
	DvecLcompC(const Lcomp *p, Long_I N, Long_I step);
	DvecLcompC(const DvecLcompC &v) = default; // copy constructor (shalow)
	DvecLcompC &operator=(const DvecLcompC &v) = default; // copy assignment (shalow)

	const Lcomp* p() const;
	Long size() const;
	Long step() const;
	const Lcomp &operator[](Long_I i) const;
	const Lcomp &end() const;
	const Lcomp &end(Long_I i) const;


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

inline Long size(const DvecLcompC &v) { return v.size(); }

class DvecLcomp
{
protected:
	Lcomp *m_p;
	Long m_N;
	Long m_step;
public:
	DvecLcomp();
	DvecLcomp(Lcomp *p, Long_I N, Long_I step);
	DvecLcomp(const DvecLcomp &v) = default; // copy constructor (shalow)
	DvecLcomp &operator=(const DvecLcomp &v) = default; // copy assignment (shalow)

	Lcomp* p() const;
	Long size() const;
	Long step() const;
	Lcomp &operator[](Long_I i) const;
	Lcomp &end() const;
	Lcomp &end(Long_I i) const;

	operator DvecLcompC() const;

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

inline Long size(const DvecLcomp &v) { return v.size(); }




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
