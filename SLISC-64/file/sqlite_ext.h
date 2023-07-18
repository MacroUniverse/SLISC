// sqlite3 utils
// don't rely on the return order!

#pragma once
#include <sqlite3.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <SQLiteCpp/Transaction.h>
#include "../util/STL_util.h"
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
	if (!stmt.executeStep())
		throw std::runtime_error("unknown: " + cmd + " [? = " + text + "]");
	return (int)stmt.getColumn(0);
}

// get an integer
inline Llong get_int(Str_I table, Str_I field, Str_I val, Str_I field_out, SQLite::Database &db)
{
	Llong ret;
	Str cmd = "SELECT \"" + field_out + "\" FROM \"" + table + "\" WHERE \"" + field + "\" = '" + val + "';";
	SQLite::Statement stmt(db, cmd);
	if (!stmt.executeStep())
		throw std::runtime_error("get_text(): row not found: " + cmd);
	ret = (int)stmt.getColumn(0);
	return ret;
}

inline Str get_text(Str_I table, Str_I field, Str_I val, Str_I field_out, SQLite::Database &db)
{
	Str ret;
	Str cmd = "SELECT \"" + field_out + "\" FROM \"" + table + "\" WHERE \"" + field + "\" = '" + val + "';";
	SQLite::Statement stmt(db, cmd);
	if (!stmt.executeStep())
		throw std::runtime_error("get_text(): row not found: " + cmd);
	ret = (const char*)stmt.getColumn(0);
	return ret;
}

// get single column
inline void get_column(vecStr_O data, Str_I table, Str_I field, SQLite::Database &db)
{
	data.clear();
	Str cmd = "SELECT \"" + field + "\" FROM \"" + table + "\";";
	SQLite::Statement stmt(db, cmd);
	while (stmt.executeStep())
		data.push_back(stmt.getColumn(0));
}

inline void get_column(vecStr32_O data, Str_I table, Str_I field, SQLite::Database &db)
{
	data.clear();
	Str cmd = "SELECT \"" + field + "\" FROM \"" + table + "\";";
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
			data.push_back(stmt.getColumn(i).getInt64());
	}
}

// remove everything inside table
inline void table_clear(Str_I table, SQLite::Database &db)
{
	Str cmd = "DELETE FROM \"" + table + "\";";
	exec(cmd, db);
}

// list all user tables of a db
inline void table_list(unordered_set<Str> &tables, SQLite::Database &db)
{
	tables.clear();
	SQLite::Statement stmt(db,
	R"(SELECT "name" FROM "sqlite_master" WHERE "type"='table' AND "name" NOT LIKE 'sqlite_%' ORDER BY "name";)");
	while (stmt.executeStep())
		tables.insert(stmt.getColumn(0));
}

// check if a table exists
inline bool table_exist(Str_I table, SQLite::Database &db)
{
	SQLite::Statement stmt(db,
		R"(SELECT COUNT(*) FROM "sqlite_master" WHERE "type"='table' AND "name"=?;)");
	stmt.bind(1, table);
	SLS_ASSERT(stmt.executeStep());
	return stmt.getColumn(0).getInt();
}

// column info
struct SQLiteColumnInfo {
	Str name;      // Column name
	Str type;      // Column data type
	Str dft_val;   // Default value (as a string, empty if no default value)
	bool pk;       // Column is Primary Key
	bool notnull;  // Column is NOT NULL
};

// if db_old has a table and a field of the same name, type as in db_new of the table remains
// the same, then copy those data from db_old to db_new
// all data from db_new tables will be cleared first!
inline void migrate_db(Str_I file_db_new, Str_I file_db_old)
{
	SQLite::Database db_old(file_db_old, SQLite::OPEN_READWRITE);
	SQLite::Database db_new(file_db_new, SQLite::OPEN_READWRITE);
	Str tmp;
	unordered_set<Str> tables;
	table_list(tables, db_new);
	unordered_map<Str, Str> col_info_old; // col_name -> col_type
	vecStr col_to_cp;
	Str cols_str, vals_str;

	// attach db_new to db_old
	tmp = "ATTACH DATABASE '"; tmp << file_db_new << "' AS db_new";
	db_old.exec(tmp);

	for (auto &table : tables) {
		if (!table_exist(table, db_old))
			continue;
		table_clear(table, db_new);

		// compare cols, get the cols to copy
		SQLite::Statement stmt_col_old(db_old, "PRAGMA table_info(" + table + ");");
		SQLite::Statement stmt_col_new(db_new, "PRAGMA table_info(" + table + ");");
		col_info_old.clear();
		while (stmt_col_old.executeStep()) {
			col_info_old[stmt_col_old.getColumn(1)] =
					stmt_col_old.getColumn(2).getString();
		}
		stmt_col_old.reset();
		col_to_cp.clear();
		while (stmt_col_new.executeStep()) {
			const char *col_name = stmt_col_new.getColumn(1);
			const char *col_type = stmt_col_new.getColumn(2);
			if (col_info_old.count(col_name) && col_info_old[col_name] == col_type)
				col_to_cp.emplace_back(col_name);
		}
		stmt_col_new.reset();
		cols_str.clear();
		for (auto &col : col_to_cp)
			cols_str += "\"" + col + "\", ";
		cols_str.pop_back(); cols_str.pop_back();

		// copy columns in col_to_cp
		tmp = "INSERT INTO db_new."; tmp << table << " (" << cols_str << ") SELECT "
			<< cols_str << " FROM \"" << table << "\";";
		db_old.exec(tmp);
	}
}

} // namespace slisc
