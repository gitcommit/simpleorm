#include <orm/mapping.hpp>

#include <boost/assert.hpp>

#include <orm/mappedproperty.hpp>

Mapping::Mapping(Table* t)
: _table(0) {
    setTable(t);
}

Mapping::Mapping(const Mapping& o)
: _mappedProperties(o._mappedProperties) {
}

Mapping::~Mapping() {
}

Table* Mapping::table() const {
    return _table;
}

void Mapping::setTable(Table* t) {
    _table = t;
}

const bool Mapping::hasTable() const {
    return (0 != table());
}

MappedProperty* Mapping::add(MappedProperty* p) {
    _mappedProperties.insert(std::make_pair(p->propertyName(), p));
}

const bool Mapping::hasMappedProperty(const String& propertyName) const {
    return (_mappedProperties.end() != _mappedProperties.find(propertyName));
}

const bool Mapping::hasMappedProperty(TableColumn* col) const {
    for (std::map<String, MappedProperty*>::const_iterator i = _mappedProperties.begin(); i != _mappedProperties.end(); ++i) {
        if (i->second->column() == col) {
            return true;
        }
    }
    return false;
}

MappedProperty* Mapping::mappedProperty(const String& propertyName) const {
    BOOST_ASSERT(hasMappedProperty(propertyName));
    return _mappedProperties.find(propertyName)->second;
}

MappedProperty* Mapping::createProperty(const String& propertyName, TableColumn* col) {
    return add(new MappedProperty(this, propertyName, col));
}

std::map<String, MappedProperty*> Mapping::mappedPropertiesMap() const {
    return _mappedProperties;
}

StringVector Mapping::propertyNames() const {
    StringVector v;
    for (std::map<String, MappedProperty*>::const_iterator i = _mappedProperties.begin();
            i != _mappedProperties.end(); ++i) {
        v.push_back(i->first);
    }
    return v;
}

std::vector<MappedProperty*> Mapping::mappedProperties() const {
    std::vector<MappedProperty*> v;
    for (std::map<String, MappedProperty*>::const_iterator i = _mappedProperties.begin();
            i != _mappedProperties.end(); ++i) {
        v.push_back(i->second);
    }
    return v;
}