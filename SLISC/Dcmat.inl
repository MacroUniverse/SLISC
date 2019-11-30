class DcmatLlong
{
private:
    Llong *m_p;
    Long m_N;
    Long m_Nr, m_Nc;
    Long m_lda; // leading dimension (here is m_Nr of host matrix)
public:
    typedef Llong value_type;
    DcmatLlong();
    DcmatLlong(const Llong *ptr, Long_I Nr, Long_I Nc, Long_I lda);
    void set(const Llong *ptr, Long_I Nr, Long_I Nc, Long_I lda);

    // === Cmat member functions ===
    Llong& operator[](Long_I i);    // single indexing (inefficient)
    const Llong& operator[](Long_I i) const;
    Llong& operator()(Long_I i);    // same as operator[]
    const Llong& operator()(Long_I i) const;
    Llong& operator()(Long_I i, Long_I j);    // double indexing
    const Llong& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Llong *ptr() const;
    Llong *ptr();
};

inline DcmatLlong::DcmatLlong() {}

inline DcmatLlong::DcmatLlong(const Llong *ptr, Long_I Nr, Long_I Nc, Long_I lda)
    : m_p((Llong *)ptr), m_Nr(Nr), m_Nc(Nc), m_N(Nr*Nc), m_lda(lda)
{}

inline void DcmatLlong::set(const Llong *ptr, Long_I Nr, Long_I Nc, Long_I lda)
{
    m_p = (Llong *)ptr; m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc; m_lda = lda;
}

inline Llong & DcmatLlong::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_Nc + m_lda * i/m_Nc];
}

inline const Llong & DcmatLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_Nc + m_lda * i / m_Nc];
}

inline Llong & DcmatLlong::operator()(Long_I i)
{
    return operator[](i);
}

inline const Llong & DcmatLlong::operator()(Long_I i) const
{
    return operator[](i);
}

inline Llong & DcmatLlong::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline const Llong & DcmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatLlong::n1() const
{
    return m_Nr;
}

inline Long DcmatLlong::n2() const
{
    return m_Nc;
}

inline Long DcmatLlong::lda() const
{
    return m_lda;
}

inline Long DcmatLlong::size() const
{
    return m_N;
}

inline const Llong * DcmatLlong::ptr() const
{
    return m_p;
}

inline Llong * DcmatLlong::ptr()
{
    return m_p;
}

class DcmatDoub
{
private:
    Doub *m_p;
    Long m_N;
    Long m_Nr, m_Nc;
    Long m_lda; // leading dimension (here is m_Nr of host matrix)
public:
    typedef Doub value_type;
    DcmatDoub();
    DcmatDoub(const Doub *ptr, Long_I Nr, Long_I Nc, Long_I lda);
    void set(const Doub *ptr, Long_I Nr, Long_I Nc, Long_I lda);

    // === Cmat member functions ===
    Doub& operator[](Long_I i);    // single indexing (inefficient)
    const Doub& operator[](Long_I i) const;
    Doub& operator()(Long_I i);    // same as operator[]
    const Doub& operator()(Long_I i) const;
    Doub& operator()(Long_I i, Long_I j);    // double indexing
    const Doub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Doub *ptr() const;
    Doub *ptr();
};

inline DcmatDoub::DcmatDoub() {}

inline DcmatDoub::DcmatDoub(const Doub *ptr, Long_I Nr, Long_I Nc, Long_I lda)
    : m_p((Doub *)ptr), m_Nr(Nr), m_Nc(Nc), m_N(Nr*Nc), m_lda(lda)
{}

inline void DcmatDoub::set(const Doub *ptr, Long_I Nr, Long_I Nc, Long_I lda)
{
    m_p = (Doub *)ptr; m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc; m_lda = lda;
}

inline Doub & DcmatDoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_Nc + m_lda * i/m_Nc];
}

inline const Doub & DcmatDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_Nc + m_lda * i / m_Nc];
}

inline Doub & DcmatDoub::operator()(Long_I i)
{
    return operator[](i);
}

inline const Doub & DcmatDoub::operator()(Long_I i) const
{
    return operator[](i);
}

inline Doub & DcmatDoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline const Doub & DcmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatDoub::n1() const
{
    return m_Nr;
}

inline Long DcmatDoub::n2() const
{
    return m_Nc;
}

inline Long DcmatDoub::lda() const
{
    return m_lda;
}

inline Long DcmatDoub::size() const
{
    return m_N;
}

inline const Doub * DcmatDoub::ptr() const
{
    return m_p;
}

inline Doub * DcmatDoub::ptr()
{
    return m_p;
}

class DcmatComp
{
private:
    Comp *m_p;
    Long m_N;
    Long m_Nr, m_Nc;
    Long m_lda; // leading dimension (here is m_Nr of host matrix)
public:
    typedef Comp value_type;
    DcmatComp();
    DcmatComp(const Comp *ptr, Long_I Nr, Long_I Nc, Long_I lda);
    void set(const Comp *ptr, Long_I Nr, Long_I Nc, Long_I lda);

    // === Cmat member functions ===
    Comp& operator[](Long_I i);    // single indexing (inefficient)
    const Comp& operator[](Long_I i) const;
    Comp& operator()(Long_I i);    // same as operator[]
    const Comp& operator()(Long_I i) const;
    Comp& operator()(Long_I i, Long_I j);    // double indexing
    const Comp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    Long lda() const;
    Long size() const;
    const Comp *ptr() const;
    Comp *ptr();
};

inline DcmatComp::DcmatComp() {}

inline DcmatComp::DcmatComp(const Comp *ptr, Long_I Nr, Long_I Nc, Long_I lda)
    : m_p((Comp *)ptr), m_Nr(Nr), m_Nc(Nc), m_N(Nr*Nc), m_lda(lda)
{}

inline void DcmatComp::set(const Comp *ptr, Long_I Nr, Long_I Nc, Long_I lda)
{
    m_p = (Comp *)ptr; m_Nr = Nr; m_Nc = Nc; m_N = Nr * Nc; m_lda = lda;
}

inline Comp & DcmatComp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_Nc + m_lda * i/m_Nc];
}

inline const Comp & DcmatComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i % m_Nc + m_lda * i / m_Nc];
}

inline Comp & DcmatComp::operator()(Long_I i)
{
    return operator[](i);
}

inline const Comp & DcmatComp::operator()(Long_I i) const
{
    return operator[](i);
}

inline Comp & DcmatComp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline const Comp & DcmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_lda * j];
}

inline Long DcmatComp::n1() const
{
    return m_Nr;
}

inline Long DcmatComp::n2() const
{
    return m_Nc;
}

inline Long DcmatComp::lda() const
{
    return m_lda;
}

inline Long DcmatComp::size() const
{
    return m_N;
}

inline const Comp * DcmatComp::ptr() const
{
    return m_p;
}

inline Comp * DcmatComp::ptr()
{
    return m_p;
}

