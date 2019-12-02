inline void mul(CmatDoub_O y, CmatDoub_I a, CmatDoub_I x)
{
    Long Nr_a = a.n1(), Nc_a = a.n2(), Nc_x = x.n2();
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.n1() || y.n1() != Nr_a || y.n2() != Nc_x)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.ptr(), 0, Nr_a*Nc_x);
    for (Long i = 0; i < Nr_a; ++i) {
        for (Long j = 0; j < Nc_x; ++j) {
            for (Long k = 0; k < Nc_a; ++k)
                y(i, j) += a(i, k) * x(k, j);
        }
    }
}

