inline void reorder(VecInt_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    VecInt u(N);
    for (Long i = 0; i < N; ++i) {
        u[i] = v[order[i]];
    }
    for (Long i = 0; i < N; ++i) {
        v[i] = u[i];
    }
}

inline void reorder(VecLlong_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    VecLlong u(N);
    for (Long i = 0; i < N; ++i) {
        u[i] = v[order[i]];
    }
    for (Long i = 0; i < N; ++i) {
        v[i] = u[i];
    }
}

inline void reorder(SvecInt_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    VecInt u(N);
    for (Long i = 0; i < N; ++i) {
        u[i] = v[order[i]];
    }
    for (Long i = 0; i < N; ++i) {
        v[i] = u[i];
    }
}

inline void reorder(SvecLlong_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    VecLlong u(N);
    for (Long i = 0; i < N; ++i) {
        u[i] = v[order[i]];
    }
    for (Long i = 0; i < N; ++i) {
        v[i] = u[i];
    }
}

inline void reorder(SvecDoub_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    VecDoub u(N);
    for (Long i = 0; i < N; ++i) {
        u[i] = v[order[i]];
    }
    for (Long i = 0; i < N; ++i) {
        v[i] = u[i];
    }
}

