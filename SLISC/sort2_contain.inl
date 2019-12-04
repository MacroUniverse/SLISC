void sort2(VecChar_IO v, VecLong_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
	if (!shape_cmp(v, v1))
		SLS_ERR("wrong shape!");
#endif
	sort2_vv(v.ptr(), v1.ptr(), v.size());
}

void sort2(VecInt_IO v, VecInt_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
	if (!shape_cmp(v, v1))
		SLS_ERR("wrong shape!");
#endif
	sort2_vv(v.ptr(), v1.ptr(), v.size());
}

void sort2(VecInt_IO v, VecLong_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
	if (!shape_cmp(v, v1))
		SLS_ERR("wrong shape!");
#endif
	sort2_vv(v.ptr(), v1.ptr(), v.size());
}

void sort2(VecLlong_IO v, VecLong_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
	if (!shape_cmp(v, v1))
		SLS_ERR("wrong shape!");
#endif
	sort2_vv(v.ptr(), v1.ptr(), v.size());
}

void sort2(VecDoub_IO v, VecLong_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
	if (!shape_cmp(v, v1))
		SLS_ERR("wrong shape!");
#endif
	sort2_vv(v.ptr(), v1.ptr(), v.size());
}

