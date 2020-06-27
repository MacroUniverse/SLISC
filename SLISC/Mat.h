// row-major matrix container
#pragma once
#include "Vbase.h"

namespace slisc {
class MatChar : public VbaseChar
{
protected:
    typedef VbaseChar Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
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
    void reshape(Long_I N1, Long_I N2);
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

inline void MatChar::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatChar reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatChar & MatChar_I;
typedef MatChar & MatChar_O, & MatChar_IO;

class MatInt : public VbaseInt
{
protected:
    typedef VbaseInt Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
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
    void reshape(Long_I N1, Long_I N2);
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

inline void MatInt::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatInt reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatInt & MatInt_I;
typedef MatInt & MatInt_O, & MatInt_IO;

class MatLlong : public VbaseLlong
{
protected:
    typedef VbaseLlong Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
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
    void reshape(Long_I N1, Long_I N2);
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

inline void MatLlong::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatLlong reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatLlong & MatLlong_I;
typedef MatLlong & MatLlong_O, & MatLlong_IO;

class MatFloat : public VbaseFloat
{
protected:
    typedef VbaseFloat Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
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
    void reshape(Long_I N1, Long_I N2);
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

inline void MatFloat::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatFloat reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatFloat & MatFloat_I;
typedef MatFloat & MatFloat_O, & MatFloat_IO;

class MatDoub : public VbaseDoub
{
protected:
    typedef VbaseDoub Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
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
    void reshape(Long_I N1, Long_I N2);
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

inline void MatDoub::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatDoub reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatDoub & MatDoub_I;
typedef MatDoub & MatDoub_O, & MatDoub_IO;

class MatLdoub : public VbaseLdoub
{
protected:
    typedef VbaseLdoub Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    MatLdoub(): m_N1(0), m_N2(0) {};
    MatLdoub(Long_I N1, Long_I N2);
    MatLdoub(const MatLdoub &rhs);        // Copy constructor
    MatLdoub & operator=(const MatLdoub &rhs) = delete;
    void operator<<(MatLdoub &rhs); // move data and rhs.resize(0, 0)
    Ldoub& operator()(Long_I i, Long_I j); // double indexing
    const Ldoub& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
    void reshape(Long_I N1, Long_I N2);
};

inline MatLdoub::MatLdoub(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatLdoub::MatLdoub(const MatLdoub &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatLdoub::operator<<(MatLdoub &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Ldoub& MatLdoub::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatLdoub subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Ldoub & MatLdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatLdoub subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatLdoub::n1() const
{
    return m_N1;
}

inline Long MatLdoub::n2() const
{
    return m_N2;
}

inline void MatLdoub::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

inline void MatLdoub::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatLdoub reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatLdoub & MatLdoub_I;
typedef MatLdoub & MatLdoub_O, & MatLdoub_IO;

class MatFcomp : public VbaseFcomp
{
protected:
    typedef VbaseFcomp Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    MatFcomp(): m_N1(0), m_N2(0) {};
    MatFcomp(Long_I N1, Long_I N2);
    MatFcomp(const MatFcomp &rhs);        // Copy constructor
    MatFcomp & operator=(const MatFcomp &rhs) = delete;
    void operator<<(MatFcomp &rhs); // move data and rhs.resize(0, 0)
    Fcomp& operator()(Long_I i, Long_I j); // double indexing
    const Fcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
    void reshape(Long_I N1, Long_I N2);
};

inline MatFcomp::MatFcomp(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatFcomp::MatFcomp(const MatFcomp &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatFcomp::operator<<(MatFcomp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Fcomp& MatFcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatFcomp subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Fcomp & MatFcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatFcomp subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatFcomp::n1() const
{
    return m_N1;
}

inline Long MatFcomp::n2() const
{
    return m_N2;
}

inline void MatFcomp::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

inline void MatFcomp::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatFcomp reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatFcomp & MatFcomp_I;
typedef MatFcomp & MatFcomp_O, & MatFcomp_IO;

class MatComp : public VbaseComp
{
protected:
    typedef VbaseComp Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
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
    void reshape(Long_I N1, Long_I N2);
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

inline void MatComp::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatComp reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatComp & MatComp_I;
typedef MatComp & MatComp_O, & MatComp_IO;

class MatLcomp : public VbaseLcomp
{
protected:
    typedef VbaseLcomp Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    MatLcomp(): m_N1(0), m_N2(0) {};
    MatLcomp(Long_I N1, Long_I N2);
    MatLcomp(const MatLcomp &rhs);        // Copy constructor
    MatLcomp & operator=(const MatLcomp &rhs) = delete;
    void operator<<(MatLcomp &rhs); // move data and rhs.resize(0, 0)
    Lcomp& operator()(Long_I i, Long_I j); // double indexing
    const Lcomp& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
    void reshape(Long_I N1, Long_I N2);
};

inline MatLcomp::MatLcomp(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatLcomp::MatLcomp(const MatLcomp &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatLcomp::operator<<(MatLcomp &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Lcomp& MatLcomp::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatLcomp subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Lcomp & MatLcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatLcomp subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatLcomp::n1() const
{
    return m_N1;
}

inline Long MatLcomp::n2() const
{
    return m_N2;
}

inline void MatLcomp::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

inline void MatLcomp::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatLcomp reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatLcomp & MatLcomp_I;
typedef MatLcomp & MatLcomp_O, & MatLcomp_IO;

class MatFimag : public VbaseFimag
{
protected:
    typedef VbaseFimag Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    MatFimag(): m_N1(0), m_N2(0) {};
    MatFimag(Long_I N1, Long_I N2);
    MatFimag(const MatFimag &rhs);        // Copy constructor
    MatFimag & operator=(const MatFimag &rhs) = delete;
    void operator<<(MatFimag &rhs); // move data and rhs.resize(0, 0)
    Fimag& operator()(Long_I i, Long_I j); // double indexing
    const Fimag& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
    void reshape(Long_I N1, Long_I N2);
};

inline MatFimag::MatFimag(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatFimag::MatFimag(const MatFimag &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatFimag::operator<<(MatFimag &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Fimag& MatFimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatFimag subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Fimag & MatFimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatFimag subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatFimag::n1() const
{
    return m_N1;
}

inline Long MatFimag::n2() const
{
    return m_N2;
}

inline void MatFimag::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

inline void MatFimag::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatFimag reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatFimag & MatFimag_I;
typedef MatFimag & MatFimag_O, & MatFimag_IO;

class MatImag : public VbaseImag
{
protected:
    typedef VbaseImag Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    MatImag(): m_N1(0), m_N2(0) {};
    MatImag(Long_I N1, Long_I N2);
    MatImag(const MatImag &rhs);        // Copy constructor
    MatImag & operator=(const MatImag &rhs) = delete;
    void operator<<(MatImag &rhs); // move data and rhs.resize(0, 0)
    Imag& operator()(Long_I i, Long_I j); // double indexing
    const Imag& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
    void reshape(Long_I N1, Long_I N2);
};

inline MatImag::MatImag(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatImag::MatImag(const MatImag &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatImag::operator<<(MatImag &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Imag& MatImag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatImag subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Imag & MatImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatImag subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatImag::n1() const
{
    return m_N1;
}

inline Long MatImag::n2() const
{
    return m_N2;
}

inline void MatImag::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

inline void MatImag::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatImag reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatImag & MatImag_I;
typedef MatImag & MatImag_O, & MatImag_IO;

class MatLimag : public VbaseLimag
{
protected:
    typedef VbaseLimag Base;
    Long m_N1, m_N2;
public:
    using Base::ptr;
    MatLimag(): m_N1(0), m_N2(0) {};
    MatLimag(Long_I N1, Long_I N2);
    MatLimag(const MatLimag &rhs);        // Copy constructor
    MatLimag & operator=(const MatLimag &rhs) = delete;
    void operator<<(MatLimag &rhs); // move data and rhs.resize(0, 0)
    Limag& operator()(Long_I i, Long_I j); // double indexing
    const Limag& operator()(Long_I i, Long_I j) const;
    Long n1() const;
    Long n2() const;
    void resize(Long_I N1, Long_I N2); // resize (contents not preserved)
    void reshape(Long_I N1, Long_I N2);
};

inline MatLimag::MatLimag(Long_I N1, Long_I N2) : Base(N1*N2), m_N1(N1), m_N2(N2) {}

inline MatLimag::MatLimag(const MatLimag &rhs) : Base(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference argument for function input or output, and use \"=\" to copy!");
}

inline void MatLimag::operator<<(MatLimag &rhs)
{
    m_N1 = rhs.m_N1; m_N2 = rhs.m_N2;
    rhs.m_N1 = rhs.m_N2 = 0;
    Base::operator<<(rhs);
}

inline Limag& MatLimag::operator()(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatLimag subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline const Limag & MatLimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("MatLimag subscript out of bounds");
#endif
    return m_p[m_N2*i+j];
}

inline Long MatLimag::n1() const
{
    return m_N1;
}

inline Long MatLimag::n2() const
{
    return m_N2;
}

inline void MatLimag::resize(Long_I N1, Long_I N2)
{
    if (N1 != m_N1 || N2 != m_N2) {
        Base::resize(N1*N2);
        m_N1 = N1; m_N2 = N2;
    }
}

inline void MatLimag::reshape(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 * N2 != m_N)
        SLS_ERR("MatLimag reshaping from ("+num2str(m_N1)+", "+num2str(m_N2)
            +") to ("+num2str(N1)+", "+num2str(N2)+"), element number not the same!");
#endif
    m_N1 = N1; m_N2 = N2;
}

typedef const MatLimag & MatLimag_I;
typedef MatLimag & MatLimag_O, & MatLimag_IO;

} // namespace slisc
