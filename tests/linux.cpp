#include "../SLISC/util/linux.h"
#if defined(SLS_USE_LINUX) || defined(SLS_USE_MACOS)
#include <signal.h>
#endif

void test_linux()
{
#if defined(SLS_USE_LINUX) || defined(SLS_USE_MACOS)
	using namespace slisc;
	
	// test exec_str()
	Str stdout;
	SLS_ASSERT(exec_str(stdout, "echo hello world!") == 0);
	if (stdout != "hello world!\n")
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
	#ifdef SLS_USE_LINUX
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
	printf("---------- disabled! ----------\n");
#endif
}

#ifndef SLS_TEST_ALL
int main() { test_linux(); }
#endif
