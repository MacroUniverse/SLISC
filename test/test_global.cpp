#include "../SLISC/global.h"

void test_global()
{
	using namespace slisc;
	// test isnan()
	Doub x = NaN;
	if (!slisc::isnan(x) || slisc::isnan(1))
		SLS_ERR("failed!");
	Comp c(NaN, NaN);
	if (!slisc::isnan(c) || slisc::isnan(Comp(1,2)))
		SLS_ERR("failed!");
	if (sizeof(Char) != 1) SLS_ERR("failed!");
	if (sizeof(Int) != 4) SLS_ERR("failed!");
	if (sizeof(Llong) != 8) SLS_ERR("failed!");
	if (sizeof(Uchar) != 1) SLS_ERR("failed!");
	if (sizeof(Uint) != 4) SLS_ERR("failed!");
	if (sizeof(Ullong) != 8) SLS_ERR("failed!");
	if (sizeof(Float) != 4) SLS_ERR("failed!");
	if (sizeof(Doub) != 8) SLS_ERR("failed!");
	if (sizeof(Fcomp) != 8) SLS_ERR("failed!");
	if (sizeof(Comp) != 16) SLS_ERR("failed!");
#ifdef SLS_USE_QUAD
	if (sizeof(Qdoub) != 16) SLS_ERR("failed!");
	if (sizeof(Qcomp) != 32) SLS_ERR("failed!");
#endif
	if (sizeof(Ldoub) != 10) {
		SLS_WARN("Ldoub bytes: " + to_string(sizeof(Ldoub)));
		SLS_WARN("Lcomp bytes: " + to_string(sizeof(Lcomp)));
	}
	//% check if is 80 bit implementation
#ifndef SLS_USE_MSVC
	if (abs(std::numeric_limits<Ldoub>::max() - 1.1897314e+4932L) > 1e4926L)
		SLS_WARN("Ldoub max =" + to_string(std::numeric_limits<Ldoub>::max()));
	if (log2(std::numeric_limits<Ldoub>::epsilon()) != -63)
		SLS_WARN("Ldoub mantessa bits: =" + to_string(log2(std::numeric_limits<Ldoub>::epsilon())));
#endif
}
