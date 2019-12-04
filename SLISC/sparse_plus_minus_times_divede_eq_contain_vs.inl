inline void operator*=(McooDoub_IO v, Doub_I s)
{
    times_equals_vs(v.ptr(), s, v.nnz());
}

