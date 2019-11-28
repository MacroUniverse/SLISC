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

