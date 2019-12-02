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

