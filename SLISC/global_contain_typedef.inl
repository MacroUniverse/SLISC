class VbaseChar;
typedef const VbaseChar &VbaseChar_I;
typedef VbaseChar &VbaseChar_O, &VbaseChar_IO;

class VbaseInt;
typedef const VbaseInt &VbaseInt_I;
typedef VbaseInt &VbaseInt_O, &VbaseInt_IO;

class VbaseLlong;
typedef const VbaseLlong &VbaseLlong_I;
typedef VbaseLlong &VbaseLlong_O, &VbaseLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef VbaseInt VbaseLong;
#else
typedef VbaseLlong VbaseLong;
#endif

typedef const VbaseLong &VbaseLong_I;
typedef VbaseLong &VbaseLong_O, &VbaseLong_IO;

class VbaseFdoub;
typedef const VbaseFdoub &VbaseFdoub_I;
typedef VbaseFdoub &VbaseFdoub_O, &VbaseFdoub_IO;

class VbaseDoub;
typedef const VbaseDoub &VbaseDoub_I;
typedef VbaseDoub &VbaseDoub_O, &VbaseDoub_IO;

class VbaseLdoub;
typedef const VbaseLdoub &VbaseLdoub_I;
typedef VbaseLdoub &VbaseLdoub_O, &VbaseLdoub_IO;

class VbaseFcomp;
typedef const VbaseFcomp &VbaseFcomp_I;
typedef VbaseFcomp &VbaseFcomp_O, &VbaseFcomp_IO;

class VbaseComp;
typedef const VbaseComp &VbaseComp_I;
typedef VbaseComp &VbaseComp_O, &VbaseComp_IO;

class VbaseLcomp;
typedef const VbaseLcomp &VbaseLcomp_I;
typedef VbaseLcomp &VbaseLcomp_O, &VbaseLcomp_IO;


class VecChar;
typedef const VecChar &VecChar_I;
typedef VecChar &VecChar_O, &VecChar_IO;

class VecInt;
typedef const VecInt &VecInt_I;
typedef VecInt &VecInt_O, &VecInt_IO;

class VecLlong;
typedef const VecLlong &VecLlong_I;
typedef VecLlong &VecLlong_O, &VecLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef VecInt VecLong;
#else
typedef VecLlong VecLong;
#endif

typedef const VecLong &VecLong_I;
typedef VecLong &VecLong_O, &VecLong_IO;

class VecFdoub;
typedef const VecFdoub &VecFdoub_I;
typedef VecFdoub &VecFdoub_O, &VecFdoub_IO;

class VecDoub;
typedef const VecDoub &VecDoub_I;
typedef VecDoub &VecDoub_O, &VecDoub_IO;

class VecLdoub;
typedef const VecLdoub &VecLdoub_I;
typedef VecLdoub &VecLdoub_O, &VecLdoub_IO;

class VecFcomp;
typedef const VecFcomp &VecFcomp_I;
typedef VecFcomp &VecFcomp_O, &VecFcomp_IO;

class VecComp;
typedef const VecComp &VecComp_I;
typedef VecComp &VecComp_O, &VecComp_IO;

class VecLcomp;
typedef const VecLcomp &VecLcomp_I;
typedef VecLcomp &VecLcomp_O, &VecLcomp_IO;


class MatChar;
typedef const MatChar &MatChar_I;
typedef MatChar &MatChar_O, &MatChar_IO;

class MatInt;
typedef const MatInt &MatInt_I;
typedef MatInt &MatInt_O, &MatInt_IO;

class MatLlong;
typedef const MatLlong &MatLlong_I;
typedef MatLlong &MatLlong_O, &MatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef MatInt MatLong;
#else
typedef MatLlong MatLong;
#endif

typedef const MatLong &MatLong_I;
typedef MatLong &MatLong_O, &MatLong_IO;

class MatFdoub;
typedef const MatFdoub &MatFdoub_I;
typedef MatFdoub &MatFdoub_O, &MatFdoub_IO;

class MatDoub;
typedef const MatDoub &MatDoub_I;
typedef MatDoub &MatDoub_O, &MatDoub_IO;

