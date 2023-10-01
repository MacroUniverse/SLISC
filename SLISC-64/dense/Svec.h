#pragma once
#include "../dense/Svbase.h"

// this class is not memory safe!
// "C" means lower level const

namespace slisc {

class SvecBoolC : public SvbaseBoolC
{
public:
	using SvbaseBoolC::SvbaseBoolC;
	explicit SvecBoolC(Long_I N);
};


typedef const SvecBoolC &SvecBool_I;


class SvecBool : public SvbaseBool
{
public:
	using SvbaseBool::SvbaseBool;
	explicit SvecBool(Long_I N);
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
	using SvbaseCharC::SvbaseCharC;
	explicit SvecCharC(Long_I N);
};


typedef const SvecCharC &SvecChar_I;


class SvecChar : public SvbaseChar
{
public:
	using SvbaseChar::SvbaseChar;
	explicit SvecChar(Long_I N);
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
	using SvbaseUcharC::SvbaseUcharC;
	explicit SvecUcharC(Long_I N);
};


typedef const SvecUcharC &SvecUchar_I;


class SvecUchar : public SvbaseUchar
{
public:
	using SvbaseUchar::SvbaseUchar;
	explicit SvecUchar(Long_I N);
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
	using SvbaseIntC::SvbaseIntC;
	explicit SvecIntC(Long_I N);
};


typedef const SvecIntC &SvecInt_I;


class SvecInt : public SvbaseInt
{
public:
	using SvbaseInt::SvbaseInt;
	explicit SvecInt(Long_I N);
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
	using SvbaseLlongC::SvbaseLlongC;
	explicit SvecLlongC(Long_I N);
};


typedef const SvecLlongC &SvecLlong_I;


class SvecLlong : public SvbaseLlong
{
public:
	using SvbaseLlong::SvbaseLlong;
	explicit SvecLlong(Long_I N);
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
	using SvbaseFloatC::SvbaseFloatC;
	explicit SvecFloatC(Long_I N);
};


typedef const SvecFloatC &SvecFloat_I;


class SvecFloat : public SvbaseFloat
{
public:
	using SvbaseFloat::SvbaseFloat;
	explicit SvecFloat(Long_I N);
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
	using SvbaseDoubC::SvbaseDoubC;
	explicit SvecDoubC(Long_I N);
};


typedef const SvecDoubC &SvecDoub_I;


class SvecDoub : public SvbaseDoub
{
public:
	using SvbaseDoub::SvbaseDoub;
	explicit SvecDoub(Long_I N);
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
	using SvbaseLdoubC::SvbaseLdoubC;
	explicit SvecLdoubC(Long_I N);
};


typedef const SvecLdoubC &SvecLdoub_I;


class SvecLdoub : public SvbaseLdoub
{
public:
	using SvbaseLdoub::SvbaseLdoub;
	explicit SvecLdoub(Long_I N);
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
	using SvbaseFcompC::SvbaseFcompC;
	explicit SvecFcompC(Long_I N);
};


typedef const SvecFcompC &SvecFcomp_I;


class SvecFcomp : public SvbaseFcomp
{
public:
	using SvbaseFcomp::SvbaseFcomp;
	explicit SvecFcomp(Long_I N);
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
	using SvbaseCompC::SvbaseCompC;
	explicit SvecCompC(Long_I N);
};


typedef const SvecCompC &SvecComp_I;


class SvecComp : public SvbaseComp
{
public:
	using SvbaseComp::SvbaseComp;
	explicit SvecComp(Long_I N);
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
	using SvbaseLcompC::SvbaseLcompC;
	explicit SvecLcompC(Long_I N);
};


typedef const SvecLcompC &SvecLcomp_I;


class SvecLcomp : public SvbaseLcomp
{
public:
	using SvbaseLcomp::SvbaseLcomp;
	explicit SvecLcomp(Long_I N);
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
	using SvbaseFimagC::SvbaseFimagC;
	explicit SvecFimagC(Long_I N);
};


typedef const SvecFimagC &SvecFimag_I;


class SvecFimag : public SvbaseFimag
{
public:
	using SvbaseFimag::SvbaseFimag;
	explicit SvecFimag(Long_I N);
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
	using SvbaseImagC::SvbaseImagC;
	explicit SvecImagC(Long_I N);
};


typedef const SvecImagC &SvecImag_I;


class SvecImag : public SvbaseImag
{
public:
	using SvbaseImag::SvbaseImag;
	explicit SvecImag(Long_I N);
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
	using SvbaseLimagC::SvbaseLimagC;
	explicit SvecLimagC(Long_I N);
};


typedef const SvecLimagC &SvecLimag_I;


class SvecLimag : public SvbaseLimag
{
public:
	using SvbaseLimag::SvbaseLimag;
	explicit SvecLimag(Long_I N);
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
