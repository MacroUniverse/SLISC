// square diagonal matrix
// mostly a clone a Vector<T>
#pragma once
#include "Vec.h"

namespace slisc {
void veccpy(Int *, const Int *, Llong_I);

class DiagInt : public VecInt
{
private:
    typedef VecInt Base;
public:
    DiagInt(Long_I N);
    DiagInt(VecInt_I v);
    Long size() const;
    Long nnz() const;
    Long n0() const;
    Long n1() const;
    Int &ref(Long_I i, Long_I j);
    Int operator()(Long_I i, Long_I j) const;
};

inline DiagInt::DiagInt(Long_I N) : Base(N) {}

inline DiagInt::DiagInt(VecInt_I v) : Base(v.size())
{
    veccpy(m_p, v.p(), m_N);
}

inline Long DiagInt::size() const
{
    SLS_ERR("use nnz() instead!");
    return 0;
}

inline Long DiagInt::nnz() const
{
    return Base::size();
}

inline Long DiagInt::n0() const
{
    return Base::size();
}

inline Long DiagInt::n1() const
{
    return Base::size();
}

inline Int &DiagInt::ref(Long_I i, Long_I j)
{
    if (i == j)
        return (*this)[i];
    SLS_ERR("not a diagonal element!");
    return (*this)[i];
}

inline Int DiagInt::operator()(Long_I i, Long_I j) const
{
    if (i == j) return (*this)[i];
    return 0;
}

// convert vector to diagonal matrix
inline const DiagInt &diag(VecInt_I v)
{
    return (DiagInt&)v;
}

typedef const DiagInt &DiagInt_I;
typedef DiagInt &DiagInt_O, &DiagInt_IO;

void veccpy(Llong *, const Llong *, Llong_I);

class DiagLlong : public VecLlong
{
private:
    typedef VecLlong Base;
public:
    DiagLlong(Long_I N);
    DiagLlong(VecLlong_I v);
    Long size() const;
    Long nnz() const;
    Long n0() const;
    Long n1() const;
    Llong &ref(Long_I i, Long_I j);
    Llong operator()(Long_I i, Long_I j) const;
};

inline DiagLlong::DiagLlong(Long_I N) : Base(N) {}

inline DiagLlong::DiagLlong(VecLlong_I v) : Base(v.size())
{
    veccpy(m_p, v.p(), m_N);
}

inline Long DiagLlong::size() const
{
    SLS_ERR("use nnz() instead!");
    return 0;
}

inline Long DiagLlong::nnz() const
{
    return Base::size();
}

inline Long DiagLlong::n0() const
{
    return Base::size();
}

inline Long DiagLlong::n1() const
{
    return Base::size();
}

inline Llong &DiagLlong::ref(Long_I i, Long_I j)
{
    if (i == j)
        return (*this)[i];
    SLS_ERR("not a diagonal element!");
    return (*this)[i];
}

inline Llong DiagLlong::operator()(Long_I i, Long_I j) const
{
    if (i == j) return (*this)[i];
    return 0;
}

// convert vector to diagonal matrix
inline const DiagLlong &diag(VecLlong_I v)
{
    return (DiagLlong&)v;
}

typedef const DiagLlong &DiagLlong_I;
typedef DiagLlong &DiagLlong_O, &DiagLlong_IO;

void veccpy(Doub *, const Doub *, Llong_I);

class DiagDoub : public VecDoub
{
private:
    typedef VecDoub Base;
public:
    DiagDoub(Long_I N);
    DiagDoub(VecDoub_I v);
    Long size() const;
    Long nnz() const;
    Long n0() const;
    Long n1() const;
    Doub &ref(Long_I i, Long_I j);
    Doub operator()(Long_I i, Long_I j) const;
};

inline DiagDoub::DiagDoub(Long_I N) : Base(N) {}

inline DiagDoub::DiagDoub(VecDoub_I v) : Base(v.size())
{
    veccpy(m_p, v.p(), m_N);
}

inline Long DiagDoub::size() const
{
    SLS_ERR("use nnz() instead!");
    return 0;
}

inline Long DiagDoub::nnz() const
{
    return Base::size();
}

inline Long DiagDoub::n0() const
{
    return Base::size();
}

inline Long DiagDoub::n1() const
{
    return Base::size();
}

inline Doub &DiagDoub::ref(Long_I i, Long_I j)
{
    if (i == j)
        return (*this)[i];
    SLS_ERR("not a diagonal element!");
    return (*this)[i];
}

inline Doub DiagDoub::operator()(Long_I i, Long_I j) const
{
    if (i == j) return (*this)[i];
    return 0;
}

// convert vector to diagonal matrix
inline const DiagDoub &diag(VecDoub_I v)
{
    return (DiagDoub&)v;
}

typedef const DiagDoub &DiagDoub_I;
typedef DiagDoub &DiagDoub_O, &DiagDoub_IO;

void veccpy(Comp *, const Comp *, Llong_I);

class DiagComp : public VecComp
{
private:
    typedef VecComp Base;
public:
    DiagComp(Long_I N);
    DiagComp(VecComp_I v);
    Long size() const;
    Long nnz() const;
    Long n0() const;
    Long n1() const;
    Comp &ref(Long_I i, Long_I j);
    Comp operator()(Long_I i, Long_I j) const;
};

inline DiagComp::DiagComp(Long_I N) : Base(N) {}

inline DiagComp::DiagComp(VecComp_I v) : Base(v.size())
{
    veccpy(m_p, v.p(), m_N);
}

inline Long DiagComp::size() const
{
    SLS_ERR("use nnz() instead!");
    return 0;
}

inline Long DiagComp::nnz() const
{
    return Base::size();
}

inline Long DiagComp::n0() const
{
    return Base::size();
}

inline Long DiagComp::n1() const
{
    return Base::size();
}

inline Comp &DiagComp::ref(Long_I i, Long_I j)
{
    if (i == j)
        return (*this)[i];
    SLS_ERR("not a diagonal element!");
    return (*this)[i];
}

inline Comp DiagComp::operator()(Long_I i, Long_I j) const
{
    if (i == j) return (*this)[i];
    return 0;
}

// convert vector to diagonal matrix
inline const DiagComp &diag(VecComp_I v)
{
    return (DiagComp&)v;
}

typedef const DiagComp &DiagComp_I;
typedef DiagComp &DiagComp_O, &DiagComp_IO;


#ifdef SLS_USE_INT_AS_LONG
typedef DiagInt DiagLong;
#else
typedef DiagLlong DiagLong;
#endif
typedef const DiagLong &DiagLong_I;
typedef DiagLong &DiagLong_O, &DiagLong_IO;

} // namespace slisc
