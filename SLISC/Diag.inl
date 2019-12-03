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
    Long n1() const;
    Long n2() const;
    Int &ref(Long_I i, Long_I j);
    const Int operator()(Long_I i, Long_I j) const;
};

DiagInt::DiagInt(Long_I N) : Base(N) {}

DiagInt::DiagInt(VecInt_I v) : Base(v.size())
{
    veccpy(m_p, v.ptr(), m_N);
}

Long DiagInt::size() const
{
    SLS_ERR("use nnz() instead!");
    return 0;
}

Long DiagInt::nnz() const
{
    return Base::size();
}

Long DiagInt::n1() const
{
    return Base::size();
}

Long DiagInt::n2() const
{
    return Base::size();
}

Int &DiagInt::ref(Long_I i, Long_I j)
{
    if (i == j)
        return (*this)[i];
    SLS_ERR("not a diagonal element!");
    return (*this)[i];
}

const Int DiagInt::operator()(Long_I i, Long_I j) const
{
    if (i == j) return (*this)[i];
    return 0;
}

// convert vector to diagonal matrix
const DiagInt &diag(VecInt_I v)
{
    return (DiagInt&)v;
}

typedef const DiagInt & DiagInt_I;
typedef DiagInt & DiagInt_O, & DiagInt_IO;

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
    Long n1() const;
    Long n2() const;
    Llong &ref(Long_I i, Long_I j);
    const Llong operator()(Long_I i, Long_I j) const;
};

DiagLlong::DiagLlong(Long_I N) : Base(N) {}

DiagLlong::DiagLlong(VecLlong_I v) : Base(v.size())
{
    veccpy(m_p, v.ptr(), m_N);
}

Long DiagLlong::size() const
{
    SLS_ERR("use nnz() instead!");
    return 0;
}

Long DiagLlong::nnz() const
{
    return Base::size();
}

Long DiagLlong::n1() const
{
    return Base::size();
}

Long DiagLlong::n2() const
{
    return Base::size();
}

Llong &DiagLlong::ref(Long_I i, Long_I j)
{
    if (i == j)
        return (*this)[i];
    SLS_ERR("not a diagonal element!");
    return (*this)[i];
}

const Llong DiagLlong::operator()(Long_I i, Long_I j) const
{
    if (i == j) return (*this)[i];
    return 0;
}

// convert vector to diagonal matrix
const DiagLlong &diag(VecLlong_I v)
{
    return (DiagLlong&)v;
}

typedef const DiagLlong & DiagLlong_I;
typedef DiagLlong & DiagLlong_O, & DiagLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef DiagInt DiagLong;
#else
typedef DiagLlong DiagLong;
#endif

typedef const DiagLong & DiagLong_I;
typedef DiagLong & DiagLong_O, & DiagLong_IO;

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
    Long n1() const;
    Long n2() const;
    Doub &ref(Long_I i, Long_I j);
    const Doub operator()(Long_I i, Long_I j) const;
};

DiagDoub::DiagDoub(Long_I N) : Base(N) {}

DiagDoub::DiagDoub(VecDoub_I v) : Base(v.size())
{
    veccpy(m_p, v.ptr(), m_N);
}

Long DiagDoub::size() const
{
    SLS_ERR("use nnz() instead!");
    return 0;
}

Long DiagDoub::nnz() const
{
    return Base::size();
}

Long DiagDoub::n1() const
{
    return Base::size();
}

Long DiagDoub::n2() const
{
    return Base::size();
}

Doub &DiagDoub::ref(Long_I i, Long_I j)
{
    if (i == j)
        return (*this)[i];
    SLS_ERR("not a diagonal element!");
    return (*this)[i];
}

const Doub DiagDoub::operator()(Long_I i, Long_I j) const
{
    if (i == j) return (*this)[i];
    return 0;
}

// convert vector to diagonal matrix
const DiagDoub &diag(VecDoub_I v)
{
    return (DiagDoub&)v;
}

typedef const DiagDoub & DiagDoub_I;
typedef DiagDoub & DiagDoub_O, & DiagDoub_IO;

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
    Long n1() const;
    Long n2() const;
    Comp &ref(Long_I i, Long_I j);
    const Comp operator()(Long_I i, Long_I j) const;
};

DiagComp::DiagComp(Long_I N) : Base(N) {}

DiagComp::DiagComp(VecComp_I v) : Base(v.size())
{
    veccpy(m_p, v.ptr(), m_N);
}

Long DiagComp::size() const
{
    SLS_ERR("use nnz() instead!");
    return 0;
}

Long DiagComp::nnz() const
{
    return Base::size();
}

Long DiagComp::n1() const
{
    return Base::size();
}

Long DiagComp::n2() const
{
    return Base::size();
}

Comp &DiagComp::ref(Long_I i, Long_I j)
{
    if (i == j)
        return (*this)[i];
    SLS_ERR("not a diagonal element!");
    return (*this)[i];
}

const Comp DiagComp::operator()(Long_I i, Long_I j) const
{
    if (i == j) return (*this)[i];
    return 0;
}

// convert vector to diagonal matrix
const DiagComp &diag(VecComp_I v)
{
    return (DiagComp&)v;
}

typedef const DiagComp & DiagComp_I;
typedef DiagComp & DiagComp_O, & DiagComp_IO;
