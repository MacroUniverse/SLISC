
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

inline VecBool::VecBool(Long_I N) : Base(N) {}

inline VecBool::VecBool(const VecBool &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

inline void VecBool::operator<<(VecBool &rhs)
{
    Base::operator<<(rhs);
}


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

inline VecChar::VecChar(Long_I N) : Base(N) {}

inline VecChar::VecChar(const VecChar &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

inline void VecChar::operator<<(VecChar &rhs)
{
    Base::operator<<(rhs);
}


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

inline VecFloat::VecFloat(Long_I N) : Base(N) {}

inline VecFloat::VecFloat(const VecFloat &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

inline void VecFloat::operator<<(VecFloat &rhs)
{
    Base::operator<<(rhs);
}


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

inline VecLdoub::VecLdoub(Long_I N) : Base(N) {}

inline VecLdoub::VecLdoub(const VecLdoub &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

inline void VecLdoub::operator<<(VecLdoub &rhs)
{
    Base::operator<<(rhs);
}


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

inline VecFcomp::VecFcomp(Long_I N) : Base(N) {}

inline VecFcomp::VecFcomp(const VecFcomp &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

inline void VecFcomp::operator<<(VecFcomp &rhs)
{
    Base::operator<<(rhs);
}


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

inline VecLcomp::VecLcomp(Long_I N) : Base(N) {}

inline VecLcomp::VecLcomp(const VecLcomp &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

inline void VecLcomp::operator<<(VecLcomp &rhs)
{
    Base::operator<<(rhs);
}

