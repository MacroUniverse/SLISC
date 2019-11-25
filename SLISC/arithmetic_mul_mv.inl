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

inline void mul(VecLcomp_O y, MatComp_I a, VecInt_I x)
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

inline void mul(VecInt_O y, CmatInt_I a, VecInt_I x)
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

inline void mul(DvecComp_O y, DcmatDoub_I a, DvecComp_I x)
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

inline void mul(VecComp_O y, CmatImag_I a, VecComp_I x)
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

inline void mul(VecComp_O y, MatDoub_I a, VecComp_I x)
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

inline void mul(SvecComp_O y, MatDoub_I a, VecComp_I x)
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

