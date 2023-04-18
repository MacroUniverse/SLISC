#pragma once
#include "../arith/scalar_arith.h"
#include <sstream>
#include <fstream>
#include <locale>
// #include <codecvt>
#ifdef SLS_USE_WINDOWS
	#include <Windows.h> // for console unicode output
	#undef max
	#undef min
#endif
#include "utfcpp/utf8.h"

namespace slisc {

using std::stringstream;

inline Long CRLF_to_LF(Str_IO str);

#ifdef SLS_USE_WINDOWS
// set windows console to display utf-8
struct set_windows_console_utf8 {
	set_windows_console_utf8() {
		SetConsoleOutputCP(65001); // code page 65001 is UTF-8
	}
};
// in case of ODR error, put this in main function;
// set_windows_console_utf8 yes_set_windows_console_utf8;

// Convert a wide Unicode wstring to an UTF8 string
inline Str wstr2utf8(const std::wstring& wstr)
{
	if (wstr.empty()) return std::string();
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
	return strTo;
}

// Convert an UTF8 string to a wide Unicode wstring
inline std::wstring utf82wstr(Str_I str)
{
	if (str.empty()) return std::wstring();
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	return wstrTo;
}
#endif

#ifdef SLS_USE_UTFCPP
// convert from UTF-8 Str to UTF-32 Str32
inline void u32(Str32_O str32, Str_I str)
{
	str32.clear();
	utf8::utf8to32(str.begin(), str.end(), back_inserter(str32));
}

// convert from UTF-32 Str32 to UTF-8 Str
inline void u8(Str_O str, Str32_I str32)
{
	str.clear();
	utf8::utf32to8(str32.begin(), str32.end(), back_inserter(str));
}

inline void utf8to16(Str_O str16, Str_I str)
{
	str16.clear();
	utf8::utf8to16(str.begin(), str.end(), back_inserter(str16));
}

inline void utf16to8(Str_O str, Str_I str16)
{
	str.clear();
	utf8::utf16to8(str16.begin(), str16.end(), back_inserter(str));
}

inline void utf16to32(Str32_O str32, Str_I str16)
{
	Str str8; utf16to8(str8, str16); u32(str32, str8);
}

inline void utf32to16(Str_O str16, Str32_I str32)
{
	Str str8; u8(str8, str32); utf8to16(str16, str8);
}

#else
// convert from UTF-8 Str to UTF-32 Str32
inline void u32(Str32_O str32, Str_I str)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> myconv;
	str32 = myconv.from_bytes(str);
}

// convert from UTF-32 Str32 to UTF-8 Str
inline void u8(Str_O str, Str32_I str32)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> myconv;
	str = myconv.to_bytes(str32);
}
#endif

// convert from UTF-8 Str32 to UTF-32 Str
inline Str32 u32(Str_I str)
{
	Str32 str32;
	u32(str32, str);
	return str32;
}

// convert from UTF-32 Str32 to UTF-8 Str
inline Str u8(Str32_I str32)
{
	Str str;
	u8(str, str32);
	return str;
}

inline Str utf8to16(Str_I str)
{
	Str str16;
	utf8to16(str16, str);
	return str16;
}

// convert from UTF-32 Str32 to UTF-8 Str
inline Str utf16to8(Str_I str16)
{
	Str str;
	utf16to8(str, str16);
	return str;
}

inline Str32 utf16to32(Str_I str)
{
	Str32 str32;
	utf16to32(str32, str);
	return str32;
}

inline Str utf32to16(Str32_I str32)
{
	Str str;
	utf32to16(str, str32);
	return str;
}

// check utf-8 string
using utf8::is_valid; // Bool is_valid(Str_I s);

// replace invalid codepoint
using utf8::replace_invalid; // Str replace_invalid(Str_I s, Char32 replacement);

// check if is the start of a utf-8 character
inline bool is_char8_start(Str_I str, Long_I index)
{
	if (index >= size(str) || index < 0) {
		return false;
	}

	unsigned char byte = str[index];
	if ((byte & 0b10000000) == 0) { // ASCII character (most significant bit is 0)
		return true;
	}

	// Multi-byte character starts with a sequence of 1's followed by a 0
	return (byte & 0b11000000) == 0b11000000;
}

