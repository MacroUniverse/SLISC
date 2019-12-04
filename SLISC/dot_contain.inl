inline Llong dot(VecLlong_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Doub dot(VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Comp dot(VecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.ptr(), v2.ptr(), v2.size());
}

