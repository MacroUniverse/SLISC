#include "../SLISC/file.h"
#include <iostream>
#ifdef SLS_USE_SQLITE
#include <sqlite3.h>
#endif

void test_sqlite()
{
    using namespace slisc;
#ifdef SLS_USE_SQLITE
    sqlite3* DB;
    int exit;
    file_remove("example.db");
    exit = sqlite3_open("example.db", &DB);
    if (exit) {
		cout << sqlite3_errmsg(DB) << endl;
        SLS_ERR("Error open DB!");
    }
	char* messaggeError;
	string sql = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );";
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        SLS_ERR("Error Create Table");
        sqlite3_free(messaggeError);
    }
    sqlite3_close(DB);
#else
	cout << "disabled!" << endl;
#endif
}
