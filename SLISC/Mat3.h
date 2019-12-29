// row-major 3D container
#pragma once
#include "Vbase.h"

namespace slisc {
class Mat3Char : public VbaseChar
{
private:
    typedef VbaseChar Base;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    Mat3Char(Long_I N1, Long_I N2, Long_I N3);
    Mat3Char(const Mat3Char &rhs) = delete;   // Copy constructor
    void operator<<(Mat3Char &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Char & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Char & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Char::Mat3Char(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Char::operator<<(Mat3Char &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Char::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Char & Mat3Char::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Char & Mat3Char::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Char::n1() const
{
    return m_N1;
}

inline Long Mat3Char::n2() const
{
    return m_N2;
}

inline Long Mat3Char::n3() const
{
    return m_N3;
}

typedef const Mat3Char & Mat3Char_I;
typedef Mat3Char & Mat3Char_O, & Mat3Char_IO;

class Mat3Int : public VbaseInt
{
private:
    typedef VbaseInt Base;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    Mat3Int(Long_I N1, Long_I N2, Long_I N3);
    Mat3Int(const Mat3Int &rhs) = delete;   // Copy constructor
    void operator<<(Mat3Int &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Int & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Int & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Int::Mat3Int(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Int::operator<<(Mat3Int &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Int::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Int & Mat3Int::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Int & Mat3Int::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Int::n1() const
{
    return m_N1;
}

inline Long Mat3Int::n2() const
{
    return m_N2;
}

inline Long Mat3Int::n3() const
{
    return m_N3;
}

typedef const Mat3Int & Mat3Int_I;
typedef Mat3Int & Mat3Int_O, & Mat3Int_IO;

class Mat3Llong : public VbaseLlong
{
private:
    typedef VbaseLlong Base;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    Mat3Llong(Long_I N1, Long_I N2, Long_I N3);
    Mat3Llong(const Mat3Llong &rhs) = delete;   // Copy constructor
    void operator<<(Mat3Llong &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Llong & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Llong & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Llong::Mat3Llong(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Llong::operator<<(Mat3Llong &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Llong::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Llong & Mat3Llong::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Llong & Mat3Llong::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Llong::n1() const
{
    return m_N1;
}

inline Long Mat3Llong::n2() const
{
    return m_N2;
}

inline Long Mat3Llong::n3() const
{
    return m_N3;
}

typedef const Mat3Llong & Mat3Llong_I;
typedef Mat3Llong & Mat3Llong_O, & Mat3Llong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef Mat3Int Mat3Long;
#else
typedef Mat3Llong Mat3Long;
#endif

typedef const Mat3Long & Mat3Long_I;
typedef Mat3Long & Mat3Long_O, & Mat3Long_IO;

class Mat3Float : public VbaseFloat
{
private:
    typedef VbaseFloat Base;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    Mat3Float(Long_I N1, Long_I N2, Long_I N3);
    Mat3Float(const Mat3Float &rhs) = delete;   // Copy constructor
    void operator<<(Mat3Float &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Float & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Float & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Float::Mat3Float(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Float::operator<<(Mat3Float &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Float::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Float & Mat3Float::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Float & Mat3Float::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Float::n1() const
{
    return m_N1;
}

inline Long Mat3Float::n2() const
{
    return m_N2;
}

inline Long Mat3Float::n3() const
{
    return m_N3;
}

typedef const Mat3Float & Mat3Float_I;
typedef Mat3Float & Mat3Float_O, & Mat3Float_IO;

class Mat3Doub : public VbaseDoub
{
private:
    typedef VbaseDoub Base;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    Mat3Doub(Long_I N1, Long_I N2, Long_I N3);
    Mat3Doub(const Mat3Doub &rhs) = delete;   // Copy constructor
    void operator<<(Mat3Doub &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Doub & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Doub & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Doub::Mat3Doub(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Doub::operator<<(Mat3Doub &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Doub::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Doub & Mat3Doub::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Doub & Mat3Doub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Doub::n1() const
{
    return m_N1;
}

inline Long Mat3Doub::n2() const
{
    return m_N2;
}

inline Long Mat3Doub::n3() const
{
    return m_N3;
}

typedef const Mat3Doub & Mat3Doub_I;
typedef Mat3Doub & Mat3Doub_O, & Mat3Doub_IO;

class Mat3Comp : public VbaseComp
{
private:
    typedef VbaseComp Base;
    Long m_N1;
    Long m_N2;
    Long m_N3;
public:
    Mat3Comp(Long_I N1, Long_I N2, Long_I N3);
    Mat3Comp(const Mat3Comp &rhs) = delete;   // Copy constructor
    void operator<<(Mat3Comp &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Comp & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Comp & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Comp::Mat3Comp(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Comp::operator<<(Mat3Comp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Comp::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Comp & Mat3Comp::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Comp & Mat3Comp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Comp::n1() const
{
    return m_N1;
}

inline Long Mat3Comp::n2() const
{
    return m_N2;
}

inline Long Mat3Comp::n3() const
{
    return m_N3;
}

typedef const Mat3Comp & Mat3Comp_I;
typedef Mat3Comp & Mat3Comp_O, & Mat3Comp_IO;

} // namespace slisc
