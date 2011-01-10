#include <application/application.hpp>

Application::Application()
: _database(0), _session(0) {
}

Application::Application(const Application& o) {
}

Application::~Application() {
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