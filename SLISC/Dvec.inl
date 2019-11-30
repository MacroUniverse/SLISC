class DvecLlong
{
private:
    Llong *m_p;
    Long m_N;
    Long m_step;

public:
    DvecLlong();
    DvecLlong(const Llong *ptr, Long_I N, Long_I step);

    Llong* ptr(); // get pointer
    const Llong* ptr() const;
    Long size() const;
    Long step() const;
    // resize() is a bad idea, don't try to create it!
    Llong & operator[](Long_I i);
    const Llong & operator[](Long_I i) const;
    Llong & operator()(Long_I i);
    const Llong & operator()(Long_I i) const;
    Llong& end();
    const Llong& end() const;
    Llong& end(Long_I i);
    const Llong& end(Long_I i) const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Llong *ptr);
    void set(const Llong *ptr, Long_I N, Long_I step);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecLlong();
};

inline DvecLlong::DvecLlong() {}

inline DvecLlong::DvecLlong(const Llong *ptr, Long_I N, Long_I step)
    : m_p((Llong *)ptr), m_N(N), m_step(step) {}

inline Llong * DvecLlong::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Llong * DvecLlong::ptr() const
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

inline Llong & DvecLlong::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Llong & DvecLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Llong & DvecLlong::operator()(Long_I i)
{ return (*this)[i]; }

inline const Llong & DvecLlong::operator()(Long_I i) const
{ return (*this)[i]; }

inline Llong & DvecLlong::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Llong & DvecLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Llong & DvecLlong::end(Long_I i)
{
    return m_p[m_step*(m_N - 1)];
}

inline const Llong & DvecLlong::end(Long_I i) const
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

inline void DvecLlong::set_ptr(const Llong * ptr)
{
    m_p = (Llong *)ptr;
}

inline void DvecLlong::set(const Llong * ptr, Long_I N, Long_I step)
{
    m_p = (Llong *)ptr; m_N = N; m_step = step;
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

typedef const DvecLlong & DvecLlong_I;
typedef DvecLlong & DvecLlong_O, & DvecLlong_IO;

class DvecDoub
{
private:
    Doub *m_p;
    Long m_N;
    Long m_step;

public:
    DvecDoub();
    DvecDoub(const Doub *ptr, Long_I N, Long_I step);

    Doub* ptr(); // get pointer
    const Doub* ptr() const;
    Long size() const;
    Long step() const;
    // resize() is a bad idea, don't try to create it!
    Doub & operator[](Long_I i);
    const Doub & operator[](Long_I i) const;
    Doub & operator()(Long_I i);
    const Doub & operator()(Long_I i) const;
    Doub& end();
    const Doub& end() const;
    Doub& end(Long_I i);
    const Doub& end(Long_I i) const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Doub *ptr);
    void set(const Doub *ptr, Long_I N, Long_I step);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecDoub();
};

inline DvecDoub::DvecDoub() {}

inline DvecDoub::DvecDoub(const Doub *ptr, Long_I N, Long_I step)
    : m_p((Doub *)ptr), m_N(N), m_step(step) {}

inline Doub * DvecDoub::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Doub * DvecDoub::ptr() const
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

inline Doub & DvecDoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Doub & DvecDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Doub & DvecDoub::operator()(Long_I i)
{ return (*this)[i]; }

inline const Doub & DvecDoub::operator()(Long_I i) const
{ return (*this)[i]; }

inline Doub & DvecDoub::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Doub & DvecDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Doub & DvecDoub::end(Long_I i)
{
    return m_p[m_step*(m_N - 1)];
}

inline const Doub & DvecDoub::end(Long_I i) const
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

inline void DvecDoub::set_ptr(const Doub * ptr)
{
    m_p = (Doub *)ptr;
}

inline void DvecDoub::set(const Doub * ptr, Long_I N, Long_I step)
{
    m_p = (Doub *)ptr; m_N = N; m_step = step;
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

typedef const DvecDoub & DvecDoub_I;
typedef DvecDoub & DvecDoub_O, & DvecDoub_IO;

class DvecComp
{
private:
    Comp *m_p;
    Long m_N;
    Long m_step;

public:
    DvecComp();
    DvecComp(const Comp *ptr, Long_I N, Long_I step);

    Comp* ptr(); // get pointer
    const Comp* ptr() const;
    Long size() const;
    Long step() const;
    // resize() is a bad idea, don't try to create it!
    Comp & operator[](Long_I i);
    const Comp & operator[](Long_I i) const;
    Comp & operator()(Long_I i);
    const Comp & operator()(Long_I i) const;
    Comp& end();
    const Comp& end() const;
    Comp& end(Long_I i);
    const Comp& end(Long_I i) const;

    // === other member functions ===
    // There is no bound checking, use with care
    void set_size(Long_I N);
    void set_ptr(const Comp *ptr);
    void set(const Comp *ptr, Long_I N, Long_I step);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    
    ~DvecComp();
};

inline DvecComp::DvecComp() {}

inline DvecComp::DvecComp(const Comp *ptr, Long_I N, Long_I step)
    : m_p((Comp *)ptr), m_N(N), m_step(step) {}

inline Comp * DvecComp::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Comp * DvecComp::ptr() const
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

inline Comp & DvecComp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline const Comp & DvecComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Vbase subscript out of bounds");
#endif
    return m_p[m_step*i];
}

inline Comp & DvecComp::operator()(Long_I i)
{ return (*this)[i]; }

inline const Comp & DvecComp::operator()(Long_I i) const
{ return (*this)[i]; }

inline Comp & DvecComp::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline const Comp & DvecComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_step*(m_N - 1)];
}

inline Comp & DvecComp::end(Long_I i)
{
    return m_p[m_step*(m_N - 1)];
}

inline const Comp & DvecComp::end(Long_I i) const
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

inline void DvecComp::set_ptr(const Comp * ptr)
{
    m_p = (Comp *)ptr;
}

inline void DvecComp::set(const Comp * ptr, Long_I N, Long_I step)
{
    m_p = (Comp *)ptr; m_N = N; m_step = step;
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

typedef const DvecComp & DvecComp_I;
typedef DvecComp & DvecComp_O, & DvecComp_IO;

