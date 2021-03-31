// print each argument to a line
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i) {
		cout << "arg" << i << ":" << endl;
		cout << argv[i] << endl;
	}
}
