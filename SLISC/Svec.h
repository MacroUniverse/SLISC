#pragma once
#include "global.h"
#include "Imag.h"

namespace slisc {
class SvecChar_c
{
protected:
    const Char *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecChar_c();
    explicit SvecChar_c(Long_I N);
    SvecChar_c(const Char *data, Long_I N); // unsafe
    SvecChar_c(const Char *data, Long_I data_len, Long_I N);
    const Char* p() const;
    Long size() const;
    const Char & operator[](Long_I i) const;
    const Char & operator()(Long_I i) const;
    const Char & end() const;
    const Char & end(Long_I i) const;
    void set(const Char *data, Long_I data_len, Long_I N);
    void set(const SvecChar_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Char *data);
    void set_size(Long_I N);
    void set(const Char *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecChar_c();
};

inline SvecChar_c::SvecChar_c() {}

inline SvecChar_c::SvecChar_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecChar_c::SvecChar_c(const Char *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecChar_c::SvecChar_c(const Char *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Char & SvecChar_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecChar_c::set(const Char *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecChar_c::set(const Char *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecChar_c::set(const SvecChar_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecChar_c::set_p(const Char *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecChar_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecChar_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecChar_c::last()
{
    m_p -= m_N;
}

inline void SvecChar_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecChar_c::~SvecChar_c() {}

typedef const SvecChar_c & SvecChar_I;

class SvecChar
{
protected:
    Char *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecChar();
    explicit SvecChar(Long_I N);
    SvecChar(Char *data, Long_I N); // unsafe
    SvecChar(Char *data, Long_I data_len, Long_I N);
    Char* p() const;
    Long size() const;
    Char & operator[](Long_I i) const;
    Char & operator()(Long_I i) const;
    Char & end() const;
    Char & end(Long_I i) const;
    operator SvecChar_c() const;
    void set(Char *data, Long_I data_len, Long_I N);
    void set(const SvecChar &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Char *data);
    void set_size(Long_I N);
    void set(Char *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecChar();
};

inline SvecChar::SvecChar() {}

inline SvecChar::SvecChar(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecChar::SvecChar(Char *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecChar::SvecChar(Char *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Char & SvecChar::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecChar::set(Char *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecChar::set(Char *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecChar::set(const SvecChar &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecChar::set_p(Char *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecChar::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecChar::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecChar::last()
{
    m_p -= m_N;
}

inline void SvecChar::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecChar::~SvecChar() {}

typedef const SvecChar & SvecChar_O, & SvecChar_IO;

class SvecInt_c
{
protected:
    const Int *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecInt_c();
    explicit SvecInt_c(Long_I N);
    SvecInt_c(const Int *data, Long_I N); // unsafe
    SvecInt_c(const Int *data, Long_I data_len, Long_I N);
    const Int* p() const;
    Long size() const;
    const Int & operator[](Long_I i) const;
    const Int & operator()(Long_I i) const;
    const Int & end() const;
    const Int & end(Long_I i) const;
    void set(const Int *data, Long_I data_len, Long_I N);
    void set(const SvecInt_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Int *data);
    void set_size(Long_I N);
    void set(const Int *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecInt_c();
};

inline SvecInt_c::SvecInt_c() {}

inline SvecInt_c::SvecInt_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecInt_c::SvecInt_c(const Int *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecInt_c::SvecInt_c(const Int *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Int & SvecInt_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecInt_c::set(const Int *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecInt_c::set(const Int *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecInt_c::set(const SvecInt_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecInt_c::set_p(const Int *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecInt_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecInt_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecInt_c::last()
{
    m_p -= m_N;
}

inline void SvecInt_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecInt_c::~SvecInt_c() {}

typedef const SvecInt_c & SvecInt_I;

class SvecInt
{
protected:
    Int *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecInt();
    explicit SvecInt(Long_I N);
    SvecInt(Int *data, Long_I N); // unsafe
    SvecInt(Int *data, Long_I data_len, Long_I N);
    Int* p() const;
    Long size() const;
    Int & operator[](Long_I i) const;
    Int & operator()(Long_I i) const;
    Int & end() const;
    Int & end(Long_I i) const;
    operator SvecInt_c() const;
    void set(Int *data, Long_I data_len, Long_I N);
    void set(const SvecInt &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Int *data);
    void set_size(Long_I N);
    void set(Int *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecInt();
};

inline SvecInt::SvecInt() {}

inline SvecInt::SvecInt(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecInt::SvecInt(Int *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecInt::SvecInt(Int *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Int & SvecInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecInt::set(Int *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecInt::set(Int *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecInt::set(const SvecInt &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecInt::set_p(Int *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecInt::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecInt::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecInt::last()
{
    m_p -= m_N;
}

inline void SvecInt::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecInt::~SvecInt() {}

typedef const SvecInt & SvecInt_O, & SvecInt_IO;

class SvecLlong_c
{
protected:
    const Llong *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecLlong_c();
    explicit SvecLlong_c(Long_I N);
    SvecLlong_c(const Llong *data, Long_I N); // unsafe
    SvecLlong_c(const Llong *data, Long_I data_len, Long_I N);
    const Llong* p() const;
    Long size() const;
    const Llong & operator[](Long_I i) const;
    const Llong & operator()(Long_I i) const;
    const Llong & end() const;
    const Llong & end(Long_I i) const;
    void set(const Llong *data, Long_I data_len, Long_I N);
    void set(const SvecLlong_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Llong *data);
    void set_size(Long_I N);
    void set(const Llong *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLlong_c();
};

inline SvecLlong_c::SvecLlong_c() {}

inline SvecLlong_c::SvecLlong_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecLlong_c::SvecLlong_c(const Llong *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecLlong_c::SvecLlong_c(const Llong *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Llong & SvecLlong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecLlong_c::set(const Llong *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLlong_c::set(const Llong *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecLlong_c::set(const SvecLlong_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecLlong_c::set_p(const Llong *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLlong_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecLlong_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecLlong_c::last()
{
    m_p -= m_N;
}

inline void SvecLlong_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecLlong_c::~SvecLlong_c() {}

typedef const SvecLlong_c & SvecLlong_I;

class SvecLlong
{
protected:
    Llong *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecLlong();
    explicit SvecLlong(Long_I N);
    SvecLlong(Llong *data, Long_I N); // unsafe
    SvecLlong(Llong *data, Long_I data_len, Long_I N);
    Llong* p() const;
    Long size() const;
    Llong & operator[](Long_I i) const;
    Llong & operator()(Long_I i) const;
    Llong & end() const;
    Llong & end(Long_I i) const;
    operator SvecLlong_c() const;
    void set(Llong *data, Long_I data_len, Long_I N);
    void set(const SvecLlong &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Llong *data);
    void set_size(Long_I N);
    void set(Llong *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLlong();
};

inline SvecLlong::SvecLlong() {}

inline SvecLlong::SvecLlong(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecLlong::SvecLlong(Llong *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecLlong::SvecLlong(Llong *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Llong & SvecLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecLlong::set(Llong *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLlong::set(Llong *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecLlong::set(const SvecLlong &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecLlong::set_p(Llong *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLlong::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecLlong::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecLlong::last()
{
    m_p -= m_N;
}

inline void SvecLlong::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
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
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecFloat_c();
    explicit SvecFloat_c(Long_I N);
    SvecFloat_c(const Float *data, Long_I N); // unsafe
    SvecFloat_c(const Float *data, Long_I data_len, Long_I N);
    const Float* p() const;
    Long size() const;
    const Float & operator[](Long_I i) const;
    const Float & operator()(Long_I i) const;
    const Float & end() const;
    const Float & end(Long_I i) const;
    void set(const Float *data, Long_I data_len, Long_I N);
    void set(const SvecFloat_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Float *data);
    void set_size(Long_I N);
    void set(const Float *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecFloat_c();
};

inline SvecFloat_c::SvecFloat_c() {}

inline SvecFloat_c::SvecFloat_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecFloat_c::SvecFloat_c(const Float *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecFloat_c::SvecFloat_c(const Float *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Float & SvecFloat_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecFloat_c::set(const Float *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFloat_c::set(const Float *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecFloat_c::set(const SvecFloat_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecFloat_c::set_p(const Float *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFloat_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecFloat_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecFloat_c::last()
{
    m_p -= m_N;
}

inline void SvecFloat_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecFloat_c::~SvecFloat_c() {}

typedef const SvecFloat_c & SvecFloat_I;

class SvecFloat
{
protected:
    Float *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecFloat();
    explicit SvecFloat(Long_I N);
    SvecFloat(Float *data, Long_I N); // unsafe
    SvecFloat(Float *data, Long_I data_len, Long_I N);
    Float* p() const;
    Long size() const;
    Float & operator[](Long_I i) const;
    Float & operator()(Long_I i) const;
    Float & end() const;
    Float & end(Long_I i) const;
    operator SvecFloat_c() const;
    void set(Float *data, Long_I data_len, Long_I N);
    void set(const SvecFloat &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Float *data);
    void set_size(Long_I N);
    void set(Float *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecFloat();
};

inline SvecFloat::SvecFloat() {}

inline SvecFloat::SvecFloat(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecFloat::SvecFloat(Float *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecFloat::SvecFloat(Float *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Float & SvecFloat::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecFloat::set(Float *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFloat::set(Float *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecFloat::set(const SvecFloat &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecFloat::set_p(Float *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFloat::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecFloat::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecFloat::last()
{
    m_p -= m_N;
}

inline void SvecFloat::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecFloat::~SvecFloat() {}

typedef const SvecFloat & SvecFloat_O, & SvecFloat_IO;

class SvecDoub_c
{
protected:
    const Doub *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecDoub_c();
    explicit SvecDoub_c(Long_I N);
    SvecDoub_c(const Doub *data, Long_I N); // unsafe
    SvecDoub_c(const Doub *data, Long_I data_len, Long_I N);
    const Doub* p() const;
    Long size() const;
    const Doub & operator[](Long_I i) const;
    const Doub & operator()(Long_I i) const;
    const Doub & end() const;
    const Doub & end(Long_I i) const;
    void set(const Doub *data, Long_I data_len, Long_I N);
    void set(const SvecDoub_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Doub *data);
    void set_size(Long_I N);
    void set(const Doub *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecDoub_c();
};

inline SvecDoub_c::SvecDoub_c() {}

inline SvecDoub_c::SvecDoub_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecDoub_c::SvecDoub_c(const Doub *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecDoub_c::SvecDoub_c(const Doub *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Doub & SvecDoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecDoub_c::set(const Doub *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecDoub_c::set(const Doub *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecDoub_c::set(const SvecDoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecDoub_c::set_p(const Doub *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecDoub_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecDoub_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecDoub_c::last()
{
    m_p -= m_N;
}

inline void SvecDoub_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecDoub_c::~SvecDoub_c() {}

typedef const SvecDoub_c & SvecDoub_I;

class SvecDoub
{
protected:
    Doub *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecDoub();
    explicit SvecDoub(Long_I N);
    SvecDoub(Doub *data, Long_I N); // unsafe
    SvecDoub(Doub *data, Long_I data_len, Long_I N);
    Doub* p() const;
    Long size() const;
    Doub & operator[](Long_I i) const;
    Doub & operator()(Long_I i) const;
    Doub & end() const;
    Doub & end(Long_I i) const;
    operator SvecDoub_c() const;
    void set(Doub *data, Long_I data_len, Long_I N);
    void set(const SvecDoub &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Doub *data);
    void set_size(Long_I N);
    void set(Doub *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecDoub();
};

inline SvecDoub::SvecDoub() {}

inline SvecDoub::SvecDoub(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecDoub::SvecDoub(Doub *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecDoub::SvecDoub(Doub *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Doub & SvecDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecDoub::set(Doub *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecDoub::set(Doub *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecDoub::set(const SvecDoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecDoub::set_p(Doub *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecDoub::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecDoub::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecDoub::last()
{
    m_p -= m_N;
}

inline void SvecDoub::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecDoub::~SvecDoub() {}

typedef const SvecDoub & SvecDoub_O, & SvecDoub_IO;

class SvecLdoub_c
{
protected:
    const Ldoub *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecLdoub_c();
    explicit SvecLdoub_c(Long_I N);
    SvecLdoub_c(const Ldoub *data, Long_I N); // unsafe
    SvecLdoub_c(const Ldoub *data, Long_I data_len, Long_I N);
    const Ldoub* p() const;
    Long size() const;
    const Ldoub & operator[](Long_I i) const;
    const Ldoub & operator()(Long_I i) const;
    const Ldoub & end() const;
    const Ldoub & end(Long_I i) const;
    void set(const Ldoub *data, Long_I data_len, Long_I N);
    void set(const SvecLdoub_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Ldoub *data);
    void set_size(Long_I N);
    void set(const Ldoub *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLdoub_c();
};

inline SvecLdoub_c::SvecLdoub_c() {}

inline SvecLdoub_c::SvecLdoub_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecLdoub_c::SvecLdoub_c(const Ldoub *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecLdoub_c::SvecLdoub_c(const Ldoub *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Ldoub & SvecLdoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecLdoub_c::set(const Ldoub *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLdoub_c::set(const Ldoub *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecLdoub_c::set(const SvecLdoub_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecLdoub_c::set_p(const Ldoub *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLdoub_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecLdoub_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecLdoub_c::last()
{
    m_p -= m_N;
}

inline void SvecLdoub_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecLdoub_c::~SvecLdoub_c() {}

typedef const SvecLdoub_c & SvecLdoub_I;

class SvecLdoub
{
protected:
    Ldoub *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecLdoub();
    explicit SvecLdoub(Long_I N);
    SvecLdoub(Ldoub *data, Long_I N); // unsafe
    SvecLdoub(Ldoub *data, Long_I data_len, Long_I N);
    Ldoub* p() const;
    Long size() const;
    Ldoub & operator[](Long_I i) const;
    Ldoub & operator()(Long_I i) const;
    Ldoub & end() const;
    Ldoub & end(Long_I i) const;
    operator SvecLdoub_c() const;
    void set(Ldoub *data, Long_I data_len, Long_I N);
    void set(const SvecLdoub &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Ldoub *data);
    void set_size(Long_I N);
    void set(Ldoub *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLdoub();
};

inline SvecLdoub::SvecLdoub() {}

inline SvecLdoub::SvecLdoub(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecLdoub::SvecLdoub(Ldoub *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecLdoub::SvecLdoub(Ldoub *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Ldoub & SvecLdoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecLdoub::set(Ldoub *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLdoub::set(Ldoub *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecLdoub::set(const SvecLdoub &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecLdoub::set_p(Ldoub *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLdoub::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecLdoub::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecLdoub::last()
{
    m_p -= m_N;
}

inline void SvecLdoub::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecLdoub::~SvecLdoub() {}

typedef const SvecLdoub & SvecLdoub_O, & SvecLdoub_IO;

class SvecFcomp_c
{
protected:
    const Fcomp *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecFcomp_c();
    explicit SvecFcomp_c(Long_I N);
    SvecFcomp_c(const Fcomp *data, Long_I N); // unsafe
    SvecFcomp_c(const Fcomp *data, Long_I data_len, Long_I N);
    const Fcomp* p() const;
    Long size() const;
    const Fcomp & operator[](Long_I i) const;
    const Fcomp & operator()(Long_I i) const;
    const Fcomp & end() const;
    const Fcomp & end(Long_I i) const;
    void set(const Fcomp *data, Long_I data_len, Long_I N);
    void set(const SvecFcomp_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Fcomp *data);
    void set_size(Long_I N);
    void set(const Fcomp *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecFcomp_c();
};

inline SvecFcomp_c::SvecFcomp_c() {}

inline SvecFcomp_c::SvecFcomp_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecFcomp_c::SvecFcomp_c(const Fcomp *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecFcomp_c::SvecFcomp_c(const Fcomp *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Fcomp & SvecFcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecFcomp_c::set(const Fcomp *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFcomp_c::set(const Fcomp *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecFcomp_c::set(const SvecFcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecFcomp_c::set_p(const Fcomp *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFcomp_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecFcomp_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecFcomp_c::last()
{
    m_p -= m_N;
}

inline void SvecFcomp_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecFcomp_c::~SvecFcomp_c() {}

typedef const SvecFcomp_c & SvecFcomp_I;

class SvecFcomp
{
protected:
    Fcomp *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecFcomp();
    explicit SvecFcomp(Long_I N);
    SvecFcomp(Fcomp *data, Long_I N); // unsafe
    SvecFcomp(Fcomp *data, Long_I data_len, Long_I N);
    Fcomp* p() const;
    Long size() const;
    Fcomp & operator[](Long_I i) const;
    Fcomp & operator()(Long_I i) const;
    Fcomp & end() const;
    Fcomp & end(Long_I i) const;
    operator SvecFcomp_c() const;
    void set(Fcomp *data, Long_I data_len, Long_I N);
    void set(const SvecFcomp &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Fcomp *data);
    void set_size(Long_I N);
    void set(Fcomp *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecFcomp();
};

inline SvecFcomp::SvecFcomp() {}

inline SvecFcomp::SvecFcomp(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecFcomp::SvecFcomp(Fcomp *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecFcomp::SvecFcomp(Fcomp *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Fcomp & SvecFcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecFcomp::set(Fcomp *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFcomp::set(Fcomp *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecFcomp::set(const SvecFcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecFcomp::set_p(Fcomp *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFcomp::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecFcomp::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecFcomp::last()
{
    m_p -= m_N;
}

inline void SvecFcomp::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecFcomp::~SvecFcomp() {}

typedef const SvecFcomp & SvecFcomp_O, & SvecFcomp_IO;

class SvecComp_c
{
protected:
    const Comp *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecComp_c();
    explicit SvecComp_c(Long_I N);
    SvecComp_c(const Comp *data, Long_I N); // unsafe
    SvecComp_c(const Comp *data, Long_I data_len, Long_I N);
    const Comp* p() const;
    Long size() const;
    const Comp & operator[](Long_I i) const;
    const Comp & operator()(Long_I i) const;
    const Comp & end() const;
    const Comp & end(Long_I i) const;
    void set(const Comp *data, Long_I data_len, Long_I N);
    void set(const SvecComp_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Comp *data);
    void set_size(Long_I N);
    void set(const Comp *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecComp_c();
};

inline SvecComp_c::SvecComp_c() {}

inline SvecComp_c::SvecComp_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecComp_c::SvecComp_c(const Comp *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecComp_c::SvecComp_c(const Comp *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Comp & SvecComp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecComp_c::set(const Comp *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecComp_c::set(const Comp *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecComp_c::set(const SvecComp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecComp_c::set_p(const Comp *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecComp_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecComp_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecComp_c::last()
{
    m_p -= m_N;
}

inline void SvecComp_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecComp_c::~SvecComp_c() {}

typedef const SvecComp_c & SvecComp_I;

class SvecComp
{
protected:
    Comp *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecComp();
    explicit SvecComp(Long_I N);
    SvecComp(Comp *data, Long_I N); // unsafe
    SvecComp(Comp *data, Long_I data_len, Long_I N);
    Comp* p() const;
    Long size() const;
    Comp & operator[](Long_I i) const;
    Comp & operator()(Long_I i) const;
    Comp & end() const;
    Comp & end(Long_I i) const;
    operator SvecComp_c() const;
    void set(Comp *data, Long_I data_len, Long_I N);
    void set(const SvecComp &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Comp *data);
    void set_size(Long_I N);
    void set(Comp *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecComp();
};

inline SvecComp::SvecComp() {}

inline SvecComp::SvecComp(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecComp::SvecComp(Comp *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecComp::SvecComp(Comp *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Comp & SvecComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecComp::set(Comp *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecComp::set(Comp *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecComp::set(const SvecComp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecComp::set_p(Comp *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecComp::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecComp::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecComp::last()
{
    m_p -= m_N;
}

inline void SvecComp::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecComp::~SvecComp() {}

typedef const SvecComp & SvecComp_O, & SvecComp_IO;

class SvecLcomp_c
{
protected:
    const Lcomp *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecLcomp_c();
    explicit SvecLcomp_c(Long_I N);
    SvecLcomp_c(const Lcomp *data, Long_I N); // unsafe
    SvecLcomp_c(const Lcomp *data, Long_I data_len, Long_I N);
    const Lcomp* p() const;
    Long size() const;
    const Lcomp & operator[](Long_I i) const;
    const Lcomp & operator()(Long_I i) const;
    const Lcomp & end() const;
    const Lcomp & end(Long_I i) const;
    void set(const Lcomp *data, Long_I data_len, Long_I N);
    void set(const SvecLcomp_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Lcomp *data);
    void set_size(Long_I N);
    void set(const Lcomp *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLcomp_c();
};

inline SvecLcomp_c::SvecLcomp_c() {}

inline SvecLcomp_c::SvecLcomp_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecLcomp_c::SvecLcomp_c(const Lcomp *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecLcomp_c::SvecLcomp_c(const Lcomp *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Lcomp & SvecLcomp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecLcomp_c::set(const Lcomp *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLcomp_c::set(const Lcomp *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecLcomp_c::set(const SvecLcomp_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecLcomp_c::set_p(const Lcomp *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLcomp_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecLcomp_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecLcomp_c::last()
{
    m_p -= m_N;
}

inline void SvecLcomp_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecLcomp_c::~SvecLcomp_c() {}

typedef const SvecLcomp_c & SvecLcomp_I;

class SvecLcomp
{
protected:
    Lcomp *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecLcomp();
    explicit SvecLcomp(Long_I N);
    SvecLcomp(Lcomp *data, Long_I N); // unsafe
    SvecLcomp(Lcomp *data, Long_I data_len, Long_I N);
    Lcomp* p() const;
    Long size() const;
    Lcomp & operator[](Long_I i) const;
    Lcomp & operator()(Long_I i) const;
    Lcomp & end() const;
    Lcomp & end(Long_I i) const;
    operator SvecLcomp_c() const;
    void set(Lcomp *data, Long_I data_len, Long_I N);
    void set(const SvecLcomp &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Lcomp *data);
    void set_size(Long_I N);
    void set(Lcomp *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLcomp();
};

inline SvecLcomp::SvecLcomp() {}

inline SvecLcomp::SvecLcomp(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecLcomp::SvecLcomp(Lcomp *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecLcomp::SvecLcomp(Lcomp *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Lcomp & SvecLcomp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecLcomp::set(Lcomp *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLcomp::set(Lcomp *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecLcomp::set(const SvecLcomp &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecLcomp::set_p(Lcomp *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLcomp::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecLcomp::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecLcomp::last()
{
    m_p -= m_N;
}

inline void SvecLcomp::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecLcomp::~SvecLcomp() {}

typedef const SvecLcomp & SvecLcomp_O, & SvecLcomp_IO;

class SvecFimag_c
{
protected:
    const Fimag *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecFimag_c();
    explicit SvecFimag_c(Long_I N);
    SvecFimag_c(const Fimag *data, Long_I N); // unsafe
    SvecFimag_c(const Fimag *data, Long_I data_len, Long_I N);
    const Fimag* p() const;
    Long size() const;
    const Fimag & operator[](Long_I i) const;
    const Fimag & operator()(Long_I i) const;
    const Fimag & end() const;
    const Fimag & end(Long_I i) const;
    void set(const Fimag *data, Long_I data_len, Long_I N);
    void set(const SvecFimag_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Fimag *data);
    void set_size(Long_I N);
    void set(const Fimag *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecFimag_c();
};

inline SvecFimag_c::SvecFimag_c() {}

inline SvecFimag_c::SvecFimag_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecFimag_c::SvecFimag_c(const Fimag *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecFimag_c::SvecFimag_c(const Fimag *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Fimag & SvecFimag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecFimag_c::set(const Fimag *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFimag_c::set(const Fimag *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecFimag_c::set(const SvecFimag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecFimag_c::set_p(const Fimag *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFimag_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecFimag_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecFimag_c::last()
{
    m_p -= m_N;
}

inline void SvecFimag_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecFimag_c::~SvecFimag_c() {}

typedef const SvecFimag_c & SvecFimag_I;

class SvecFimag
{
protected:
    Fimag *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecFimag();
    explicit SvecFimag(Long_I N);
    SvecFimag(Fimag *data, Long_I N); // unsafe
    SvecFimag(Fimag *data, Long_I data_len, Long_I N);
    Fimag* p() const;
    Long size() const;
    Fimag & operator[](Long_I i) const;
    Fimag & operator()(Long_I i) const;
    Fimag & end() const;
    Fimag & end(Long_I i) const;
    operator SvecFimag_c() const;
    void set(Fimag *data, Long_I data_len, Long_I N);
    void set(const SvecFimag &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Fimag *data);
    void set_size(Long_I N);
    void set(Fimag *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecFimag();
};

inline SvecFimag::SvecFimag() {}

inline SvecFimag::SvecFimag(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecFimag::SvecFimag(Fimag *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecFimag::SvecFimag(Fimag *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Fimag & SvecFimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecFimag::set(Fimag *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFimag::set(Fimag *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecFimag::set(const SvecFimag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecFimag::set_p(Fimag *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecFimag::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecFimag::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecFimag::last()
{
    m_p -= m_N;
}

inline void SvecFimag::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecFimag::~SvecFimag() {}

typedef const SvecFimag & SvecFimag_O, & SvecFimag_IO;

class SvecImag_c
{
protected:
    const Imag *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecImag_c();
    explicit SvecImag_c(Long_I N);
    SvecImag_c(const Imag *data, Long_I N); // unsafe
    SvecImag_c(const Imag *data, Long_I data_len, Long_I N);
    const Imag* p() const;
    Long size() const;
    const Imag & operator[](Long_I i) const;
    const Imag & operator()(Long_I i) const;
    const Imag & end() const;
    const Imag & end(Long_I i) const;
    void set(const Imag *data, Long_I data_len, Long_I N);
    void set(const SvecImag_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Imag *data);
    void set_size(Long_I N);
    void set(const Imag *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecImag_c();
};

inline SvecImag_c::SvecImag_c() {}

inline SvecImag_c::SvecImag_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecImag_c::SvecImag_c(const Imag *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecImag_c::SvecImag_c(const Imag *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Imag & SvecImag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecImag_c::set(const Imag *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecImag_c::set(const Imag *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecImag_c::set(const SvecImag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecImag_c::set_p(const Imag *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecImag_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecImag_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecImag_c::last()
{
    m_p -= m_N;
}

inline void SvecImag_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecImag_c::~SvecImag_c() {}

typedef const SvecImag_c & SvecImag_I;

class SvecImag
{
protected:
    Imag *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecImag();
    explicit SvecImag(Long_I N);
    SvecImag(Imag *data, Long_I N); // unsafe
    SvecImag(Imag *data, Long_I data_len, Long_I N);
    Imag* p() const;
    Long size() const;
    Imag & operator[](Long_I i) const;
    Imag & operator()(Long_I i) const;
    Imag & end() const;
    Imag & end(Long_I i) const;
    operator SvecImag_c() const;
    void set(Imag *data, Long_I data_len, Long_I N);
    void set(const SvecImag &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Imag *data);
    void set_size(Long_I N);
    void set(Imag *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecImag();
};

inline SvecImag::SvecImag() {}

inline SvecImag::SvecImag(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecImag::SvecImag(Imag *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecImag::SvecImag(Imag *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Imag & SvecImag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecImag::set(Imag *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecImag::set(Imag *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecImag::set(const SvecImag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecImag::set_p(Imag *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecImag::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecImag::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecImag::last()
{
    m_p -= m_N;
}

inline void SvecImag::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecImag::~SvecImag() {}

typedef const SvecImag & SvecImag_O, & SvecImag_IO;

class SvecLimag_c
{
protected:
    const Limag *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecLimag_c();
    explicit SvecLimag_c(Long_I N);
    SvecLimag_c(const Limag *data, Long_I N); // unsafe
    SvecLimag_c(const Limag *data, Long_I data_len, Long_I N);
    const Limag* p() const;
    Long size() const;
    const Limag & operator[](Long_I i) const;
    const Limag & operator()(Long_I i) const;
    const Limag & end() const;
    const Limag & end(Long_I i) const;
    void set(const Limag *data, Long_I data_len, Long_I N);
    void set(const SvecLimag_c &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(const Limag *data);
    void set_size(Long_I N);
    void set(const Limag *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLimag_c();
};

inline SvecLimag_c::SvecLimag_c() {}

inline SvecLimag_c::SvecLimag_c(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecLimag_c::SvecLimag_c(const Limag *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecLimag_c::SvecLimag_c(const Limag *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline const Limag & SvecLimag_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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


inline void SvecLimag_c::set(const Limag *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLimag_c::set(const Limag *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecLimag_c::set(const SvecLimag_c &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecLimag_c::set_p(const Limag *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLimag_c::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecLimag_c::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecLimag_c::last()
{
    m_p -= m_N;
}

inline void SvecLimag_c::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecLimag_c::~SvecLimag_c() {}

typedef const SvecLimag_c & SvecLimag_I;

class SvecLimag
{
protected:
    Limag *m_p;
    Long m_N;
#ifdef SLS_CHECK_BOUNDS
    Long m_data_len; // used for debug
#endif
public:
    SvecLimag();
    explicit SvecLimag(Long_I N);
    SvecLimag(Limag *data, Long_I N); // unsafe
    SvecLimag(Limag *data, Long_I data_len, Long_I N);
    Limag* p() const;
    Long size() const;
    Limag & operator[](Long_I i) const;
    Limag & operator()(Long_I i) const;
    Limag & end() const;
    Limag & end(Long_I i) const;
    operator SvecLimag_c() const;
    void set(Limag *data, Long_I data_len, Long_I N);
    void set(const SvecLimag &sli);
    void next(); // m_p += m_N
    
    // === unsafe operations (unsafe) ===
    void set_p(Limag *data);
    void set_size(Long_I N);
    void set(Limag *data, Long_I N);
    void last(); // m_p -= m_N
    void shift(Long_I N); // m_p += N

    ~SvecLimag();
};

inline SvecLimag::SvecLimag() {}

inline SvecLimag::SvecLimag(Long_I N) : m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    m_p = nullptr; m_data_len = 0;
#endif
}

inline SvecLimag::SvecLimag(Limag *data, Long_I N)
    : m_p(data), m_N(N) {
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline SvecLimag::SvecLimag(Limag *data, Long_I data_len, Long_I N)
    : m_p(data), m_N(N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
    m_data_len = data_len;
#endif
}

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

inline Limag & SvecLimag::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[i];
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

inline void SvecLimag::set(Limag *data, Long_I N)
{
    m_p = data; m_N = N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLimag::set(Limag *data, Long_I data_len, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p = data; m_N = N;
}

inline void SvecLimag::set(const SvecLimag &sli)
{
    m_p = sli.m_p; m_N = sli.m_N;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = sli.m_data_len;
#endif
}

inline void SvecLimag::set_p(Limag *data)
{
    m_p = data;
#ifdef SLS_CHECK_BOUNDS
    m_data_len = std::numeric_limits<Long>::max();
#endif
}

inline void SvecLimag::set_size(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_N = N;
}

inline void SvecLimag::next()
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += m_N;
}

inline void SvecLimag::last()
{
    m_p -= m_N;
}

inline void SvecLimag::shift(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    m_data_len -= m_N;
    if (m_N > m_data_len)
        SLS_ERR("cut out of bound!");
#endif
    m_p += N;
}

inline SvecLimag::~SvecLimag() {}

typedef const SvecLimag & SvecLimag_O, & SvecLimag_IO;

} // namespace slisc
