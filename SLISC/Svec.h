#pragma once
#include "global.h"
#include "Imag.h"
// this class is not memory safe!
// "_c" means lower level const

namespace slisc {
class SvecChar_c
{
protected:
    const Char *m_p;
    Long m_N;
public:
    SvecChar_c();
    explicit SvecChar_c(Long_I N);
    SvecChar_c(const Char *data, Long_I N); // unsafe
    const Char* p() const;
    Long size() const;
    SvecChar_c &operator=(const SvecChar_c &rhs) = delete;
    const Char &operator[](Long_I i) const;
    const Char &end() const;
    const Char &end(Long_I i) const;
    void set(const SvecChar_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Char *data);
    void set(Long_I N);
    void set(const Char *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecChar_c();
};

inline SvecChar_c::SvecChar_c() {}

inline SvecChar_c::SvecChar_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecChar_c::SvecChar_c(const Char *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Char * SvecChar_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecChar_c::size() const
{
    return m_N;
}

inline const Char &SvecChar_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Char &SvecChar_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Char &SvecChar_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecChar_c::set(const Char *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecChar_c::set(const Char *data)
{
    m_p = data;
}

inline void SvecChar_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecChar_c::set(const SvecChar_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecChar_c::~SvecChar_c() {}

typedef const SvecChar_c &SvecChar_I;

class SvecChar
{
protected:
    Char *m_p;
    Long m_N;
public:
    SvecChar();
    explicit SvecChar(Long_I N);
    SvecChar(Char *data, Long_I N); // unsafe
    Char* p() const;
    Long size() const;
    SvecChar &operator=(const SvecChar &rhs) = delete;
    Char &operator[](Long_I i) const;
    Char &end() const;
    Char &end(Long_I i) const;
    operator SvecChar_c() const;
    void set(const SvecChar &sli);
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

inline Char &SvecChar::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Char &SvecChar::end(Long_I i) const
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

inline void SvecChar::set(Char *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecChar::set(Char *data)
{
    m_p = data;
}

inline void SvecChar::set(Long_I N)
{
    m_N = N;
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

inline void SvecChar::set(const SvecChar &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecChar::~SvecChar() {}

typedef const SvecChar &SvecChar_O, &SvecChar_IO;

class SvecInt_c
{
protected:
    const Int *m_p;
    Long m_N;
public:
    SvecInt_c();
    explicit SvecInt_c(Long_I N);
    SvecInt_c(const Int *data, Long_I N); // unsafe
    const Int* p() const;
    Long size() const;
    SvecInt_c &operator=(const SvecInt_c &rhs) = delete;
    const Int &operator[](Long_I i) const;
    const Int &end() const;
    const Int &end(Long_I i) const;
    void set(const SvecInt_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Int *data);
    void set(Long_I N);
    void set(const Int *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecInt_c();
};

inline SvecInt_c::SvecInt_c() {}

inline SvecInt_c::SvecInt_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecInt_c::SvecInt_c(const Int *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Int * SvecInt_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecInt_c::size() const
{
    return m_N;
}

inline const Int &SvecInt_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Int &SvecInt_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Int &SvecInt_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecInt_c::set(const Int *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecInt_c::set(const Int *data)
{
    m_p = data;
}

inline void SvecInt_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecInt_c::set(const SvecInt_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecInt_c::~SvecInt_c() {}

typedef const SvecInt_c &SvecInt_I;

class SvecInt
{
protected:
    Int *m_p;
    Long m_N;
public:
    SvecInt();
    explicit SvecInt(Long_I N);
    SvecInt(Int *data, Long_I N); // unsafe
    Int* p() const;
    Long size() const;
    SvecInt &operator=(const SvecInt &rhs) = delete;
    Int &operator[](Long_I i) const;
    Int &end() const;
    Int &end(Long_I i) const;
    operator SvecInt_c() const;
    void set(const SvecInt &sli);
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

inline Int &SvecInt::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Int &SvecInt::end(Long_I i) const
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

inline void SvecInt::set(Int *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecInt::set(Int *data)
{
    m_p = data;
}

inline void SvecInt::set(Long_I N)
{
    m_N = N;
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

inline void SvecInt::set(const SvecInt &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecInt::~SvecInt() {}

typedef const SvecInt &SvecInt_O, &SvecInt_IO;

class SvecLlong_c
{
protected:
    const Llong *m_p;
    Long m_N;
public:
    SvecLlong_c();
    explicit SvecLlong_c(Long_I N);
    SvecLlong_c(const Llong *data, Long_I N); // unsafe
    const Llong* p() const;
    Long size() const;
    SvecLlong_c &operator=(const SvecLlong_c &rhs) = delete;
    const Llong &operator[](Long_I i) const;
    const Llong &end() const;
    const Llong &end(Long_I i) const;
    void set(const SvecLlong_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Llong *data);
    void set(Long_I N);
    void set(const Llong *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLlong_c();
};

inline SvecLlong_c::SvecLlong_c() {}

inline SvecLlong_c::SvecLlong_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecLlong_c::SvecLlong_c(const Llong *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Llong * SvecLlong_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecLlong_c::size() const
{
    return m_N;
}

inline const Llong &SvecLlong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Llong &SvecLlong_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Llong &SvecLlong_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecLlong_c::set(const Llong *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecLlong_c::set(const Llong *data)
{
    m_p = data;
}

inline void SvecLlong_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecLlong_c::set(const SvecLlong_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLlong_c::~SvecLlong_c() {}

typedef const SvecLlong_c &SvecLlong_I;

class SvecLlong
{
protected:
    Llong *m_p;
    Long m_N;
public:
    SvecLlong();
    explicit SvecLlong(Long_I N);
    SvecLlong(Llong *data, Long_I N); // unsafe
    Llong* p() const;
    Long size() const;
    SvecLlong &operator=(const SvecLlong &rhs) = delete;
    Llong &operator[](Long_I i) const;
    Llong &end() const;
    Llong &end(Long_I i) const;
    operator SvecLlong_c() const;
    void set(const SvecLlong &sli);
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

inline Llong &SvecLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Llong &SvecLlong::end(Long_I i) const
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

inline void SvecLlong::set(Llong *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecLlong::set(Llong *data)
{
    m_p = data;
}

inline void SvecLlong::set(Long_I N)
{
    m_N = N;
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

inline void SvecLlong::set(const SvecLlong &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLlong::~SvecLlong() {}

typedef const SvecLlong &SvecLlong_O, &SvecLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef SvecInt_c SvecLong_c;
#else
typedef SvecLlong_c SvecLong_c;
#endif

typedef const SvecLong_c &SvecLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef SvecInt SvecLong;
#else
typedef SvecLlong SvecLong;
#endif

typedef const SvecLong &SvecLong_O, &SvecLong_IO;

class SvecFloat_c
{
protected:
    const Float *m_p;
    Long m_N;
public:
    SvecFloat_c();
    explicit SvecFloat_c(Long_I N);
    SvecFloat_c(const Float *data, Long_I N); // unsafe
    const Float* p() const;
    Long size() const;
    SvecFloat_c &operator=(const SvecFloat_c &rhs) = delete;
    const Float &operator[](Long_I i) const;
    const Float &end() const;
    const Float &end(Long_I i) const;
    void set(const SvecFloat_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Float *data);
    void set(Long_I N);
    void set(const Float *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecFloat_c();
};

inline SvecFloat_c::SvecFloat_c() {}

inline SvecFloat_c::SvecFloat_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecFloat_c::SvecFloat_c(const Float *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Float * SvecFloat_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecFloat_c::size() const
{
    return m_N;
}

inline const Float &SvecFloat_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Float &SvecFloat_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Float &SvecFloat_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecFloat_c::set(const Float *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecFloat_c::set(const Float *data)
{
    m_p = data;
}

inline void SvecFloat_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecFloat_c::set(const SvecFloat_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFloat_c::~SvecFloat_c() {}

typedef const SvecFloat_c &SvecFloat_I;

class SvecFloat
{
protected:
    Float *m_p;
    Long m_N;
public:
    SvecFloat();
    explicit SvecFloat(Long_I N);
    SvecFloat(Float *data, Long_I N); // unsafe
    Float* p() const;
    Long size() const;
    SvecFloat &operator=(const SvecFloat &rhs) = delete;
    Float &operator[](Long_I i) const;
    Float &end() const;
    Float &end(Long_I i) const;
    operator SvecFloat_c() const;
    void set(const SvecFloat &sli);
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

inline Float &SvecFloat::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Float &SvecFloat::end(Long_I i) const
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

inline void SvecFloat::set(Float *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecFloat::set(Float *data)
{
    m_p = data;
}

inline void SvecFloat::set(Long_I N)
{
    m_N = N;
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

inline void SvecFloat::set(const SvecFloat &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFloat::~SvecFloat() {}

typedef const SvecFloat &SvecFloat_O, &SvecFloat_IO;

class SvecDoub_c
{
protected:
    const Doub *m_p;
    Long m_N;
public:
    SvecDoub_c();
    explicit SvecDoub_c(Long_I N);
    SvecDoub_c(const Doub *data, Long_I N); // unsafe
    const Doub* p() const;
    Long size() const;
    SvecDoub_c &operator=(const SvecDoub_c &rhs) = delete;
    const Doub &operator[](Long_I i) const;
    const Doub &end() const;
    const Doub &end(Long_I i) const;
    void set(const SvecDoub_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Doub *data);
    void set(Long_I N);
    void set(const Doub *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecDoub_c();
};

inline SvecDoub_c::SvecDoub_c() {}

inline SvecDoub_c::SvecDoub_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecDoub_c::SvecDoub_c(const Doub *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Doub * SvecDoub_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecDoub_c::size() const
{
    return m_N;
}

inline const Doub &SvecDoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Doub &SvecDoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Doub &SvecDoub_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecDoub_c::set(const Doub *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecDoub_c::set(const Doub *data)
{
    m_p = data;
}

inline void SvecDoub_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecDoub_c::set(const SvecDoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecDoub_c::~SvecDoub_c() {}

typedef const SvecDoub_c &SvecDoub_I;

class SvecDoub
{
protected:
    Doub *m_p;
    Long m_N;
public:
    SvecDoub();
    explicit SvecDoub(Long_I N);
    SvecDoub(Doub *data, Long_I N); // unsafe
    Doub* p() const;
    Long size() const;
    SvecDoub &operator=(const SvecDoub &rhs) = delete;
    Doub &operator[](Long_I i) const;
    Doub &end() const;
    Doub &end(Long_I i) const;
    operator SvecDoub_c() const;
    void set(const SvecDoub &sli);
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

inline Doub &SvecDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Doub &SvecDoub::end(Long_I i) const
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

inline void SvecDoub::set(Doub *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecDoub::set(Doub *data)
{
    m_p = data;
}

inline void SvecDoub::set(Long_I N)
{
    m_N = N;
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

inline void SvecDoub::set(const SvecDoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecDoub::~SvecDoub() {}

typedef const SvecDoub &SvecDoub_O, &SvecDoub_IO;

class SvecLdoub_c
{
protected:
    const Ldoub *m_p;
    Long m_N;
public:
    SvecLdoub_c();
    explicit SvecLdoub_c(Long_I N);
    SvecLdoub_c(const Ldoub *data, Long_I N); // unsafe
    const Ldoub* p() const;
    Long size() const;
    SvecLdoub_c &operator=(const SvecLdoub_c &rhs) = delete;
    const Ldoub &operator[](Long_I i) const;
    const Ldoub &end() const;
    const Ldoub &end(Long_I i) const;
    void set(const SvecLdoub_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Ldoub *data);
    void set(Long_I N);
    void set(const Ldoub *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLdoub_c();
};

inline SvecLdoub_c::SvecLdoub_c() {}

inline SvecLdoub_c::SvecLdoub_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecLdoub_c::SvecLdoub_c(const Ldoub *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Ldoub * SvecLdoub_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecLdoub_c::size() const
{
    return m_N;
}

inline const Ldoub &SvecLdoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Ldoub &SvecLdoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Ldoub &SvecLdoub_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecLdoub_c::set(const Ldoub *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecLdoub_c::set(const Ldoub *data)
{
    m_p = data;
}

inline void SvecLdoub_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecLdoub_c::set(const SvecLdoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLdoub_c::~SvecLdoub_c() {}

typedef const SvecLdoub_c &SvecLdoub_I;

class SvecLdoub
{
protected:
    Ldoub *m_p;
    Long m_N;
public:
    SvecLdoub();
    explicit SvecLdoub(Long_I N);
    SvecLdoub(Ldoub *data, Long_I N); // unsafe
    Ldoub* p() const;
    Long size() const;
    SvecLdoub &operator=(const SvecLdoub &rhs) = delete;
    Ldoub &operator[](Long_I i) const;
    Ldoub &end() const;
    Ldoub &end(Long_I i) const;
    operator SvecLdoub_c() const;
    void set(const SvecLdoub &sli);
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

inline Ldoub &SvecLdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Ldoub &SvecLdoub::end(Long_I i) const
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

inline void SvecLdoub::set(Ldoub *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecLdoub::set(Ldoub *data)
{
    m_p = data;
}

inline void SvecLdoub::set(Long_I N)
{
    m_N = N;
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

inline void SvecLdoub::set(const SvecLdoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLdoub::~SvecLdoub() {}

typedef const SvecLdoub &SvecLdoub_O, &SvecLdoub_IO;

class SvecFcomp_c
{
protected:
    const Fcomp *m_p;
    Long m_N;
public:
    SvecFcomp_c();
    explicit SvecFcomp_c(Long_I N);
    SvecFcomp_c(const Fcomp *data, Long_I N); // unsafe
    const Fcomp* p() const;
    Long size() const;
    SvecFcomp_c &operator=(const SvecFcomp_c &rhs) = delete;
    const Fcomp &operator[](Long_I i) const;
    const Fcomp &end() const;
    const Fcomp &end(Long_I i) const;
    void set(const SvecFcomp_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Fcomp *data);
    void set(Long_I N);
    void set(const Fcomp *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecFcomp_c();
};

inline SvecFcomp_c::SvecFcomp_c() {}

inline SvecFcomp_c::SvecFcomp_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecFcomp_c::SvecFcomp_c(const Fcomp *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Fcomp * SvecFcomp_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecFcomp_c::size() const
{
    return m_N;
}

inline const Fcomp &SvecFcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Fcomp &SvecFcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Fcomp &SvecFcomp_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecFcomp_c::set(const Fcomp *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecFcomp_c::set(const Fcomp *data)
{
    m_p = data;
}

inline void SvecFcomp_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecFcomp_c::set(const SvecFcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFcomp_c::~SvecFcomp_c() {}

typedef const SvecFcomp_c &SvecFcomp_I;

class SvecFcomp
{
protected:
    Fcomp *m_p;
    Long m_N;
public:
    SvecFcomp();
    explicit SvecFcomp(Long_I N);
    SvecFcomp(Fcomp *data, Long_I N); // unsafe
    Fcomp* p() const;
    Long size() const;
    SvecFcomp &operator=(const SvecFcomp &rhs) = delete;
    Fcomp &operator[](Long_I i) const;
    Fcomp &end() const;
    Fcomp &end(Long_I i) const;
    operator SvecFcomp_c() const;
    void set(const SvecFcomp &sli);
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

inline Fcomp &SvecFcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Fcomp &SvecFcomp::end(Long_I i) const
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

inline void SvecFcomp::set(Fcomp *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecFcomp::set(Fcomp *data)
{
    m_p = data;
}

inline void SvecFcomp::set(Long_I N)
{
    m_N = N;
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

inline void SvecFcomp::set(const SvecFcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFcomp::~SvecFcomp() {}

typedef const SvecFcomp &SvecFcomp_O, &SvecFcomp_IO;

class SvecComp_c
{
protected:
    const Comp *m_p;
    Long m_N;
public:
    SvecComp_c();
    explicit SvecComp_c(Long_I N);
    SvecComp_c(const Comp *data, Long_I N); // unsafe
    const Comp* p() const;
    Long size() const;
    SvecComp_c &operator=(const SvecComp_c &rhs) = delete;
    const Comp &operator[](Long_I i) const;
    const Comp &end() const;
    const Comp &end(Long_I i) const;
    void set(const SvecComp_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Comp *data);
    void set(Long_I N);
    void set(const Comp *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecComp_c();
};

inline SvecComp_c::SvecComp_c() {}

inline SvecComp_c::SvecComp_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecComp_c::SvecComp_c(const Comp *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Comp * SvecComp_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecComp_c::size() const
{
    return m_N;
}

inline const Comp &SvecComp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Comp &SvecComp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Comp &SvecComp_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecComp_c::set(const Comp *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecComp_c::set(const Comp *data)
{
    m_p = data;
}

inline void SvecComp_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecComp_c::set(const SvecComp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecComp_c::~SvecComp_c() {}

typedef const SvecComp_c &SvecComp_I;

class SvecComp
{
protected:
    Comp *m_p;
    Long m_N;
public:
    SvecComp();
    explicit SvecComp(Long_I N);
    SvecComp(Comp *data, Long_I N); // unsafe
    Comp* p() const;
    Long size() const;
    SvecComp &operator=(const SvecComp &rhs) = delete;
    Comp &operator[](Long_I i) const;
    Comp &end() const;
    Comp &end(Long_I i) const;
    operator SvecComp_c() const;
    void set(const SvecComp &sli);
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

inline Comp &SvecComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Comp &SvecComp::end(Long_I i) const
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

inline void SvecComp::set(Comp *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecComp::set(Comp *data)
{
    m_p = data;
}

inline void SvecComp::set(Long_I N)
{
    m_N = N;
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

inline void SvecComp::set(const SvecComp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecComp::~SvecComp() {}

typedef const SvecComp &SvecComp_O, &SvecComp_IO;

class SvecLcomp_c
{
protected:
    const Lcomp *m_p;
    Long m_N;
public:
    SvecLcomp_c();
    explicit SvecLcomp_c(Long_I N);
    SvecLcomp_c(const Lcomp *data, Long_I N); // unsafe
    const Lcomp* p() const;
    Long size() const;
    SvecLcomp_c &operator=(const SvecLcomp_c &rhs) = delete;
    const Lcomp &operator[](Long_I i) const;
    const Lcomp &end() const;
    const Lcomp &end(Long_I i) const;
    void set(const SvecLcomp_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Lcomp *data);
    void set(Long_I N);
    void set(const Lcomp *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLcomp_c();
};

inline SvecLcomp_c::SvecLcomp_c() {}

inline SvecLcomp_c::SvecLcomp_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecLcomp_c::SvecLcomp_c(const Lcomp *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Lcomp * SvecLcomp_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecLcomp_c::size() const
{
    return m_N;
}

inline const Lcomp &SvecLcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Lcomp &SvecLcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Lcomp &SvecLcomp_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecLcomp_c::set(const Lcomp *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecLcomp_c::set(const Lcomp *data)
{
    m_p = data;
}

inline void SvecLcomp_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecLcomp_c::set(const SvecLcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLcomp_c::~SvecLcomp_c() {}

typedef const SvecLcomp_c &SvecLcomp_I;

class SvecLcomp
{
protected:
    Lcomp *m_p;
    Long m_N;
public:
    SvecLcomp();
    explicit SvecLcomp(Long_I N);
    SvecLcomp(Lcomp *data, Long_I N); // unsafe
    Lcomp* p() const;
    Long size() const;
    SvecLcomp &operator=(const SvecLcomp &rhs) = delete;
    Lcomp &operator[](Long_I i) const;
    Lcomp &end() const;
    Lcomp &end(Long_I i) const;
    operator SvecLcomp_c() const;
    void set(const SvecLcomp &sli);
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

inline Lcomp &SvecLcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Lcomp &SvecLcomp::end(Long_I i) const
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

inline void SvecLcomp::set(Lcomp *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecLcomp::set(Lcomp *data)
{
    m_p = data;
}

inline void SvecLcomp::set(Long_I N)
{
    m_N = N;
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

inline void SvecLcomp::set(const SvecLcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLcomp::~SvecLcomp() {}

typedef const SvecLcomp &SvecLcomp_O, &SvecLcomp_IO;

class SvecFimag_c
{
protected:
    const Fimag *m_p;
    Long m_N;
public:
    SvecFimag_c();
    explicit SvecFimag_c(Long_I N);
    SvecFimag_c(const Fimag *data, Long_I N); // unsafe
    const Fimag* p() const;
    Long size() const;
    SvecFimag_c &operator=(const SvecFimag_c &rhs) = delete;
    const Fimag &operator[](Long_I i) const;
    const Fimag &end() const;
    const Fimag &end(Long_I i) const;
    void set(const SvecFimag_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Fimag *data);
    void set(Long_I N);
    void set(const Fimag *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecFimag_c();
};

inline SvecFimag_c::SvecFimag_c() {}

inline SvecFimag_c::SvecFimag_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecFimag_c::SvecFimag_c(const Fimag *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Fimag * SvecFimag_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecFimag_c::size() const
{
    return m_N;
}

inline const Fimag &SvecFimag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Fimag &SvecFimag_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Fimag &SvecFimag_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecFimag_c::set(const Fimag *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecFimag_c::set(const Fimag *data)
{
    m_p = data;
}

inline void SvecFimag_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecFimag_c::set(const SvecFimag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFimag_c::~SvecFimag_c() {}

typedef const SvecFimag_c &SvecFimag_I;

class SvecFimag
{
protected:
    Fimag *m_p;
    Long m_N;
public:
    SvecFimag();
    explicit SvecFimag(Long_I N);
    SvecFimag(Fimag *data, Long_I N); // unsafe
    Fimag* p() const;
    Long size() const;
    SvecFimag &operator=(const SvecFimag &rhs) = delete;
    Fimag &operator[](Long_I i) const;
    Fimag &end() const;
    Fimag &end(Long_I i) const;
    operator SvecFimag_c() const;
    void set(const SvecFimag &sli);
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

inline Fimag &SvecFimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Fimag &SvecFimag::end(Long_I i) const
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

inline void SvecFimag::set(Fimag *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecFimag::set(Fimag *data)
{
    m_p = data;
}

inline void SvecFimag::set(Long_I N)
{
    m_N = N;
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

inline void SvecFimag::set(const SvecFimag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecFimag::~SvecFimag() {}

typedef const SvecFimag &SvecFimag_O, &SvecFimag_IO;

class SvecImag_c
{
protected:
    const Imag *m_p;
    Long m_N;
public:
    SvecImag_c();
    explicit SvecImag_c(Long_I N);
    SvecImag_c(const Imag *data, Long_I N); // unsafe
    const Imag* p() const;
    Long size() const;
    SvecImag_c &operator=(const SvecImag_c &rhs) = delete;
    const Imag &operator[](Long_I i) const;
    const Imag &end() const;
    const Imag &end(Long_I i) const;
    void set(const SvecImag_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Imag *data);
    void set(Long_I N);
    void set(const Imag *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecImag_c();
};

inline SvecImag_c::SvecImag_c() {}

inline SvecImag_c::SvecImag_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecImag_c::SvecImag_c(const Imag *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Imag * SvecImag_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecImag_c::size() const
{
    return m_N;
}

inline const Imag &SvecImag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Imag &SvecImag_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Imag &SvecImag_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecImag_c::set(const Imag *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecImag_c::set(const Imag *data)
{
    m_p = data;
}

inline void SvecImag_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecImag_c::set(const SvecImag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecImag_c::~SvecImag_c() {}

typedef const SvecImag_c &SvecImag_I;

class SvecImag
{
protected:
    Imag *m_p;
    Long m_N;
public:
    SvecImag();
    explicit SvecImag(Long_I N);
    SvecImag(Imag *data, Long_I N); // unsafe
    Imag* p() const;
    Long size() const;
    SvecImag &operator=(const SvecImag &rhs) = delete;
    Imag &operator[](Long_I i) const;
    Imag &end() const;
    Imag &end(Long_I i) const;
    operator SvecImag_c() const;
    void set(const SvecImag &sli);
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

inline Imag &SvecImag::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Imag &SvecImag::end(Long_I i) const
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

inline void SvecImag::set(Imag *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecImag::set(Imag *data)
{
    m_p = data;
}

inline void SvecImag::set(Long_I N)
{
    m_N = N;
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

inline void SvecImag::set(const SvecImag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecImag::~SvecImag() {}

typedef const SvecImag &SvecImag_O, &SvecImag_IO;

class SvecLimag_c
{
protected:
    const Limag *m_p;
    Long m_N;
public:
    SvecLimag_c();
    explicit SvecLimag_c(Long_I N);
    SvecLimag_c(const Limag *data, Long_I N); // unsafe
    const Limag* p() const;
    Long size() const;
    SvecLimag_c &operator=(const SvecLimag_c &rhs) = delete;
    const Limag &operator[](Long_I i) const;
    const Limag &end() const;
    const Limag &end(Long_I i) const;
    void set(const SvecLimag_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set(const Limag *data);
    void set(Long_I N);
    void set(const Limag *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLimag_c();
};

inline SvecLimag_c::SvecLimag_c() {}

inline SvecLimag_c::SvecLimag_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr;
#endif
}

inline SvecLimag_c::SvecLimag_c(const Limag *data, Long_I N)
    : m_p(data), m_N(N) {}

inline const Limag * SvecLimag_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long SvecLimag_c::size() const
{
    return m_N;
}

inline const Limag &SvecLimag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
}

inline const Limag &SvecLimag_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Limag &SvecLimag_c::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}


inline void SvecLimag_c::set(const Limag *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecLimag_c::set(const Limag *data)
{
    m_p = data;
}

inline void SvecLimag_c::set(Long_I N)
{
    m_N = N;
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

inline void SvecLimag_c::set(const SvecLimag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLimag_c::~SvecLimag_c() {}

typedef const SvecLimag_c &SvecLimag_I;

class SvecLimag
{
protected:
    Limag *m_p;
    Long m_N;
public:
    SvecLimag();
    explicit SvecLimag(Long_I N);
    SvecLimag(Limag *data, Long_I N); // unsafe
    Limag* p() const;
    Long size() const;
    SvecLimag &operator=(const SvecLimag &rhs) = delete;
    Limag &operator[](Long_I i) const;
    Limag &end() const;
    Limag &end(Long_I i) const;
    operator SvecLimag_c() const;
    void set(const SvecLimag &sli);
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

inline Limag &SvecLimag::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Limag &SvecLimag::end(Long_I i) const
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

inline void SvecLimag::set(Limag *data, Long_I N)
{
    m_p = data; m_N = N;
}

inline void SvecLimag::set(Limag *data)
{
    m_p = data;
}

inline void SvecLimag::set(Long_I N)
{
    m_N = N;
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

inline void SvecLimag::set(const SvecLimag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
}

inline SvecLimag::~SvecLimag() {}

typedef const SvecLimag &SvecLimag_O, &SvecLimag_IO;

} // namespace slisc
