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

