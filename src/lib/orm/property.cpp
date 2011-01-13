#include <orm/property.hpp>

#include <sstream>

#include <dbmodel/primarykeyconstraint.hpp>

Property::Property(Entity* entity, const String& name, const boost::any& value)
: _entity(entity), _name(name), _value(value) {
}

Property::Property(const Property& o)
: _entity(o._entity), _name(o._name), _value(o._value) {
}

Property::~Property() {
}

const bool Property::hasEntity() const {
    return (0 != _entity);
}

String Property::name() const {
    return _name;
}

boost::any Property::value() const {
    return _value;
}

Entity* Property::entity() const {
    return _entity;
}

void Property::setValue(const boost::any& value) {
    _value = value;
}

Integer Property::toInteger() const {
    return boost::any_cast<Integer > (_value);
}

String Property::toString() const {
    std::stringstream ss;
    if (isNumeric()) {
        ss << toNumeric();
        return ss.str();
    }
    if (isInteger()) {
        ss << toInteger();
        return ss.str();
    }

    try {
        return boost::any_cast<String > (_value);
    } catch (boost::bad_any_cast e) {
        return e.what();
    }
}

Numeric Property::toNumeric() const {
    return boost::any_cast<Numeric > (_value);
}

const bool Property::isInteger() const {
    return (_value.type() == typeid (Integer));
}

const bool Property::isNumeric() const {
    return (_value.type() == typeid (Numeric));
}

const bool Property::isString() const {
    return (_value.type() == typeid (String));
}

void Property::printOn(std::ostream& strm) {
    std::stringstream ss;
    ss << name() << ": " << toString();
    strm << ss.str();
}

std::ostream & operator<<(std::ostream& strm, Property& p) {
    p.printOn(strm);
    return strm;
}