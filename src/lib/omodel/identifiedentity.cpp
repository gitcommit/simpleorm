#include <omodel/identifiedentity.hpp>

#include <sstream>

IdentifiedEntity::IdentifiedEntity(Session* s, const Integer& id)
: Entity(s), _id(id) {
    setId(id);
}

IdentifiedEntity::IdentifiedEntity(Entity* p, const Integer& id)
: Entity(p), _id(id) {
    setId(id);
}

IdentifiedEntity::~IdentifiedEntity() {
}

const bool IdentifiedEntity::hasId() const {
    return (0 < id());
}

const Integer IdentifiedEntity::id() const {
    return _id;
}

void IdentifiedEntity::setId(const Integer& id) {
    _id = id;
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
    std::stringstream ss;
    ss << l;
    if (hasId()) {
        ss << id();
    } else {
        ss << "None";
    }
    ss << r;
    return ss.str();
}