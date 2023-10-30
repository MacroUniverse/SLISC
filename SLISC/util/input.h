#pragma once
#include "../global.h"
#define SLS_INP(var) do {cin >> var; cout << #var << " = " << var << ";    "; if (!cin.good()) SLS_ERR("illegal input file!");} while(0);

namespace slisc {

// use `./scratch.x < scratch.inp` to use input file
// use Ctrl+D to simulate end of file in stdin
// allows multiple spaces or returns as separator
inline void read_input(vector<int> &v_num, vector<string> &v_str)
{
    int num; string str;
    while (cin >> num >> str) {
        v_num.push_back(num);
        v_str.push_back(move(str));
    }
}

// read_input(), but use Enter to end input
// ask to try again for illegal input
// v_str[i] ends until end of the line
inline void read_input2(vector<int> &v_num, vector<string> &v_str)
{
	size_t ind; string line;
    while (1) {
		getline(cin, line);
		if (!cin.good() || line.find_first_not_of(' ') == string::npos)
			break;

		try {
			v_num.push_back(stoi(line, &ind));
			v_str.push_back(line.substr(line.find_first_not_of(' ', ind)));
		}
		catch (...) { cerr << "illegal input, please try again." << endl; }
    }
}

inline void cin_comment()
{
	string str;
	cin >> str;
	if (str.size() > 0 && str.substr(0, 2) != "//")
		SLS_ERR("each line must only be followed by a comment starting with //");
}

inline void cin_ignore_line()
{ cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); }

inline void cin_LF()
{ cin_ignore_line(); cout << endl; }

inline void fin_comment(ifstream &fin)
{
	string str;
	fin >> str;
	if (str.size() > 0 && str.substr(0, 2) != "//")
		SLS_ERR("each line must only be followed by a comment starting with //");
}

inline void fin_ignore_line(ifstream &fin)
{ fin.ignore(numeric_limits<std::streamsize>::max(), '\n'); }

inline void fin_LF(ifstream &fin)
{ fin_ignore_line(fin); cout << endl; }

} // namespace slisc
