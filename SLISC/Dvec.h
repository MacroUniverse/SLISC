#pragma once
#include "global.h"

namespace slisc {
class DvecInt_c
{
protected:
    const Int *m_p;
    Long m_N;
    Long m_step;
public:
    DvecInt_c();
    DvecInt_c(const Int *ptr, Long_I N, Long_I step);
	const Int* ptr() const;
	const Int & operator[](Long_I i) const;
	const Int & operator()(Long_I i) const;
	const Int & end() const;
	const Int & end(Long_I i) const;
    Long size() const;
    Long step() const;

	DvecInt_c &operator=(const DvecInt_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
	void set_ptr(const Int *ptr);
	void set(const Int *ptr, Long_I N, Long_I step);
	void set(const DvecInt_c &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecInt_c();
};

inline DvecInt_c::DvecInt_c() {}

inline DvecInt_c::DvecInt_c(const Int *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline const Int * DvecInt_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long DvecInt_c::size() const
{
    return m_N;
}

inline Long DvecInt_c::step() const
{
    return m_step;
}

inline const Int & DvecInt_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Int & DvecInt_c::operator()(Long_I i) const
{ return (*this)[i]; }

inline const Int & DvecInt_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Int & DvecInt_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecInt_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecInt_c::set_ptr(const Int * ptr)
{
    m_p = ptr;
}

inline void DvecInt_c::set(const Int * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
}

inline void DvecInt_c::set(const DvecInt_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecInt_c::next()
{
    m_p += m_N;
}

inline void DvecInt_c::last()
{
    m_p -= m_N;
}

inline void DvecInt_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecInt_c::~DvecInt_c() {}


typedef const DvecInt_c & DvecInt_I;

class DvecInt
{
protected:
    Int *m_p;
    Long m_N;
    Long m_step;
public:
    DvecInt();
    DvecInt(Int *ptr, Long_I N, Long_I step);
	Int* ptr() const;
	Int & operator[](Long_I i) const;
	Int & operator()(Long_I i) const;
	Int & end() const;
	Int & end(Long_I i) const;
    Long size() const;
    Long step() const;

	operator DvecInt_c() const;
	DvecInt &operator=(const DvecInt &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
	void set_ptr(Int *ptr);
	void set(Int *ptr, Long_I N, Long_I step);
	void set(const DvecInt &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecInt();
};

inline DvecInt::DvecInt() {}

inline DvecInt::DvecInt(Int *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline Int * DvecInt::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline Int & DvecInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Int & DvecInt::operator()(Long_I i) const
{ return (*this)[i]; }

inline Int & DvecInt::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Int & DvecInt::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecInt::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline DvecInt::operator DvecInt_c() const
{
	return *((DvecInt_c *)this);
}

inline void DvecInt::set_ptr(Int * ptr)
{
    m_p = ptr;
}

inline void DvecInt::set(Int * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecInt & DvecInt_O, & DvecInt_IO;

class DvecLlong_c
{
protected:
    const Llong *m_p;
    Long m_N;
    Long m_step;
public:
    DvecLlong_c();
    DvecLlong_c(const Llong *ptr, Long_I N, Long_I step);
	const Llong* ptr() const;
	const Llong & operator[](Long_I i) const;
	const Llong & operator()(Long_I i) const;
	const Llong & end() const;
	const Llong & end(Long_I i) const;
    Long size() const;
    Long step() const;

	DvecLlong_c &operator=(const DvecLlong_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
	void set_ptr(const Llong *ptr);
	void set(const Llong *ptr, Long_I N, Long_I step);
	void set(const DvecLlong_c &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecLlong_c();
};

inline DvecLlong_c::DvecLlong_c() {}

inline DvecLlong_c::DvecLlong_c(const Llong *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline const Llong * DvecLlong_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long DvecLlong_c::size() const
{
    return m_N;
}

inline Long DvecLlong_c::step() const
{
    return m_step;
}

inline const Llong & DvecLlong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Llong & DvecLlong_c::operator()(Long_I i) const
{ return (*this)[i]; }

inline const Llong & DvecLlong_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Llong & DvecLlong_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecLlong_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecLlong_c::set_ptr(const Llong * ptr)
{
    m_p = ptr;
}

inline void DvecLlong_c::set(const Llong * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
}

inline void DvecLlong_c::set(const DvecLlong_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecLlong_c::next()
{
    m_p += m_N;
}

inline void DvecLlong_c::last()
{
    m_p -= m_N;
}

inline void DvecLlong_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecLlong_c::~DvecLlong_c() {}


typedef const DvecLlong_c & DvecLlong_I;

class DvecLlong
{
protected:
    Llong *m_p;
    Long m_N;
    Long m_step;
public:
    DvecLlong();
    DvecLlong(Llong *ptr, Long_I N, Long_I step);
	Llong* ptr() const;
	Llong & operator[](Long_I i) const;
	Llong & operator()(Long_I i) const;
	Llong & end() const;
	Llong & end(Long_I i) const;
    Long size() const;
    Long step() const;

	operator DvecLlong_c() const;
	DvecLlong &operator=(const DvecLlong &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
	void set_ptr(Llong *ptr);
	void set(Llong *ptr, Long_I N, Long_I step);
	void set(const DvecLlong &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecLlong();
};

inline DvecLlong::DvecLlong() {}

inline DvecLlong::DvecLlong(Llong *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline Llong * DvecLlong::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline Llong & DvecLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Llong & DvecLlong::operator()(Long_I i) const
{ return (*this)[i]; }

inline Llong & DvecLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Llong & DvecLlong::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecLlong::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline DvecLlong::operator DvecLlong_c() const
{
	return *((DvecLlong_c *)this);
}

inline void DvecLlong::set_ptr(Llong * ptr)
{
    m_p = ptr;
}

inline void DvecLlong::set(Llong * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecLlong & DvecLlong_O, & DvecLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef DvecInt_c DvecLong_c;
#else
typedef DvecLlong_c DvecLong_c;
#endif

typedef const DvecLong_c & DvecLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef DvecInt DvecLong;
#else
typedef DvecLlong DvecLong;
#endif

typedef const DvecLong & DvecLong_O, & DvecLong_IO;

class DvecDoub_c
{
protected:
    const Doub *m_p;
    Long m_N;
    Long m_step;
public:
    DvecDoub_c();
    DvecDoub_c(const Doub *ptr, Long_I N, Long_I step);
	const Doub* ptr() const;
	const Doub & operator[](Long_I i) const;
	const Doub & operator()(Long_I i) const;
	const Doub & end() const;
	const Doub & end(Long_I i) const;
    Long size() const;
    Long step() const;

	DvecDoub_c &operator=(const DvecDoub_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
	void set_ptr(const Doub *ptr);
	void set(const Doub *ptr, Long_I N, Long_I step);
	void set(const DvecDoub_c &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecDoub_c();
};

inline DvecDoub_c::DvecDoub_c() {}

inline DvecDoub_c::DvecDoub_c(const Doub *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline const Doub * DvecDoub_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long DvecDoub_c::size() const
{
    return m_N;
}

inline Long DvecDoub_c::step() const
{
    return m_step;
}

inline const Doub & DvecDoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Doub & DvecDoub_c::operator()(Long_I i) const
{ return (*this)[i]; }

inline const Doub & DvecDoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Doub & DvecDoub_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecDoub_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecDoub_c::set_ptr(const Doub * ptr)
{
    m_p = ptr;
}

inline void DvecDoub_c::set(const Doub * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
}

inline void DvecDoub_c::set(const DvecDoub_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecDoub_c::next()
{
    m_p += m_N;
}

inline void DvecDoub_c::last()
{
    m_p -= m_N;
}

inline void DvecDoub_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecDoub_c::~DvecDoub_c() {}


typedef const DvecDoub_c & DvecDoub_I;

class DvecDoub
{
protected:
    Doub *m_p;
    Long m_N;
    Long m_step;
public:
    DvecDoub();
    DvecDoub(Doub *ptr, Long_I N, Long_I step);
	Doub* ptr() const;
	Doub & operator[](Long_I i) const;
	Doub & operator()(Long_I i) const;
	Doub & end() const;
	Doub & end(Long_I i) const;
    Long size() const;
    Long step() const;

	operator DvecDoub_c() const;
	DvecDoub &operator=(const DvecDoub &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
	void set_ptr(Doub *ptr);
	void set(Doub *ptr, Long_I N, Long_I step);
	void set(const DvecDoub &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecDoub();
};

inline DvecDoub::DvecDoub() {}

inline DvecDoub::DvecDoub(Doub *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline Doub * DvecDoub::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline Doub & DvecDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Doub & DvecDoub::operator()(Long_I i) const
{ return (*this)[i]; }

inline Doub & DvecDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Doub & DvecDoub::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecDoub::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline DvecDoub::operator DvecDoub_c() const
{
	return *((DvecDoub_c *)this);
}

inline void DvecDoub::set_ptr(Doub * ptr)
{
    m_p = ptr;
}

inline void DvecDoub::set(Doub * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecDoub & DvecDoub_O, & DvecDoub_IO;

class DvecComp_c
{
protected:
    const Comp *m_p;
    Long m_N;
    Long m_step;
public:
    DvecComp_c();
    DvecComp_c(const Comp *ptr, Long_I N, Long_I step);
	const Comp* ptr() const;
	const Comp & operator[](Long_I i) const;
	const Comp & operator()(Long_I i) const;
	const Comp & end() const;
	const Comp & end(Long_I i) const;
    Long size() const;
    Long step() const;

	DvecComp_c &operator=(const DvecComp_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
	void set_ptr(const Comp *ptr);
	void set(const Comp *ptr, Long_I N, Long_I step);
	void set(const DvecComp_c &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecComp_c();
};

inline DvecComp_c::DvecComp_c() {}

inline DvecComp_c::DvecComp_c(const Comp *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline const Comp * DvecComp_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long DvecComp_c::size() const
{
    return m_N;
}

inline Long DvecComp_c::step() const
{
    return m_step;
}

inline const Comp & DvecComp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Comp & DvecComp_c::operator()(Long_I i) const
{ return (*this)[i]; }

inline const Comp & DvecComp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Comp & DvecComp_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecComp_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecComp_c::set_ptr(const Comp * ptr)
{
    m_p = ptr;
}

inline void DvecComp_c::set(const Comp * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
}

inline void DvecComp_c::set(const DvecComp_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecComp_c::next()
{
    m_p += m_N;
}

inline void DvecComp_c::last()
{
    m_p -= m_N;
}

inline void DvecComp_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecComp_c::~DvecComp_c() {}


typedef const DvecComp_c & DvecComp_I;

class DvecComp
{
protected:
    Comp *m_p;
    Long m_N;
    Long m_step;
public:
    DvecComp();
    DvecComp(Comp *ptr, Long_I N, Long_I step);
	Comp* ptr() const;
	Comp & operator[](Long_I i) const;
	Comp & operator()(Long_I i) const;
	Comp & end() const;
	Comp & end(Long_I i) const;
    Long size() const;
    Long step() const;

	operator DvecComp_c() const;
	DvecComp &operator=(const DvecComp &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
	void set_ptr(Comp *ptr);
	void set(Comp *ptr, Long_I N, Long_I step);
	void set(const DvecComp &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecComp();
};

inline DvecComp::DvecComp() {}

inline DvecComp::DvecComp(Comp *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline Comp * DvecComp::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline Comp & DvecComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Comp & DvecComp::operator()(Long_I i) const
{ return (*this)[i]; }

inline Comp & DvecComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Comp & DvecComp::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecComp::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline DvecComp::operator DvecComp_c() const
{
	return *((DvecComp_c *)this);
}

inline void DvecComp::set_ptr(Comp * ptr)
{
    m_p = ptr;
}

inline void DvecComp::set(Comp * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecComp & DvecComp_O, & DvecComp_IO;

} // namespace slisc
