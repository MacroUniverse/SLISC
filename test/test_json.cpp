#include "../SLISC/file/file.h"
#include "../SLISC/util/json.h"

using namespace slisc;
using json = nlohmann::json; // the main class

void test_json()
{
#if !(defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(__MSYS__))
	string str;
	read(str, "test/test_file/test1.json");
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
#else
	std::cout << "---------- disabled! ----------" << std::endl;
#endif
}
