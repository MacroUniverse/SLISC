// linux utilities
#pragma once
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

} // namespace slisc
