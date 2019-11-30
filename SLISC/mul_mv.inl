inline void mul(VecDoub_O y, CmatDoub_I a, VecDoub_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPE
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, CmatComp_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPE
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, CmatDoub_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPE
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, MatComp_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPE
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

