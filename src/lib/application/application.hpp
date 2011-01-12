/* 
 * File:   application.hpp
 * Author: jolo
 *
 * Created on 10. Januar 2011, 14:14
 */

#ifndef APPLICATION_HPP
#define	APPLICATION_HPP

#include <common/customtypes.hpp>

class Database;
class Session;
class Conn;
class Settings;

class Application {
public:
    Application();
    virtual ~Application();

    virtual void setDatabase(Database* d);
    const bool hasDatabase() const;
    virtual Database* database() const;

    virtual Session* session() const;
    virtual void setSession(Session* s);

    virtual Conn* connection() const;
    virtual void setConnection(Conn* c);

    virtual Settings* settings() const;
    
    virtual Integer exec() = 0;
private:
    Application(const Application& o);

    Database* _database;
    Conn* _conn;
    Session* _session;
    Settings* _settings;
};

#endif	/* APPLICATION_HPP */

