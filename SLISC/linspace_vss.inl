inline void linspace_vss(Int *v, Int_I first, Int_I last, Long N)
{
    Int delta = (last - first) / (N - 1);
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i;
}

inline void linspace_vss(Llong *v, Llong_I first, Llong_I last, Long N)
{
    Llong delta = (last - first) / (N - 1);
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i;
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

