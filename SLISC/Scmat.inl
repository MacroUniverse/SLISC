class ScmatInt_c : public SvecInt_c
{
public:
    Long m_N1, m_N2;
    ScmatInt_c();
    ScmatInt_c(Long_I N1, Long_I N2);
    ScmatInt_c(const Int *ptr, Long_I N1, Long_I N2);

    // === Cmat functions ===
    const Int& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(const Int *ptr, Long_I N1, Long_I N2);
    ~ScmatInt_c();
};

inline ScmatInt_c::ScmatInt_c() {}

inline ScmatInt_c::ScmatInt_c(Long_I N1, Long_I N2)
    : SvecInt_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatInt_c::ScmatInt_c(const Int *ptr, Long_I N1, Long_I N2)
    : ScmatInt_c(N1, N2)
{
    m_p = ptr;
}

inline const Int & ScmatInt_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatInt_c::n1() const
{
    return m_N1;
}

inline Long ScmatInt_c::n2() const
{
    return m_N2;
}

inline void ScmatInt_c::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatInt_c::set(const Int * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline ScmatInt_c::~ScmatInt_c() {}

typedef const ScmatInt_c & ScmatInt_I;

class ScmatInt : public SvecInt
{
public:
    Long m_N1, m_N2;
    ScmatInt();
    ScmatInt(Long_I N1, Long_I N2);
    ScmatInt(Int *ptr, Long_I N1, Long_I N2);

    // === Cmat functions ===
    Int& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(Int *ptr, Long_I N1, Long_I N2);
    ~ScmatInt();
};

inline ScmatInt::ScmatInt() {}

inline ScmatInt::ScmatInt(Long_I N1, Long_I N2)
    : SvecInt(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatInt::ScmatInt(Int *ptr, Long_I N1, Long_I N2)
    : ScmatInt(N1, N2)
{
    m_p = ptr;
}

inline Int & ScmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatInt::n1() const
{
    return m_N1;
}

inline Long ScmatInt::n2() const
{
    return m_N2;
}

inline void ScmatInt::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatInt::set(Int * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline ScmatInt::~ScmatInt() {}

typedef const ScmatInt & ScmatInt_O, & ScmatInt_IO;

class ScmatLlong_c : public SvecLlong_c
{
public:
    Long m_N1, m_N2;
    ScmatLlong_c();
    ScmatLlong_c(Long_I N1, Long_I N2);
    ScmatLlong_c(const Llong *ptr, Long_I N1, Long_I N2);

    // === Cmat functions ===
    const Llong& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(const Llong *ptr, Long_I N1, Long_I N2);
    ~ScmatLlong_c();
};

inline ScmatLlong_c::ScmatLlong_c() {}

inline ScmatLlong_c::ScmatLlong_c(Long_I N1, Long_I N2)
    : SvecLlong_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLlong_c::ScmatLlong_c(const Llong *ptr, Long_I N1, Long_I N2)
    : ScmatLlong_c(N1, N2)
{
    m_p = ptr;
}

inline const Llong & ScmatLlong_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLlong_c::n1() const
{
    return m_N1;
}

inline Long ScmatLlong_c::n2() const
{
    return m_N2;
}

inline void ScmatLlong_c::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLlong_c::set(const Llong * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline ScmatLlong_c::~ScmatLlong_c() {}

typedef const ScmatLlong_c & ScmatLlong_I;

class ScmatLlong : public SvecLlong
{
public:
    Long m_N1, m_N2;
    ScmatLlong();
    ScmatLlong(Long_I N1, Long_I N2);
    ScmatLlong(Llong *ptr, Long_I N1, Long_I N2);

    // === Cmat functions ===
    Llong& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(Llong *ptr, Long_I N1, Long_I N2);
    ~ScmatLlong();
};

inline ScmatLlong::ScmatLlong() {}

inline ScmatLlong::ScmatLlong(Long_I N1, Long_I N2)
    : SvecLlong(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLlong::ScmatLlong(Llong *ptr, Long_I N1, Long_I N2)
    : ScmatLlong(N1, N2)
{
    m_p = ptr;
}

inline Llong & ScmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLlong::n1() const
{
    return m_N1;
}

inline Long ScmatLlong::n2() const
{
    return m_N2;
}

inline void ScmatLlong::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLlong::set(Llong * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline ScmatLlong::~ScmatLlong() {}

typedef const ScmatLlong & ScmatLlong_O, & ScmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef ScmatInt_c ScmatLong_c;
#else
typedef ScmatLlong_c ScmatLong_c;
#endif

typedef const ScmatLong_c & ScmatLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef ScmatInt ScmatLong;
#else
typedef ScmatLlong ScmatLong;
#endif

typedef const ScmatLong & ScmatLong_O, & ScmatLong_IO;

class ScmatDoub_c : public SvecDoub_c
{
public:
    Long m_N1, m_N2;
    ScmatDoub_c();
    ScmatDoub_c(Long_I N1, Long_I N2);
    ScmatDoub_c(const Doub *ptr, Long_I N1, Long_I N2);

    // === Cmat functions ===
    const Doub& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(const Doub *ptr, Long_I N1, Long_I N2);
    ~ScmatDoub_c();
};

inline ScmatDoub_c::ScmatDoub_c() {}

inline ScmatDoub_c::ScmatDoub_c(Long_I N1, Long_I N2)
    : SvecDoub_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatDoub_c::ScmatDoub_c(const Doub *ptr, Long_I N1, Long_I N2)
    : ScmatDoub_c(N1, N2)
{
    m_p = ptr;
}

inline const Doub & ScmatDoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatDoub_c::n1() const
{
    return m_N1;
}

inline Long ScmatDoub_c::n2() const
{
    return m_N2;
}

inline void ScmatDoub_c::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatDoub_c::set(const Doub * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline ScmatDoub_c::~ScmatDoub_c() {}

typedef const ScmatDoub_c & ScmatDoub_I;

class ScmatDoub : public SvecDoub
{
public:
    Long m_N1, m_N2;
    ScmatDoub();
    ScmatDoub(Long_I N1, Long_I N2);
    ScmatDoub(Doub *ptr, Long_I N1, Long_I N2);

    // === Cmat functions ===
    Doub& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(Doub *ptr, Long_I N1, Long_I N2);
    ~ScmatDoub();
};

inline ScmatDoub::ScmatDoub() {}

inline ScmatDoub::ScmatDoub(Long_I N1, Long_I N2)
    : SvecDoub(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatDoub::ScmatDoub(Doub *ptr, Long_I N1, Long_I N2)
    : ScmatDoub(N1, N2)
{
    m_p = ptr;
}

inline Doub & ScmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatDoub::n1() const
{
    return m_N1;
}

inline Long ScmatDoub::n2() const
{
    return m_N2;
}

inline void ScmatDoub::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatDoub::set(Doub * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline ScmatDoub::~ScmatDoub() {}

typedef const ScmatDoub & ScmatDoub_O, & ScmatDoub_IO;

class ScmatComp_c : public SvecComp_c
{
public:
    Long m_N1, m_N2;
    ScmatComp_c();
    ScmatComp_c(Long_I N1, Long_I N2);
    ScmatComp_c(const Comp *ptr, Long_I N1, Long_I N2);

    // === Cmat functions ===
    const Comp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(const Comp *ptr, Long_I N1, Long_I N2);
    ~ScmatComp_c();
};

inline ScmatComp_c::ScmatComp_c() {}

inline ScmatComp_c::ScmatComp_c(Long_I N1, Long_I N2)
    : SvecComp_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatComp_c::ScmatComp_c(const Comp *ptr, Long_I N1, Long_I N2)
    : ScmatComp_c(N1, N2)
{
    m_p = ptr;
}

inline const Comp & ScmatComp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatComp_c::n1() const
{
    return m_N1;
}

inline Long ScmatComp_c::n2() const
{
    return m_N2;
}

inline void ScmatComp_c::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatComp_c::set(const Comp * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline ScmatComp_c::~ScmatComp_c() {}

typedef const ScmatComp_c & ScmatComp_I;

class ScmatComp : public SvecComp
{
public:
    Long m_N1, m_N2;
    ScmatComp();
    ScmatComp(Long_I N1, Long_I N2);
    ScmatComp(Comp *ptr, Long_I N1, Long_I N2);

    // === Cmat functions ===
    Comp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(Comp *ptr, Long_I N1, Long_I N2);
    ~ScmatComp();
};

inline ScmatComp::ScmatComp() {}

inline ScmatComp::ScmatComp(Long_I N1, Long_I N2)
    : SvecComp(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatComp::ScmatComp(Comp *ptr, Long_I N1, Long_I N2)
    : ScmatComp(N1, N2)
{
    m_p = ptr;
}

inline Comp & ScmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatComp::n1() const
{
    return m_N1;
}

inline Long ScmatComp::n2() const
{
    return m_N2;
}

inline void ScmatComp::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatComp::set(Comp * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline ScmatComp::~ScmatComp() {}

typedef const ScmatComp & ScmatComp_O, & ScmatComp_IO;

