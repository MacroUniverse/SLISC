// row-major matrix container
#pragma once
#include "Vbase.h"

namespace slisc {
class MatChar : public VbaseChar
{
protected:
    typedef VbaseChar Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    using Base::operator();
    MatChar(): m_N1(0), m_N2(0) {};
    MatChar(Long_I N1, Long_I N2);
    MatChar(const MatChar &rhs);        // Copy constructor
    MatChar & operator=(const MatChar &rhs) = delete;
    void operator<<(MatChar &rhs); // move data and rhs.resize(0, 0)
    Char& operator()(Long_I i, Long_I j); // double indexing
    const Char& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline MatChar::MatChar(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatChar::MatChar(const MatChar &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatChar::operator<<(MatChar &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Char& MatChar::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatChar subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Char & MatChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatChar subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatChar::n1() const
{
    return m_N1;
}

inline Long MatChar::n2() const
{
    return m_N2;
}

inline void MatChar::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const MatChar & MatChar_I;
typedef MatChar & MatChar_O, & MatChar_IO;

class MatInt : public VbaseInt
{
protected:
    typedef VbaseInt Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    using Base::operator();
    MatInt(): m_N1(0), m_N2(0) {};
    MatInt(Long_I N1, Long_I N2);
    MatInt(const MatInt &rhs);        // Copy constructor
    MatInt & operator=(const MatInt &rhs) = delete;
    void operator<<(MatInt &rhs); // move data and rhs.resize(0, 0)
    Int& operator()(Long_I i, Long_I j); // double indexing
    const Int& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline MatInt::MatInt(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatInt::MatInt(const MatInt &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatInt::operator<<(MatInt &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Int& MatInt::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatInt subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Int & MatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatInt subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatInt::n1() const
{
    return m_N1;
}

inline Long MatInt::n2() const
{
    return m_N2;
}

inline void MatInt::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const MatInt & MatInt_I;
typedef MatInt & MatInt_O, & MatInt_IO;

class MatLlong : public VbaseLlong
{
protected:
    typedef VbaseLlong Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    using Base::operator();
    MatLlong(): m_N1(0), m_N2(0) {};
    MatLlong(Long_I N1, Long_I N2);
    MatLlong(const MatLlong &rhs);        // Copy constructor
    MatLlong & operator=(const MatLlong &rhs) = delete;
    void operator<<(MatLlong &rhs); // move data and rhs.resize(0, 0)
    Llong& operator()(Long_I i, Long_I j); // double indexing
    const Llong& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline MatLlong::MatLlong(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatLlong::MatLlong(const MatLlong &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatLlong::operator<<(MatLlong &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Llong& MatLlong::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatLlong subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Llong & MatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatLlong subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatLlong::n1() const
{
    return m_N1;
}

inline Long MatLlong::n2() const
{
    return m_N2;
}

inline void MatLlong::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
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

class MatFloat : public VbaseFloat
{
protected:
    typedef VbaseFloat Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    using Base::operator();
    MatFloat(): m_N1(0), m_N2(0) {};
    MatFloat(Long_I N1, Long_I N2);
    MatFloat(const MatFloat &rhs);        // Copy constructor
    MatFloat & operator=(const MatFloat &rhs) = delete;
    void operator<<(MatFloat &rhs); // move data and rhs.resize(0, 0)
    Float& operator()(Long_I i, Long_I j); // double indexing
    const Float& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline MatFloat::MatFloat(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatFloat::MatFloat(const MatFloat &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatFloat::operator<<(MatFloat &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Float& MatFloat::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatFloat subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Float & MatFloat::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatFloat subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatFloat::n1() const
{
    return m_N1;
}

inline Long MatFloat::n2() const
{
    return m_N2;
}

inline void MatFloat::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const MatFloat & MatFloat_I;
typedef MatFloat & MatFloat_O, & MatFloat_IO;

class MatDoub : public VbaseDoub
{
protected:
    typedef VbaseDoub Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    using Base::operator();
    MatDoub(): m_N1(0), m_N2(0) {};
    MatDoub(Long_I N1, Long_I N2);
    MatDoub(const MatDoub &rhs);        // Copy constructor
    MatDoub & operator=(const MatDoub &rhs) = delete;
    void operator<<(MatDoub &rhs); // move data and rhs.resize(0, 0)
    Doub& operator()(Long_I i, Long_I j); // double indexing
    const Doub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline MatDoub::MatDoub(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatDoub::MatDoub(const MatDoub &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatDoub::operator<<(MatDoub &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Doub& MatDoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatDoub subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Doub & MatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatDoub subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatDoub::n1() const
{
    return m_N1;
}

inline Long MatDoub::n2() const
{
    return m_N2;
}

inline void MatDoub::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const MatDoub & MatDoub_I;
typedef MatDoub & MatDoub_O, & MatDoub_IO;

class MatComp : public VbaseComp
{
protected:
    typedef VbaseComp Base;
    using Base::m_p;
    using Base::m_N;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    using Base::operator();
    MatComp(): m_N1(0), m_N2(0) {};
    MatComp(Long_I N1, Long_I N2);
    MatComp(const MatComp &rhs);        // Copy constructor
    MatComp & operator=(const MatComp &rhs) = delete;
    void operator<<(MatComp &rhs); // move data and rhs.resize(0, 0)
    Comp& operator()(Long_I i, Long_I j); // double indexing
    const Comp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
};

inline MatComp::MatComp(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatComp::MatComp(const MatComp &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatComp::operator<<(MatComp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Comp& MatComp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatComp subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Comp & MatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatComp subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatComp::n1() const
{
    return m_N1;
}

inline Long MatComp::n2() const
{
    return m_N2;
}

inline void MatComp::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

typedef const MatComp & MatComp_I;
typedef MatComp & MatComp_O, & MatComp_IO;

} // namespace slisc
