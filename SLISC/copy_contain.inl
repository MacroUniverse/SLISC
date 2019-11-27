void copy(VecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

void copy(CmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

void copy(Cmat3Doub_O v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

void copy(Jcmat3Doub_O v, Jcmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    // slow
    if (v1.size() != 0)
    for (Long k = 0; k < v.n3(); ++k)
        for (Long j = 0; j < v.n2(); ++j)
            for (Long i = 0; i < v.n1(); ++i)
                v(i, j, k) = v1(i, j, k);
}

void copy(MatDoub_O v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

void copy(Mat3Doub_O v, Mat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

