#include <omodel/namedentity.hpp>

#include <sstream>

NamedEntity::NamedEntity(Session* s, const Integer& id, const String& name)
: IdentifiedEntity(s, id), _name(name) {
    setName(name);
}

NamedEntity::NamedEntity(NamedEntity* p, const Integer& id, const String& name)
: IdentifiedEntity(p, id), _name(name) {
    setName(name);
}

NamedEntity::~NamedEntity() {
}

const bool NamedEntity::hasName() const {
    return ("" != name());
}

String NamedEntity::name() const {
    return _name;
}

void NamedEntity::setName(const String& n) {
    _name = n;
}

String NamedEntity::toString() const {
    std::stringstream s;
    s << name() << " " << idInBrackets();
    return s.str();
}