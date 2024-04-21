#include "../SLISC/util/json.h"
#include "../SLISC/file/file.h"

using namespace slisc;
using json = nlohmann::json; // the main class

void test_json()
{
	string str;
	read(str, "tests/test_file/test1.json");
	// can parse string or fstream
	json data = json::parse(str);

	// cout << data.dump() << endl; // no space or return
	// cout << data.dump(2) << endl; // 2 space indent

	data["menu"]["popup"]["menuitem"][0]["onclick"] = "myfun()";
	// cout << data.dump(2) << endl;

	// a value is also a json object
	json popup = data["menu"]["popup"];
	// cout << popup.dump(2) << endl;
	data["menu"].erase("id");
	data["menu"]["popup"]["menuitem"].erase(1);
	// cout << data.dump(2) << endl;
}

#ifndef SLS_TEST_ALL
int main() { test_json(); }
#endif
