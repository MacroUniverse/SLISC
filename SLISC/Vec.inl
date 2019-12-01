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

inline VecInt::VecInt(Long_I N) : Base(N) {}

inline VecInt::VecInt(const VecInt &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

inline void VecInt::operator<<(VecInt &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecInt & VecInt_I;
typedef VecInt & VecInt_O, & VecInt_IO;

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

inline VecLlong::VecLlong(Long_I N) : Base(N) {}

inline VecLlong::VecLlong(const VecLlong &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

inline void VecLlong::operator<<(VecLlong &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecLlong & VecLlong_I;
typedef VecLlong & VecLlong_O, & VecLlong_IO;

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

inline VecDoub::VecDoub(Long_I N) : Base(N) {}

inline VecDoub::VecDoub(const VecDoub &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

inline void VecDoub::operator<<(VecDoub &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecDoub & VecDoub_I;
typedef VecDoub & VecDoub_O, & VecDoub_IO;

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

inline VecComp::VecComp(Long_I N) : Base(N) {}

inline VecComp::VecComp(const VecComp &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

inline void VecComp::operator<<(VecComp &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecComp & VecComp_I;
typedef VecComp & VecComp_O, & VecComp_IO;

