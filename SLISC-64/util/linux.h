// linux utilities
#pragma once
#include "../str/str.h"

#if defined(SLS_USE_LINUX) || defined(SLS_USE_MACOS)
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include <unistd.h>

namespace slisc {

// execute a command in default shell and get the output to stdout
// return exit code
// use `int system(cmd)` if you don't need stdout
inline int exec_str(Str_O stdout, Str_I cmd)
{
	if (cmd.empty())
		SLS_ERR("exec_str(): cmd is empty()");

	char buffer[256];
	FILE *pipe = popen(cmd.c_str(), "r");
	if (!pipe)
		throw runtime_error("popen() failed!");

	stdout.clear();
	while (fgets(buffer, sizeof(buffer), fp) != nullptr)
		stdout += buffer;

	int ret = pclose(fp);
    if (ret == -1) {
        perror("pclose() failed");
        SLS_ERR(SLS_WHERE);
    }
	if (WIFEXITED(ret))
		return WEXITSTATUS(ret);
	SLS_ERR(SLS_WHERE);
	return -1;
}

// get pid of all child processes
// reslut should be sorted (not sure)
// return -1 if no child
inline void child_pid(vector<Int> &child_pids, Int_I pid)
{
	Str cmd  = "pgrep -P " + to_string(pid), stdout;
	if (exec_str(stdout, cmd))
		SLS_ERR(stdout);
	std::istringstream iss(stdout);
	Str pid_str;
	child_pids.clear();
	while (true) {
		std::getline(iss, pid_str);
		if (iss.eof())
			break;
		child_pids.push_back(stoi(pid_str));
	}
}

// mem usage by this program in KiB
// works on computer cluster
// run time about 5e-5s
#ifndef SLS_USE_MACOS
// get the current hostname (machine name)
inline Str host_name()
{
    char name[1024];
    if (gethostname(name, 1024) != 0)
    	SLS_ERR("host_name() failed!");
    return name;
}

inline Long ram_usage() {
	FILE* file = fopen("/proc/self/status", "r");
	char line[128];

	Long i = -1;
	while (fgets(line, 128, file) != NULL) {
		if (strncmp(line, "VmRSS:", 6) == 0){
			i = strlen(line);
			const char* p = line;
			while (*p <'0' || *p > '9') p++;
			line[i-3] = '\0';
			i = atoi(p);
			break;
		}
	}
	fclose(file);
	return i;
}
#else
inline Long ram_usage() {
	SLS_WARN("not implemented for macOS");
	return -1;
}
#endif

} // namespace slisc
#endif
