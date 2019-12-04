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

