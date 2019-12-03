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

