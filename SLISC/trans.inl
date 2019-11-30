inline void trans(CmatDoub_IO v)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

inline void trans(CmatComp_IO v)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

inline void trans(DcmatDoub_IO v)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

inline void trans(DcmatComp_IO v)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

