#include "../SLISC/file/file.h"
#include <iostream>
#ifdef SLS_USE_SQLITE
#include <sqlite3.h>
#endif
#ifdef SLS_USE_SQLITECPP
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#endif

using namespace slisc;

void test_sql_bind()
{
#ifdef SLS_USE_SQLITE
	Str str;
	sqlite3 *db;
	vecStr res_name;
	vecInt res_id, res_age;

	file_remove("test_sql_bind.db");
	int ret = sqlite3_open("test_sql_bind.db", &db);
	SLS_ASSERT(ret == SQLITE_OK);
	
	// create table
	str = "CREATE TABLE NAMES(ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME CHAR(50), AGE INTEGER)";
	ret = sqlite3_exec(db, str.c_str(), NULL, NULL, NULL);
	SLS_ASSERT(ret == SQLITE_OK);

	// insert data using binding
	// https://www.sqlite.org/c3ref/bind_blob.html
	str = "INSERT INTO NAMES(NAME, AGE) VALUES(?, ?)";
	sqlite3_stmt *stmt; // represents str
	ret = sqlite3_prepare_v2(db, str.c_str(), str.size()+1, &stmt, NULL);
	SLS_ASSERT(ret == SQLITE_OK);

	int Nparam = sqlite3_bind_parameter_count(stmt); // # of '?'
	SLS_ASSERT(Nparam == 2);

	vecStr names = {"Alice", "Bob", "Cindy", "Alice"};
	vecInt ages = {10, 20, 30, 40};

	for (Long i = 0, N = size(names); i < N; ++i) {
		ret = sqlite3_bind_text(stmt, 1, names[i].c_str(), names[i].size(), SQLITE_STATIC);
		ret = sqlite3_bind_int(stmt, 2, ages[i]);
		SLS_ASSERT(ret == SQLITE_OK);

		ret = sqlite3_step(stmt);
		SLS_ASSERT(ret == SQLITE_DONE);

		sqlite3_reset(stmt);
		sqlite3_clear_bindings(stmt);
	}
	sqlite3_finalize(stmt);

	// query using one bind parameter
    sqlite3_stmt *stmt2;
	str = "SELECT \"AGE\", \"NAME\", \"ID\" FROM NAMES WHERE \"NAME\" = ?;";
	ret = sqlite3_prepare_v2(db, str.c_str(), str.size()+1, &stmt2, NULL);
	SLS_ASSERT(ret == SQLITE_OK);
	Nparam = sqlite3_bind_parameter_count(stmt2);
	SLS_ASSERT(Nparam == 1);

    str = "Alice";
    ret = sqlite3_bind_text(stmt2, 1, str.c_str(), -1, SQLITE_TRANSIENT);
    SLS_ASSERT(ret == SQLITE_OK);
    while ((ret = sqlite3_step(stmt2)) == SQLITE_ROW) {
        // get return
        res_age.push_back(sqlite3_column_int(stmt2, 0));
        res_name.push_back((char *) sqlite3_column_text(stmt2, 1));
        res_id.push_back(sqlite3_column_int(stmt2, 2));
        // cout << res_id.back() << " " << res_name.back() << " " << res_age.back() << endl;
    }
    if (ret != SQLITE_DONE) {
        Str msg = sqlite3_errmsg(db);
        sqlite3_finalize(stmt2); sqlite3_close(db);
        SLS_ERR("sqlite3_step() 2: " + msg);
    }
    sqlite3_finalize(stmt2);

	SLS_ASSERT(res_id.size() == 2);
	SLS_ASSERT(res_id[0] == 1);
	SLS_ASSERT(res_id[1] == 4);
	SLS_ASSERT(res_name.size() == 2);
	SLS_ASSERT(res_name[0] == "Alice");
	SLS_ASSERT(res_name[1] == "Alice");
	SLS_ASSERT(res_age.size() == 2);
	SLS_ASSERT(res_age[0] == 10);
	SLS_ASSERT(res_age[1] == 40);

	// query using two bind parameters
	str = "SELECT ID FROM NAMES WHERE NAME=?2 AND ID=?1";
	ret = sqlite3_prepare_v2(db, str.c_str(), str.size()+1, &stmt, NULL);
	SLS_ASSERT(ret == SQLITE_OK);

	Nparam = sqlite3_bind_parameter_count(stmt);
	SLS_ASSERT(Nparam == 2);

	ret = sqlite3_bind_text(stmt, 2, "Cindy", strlen("Cindy"), SQLITE_STATIC);
	SLS_ASSERT(ret == SQLITE_OK);

	ret = sqlite3_bind_int(stmt, 1, 3);
	SLS_ASSERT(ret == SQLITE_OK);

	res_id.clear();
	while (sqlite3_step(stmt) == SQLITE_ROW)
		res_id.push_back(sqlite3_column_int(stmt, 0));
	sqlite3_finalize(stmt);

	SLS_ASSERT(res_id.size() == 1);
	SLS_ASSERT(res_id[0] == 3);

	sqlite3_close(db);
#endif
}

void test_sqlite()
{
#ifdef SLS_USE_SQLITE
	test_sql_bind();
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

	sql = "INSERT INTO PERSON"
						"(ID, NAME, SURNAME, AGE, ADDRESS, SALARY)"
						" VALUES "
						"(0, 'Addis', 'Chen', 30, 'Claflin Rd, Manhattan, KS, 66502', 1500.03);"
			 "INSERT INTO PERSON"
						" VALUES "
						"(1, 'Bob', 'Chen', 31, 'Anderson Ave, Manhattan, KS, 66502', 1500.03);";
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		SLS_ERR("Error Inserting Table :" + Str(messaggeError));
		sqlite3_free(messaggeError);
	}
	sqlite3_close(DB);

    // test SQLiteCpp
#ifdef SLS_USE_SQLITECPP
    cout << "(testing SQLiteCpp)" << endl;
    try {
        SQLite::Database db("test_sql_bind.db");
        SQLite::Statement query(db, "SELECT * FROM names WHERE age > ?");
        SLS_ASSERT(query.getColumnName(0) == Str("ID"));
        SLS_ASSERT(query.getColumnDeclaredType(0) == Str("INTEGER"));
        SLS_ASSERT(query.getColumnName(1) == Str("NAME"));
        SLS_ASSERT(query.getColumnDeclaredType(1) == Str("CHAR(50)"));
        SLS_ASSERT(query.getColumnName(2) == Str("AGE"));
        SLS_ASSERT(query.getColumnDeclaredType(2) == Str("INTEGER"));
        query.bind(1, 20);

        vecInt id, age;
        vecStr name;
        while (query.executeStep())
        {
            SLS_ASSERT(!query.isColumnNull(0));
            id.push_back(query.getColumn(0));
            SLS_ASSERT(!query.isColumnNull(1));
            name.push_back(query.getColumn(1));
            SLS_ASSERT(!query.isColumnNull(2));
            age.push_back(query.getColumn(2));
        }
        SLS_ASSERT(id.size() == 2);
        SLS_ASSERT(name.size() == 2);
        SLS_ASSERT(age.size() == 2);
        SLS_ASSERT(id[0] == 3);
        SLS_ASSERT(name[0] == "Cindy");
        SLS_ASSERT(age[0] == 30);
        SLS_ASSERT(id[1] == 4);
        SLS_ASSERT(name[1] == "Alice");
        SLS_ASSERT(age[1] == 40);
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }
#else
    cout << "---------- sqlite cpp disabled! ----------" << endl;
#endif

#else
	cout << "---------- disabled! ----------" << endl;
#endif
}
