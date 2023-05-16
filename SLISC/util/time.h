// === time utilities ===

#pragma once
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <ctime>
#include "../str/str.h"

namespace slisc {

// get current system time "hh:mm:ss"
inline Str hhmmss()
{
	auto p = std::chrono::system_clock::now();
	std::time_t t = std::chrono::system_clock::to_time_t(p);
#ifdef SLS_USE_MSVC
	Str str; str.resize(50);
	ctime_s(&str[0], str.size(), &t);
#else
	Str str = std::ctime(&t);
#endif
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

// get current machine time (not necessarily correct)
// [year]   tm::tm_year + 1900;
// [month]  tm::tm_mon + 1;
// [day]    tm::tm_mday;
// [monday] tm::tm_wday
// [hour]   tm::tm_hour;
// [min]    tm::tm_min;
// [sec]    tm::tm_sec;
// [string] put_time(&tm_val, "%c %Z")
// [epoch] std::time_t mktime(&tm_val);
inline std::tm local_time()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    return *std::localtime(&now_time_t);
}

// get UTC/GMT time (not necessarily correct)
inline std::tm utc_time()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    return *std::gmtime(&now_time_t);
}

// time zone in minutes (e.g. UTF+8 returns 480)
// time zones are not always in integer numbers
inline int time_zone()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm local_tm = *std::localtime(&now_time_t);
    std::tm utc_tm = *std::gmtime(&now_time_t);
	int minutes = local_tm.tm_hour*60 + local_tm.tm_min
				- (utc_tm.tm_hour*60 + utc_tm.tm_min);

	if (local_tm.tm_year != utc_tm.tm_year) {
		if (local_tm.tm_year < utc_tm.tm_year)
			return minutes - 24*60;
		else
			return minutes + 24*60;
	}
	else if (local_tm.tm_mon != utc_tm.tm_mon) {
		if (local_tm.tm_mon < utc_tm.tm_mon)
			return minutes - 24*60;
		else
			return minutes + 24*60;
	}
	else if (local_tm.tm_mday != utc_tm.tm_mday) {
		if (local_tm.tm_mday < utc_tm.tm_mday)
			return minutes - 24*60;
		else
			return minutes + 24*60;
	}
	else
		return minutes;
}

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
