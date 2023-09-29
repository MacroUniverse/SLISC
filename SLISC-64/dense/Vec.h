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
	VecChar(VecChar &&rhs); // move constructor
	VecChar &operator=(const VecChar &); // copy asignment
	VecChar &operator=(VecChar &&); // move asignment
};

inline VecChar::VecChar(Long_I N) : Base(N) {}

inline VecChar::VecChar(const VecChar &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecChar::VecChar(VecChar &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecChar &VecChar::operator=(const VecChar &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecChar &VecChar::operator=(VecChar &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecChar &VecChar_I;
typedef VecChar &VecChar_O, &VecChar_IO;

class VecUchar : public VbaseUchar
{
public:
	typedef VbaseUchar Base;
	VecUchar() = default;
	explicit VecUchar(Long_I N);
	VecUchar(const VecUchar &rhs); // copy constructor
	VecUchar(VecUchar &&rhs); // move constructor
	VecUchar &operator=(const VecUchar &); // copy asignment
	VecUchar &operator=(VecUchar &&); // move asignment
};

inline VecUchar::VecUchar(Long_I N) : Base(N) {}

inline VecUchar::VecUchar(const VecUchar &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecUchar::VecUchar(VecUchar &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecUchar &VecUchar::operator=(const VecUchar &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecUchar &VecUchar::operator=(VecUchar &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecUchar &VecUchar_I;
typedef VecUchar &VecUchar_O, &VecUchar_IO;

class VecInt : public VbaseInt
{
public:
	typedef VbaseInt Base;
	VecInt() = default;
	explicit VecInt(Long_I N);
	VecInt(const VecInt &rhs); // copy constructor
	VecInt(VecInt &&rhs); // move constructor
	VecInt &operator=(const VecInt &); // copy asignment
	VecInt &operator=(VecInt &&); // move asignment
};

inline VecInt::VecInt(Long_I N) : Base(N) {}

inline VecInt::VecInt(const VecInt &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecInt::VecInt(VecInt &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecInt &VecInt::operator=(const VecInt &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecInt &VecInt::operator=(VecInt &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecInt &VecInt_I;
typedef VecInt &VecInt_O, &VecInt_IO;

class VecLlong : public VbaseLlong
{
public:
	typedef VbaseLlong Base;
	VecLlong() = default;
	explicit VecLlong(Long_I N);
	VecLlong(const VecLlong &rhs); // copy constructor
	VecLlong(VecLlong &&rhs); // move constructor
	VecLlong &operator=(const VecLlong &); // copy asignment
	VecLlong &operator=(VecLlong &&); // move asignment
};

inline VecLlong::VecLlong(Long_I N) : Base(N) {}

inline VecLlong::VecLlong(const VecLlong &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecLlong::VecLlong(VecLlong &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecLlong &VecLlong::operator=(const VecLlong &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecLlong &VecLlong::operator=(VecLlong &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecLlong &VecLlong_I;
typedef VecLlong &VecLlong_O, &VecLlong_IO;

class VecFloat : public VbaseFloat
{
public:
	typedef VbaseFloat Base;
	VecFloat() = default;
	explicit VecFloat(Long_I N);
	VecFloat(const VecFloat &rhs); // copy constructor
	VecFloat(VecFloat &&rhs); // move constructor
	VecFloat &operator=(const VecFloat &); // copy asignment
	VecFloat &operator=(VecFloat &&); // move asignment
};

inline VecFloat::VecFloat(Long_I N) : Base(N) {}

inline VecFloat::VecFloat(const VecFloat &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecFloat::VecFloat(VecFloat &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecFloat &VecFloat::operator=(const VecFloat &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecFloat &VecFloat::operator=(VecFloat &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecFloat &VecFloat_I;
typedef VecFloat &VecFloat_O, &VecFloat_IO;

class VecDoub : public VbaseDoub
{
public:
	typedef VbaseDoub Base;
	VecDoub() = default;
	explicit VecDoub(Long_I N);
	VecDoub(const VecDoub &rhs); // copy constructor
	VecDoub(VecDoub &&rhs); // move constructor
	VecDoub &operator=(const VecDoub &); // copy asignment
	VecDoub &operator=(VecDoub &&); // move asignment
};

inline VecDoub::VecDoub(Long_I N) : Base(N) {}

inline VecDoub::VecDoub(const VecDoub &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecDoub::VecDoub(VecDoub &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecDoub &VecDoub::operator=(const VecDoub &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecDoub &VecDoub::operator=(VecDoub &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecDoub &VecDoub_I;
typedef VecDoub &VecDoub_O, &VecDoub_IO;

class VecLdoub : public VbaseLdoub
{
public:
	typedef VbaseLdoub Base;
	VecLdoub() = default;
	explicit VecLdoub(Long_I N);
	VecLdoub(const VecLdoub &rhs); // copy constructor
	VecLdoub(VecLdoub &&rhs); // move constructor
	VecLdoub &operator=(const VecLdoub &); // copy asignment
	VecLdoub &operator=(VecLdoub &&); // move asignment
};

inline VecLdoub::VecLdoub(Long_I N) : Base(N) {}

inline VecLdoub::VecLdoub(const VecLdoub &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecLdoub::VecLdoub(VecLdoub &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecLdoub &VecLdoub::operator=(const VecLdoub &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecLdoub &VecLdoub::operator=(VecLdoub &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecLdoub &VecLdoub_I;
typedef VecLdoub &VecLdoub_O, &VecLdoub_IO;


class VecFcomp : public VbaseFcomp
{
public:
	typedef VbaseFcomp Base;
	VecFcomp() = default;
	explicit VecFcomp(Long_I N);
	VecFcomp(const VecFcomp &rhs); // copy constructor
	VecFcomp(VecFcomp &&rhs); // move constructor
	VecFcomp &operator=(const VecFcomp &); // copy asignment
	VecFcomp &operator=(VecFcomp &&); // move asignment
};

inline VecFcomp::VecFcomp(Long_I N) : Base(N) {}

inline VecFcomp::VecFcomp(const VecFcomp &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecFcomp::VecFcomp(VecFcomp &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecFcomp &VecFcomp::operator=(const VecFcomp &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecFcomp &VecFcomp::operator=(VecFcomp &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecFcomp &VecFcomp_I;
typedef VecFcomp &VecFcomp_O, &VecFcomp_IO;

class VecComp : public VbaseComp
{
public:
	typedef VbaseComp Base;
	VecComp() = default;
	explicit VecComp(Long_I N);
	VecComp(const VecComp &rhs); // copy constructor
	VecComp(VecComp &&rhs); // move constructor
	VecComp &operator=(const VecComp &); // copy asignment
	VecComp &operator=(VecComp &&); // move asignment
};

inline VecComp::VecComp(Long_I N) : Base(N) {}

inline VecComp::VecComp(const VecComp &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecComp::VecComp(VecComp &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecComp &VecComp::operator=(const VecComp &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecComp &VecComp::operator=(VecComp &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecComp &VecComp_I;
typedef VecComp &VecComp_O, &VecComp_IO;

class VecLcomp : public VbaseLcomp
{
public:
	typedef VbaseLcomp Base;
	VecLcomp() = default;
	explicit VecLcomp(Long_I N);
	VecLcomp(const VecLcomp &rhs); // copy constructor
	VecLcomp(VecLcomp &&rhs); // move constructor
	VecLcomp &operator=(const VecLcomp &); // copy asignment
	VecLcomp &operator=(VecLcomp &&); // move asignment
};

inline VecLcomp::VecLcomp(Long_I N) : Base(N) {}

inline VecLcomp::VecLcomp(const VecLcomp &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecLcomp::VecLcomp(VecLcomp &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecLcomp &VecLcomp::operator=(const VecLcomp &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecLcomp &VecLcomp::operator=(VecLcomp &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecLcomp &VecLcomp_I;
typedef VecLcomp &VecLcomp_O, &VecLcomp_IO;


class VecFimag : public VbaseFimag
{
public:
	typedef VbaseFimag Base;
	VecFimag() = default;
	explicit VecFimag(Long_I N);
	VecFimag(const VecFimag &rhs); // copy constructor
	VecFimag(VecFimag &&rhs); // move constructor
	VecFimag &operator=(const VecFimag &); // copy asignment
	VecFimag &operator=(VecFimag &&); // move asignment
};

inline VecFimag::VecFimag(Long_I N) : Base(N) {}

inline VecFimag::VecFimag(const VecFimag &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecFimag::VecFimag(VecFimag &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecFimag &VecFimag::operator=(const VecFimag &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecFimag &VecFimag::operator=(VecFimag &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecFimag &VecFimag_I;
typedef VecFimag &VecFimag_O, &VecFimag_IO;

class VecImag : public VbaseImag
{
public:
	typedef VbaseImag Base;
	VecImag() = default;
	explicit VecImag(Long_I N);
	VecImag(const VecImag &rhs); // copy constructor
	VecImag(VecImag &&rhs); // move constructor
	VecImag &operator=(const VecImag &); // copy asignment
	VecImag &operator=(VecImag &&); // move asignment
};

inline VecImag::VecImag(Long_I N) : Base(N) {}

inline VecImag::VecImag(const VecImag &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecImag::VecImag(VecImag &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecImag &VecImag::operator=(const VecImag &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecImag &VecImag::operator=(VecImag &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecImag &VecImag_I;
typedef VecImag &VecImag_O, &VecImag_IO;

class VecLimag : public VbaseLimag
{
public:
	typedef VbaseLimag Base;
	VecLimag() = default;
	explicit VecLimag(Long_I N);
	VecLimag(const VecLimag &rhs); // copy constructor
	VecLimag(VecLimag &&rhs); // move constructor
	VecLimag &operator=(const VecLimag &); // copy asignment
	VecLimag &operator=(VecLimag &&); // move asignment
};

inline VecLimag::VecLimag(Long_I N) : Base(N) {}

inline VecLimag::VecLimag(const VecLimag &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

inline VecLimag::VecLimag(VecLimag &&rhs) : Base(move(rhs))
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("move constructor forbidden!");
#endif
}

inline VecLimag &VecLimag::operator=(const VecLimag &rhs) {
	Base::operator=(rhs);
	return *this;
};

inline VecLimag &VecLimag::operator=(VecLimag &&rhs) {
	Base::operator=(move(rhs));
	return *this;
};

typedef const VecLimag &VecLimag_I;
typedef VecLimag &VecLimag_O, &VecLimag_IO;



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
	// move constructor is inherited
	using Base::operator=;
};

inline VecBool::VecBool(Long_I N) : Base(N) {}

inline VecBool::VecBool(const VecBool &rhs) : Base(rhs)
{
#ifdef SLS_NO_CPY_CONSTRUCTOR
	SLS_ERR("copy constructor forbidden!");
#endif
}

typedef const VecBool &VecBool_I;
typedef VecBool &VecBool_O, &VecBool_IO;

// common api for STL and SLISC
inline Long size(VecBool_I v) { return v.size(); }

} // namespace slisc
