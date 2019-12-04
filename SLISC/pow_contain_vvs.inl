inline void pow(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void pow(VecDoub_O v, VecDoub_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void pow(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void pow(VecComp_O v, VecComp_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void pow(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void pow(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

