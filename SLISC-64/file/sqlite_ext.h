// sqlite3 utils
// don't rely on the return order!

#pragma once
#include <sqlite3.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include "../arith/scalar_arith.h"
#include "../str/unicode.h"

namespace slisc {

inline void exec(Str_I cmd, SQLite::Database &db)
{
    SQLite::Statement stmt(db, cmd);
    stmt.exec();
}

// check foreign key existence by default
// run after db is opened (default: OFF)
inline void check_foreign_key(SQLite::Database &db, bool on = true)
{
    Str cmd = on ? "ON" : "OFF";
    cmd = "PRAGMA foreign_keys = " + cmd + ";";
    exec(cmd, db);
}

// check if an entry exists
inline bool exist(Str_I table, Str_I field, Str_I val, SQLite::Database &db_read)
{
    Str cmd = "SELECT 1 FROM \"" + table + "\" WHERE \"" + field + "\" = ?;";
    SQLite::Statement stmt(db_read, cmd);
    stmt.bind(1, val);
    return stmt.executeStep();
}

// count
inline bool count(Str_I table, Str_I field, Str_I text, SQLite::Database &db)
{
    Str cmd = "SELECT COUNT(*) FROM \"" + table + "\" WHERE \"" + field + "\" = ?;";
    SQLite::Statement stmt(db, cmd);
    stmt.bind(1, text);
    if (!stmt.executeStep()) throw Str("unknown!");
    return (int)stmt.getColumn(0);
}

// get an integer
inline Llong get_int(Str_I table, Str_I field, Str_I val, Str_I field_out, SQLite::Database &db)
{
    Llong ret;
    Str cmd = "SELECT \"" + field_out + "\" FROM \"" + table + "\" WHERE \"" + field + "\" = '" + val + "';";
    SQLite::Statement stmt(db, cmd);
	if (stmt.executeStep())
        ret = (int)stmt.getColumn(0);
    return ret;
}

inline Str get_text(Str_I table, Str_I field, Str_I val, Str_I field_out, SQLite::Database &db)
{
    Str ret;
    Str cmd = "SELECT \"" + field_out + "\" FROM \"" + table + "\" WHERE \"" + field + "\" = '" + val + "';";
    SQLite::Statement stmt(db, cmd);
    if (stmt.executeStep())
        ret = (const char*)stmt.getColumn(0);
    return ret;
}

// get single column
inline void get_column(vecStr_O data, Str_I table, Str_I field, SQLite::Database &db)
{
	data.clear();
    Str cmd = "SELECT \"" + field + "\" FROM " + table;
    SQLite::Statement stmt(db, cmd);
	while (stmt.executeStep())
		data.push_back(stmt.getColumn(0));
}

inline void get_column(vecStr32_O data, Str_I table, Str_I field, SQLite::Database &db)
{
	data.clear();
    Str cmd = "SELECT \"" + field + "\" FROM " + table;
    SQLite::Statement stmt(db, cmd);
	while (stmt.executeStep()) {
        const char *p = stmt.getColumn(0);
        if (!p)
            data.emplace_back();
        else
		    data.push_back(u32(p));
    }
}

inline void get_column(vecLlong_O data, Str_I table, Str_I field, SQLite::Database &db)
{
	data.clear();
    Str cmd = "SELECT \"" + field + "\" FROM " + table;
    SQLite::Statement stmt(db, cmd);
	while (stmt.executeStep())
		data.push_back((int)stmt.getColumn(0));
}

// get single row
inline void get_row(vecStr_O data, Str_I table, Str_I field, Str_I val, vecStr_I fields_out, SQLite::Database &db)
{
    data.clear();
    Str cmd = "SELECT ";
    for (auto &field_out : fields_out)
        cmd += '"' + field_out + "\",";
    cmd.pop_back();
    SQLite::Statement stmt(db, cmd);
    for (auto &field_out : fields_out)
        cmd += '"' + field_out + "\",";
    cmd.pop_back();
    cmd += " FROM " + table + " WHERE " + field + " = '" + val + "';";
	if (stmt.executeStep()) {
        for (Long i = 0; i < size(fields_out); ++i)
		    data.push_back(stmt.getColumn(i));
    }
}

inline void get_row(vecLong_O data, Str_I table, Str_I field, Str_I val, vecStr_I fields_out, SQLite::Database &db)
{
    data.clear();
    Str cmd = "SELECT ";
    for (auto &field_out : fields_out)
        cmd += '"' + field_out + "\",";
    cmd.pop_back();
    SQLite::Statement stmt(db, cmd);
    for (auto &field_out : fields_out)
        cmd += '"' + field_out + "\",";
    cmd.pop_back();
    cmd += " FROM " + table + " WHERE " + field + " = '" + val + "';";
    if (stmt.executeStep()) {
        for (Long i = 0; i < size(fields_out); ++i)
            data.push_back((int)stmt.getColumn(i));
    }
}

// remove everything inside table
inline void table_clear(Str_I table, SQLite::Database &db)
{
    Str cmd = "DELETE FROM \"" + table + "\";";
    exec(cmd, db);
}

} // namespace slisc
