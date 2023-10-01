// vector container
#pragma once
#include "../dense/Vbase.h"

namespace slisc {
class VecBool : public VbaseBool {
protected:
	typedef VbaseBool Base;
public:
	using VbaseBool::VbaseBool;
	VecBool() = default;
	explicit VecBool(Long_I N) : Base(N) {}
	VecBool(const VecBool &rhs) = default;
	VecBool(VecBool &&) = default;
	VecBool &operator=(const VecBool &) = default;
	VecBool &operator=(VecBool &&) = default;
	operator const SvecBoolC&() const;
	operator const SvecBool&();
};

inline VecBool::operator const SvecBoolC&() const {
	return reinterpret_cast<const SvecBoolC&>(*this);
}

inline VecBool::operator const SvecBool&() {
	return reinterpret_cast<const SvecBool&>(*this);
}

typedef const VecBool &VecBool_I;
typedef VecBool &VecBool_O, &VecBool_IO;

class VecChar : public VbaseChar {
protected:
	typedef VbaseChar Base;
public:
	using VbaseChar::VbaseChar;
	VecChar() = default;
	explicit VecChar(Long_I N) : Base(N) {}
	VecChar(const VecChar &rhs) = default;
	VecChar(VecChar &&) = default;
	VecChar &operator=(const VecChar &) = default;
	VecChar &operator=(VecChar &&) = default;
	operator const SvecCharC&() const;
	operator const SvecChar&();
};

inline VecChar::operator const SvecCharC&() const {
	return reinterpret_cast<const SvecCharC&>(*this);
}

inline VecChar::operator const SvecChar&() {
	return reinterpret_cast<const SvecChar&>(*this);
}

typedef const VecChar &VecChar_I;
typedef VecChar &VecChar_O, &VecChar_IO;

class VecUchar : public VbaseUchar {
protected:
	typedef VbaseUchar Base;
public:
	using VbaseUchar::VbaseUchar;
	VecUchar() = default;
	explicit VecUchar(Long_I N) : Base(N) {}
	VecUchar(const VecUchar &rhs) = default;
	VecUchar(VecUchar &&) = default;
	VecUchar &operator=(const VecUchar &) = default;
	VecUchar &operator=(VecUchar &&) = default;
	operator const SvecUcharC&() const;
	operator const SvecUchar&();
};

inline VecUchar::operator const SvecUcharC&() const {
	return reinterpret_cast<const SvecUcharC&>(*this);
}

inline VecUchar::operator const SvecUchar&() {
	return reinterpret_cast<const SvecUchar&>(*this);
}

typedef const VecUchar &VecUchar_I;
typedef VecUchar &VecUchar_O, &VecUchar_IO;

class VecInt : public VbaseInt {
protected:
	typedef VbaseInt Base;
public:
	using VbaseInt::VbaseInt;
	VecInt() = default;
	explicit VecInt(Long_I N) : Base(N) {}
	VecInt(const VecInt &rhs) = default;
	VecInt(VecInt &&) = default;
	VecInt &operator=(const VecInt &) = default;
	VecInt &operator=(VecInt &&) = default;
	operator const SvecIntC&() const;
	operator const SvecInt&();
};

inline VecInt::operator const SvecIntC&() const {
	return reinterpret_cast<const SvecIntC&>(*this);
}

inline VecInt::operator const SvecInt&() {
	return reinterpret_cast<const SvecInt&>(*this);
}

typedef const VecInt &VecInt_I;
typedef VecInt &VecInt_O, &VecInt_IO;

class VecLlong : public VbaseLlong {
protected:
	typedef VbaseLlong Base;
public:
	using VbaseLlong::VbaseLlong;
	VecLlong() = default;
	explicit VecLlong(Long_I N) : Base(N) {}
	VecLlong(const VecLlong &rhs) = default;
	VecLlong(VecLlong &&) = default;
	VecLlong &operator=(const VecLlong &) = default;
	VecLlong &operator=(VecLlong &&) = default;
	operator const SvecLlongC&() const;
	operator const SvecLlong&();
};

inline VecLlong::operator const SvecLlongC&() const {
	return reinterpret_cast<const SvecLlongC&>(*this);
}

inline VecLlong::operator const SvecLlong&() {
	return reinterpret_cast<const SvecLlong&>(*this);
}

typedef const VecLlong &VecLlong_I;
typedef VecLlong &VecLlong_O, &VecLlong_IO;

class VecFloat : public VbaseFloat {
protected:
	typedef VbaseFloat Base;
public:
	using VbaseFloat::VbaseFloat;
	VecFloat() = default;
	explicit VecFloat(Long_I N) : Base(N) {}
	VecFloat(const VecFloat &rhs) = default;
	VecFloat(VecFloat &&) = default;
	VecFloat &operator=(const VecFloat &) = default;
	VecFloat &operator=(VecFloat &&) = default;
	operator const SvecFloatC&() const;
	operator const SvecFloat&();
};

inline VecFloat::operator const SvecFloatC&() const {
	return reinterpret_cast<const SvecFloatC&>(*this);
}

inline VecFloat::operator const SvecFloat&() {
	return reinterpret_cast<const SvecFloat&>(*this);
}

typedef const VecFloat &VecFloat_I;
typedef VecFloat &VecFloat_O, &VecFloat_IO;

class VecDoub : public VbaseDoub {
protected:
	typedef VbaseDoub Base;
public:
	using VbaseDoub::VbaseDoub;
	VecDoub() = default;
	explicit VecDoub(Long_I N) : Base(N) {}
	VecDoub(const VecDoub &rhs) = default;
	VecDoub(VecDoub &&) = default;
	VecDoub &operator=(const VecDoub &) = default;
	VecDoub &operator=(VecDoub &&) = default;
	operator const SvecDoubC&() const;
	operator const SvecDoub&();
};

inline VecDoub::operator const SvecDoubC&() const {
	return reinterpret_cast<const SvecDoubC&>(*this);
}

inline VecDoub::operator const SvecDoub&() {
	return reinterpret_cast<const SvecDoub&>(*this);
}

typedef const VecDoub &VecDoub_I;
typedef VecDoub &VecDoub_O, &VecDoub_IO;

class VecLdoub : public VbaseLdoub {
protected:
	typedef VbaseLdoub Base;
public:
	using VbaseLdoub::VbaseLdoub;
	VecLdoub() = default;
	explicit VecLdoub(Long_I N) : Base(N) {}
	VecLdoub(const VecLdoub &rhs) = default;
	VecLdoub(VecLdoub &&) = default;
	VecLdoub &operator=(const VecLdoub &) = default;
	VecLdoub &operator=(VecLdoub &&) = default;
	operator const SvecLdoubC&() const;
	operator const SvecLdoub&();
};

inline VecLdoub::operator const SvecLdoubC&() const {
	return reinterpret_cast<const SvecLdoubC&>(*this);
}

inline VecLdoub::operator const SvecLdoub&() {
	return reinterpret_cast<const SvecLdoub&>(*this);
}

typedef const VecLdoub &VecLdoub_I;
typedef VecLdoub &VecLdoub_O, &VecLdoub_IO;


class VecFcomp : public VbaseFcomp {
protected:
	typedef VbaseFcomp Base;
public:
	using VbaseFcomp::VbaseFcomp;
	VecFcomp() = default;
	explicit VecFcomp(Long_I N) : Base(N) {}
	VecFcomp(const VecFcomp &rhs) = default;
	VecFcomp(VecFcomp &&) = default;
	VecFcomp &operator=(const VecFcomp &) = default;
	VecFcomp &operator=(VecFcomp &&) = default;
	operator const SvecFcompC&() const;
	operator const SvecFcomp&();
};

inline VecFcomp::operator const SvecFcompC&() const {
	return reinterpret_cast<const SvecFcompC&>(*this);
}

inline VecFcomp::operator const SvecFcomp&() {
	return reinterpret_cast<const SvecFcomp&>(*this);
}

typedef const VecFcomp &VecFcomp_I;
typedef VecFcomp &VecFcomp_O, &VecFcomp_IO;

class VecComp : public VbaseComp {
protected:
	typedef VbaseComp Base;
public:
	using VbaseComp::VbaseComp;
	VecComp() = default;
	explicit VecComp(Long_I N) : Base(N) {}
	VecComp(const VecComp &rhs) = default;
	VecComp(VecComp &&) = default;
	VecComp &operator=(const VecComp &) = default;
	VecComp &operator=(VecComp &&) = default;
	operator const SvecCompC&() const;
	operator const SvecComp&();
};

inline VecComp::operator const SvecCompC&() const {
	return reinterpret_cast<const SvecCompC&>(*this);
}

inline VecComp::operator const SvecComp&() {
	return reinterpret_cast<const SvecComp&>(*this);
}

typedef const VecComp &VecComp_I;
typedef VecComp &VecComp_O, &VecComp_IO;

class VecLcomp : public VbaseLcomp {
protected:
	typedef VbaseLcomp Base;
public:
	using VbaseLcomp::VbaseLcomp;
	VecLcomp() = default;
	explicit VecLcomp(Long_I N) : Base(N) {}
	VecLcomp(const VecLcomp &rhs) = default;
	VecLcomp(VecLcomp &&) = default;
	VecLcomp &operator=(const VecLcomp &) = default;
	VecLcomp &operator=(VecLcomp &&) = default;
	operator const SvecLcompC&() const;
	operator const SvecLcomp&();
};

inline VecLcomp::operator const SvecLcompC&() const {
	return reinterpret_cast<const SvecLcompC&>(*this);
}

inline VecLcomp::operator const SvecLcomp&() {
	return reinterpret_cast<const SvecLcomp&>(*this);
}

typedef const VecLcomp &VecLcomp_I;
typedef VecLcomp &VecLcomp_O, &VecLcomp_IO;


class VecFimag : public VbaseFimag {
protected:
	typedef VbaseFimag Base;
public:
	using VbaseFimag::VbaseFimag;
	VecFimag() = default;
	explicit VecFimag(Long_I N) : Base(N) {}
	VecFimag(const VecFimag &rhs) = default;
	VecFimag(VecFimag &&) = default;
	VecFimag &operator=(const VecFimag &) = default;
	VecFimag &operator=(VecFimag &&) = default;
	operator const SvecFimagC&() const;
	operator const SvecFimag&();
};

inline VecFimag::operator const SvecFimagC&() const {
	return reinterpret_cast<const SvecFimagC&>(*this);
}

inline VecFimag::operator const SvecFimag&() {
	return reinterpret_cast<const SvecFimag&>(*this);
}

typedef const VecFimag &VecFimag_I;
typedef VecFimag &VecFimag_O, &VecFimag_IO;

class VecImag : public VbaseImag {
protected:
	typedef VbaseImag Base;
public:
	using VbaseImag::VbaseImag;
	VecImag() = default;
	explicit VecImag(Long_I N) : Base(N) {}
	VecImag(const VecImag &rhs) = default;
	VecImag(VecImag &&) = default;
	VecImag &operator=(const VecImag &) = default;
	VecImag &operator=(VecImag &&) = default;
	operator const SvecImagC&() const;
	operator const SvecImag&();
};

inline VecImag::operator const SvecImagC&() const {
	return reinterpret_cast<const SvecImagC&>(*this);
}

inline VecImag::operator const SvecImag&() {
	return reinterpret_cast<const SvecImag&>(*this);
}

typedef const VecImag &VecImag_I;
typedef VecImag &VecImag_O, &VecImag_IO;

class VecLimag : public VbaseLimag {
protected:
	typedef VbaseLimag Base;
public:
	using VbaseLimag::VbaseLimag;
	VecLimag() = default;
	explicit VecLimag(Long_I N) : Base(N) {}
	VecLimag(const VecLimag &rhs) = default;
	VecLimag(VecLimag &&) = default;
	VecLimag &operator=(const VecLimag &) = default;
	VecLimag &operator=(VecLimag &&) = default;
	operator const SvecLimagC&() const;
	operator const SvecLimag&();
};

inline VecLimag::operator const SvecLimagC&() const {
	return reinterpret_cast<const SvecLimagC&>(*this);
}

inline VecLimag::operator const SvecLimag&() {
	return reinterpret_cast<const SvecLimag&>(*this);
}

typedef const VecLimag &VecLimag_I;
typedef VecLimag &VecLimag_O, &VecLimag_IO;



#ifdef SLS_USE_INT_AS_LONG
typedef VecInt VecLong;
#else
typedef VecLlong VecLong;
#endif
typedef const VecLong &VecLong_I;
typedef VecLong &VecLong_O, &VecLong_IO;

} // namespace slisc
