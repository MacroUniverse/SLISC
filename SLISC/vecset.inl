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

