inline void plus(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecChar_O v, Char_I s, VecChar_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecChar_O v, Char_I s, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecChar_O v, Char_I s, VecChar_I v1)
{
	times(v, v1, s);
}

inline void divide(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecChar_O v, Char_I s, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecInt_O v, Int_I s, VecInt_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecInt_O v, Int_I s, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecInt_O v, Int_I s, VecInt_I v1)
{
	times(v, v1, s);
}

inline void divide(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecInt_O v, Int_I s, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
	times(v, v1, s);
}

inline void divide(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
	times(v, v1, s);
}

inline void divide(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecComp_O v, Doub_I s, VecComp_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecComp_O v, Doub_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecComp_O v, Doub_I s, VecComp_I v1)
{
	times(v, v1, s);
}

inline void divide(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecComp_O v, Doub_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecComp_O v, Comp_I s, VecDoub_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecComp_O v, Comp_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecComp_O v, Comp_I s, VecDoub_I v1)
{
	times(v, v1, s);
}

inline void divide(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecComp_O v, Comp_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecComp_O v, Comp_I s, VecComp_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecComp_O v, Comp_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecComp_O v, Comp_I s, VecComp_I v1)
{
	times(v, v1, s);
}

inline void divide(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecComp_O v, Comp_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatInt_O v, Int_I s, CmatInt_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatInt_O v, Int_I s, CmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatInt_O v, Int_I s, CmatInt_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatInt_O v, Int_I s, CmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

