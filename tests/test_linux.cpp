#include "../SLISC/util/linux.h"
#ifdef SLS_USE_LINUX
#include <signal.h>
#endif

void test_linux()
{
#ifdef SLS_USE_LINUX
	using namespace slisc;
	
	// test exec_str()
	if (exec_str("echo hello world!") != "hello world!\n")
		SLS_FAIL;
	
	// test child_pid()
	{
		Int child_pid1 = fork(), child_pid2;
		if (child_pid1 < 0)
			SLS_FAIL;
		else if (child_pid1 == 0) { // in child1 process
			sleep(5);
		}
		else { // in main process
			child_pid2 = fork();
			if (child_pid2 < 0)
				SLS_FAIL;
			else if (child_pid2 == 0) { // in child2 process
				sleep(5);
			}
			else { // in main process
				vector<Int> child_pids;
				child_pid(child_pids, getpid());
				if (child_pid1 != child_pids[0])
					SLS_FAIL;
				if (child_pid2 != child_pids[1])
					SLS_FAIL;
				kill(child_pid1, SIGKILL);
				kill(child_pid2, SIGKILL);
			}
		}
	}

	// test ram_usage();
	{
#ifndef SLS_USE_MACOS
		Long old_ram = ram_usage();
		Long N = 1024*1024*100; // 100 Mib
		Char *s = new Char[N];
		s[0] = 0;
		for (Long i = 1; i < N; ++i)
			s[i] = s[i-1] + 1;
		Long new_ram = ram_usage();
#ifdef SLS_USE_ASAN
		if (abs((new_ram - old_ram)/1024 - 100.) > 20)
			SLS_FAIL;
#else
		if (abs((new_ram - old_ram)/1024 - 100.) > 1.)
			SLS_FAIL;
#endif
		delete [] s;
#endif
	}



#else
	std::cout << "---------- disabled! ----------" << std::endl;
#endif
}
