#include <application/settings.hpp>

#include <dbconn/connectiondata.hpp>

Settings::Settings()
: _connectionData(0) {
    _connectionData = new ConnectionData();
}

Settings::Settings(const Settings& o) {
}

Settings::~Settings() {
    delete _connectionData;
}

ConnectionData* Settings::connectionData() const {
    return _connectionData;
}