inline void copy(McooDoub_O v, McooDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
    if (v.capacity() < v1.nnz())
        SLS_ERR("not enough capacity!");
#endif
    if (v1.nnz() == 0)
        return;
    if (v.ptr() == v1.ptr())
        SLS_ERR("self assignment is forbidden!");
    Long Nnz = v1.nnz();
    v.resize(Nnz);
    veccpy(v.ptr(), v1.ptr(), Nnz);
    veccpy(v.row_ptr(), v1.row_ptr(), Nnz);
    veccpy(v.col_ptr(), v1.col_ptr(), Nnz);
}

inline void copy(McooComp_O v, McooComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
    if (v.capacity() < v1.nnz())
        SLS_ERR("not enough capacity!");
#endif
    if (v1.nnz() == 0)
        return;
    if (v.ptr() == v1.ptr())
        SLS_ERR("self assignment is forbidden!");
    Long Nnz = v1.nnz();
    v.resize(Nnz);
    veccpy(v.ptr(), v1.ptr(), Nnz);
    veccpy(v.row_ptr(), v1.row_ptr(), Nnz);
    veccpy(v.col_ptr(), v1.col_ptr(), Nnz);
}

