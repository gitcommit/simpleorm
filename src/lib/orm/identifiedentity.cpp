#include <orm/identifiedentity.hpp>

#include <sstream>

IdentifiedEntity::IdentifiedEntity(Session* s, const Integer& id)
: Entity(s) {
    setId(id);
}

IdentifiedEntity::IdentifiedEntity(Entity* p, const Integer& id)
: Entity(p) {
    setId(id);
}

IdentifiedEntity::~IdentifiedEntity() {
}

const bool IdentifiedEntity::hasId() const {
    return (0 < id());
}

const Integer IdentifiedEntity::id() const {
    return property("id").toInteger();
}

void IdentifiedEntity::setId(const Integer& id) {
    setProperty("id", id);
}

String IdentifiedEntity::toString() const {
    std::stringstream s;
    if (hasId()) {
        s << "Identified Entity [" << id() << "]";
    } else {
        s << "Identified Entity [No ID]";
    }
    return s.str();
}

String IdentifiedEntity::idInBrackets(const String& l, const String& r) const {
    std::stringstream ids;
    if (hasId()) {
        ids << id();
    } else {
        ids << "None";
    }
    return bracket(ids.str());
}

void IdentifiedEntity::persist() {
    if (hasId()) {
        update();
    } else {
        insert();
    }
}
