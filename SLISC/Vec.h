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

class VecLdoub : public VbaseLdoub
{
public:
    typedef VbaseLdoub Base;
    VecLdoub() = default;
    explicit VecLdoub(Long_I N);
    VecLdoub(const VecLdoub &rhs); // copy constructor
    VecLdoub & operator=(const VecLdoub &rhs) = delete;
    Ldoub & operator()(Long_I i);
    const Ldoub & operator()(Long_I i) const;
    void operator<<(VecLdoub &rhs); // move data and rhs.resize(0)
};

inline VecLdoub::VecLdoub(Long_I N) : Base(N) {}

inline VecLdoub::VecLdoub(const VecLdoub &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Ldoub & VecLdoub::operator()(Long_I i)
{ return (*this)[i]; }

inline const Ldoub & VecLdoub::operator()(Long_I i) const
{ return (*this)[i]; }

inline void VecLdoub::operator<<(VecLdoub &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecLdoub & VecLdoub_I;
typedef VecLdoub & VecLdoub_O, & VecLdoub_IO;

class VecFcomp : public VbaseFcomp
{
public:
    typedef VbaseFcomp Base;
    VecFcomp() = default;
    explicit VecFcomp(Long_I N);
    VecFcomp(const VecFcomp &rhs); // copy constructor
    VecFcomp & operator=(const VecFcomp &rhs) = delete;
    Fcomp & operator()(Long_I i);
    const Fcomp & operator()(Long_I i) const;
    void operator<<(VecFcomp &rhs); // move data and rhs.resize(0)
};

inline VecFcomp::VecFcomp(Long_I N) : Base(N) {}

inline VecFcomp::VecFcomp(const VecFcomp &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Fcomp & VecFcomp::operator()(Long_I i)
{ return (*this)[i]; }

inline const Fcomp & VecFcomp::operator()(Long_I i) const
{ return (*this)[i]; }

inline void VecFcomp::operator<<(VecFcomp &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecFcomp & VecFcomp_I;
typedef VecFcomp & VecFcomp_O, & VecFcomp_IO;

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

class VecLcomp : public VbaseLcomp
{
public:
    typedef VbaseLcomp Base;
    VecLcomp() = default;
    explicit VecLcomp(Long_I N);
    VecLcomp(const VecLcomp &rhs); // copy constructor
    VecLcomp & operator=(const VecLcomp &rhs) = delete;
    Lcomp & operator()(Long_I i);
    const Lcomp & operator()(Long_I i) const;
    void operator<<(VecLcomp &rhs); // move data and rhs.resize(0)
};

inline VecLcomp::VecLcomp(Long_I N) : Base(N) {}

inline VecLcomp::VecLcomp(const VecLcomp &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Lcomp & VecLcomp::operator()(Long_I i)
{ return (*this)[i]; }

inline const Lcomp & VecLcomp::operator()(Long_I i) const
{ return (*this)[i]; }

inline void VecLcomp::operator<<(VecLcomp &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecLcomp & VecLcomp_I;
typedef VecLcomp & VecLcomp_O, & VecLcomp_IO;

class VecFimag : public VbaseFimag
{
public:
    typedef VbaseFimag Base;
    VecFimag() = default;
    explicit VecFimag(Long_I N);
    VecFimag(const VecFimag &rhs); // copy constructor
    VecFimag & operator=(const VecFimag &rhs) = delete;
    Fimag & operator()(Long_I i);
    const Fimag & operator()(Long_I i) const;
    void operator<<(VecFimag &rhs); // move data and rhs.resize(0)
};

inline VecFimag::VecFimag(Long_I N) : Base(N) {}

inline VecFimag::VecFimag(const VecFimag &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Fimag & VecFimag::operator()(Long_I i)
{ return (*this)[i]; }

inline const Fimag & VecFimag::operator()(Long_I i) const
{ return (*this)[i]; }

inline void VecFimag::operator<<(VecFimag &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecFimag & VecFimag_I;
typedef VecFimag & VecFimag_O, & VecFimag_IO;

class VecImag : public VbaseImag
{
public:
    typedef VbaseImag Base;
    VecImag() = default;
    explicit VecImag(Long_I N);
    VecImag(const VecImag &rhs); // copy constructor
    VecImag & operator=(const VecImag &rhs) = delete;
    Imag & operator()(Long_I i);
    const Imag & operator()(Long_I i) const;
    void operator<<(VecImag &rhs); // move data and rhs.resize(0)
};

inline VecImag::VecImag(Long_I N) : Base(N) {}

inline VecImag::VecImag(const VecImag &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Imag & VecImag::operator()(Long_I i)
{ return (*this)[i]; }

inline const Imag & VecImag::operator()(Long_I i) const
{ return (*this)[i]; }

inline void VecImag::operator<<(VecImag &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecImag & VecImag_I;
typedef VecImag & VecImag_O, & VecImag_IO;

class VecLimag : public VbaseLimag
{
public:
    typedef VbaseLimag Base;
    VecLimag() = default;
    explicit VecLimag(Long_I N);
    VecLimag(const VecLimag &rhs); // copy constructor
    VecLimag & operator=(const VecLimag &rhs) = delete;
    Limag & operator()(Long_I i);
    const Limag & operator()(Long_I i) const;
    void operator<<(VecLimag &rhs); // move data and rhs.resize(0)
};

inline VecLimag::VecLimag(Long_I N) : Base(N) {}

inline VecLimag::VecLimag(const VecLimag &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
    SLS_ERR("copy constructor forbidden!");
#endif
}

inline Limag & VecLimag::operator()(Long_I i)
{ return (*this)[i]; }

inline const Limag & VecLimag::operator()(Long_I i) const
{ return (*this)[i]; }

inline void VecLimag::operator<<(VecLimag &rhs)
{
    Base::operator<<(rhs);
}

typedef const VecLimag & VecLimag_I;
typedef VecLimag & VecLimag_O, & VecLimag_IO;


// implemented with vector<Bool>, not actually a vector of Bool
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
