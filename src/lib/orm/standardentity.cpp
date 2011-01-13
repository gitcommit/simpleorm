#include <orm/standardentity.hpp>

#include <sstream>

StandardEntity::StandardEntity(Session* s, const Integer& id, const String& name, const String& code, const String& description)
        : NamedEntity(s, id, name) {
    setCode(code);
    setDescription(description);
}

StandardEntity::StandardEntity(StandardEntity* p, const Integer& id, const String& name, const String& code, const String& description)
        : NamedEntity(p, id, name) {
    setCode(code);
    setDescription(description);
}

StandardEntity::~StandardEntity() {}

const bool StandardEntity::hasCode() const {
    return isNotEmpty(code());
}

const bool StandardEntity::hasDescription() const {
    return isNotEmpty(description());
}

void StandardEntity::setCode(const String& code) {
    setProperty("code", code);
}

void StandardEntity::setDescription(const String& description) {
    setProperty("description", description);
}

String StandardEntity::code() const {
    return property("code").toString();
}

String StandardEntity::description() const {
    return property("description").toString();
}

String StandardEntity::toString() const {
    std::stringstream s;
    s << name() << " " << idInBrackets() << " " << codeInBrackets();
    return s.str();
}

String StandardEntity::codeInBrackets(const String& left, const String& right) const {
    return bracket(code(), left, right);
}