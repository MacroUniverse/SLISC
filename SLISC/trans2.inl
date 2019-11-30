inline void trans(CmatLlong_O v, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(CmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(CmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(DcmatLlong_O v, DcmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(DcmatDoub_O v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(DcmatComp_O v, DcmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

