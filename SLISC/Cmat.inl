class CmatInt : public VbaseInt
{
protected:
    typedef VbaseInt Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatInt(Long_I Nr, Long_I Nc);
    CmatInt(const CmatInt &rhs);        // Copy constructor
	CmatInt & operator=(const CmatInt &rhs) = delete;
    void operator<<(CmatInt &rhs); // move data and rhs.resize(0, 0)
    Int& operator()(Long_I i, Long_I j);    // double indexing
    const Int& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline CmatInt::CmatInt(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline CmatInt::CmatInt(const CmatInt &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatInt::operator<<(CmatInt &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Int & CmatInt::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Int & CmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatInt::n1() const
{ return m_Nr; }

inline Long CmatInt::n2() const
{ return m_Nc; }

inline void CmatInt::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

typedef const CmatInt & CmatInt_I;
typedef CmatInt & CmatInt_O, & CmatInt_IO;

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
	CmatLlong & operator=(const CmatLlong &rhs) = delete;
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

typedef const CmatLlong & CmatLlong_I;
typedef CmatLlong & CmatLlong_O, & CmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef CmatInt CmatLong;
#else
typedef CmatLlong CmatLong;
#endif
typedef const CmatLong & CmatLong_I;
typedef CmatLong & CmatLong_O, & CmatLong_IO;

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
	CmatDoub & operator=(const CmatDoub &rhs) = delete;
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

typedef const CmatDoub & CmatDoub_I;
typedef CmatDoub & CmatDoub_O, & CmatDoub_IO;

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
	CmatComp & operator=(const CmatComp &rhs) = delete;
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

typedef const CmatComp & CmatComp_I;
typedef CmatComp & CmatComp_O, & CmatComp_IO;

