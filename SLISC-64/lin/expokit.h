#pragma once
#include "../global.h"
#ifdef SLS_USE_CBLAS
#include "../dense/WorkSpace.h"
#include "expokit0.h"

namespace slisc {

// expv()
// this function is extremely slow when used in a loop! due to dynamic memory allocation
// use ZGEXPV() for MatCoo<>, ZHEXPV() for MatCooH<>
// v cannot be empty!
// the callable `void mat_mul(Comp *y, const Comp *x)` performs matrix-vector multiplication for an N*N matrix
template <class Tmul>
inline void expv(SvecComp_IO v, Tmul &mat_mul, Doub_I t, Long_I Nkrylov, Doub_I mat_norm, WorkSpace &wsp, Doub_I tol = 0, Bool_I her = false)
{
	wsp.reset();
	auto wsp_c = wsp.SvecComp(max(Long(10), v.size()*(Nkrylov + 2) + 5*sqr(Nkrylov + 2) + 8));
	auto wsp_i = wsp.SvecLong(max(Nkrylov + 2, 7));

	Long iflag;
	if (!her)
		external::ZGEXPV(v.size(), Nkrylov, t, v.p(),
			tol, mat_norm, wsp_c.p(), wsp_c.size(),
			wsp_i.p(), wsp_i.size(), mat_mul, 0, iflag);
	else
		external::ZHEXPV(v.size(), Nkrylov, t, v.p(),
			tol, mat_norm, wsp_c.p(), wsp_c.size(),
			wsp_i.p(), wsp_i.size(), mat_mul, 0, iflag);
}

template <class Tmul>
inline void expv(SvecComp_IO v, Tmul &mat_mul, Doub_I t, Long_I Nkrylov, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	thread_local static VecUchar wsp_mem(sizeof(Comp)*max(Long(10), v.size()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8) + sizeof(Long)*max(Nkrylov + 2, 7) + SLS_WSP_ALIGN);
	WorkSpace wsp(wsp_mem);
	expv(v, mat_mul, t, Nkrylov, mat_norm, wsp, tol, her);
}

template <class Tmul>
inline void expv(VecComp_IO v, Tmul &mat_mul, Doub_I t, Long_I Nkrylov, Doub_I mat_norm, WorkSpace &wsp, Doub_I tol = 0, Bool_I her = false)
{
	wsp.reset();
	auto wsp_c = wsp.SvecComp(max(Long(10), v.size()*(Nkrylov + 2) + 5*sqr(Nkrylov + 2) + 8));
	auto wsp_i = wsp.SvecLong(max(Nkrylov + 2, 7));

	Long iflag;
	if (!her)
		external::ZGEXPV(v.size(), Nkrylov, t, v.p(),
			tol, mat_norm, wsp_c.p(), wsp_c.size(),
			wsp_i.p(), wsp_i.size(), mat_mul, 0, iflag);
	else
		external::ZHEXPV(v.size(), Nkrylov, t, v.p(),
			tol, mat_norm, wsp_c.p(), wsp_c.size(),
			wsp_i.p(), wsp_i.size(), mat_mul, 0, iflag);
}

template <class Tmul>
inline void expv(VecComp_IO v, Tmul &mat_mul, Doub_I t, Long_I Nkrylov, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	thread_local static VecUchar wsp_mem(sizeof(Comp)*max(Long(10), v.size()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8) + sizeof(Long)*max(Nkrylov + 2, 7) + SLS_WSP_ALIGN);
	WorkSpace wsp(wsp_mem);
	expv(v, mat_mul, t, Nkrylov, mat_norm, wsp, tol, her);
}


} // namespace slisc

#endif
