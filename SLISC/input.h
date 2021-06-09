#pragma once
#include "global.h"
#define SLS_INP(var) do {cin >> var; cout << #var << " = " << var << ";    "; if (!cin.good()) SLS_ERR("illegal input file!");} while(0);

namespace slisc {
inline void cin_comment()
{
    string str;
    cin >> str;
    if (str.size() > 0 && str.substr(0, 2) != "//")
        SLS_ERR("each line must only be followed by a comment starting with //");
}

inline void cin_LF()
{
    cin.ignore(1000, '\n');
    cout << endl;
}
} // namespace slisc
