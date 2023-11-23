// === time utilities ===

#pragma once
#include <cstdio>
#include <string>
#include <chrono>
#include <ctime>
#include <thread>
#include "../str/str.h"

namespace slisc {

using std::time_t;
inline int is_daylight_saving();

// ================ time to string ======================

// convert time_t integer to time string
// e.g. 20230102.030405
// ref: https://en.cppreference.com/w/cpp/io/manip/put_time
inline Str time_t2str(time_t time, Str_I format = "%Y%m%d.%H%M%S")
{
	std::tm *ptm = localtime(&time);
	stringstream ss;
	ss << std::put_time(ptm, format.c_str());
	return ss.str();
}

// current system time
// e.g. 20230102.030405
// ref: https://en.cppreference.com/w/cpp/io/manip/put_time
inline Str time_str(Str_I format = "%Y%m%d.%H%M%S")
{
    return time_t2str(std::time(nullptr), format);
}

// get current system time "hh:mm:ss"
inline Str hhmmss()
{
	return time_str("%H:%M:%S");
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

// ================ string to time ======================

// convert a string to std::tm
inline std::tm str2tm(Str_I str)
{
	Long N = size(str);
	std::tm t = {};
	std::istringstream ss(str);
	if (N == 12)
		ss >> std::get_time(&t, "%Y%m%d%H%M");
	else if (N == 14)
		ss >> std::get_time(&t, "%Y%m%d%H%M%S");
	else
		throw std::runtime_error("str2time(): wrong size(str): " + to_string(N));
	if (ss.fail()) {
		throw std::runtime_error(SLS_WHERE);
	}
	t.tm_isdst = is_daylight_saving();
	return t;
}

inline time_t str2time_t(Str_I str)
{
	std::tm t = str2tm(str);
	return mktime(&t);
}

// =============== get time =====================

// get current machine time (not necessarily correct)
// ref: https://en.cppreference.com/w/cpp/chrono/c/tm
// [year]   tm::tm_year + 1900;
// [month]  tm::tm_mon + 1;
// [day]    tm::tm_mday;
// [monday] tm::tm_wday
// [hour]   tm::tm_hour;
// [min]    tm::tm_min;
// [sec]    tm::tm_sec;
// [string] put_time(&tm_val, "%c %Z")
// [epoch] time_t mktime(&tm_val);
inline std::tm local_time()
{
	time_t now = std::time(nullptr);
	return *std::localtime(&now);
}

// get UTC/GMT time (not necessarily correct)
inline std::tm utc_time()
{
	time_t now = std::time(nullptr);
	return *std::gmtime(&now);
}

// time zone in minutes (e.g. UTF+8 returns 480)
// time zones are not always in integer numbers
inline int time_zone()
{
	time_t now = std::time(nullptr);
	std::tm local_tm = *std::localtime(&now);
	std::tm utc_tm = *std::gmtime(&now);
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

// check if daylight saving time is in effect
inline int is_daylight_saving()
{
	static int ret = INT_MIN;
	if (ret == INT_MIN) {
		std::time_t t = std::time(nullptr); // get current time
		std::tm *now = std::localtime(&t);  // convert to local time
		ret = now->tm_isdst;
	}
	return ret;
}

// ================= Timer =====================

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

// pause a certain time (cpu will be occupied)
inline void pause(double t)
{ Timer time; time.tic(); while (time.toc() < t); }

// pause and free the cpu (current thread only)
// usually ~0.001s accuracy
inline void sleep(double t)
{
    std::this_thread::sleep_for(std::chrono::duration<double>(t));
}

} // namespace slisc
