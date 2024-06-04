// string utilities

#pragma once
#include "../str/unicode.h"

namespace slisc {

// string utilities

// see if a string match the first part of another string
inline bool match_head(Str_I str_short, Str_I str_long)
{
	if (str_short.size() > str_long.size())
		return false;
	return str_long.substr(0, str_short.size()) == str_short;
}

inline bool match_head(Str32_I str_short, Str32_I str_long)
{
	if (str_short.size() > str_long.size())
		return false;
	return str_long.substr(0, str_short.size()) == str_short;
}


inline void num2str(Str_O str, Char_I s, Long_I min_len = -1)
{
	str = to_string(s);
	// 0 padding on the left
	if (min_len > 0 && size(str) < min_len) {
		Str str1;
		for (Long i = 0; i < min_len - size(str); ++i)
			str1 += '0';
		str = str1 + str;
	}
}

inline Str num2str(Char_I s, Long_I min_len = -1)
{
	Str str;
	num2str(str, s, min_len);
	return str;
}

inline void num2str(Str32_O str, Char_I num, Long_I min_len = -1)
{
	u32(str, num2str(num, min_len));
}

inline Str32 num2str32(Char_I num, Long_I min_len = -1)
{
	Str32 str;
	num2str(str, num, min_len);
	return str;
}

inline void num2str(Str_O str, Int_I s, Long_I min_len = -1)
{
	str = to_string(s);
	// 0 padding on the left
	if (min_len > 0 && size(str) < min_len) {
		Str str1;
		for (Long i = 0; i < min_len - size(str); ++i)
			str1 += '0';
		str = str1 + str;
	}
}

inline Str num2str(Int_I s, Long_I min_len = -1)
{
	Str str;
	num2str(str, s, min_len);
	return str;
}

inline void num2str(Str32_O str, Int_I num, Long_I min_len = -1)
{
	u32(str, num2str(num, min_len));
}

inline Str32 num2str32(Int_I num, Long_I min_len = -1)
{
	Str32 str;
	num2str(str, num, min_len);
	return str;
}

inline void num2str(Str_O str, Llong_I s, Long_I min_len = -1)
{
	str = to_string(s);
	// 0 padding on the left
	if (min_len > 0 && size(str) < min_len) {
		Str str1;
		for (Long i = 0; i < min_len - size(str); ++i)
			str1 += '0';
		str = str1 + str;
	}
}

inline Str num2str(Llong_I s, Long_I min_len = -1)
{
	Str str;
	num2str(str, s, min_len);
	return str;
}

inline void num2str(Str32_O str, Llong_I num, Long_I min_len = -1)
{
	u32(str, num2str(num, min_len));
}

inline Str32 num2str32(Llong_I num, Long_I min_len = -1)
{
	Str32 str;
	num2str(str, num, min_len);
	return str;
}


// if `prec` is enough, this will give the exact decimal conversion of x,
// and trailing zeros are omitted
inline Str num2str(Float_I x, std::streamsize prec = 5)
{
	std::ostringstream os; os.precision(prec);
	os << x;
	return os.str();
}

inline Str num2str(Doub_I x, std::streamsize prec = 5)
{
	std::ostringstream os; os.precision(prec);
	os << x;
	return os.str();
}

inline Str num2str(Comp_I x, std::streamsize prec = 5)
{
	std::ostringstream os; os.precision(prec);
	os << x;
	return os.str();
}

inline Str num2str(Qdoub_I x, std::streamsize prec = 5)
{
	std::ostringstream os; os.precision(prec);
	os << x;
	return os.str();
}


// get a line starting from ind0
inline Str getline(Str_I str, Long_I start = 0)
{
	Long ind = str.find('\n', start);
	if (ind < 0)
		return str.substr(start);
	return str.substr(start, ind - start);
}

inline Str32 getline(Str32_I str, Long_I start = 0)
{
	Long ind = str.find('\n', start);
	if (ind < 0)
		return str.substr(start);
	return str.substr(start, ind - start);
}

// read a line from a string, from str[start] to 1 char before '\n'
// return the start of the next line, return -1 if out of bound
// if the file ends with `\n`, then the line.back() is not empty
inline Long get_line(Str_O line, Str_I str, Long_I start = 0)
{
	Long ind = str.find('\n', start);
	line = str.substr(start, ind - start);
	if (ind < 0 || ind == Long(str.size()) - 1)
		return -1;
	return ind + 1;
}

inline Long get_line(Str32_O line, Str32_I str, Long_I start = 0)
{
	Long ind = str.find(U'\n', start);
	line = str.substr(start, ind - start);
	if (ind < 0 || ind == Long(str.size()) - 1)
		return -1;
	return ind + 1;
}

// skip to the next line
// return the index after `\n`
// return -1 if `\n` not found
inline Long skip_line(Str_I str, Long_I start = 0)
{
	Long ind = str.find('\n', start);
	if (ind < 0 || ind == Long(str.size()) - 1)
		return -1;
	return ind + 1;
}

inline Long skip_line(Str32_I str, Long_I start = 0)
{
	Long ind = str.find(U'\n', start);
	if (ind < 0 || ind == Long(str.size()) - 1)
		return -1;
	return ind + 1;
}

inline std::istream &skip_line(std::istream& stream, Long_I n = 1)
{
	for (Long i = 0; i < n; ++i)
		if (!stream.ignore(numeric_limits<std::streamsize>::max(), '\n'))
			SLS_ERR("skip_line() error line # = " + to_string(i));
	return stream;
}

// convert string to lower case
inline void to_lower(Str_O str)
{
	Char C, diff = 'a' - 'A';
	Long N = str.size();
	for (Long i = 0; i < N; ++i) {
		C = str[i];
		if (C >= 'A' && C <= 'Z')
			str[i] = C + diff;
		else
			str[i] = C;
	}
}

inline void to_lower(Str32_O str)
{
	Char32 C, diff = 'a' - 'A';
	Long N = str.size();
	for (Long i = 0; i < N; ++i) {
		C = str[i];
		if (C >= 'A' && C <= 'Z')
			str[i] = C + diff;
		else
			str[i] = C;
	}
}


// convert string to lower case
inline void to_lower(Str_O str, Str_I STR)
{
	Char C, diff = 'a' - 'A';
	Long N = STR.size();
	str.resize(N);
	for (Long i = 0; i < N; ++i) {
		C = STR[i];
		if (C >= 'A' && C <= 'Z')
			str[i] = C + diff;
		else
			str[i] = C;
	}
}

inline void to_lower(Str32_O str, Str32_I STR)
{
	Char32 C, diff = 'a' - 'A';
	Long N = STR.size();
	str.resize(N);
	for (Long i = 0; i < N; ++i) {
		C = STR[i];
		if (C >= 'A' && C <= 'Z')
			str[i] = C + diff;
		else
			str[i] = C;
	}
}


// convert string to lower case
inline void to_upper(Str_O STR, Str_I str)
{
	Char c, diff = 'A' - 'a';
	Long N = str.size();
	STR.resize(N);
	for (Long i = 0; i < N; ++i) {
		c = str[i];
		if (c >= 'a' && c <= 'z')
			STR[i] = c + diff;
		else
			STR[i] = c;
	}
}

inline void to_upper(Str32_O STR, Str32_I str)
{
	Char32 c, diff = 'A' - 'a';
	Long N = str.size();
	STR.resize(N);
	for (Long i = 0; i < N; ++i) {
		c = str[i];
		if (c >= 'a' && c <= 'z')
			STR[i] = c + diff;
		else
			STR[i] = c;
	}
}


// convert string to lower case
inline void to_upper(Str_IO str)
{
	Char c, diff = 'A' - 'a';
	Long N = str.size();
	for (Long i = 0; i < N; ++i) {
		c = str[i];
		if (c >= 'a' && c <= 'z')
			str[i] = c + diff;
		else
			str[i] = c;
	}
}

inline void to_upper(Str32_IO str)
{
	Char32 c, diff = 'A' - 'a';
	Long N = str.size();
	for (Long i = 0; i < N; ++i) {
		c = str[i];
		if (c >= 'a' && c <= 'z')
			str[i] = c + diff;
		else
			str[i] = c;
	}
}


inline void to_lower(vecStr_O vs, vecStr_I VS)
{
	Long N = VS.size();
	vs.resize(N);
	for (Long i = 0; i < N; ++i)
		to_lower(vs[i], VS[i]);
}

inline void to_lower(vecStr32_O vs, vecStr32_I VS)
{
	Long N = VS.size();
	vs.resize(N);
	for (Long i = 0; i < N; ++i)
		to_lower(vs[i], VS[i]);
}


inline void to_lower(vecStr_IO vs)
{
	Long N = vs.size();
	for (Long i = 0; i < N; ++i)
		to_lower(vs[i]);
}

inline void to_lower(vecStr32_IO vs)
{
	Long N = vs.size();
	for (Long i = 0; i < N; ++i)
		to_lower(vs[i]);
}


inline void to_upper(vecStr_O VS, vecStr_I vs)
{
	Long N = vs.size();
	VS.resize(N);
	for (Long i = 0; i < N; ++i)
		to_upper(VS[i], vs[i]);
}

inline void to_upper(vecStr32_O VS, vecStr32_I vs)
{
	Long N = vs.size();
	VS.resize(N);
	for (Long i = 0; i < N; ++i)
		to_upper(VS[i], vs[i]);
}


inline void to_upper(vecStr_IO vs)
{
	Long N = vs.size();
	vs.resize(N);
	for (Long i = 0; i < N; ++i)
		to_upper(vs[i]);
}

inline void to_upper(vecStr32_IO vs)
{
	Long N = vs.size();
	vs.resize(N);
	for (Long i = 0; i < N; ++i)
		to_upper(vs[i]);
}


// if `s` starts with `key`
inline bool startswith(Str_I s, Str_I key)
{
	if (s.size() >= key.size() && s.substr(0, key.size()) == key)
		return true;
	else
		return false;
}

// if `s` ends with `key`
inline bool endswith(Str_I s, Str_I key)
{
	if (s.size() >= key.size() && s.substr(s.size()-key.size()) == key)
		return true;
	else
		return false;
}

// print Str32
inline std::ostream &operator<<(std::ostream &out, Str32_I str32)
{
	Str str = u8(str32);
	out << str;
	return out;
}

// operator+ that converts Str to Str32
inline Str operator+(Str32_I str32, Str_I str)
{
	return u8(str32) + str;
}

inline Str operator+(Str_I str, Str32_I str32)
{
	return str + u8(str32);
}

inline void operator+=(Str_IO str, Str32_I str32)
{
	str += u8(str32);
}

inline void operator+=(Str32_IO str32, Str_I str)
{
	str32 += u32(str);
}

// check if a character is an ascii character
inline bool is_ascii(Char32_I c)
{
	if (c >= 0 && c < 128)
		return true;
	return false;
}


inline bool is_num(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

// check if a character is a letter (a-z, A-Z)
inline bool is_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}

// check if a character is alphanumeric (a-z, A-Z, 0-9)
inline bool is_alphanum(char c)
{
	if (is_letter(c) || is_num(c))
		return true;
	return false;
}

// check if a character is alphanumeric or an underscore
inline bool is_alphanum_(char c)
{
	if (is_alphanum(c) || c == '_')
		return true;
	return false;
}

inline Long insert(Str_IO str, Str_I key, Long start)
{
	str.insert(start, key);
	return start + key.size();
}

// replace every "\r\n" with "\n"
inline Long CRLF_to_LF(Str_IO str)
{
	Long ind0{}, N{};
	while (true) {
		ind0 = str.find("\r\n", ind0);
		if (ind0 < 0) return N;
		str.erase(ind0, 1);
	}
}

// my version of string::find() and rfind()
inline Long find(Str_I str, Str_I key, Long pos = 0)
{
	size_t ind = str.find(key, pos);
	return ind == npos ? -1 : ind;
}

inline Long find(Str_I str, const char* key, Long pos = 0)
{
	size_t ind = str.find(key, pos);
	return ind == npos ? -1 : ind;
}

inline Long find(Str_I str, char key, Long pos = 0)
{
	size_t ind = str.find(key, pos);
	return ind == npos ? -1 : ind;
}

inline Long rfind(Str_I str, Str_I key, Long pos = 0)
{
	size_t ind = str.rfind(key, pos);
	return ind == npos ? -1 : ind;
}

inline Long rfind(Str_I str, const char* key, Long pos = 0)
{
	size_t ind = str.rfind(key, pos);
	return ind == npos ? -1 : ind;
}

inline Long rfind(Str_I str, char key, Long pos = 0)
{
	size_t ind = str.find(key, pos);
	return ind == npos ? -1 : ind;
}

// Find the next appearance of one of "key"
// output the ikey of key[ikey] found
// return the first index of key[ikey] found, return -1 if nothing found
inline Long find(Long_O ikey, Str_I str, vecStr_I keys, Long_I start = 0)
{
	Long i{}, ind0{}, Nkey{}, imin;
	Nkey = keys.size(); ikey = -1;
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
inline Long rfind(Long_O ikey, Str_I str, vecStr_I key, Long_I start)
{
	Long i{}, ind0{}, Nkey{}, imax;
	Nkey = key.size(); ikey = -1;
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
inline Long rfind(vecLong_O ikey, Str_I str, vecStr_I key, Long_I start)
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
inline Long expect(Str_I str, Str_I key, Long_I start)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start >= size(str))
		throw std::runtime_error("expect(): out of bound");
#endif
	Long ind = start;
	Long ind0 = 0;
	Long L = str.size();
	Long L0 = key.size();
	char c0, c;
	while (true) {
		 c0 = key[ind0];
		 c = str[ind];
		 if (c == c0) {
			 ++ind0;
			 if (ind0 == L0)
				 return ind + 1;
		 }
		 else if (c != ' ' && c != '\n')
			 return -1;
		 ++ind;
		 if (ind == L)
			 return -1;
	}
}

// trim all occurance of key on the left
// return the number of charaters trimed
// e.g. key = "\n " to trim space and '\n'
inline Long trimL(Str_IO str, Str_I key = " ")
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
inline Long trimR(Str_IO str, Str_I key = " ")
{
	Long N;
	Long ind = str.find_last_not_of(key);
	if (ind < 0) {
		N = size(str);
		str.clear();
		return N;
	}
	str.erase(ind + 1);
	N = size(str) - ind;
	return N;
}

// trim both sides
// e.g. key = "\n " to trim space and '\n'
inline Long trim(Str_IO str, Str_I key = " ")
{
	return trimL(str, key) + trimR(str, key);
}

// check if a word is a whole word
inline bool is_whole_word(Str_I str, Long_I ind, Long_I count)
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
inline Long find_whole_word(Str_I str, Str_I key, Long_I start)
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
inline Long replace(Str_IO str, Str_I key, Str_I new_key)
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
inline Long replace(Str_O str1, Str_I str, Str_I key, Str_I new_key)
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
inline Long NextNoSpace(Str_O c, Str_I str, Long start)
{
	for (Long i = start; i < size(str); ++i) {
		c = str.at(i);
		if (c == " ")
			continue;
		else
			return i;
	}
	return -1;
}

// reverse version of Expect key
// return the previous index of the key found, return -2 if nothing found.
inline Long ExpectKeyReverse(Str_I str, Str_I key, Long start)
{
	if (start < 0)
		return -2;
	Long ind = start;
	Long L0 = key.size();
	Long ind0 = L0 - 1;
	char c0, c;
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
inline Long find_num(Str_I str, Long start)
{
	Long i{}, end = str.size() - 1;
	char c;
	for (i = start; i <= end; ++i) {
		c = str.at(i);
		if (c >= '0' && c <= '9')
			return i;
	}
	return -1;
}

// delete any following ' ' or '\n' characters starting from "start" (including "start")
// return the number of characters deleted
inline Long eatR(Str& str, Long start, Str_I chars)
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
inline Long eatL(Str& str, Long start, Str_I chars)
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
inline Long pair_brace(Str_I str, Long ind)
{
	char left, right, type = str[ind];
	if (type == '{' || type == '}') {
		left = '{'; right = '}';
	}
	else if (type == '(' || type == ')') {
		left = '('; right = ')';
	}
	else if (type == '[' || type == ']') {
		left = '['; right = ']';
	}
	else {
		throw std::runtime_error("pair_brace: illegal brace");
	}

	char c, c0 = ' ';
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
	throw std::runtime_error("pair_brace() failed: " + str.substr(ind, 20));
}

// match braces
// return -1 means failure, otherwise return number of {} paired
// output ind_left, ind_right, ind_RmatchL
inline Long MatchBraces(vecLong_O ind_left, vecLong_O ind_right,
	vecLong_O ind_RmatchL, Str_I str, Long start, Long end)
{
	ind_left.resize(0); ind_right.resize(0); ind_RmatchL.resize(0);
	char c, c_last = ' ';
	Long Nleft = 0, Nright = 0;
	vector<bool> Lmatched;
	bool matched;
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

// get non-negative integer from string
// str[start] must be a number
// return the index after the last digit
// return -1 if failed
// return -i if overflow, where i is the index after processed digit (num will be the front digits before overflow)
template <class T>
inline Long str2int0(T &num, Str_I str, Long_I start = 0)
{
	Long i = start, N = size(str);
	if (i >= N) return -1;
	char c = str[i];
	if (!is_num(c)) return -1;
	num = c - '0';
	T max = numeric_limits<T>::max();
	for (++i; i < N; ++i) {
		if (!is_num(c = str[i])) return i;
		c -= '0';
		if (num > (max - (T)c)/10)
			return -i; // overflow
		num = 10 * num + c;
	}
	return i;
}

// get integer from string: dddd, +dddd, -dddd
// str[start] must be a number or '+' or '-' or ' '
// return the index after the last digit
// return -1 if format is wrong
// return -i if overflow, where i is the index after processed digit (num will be the front digits before overflow)
// see also std::strtol, std::strtoll
template <class T>
inline Long str2int(T &num, Str_I str, Long_I start = 0)
{
	Long N = size(str); num = 0;
	if (start >= N) return -1;
	Long i = start;
	while (str[i] == ' ')
		if (++i == N) return -1;
	char c = str[i];
	if (c == '+') {
		if (++i == N || !is_num(str[i]))
			return -1;
		return str2int0(num, str, i);
	}
	else if (is_num(c))
		return str2int0(num, str, i);
	else if (c == '-') {
		// can't use str2int0 since `min != -max`
		if (++i == N) return -1;
		if (!is_num(c = str[i])) return -1;
		num = '0' - c;
		T min = numeric_limits<T>::min();
		for (++i; i < N; ++i) {
			c = str[i];
			if (!is_num(c)) return i;
			c -= '0';
			if (num < (min + (T)c)/10)
				return -i; // overflow
			num = 10 * num - c;
		}
	}
	return i;
}

// str must be +ddd, -ddd, or ddd
inline Int str2Int(Str_I str, Long_I start = 0)
{
	Int num;
	if (str2int(num, str, start) < 0)
		SLS_ERR("str2Int(): not an integer: " + str.substr(start, 20));
	return num;
}

// str must be +ddd, -ddd, or ddd
inline Llong str2Llong(Str_I str, Long_I start = 0)
{
	Llong num;
	if (str2int(num, str, start) < 0)
		SLS_ERR("str2Llong(): not an integer: " + str.substr(start, 20));
	return num;
}

// [warning] last 2 digits might be wrong
// get non-negative double from string with format dddd.dddd or .dddd
// return the index after the last digit (might be str.size()), return -1 if failed
// str[start] must be a number
inline Long str2double0(Doub& num, Str_I str, Long_I start = 0)
{
	Llong num1;
	if (!is_num(str[start])) return -1;
	Long ind = start;
	ind = str2int0(num1, str, ind);
	if (ind < 0) return -1;
	num = Doub(num1);
	if (ind == size(str) || str[ind] != '.')
		return ind;
	++ind;
	Long ind1 = str2int0(num1, str, ind);
	if (ind1 == -1) return -1;
	int exp = abs(ind1)-ind;
	Doub d = num1 * pow(10LL, -exp);
	cout.precision(18);
	num += d;
	return ind1;
}

// [warning] last 2 digits might be wrong
// get non-negative double from string with format dddd.dddd or .dddd (there can be +,- at from and eddd,e+ddd,e-ddd at the end)
// return the index after the last digit (might be str.size()), return -1 if failed
// str[start] must be a number
inline Long str2double(Doub& num, Str_I str, Long_I start = 0)
{
	if (start >= size(str)) return -1;
	Long ind = start, num1 = 0;
	bool neg = false;
	if (str[ind] == '+') ++ind;
	if (str[ind] == '-') { neg = true; ++ind; }
	// ddd.ddd or .ddd
	ind = str2double0(num, str, ind);
	if (ind < 0) return -1;
	if (neg) num = -num;
	if (ind+1 >= size(str) || (str[ind] != 'e' && str[ind] != 'E'))
		return ind;
	// exponent
	++ind;
	ind = str2int(num1, str, ind);
	if (ind < 0) return -1;
	num *= pow(10., num1);
	return ind;
}

inline Doub str2double(Str_I str, Long_I start = 0)
{
	Doub num;
	if (str2double(num, str, start) < 0)
		SLS_ERR("str2int(): not a double: " + str.substr(start, 20));
	return num;
}


inline bool is_num(Char32 c)
{
	if (c >= U'0' && c <= U'9')
		return true;
	return false;
}

// check if a character is a letter (a-z, A-Z)
inline bool is_letter(Char32 c)
{
	if ((c >= U'a' && c <= U'z') || (c >= U'A' && c <= U'Z'))
		return true;
	return false;
}

// check if a character is alphanumeric (a-z, A-Z, 0-9)
inline bool is_alphanum(Char32 c)
{
	if (is_letter(c) || is_num(c))
		return true;
	return false;
}

// check if a character is alphanumeric or an underscore
inline bool is_alphanum_(Char32 c)
{
	if (is_alphanum(c) || c == U'_')
		return true;
	return false;
}

inline Long insert(Str32_IO str, Str32_I key, Long start)
{
	str.insert(start, key);
	return start + key.size();
}

// replace every "\r\n" with "\n"
inline Long CRLF_to_LF(Str32_IO str)
{
	Long ind0{}, N{};
	while (true) {
		ind0 = str.find(U"\r\n", ind0);
		if (ind0 < 0) return N;
		str.erase(ind0, 1);
	}
}

// my version of string::find() and rfind()
inline Long find(Str32_I str, Str32_I key, Long pos = 0)
{
	size_t ind = str.find(key, pos);
	return ind == npos ? -1 : ind;
}

inline Long find(Str32_I str, const Char32* key, Long pos = 0)
{
	size_t ind = str.find(key, pos);
	return ind == npos ? -1 : ind;
}

inline Long find(Str32_I str, Char32 key, Long pos = 0)
{
	size_t ind = str.find(key, pos);
	return ind == npos ? -1 : ind;
}

inline Long rfind(Str32_I str, Str32_I key, Long pos = 0)
{
	size_t ind = str.rfind(key, pos);
	return ind == npos ? -1 : ind;
}

inline Long rfind(Str32_I str, const Char32* key, Long pos = 0)
{
	size_t ind = str.rfind(key, pos);
	return ind == npos ? -1 : ind;
}

inline Long rfind(Str32_I str, Char32 key, Long pos = 0)
{
	size_t ind = str.find(key, pos);
	return ind == npos ? -1 : ind;
}

// Find the next appearance of one of "key"
// output the ikey of key[ikey] found
// return the first index of key[ikey] found, return -1 if nothing found
inline Long find(Long_O ikey, Str32_I str, vecStr32_I keys, Long_I start = 0)
{
	Long i{}, ind0{}, Nkey{}, imin;
	Nkey = keys.size(); ikey = -1;
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
	Nkey = key.size(); ikey = -1;
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
		throw std::runtime_error("expect(): out of bound");
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
		N = size(str);
		str.clear();
		return N;
	}
	str.erase(ind + 1);
	N = size(str) - ind;
	return N;
}

// trim both sides
// e.g. key = "\n " to trim space and '\n'
inline Long trim(Str32_IO str, Str32_I key = U" ")
{
	return trimL(str, key) + trimR(str, key);
}

// check if a word is a whole word
inline bool is_whole_word(Str32_I str, Long_I ind, Long_I count)
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
		throw std::runtime_error("pair_brace: illegal brace");
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
	throw std::runtime_error("pair_brace() failed: " + str.substr(ind, 20));
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
	vector<bool> Lmatched;
	bool matched;
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

// get non-negative integer from string
// str[start] must be a number
// return the index after the last digit
// return -1 if failed
// return -i if overflow, where i is the index after processed digit (num will be the front digits before overflow)
template <class T>
inline Long str2int0(T &num, Str32_I str, Long_I start = 0)
{
	Long i = start, N = size(str);
	if (i >= N) return -1;
	Char32 c = str[i];
	if (!is_num(c)) return -1;
	num = c - '0';
	T max = numeric_limits<T>::max();
	for (++i; i < N; ++i) {
		if (!is_num(c = str[i])) return i;
		c -= '0';
		if (num > (max - (T)c)/10)
			return -i; // overflow
		num = 10 * num + c;
	}
	return i;
}

// get integer from string: dddd, +dddd, -dddd
// str[start] must be a number or '+' or '-' or ' '
// return the index after the last digit
// return -1 if format is wrong
// return -i if overflow, where i is the index after processed digit (num will be the front digits before overflow)
// see also std::strtol, std::strtoll
template <class T>
inline Long str2int(T &num, Str32_I str, Long_I start = 0)
{
	Long N = size(str); num = 0;
	if (start >= N) return -1;
	Long i = start;
	while (str[i] == ' ')
		if (++i == N) return -1;
	Char32 c = str[i];
	if (c == '+') {
		if (++i == N || !is_num(str[i]))
			return -1;
		return str2int0(num, str, i);
	}
	else if (is_num(c))
		return str2int0(num, str, i);
	else if (c == '-') {
		// can't use str2int0 since `min != -max`
		if (++i == N) return -1;
		if (!is_num(c = str[i])) return -1;
		num = '0' - c;
		T min = numeric_limits<T>::min();
		for (++i; i < N; ++i) {
			c = str[i];
			if (!is_num(c)) return i;
			c -= '0';
			if (num < (min + (T)c)/10)
				return -i; // overflow
			num = 10 * num - c;
		}
	}
	return i;
}

// str must be +ddd, -ddd, or ddd
inline Int str2Int(Str32_I str, Long_I start = 0)
{
	Int num;
	if (str2int(num, str, start) < 0)
		SLS_ERR("str2Int(): not an integer: " + str.substr(start, 20));
	return num;
}

// str must be +ddd, -ddd, or ddd
inline Llong str2Llong(Str32_I str, Long_I start = 0)
{
	Llong num;
	if (str2int(num, str, start) < 0)
		SLS_ERR("str2Llong(): not an integer: " + str.substr(start, 20));
	return num;
}

// [warning] last 2 digits might be wrong
// get non-negative double from string with format dddd.dddd or .dddd
// return the index after the last digit (might be str.size()), return -1 if failed
// str[start] must be a number
inline Long str2double0(Doub& num, Str32_I str, Long_I start = 0)
{
	Llong num1;
	if (!is_num(str[start])) return -1;
	Long ind = start;
	ind = str2int0(num1, str, ind);
	if (ind < 0) return -1;
	num = Doub(num1);
	if (ind == size(str) || str[ind] != '.')
		return ind;
	++ind;
	Long ind1 = str2int0(num1, str, ind);
	if (ind1 == -1) return -1;
	int exp = abs(ind1)-ind;
	Doub d = num1 * pow(10LL, -exp);
	cout.precision(18);
	num += d;
	return ind1;
}

// [warning] last 2 digits might be wrong
// get non-negative double from string with format dddd.dddd or .dddd (there can be +,- at from and eddd,e+ddd,e-ddd at the end)
// return the index after the last digit (might be str.size()), return -1 if failed
// str[start] must be a number
inline Long str2double(Doub& num, Str32_I str, Long_I start = 0)
{
	if (start >= size(str)) return -1;
	Long ind = start, num1 = 0;
	bool neg = false;
	if (str[ind] == '+') ++ind;
	if (str[ind] == '-') { neg = true; ++ind; }
	// ddd.ddd or .ddd
	ind = str2double0(num, str, ind);
	if (ind < 0) return -1;
	if (neg) num = -num;
	if (ind+1 >= size(str) || (str[ind] != 'e' && str[ind] != 'E'))
		return ind;
	// exponent
	++ind;
	ind = str2int(num1, str, ind);
	if (ind < 0) return -1;
	num *= pow(10., num1);
	return ind;
}

inline Doub str2double(Str32_I str, Long_I start = 0)
{
	Doub num;
	if (str2double(num, str, start) < 0)
		SLS_ERR("str2int(): not a double: " + str.substr(start, 20));
	return num;
}



// find the longest sequence of numbers after '.'
//     then remove 0s at the end of the sequence
inline void rm_float_zeros(Str_IO str, Long start = 0)
{
	Long ind = str.find('.', start);
	if (ind > 0) {
		++ind;
		while (ind < size(str) && is_num(str[ind])) ++ind;
		if (str[--ind] == '0') {
			Long ind1 = ind;
			while (str[--ind] == '0') ;
			if (str[ind] != '.')
				str.erase(ind+1, ind1 - ind);
			else
				str.erase(ind, ind1-ind+1);
		}
	}
}

// convert a number to chinese
inline Str num2chinese(Long num) {
	map<Long, Str> digits = {
		{0, "零"}, {1, "一"}, {2, "二"}, {3, "三"}, {4, "四"},
		{5, "五"}, {6, "六"}, {7, "七"}, {8, "八"}, {9, "九"},
	};
	map<Long, Str> units = {
		{1, "十"}, {2, "百"}, {3, "千"}, {4, "万"},
	};

	Str result = "";

	if (num >= 100000 || num < 0)
		SLS_ERR("not supported yet!");

	if (num >= 10000) {
		Long num1 = num / 10000;
		num %= 10000;
		result += digits[num1] + units[4];
		if (num > 0 && num < 1000)
			result += digits[0];
	}

	if (num >= 1000) {
		Long num1 = num / 1000;
		num %= 1000;
		result += digits[num1] + units[3];
		if (num > 0 && num < 100)
			result += digits[0];
	}

	if (num >= 100) {
		Long num1 = num / 100;
		num %= 100;
		result += digits[num1] + units[2];
		if (num > 0 && num < 10)
			result += digits[0];
	}

	if (num >= 10) {
		Long num1 = num / 10;
		num %= 10;
		if (num1 != 1 || !result.empty())
			result += digits[num1];
		result += units[1];
	}

	if (num > 0 || result.empty())
		result += digits[num];

	if (result.substr(0, 2) == "一十")
		result = result.substr(1);
	return result;
}

// split() splits a string into substrings (each element can be empty)
// can reconstruct original string with `join()`
// two contiguous separators mean there is an empty element in between
// if `str` starts or end with a separator, then there is an empty element at the beginning or end
// str = v[0] + sep + v[1] + sep + ... v.back()
inline void split(vector<Str> &v, Str_I str, Str_I sep = " ", bool has_empty = false)
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (has_empty || ind1 > ind0)
			v.push_back(str.substr(ind0, ind1-ind0));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str) || has_empty)
		v.push_back(str.substr(ind0));
}

