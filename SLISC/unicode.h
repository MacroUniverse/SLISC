#pragma once
#include "arithmetic.h"
#include <sstream>
#include <fstream>
#include <locale>
#include <codecvt>
#ifdef SLS_USE_MSVC
#include <Windows.h> // for console unicode output
#undef max
#undef min
#endif
#include "string.h"
#include "utfcpp/utf8.h"

#ifdef SLS_USE_MSVC
#define SLS_USE_UTFCPP
#endif

namespace slisc {

using std::stringstream;

inline Long CRLF_to_LF(Str32_IO str);

#ifdef SLS_USE_MSVC
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
inline void utf8to32(Str32_O str32, Str_I str)
{
	str32.clear();
	utf8::utf8to32(str.begin(), str.end(), back_inserter(str32));
}

// convert from UTF-32 Str32 to UTF-8 Str
inline void utf32to8(Str_O str, Str32_I str32)
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
	Str str8; utf16to8(str8, str16); utf8to32(str32, str8);
}

inline void utf32to16(Str_O str16, Str32_I str32)
{
	Str str8; utf32to8(str8, str32); utf8to16(str16, str8);
}

#else
// convert from UTF-8 Str to UTF-32 Str32
inline void utf8to32(Str32_O str32, Str_I str)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> myconv;
	str32 = myconv.from_bytes(str);
}

// convert from UTF-32 Str32 to UTF-8 Str
inline void utf32to8(Str_O str, Str32_I str32)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> myconv;
	str = myconv.to_bytes(str32);
}
#endif

// convert from UTF-8 Str32 to UTF-32 Str
inline Str32 utf8to32(Str_I str)
{
	Str32 str32;
	utf8to32(str32, str);
	return str32;
}

// convert from UTF-32 Str32 to UTF-8 Str
inline Str utf32to8(Str32_I str32)
{
	Str str;
	utf32to8(str, str32);
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

// display Str32
inline std::ostream &operator<<(std::ostream &out, Str32_I str32)
{
	Str str;
	utf32to8(str, str32);
	out << str;
	return out;
}

// operator+ that converts Str to Str32
inline Str32 operator+(Str32_I str32, Str_I str)
{
	return str32 + utf8to32(str);
}

inline Str32 operator+(Str_I str, Str32_I str32)
{
	return utf8to32(str) + str32;
}

inline void num2str(Str32_O str, Char_I num, Long_I min_len = -1)
{
	utf8to32(str, num2str(num, min_len));
}

inline Str32 num2str32(Char_I num, Long_I min_len = -1)
{
	Str32 str;
	num2str(str, num, min_len);
	return str;
}

inline void num2str(Str32_O str, Int_I num, Long_I min_len = -1)
{
	utf8to32(str, num2str(num, min_len));
}

inline Str32 num2str32(Int_I num, Long_I min_len = -1)
{
	Str32 str;
	num2str(str, num, min_len);
	return str;
}

inline void num2str(Str32_O str, Llong_I num, Long_I min_len = -1)
{
	utf8to32(str, num2str(num, min_len));
}

inline Str32 num2str32(Llong_I num, Long_I min_len = -1)
{
	Str32 str;
	num2str(str, num, min_len);
	return str;
}

inline void num2str(Str32_O str, Float_I num, Long_I min_len = -1)
{
	utf8to32(str, num2str(num, min_len));
}

inline Str32 num2str32(Float_I num, Long_I min_len = -1)
{
	Str32 str;
	num2str(str, num, min_len);
	return str;
}

inline void num2str(Str32_O str, Doub_I num, Long_I min_len = -1)
{
	utf8to32(str, num2str(num, min_len));
}

inline Str32 num2str32(Doub_I num, Long_I min_len = -1)
{
	Str32 str;
	num2str(str, num, min_len);
	return str;
}


// same as str.insert(), but return one index after key after insertion
inline Long insert(Str32_IO str, Str32_I key, Long start)
{
	str.insert(start, key);
	return start + key.size();
}

// replace every U"\r\n" with U"\n"
inline Long CRLF_to_LF(Str32_IO str)
{
	Long ind0{}, N{};
	while (true) {
		ind0 = str.find(U"\r\n", ind0);
		if (ind0 < 0) return N;
		str.erase(ind0, 1);
	}
}

// Find the next appearance of one of "key"
// output the ikey of key[ikey] found
// return the first index of key[ikey] found, return -1 if nothing found
inline Long find(Long_O ikey, Str32_I str, vecStr32_I keys, Long_I start = 0)
{
	Long i{}, ind0{}, Nkey{}, imin;
	Nkey = keys.size();
	imin = str.size();
	for (i = 0; i < Nkey; ++i) {
		 ind0 = str.find(keys[i], start);
		 if (ind0 >= start && ind0 < imin) {
			 imin = ind0; ikey = i;
		 }
	}
	if (imin == size(str)) imin = -1;
	return imin;
}

// Find the previous appearance of one of "key"
// output the ikey of key[ikey] found
// return the first index of key[ikey] found, return -1 if nothing found
// keyword will be found even if starting from the middle of it
inline Long rfind(Long_O ikey, Str32_I str, vecStr32_I key, Long_I start)
{
	Long i{}, ind0{}, Nkey{}, imax;
	Nkey = key.size();
	imax = -1;
	for (i = 0; i < Nkey; ++i) {
		ind0 = str.rfind(key[i], start);
		if (ind0 > imax && ind0 <= start) {
			imax = ind0; ikey = i;
		}
	}
	return imax;
}

// same as FindMultipleReverse, but able to deal with multiple match
// return the number of matches, return -1 if not found
inline Long rfind(vecLong_O ikey, Str32_I str, vecStr32_I key, Long_I start)
{
	Long i{}, ind0{}, Nkey{}, imax;
	Nkey = key.size();
	imax = -1;
	for (i = 0; i < Nkey; ++i) {
		ind0 = str.rfind(key[i], start);
		if (ind0 > imax && ind0 <= start) {
			imax = ind0; ikey.clear();
			ikey.push_back(i);
		}
		// found another
		else if (ind0 == imax)
			ikey.push_back(i);
	}
	return imax;
}

// see if a key appears followed only by only white space or '\n'
// return the index after the key found, return -1 if nothing found.
inline Long expect(Str32_I str, Str32_I key, Long_I start)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start >= size(str))
		throw Str32(U"内部错误： expect(): out of bound");
