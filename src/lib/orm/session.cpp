#include <orm/session.hpp>

#include <boost/assert.hpp>

Session::Session() {
}

Session::Session(const Session& o) {
}

Session::~Session() {
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