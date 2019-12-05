#pragma once
#include "global.h"

namespace slisc {
class SvecChar_c
{
public:
    const Char *m_p;
    Long m_N;
    SvecChar_c();
    SvecChar_c(Long_I N);
    SvecChar_c(const Char *ptr, Long_I N);
	const Char* ptr() const;
    Long size() const;
    const Char & operator[](Long_I i) const;
    const Char & operator()(Long_I i) const;
    const Char & end() const;
    const Char & end(Long_I i) const;


    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Char *ptr);
    void set(const Char *ptr, Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecChar_c();
};

inline SvecChar_c::SvecChar_c() {}

inline SvecChar_c::SvecChar_c(Long_I N) : m_N(N) {}

inline SvecChar_c::SvecChar_c(const Char *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Char * SvecChar_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecChar_c::size() const
{
    return m_N;
}

inline const Char & SvecChar_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Char & SvecChar_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Char & SvecChar_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Char & SvecChar_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecChar_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecChar_c::set_ptr(const Char * ptr)
{
    m_p = ptr;
}

inline void SvecChar_c::set(const Char * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecChar_c::next()
{
    m_p += m_N;
}

inline void SvecChar_c::last()
{
    m_p -= m_N;
}

inline void SvecChar_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecChar_c::~SvecChar_c() {}

typedef const SvecChar_c & SvecChar_I;

class SvecChar
{
public:
    Char *m_p;
    Long m_N;
    SvecChar();
    SvecChar(Long_I N);
    SvecChar(Char *ptr, Long_I N);
	Char* ptr() const;
    Long size() const;
    Char & operator[](Long_I i) const;
    Char & operator()(Long_I i) const;
    Char & end() const;
    Char & end(Long_I i) const;

	operator SvecChar_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Char *ptr);
    void set(Char *ptr, Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecChar();
};

inline SvecChar::SvecChar() {}

inline SvecChar::SvecChar(Long_I N) : m_N(N) {}

inline SvecChar::SvecChar(Char *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Char * SvecChar::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecChar::size() const
{
    return m_N;
}

inline Char & SvecChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Char & SvecChar::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Char & SvecChar::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Char & SvecChar::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecChar::operator SvecChar_c() const
{
	return *((SvecChar_c *)this);
}

inline void SvecChar::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecChar::set_ptr(Char * ptr)
{
    m_p = ptr;
}

inline void SvecChar::set(Char * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecChar::next()
{
    m_p += m_N;
}

inline void SvecChar::last()
{
    m_p -= m_N;
}

inline void SvecChar::shift(Long_I N)
{
    m_p += N;
}

inline SvecChar::~SvecChar() {}

typedef const SvecChar & SvecChar_O, & SvecChar_IO;

class SvecInt_c
{
public:
    const Int *m_p;
    Long m_N;
    SvecInt_c();
    SvecInt_c(Long_I N);
    SvecInt_c(const Int *ptr, Long_I N);
	const Int* ptr() const;
    Long size() const;
    const Int & operator[](Long_I i) const;
    const Int & operator()(Long_I i) const;
    const Int & end() const;
    const Int & end(Long_I i) const;


    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Int *ptr);
    void set(const Int *ptr, Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecInt_c();
};

inline SvecInt_c::SvecInt_c() {}

inline SvecInt_c::SvecInt_c(Long_I N) : m_N(N) {}

inline SvecInt_c::SvecInt_c(const Int *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Int * SvecInt_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecInt_c::size() const
{
    return m_N;
}

inline const Int & SvecInt_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Int & SvecInt_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Int & SvecInt_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Int & SvecInt_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecInt_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecInt_c::set_ptr(const Int * ptr)
{
    m_p = ptr;
}

inline void SvecInt_c::set(const Int * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecInt_c::next()
{
    m_p += m_N;
}

inline void SvecInt_c::last()
{
    m_p -= m_N;
}

inline void SvecInt_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecInt_c::~SvecInt_c() {}

typedef const SvecInt_c & SvecInt_I;

class SvecInt
{
public:
    Int *m_p;
    Long m_N;
    SvecInt();
    SvecInt(Long_I N);
    SvecInt(Int *ptr, Long_I N);
	Int* ptr() const;
    Long size() const;
    Int & operator[](Long_I i) const;
    Int & operator()(Long_I i) const;
    Int & end() const;
    Int & end(Long_I i) const;

	operator SvecInt_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Int *ptr);
    void set(Int *ptr, Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecInt();
};

inline SvecInt::SvecInt() {}

inline SvecInt::SvecInt(Long_I N) : m_N(N) {}

inline SvecInt::SvecInt(Int *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Int * SvecInt::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecInt::size() const
{
    return m_N;
}

inline Int & SvecInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Int & SvecInt::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Int & SvecInt::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Int & SvecInt::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecInt::operator SvecInt_c() const
{
	return *((SvecInt_c *)this);
}

inline void SvecInt::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecInt::set_ptr(Int * ptr)
{
    m_p = ptr;
}

inline void SvecInt::set(Int * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecInt::next()
{
    m_p += m_N;
}

inline void SvecInt::last()
{
    m_p -= m_N;
}

inline void SvecInt::shift(Long_I N)
{
    m_p += N;
}

inline SvecInt::~SvecInt() {}

typedef const SvecInt & SvecInt_O, & SvecInt_IO;

class SvecLlong_c
{
public:
    const Llong *m_p;
    Long m_N;
    SvecLlong_c();
    SvecLlong_c(Long_I N);
    SvecLlong_c(const Llong *ptr, Long_I N);
	const Llong* ptr() const;
    Long size() const;
    const Llong & operator[](Long_I i) const;
    const Llong & operator()(Long_I i) const;
    const Llong & end() const;
    const Llong & end(Long_I i) const;


    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Llong *ptr);
    void set(const Llong *ptr, Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecLlong_c();
};

inline SvecLlong_c::SvecLlong_c() {}

inline SvecLlong_c::SvecLlong_c(Long_I N) : m_N(N) {}

inline SvecLlong_c::SvecLlong_c(const Llong *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Llong * SvecLlong_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecLlong_c::size() const
{
    return m_N;
}

inline const Llong & SvecLlong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Llong & SvecLlong_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Llong & SvecLlong_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Llong & SvecLlong_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecLlong_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecLlong_c::set_ptr(const Llong * ptr)
{
    m_p = ptr;
}

inline void SvecLlong_c::set(const Llong * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecLlong_c::next()
{
    m_p += m_N;
}

inline void SvecLlong_c::last()
{
    m_p -= m_N;
}

inline void SvecLlong_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecLlong_c::~SvecLlong_c() {}

typedef const SvecLlong_c & SvecLlong_I;

class SvecLlong
{
public:
    Llong *m_p;
    Long m_N;
    SvecLlong();
    SvecLlong(Long_I N);
    SvecLlong(Llong *ptr, Long_I N);
	Llong* ptr() const;
    Long size() const;
    Llong & operator[](Long_I i) const;
    Llong & operator()(Long_I i) const;
    Llong & end() const;
    Llong & end(Long_I i) const;

	operator SvecLlong_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Llong *ptr);
    void set(Llong *ptr, Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecLlong();
};

inline SvecLlong::SvecLlong() {}

inline SvecLlong::SvecLlong(Long_I N) : m_N(N) {}

inline SvecLlong::SvecLlong(Llong *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Llong * SvecLlong::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecLlong::size() const
{
    return m_N;
}

inline Llong & SvecLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Llong & SvecLlong::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Llong & SvecLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Llong & SvecLlong::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecLlong::operator SvecLlong_c() const
{
	return *((SvecLlong_c *)this);
}

inline void SvecLlong::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecLlong::set_ptr(Llong * ptr)
{
    m_p = ptr;
}

inline void SvecLlong::set(Llong * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecLlong::next()
{
    m_p += m_N;
}

inline void SvecLlong::last()
{
    m_p -= m_N;
}

inline void SvecLlong::shift(Long_I N)
{
    m_p += N;
}

inline SvecLlong::~SvecLlong() {}

typedef const SvecLlong & SvecLlong_O, & SvecLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef SvecInt_c SvecLong_c;
#else
typedef SvecLlong_c SvecLong_c;
#endif

typedef const SvecLong_c & SvecLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef SvecInt SvecLong;
#else
typedef SvecLlong SvecLong;
#endif

typedef const SvecLong & SvecLong_O, & SvecLong_IO;

class SvecDoub_c
{
public:
    const Doub *m_p;
    Long m_N;
    SvecDoub_c();
    SvecDoub_c(Long_I N);
    SvecDoub_c(const Doub *ptr, Long_I N);
	const Doub* ptr() const;
    Long size() const;
    const Doub & operator[](Long_I i) const;
    const Doub & operator()(Long_I i) const;
    const Doub & end() const;
    const Doub & end(Long_I i) const;


    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Doub *ptr);
    void set(const Doub *ptr, Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecDoub_c();
};

inline SvecDoub_c::SvecDoub_c() {}

inline SvecDoub_c::SvecDoub_c(Long_I N) : m_N(N) {}

inline SvecDoub_c::SvecDoub_c(const Doub *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Doub * SvecDoub_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecDoub_c::size() const
{
    return m_N;
}

inline const Doub & SvecDoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Doub & SvecDoub_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Doub & SvecDoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Doub & SvecDoub_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecDoub_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecDoub_c::set_ptr(const Doub * ptr)
{
    m_p = ptr;
}

inline void SvecDoub_c::set(const Doub * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecDoub_c::next()
{
    m_p += m_N;
}

inline void SvecDoub_c::last()
{
    m_p -= m_N;
}

inline void SvecDoub_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecDoub_c::~SvecDoub_c() {}

typedef const SvecDoub_c & SvecDoub_I;

class SvecDoub
{
public:
    Doub *m_p;
    Long m_N;
    SvecDoub();
    SvecDoub(Long_I N);
    SvecDoub(Doub *ptr, Long_I N);
	Doub* ptr() const;
    Long size() const;
    Doub & operator[](Long_I i) const;
    Doub & operator()(Long_I i) const;
    Doub & end() const;
    Doub & end(Long_I i) const;

	operator SvecDoub_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Doub *ptr);
    void set(Doub *ptr, Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecDoub();
};

inline SvecDoub::SvecDoub() {}

inline SvecDoub::SvecDoub(Long_I N) : m_N(N) {}

inline SvecDoub::SvecDoub(Doub *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Doub * SvecDoub::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecDoub::size() const
{
    return m_N;
}

inline Doub & SvecDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Doub & SvecDoub::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Doub & SvecDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Doub & SvecDoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecDoub::operator SvecDoub_c() const
{
	return *((SvecDoub_c *)this);
}

inline void SvecDoub::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecDoub::set_ptr(Doub * ptr)
{
    m_p = ptr;
}

inline void SvecDoub::set(Doub * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecDoub::next()
{
    m_p += m_N;
}

inline void SvecDoub::last()
{
    m_p -= m_N;
}

inline void SvecDoub::shift(Long_I N)
{
    m_p += N;
}

inline SvecDoub::~SvecDoub() {}

typedef const SvecDoub & SvecDoub_O, & SvecDoub_IO;

class SvecComp_c
{
public:
    const Comp *m_p;
    Long m_N;
    SvecComp_c();
    SvecComp_c(Long_I N);
    SvecComp_c(const Comp *ptr, Long_I N);
	const Comp* ptr() const;
    Long size() const;
    const Comp & operator[](Long_I i) const;
    const Comp & operator()(Long_I i) const;
    const Comp & end() const;
    const Comp & end(Long_I i) const;


    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Comp *ptr);
    void set(const Comp *ptr, Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecComp_c();
};

inline SvecComp_c::SvecComp_c() {}

inline SvecComp_c::SvecComp_c(Long_I N) : m_N(N) {}

inline SvecComp_c::SvecComp_c(const Comp *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Comp * SvecComp_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecComp_c::size() const
{
    return m_N;
}

inline const Comp & SvecComp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Comp & SvecComp_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Comp & SvecComp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Comp & SvecComp_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecComp_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecComp_c::set_ptr(const Comp * ptr)
{
    m_p = ptr;
}

inline void SvecComp_c::set(const Comp * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecComp_c::next()
{
    m_p += m_N;
}

inline void SvecComp_c::last()
{
    m_p -= m_N;
}

inline void SvecComp_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecComp_c::~SvecComp_c() {}

typedef const SvecComp_c & SvecComp_I;

class SvecComp
{
public:
    Comp *m_p;
    Long m_N;
    SvecComp();
    SvecComp(Long_I N);
    SvecComp(Comp *ptr, Long_I N);
	Comp* ptr() const;
    Long size() const;
    Comp & operator[](Long_I i) const;
    Comp & operator()(Long_I i) const;
    Comp & end() const;
    Comp & end(Long_I i) const;

	operator SvecComp_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Comp *ptr);
    void set(Comp *ptr, Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecComp();
};

inline SvecComp::SvecComp() {}

inline SvecComp::SvecComp(Long_I N) : m_N(N) {}

inline SvecComp::SvecComp(Comp *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Comp * SvecComp::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecComp::size() const
{
    return m_N;
}

inline Comp & SvecComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Comp & SvecComp::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Comp & SvecComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Comp & SvecComp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecComp::operator SvecComp_c() const
{
	return *((SvecComp_c *)this);
}

inline void SvecComp::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecComp::set_ptr(Comp * ptr)
{
    m_p = ptr;
}

inline void SvecComp::set(Comp * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecComp::next()
{
    m_p += m_N;
}

inline void SvecComp::last()
{
    m_p -= m_N;
}

inline void SvecComp::shift(Long_I N)
{
    m_p += N;
}

inline SvecComp::~SvecComp() {}

typedef const SvecComp & SvecComp_O, & SvecComp_IO;

} // namespace slisc
