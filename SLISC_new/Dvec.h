#pragma once
#include "global.h"
// "_c" means lower level const

namespace slisc {
class DvecChar_c
{
protected:
    const Char *m_p;
    Long m_N;
    Long m_step;
public:
    DvecChar_c();
    DvecChar_c(const Char *p, Long_I N, Long_I step);
    const Char* p() const;
    const Char &operator[](Long_I i) const;
    const Char &end() const;
    const Char &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecChar_c &operator=(const DvecChar_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Char *p);
    void set(const Char *p, Long_I N, Long_I step);
    void set(const DvecChar_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecChar_c();
};

inline DvecChar_c::DvecChar_c() {}

inline DvecChar_c::DvecChar_c(const Char *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Char * DvecChar_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long DvecChar_c::size() const
{
    return m_N;
}

inline Long DvecChar_c::step() const
{
    return m_step;
}

inline const Char &DvecChar_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Char &DvecChar_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Char &DvecChar_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecChar_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecChar_c::set(const Char * p)
{
    m_p = p;
}

inline void DvecChar_c::set(const Char * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
}

inline void DvecChar_c::set(const DvecChar_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecChar_c::next()
{
    m_p += m_N;
}

inline void DvecChar_c::last()
{
    m_p -= m_N;
}

inline void DvecChar_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecChar_c::~DvecChar_c() {}


typedef const DvecChar_c &DvecChar_I;

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

    operator DvecChar_c() const;
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

inline DvecChar::operator DvecChar_c() const
{
    return *((DvecChar_c *)this);
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

class DvecInt_c
{
protected:
    const Int *m_p;
    Long m_N;
    Long m_step;
public:
    DvecInt_c();
    DvecInt_c(const Int *p, Long_I N, Long_I step);
    const Int* p() const;
    const Int &operator[](Long_I i) const;
    const Int &end() const;
    const Int &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecInt_c &operator=(const DvecInt_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Int *p);
    void set(const Int *p, Long_I N, Long_I step);
    void set(const DvecInt_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecInt_c();
};

inline DvecInt_c::DvecInt_c() {}

inline DvecInt_c::DvecInt_c(const Int *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Int * DvecInt_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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

inline const Int &DvecInt_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Int &DvecInt_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Int &DvecInt_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecInt_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecInt_c::set(const Int * p)
{
    m_p = p;
}

inline void DvecInt_c::set(const Int * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
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


typedef const DvecInt_c &DvecInt_I;

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

    operator DvecInt_c() const;
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

inline DvecInt::operator DvecInt_c() const
{
    return *((DvecInt_c *)this);
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

class DvecLlong_c
{
protected:
    const Llong *m_p;
    Long m_N;
    Long m_step;
public:
    DvecLlong_c();
    DvecLlong_c(const Llong *p, Long_I N, Long_I step);
    const Llong* p() const;
    const Llong &operator[](Long_I i) const;
    const Llong &end() const;
    const Llong &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecLlong_c &operator=(const DvecLlong_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Llong *p);
    void set(const Llong *p, Long_I N, Long_I step);
    void set(const DvecLlong_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecLlong_c();
};

inline DvecLlong_c::DvecLlong_c() {}

inline DvecLlong_c::DvecLlong_c(const Llong *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Llong * DvecLlong_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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

inline const Llong &DvecLlong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Llong &DvecLlong_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Llong &DvecLlong_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecLlong_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecLlong_c::set(const Llong * p)
{
    m_p = p;
}

inline void DvecLlong_c::set(const Llong * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
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


typedef const DvecLlong_c &DvecLlong_I;

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

    operator DvecLlong_c() const;
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

inline DvecLlong::operator DvecLlong_c() const
{
    return *((DvecLlong_c *)this);
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

#ifdef SLS_USE_INT_AS_LONG
typedef DvecInt_c DvecLong_c;
#else
typedef DvecLlong_c DvecLong_c;
#endif

typedef const DvecLong_c &DvecLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef DvecInt DvecLong;
#else
typedef DvecLlong DvecLong;
#endif

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const DvecLong &DvecLong_O, &DvecLong_IO;

class DvecFloat_c
{
protected:
    const Float *m_p;
    Long m_N;
    Long m_step;
public:
    DvecFloat_c();
    DvecFloat_c(const Float *p, Long_I N, Long_I step);
    const Float* p() const;
    const Float &operator[](Long_I i) const;
    const Float &end() const;
    const Float &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecFloat_c &operator=(const DvecFloat_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Float *p);
    void set(const Float *p, Long_I N, Long_I step);
    void set(const DvecFloat_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecFloat_c();
};

inline DvecFloat_c::DvecFloat_c() {}

inline DvecFloat_c::DvecFloat_c(const Float *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Float * DvecFloat_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long DvecFloat_c::size() const
{
    return m_N;
}

inline Long DvecFloat_c::step() const
{
    return m_step;
}

inline const Float &DvecFloat_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Float &DvecFloat_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Float &DvecFloat_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecFloat_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecFloat_c::set(const Float * p)
{
    m_p = p;
}

inline void DvecFloat_c::set(const Float * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
}

inline void DvecFloat_c::set(const DvecFloat_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecFloat_c::next()
{
    m_p += m_N;
}

inline void DvecFloat_c::last()
{
    m_p -= m_N;
}

inline void DvecFloat_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecFloat_c::~DvecFloat_c() {}


typedef const DvecFloat_c &DvecFloat_I;

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

    operator DvecFloat_c() const;
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

inline DvecFloat::operator DvecFloat_c() const
{
    return *((DvecFloat_c *)this);
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

class DvecDoub_c
{
protected:
    const Doub *m_p;
    Long m_N;
    Long m_step;
public:
    DvecDoub_c();
    DvecDoub_c(const Doub *p, Long_I N, Long_I step);
    const Doub* p() const;
    const Doub &operator[](Long_I i) const;
    const Doub &end() const;
    const Doub &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecDoub_c &operator=(const DvecDoub_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Doub *p);
    void set(const Doub *p, Long_I N, Long_I step);
    void set(const DvecDoub_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecDoub_c();
};

inline DvecDoub_c::DvecDoub_c() {}

inline DvecDoub_c::DvecDoub_c(const Doub *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Doub * DvecDoub_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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

inline const Doub &DvecDoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Doub &DvecDoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Doub &DvecDoub_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecDoub_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecDoub_c::set(const Doub * p)
{
    m_p = p;
}

inline void DvecDoub_c::set(const Doub * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
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


typedef const DvecDoub_c &DvecDoub_I;

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

    operator DvecDoub_c() const;
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

inline DvecDoub::operator DvecDoub_c() const
{
    return *((DvecDoub_c *)this);
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

class DvecLdoub_c
{
protected:
    const Ldoub *m_p;
    Long m_N;
    Long m_step;
public:
    DvecLdoub_c();
    DvecLdoub_c(const Ldoub *p, Long_I N, Long_I step);
    const Ldoub* p() const;
    const Ldoub &operator[](Long_I i) const;
    const Ldoub &end() const;
    const Ldoub &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecLdoub_c &operator=(const DvecLdoub_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Ldoub *p);
    void set(const Ldoub *p, Long_I N, Long_I step);
    void set(const DvecLdoub_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecLdoub_c();
};

inline DvecLdoub_c::DvecLdoub_c() {}

inline DvecLdoub_c::DvecLdoub_c(const Ldoub *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Ldoub * DvecLdoub_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long DvecLdoub_c::size() const
{
    return m_N;
}

inline Long DvecLdoub_c::step() const
{
    return m_step;
}

inline const Ldoub &DvecLdoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Ldoub &DvecLdoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Ldoub &DvecLdoub_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecLdoub_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecLdoub_c::set(const Ldoub * p)
{
    m_p = p;
}

inline void DvecLdoub_c::set(const Ldoub * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
}

inline void DvecLdoub_c::set(const DvecLdoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecLdoub_c::next()
{
    m_p += m_N;
}

inline void DvecLdoub_c::last()
{
    m_p -= m_N;
}

inline void DvecLdoub_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecLdoub_c::~DvecLdoub_c() {}


typedef const DvecLdoub_c &DvecLdoub_I;

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

    operator DvecLdoub_c() const;
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

inline DvecLdoub::operator DvecLdoub_c() const
{
    return *((DvecLdoub_c *)this);
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

#ifdef SLS_USE_QUAD_MATH
class DvecQdoub_c
{
protected:
    const Qdoub *m_p;
    Long m_N;
    Long m_step;
public:
    DvecQdoub_c();
    DvecQdoub_c(const Qdoub *p, Long_I N, Long_I step);
    const Qdoub* p() const;
    const Qdoub &operator[](Long_I i) const;
    const Qdoub &end() const;
    const Qdoub &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecQdoub_c &operator=(const DvecQdoub_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Qdoub *p);
    void set(const Qdoub *p, Long_I N, Long_I step);
    void set(const DvecQdoub_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecQdoub_c();
};

inline DvecQdoub_c::DvecQdoub_c() {}

inline DvecQdoub_c::DvecQdoub_c(const Qdoub *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Qdoub * DvecQdoub_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long DvecQdoub_c::size() const
{
    return m_N;
}

inline Long DvecQdoub_c::step() const
{
    return m_step;
}

inline const Qdoub &DvecQdoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Qdoub &DvecQdoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Qdoub &DvecQdoub_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecQdoub_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecQdoub_c::set(const Qdoub * p)
{
    m_p = p;
}

inline void DvecQdoub_c::set(const Qdoub * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
}

inline void DvecQdoub_c::set(const DvecQdoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecQdoub_c::next()
{
    m_p += m_N;
}

inline void DvecQdoub_c::last()
{
    m_p -= m_N;
}

inline void DvecQdoub_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecQdoub_c::~DvecQdoub_c() {}


typedef const DvecQdoub_c &DvecQdoub_I;
#endif

#ifdef SLS_USE_QUAD_MATH
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

    operator DvecQdoub_c() const;
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

inline DvecQdoub::operator DvecQdoub_c() const
{
    return *((DvecQdoub_c *)this);
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
#endif

class DvecFcomp_c
{
protected:
    const Fcomp *m_p;
    Long m_N;
    Long m_step;
public:
    DvecFcomp_c();
    DvecFcomp_c(const Fcomp *p, Long_I N, Long_I step);
    const Fcomp* p() const;
    const Fcomp &operator[](Long_I i) const;
    const Fcomp &end() const;
    const Fcomp &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecFcomp_c &operator=(const DvecFcomp_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Fcomp *p);
    void set(const Fcomp *p, Long_I N, Long_I step);
    void set(const DvecFcomp_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecFcomp_c();
};

inline DvecFcomp_c::DvecFcomp_c() {}

inline DvecFcomp_c::DvecFcomp_c(const Fcomp *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Fcomp * DvecFcomp_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long DvecFcomp_c::size() const
{
    return m_N;
}

inline Long DvecFcomp_c::step() const
{
    return m_step;
}

inline const Fcomp &DvecFcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Fcomp &DvecFcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Fcomp &DvecFcomp_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecFcomp_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecFcomp_c::set(const Fcomp * p)
{
    m_p = p;
}

inline void DvecFcomp_c::set(const Fcomp * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
}

inline void DvecFcomp_c::set(const DvecFcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecFcomp_c::next()
{
    m_p += m_N;
}

inline void DvecFcomp_c::last()
{
    m_p -= m_N;
}

inline void DvecFcomp_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecFcomp_c::~DvecFcomp_c() {}


typedef const DvecFcomp_c &DvecFcomp_I;

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

    operator DvecFcomp_c() const;
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

inline DvecFcomp::operator DvecFcomp_c() const
{
    return *((DvecFcomp_c *)this);
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

class DvecComp_c
{
protected:
    const Comp *m_p;
    Long m_N;
    Long m_step;
public:
    DvecComp_c();
    DvecComp_c(const Comp *p, Long_I N, Long_I step);
    const Comp* p() const;
    const Comp &operator[](Long_I i) const;
    const Comp &end() const;
    const Comp &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecComp_c &operator=(const DvecComp_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Comp *p);
    void set(const Comp *p, Long_I N, Long_I step);
    void set(const DvecComp_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecComp_c();
};

inline DvecComp_c::DvecComp_c() {}

inline DvecComp_c::DvecComp_c(const Comp *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Comp * DvecComp_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
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

inline const Comp &DvecComp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Comp &DvecComp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Comp &DvecComp_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecComp_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecComp_c::set(const Comp * p)
{
    m_p = p;
}

inline void DvecComp_c::set(const Comp * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
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


typedef const DvecComp_c &DvecComp_I;

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

    operator DvecComp_c() const;
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

inline DvecComp::operator DvecComp_c() const
{
    return *((DvecComp_c *)this);
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

class DvecLcomp_c
{
protected:
    const Lcomp *m_p;
    Long m_N;
    Long m_step;
public:
    DvecLcomp_c();
    DvecLcomp_c(const Lcomp *p, Long_I N, Long_I step);
    const Lcomp* p() const;
    const Lcomp &operator[](Long_I i) const;
    const Lcomp &end() const;
    const Lcomp &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecLcomp_c &operator=(const DvecLcomp_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Lcomp *p);
    void set(const Lcomp *p, Long_I N, Long_I step);
    void set(const DvecLcomp_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecLcomp_c();
};

inline DvecLcomp_c::DvecLcomp_c() {}

inline DvecLcomp_c::DvecLcomp_c(const Lcomp *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Lcomp * DvecLcomp_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long DvecLcomp_c::size() const
{
    return m_N;
}

inline Long DvecLcomp_c::step() const
{
    return m_step;
}

inline const Lcomp &DvecLcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Lcomp &DvecLcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Lcomp &DvecLcomp_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecLcomp_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecLcomp_c::set(const Lcomp * p)
{
    m_p = p;
}

inline void DvecLcomp_c::set(const Lcomp * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
}

inline void DvecLcomp_c::set(const DvecLcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecLcomp_c::next()
{
    m_p += m_N;
}

inline void DvecLcomp_c::last()
{
    m_p -= m_N;
}

inline void DvecLcomp_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecLcomp_c::~DvecLcomp_c() {}


typedef const DvecLcomp_c &DvecLcomp_I;

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

    operator DvecLcomp_c() const;
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

inline DvecLcomp::operator DvecLcomp_c() const
{
    return *((DvecLcomp_c *)this);
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

#ifdef SLS_USE_QUAD_MATH
class DvecQcomp_c
{
protected:
    const Qcomp *m_p;
    Long m_N;
    Long m_step;
public:
    DvecQcomp_c();
    DvecQcomp_c(const Qcomp *p, Long_I N, Long_I step);
    const Qcomp* p() const;
    const Qcomp &operator[](Long_I i) const;
    const Qcomp &end() const;
    const Qcomp &end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecQcomp_c &operator=(const DvecQcomp_c &) = delete;
    // === other member functions ===
    // There is no bound checking, use with care
    void set(const Qcomp *p);
    void set(const Qcomp *p, Long_I N, Long_I step);
    void set(const DvecQcomp_c &sli);
    void set(Long_I N);
    void next(); // m_p += m_N
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N;
    
    ~DvecQcomp_c();
};

inline DvecQcomp_c::DvecQcomp_c() {}

inline DvecQcomp_c::DvecQcomp_c(const Qcomp *p, Long_I N, Long_I step)
    : m_p(p), m_N(N), m_step(step) {}

inline const Qcomp * DvecQcomp_c::p() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using p() for empty container!");
#endif
    return m_p;
}

inline Long DvecQcomp_c::size() const
{
    return m_N;
}

inline Long DvecQcomp_c::step() const
{
    return m_step;
}

inline const Qcomp &DvecQcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Qcomp &DvecQcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Qcomp &DvecQcomp_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecQcomp_c::set(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecQcomp_c::set(const Qcomp * p)
{
    m_p = p;
}

inline void DvecQcomp_c::set(const Qcomp * p, Long_I N, Long_I step)
{
    m_p = p; m_N = N; m_step = step;
}

inline void DvecQcomp_c::set(const DvecQcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N; m_step = sli.m_step;
}

inline void DvecQcomp_c::next()
{
    m_p += m_N;
}

inline void DvecQcomp_c::last()
{
    m_p -= m_N;
}

inline void DvecQcomp_c::shift(Long_I N)
{
    m_p += N;
}

inline DvecQcomp_c::~DvecQcomp_c() {}


typedef const DvecQcomp_c &DvecQcomp_I;
#endif

#ifdef SLS_USE_QUAD_MATH
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

    operator DvecQcomp_c() const;
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

inline DvecQcomp::operator DvecQcomp_c() const
{
    return *((DvecQcomp_c *)this);
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
#endif


} // namespace slisc
