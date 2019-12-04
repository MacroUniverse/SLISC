inline void plus_equals_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void minus_equals_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
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

inline void minus_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
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

inline void minus_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
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

inline void minus_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
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

