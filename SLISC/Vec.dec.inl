class VecBool : public VbaseBool
{
public:
    typedef VbaseBool Base;
    using Base::resize;
    using Base::operator[];

    explicit VecBool(Long_I N);
    VecBool(const VecBool &rhs); // copy constructor
    void operator<<(VecBool &rhs); // move data and rhs.resize(0)
};

class VecChar : public VbaseChar
{
public:
    typedef VbaseChar Base;
    using Base::resize;
    using Base::operator[];

    explicit VecChar(Long_I N);
    VecChar(const VecChar &rhs); // copy constructor
    void operator<<(VecChar &rhs); // move data and rhs.resize(0)
};

class VecInt : public VbaseInt
{
public:
    typedef VbaseInt Base;
    using Base::resize;
    using Base::operator[];

    explicit VecInt(Long_I N);
    VecInt(const VecInt &rhs); // copy constructor
    void operator<<(VecInt &rhs); // move data and rhs.resize(0)
};

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

class VecFloat : public VbaseFloat
{
public:
    typedef VbaseFloat Base;
    using Base::resize;
    using Base::operator[];

    explicit VecFloat(Long_I N);
    VecFloat(const VecFloat &rhs); // copy constructor
    void operator<<(VecFloat &rhs); // move data and rhs.resize(0)
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

class VecLdoub : public VbaseLdoub
{
public:
    typedef VbaseLdoub Base;
    using Base::resize;
    using Base::operator[];

    explicit VecLdoub(Long_I N);
    VecLdoub(const VecLdoub &rhs); // copy constructor
    void operator<<(VecLdoub &rhs); // move data and rhs.resize(0)
};

class VecFcomp : public VbaseFcomp
{
public:
    typedef VbaseFcomp Base;
    using Base::resize;
    using Base::operator[];

    explicit VecFcomp(Long_I N);
    VecFcomp(const VecFcomp &rhs); // copy constructor
    void operator<<(VecFcomp &rhs); // move data and rhs.resize(0)
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

class VecLcomp : public VbaseLcomp
{
public:
    typedef VbaseLcomp Base;
    using Base::resize;
    using Base::operator[];

    explicit VecLcomp(Long_I N);
    VecLcomp(const VecLcomp &rhs); // copy constructor
    void operator<<(VecLcomp &rhs); // move data and rhs.resize(0)
};

