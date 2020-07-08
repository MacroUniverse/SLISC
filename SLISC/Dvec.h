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
#ifdef SLS_CHECK_SHAPES
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
#ifdef SLS_CHECK_SHAPES
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
#ifdef SLS_CHECK_SHAPES
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
#ifdef SLS_CHECK_SHAPES
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

class DvecFloat_c
{
protected:
    const Float *m_p;
    Long m_N;
    Long m_step;
public:
    DvecFloat_c();
    DvecFloat_c(const Float *ptr, Long_I N, Long_I step);
    const Float* ptr() const;
    const Float & operator[](Long_I i) const;
    const Float & operator()(Long_I i) const;
    const Float & end() const;
    const Float & end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecFloat_c &operator=(const DvecFloat_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_ptr(const Float *ptr);
    void set(const Float *ptr, Long_I N, Long_I step);
    void set(const DvecFloat_c &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecFloat_c();
};

inline DvecFloat_c::DvecFloat_c() {}

inline DvecFloat_c::DvecFloat_c(const Float *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline const Float * DvecFloat_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline const Float & DvecFloat_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Float & DvecFloat_c::operator()(Long_I i) const
{ return (*this)[i]; }

inline const Float & DvecFloat_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Float & DvecFloat_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecFloat_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecFloat_c::set_ptr(const Float * ptr)
{
    m_p = ptr;
}

inline void DvecFloat_c::set(const Float * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecFloat_c & DvecFloat_I;

class DvecFloat
{
protected:
    Float *m_p;
    Long m_N;
    Long m_step;
public:
    DvecFloat();
    DvecFloat(Float *ptr, Long_I N, Long_I step);
    Float* ptr() const;
    Float & operator[](Long_I i) const;
    Float & operator()(Long_I i) const;
    Float & end() const;
    Float & end(Long_I i) const;
    Long size() const;
    Long step() const;

    operator DvecFloat_c() const;
    DvecFloat &operator=(const DvecFloat &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_ptr(Float *ptr);
    void set(Float *ptr, Long_I N, Long_I step);
    void set(const DvecFloat &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecFloat();
};

inline DvecFloat::DvecFloat() {}

inline DvecFloat::DvecFloat(Float *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline Float * DvecFloat::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline Float & DvecFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Float & DvecFloat::operator()(Long_I i) const
{ return (*this)[i]; }

inline Float & DvecFloat::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Float & DvecFloat::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecFloat::set_size(Long_I N)
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

inline void DvecFloat::set_ptr(Float * ptr)
{
    m_p = ptr;
}

inline void DvecFloat::set(Float * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecFloat & DvecFloat_O, & DvecFloat_IO;

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
#ifdef SLS_CHECK_SHAPES
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
#ifdef SLS_CHECK_SHAPES
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

class DvecLdoub_c
{
protected:
    const Ldoub *m_p;
    Long m_N;
    Long m_step;
public:
    DvecLdoub_c();
    DvecLdoub_c(const Ldoub *ptr, Long_I N, Long_I step);
    const Ldoub* ptr() const;
    const Ldoub & operator[](Long_I i) const;
    const Ldoub & operator()(Long_I i) const;
    const Ldoub & end() const;
    const Ldoub & end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecLdoub_c &operator=(const DvecLdoub_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_ptr(const Ldoub *ptr);
    void set(const Ldoub *ptr, Long_I N, Long_I step);
    void set(const DvecLdoub_c &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecLdoub_c();
};

inline DvecLdoub_c::DvecLdoub_c() {}

inline DvecLdoub_c::DvecLdoub_c(const Ldoub *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline const Ldoub * DvecLdoub_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline const Ldoub & DvecLdoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Ldoub & DvecLdoub_c::operator()(Long_I i) const
{ return (*this)[i]; }

inline const Ldoub & DvecLdoub_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Ldoub & DvecLdoub_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecLdoub_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecLdoub_c::set_ptr(const Ldoub * ptr)
{
    m_p = ptr;
}

inline void DvecLdoub_c::set(const Ldoub * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecLdoub_c & DvecLdoub_I;

class DvecLdoub
{
protected:
    Ldoub *m_p;
    Long m_N;
    Long m_step;
public:
    DvecLdoub();
    DvecLdoub(Ldoub *ptr, Long_I N, Long_I step);
    Ldoub* ptr() const;
    Ldoub & operator[](Long_I i) const;
    Ldoub & operator()(Long_I i) const;
    Ldoub & end() const;
    Ldoub & end(Long_I i) const;
    Long size() const;
    Long step() const;

    operator DvecLdoub_c() const;
    DvecLdoub &operator=(const DvecLdoub &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_ptr(Ldoub *ptr);
    void set(Ldoub *ptr, Long_I N, Long_I step);
    void set(const DvecLdoub &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecLdoub();
};

inline DvecLdoub::DvecLdoub() {}

inline DvecLdoub::DvecLdoub(Ldoub *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline Ldoub * DvecLdoub::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline Ldoub & DvecLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Ldoub & DvecLdoub::operator()(Long_I i) const
{ return (*this)[i]; }

inline Ldoub & DvecLdoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Ldoub & DvecLdoub::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecLdoub::set_size(Long_I N)
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

inline void DvecLdoub::set_ptr(Ldoub * ptr)
{
    m_p = ptr;
}

inline void DvecLdoub::set(Ldoub * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecLdoub & DvecLdoub_O, & DvecLdoub_IO;

class DvecFcomp_c
{
protected:
    const Fcomp *m_p;
    Long m_N;
    Long m_step;
public:
    DvecFcomp_c();
    DvecFcomp_c(const Fcomp *ptr, Long_I N, Long_I step);
    const Fcomp* ptr() const;
    const Fcomp & operator[](Long_I i) const;
    const Fcomp & operator()(Long_I i) const;
    const Fcomp & end() const;
    const Fcomp & end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecFcomp_c &operator=(const DvecFcomp_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_ptr(const Fcomp *ptr);
    void set(const Fcomp *ptr, Long_I N, Long_I step);
    void set(const DvecFcomp_c &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecFcomp_c();
};

inline DvecFcomp_c::DvecFcomp_c() {}

inline DvecFcomp_c::DvecFcomp_c(const Fcomp *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline const Fcomp * DvecFcomp_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline const Fcomp & DvecFcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Fcomp & DvecFcomp_c::operator()(Long_I i) const
{ return (*this)[i]; }

inline const Fcomp & DvecFcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Fcomp & DvecFcomp_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecFcomp_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecFcomp_c::set_ptr(const Fcomp * ptr)
{
    m_p = ptr;
}

inline void DvecFcomp_c::set(const Fcomp * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecFcomp_c & DvecFcomp_I;

class DvecFcomp
{
protected:
    Fcomp *m_p;
    Long m_N;
    Long m_step;
public:
    DvecFcomp();
    DvecFcomp(Fcomp *ptr, Long_I N, Long_I step);
    Fcomp* ptr() const;
    Fcomp & operator[](Long_I i) const;
    Fcomp & operator()(Long_I i) const;
    Fcomp & end() const;
    Fcomp & end(Long_I i) const;
    Long size() const;
    Long step() const;

    operator DvecFcomp_c() const;
    DvecFcomp &operator=(const DvecFcomp &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_ptr(Fcomp *ptr);
    void set(Fcomp *ptr, Long_I N, Long_I step);
    void set(const DvecFcomp &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecFcomp();
};

inline DvecFcomp::DvecFcomp() {}

inline DvecFcomp::DvecFcomp(Fcomp *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline Fcomp * DvecFcomp::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline Fcomp & DvecFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Fcomp & DvecFcomp::operator()(Long_I i) const
{ return (*this)[i]; }

inline Fcomp & DvecFcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Fcomp & DvecFcomp::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecFcomp::set_size(Long_I N)
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

inline void DvecFcomp::set_ptr(Fcomp * ptr)
{
    m_p = ptr;
}

inline void DvecFcomp::set(Fcomp * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecFcomp & DvecFcomp_O, & DvecFcomp_IO;

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
#ifdef SLS_CHECK_SHAPES
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
#ifdef SLS_CHECK_SHAPES
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

class DvecLcomp_c
{
protected:
    const Lcomp *m_p;
    Long m_N;
    Long m_step;
public:
    DvecLcomp_c();
    DvecLcomp_c(const Lcomp *ptr, Long_I N, Long_I step);
    const Lcomp* ptr() const;
    const Lcomp & operator[](Long_I i) const;
    const Lcomp & operator()(Long_I i) const;
    const Lcomp & end() const;
    const Lcomp & end(Long_I i) const;
    Long size() const;
    Long step() const;

    DvecLcomp_c &operator=(const DvecLcomp_c &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_ptr(const Lcomp *ptr);
    void set(const Lcomp *ptr, Long_I N, Long_I step);
    void set(const DvecLcomp_c &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecLcomp_c();
};

inline DvecLcomp_c::DvecLcomp_c() {}

inline DvecLcomp_c::DvecLcomp_c(const Lcomp *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline const Lcomp * DvecLcomp_c::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline const Lcomp & DvecLcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Lcomp & DvecLcomp_c::operator()(Long_I i) const
{ return (*this)[i]; }

inline const Lcomp & DvecLcomp_c::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Lcomp & DvecLcomp_c::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecLcomp_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (N <= 0) SLS_ERR("illegal N!");
#endif
    m_N = N;
}


inline void DvecLcomp_c::set_ptr(const Lcomp * ptr)
{
    m_p = ptr;
}

inline void DvecLcomp_c::set(const Lcomp * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecLcomp_c & DvecLcomp_I;

class DvecLcomp
{
protected:
    Lcomp *m_p;
    Long m_N;
    Long m_step;
public:
    DvecLcomp();
    DvecLcomp(Lcomp *ptr, Long_I N, Long_I step);
    Lcomp* ptr() const;
    Lcomp & operator[](Long_I i) const;
    Lcomp & operator()(Long_I i) const;
    Lcomp & end() const;
    Lcomp & end(Long_I i) const;
    Long size() const;
    Long step() const;

    operator DvecLcomp_c() const;
    DvecLcomp &operator=(const DvecLcomp &) = delete;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_ptr(Lcomp *ptr);
    void set(Lcomp *ptr, Long_I N, Long_I step);
    void set(const DvecLcomp &sli);
    void set_size(Long_I N);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecLcomp();
};

inline DvecLcomp::DvecLcomp() {}

inline DvecLcomp::DvecLcomp(Lcomp *ptr, Long_I N, Long_I step)
    : m_p(ptr), m_N(N), m_step(step) {}

inline Lcomp * DvecLcomp::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
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

inline Lcomp & DvecLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Lcomp & DvecLcomp::operator()(Long_I i) const
{ return (*this)[i]; }

inline Lcomp & DvecLcomp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Lcomp & DvecLcomp::end(Long_I i) const
{
    return m_p[m_step*(m_N - i)];
}

inline void DvecLcomp::set_size(Long_I N)
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

inline void DvecLcomp::set_ptr(Lcomp * ptr)
{
    m_p = ptr;
}

inline void DvecLcomp::set(Lcomp * ptr, Long_I N, Long_I step)
{
    m_p = ptr; m_N = N; m_step = step;
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


typedef const DvecLcomp & DvecLcomp_O, & DvecLcomp_IO;

} // namespace slisc
