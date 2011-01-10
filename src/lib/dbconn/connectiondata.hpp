/* 
 * File:   connectiondata.hpp
 * Author: jolo
 *
 * Created on 8. Januar 2011, 16:38
 */

#ifndef CONNECTIONDATA_HPP
#define	CONNECTIONDATA_HPP

#include <common/common.hpp>

class ConnectionData {
public:
    ConnectionData(const String& host,
            const Integer& port,
            const String& database,
            const String& user,
            const String& password,
            const String& driver = "QPSQL7");
    ConnectionData(const ConnectionData& o);
    virtual ~ConnectionData();

    virtual void setHost(const String& h);
    virtual void setPort(const Integer& p);
    virtual void setDatabase(const String& d);
    virtual void setUser(const String& u);
    virtual void setPassword(const String& p);
    virtual void setDriver(const String& d);

    String host() const;
    Integer port() const;
    String database() const;
    String user() const;
    String password() const;
    String driver() const;
    
    virtual String connectionString() const;
    
private:
    String _host;
    Integer _port;
    String _database;
    String _user;
    String _password;
    String _driver;
};

#endif	/* CONNECTIONDATA_HPP */

