class CmatBool : public VbaseBool
{
protected:
    typedef VbaseBool Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatBool(Long_I Nr, Long_I Nc);
    CmatBool(const CmatBool &rhs);        // Copy constructor
    void operator<<(CmatBool &rhs); // move data and rhs.resize(0, 0)
    Bool& operator()(Long_I i, Long_I j);    // double indexing
    const Bool& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

CmatBool::CmatBool(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

CmatBool::CmatBool(const CmatBool &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatBool::operator<<(CmatBool &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Bool & CmatBool::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Bool & CmatBool::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatBool::n1() const
{ return m_Nr; }

inline Long CmatBool::n2() const
{ return m_Nc; }

inline void CmatBool::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

class CmatChar : public VbaseChar
{
protected:
    typedef VbaseChar Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatChar(Long_I Nr, Long_I Nc);
    CmatChar(const CmatChar &rhs);        // Copy constructor
    void operator<<(CmatChar &rhs); // move data and rhs.resize(0, 0)
    Char& operator()(Long_I i, Long_I j);    // double indexing
    const Char& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

CmatChar::CmatChar(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

CmatChar::CmatChar(const CmatChar &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatChar::operator<<(CmatChar &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Char & CmatChar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Char & CmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatChar::n1() const
{ return m_Nr; }

inline Long CmatChar::n2() const
{ return m_Nc; }

inline void CmatChar::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

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
    void operator<<(CmatInt &rhs); // move data and rhs.resize(0, 0)
    Int& operator()(Long_I i, Long_I j);    // double indexing
    const Int& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

CmatInt::CmatInt(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

CmatInt::CmatInt(const CmatInt &rhs) : Base(0)
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

CmatLlong::CmatLlong(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

CmatLlong::CmatLlong(const CmatLlong &rhs) : Base(0)
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

class CmatFloat : public VbaseFloat
{
protected:
    typedef VbaseFloat Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatFloat(Long_I Nr, Long_I Nc);
    CmatFloat(const CmatFloat &rhs);        // Copy constructor
    void operator<<(CmatFloat &rhs); // move data and rhs.resize(0, 0)
    Float& operator()(Long_I i, Long_I j);    // double indexing
    const Float& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

CmatFloat::CmatFloat(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

CmatFloat::CmatFloat(const CmatFloat &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatFloat::operator<<(CmatFloat &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Float & CmatFloat::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Float & CmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatFloat::n1() const
{ return m_Nr; }

inline Long CmatFloat::n2() const
{ return m_Nc; }

inline void CmatFloat::resize(Long_I Nr, Long_I Nc)
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

CmatDoub::CmatDoub(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

CmatDoub::CmatDoub(const CmatDoub &rhs) : Base(0)
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

class CmatLdoub : public VbaseLdoub
{
protected:
    typedef VbaseLdoub Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatLdoub(Long_I Nr, Long_I Nc);
    CmatLdoub(const CmatLdoub &rhs);        // Copy constructor
    void operator<<(CmatLdoub &rhs); // move data and rhs.resize(0, 0)
    Ldoub& operator()(Long_I i, Long_I j);    // double indexing
    const Ldoub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

CmatLdoub::CmatLdoub(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

CmatLdoub::CmatLdoub(const CmatLdoub &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatLdoub::operator<<(CmatLdoub &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Ldoub & CmatLdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Ldoub & CmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatLdoub::n1() const
{ return m_Nr; }

inline Long CmatLdoub::n2() const
{ return m_Nc; }

inline void CmatLdoub::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

class CmatFcomp : public VbaseFcomp
{
protected:
    typedef VbaseFcomp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatFcomp(Long_I Nr, Long_I Nc);
    CmatFcomp(const CmatFcomp &rhs);        // Copy constructor
    void operator<<(CmatFcomp &rhs); // move data and rhs.resize(0, 0)
    Fcomp& operator()(Long_I i, Long_I j);    // double indexing
    const Fcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

CmatFcomp::CmatFcomp(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

CmatFcomp::CmatFcomp(const CmatFcomp &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatFcomp::operator<<(CmatFcomp &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Fcomp & CmatFcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Fcomp & CmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatFcomp::n1() const
{ return m_Nr; }

inline Long CmatFcomp::n2() const
{ return m_Nc; }

inline void CmatFcomp::resize(Long_I Nr, Long_I Nc)
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

CmatComp::CmatComp(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

CmatComp::CmatComp(const CmatComp &rhs) : Base(0)
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

class CmatLcomp : public VbaseLcomp
{
protected:
    typedef VbaseLcomp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatLcomp(Long_I Nr, Long_I Nc);
    CmatLcomp(const CmatLcomp &rhs);        // Copy constructor
    void operator<<(CmatLcomp &rhs); // move data and rhs.resize(0, 0)
    Lcomp& operator()(Long_I i, Long_I j);    // double indexing
    const Lcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

CmatLcomp::CmatLcomp(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

CmatLcomp::CmatLcomp(const CmatLcomp &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatLcomp::operator<<(CmatLcomp &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Lcomp & CmatLcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Lcomp & CmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatLcomp::n1() const
{ return m_Nr; }

inline Long CmatLcomp::n2() const
{ return m_Nc; }

inline void CmatLcomp::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

