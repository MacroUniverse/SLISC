inline void mod(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    mod_vvs(v.ptr(), v1.ptr(), s, v.size());
}

inline void mod(VecInt_O v, Int_I s)
{
    mod_vs(v.ptr(), s, v.size());
}

inline void mod(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    mod_vvs(v.ptr(), v1.ptr(), s, v.size());
}

inline void mod(VecLlong_O v, Llong_I s)
{
    mod_vs(v.ptr(), s, v.size());
}

