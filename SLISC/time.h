// === time utilities ===

#pragma once
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <ctime>
#include "string.h"

namespace slisc {

// get current system time "hh:mm:ss"
inline Str hhmmss()
{
    auto p = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(p);
    Str str = std::ctime(&t);
    return str.substr(str.find(':')-2, 8);
}

// convert seconds to "hh:mm:ss" format
inline Str hhmmss(Long sec)
{
    sec %= 86400;
    Str hh = num2str(sec / 3600);
    sec %= 3600;
    Str mm = num2str(sec / 60);
    Str ss = num2str(sec % 60);
    Str ret;
    if (hh.size() == 1)
        ret += "0";
    ret += hh + ":";
    if (mm.size() == 1)
        ret += "0";
    ret += mm + ":";
    if (ss.size() == 1)
        ret += "0";
    ret += ss;
    return ret;
}

// convert seconds to "....h:mm:ss" format
inline Str hhhmmss(Long sec)
{
    Str hh = num2str(sec / 3600);
    sec %= 3600;
    Str mm = num2str(sec / 60);
    Str ss = num2str(sec % 60);
    Str ret;
    if (hh.size() == 1)
        ret += "0";
    ret += hh + ":";
    if (mm.size() == 1)
        ret += "0";
    ret += mm + ":";
    if (ss.size() == 1)
        ret += "0";
    ret += ss;
    return ret;
}

// timer for natural time
class Timer
{
private:
    std::chrono::steady_clock::time_point start;
public:
    void tic() // start timer
    { start = std::chrono::steady_clock::now(); }

    double toc() // time elapsed
    {
        auto stop = std::chrono::steady_clock::now();
        auto t = std::chrono::duration_cast<std::chrono::duration<double>>
            (stop - start);
        return t.count();
    }
};

// timer for cpu time (scales with cpu cores)
class CPUTimer
{
private:
    long long start;
public:
    void tic() { start = clock(); }
    double toc()
    { return (clock() - start) / (double)CLOCKS_PER_SEC; }
};

// pause untill key press
inline void pause()
{ printf("\nPress return to continue.\n"); getchar(); }

// pause a certain time
inline void pause(double t)
{ Timer time; time.tic(); while (time.toc() < t); }

} // namespace slisc