#endif
	Long ind = start;
	Long ind0 = 0;
	Long L = str.size();
	Long L0 = key.size();
	Char32 c0, c;
	while (true) {
		 c0 = key[ind0];
		 c = str[ind];
		 if (c == c0) {
			 ++ind0;
			 if (ind0 == L0)
				 return ind + 1;
		 }
		 else if (c != U' ' && c != U'\n')
			 return -1;
		 ++ind;
		 if (ind == L)
			 return -1;
	}
}

// trim all occurance of key on the left
// return the number of charaters trimed
// e.g. key = "\n " to trim space and '\n'
inline Long trimL(Str32_IO str, Str32_I key = U" ")
{
	Long N;
	Long ind = str.find_first_not_of(key);
	if (ind < 0) {
		N = str.size();
		str.clear();
		return N;
	}
	N = ind;
	str.erase(0, N);
	return N;
}

// trim all occurance of key on the right
// return the number of charaters trimed
// e.g. key = "\n " to trim space and '\n'
inline Long trimR(Str32_IO str, Str32_I key = U" ")
{
	Long N;
	Long ind = str.find_last_not_of(key);
	if (ind < 0) {
		N = str.size();
		str.clear();
		return N;
	}
	str.erase(ind + 1);
	N = str.size() - ind;
	return N;
}

// trim both sides
// e.g. key = "\n " to trim space and '\n'
inline Long trim(Str32_IO str, Str32_I key = U" ")
{
	return trimL(str, key) + trimR(str, key);
}

// check if a character is a letter (a-z, A-Z)
inline Bool is_letter(Char32_I c)
{
	if ((c >= U'a' && c <= U'z') || (c >= U'A' && c <= U'Z'))
		return true;
	return false;
}

inline Bool is_num(Char32_I c)
{
	if (c >= U'0' && c <= U'9')
		return true;
	return false;
}

// check if a character is an ascii character (a-z, A-Z, 0-9)
inline Bool is_ascii(Char32_I c)
{
	if (c > 0 && c < 128)
		return true;
	return false;
}

// check if a character is alphanumeric (a-z, A-Z, 0-9)
inline Bool is_alphanum(Char32_I c)
{
	if (is_letter(c) || is_num(c))
		return true;
	return false;
}

