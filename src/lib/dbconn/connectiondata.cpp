#include <dbconn/connectiondata.hpp>

#include <sstream>

ConnectionData::ConnectionData(const String& host, const Integer& port, 
        const String& database, const String& user, const String& password,
        const String& driver)
        : _host(host),
        _port(port),
        _database(database),
        _user(user),
        _password(password),
        _driver(driver) {}

ConnectionData::ConnectionData(const ConnectionData& o)
        : _host(o._host),
        _port(o._port),
        _database(o._database),
        _user(o._user),
        _password(o._password),
        _driver(o._driver) {}

ConnectionData::~ConnectionData() {}

void ConnectionData::setHost(const String& h) {
    _host = h;
}

void ConnectionData::setPort(const Integer& p) {
    _port = p;
}

void ConnectionData::setDatabase(const String& d) {
    _database = d;
}

void ConnectionData::setUser(const String& u) {
    _user = u;
}

void ConnectionData::setPassword(const String& p) {
    _password = p;
}

void ConnectionData::setDriver(const String& d) {
    _driver = d;
}

String ConnectionData::host() const {
    return _host;
}

Integer ConnectionData::port() const {
    return _port;
}

String ConnectionData::database() const {
    return _database;
}

String ConnectionData::user() const {
    return _user;
}

String ConnectionData::password() const {
    return _password;
}

String ConnectionData::driver() const {
    return _driver;
}

String ConnectionData::connectionString() const {
    std::stringstream ss;
    ss << driver() << "://" << user() << ":" << password() 
       << "@" << host() << ":" << port()
       << "/" << database();
    return ss.str();
}
