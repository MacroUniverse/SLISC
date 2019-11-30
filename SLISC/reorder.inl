inline void reorder(VecLlong_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    static VecLlong u(N);
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(VecDoub_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    static VecDoub u(N);
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

