#pragma once
#define SLS_INP(var) do {cin >> var; cout << #var << " = " << var << ";    ";} while(0);

namespace slisc {
inline void cin_line()
{
	cin.ignore(1000, '\n');
    cout << endl;
}
} // namespace slisc