inline void join(Str_O str, const vector<Str> &v, Str_I sep = " ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += e + sep;
	str.resize(str.size() - sep.size());
}

inline void split(vector<Str32> &v, Str32_I str, Str32_I sep = U" ", bool has_empty = false)
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (has_empty || ind1 > ind0)
			v.push_back(str.substr(ind0, ind1-ind0));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str) || has_empty)
		v.push_back(str.substr(ind0));
}

inline void join(Str32_O str, const vector<Str32> &v, Str32_I sep = U" ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += e + sep;
	str.resize(str.size() - sep.size());
}

inline void split(set<Str> &v, Str_I str, Str_I sep = " ", bool has_empty = false)
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (has_empty || ind1 > ind0)
			v.insert(str.substr(ind0, ind1-ind0));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str) || has_empty)
		v.insert(str.substr(ind0));
}

inline void join(Str_O str, const set<Str> &v, Str_I sep = " ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += e + sep;
	str.resize(str.size() - sep.size());
}

inline void split(set<Str32> &v, Str32_I str, Str32_I sep = U" ", bool has_empty = false)
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (has_empty || ind1 > ind0)
			v.insert(str.substr(ind0, ind1-ind0));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str) || has_empty)
		v.insert(str.substr(ind0));
}

inline void join(Str32_O str, const set<Str32> &v, Str32_I sep = U" ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += e + sep;
	str.resize(str.size() - sep.size());
}

