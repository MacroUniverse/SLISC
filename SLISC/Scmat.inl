class ScmatLlong : public SvecLlong
{
public:
    typedef SvecLlong Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
    ScmatLlong();
    ScmatLlong(Long_I Nr, Long_I Nc);
    ScmatLlong(Llong *ptr, Long_I Nr, Long_I Nc);

    // === Cmat functions ===
    Llong& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I Nr, Long_I Nc);
    void set_ptr(Llong *ptr);
    void set(Llong *ptr, Long_I Nr, Long_I Nc);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    ~ScmatLlong();
};

inline ScmatLlong::ScmatLlong() {}

inline ScmatLlong::ScmatLlong(Long_I Nr, Long_I Nc)
    : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline ScmatLlong::ScmatLlong(Llong *ptr, Long_I Nr, Long_I Nc)
    : ScmatLlong(Nr, Nc)
{
    m_p = (Llong *)ptr;
}

inline Llong & ScmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_Nr * j];
}

inline Long ScmatLlong::n1() const
{
    return m_Nr;
}

inline Long ScmatLlong::n2() const
{
    return m_Nc;
}

inline void ScmatLlong::set_size(Long_I Nr, Long_I Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr <= 0 || Nc <= 0) SLS_ERR("illegal Nr or Nc!");
#endif
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatLlong::set_ptr(Llong * ptr)
{
    m_p = (Llong *)ptr;
}

inline void ScmatLlong::set(Llong * ptr, Long_I Nr, Long_I Nc)
{
    m_p = (Llong *)ptr;
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatLlong::next()
{
    m_p += m_N;
}

inline void ScmatLlong::last()
{
    m_p -= m_N;
}

inline void ScmatLlong::shift(Long_I N)
{
    m_p += N;
}

inline ScmatLlong::~ScmatLlong() {}


// ========== low level const of ScmatLlong =========
class ScmatLlong_c : public SvecLlong
{
public:
    typedef SvecLlong Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
    ScmatLlong_c();
    ScmatLlong_c(Long_I Nr, Long_I Nc);
    ScmatLlong_c(const Llong *ptr, Long_I Nr, Long_I Nc);

    // === Cmat functions ===
    const Llong& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I Nr, Long_I Nc);
    void set_ptr(const Llong *ptr);
    void set(const Llong *ptr, Long_I Nr, Long_I Nc);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    ~ScmatLlong_c();
};

inline ScmatLlong_c::ScmatLlong_c() {}

inline ScmatLlong_c::ScmatLlong_c(Long_I Nr, Long_I Nc)
    : m_Nr(Nr), m_Nc(Nc), Base(Nr*Nc) {}

inline ScmatLlong_c::ScmatLlong_c(const Llong *ptr, Long_I Nr, Long_I Nc)
    : ScmatLlong_c(Nr, Nc)
{
    m_p = (Llong *)ptr;
}

inline const Llong & ScmatLlong_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_Nr * j];
}

inline Long ScmatLlong_c::n1() const
{
    return m_Nr;
}

inline Long ScmatLlong_c::n2() const
{
    return m_Nc;
}

inline void ScmatLlong_c::set_size(Long_I Nr, Long_I Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr <= 0 || Nc <= 0) SLS_ERR("illegal Nr or Nc!");
#endif
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatLlong_c::set_ptr(const Llong * ptr)
{
    m_p = (Llong *)ptr;
}

inline void ScmatLlong_c::set(const Llong * ptr, Long_I Nr, Long_I Nc)
{
    m_p = (Llong *)ptr;
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatLlong_c::next()
{
    m_p += m_N;
}

inline void ScmatLlong_c::last()
{
    m_p -= m_N;
}

inline void ScmatLlong_c::shift(Long_I N)
{
    m_p += N;
}

inline ScmatLlong_c::~ScmatLlong_c() {}

class ScmatDoub : public SvecDoub
{
public:
    typedef SvecDoub Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
    ScmatDoub();
    ScmatDoub(Long_I Nr, Long_I Nc);
    ScmatDoub(Doub *ptr, Long_I Nr, Long_I Nc);

    // === Cmat functions ===
    Doub& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I Nr, Long_I Nc);
    void set_ptr(Doub *ptr);
    void set(Doub *ptr, Long_I Nr, Long_I Nc);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    ~ScmatDoub();
};

inline ScmatDoub::ScmatDoub() {}

inline ScmatDoub::ScmatDoub(Long_I Nr, Long_I Nc)
    : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline ScmatDoub::ScmatDoub(Doub *ptr, Long_I Nr, Long_I Nc)
    : ScmatDoub(Nr, Nc)
{
    m_p = (Doub *)ptr;
}

inline Doub & ScmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_Nr * j];
}

inline Long ScmatDoub::n1() const
{
    return m_Nr;
}

inline Long ScmatDoub::n2() const
{
    return m_Nc;
}

inline void ScmatDoub::set_size(Long_I Nr, Long_I Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr <= 0 || Nc <= 0) SLS_ERR("illegal Nr or Nc!");
#endif
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatDoub::set_ptr(Doub * ptr)
{
    m_p = (Doub *)ptr;
}

inline void ScmatDoub::set(Doub * ptr, Long_I Nr, Long_I Nc)
{
    m_p = (Doub *)ptr;
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatDoub::next()
{
    m_p += m_N;
}

inline void ScmatDoub::last()
{
    m_p -= m_N;
}

inline void ScmatDoub::shift(Long_I N)
{
    m_p += N;
}

inline ScmatDoub::~ScmatDoub() {}


// ========== low level const of ScmatDoub =========
class ScmatDoub_c : public SvecDoub
{
public:
    typedef SvecDoub Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
    ScmatDoub_c();
    ScmatDoub_c(Long_I Nr, Long_I Nc);
    ScmatDoub_c(const Doub *ptr, Long_I Nr, Long_I Nc);

    // === Cmat functions ===
    const Doub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I Nr, Long_I Nc);
    void set_ptr(const Doub *ptr);
    void set(const Doub *ptr, Long_I Nr, Long_I Nc);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    ~ScmatDoub_c();
};

