#include <application/application.hpp>
#include <application/settings.hpp>

#include <dbconn/conn.hpp>
#include <orm/session.hpp>
#include <dbmodel/database.hpp>

Application::Application()
: _database(0), _session(0), _conn(0), _settings(0) {
    _settings = new Settings();
}

Application::Application(const Application& o) {
}

Application::~Application() {
    if (_database) {
        delete _database;
    }
    if (_session) {
        delete _session;
    }
    if (_conn) {
        delete _conn;
    }
    delete _settings;
}

const bool Application::hasDatabase() const {
    return (0 != database());
}

Database* Application::database() const {
    return _database;
}

void Application::setDatabase(Database* d) {
    _database = d;
}

Session* Application::session() const {
    return _session;
}

void Application::setSession(Session* s) {
    _session = s;    
}

void Application::setConnection(Conn* c) {
    _conn = c;
}

Conn* Application::connection() const {
    return _conn;
}

Settings* Application::settings() const {
    return _settings;
}