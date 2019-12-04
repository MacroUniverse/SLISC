inline void sort_r(McooChar_IO a)
{
	Long Nnz = a.nnz();
    VecLong inds(Nnz), order(Nnz);
    linspace(order, 0, Nnz - 1);
    for (Long i = 0; i < Nnz; ++i)
        inds[i] = a.n2() * a.row(i) + a.col(i);
    sort2(inds, order);
    SvecChar sli(a.ptr(), Nnz);
    reorder(sli, order);
    SvecLong sli1;
    sli1.set(a.row_ptr(), Nnz);
    reorder(sli1, order);
    sli1.set_ptr(a.col_ptr());
    reorder(sli1, order);
}

inline void sort_r(McooInt_IO a)
{
	Long Nnz = a.nnz();
    VecLong inds(Nnz), order(Nnz);
    linspace(order, 0, Nnz - 1);
    for (Long i = 0; i < Nnz; ++i)
        inds[i] = a.n2() * a.row(i) + a.col(i);
    sort2(inds, order);
    SvecInt sli(a.ptr(), Nnz);
    reorder(sli, order);
    SvecLong sli1;
    sli1.set(a.row_ptr(), Nnz);
    reorder(sli1, order);
    sli1.set_ptr(a.col_ptr());
    reorder(sli1, order);
}

inline void sort_r(McooLlong_IO a)
{
	Long Nnz = a.nnz();
    VecLong inds(Nnz), order(Nnz);
    linspace(order, 0, Nnz - 1);
    for (Long i = 0; i < Nnz; ++i)
        inds[i] = a.n2() * a.row(i) + a.col(i);
    sort2(inds, order);
    SvecLlong sli(a.ptr(), Nnz);
    reorder(sli, order);
    SvecLong sli1;
    sli1.set(a.row_ptr(), Nnz);
    reorder(sli1, order);
    sli1.set_ptr(a.col_ptr());
    reorder(sli1, order);
}

inline void sort_r(McooDoub_IO a)
{
	Long Nnz = a.nnz();
    VecLong inds(Nnz), order(Nnz);
    linspace(order, 0, Nnz - 1);
    for (Long i = 0; i < Nnz; ++i)
        inds[i] = a.n2() * a.row(i) + a.col(i);
    sort2(inds, order);
    SvecDoub sli(a.ptr(), Nnz);
    reorder(sli, order);
    SvecLong sli1;
    sli1.set(a.row_ptr(), Nnz);
    reorder(sli1, order);
    sli1.set_ptr(a.col_ptr());
    reorder(sli1, order);
}

inline void sort_r(McooComp_IO a)
{
	Long Nnz = a.nnz();
    VecLong inds(Nnz), order(Nnz);
    linspace(order, 0, Nnz - 1);
    for (Long i = 0; i < Nnz; ++i)
        inds[i] = a.n2() * a.row(i) + a.col(i);
    sort2(inds, order);
    SvecComp sli(a.ptr(), Nnz);
    reorder(sli, order);
    SvecLong sli1;
    sli1.set(a.row_ptr(), Nnz);
    reorder(sli1, order);
    sli1.set_ptr(a.col_ptr());
    reorder(sli1, order);
}

