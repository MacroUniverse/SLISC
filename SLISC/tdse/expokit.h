#pragma once
#include "../global.h"
#ifdef SLS_USE_CBLAS
#include "../dense/WorkSpace.h"
#include "expokit0.h"

namespace slisc {

// workspace requirement
inline Long expokit_expv_Comp_Nwsp(Long_I N, Long_I Nkry) {
	return sizeof(Comp)*(max(Long(10), N*(Nkry + 2) + 5*sqr(Nkry + 2) + 8)) +
		sizeof(Long)*(max(Nkry + 2, 7)) + (SLS_WSP_ALIGN-1);
}

// calculates v *= exp(mat*t)
// use ZGEXPV() for MatCoo<>, ZHEXPV() for MatCooH<>
// v cannot be empty!
// the callable `void mat_mul(Comp *y, const Comp *x)` performs matrix-vector multiplication for an N*N matrix
template <class Tmul>
inline void expv(SvecComp_IO v, Tmul &mat_mul, Doub_I t, Long_I Nkry, Doub_I mat_norm, WorkSpace &wsp, Doub_I tol = 0, Bool_I her = false)
{
#pragma omp critical
	{
		SLS_WARN("expv() debug...");
		SLS_PRINT(wsp.size()); SLS_PRINT(wsp.used());
		SLS_PRINT(wsp.free());
		SLS_PRINT(expokit_expv_Comp_Nwsp(v.size(), Nkry));
	}

	auto wsp_c = wsp.SvecComp(max(Long(10), v.size()*(Nkry + 2) + 5*sqr(Nkry + 2) + 8));
	auto wsp_i = wsp.SvecLong(max(Nkry + 2, 7));

	Long iflag;
	if (!her)
		external::ZGEXPV(v.size(), Nkry, t, v.p(),
			tol, mat_norm, wsp_c.p(), wsp_c.size(),
			wsp_i.p(), wsp_i.size(), mat_mul, 0, iflag);
	else
		external::ZHEXPV(v.size(), Nkry, t, v.p(),
			tol, mat_norm, wsp_c.p(), wsp_c.size(),
			wsp_i.p(), wsp_i.size(), mat_mul, 0, iflag);
}

template <class Tmul>
inline void expv(SvecComp_IO v, Tmul &mat_mul, Doub_I t, Long_I Nkry, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	thread_local static VecUchar wsp_mem(sizeof(Comp)*max(Long(10), v.size()*(Nkry + 2) + 5 * sqr(Nkry + 2) + 8) + sizeof(Long)*max(Nkry + 2, 7) + SLS_WSP_ALIGN);
	WorkSpace wsp(wsp_mem);
	expv(v, mat_mul, t, Nkry, mat_norm, wsp, tol, her);
}

template <class Tmul>
inline void expv(VecComp_IO v, Tmul &mat_mul, Doub_I t, Long_I Nkry, Doub_I mat_norm, WorkSpace &wsp, Doub_I tol = 0, Bool_I her = false)
{
#pragma omp critical
	{
		SLS_WARN("expv() debug...");
		SLS_PRINT(wsp.size()); SLS_PRINT(wsp.used());
		SLS_PRINT(wsp.free());
		SLS_PRINT(expokit_expv_Comp_Nwsp(v.size(), Nkry));
	}

	auto wsp_c = wsp.SvecComp(max(Long(10), v.size()*(Nkry + 2) + 5*sqr(Nkry + 2) + 8));
	auto wsp_i = wsp.SvecLong(max(Nkry + 2, 7));

	Long iflag;
	if (!her)
		external::ZGEXPV(v.size(), Nkry, t, v.p(),
			tol, mat_norm, wsp_c.p(), wsp_c.size(),
			wsp_i.p(), wsp_i.size(), mat_mul, 0, iflag);
	else
		external::ZHEXPV(v.size(), Nkry, t, v.p(),
			tol, mat_norm, wsp_c.p(), wsp_c.size(),
			wsp_i.p(), wsp_i.size(), mat_mul, 0, iflag);
}

template <class Tmul>
inline void expv(VecComp_IO v, Tmul &mat_mul, Doub_I t, Long_I Nkry, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	thread_local static VecUchar wsp_mem(sizeof(Comp)*max(Long(10), v.size()*(Nkry + 2) + 5 * sqr(Nkry + 2) + 8) + sizeof(Long)*max(Nkry + 2, 7) + SLS_WSP_ALIGN);
	WorkSpace wsp(wsp_mem);
	expv(v, mat_mul, t, Nkry, mat_norm, wsp, tol, her);
}


} // namespace slisc

#endif
