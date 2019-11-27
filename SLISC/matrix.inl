class MatBool : public VbaseBool
{
private:
    typedef VbaseBool Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatBool(Long_I Nr, Long_I Nc);
    MatBool(const MatBool &rhs);        // Copy constructor
    void operator<<(MatBool &rhs); // move data and rhs.resize(0, 0)
    Bool& operator()(Long_I i, Long_I j); // double indexing
    const Bool& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

MatBool::MatBool() {}

MatBool::MatBool(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatBool::MatBool(const MatBool &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
}

inline void MatBool::operator<<(MatBool &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Bool& MatBool::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatBool subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Bool & MatBool::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatBool subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatBool::n1() const
{ return m_Nr; }

inline Long MatBool::n2() const
{ return m_Nc; }

inline void MatBool::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


class MatChar : public VbaseChar
{
private:
    typedef VbaseChar Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatChar(Long_I Nr, Long_I Nc);
    MatChar(const MatChar &rhs);        // Copy constructor
    void operator<<(MatChar &rhs); // move data and rhs.resize(0, 0)
    Char& operator()(Long_I i, Long_I j); // double indexing
    const Char& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

MatChar::MatChar() {}

MatChar::MatChar(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatChar::MatChar(const MatChar &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
}

inline void MatChar::operator<<(MatChar &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Char& MatChar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatChar subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Char & MatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatChar subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatChar::n1() const
{ return m_Nr; }

inline Long MatChar::n2() const
{ return m_Nc; }

inline void MatChar::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


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

MatInt::MatInt() {}

MatInt::MatInt(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatInt::MatInt(const MatInt &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
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
{ return m_Nr; }

inline Long MatInt::n2() const
{ return m_Nc; }

inline void MatInt::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


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

MatLlong::MatLlong() {}

MatLlong::MatLlong(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatLlong::MatLlong(const MatLlong &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
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
{ return m_Nr; }

inline Long MatLlong::n2() const
{ return m_Nc; }

inline void MatLlong::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


class MatFloat : public VbaseFloat
{
private:
    typedef VbaseFloat Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatFloat(Long_I Nr, Long_I Nc);
    MatFloat(const MatFloat &rhs);        // Copy constructor
    void operator<<(MatFloat &rhs); // move data and rhs.resize(0, 0)
    Float& operator()(Long_I i, Long_I j); // double indexing
    const Float& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

MatFloat::MatFloat() {}

MatFloat::MatFloat(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatFloat::MatFloat(const MatFloat &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
}

inline void MatFloat::operator<<(MatFloat &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Float& MatFloat::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatFloat subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Float & MatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatFloat subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatFloat::n1() const
{ return m_Nr; }

inline Long MatFloat::n2() const
{ return m_Nc; }

inline void MatFloat::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


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

MatDoub::MatDoub() {}

MatDoub::MatDoub(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatDoub::MatDoub(const MatDoub &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
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
{ return m_Nr; }

inline Long MatDoub::n2() const
{ return m_Nc; }

inline void MatDoub::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


class MatLdoub : public VbaseLdoub
{
private:
    typedef VbaseLdoub Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatLdoub(Long_I Nr, Long_I Nc);
    MatLdoub(const MatLdoub &rhs);        // Copy constructor
    void operator<<(MatLdoub &rhs); // move data and rhs.resize(0, 0)
    Ldoub& operator()(Long_I i, Long_I j); // double indexing
    const Ldoub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

MatLdoub::MatLdoub() {}

MatLdoub::MatLdoub(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatLdoub::MatLdoub(const MatLdoub &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
}

inline void MatLdoub::operator<<(MatLdoub &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Ldoub& MatLdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatLdoub subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Ldoub & MatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatLdoub subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatLdoub::n1() const
{ return m_Nr; }

inline Long MatLdoub::n2() const
{ return m_Nc; }

inline void MatLdoub::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


class MatFcomp : public VbaseFcomp
{
private:
    typedef VbaseFcomp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatFcomp(Long_I Nr, Long_I Nc);
    MatFcomp(const MatFcomp &rhs);        // Copy constructor
    void operator<<(MatFcomp &rhs); // move data and rhs.resize(0, 0)
    Fcomp& operator()(Long_I i, Long_I j); // double indexing
    const Fcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

MatFcomp::MatFcomp() {}

MatFcomp::MatFcomp(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatFcomp::MatFcomp(const MatFcomp &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
}

inline void MatFcomp::operator<<(MatFcomp &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Fcomp& MatFcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatFcomp subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Fcomp & MatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatFcomp subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatFcomp::n1() const
{ return m_Nr; }

inline Long MatFcomp::n2() const
{ return m_Nc; }

inline void MatFcomp::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


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

MatComp::MatComp() {}

MatComp::MatComp(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatComp::MatComp(const MatComp &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
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
{ return m_Nr; }

inline Long MatComp::n2() const
{ return m_Nc; }

inline void MatComp::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


class MatLcomp : public VbaseLcomp
{
private:
    typedef VbaseLcomp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatLcomp(Long_I Nr, Long_I Nc);
    MatLcomp(const MatLcomp &rhs);        // Copy constructor
    void operator<<(MatLcomp &rhs); // move data and rhs.resize(0, 0)
    Lcomp& operator()(Long_I i, Long_I j); // double indexing
    const Lcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

MatLcomp::MatLcomp() {}

MatLcomp::MatLcomp(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatLcomp::MatLcomp(const MatLcomp &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
}

inline void MatLcomp::operator<<(MatLcomp &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Lcomp& MatLcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatLcomp subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Lcomp & MatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatLcomp subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatLcomp::n1() const
{ return m_Nr; }

inline Long MatLcomp::n2() const
{ return m_Nc; }

inline void MatLcomp::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


class MatImag : public VbaseImag
{
private:
    typedef VbaseImag Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    MatImag(Long_I Nr, Long_I Nc);
    MatImag(const MatImag &rhs);        // Copy constructor
    void operator<<(MatImag &rhs); // move data and rhs.resize(0, 0)
    Imag& operator()(Long_I i, Long_I j); // double indexing
    const Imag& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

MatImag::MatImag() {}

MatImag::MatImag(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

MatImag::MatImag(const MatImag &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use "=" to copy!");
}

inline void MatImag::operator<<(MatImag &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Imag& MatImag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatImag subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline const Imag & MatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatImag subscript out of bounds");
#endif
    return m_p[m_Nc*i+j];
}

inline Long MatImag::n1() const
{ return m_Nr; }

inline Long MatImag::n2() const
{ return m_Nc; }

inline void MatImag::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}