class MatLdoub;
typedef const MatLdoub &MatLdoub_I;
typedef MatLdoub &MatLdoub_O, &MatLdoub_IO;

class MatFcomp;
typedef const MatFcomp &MatFcomp_I;
typedef MatFcomp &MatFcomp_O, &MatFcomp_IO;

class MatComp;
typedef const MatComp &MatComp_I;
typedef MatComp &MatComp_O, &MatComp_IO;

class MatLcomp;
typedef const MatLcomp &MatLcomp_I;
typedef MatLcomp &MatLcomp_O, &MatLcomp_IO;


class Mat3Char;
typedef const Mat3Char &Mat3Char_I;
typedef Mat3Char &Mat3Char_O, &Mat3Char_IO;

class Mat3Int;
typedef const Mat3Int &Mat3Int_I;
typedef Mat3Int &Mat3Int_O, &Mat3Int_IO;

class Mat3Llong;
typedef const Mat3Llong &Mat3Llong_I;
typedef Mat3Llong &Mat3Llong_O, &Mat3Llong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef Mat3Int Mat3Long;
#else
typedef Mat3Llong Mat3Long;
#endif

typedef const Mat3Long &Mat3Long_I;
typedef Mat3Long &Mat3Long_O, &Mat3Long_IO;

class Mat3Fdoub;
typedef const Mat3Fdoub &Mat3Fdoub_I;
typedef Mat3Fdoub &Mat3Fdoub_O, &Mat3Fdoub_IO;

class Mat3Doub;
typedef const Mat3Doub &Mat3Doub_I;
typedef Mat3Doub &Mat3Doub_O, &Mat3Doub_IO;

class Mat3Ldoub;
typedef const Mat3Ldoub &Mat3Ldoub_I;
typedef Mat3Ldoub &Mat3Ldoub_O, &Mat3Ldoub_IO;

class Mat3Fcomp;
typedef const Mat3Fcomp &Mat3Fcomp_I;
typedef Mat3Fcomp &Mat3Fcomp_O, &Mat3Fcomp_IO;

class Mat3Comp;
typedef const Mat3Comp &Mat3Comp_I;
typedef Mat3Comp &Mat3Comp_O, &Mat3Comp_IO;

class Mat3Lcomp;
typedef const Mat3Lcomp &Mat3Lcomp_I;
typedef Mat3Lcomp &Mat3Lcomp_O, &Mat3Lcomp_IO;


class CmatChar;
typedef const CmatChar &CmatChar_I;
typedef CmatChar &CmatChar_O, &CmatChar_IO;

class CmatInt;
typedef const CmatInt &CmatInt_I;
typedef CmatInt &CmatInt_O, &CmatInt_IO;

class CmatLlong;
typedef const CmatLlong &CmatLlong_I;
typedef CmatLlong &CmatLlong_O, &CmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef CmatInt CmatLong;
#else
typedef CmatLlong CmatLong;
#endif

typedef const CmatLong &CmatLong_I;
typedef CmatLong &CmatLong_O, &CmatLong_IO;

class CmatFdoub;
typedef const CmatFdoub &CmatFdoub_I;
typedef CmatFdoub &CmatFdoub_O, &CmatFdoub_IO;

class CmatDoub;
typedef const CmatDoub &CmatDoub_I;
typedef CmatDoub &CmatDoub_O, &CmatDoub_IO;

class CmatLdoub;
typedef const CmatLdoub &CmatLdoub_I;
typedef CmatLdoub &CmatLdoub_O, &CmatLdoub_IO;

class CmatFcomp;
typedef const CmatFcomp &CmatFcomp_I;
typedef CmatFcomp &CmatFcomp_O, &CmatFcomp_IO;

class CmatComp;
typedef const CmatComp &CmatComp_I;
typedef CmatComp &CmatComp_O, &CmatComp_IO;

class CmatLcomp;
typedef const CmatLcomp &CmatLcomp_I;
typedef CmatLcomp &CmatLcomp_O, &CmatLcomp_IO;


