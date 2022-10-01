// linux utilities
#pragma once
#ifdef SLS_USE_LINUX
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include "global.h"
#include <sstream>
#include <unistd.h>

namespace slisc {

// execute a command in shell and return the output to stdout
inline Str exec_str(Str_I cmd) {
	std::array<char, 128> buffer;
	Str result;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
	if (!pipe)
	    throw std::runtime_error("popen() failed!");
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
	    result += buffer.data();
	return result;
}

// get pid of all child processes
// reslut should be sorted (not sure)
// return -1 if no child
inline void child_pid(vector<Int> &child_pids, Int_I pid)
{
	Str cmd  = "pgrep -P " + to_string(pid);
	std::istringstream iss(exec_str(cmd));
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
inline Long ram_usage() {
	FILE* file = fopen("/proc/self/status", "r");
	Char line[128];

	Long i = -1;
	while (fgets(line, 128, file) != NULL) {
	    if (strncmp(line, "VmRSS:", 6) == 0){
	        i = strlen(line);
	        const Char* p = line;
	        while (*p <'0' || *p > '9') p++;
	        line[i-3] = '\0';
	        i = atoi(p);
	        break;
	    }
	}
	fclose(file);
	return i;
}

} // namespace slisc
#endif
