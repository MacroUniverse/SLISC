// vector container
#pragma once
#include "../dense/Vbase.h"

namespace slisc {
class VecChar : public VbaseChar
{
public:
	typedef VbaseChar Base;
	VecChar() = default;
	explicit VecChar(Long_I N);
	VecChar(const VecChar &rhs); // copy constructor
	VecChar &operator=(const VecChar &rhs) = delete;
	void operator<<(VecChar &rhs); // move data and rhs.resize(0)
};

inline VecChar::VecChar(Long_I N) : Base(N) {}

inline VecChar::VecChar(const VecChar &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecChar::operator<<(VecChar &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecChar &VecChar_I;
typedef VecChar &VecChar_O, &VecChar_IO;

// common api for STL and SLISC
inline Long size(VecChar_I v) { return v.size(); }

inline const Char *p(VecChar_I v) { return v.p(); }

inline Char *p(VecChar &v) { return v.p(); }


class VecUchar : public VbaseUchar
{
public:
	typedef VbaseUchar Base;
	VecUchar() = default;
	explicit VecUchar(Long_I N);
	VecUchar(const VecUchar &rhs); // copy constructor
	VecUchar &operator=(const VecUchar &rhs) = delete;
	void operator<<(VecUchar &rhs); // move data and rhs.resize(0)
};

inline VecUchar::VecUchar(Long_I N) : Base(N) {}

inline VecUchar::VecUchar(const VecUchar &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecUchar::operator<<(VecUchar &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecUchar &VecUchar_I;
typedef VecUchar &VecUchar_O, &VecUchar_IO;

// common api for STL and SLISC
inline Long size(VecUchar_I v) { return v.size(); }

inline const Uchar *p(VecUchar_I v) { return v.p(); }

inline Uchar *p(VecUchar &v) { return v.p(); }


class VecInt : public VbaseInt
{
public:
	typedef VbaseInt Base;
	VecInt() = default;
	explicit VecInt(Long_I N);
	VecInt(const VecInt &rhs); // copy constructor
	VecInt &operator=(const VecInt &rhs) = delete;
	void operator<<(VecInt &rhs); // move data and rhs.resize(0)
};

inline VecInt::VecInt(Long_I N) : Base(N) {}

inline VecInt::VecInt(const VecInt &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecInt::operator<<(VecInt &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecInt &VecInt_I;
typedef VecInt &VecInt_O, &VecInt_IO;

// common api for STL and SLISC
inline Long size(VecInt_I v) { return v.size(); }

inline const Int *p(VecInt_I v) { return v.p(); }

inline Int *p(VecInt &v) { return v.p(); }


class VecLlong : public VbaseLlong
{
public:
	typedef VbaseLlong Base;
	VecLlong() = default;
	explicit VecLlong(Long_I N);
	VecLlong(const VecLlong &rhs); // copy constructor
	VecLlong &operator=(const VecLlong &rhs) = delete;
	void operator<<(VecLlong &rhs); // move data and rhs.resize(0)
};

inline VecLlong::VecLlong(Long_I N) : Base(N) {}

inline VecLlong::VecLlong(const VecLlong &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecLlong::operator<<(VecLlong &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecLlong &VecLlong_I;
typedef VecLlong &VecLlong_O, &VecLlong_IO;

// common api for STL and SLISC
inline Long size(VecLlong_I v) { return v.size(); }

inline const Llong *p(VecLlong_I v) { return v.p(); }

inline Llong *p(VecLlong &v) { return v.p(); }


class VecFloat : public VbaseFloat
{
public:
	typedef VbaseFloat Base;
	VecFloat() = default;
	explicit VecFloat(Long_I N);
	VecFloat(const VecFloat &rhs); // copy constructor
	VecFloat &operator=(const VecFloat &rhs) = delete;
	void operator<<(VecFloat &rhs); // move data and rhs.resize(0)
};

inline VecFloat::VecFloat(Long_I N) : Base(N) {}

inline VecFloat::VecFloat(const VecFloat &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecFloat::operator<<(VecFloat &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecFloat &VecFloat_I;
typedef VecFloat &VecFloat_O, &VecFloat_IO;

// common api for STL and SLISC
inline Long size(VecFloat_I v) { return v.size(); }

inline const Float *p(VecFloat_I v) { return v.p(); }

inline Float *p(VecFloat &v) { return v.p(); }


class VecDoub : public VbaseDoub
{
public:
	typedef VbaseDoub Base;
	VecDoub() = default;
	explicit VecDoub(Long_I N);
	VecDoub(const VecDoub &rhs); // copy constructor
	VecDoub &operator=(const VecDoub &rhs) = delete;
	void operator<<(VecDoub &rhs); // move data and rhs.resize(0)
};

inline VecDoub::VecDoub(Long_I N) : Base(N) {}

inline VecDoub::VecDoub(const VecDoub &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecDoub::operator<<(VecDoub &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecDoub &VecDoub_I;
typedef VecDoub &VecDoub_O, &VecDoub_IO;

// common api for STL and SLISC
inline Long size(VecDoub_I v) { return v.size(); }

inline const Doub *p(VecDoub_I v) { return v.p(); }

inline Doub *p(VecDoub &v) { return v.p(); }


class VecLdoub : public VbaseLdoub
{
public:
	typedef VbaseLdoub Base;
	VecLdoub() = default;
	explicit VecLdoub(Long_I N);
	VecLdoub(const VecLdoub &rhs); // copy constructor
	VecLdoub &operator=(const VecLdoub &rhs) = delete;
	void operator<<(VecLdoub &rhs); // move data and rhs.resize(0)
};

inline VecLdoub::VecLdoub(Long_I N) : Base(N) {}

inline VecLdoub::VecLdoub(const VecLdoub &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecLdoub::operator<<(VecLdoub &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecLdoub &VecLdoub_I;
typedef VecLdoub &VecLdoub_O, &VecLdoub_IO;

// common api for STL and SLISC
inline Long size(VecLdoub_I v) { return v.size(); }

inline const Ldoub *p(VecLdoub_I v) { return v.p(); }

inline Ldoub *p(VecLdoub &v) { return v.p(); }



class VecFcomp : public VbaseFcomp
{
public:
	typedef VbaseFcomp Base;
	VecFcomp() = default;
	explicit VecFcomp(Long_I N);
	VecFcomp(const VecFcomp &rhs); // copy constructor
	VecFcomp &operator=(const VecFcomp &rhs) = delete;
	void operator<<(VecFcomp &rhs); // move data and rhs.resize(0)
};

inline VecFcomp::VecFcomp(Long_I N) : Base(N) {}

inline VecFcomp::VecFcomp(const VecFcomp &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecFcomp::operator<<(VecFcomp &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecFcomp &VecFcomp_I;
typedef VecFcomp &VecFcomp_O, &VecFcomp_IO;

// common api for STL and SLISC
inline Long size(VecFcomp_I v) { return v.size(); }

inline const Fcomp *p(VecFcomp_I v) { return v.p(); }

inline Fcomp *p(VecFcomp &v) { return v.p(); }


class VecComp : public VbaseComp
{
public:
	typedef VbaseComp Base;
	VecComp() = default;
	explicit VecComp(Long_I N);
	VecComp(const VecComp &rhs); // copy constructor
	VecComp &operator=(const VecComp &rhs) = delete;
	void operator<<(VecComp &rhs); // move data and rhs.resize(0)
};

inline VecComp::VecComp(Long_I N) : Base(N) {}

inline VecComp::VecComp(const VecComp &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecComp::operator<<(VecComp &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecComp &VecComp_I;
typedef VecComp &VecComp_O, &VecComp_IO;

// common api for STL and SLISC
inline Long size(VecComp_I v) { return v.size(); }

inline const Comp *p(VecComp_I v) { return v.p(); }

inline Comp *p(VecComp &v) { return v.p(); }


class VecLcomp : public VbaseLcomp
{
public:
	typedef VbaseLcomp Base;
	VecLcomp() = default;
	explicit VecLcomp(Long_I N);
	VecLcomp(const VecLcomp &rhs); // copy constructor
	VecLcomp &operator=(const VecLcomp &rhs) = delete;
	void operator<<(VecLcomp &rhs); // move data and rhs.resize(0)
};

inline VecLcomp::VecLcomp(Long_I N) : Base(N) {}

inline VecLcomp::VecLcomp(const VecLcomp &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecLcomp::operator<<(VecLcomp &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecLcomp &VecLcomp_I;
typedef VecLcomp &VecLcomp_O, &VecLcomp_IO;

// common api for STL and SLISC
inline Long size(VecLcomp_I v) { return v.size(); }

inline const Lcomp *p(VecLcomp_I v) { return v.p(); }

inline Lcomp *p(VecLcomp &v) { return v.p(); }



class VecFimag : public VbaseFimag
{
public:
	typedef VbaseFimag Base;
	VecFimag() = default;
	explicit VecFimag(Long_I N);
	VecFimag(const VecFimag &rhs); // copy constructor
	VecFimag &operator=(const VecFimag &rhs) = delete;
	void operator<<(VecFimag &rhs); // move data and rhs.resize(0)
};

inline VecFimag::VecFimag(Long_I N) : Base(N) {}

inline VecFimag::VecFimag(const VecFimag &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecFimag::operator<<(VecFimag &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecFimag &VecFimag_I;
typedef VecFimag &VecFimag_O, &VecFimag_IO;

// common api for STL and SLISC
inline Long size(VecFimag_I v) { return v.size(); }

inline const Fimag *p(VecFimag_I v) { return v.p(); }

inline Fimag *p(VecFimag &v) { return v.p(); }


class VecImag : public VbaseImag
{
public:
	typedef VbaseImag Base;
	VecImag() = default;
	explicit VecImag(Long_I N);
	VecImag(const VecImag &rhs); // copy constructor
	VecImag &operator=(const VecImag &rhs) = delete;
	void operator<<(VecImag &rhs); // move data and rhs.resize(0)
};

inline VecImag::VecImag(Long_I N) : Base(N) {}

inline VecImag::VecImag(const VecImag &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecImag::operator<<(VecImag &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecImag &VecImag_I;
typedef VecImag &VecImag_O, &VecImag_IO;

// common api for STL and SLISC
inline Long size(VecImag_I v) { return v.size(); }

inline const Imag *p(VecImag_I v) { return v.p(); }

inline Imag *p(VecImag &v) { return v.p(); }


class VecLimag : public VbaseLimag
{
public:
	typedef VbaseLimag Base;
	VecLimag() = default;
	explicit VecLimag(Long_I N);
	VecLimag(const VecLimag &rhs); // copy constructor
	VecLimag &operator=(const VecLimag &rhs) = delete;
	void operator<<(VecLimag &rhs); // move data and rhs.resize(0)
};

inline VecLimag::VecLimag(Long_I N) : Base(N) {}

inline VecLimag::VecLimag(const VecLimag &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecLimag::operator<<(VecLimag &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecLimag &VecLimag_I;
typedef VecLimag &VecLimag_O, &VecLimag_IO;

// common api for STL and SLISC
inline Long size(VecLimag_I v) { return v.size(); }

inline const Limag *p(VecLimag_I v) { return v.p(); }

inline Limag *p(VecLimag &v) { return v.p(); }



#ifdef SLS_USE_INT_AS_LONG
typedef VecInt VecLong;
#else
typedef VecLlong VecLong;
#endif
typedef const VecLong &VecLong_I;
typedef VecLong &VecLong_O, &VecLong_IO;

// implemented with vector<bool>, not actually a vector of bool
class VecBool : public VbaseBool
{
public:
	typedef VbaseBool Base;
	using Base::ref; // bit reference

	VecBool() = default;
	explicit VecBool(Long_I N);
	VecBool(const VecBool &rhs); // copy constructor
	VecBool &operator=(const VecBool &rhs) = delete;
	void operator<<(VecBool &rhs); // move data and rhs.resize(0)
};

inline VecBool::VecBool(Long_I N) : Base(N) {}

inline VecBool::VecBool(const VecBool &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline void VecBool::operator<<(VecBool &rhs)
{
	Base::operator<<(rhs);
}

typedef const VecBool &VecBool_I;
typedef VecBool &VecBool_O, &VecBool_IO;

// common api for STL and SLISC
inline Long size(VecBool_I v) { return v.size(); }

} // namespace slisc
