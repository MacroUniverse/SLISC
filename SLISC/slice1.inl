inline void slice1(SvecDoub_c &sli, CmatDoub_I v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecDoub &sli, CmatDoub &v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}


inline void slice1(SvecComp_c &sli, CmatComp_I v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecComp &sli, CmatComp &v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}


inline void slice1(SvecDoub_c &sli, ScmatDoub_I v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecDoub &sli, ScmatDoub &v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}


inline void slice1(SvecComp_c &sli, ScmatComp_I v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecComp &sli, ScmatComp &v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}


