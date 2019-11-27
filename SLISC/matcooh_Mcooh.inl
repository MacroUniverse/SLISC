class McoohInt : public McooInt
{
private:
    typedef McooInt Base;
    // McoohInt() : Base() {} // default constructor : uninitialized
public:
    McoohInt(Long_I Nr, Long_I Nc);
    McoohInt(Long_I Nr, Long_I Nc, Long_I Nnz);
    using Base::operator();
    Int &ref(Long_I i, Long_I j); // reference to an element
    const Int operator()(Long_I i, Long_I j) const; // double indexing (element need not exist)
    void push(Int_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Int_I s, Long_I i, Long_I j); // change existing element or push new element
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
};

McoohInt::McoohInt(Long_I Nr, Long_I Nc) : Base(Nr, Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr != Nc) SLS_ERR("must be square matrix!");
#endif
}

McoohInt::McoohInt(Long_I Nr, Long_I Nc, Long_I Nnz) : Base(Nr, Nc, Nnz)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr != Nc) SLS_ERR("must be square matrix!");
#endif
}

// cannot return a const reference since conj() might create a temporary
const Int McoohInt::operator()(Long_I i, Long_I j) const
{
    if (i > j) {
        return CONJ(Base::operator()(j, i));
    }
    return Base::operator()(i, j);
}

Int &McoohInt::ref(Long_I i, Long_I j)
{
    if (i > j) {
        SLS_ERR("lower triangle is empty!");
        return Base::ref(j, i);
    }
    else
        return Base::ref(i, j);
}

void McoohInt::push(Int_I s, Long_I i, Long_I j)
{
    if (i > j)
        Base::push(CONJ(s), j, i);
    else
        Base::push(s, i, j);
}

void McoohInt::set(Int_I s, Long_I i, Long_I j)
{
    if (i > j)
        Base::set(s, j, i);
    else
        Base::set(s, i, j);
}

void McoohInt::reshape(Long_I Nr, Long_I Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr != Nc) SLS_ERR("must be a square matrix!");
#endif
    Base::reshape(Nr, Nc);
}

class McoohDoub : public McooDoub
{
private:
    typedef McooDoub Base;
    // McoohDoub() : Base() {} // default constructor : uninitialized
public:
    McoohDoub(Long_I Nr, Long_I Nc);
    McoohDoub(Long_I Nr, Long_I Nc, Long_I Nnz);
    using Base::operator();
    Doub &ref(Long_I i, Long_I j); // reference to an element
    const Doub operator()(Long_I i, Long_I j) const; // double indexing (element need not exist)
    void push(Doub_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Doub_I s, Long_I i, Long_I j); // change existing element or push new element
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
};

McoohDoub::McoohDoub(Long_I Nr, Long_I Nc) : Base(Nr, Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr != Nc) SLS_ERR("must be square matrix!");
#endif
}

McoohDoub::McoohDoub(Long_I Nr, Long_I Nc, Long_I Nnz) : Base(Nr, Nc, Nnz)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr != Nc) SLS_ERR("must be square matrix!");
#endif
}

// cannot return a const reference since conj() might create a temporary
const Doub McoohDoub::operator()(Long_I i, Long_I j) const
{
    if (i > j) {
        return CONJ(Base::operator()(j, i));
    }
    return Base::operator()(i, j);
}

Doub &McoohDoub::ref(Long_I i, Long_I j)
{
    if (i > j) {
        SLS_ERR("lower triangle is empty!");
        return Base::ref(j, i);
    }
    else
        return Base::ref(i, j);
}

void McoohDoub::push(Doub_I s, Long_I i, Long_I j)
{
    if (i > j)
        Base::push(CONJ(s), j, i);
    else
        Base::push(s, i, j);
}

void McoohDoub::set(Doub_I s, Long_I i, Long_I j)
{
    if (i > j)
        Base::set(s, j, i);
    else
        Base::set(s, i, j);
}

void McoohDoub::reshape(Long_I Nr, Long_I Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr != Nc) SLS_ERR("must be a square matrix!");
#endif
    Base::reshape(Nr, Nc);
}

class McoohComp : public McooComp
{
private:
    typedef McooComp Base;
    // McoohComp() : Base() {} // default constructor : uninitialized
public:
    McoohComp(Long_I Nr, Long_I Nc);
    McoohComp(Long_I Nr, Long_I Nc, Long_I Nnz);
    using Base::operator();
    Comp &ref(Long_I i, Long_I j); // reference to an element
    const Comp operator()(Long_I i, Long_I j) const; // double indexing (element need not exist)
    void push(Comp_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Comp_I s, Long_I i, Long_I j); // change existing element or push new element
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
};

McoohComp::McoohComp(Long_I Nr, Long_I Nc) : Base(Nr, Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr != Nc) SLS_ERR("must be square matrix!");
#endif
}

McoohComp::McoohComp(Long_I Nr, Long_I Nc, Long_I Nnz) : Base(Nr, Nc, Nnz)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr != Nc) SLS_ERR("must be square matrix!");
#endif
}

// cannot return a const reference since conj() might create a temporary
const Comp McoohComp::operator()(Long_I i, Long_I j) const
{
    if (i > j) {
        return CONJ(Base::operator()(j, i));
    }
    return Base::operator()(i, j);
}

Comp &McoohComp::ref(Long_I i, Long_I j)
{
    if (i > j) {
        SLS_ERR("lower triangle is empty!");
        return Base::ref(j, i);
    }
    else
        return Base::ref(i, j);
}

void McoohComp::push(Comp_I s, Long_I i, Long_I j)
{
    if (i > j)
        Base::push(CONJ(s), j, i);
    else
        Base::push(s, i, j);
}

void McoohComp::set(Comp_I s, Long_I i, Long_I j)
{
    if (i > j)
        Base::set(s, j, i);
    else
        Base::set(s, i, j);
}

void McoohComp::reshape(Long_I Nr, Long_I Nc)
{
#ifdef SLS_CHECK_SHAPE
    if (Nr != Nc) SLS_ERR("must be a square matrix!");
#endif
    Base::reshape(Nr, Nc);
}

