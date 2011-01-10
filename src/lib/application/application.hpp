/* 
 * File:   application.hpp
 * Author: jolo
 *
 * Created on 10. Januar 2011, 14:14
 */

#ifndef APPLICATION_HPP
#define	APPLICATION_HPP

#include <common/common.hpp>

class Database;
class Session;

class Application {
public:
    Application();
    virtual ~Application();

    virtual void setDatabase(Database* d);
    const bool hasDatabase() const;
    virtual Database* database() const;

    virtual Session* session() const;
    virtual void setSession(Session* s);
    
    virtual Integer exec() = 0;
private:
    Application(const Application& o);

    Database* _database;
    Session* _session;
};

#endif	/* APPLICATION_HPP */

