// Cmat container
#pragma once
#include "Vbase.h"

namespace slisc {
class Cmat3Char : public VbaseChar
{
protected:
    typedef VbaseChar Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    typedef Char value_type;
    using Base::operator();
    using Base::ptr;
    Cmat3Char(): m_N1(0), m_N2(0), m_N3(0) {};
    Cmat3Char(Long_I N1, Long_I N2, Long_I N3);
    Cmat3Char(const Cmat3Char &rhs) = delete;
    Cmat3Char & operator=(const Cmat3Char &rhs) = delete;
    void operator<<(Cmat3Char &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Char & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Char & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat3Char::Cmat3Char(Long_I N1, Long_I N2, Long_I N3) : Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Cmat3Char::operator<<(Cmat3Char &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Cmat3Char::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Char & Cmat3Char::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline const Char & Cmat3Char::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Cmat3Char::n1() const {
    return m_N1;
}

inline Long Cmat3Char::n2() const {
    return m_N2;
}

inline Long Cmat3Char::n3() const {
    return m_N3;
}

typedef const Cmat3Char & Cmat3Char_I;
typedef Cmat3Char & Cmat3Char_O, & Cmat3Char_IO;

class Cmat3Int : public VbaseInt
{
protected:
    typedef VbaseInt Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    typedef Int value_type;
    using Base::operator();
    using Base::ptr;
    Cmat3Int(): m_N1(0), m_N2(0), m_N3(0) {};
    Cmat3Int(Long_I N1, Long_I N2, Long_I N3);
    Cmat3Int(const Cmat3Int &rhs) = delete;
    Cmat3Int & operator=(const Cmat3Int &rhs) = delete;
    void operator<<(Cmat3Int &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Int & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Int & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat3Int::Cmat3Int(Long_I N1, Long_I N2, Long_I N3) : Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Cmat3Int::operator<<(Cmat3Int &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Cmat3Int::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Int & Cmat3Int::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline const Int & Cmat3Int::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Cmat3Int::n1() const {
    return m_N1;
}

inline Long Cmat3Int::n2() const {
    return m_N2;
}

inline Long Cmat3Int::n3() const {
    return m_N3;
}

typedef const Cmat3Int & Cmat3Int_I;
typedef Cmat3Int & Cmat3Int_O, & Cmat3Int_IO;

class Cmat3Llong : public VbaseLlong
{
protected:
    typedef VbaseLlong Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    typedef Llong value_type;
    using Base::operator();
    using Base::ptr;
    Cmat3Llong(): m_N1(0), m_N2(0), m_N3(0) {};
    Cmat3Llong(Long_I N1, Long_I N2, Long_I N3);
    Cmat3Llong(const Cmat3Llong &rhs) = delete;
    Cmat3Llong & operator=(const Cmat3Llong &rhs) = delete;
    void operator<<(Cmat3Llong &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Llong & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Llong & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat3Llong::Cmat3Llong(Long_I N1, Long_I N2, Long_I N3) : Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Cmat3Llong::operator<<(Cmat3Llong &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Cmat3Llong::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Llong & Cmat3Llong::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline const Llong & Cmat3Llong::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Cmat3Llong::n1() const {
    return m_N1;
}

inline Long Cmat3Llong::n2() const {
    return m_N2;
}

inline Long Cmat3Llong::n3() const {
    return m_N3;
}

typedef const Cmat3Llong & Cmat3Llong_I;
typedef Cmat3Llong & Cmat3Llong_O, & Cmat3Llong_IO;

class Cmat3Doub : public VbaseDoub
{
protected:
    typedef VbaseDoub Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    typedef Doub value_type;
    using Base::operator();
    using Base::ptr;
    Cmat3Doub(): m_N1(0), m_N2(0), m_N3(0) {};
    Cmat3Doub(Long_I N1, Long_I N2, Long_I N3);
    Cmat3Doub(const Cmat3Doub &rhs) = delete;
    Cmat3Doub & operator=(const Cmat3Doub &rhs) = delete;
    void operator<<(Cmat3Doub &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Doub & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Doub & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat3Doub::Cmat3Doub(Long_I N1, Long_I N2, Long_I N3) : Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Cmat3Doub::operator<<(Cmat3Doub &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Cmat3Doub::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Doub & Cmat3Doub::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline const Doub & Cmat3Doub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Cmat3Doub::n1() const {
    return m_N1;
}

inline Long Cmat3Doub::n2() const {
    return m_N2;
}

inline Long Cmat3Doub::n3() const {
    return m_N3;
}

typedef const Cmat3Doub & Cmat3Doub_I;
typedef Cmat3Doub & Cmat3Doub_O, & Cmat3Doub_IO;

class Cmat3Comp : public VbaseComp
{
protected:
    typedef VbaseComp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    typedef Comp value_type;
    using Base::operator();
    using Base::ptr;
    Cmat3Comp(): m_N1(0), m_N2(0), m_N3(0) {};
    Cmat3Comp(Long_I N1, Long_I N2, Long_I N3);
    Cmat3Comp(const Cmat3Comp &rhs) = delete;
    Cmat3Comp & operator=(const Cmat3Comp &rhs) = delete;
    void operator<<(Cmat3Comp &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Comp & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Comp & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat3Comp::Cmat3Comp(Long_I N1, Long_I N2, Long_I N3) : Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Cmat3Comp::operator<<(Cmat3Comp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Cmat3Comp::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Comp & Cmat3Comp::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline const Comp & Cmat3Comp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1*j + m_N1*m_N2*k];
}

inline Long Cmat3Comp::n1() const {
    return m_N1;
}

inline Long Cmat3Comp::n2() const {
    return m_N2;
}

inline Long Cmat3Comp::n3() const {
    return m_N3;
}

typedef const Cmat3Comp & Cmat3Comp_I;
typedef Cmat3Comp & Cmat3Comp_O, & Cmat3Comp_IO;

} // namespace slisc
