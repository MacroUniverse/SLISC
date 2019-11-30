class SvecLlong
{
public:
    typedef Llong value_type;
    Llong *m_p;
    Long m_N;
    SvecLlong();
    SvecLlong(Long_I N);
    SvecLlong(Llong *ptr, Long_I N);

    Llong* ptr() const; // get pointer
    Long size() const;
    // resize() is a bad idea, don't try to create it!
    Llong & operator[](Long_I i) const;
    Llong & operator()(Long_I i) const;
    Llong & end() const;
    Llong & end(Long_I i) const;

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

// ===========  slice to constant array (low level const) ========
class SvecLlong_c
{
public:
    typedef Llong value_type;
    const Llong *m_p;
    Long m_N;
    SvecLlong_c();
    SvecLlong_c(Long_I N);
    SvecLlong_c(const Llong *ptr, Long_I N);

    const Llong* ptr() const;
    Long size() const;
    // resize() is a bad idea, don't try to create it!
    const Llong & operator[](Long_I i) const;
    const Llong & operator()(Long_I i) const;
    const Llong& end() const;
    const Llong& end(Long_I i) const;

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

inline SvecLlong_c::~SvecLlong_c()
{}

typedef const SvecLlong_c & SvecLlong_I;
typedef SvecLlong & SvecLlong_O, & SvecLlong_IO;

class SvecDoub
{
public:
    typedef Doub value_type;
    Doub *m_p;
    Long m_N;
    SvecDoub();
    SvecDoub(Long_I N);
    SvecDoub(Doub *ptr, Long_I N);

    Doub* ptr() const; // get pointer
    Long size() const;
    // resize() is a bad idea, don't try to create it!
    Doub & operator[](Long_I i) const;
    Doub & operator()(Long_I i) const;
    Doub & end() const;
    Doub & end(Long_I i) const;

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

// ===========  slice to constant array (low level const) ========
class SvecDoub_c
{
public:
    typedef Doub value_type;
    const Doub *m_p;
    Long m_N;
    SvecDoub_c();
    SvecDoub_c(Long_I N);
    SvecDoub_c(const Doub *ptr, Long_I N);

    const Doub* ptr() const;
    Long size() const;
    // resize() is a bad idea, don't try to create it!
    const Doub & operator[](Long_I i) const;
    const Doub & operator()(Long_I i) const;
    const Doub& end() const;
    const Doub& end(Long_I i) const;

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

inline SvecDoub_c::~SvecDoub_c()
{}

typedef const SvecDoub_c & SvecDoub_I;
typedef SvecDoub & SvecDoub_O, & SvecDoub_IO;

class SvecComp
{
public:
    typedef Comp value_type;
    Comp *m_p;
    Long m_N;
    SvecComp();
    SvecComp(Long_I N);
    SvecComp(Comp *ptr, Long_I N);

    Comp* ptr() const; // get pointer
    Long size() const;
    // resize() is a bad idea, don't try to create it!
    Comp & operator[](Long_I i) const;
    Comp & operator()(Long_I i) const;
    Comp & end() const;
    Comp & end(Long_I i) const;

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

// ===========  slice to constant array (low level const) ========
class SvecComp_c
{
public:
    typedef Comp value_type;
    const Comp *m_p;
    Long m_N;
    SvecComp_c();
    SvecComp_c(Long_I N);
    SvecComp_c(const Comp *ptr, Long_I N);

    const Comp* ptr() const;
    Long size() const;
    // resize() is a bad idea, don't try to create it!
    const Comp & operator[](Long_I i) const;
    const Comp & operator()(Long_I i) const;
    const Comp& end() const;
    const Comp& end(Long_I i) const;

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

inline SvecComp_c::~SvecComp_c()
{}

typedef const SvecComp_c & SvecComp_I;
typedef SvecComp & SvecComp_O, & SvecComp_IO;

