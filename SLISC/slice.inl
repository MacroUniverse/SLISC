inline void slice(SvecDoub &sli, VecDoub_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(SvecComp &sli, VecComp_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(SvecDoub &sli, SvecDoub_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(SvecComp &sli, SvecComp_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(DvecDoub &sli, DvecDoub_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N, v.step());
}

inline void slice(DvecComp &sli, DvecComp_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N, v.step());
}

inline void slice(DcmatDoub &sli, CmatDoub_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}
inline void slice(ScmatDoub &sli, CmatDoub_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	sli.set(v.ptr() + v.n1()*start2, v.n1(), N2);
}

inline void slice(DcmatComp &sli, CmatComp_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}
inline void slice(ScmatComp &sli, CmatComp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	sli.set(v.ptr() + v.n1()*start2, v.n1(), N2);
}

inline void slice(DcmatDoub &sli, ScmatDoub_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}

inline void slice(DcmatComp &sli, ScmatComp_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}

