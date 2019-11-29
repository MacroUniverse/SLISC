class VecLlong : public VbaseLlong
{
public:
    typedef VbaseLlong Base;
    using Base::resize;
    using Base::operator[];

    explicit VecLlong(Long_I N);
    VecLlong(const VecLlong &rhs); // copy constructor
    void operator<<(VecLlong &rhs); // move data and rhs.resize(0)
};

class VecDoub : public VbaseDoub
{
public:
    typedef VbaseDoub Base;
    using Base::resize;
    using Base::operator[];

    explicit VecDoub(Long_I N);
    VecDoub(const VecDoub &rhs); // copy constructor
    void operator<<(VecDoub &rhs); // move data and rhs.resize(0)
};

class VecComp : public VbaseComp
{
public:
    typedef VbaseComp Base;
    using Base::resize;
    using Base::operator[];

    explicit VecComp(Long_I N);
    VecComp(const VecComp &rhs); // copy constructor
    void operator<<(VecComp &rhs); // move data and rhs.resize(0)
};

