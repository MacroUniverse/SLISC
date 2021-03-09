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
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecInt_O v, Int_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecLlong_O v, Llong_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecFloat_O v, Float_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecLdoub_O v, Ldoub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecFcomp_O v, Fcomp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecLcomp_O v, Lcomp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecChar_O v, Char_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecInt_O v, Int_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecLlong_O v, Llong_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecFloat_O v, Float_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecLdoub_O v, Ldoub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecFcomp_O v, Fcomp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecLcomp_O v, Lcomp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(MatChar_O v, Char_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(MatInt_O v, Int_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(MatLlong_O v, Llong_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(MatFloat_O v, Float_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(MatDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(MatLdoub_O v, Ldoub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(DvecFloat_O v, Float_I s)
{
    vecset(v.ptr(), s, v.size(), v.step());
}

inline void copy(DvecDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size(), v.step());
}

inline void copy(DvecLdoub_O v, Ldoub_I s)
{
    vecset(v.ptr(), s, v.size(), v.step());
}

inline void copy(DvecFcomp_O v, Fcomp_I s)
{
    vecset(v.ptr(), s, v.size(), v.step());
}

inline void copy(DvecComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size(), v.step());
}

inline void copy(DvecLcomp_O v, Lcomp_I s)
{
    vecset(v.ptr(), s, v.size(), v.step());
}

inline void copy(MatComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Mat3Doub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatChar_O v, Char_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatInt_O v, Int_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatLlong_O v, Llong_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatFloat_O v, Float_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatLdoub_O v, Ldoub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatFcomp_O v, Fcomp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatLcomp_O v, Lcomp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Cmat3Char_O v, Char_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Cmat3Int_O v, Int_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Cmat3Llong_O v, Llong_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Cmat3Float_O v, Float_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Cmat3Doub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Cmat3Ldoub_O v, Ldoub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Cmat3Fcomp_O v, Fcomp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Cmat3Comp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Cmat3Lcomp_O v, Lcomp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(Cmat4Doub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(DcmatDoub_O v, Doub_I s)
{
    Long N1 = v.n1(), N2 = v.n2();
    for (Long j = 0; j < N2; ++j)
        vecset(&v(0, j), s, N1);
}

inline void copy(DcmatComp_O v, Comp_I s)
{
    Long N1 = v.n1(), N2 = v.n2();
    for (Long j = 0; j < N2; ++j)
        vecset(&v(0, j), s, N1);
}

inline void copy(Jcmat3Float_O v, Float_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
                v(i, j, k) = s;
}

inline void copy(Jcmat3Doub_O v, Doub_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
                v(i, j, k) = s;
}

inline void copy(Jcmat3Ldoub_O v, Ldoub_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
                v(i, j, k) = s;
}

inline void copy(Jcmat3Fcomp_O v, Fcomp_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
                v(i, j, k) = s;
}

inline void copy(Jcmat3Comp_O v, Comp_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
                v(i, j, k) = s;
}

inline void copy(Jcmat3Lcomp_O v, Lcomp_I s)
{
    // slow
    if (v.size() != 0)
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
                v(i, j, k) = s;
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
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecInt_O v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecInt_O v, SvecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecInt_O v, DvecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v1.step(), v1.size());
}

inline void copy(VecLlong_O v, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecDoub_O v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(SvecDoub_O v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(SvecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(SvecComp_O v, SvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(SvecComp_O v, SvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(SvecComp_O v, DvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v1.step(), v1.size());
}

inline void copy(VecComp_O v, DvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v1.step(), v1.size());
}

inline void copy(DvecInt_O v, DvecInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v.step(), v1.ptr(), v1.step(), v.size());
}

inline void copy(DvecLlong_O v, DvecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v.step(), v1.ptr(), v1.step(), v.size());
}

inline void copy(DvecDoub_O v, DvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v.step(), v1.ptr(), v1.step(), v.size());
}

inline void copy(DvecComp_O v, SvecComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v.step(), v1.ptr(), v1.size());
}

inline void copy(MatLlong_O v, MatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(MatDoub_O v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(MatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy_diff_major(v.ptr(), v1.ptr(), v.n2(), v.n1());
}

inline void copy(MatComp_O v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(Mat3Doub_O v, Mat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(Mat3Comp_O v, Mat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(Mat3Comp_O v, Mat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatLlong_O v, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatDoub_O v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatDoub_O v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.n1(), v1.ptr(), v1.lda(), v.n1(), v.n2());
}

inline void copy(CmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatComp_O v, ScmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatComp_O v, DcmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.n1(), v1.ptr(), v1.lda(), v.n1(), v.n2());
}

inline void copy(CmatDoub_O v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy_diff_major(v.ptr(), v1.ptr(), v.n1(), v.n2());
}

inline void copy(Cmat3Int_O v, Cmat3Int_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(Cmat3Doub_O v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(Cmat3Comp_O v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(Cmat3Comp_O v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(ScmatInt_O v, ScmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(ScmatLlong_O v, ScmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(ScmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(ScmatDoub_O v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(ScmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(ScmatComp_O v, ScmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(DcmatChar_O v, DcmatChar_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v1.lda(), v.n1(), v.n2());
}

inline void copy(DcmatInt_O v, CmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v.n1(), v.n1(), v.n2());
}

inline void copy(DcmatInt_O v, DcmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v1.lda(), v.n1(), v.n2());
}

inline void copy(DcmatLlong_O v, DcmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v1.lda(), v.n1(), v.n2());
}

inline void copy(DcmatFloat_O v, DcmatFloat_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v1.lda(), v.n1(), v.n2());
}

inline void copy(DcmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v.n1(), v.n1(), v.n2());
}

inline void copy(DcmatDoub_O v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v1.lda(), v.n1(), v.n2());
}

inline void copy(DcmatLdoub_O v, DcmatLdoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v1.lda(), v.n1(), v.n2());
}

inline void copy(DcmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v.n1(), v.n1(), v.n2());
}

inline void copy(DcmatComp_O v, DcmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v1.lda(), v.n1(), v.n2());
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
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
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
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
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
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
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
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
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
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
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
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
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
    if (v.ptr() == v1.ptr())
        SLS_ERR("self assignment is forbidden!");
    Long Nnz = v1.nnz();
    v.resize(Nnz);
    veccpy(v.ptr(), v1.ptr(), Nnz);
    veccpy(v.row_ptr(), v1.row_ptr(), Nnz);
    veccpy(v.col_ptr(), v1.col_ptr(), Nnz);
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
    if (v.ptr() == v1.ptr())
        SLS_ERR("self assignment is forbidden!");
    Long Nnz = v1.nnz();
    v.resize(Nnz);
    veccpy(v.ptr(), v1.ptr(), Nnz);
    veccpy(v.row_ptr(), v1.row_ptr(), Nnz);
    veccpy(v.col_ptr(), v1.col_ptr(), Nnz);
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
    veccpy(v.ptr(), v1.ptr(), Nnz);
    veccpy(v.row_ptr(), v1.row_ptr(), Nnz);
    veccpy(v.col_ptr(), v1.col_ptr(), Nnz);
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
    auto & c3 = lhs.cmat3();
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
    auto & c3 = lhs.cmat3();
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
    auto & c3 = lhs.cmat3();
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
    for (Long j = 0; j < lhs.n2(); ++j)
        for (Long i = 0; i < lhs.n1(); ++i)
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
//     Long N = v1.n1();
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
    a.reshape(b.n1(), b.nup(), b.nlow());
    copy(band(a), band(b));
}

inline void copy(CbandComp_O a, CbandComp_I b)
{
#ifdef SLS_CHECK_SHAPES
    if (a.idiag() < b.nup() || a.lda() - a.idiag() - 1 < b.nlow())
        SLS_ERR("wrong shape!");
#endif
    a.reshape(b.n1(), b.nup(), b.nlow());
    copy(band(a), band(b));
}


inline void copy(CbandDoub_O b, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(a, b))
        SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        SvecDoub cut_b = cut1(b.cmat(), j);
        SvecDoub_c cut_a = cut1(a, j);
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
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecDoub cut_a = cut1(a, j);
        SvecDoub_c cut_b = cut1(b.cmat(), j);
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
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        SvecDoub cut_b = cut1(b.cmat(), j);
        SvecDoub_c cut_a = cut1(a, j);
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
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecDoub cut_a = cut1(a, j);
        SvecDoub_c cut_b = cut1(b.cmat(), j);
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
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        SvecComp cut_b = cut1(b.cmat(), j);
        SvecComp_c cut_a = cut1(a, j);
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
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecComp cut_a = cut1(a, j);
        SvecComp_c cut_b = cut1(b.cmat(), j);
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
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        SvecComp cut_b = cut1(b.cmat(), j);
        SvecComp_c cut_a = cut1(a, j);
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
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecComp cut_a = cut1(a, j);
        SvecComp_c cut_b = cut1(b.cmat(), j);
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
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        SvecComp cut_b = cut1(b.cmat(), j);
        SvecDoub_c cut_a = cut1(a, j);
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
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecComp cut_a = cut1(a, j);
        SvecDoub_c cut_b = cut1(b.cmat(), j);
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
//     Long N1 = a.n1(), N2 = a.n2();
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
//     Long N1 = a.n1(), N2 = a.n2();
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
