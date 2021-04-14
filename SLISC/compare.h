#pragma once
#include "Vec.h"
#include "Mat.h"
#include "Mat3.h"
#include "Cmat.h"
#include "Cmat3.h"
#include "Cmat4.h"
#include "Cband.h"
#include "Mcoo.h"
#include "Cmobd.h"
#include "Svec.h"
#include "Dvec.h"
#include "Scmat.h"
#include "Scmat3.h"
#include "Dcmat.h"
#include "Jcmat3.h"

namespace slisc {
inline Bool equals_to_vs(const Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool equals_to_vs(const Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool equals_to_vs(const Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool equals_to_vs(const Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}


inline Bool equals_to_vv(const Char *v1, const Char *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Doub *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}


inline Bool shape_cmp(VecChar_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecChar_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecInt_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLlong_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFloat_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecDoub_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLdoub_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecFcomp_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecComp_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(VecLcomp_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecChar_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecInt_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLlong_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFloat_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLdoub_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecFcomp_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecComp_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(SvecLcomp_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecChar_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecInt_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFloat_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLdoub_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecFcomp_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecComp_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, VecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, VecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, VecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, VecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, VecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, VecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, VecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, VecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, VecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, SvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, SvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, SvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, SvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, SvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, SvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, SvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, SvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, SvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, DvecChar_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, DvecInt_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, DvecLlong_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, DvecFloat_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, DvecDoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, DvecLdoub_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, DvecFcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, DvecComp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(DvecLcomp_I v1, DvecLcomp_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(CmatChar_I v1, CmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatChar_I v1, CmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatChar_I v1, CmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatChar_I v1, CmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatChar_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatChar_I v1, CmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatChar_I v1, CmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatChar_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatChar_I v1, CmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatInt_I v1, CmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatInt_I v1, CmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatInt_I v1, CmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatInt_I v1, CmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatInt_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatInt_I v1, CmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatInt_I v1, CmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatInt_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatInt_I v1, CmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLlong_I v1, CmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLlong_I v1, CmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLlong_I v1, CmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLlong_I v1, CmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLlong_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLlong_I v1, CmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLlong_I v1, CmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLlong_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLlong_I v1, CmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFloat_I v1, CmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFloat_I v1, CmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFloat_I v1, CmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFloat_I v1, CmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFloat_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFloat_I v1, CmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFloat_I v1, CmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFloat_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFloat_I v1, CmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLdoub_I v1, CmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLdoub_I v1, CmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLdoub_I v1, CmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLdoub_I v1, CmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLdoub_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLdoub_I v1, CmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLdoub_I v1, CmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLdoub_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLdoub_I v1, CmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFcomp_I v1, CmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFcomp_I v1, CmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFcomp_I v1, CmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFcomp_I v1, CmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFcomp_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFcomp_I v1, CmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFcomp_I v1, CmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFcomp_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatFcomp_I v1, CmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLcomp_I v1, CmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLcomp_I v1, CmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLcomp_I v1, CmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLcomp_I v1, CmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLcomp_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLcomp_I v1, CmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLcomp_I v1, CmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLcomp_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLcomp_I v1, CmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatChar_I v1, MatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatChar_I v1, MatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatChar_I v1, MatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatChar_I v1, MatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatChar_I v1, MatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatChar_I v1, MatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatChar_I v1, MatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatChar_I v1, MatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatChar_I v1, MatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatInt_I v1, MatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatInt_I v1, MatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatInt_I v1, MatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatInt_I v1, MatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatInt_I v1, MatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatInt_I v1, MatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatInt_I v1, MatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatInt_I v1, MatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatInt_I v1, MatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLlong_I v1, MatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLlong_I v1, MatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLlong_I v1, MatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLlong_I v1, MatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLlong_I v1, MatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLlong_I v1, MatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLlong_I v1, MatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLlong_I v1, MatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLlong_I v1, MatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFloat_I v1, MatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFloat_I v1, MatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFloat_I v1, MatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFloat_I v1, MatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFloat_I v1, MatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFloat_I v1, MatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFloat_I v1, MatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFloat_I v1, MatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFloat_I v1, MatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatDoub_I v1, MatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatDoub_I v1, MatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatDoub_I v1, MatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatDoub_I v1, MatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatDoub_I v1, MatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatDoub_I v1, MatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatDoub_I v1, MatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatDoub_I v1, MatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatDoub_I v1, MatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLdoub_I v1, MatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLdoub_I v1, MatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLdoub_I v1, MatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLdoub_I v1, MatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLdoub_I v1, MatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLdoub_I v1, MatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLdoub_I v1, MatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLdoub_I v1, MatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLdoub_I v1, MatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFcomp_I v1, MatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFcomp_I v1, MatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFcomp_I v1, MatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFcomp_I v1, MatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFcomp_I v1, MatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFcomp_I v1, MatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFcomp_I v1, MatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFcomp_I v1, MatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatFcomp_I v1, MatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatComp_I v1, MatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatComp_I v1, MatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatComp_I v1, MatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatComp_I v1, MatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatComp_I v1, MatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatComp_I v1, MatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatComp_I v1, MatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatComp_I v1, MatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatComp_I v1, MatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLcomp_I v1, MatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLcomp_I v1, MatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLcomp_I v1, MatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLcomp_I v1, MatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLcomp_I v1, MatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLcomp_I v1, MatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLcomp_I v1, MatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLcomp_I v1, MatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatLcomp_I v1, MatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatChar_I v1, DcmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatChar_I v1, DcmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatChar_I v1, DcmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatChar_I v1, DcmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatChar_I v1, DcmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatChar_I v1, DcmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatChar_I v1, DcmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatChar_I v1, DcmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatChar_I v1, DcmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatInt_I v1, DcmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatInt_I v1, DcmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatInt_I v1, DcmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatInt_I v1, DcmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatInt_I v1, DcmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatInt_I v1, DcmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatInt_I v1, DcmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatInt_I v1, DcmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatInt_I v1, DcmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLlong_I v1, DcmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLlong_I v1, DcmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLlong_I v1, DcmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLlong_I v1, DcmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLlong_I v1, DcmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLlong_I v1, DcmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLlong_I v1, DcmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLlong_I v1, DcmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLlong_I v1, DcmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFloat_I v1, DcmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFloat_I v1, DcmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFloat_I v1, DcmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFloat_I v1, DcmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFloat_I v1, DcmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFloat_I v1, DcmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFloat_I v1, DcmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFloat_I v1, DcmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFloat_I v1, DcmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, DcmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, DcmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, DcmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, DcmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, DcmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, DcmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, DcmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, DcmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, DcmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLdoub_I v1, DcmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLdoub_I v1, DcmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLdoub_I v1, DcmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLdoub_I v1, DcmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLdoub_I v1, DcmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLdoub_I v1, DcmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLdoub_I v1, DcmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLdoub_I v1, DcmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLdoub_I v1, DcmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFcomp_I v1, DcmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFcomp_I v1, DcmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFcomp_I v1, DcmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFcomp_I v1, DcmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFcomp_I v1, DcmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFcomp_I v1, DcmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFcomp_I v1, DcmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFcomp_I v1, DcmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatFcomp_I v1, DcmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLcomp_I v1, DcmatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLcomp_I v1, DcmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLcomp_I v1, DcmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLcomp_I v1, DcmatFloat_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLcomp_I v1, DcmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLcomp_I v1, DcmatLdoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLcomp_I v1, DcmatFcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLcomp_I v1, DcmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatLcomp_I v1, DcmatLcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(Cmat3Char_I v1, Cmat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Char_I v1, Cmat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Char_I v1, Cmat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Char_I v1, Cmat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Char_I v1, Cmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Char_I v1, Cmat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Char_I v1, Cmat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Char_I v1, Cmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Char_I v1, Cmat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Int_I v1, Cmat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Int_I v1, Cmat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Int_I v1, Cmat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Int_I v1, Cmat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Int_I v1, Cmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Int_I v1, Cmat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Int_I v1, Cmat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Int_I v1, Cmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Int_I v1, Cmat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Llong_I v1, Cmat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Llong_I v1, Cmat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Llong_I v1, Cmat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Llong_I v1, Cmat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Llong_I v1, Cmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Llong_I v1, Cmat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Llong_I v1, Cmat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Llong_I v1, Cmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Llong_I v1, Cmat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Float_I v1, Cmat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Float_I v1, Cmat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Float_I v1, Cmat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Float_I v1, Cmat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Float_I v1, Cmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Float_I v1, Cmat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Float_I v1, Cmat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Float_I v1, Cmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Float_I v1, Cmat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Ldoub_I v1, Cmat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Ldoub_I v1, Cmat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Ldoub_I v1, Cmat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Ldoub_I v1, Cmat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Ldoub_I v1, Cmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Ldoub_I v1, Cmat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Ldoub_I v1, Cmat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Ldoub_I v1, Cmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Ldoub_I v1, Cmat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Fcomp_I v1, Cmat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Fcomp_I v1, Cmat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Fcomp_I v1, Cmat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Fcomp_I v1, Cmat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Fcomp_I v1, Cmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Fcomp_I v1, Cmat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Fcomp_I v1, Cmat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Fcomp_I v1, Cmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Fcomp_I v1, Cmat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Lcomp_I v1, Cmat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Lcomp_I v1, Cmat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Lcomp_I v1, Cmat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Lcomp_I v1, Cmat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Lcomp_I v1, Cmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Lcomp_I v1, Cmat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Lcomp_I v1, Cmat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Lcomp_I v1, Cmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Cmat3Lcomp_I v1, Cmat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Char_I v1, Mat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Char_I v1, Mat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Char_I v1, Mat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Char_I v1, Mat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Char_I v1, Mat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Char_I v1, Mat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Char_I v1, Mat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Char_I v1, Mat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Char_I v1, Mat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Int_I v1, Mat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Int_I v1, Mat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Int_I v1, Mat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Int_I v1, Mat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Int_I v1, Mat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Int_I v1, Mat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Int_I v1, Mat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Int_I v1, Mat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Int_I v1, Mat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Llong_I v1, Mat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Llong_I v1, Mat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Llong_I v1, Mat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Llong_I v1, Mat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Llong_I v1, Mat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Llong_I v1, Mat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Llong_I v1, Mat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Llong_I v1, Mat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Llong_I v1, Mat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Float_I v1, Mat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Float_I v1, Mat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Float_I v1, Mat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Float_I v1, Mat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Float_I v1, Mat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Float_I v1, Mat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Float_I v1, Mat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Float_I v1, Mat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Float_I v1, Mat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Ldoub_I v1, Mat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Ldoub_I v1, Mat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Ldoub_I v1, Mat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Ldoub_I v1, Mat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Ldoub_I v1, Mat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Ldoub_I v1, Mat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Ldoub_I v1, Mat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Ldoub_I v1, Mat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Ldoub_I v1, Mat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Fcomp_I v1, Mat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Fcomp_I v1, Mat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Fcomp_I v1, Mat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Fcomp_I v1, Mat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Fcomp_I v1, Mat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Fcomp_I v1, Mat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Fcomp_I v1, Mat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Fcomp_I v1, Mat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Fcomp_I v1, Mat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Comp_I v1, Mat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Comp_I v1, Mat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Comp_I v1, Mat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Comp_I v1, Mat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Comp_I v1, Mat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Comp_I v1, Mat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Comp_I v1, Mat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Comp_I v1, Mat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Comp_I v1, Mat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Lcomp_I v1, Mat3Char_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Lcomp_I v1, Mat3Int_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Lcomp_I v1, Mat3Llong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Lcomp_I v1, Mat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Lcomp_I v1, Mat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Lcomp_I v1, Mat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Lcomp_I v1, Mat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Lcomp_I v1, Mat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Mat3Lcomp_I v1, Mat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(VecBool_I v1, VecBool_I v2) {return v1.size() == v2.size();}

inline Bool shape_cmp(CmatBool_I v1, CmatBool_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatDoub_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(MatComp_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatInt_I v1, MatChar_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatLlong_I v1, ScmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatLlong_I v1, CmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, ScmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, DcmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, MatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, McooDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CbandDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatDoub_I v1, CmobdDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, ScmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, DcmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, MatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatInt_I v1, CmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatComp_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(Cmat3Comp_I v1, Jcmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(CmatComp_I v1, McooComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(McooDoub_I v1, ScmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(McooDoub_I v1, McooDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(McooDoub_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(McooDoub_I v1, CbandComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(McooComp_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(McooComp_I v1, ScmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(McooComp_I v1, McooDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(McooComp_I v1, McooComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatInt_I v1, ScmatInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatLlong_I v1, ScmatLlong_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatDoub_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatDoub_I v1, McooDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatDoub_I v1, CbandDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatDoub_I v1, CbandComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatComp_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatComp_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatComp_I v1, CbandDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(ScmatComp_I v1, CbandComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(Jcmat3Float_I v1, Jcmat3Float_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Jcmat3Doub_I v1, Cmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Jcmat3Doub_I v1, Jcmat3Doub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Jcmat3Ldoub_I v1, Jcmat3Ldoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Jcmat3Fcomp_I v1, Jcmat3Fcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Jcmat3Comp_I v1, Jcmat3Comp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(Jcmat3Lcomp_I v1, Jcmat3Lcomp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

inline Bool shape_cmp(CmobdInt_I v1, McooInt_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmobdDoub_I v1, McooDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmobdComp_I v1, McooDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmobdComp_I v1, CmobdDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmobdComp_I v1, CmobdComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CbandDoub_I v1, CbandDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CbandDoub_I v1, CmatDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CbandDoub_I v1, CbandComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CbandComp_I v1, CbandComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CbandComp_I v1, CmatComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CbandComp_I v1, CbandDoub_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CbandComp_I v2) {return v1.n1() == v2.n1() && v1.n2() == v2.n2();}


inline Bool operator==(VecChar_I v1, VecChar_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecChar_I v1, VecChar_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecInt_I v1, VecInt_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecInt_I v1, VecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecInt_I v1, DvecInt_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(VecInt_I v1, DvecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecLlong_I v1, DvecLlong_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(VecLlong_I v1, DvecLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecLlong_I v1, VecLlong_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecLlong_I v1, VecLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecDoub_I v1, DvecDoub_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(VecDoub_I v1, DvecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecDoub_I v1, VecDoub_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecDoub_I v1, VecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecDoub_I v1, VecComp_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecDoub_I v1, VecComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecComp_I v1, VecComp_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecComp_I v1, VecComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecChar_I v1, SvecChar_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecChar_I v1, SvecChar_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecInt_I v1, SvecInt_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecInt_I v1, SvecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecInt_I v1, DvecInt_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(SvecInt_I v1, DvecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecLlong_I v1, DvecLlong_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(SvecLlong_I v1, DvecLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecLlong_I v1, SvecLlong_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecLlong_I v1, SvecLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecDoub_I v1, DvecDoub_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(SvecDoub_I v1, DvecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecDoub_I v1, SvecDoub_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecDoub_I v1, SvecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecDoub_I v1, SvecComp_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecDoub_I v1, SvecComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecComp_I v1, SvecComp_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecComp_I v1, SvecComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatInt_I v1, MatInt_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatInt_I v1, MatInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatLlong_I v1, MatLlong_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatLlong_I v1, MatLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatDoub_I v1, MatDoub_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatDoub_I v1, MatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatComp_I v1, MatComp_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatComp_I v1, MatComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatInt_I v1, CmatInt_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(CmatInt_I v1, CmatInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatDoub_I v1, CmatDoub_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(CmatDoub_I v1, CmatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatComp_I v1, CmatComp_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(CmatComp_I v1, CmatComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatComp_I v1, MatComp_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.n1(); ++i)
        for (Long j = 0; j < v1.n2(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(CmatComp_I v1, MatComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatDoub_I v1, CmatDoub_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.n1(); ++i)
        for (Long j = 0; j < v1.n2(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(MatDoub_I v1, CmatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatDoub_I v1, MatDoub_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.n1(); ++i)
        for (Long j = 0; j < v1.n2(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(CmatDoub_I v1, MatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(Cmat3Doub_I v1, Cmat3Doub_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(Cmat3Doub_I v1, Cmat3Doub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmobdComp_I v1, CmobdDoub_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.n1(); ++i)
        for (Long j = 0; j < v1.n2(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(CmobdComp_I v1, CmobdDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(Mat3Doub_I v1, Mat3Doub_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(Mat3Doub_I v1, Mat3Doub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(DvecInt_I v1, DvecInt_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(DvecInt_I v1, DvecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(DvecLong_I v1, DvecLong_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(DvecLong_I v1, DvecLong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(DvecDoub_I v1, DvecDoub_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(DvecDoub_I v1, DvecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(DcmatDoub_I v1, CmatDoub_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.n1(); ++i)
        for (Long j = 0; j < v1.n2(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(DcmatDoub_I v1, CmatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(Jcmat3Doub_I v1, Cmat3Doub_I v2)
{
    if (!shape_cmp(v1, v2))
        return false;
    for (Long i = 0; i < v1.n1(); ++i)
        for (Long j = 0; j < v1.n2(); ++j)
            for (Long k = 0; k < v1.n3(); ++k)
                if (v1(i, j, k) != v2(i, j, k))
                    return false;
    return true;
}

inline Bool operator!=(Jcmat3Doub_I v1, Cmat3Doub_I v2)
{
    return !(v1 == v2);
}


inline Bool operator==(VecBool_I v1, VecBool_I v2)
{
    for (Long i = 0; i < v1.size(); ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool operator!=(VecBool_I v1, VecBool_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecInt_I v, Int_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(VecInt_I v, Int_I s)
{
    return !(v == s);
}

inline Bool operator==(VecLlong_I v, Llong_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(VecLlong_I v, Llong_I s)
{
    return !(v == s);
}

inline Bool operator==(VecDoub_I v, Doub_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(VecDoub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(VecComp_I v, Comp_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(VecComp_I v, Comp_I s)
{
    return !(v == s);
}

inline Bool operator==(DvecInt_I v, Int_I s)
{
    for (Long i = 0; i < v.size(); ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool operator!=(DvecInt_I v, Int_I s)
{
    return !(v == s);
}

inline Bool operator==(DvecLlong_I v, Llong_I s)
{
    for (Long i = 0; i < v.size(); ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool operator!=(DvecLlong_I v, Llong_I s)
{
    return !(v == s);
}

inline Bool operator==(DvecDoub_I v, Doub_I s)
{
    for (Long i = 0; i < v.size(); ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool operator!=(DvecDoub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(MatInt_I v, Int_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(MatInt_I v, Int_I s)
{
    return !(v == s);
}

inline Bool operator==(MatLlong_I v, Llong_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(MatLlong_I v, Llong_I s)
{
    return !(v == s);
}

inline Bool operator==(MatDoub_I v, Doub_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(MatDoub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(MatComp_I v, Comp_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(MatComp_I v, Comp_I s)
{
    return !(v == s);
}

inline Bool operator==(Mat3Doub_I v, Doub_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(Mat3Doub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(CmatDoub_I v, Doub_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(CmatDoub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(CmatComp_I v, Comp_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(CmatComp_I v, Comp_I s)
{
    return !(v == s);
}

inline Bool operator==(Cmat3Doub_I v, Doub_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(Cmat3Doub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(Cmat3Comp_I v, Comp_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(Cmat3Comp_I v, Comp_I s)
{
    return !(v == s);
}

} // namespace slisc