// bytes of a utf-8 character
inline Long char8_len(Str_I s, Long_I ind) {
	if (s.empty())
		throw std::out_of_range("char8_len(): empty string!");
	unsigned char byte = s[ind];
	Long char_size;
	if (byte <= 0x7F) {
		char_size = 1;
	} else if ((byte >> 5) == 0x06) {
		char_size = 2;
	} else if ((byte >> 4) == 0x0E) {
		char_size = 3;
	} else if ((byte >> 3) == 0x1E) {
		char_size = 4;
	} else {
		throw std::runtime_error("char8_len(): Invalid UTF-8 encoding");
	}
	if (ind + char_size > size(s))
		throw std::out_of_range("char8_len(): Invalid UTF-8 encoding (out of range)");
	return char_size;
}

// get a utf-8 char from a utf-8 string
inline Str u8char(Str_I str, Long_I ind)
{
	Long char_size = char8_len(str, ind);
	return str.substr(ind, char_size);
}

// skip N utf-8 characters (supports N < 0 and N == s.size())
inline Long skip_char8(Str_I s, Long_I ind, Long_I N)
{
	if (ind < 0 || ind > size(s))
		throw std::out_of_range("skip_char8(): input error!");
	Long i = ind;
	if (N == 0)
		return ind;
	else if (N > 0) {
		Long utf8_len = s.size();
		Long skipped = 0;
		while (i < utf8_len && skipped < N) {
			Long char_size = char8_len(s, i);
			i += char_size;
			skipped++;
		}
		if (skipped < N)
			throw std::out_of_range("skip_char8(): Not enough characters to skip");
	}
	else if (N < 0) {
		Long remaining = -N;
		while (i > 0 && remaining > 0) {
			i--;
			if ((s[i] & 0xC0) != 0x80)
				remaining--;
		}
		if (remaining > 0)
			throw std::out_of_range("skip_char8(): Not enough characters to skip back");
	}
	return i;
}

// get a substring of utf-8, with N characters
inline Str substr8(Str_I s, Long_I ind, Long_I N)
{
	Long ind1;
	try { ind1 = skip_char8(s, ind, N); }
	catch (const std::out_of_range &) {
		ind1 = s.size();
	}
	return s.substr(ind, ind1-ind);
}

// get a Char32 from a utf-8 string
inline Char32 char32(Str_I str, Long_I ind)
{
	Str c = u8char(str, ind);
	return u32(c)[0];
}

// an iterator for utf-8
class u8_iter
{
private:
	Long ind;
	Str_I s;

public:
	// use i == -1 to point to the last character
	u8_iter(Str_I str, Long_I i = 0): ind(i), s(str) {
		if (i == -1)
			ind = skip_char8(str, size(str), -1);
		if (!is_char8_start(s, ind))
			throw std::runtime_error("u8_iter(str, i): not the start of a utf-8 char!");
	};

	// set string index
	Long operator=(Long_I i) {
		if (!is_char8_start(s, i))
			throw std::runtime_error("u8_iter::operator=(i): not the start of a utf-8 char!");
		ind = i;
		return i;
	}

	// convert to string index
	operator Long() {
		return ind;
	}

	// dereference
	Str operator*() {
		return u8char(s, ind);
	}

	bool operator==(const u8_iter &rhs) {
		if (s.empty() || rhs.s.empty())
			throw std::runtime_error("u8_iter::operator=(=: out of range!");
		return (ind == rhs.ind && &s == &rhs.s);
	}

	bool operator!=(const u8_iter &rhs) {
		return !(*this == rhs);
	}

	u8_iter operator+(Int_I N) {
		return u8_iter(s, skip_char8(s, ind, N));
	}

	u8_iter operator+(Llong_I N) {
		return u8_iter(s, skip_char8(s, ind, N));
	}

	u8_iter operator-(Int_I N) {
		return u8_iter(s, skip_char8(s, ind, -N));
	}

	u8_iter operator-(Llong_I N) {
		return u8_iter(s, skip_char8(s, ind, -N));
	}

	// next utf-8 position
	void operator++() {
		ind = skip_char8(s, ind, 1);
	}

	// last utf-8 position
	void operator--() {
		ind = skip_char8(s, ind, -1);
	}

	// skip N utf-8 chars
	void operator+=(Llong_I N) {
		ind = skip_char8(s, ind, N);
	}

	// skip back N utf-8 chars
	void operator-=(Long_I N) {
		ind = skip_char8(s, ind, -N);
	}
};