inline void split(unordered_set<Str> &v, Str_I str, Str_I sep = " ", bool has_empty = false)
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (has_empty || ind1 > ind0)
			v.insert(str.substr(ind0, ind1-ind0));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str) || has_empty)
		v.insert(str.substr(ind0));
}

inline void join(Str_O str, const unordered_set<Str> &v, Str_I sep = " ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += e + sep;
	str.resize(str.size() - sep.size());
}

inline void split(unordered_set<Str32> &v, Str32_I str, Str32_I sep = U" ", bool has_empty = false)
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (has_empty || ind1 > ind0)
			v.insert(str.substr(ind0, ind1-ind0));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str) || has_empty)
		v.insert(str.substr(ind0));
}

inline void join(Str32_O str, const unordered_set<Str32> &v, Str32_I sep = U" ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += e + sep;
	str.resize(str.size() - sep.size());
}


// integer-output version of split()
// str = v[0] + sep + v[1] + sep + ... v.back()
inline void split(vector<Llong> &v, Str_I str, Str_I sep = " ")
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (ind0 < ind1)
			v.push_back(str2Llong(str.substr(ind0, ind1-ind0)));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str))
		v.push_back(str2Llong(str.substr(ind0)));
}

inline void join(Str_O str, const vector<Llong> &v, Str_I sep = " ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += to_string(e) + sep;
	str.resize(str.size() - sep.size());
}

