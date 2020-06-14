// Cmat container
#pragma once
#include "Vbase.h"

namespace slisc {
class Cmat4Int : public VbaseInt
{
protected:
    typedef VbaseInt Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1, m_N2, m_N3, m_N4;
public:
    typedef Int value_type;
    using Base::operator();
    using Base::ptr;
    Cmat4Int(): m_N1(0), m_N2(0), m_N3(0), m_N4(0) {};
    Cmat4Int(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Int(const Cmat4Int &rhs) = delete;   // Copy constructor
    void operator<<(Cmat4Int &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Int & operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Int & operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long n4() const;
};

inline Cmat4Int::Cmat4Int(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N1(N1), m_N2(N2), m_N3(N3), m_N4(N4) {}

inline void Cmat4Int::operator<<(Cmat4Int &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Int::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3 || N4 != m_N4) {
        Base::resize(N1*N2*N3*N4);
        m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N4 = N4;
    }
}

inline Int & Cmat4Int::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 ||
        k < 0 || k >= m_N3 || l < 0 || l >= m_N4)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N1 * m_N2;
    return m_p[i + m_N1*j + N1N2 *k + N1N2 *m_N3*l];
}

inline const Int & Cmat4Int::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 ||
        k < 0 || k >= m_N3 || l < 0 || l >= m_N4)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N1 * m_N2;
    return m_p[i + m_N1 * j + N1N2 * k + N1N2 * m_N3*l];
}

inline Long Cmat4Int::n1() const {
    return m_N1;
}

inline Long Cmat4Int::n2() const {
    return m_N2;
}

inline Long Cmat4Int::n3() const {
    return m_N3;
}

inline Long Cmat4Int::n4() const {
    return m_N4;
}

typedef const Cmat4Int & Cmat4Int_I;
typedef Cmat4Int & Cmat4Int_O, & Cmat4Int_IO;

class Cmat4Llong : public VbaseLlong
{
protected:
    typedef VbaseLlong Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1, m_N2, m_N3, m_N4;
public:
    typedef Llong value_type;
    using Base::operator();
    using Base::ptr;
    Cmat4Llong(): m_N1(0), m_N2(0), m_N3(0), m_N4(0) {};
    Cmat4Llong(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Llong(const Cmat4Llong &rhs) = delete;   // Copy constructor
    void operator<<(Cmat4Llong &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Llong & operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Llong & operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long n4() const;
};

inline Cmat4Llong::Cmat4Llong(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N1(N1), m_N2(N2), m_N3(N3), m_N4(N4) {}

inline void Cmat4Llong::operator<<(Cmat4Llong &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Llong::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3 || N4 != m_N4) {
        Base::resize(N1*N2*N3*N4);
        m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N4 = N4;
    }
}

inline Llong & Cmat4Llong::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 ||
        k < 0 || k >= m_N3 || l < 0 || l >= m_N4)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N1 * m_N2;
    return m_p[i + m_N1*j + N1N2 *k + N1N2 *m_N3*l];
}

inline const Llong & Cmat4Llong::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 ||
        k < 0 || k >= m_N3 || l < 0 || l >= m_N4)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N1 * m_N2;
    return m_p[i + m_N1 * j + N1N2 * k + N1N2 * m_N3*l];
}

inline Long Cmat4Llong::n1() const {
    return m_N1;
}

inline Long Cmat4Llong::n2() const {
    return m_N2;
}

inline Long Cmat4Llong::n3() const {
    return m_N3;
}

inline Long Cmat4Llong::n4() const {
    return m_N4;
}

typedef const Cmat4Llong & Cmat4Llong_I;
typedef Cmat4Llong & Cmat4Llong_O, & Cmat4Llong_IO;

class Cmat4Doub : public VbaseDoub
{
protected:
    typedef VbaseDoub Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1, m_N2, m_N3, m_N4;
public:
    typedef Doub value_type;
    using Base::operator();
    using Base::ptr;
    Cmat4Doub(): m_N1(0), m_N2(0), m_N3(0), m_N4(0) {};
    Cmat4Doub(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Doub(const Cmat4Doub &rhs) = delete;   // Copy constructor
    void operator<<(Cmat4Doub &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Doub & operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Doub & operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long n4() const;
};

inline Cmat4Doub::Cmat4Doub(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N1(N1), m_N2(N2), m_N3(N3), m_N4(N4) {}

inline void Cmat4Doub::operator<<(Cmat4Doub &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Doub::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3 || N4 != m_N4) {
        Base::resize(N1*N2*N3*N4);
        m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N4 = N4;
    }
}

inline Doub & Cmat4Doub::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 ||
        k < 0 || k >= m_N3 || l < 0 || l >= m_N4)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N1 * m_N2;
    return m_p[i + m_N1*j + N1N2 *k + N1N2 *m_N3*l];
}

inline const Doub & Cmat4Doub::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 ||
        k < 0 || k >= m_N3 || l < 0 || l >= m_N4)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N1 * m_N2;
    return m_p[i + m_N1 * j + N1N2 * k + N1N2 * m_N3*l];
}

inline Long Cmat4Doub::n1() const {
    return m_N1;
}

inline Long Cmat4Doub::n2() const {
    return m_N2;
}

inline Long Cmat4Doub::n3() const {
    return m_N3;
}

inline Long Cmat4Doub::n4() const {
    return m_N4;
}

typedef const Cmat4Doub & Cmat4Doub_I;
typedef Cmat4Doub & Cmat4Doub_O, & Cmat4Doub_IO;

class Cmat4Comp : public VbaseComp
{
protected:
    typedef VbaseComp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1, m_N2, m_N3, m_N4;
public:
    typedef Comp value_type;
    using Base::operator();
    using Base::ptr;
    Cmat4Comp(): m_N1(0), m_N2(0), m_N3(0), m_N4(0) {};
    Cmat4Comp(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Comp(const Cmat4Comp &rhs) = delete;   // Copy constructor
    void operator<<(Cmat4Comp &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Comp & operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Comp & operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
    Long n4() const;
};

inline Cmat4Comp::Cmat4Comp(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N1(N1), m_N2(N2), m_N3(N3), m_N4(N4) {}

inline void Cmat4Comp::operator<<(Cmat4Comp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Comp::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3 || N4 != m_N4) {
        Base::resize(N1*N2*N3*N4);
        m_N1 = N1; m_N2 = N2; m_N3 = N3; m_N4 = N4;
    }
}

inline Comp & Cmat4Comp::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 ||
        k < 0 || k >= m_N3 || l < 0 || l >= m_N4)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N1 * m_N2;
    return m_p[i + m_N1*j + N1N2 *k + N1N2 *m_N3*l];
}

inline const Comp & Cmat4Comp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 ||
        k < 0 || k >= m_N3 || l < 0 || l >= m_N4)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N1 * m_N2;
    return m_p[i + m_N1 * j + N1N2 * k + N1N2 * m_N3*l];
}

inline Long Cmat4Comp::n1() const {
    return m_N1;
}

inline Long Cmat4Comp::n2() const {
    return m_N2;
}

inline Long Cmat4Comp::n3() const {
    return m_N3;
}

inline Long Cmat4Comp::n4() const {
    return m_N4;
}

typedef const Cmat4Comp & Cmat4Comp_I;
typedef Cmat4Comp & Cmat4Comp_O, & Cmat4Comp_IO;

} // namespace slisc
