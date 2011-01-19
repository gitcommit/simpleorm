#ifndef CONN_H
#define CONN_H

#include <common/customtypes.hpp>

#include <libpq-fe.h>

class ConnectionData;
class Database;

class Conn {
public:
    Conn();
    Conn(const Conn& o);
    virtual ~Conn();

    virtual void setDatabase(Database* db);
    virtual const bool hasDatabase() const;
    virtual Database* database() const;

    virtual const bool connect(ConnectionData* cd);
    virtual const bool disconnect();

    virtual const bool begin();
    virtual const bool commit();
    virtual const bool rollback();

    virtual const bool savepoint(const String& name);
    virtual const bool rollbackTo(const String& savepoint);

    virtual const bool execDML(const String& cmd);

protected:
    virtual const bool execTransactionCommand(const String& cmd);

private:
    Database* _database;
    PGconn* _c;
};

#endif CONN_H
