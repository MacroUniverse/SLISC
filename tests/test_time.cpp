#include "../SLISC/util/time.h"

#ifdef NDEBUG // release mode
#define SLS_TIME_H_ERR(str) SLS_ERR(str)
#else // debug mode
void SLS_TIME_H_ERR(const std::string &str) {}
#endif

// test time utilities
int main()
{
#ifndef NDEBUG
	std::cout << "no fail in debug mode!" << std::endl;
#endif
	using namespace slisc;
	// convert sec to hh:mm:ss
	if (hhmmss(27*3600+12*60 + 5) != "03:12:05")
		SLS_FAIL;

	// current hh:mm:ss
	Str str = hhmmss();
	if (str.size() != 8 || str[2] != ':' || str[5] != ':')
		SLS_FAIL;

	Timer t; CPUTimer cput;
	// cpu time
	cput.tic();
	if (cput.toc() > 0.1)
		SLS_TIME_H_ERR("failed!");

	// natural time
	t.tic(); pause(0.114);
	if (abs(t.toc() - 0.114) > 1e-4) SLS_TIME_H_ERR("failed!");
}
