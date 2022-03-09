// copy data from one container to another
// includes container shape checking
// all `container = container` should be implemented using copy
#pragma once
#include "compare.h"
#include "cut.h"

namespace slisc {
//  === pointer interface ===

inline void vecset(Char *v, Char_I val, Long_I n)
{
    for (Char *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Char *v, Char_I val, Long_I n, Long_I step)
{
    for (Char *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Int *v, Int_I val, Long_I n)
{
    for (Int *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Int *v, Int_I val, Long_I n, Long_I step)
{
    for (Int *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Llong *v, Llong_I val, Long_I n)
{
    for (Llong *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Llong *v, Llong_I val, Long_I n, Long_I step)
{
    for (Llong *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Float *v, Float_I val, Long_I n)
{
    for (Float *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Float *v, Float_I val, Long_I n, Long_I step)
{
    for (Float *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Doub *v, Doub_I val, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Doub *v, Doub_I val, Long_I n, Long_I step)
{
    for (Doub *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Ldoub *v, Ldoub_I val, Long_I n)
{
    for (Ldoub *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Ldoub *v, Ldoub_I val, Long_I n, Long_I step)
{
    for (Ldoub *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Fcomp *v, Fcomp_I val, Long_I n)
{
    for (Fcomp *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Fcomp *v, Fcomp_I val, Long_I n, Long_I step)
{
    for (Fcomp *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Comp *v, Comp_I val, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Comp *v, Comp_I val, Long_I n, Long_I step)
{
    for (Comp *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Lcomp *v, Lcomp_I val, Long_I n)
{
    for (Lcomp *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Lcomp *v, Lcomp_I val, Long_I n, Long_I step)
{
    for (Lcomp *p = v; p < v + n*step; p += step)
        *p = val;
}


inline void veccpy(Char *v, const Char *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Char *v, const Char *v1, Long_I step1, Long_I n)
{
    for (Char *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Char *v, Long_I step, const Char *v1, Long_I n)
{
    for (Char *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Char *v, Long_I step, const Char *v1, Long_I step1, Long_I n)
{
    Char *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Int *v, const Char *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Int *v, const Char *v1, Long_I step1, Long_I n)
{
    for (Int *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Int *v, Long_I step, const Char *v1, Long_I n)
{
    for (Int *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Int *v, Long_I step, const Char *v1, Long_I step1, Long_I n)
{
    Int *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Int *v, const Int *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Int *v, const Int *v1, Long_I step1, Long_I n)
{
    for (Int *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Int *v, Long_I step, const Int *v1, Long_I n)
{
    for (Int *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Int *v, Long_I step, const Int *v1, Long_I step1, Long_I n)
{
    Int *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Llong *v, const Char *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Llong *v, const Char *v1, Long_I step1, Long_I n)
{
    for (Llong *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Llong *v, Long_I step, const Char *v1, Long_I n)
{
    for (Llong *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Llong *v, Long_I step, const Char *v1, Long_I step1, Long_I n)
{
    Llong *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Llong *v, const Int *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Llong *v, const Int *v1, Long_I step1, Long_I n)
{
    for (Llong *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Llong *v, Long_I step, const Int *v1, Long_I n)
{
    for (Llong *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Llong *v, Long_I step, const Int *v1, Long_I step1, Long_I n)
{
    Llong *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Llong *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Llong *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Llong *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Llong *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Llong *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Llong *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Llong *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Float *v, const Float *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Float *v, const Float *v1, Long_I step1, Long_I n)
{
    for (Float *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Float *v, Long_I step, const Float *v1, Long_I n)
{
    for (Float *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Float *v, Long_I step, const Float *v1, Long_I step1, Long_I n)
{
    Float *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, const Int *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Doub *v, const Int *v1, Long_I step1, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Int *v1, Long_I n)
{
    for (Doub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Int *v1, Long_I step1, Long_I n)
{
    Doub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Doub *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Doub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Doub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, const Float *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Doub *v, const Float *v1, Long_I step1, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Float *v1, Long_I n)
{
    for (Doub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Float *v1, Long_I step1, Long_I n)
{
    Doub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, const Doub *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Doub *v, const Doub *v1, Long_I step1, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Doub *v1, Long_I n)
{
    for (Doub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Doub *v1, Long_I step1, Long_I n)
{
    Doub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Ldoub *v, const Float *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Ldoub *v, const Float *v1, Long_I step1, Long_I n)
{
    for (Ldoub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Ldoub *v, Long_I step, const Float *v1, Long_I n)
{
    for (Ldoub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Ldoub *v, Long_I step, const Float *v1, Long_I step1, Long_I n)
{
    Ldoub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Ldoub *v, const Doub *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Ldoub *v, const Doub *v1, Long_I step1, Long_I n)
{
    for (Ldoub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Ldoub *v, Long_I step, const Doub *v1, Long_I n)
{
    for (Ldoub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Ldoub *v, Long_I step, const Doub *v1, Long_I step1, Long_I n)
{
    Ldoub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Ldoub *v, const Ldoub *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Ldoub *v, const Ldoub *v1, Long_I step1, Long_I n)
{
    for (Ldoub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Ldoub *v, Long_I step, const Ldoub *v1, Long_I n)
{
    for (Ldoub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Ldoub *v, Long_I step, const Ldoub *v1, Long_I step1, Long_I n)
{
    Ldoub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Fcomp *v, const Int *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Fcomp *v, const Int *v1, Long_I step1, Long_I n)
{
    for (Fcomp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Fcomp *v, Long_I step, const Int *v1, Long_I n)
{
    for (Fcomp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Fcomp *v, Long_I step, const Int *v1, Long_I step1, Long_I n)
{
    Fcomp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Fcomp *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Fcomp *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Fcomp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Fcomp *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Fcomp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Fcomp *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Fcomp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Fcomp *v, const Float *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Fcomp *v, const Float *v1, Long_I step1, Long_I n)
{
    for (Fcomp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Fcomp *v, Long_I step, const Float *v1, Long_I n)
{
    for (Fcomp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Fcomp *v, Long_I step, const Float *v1, Long_I step1, Long_I n)
{
    Fcomp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Fcomp *v, const Fcomp *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Fcomp *v, const Fcomp *v1, Long_I step1, Long_I n)
{
    for (Fcomp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Fcomp *v, Long_I step, const Fcomp *v1, Long_I n)
{
    for (Fcomp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Fcomp *v, Long_I step, const Fcomp *v1, Long_I step1, Long_I n)
{
    Fcomp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, const Int *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Comp *v, const Int *v1, Long_I step1, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Int *v1, Long_I n)
{
    for (Comp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Int *v1, Long_I step1, Long_I n)
{
    Comp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Comp *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Comp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Comp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, const Doub *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Comp *v, const Doub *v1, Long_I step1, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Doub *v1, Long_I n)
{
    for (Comp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Doub *v1, Long_I step1, Long_I n)
{
    Comp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, const Comp *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Comp *v, const Comp *v1, Long_I step1, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Comp *v1, Long_I n)
{
    for (Comp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Comp *v1, Long_I step1, Long_I n)
{
    Comp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Lcomp *v, const Int *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Lcomp *v, const Int *v1, Long_I step1, Long_I n)
{
    for (Lcomp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Lcomp *v, Long_I step, const Int *v1, Long_I n)
{
    for (Lcomp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Lcomp *v, Long_I step, const Int *v1, Long_I step1, Long_I n)
{
    Lcomp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Lcomp *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Lcomp *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Lcomp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Lcomp *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Lcomp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Lcomp *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Lcomp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Lcomp *v, const Doub *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Lcomp *v, const Doub *v1, Long_I step1, Long_I n)
{
    for (Lcomp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Lcomp *v, Long_I step, const Doub *v1, Long_I n)
{
    for (Lcomp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Lcomp *v, Long_I step, const Doub *v1, Long_I step1, Long_I n)
{
    Lcomp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Lcomp *v, const Comp *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Lcomp *v, const Comp *v1, Long_I step1, Long_I n)
{
    for (Lcomp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Lcomp *v, Long_I step, const Comp *v1, Long_I n)
{
    for (Lcomp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Lcomp *v, Long_I step, const Comp *v1, Long_I step1, Long_I n)
{
    Lcomp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Lcomp *v, const Lcomp *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Lcomp *v, const Lcomp *v1, Long_I step1, Long_I n)
{
    for (Lcomp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Lcomp *v, Long_I step, const Lcomp *v1, Long_I n)
{
    for (Lcomp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Lcomp *v, Long_I step, const Lcomp *v1, Long_I step1, Long_I n)
{
    Lcomp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}


inline void matcpy(Char *v, Long_I lda, const Char *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Int *v, Long_I lda, const Int *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Llong *v, Long_I lda, const Llong *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Float *v, Long_I lda, const Float *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Doub *v, Long_I lda, const Doub *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Ldoub *v, Long_I lda, const Ldoub *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Fcomp *v, Long_I lda, const Fcomp *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Comp *v, Long_I lda, const Comp *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Lcomp *v, Long_I lda, const Lcomp *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}


inline void matcpy_diff_major(Llong *a2, const Llong *a1, Long_I N2, Long_I N1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = N1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += N2;
        }
    }
}

inline void matcpy_diff_major(Llong *a2, const Llong *a1, Long_I N2, Long_I lda2, Long_I N1, Long_I lda1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = lda1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += lda2;
        }
    }
}

inline void matcpy_diff_major(Doub *a2, const Doub *a1, Long_I N2, Long_I N1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = N1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += N2;
        }
    }
}

inline void matcpy_diff_major(Doub *a2, const Doub *a1, Long_I N2, Long_I lda2, Long_I N1, Long_I lda1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = lda1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += lda2;
        }
    }
}

inline void matcpy_diff_major(Comp *a2, const Comp *a1, Long_I N2, Long_I N1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = N1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += N2;
        }
    }
}

inline void matcpy_diff_major(Comp *a2, const Comp *a1, Long_I N2, Long_I lda2, Long_I N1, Long_I lda1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = lda1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += lda2;
        }
    }
}


// copy dense matrix with different majors
// lda1 is leading dimension of a1, lda2 is leading dimension of a2
// if a1 is row major and a2 is column major, N1 is number of columns, N2 is number of rows
// if a1 is column major and a2 is row major, N1 is number of rows, N2 is number of columns
// #include "matcpy_diff_major.inl"

// === container interface ===
// must use pointer version

// scalar to container
inline void copy(VecBool_O v, Bool_I s)
{
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = s;
}

inline void copy(VecChar_O v, Char_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecInt_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecLlong_O v, Llong_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecFloat_O v, Float_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecDoub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecLdoub_O v, Ldoub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecFcomp_O v, Fcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecComp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecLcomp_O v, Lcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(SvecChar_O v, Char_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(SvecInt_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(SvecLlong_O v, Llong_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(SvecFloat_O v, Float_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(SvecDoub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(SvecLdoub_O v, Ldoub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(SvecFcomp_O v, Fcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(SvecComp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(SvecLcomp_O v, Lcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(MatChar_O v, Char_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(MatInt_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(MatLlong_O v, Llong_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(MatFloat_O v, Float_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(MatDoub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(MatLdoub_O v, Ldoub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(DvecFloat_O v, Float_I s)
{
    vecset(v.p(), s, v.size(), v.step());
}

inline void copy(DvecDoub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size(), v.step());
}

inline void copy(DvecLdoub_O v, Ldoub_I s)
{
    vecset(v.p(), s, v.size(), v.step());
}

inline void copy(DvecFcomp_O v, Fcomp_I s)
{
    vecset(v.p(), s, v.size(), v.step());
}

inline void copy(DvecComp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size(), v.step());
}

inline void copy(DvecLcomp_O v, Lcomp_I s)
{
    vecset(v.p(), s, v.size(), v.step());
}

inline void copy(MatComp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Mat3Doub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatChar_O v, Char_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatInt_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatLlong_O v, Llong_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatFloat_O v, Float_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatDoub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatLdoub_O v, Ldoub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatFcomp_O v, Fcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatComp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatLcomp_O v, Lcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(ScmatChar_O v, Char_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(ScmatInt_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(ScmatLlong_O v, Llong_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(ScmatFloat_O v, Float_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(ScmatDoub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(ScmatLdoub_O v, Ldoub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(ScmatFcomp_O v, Fcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(ScmatComp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(ScmatLcomp_O v, Lcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Char_O v, Char_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Int_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Llong_O v, Llong_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Float_O v, Float_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Doub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Ldoub_O v, Ldoub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Fcomp_O v, Fcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Comp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Lcomp_O v, Lcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Char_O v, Char_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Int_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Llong_O v, Llong_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Float_O v, Float_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Doub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Ldoub_O v, Ldoub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Fcomp_O v, Fcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Comp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Lcomp_O v, Lcomp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat4Doub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(DcmatDoub_O v, Doub_I s)
{
    Long N1 = v.n0(), N2 = v.n1();
    for (Long j = 0; j < N2; ++j)
        vecset(&v(0, j), s, N1);
}

inline void copy(DcmatComp_O v, Comp_I s)
{
    Long N1 = v.n0(), N2 = v.n1();
    for (Long j = 0; j < N2; ++j)
        vecset(&v(0, j), s, N1);
}

inline void copy(Jcmat3Float_O v, Float_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = s;
}

inline void copy(Jcmat3Doub_O v, Doub_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = s;
}

inline void copy(Jcmat3Ldoub_O v, Ldoub_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = s;
}

inline void copy(Jcmat3Fcomp_O v, Fcomp_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = s;
}

inline void copy(Jcmat3Comp_O v, Comp_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = s;
}

inline void copy(Jcmat3Lcomp_O v, Lcomp_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = s;
}


// assign value to containers
inline void assign(vecBool_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(vecBool_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(vecChar_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(vecChar_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(vecInt_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(vecInt_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(vecLlong_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign2(vecLlong_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign(vecDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(vecDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(Str_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(Str_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(vecStr_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Str);
    va_end(args);
}

inline void assign2(vecStr_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Str);
    va_end(args);
}

inline void assign(VecChar_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(VecChar_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(VecInt_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(VecInt_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(VecLlong_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign2(VecLlong_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign(VecFloat_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(VecFloat_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(VecDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(VecDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(VecLdoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign2(VecLdoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign(VecFcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign2(VecFcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign(VecComp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign2(VecComp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign(VecLcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign2(VecLcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign(VecFimag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fimag);
    va_end(args);
}

inline void assign2(VecFimag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fimag);
    va_end(args);
}

inline void assign(VecImag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Imag);
    va_end(args);
}

inline void assign2(VecImag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Imag);
    va_end(args);
}

inline void assign(VecLimag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Limag);
    va_end(args);
}

inline void assign2(VecLimag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Limag);
    va_end(args);
}

inline void assign(SvecChar_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(SvecChar_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(SvecInt_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(SvecInt_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(SvecLlong_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign2(SvecLlong_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign(SvecFloat_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(SvecFloat_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(SvecDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(SvecDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(SvecLdoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign2(SvecLdoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign(SvecFcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign2(SvecFcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign(SvecComp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign2(SvecComp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign(SvecLcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign2(SvecLcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign(SvecFimag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fimag);
    va_end(args);
}

inline void assign2(SvecFimag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fimag);
    va_end(args);
}

inline void assign(SvecImag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Imag);
    va_end(args);
}

inline void assign2(SvecImag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Imag);
    va_end(args);
}

inline void assign(SvecLimag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Limag);
    va_end(args);
}

inline void assign2(SvecLimag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Limag);
    va_end(args);
}

inline void assign(DvecChar_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(DvecChar_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(DvecInt_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(DvecInt_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(DvecLlong_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign2(DvecLlong_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign(DvecFloat_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(DvecFloat_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(DvecDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(DvecDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(DvecLdoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign2(DvecLdoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign(DvecFcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign2(DvecFcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign(DvecComp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign2(DvecComp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign(DvecLcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign2(DvecLcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign(CmatChar_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(CmatChar_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(CmatInt_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(CmatInt_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(CmatLlong_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign2(CmatLlong_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign(CmatFloat_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(CmatFloat_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(CmatDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(CmatDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(CmatLdoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign2(CmatLdoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign(CmatFcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign2(CmatFcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign(CmatComp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign2(CmatComp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign(CmatLcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign2(CmatLcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign(CmatFimag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fimag);
    va_end(args);
}

inline void assign2(CmatFimag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fimag);
    va_end(args);
}

inline void assign(CmatImag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Imag);
    va_end(args);
}

inline void assign2(CmatImag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Imag);
    va_end(args);
}

inline void assign(CmatLimag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Limag);
    va_end(args);
}

inline void assign2(CmatLimag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Limag);
    va_end(args);
}

inline void assign(ScmatChar_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(ScmatChar_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(ScmatInt_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(ScmatInt_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(ScmatLlong_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign2(ScmatLlong_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign(ScmatFloat_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(ScmatFloat_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(ScmatDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(ScmatDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(ScmatLdoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign2(ScmatLdoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign(ScmatFcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign2(ScmatFcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign(ScmatComp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign2(ScmatComp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign(ScmatLcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign2(ScmatLcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign(ScmatFimag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fimag);
    va_end(args);
}

inline void assign2(ScmatFimag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fimag);
    va_end(args);
}

inline void assign(ScmatImag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Imag);
    va_end(args);
}

inline void assign2(ScmatImag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Imag);
    va_end(args);
}

inline void assign(ScmatLimag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Limag);
    va_end(args);
}

inline void assign2(ScmatLimag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Limag);
    va_end(args);
}

inline void assign(DcmatChar_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(DcmatChar_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(DcmatInt_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(DcmatInt_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(DcmatLlong_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign2(DcmatLlong_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign(DcmatFloat_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(DcmatFloat_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(DcmatDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(DcmatDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(DcmatLdoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign2(DcmatLdoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign(DcmatFcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign2(DcmatFcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign(DcmatComp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign2(DcmatComp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign(DcmatLcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign2(DcmatLcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign(Cmat3Char_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(Cmat3Char_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(Cmat3Int_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign2(Cmat3Int_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Int);
    va_end(args);
}

inline void assign(Cmat3Llong_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign2(Cmat3Llong_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Llong);
    va_end(args);
}

inline void assign(Cmat3Float_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(Cmat3Float_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(Cmat3Doub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(Cmat3Doub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(Cmat3Ldoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign2(Cmat3Ldoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Ldoub);
    va_end(args);
}

inline void assign(Cmat3Fcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign2(Cmat3Fcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fcomp);
    va_end(args);
}

inline void assign(Cmat3Comp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign2(Cmat3Comp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign(Cmat3Lcomp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign2(Cmat3Lcomp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Lcomp);
    va_end(args);
}

inline void assign(Cmat3Fimag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Fimag);
    va_end(args);
}

inline void assign2(Cmat3Fimag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Fimag);
    va_end(args);
}

inline void assign(Cmat3Imag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Imag);
    va_end(args);
}

inline void assign2(Cmat3Imag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Imag);
    va_end(args);
}

inline void assign(Cmat3Limag_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Limag);
    va_end(args);
}

inline void assign2(Cmat3Limag_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Limag);
    va_end(args);
}


// container to container
inline void copy(VecBool_O v, VecBool_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i];
}

inline void copy(VecChar_O v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(VecInt_O v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(VecInt_O v, SvecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(VecInt_O v, DvecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v1.step(), v1.size());
}

inline void copy(VecLlong_O v, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(VecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(VecDoub_O v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(VecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(SvecDoub_O v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(SvecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(SvecDoub_O v, DvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v1.step(), v1.size());
}

inline void copy(SvecComp_O v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(SvecComp_O v, SvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(SvecComp_O v, DvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v1.step(), v1.size());
}

inline void copy(VecComp_O v, DvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v1.step(), v1.size());
}

inline void copy(DvecInt_O v, DvecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v.step(), v1.p(), v1.step(), v.size());
}

inline void copy(DvecLlong_O v, DvecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v.step(), v1.p(), v1.step(), v.size());
}

inline void copy(DvecDoub_O v, DvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v.step(), v1.p(), v1.step(), v.size());
}

inline void copy(DvecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v.step(), v1.p(), v1.size());
}

inline void copy(DvecComp_O v, SvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v.step(), v1.p(), v1.size());
}

inline void copy(MatLlong_O v, MatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(MatDoub_O v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(MatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy_diff_major(v.p(), v1.p(), v.n1(), v.n0());
}

inline void copy(MatComp_O v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Mat3Doub_O v, Mat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Mat3Comp_O v, Mat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Mat3Comp_O v, Mat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatLlong_O v, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatLlong_O v, ScmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(ScmatLlong_O v, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatDoub_O v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatDoub_O v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.n0(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(CmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatComp_O v, ScmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatComp_O v, DcmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.n0(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(CmatDoub_O v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy_diff_major(v.p(), v1.p(), v.n0(), v.n1());
}

inline void copy(Cmat3Int_O v, Cmat3Int_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Cmat3Doub_O v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Cmat3Comp_O v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Cmat3Comp_O v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(ScmatInt_O v, ScmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(ScmatLlong_O v, ScmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(ScmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(ScmatDoub_O v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(ScmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(ScmatComp_O v, ScmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(DcmatChar_O v, DcmatChar_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatInt_O v, CmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v.n0(), v.n0(), v.n1());
}

inline void copy(DcmatInt_O v, DcmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatLlong_O v, DcmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatFloat_O v, DcmatFloat_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v.n0(), v.n0(), v.n1());
}

inline void copy(DcmatDoub_O v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatLdoub_O v, DcmatLdoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v.n0(), v.n0(), v.n1());
}

inline void copy(DcmatComp_O v, DcmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(Jcmat3Float_O v, Jcmat3Float_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    // slow
    if (v1.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = v1(i, j, k);
}

inline void copy(Jcmat3Doub_O v, Jcmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    // slow
    if (v1.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = v1(i, j, k);
}

inline void copy(Jcmat3Ldoub_O v, Jcmat3Ldoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    // slow
    if (v1.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = v1(i, j, k);
}

inline void copy(Jcmat3Fcomp_O v, Jcmat3Fcomp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    // slow
    if (v1.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = v1(i, j, k);
}

inline void copy(Jcmat3Comp_O v, Jcmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    // slow
    if (v1.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = v1(i, j, k);
}

inline void copy(Jcmat3Lcomp_O v, Jcmat3Lcomp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    // slow
    if (v1.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = v1(i, j, k);
}


// for sparse containers
inline void copy(McooDoub_O v, McooDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
    if (v.capacity() < v1.nnz())
        SLS_ERR("not enough capacity!");
#endif
    if (v1.nnz() == 0)
        return;
    if (v.p() == v1.p())
        SLS_ERR("self assignment is forbidden!");
    Long Nnz = v1.nnz();
    v.resize(Nnz);
    veccpy(v.p(), v1.p(), Nnz);
    veccpy(v.row_p(), v1.row_p(), Nnz);
    veccpy(v.col_p(), v1.col_p(), Nnz);
}

inline void copy(McooComp_O v, McooComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
    if (v.capacity() < v1.nnz())
        SLS_ERR("not enough capacity!");
#endif
    if (v1.nnz() == 0)
        return;
    if (v.p() == v1.p())
        SLS_ERR("self assignment is forbidden!");
    Long Nnz = v1.nnz();
    v.resize(Nnz);
    veccpy(v.p(), v1.p(), Nnz);
    veccpy(v.row_p(), v1.row_p(), Nnz);
    veccpy(v.col_p(), v1.col_p(), Nnz);
}

inline void copy(McooComp_O v, McooDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
    if (v.capacity() < v1.nnz())
        SLS_ERR("not enough capacity!");
#endif
    if (v1.nnz() == 0)
        return;
    Long Nnz = v1.nnz();
    v.resize(Nnz);
    veccpy(v.p(), v1.p(), Nnz);
    veccpy(v.row_p(), v1.row_p(), Nnz);
    veccpy(v.col_p(), v1.col_p(), Nnz);
}


// copy dense matrix to Mcoo matrix
// abs(s) < tol is considered 0

inline void copy(McooDoub_O v, CmatDoub_I v1, Doub_I tol = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long j = 0; j < v1.n1(); ++j) {
        for (Long i = 0; i < v1.n0(); ++i) {
            Doub val = v1(i, j);
            if (abs(val) > tol)
                v.push(val, i, j);
        }
    }
}

inline void copy(McooDoub_O v, ScmatDoub_I v1, Doub_I tol = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long j = 0; j < v1.n1(); ++j) {
        for (Long i = 0; i < v1.n0(); ++i) {
            Doub val = v1(i, j);
            if (abs(val) > tol)
                v.push(val, i, j);
        }
    }
}

inline void copy(McooComp_O v, CmatComp_I v1, Doub_I tol = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long j = 0; j < v1.n1(); ++j) {
        for (Long i = 0; i < v1.n0(); ++i) {
            Comp val = v1(i, j);
            if (abs(val) > tol)
                v.push(val, i, j);
        }
    }
}

inline void copy(McooComp_O v, ScmatComp_I v1, Doub_I tol = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    for (Long j = 0; j < v1.n1(); ++j) {
        for (Long i = 0; i < v1.n0(); ++i) {
            Comp val = v1(i, j);
            if (abs(val) > tol)
                v.push(val, i, j);
        }
    }
}


inline void copy(CmatDoub_O lhs, McooDoub_I rhs)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    copy(lhs, 0);
    for (Long i = 0; i < rhs.nnz(); ++i) {
        lhs(rhs.row(i), rhs.col(i)) = rhs[i];
    }
}

inline void copy(ScmatDoub_O lhs, McooDoub_I rhs)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    copy(lhs, 0);
    for (Long i = 0; i < rhs.nnz(); ++i) {
        lhs(rhs.row(i), rhs.col(i)) = rhs[i];
    }
}

inline void copy(CmatComp_O lhs, McooComp_I rhs)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    copy(lhs, 0);
    for (Long i = 0; i < rhs.nnz(); ++i) {
        lhs(rhs.row(i), rhs.col(i)) = rhs[i];
    }
}


inline void copy(CmobdInt_O lhs, CmobdInt_I rhs)
{
    copy(lhs.cmat3(), rhs.cmat3());
}

inline void copy(CmobdDoub_O lhs, CmobdDoub_I rhs)
{
    copy(lhs.cmat3(), rhs.cmat3());
}

inline void copy(CmobdComp_O lhs, CmobdDoub_I rhs)
{
    copy(lhs.cmat3(), rhs.cmat3());
}


inline void copy(CmobdInt_O lhs, McooInt_I rhs)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    Cmat3Int &c3 = lhs.cmat3();
    copy(c3, 0);
    for (Long k = 0; k < rhs.nnz(); ++k) {
        Long i = rhs.row(k), j = rhs.col(k);
        lhs.ref(i, j) = rhs[k];
    }
}

inline void copy(CmobdDoub_O lhs, McooDoub_I rhs)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    Cmat3Doub &c3 = lhs.cmat3();
    copy(c3, 0);
    for (Long k = 0; k < rhs.nnz(); ++k) {
        Long i = rhs.row(k), j = rhs.col(k);
        lhs.ref(i, j) = rhs[k];
    }
}

inline void copy(CmobdComp_O lhs, McooDoub_I rhs)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    Cmat3Comp &c3 = lhs.cmat3();
    copy(c3, 0);
    for (Long k = 0; k < rhs.nnz(); ++k) {
        Long i = rhs.row(k), j = rhs.col(k);
        lhs.ref(i, j) = rhs[k];
    }
}


// not optimized
inline void copy(CmatDoub_O lhs, CmobdDoub_I rhs)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    for (Long j = 0; j < lhs.n1(); ++j)
        for (Long i = 0; i < lhs.n0(); ++i)
            lhs(i, j) = rhs(i, j);
}


// inline void cooh2dense(@Tmat@_O lhs, @McoohTs@_I rhs)
// {
// #ifdef SLS_CHECK_SHAPES
//     if (!shape_cmp(lhs, rhs))
//         SLS_ERR("wrong shape!");
// #endif
//     copy(lhs, 0);
//     for (Long i = 0; i < rhs.nnz(); ++i) {
//         Long r = rhs.row(i), c = rhs.col(i);
//         if (r == c)
//             lhs(r, r) = rhs(i);
//         else {
//             lhs(r, c) = rhs(i);
//             lhs(c, r) = conj(rhs(i));
//         }
//     }
// }

// from MatCoo and MatCooH to dense matrix
// #include "matrix_coo2dense.inl"

// template <class T, class T1, SLS_IF(is_promo<T, T1>())>
// void copy(MatCoo<T> &v, const CmatObd<T1> &v1)
// {
// #ifdef SLS_CHECK_SHAPES
//     if (!shape_cmp(v, v1))
//         SLS_ERR("wrong shape!");
//     if (v.capacity() < v1.nnz())
//         SLS_ERR("not enough capacity!");
// #endif
//     if (v1.nnz() == 0)
//         return;
//     Long N0 = v1.n0(), N1 = N0 - 1;
//     Long N = v1.n0();
//     Long k = 0;
//     for (Long blk = 0; blk < v1.nblk(); ++blk) {
//         for (Long j = 0; j < N0; ++j) {
//             for (Long i = 0; i < N0; ++i) {
//                 Long shift = blk * N1 - 1;
//                 Long ii = shift + i, jj = shift + j;
//                 if (!((i == N1 && j == N1) || ii < 0 || jj < 0 || ii == N || jj == N))
//                     v.push(v1(k), ii, jj);
//                 ++k;
//             }
//         }
//     }
// }

DcmatDoub band(CbandDoub_IO);
DcmatDoub_c band(CbandDoub_I);

inline void copy(CbandDoub_O a, Doub_I s)
{
    copy(band(a), s);
}

DcmatComp band(CbandComp_IO);
DcmatComp_c band(CbandComp_I);

inline void copy(CbandComp_O a, Comp_I s)
{
    copy(band(a), s);
}


inline void copy(CbandDoub_O a, CbandDoub_I b)
{
#ifdef SLS_CHECK_SHAPES
    if (a.idiag() < b.nup() || a.lda() - a.idiag() - 1 < b.nlow())
        SLS_ERR("wrong shape!");
#endif
    a.reshape(b.n0(), b.nup(), b.nlow());
    copy(band(a), band(b));
}

inline void copy(CbandComp_O a, CbandComp_I b)
{
#ifdef SLS_CHECK_SHAPES
    if (a.idiag() < b.nup() || a.lda() - a.idiag() - 1 < b.nlow())
        SLS_ERR("wrong shape!");
#endif
    a.reshape(b.n0(), b.nup(), b.nlow());
    copy(band(a), band(b));
}


inline void copy(CbandDoub_O b, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        SvecDoub cut_b = cut0(b.cmat(), j);
        SvecDoub_c cut_a = cut0(a, j);
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        for (Long i = i_beg; i < i_end; ++i)
            cut_b[k + i] = cut_a[i];
    }
}

inline void copy(CmatDoub_O a, CbandDoub_I b)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecDoub cut_a = cut0(a, j);
        SvecDoub_c cut_b = cut0(b.cmat(), j);
        for (Long i = 0; i < i_beg; ++i)
            cut_a[i] = 0;
        for (Long i = i_beg; i < i_end; i++)
            cut_a[i] = cut_b[k + i];
        for (Long i = i_end; i < N1; ++i)
            cut_a[i] = 0;
    }
}

inline void copy(CbandDoub_O b, ScmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        SvecDoub cut_b = cut0(b.cmat(), j);
        SvecDoub_c cut_a = cut0(a, j);
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        for (Long i = i_beg; i < i_end; ++i)
            cut_b[k + i] = cut_a[i];
    }
}

inline void copy(ScmatDoub_O a, CbandDoub_I b)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecDoub cut_a = cut0(a, j);
        SvecDoub_c cut_b = cut0(b.cmat(), j);
        for (Long i = 0; i < i_beg; ++i)
            cut_a[i] = 0;
        for (Long i = i_beg; i < i_end; i++)
            cut_a[i] = cut_b[k + i];
        for (Long i = i_end; i < N1; ++i)
            cut_a[i] = 0;
    }
}

inline void copy(CbandComp_O b, CmatComp_I a)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        SvecComp cut_b = cut0(b.cmat(), j);
        SvecComp_c cut_a = cut0(a, j);
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        for (Long i = i_beg; i < i_end; ++i)
            cut_b[k + i] = cut_a[i];
    }
}

inline void copy(CmatComp_O a, CbandComp_I b)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecComp cut_a = cut0(a, j);
        SvecComp_c cut_b = cut0(b.cmat(), j);
        for (Long i = 0; i < i_beg; ++i)
            cut_a[i] = 0;
        for (Long i = i_beg; i < i_end; i++)
            cut_a[i] = cut_b[k + i];
        for (Long i = i_end; i < N1; ++i)
            cut_a[i] = 0;
    }
}

inline void copy(CbandComp_O b, ScmatComp_I a)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        SvecComp cut_b = cut0(b.cmat(), j);
        SvecComp_c cut_a = cut0(a, j);
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        for (Long i = i_beg; i < i_end; ++i)
            cut_b[k + i] = cut_a[i];
    }
}

inline void copy(ScmatComp_O a, CbandComp_I b)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecComp cut_a = cut0(a, j);
        SvecComp_c cut_b = cut0(b.cmat(), j);
        for (Long i = 0; i < i_beg; ++i)
            cut_a[i] = 0;
        for (Long i = i_beg; i < i_end; i++)
            cut_a[i] = cut_b[k + i];
        for (Long i = i_end; i < N1; ++i)
            cut_a[i] = 0;
    }
}

inline void copy(CbandComp_O b, ScmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        SvecComp cut_b = cut0(b.cmat(), j);
        SvecDoub_c cut_a = cut0(a, j);
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        for (Long i = i_beg; i < i_end; ++i)
            cut_b[k + i] = cut_a[i];
    }
}

inline void copy(ScmatComp_O a, CbandDoub_I b)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecComp cut_a = cut0(a, j);
        SvecDoub_c cut_b = cut0(b.cmat(), j);
        for (Long i = 0; i < i_beg; ++i)
            cut_a[i] = 0;
        for (Long i = i_beg; i < i_end; i++)
            cut_a[i] = cut_b[k + i];
        for (Long i = i_end; i < N1; ++i)
            cut_a[i] = 0;
    }
}


// void copy(Matrix<T> &b, const Matrix<T> &a, Long_I Nup, Long_I Nlow)
// {
//     Long N1 = a.n0(), N2 = a.n1();
//     for (Long i = 0; i < N1; i++) {
//         Long k = Nlow - i;
//         for (Long j = max(Long(0), i - Nlow); j < MIN(N2, i + Nup + 1); j++) {
//             b(i, k + j) = a(i, j);
//         }
//     }
// }

// template <class T, SLS_IF0(is_scalar<T>())>
// void copy(Matrix<T> &a, const Matrix<T> &b, Long_I Nup, Long_I Nlow)
// {
//     Long N1 = a.n0(), N2 = a.n1();
//     for (Long i = 0; i < N1; i++) {
//         Long k = Nlow - i;
//         for (Long j = max(Long(0), i - Nlow); j < MIN(N2, i + Nup + 1); j++) {
//             a(i, j) = b(i, k + j);
//         }
//     }
// }

// copy initializer list to containers

inline void copy(VecInt_O v, const std::initializer_list<Int> &v1)
{
    const Int *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(VecLlong_O v, const std::initializer_list<Llong> &v1)
{
    const Llong *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(VecDoub_O v, const std::initializer_list<Doub> &v1)
{
    const Doub *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(VecComp_O v, const std::initializer_list<Comp> &v1)
{
    const Comp *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(SvecInt_O v, const std::initializer_list<Int> &v1)
{
    const Int *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(SvecLlong_O v, const std::initializer_list<Llong> &v1)
{
    const Llong *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(SvecDoub_O v, const std::initializer_list<Doub> &v1)
{
    const Doub *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(SvecComp_O v, const std::initializer_list<Comp> &v1)
{
    const Comp *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(CmatInt_O v, const std::initializer_list<Int> &v1)
{
    const Int *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(CmatLlong_O v, const std::initializer_list<Llong> &v1)
{
    const Llong *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(CmatDoub_O v, const std::initializer_list<Doub> &v1)
{
    const Doub *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(CmatComp_O v, const std::initializer_list<Comp> &v1)
{
    const Comp *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(ScmatInt_O v, const std::initializer_list<Int> &v1)
{
    const Int *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(ScmatLlong_O v, const std::initializer_list<Llong> &v1)
{
    const Llong *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(ScmatDoub_O v, const std::initializer_list<Doub> &v1)
{
    const Doub *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void copy(ScmatComp_O v, const std::initializer_list<Comp> &v1)
{
    const Comp *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}


} // namespace slisc
