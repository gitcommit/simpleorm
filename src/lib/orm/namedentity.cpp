#include <orm/namedentity.hpp>

#include <sstream>

NamedEntity::NamedEntity(Session* s, const Integer& id, const String& name)
: IdentifiedEntity(s, id) {
    setName(name);
}

NamedEntity::NamedEntity(NamedEntity* p, const Integer& id, const String& name)
: IdentifiedEntity(p, id) {
    setName(name);
}

NamedEntity::~NamedEntity() {
}

const bool NamedEntity::hasName() const {
    return isNotEmpty(name());
}

String NamedEntity::name() const {
    return property("name").toString();
}

void NamedEntity::setName(const String& n) {
    setProperty("name", n);
}

String NamedEntity::toString() const {
    std::stringstream s;
    s << name() << " " << idInBrackets();
    return s.str();
}