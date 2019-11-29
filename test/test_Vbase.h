#pragma once
#include "../SLISC/Vbase.h"
namespace slisc {

}
int test_Vbase()
{
	Long N = 3;
	VbaseDoub v(N);
	if (v.size() != 3)
		SLS_ERR("failed!");
}
