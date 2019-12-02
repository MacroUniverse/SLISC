// v += v
inline void operator+=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

