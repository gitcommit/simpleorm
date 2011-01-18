#include <orm/session.hpp>

#include <iostream>

#include <boost/assert.hpp>

#include <orm/mapping.hpp>
#include <dbconn/conn.hpp>

#include <orm/entity.hpp>
#include <orm/property.hpp>

#include "insertvisitor.hpp"

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

Mapping* Session::createMapping(const String& mappingName, Table* t) {
    return add(mappingName, new Mapping(t));
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


void Session::deleteFromDatabase(Entity* e) {
    std::cout << "Session::deleteFromDatabase(" << *e << ")" << std::endl;
}

void Session::reload(Entity* e) {
    std::cout << "Session::reload(" << *e << ")" << std::endl;
}

void Session::insert(Entity* e) {
    std::cout << "Session::insert(" << *e << ")" << std::endl;
    debugEntity(e);
}

void Session::update(Entity* e) {
    std::cout << "Session::update(" << *e << ")" << std::endl;
}

void Session::debugEntity(Entity* e) {
    std::cout << "Entity:" << std::endl;
    InsertVisitor iv;
    e->visit(&iv);
    StringVector pnv = e->propertyNames();
    for (StringVectorConstIterator i = pnv.begin(); i != pnv.end(); ++i) {
        Property p = e->property(*i);
        std::cout << "\t" << p << std::endl;
    }
    std::cout << "INSERT Visitor: " << std::endl << "\t" << iv.query()->sql() << std::endl;
    StringVector valueKeys = iv.query()->keys();
    for (StringVector::const_iterator i = valueKeys.begin(); i != valueKeys.end(); ++i) {
        std::cout << "\t\t" << *i << ": " << iv.query()->value(*i) << std::endl;
    }
}