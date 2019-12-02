inline Long search_row(VecInt_I v, CmatInt_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (v.size() != a.n2())
        SLS_ERR("wrong shape");
#endif
    for (Long i = start; i < a.n1(); ++i) {
		DvecInt_c sli; slice2(sli, a, i);
        if (v == sli)
            return i;
    }
    return -1;
}

inline Long search_row(VecLlong_I v, CmatLlong_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (v.size() != a.n2())
        SLS_ERR("wrong shape");
#endif
    for (Long i = start; i < a.n1(); ++i) {
		DvecLlong_c sli; slice2(sli, a, i);
        if (v == sli)
            return i;
    }
    return -1;
}

inline Long search_row(VecDoub_I v, CmatDoub_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (v.size() != a.n2())
        SLS_ERR("wrong shape");
#endif
    for (Long i = start; i < a.n1(); ++i) {
		DvecDoub_c sli; slice2(sli, a, i);
        if (v == sli)
            return i;
    }
    return -1;
}

