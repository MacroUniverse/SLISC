// vector container
#pragma once
#include "Vbase.h"

namespace slisc {
class VecChar : public VbaseChar
{
public:
    typedef VbaseChar Base;
    VecChar() = default;
    explicit VecChar(Long_I N);
    VecChar(const VecChar &rhs); // copy constructor
    VecChar & operator=(const VecChar &rhs) = delete;
    Char & operator()(Long_I i);
    const Char & operator()(Long_I i) const;
    void operator<<(VecChar &rhs); // move data and rhs.resize(0)
};

inline VecChar::VecChar(Long_I N) : Base(N) {}

inline VecChar::VecChar(const VecChar &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Char & VecChar::operator()(Long_I i)
{ return (*this)[i]; }

inline const Char & VecChar::operator()(Long_I i) const
{ return (*this)[i]; }

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
    VecInt() = default;
    explicit VecInt(Long_I N);
    VecInt(const VecInt &rhs); // copy constructor
    VecInt & operator=(const VecInt &rhs) = delete;
    Int & operator()(Long_I i);
    const Int & operator()(Long_I i) const;
    void operator<<(VecInt &rhs); // move data and rhs.resize(0)
};

inline VecInt::VecInt(Long_I N) : Base(N) {}

inline VecInt::VecInt(const VecInt &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Int & VecInt::operator()(Long_I i)
{ return (*this)[i]; }

inline const Int & VecInt::operator()(Long_I i) const
{ return (*this)[i]; }

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
    VecLlong() = default;
    explicit VecLlong(Long_I N);
    VecLlong(const VecLlong &rhs); // copy constructor
    VecLlong & operator=(const VecLlong &rhs) = delete;
    Llong & operator()(Long_I i);
    const Llong & operator()(Long_I i) const;
    void operator<<(VecLlong &rhs); // move data and rhs.resize(0)
};

inline VecLlong::VecLlong(Long_I N) : Base(N) {}

inline VecLlong::VecLlong(const VecLlong &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Llong & VecLlong::operator()(Long_I i)
{ return (*this)[i]; }

inline const Llong & VecLlong::operator()(Long_I i) const
{ return (*this)[i]; }

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
    VecFloat() = default;
    explicit VecFloat(Long_I N);
    VecFloat(const VecFloat &rhs); // copy constructor
    VecFloat & operator=(const VecFloat &rhs) = delete;
    Float & operator()(Long_I i);
    const Float & operator()(Long_I i) const;
    void operator<<(VecFloat &rhs); // move data and rhs.resize(0)
};

inline VecFloat::VecFloat(Long_I N) : Base(N) {}

inline VecFloat::VecFloat(const VecFloat &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Float & VecFloat::operator()(Long_I i)
{ return (*this)[i]; }

inline const Float & VecFloat::operator()(Long_I i) const
{ return (*this)[i]; }

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
    VecDoub() = default;
    explicit VecDoub(Long_I N);
    VecDoub(const VecDoub &rhs); // copy constructor
    VecDoub & operator=(const VecDoub &rhs) = delete;
    Doub & operator()(Long_I i);
    const Doub & operator()(Long_I i) const;
    void operator<<(VecDoub &rhs); // move data and rhs.resize(0)
};

inline VecDoub::VecDoub(Long_I N) : Base(N) {}

inline VecDoub::VecDoub(const VecDoub &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Doub & VecDoub::operator()(Long_I i)
{ return (*this)[i]; }

inline const Doub & VecDoub::operator()(Long_I i) const
{ return (*this)[i]; }

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
    VecComp() = default;
    explicit VecComp(Long_I N);
    VecComp(const VecComp &rhs); // copy constructor
    VecComp & operator=(const VecComp &rhs) = delete;
    Comp & operator()(Long_I i);
    const Comp & operator()(Long_I i) const;
    void operator<<(VecComp &rhs); // move data and rhs.resize(0)
};

inline VecComp::VecComp(Long_I N) : Base(N) {}

inline VecComp::VecComp(const VecComp &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Comp & VecComp::operator()(Long_I i)
{ return (*this)[i]; }

inline const Comp & VecComp::operator()(Long_I i) const
{ return (*this)[i]; }

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

    VecBool() = default;
    explicit VecBool(Long_I N);
    VecBool(const VecBool &rhs); // copy constructor
    VecBool & operator=(const VecBool &rhs) = delete;
    ref operator()(Long_I i);
    Bool operator()(Long_I i) const;
    void operator<<(VecBool &rhs); // move data and rhs.resize(0)
};

inline VecBool::VecBool(Long_I N) : Base(N) {}

inline VecBool::VecBool(const VecBool &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline VbaseBool::ref VecBool::operator()(Long_I i)
{ return m_v[i]; }

inline Bool VecBool::operator()(Long_I i) const
{ return m_v[i]; }

inline void VecBool::operator<<(VecBool &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecBool & VecBool_I;
typedef VecBool & VecBool_O, & VecBool_IO;

} // namespace slisc
