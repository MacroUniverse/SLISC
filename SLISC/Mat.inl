class MatInt : public VbaseInt
{
private:
    typedef VbaseInt Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatInt(Long_I Nr, Long_I Nc);
    MatInt(const MatInt &rhs);        // Copy constructor
    void operator<<(MatInt &rhs); // move data and rhs.resize(0, 0)
    Int& operator()(Long_I i, Long_I j); // double indexing
    const Int& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline MatInt::MatInt(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline MatInt::MatInt(const MatInt &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatInt::operator<<(MatInt &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Int& MatInt::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatInt subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Int & MatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatInt subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatInt::n1() const
{
    return m_Nr;
}

inline Long MatInt::n2() const
{
    return m_Nc;
}

inline void MatInt::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

typedef const MatInt & MatInt_I;
typedef MatInt & MatInt_O, & MatInt_IO;

class MatLlong : public VbaseLlong
{
private:
    typedef VbaseLlong Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatLlong(Long_I Nr, Long_I Nc);
    MatLlong(const MatLlong &rhs);        // Copy constructor
    void operator<<(MatLlong &rhs); // move data and rhs.resize(0, 0)
    Llong& operator()(Long_I i, Long_I j); // double indexing
    const Llong& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline MatLlong::MatLlong(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline MatLlong::MatLlong(const MatLlong &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatLlong::operator<<(MatLlong &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Llong& MatLlong::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatLlong subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Llong & MatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatLlong subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatLlong::n1() const
{
    return m_Nr;
}

inline Long MatLlong::n2() const
{
    return m_Nc;
}

inline void MatLlong::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

typedef const MatLlong & MatLlong_I;
typedef MatLlong & MatLlong_O, & MatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef MatInt MatLong;
#else
typedef MatLlong MatLong;
#endif
typedef const MatLong & MatLong_I;
typedef MatLong & MatLong_O, & MatLong_IO;

class MatDoub : public VbaseDoub
{
private:
    typedef VbaseDoub Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatDoub(Long_I Nr, Long_I Nc);
    MatDoub(const MatDoub &rhs);        // Copy constructor
    void operator<<(MatDoub &rhs); // move data and rhs.resize(0, 0)
    Doub& operator()(Long_I i, Long_I j); // double indexing
    const Doub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline MatDoub::MatDoub(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline MatDoub::MatDoub(const MatDoub &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatDoub::operator<<(MatDoub &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Doub& MatDoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatDoub subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Doub & MatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatDoub subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatDoub::n1() const
{
    return m_Nr;
}

inline Long MatDoub::n2() const
{
    return m_Nc;
}

inline void MatDoub::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

typedef const MatDoub & MatDoub_I;
typedef MatDoub & MatDoub_O, & MatDoub_IO;

class MatComp : public VbaseComp
{
private:
    typedef VbaseComp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatComp(Long_I Nr, Long_I Nc);
    MatComp(const MatComp &rhs);        // Copy constructor
    void operator<<(MatComp &rhs); // move data and rhs.resize(0, 0)
    Comp& operator()(Long_I i, Long_I j); // double indexing
    const Comp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline MatComp::MatComp(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline MatComp::MatComp(const MatComp &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatComp::operator<<(MatComp &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Comp& MatComp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatComp subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Comp & MatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatComp subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatComp::n1() const
{
    return m_Nr;
}

inline Long MatComp::n2() const
{
    return m_Nc;
}

inline void MatComp::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

typedef const MatComp & MatComp_I;
typedef MatComp & MatComp_O, & MatComp_IO;

