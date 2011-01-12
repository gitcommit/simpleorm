#include <orm/session.hpp>

#include <boost/assert.hpp>

#include <orm/mapping.hpp>
#include <dbconn/conn.hpp>

Session::Session()
: _conn(0) {
}

Session::Session(const Session& o) {
}

Session::~Session() {
    // _conn is deleted in the application dtor
}

void Session::add(Entity* e) {
    BOOST_ASSERT(0 != e);
    BOOST_ASSERT(! contains(e));
    _entities.push_back(e);
}

void Session::remove(Entity* e) {
    BOOST_ASSERT(0 != e);
    BOOST_ASSERT(contains(e));
    for (std::vector<Entity*>::iterator i = _entities.begin(); i != _entities.end(); ++i) {
        if ((*i) == e) {
            _entities.erase(i);
            return;
        }
    }
}

bool Session::contains(Entity* e) const {
    BOOST_ASSERT(0 != e);
    for (std::vector<Entity*>::const_iterator i = _entities.begin(); i != _entities.end(); ++i) {
        if ((*i) == e) {
            return true;
        }
    }
    return false;
}

std::vector<Entity*> Session::entities() const {
    return _entities;
}

const bool Session::hasConnection() const {
    return (0 != connection());
}

void Session::setConnection(Conn* c) {
    _conn = c;
}

Conn* Session::connection() const {
    return _conn;
}

const bool Session::hasMapping(const String& mappingName) const {
    return (_mappings.find(mappingName) != _mappings.end());
}

Mapping* Session::createMapping(const String& mappingName) {
    return add(mappingName, new Mapping());
}

Mapping* Session::add(const String& mappingName, Mapping* m) {
    _mappings.insert(std::make_pair(mappingName, m));
    return mappingByName(mappingName);
}

Mapping* Session::mappingByName(const String& mappingName) const {
    std::map<String, Mapping*>::const_iterator i = _mappings.find(mappingName);
    BOOST_ASSERT(i != _mappings.end());
    return i->second;
}