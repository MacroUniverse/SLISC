// row-major 3D container
#pragma once
#include "Vbase.h"

namespace slisc {
class Mat3Char : public VbaseChar
{
protected:
    typedef VbaseChar Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Char(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Char(Long_I N1, Long_I N2, Long_I N3);
    Mat3Char(const Mat3Char &rhs) = delete;   // Copy constructor
    Mat3Char & operator=(const Mat3Char &rhs) = delete;
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
protected:
    typedef VbaseInt Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Int(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Int(Long_I N1, Long_I N2, Long_I N3);
    Mat3Int(const Mat3Int &rhs) = delete;   // Copy constructor
    Mat3Int & operator=(const Mat3Int &rhs) = delete;
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
protected:
    typedef VbaseLlong Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Llong(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Llong(Long_I N1, Long_I N2, Long_I N3);
    Mat3Llong(const Mat3Llong &rhs) = delete;   // Copy constructor
    Mat3Llong & operator=(const Mat3Llong &rhs) = delete;
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

class Mat3Float : public VbaseFloat
{
protected:
    typedef VbaseFloat Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Float(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Float(Long_I N1, Long_I N2, Long_I N3);
    Mat3Float(const Mat3Float &rhs) = delete;   // Copy constructor
    Mat3Float & operator=(const Mat3Float &rhs) = delete;
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
protected:
    typedef VbaseDoub Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Doub(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Doub(Long_I N1, Long_I N2, Long_I N3);
    Mat3Doub(const Mat3Doub &rhs) = delete;   // Copy constructor
    Mat3Doub & operator=(const Mat3Doub &rhs) = delete;
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

class Mat3Ldoub : public VbaseLdoub
{
protected:
    typedef VbaseLdoub Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Ldoub(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Ldoub(Long_I N1, Long_I N2, Long_I N3);
    Mat3Ldoub(const Mat3Ldoub &rhs) = delete;   // Copy constructor
    Mat3Ldoub & operator=(const Mat3Ldoub &rhs) = delete;
    void operator<<(Mat3Ldoub &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Ldoub & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Ldoub & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Ldoub::Mat3Ldoub(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Ldoub::operator<<(Mat3Ldoub &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Ldoub::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Ldoub & Mat3Ldoub::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Ldoub & Mat3Ldoub::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Ldoub::n1() const
{
    return m_N1;
}

inline Long Mat3Ldoub::n2() const
{
    return m_N2;
}

inline Long Mat3Ldoub::n3() const
{
    return m_N3;
}

typedef const Mat3Ldoub & Mat3Ldoub_I;
typedef Mat3Ldoub & Mat3Ldoub_O, & Mat3Ldoub_IO;

class Mat3Fcomp : public VbaseFcomp
{
protected:
    typedef VbaseFcomp Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Fcomp(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Fcomp(Long_I N1, Long_I N2, Long_I N3);
    Mat3Fcomp(const Mat3Fcomp &rhs) = delete;   // Copy constructor
    Mat3Fcomp & operator=(const Mat3Fcomp &rhs) = delete;
    void operator<<(Mat3Fcomp &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Fcomp & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Fcomp & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Fcomp::Mat3Fcomp(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Fcomp::operator<<(Mat3Fcomp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Fcomp::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Fcomp & Mat3Fcomp::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Fcomp & Mat3Fcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Fcomp::n1() const
{
    return m_N1;
}

inline Long Mat3Fcomp::n2() const
{
    return m_N2;
}

inline Long Mat3Fcomp::n3() const
{
    return m_N3;
}

typedef const Mat3Fcomp & Mat3Fcomp_I;
typedef Mat3Fcomp & Mat3Fcomp_O, & Mat3Fcomp_IO;

class Mat3Comp : public VbaseComp
{
protected:
    typedef VbaseComp Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Comp(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Comp(Long_I N1, Long_I N2, Long_I N3);
    Mat3Comp(const Mat3Comp &rhs) = delete;   // Copy constructor
    Mat3Comp & operator=(const Mat3Comp &rhs) = delete;
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

class Mat3Lcomp : public VbaseLcomp
{
protected:
    typedef VbaseLcomp Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Lcomp(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Lcomp(Long_I N1, Long_I N2, Long_I N3);
    Mat3Lcomp(const Mat3Lcomp &rhs) = delete;   // Copy constructor
    Mat3Lcomp & operator=(const Mat3Lcomp &rhs) = delete;
    void operator<<(Mat3Lcomp &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Lcomp & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Lcomp & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Lcomp::Mat3Lcomp(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Lcomp::operator<<(Mat3Lcomp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Lcomp::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Lcomp & Mat3Lcomp::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Lcomp & Mat3Lcomp::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Lcomp::n1() const
{
    return m_N1;
}

inline Long Mat3Lcomp::n2() const
{
    return m_N2;
}

inline Long Mat3Lcomp::n3() const
{
    return m_N3;
}

typedef const Mat3Lcomp & Mat3Lcomp_I;
typedef Mat3Lcomp & Mat3Lcomp_O, & Mat3Lcomp_IO;

class Mat3Fimag : public VbaseFimag
{
protected:
    typedef VbaseFimag Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Fimag(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Fimag(Long_I N1, Long_I N2, Long_I N3);
    Mat3Fimag(const Mat3Fimag &rhs) = delete;   // Copy constructor
    Mat3Fimag & operator=(const Mat3Fimag &rhs) = delete;
    void operator<<(Mat3Fimag &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Fimag & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Fimag & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Fimag::Mat3Fimag(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Fimag::operator<<(Mat3Fimag &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Fimag::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Fimag & Mat3Fimag::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Fimag & Mat3Fimag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Fimag::n1() const
{
    return m_N1;
}

inline Long Mat3Fimag::n2() const
{
    return m_N2;
}

inline Long Mat3Fimag::n3() const
{
    return m_N3;
}

typedef const Mat3Fimag & Mat3Fimag_I;
typedef Mat3Fimag & Mat3Fimag_O, & Mat3Fimag_IO;

class Mat3Imag : public VbaseImag
{
protected:
    typedef VbaseImag Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Imag(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Imag(Long_I N1, Long_I N2, Long_I N3);
    Mat3Imag(const Mat3Imag &rhs) = delete;   // Copy constructor
    Mat3Imag & operator=(const Mat3Imag &rhs) = delete;
    void operator<<(Mat3Imag &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Imag & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Imag & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Imag::Mat3Imag(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Imag::operator<<(Mat3Imag &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Imag::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Imag & Mat3Imag::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Imag & Mat3Imag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Imag::n1() const
{
    return m_N1;
}

inline Long Mat3Imag::n2() const
{
    return m_N2;
}

inline Long Mat3Imag::n3() const
{
    return m_N3;
}

typedef const Mat3Imag & Mat3Imag_I;
typedef Mat3Imag & Mat3Imag_O, & Mat3Imag_IO;

class Mat3Limag : public VbaseLimag
{
protected:
    typedef VbaseLimag Base;
    Long m_N1, m_N2, m_N3;
public:
    Mat3Limag(): m_N1(0), m_N2(0), m_N3(0) {};
    Mat3Limag(Long_I N1, Long_I N2, Long_I N3);
    Mat3Limag(const Mat3Limag &rhs) = delete;   // Copy constructor
    Mat3Limag & operator=(const Mat3Limag &rhs) = delete;
    void operator<<(Mat3Limag &rhs); // move data and rhs.resize(0, 0, 0)
    void resize(Long_I N1, Long_I N2, Long_I N3);
    Limag & operator()(Long_I i, Long_I j, Long_I k);    //subscripting: pointer to row i
    const Limag & operator()(Long_I i, Long_I j, Long_I k) const;
    Long n1() const;
    Long n2() const;
    Long n3() const;
};

inline Mat3Limag::Mat3Limag(Long_I N1, Long_I N2, Long_I N3) :
    Base(N1*N2*N3), m_N1(N1), m_N2(N2), m_N3(N3) {}

inline void Mat3Limag::operator<<(Mat3Limag &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2; m_N3 = rhs.m_N3;
    rhs.m_N1 = rhs.m_N2 = rhs.m_N3 = 0;
    Base::operator<<(rhs);
}

inline void Mat3Limag::resize(Long_I N1, Long_I N2, Long_I N3)
{
    if (N1 != m_N1 || N2 != m_N2 || N3 != m_N3) {
        Base::resize(N1*N2*N3);
        m_N1 = N1; m_N2 = N2; m_N3 = N3;
    }
}

inline Limag & Mat3Limag::operator()(Long_I i, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline const Limag & Mat3Limag::operator()(Long_I i, Long_I j, Long_I k) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2 || k < 0 || k >= m_N3)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[m_N2*m_N3*i + m_N3*j + k];
}

inline Long Mat3Limag::n1() const
{
    return m_N1;
}

inline Long Mat3Limag::n2() const
{
    return m_N2;
}

inline Long Mat3Limag::n3() const
{
    return m_N3;
}

typedef const Mat3Limag & Mat3Limag_I;
typedef Mat3Limag & Mat3Limag_O, & Mat3Limag_IO;

} // namespace slisc
