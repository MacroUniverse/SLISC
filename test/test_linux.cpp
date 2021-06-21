#include "../SLISC/linux.h"
#include <signal.h>

void test_linux()
{
	using namespace slisc;
	
	// test exec_str()
	if (exec_str("echo hello world!") != "hello world!\n")
		SLS_ERR("failed!");
	
	// test child_pid()
	{
		Int child_pid1 = fork(), child_pid2;
		if (child_pid1 < 0)
			SLS_ERR("failed!");
		else if (child_pid1 == 0) { // in child1 process
			sleep(5);
		}
		else { // in main process
			child_pid2 = fork();
			if (child_pid2 < 0)
				SLS_ERR("failed!");
			else if (child_pid2 == 0) { // in child2 process
				sleep(5);
			}
			else { // in main process
				vector<Int> child_pids;
				child_pid(child_pids, getpid());
				if (child_pid1 != child_pids[0])
					SLS_ERR("failed!");
				if (child_pid2 != child_pids[1])
					SLS_ERR("failed!");
				kill(child_pid1, SIGKILL);
				kill(child_pid2, SIGKILL);
			}
		}
	}

	// test ram_usage();
	{
		Long old_ram = ram_usage();
		Long N = 1024*1024*100; // 100 Mib
		Char *s = new Char[N];
		s[0] = 0;
		for (Long i = 1; i < N; ++i)
			s[i] = s[i-1] + 1;
		Long new_ram = ram_usage();
		if (abs((new_ram - old_ram)/1024 - 100.) > 1.)
			SLS_ERR("failed!");
		delete [] s;
	}
}
