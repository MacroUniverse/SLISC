// Cmat container
#pragma once
#include "Vbase.h"

namespace slisc {
class CmatChar : public VbaseChar
{
protected:
    typedef VbaseChar Base;
    Long m_N0, m_N1;
public:
    CmatChar(): m_N0(0), m_N1(0) {};
    CmatChar(Long_I N0, Long_I N1);
    CmatChar(const CmatChar &rhs);        // Copy constructor
    CmatChar &operator=(const CmatChar &rhs) = delete;
    void operator<<(CmatChar &rhs); // move data and rhs.resize(0, 0)
    Char& operator()(Long_I i, Long_I j);    // double indexing
    const Char& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatChar::CmatChar(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatChar::CmatChar(const CmatChar &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatChar::operator<<(CmatChar &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Char &CmatChar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatChar index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Char &CmatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatChar index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatChar::n0() const
{ return m_N0; }

inline Long CmatChar::n1() const
{ return m_N1; }

inline void CmatChar::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatChar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatChar reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatChar &CmatChar_I;
typedef CmatChar &CmatChar_O, &CmatChar_IO;

class CmatUchar : public VbaseUchar
{
protected:
    typedef VbaseUchar Base;
    Long m_N0, m_N1;
public:
    CmatUchar(): m_N0(0), m_N1(0) {};
    CmatUchar(Long_I N0, Long_I N1);
    CmatUchar(const CmatUchar &rhs);        // Copy constructor
    CmatUchar &operator=(const CmatUchar &rhs) = delete;
    void operator<<(CmatUchar &rhs); // move data and rhs.resize(0, 0)
    Uchar& operator()(Long_I i, Long_I j);    // double indexing
    const Uchar& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatUchar::CmatUchar(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatUchar::CmatUchar(const CmatUchar &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatUchar::operator<<(CmatUchar &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Uchar &CmatUchar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatUchar index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Uchar &CmatUchar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatUchar index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatUchar::n0() const
{ return m_N0; }

inline Long CmatUchar::n1() const
{ return m_N1; }

inline void CmatUchar::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatUchar::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatUchar reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatUchar &CmatUchar_I;
typedef CmatUchar &CmatUchar_O, &CmatUchar_IO;

class CmatInt : public VbaseInt
{
protected:
    typedef VbaseInt Base;
    Long m_N0, m_N1;
public:
    CmatInt(): m_N0(0), m_N1(0) {};
    CmatInt(Long_I N0, Long_I N1);
    CmatInt(const CmatInt &rhs);        // Copy constructor
    CmatInt &operator=(const CmatInt &rhs) = delete;
    void operator<<(CmatInt &rhs); // move data and rhs.resize(0, 0)
    Int& operator()(Long_I i, Long_I j);    // double indexing
    const Int& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatInt::CmatInt(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatInt::CmatInt(const CmatInt &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatInt::operator<<(CmatInt &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Int &CmatInt::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatInt index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Int &CmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatInt index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatInt::n0() const
{ return m_N0; }

inline Long CmatInt::n1() const
{ return m_N1; }

inline void CmatInt::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatInt::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatInt reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatInt &CmatInt_I;
typedef CmatInt &CmatInt_O, &CmatInt_IO;

class CmatLlong : public VbaseLlong
{
protected:
    typedef VbaseLlong Base;
    Long m_N0, m_N1;
public:
    CmatLlong(): m_N0(0), m_N1(0) {};
    CmatLlong(Long_I N0, Long_I N1);
    CmatLlong(const CmatLlong &rhs);        // Copy constructor
    CmatLlong &operator=(const CmatLlong &rhs) = delete;
    void operator<<(CmatLlong &rhs); // move data and rhs.resize(0, 0)
    Llong& operator()(Long_I i, Long_I j);    // double indexing
    const Llong& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatLlong::CmatLlong(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatLlong::CmatLlong(const CmatLlong &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatLlong::operator<<(CmatLlong &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Llong &CmatLlong::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatLlong index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Llong &CmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatLlong index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatLlong::n0() const
{ return m_N0; }

inline Long CmatLlong::n1() const
{ return m_N1; }

inline void CmatLlong::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatLlong::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatLlong reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatLlong &CmatLlong_I;
typedef CmatLlong &CmatLlong_O, &CmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef CmatInt CmatLong;
#else
typedef CmatLlong CmatLong;
#endif

typedef const CmatLong &CmatLong_I;
typedef CmatLong &CmatLong_O, &CmatLong_IO;

class CmatFloat : public VbaseFloat
{
protected:
    typedef VbaseFloat Base;
    Long m_N0, m_N1;
public:
    CmatFloat(): m_N0(0), m_N1(0) {};
    CmatFloat(Long_I N0, Long_I N1);
    CmatFloat(const CmatFloat &rhs);        // Copy constructor
    CmatFloat &operator=(const CmatFloat &rhs) = delete;
    void operator<<(CmatFloat &rhs); // move data and rhs.resize(0, 0)
    Float& operator()(Long_I i, Long_I j);    // double indexing
    const Float& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatFloat::CmatFloat(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatFloat::CmatFloat(const CmatFloat &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatFloat::operator<<(CmatFloat &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Float &CmatFloat::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatFloat index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Float &CmatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatFloat index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatFloat::n0() const
{ return m_N0; }

inline Long CmatFloat::n1() const
{ return m_N1; }

inline void CmatFloat::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatFloat::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatFloat reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatFloat &CmatFloat_I;
typedef CmatFloat &CmatFloat_O, &CmatFloat_IO;

class CmatDoub : public VbaseDoub
{
protected:
    typedef VbaseDoub Base;
    Long m_N0, m_N1;
public:
    CmatDoub(): m_N0(0), m_N1(0) {};
    CmatDoub(Long_I N0, Long_I N1);
    CmatDoub(const CmatDoub &rhs);        // Copy constructor
    CmatDoub &operator=(const CmatDoub &rhs) = delete;
    void operator<<(CmatDoub &rhs); // move data and rhs.resize(0, 0)
    Doub& operator()(Long_I i, Long_I j);    // double indexing
    const Doub& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatDoub::CmatDoub(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatDoub::CmatDoub(const CmatDoub &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatDoub::operator<<(CmatDoub &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Doub &CmatDoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatDoub index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Doub &CmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatDoub index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatDoub::n0() const
{ return m_N0; }

inline Long CmatDoub::n1() const
{ return m_N1; }

inline void CmatDoub::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatDoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatDoub reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatDoub &CmatDoub_I;
typedef CmatDoub &CmatDoub_O, &CmatDoub_IO;

class CmatLdoub : public VbaseLdoub
{
protected:
    typedef VbaseLdoub Base;
    Long m_N0, m_N1;
public:
    CmatLdoub(): m_N0(0), m_N1(0) {};
    CmatLdoub(Long_I N0, Long_I N1);
    CmatLdoub(const CmatLdoub &rhs);        // Copy constructor
    CmatLdoub &operator=(const CmatLdoub &rhs) = delete;
    void operator<<(CmatLdoub &rhs); // move data and rhs.resize(0, 0)
    Ldoub& operator()(Long_I i, Long_I j);    // double indexing
    const Ldoub& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatLdoub::CmatLdoub(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatLdoub::CmatLdoub(const CmatLdoub &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatLdoub::operator<<(CmatLdoub &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Ldoub &CmatLdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatLdoub index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Ldoub &CmatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatLdoub index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatLdoub::n0() const
{ return m_N0; }

inline Long CmatLdoub::n1() const
{ return m_N1; }

inline void CmatLdoub::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatLdoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatLdoub reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatLdoub &CmatLdoub_I;
typedef CmatLdoub &CmatLdoub_O, &CmatLdoub_IO;

class CmatQdoub : public VbaseQdoub
{
protected:
    typedef VbaseQdoub Base;
    Long m_N0, m_N1;
public:
    CmatQdoub(): m_N0(0), m_N1(0) {};
    CmatQdoub(Long_I N0, Long_I N1);
    CmatQdoub(const CmatQdoub &rhs);        // Copy constructor
    CmatQdoub &operator=(const CmatQdoub &rhs) = delete;
    void operator<<(CmatQdoub &rhs); // move data and rhs.resize(0, 0)
    Qdoub& operator()(Long_I i, Long_I j);    // double indexing
    const Qdoub& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatQdoub::CmatQdoub(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatQdoub::CmatQdoub(const CmatQdoub &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatQdoub::operator<<(CmatQdoub &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Qdoub &CmatQdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatQdoub index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Qdoub &CmatQdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatQdoub index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatQdoub::n0() const
{ return m_N0; }

inline Long CmatQdoub::n1() const
{ return m_N1; }

inline void CmatQdoub::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatQdoub::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatQdoub reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatQdoub &CmatQdoub_I;
typedef CmatQdoub &CmatQdoub_O, &CmatQdoub_IO;

class CmatFcomp : public VbaseFcomp
{
protected:
    typedef VbaseFcomp Base;
    Long m_N0, m_N1;
public:
    CmatFcomp(): m_N0(0), m_N1(0) {};
    CmatFcomp(Long_I N0, Long_I N1);
    CmatFcomp(const CmatFcomp &rhs);        // Copy constructor
    CmatFcomp &operator=(const CmatFcomp &rhs) = delete;
    void operator<<(CmatFcomp &rhs); // move data and rhs.resize(0, 0)
    Fcomp& operator()(Long_I i, Long_I j);    // double indexing
    const Fcomp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatFcomp::CmatFcomp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatFcomp::CmatFcomp(const CmatFcomp &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatFcomp::operator<<(CmatFcomp &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Fcomp &CmatFcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatFcomp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Fcomp &CmatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatFcomp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatFcomp::n0() const
{ return m_N0; }

inline Long CmatFcomp::n1() const
{ return m_N1; }

inline void CmatFcomp::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatFcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatFcomp reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatFcomp &CmatFcomp_I;
typedef CmatFcomp &CmatFcomp_O, &CmatFcomp_IO;

class CmatComp : public VbaseComp
{
protected:
    typedef VbaseComp Base;
    Long m_N0, m_N1;
public:
    CmatComp(): m_N0(0), m_N1(0) {};
    CmatComp(Long_I N0, Long_I N1);
    CmatComp(const CmatComp &rhs);        // Copy constructor
    CmatComp &operator=(const CmatComp &rhs) = delete;
    void operator<<(CmatComp &rhs); // move data and rhs.resize(0, 0)
    Comp& operator()(Long_I i, Long_I j);    // double indexing
    const Comp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatComp::CmatComp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatComp::CmatComp(const CmatComp &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatComp::operator<<(CmatComp &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Comp &CmatComp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatComp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Comp &CmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatComp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatComp::n0() const
{ return m_N0; }

inline Long CmatComp::n1() const
{ return m_N1; }

inline void CmatComp::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatComp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatComp reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatComp &CmatComp_I;
typedef CmatComp &CmatComp_O, &CmatComp_IO;

class CmatLcomp : public VbaseLcomp
{
protected:
    typedef VbaseLcomp Base;
    Long m_N0, m_N1;
public:
    CmatLcomp(): m_N0(0), m_N1(0) {};
    CmatLcomp(Long_I N0, Long_I N1);
    CmatLcomp(const CmatLcomp &rhs);        // Copy constructor
    CmatLcomp &operator=(const CmatLcomp &rhs) = delete;
    void operator<<(CmatLcomp &rhs); // move data and rhs.resize(0, 0)
    Lcomp& operator()(Long_I i, Long_I j);    // double indexing
    const Lcomp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatLcomp::CmatLcomp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatLcomp::CmatLcomp(const CmatLcomp &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatLcomp::operator<<(CmatLcomp &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Lcomp &CmatLcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatLcomp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Lcomp &CmatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatLcomp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatLcomp::n0() const
{ return m_N0; }

inline Long CmatLcomp::n1() const
{ return m_N1; }

inline void CmatLcomp::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatLcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatLcomp reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatLcomp &CmatLcomp_I;
typedef CmatLcomp &CmatLcomp_O, &CmatLcomp_IO;

class CmatQcomp : public VbaseQcomp
{
protected:
    typedef VbaseQcomp Base;
    Long m_N0, m_N1;
public:
    CmatQcomp(): m_N0(0), m_N1(0) {};
    CmatQcomp(Long_I N0, Long_I N1);
    CmatQcomp(const CmatQcomp &rhs);        // Copy constructor
    CmatQcomp &operator=(const CmatQcomp &rhs) = delete;
    void operator<<(CmatQcomp &rhs); // move data and rhs.resize(0, 0)
    Qcomp& operator()(Long_I i, Long_I j);    // double indexing
    const Qcomp& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatQcomp::CmatQcomp(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatQcomp::CmatQcomp(const CmatQcomp &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatQcomp::operator<<(CmatQcomp &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Qcomp &CmatQcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatQcomp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Qcomp &CmatQcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatQcomp index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatQcomp::n0() const
{ return m_N0; }

inline Long CmatQcomp::n1() const
{ return m_N1; }

inline void CmatQcomp::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatQcomp::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatQcomp reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatQcomp &CmatQcomp_I;
typedef CmatQcomp &CmatQcomp_O, &CmatQcomp_IO;

class CmatFimag : public VbaseFimag
{
protected:
    typedef VbaseFimag Base;
    Long m_N0, m_N1;
public:
    CmatFimag(): m_N0(0), m_N1(0) {};
    CmatFimag(Long_I N0, Long_I N1);
    CmatFimag(const CmatFimag &rhs);        // Copy constructor
    CmatFimag &operator=(const CmatFimag &rhs) = delete;
    void operator<<(CmatFimag &rhs); // move data and rhs.resize(0, 0)
    Fimag& operator()(Long_I i, Long_I j);    // double indexing
    const Fimag& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatFimag::CmatFimag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatFimag::CmatFimag(const CmatFimag &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatFimag::operator<<(CmatFimag &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Fimag &CmatFimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatFimag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Fimag &CmatFimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatFimag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatFimag::n0() const
{ return m_N0; }

inline Long CmatFimag::n1() const
{ return m_N1; }

inline void CmatFimag::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatFimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatFimag reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatFimag &CmatFimag_I;
typedef CmatFimag &CmatFimag_O, &CmatFimag_IO;

class CmatImag : public VbaseImag
{
protected:
    typedef VbaseImag Base;
    Long m_N0, m_N1;
public:
    CmatImag(): m_N0(0), m_N1(0) {};
    CmatImag(Long_I N0, Long_I N1);
    CmatImag(const CmatImag &rhs);        // Copy constructor
    CmatImag &operator=(const CmatImag &rhs) = delete;
    void operator<<(CmatImag &rhs); // move data and rhs.resize(0, 0)
    Imag& operator()(Long_I i, Long_I j);    // double indexing
    const Imag& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatImag::CmatImag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatImag::CmatImag(const CmatImag &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatImag::operator<<(CmatImag &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Imag &CmatImag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatImag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Imag &CmatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatImag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatImag::n0() const
{ return m_N0; }

inline Long CmatImag::n1() const
{ return m_N1; }

inline void CmatImag::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatImag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatImag reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatImag &CmatImag_I;
typedef CmatImag &CmatImag_O, &CmatImag_IO;

class CmatLimag : public VbaseLimag
{
protected:
    typedef VbaseLimag Base;
    Long m_N0, m_N1;
public:
    CmatLimag(): m_N0(0), m_N1(0) {};
    CmatLimag(Long_I N0, Long_I N1);
    CmatLimag(const CmatLimag &rhs);        // Copy constructor
    CmatLimag &operator=(const CmatLimag &rhs) = delete;
    void operator<<(CmatLimag &rhs); // move data and rhs.resize(0, 0)
    Limag& operator()(Long_I i, Long_I j);    // double indexing
    const Limag& operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
    void reshape(Long_I N0, Long_I N1); // reshape (total elm # must be the same)
};

inline CmatLimag::CmatLimag(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatLimag::CmatLimag(const CmatLimag &rhs) : Base(rhs), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
    for (Long i = 0; i < m_N; ++i)
        m_p[i] = rhs.m_p[i];
}

inline void CmatLimag::operator<<(CmatLimag &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline Limag &CmatLimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatLimag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline const Limag &CmatLimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatLimag index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return m_p[i+m_N0*j];
}

inline Long CmatLimag::n0() const
{ return m_N0; }

inline Long CmatLimag::n1() const
{ return m_N1; }

inline void CmatLimag::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

inline void CmatLimag::reshape(Long_I N0, Long_I N1)
{
#ifdef SLS_CHECK_SHAPES
    if (N0 * N1 != m_N)
        SLS_ERR("CmatLimag reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)
            +") to ("+num2str(N0)+", "+num2str(N1)+"), element number not the same!");
#endif
    m_N0 = N0; m_N1 = N1;
}

typedef const CmatLimag &CmatLimag_I;
typedef CmatLimag &CmatLimag_O, &CmatLimag_IO;


class CmatBool : public VbaseBool
{
protected:
    typedef VbaseBool Base;
    Long m_N0, m_N1;
public:
    CmatBool(): m_N0(0), m_N1(0) {};
    CmatBool(Long_I N0, Long_I N1);
    CmatBool(const CmatBool &rhs);        // Copy constructor
    CmatBool &operator=(const CmatBool &rhs) = delete;
    void operator<<(CmatBool &rhs); // move data and rhs.resize(0, 0)
    CmatBool::ref operator()(Long_I i, Long_I j);    // double indexing
    Bool operator()(Long_I i, Long_I j) const;
    Long n0() const;
    Long n1() const;
    void resize(Long_I N0, Long_I N1); // resize (contents not preserved)
};

inline CmatBool::CmatBool(Long_I N0, Long_I N1) : Base(N0*N1), m_N0(N0), m_N1(N1) {}

inline CmatBool::CmatBool(const CmatBool &rhs) : Base(rhs.size()), m_N0(rhs.m_N0), m_N1(rhs.m_N1)
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
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1;
    rhs.m_N0 = rhs.m_N1 = 0;
    Base::operator<<(rhs);
}

inline CmatBool::ref CmatBool::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatBool index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return (*this)[i+m_N0*j];
}

inline Bool CmatBool::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
        SLS_ERR("CmatBool index ("+num2str(i)+", "+num2str(j)
            +") out of bounds: shape = ("+num2str(m_N0)+", "+num2str(m_N1)+")");
#endif
    return (*this)[i+m_N0*j];
}

inline Long CmatBool::n0() const
{ return m_N0; }

inline Long CmatBool::n1() const
{ return m_N1; }

inline void CmatBool::resize(Long_I N0, Long_I N1)
{
    if (N0 != m_N0 || N1 != m_N1) {
        Base::resize(N0*N1);
        m_N0 = N0; m_N1 = N1;
    }
}

typedef const CmatBool &CmatBool_I;
typedef CmatBool &CmatBool_O, &CmatBool_IO;

} // namespace slisc
