inline void slice(SvecDoub_O sli, VecDoub_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(SvecComp_O sli, VecComp_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(SvecDoub_O sli, SvecDoub_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(SvecComp_O sli, SvecComp_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(DvecDoub_O sli, DvecDoub_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N, v.step());
}

inline void slice(DvecComp_O sli, DvecComp_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N, v.step());
}

inline void slice(DcmatDoub_O sli, CmatDoub_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}
inline void slice(ScmatDoub_O sli, CmatDoub_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	sli.set(v.ptr() + v.n1()*start2, v.n1(), N2);
}

inline void slice(DcmatComp_O sli, CmatComp_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}
inline void slice(ScmatComp_O sli, CmatComp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	sli.set(v.ptr() + v.n1()*start2, v.n1(), N2);
}

inline void slice(DcmatDoub_O sli, ScmatDoub_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}

inline void slice(DcmatComp_O sli, ScmatComp_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}