inline void split(vector<Llong> &v, Str32_I str, Str32_I sep = U" ")
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (ind0 < ind1)
			v.push_back(str2Llong(str.substr(ind0, ind1-ind0)));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str))
		v.push_back(str2Llong(str.substr(ind0)));
}

inline void join(Str32_O str, const vector<Llong> &v, Str32_I sep = U" ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += to_string(e) + sep;
	str.resize(str.size() - sep.size());
}

inline void split(set<Llong> &v, Str_I str, Str_I sep = " ")
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (ind0 < ind1)
			v.insert(str2Llong(str.substr(ind0, ind1-ind0)));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str))
		v.insert(str2Llong(str.substr(ind0)));
}

inline void join(Str_O str, const set<Llong> &v, Str_I sep = " ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += to_string(e) + sep;
	str.resize(str.size() - sep.size());
}

inline void split(set<Llong> &v, Str32_I str, Str32_I sep = U" ")
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (ind0 < ind1)
			v.insert(str2Llong(str.substr(ind0, ind1-ind0)));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str))
		v.insert(str2Llong(str.substr(ind0)));
}

inline void join(Str32_O str, const set<Llong> &v, Str32_I sep = U" ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += to_string(e) + sep;
	str.resize(str.size() - sep.size());
}

inline void split(unordered_set<Llong> &v, Str_I str, Str_I sep = " ")
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (ind0 < ind1)
			v.insert(str2Llong(str.substr(ind0, ind1-ind0)));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str))
		v.insert(str2Llong(str.substr(ind0)));
}

