class DiagInt : public VecInt
{
private:
    typedef VecInt Base;
    DiagInt() : Base() {} // default constructor: uninitialized
public:
    using Base::operator();
    using Base::operator=;
    DiagInt(Long_I N);
    DiagInt(Long_I N, Int_I s);
    DiagInt(VecInt_I v);
    Long size() const;
    Long nnz() const;
    Long n1() const;
    Long n2() const;
    DiagInt &operator=(DiagInt_I rhs);
    DiagInt &operator=(VecInt_I rhs);
    Int &ref(Long_I i, Long_I j);
    const Int operator()(Long_I i, Long_I j) const;
};

DiagInt::DiagInt(Long_I N) : Base(N) {}

DiagInt::DiagInt(Long_I N, Int_I s) : Base(N, s) {}

DiagInt::DiagInt(VecInt_I v) : Base(v.size())
{
    *this = v;
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

DiagInt &DiagInt::operator=(DiagInt_I rhs)
{
    Base::operator=(rhs); return *this;
}

DiagInt &DiagInt::operator=(VecInt_I rhs)
{
    Base::operator=(rhs); return *this;
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

class DiagDoub : public VecDoub
{
private:
    typedef VecDoub Base;
    DiagDoub() : Base() {} // default constructor: uninitialized
public:
    using Base::operator();
    using Base::operator=;
    DiagDoub(Long_I N);
    DiagDoub(Long_I N, Doub_I s);
    DiagDoub(VecDoub_I v);
    Long size() const;
    Long nnz() const;
    Long n1() const;
    Long n2() const;
    DiagDoub &operator=(DiagDoub_I rhs);
    DiagDoub &operator=(VecDoub_I rhs);
    Doub &ref(Long_I i, Long_I j);
    const Doub operator()(Long_I i, Long_I j) const;
};

DiagDoub::DiagDoub(Long_I N) : Base(N) {}

DiagDoub::DiagDoub(Long_I N, Doub_I s) : Base(N, s) {}

DiagDoub::DiagDoub(VecDoub_I v) : Base(v.size())
{
    *this = v;
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

DiagDoub &DiagDoub::operator=(DiagDoub_I rhs)
{
    Base::operator=(rhs); return *this;
}

DiagDoub &DiagDoub::operator=(VecDoub_I rhs)
{
    Base::operator=(rhs); return *this;
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

class DiagFcomp : public VecFcomp
{
private:
    typedef VecFcomp Base;
    DiagFcomp() : Base() {} // default constructor: uninitialized
public:
    using Base::operator();
    using Base::operator=;
    DiagFcomp(Long_I N);
    DiagFcomp(Long_I N, Fcomp_I s);
    DiagFcomp(VecFcomp_I v);
    Long size() const;
    Long nnz() const;
    Long n1() const;
    Long n2() const;
    DiagFcomp &operator=(DiagFcomp_I rhs);
    DiagFcomp &operator=(VecFcomp_I rhs);
    Fcomp &ref(Long_I i, Long_I j);
    const Fcomp operator()(Long_I i, Long_I j) const;
};

DiagFcomp::DiagFcomp(Long_I N) : Base(N) {}

DiagFcomp::DiagFcomp(Long_I N, Fcomp_I s) : Base(N, s) {}

DiagFcomp::DiagFcomp(VecFcomp_I v) : Base(v.size())
{
    *this = v;
}

Long DiagFcomp::size() const
{
    SLS_ERR("use nnz() instead!");
    return 0;
}

Long DiagFcomp::nnz() const
{
    return Base::size();
}

Long DiagFcomp::n1() const
{
    return Base::size();
}

Long DiagFcomp::n2() const
{
    return Base::size();
}

DiagFcomp &DiagFcomp::operator=(DiagFcomp_I rhs)
{
    Base::operator=(rhs); return *this;
}

DiagFcomp &DiagFcomp::operator=(VecFcomp_I rhs)
{
    Base::operator=(rhs); return *this;
}

Fcomp &DiagFcomp::ref(Long_I i, Long_I j)
{
    if (i == j)
		return (*this)[i];
	SLS_ERR("not a diagonal element!");
    return (*this)[i];
}

const Fcomp DiagFcomp::operator()(Long_I i, Long_I j) const
{
    if (i == j) return (*this)[i];
    return 0;
}

// convert vector to diagonal matrix
const DiagFcomp &diag(VecFcomp_I v)
{
    return (DiagFcomp&)v;
}

class DiagComp : public VecComp
{
private:
    typedef VecComp Base;
    DiagComp() : Base() {} // default constructor: uninitialized
public:
    using Base::operator();
    using Base::operator=;
    DiagComp(Long_I N);
    DiagComp(Long_I N, Comp_I s);
    DiagComp(VecComp_I v);
    Long size() const;
    Long nnz() const;
    Long n1() const;
    Long n2() const;
    DiagComp &operator=(DiagComp_I rhs);
    DiagComp &operator=(VecComp_I rhs);
    Comp &ref(Long_I i, Long_I j);
    const Comp operator()(Long_I i, Long_I j) const;
};

DiagComp::DiagComp(Long_I N) : Base(N) {}

DiagComp::DiagComp(Long_I N, Comp_I s) : Base(N, s) {}

DiagComp::DiagComp(VecComp_I v) : Base(v.size())
{
    *this = v;
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

DiagComp &DiagComp::operator=(DiagComp_I rhs)
{
    Base::operator=(rhs); return *this;
}

DiagComp &DiagComp::operator=(VecComp_I rhs)
{
    Base::operator=(rhs); return *this;
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

class DiagImag : public VecImag
{
private:
    typedef VecImag Base;
    DiagImag() : Base() {} // default constructor: uninitialized
public:
    using Base::operator();
    using Base::operator=;
    DiagImag(Long_I N);
    DiagImag(Long_I N, Imag_I s);
    DiagImag(VecImag_I v);
    Long size() const;
    Long nnz() const;
    Long n1() const;
    Long n2() const;
    DiagImag &operator=(DiagImag_I rhs);
    DiagImag &operator=(VecImag_I rhs);
    Imag &ref(Long_I i, Long_I j);
    const Imag operator()(Long_I i, Long_I j) const;
};

DiagImag::DiagImag(Long_I N) : Base(N) {}

DiagImag::DiagImag(Long_I N, Imag_I s) : Base(N, s) {}

DiagImag::DiagImag(VecImag_I v) : Base(v.size())
{
    *this = v;
}

Long DiagImag::size() const
{
    SLS_ERR("use nnz() instead!");
    return 0;
}

Long DiagImag::nnz() const
{
    return Base::size();
}

Long DiagImag::n1() const
{
    return Base::size();
}

Long DiagImag::n2() const
{
    return Base::size();
}

DiagImag &DiagImag::operator=(DiagImag_I rhs)
{
    Base::operator=(rhs); return *this;
}

DiagImag &DiagImag::operator=(VecImag_I rhs)
{
    Base::operator=(rhs); return *this;
}

Imag &DiagImag::ref(Long_I i, Long_I j)
{
    if (i == j)
		return (*this)[i];
	SLS_ERR("not a diagonal element!");
    return (*this)[i];
}

const Imag DiagImag::operator()(Long_I i, Long_I j) const
{
    if (i == j) return (*this)[i];
    return 0;
}

// convert vector to diagonal matrix
const DiagImag &diag(VecImag_I v)
{
    return (DiagImag&)v;
}

