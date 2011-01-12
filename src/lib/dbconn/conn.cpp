#include <dbconn/conn.hpp>

Conn::Conn()
: _database(0) {
}

void Conn::setDatabase(Database* db) {
    _database = db;
}

const bool Conn::hasDatabase() const {
    return (0 != _database);
}

Database* Conn::database() const {
    return _database;
}