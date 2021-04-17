// Cmat container
#pragma once
#include "Vbase.h"

namespace slisc {
class Cmat4Char : public VbaseChar
{
protected:
    typedef VbaseChar Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Char value_type;
    Cmat4Char(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Char(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Char(const Cmat4Char &rhs);   // Copy constructor
    void operator<<(Cmat4Char &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Char &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Char &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Char::Cmat4Char(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Char::Cmat4Char(const Cmat4Char &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Char::operator<<(Cmat4Char &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Char::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Char::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Char reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Char &Cmat4Char::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Char &Cmat4Char::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Char::n0() const {
    return m_N0;
}

inline Long Cmat4Char::n1() const {
    return m_N1;
}

inline Long Cmat4Char::n2() const {
    return m_N2;
}

inline Long Cmat4Char::n3() const {
    return m_N3;
}

typedef const Cmat4Char &Cmat4Char_I;
typedef Cmat4Char &Cmat4Char_O, &Cmat4Char_IO;

class Cmat4Int : public VbaseInt
{
protected:
    typedef VbaseInt Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Int value_type;
    Cmat4Int(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Int(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Int(const Cmat4Int &rhs);   // Copy constructor
    void operator<<(Cmat4Int &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Int &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Int &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Int::Cmat4Int(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Int::Cmat4Int(const Cmat4Int &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Int::operator<<(Cmat4Int &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Int::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Int::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Int reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Int &Cmat4Int::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Int &Cmat4Int::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Int::n0() const {
    return m_N0;
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

typedef const Cmat4Int &Cmat4Int_I;
typedef Cmat4Int &Cmat4Int_O, &Cmat4Int_IO;

class Cmat4Llong : public VbaseLlong
{
protected:
    typedef VbaseLlong Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Llong value_type;
    Cmat4Llong(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Llong(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Llong(const Cmat4Llong &rhs);   // Copy constructor
    void operator<<(Cmat4Llong &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Llong &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Llong &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Llong::Cmat4Llong(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Llong::Cmat4Llong(const Cmat4Llong &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Llong::operator<<(Cmat4Llong &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Llong::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Llong::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Llong reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Llong &Cmat4Llong::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Llong &Cmat4Llong::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Llong::n0() const {
    return m_N0;
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

typedef const Cmat4Llong &Cmat4Llong_I;
typedef Cmat4Llong &Cmat4Llong_O, &Cmat4Llong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef Cmat4Int Cmat4Long;
#else
typedef Cmat4Llong Cmat4Long;
#endif

typedef const Cmat4Long &Cmat4Long_I;
typedef Cmat4Long &Cmat4Long_O, &Cmat4Long_IO;

class Cmat4Float : public VbaseFloat
{
protected:
    typedef VbaseFloat Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Float value_type;
    Cmat4Float(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Float(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Float(const Cmat4Float &rhs);   // Copy constructor
    void operator<<(Cmat4Float &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Float &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Float &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Float::Cmat4Float(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Float::Cmat4Float(const Cmat4Float &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Float::operator<<(Cmat4Float &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Float::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Float::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Float reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Float &Cmat4Float::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Float &Cmat4Float::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Float::n0() const {
    return m_N0;
}

inline Long Cmat4Float::n1() const {
    return m_N1;
}

inline Long Cmat4Float::n2() const {
    return m_N2;
}

inline Long Cmat4Float::n3() const {
    return m_N3;
}

typedef const Cmat4Float &Cmat4Float_I;
typedef Cmat4Float &Cmat4Float_O, &Cmat4Float_IO;

class Cmat4Doub : public VbaseDoub
{
protected:
    typedef VbaseDoub Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Doub value_type;
    Cmat4Doub(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Doub(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Doub(const Cmat4Doub &rhs);   // Copy constructor
    void operator<<(Cmat4Doub &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Doub &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Doub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Doub::Cmat4Doub(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Doub::Cmat4Doub(const Cmat4Doub &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Doub::operator<<(Cmat4Doub &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Doub::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Doub::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Doub reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Doub &Cmat4Doub::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Doub &Cmat4Doub::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Doub::n0() const {
    return m_N0;
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

typedef const Cmat4Doub &Cmat4Doub_I;
typedef Cmat4Doub &Cmat4Doub_O, &Cmat4Doub_IO;

class Cmat4Ldoub : public VbaseLdoub
{
protected:
    typedef VbaseLdoub Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Ldoub value_type;
    Cmat4Ldoub(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Ldoub(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Ldoub(const Cmat4Ldoub &rhs);   // Copy constructor
    void operator<<(Cmat4Ldoub &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Ldoub &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Ldoub &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Ldoub::Cmat4Ldoub(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Ldoub::Cmat4Ldoub(const Cmat4Ldoub &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Ldoub::operator<<(Cmat4Ldoub &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Ldoub::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Ldoub::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Ldoub reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Ldoub &Cmat4Ldoub::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Ldoub &Cmat4Ldoub::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Ldoub::n0() const {
    return m_N0;
}

inline Long Cmat4Ldoub::n1() const {
    return m_N1;
}

inline Long Cmat4Ldoub::n2() const {
    return m_N2;
}

inline Long Cmat4Ldoub::n3() const {
    return m_N3;
}

typedef const Cmat4Ldoub &Cmat4Ldoub_I;
typedef Cmat4Ldoub &Cmat4Ldoub_O, &Cmat4Ldoub_IO;

class Cmat4Fcomp : public VbaseFcomp
{
protected:
    typedef VbaseFcomp Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Fcomp value_type;
    Cmat4Fcomp(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Fcomp(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Fcomp(const Cmat4Fcomp &rhs);   // Copy constructor
    void operator<<(Cmat4Fcomp &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Fcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Fcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Fcomp::Cmat4Fcomp(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Fcomp::Cmat4Fcomp(const Cmat4Fcomp &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Fcomp::operator<<(Cmat4Fcomp &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Fcomp::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Fcomp::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Fcomp reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Fcomp &Cmat4Fcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Fcomp &Cmat4Fcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Fcomp::n0() const {
    return m_N0;
}

inline Long Cmat4Fcomp::n1() const {
    return m_N1;
}

inline Long Cmat4Fcomp::n2() const {
    return m_N2;
}

inline Long Cmat4Fcomp::n3() const {
    return m_N3;
}

typedef const Cmat4Fcomp &Cmat4Fcomp_I;
typedef Cmat4Fcomp &Cmat4Fcomp_O, &Cmat4Fcomp_IO;

class Cmat4Comp : public VbaseComp
{
protected:
    typedef VbaseComp Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Comp value_type;
    Cmat4Comp(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Comp(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Comp(const Cmat4Comp &rhs);   // Copy constructor
    void operator<<(Cmat4Comp &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Comp &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Comp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Comp::Cmat4Comp(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Comp::Cmat4Comp(const Cmat4Comp &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Comp::operator<<(Cmat4Comp &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Comp::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Comp::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Comp reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Comp &Cmat4Comp::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Comp &Cmat4Comp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Comp::n0() const {
    return m_N0;
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

typedef const Cmat4Comp &Cmat4Comp_I;
typedef Cmat4Comp &Cmat4Comp_O, &Cmat4Comp_IO;

class Cmat4Lcomp : public VbaseLcomp
{
protected:
    typedef VbaseLcomp Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Lcomp value_type;
    Cmat4Lcomp(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Lcomp(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Lcomp(const Cmat4Lcomp &rhs);   // Copy constructor
    void operator<<(Cmat4Lcomp &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Lcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Lcomp &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Lcomp::Cmat4Lcomp(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Lcomp::Cmat4Lcomp(const Cmat4Lcomp &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Lcomp::operator<<(Cmat4Lcomp &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Lcomp::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Lcomp::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Lcomp reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Lcomp &Cmat4Lcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Lcomp &Cmat4Lcomp::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Lcomp::n0() const {
    return m_N0;
}

inline Long Cmat4Lcomp::n1() const {
    return m_N1;
}

inline Long Cmat4Lcomp::n2() const {
    return m_N2;
}

inline Long Cmat4Lcomp::n3() const {
    return m_N3;
}

typedef const Cmat4Lcomp &Cmat4Lcomp_I;
typedef Cmat4Lcomp &Cmat4Lcomp_O, &Cmat4Lcomp_IO;

class Cmat4Fimag : public VbaseFimag
{
protected:
    typedef VbaseFimag Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Fimag value_type;
    Cmat4Fimag(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Fimag(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Fimag(const Cmat4Fimag &rhs);   // Copy constructor
    void operator<<(Cmat4Fimag &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Fimag &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Fimag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Fimag::Cmat4Fimag(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Fimag::Cmat4Fimag(const Cmat4Fimag &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Fimag::operator<<(Cmat4Fimag &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Fimag::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Fimag::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Fimag reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Fimag &Cmat4Fimag::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Fimag &Cmat4Fimag::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Fimag::n0() const {
    return m_N0;
}

inline Long Cmat4Fimag::n1() const {
    return m_N1;
}

inline Long Cmat4Fimag::n2() const {
    return m_N2;
}

inline Long Cmat4Fimag::n3() const {
    return m_N3;
}

typedef const Cmat4Fimag &Cmat4Fimag_I;
typedef Cmat4Fimag &Cmat4Fimag_O, &Cmat4Fimag_IO;

class Cmat4Imag : public VbaseImag
{
protected:
    typedef VbaseImag Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Imag value_type;
    Cmat4Imag(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Imag(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Imag(const Cmat4Imag &rhs);   // Copy constructor
    void operator<<(Cmat4Imag &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Imag &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Imag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Imag::Cmat4Imag(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Imag::Cmat4Imag(const Cmat4Imag &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Imag::operator<<(Cmat4Imag &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Imag::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Imag::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Imag reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Imag &Cmat4Imag::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Imag &Cmat4Imag::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Imag::n0() const {
    return m_N0;
}

inline Long Cmat4Imag::n1() const {
    return m_N1;
}

inline Long Cmat4Imag::n2() const {
    return m_N2;
}

inline Long Cmat4Imag::n3() const {
    return m_N3;
}

typedef const Cmat4Imag &Cmat4Imag_I;
typedef Cmat4Imag &Cmat4Imag_O, &Cmat4Imag_IO;

class Cmat4Limag : public VbaseLimag
{
protected:
    typedef VbaseLimag Base;
    Long m_N0, m_N1, m_N2, m_N3;
public:
    typedef Limag value_type;
    Cmat4Limag(): m_N0(0), m_N1(0), m_N2(0), m_N3(0) {};
    Cmat4Limag(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Cmat4Limag(const Cmat4Limag &rhs);   // Copy constructor
    void operator<<(Cmat4Limag &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    void reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4);
    Limag &operator()(Long_I i, Long_I j, Long_I k, Long_I l);
    const Limag &operator()(Long_I i, Long_I j, Long_I k, Long_I l) const;
    Long n0() const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Cmat4Limag::Cmat4Limag(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
    : Base(N1*N2*N3*N4), m_N0(N1), m_N1(N2), m_N2(N3), m_N3(N4) {}

// Copy constructor
inline Cmat4Limag::Cmat4Limag(const Cmat4Limag &rhs): Base(rhs),
    m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_N2(rhs.m_N2), m_N3(rhs.m_N3)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline void Cmat4Limag::operator<<(Cmat4Limag &rhs)
{
    m_N0 = rhs.m_N0; m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N0 = rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline void Cmat4Limag::resize(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
    if (N1 != m_N0 || N2 != m_N1 || N3 != m_N2 || N4 != m_N3) {
        Base::resize(N1*N2*N3*N4);
        m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
    }
}

inline void Cmat4Limag::reshape(Long_I N1, Long_I N2, Long_I N3, Long_I N4)
{
#ifdef SLS_CHECK_SHAPES
    if (N1 * N2 * N3 != m_N)
        SLS_ERR("Cmat4Limag reshaping from ("+num2str(m_N0)+", "+num2str(m_N1)+", "+num2str(m_N2)+", "+num2str(m_N3)
            +") to ("+num2str(N1)+", "+num2str(N2)+", "+num2str(N3)+", "+num2str(N4)+"), element number not the same!");
#endif
    m_N0 = N1; m_N1 = N2; m_N2 = N3; m_N3 = N4;
}

inline Limag &Cmat4Limag::operator()(Long_I i, Long_I j, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0*j + N1N2 *k + N1N2 *m_N2*l];
}

inline const Limag &Cmat4Limag::operator()(Long_I i, Long_I j, Long_I k, Long_I l) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1 ||
        k < 0 || k >= m_N2 || l < 0 || l >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    Long N1N2 = m_N0 * m_N1;
    return m_p[i + m_N0 * j + N1N2 * k + N1N2 * m_N2*l];
}

inline Long Cmat4Limag::n0() const {
    return m_N0;
}

inline Long Cmat4Limag::n1() const {
    return m_N1;
}

inline Long Cmat4Limag::n2() const {
    return m_N2;
}

inline Long Cmat4Limag::n3() const {
    return m_N3;
}

typedef const Cmat4Limag &Cmat4Limag_I;
typedef Cmat4Limag &Cmat4Limag_O, &Cmat4Limag_IO;

} // namespace slisc
