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
	if (sizeof(Ldoub) != 10) SLS_WARN("Ldoub bytes: " + to_string(sizeof(Ldoub)));
	if (sizeof(Fcomp) != 8) SLS_ERR("failed!");
	if (sizeof(Comp) != 16) SLS_ERR("failed!");
	if (sizeof(Lcomp) != 20) SLS_WARN("Lcomp bytes: " + to_string(sizeof(Lcomp)));
#ifdef SLS_USE_QUAD
	if (sizeof(Qdoub) != 16) SLS_ERR("failed!");
	if (sizeof(Qcomp) != 32) SLS_ERR("failed!");
#endif
}
