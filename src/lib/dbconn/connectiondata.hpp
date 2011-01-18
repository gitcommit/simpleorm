/* 
 * File:   connectiondata.hpp
 * Author: jolo
 *
 * Created on 8. Januar 2011, 16:38
 */

#ifndef CONNECTIONDATA_HPP
#define	CONNECTIONDATA_HPP

#include <common/customtypes.hpp>

class ConnectionData {
public:
    ConnectionData(const String& host = "localhost",
            const Integer& port = 5432,
            const String& database = "fgeo",
            const String& user = "fgeo",
            const String& password = "changeme",
            const String& driver = "QPSQL7");
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
    Integer connectTimeout() const;
    
    virtual String connectionString() const;
    
private:
    ConnectionData(const ConnectionData& o);

    String _host;
    Integer _port;
    String _database;
    String _user;
    String _password;
    String _driver;
    Integer _connectTimeout;
};

#endif	/* CONNECTIONDATA_HPP */

