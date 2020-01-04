// === time utilities ===

#pragma once
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <ctime>

namespace slisc {

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
