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


