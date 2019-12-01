inline void rand(VecLlong_O v, Long_I N)
{
	Long i, Nv = v.size();
	for (i = 0; i < Nv; ++i)
		v[i] = randLong(N);
}

inline void rand(VecDoub_O &v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}

inline void rand(VecComp_O &v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}

inline void rand(SvecLlong_O v, Long_I N)
{
	Long i, Nv = v.size();
	for (i = 0; i < Nv; ++i)
		v[i] = randLong(N);
}

inline void rand(SvecDoub_O &v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}

inline void rand(SvecComp_O &v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}

inline void rand(MatLlong_O v, Long_I N)
{
	Long i, Nv = v.size();
	for (i = 0; i < Nv; ++i)
		v[i] = randLong(N);
}

inline void rand(MatDoub_O &v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}

inline void rand(MatComp_O &v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}

inline void rand(CmatLlong_O v, Long_I N)
{
	Long i, Nv = v.size();
	for (i = 0; i < Nv; ++i)
		v[i] = randLong(N);
}

inline void rand(CmatDoub_O &v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}

inline void rand(CmatComp_O &v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}

inline void rand(ScmatLlong_O v, Long_I N)
{
	Long i, Nv = v.size();
	for (i = 0; i < Nv; ++i)
		v[i] = randLong(N);
}

inline void rand(ScmatDoub_O &v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}

inline void rand(ScmatComp_O &v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}