class Cmat3Char;
typedef const Cmat3Char &Cmat3Char_I;
typedef Cmat3Char &Cmat3Char_O, &Cmat3Char_IO;

class Cmat3Int;
typedef const Cmat3Int &Cmat3Int_I;
typedef Cmat3Int &Cmat3Int_O, &Cmat3Int_IO;

class Cmat3Llong;
typedef const Cmat3Llong &Cmat3Llong_I;
typedef Cmat3Llong &Cmat3Llong_O, &Cmat3Llong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef Cmat3Int Cmat3Long;
#else
typedef Cmat3Llong Cmat3Long;
#endif

typedef const Cmat3Long &Cmat3Long_I;
typedef Cmat3Long &Cmat3Long_O, &Cmat3Long_IO;

class Cmat3Fdoub;
typedef const Cmat3Fdoub &Cmat3Fdoub_I;
typedef Cmat3Fdoub &Cmat3Fdoub_O, &Cmat3Fdoub_IO;

class Cmat3Doub;
typedef const Cmat3Doub &Cmat3Doub_I;
typedef Cmat3Doub &Cmat3Doub_O, &Cmat3Doub_IO;

class Cmat3Ldoub;
typedef const Cmat3Ldoub &Cmat3Ldoub_I;
typedef Cmat3Ldoub &Cmat3Ldoub_O, &Cmat3Ldoub_IO;

class Cmat3Fcomp;
typedef const Cmat3Fcomp &Cmat3Fcomp_I;
typedef Cmat3Fcomp &Cmat3Fcomp_O, &Cmat3Fcomp_IO;

class Cmat3Comp;
typedef const Cmat3Comp &Cmat3Comp_I;
typedef Cmat3Comp &Cmat3Comp_O, &Cmat3Comp_IO;

class Cmat3Lcomp;
typedef const Cmat3Lcomp &Cmat3Lcomp_I;
typedef Cmat3Lcomp &Cmat3Lcomp_O, &Cmat3Lcomp_IO;


class Cmat4Char;
typedef const Cmat4Char &Cmat4Char_I;
typedef Cmat4Char &Cmat4Char_O, &Cmat4Char_IO;

class Cmat4Int;
typedef const Cmat4Int &Cmat4Int_I;
typedef Cmat4Int &Cmat4Int_O, &Cmat4Int_IO;

class Cmat4Llong;
typedef const Cmat4Llong &Cmat4Llong_I;
typedef Cmat4Llong &Cmat4Llong_O, &Cmat4Llong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef Cmat4Int Cmat4Long;
#else
typedef Cmat4Llong Cmat4Long;
#endif

typedef const Cmat4Long &Cmat4Long_I;
typedef Cmat4Long &Cmat4Long_O, &Cmat4Long_IO;

class Cmat4Fdoub;
typedef const Cmat4Fdoub &Cmat4Fdoub_I;
typedef Cmat4Fdoub &Cmat4Fdoub_O, &Cmat4Fdoub_IO;

class Cmat4Doub;
typedef const Cmat4Doub &Cmat4Doub_I;
typedef Cmat4Doub &Cmat4Doub_O, &Cmat4Doub_IO;

class Cmat4Ldoub;
typedef const Cmat4Ldoub &Cmat4Ldoub_I;
typedef Cmat4Ldoub &Cmat4Ldoub_O, &Cmat4Ldoub_IO;

class Cmat4Fcomp;
typedef const Cmat4Fcomp &Cmat4Fcomp_I;
typedef Cmat4Fcomp &Cmat4Fcomp_O, &Cmat4Fcomp_IO;

class Cmat4Comp;
typedef const Cmat4Comp &Cmat4Comp_I;
typedef Cmat4Comp &Cmat4Comp_O, &Cmat4Comp_IO;

class Cmat4Lcomp;
typedef const Cmat4Lcomp &Cmat4Lcomp_I;
typedef Cmat4Lcomp &Cmat4Lcomp_O, &Cmat4Lcomp_IO;


class SvecChar;
typedef const SvecChar &SvecChar_I;
typedef SvecChar &SvecChar_O, &SvecChar_IO;

