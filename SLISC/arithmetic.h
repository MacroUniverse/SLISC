#pragma once
#include "copy.h"
#include "scalar_arith.h"
#include "cut.h"

namespace slisc {
// return signed size instead of unsigned
inline Long size(vecBool_I v)
{
    return v.size();
}

inline Long size(vecChar_I v)
{
    return v.size();
}

inline Long size(vecInt_I v)
{
    return v.size();
}

inline Long size(vecLlong_I v)
{
    return v.size();
}

inline Long size(vecDoub_I v)
{
    return v.size();
}

inline Long size(Str_I v)
{
    return v.size();
}

inline Long size(Str32_I v)
{
    return v.size();
}

inline Long size(vecStr_I v)
{
    return v.size();
}

inline Long size(vecStr32_I v)
{
    return v.size();
}


// sum of absolute values
inline Llong sum_abs_v(const Char *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Llong sum_abs_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Llong sum_abs_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Float sum_abs_v(const Float *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Doub sum_abs_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Ldoub sum_abs_v(const Ldoub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Ldoub s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Float sum_abs_v(const Fcomp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Doub sum_abs_v(const Comp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Ldoub sum_abs_v(const Lcomp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Ldoub s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}


// sum of absolute values
inline Llong sum_abs(VecChar_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(VecInt_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(VecLlong_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(VecFloat_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(VecDoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(VecLdoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(VecFcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(VecComp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(VecLcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(SvecChar_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(SvecInt_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(SvecLlong_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(SvecFloat_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(SvecDoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(SvecLdoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(SvecFcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(SvecComp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(SvecLcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(CmatChar_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(CmatInt_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(CmatLlong_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(CmatFloat_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(CmatDoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(CmatLdoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(CmatFcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(CmatComp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(CmatLcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(ScmatChar_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(ScmatInt_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(ScmatLlong_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(ScmatFloat_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(ScmatDoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(ScmatLdoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(ScmatFcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(ScmatComp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(ScmatLcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(MatChar_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(MatInt_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(MatLlong_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(MatFloat_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(MatDoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(MatLdoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(MatFcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(MatComp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(MatLcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(Cmat3Char_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(Cmat3Int_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(Cmat3Llong_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(Cmat3Float_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(Cmat3Doub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(Cmat3Ldoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(Cmat3Fcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(Cmat3Comp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(Cmat3Lcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(Scmat3Char_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(Scmat3Int_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(Scmat3Llong_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(Scmat3Float_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(Scmat3Doub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(Scmat3Ldoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(Scmat3Fcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(Scmat3Comp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(Scmat3Lcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(Mat3Char_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(Mat3Int_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Llong sum_abs(Mat3Llong_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(Mat3Float_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(Mat3Doub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(Mat3Ldoub_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Float sum_abs(Mat3Fcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Doub sum_abs(Mat3Comp_I v)
{
    return sum_abs_v(v.p(), v.size());
}

inline Ldoub sum_abs(Mat3Lcomp_I v)
{
    return sum_abs_v(v.p(), v.size());
}


inline Long sum_abs(VecBool_I v)
{
    Long N = v.size();
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Long s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}


// maximum/minimum element (pointer version)
// max_v(), min_v()
inline Char max_v(const Char *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Char s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Char max_v(const Char *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Char s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Char max_v(Long_O ind, const Char *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Char s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Char max_v(Long_O ind, const Char *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Char s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Char min_v(const Char *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Char s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Char min_v(const Char *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Char s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Char min_v(Long_O ind, const Char *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Char s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Char min_v(Long_O ind, const Char *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Char s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Int max_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Int max_v(const Int *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Int max_v(Long_O ind, const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Int max_v(Long_O ind, const Int *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Int min_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Int min_v(const Int *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Int min_v(Long_O ind, const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Int min_v(Long_O ind, const Int *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Llong max_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Llong max_v(const Llong *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Llong max_v(Long_O ind, const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Llong max_v(Long_O ind, const Llong *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Llong min_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Llong min_v(const Llong *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Llong min_v(Long_O ind, const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Llong min_v(Long_O ind, const Llong *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Float max_v(const Float *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Float max_v(const Float *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Float max_v(Long_O ind, const Float *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Float max_v(Long_O ind, const Float *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Float min_v(const Float *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Float min_v(const Float *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Float min_v(Long_O ind, const Float *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Float min_v(Long_O ind, const Float *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Doub max_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Doub max_v(const Doub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Doub max_v(Long_O ind, const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Doub max_v(Long_O ind, const Doub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Doub min_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Doub min_v(const Doub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Doub min_v(Long_O ind, const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Doub min_v(Long_O ind, const Doub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Ldoub max_v(const Ldoub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Ldoub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Ldoub max_v(const Ldoub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Ldoub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Ldoub max_v(Long_O ind, const Ldoub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Ldoub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Ldoub max_v(Long_O ind, const Ldoub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Ldoub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Ldoub min_v(const Ldoub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Ldoub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Ldoub min_v(const Ldoub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Ldoub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Ldoub min_v(Long_O ind, const Ldoub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Ldoub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Ldoub min_v(Long_O ind, const Ldoub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Ldoub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}


inline Char max(VecChar_I v)
{ return max_v(v.p(), v.size()); }

inline Char max(Long_O ind, VecChar_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Char min(VecChar_I v)
{ return min_v(v.p(), v.size()); }

inline Char min(Long_O ind, VecChar_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Int max(VecInt_I v)
{ return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, VecInt_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Int min(VecInt_I v)
{ return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, VecInt_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Llong max(VecLlong_I v)
{ return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, VecLlong_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Llong min(VecLlong_I v)
{ return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, VecLlong_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Float max(VecFloat_I v)
{ return max_v(v.p(), v.size()); }

inline Float max(Long_O ind, VecFloat_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Float min(VecFloat_I v)
{ return min_v(v.p(), v.size()); }

inline Float min(Long_O ind, VecFloat_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Doub max(VecDoub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, VecDoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(VecDoub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, VecDoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Ldoub max(VecLdoub_I v)
{ return max_v(v.p(), v.size()); }

inline Ldoub max(Long_O ind, VecLdoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Ldoub min(VecLdoub_I v)
{ return min_v(v.p(), v.size()); }

inline Ldoub min(Long_O ind, VecLdoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Char max(MatChar_I v)
{ return max_v(v.p(), v.size()); }

inline Char max(Long_O ind, MatChar_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Char min(MatChar_I v)
{ return min_v(v.p(), v.size()); }

inline Char min(Long_O ind, MatChar_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Int max(MatInt_I v)
{ return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, MatInt_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Int min(MatInt_I v)
{ return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, MatInt_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Llong max(MatLlong_I v)
{ return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, MatLlong_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Llong min(MatLlong_I v)
{ return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, MatLlong_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Float max(MatFloat_I v)
{ return max_v(v.p(), v.size()); }

inline Float max(Long_O ind, MatFloat_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Float min(MatFloat_I v)
{ return min_v(v.p(), v.size()); }

inline Float min(Long_O ind, MatFloat_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Doub max(MatDoub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, MatDoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(MatDoub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, MatDoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Ldoub max(MatLdoub_I v)
{ return max_v(v.p(), v.size()); }

inline Ldoub max(Long_O ind, MatLdoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Ldoub min(MatLdoub_I v)
{ return min_v(v.p(), v.size()); }

inline Ldoub min(Long_O ind, MatLdoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Char max(Mat3Char_I v)
{ return max_v(v.p(), v.size()); }

inline Char max(Long_O ind, Mat3Char_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Char min(Mat3Char_I v)
{ return min_v(v.p(), v.size()); }

inline Char min(Long_O ind, Mat3Char_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Int max(Mat3Int_I v)
{ return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, Mat3Int_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Int min(Mat3Int_I v)
{ return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, Mat3Int_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Llong max(Mat3Llong_I v)
{ return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, Mat3Llong_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Llong min(Mat3Llong_I v)
{ return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, Mat3Llong_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Float max(Mat3Float_I v)
{ return max_v(v.p(), v.size()); }

inline Float max(Long_O ind, Mat3Float_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Float min(Mat3Float_I v)
{ return min_v(v.p(), v.size()); }

inline Float min(Long_O ind, Mat3Float_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Doub max(Mat3Doub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, Mat3Doub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(Mat3Doub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, Mat3Doub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Ldoub max(Mat3Ldoub_I v)
{ return max_v(v.p(), v.size()); }

inline Ldoub max(Long_O ind, Mat3Ldoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Ldoub min(Mat3Ldoub_I v)
{ return min_v(v.p(), v.size()); }

inline Ldoub min(Long_O ind, Mat3Ldoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Char max(CmatChar_I v)
{ return max_v(v.p(), v.size()); }

inline Char max(Long_O ind, CmatChar_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Char min(CmatChar_I v)
{ return min_v(v.p(), v.size()); }

inline Char min(Long_O ind, CmatChar_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Int max(CmatInt_I v)
{ return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, CmatInt_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Int min(CmatInt_I v)
{ return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, CmatInt_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Llong max(CmatLlong_I v)
{ return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, CmatLlong_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Llong min(CmatLlong_I v)
{ return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, CmatLlong_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Float max(CmatFloat_I v)
{ return max_v(v.p(), v.size()); }

inline Float max(Long_O ind, CmatFloat_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Float min(CmatFloat_I v)
{ return min_v(v.p(), v.size()); }

inline Float min(Long_O ind, CmatFloat_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Doub max(CmatDoub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, CmatDoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(CmatDoub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, CmatDoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Ldoub max(CmatLdoub_I v)
{ return max_v(v.p(), v.size()); }

inline Ldoub max(Long_O ind, CmatLdoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Ldoub min(CmatLdoub_I v)
{ return min_v(v.p(), v.size()); }

inline Ldoub min(Long_O ind, CmatLdoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Char max(Cmat3Char_I v)
{ return max_v(v.p(), v.size()); }

inline Char max(Long_O ind, Cmat3Char_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Char min(Cmat3Char_I v)
{ return min_v(v.p(), v.size()); }

inline Char min(Long_O ind, Cmat3Char_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Int max(Cmat3Int_I v)
{ return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, Cmat3Int_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Int min(Cmat3Int_I v)
{ return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, Cmat3Int_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Llong max(Cmat3Llong_I v)
{ return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, Cmat3Llong_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Llong min(Cmat3Llong_I v)
{ return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, Cmat3Llong_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Float max(Cmat3Float_I v)
{ return max_v(v.p(), v.size()); }

inline Float max(Long_O ind, Cmat3Float_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Float min(Cmat3Float_I v)
{ return min_v(v.p(), v.size()); }

inline Float min(Long_O ind, Cmat3Float_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Doub max(Cmat3Doub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, Cmat3Doub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(Cmat3Doub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, Cmat3Doub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Ldoub max(Cmat3Ldoub_I v)
{ return max_v(v.p(), v.size()); }

inline Ldoub max(Long_O ind, Cmat3Ldoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Ldoub min(Cmat3Ldoub_I v)
{ return min_v(v.p(), v.size()); }

inline Ldoub min(Long_O ind, Cmat3Ldoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Char max(SvecChar_I v)
{ return max_v(v.p(), v.size()); }

inline Char max(Long_O ind, SvecChar_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Char min(SvecChar_I v)
{ return min_v(v.p(), v.size()); }

inline Char min(Long_O ind, SvecChar_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Int max(SvecInt_I v)
{ return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, SvecInt_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Int min(SvecInt_I v)
{ return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, SvecInt_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Llong max(SvecLlong_I v)
{ return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, SvecLlong_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Llong min(SvecLlong_I v)
{ return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, SvecLlong_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Float max(SvecFloat_I v)
{ return max_v(v.p(), v.size()); }

inline Float max(Long_O ind, SvecFloat_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Float min(SvecFloat_I v)
{ return min_v(v.p(), v.size()); }

inline Float min(Long_O ind, SvecFloat_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Doub max(SvecDoub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, SvecDoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(SvecDoub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, SvecDoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Ldoub max(SvecLdoub_I v)
{ return max_v(v.p(), v.size()); }

inline Ldoub max(Long_O ind, SvecLdoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Ldoub min(SvecLdoub_I v)
{ return min_v(v.p(), v.size()); }

inline Ldoub min(Long_O ind, SvecLdoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Char max(ScmatChar_I v)
{ return max_v(v.p(), v.size()); }

inline Char max(Long_O ind, ScmatChar_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Char min(ScmatChar_I v)
{ return min_v(v.p(), v.size()); }

inline Char min(Long_O ind, ScmatChar_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Int max(ScmatInt_I v)
{ return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, ScmatInt_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Int min(ScmatInt_I v)
{ return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, ScmatInt_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Llong max(ScmatLlong_I v)
{ return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, ScmatLlong_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Llong min(ScmatLlong_I v)
{ return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, ScmatLlong_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Float max(ScmatFloat_I v)
{ return max_v(v.p(), v.size()); }

inline Float max(Long_O ind, ScmatFloat_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Float min(ScmatFloat_I v)
{ return min_v(v.p(), v.size()); }

inline Float min(Long_O ind, ScmatFloat_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Doub max(ScmatDoub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, ScmatDoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(ScmatDoub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, ScmatDoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Ldoub max(ScmatLdoub_I v)
{ return max_v(v.p(), v.size()); }

inline Ldoub max(Long_O ind, ScmatLdoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Ldoub min(ScmatLdoub_I v)
{ return min_v(v.p(), v.size()); }

inline Ldoub min(Long_O ind, ScmatLdoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Char max(Scmat3Char_I v)
{ return max_v(v.p(), v.size()); }

inline Char max(Long_O ind, Scmat3Char_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Char min(Scmat3Char_I v)
{ return min_v(v.p(), v.size()); }

inline Char min(Long_O ind, Scmat3Char_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Int max(Scmat3Int_I v)
{ return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, Scmat3Int_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Int min(Scmat3Int_I v)
{ return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, Scmat3Int_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Llong max(Scmat3Llong_I v)
{ return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, Scmat3Llong_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Llong min(Scmat3Llong_I v)
{ return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, Scmat3Llong_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Float max(Scmat3Float_I v)
{ return max_v(v.p(), v.size()); }

inline Float max(Long_O ind, Scmat3Float_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Float min(Scmat3Float_I v)
{ return min_v(v.p(), v.size()); }

inline Float min(Long_O ind, Scmat3Float_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Doub max(Scmat3Doub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, Scmat3Doub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(Scmat3Doub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, Scmat3Doub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Ldoub max(Scmat3Ldoub_I v)
{ return max_v(v.p(), v.size()); }

inline Ldoub max(Long_O ind, Scmat3Ldoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Ldoub min(Scmat3Ldoub_I v)
{ return min_v(v.p(), v.size()); }

inline Ldoub min(Long_O ind, Scmat3Ldoub_I v)
{ return min_v(ind, v.p(), v.size()); }


inline Int max_abs_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Int max_abs_v(const Int *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Llong max_abs_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Llong max_abs_v(const Llong *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Float max_abs_v(const Float *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Float max_abs_v(const Float *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Doub max_abs_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Doub max_abs_v(const Doub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Doub max_abs_v(const Comp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Doub max_abs_v(const Comp *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}


inline Int max_abs(VecInt_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Llong max_abs(VecLlong_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Float max_abs(VecFloat_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(VecDoub_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(VecComp_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(MatComp_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(CmatDoub_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(CmatComp_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(Cmat3Doub_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(Cmat3Comp_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(DvecDoub_I v)
{
    return max_abs_v(v.p(), v.size(), v.step());
}

inline Doub max_abs(DvecComp_I v)
{
    return max_abs_v(v.p(), v.size(), v.step());
}

inline Doub max_abs(SvecComp_I v)
{
    return max_abs_v(v.p(), v.size());
}


inline void mod_vvs(Char *v, const Char *v1, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v1[i], s);
}

inline void mod_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v[i], s);
}

inline void mod_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v1[i], s);
}

inline void mod_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v[i], s);
}

inline void mod_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v1[i], s);
}

inline void mod_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v[i], s);
}

inline void mod_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v1[i], s);
}

inline void mod_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v[i], s);
}


inline void mod(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    mod_vvs(v.p(), v1.p(), s, v.size());
}

inline void mod(VecInt_O v, Int_I s)
{
    mod_vs(v.p(), s, v.size());
}

inline void mod(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    mod_vvs(v.p(), v1.p(), s, v.size());
}

inline void mod(VecLlong_O v, Llong_I s)
{
    mod_vs(v.p(), s, v.size());
}


inline void real_v(Fcomp *v, Long_I N)
{
    Float *pr = (Float *)v;
    for (Long i = 1; i < 2*N; i += 2)
        pr[i] = 0;
}

inline void imag_v(Fcomp *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = imag(v[i]);
}

inline void real_v(Comp *v, Long_I N)
{
    Doub *pr = (Doub *)v;
    for (Long i = 1; i < 2*N; i += 2)
        pr[i] = 0;
}

inline void imag_v(Comp *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = imag(v[i]);
}

inline void real_v(Lcomp *v, Long_I N)
{
    Ldoub *pr = (Ldoub *)v;
    for (Long i = 1; i < 2*N; i += 2)
        pr[i] = 0;
}

inline void imag_v(Lcomp *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = imag(v[i]);
}


inline void real_vv(Doub *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = real(v1[i]); 
}

inline void imag_vv(Doub *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = imag(v1[i]); 
}

inline void real_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = real(v1[i]); 
}

inline void imag_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = imag(v1[i]); 
}


inline void real(VecComp_IO v)
{
    real_v(v.p(), v.size());
}

inline void imag(VecComp_IO v)
{
    imag_v(v.p(), v.size());
}


inline void real(VecDoub_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    real_vv(v.p(), v1.p(), v1.size());
}

inline void imag(VecDoub_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    imag_vv(v.p(), v1.p(), v1.size());
}

inline void real(VecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    real_vv(v.p(), v1.p(), v1.size());
}

inline void imag(VecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    imag_vv(v.p(), v1.p(), v1.size());
}


inline void abs_v(Int *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v[i]);
}

inline void abs_v(Llong *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v[i]);
}

inline void abs_v(Doub *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v[i]);
}

inline void abs_v(Fcomp *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v[i]);
}

inline void abs_v(Comp *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v[i]);
}

inline void abs_v(Lcomp *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v[i]);
}


inline void abs_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v1[i]); 
}

inline void abs_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v1[i]); 
}

inline void abs_vv(Doub *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v1[i]); 
}

inline void abs_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v1[i]); 
}


inline void abs(VecDoub_IO v)
{
    abs_v(v.p(), v.size());
}

inline void abs(VecComp_IO v)
{
    abs_v(v.p(), v.size());
}


inline void abs(VecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    abs_vv(v.p(), v1.p(), v1.size());
}

inline void abs(VecDoub_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    abs_vv(v.p(), v1.p(), v1.size());
}

inline void abs(VecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    abs_vv(v.p(), v1.p(), v1.size());
}


inline Bool sum_v(const Bool *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Bool s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}

inline Llong sum_v(const Char *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}

inline Llong sum_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}

inline Llong sum_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}

inline Doub sum_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}

inline Comp sum_v(const Comp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}


inline Llong prod_v(const Char *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i)
        s *= v[i];
    return s;
}

inline Llong prod_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i)
        s *= v[i];
    return s;
}

inline Llong prod_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i)
        s *= v[i];
    return s;
}

inline Doub prod_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i)
        s *= v[i];
    return s;
}

inline Comp prod_v(const Comp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = v[0];
    for (Long i = 1; i < N; ++i)
        s *= v[i];
    return s;
}


inline Llong sum(VecChar_I v)
{
    return sum_v(v.p(), v.size());
}

inline Llong prod(VecChar_I v)
{
    return prod_v(v.p(), v.size());
}

inline Llong sum(VecInt_I v)
{
    return sum_v(v.p(), v.size());
}

inline Llong prod(VecInt_I v)
{
    return prod_v(v.p(), v.size());
}

inline Llong sum(VecLlong_I v)
{
    return sum_v(v.p(), v.size());
}

inline Llong prod(VecLlong_I v)
{
    return prod_v(v.p(), v.size());
}

inline Doub sum(VecDoub_I v)
{
    return sum_v(v.p(), v.size());
}

inline Doub prod(VecDoub_I v)
{
    return prod_v(v.p(), v.size());
}

inline Doub sum(SvecDoub_I v)
{
    return sum_v(v.p(), v.size());
}

inline Doub prod(SvecDoub_I v)
{
    return prod_v(v.p(), v.size());
}

inline Comp sum(MatComp_I v)
{
    return sum_v(v.p(), v.size());
}

inline Comp prod(MatComp_I v)
{
    return prod_v(v.p(), v.size());
}

inline Doub sum(CmatDoub_I v)
{
    return sum_v(v.p(), v.size());
}

inline Doub prod(CmatDoub_I v)
{
    return prod_v(v.p(), v.size());
}

inline Comp sum(CmatComp_I v)
{
    return sum_v(v.p(), v.size());
}

inline Comp prod(CmatComp_I v)
{
    return prod_v(v.p(), v.size());
}


inline Doub norm2(VecDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(VecDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(VecComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(VecComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(MatDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(MatDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(MatComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(MatComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(CmatDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(CmatDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(CmatComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(CmatComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(Cmat3Doub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(Cmat3Doub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(Cmat3Comp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(Cmat3Comp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(SvecDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(SvecDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(SvecComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(SvecComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(DvecDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(DvecDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(DvecComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(DvecComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(ScmatDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(ScmatDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(DcmatComp_I a)
{
    const Comp *p = a.p();
    Long Nr = a.n1(), lda = a.lda();
    Doub s2 = 0;
    for (Long j = 0; j < a.n2(); ++j) {
        for (Long i = 0; i < Nr; ++i)
            s2 += abs2(p[i]);
        p += lda;
    }
    return s2;
}
inline Doub norm(DcmatComp_I v)
{
    return sqrt(norm2(v));
}


inline void resize_cpy(VecChar_IO v, Long_I N, Char_I val = 0)
{
    Long N0 = v.size();
    if (N != N0) {
        if (N0 == 0) {
            v.resize(N); copy(v, val);
        }
        else if (N == 0)
            v.resize(0);
        else {
            VecChar v1(N);
            if (N > N0) {
                veccpy(v1.p(), v.p(), N0);
                vecset(v1.p() + N0, val, N - N0);
            }
            else // N < N0
                veccpy(v1.p(), v.p(), N);
            v << v1;
        }
    }
}

inline void resize_cpy(VecInt_IO v, Long_I N, Int_I val = 0)
{
    Long N0 = v.size();
    if (N != N0) {
        if (N0 == 0) {
            v.resize(N); copy(v, val);
        }
        else if (N == 0)
            v.resize(0);
        else {
            VecInt v1(N);
            if (N > N0) {
                veccpy(v1.p(), v.p(), N0);
                vecset(v1.p() + N0, val, N - N0);
            }
            else // N < N0
                veccpy(v1.p(), v.p(), N);
            v << v1;
        }
    }
}

inline void resize_cpy(VecLlong_IO v, Long_I N, Llong_I val = 0)
{
    Long N0 = v.size();
    if (N != N0) {
        if (N0 == 0) {
            v.resize(N); copy(v, val);
        }
        else if (N == 0)
            v.resize(0);
        else {
            VecLlong v1(N);
            if (N > N0) {
                veccpy(v1.p(), v.p(), N0);
                vecset(v1.p() + N0, val, N - N0);
            }
            else // N < N0
                veccpy(v1.p(), v.p(), N);
            v << v1;
        }
    }
}

inline void resize_cpy(VecFloat_IO v, Long_I N, Float_I val = 0)
{
    Long N0 = v.size();
    if (N != N0) {
        if (N0 == 0) {
            v.resize(N); copy(v, val);
        }
        else if (N == 0)
            v.resize(0);
        else {
            VecFloat v1(N);
            if (N > N0) {
                veccpy(v1.p(), v.p(), N0);
                vecset(v1.p() + N0, val, N - N0);
            }
            else // N < N0
                veccpy(v1.p(), v.p(), N);
            v << v1;
        }
    }
}

inline void resize_cpy(VecDoub_IO v, Long_I N, Doub_I val = 0)
{
    Long N0 = v.size();
    if (N != N0) {
        if (N0 == 0) {
            v.resize(N); copy(v, val);
        }
        else if (N == 0)
            v.resize(0);
        else {
            VecDoub v1(N);
            if (N > N0) {
                veccpy(v1.p(), v.p(), N0);
                vecset(v1.p() + N0, val, N - N0);
            }
            else // N < N0
                veccpy(v1.p(), v.p(), N);
            v << v1;
        }
    }
}

inline void resize_cpy(VecLdoub_IO v, Long_I N, Ldoub_I val = 0)
{
    Long N0 = v.size();
    if (N != N0) {
        if (N0 == 0) {
            v.resize(N); copy(v, val);
        }
        else if (N == 0)
            v.resize(0);
        else {
            VecLdoub v1(N);
            if (N > N0) {
                veccpy(v1.p(), v.p(), N0);
                vecset(v1.p() + N0, val, N - N0);
            }
            else // N < N0
                veccpy(v1.p(), v.p(), N);
            v << v1;
        }
    }
}

inline void resize_cpy(VecFcomp_IO v, Long_I N, Fcomp_I val = 0)
{
    Long N0 = v.size();
    if (N != N0) {
        if (N0 == 0) {
            v.resize(N); copy(v, val);
        }
        else if (N == 0)
            v.resize(0);
        else {
            VecFcomp v1(N);
            if (N > N0) {
                veccpy(v1.p(), v.p(), N0);
                vecset(v1.p() + N0, val, N - N0);
            }
            else // N < N0
                veccpy(v1.p(), v.p(), N);
            v << v1;
        }
    }
}

inline void resize_cpy(VecComp_IO v, Long_I N, Comp_I val = 0)
{
    Long N0 = v.size();
    if (N != N0) {
        if (N0 == 0) {
            v.resize(N); copy(v, val);
        }
        else if (N == 0)
            v.resize(0);
        else {
            VecComp v1(N);
            if (N > N0) {
                veccpy(v1.p(), v.p(), N0);
                vecset(v1.p() + N0, val, N - N0);
            }
            else // N < N0
                veccpy(v1.p(), v.p(), N);
            v << v1;
        }
    }
}

inline void resize_cpy(VecLcomp_IO v, Long_I N, Lcomp_I val = 0)
{
    Long N0 = v.size();
    if (N != N0) {
        if (N0 == 0) {
            v.resize(N); copy(v, val);
        }
        else if (N == 0)
            v.resize(0);
        else {
            VecLcomp v1(N);
            if (N > N0) {
                veccpy(v1.p(), v.p(), N0);
                vecset(v1.p() + N0, val, N - N0);
            }
            else // N < N0
                veccpy(v1.p(), v.p(), N);
            v << v1;
        }
    }
}

inline void resize_cpy(CmatChar_IO v, Long_I N1, Long_I N2, Char_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N0 = N1*N2;
    Long N = N1 * N2;
    if (N1 != N10 || N2 != N20) {
        if (N0 == 0) {
            v.resize(N1, N2); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0);
        else {
            CmatChar v1(N1, N2); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20);
            copy(cut(v1, 0, N1min, 0, N2min),
                cut(v, 0, N1min, 0, N2min));
            v << v1;
        }
    }
}

inline void resize_cpy(CmatInt_IO v, Long_I N1, Long_I N2, Int_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N0 = N1*N2;
    Long N = N1 * N2;
    if (N1 != N10 || N2 != N20) {
        if (N0 == 0) {
            v.resize(N1, N2); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0);
        else {
            CmatInt v1(N1, N2); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20);
            copy(cut(v1, 0, N1min, 0, N2min),
                cut(v, 0, N1min, 0, N2min));
            v << v1;
        }
    }
}

inline void resize_cpy(CmatLlong_IO v, Long_I N1, Long_I N2, Llong_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N0 = N1*N2;
    Long N = N1 * N2;
    if (N1 != N10 || N2 != N20) {
        if (N0 == 0) {
            v.resize(N1, N2); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0);
        else {
            CmatLlong v1(N1, N2); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20);
            copy(cut(v1, 0, N1min, 0, N2min),
                cut(v, 0, N1min, 0, N2min));
            v << v1;
        }
    }
}

inline void resize_cpy(CmatFloat_IO v, Long_I N1, Long_I N2, Float_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N0 = N1*N2;
    Long N = N1 * N2;
    if (N1 != N10 || N2 != N20) {
        if (N0 == 0) {
            v.resize(N1, N2); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0);
        else {
            CmatFloat v1(N1, N2); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20);
            copy(cut(v1, 0, N1min, 0, N2min),
                cut(v, 0, N1min, 0, N2min));
            v << v1;
        }
    }
}

inline void resize_cpy(CmatDoub_IO v, Long_I N1, Long_I N2, Doub_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N0 = N1*N2;
    Long N = N1 * N2;
    if (N1 != N10 || N2 != N20) {
        if (N0 == 0) {
            v.resize(N1, N2); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0);
        else {
            CmatDoub v1(N1, N2); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20);
            copy(cut(v1, 0, N1min, 0, N2min),
                cut(v, 0, N1min, 0, N2min));
            v << v1;
        }
    }
}

inline void resize_cpy(CmatLdoub_IO v, Long_I N1, Long_I N2, Ldoub_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N0 = N1*N2;
    Long N = N1 * N2;
    if (N1 != N10 || N2 != N20) {
        if (N0 == 0) {
            v.resize(N1, N2); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0);
        else {
            CmatLdoub v1(N1, N2); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20);
            copy(cut(v1, 0, N1min, 0, N2min),
                cut(v, 0, N1min, 0, N2min));
            v << v1;
        }
    }
}

inline void resize_cpy(Cmat3Float_IO v, Long_I N1, Long_I N2, Long_I N3, Float_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N30 = v.n3(), N0 = N1*N2;
    Long N = N1 * N2 * N3;
    if (N1 != N10 || N2 != N20 || N3 != N30) {
        if (N0 == 0) {
            v.resize(N1, N2, N3); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0, 0);
        else {
            Cmat3Float v1(N1, N2, N3); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20), N3min = min(N3, N30);
            copy(cut(v1, 0, N1min, 0, N2min, 0, N3min),
                cut(v, 0, N1min, 0, N2min, 0, N3min));
            v << v1;
        }
    }
}

inline void resize_cpy(Cmat3Doub_IO v, Long_I N1, Long_I N2, Long_I N3, Doub_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N30 = v.n3(), N0 = N1*N2;
    Long N = N1 * N2 * N3;
    if (N1 != N10 || N2 != N20 || N3 != N30) {
        if (N0 == 0) {
            v.resize(N1, N2, N3); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0, 0);
        else {
            Cmat3Doub v1(N1, N2, N3); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20), N3min = min(N3, N30);
            copy(cut(v1, 0, N1min, 0, N2min, 0, N3min),
                cut(v, 0, N1min, 0, N2min, 0, N3min));
            v << v1;
        }
    }
}

inline void resize_cpy(Cmat3Ldoub_IO v, Long_I N1, Long_I N2, Long_I N3, Ldoub_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N30 = v.n3(), N0 = N1*N2;
    Long N = N1 * N2 * N3;
    if (N1 != N10 || N2 != N20 || N3 != N30) {
        if (N0 == 0) {
            v.resize(N1, N2, N3); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0, 0);
        else {
            Cmat3Ldoub v1(N1, N2, N3); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20), N3min = min(N3, N30);
            copy(cut(v1, 0, N1min, 0, N2min, 0, N3min),
                cut(v, 0, N1min, 0, N2min, 0, N3min));
            v << v1;
        }
    }
}

inline void resize_cpy(Cmat3Fcomp_IO v, Long_I N1, Long_I N2, Long_I N3, Fcomp_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N30 = v.n3(), N0 = N1*N2;
    Long N = N1 * N2 * N3;
    if (N1 != N10 || N2 != N20 || N3 != N30) {
        if (N0 == 0) {
            v.resize(N1, N2, N3); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0, 0);
        else {
            Cmat3Fcomp v1(N1, N2, N3); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20), N3min = min(N3, N30);
            copy(cut(v1, 0, N1min, 0, N2min, 0, N3min),
                cut(v, 0, N1min, 0, N2min, 0, N3min));
            v << v1;
        }
    }
}

inline void resize_cpy(Cmat3Comp_IO v, Long_I N1, Long_I N2, Long_I N3, Comp_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N30 = v.n3(), N0 = N1*N2;
    Long N = N1 * N2 * N3;
    if (N1 != N10 || N2 != N20 || N3 != N30) {
        if (N0 == 0) {
            v.resize(N1, N2, N3); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0, 0);
        else {
            Cmat3Comp v1(N1, N2, N3); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20), N3min = min(N3, N30);
            copy(cut(v1, 0, N1min, 0, N2min, 0, N3min),
                cut(v, 0, N1min, 0, N2min, 0, N3min));
            v << v1;
        }
    }
}

inline void resize_cpy(Cmat3Lcomp_IO v, Long_I N1, Long_I N2, Long_I N3, Lcomp_I val = 0)
{
    Long N10 = v.n1(), N20 = v.n2(), N30 = v.n3(), N0 = N1*N2;
    Long N = N1 * N2 * N3;
    if (N1 != N10 || N2 != N20 || N3 != N30) {
        if (N0 == 0) {
            v.resize(N1, N2, N3); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0, 0);
        else {
            Cmat3Lcomp v1(N1, N2, N3); copy(v1, val);
            Long N1min = min(N1, N10), N2min = min(N2, N20), N3min = min(N3, N30);
            copy(cut(v1, 0, N1min, 0, N2min, 0, N3min),
                cut(v, 0, N1min, 0, N2min, 0, N3min));
            v << v1;
        }
    }
}


inline void linspace_vss(Char *v, Char_I first, Char_I last, Long N)
{
    Char delta = (last - first), Nm1 = N-1;
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i / Nm1;
}

inline void linspace_vss(Int *v, Int_I first, Int_I last, Long N)
{
    Int delta = (last - first), Nm1 = N-1;
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i / Nm1;
}

inline void linspace_vss(Llong *v, Llong_I first, Llong_I last, Long N)
{
    Llong delta = (last - first), Nm1 = N-1;
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i / Nm1;
}

inline void linspace_vss(Doub *v, Doub_I first, Doub_I last, Long N)
{
    Doub delta = (last - first) / (N - 1);
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i;
}

inline void linspace_vss(Comp *v, Comp_I first, Comp_I last, Long N)
{
    Comp delta = (last - first) / (N - 1);
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i;
}


inline void linspace(VecChar_O v, Char_I first, Char_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(VecInt_O v, Int_I first, Int_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(VecLlong_O v, Llong_I first, Llong_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(VecDoub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(VecComp_O v, Comp_I first, Comp_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(MatInt_O v, Int_I first, Int_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(MatComp_O v, Comp_I first, Comp_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(CmatInt_O v, Int_I first, Int_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(CmatLlong_O v, Llong_I first, Llong_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(CmatDoub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(CmatComp_O v, Comp_I first, Comp_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(Cmat3Int_O v, Int_I first, Int_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(Cmat3Doub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(Cmat3Comp_O v, Comp_I first, Comp_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(Cmat4Int_O v, Int_I first, Int_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(Cmat4Doub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(Cmat4Comp_O v, Comp_I first, Comp_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}

inline void linspace(ScmatInt_O v, Int_I first, Int_I last)
{
    linspace_vss(v.p(), first, last, v.size());
}


inline void flip_v(Char *v, Long_I N)
{
    for (Long i = 0; i < N / 2; ++i)
        swap(v[i], v[N - i - 1]);
}

inline void flip_v(Int *v, Long_I N)
{
    for (Long i = 0; i < N / 2; ++i)
        swap(v[i], v[N - i - 1]);
}

inline void flip_v(Llong *v, Long_I N)
{
    for (Long i = 0; i < N / 2; ++i)
        swap(v[i], v[N - i - 1]);
}

inline void flip_v(Doub *v, Long_I N)
{
    for (Long i = 0; i < N / 2; ++i)
        swap(v[i], v[N - i - 1]);
}

inline void flip_v(Comp *v, Long_I N)
{
    for (Long i = 0; i < N / 2; ++i)
        swap(v[i], v[N - i - 1]);
}


inline void flip_vv(Char *v, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[N - i - 1];
}

inline void flip_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[N - i - 1];
}

inline void flip_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[N - i - 1];
}

inline void flip_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[N - i - 1];
}

inline void flip_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[N - i - 1];
}


inline void flip(VecChar_IO v)
{
    flip_v(v.p(), v.size());
}

inline void flip(VecInt_IO v)
{
    flip_v(v.p(), v.size());
}

inline void flip(VecLlong_IO v)
{
    flip_v(v.p(), v.size());
}

inline void flip(VecDoub_IO v)
{
    flip_v(v.p(), v.size());
}

inline void flip(VecComp_IO v)
{
    flip_v(v.p(), v.size());
}


inline void flip(VecChar_O v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    flip_vv(v.p(), v1.p(), v1.size());
}

inline void flip(VecInt_O v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    flip_vv(v.p(), v1.p(), v1.size());
}

inline void flip(VecLlong_O v, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    flip_vv(v.p(), v1.p(), v1.size());
}

inline void flip(VecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    flip_vv(v.p(), v1.p(), v1.size());
}

inline void flip(VecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    flip_vv(v.p(), v1.p(), v1.size());
}


inline void reorder(VecInt_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static VecInt u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(VecLlong_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static VecLlong u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(VecDoub_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static VecDoub u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(SvecChar_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static VecChar u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(SvecInt_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static VecInt u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(SvecLlong_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static VecLlong u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(SvecDoub_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static VecDoub u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(SvecComp_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static VecComp u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(vecLlong_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static VecLlong u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(vecStr_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static vecStr u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(vecStr_O v, vecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static vecStr u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(vecStr32_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static vecStr32 u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(vecStr32_O v, vecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static vecStr32 u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}


inline void trans(CmatDoub_IO v)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

inline void trans(CmatComp_IO v)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

inline void trans(MatComp_IO v)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

inline void trans(DcmatDoub_IO v)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

inline void trans(DcmatComp_IO v)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}


inline void trans(CmatLlong_O v, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(CmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(MatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(CmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(CmatComp_O v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(ScmatDoub_O v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(ScmatComp_O v, ScmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(DcmatLlong_O v, DcmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(DcmatDoub_O v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(DcmatComp_O v, DcmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}


inline void conj_v(Comp *v, Long_I N)
{
    Doub *p = (Doub *)v;
    for (Long i = 1; i < 2*N; i += 2)
        p[i] = -p[i];
}


inline void conj_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = conj(v1[i]);
}


inline void conj(VecComp_IO v)
{
    conj_v(v.p(), v.size());
}

inline void conj(CmatComp_IO v)
{
    conj_v(v.p(), v.size());
}

inline void conj(MatComp_IO v)
{
    conj_v(v.p(), v.size());
}

inline void conj(DcmatComp_IO v)
{
    for (Long j = 0; j < v.n2(); ++j)
        conj_v(v.p(), v.n1());
}


inline void conj(CmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    conj_vv(v.p(), v1.p(), v.size());
}

inline void conj(MatComp_O v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    conj_vv(v.p(), v1.p(), v.size());
}


inline void her(CmatComp_IO v)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v.n2()) SLS_ERR("illegal shape!");
#endif
    trans(v); conj(v);
}

inline void her(MatComp_IO v)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n1() != v.n2()) SLS_ERR("illegal shape!");
#endif
    trans(v); conj(v);
}


inline void her(MatComp_O v, CmatComp_I v1)
{
    trans(v, v1); conj(v);
}

inline void her(CmatComp_O v, MatComp_I v1)
{
    trans(v, v1); conj(v);
}

inline void her(CmatComp_O v, CmatComp_I v1)
{
    trans(v, v1); conj(v);
}

inline void her(DcmatComp_O v, DcmatComp_I v1)
{
    trans(v, v1); conj(v);
}


inline void plus_equals_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void plus_equals_vs(Char *v, Char_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void minus_equals_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void minus_equals_vs(Char *v, Char_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void times_equals_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Char *v, Char_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}

inline void divide_equals_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= s;
}

inline void divide_equals_vs(Char *v, Char_I s, Long_I N, Long_I step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] /= s;
}

inline void plus_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void plus_equals_vs(Int *v, Int_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void minus_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void minus_equals_vs(Int *v, Int_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void times_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Int *v, Int_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}

inline void divide_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= s;
}

inline void divide_equals_vs(Int *v, Int_I s, Long_I N, Long_I step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] /= s;
}

inline void plus_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void plus_equals_vs(Doub *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void minus_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void minus_equals_vs(Doub *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void times_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Doub *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}

inline void divide_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    times_equals_vs(v, 1/s, N);
}

inline void divide_equals_vs(Doub *v, Doub_I s, Long_I N, Long_I step)
{
    times_equals_vs(v, 1/s, N, step);
}

inline void plus_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void plus_equals_vs(Comp *v, Comp_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void minus_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void minus_equals_vs(Comp *v, Comp_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void times_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Comp *v, Comp_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}

inline void divide_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    times_equals_vs(v, 1/s, N);
}

inline void divide_equals_vs(Comp *v, Comp_I s, Long_I N, Long_I step)
{
    times_equals_vs(v, 1/s, N, step);
}


inline void operator+=(VecChar_IO v, Char_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(VecChar_IO v, Char_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(VecChar_IO v, Char_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(VecChar_IO v, Char_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(VecInt_IO v, Int_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(VecInt_IO v, Int_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(VecInt_IO v, Int_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(VecInt_IO v, Int_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(VecDoub_IO v, Doub_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(VecDoub_IO v, Doub_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(VecDoub_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(VecDoub_IO v, Doub_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(VecComp_IO v, Comp_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(VecComp_IO v, Comp_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(VecComp_IO v, Comp_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(VecComp_IO v, Comp_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(CmatChar_IO v, Char_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(CmatChar_IO v, Char_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(CmatChar_IO v, Char_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(CmatChar_IO v, Char_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(CmatInt_IO v, Int_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(CmatInt_IO v, Int_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(CmatInt_IO v, Int_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(CmatInt_IO v, Int_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(CmatDoub_IO v, Doub_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(CmatDoub_IO v, Doub_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(CmatDoub_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(CmatDoub_IO v, Doub_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(CmatComp_IO v, Doub_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(CmatComp_IO v, Doub_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(CmatComp_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(CmatComp_IO v, Doub_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(CmatComp_IO v, Comp_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(CmatComp_IO v, Comp_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(CmatComp_IO v, Comp_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(CmatComp_IO v, Comp_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(ScmatComp_IO v, Doub_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(ScmatComp_IO v, Doub_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(ScmatComp_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(ScmatComp_IO v, Doub_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(ScmatComp_IO v, Comp_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(ScmatComp_IO v, Comp_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(ScmatComp_IO v, Comp_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(ScmatComp_IO v, Comp_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(SvecDoub_IO v, Doub_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(SvecDoub_IO v, Doub_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(SvecDoub_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(SvecDoub_IO v, Doub_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(SvecComp_IO v, Doub_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(SvecComp_IO v, Doub_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(SvecComp_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(SvecComp_IO v, Doub_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(DvecComp_IO v, Doub_I s)
{
    plus_equals_vs(v.p(), s, v.size(), v.step());
}

inline void operator-=(DvecComp_IO v, Doub_I s)
{
    minus_equals_vs(v.p(), s, v.size(), v.step());
}

inline void operator*=(DvecComp_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.size(), v.step());
}

inline void operator/=(DvecComp_IO v, Doub_I s)
{
    divide_equals_vs(v.p(), s, v.size(), v.step());
}

inline void operator+=(DvecComp_IO v, Comp_I s)
{
    plus_equals_vs(v.p(), s, v.size(), v.step());
}

inline void operator-=(DvecComp_IO v, Comp_I s)
{
    minus_equals_vs(v.p(), s, v.size(), v.step());
}

inline void operator*=(DvecComp_IO v, Comp_I s)
{
    times_equals_vs(v.p(), s, v.size(), v.step());
}

inline void operator/=(DvecComp_IO v, Comp_I s)
{
    divide_equals_vs(v.p(), s, v.size(), v.step());
}

inline void operator+=(DcmatDoub_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        plus_equals_vs(&v(0,j), s, v.n1());
}

inline void operator-=(DcmatDoub_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        minus_equals_vs(&v(0,j), s, v.n1());
}

inline void operator*=(DcmatDoub_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        times_equals_vs(&v(0,j), s, v.n1());
}

inline void operator/=(DcmatDoub_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        divide_equals_vs(&v(0,j), s, v.n1());
}

inline void operator+=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        plus_equals_vs(&v(0,j), s, v.n1());
}

inline void operator-=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        minus_equals_vs(&v(0,j), s, v.n1());
}

inline void operator*=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        times_equals_vs(&v(0,j), s, v.n1());
}

inline void operator/=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        divide_equals_vs(&v(0,j), s, v.n1());
}

inline void operator+=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        plus_equals_vs(&v(0,j), s, v.n1());
}

inline void operator-=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        minus_equals_vs(&v(0,j), s, v.n1());
}

inline void operator*=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        times_equals_vs(&v(0,j), s, v.n1());
}

inline void operator/=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n2(); ++j)
        divide_equals_vs(&v(0,j), s, v.n1());
}

inline void operator+=(Cmat3Doub_IO v, Doub_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(Cmat3Doub_IO v, Doub_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(Cmat3Doub_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(Cmat3Doub_IO v, Doub_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(Cmat3Comp_IO v, Doub_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(Cmat3Comp_IO v, Doub_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(Cmat3Comp_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(Cmat3Comp_IO v, Doub_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}

inline void operator+=(Cmat3Comp_IO v, Comp_I s)
{
    plus_equals_vs(v.p(), s, v.size());
}

inline void operator-=(Cmat3Comp_IO v, Comp_I s)
{
    minus_equals_vs(v.p(), s, v.size());
}

inline void operator*=(Cmat3Comp_IO v, Comp_I s)
{
    times_equals_vs(v.p(), s, v.size());
}

inline void operator/=(Cmat3Comp_IO v, Comp_I s)
{
    divide_equals_vs(v.p(), s, v.size());
}


inline void plus_equals_vv(Char *v, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Char *v, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Char *v, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Char *v, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void plus_equals_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void plus_equals_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void plus_equals_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void plus_equals_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}


inline void operator+=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecDoub_O &v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecDoub_O &v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecDoub_O &v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecDoub_O &v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecComp_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecComp_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecComp_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecComp_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(SvecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(SvecDoub_O &v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecDoub_O &v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecDoub_O &v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecDoub_O &v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(SvecComp_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecComp_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecComp_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecComp_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(SvecComp_O &v, SvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecComp_O &v, SvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecComp_O &v, SvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecComp_O &v, SvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

// v += v
inline void operator+=(SvecComp_O &v, DvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] += v1[i];
}

// v -= v
inline void operator-=(SvecComp_O &v, DvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] -= v1[i];
}

// v *= v
inline void operator*=(SvecComp_O &v, DvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] *= v1[i];
}

// v /= v
inline void operator/=(SvecComp_O &v, DvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] /= v1[i];
}

// v += v
inline void operator+=(DvecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] += v1[i];
}

// v -= v
inline void operator-=(DvecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] -= v1[i];
}

// v *= v
inline void operator*=(DvecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] *= v1[i];
}

// v /= v
inline void operator/=(DvecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] /= v1[i];
}

inline void operator+=(ScmatDoub_O &v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(ScmatDoub_O &v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(ScmatDoub_O &v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(ScmatDoub_O &v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(ScmatComp_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(ScmatComp_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(ScmatComp_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(ScmatComp_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(ScmatComp_O &v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(ScmatComp_O &v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(ScmatComp_O &v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(ScmatComp_O &v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(ScmatComp_O &v, ScmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(ScmatComp_O &v, ScmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(ScmatComp_O &v, ScmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(ScmatComp_O &v, ScmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

// v += v (slow!)
inline void operator+=(DcmatComp_O &v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long j = 0; j < v.n2(); ++j)
        for (Long i = 0; i < v.n1(); ++i)
            v(i, j) += v1(i, j);
}

// v -= v (slow!)
inline void operator-=(DcmatComp_O &v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long j = 0; j < v.n2(); ++j)
        for (Long i = 0; i < v.n1(); ++i)
            v(i, j) -= v1(i, j);
}

// v *= v (slow!)
inline void operator*=(DcmatComp_O &v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long j = 0; j < v.n2(); ++j)
        for (Long i = 0; i < v.n1(); ++i)
            v(i, j) *= v1(i, j);
}

// v /= v (slow!)
inline void operator/=(DcmatComp_O &v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long j = 0; j < v.n2(); ++j)
        for (Long i = 0; i < v.n1(); ++i)
            v(i, j) /= v1(i, j);
}


inline void plus_vvs(Char *v, const Char *v1, Char_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Char *v, const Char *v1, Char_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Char *v, const Char *v1, Char_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Char *v, const Char *v1, Char_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / s;
        v += step1; v1 += step2;
    }
}

inline void plus_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / s;
        v += step1; v1 += step2;
    }
}

inline void plus_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / s;
        v += step1; v1 += step2;
    }
}

inline void plus_vvs(Float *v, const Float *v1, Float_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Float *v, const Float *v1, Float_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Float *v, const Float *v1, Float_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Float *v, const Float *v1, Float_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    Float inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void plus_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    Doub inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void plus_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    Doub inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void plus_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    Imag inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void plus_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    Comp inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void plus_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step1 = 1, Long_I step2 = 1)
{
    Comp inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}


inline void minus_vsv(Char *v, const Char &s, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Char *v, const Char &s, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Int *v, const Int &s, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Int *v, const Int &s, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Llong *v, const Llong &s, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Llong *v, const Llong &s, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Float *v, const Float &s, const Float *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Float *v, const Float &s, const Float *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}


inline void plus_vvv(Char *v, const Char *v1, const Char *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Char *v, const Char *v1, const Char *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Char *v, const Char *v1, const Char *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Char *v, const Char *v1, const Char *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Float *v, const Float *v1, const Float *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Float *v, const Float *v1, const Float *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Float *v, const Float *v1, const Float *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Float *v, const Float *v1, const Float *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Comp *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Comp *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Comp *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Comp *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}


inline void plus(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecChar_O v, Char_I s, VecChar_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecChar_O v, Char_I s, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecChar_O v, Char_I s, VecChar_I v1)
{
    times(v, v1, s);
}

inline void divide(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecChar_O v, Char_I s, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecInt_O v, Int_I s, VecInt_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecInt_O v, Int_I s, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecInt_O v, Int_I s, VecInt_I v1)
{
    times(v, v1, s);
}

inline void divide(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecInt_O v, Int_I s, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
    times(v, v1, s);
}

inline void divide(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
    times(v, v1, s);
}

inline void divide(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecDoub_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecDoub_O v, Doub_I s, SvecDoub_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecDoub_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecDoub_O v, Doub_I s, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecDoub_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecDoub_O v, Doub_I s, SvecDoub_I v1)
{
    times(v, v1, s);
}

inline void divide(VecDoub_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecDoub_O v, Doub_I s, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Doub_I s, VecComp_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Doub_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Doub_I s, VecComp_I v1)
{
    times(v, v1, s);
}

inline void divide(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Doub_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecComp_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Doub_I s, VecDoub_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecComp_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Doub_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Doub_I s, VecDoub_I v1)
{
    times(v, v1, s);
}

inline void divide(VecComp_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Doub_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Doub_I s, SvecDoub_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Doub_I s, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Doub_I s, SvecDoub_I v1)
{
    times(v, v1, s);
}

inline void divide(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Doub_I s, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Imag_I s, SvecDoub_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Imag_I s, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Imag_I s, SvecDoub_I v1)
{
    times(v, v1, s);
}

inline void divide(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Imag_I s, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(SvecDoub_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(SvecDoub_O v, Doub_I s, SvecDoub_I v1)
{
    plus(v, v1, s);
}

inline void minus(SvecDoub_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(SvecDoub_O v, Doub_I s, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(SvecDoub_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(SvecDoub_O v, Doub_I s, SvecDoub_I v1)
{
    times(v, v1, s);
}

inline void divide(SvecDoub_O v, SvecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(SvecDoub_O v, Doub_I s, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(SvecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(SvecDoub_O v, Doub_I s, VecDoub_I v1)
{
    plus(v, v1, s);
}

inline void minus(SvecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(SvecDoub_O v, Doub_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(SvecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(SvecDoub_O v, Doub_I s, VecDoub_I v1)
{
    times(v, v1, s);
}

inline void divide(SvecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(SvecDoub_O v, Doub_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(SvecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(SvecComp_O v, Doub_I s, VecComp_I v1)
{
    plus(v, v1, s);
}

inline void minus(SvecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(SvecComp_O v, Doub_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(SvecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(SvecComp_O v, Doub_I s, VecComp_I v1)
{
    times(v, v1, s);
}

inline void divide(SvecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(SvecComp_O v, Doub_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] = v1[i] + s;
}

inline void plus(SvecComp_O v, Doub_I s, DvecComp_I v1)
{
    plus(v, v1, s);
}

inline void minus(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] = v1[i] - s;
}

inline void minus(SvecComp_O v, Doub_I s, DvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] = s - v1[i];
}

inline void times(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] = v1[i] * s;
}

inline void times(SvecComp_O v, Doub_I s, DvecComp_I v1)
{
    times(v, v1, s);
}

inline void divide(SvecComp_O v, Doub_I s, DvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.size(); ++i)
        v[i] = s / v1[i];
}

inline void plus(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Comp_I s, VecDoub_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Comp_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Comp_I s, VecDoub_I v1)
{
    times(v, v1, s);
}

inline void divide(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Comp_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Comp_I s, VecComp_I v1)
{
    plus(v, v1, s);
}

inline void minus(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Comp_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Comp_I s, VecComp_I v1)
{
    times(v, v1, s);
}

inline void divide(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Comp_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(CmatInt_O v, Int_I s, CmatInt_I v1)
{
    plus(v, v1, s);
}

inline void minus(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(CmatInt_O v, Int_I s, CmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(CmatInt_O v, Int_I s, CmatInt_I v1)
{
    times(v, v1, s);
}

inline void divide(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(CmatInt_O v, Int_I s, CmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
    plus(v, v1, s);
}

inline void minus(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
    times(v, v1, s);
}

inline void divide(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
    plus(v, v1, s);
}

inline void minus(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
    times(v, v1, s);
}

inline void divide(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
    plus(v, v1, s);
}

inline void minus(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
    times(v, v1, s);
}

inline void divide(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
    plus(v, v1, s);
}

inline void minus(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
    times(v, v1, s);
}

inline void divide(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
    plus(v, v1, s);
}

inline void minus(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
    times(v, v1, s);
}

inline void divide(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n2(); ++j) {
        plus_vvs(p, p1, s, v.n1());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void plus(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{
    plus(v, v1, s);
}

inline void minus(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n2(); ++j) {
        minus_vvs(p, p1, s, v.n1());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void minus(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n2(); ++j) {
        minus_vsv(p, s, p1, v.n1());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void times(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n2(); ++j) {
        times_vvs(p, p1, s, v.n1());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void times(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{
    times(v, v1, s);
}

inline void divide(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n2(); ++j) {
        divide_vvs(p, p1, s, v.n1());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void divide(DcmatComp_O v, const Doub_I s, DcmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n2(); ++j) {
        divide_vsv(p, s, p1, v.n1());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void plus(Cmat3Comp_O v, Cmat3Comp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(Cmat3Comp_O v, Comp_I s, Cmat3Comp_I v1)
{
    plus(v, v1, s);
}

inline void minus(Cmat3Comp_O v, Cmat3Comp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(Cmat3Comp_O v, Comp_I s, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(Cmat3Comp_O v, Cmat3Comp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(Cmat3Comp_O v, Comp_I s, Cmat3Comp_I v1)
{
    times(v, v1, s);
}

inline void divide(Cmat3Comp_O v, Cmat3Comp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(Cmat3Comp_O v, Comp_I s, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(Cmat3Comp_O v, Cmat3Doub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(Cmat3Comp_O v, Comp_I s, Cmat3Doub_I v1)
{
    plus(v, v1, s);
}

inline void minus(Cmat3Comp_O v, Cmat3Doub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(Cmat3Comp_O v, Comp_I s, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(Cmat3Comp_O v, Cmat3Doub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(Cmat3Comp_O v, Comp_I s, Cmat3Doub_I v1)
{
    times(v, v1, s);
}

inline void divide(Cmat3Comp_O v, Cmat3Doub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(Cmat3Comp_O v, Comp_I s, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_vsv(v.p(), s, v1.p(), v1.size());
}


inline void plus(VecChar_O v, VecChar_I v1, VecChar_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(VecChar_O v, VecChar_I v1, VecChar_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(VecChar_O v, VecChar_I v1, VecChar_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(VecChar_O v, VecChar_I v1, VecChar_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(VecLlong_O v, VecLlong_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(VecLlong_O v, VecLlong_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(VecLlong_O v, VecLlong_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(VecLlong_O v, VecLlong_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(VecComp_O v, VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(VecComp_O v, VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(VecComp_O v, VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(VecComp_O v, VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v1.size(); ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v1.size(); ++i)
        v[i] = v1[i] - v2[i];
}

inline void times(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v1.size(); ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v1.size(); ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus(CmatInt_O v, CmatInt_I v1, CmatInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(CmatInt_O v, CmatInt_I v1, CmatInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(CmatInt_O v, CmatInt_I v1, CmatInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(CmatInt_O v, CmatInt_I v1, CmatInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(CmatLlong_O v, CmatLlong_I v1, CmatLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(CmatLlong_O v, CmatLlong_I v1, CmatLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(CmatLlong_O v, CmatLlong_I v1, CmatLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(CmatLlong_O v, CmatLlong_I v1, CmatLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(CmatDoub_O v, CmatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(CmatDoub_O v, CmatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(CmatDoub_O v, CmatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(CmatDoub_O v, CmatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(CmatComp_O v, CmatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(CmatComp_O v, CmatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(CmatComp_O v, CmatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(CmatComp_O v, CmatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(CmatComp_O v, CmatComp_I v1, CmatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(CmatComp_O v, CmatComp_I v1, CmatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(CmatComp_O v, CmatComp_I v1, CmatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(CmatComp_O v, CmatComp_I v1, CmatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1) || !shape_cmp(v, v2))
        SLS_ERR("wrong shape!");
#endif
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}


inline void minus_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}

inline void minus_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}

inline void minus_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}

inline void minus_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}

inline void minus_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}


inline void minus(VecInt_O v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vv(v.p(), v1.p(), v1.size());
}

inline void minus(VecLlong_O v, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vv(v.p(), v1.p(), v1.size());
}

inline void minus(VecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vv(v.p(), v1.p(), v1.size());
}

inline void minus(VecComp_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vv(v.p(), v1.p(), v1.size());
}

inline void minus(VecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vv(v.p(), v1.p(), v1.size());
}

inline void minus(ScmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_vv(v.p(), v1.p(), v1.size());
}


inline void pow_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Float *v, Float_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Doub *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Doub *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Comp *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Comp *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Comp *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}


inline void pow(VecLlong_IO v, Llong_I s)
{
    pow_vs(v.p(), s, v.size());
}

inline void pow(VecDoub_IO v, Int_I s)
{
    pow_vs(v.p(), s, v.size());
}

inline void pow(VecDoub_IO v, Doub_I s)
{
    pow_vs(v.p(), s, v.size());
}

inline void pow(VecComp_IO v, Int_I s)
{
    pow_vs(v.p(), s, v.size());
}

inline void pow(VecComp_IO v, Doub_I s)
{
    pow_vs(v.p(), s, v.size());
}

inline void pow(VecComp_IO v, Comp_I s)
{
    pow_vs(v.p(), s, v.size());
}


inline void pow_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Float *v, const Float *v1, Float_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Doub *v, const Doub *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Doub *v, const Doub *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Comp *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Comp *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}


inline void pow(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(VecDoub_O v, VecDoub_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(VecDoub_O v, VecDoub_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(VecComp_O v, VecComp_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    pow_vvs(v.p(), v1.p(), s, v1.size());
}


inline Int dot_vv(const Int *v1, const Int *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += v1[i] * v2[i];
    }
    return s;
}

inline Llong dot_vv(const Llong *v1, const Llong *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += v1[i] * v2[i];
    }
    return s;
}

inline Float dot_vv(const Float *v1, const Float *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += v1[i] * v2[i];
    }
    return s;
}

inline Doub dot_vv(const Doub *v1, const Int *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += v1[i] * v2[i];
    }
    return s;
}

inline Comp dot_vv(const Doub *v1, const Comp *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += v1[i] * v2[i];
    }
    return s;
}

inline Doub dot_vv(const Doub *v1, const Llong *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += v1[i] * v2[i];
    }
    return s;
}

inline Doub dot_vv(const Doub *v1, const Char *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += v1[i] * v2[i];
    }
    return s;
}

inline Doub dot_vv(const Doub *v1, const Doub *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += v1[i] * v2[i];
    }
    return s;
}

inline Comp dot_vv(const Comp *v1, const Int *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
    }
    return s;
}

inline Comp dot_vv(const Comp *v1, const Llong *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
    }
    return s;
}

inline Comp dot_vv(const Comp *v1, const Doub *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
    }
    return s;
}

inline Comp dot_vv(const Comp *v1, const Comp *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
    }
    return s;
}


inline Llong dot(VecLlong_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Doub dot(VecDoub_I v1, VecChar_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Doub dot(VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(VecDoub_I v1, SvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(VecComp_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(VecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Doub dot(SvecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Doub dot(SvecDoub_I v1, SvecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(SvecDoub_I v1, SvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(SvecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(SvecComp_I v1, SvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(DvecComp_I v1, SvecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    Comp sum = 0;
    for (Long i = 0; i < v1.size(); ++i)
        sum += conj(v1[i]) * v2[i];
    return sum;
}

inline Comp dot(Cmat3Comp_I v1, Cmat3Comp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(Cmat3Comp_I v1, Jcmat3Comp_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    Comp sum = 0;
    for (Long i = 0; i < v1.n1(); ++i)
        for (Long j = 0; j < v1.n2(); ++j)
            for (Long k = 0; k < v1.n3(); ++k)
                sum += conj(v1(i,j,k)) * v2(i,j,k);
    return sum;
}


inline void cumsum_vv(Int *v, const Int *v1, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    v[0] = v1[0];
    for (Long i = 1; i < N; ++i)
        v[i] = v[i - 1] + v1[i];
}

inline void cumsum_vv(Llong *v, const Int *v1, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    v[0] = v1[0];
    for (Long i = 1; i < N; ++i)
        v[i] = v[i - 1] + v1[i];
}

inline void cumsum_vv(Llong *v, const Llong *v1, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    v[0] = v1[0];
    for (Long i = 1; i < N; ++i)
        v[i] = v[i - 1] + v1[i];
}

inline void cumsum_vv(Doub *v, const Doub *v1, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    v[0] = v1[0];
    for (Long i = 1; i < N; ++i)
        v[i] = v[i - 1] + v1[i];
}


inline void cumsum(VecInt_O v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    cumsum_vv(v.p(), v1.p(), v1.size());
}

inline void cumsum(VecLlong_O v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    cumsum_vv(v.p(), v1.p(), v1.size());
}

inline void cumsum(VecLlong_O v, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    cumsum_vv(v.p(), v1.p(), v1.size());
}

inline void cumsum(VecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    cumsum_vv(v.p(), v1.p(), v1.size());
}


inline void mul(VecDoub_O y, CmatDoub_I a, VecDoub_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecDoub_O y, CmatDoub_I a, SvecDoub_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecInt_O y, CmatInt_I a, VecInt_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, CmatComp_I a, VecDoub_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, CmatComp_I a, SvecDoub_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, CmatComp_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, CmatDoub_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, ScmatComp_I a, SvecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, MatComp_I a, VecDoub_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, MatComp_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, CmatImag_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, MatDoub_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, ScmatDoub_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, ScmatComp_I a, SvecDoub_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(DvecComp_O y, DcmatDoub_I a, DvecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(SvecComp_O y, ScmatDoub_I a, SvecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(SvecComp_O y, ScmatDoub_I a, DvecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(DvecComp_O y, CmatDoub_I a, DvecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(DvecComp_O y, ScmatDoub_I a, SvecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(SvecComp_O y, MatDoub_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(SvecComp_O y, ScmatComp_I a, SvecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(SvecComp_O y, ScmatComp_I a, DvecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(SvecComp_O y, DcmatComp_I a, SvecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(SvecComp_O y, DcmatDoub_I a, SvecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}


inline void mul(VecDoub_O &y, VecDoub_I x, MatDoub_I a)
{
    Long Nr_a = a.n1(), Nc_a = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n1() || y.size() != Nc_a)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.p(), 0, Nc_a);
    for (Long j = 0; j < Nc_a; ++j) {
        for (Long i = 0; i < Nr_a; ++i)
            y[j] += x[i] * a(i, j);
    }
}

inline void mul(VecComp_O &y, VecDoub_I x, MatComp_I a)
{
    Long Nr_a = a.n1(), Nc_a = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n1() || y.size() != Nc_a)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.p(), 0, Nc_a);
    for (Long j = 0; j < Nc_a; ++j) {
        for (Long i = 0; i < Nr_a; ++i)
            y[j] += x[i] * a(i, j);
    }
}

inline void mul(VecComp_O &y, VecComp_I x, MatComp_I a)
{
    Long Nr_a = a.n1(), Nc_a = a.n2();
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n1() || y.size() != Nc_a)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.p(), 0, Nc_a);
    for (Long j = 0; j < Nc_a; ++j) {
        for (Long i = 0; i < Nr_a; ++i)
            y[j] += x[i] * a(i, j);
    }
}


inline void mul(CmatDoub_O y, CmatDoub_I a, CmatDoub_I x)
{
    Long Nr_a = a.n1(), Nc_a = a.n2(), Nc_x = x.n2();
#ifdef SLS_CHECK_SHAPES
    if (a.n2() != x.n1() || y.n1() != Nr_a || y.n2() != Nc_x)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.p(), 0, Nr_a*Nc_x);
    for (Long i = 0; i < Nr_a; ++i) {
        for (Long j = 0; j < Nc_x; ++j) {
            for (Long k = 0; k < Nc_a; ++k)
                y(i, j) += a(i, k) * x(k, j);
        }
    }
}

inline void mul(CmatComp_O y, CmatComp_I a, CmatDoub_I x)
{
    Long Nr_a = a.n1(), Nc_a = a.n2(), Nc_x = x.n2();
#ifdef SLS_CHECK_SHAPES
    if (a.n2() != x.n1() || y.n1() != Nr_a || y.n2() != Nc_x)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.p(), 0, Nr_a*Nc_x);
    for (Long i = 0; i < Nr_a; ++i) {
        for (Long j = 0; j < Nc_x; ++j) {
            for (Long k = 0; k < Nc_a; ++k)
                y(i, j) += a(i, k) * x(k, j);
        }
    }
}

inline void mul(CmatComp_O y, CmatComp_I a, CmatComp_I x)
{
    Long Nr_a = a.n1(), Nc_a = a.n2(), Nc_x = x.n2();
#ifdef SLS_CHECK_SHAPES
    if (a.n2() != x.n1() || y.n1() != Nr_a || y.n2() != Nc_x)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.p(), 0, Nr_a*Nc_x);
    for (Long i = 0; i < Nr_a; ++i) {
        for (Long j = 0; j < Nc_x; ++j) {
            for (Long k = 0; k < Nc_a; ++k)
                y(i, j) += a(i, k) * x(k, j);
        }
    }
}

inline void mul(CmatComp_O y, CmatComp_I a, MatComp_I x)
{
    Long Nr_a = a.n1(), Nc_a = a.n2(), Nc_x = x.n2();
#ifdef SLS_CHECK_SHAPES
    if (a.n2() != x.n1() || y.n1() != Nr_a || y.n2() != Nc_x)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.p(), 0, Nr_a*Nc_x);
    for (Long i = 0; i < Nr_a; ++i) {
        for (Long j = 0; j < Nc_x; ++j) {
            for (Long k = 0; k < Nc_a; ++k)
                y(i, j) += a(i, k) * x(k, j);
        }
    }
}

inline void mul(ScmatComp_O y, ScmatDoub_I a, CmatComp_I x)
{
    Long Nr_a = a.n1(), Nc_a = a.n2(), Nc_x = x.n2();
#ifdef SLS_CHECK_SHAPES
    if (a.n2() != x.n1() || y.n1() != Nr_a || y.n2() != Nc_x)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.p(), 0, Nr_a*Nc_x);
    for (Long i = 0; i < Nr_a; ++i) {
        for (Long j = 0; j < Nc_x; ++j) {
            for (Long k = 0; k < Nc_a; ++k)
                y(i, j) += a(i, k) * x(k, j);
        }
    }
}


// matrix-vector multiplication
inline void mul_gen(VecDoub_O &y, CmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, x.p(), incx, beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(VecDoub_O &y, CmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, x.p(), incx, beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(VecComp_O &y, CmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(VecComp_O &y, CmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(VecComp_O &y, CmatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.p(),
        lda, x.p(), incx, &beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(VecComp_O &y, ScmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(VecComp_O &y, ScmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.p(),
        lda, x.p(), incx, &beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(DvecComp_O &y, DcmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
    incx = x.step();
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(DvecComp_O &y, CmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(DvecComp_O &y, ScmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(DvecComp_O &y, ScmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.p(),
        lda, x.p(), incx, &beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(SvecDoub_O &y, CmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, x.p(), incx, beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(SvecDoub_O &y, ScmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, x.p(), incx, beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(SvecComp_O &y, ScmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(SvecComp_O &y, ScmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.p(),
        lda, x.p(), incx, &beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(SvecComp_O &y, ScmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.p(),
        lda, x.p(), incx, &beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(SvecComp_O &y, DcmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(SvecComp_O &y, ScmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(SvecComp_O &y, CmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(SvecComp_O &y, CmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.p(),
        lda, x.p(), incx, &beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}


inline void mul_sym(VecDoub_O &y, CmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1() || x.size() != y.size())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_dsymv(layout, CblasUpper, N1, alpha, a.p(),
        lda, x.p(), incx, beta, y.p(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_sym(VecComp_O &y, CmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n2() || y.size() != a.n1() || x.size() != y.size())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dsymv(layout, CblasUpper, N1, alpha, a.p(),
        lda, (Doub*)x.p(), 2*incx, beta, (Doub*)y.p(), 2*incy);
    // do imag part
    cblas_dsymv(layout, CblasUpper, N1, alpha, a.p(),
        lda, (Doub*)x.p()+1, 2*incx, beta, (Doub*)y.p()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}


inline void mul_gen(CmatDoub_O y, CmatDoub_I a, CmatDoub_I &x)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n2() != x.n1() || y.n1() != a.n1() || y.n2() != x.n2())
        SLS_ERR("illegal shape!");
#endif
#ifdef SLS_USE_CBLAS
    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, a.n1(), x.n2(), a.n2(), 1, (Doub*)a.p(), a.n1(), (Doub*)x.p(), a.n2(), 0, (Doub*)y.p(), a.n1());
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(CmatComp_O y, CmatComp_I a, CmatDoub_I &x)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n2() != x.n1() || y.n1() != a.n1() || y.n2() != x.n2())
        SLS_ERR("illegal shape!");
#endif
#ifdef SLS_USE_CBLAS
        SLS_WARN("not implemented with cBLAS, using slow version");
        mul(y, a, x);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(CmatComp_O y, CmatComp_I a, CmatComp_I &x)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n2() != x.n1() || y.n1() != a.n1() || y.n2() != x.n2())
        SLS_ERR("illegal shape!");
#endif
#ifdef SLS_USE_CBLAS
        Comp alpha(1,0), beta(0,0);
        cblas_zgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, a.n1(), x.n2(), a.n2(), &alpha, a.p(), a.n1(), x.p(), a.n2(), &beta, y.p(), a.n1());
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(ScmatComp_O y, ScmatDoub_I a, CmatComp_I &x)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n2() != x.n1() || y.n1() != a.n1() || y.n2() != x.n2())
        SLS_ERR("illegal shape!");
#endif
#ifdef SLS_USE_CBLAS
        SLS_WARN("not implemented with cBLAS, using slow version");
        mul(y, a, x);
#else
    mul(y, a, x);
#endif
}


// concatinate std::vector
// get unique elements from a vector
inline void operator+=(vecInt_IO v, vecInt_I v1)
{
    v.insert(v.end(), v1.begin(), v1.end());
}

inline void operator+=(vecLong_IO v, vecLong_I v1)
{
    v.insert(v.end(), v1.begin(), v1.end());
}

inline void operator+=(vecStr_IO v, vecStr_I v1)
{
    v.insert(v.end(), v1.begin(), v1.end());
}

inline void operator+=(vecStr32_IO v, vecStr32_I v1)
{
    v.insert(v.end(), v1.begin(), v1.end());
}


// get unique elements from a vector
inline void uniq_elm(VecInt_IO v)
{
    Long N = v.size(), n = 0; // already done
    for (Long i = 0; i < N; ++i) {
        Bool repeat = false;
        for (Long j = 0; j < n; ++j) {
            if (v[i] == v[j]) {
                repeat = true; break;
            }
        }
        if (!repeat) {
            v[n] = v[i];
            ++n;
        }
    }
    v.resize(n);
}

inline void uniq_elm(VecLong_IO v)
{
    Long N = v.size(), n = 0; // already done
    for (Long i = 0; i < N; ++i) {
        Bool repeat = false;
        for (Long j = 0; j < n; ++j) {
            if (v[i] == v[j]) {
                repeat = true; break;
            }
        }
        if (!repeat) {
            v[n] = v[i];
            ++n;
        }
    }
    v.resize(n);
}

inline void uniq_elm(vecInt_IO v)
{
    Long N = v.size(), n = 0; // already done
    for (Long i = 0; i < N; ++i) {
        Bool repeat = false;
        for (Long j = 0; j < n; ++j) {
            if (v[i] == v[j]) {
                repeat = true; break;
            }
        }
        if (!repeat) {
            v[n] = v[i];
            ++n;
        }
    }
    v.resize(n);
}

inline void uniq_elm(vecLong_IO v)
{
    Long N = v.size(), n = 0; // already done
    for (Long i = 0; i < N; ++i) {
        Bool repeat = false;
        for (Long j = 0; j < n; ++j) {
            if (v[i] == v[j]) {
                repeat = true; break;
            }
        }
        if (!repeat) {
            v[n] = v[i];
            ++n;
        }
    }
    v.resize(n);
}

inline void uniq_elm(vecStr_IO v)
{
    Long N = v.size(), n = 0; // already done
    for (Long i = 0; i < N; ++i) {
        Bool repeat = false;
        for (Long j = 0; j < n; ++j) {
            if (v[i] == v[j]) {
                repeat = true; break;
            }
        }
        if (!repeat) {
            v[n] = v[i];
            ++n;
        }
    }
    v.resize(n);
}

inline void uniq_elm(vecStr32_IO v)
{
    Long N = v.size(), n = 0; // already done
    for (Long i = 0; i < N; ++i) {
        Bool repeat = false;
        for (Long j = 0; j < n; ++j) {
            if (v[i] == v[j]) {
                repeat = true; break;
            }
        }
        if (!repeat) {
            v[n] = v[i];
            ++n;
        }
    }
    v.resize(n);
}


// get all unique rows from a matrix
inline void uniq_rows(CmatInt_O a, CmatInt_I a1)
{
    Long k = 0;
    a.resize(a1.n1(), a1.n2());
    for (Long i = 0; i < a1.n1(); ++i) {
        // check repeat
        Bool repeat = false;
        DvecInt_c sli1 = cut2(a1, i);
        for (Long j = 0; j < k; ++j) {
            if (cut2(a, j) == sli1) {
                repeat = true; break;
            }
        }
        if (repeat)
            continue;
        copy(cut2(a, k), sli1);
        ++k;
    }
    resize_cpy(a, k, a1.n2());
}

inline void uniq_rows(CmatLlong_O a, ScmatLlong_I a1)
{
    Long k = 0;
    a.resize(a1.n1(), a1.n2());
    for (Long i = 0; i < a1.n1(); ++i) {
        // check repeat
        Bool repeat = false;
        DvecLlong_c sli1 = cut2(a1, i);
        for (Long j = 0; j < k; ++j) {
            if (cut2(a, j) == sli1) {
                repeat = true; break;
            }
        }
        if (repeat)
            continue;
        copy(cut2(a, k), sli1);
        ++k;
    }
    resize_cpy(a, k, a1.n2());
}

inline void uniq_rows(CmatDoub_O a, CmatDoub_I a1)
{
    Long k = 0;
    a.resize(a1.n1(), a1.n2());
    for (Long i = 0; i < a1.n1(); ++i) {
        // check repeat
        Bool repeat = false;
        DvecDoub_c sli1 = cut2(a1, i);
        for (Long j = 0; j < k; ++j) {
            if (cut2(a, j) == sli1) {
                repeat = true; break;
            }
        }
        if (repeat)
            continue;
        copy(cut2(a, k), sli1);
        ++k;
    }
    resize_cpy(a, k, a1.n2());
}


inline void exp_v(Doub *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = exp(v[i]);
}

inline void exp_v(Comp *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = exp(v[i]);
}


inline void exp_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = exp(v1[i]);
}

inline void exp_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = exp(v1[i]);
}


inline void exp(VecDoub_IO v)
{
    exp_v(v.p(), v.size());
}

inline void exp(VecComp_IO v)
{
    exp_v(v.p(), v.size());
}


inline void exp(VecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    exp_vv(v.p(), v1.p(), v1.size());
}

inline void exp(VecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    exp_vv(v.p(), v1.p(), v1.size());
}


} // namespace slisc
