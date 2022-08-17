#include "../SLISC/disp.h"

void test_disp()
{
	using namespace slisc;
	CmatDoub a(3, 4);
	linspace(a, 1, 12);
	cout << "display matrix:" << endl;
	disp(a);

	cout << "\text_style() :" << endl;
	cout << text_style('r', 'b') + "Bold red text" + text_style() << endl;
    cout << text_style('g') + "Green Text" + text_style() << endl;
    cout << text_style('y', 'u') + "Yellow underlined text" + text_style() << endl;
    cout << text_style('b') + "Blue text" + text_style() << endl;
    cout.flush();
}