// check if a character is alphanumeric or an underscore
inline Bool is_alphanum_(Char32_I c)
{
	if (is_alphanum(c) || c == U'_')
		return true;
	return false;
}

// check if a word is a whole word
inline Bool is_whole_word(Str32_I str, Long_I ind, Long_I count)
{
	// check left
	Long ind0 = ind - 1;
	if (ind0 >= 0 && is_alphanum_(str[ind0]))
		return false;
	// check right
	ind0 += 1 + count;
	if (ind0 < size(str) && is_alphanum_(str[ind0]))
		return false;
	return true;
}

// find whole word, like in Visual Studio Code, begin from "str[start]"
// return the first index of key found, return -1 if not found
inline Long find_whole_word(Str32_I str, Str32_I key, Long_I start)
{
	Long ind0 = start;
	while (true) {
		ind0 = str.find(key, ind0);
		if (ind0 < 0)
			return -1;
		if (is_whole_word(str, ind0, key.size()))
			return ind0;
		++ind0;
	}
}

// replace all occurance of "key" with "new_key"
// return the number of keys replaced
// works with utf-8
inline Long replace(Str32_IO str, Str32_I key, Str32_I new_key)
{
	Long ind0 = 0, N = 0, Nkey = key.size();
	while (true) {
		 ind0 = str.find(key, ind0);
		if (ind0 < 0) break;
		str.replace(ind0, Nkey, new_key);
		++N; ind0 += new_key.size();
	}
	return N;
}

// replace to new string
inline Long replace(Str32_O str1, Str32_I str, Str32_I key, Str32_I new_key)
{
	Long ind0 = 0, N = 0, Nkey = key.size();
	str1.clear();
	while (true) {
		Long ind1 = str.find(key, ind0);
		if (ind1 < 0) break;
		str1 += str.substr(ind0, ind1-ind0) + new_key;
		ind0 = ind1 + Nkey;
		++N;
	}
	if (ind0 < size(str))
		str1 += str.substr(ind0);
	return N;
}

// find next character that is not a space
// output single character c, return the position of the c
// return -1 if not found
// TODO: replace this with basic_string::find_first_not_of
inline Long NextNoSpace(Str32_O c, Str32_I str, Long start)
{
	for (Long i = start; i < size(str); ++i) {
		c = str.at(i);
		if (c == U" ")
			continue;
		else
			return i;
	}
	return -1;
}

// reverse version of Expect key
// return the previous index of the key found, return -2 if nothing found.
inline Long ExpectKeyReverse(Str32_I str, Str32_I key, Long start)
{
	if (start < 0)
		return -2;
	Long ind = start;
	Long L0 = key.size();
	Long ind0 = L0 - 1;
	Char32 c0, c;
	while (true) {
		c0 = key.at(ind0);
		c = str.at(ind);
		if (c == c0) {
			--ind0;
			if (ind0 < 0)
				return ind - 1;
		}
		else if (c != ' ' && c != '\n')
			return -2;
		--ind;
		if (ind < 0)
			return -2;
	}
}

// Find the next number
// return -1 if not found
inline Long find_num(Str32_I str, Long start)
{
	Long i{}, end = str.size() - 1;
	Char32 c;
	for (i = start; i <= end; ++i) {
		c = str.at(i);
		if (c >= '0' && c <= '9')
			return i;
	}
	return -1;
}

// get non-negative integer from string
// return the index after the last digit, return -1 if failed
// str[start] must be a number
inline Long str2int(Long_O num, Str32_I str, Long_I start = 0)
{
	Long i{};
	Char32 c;
	c = str.at(start);
	if (c < '0' || c > '9') {
		SLS_ERR("not a number!"); return -1;  // break point here
	}
	num = c - '0';
	for (i = start + 1; i < size(str); ++i) {
		c = str.at(i);
		if (c >= '0' && c <= '9')
			num = 10 * num + (Long)(c - '0');
		else
			return i;
	}
	return i;
}

// get non-negative double from string
// return the index after the last digit, return -1 if failed
// str[start] must be a number
inline Long str2double(Doub& num, Str32_I str, Long_I start = 0)
{
	Long ind0{}, num1{}, num2{};
	ind0 = str2int(num1, str, start);
	if (str.at(ind0) != '.') {
		num = (Doub)num1;
		return ind0;
	}
	ind0 = str2int(num2, str, ind0 + 1);
	num = (Doub)num2;
	while (num >= 1)
		num /= 10;
	num += (Doub)num1;
	return ind0;
}