// check if is a chinese character
// does not include punctuations
// ref [1]: https://www.qqxiuzi.cn/zh/hanzi-unicode-bianma.php
// ref [2]: https://www.qqxiuzi.cn/bianma/zifuji.php
// see also: chinese_unicode.m (Matlab code)
inline Bool is_chinese(Str_I str, Long_I ind)
{
	Char32 c = char32(str, ind);
	// not sorted
	static const Char32 range[] = {
		0x4E00, 0x9FA5, // '基本汉字'
		0x9FA6, 0x9FFF, // '基本汉字补充（紧接上一行）'
		0x3400, 0x4DBF, // '扩展A'U'\u
		0x20000, 0x2A6DF, // '扩展B'
		0x2A700, 0x2B739, // '扩展C'
		0x2B740, 0x2B81D, // '扩展D'
		0x2B820, 0x2CEA1, // '扩展E'
		0x2CEB0, 0x2EBE0, // '扩展F'
		0x30000, 0x3134A, // '扩展G'
		0x31350, 0x323AF, // '扩展H'
		0x2F00, 0x2FD5, // '康熙部首'
		0x2E80, 0x2EF3, // '部首扩展'
		0xF900, 0xFAD9, // '兼容汉字'
		0x2F800, 0x2FA1D, // '兼容扩展'
		0x31C0, 0x31E3, // '汉字笔画'
		0x2FF0, 0x2FFB, // '汉字结构'
		0x3105, 0x312F, // '汉语注音'
		0x31A0, 0x31BF, // '注音扩展'
		0x3007, 0x3007 // '〇'
	};
	static_assert(sizeof(Char32) == 4, "unexpected!");
	Long N = sizeof(range) / sizeof(range[0]);
	// TODO: use bisection to optimize
	for (Long i = 0; i < N; i += 2) {
		if (c >= range[i] && c <= range[i+1])
			return true;
	}
	return false;
}

// see if a character is an emoji
// by GPT-4, not verified
inline Bool is_emoji(Char32_I c) {
	return (
		(c >= 0x1F600 && c <= 0x1F64F) || // Emoticons
		(c >= 0x2700 && c <= 0x27BF) || // Dingbats
		(c >= 0x1F680 && c <= 0x1F6FF) || // Transport and Map Symbols
		(c >= 0x2600 && c <= 0x26FF) || // Miscellaneous Symbols
		(c >= 0x1F300 && c <= 0x1F5FF) || // Miscellaneous Symbols and Pictographs
		(c >= 0x1F900 && c <= 0x1F9FF) || // Supplemental Symbols and Pictographs
		(c >= 0x1FA00 && c <= 0x1FA6F) // Symbols and Pictographs Extended-A
	);
}

// convert a utf-32 char to utf-8
// (verified)
inline Str u8(Char32_I c) {
	Str utf8;
	if (c <= 0x7F)
		utf8.push_back(char(c));
	else if (c <= 0x7FF) {
		utf8.push_back(char(0xC0 | (c >> 6)));
		utf8.push_back(char(0x80 | (c & 0x3F)));
	}
	else if (c <= 0xFFFF) {
		utf8.push_back(char(0xE0 | (c >> 12)));
		utf8.push_back(char(0x80 | ((c >> 6) & 0x3F)));
		utf8.push_back(char(0x80 | (c & 0x3F)));
	}
	else if (c <= 0x10FFFF) {
		utf8.push_back(char(0xF0 | (c >> 18)));
		utf8.push_back(char(0x80 | ((c >> 12) & 0x3F)));
		utf8.push_back(char(0x80 | ((c >> 6) & 0x3F)));
		utf8.push_back(char(0x80 | (c & 0x3F)));
	}
	else
		throw std::runtime_error("u8(Char32_I): Invalid Unicode codepoint.");
	return utf8;
}

// recycle
// ref: https://stackoverflow.com/questions/1366068/whats-the-complete-range-for-chinese-characters-in-unicode
// inline Bool is_chinese(Char32_I c)
// {
//     // from [1]
//     if ((c >= U'\u2E80' && c <= U'\u2FD5') || // 部首拓展（115 个）2E80-2EF3， 康熙部首（214 个）2F00-2FD5
//         (c >= U'\u3190' && c <= U'\u319f') ||
//         (c >= U'\u3400' && c <= U'\u4DBF') || // 扩展 A（6592 个）3400-4DBF
//         (c >= U'\u4E00' && c <= U'\u9FCC') || // 基本汉字（20902 个）4E00-9FA5， 
//         (c >= U'\uF900' && c <= U'\uFAAD'))   // 兼容汉字（477 个）F900-FAD9
//         return true;
//     return false;
// }

// check if is a chinese character
// include punctuations
inline Bool is_chinese_punc(Str_I str, Long_I ind)
{
	Char32 c = char32(str, ind);
	static const Str32 s = U"，。？！、：；“”‘’（）【】…—《》￥·";
	if ((Long)s.find(c) >= 0)
		return true;
	return false;
}

} // namespace slisc