inline void join(Str_O str, const unordered_set<Llong> &v, Str_I sep = " ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += to_string(e) + sep;
	str.resize(str.size() - sep.size());
}

inline void split(unordered_set<Llong> &v, Str32_I str, Str32_I sep = U" ")
{
	Long ind0 = 0; v.clear();
	if (str.empty()) return;
	while (1) {
		Long ind1 = str.find(sep, ind0);
		if (ind1 < 0) break;
		if (ind0 < ind1)
			v.insert(str2Llong(str.substr(ind0, ind1-ind0)));
		ind0 = ind1 + 1;
	}
	if (ind0 < size(str))
		v.insert(str2Llong(str.substr(ind0)));
}

inline void join(Str32_O str, const unordered_set<Llong> &v, Str32_I sep = U" ")
{
	str.clear();
	if (v.empty()) return;
	for (auto &e : v)
		str += to_string(e) + sep;
	str.resize(str.size() - sep.size());
}


// give the mantissa of a double
// if `prec` is big enough, there will be no error
inline Str mantissa_str(Doub x, char prec = 17)
{
	Str str;
	// bool neg = false;
	if (x < 0) x = -x; // neg = true;
	x = double_set_exp(x, 0); // erase exponent
	if (x < 1) {
		x *= 10; str = '0';
	}
	else {
		char i = floor(x);
		str = '0' + i;
		x -= i; x *= 10;
	}
	if (x > 0) str += '.';
	assert(x < 10);
	while (x != 0 && size(str) <= prec) {
		char i = floor(x);
		str += '0' + i;
		x -= i;
		x *= 10;
	}
	return str;
}

// parse a double, return the index after the processed char
// return -1 if failed
inline Long str2Doub(Doub_O x, Str_I str, Long start = 0)
{
	if (start < 0 || start >= size(str))
		return -1;
	const char *beg = str.c_str() + start;
	char* end = nullptr;
	errno = 0;
	x = std::strtod(beg, &end);
	if (errno == ERANGE)
		return -1;
	start += end - beg;
	// if there are too many digits, strtod will not process the extra ones
	// but we still want to jump them
	while (start < size(str) && is_num(str[start]))
		++start;
	return start;
}

inline Doub str2Doub(Str_I str, Long_I start = 0)
{
	Doub x;
	if (str2Doub(x, str, start) < 0)
		SLS_ERR("str2Doub(): not a double: " + str.substr(start, 20));
	return x;
}

} // namespace slisc