inline Long str2int(Str32_I str)
{
	Long num; str2int(num, str);
	return num;
}

// delete any following ' ' or '\n' characters starting from "start" (including "start")
// return the number of characters deleted
inline Long eatR(Str32& str, Long start, Str32_I chars)
{
	Long N;
	Long ind0 = str.find_first_not_of(chars, start);
	if (ind0 < 0) {
		N = str.size() - start;
		if (N > 0)
			str.erase(start, N);
	}
	N = ind0 - start;
	if (N > 0)
		str.erase(start, N);
	return N;
}

// eat to left, see eatR
inline Long eatL(Str32& str, Long start, Str32_I chars)
{
	Long N;
	Long ind0 = str.find_last_not_of(chars, start);
	if (ind0 < 0) {
		N = start + 1;
		str.erase(0, N);
	}
	N = start - ind0;
	if (N > 0)
		str.erase(ind0 + 1, N);
	return N;
}

// Pair right brace to left one (default)
// or () or [] or anying single character
// ind is inddex of left brace
// return index of right brace
inline Long pair_brace(Str32_I str, Long ind)
{
	Char32 left, right, type = str[ind];
	if (type == U'{' || type == U'}') {
		left = U'{'; right = U'}';
	}
	else if (type == U'(' || type == U')') {
		left = U'('; right = U')';
	}
	else if (type == U'[' || type == U']') {
		left = U'['; right = U']';
	}
	else {
		throw Str32(U"pair_brace: illegal brace");
	}

	Char32 c, c0 = ' ';
	Long Nleft = 1;
	Long N = str.size();
	for (Long i = ind + 1; i < N; i++) {
		c = str[i];
		if (c == left && c0 != '\\')
			++Nleft;
		else if (c == right && c0 != '\\')
		{
			--Nleft;
			if (Nleft == 0)
				return i;
		}
		c0 = c;
	}
	throw Str32(U"pair_brace() failed!");
}

// match braces
// return -1 means failure, otherwise return number of {} paired
// output ind_left, ind_right, ind_RmatchL
inline Long MatchBraces(vecLong_O ind_left, vecLong_O ind_right,
	vecLong_O ind_RmatchL, Str32_I str, Long start, Long end)
{
	ind_left.resize(0); ind_right.resize(0); ind_RmatchL.resize(0);
	Char32 c, c_last = ' ';
	Long Nleft = 0, Nright = 0;
	vector<Bool> Lmatched;
	Bool matched;
	for (Long i = start; i <= end; ++i)
	{
		c = str.at(i);
		if (c == '{' && c_last != '\\')
		{
			++Nleft;
			ind_left.push_back(i);
			Lmatched.push_back(false);
		}
		else if (c == '}' && c_last != '\\')
		{
			++Nright;
			ind_right.push_back(i);
			matched = false;
			for (Long j = Nleft - 1; j >= 0; --j)
				if (!Lmatched[j])
				{
					ind_RmatchL.push_back(j);
					Lmatched[j] = true;
					matched = true;
					break;
				}
			if (!matched)
				return -1; // unbalanced braces
		}
		c_last = c;
	}
	if (Nleft != Nright)
		return -1;
	return Nleft;
}

// check if is a chinese character
// does not include punctuations
// reference: https://stackoverflow.com/questions/1366068/whats-the-complete-range-for-chinese-characters-in-unicode
inline Bool is_chinese(Char32_I c)
{
	if ((c >= U'\u2E80' && c <= U'\u2FD5') ||
		(c >= U'\u3190' && c <= U'\u319f') ||
		(c >= U'\u3400' && c <= U'\u4DBF') ||
		(c >= U'\u4E00' && c <= U'\u9FCC') ||
		(c >= U'\uF900' && c <= U'\uFAAD'))
		return true;
	return false;
}

// check if is a chinese character
// include punctuations
inline Bool is_chinese_punc(Char32_I c)
{
	static Str32 s = U"，。？！、：；“”‘’（）【】…—《》￥·";
	if ((Long)s.find(c) >= 0)
		return true;
	return false;
}

} // namespace slisc