inline ScmatDoub_c::ScmatDoub_c() {}

inline ScmatDoub_c::ScmatDoub_c(Long_I Nr, Long_I Nc)
    : m_Nr(Nr), m_Nc(Nc), Base(Nr*Nc) {}

inline ScmatDoub_c::ScmatDoub_c(const Doub *ptr, Long_I Nr, Long_I Nc)
    : ScmatDoub_c(Nr, Nc)
{
    m_p = (Doub *)ptr;
}

inline const Doub & ScmatDoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_Nr * j];
}

inline Long ScmatDoub_c::n1() const
{
    return m_Nr;
}

inline Long ScmatDoub_c::n2() const
{
    return m_Nc;
}

inline void ScmatDoub_c::set_size(Long_I Nr, Long_I Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr <= 0 || Nc <= 0) SLS_ERR("illegal Nr or Nc!");
#endif
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatDoub_c::set_ptr(const Doub * ptr)
{
    m_p = (Doub *)ptr;
}

inline void ScmatDoub_c::set(const Doub * ptr, Long_I Nr, Long_I Nc)
{
    m_p = (Doub *)ptr;
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatDoub_c::next()
{
    m_p += m_N;
}

inline void ScmatDoub_c::last()
{
    m_p -= m_N;
}

inline void ScmatDoub_c::shift(Long_I N)
{
    m_p += N;
}

inline ScmatDoub_c::~ScmatDoub_c() {}

class ScmatComp : public SvecComp
{
public:
    typedef SvecComp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
    ScmatComp();
    ScmatComp(Long_I Nr, Long_I Nc);
    ScmatComp(Comp *ptr, Long_I Nr, Long_I Nc);

    // === Cmat functions ===
    Comp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I Nr, Long_I Nc);
    void set_ptr(Comp *ptr);
    void set(Comp *ptr, Long_I Nr, Long_I Nc);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    ~ScmatComp();
};

inline ScmatComp::ScmatComp() {}

inline ScmatComp::ScmatComp(Long_I Nr, Long_I Nc)
    : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline ScmatComp::ScmatComp(Comp *ptr, Long_I Nr, Long_I Nc)
    : ScmatComp(Nr, Nc)
{
    m_p = (Comp *)ptr;
}

inline Comp & ScmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_Nr * j];
}

inline Long ScmatComp::n1() const
{
    return m_Nr;
}

inline Long ScmatComp::n2() const
{
    return m_Nc;
}

inline void ScmatComp::set_size(Long_I Nr, Long_I Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr <= 0 || Nc <= 0) SLS_ERR("illegal Nr or Nc!");
#endif
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatComp::set_ptr(Comp * ptr)
{
    m_p = (Comp *)ptr;
}

inline void ScmatComp::set(Comp * ptr, Long_I Nr, Long_I Nc)
{
    m_p = (Comp *)ptr;
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatComp::next()
{
    m_p += m_N;
}

inline void ScmatComp::last()
{
    m_p -= m_N;
}

inline void ScmatComp::shift(Long_I N)
{
    m_p += N;
}

inline ScmatComp::~ScmatComp() {}


// ========== low level const of ScmatComp =========
class ScmatComp_c : public SvecComp
{
public:
    typedef SvecComp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
    ScmatComp_c();
    ScmatComp_c(Long_I Nr, Long_I Nc);
    ScmatComp_c(const Comp *ptr, Long_I Nr, Long_I Nc);

    // === Cmat functions ===
    const Comp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I Nr, Long_I Nc);
    void set_ptr(const Comp *ptr);
    void set(const Comp *ptr, Long_I Nr, Long_I Nc);
    void next(); // m_ptr += m_N
    void last(); // m_ptr -= m_N
    void shift(Long_I N); // m_ptr += N;
    ~ScmatComp_c();
};

inline ScmatComp_c::ScmatComp_c() {}

inline ScmatComp_c::ScmatComp_c(Long_I Nr, Long_I Nc)
    : m_Nr(Nr), m_Nc(Nc), Base(Nr*Nc) {}

inline ScmatComp_c::ScmatComp_c(const Comp *ptr, Long_I Nr, Long_I Nc)
    : ScmatComp_c(Nr, Nc)
{
    m_p = (Comp *)ptr;
}

inline const Comp & ScmatComp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_Nr * j];
}

inline Long ScmatComp_c::n1() const
{
    return m_Nr;
}

inline Long ScmatComp_c::n2() const
{
    return m_Nc;
}

inline void ScmatComp_c::set_size(Long_I Nr, Long_I Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr <= 0 || Nc <= 0) SLS_ERR("illegal Nr or Nc!");
#endif
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatComp_c::set_ptr(const Comp * ptr)
{
    m_p = (Comp *)ptr;
}

inline void ScmatComp_c::set(const Comp * ptr, Long_I Nr, Long_I Nc)
{
    m_p = (Comp *)ptr;
    m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc;
}

inline void ScmatComp_c::next()
{
    m_p += m_N;
}

inline void ScmatComp_c::last()
{
    m_p -= m_N;
}

inline void ScmatComp_c::shift(Long_I N)
{
    m_p += N;
}

inline ScmatComp_c::~ScmatComp_c() {}

