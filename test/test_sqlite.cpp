#include "../SLISC/global.h"
#include <iostream>
#include <sqlite3.h>

int test_sqlite()
{
	using namespace slisc;
    sqlite3* DB;
    int exit;
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
    return 0;
}
