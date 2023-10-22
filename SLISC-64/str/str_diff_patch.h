#pragma once

#include "str.h"

namespace slisc {

// recover from str_diff()
inline void str_patch(Str_O str2, Str_I str1, const vector<tuple<size_t, size_t, Str>> &diff)
{
	size_t ind1 = 0;
	str2.clear();
	for (auto &e : diff) {
		size_t start = get<0>(e );
		size_t size = get<1>(e );
		const Str &str = get<2>(e);
		str2 += str1.substr(ind1, start-ind1);
		str2 += str;
		ind1 = start + size;
	}
	str2 += str1.substr(ind1);
}

// calculate the difference between two strings
// diff: vector<(start, size, string)>
// str1.replace(start, size, string) from back to front will result in str2
inline void str_diff(vector<tuple<size_t, size_t, Str>> &diff, Str_I str1, Str_I str2, bool debug = false)
{
	size_t ind1 = 0, ind2 = 0, start1, start2, end1, end2, ind, N_match = 10, N_skip = 10;
	diff.clear();
	static Str tmp;
	while (ind1 < str1.size() && ind2 < str2.size() && str1[ind1] == str2[ind2])
		++ind1, ++ind2;
	if (ind1 == str1.size() || ind2 == str2.size()) {
		diff.emplace_back(ind1, str1.size()-ind1, str2.substr(ind2));
		if (debug) {
			str_patch(tmp, str1, diff);
			if (tmp != str2) {
				cout<< "\n----- str1 ------------------\n"
					<< str1
					<< "\n----- str2 ------------------\n"
					<< str2
					<< "\n----- str2 reconstruct ------\n"
					<< tmp
					<< "\n-----------------------------\n" << endl;
				exit(1);
			}
		}
		return;
	}
	start1 = ind1; start2 = ind2; // where diff start

	while (str2.size() - ind2 >= N_match) {
		ind = str1.find(str2.substr(ind2, N_match), ind1);
		if (ind != npos) { // match found
			end1 = ind; end2 = ind2;
			do { --end1; --end2; } while (end2 >= start2 && str1[end1] == str2[end2]);
			++end1; ++end2;
			diff.emplace_back(start1, end1-start1, str2.substr(start2, end2-start2));
			ind1 = ind+N_match; ind2 += N_match;
			while (ind1 < str1.size() && ind2 < str2.size() && str1[ind1] == str2[ind2])
				++ind1, ++ind2;
			if (ind1 == str1.size() || ind2 == str2.size()) {
				start1 = ind1; start2 = ind2;
				break;
			}
			start1 = ind1; start2 = ind2; // where diff start
			continue;
		}
		else { // match not found
			ind2 += N_skip;
			if (str2.size() - ind2 >= N_match)
				continue;
			else
				break;
		}
	}
	diff.emplace_back(start1, str1.size()-start1, str2.substr(start2));
	if (debug) {
		str_patch(tmp, str1, diff);
		if (tmp != str2) {
			cout<< "\n----- str1 ------------------\n"
				<< str1
				<< "\n----- str2 ------------------\n"
				<< str2
				<< "\n----- str2 reconstruct ------\n"
				<< tmp
				<< "\n-----------------------------\n" << endl;
			exit(1);
		}
	}
}

} // end namespace slisc
