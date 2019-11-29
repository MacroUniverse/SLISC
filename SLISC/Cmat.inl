class CmatLlong : public VbaseLlong
{
protected:
    typedef VbaseLlong Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatLlong(Long_I Nr, Long_I Nc);
    CmatLlong(const CmatLlong &rhs);        // Copy constructor
    void operator<<(CmatLlong &rhs); // move data and rhs.resize(0, 0)
    Llong& operator()(Long_I i, Long_I j);    // double indexing
    const Llong& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline CmatLlong::CmatLlong(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline CmatLlong::CmatLlong(const CmatLlong &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatLlong::operator<<(CmatLlong &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Llong & CmatLlong::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Llong & CmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatLlong::n1() const
{ return m_Nr; }

inline Long CmatLlong::n2() const
{ return m_Nc; }

inline void CmatLlong::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

class CmatDoub : public VbaseDoub
{
protected:
    typedef VbaseDoub Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatDoub(Long_I Nr, Long_I Nc);
    CmatDoub(const CmatDoub &rhs);        // Copy constructor
    void operator<<(CmatDoub &rhs); // move data and rhs.resize(0, 0)
    Doub& operator()(Long_I i, Long_I j);    // double indexing
    const Doub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline CmatDoub::CmatDoub(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline CmatDoub::CmatDoub(const CmatDoub &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatDoub::operator<<(CmatDoub &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Doub & CmatDoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Doub & CmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatDoub::n1() const
{ return m_Nr; }

inline Long CmatDoub::n2() const
{ return m_Nc; }

inline void CmatDoub::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

class CmatComp : public VbaseComp
{
protected:
    typedef VbaseComp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatComp(Long_I Nr, Long_I Nc);
    CmatComp(const CmatComp &rhs);        // Copy constructor
    void operator<<(CmatComp &rhs); // move data and rhs.resize(0, 0)
    Comp& operator()(Long_I i, Long_I j);    // double indexing
    const Comp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline CmatComp::CmatComp(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline CmatComp::CmatComp(const CmatComp &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatComp::operator<<(CmatComp &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Comp & CmatComp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Comp & CmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatComp::n1() const
{ return m_Nr; }

inline Long CmatComp::n2() const
{ return m_Nc; }

inline void CmatComp::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

