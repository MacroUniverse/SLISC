class DcmatInt_c
{
private:
    const Int *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Int value_type;
    DcmatInt_c();
    DcmatInt_c(const Int *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Int *ptr, Long_I N1, Long_I N2, Long_I lda);

    // === Cmat member functions ===
    const Int& operator[](Long_I i) const;
    const Int& operator()(Long_I i) const;
    const Int& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Int *ptr() const;
};

inline DcmatInt_c::DcmatInt_c() {}

inline DcmatInt_c::DcmatInt_c(const Int *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatInt_c::set(const Int *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline const Int & DcmatInt_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Int & DcmatInt_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Int & DcmatInt_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatInt_c::n1() const
{
    return m_N1;
}

inline Long DcmatInt_c::n2() const
{
    return m_N2;
}

inline Long DcmatInt_c::lda() const
{
    return m_lda;
}

inline Long DcmatInt_c::size() const
{
    return m_N;
}

inline const Int * DcmatInt_c::ptr() const
{
    return m_p;
}

typedef const DcmatInt_c & DcmatInt_I;

class DcmatInt
{
private:
    Int *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Int value_type;
    DcmatInt();
    DcmatInt(Int *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Int *ptr, Long_I N1, Long_I N2, Long_I lda);

    // === Cmat member functions ===
    Int& operator[](Long_I i) const;
    Int& operator()(Long_I i) const;
    Int& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Int *ptr() const;
};

inline DcmatInt::DcmatInt() {}

inline DcmatInt::DcmatInt(Int *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatInt::set(Int *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline Int & DcmatInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Int & DcmatInt::operator()(Long_I i) const
{
    return operator[](i);
}

inline Int & DcmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatInt::n1() const
{
    return m_N1;
}

inline Long DcmatInt::n2() const
{
    return m_N2;
}

inline Long DcmatInt::lda() const
{
    return m_lda;
}

inline Long DcmatInt::size() const
{
    return m_N;
}

inline Int * DcmatInt::ptr() const
{
    return m_p;
}

typedef const DcmatInt & DcmatInt_O, & DcmatInt_IO;

class DcmatLlong_c
{
private:
    const Llong *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Llong value_type;
    DcmatLlong_c();
    DcmatLlong_c(const Llong *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Llong *ptr, Long_I N1, Long_I N2, Long_I lda);

    // === Cmat member functions ===
    const Llong& operator[](Long_I i) const;
    const Llong& operator()(Long_I i) const;
    const Llong& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Llong *ptr() const;
};

inline DcmatLlong_c::DcmatLlong_c() {}

inline DcmatLlong_c::DcmatLlong_c(const Llong *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatLlong_c::set(const Llong *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline const Llong & DcmatLlong_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Llong & DcmatLlong_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Llong & DcmatLlong_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLlong_c::n1() const
{
    return m_N1;
}

inline Long DcmatLlong_c::n2() const
{
    return m_N2;
}

inline Long DcmatLlong_c::lda() const
{
    return m_lda;
}

inline Long DcmatLlong_c::size() const
{
    return m_N;
}

inline const Llong * DcmatLlong_c::ptr() const
{
    return m_p;
}

typedef const DcmatLlong_c & DcmatLlong_I;

class DcmatLlong
{
private:
    Llong *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Llong value_type;
    DcmatLlong();
    DcmatLlong(Llong *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Llong *ptr, Long_I N1, Long_I N2, Long_I lda);

    // === Cmat member functions ===
    Llong& operator[](Long_I i) const;
    Llong& operator()(Long_I i) const;
    Llong& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Llong *ptr() const;
};

inline DcmatLlong::DcmatLlong() {}

inline DcmatLlong::DcmatLlong(Llong *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatLlong::set(Llong *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline Llong & DcmatLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Llong & DcmatLlong::operator()(Long_I i) const
{
    return operator[](i);
}

inline Llong & DcmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLlong::n1() const
{
    return m_N1;
}

inline Long DcmatLlong::n2() const
{
    return m_N2;
}

inline Long DcmatLlong::lda() const
{
    return m_lda;
}

inline Long DcmatLlong::size() const
{
    return m_N;
}

inline Llong * DcmatLlong::ptr() const
{
    return m_p;
}

typedef const DcmatLlong & DcmatLlong_O, & DcmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef DcmatInt_c DcmatLong_c;
#else
typedef DcmatLlong_c DcmatLong_c;
#endif

typedef const DcmatLong_c & DcmatLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef DcmatInt DcmatLong;
#else
typedef DcmatLlong DcmatLong;
#endif

typedef const DcmatLong & DcmatLong_O, & DcmatLong_IO;

class DcmatDoub_c
{
private:
    const Doub *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Doub value_type;
    DcmatDoub_c();
    DcmatDoub_c(const Doub *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Doub *ptr, Long_I N1, Long_I N2, Long_I lda);

    // === Cmat member functions ===
    const Doub& operator[](Long_I i) const;
    const Doub& operator()(Long_I i) const;
    const Doub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Doub *ptr() const;
};

inline DcmatDoub_c::DcmatDoub_c() {}

inline DcmatDoub_c::DcmatDoub_c(const Doub *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatDoub_c::set(const Doub *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline const Doub & DcmatDoub_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Doub & DcmatDoub_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Doub & DcmatDoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatDoub_c::n1() const
{
    return m_N1;
}

inline Long DcmatDoub_c::n2() const
{
    return m_N2;
}

inline Long DcmatDoub_c::lda() const
{
    return m_lda;
}

inline Long DcmatDoub_c::size() const
{
    return m_N;
}

inline const Doub * DcmatDoub_c::ptr() const
{
    return m_p;
}

typedef const DcmatDoub_c & DcmatDoub_I;

class DcmatDoub
{
private:
    Doub *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Doub value_type;
    DcmatDoub();
    DcmatDoub(Doub *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Doub *ptr, Long_I N1, Long_I N2, Long_I lda);

    // === Cmat member functions ===
    Doub& operator[](Long_I i) const;
    Doub& operator()(Long_I i) const;
    Doub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Doub *ptr() const;
};

inline DcmatDoub::DcmatDoub() {}

inline DcmatDoub::DcmatDoub(Doub *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatDoub::set(Doub *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline Doub & DcmatDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Doub & DcmatDoub::operator()(Long_I i) const
{
    return operator[](i);
}

inline Doub & DcmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatDoub::n1() const
{
    return m_N1;
}

inline Long DcmatDoub::n2() const
{
    return m_N2;
}

inline Long DcmatDoub::lda() const
{
    return m_lda;
}

inline Long DcmatDoub::size() const
{
    return m_N;
}

inline Doub * DcmatDoub::ptr() const
{
    return m_p;
}

typedef const DcmatDoub & DcmatDoub_O, & DcmatDoub_IO;

class DcmatComp_c
{
private:
    const Comp *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef const Comp value_type;
    DcmatComp_c();
    DcmatComp_c(const Comp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(const Comp *ptr, Long_I N1, Long_I N2, Long_I lda);

    // === Cmat member functions ===
    const Comp& operator[](Long_I i) const;
    const Comp& operator()(Long_I i) const;
    const Comp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Comp *ptr() const;
};

inline DcmatComp_c::DcmatComp_c() {}

inline DcmatComp_c::DcmatComp_c(const Comp *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatComp_c::set(const Comp *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline const Comp & DcmatComp_c::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline const Comp & DcmatComp_c::operator()(Long_I i) const
{
    return operator[](i);
}

inline const Comp & DcmatComp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatComp_c::n1() const
{
    return m_N1;
}

inline Long DcmatComp_c::n2() const
{
    return m_N2;
}

inline Long DcmatComp_c::lda() const
{
    return m_lda;
}

inline Long DcmatComp_c::size() const
{
    return m_N;
}

inline const Comp * DcmatComp_c::ptr() const
{
    return m_p;
}

typedef const DcmatComp_c & DcmatComp_I;

class DcmatComp
{
private:
    Comp *m_p;
    Long m_N;
    Long m_N1, m_N2;
    Long m_lda; // leading dimension (here is m_N1 of host matrix)
public:
    typedef Comp value_type;
    DcmatComp();
    DcmatComp(Comp *ptr, Long_I N1, Long_I N2, Long_I lda);
    void set(Comp *ptr, Long_I N1, Long_I N2, Long_I lda);

    // === Cmat member functions ===
    Comp& operator[](Long_I i) const;
    Comp& operator()(Long_I i) const;
    Comp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    Comp *ptr() const;
};

inline DcmatComp::DcmatComp() {}

inline DcmatComp::DcmatComp(Comp *ptr, Long_I N1, Long_I N2, Long_I lda)
    : m_p(ptr), m_N1(N1), m_N2(N2), m_N(N1*N2), m_lda(lda)
{}

inline void DcmatComp::set(Comp *ptr, Long_I N1, Long_I N2, Long_I lda)
{
    m_p = ptr; m_N1 = N1; m_N2 = N2; m_N = N1 * N2; m_lda = lda;
}

inline Comp & DcmatComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_N2 + m_lda * i / m_N2];
}

inline Comp & DcmatComp::operator()(Long_I i) const
{
    return operator[](i);
}

inline Comp & DcmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatComp::n1() const
{
    return m_N1;
}

inline Long DcmatComp::n2() const
{
    return m_N2;
}

inline Long DcmatComp::lda() const
{
    return m_lda;
}

inline Long DcmatComp::size() const
{
    return m_N;
}

inline Comp * DcmatComp::ptr() const
{
    return m_p;
}

typedef const DcmatComp & DcmatComp_O, & DcmatComp_IO;

