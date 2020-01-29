// linux utilities
#pragma once
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include "global.h"

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

} // namespace slisc
