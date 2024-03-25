#pragma once
#include "../dense/Svbase.h"

// this class is not memory safe!
// "C" means lower level const

namespace slisc {

class SvecBoolC : public SvbaseBoolC
{
public:
	SvecBoolC() = default;
	explicit SvecBoolC(Long_I N) : SvbaseBoolC(N) {};
	SvecBoolC(const Bool *data, Long_I N) : SvbaseBoolC(data, N) {};
	SvecBoolC(const SvecBoolC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecBoolC &SvecBool_I;


class SvecBool : public SvbaseBool
{
public:
	SvecBool() = default;
	explicit SvecBool(Long_I N) : SvbaseBool(N) {};
	SvecBool(Bool *data, Long_I N) : SvbaseBool(data, N) {};
	SvecBool(const SvecBool &v) = default; // copy constructor (shalow)
	
	operator SvecBoolC() const;
};

inline SvecBool::operator SvecBoolC() const
{
	return *((SvecBoolC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecBool &SvecBool_O, &SvecBool_IO;


class SvecCharC : public SvbaseCharC
{
public:
	SvecCharC() = default;
	explicit SvecCharC(Long_I N) : SvbaseCharC(N) {};
	SvecCharC(const Char *data, Long_I N) : SvbaseCharC(data, N) {};
	SvecCharC(const SvecCharC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecCharC &SvecChar_I;


class SvecChar : public SvbaseChar
{
public:
	SvecChar() = default;
	explicit SvecChar(Long_I N) : SvbaseChar(N) {};
	SvecChar(Char *data, Long_I N) : SvbaseChar(data, N) {};
	SvecChar(const SvecChar &v) = default; // copy constructor (shalow)
	
	operator SvecCharC() const;
};

inline SvecChar::operator SvecCharC() const
{
	return *((SvecCharC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecChar &SvecChar_O, &SvecChar_IO;


class SvecUcharC : public SvbaseUcharC
{
public:
	SvecUcharC() = default;
	explicit SvecUcharC(Long_I N) : SvbaseUcharC(N) {};
	SvecUcharC(const Uchar *data, Long_I N) : SvbaseUcharC(data, N) {};
	SvecUcharC(const SvecUcharC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecUcharC &SvecUchar_I;


class SvecUchar : public SvbaseUchar
{
public:
	SvecUchar() = default;
	explicit SvecUchar(Long_I N) : SvbaseUchar(N) {};
	SvecUchar(Uchar *data, Long_I N) : SvbaseUchar(data, N) {};
	SvecUchar(const SvecUchar &v) = default; // copy constructor (shalow)
	
	operator SvecUcharC() const;
};

inline SvecUchar::operator SvecUcharC() const
{
	return *((SvecUcharC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecUchar &SvecUchar_O, &SvecUchar_IO;


class SvecIntC : public SvbaseIntC
{
public:
	SvecIntC() = default;
	explicit SvecIntC(Long_I N) : SvbaseIntC(N) {};
	SvecIntC(const Int *data, Long_I N) : SvbaseIntC(data, N) {};
	SvecIntC(const SvecIntC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecIntC &SvecInt_I;


class SvecInt : public SvbaseInt
{
public:
	SvecInt() = default;
	explicit SvecInt(Long_I N) : SvbaseInt(N) {};
	SvecInt(Int *data, Long_I N) : SvbaseInt(data, N) {};
	SvecInt(const SvecInt &v) = default; // copy constructor (shalow)
	
	operator SvecIntC() const;
};

inline SvecInt::operator SvecIntC() const
{
	return *((SvecIntC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecInt &SvecInt_O, &SvecInt_IO;


class SvecLlongC : public SvbaseLlongC
{
public:
	SvecLlongC() = default;
	explicit SvecLlongC(Long_I N) : SvbaseLlongC(N) {};
	SvecLlongC(const Llong *data, Long_I N) : SvbaseLlongC(data, N) {};
	SvecLlongC(const SvecLlongC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecLlongC &SvecLlong_I;


class SvecLlong : public SvbaseLlong
{
public:
	SvecLlong() = default;
	explicit SvecLlong(Long_I N) : SvbaseLlong(N) {};
	SvecLlong(Llong *data, Long_I N) : SvbaseLlong(data, N) {};
	SvecLlong(const SvecLlong &v) = default; // copy constructor (shalow)
	
	operator SvecLlongC() const;
};

inline SvecLlong::operator SvecLlongC() const
{
	return *((SvecLlongC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLlong &SvecLlong_O, &SvecLlong_IO;


class SvecFloatC : public SvbaseFloatC
{
public:
	SvecFloatC() = default;
	explicit SvecFloatC(Long_I N) : SvbaseFloatC(N) {};
	SvecFloatC(const Float *data, Long_I N) : SvbaseFloatC(data, N) {};
	SvecFloatC(const SvecFloatC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecFloatC &SvecFloat_I;


class SvecFloat : public SvbaseFloat
{
public:
	SvecFloat() = default;
	explicit SvecFloat(Long_I N) : SvbaseFloat(N) {};
	SvecFloat(Float *data, Long_I N) : SvbaseFloat(data, N) {};
	SvecFloat(const SvecFloat &v) = default; // copy constructor (shalow)
	
	operator SvecFloatC() const;
};

inline SvecFloat::operator SvecFloatC() const
{
	return *((SvecFloatC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecFloat &SvecFloat_O, &SvecFloat_IO;


class SvecDoubC : public SvbaseDoubC
{
public:
	SvecDoubC() = default;
	explicit SvecDoubC(Long_I N) : SvbaseDoubC(N) {};
	SvecDoubC(const Doub *data, Long_I N) : SvbaseDoubC(data, N) {};
	SvecDoubC(const SvecDoubC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecDoubC &SvecDoub_I;


class SvecDoub : public SvbaseDoub
{
public:
	SvecDoub() = default;
	explicit SvecDoub(Long_I N) : SvbaseDoub(N) {};
	SvecDoub(Doub *data, Long_I N) : SvbaseDoub(data, N) {};
	SvecDoub(const SvecDoub &v) = default; // copy constructor (shalow)
	
	operator SvecDoubC() const;
};

inline SvecDoub::operator SvecDoubC() const
{
	return *((SvecDoubC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecDoub &SvecDoub_O, &SvecDoub_IO;


class SvecLdoubC : public SvbaseLdoubC
{
public:
	SvecLdoubC() = default;
	explicit SvecLdoubC(Long_I N) : SvbaseLdoubC(N) {};
	SvecLdoubC(const Ldoub *data, Long_I N) : SvbaseLdoubC(data, N) {};
	SvecLdoubC(const SvecLdoubC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecLdoubC &SvecLdoub_I;


class SvecLdoub : public SvbaseLdoub
{
public:
	SvecLdoub() = default;
	explicit SvecLdoub(Long_I N) : SvbaseLdoub(N) {};
	SvecLdoub(Ldoub *data, Long_I N) : SvbaseLdoub(data, N) {};
	SvecLdoub(const SvecLdoub &v) = default; // copy constructor (shalow)
	
	operator SvecLdoubC() const;
};

inline SvecLdoub::operator SvecLdoubC() const
{
	return *((SvecLdoubC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLdoub &SvecLdoub_O, &SvecLdoub_IO;




class SvecFcompC : public SvbaseFcompC
{
public:
	SvecFcompC() = default;
	explicit SvecFcompC(Long_I N) : SvbaseFcompC(N) {};
	SvecFcompC(const Fcomp *data, Long_I N) : SvbaseFcompC(data, N) {};
	SvecFcompC(const SvecFcompC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecFcompC &SvecFcomp_I;


class SvecFcomp : public SvbaseFcomp
{
public:
	SvecFcomp() = default;
	explicit SvecFcomp(Long_I N) : SvbaseFcomp(N) {};
	SvecFcomp(Fcomp *data, Long_I N) : SvbaseFcomp(data, N) {};
	SvecFcomp(const SvecFcomp &v) = default; // copy constructor (shalow)
	
	operator SvecFcompC() const;
};

inline SvecFcomp::operator SvecFcompC() const
{
	return *((SvecFcompC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecFcomp &SvecFcomp_O, &SvecFcomp_IO;


class SvecCompC : public SvbaseCompC
{
public:
	SvecCompC() = default;
	explicit SvecCompC(Long_I N) : SvbaseCompC(N) {};
	SvecCompC(const Comp *data, Long_I N) : SvbaseCompC(data, N) {};
	SvecCompC(const SvecCompC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecCompC &SvecComp_I;


class SvecComp : public SvbaseComp
{
public:
	SvecComp() = default;
	explicit SvecComp(Long_I N) : SvbaseComp(N) {};
	SvecComp(Comp *data, Long_I N) : SvbaseComp(data, N) {};
	SvecComp(const SvecComp &v) = default; // copy constructor (shalow)
	
	operator SvecCompC() const;
};

inline SvecComp::operator SvecCompC() const
{
	return *((SvecCompC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecComp &SvecComp_O, &SvecComp_IO;


class SvecLcompC : public SvbaseLcompC
{
public:
	SvecLcompC() = default;
	explicit SvecLcompC(Long_I N) : SvbaseLcompC(N) {};
	SvecLcompC(const Lcomp *data, Long_I N) : SvbaseLcompC(data, N) {};
	SvecLcompC(const SvecLcompC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecLcompC &SvecLcomp_I;


class SvecLcomp : public SvbaseLcomp
{
public:
	SvecLcomp() = default;
	explicit SvecLcomp(Long_I N) : SvbaseLcomp(N) {};
	SvecLcomp(Lcomp *data, Long_I N) : SvbaseLcomp(data, N) {};
	SvecLcomp(const SvecLcomp &v) = default; // copy constructor (shalow)
	
	operator SvecLcompC() const;
};

inline SvecLcomp::operator SvecLcompC() const
{
	return *((SvecLcompC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLcomp &SvecLcomp_O, &SvecLcomp_IO;




class SvecFimagC : public SvbaseFimagC
{
public:
	SvecFimagC() = default;
	explicit SvecFimagC(Long_I N) : SvbaseFimagC(N) {};
	SvecFimagC(const Fimag *data, Long_I N) : SvbaseFimagC(data, N) {};
	SvecFimagC(const SvecFimagC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecFimagC &SvecFimag_I;


class SvecFimag : public SvbaseFimag
{
public:
	SvecFimag() = default;
	explicit SvecFimag(Long_I N) : SvbaseFimag(N) {};
	SvecFimag(Fimag *data, Long_I N) : SvbaseFimag(data, N) {};
	SvecFimag(const SvecFimag &v) = default; // copy constructor (shalow)
	
	operator SvecFimagC() const;
};

inline SvecFimag::operator SvecFimagC() const
{
	return *((SvecFimagC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecFimag &SvecFimag_O, &SvecFimag_IO;


class SvecImagC : public SvbaseImagC
{
public:
	SvecImagC() = default;
	explicit SvecImagC(Long_I N) : SvbaseImagC(N) {};
	SvecImagC(const Imag *data, Long_I N) : SvbaseImagC(data, N) {};
	SvecImagC(const SvecImagC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecImagC &SvecImag_I;


class SvecImag : public SvbaseImag
{
public:
	SvecImag() = default;
	explicit SvecImag(Long_I N) : SvbaseImag(N) {};
	SvecImag(Imag *data, Long_I N) : SvbaseImag(data, N) {};
	SvecImag(const SvecImag &v) = default; // copy constructor (shalow)
	
	operator SvecImagC() const;
};

inline SvecImag::operator SvecImagC() const
{
	return *((SvecImagC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecImag &SvecImag_O, &SvecImag_IO;


class SvecLimagC : public SvbaseLimagC
{
public:
	SvecLimagC() = default;
	explicit SvecLimagC(Long_I N) : SvbaseLimagC(N) {};
	SvecLimagC(const Limag *data, Long_I N) : SvbaseLimagC(data, N) {};
	SvecLimagC(const SvecLimagC &v) = default; // copy constructor (shalow)
	
};


typedef const SvecLimagC &SvecLimag_I;


class SvecLimag : public SvbaseLimag
{
public:
	SvecLimag() = default;
	explicit SvecLimag(Long_I N) : SvbaseLimag(N) {};
	SvecLimag(Limag *data, Long_I N) : SvbaseLimag(data, N) {};
	SvecLimag(const SvecLimag &v) = default; // copy constructor (shalow)
	
	operator SvecLimagC() const;
};

inline SvecLimag::operator SvecLimagC() const
{
	return *((SvecLimagC *)this);
}

// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLimag &SvecLimag_O, &SvecLimag_IO;





#ifdef SLS_USE_INT_AS_LONG
typedef SvecInt SvecLong;
typedef SvecIntC SvecLongC;
#else
typedef SvecLlong SvecLong;
typedef SvecLlongC SvecLongC;
#endif
typedef const SvecLongC &SvecLong_I;
// use "const" so that it can be bind to a temporary e.g. copy(cut0(a), cut0(b))
typedef const SvecLong &SvecLong_O, &SvecLong_IO;

} // namespace slisc