class SvecInt;
typedef const SvecInt &SvecInt_I;
typedef SvecInt &SvecInt_O, &SvecInt_IO;

class SvecLlong;
typedef const SvecLlong &SvecLlong_I;
typedef SvecLlong &SvecLlong_O, &SvecLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef SvecInt SvecLong;
#else
typedef SvecLlong SvecLong;
#endif

typedef const SvecLong &SvecLong_I;
typedef SvecLong &SvecLong_O, &SvecLong_IO;

class SvecFdoub;
typedef const SvecFdoub &SvecFdoub_I;
typedef SvecFdoub &SvecFdoub_O, &SvecFdoub_IO;

class SvecDoub;
typedef const SvecDoub &SvecDoub_I;
typedef SvecDoub &SvecDoub_O, &SvecDoub_IO;

class SvecLdoub;
typedef const SvecLdoub &SvecLdoub_I;
typedef SvecLdoub &SvecLdoub_O, &SvecLdoub_IO;

class SvecFcomp;
typedef const SvecFcomp &SvecFcomp_I;
typedef SvecFcomp &SvecFcomp_O, &SvecFcomp_IO;

class SvecComp;
typedef const SvecComp &SvecComp_I;
typedef SvecComp &SvecComp_O, &SvecComp_IO;

class SvecLcomp;
typedef const SvecLcomp &SvecLcomp_I;
typedef SvecLcomp &SvecLcomp_O, &SvecLcomp_IO;


class DvecChar;
typedef const DvecChar &DvecChar_I;
typedef DvecChar &DvecChar_O, &DvecChar_IO;

class DvecInt;
typedef const DvecInt &DvecInt_I;
typedef DvecInt &DvecInt_O, &DvecInt_IO;

class DvecLlong;
typedef const DvecLlong &DvecLlong_I;
typedef DvecLlong &DvecLlong_O, &DvecLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef DvecInt DvecLong;
#else
typedef DvecLlong DvecLong;
#endif

typedef const DvecLong &DvecLong_I;
typedef DvecLong &DvecLong_O, &DvecLong_IO;

class DvecFdoub;
typedef const DvecFdoub &DvecFdoub_I;
typedef DvecFdoub &DvecFdoub_O, &DvecFdoub_IO;

class DvecDoub;
typedef const DvecDoub &DvecDoub_I;
typedef DvecDoub &DvecDoub_O, &DvecDoub_IO;

class DvecLdoub;
typedef const DvecLdoub &DvecLdoub_I;
typedef DvecLdoub &DvecLdoub_O, &DvecLdoub_IO;

class DvecFcomp;
typedef const DvecFcomp &DvecFcomp_I;
typedef DvecFcomp &DvecFcomp_O, &DvecFcomp_IO;

class DvecComp;
typedef const DvecComp &DvecComp_I;
typedef DvecComp &DvecComp_O, &DvecComp_IO;

class DvecLcomp;
typedef const DvecLcomp &DvecLcomp_I;
typedef DvecLcomp &DvecLcomp_O, &DvecLcomp_IO;


class ScmatChar;
typedef const ScmatChar &ScmatChar_I;
typedef ScmatChar &ScmatChar_O, &ScmatChar_IO;

class ScmatInt;
typedef const ScmatInt &ScmatInt_I;
typedef ScmatInt &ScmatInt_O, &ScmatInt_IO;

class ScmatLlong;
typedef const ScmatLlong &ScmatLlong_I;
typedef ScmatLlong &ScmatLlong_O, &ScmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef ScmatInt ScmatLong;
#else
typedef ScmatLlong ScmatLong;
#endif

typedef const ScmatLong &ScmatLong_I;
typedef ScmatLong &ScmatLong_O, &ScmatLong_IO;

class ScmatFdoub;
typedef const ScmatFdoub &ScmatFdoub_I;
typedef ScmatFdoub &ScmatFdoub_O, &ScmatFdoub_IO;

class ScmatDoub;
typedef const ScmatDoub &ScmatDoub_I;
typedef ScmatDoub &ScmatDoub_O, &ScmatDoub_IO;

