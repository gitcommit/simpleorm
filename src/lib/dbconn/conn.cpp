#include <dbconn/conn.hpp>

#include <iostream>
#include <boost/assert.hpp>

#include <dbconn/connectiondata.hpp>

#include <dbconn/connectionerror.hpp>
#include <dbconn/transactionerror.hpp>

#include <libpq-fe.h>

Conn::Conn()
: _database(0), _c(0) {
}

Conn::Conn(const Conn& o)
: _database(o._database), _c(o._c) {}

Conn::~Conn() {
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

const bool Conn::connect(ConnectionData* cd) {
    BOOST_ASSERT(0 != cd);
    std::cout << "\tConnecting: " << cd->connectionString() << std::endl;
    _c = PQconnectdb(cd->connectionString().c_str());
    if (PQstatus(_c) != CONNECTION_OK) {
        throw ConnectionError(PQerrorMessage(_c), PQstatus(_c));
    }
    return true;
}

const bool Conn::disconnect() {
    PQfinish(_c);
    return true;
}

const bool Conn::begin() {
    return execTransactionCommand("BEGIN;");
}

const bool Conn::commit() {
    return execTransactionCommand("COMMIT;");
}

const bool Conn::rollback() {
    return execTransactionCommand("ROLLBACK;");
}

const bool Conn::savepoint(const String& name) {
    StringStream ss;
    ss << "SAVEPOINT " << name << ";";
    return execTransactionCommand(ss.str());
}

const bool Conn::rollbackTo(const String& savepoint) {
    StringStream ss;
    ss << "ROLLBACK TO " << savepoint << ";";
    return execTransactionCommand(ss.str());
}

const bool Conn::execTransactionCommand(const String& cmd) {
    PGresult* res = PQexec(_c, cmd.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        String msg = PQresultErrorMessage(res);
        PQclear(res);
        throw TransactionError(msg, PQresultStatus(res));
    }
    PQclear(res);
    return true;
}