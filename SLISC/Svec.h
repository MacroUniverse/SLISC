#pragma once
#include "global.h"
#include "Imag.h"

namespace slisc {
class SvecChar_c
{
protected:
    const Char *m_p;
    Long m_N;
public:
    SvecChar_c();
    explicit SvecChar_c(Long_I N);
    SvecChar_c(const Char *ptr, Long_I N);
    const Char* ptr() const;
    Long size() const;
    const Char & operator[](Long_I i) const;
    const Char & operator()(Long_I i) const;
    const Char & end() const;
    const Char & end(Long_I i) const;
    SvecChar_c &operator=(const SvecChar_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Char *ptr);
    void set(const Char *ptr, Long_I N);
    void set(const SvecChar_c &sli);
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

inline void SvecChar_c::set(const SvecChar_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
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
protected:
    Char *m_p;
    Long m_N;
public:
    SvecChar();
    explicit SvecChar(Long_I N);
    SvecChar(Char *ptr, Long_I N);
    Char* ptr() const;
    Long size() const;
    Char & operator[](Long_I i) const;
    Char & operator()(Long_I i) const;
    Char & end() const;
    Char & end(Long_I i) const;
    SvecChar &operator=(const SvecChar &) = delete;
    operator SvecChar_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Char *ptr);
    void set(Char *ptr, Long_I N);
    void set(const SvecChar &sli);
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

inline void SvecChar::set(const SvecChar &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
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
protected:
    const Int *m_p;
    Long m_N;
public:
    SvecInt_c();
    explicit SvecInt_c(Long_I N);
    SvecInt_c(const Int *ptr, Long_I N);
    const Int* ptr() const;
    Long size() const;
    const Int & operator[](Long_I i) const;
    const Int & operator()(Long_I i) const;
    const Int & end() const;
    const Int & end(Long_I i) const;
    SvecInt_c &operator=(const SvecInt_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Int *ptr);
    void set(const Int *ptr, Long_I N);
    void set(const SvecInt_c &sli);
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

inline void SvecInt_c::set(const SvecInt_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
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
protected:
    Int *m_p;
    Long m_N;
public:
    SvecInt();
    explicit SvecInt(Long_I N);
    SvecInt(Int *ptr, Long_I N);
    Int* ptr() const;
    Long size() const;
    Int & operator[](Long_I i) const;
    Int & operator()(Long_I i) const;
    Int & end() const;
    Int & end(Long_I i) const;
    SvecInt &operator=(const SvecInt &) = delete;
    operator SvecInt_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Int *ptr);
    void set(Int *ptr, Long_I N);
    void set(const SvecInt &sli);
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

inline void SvecInt::set(const SvecInt &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
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
protected:
    const Llong *m_p;
    Long m_N;
public:
    SvecLlong_c();
    explicit SvecLlong_c(Long_I N);
    SvecLlong_c(const Llong *ptr, Long_I N);
    const Llong* ptr() const;
    Long size() const;
    const Llong & operator[](Long_I i) const;
    const Llong & operator()(Long_I i) const;
    const Llong & end() const;
    const Llong & end(Long_I i) const;
    SvecLlong_c &operator=(const SvecLlong_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Llong *ptr);
    void set(const Llong *ptr, Long_I N);
    void set(const SvecLlong_c &sli);
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

inline void SvecLlong_c::set(const SvecLlong_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
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
protected:
    Llong *m_p;
    Long m_N;
public:
    SvecLlong();
    explicit SvecLlong(Long_I N);
    SvecLlong(Llong *ptr, Long_I N);
    Llong* ptr() const;
    Long size() const;
    Llong & operator[](Long_I i) const;
    Llong & operator()(Long_I i) const;
    Llong & end() const;
    Llong & end(Long_I i) const;
    SvecLlong &operator=(const SvecLlong &) = delete;
    operator SvecLlong_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Llong *ptr);
    void set(Llong *ptr, Long_I N);
    void set(const SvecLlong &sli);
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

inline void SvecLlong::set(const SvecLlong &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
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

class SvecFloat_c
{
protected:
    const Float *m_p;
    Long m_N;
public:
    SvecFloat_c();
    explicit SvecFloat_c(Long_I N);
    SvecFloat_c(const Float *ptr, Long_I N);
    const Float* ptr() const;
    Long size() const;
    const Float & operator[](Long_I i) const;
    const Float & operator()(Long_I i) const;
    const Float & end() const;
    const Float & end(Long_I i) const;
    SvecFloat_c &operator=(const SvecFloat_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Float *ptr);
    void set(const Float *ptr, Long_I N);
    void set(const SvecFloat_c &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecFloat_c();
};

inline SvecFloat_c::SvecFloat_c() {}

inline SvecFloat_c::SvecFloat_c(Long_I N) : m_N(N) {}

inline SvecFloat_c::SvecFloat_c(const Float *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Float * SvecFloat_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecFloat_c::size() const
{
    return m_N;
}

inline const Float & SvecFloat_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Float & SvecFloat_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Float & SvecFloat_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Float & SvecFloat_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecFloat_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecFloat_c::set_ptr(const Float * ptr)
{
    m_p = ptr;
}

inline void SvecFloat_c::set(const Float * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecFloat_c::set(const SvecFloat_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecFloat_c::next()
{
    m_p += m_N;
}

inline void SvecFloat_c::last()
{
    m_p -= m_N;
}

inline void SvecFloat_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecFloat_c::~SvecFloat_c() {}

typedef const SvecFloat_c & SvecFloat_I;

class SvecFloat
{
protected:
    Float *m_p;
    Long m_N;
public:
    SvecFloat();
    explicit SvecFloat(Long_I N);
    SvecFloat(Float *ptr, Long_I N);
    Float* ptr() const;
    Long size() const;
    Float & operator[](Long_I i) const;
    Float & operator()(Long_I i) const;
    Float & end() const;
    Float & end(Long_I i) const;
    SvecFloat &operator=(const SvecFloat &) = delete;
    operator SvecFloat_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Float *ptr);
    void set(Float *ptr, Long_I N);
    void set(const SvecFloat &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecFloat();
};

inline SvecFloat::SvecFloat() {}

inline SvecFloat::SvecFloat(Long_I N) : m_N(N) {}

inline SvecFloat::SvecFloat(Float *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Float * SvecFloat::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecFloat::size() const
{
    return m_N;
}

inline Float & SvecFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Float & SvecFloat::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Float & SvecFloat::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Float & SvecFloat::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecFloat::operator SvecFloat_c() const
{
    return *((SvecFloat_c *)this);
}

inline void SvecFloat::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecFloat::set_ptr(Float * ptr)
{
    m_p = ptr;
}

inline void SvecFloat::set(Float * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecFloat::set(const SvecFloat &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecFloat::next()
{
    m_p += m_N;
}

inline void SvecFloat::last()
{
    m_p -= m_N;
}

inline void SvecFloat::shift(Long_I N)
{
    m_p += N;
}

inline SvecFloat::~SvecFloat() {}

typedef const SvecFloat & SvecFloat_O, & SvecFloat_IO;

class SvecDoub_c
{
protected:
    const Doub *m_p;
    Long m_N;
public:
    SvecDoub_c();
    explicit SvecDoub_c(Long_I N);
    SvecDoub_c(const Doub *ptr, Long_I N);
    const Doub* ptr() const;
    Long size() const;
    const Doub & operator[](Long_I i) const;
    const Doub & operator()(Long_I i) const;
    const Doub & end() const;
    const Doub & end(Long_I i) const;
    SvecDoub_c &operator=(const SvecDoub_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Doub *ptr);
    void set(const Doub *ptr, Long_I N);
    void set(const SvecDoub_c &sli);
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

inline void SvecDoub_c::set(const SvecDoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
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
protected:
    Doub *m_p;
    Long m_N;
public:
    SvecDoub();
    explicit SvecDoub(Long_I N);
    SvecDoub(Doub *ptr, Long_I N);
    Doub* ptr() const;
    Long size() const;
    Doub & operator[](Long_I i) const;
    Doub & operator()(Long_I i) const;
    Doub & end() const;
    Doub & end(Long_I i) const;
    SvecDoub &operator=(const SvecDoub &) = delete;
    operator SvecDoub_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Doub *ptr);
    void set(Doub *ptr, Long_I N);
    void set(const SvecDoub &sli);
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

inline void SvecDoub::set(const SvecDoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
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

class SvecLdoub_c
{
protected:
    const Ldoub *m_p;
    Long m_N;
public:
    SvecLdoub_c();
    explicit SvecLdoub_c(Long_I N);
    SvecLdoub_c(const Ldoub *ptr, Long_I N);
    const Ldoub* ptr() const;
    Long size() const;
    const Ldoub & operator[](Long_I i) const;
    const Ldoub & operator()(Long_I i) const;
    const Ldoub & end() const;
    const Ldoub & end(Long_I i) const;
    SvecLdoub_c &operator=(const SvecLdoub_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Ldoub *ptr);
    void set(const Ldoub *ptr, Long_I N);
    void set(const SvecLdoub_c &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecLdoub_c();
};

inline SvecLdoub_c::SvecLdoub_c() {}

inline SvecLdoub_c::SvecLdoub_c(Long_I N) : m_N(N) {}

inline SvecLdoub_c::SvecLdoub_c(const Ldoub *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Ldoub * SvecLdoub_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecLdoub_c::size() const
{
    return m_N;
}

inline const Ldoub & SvecLdoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Ldoub & SvecLdoub_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Ldoub & SvecLdoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Ldoub & SvecLdoub_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecLdoub_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecLdoub_c::set_ptr(const Ldoub * ptr)
{
    m_p = ptr;
}

inline void SvecLdoub_c::set(const Ldoub * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecLdoub_c::set(const SvecLdoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecLdoub_c::next()
{
    m_p += m_N;
}

inline void SvecLdoub_c::last()
{
    m_p -= m_N;
}

inline void SvecLdoub_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecLdoub_c::~SvecLdoub_c() {}

typedef const SvecLdoub_c & SvecLdoub_I;

class SvecLdoub
{
protected:
    Ldoub *m_p;
    Long m_N;
public:
    SvecLdoub();
    explicit SvecLdoub(Long_I N);
    SvecLdoub(Ldoub *ptr, Long_I N);
    Ldoub* ptr() const;
    Long size() const;
    Ldoub & operator[](Long_I i) const;
    Ldoub & operator()(Long_I i) const;
    Ldoub & end() const;
    Ldoub & end(Long_I i) const;
    SvecLdoub &operator=(const SvecLdoub &) = delete;
    operator SvecLdoub_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Ldoub *ptr);
    void set(Ldoub *ptr, Long_I N);
    void set(const SvecLdoub &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecLdoub();
};

inline SvecLdoub::SvecLdoub() {}

inline SvecLdoub::SvecLdoub(Long_I N) : m_N(N) {}

inline SvecLdoub::SvecLdoub(Ldoub *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Ldoub * SvecLdoub::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecLdoub::size() const
{
    return m_N;
}

inline Ldoub & SvecLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Ldoub & SvecLdoub::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Ldoub & SvecLdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Ldoub & SvecLdoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecLdoub::operator SvecLdoub_c() const
{
    return *((SvecLdoub_c *)this);
}

inline void SvecLdoub::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecLdoub::set_ptr(Ldoub * ptr)
{
    m_p = ptr;
}

inline void SvecLdoub::set(Ldoub * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecLdoub::set(const SvecLdoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecLdoub::next()
{
    m_p += m_N;
}

inline void SvecLdoub::last()
{
    m_p -= m_N;
}

inline void SvecLdoub::shift(Long_I N)
{
    m_p += N;
}

inline SvecLdoub::~SvecLdoub() {}

typedef const SvecLdoub & SvecLdoub_O, & SvecLdoub_IO;

class SvecFcomp_c
{
protected:
    const Fcomp *m_p;
    Long m_N;
public:
    SvecFcomp_c();
    explicit SvecFcomp_c(Long_I N);
    SvecFcomp_c(const Fcomp *ptr, Long_I N);
    const Fcomp* ptr() const;
    Long size() const;
    const Fcomp & operator[](Long_I i) const;
    const Fcomp & operator()(Long_I i) const;
    const Fcomp & end() const;
    const Fcomp & end(Long_I i) const;
    SvecFcomp_c &operator=(const SvecFcomp_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Fcomp *ptr);
    void set(const Fcomp *ptr, Long_I N);
    void set(const SvecFcomp_c &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecFcomp_c();
};

inline SvecFcomp_c::SvecFcomp_c() {}

inline SvecFcomp_c::SvecFcomp_c(Long_I N) : m_N(N) {}

inline SvecFcomp_c::SvecFcomp_c(const Fcomp *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Fcomp * SvecFcomp_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecFcomp_c::size() const
{
    return m_N;
}

inline const Fcomp & SvecFcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Fcomp & SvecFcomp_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Fcomp & SvecFcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Fcomp & SvecFcomp_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecFcomp_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecFcomp_c::set_ptr(const Fcomp * ptr)
{
    m_p = ptr;
}

inline void SvecFcomp_c::set(const Fcomp * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecFcomp_c::set(const SvecFcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecFcomp_c::next()
{
    m_p += m_N;
}

inline void SvecFcomp_c::last()
{
    m_p -= m_N;
}

inline void SvecFcomp_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecFcomp_c::~SvecFcomp_c() {}

typedef const SvecFcomp_c & SvecFcomp_I;

class SvecFcomp
{
protected:
    Fcomp *m_p;
    Long m_N;
public:
    SvecFcomp();
    explicit SvecFcomp(Long_I N);
    SvecFcomp(Fcomp *ptr, Long_I N);
    Fcomp* ptr() const;
    Long size() const;
    Fcomp & operator[](Long_I i) const;
    Fcomp & operator()(Long_I i) const;
    Fcomp & end() const;
    Fcomp & end(Long_I i) const;
    SvecFcomp &operator=(const SvecFcomp &) = delete;
    operator SvecFcomp_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Fcomp *ptr);
    void set(Fcomp *ptr, Long_I N);
    void set(const SvecFcomp &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecFcomp();
};

inline SvecFcomp::SvecFcomp() {}

inline SvecFcomp::SvecFcomp(Long_I N) : m_N(N) {}

inline SvecFcomp::SvecFcomp(Fcomp *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Fcomp * SvecFcomp::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecFcomp::size() const
{
    return m_N;
}

inline Fcomp & SvecFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Fcomp & SvecFcomp::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Fcomp & SvecFcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Fcomp & SvecFcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecFcomp::operator SvecFcomp_c() const
{
    return *((SvecFcomp_c *)this);
}

inline void SvecFcomp::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecFcomp::set_ptr(Fcomp * ptr)
{
    m_p = ptr;
}

inline void SvecFcomp::set(Fcomp * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecFcomp::set(const SvecFcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecFcomp::next()
{
    m_p += m_N;
}

inline void SvecFcomp::last()
{
    m_p -= m_N;
}

inline void SvecFcomp::shift(Long_I N)
{
    m_p += N;
}

inline SvecFcomp::~SvecFcomp() {}

typedef const SvecFcomp & SvecFcomp_O, & SvecFcomp_IO;

class SvecComp_c
{
protected:
    const Comp *m_p;
    Long m_N;
public:
    SvecComp_c();
    explicit SvecComp_c(Long_I N);
    SvecComp_c(const Comp *ptr, Long_I N);
    const Comp* ptr() const;
    Long size() const;
    const Comp & operator[](Long_I i) const;
    const Comp & operator()(Long_I i) const;
    const Comp & end() const;
    const Comp & end(Long_I i) const;
    SvecComp_c &operator=(const SvecComp_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Comp *ptr);
    void set(const Comp *ptr, Long_I N);
    void set(const SvecComp_c &sli);
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

inline void SvecComp_c::set(const SvecComp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
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
protected:
    Comp *m_p;
    Long m_N;
public:
    SvecComp();
    explicit SvecComp(Long_I N);
    SvecComp(Comp *ptr, Long_I N);
    Comp* ptr() const;
    Long size() const;
    Comp & operator[](Long_I i) const;
    Comp & operator()(Long_I i) const;
    Comp & end() const;
    Comp & end(Long_I i) const;
    SvecComp &operator=(const SvecComp &) = delete;
    operator SvecComp_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Comp *ptr);
    void set(Comp *ptr, Long_I N);
    void set(const SvecComp &sli);
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

inline void SvecComp::set(const SvecComp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
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

class SvecLcomp_c
{
protected:
    const Lcomp *m_p;
    Long m_N;
public:
    SvecLcomp_c();
    explicit SvecLcomp_c(Long_I N);
    SvecLcomp_c(const Lcomp *ptr, Long_I N);
    const Lcomp* ptr() const;
    Long size() const;
    const Lcomp & operator[](Long_I i) const;
    const Lcomp & operator()(Long_I i) const;
    const Lcomp & end() const;
    const Lcomp & end(Long_I i) const;
    SvecLcomp_c &operator=(const SvecLcomp_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Lcomp *ptr);
    void set(const Lcomp *ptr, Long_I N);
    void set(const SvecLcomp_c &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecLcomp_c();
};

inline SvecLcomp_c::SvecLcomp_c() {}

inline SvecLcomp_c::SvecLcomp_c(Long_I N) : m_N(N) {}

inline SvecLcomp_c::SvecLcomp_c(const Lcomp *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Lcomp * SvecLcomp_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecLcomp_c::size() const
{
    return m_N;
}

inline const Lcomp & SvecLcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Lcomp & SvecLcomp_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Lcomp & SvecLcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Lcomp & SvecLcomp_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecLcomp_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecLcomp_c::set_ptr(const Lcomp * ptr)
{
    m_p = ptr;
}

inline void SvecLcomp_c::set(const Lcomp * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecLcomp_c::set(const SvecLcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecLcomp_c::next()
{
    m_p += m_N;
}

inline void SvecLcomp_c::last()
{
    m_p -= m_N;
}

inline void SvecLcomp_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecLcomp_c::~SvecLcomp_c() {}

typedef const SvecLcomp_c & SvecLcomp_I;

class SvecLcomp
{
protected:
    Lcomp *m_p;
    Long m_N;
public:
    SvecLcomp();
    explicit SvecLcomp(Long_I N);
    SvecLcomp(Lcomp *ptr, Long_I N);
    Lcomp* ptr() const;
    Long size() const;
    Lcomp & operator[](Long_I i) const;
    Lcomp & operator()(Long_I i) const;
    Lcomp & end() const;
    Lcomp & end(Long_I i) const;
    SvecLcomp &operator=(const SvecLcomp &) = delete;
    operator SvecLcomp_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Lcomp *ptr);
    void set(Lcomp *ptr, Long_I N);
    void set(const SvecLcomp &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecLcomp();
};

inline SvecLcomp::SvecLcomp() {}

inline SvecLcomp::SvecLcomp(Long_I N) : m_N(N) {}

inline SvecLcomp::SvecLcomp(Lcomp *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Lcomp * SvecLcomp::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecLcomp::size() const
{
    return m_N;
}

inline Lcomp & SvecLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Lcomp & SvecLcomp::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Lcomp & SvecLcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Lcomp & SvecLcomp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecLcomp::operator SvecLcomp_c() const
{
    return *((SvecLcomp_c *)this);
}

inline void SvecLcomp::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecLcomp::set_ptr(Lcomp * ptr)
{
    m_p = ptr;
}

inline void SvecLcomp::set(Lcomp * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecLcomp::set(const SvecLcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecLcomp::next()
{
    m_p += m_N;
}

inline void SvecLcomp::last()
{
    m_p -= m_N;
}

inline void SvecLcomp::shift(Long_I N)
{
    m_p += N;
}

inline SvecLcomp::~SvecLcomp() {}

typedef const SvecLcomp & SvecLcomp_O, & SvecLcomp_IO;

class SvecFimag_c
{
protected:
    const Fimag *m_p;
    Long m_N;
public:
    SvecFimag_c();
    explicit SvecFimag_c(Long_I N);
    SvecFimag_c(const Fimag *ptr, Long_I N);
    const Fimag* ptr() const;
    Long size() const;
    const Fimag & operator[](Long_I i) const;
    const Fimag & operator()(Long_I i) const;
    const Fimag & end() const;
    const Fimag & end(Long_I i) const;
    SvecFimag_c &operator=(const SvecFimag_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Fimag *ptr);
    void set(const Fimag *ptr, Long_I N);
    void set(const SvecFimag_c &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecFimag_c();
};

inline SvecFimag_c::SvecFimag_c() {}

inline SvecFimag_c::SvecFimag_c(Long_I N) : m_N(N) {}

inline SvecFimag_c::SvecFimag_c(const Fimag *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Fimag * SvecFimag_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecFimag_c::size() const
{
    return m_N;
}

inline const Fimag & SvecFimag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Fimag & SvecFimag_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Fimag & SvecFimag_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Fimag & SvecFimag_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecFimag_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecFimag_c::set_ptr(const Fimag * ptr)
{
    m_p = ptr;
}

inline void SvecFimag_c::set(const Fimag * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecFimag_c::set(const SvecFimag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecFimag_c::next()
{
    m_p += m_N;
}

inline void SvecFimag_c::last()
{
    m_p -= m_N;
}

inline void SvecFimag_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecFimag_c::~SvecFimag_c() {}

typedef const SvecFimag_c & SvecFimag_I;

class SvecFimag
{
protected:
    Fimag *m_p;
    Long m_N;
public:
    SvecFimag();
    explicit SvecFimag(Long_I N);
    SvecFimag(Fimag *ptr, Long_I N);
    Fimag* ptr() const;
    Long size() const;
    Fimag & operator[](Long_I i) const;
    Fimag & operator()(Long_I i) const;
    Fimag & end() const;
    Fimag & end(Long_I i) const;
    SvecFimag &operator=(const SvecFimag &) = delete;
    operator SvecFimag_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Fimag *ptr);
    void set(Fimag *ptr, Long_I N);
    void set(const SvecFimag &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecFimag();
};

inline SvecFimag::SvecFimag() {}

inline SvecFimag::SvecFimag(Long_I N) : m_N(N) {}

inline SvecFimag::SvecFimag(Fimag *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Fimag * SvecFimag::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecFimag::size() const
{
    return m_N;
}

inline Fimag & SvecFimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Fimag & SvecFimag::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Fimag & SvecFimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Fimag & SvecFimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecFimag::operator SvecFimag_c() const
{
    return *((SvecFimag_c *)this);
}

inline void SvecFimag::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecFimag::set_ptr(Fimag * ptr)
{
    m_p = ptr;
}

inline void SvecFimag::set(Fimag * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecFimag::set(const SvecFimag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecFimag::next()
{
    m_p += m_N;
}

inline void SvecFimag::last()
{
    m_p -= m_N;
}

inline void SvecFimag::shift(Long_I N)
{
    m_p += N;
}

inline SvecFimag::~SvecFimag() {}

typedef const SvecFimag & SvecFimag_O, & SvecFimag_IO;

class SvecImag_c
{
protected:
    const Imag *m_p;
    Long m_N;
public:
    SvecImag_c();
    explicit SvecImag_c(Long_I N);
    SvecImag_c(const Imag *ptr, Long_I N);
    const Imag* ptr() const;
    Long size() const;
    const Imag & operator[](Long_I i) const;
    const Imag & operator()(Long_I i) const;
    const Imag & end() const;
    const Imag & end(Long_I i) const;
    SvecImag_c &operator=(const SvecImag_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Imag *ptr);
    void set(const Imag *ptr, Long_I N);
    void set(const SvecImag_c &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecImag_c();
};

inline SvecImag_c::SvecImag_c() {}

inline SvecImag_c::SvecImag_c(Long_I N) : m_N(N) {}

inline SvecImag_c::SvecImag_c(const Imag *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Imag * SvecImag_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecImag_c::size() const
{
    return m_N;
}

inline const Imag & SvecImag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Imag & SvecImag_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Imag & SvecImag_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Imag & SvecImag_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecImag_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecImag_c::set_ptr(const Imag * ptr)
{
    m_p = ptr;
}

inline void SvecImag_c::set(const Imag * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecImag_c::set(const SvecImag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecImag_c::next()
{
    m_p += m_N;
}

inline void SvecImag_c::last()
{
    m_p -= m_N;
}

inline void SvecImag_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecImag_c::~SvecImag_c() {}

typedef const SvecImag_c & SvecImag_I;

class SvecImag
{
protected:
    Imag *m_p;
    Long m_N;
public:
    SvecImag();
    explicit SvecImag(Long_I N);
    SvecImag(Imag *ptr, Long_I N);
    Imag* ptr() const;
    Long size() const;
    Imag & operator[](Long_I i) const;
    Imag & operator()(Long_I i) const;
    Imag & end() const;
    Imag & end(Long_I i) const;
    SvecImag &operator=(const SvecImag &) = delete;
    operator SvecImag_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Imag *ptr);
    void set(Imag *ptr, Long_I N);
    void set(const SvecImag &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecImag();
};

inline SvecImag::SvecImag() {}

inline SvecImag::SvecImag(Long_I N) : m_N(N) {}

inline SvecImag::SvecImag(Imag *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Imag * SvecImag::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecImag::size() const
{
    return m_N;
}

inline Imag & SvecImag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Imag & SvecImag::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Imag & SvecImag::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Imag & SvecImag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecImag::operator SvecImag_c() const
{
    return *((SvecImag_c *)this);
}

inline void SvecImag::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecImag::set_ptr(Imag * ptr)
{
    m_p = ptr;
}

inline void SvecImag::set(Imag * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecImag::set(const SvecImag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecImag::next()
{
    m_p += m_N;
}

inline void SvecImag::last()
{
    m_p -= m_N;
}

inline void SvecImag::shift(Long_I N)
{
    m_p += N;
}

inline SvecImag::~SvecImag() {}

typedef const SvecImag & SvecImag_O, & SvecImag_IO;

class SvecLimag_c
{
protected:
    const Limag *m_p;
    Long m_N;
public:
    SvecLimag_c();
    explicit SvecLimag_c(Long_I N);
    SvecLimag_c(const Limag *ptr, Long_I N);
    const Limag* ptr() const;
    Long size() const;
    const Limag & operator[](Long_I i) const;
    const Limag & operator()(Long_I i) const;
    const Limag & end() const;
    const Limag & end(Long_I i) const;
    SvecLimag_c &operator=(const SvecLimag_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Limag *ptr);
    void set(const Limag *ptr, Long_I N);
    void set(const SvecLimag_c &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecLimag_c();
};

inline SvecLimag_c::SvecLimag_c() {}

inline SvecLimag_c::SvecLimag_c(Long_I N) : m_N(N) {}

inline SvecLimag_c::SvecLimag_c(const Limag *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline const Limag * SvecLimag_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecLimag_c::size() const
{
    return m_N;
}

inline const Limag & SvecLimag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Limag & SvecLimag_c::operator()(Long_I i) const
{
    return (*this)[i];
}

inline const Limag & SvecLimag_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Limag & SvecLimag_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecLimag_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecLimag_c::set_ptr(const Limag * ptr)
{
    m_p = ptr;
}

inline void SvecLimag_c::set(const Limag * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecLimag_c::set(const SvecLimag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecLimag_c::next()
{
    m_p += m_N;
}

inline void SvecLimag_c::last()
{
    m_p -= m_N;
}

inline void SvecLimag_c::shift(Long_I N)
{
    m_p += N;
}

inline SvecLimag_c::~SvecLimag_c() {}

typedef const SvecLimag_c & SvecLimag_I;

class SvecLimag
{
protected:
    Limag *m_p;
    Long m_N;
public:
    SvecLimag();
    explicit SvecLimag(Long_I N);
    SvecLimag(Limag *ptr, Long_I N);
    Limag* ptr() const;
    Long size() const;
    Limag & operator[](Long_I i) const;
    Limag & operator()(Long_I i) const;
    Limag & end() const;
    Limag & end(Long_I i) const;
    SvecLimag &operator=(const SvecLimag &) = delete;
    operator SvecLimag_c() const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(Limag *ptr);
    void set(Limag *ptr, Long_I N);
    void set(const SvecLimag &sli);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~SvecLimag();
};

inline SvecLimag::SvecLimag() {}

inline SvecLimag::SvecLimag(Long_I N) : m_N(N) {}

inline SvecLimag::SvecLimag(Limag *ptr, Long_I N)
    : m_p(ptr), m_N(N) {}

inline Limag * SvecLimag::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long SvecLimag::size() const
{
    return m_N;
}

inline Limag & SvecLimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline Limag & SvecLimag::operator()(Long_I i) const
{
    return (*this)[i];
}

inline Limag & SvecLimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Limag & SvecLimag::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline SvecLimag::operator SvecLimag_c() const
{
    return *((SvecLimag_c *)this);
}

inline void SvecLimag::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPE
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}

inline void SvecLimag::set_ptr(Limag * ptr)
{
    m_p = ptr;
}

inline void SvecLimag::set(Limag * ptr, Long_I N)
{
    m_p = ptr; m_N = N;
}

inline void SvecLimag::set(const SvecLimag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline void SvecLimag::next()
{
    m_p += m_N;
}

inline void SvecLimag::last()
{
    m_p -= m_N;
}

inline void SvecLimag::shift(Long_I N)
{
    m_p += N;
}

inline SvecLimag::~SvecLimag() {}

typedef const SvecLimag & SvecLimag_O, & SvecLimag_IO;

} // namespace slisc