class ScmatLdoub;
typedef const ScmatLdoub &ScmatLdoub_I;
typedef ScmatLdoub &ScmatLdoub_O, &ScmatLdoub_IO;

class ScmatFcomp;
typedef const ScmatFcomp &ScmatFcomp_I;
typedef ScmatFcomp &ScmatFcomp_O, &ScmatFcomp_IO;

class ScmatComp;
typedef const ScmatComp &ScmatComp_I;
typedef ScmatComp &ScmatComp_O, &ScmatComp_IO;

class ScmatLcomp;
typedef const ScmatLcomp &ScmatLcomp_I;
typedef ScmatLcomp &ScmatLcomp_O, &ScmatLcomp_IO;


class DcmatChar;
typedef const DcmatChar &DcmatChar_I;
typedef DcmatChar &DcmatChar_O, &DcmatChar_IO;

class DcmatInt;
typedef const DcmatInt &DcmatInt_I;
typedef DcmatInt &DcmatInt_O, &DcmatInt_IO;

class DcmatLlong;
typedef const DcmatLlong &DcmatLlong_I;
typedef DcmatLlong &DcmatLlong_O, &DcmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef DcmatInt DcmatLong;
#else
typedef DcmatLlong DcmatLong;
#endif

typedef const DcmatLong &DcmatLong_I;
typedef DcmatLong &DcmatLong_O, &DcmatLong_IO;

class DcmatFdoub;
typedef const DcmatFdoub &DcmatFdoub_I;
typedef DcmatFdoub &DcmatFdoub_O, &DcmatFdoub_IO;

class DcmatDoub;
typedef const DcmatDoub &DcmatDoub_I;
typedef DcmatDoub &DcmatDoub_O, &DcmatDoub_IO;

class DcmatLdoub;
typedef const DcmatLdoub &DcmatLdoub_I;
typedef DcmatLdoub &DcmatLdoub_O, &DcmatLdoub_IO;

class DcmatFcomp;
typedef const DcmatFcomp &DcmatFcomp_I;
typedef DcmatFcomp &DcmatFcomp_O, &DcmatFcomp_IO;

class DcmatComp;
typedef const DcmatComp &DcmatComp_I;
typedef DcmatComp &DcmatComp_O, &DcmatComp_IO;

class DcmatLcomp;
typedef const DcmatLcomp &DcmatLcomp_I;
typedef DcmatLcomp &DcmatLcomp_O, &DcmatLcomp_IO;


class DiagChar;
typedef const DiagChar &DiagChar_I;
typedef DiagChar &DiagChar_O, &DiagChar_IO;

class DiagInt;
typedef const DiagInt &DiagInt_I;
typedef DiagInt &DiagInt_O, &DiagInt_IO;

class DiagLlong;
typedef const DiagLlong &DiagLlong_I;
typedef DiagLlong &DiagLlong_O, &DiagLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef DiagInt DiagLong;
#else
typedef DiagLlong DiagLong;
#endif

typedef const DiagLong &DiagLong_I;
typedef DiagLong &DiagLong_O, &DiagLong_IO;

class DiagFdoub;
typedef const DiagFdoub &DiagFdoub_I;
typedef DiagFdoub &DiagFdoub_O, &DiagFdoub_IO;

class DiagDoub;
typedef const DiagDoub &DiagDoub_I;
typedef DiagDoub &DiagDoub_O, &DiagDoub_IO;

class DiagLdoub;
typedef const DiagLdoub &DiagLdoub_I;
typedef DiagLdoub &DiagLdoub_O, &DiagLdoub_IO;

class DiagFcomp;
typedef const DiagFcomp &DiagFcomp_I;
typedef DiagFcomp &DiagFcomp_O, &DiagFcomp_IO;

class DiagComp;
typedef const DiagComp &DiagComp_I;
typedef DiagComp &DiagComp_O, &DiagComp_IO;

class DiagLcomp;
typedef const DiagLcomp &DiagLcomp_I;
typedef DiagLcomp &DiagLcomp_O, &DiagLcomp_IO;


