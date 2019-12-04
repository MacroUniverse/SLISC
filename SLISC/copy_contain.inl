inline void copy(VecChar_O v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecInt_O v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecLlong_O v, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(MatLlong_O v, MatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(MatDoub_O v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(MatComp_O v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatLlong_O v, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(MatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy_diff_major(v.ptr(), v1.ptr(), v.n2(), v.n1());
}

inline void copy(CmatDoub_O v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy_diff_major(v.ptr(), v1.ptr(), v.n1(), v.n2());
}

inline void copy(DcmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v.n1(), v.n1(), v.n2());
}

