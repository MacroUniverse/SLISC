// Cmat container
#pragma once
#include "Vbase.h"

namespace slisc {
class CmatChar : public VbaseChar
{
protected:
    typedef VbaseChar Base;
    Long m_N1, m_N2;
public:
    CmatChar(): m_N1(0), m_N2(0) {};
    CmatChar(Long_I N1, Long_I N2);
    CmatChar(const CmatChar &rhs);        // Copy constructor
    CmatChar & operator=(const CmatChar &rhs) = delete;
    void operator<<(CmatChar &rhs); // move data and rhs.resize(0, 0)
    Char& operator()(Long_I i, Long_I j);    // double indexing
    const Char& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatChar::CmatChar(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatChar::CmatChar(const CmatChar &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatChar::operator<<(CmatChar &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Char & CmatChar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatChar index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Char & CmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatChar index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatChar::n1() const
{ return m_N1; }

inline Long CmatChar::n2() const
{ return m_N2; }

inline void CmatChar::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatChar & CmatChar_I;
typedef CmatChar & CmatChar_O, & CmatChar_IO;

class CmatInt : public VbaseInt
{
protected:
    typedef VbaseInt Base;
    Long m_N1, m_N2;
public:
    CmatInt(): m_N1(0), m_N2(0) {};
    CmatInt(Long_I N1, Long_I N2);
    CmatInt(const CmatInt &rhs);        // Copy constructor
    CmatInt & operator=(const CmatInt &rhs) = delete;
    void operator<<(CmatInt &rhs); // move data and rhs.resize(0, 0)
    Int& operator()(Long_I i, Long_I j);    // double indexing
    const Int& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatInt::CmatInt(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatInt::CmatInt(const CmatInt &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatInt::operator<<(CmatInt &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Int & CmatInt::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatInt index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Int & CmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatInt index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatInt::n1() const
{ return m_N1; }

inline Long CmatInt::n2() const
{ return m_N2; }

inline void CmatInt::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatInt & CmatInt_I;
typedef CmatInt & CmatInt_O, & CmatInt_IO;

class CmatLlong : public VbaseLlong
{
protected:
    typedef VbaseLlong Base;
    Long m_N1, m_N2;
public:
    CmatLlong(): m_N1(0), m_N2(0) {};
    CmatLlong(Long_I N1, Long_I N2);
    CmatLlong(const CmatLlong &rhs);        // Copy constructor
    CmatLlong & operator=(const CmatLlong &rhs) = delete;
    void operator<<(CmatLlong &rhs); // move data and rhs.resize(0, 0)
    Llong& operator()(Long_I i, Long_I j);    // double indexing
    const Llong& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatLlong::CmatLlong(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatLlong::CmatLlong(const CmatLlong &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatLlong::operator<<(CmatLlong &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Llong & CmatLlong::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatLlong index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Llong & CmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatLlong index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatLlong::n1() const
{ return m_N1; }

inline Long CmatLlong::n2() const
{ return m_N2; }

inline void CmatLlong::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
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
    Long m_N1, m_N2;
public:
    CmatFloat(): m_N1(0), m_N2(0) {};
    CmatFloat(Long_I N1, Long_I N2);
    CmatFloat(const CmatFloat &rhs);        // Copy constructor
    CmatFloat & operator=(const CmatFloat &rhs) = delete;
    void operator<<(CmatFloat &rhs); // move data and rhs.resize(0, 0)
    Float& operator()(Long_I i, Long_I j);    // double indexing
    const Float& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatFloat::CmatFloat(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatFloat::CmatFloat(const CmatFloat &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatFloat::operator<<(CmatFloat &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Float & CmatFloat::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatFloat index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Float & CmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatFloat index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatFloat::n1() const
{ return m_N1; }

inline Long CmatFloat::n2() const
{ return m_N2; }

inline void CmatFloat::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatFloat & CmatFloat_I;
typedef CmatFloat & CmatFloat_O, & CmatFloat_IO;

class CmatDoub : public VbaseDoub
{
protected:
    typedef VbaseDoub Base;
    Long m_N1, m_N2;
public:
    CmatDoub(): m_N1(0), m_N2(0) {};
    CmatDoub(Long_I N1, Long_I N2);
    CmatDoub(const CmatDoub &rhs);        // Copy constructor
    CmatDoub & operator=(const CmatDoub &rhs) = delete;
    void operator<<(CmatDoub &rhs); // move data and rhs.resize(0, 0)
    Doub& operator()(Long_I i, Long_I j);    // double indexing
    const Doub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatDoub::CmatDoub(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatDoub::CmatDoub(const CmatDoub &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatDoub::operator<<(CmatDoub &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Doub & CmatDoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatDoub index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Doub & CmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatDoub index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatDoub::n1() const
{ return m_N1; }

inline Long CmatDoub::n2() const
{ return m_N2; }

inline void CmatDoub::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatDoub & CmatDoub_I;
typedef CmatDoub & CmatDoub_O, & CmatDoub_IO;

class CmatLdoub : public VbaseLdoub
{
protected:
    typedef VbaseLdoub Base;
    Long m_N1, m_N2;
public:
    CmatLdoub(): m_N1(0), m_N2(0) {};
    CmatLdoub(Long_I N1, Long_I N2);
    CmatLdoub(const CmatLdoub &rhs);        // Copy constructor
    CmatLdoub & operator=(const CmatLdoub &rhs) = delete;
    void operator<<(CmatLdoub &rhs); // move data and rhs.resize(0, 0)
    Ldoub& operator()(Long_I i, Long_I j);    // double indexing
    const Ldoub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatLdoub::CmatLdoub(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatLdoub::CmatLdoub(const CmatLdoub &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatLdoub::operator<<(CmatLdoub &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Ldoub & CmatLdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatLdoub index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Ldoub & CmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatLdoub index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatLdoub::n1() const
{ return m_N1; }

inline Long CmatLdoub::n2() const
{ return m_N2; }

inline void CmatLdoub::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatLdoub & CmatLdoub_I;
typedef CmatLdoub & CmatLdoub_O, & CmatLdoub_IO;

class CmatFcomp : public VbaseFcomp
{
protected:
    typedef VbaseFcomp Base;
    Long m_N1, m_N2;
public:
    CmatFcomp(): m_N1(0), m_N2(0) {};
    CmatFcomp(Long_I N1, Long_I N2);
    CmatFcomp(const CmatFcomp &rhs);        // Copy constructor
    CmatFcomp & operator=(const CmatFcomp &rhs) = delete;
    void operator<<(CmatFcomp &rhs); // move data and rhs.resize(0, 0)
    Fcomp& operator()(Long_I i, Long_I j);    // double indexing
    const Fcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatFcomp::CmatFcomp(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatFcomp::CmatFcomp(const CmatFcomp &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatFcomp::operator<<(CmatFcomp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Fcomp & CmatFcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatFcomp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Fcomp & CmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatFcomp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatFcomp::n1() const
{ return m_N1; }

inline Long CmatFcomp::n2() const
{ return m_N2; }

inline void CmatFcomp::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatFcomp & CmatFcomp_I;
typedef CmatFcomp & CmatFcomp_O, & CmatFcomp_IO;

class CmatComp : public VbaseComp
{
protected:
    typedef VbaseComp Base;
    Long m_N1, m_N2;
public:
    CmatComp(): m_N1(0), m_N2(0) {};
    CmatComp(Long_I N1, Long_I N2);
    CmatComp(const CmatComp &rhs);        // Copy constructor
    CmatComp & operator=(const CmatComp &rhs) = delete;
    void operator<<(CmatComp &rhs); // move data and rhs.resize(0, 0)
    Comp& operator()(Long_I i, Long_I j);    // double indexing
    const Comp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatComp::CmatComp(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatComp::CmatComp(const CmatComp &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatComp::operator<<(CmatComp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Comp & CmatComp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatComp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Comp & CmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatComp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatComp::n1() const
{ return m_N1; }

inline Long CmatComp::n2() const
{ return m_N2; }

inline void CmatComp::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatComp & CmatComp_I;
typedef CmatComp & CmatComp_O, & CmatComp_IO;

class CmatLcomp : public VbaseLcomp
{
protected:
    typedef VbaseLcomp Base;
    Long m_N1, m_N2;
public:
    CmatLcomp(): m_N1(0), m_N2(0) {};
    CmatLcomp(Long_I N1, Long_I N2);
    CmatLcomp(const CmatLcomp &rhs);        // Copy constructor
    CmatLcomp & operator=(const CmatLcomp &rhs) = delete;
    void operator<<(CmatLcomp &rhs); // move data and rhs.resize(0, 0)
    Lcomp& operator()(Long_I i, Long_I j);    // double indexing
    const Lcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatLcomp::CmatLcomp(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatLcomp::CmatLcomp(const CmatLcomp &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatLcomp::operator<<(CmatLcomp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Lcomp & CmatLcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatLcomp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Lcomp & CmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatLcomp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatLcomp::n1() const
{ return m_N1; }

inline Long CmatLcomp::n2() const
{ return m_N2; }

inline void CmatLcomp::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatLcomp & CmatLcomp_I;
typedef CmatLcomp & CmatLcomp_O, & CmatLcomp_IO;

class CmatFimag : public VbaseFimag
{
protected:
    typedef VbaseFimag Base;
    Long m_N1, m_N2;
public:
    CmatFimag(): m_N1(0), m_N2(0) {};
    CmatFimag(Long_I N1, Long_I N2);
    CmatFimag(const CmatFimag &rhs);        // Copy constructor
    CmatFimag & operator=(const CmatFimag &rhs) = delete;
    void operator<<(CmatFimag &rhs); // move data and rhs.resize(0, 0)
    Fimag& operator()(Long_I i, Long_I j);    // double indexing
    const Fimag& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatFimag::CmatFimag(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatFimag::CmatFimag(const CmatFimag &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatFimag::operator<<(CmatFimag &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Fimag & CmatFimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatFimag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Fimag & CmatFimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatFimag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatFimag::n1() const
{ return m_N1; }

inline Long CmatFimag::n2() const
{ return m_N2; }

inline void CmatFimag::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatFimag & CmatFimag_I;
typedef CmatFimag & CmatFimag_O, & CmatFimag_IO;

class CmatImag : public VbaseImag
{
protected:
    typedef VbaseImag Base;
    Long m_N1, m_N2;
public:
    CmatImag(): m_N1(0), m_N2(0) {};
    CmatImag(Long_I N1, Long_I N2);
    CmatImag(const CmatImag &rhs);        // Copy constructor
    CmatImag & operator=(const CmatImag &rhs) = delete;
    void operator<<(CmatImag &rhs); // move data and rhs.resize(0, 0)
    Imag& operator()(Long_I i, Long_I j);    // double indexing
    const Imag& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatImag::CmatImag(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatImag::CmatImag(const CmatImag &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatImag::operator<<(CmatImag &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Imag & CmatImag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatImag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Imag & CmatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatImag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatImag::n1() const
{ return m_N1; }

inline Long CmatImag::n2() const
{ return m_N2; }

inline void CmatImag::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatImag & CmatImag_I;
typedef CmatImag & CmatImag_O, & CmatImag_IO;

class CmatLimag : public VbaseLimag
{
protected:
    typedef VbaseLimag Base;
    Long m_N1, m_N2;
public:
    CmatLimag(): m_N1(0), m_N2(0) {};
    CmatLimag(Long_I N1, Long_I N2);
    CmatLimag(const CmatLimag &rhs);        // Copy constructor
    CmatLimag & operator=(const CmatLimag &rhs) = delete;
    void operator<<(CmatLimag &rhs); // move data and rhs.resize(0, 0)
    Limag& operator()(Long_I i, Long_I j);    // double indexing
    const Limag& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatLimag::CmatLimag(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatLimag::CmatLimag(const CmatLimag &rhs) : Base(rhs), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatLimag::operator<<(CmatLimag &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Limag & CmatLimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatLimag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline const Limag & CmatLimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatLimag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return m_p[i+m_N1*j];
}

inline Long CmatLimag::n1() const
{ return m_N1; }

inline Long CmatLimag::n2() const
{ return m_N2; }

inline void CmatLimag::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatLimag & CmatLimag_I;
typedef CmatLimag & CmatLimag_O, & CmatLimag_IO;


class CmatBool : public VbaseBool
{
protected:
    typedef VbaseBool Base;
    Long m_N1, m_N2;
public:
    CmatBool(): m_N1(0), m_N2(0) {};
    CmatBool(Long_I N1, Long_I N2);
    CmatBool(const CmatBool &rhs);        // Copy constructor
    CmatBool & operator=(const CmatBool &rhs) = delete;
    void operator<<(CmatBool &rhs); // move data and rhs.resize(0, 0)
    CmatBool::ref operator()(Long_I i, Long_I j);    // double indexing
    Bool operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline CmatBool::CmatBool(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline CmatBool::CmatBool(const CmatBool &rhs) : Base(rhs.size()), m_N1(rhs.m_N1), m_N2(rhs.m_N2)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    Long N = size();
    for (Long i = 0; i < N; ++i)
        (*this)[i] = rhs[i];
}

inline void CmatBool::operator<<(CmatBool &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline CmatBool::ref CmatBool::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatBool index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return (*this)[i+m_N1*j];
}

inline Bool CmatBool::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("CmatBool index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N1)+", "+num2str(m_N2)+")");
#endif
    return (*this)[i+m_N1*j];
}

inline Long CmatBool::n1() const
{ return m_N1; }

inline Long CmatBool::n2() const
{ return m_N2; }

inline void CmatBool::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const CmatBool & CmatBool_I;
typedef CmatBool & CmatBool_O, & CmatBool_IO;

} // namespace slisc
