// Cmat container
#pragma once
#include "Vbase.h"

namespace slisc {
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
    CmatChar & operator=(const CmatChar &rhs) = delete;
    void operator<<(CmatChar &rhs); // move data and rhs.resize(0, 0)
    Char& operator()(Long_I i, Long_I j);    // double indexing
    const Char& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline CmatChar::CmatChar(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline CmatChar::CmatChar(const CmatChar &rhs) : Base(0)
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

typedef const CmatChar & CmatChar_I;
typedef CmatChar & CmatChar_O, & CmatChar_IO;

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
    CmatFloat & operator=(const CmatFloat &rhs) = delete;
    void operator<<(CmatFloat &rhs); // move data and rhs.resize(0, 0)
    Float& operator()(Long_I i, Long_I j);    // double indexing
    const Float& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline CmatFloat::CmatFloat(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline CmatFloat::CmatFloat(const CmatFloat &rhs) : Base(0)
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

typedef const CmatFloat & CmatFloat_I;
typedef CmatFloat & CmatFloat_O, & CmatFloat_IO;

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

class CmatImag : public VbaseImag
{
protected:
    typedef VbaseImag Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc;
public:
    using Base::ptr;
    using Base::operator();
    CmatImag(Long_I Nr, Long_I Nc);
    CmatImag(const CmatImag &rhs);        // Copy constructor
    CmatImag & operator=(const CmatImag &rhs) = delete;
    void operator<<(CmatImag &rhs); // move data and rhs.resize(0, 0)
    Imag& operator()(Long_I i, Long_I j);    // double indexing
    const Imag& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I Nr, Long_I Nc); // resize (contents not preserved)
};

inline CmatImag::CmatImag(Long_I Nr, Long_I Nc) : Base(Nr*Nc), m_Nr(Nr), m_Nc(Nc) {}

inline CmatImag::CmatImag(const CmatImag &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, "
        "use reference argument for function input or output, and use \"=\" to copy!");
}

inline void CmatImag::operator<<(CmatImag &rhs)
{
    m_Nr = rhs.m_Nr; m_Nc = rhs.m_Nc;
    rhs.m_Nr = rhs.m_Nc = 0;
    Base::operator<<(rhs);
}

inline Imag & CmatImag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline const Imag & CmatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i+m_Nr*j];
}

inline Long CmatImag::n1() const
{ return m_Nr; }

inline Long CmatImag::n2() const
{ return m_Nc; }

inline void CmatImag::resize(Long_I Nr, Long_I Nc)
{
    if (Nr != m_Nr || Nc != m_Nc) {
        Base::resize(Nr*Nc);
        m_Nr = Nr; m_Nc = Nc;
    }
}

typedef const CmatImag & CmatImag_I;
typedef CmatImag & CmatImag_O, & CmatImag_IO;

} // namespace slisc
