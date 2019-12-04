inline Int dot_vv(const Int *v1, const Int *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Int s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Llong dot_vv(const Llong *v1, const Llong *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Llong s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Float dot_vv(const Float *v1, const Float *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Float s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Doub dot_vv(const Doub *v1, const Int *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Doub s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Doub dot_vv(const Doub *v1, const Llong *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Doub s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Doub dot_vv(const Doub *v1, const Doub *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Doub s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Comp dot_vv(const Comp *v1, const Int *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
	}
    return s;
}

inline Comp dot_vv(const Comp *v1, const Llong *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
	}
    return s;
}

inline Comp dot_vv(const Comp *v1, const Doub *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
	}
    return s;
}

inline Comp dot_vv(const Comp *v1, const Comp *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
	}
    return s;
}

