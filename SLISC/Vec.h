// vector container
#pragma once
#include "Vbase.h"

namespace slisc {
class VecChar : public VbaseChar
{
public:
    typedef VbaseChar Base;
    using Base::resize;
    using Base::operator[];

    VecChar() = default;
    explicit VecChar(Long_I N);
    VecChar(const VecChar &rhs); // copy constructor
    VecChar & operator=(const VecChar &rhs) = delete;
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

typedef const VecChar & VecChar_I;
typedef VecChar & VecChar_O, & VecChar_IO;

class VecInt : public VbaseInt
{
public:
    typedef VbaseInt Base;
    using Base::resize;
    using Base::operator[];

    VecInt() = default;
    explicit VecInt(Long_I N);
    VecInt(const VecInt &rhs); // copy constructor
    VecInt & operator=(const VecInt &rhs) = delete;
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

    VecLlong() = default;
    explicit VecLlong(Long_I N);
    VecLlong(const VecLlong &rhs); // copy constructor
    VecLlong & operator=(const VecLlong &rhs) = delete;
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

#ifdef SLS_USE_INT_AS_LONG
typedef VecInt VecLong;
#else
typedef VecLlong VecLong;
#endif
typedef const VecLong & VecLong_I;
typedef VecLong & VecLong_O, & VecLong_IO;

class VecFloat : public VbaseFloat
{
public:
    typedef VbaseFloat Base;
    using Base::resize;
    using Base::operator[];

    VecFloat() = default;
    explicit VecFloat(Long_I N);
    VecFloat(const VecFloat &rhs); // copy constructor
    VecFloat & operator=(const VecFloat &rhs) = delete;
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

typedef const VecFloat & VecFloat_I;
typedef VecFloat & VecFloat_O, & VecFloat_IO;

class VecDoub : public VbaseDoub
{
public:
    typedef VbaseDoub Base;
    using Base::resize;
    using Base::operator[];

    VecDoub() = default;
    explicit VecDoub(Long_I N);
    VecDoub(const VecDoub &rhs); // copy constructor
    VecDoub & operator=(const VecDoub &rhs) = delete;
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

    VecComp() = default;
    explicit VecComp(Long_I N);
    VecComp(const VecComp &rhs); // copy constructor
    VecComp & operator=(const VecComp &rhs) = delete;
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


class VecBool : public VbaseBool
{
public:
    typedef VbaseBool Base;
    using Base::ref; // bit reference
    using Base::resize;
    using Base::operator[];

    VecBool() = default;
    explicit VecBool(Long_I N);
    VecBool(const VecBool &rhs); // copy constructor
    VecBool & operator=(const VecBool &rhs) = delete;
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

typedef const VecBool & VecBool_I;
typedef VecBool & VecBool_O, & VecBool_IO;

} // namespace slisc
