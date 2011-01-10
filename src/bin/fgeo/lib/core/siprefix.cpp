#include <lib/core/siprefix.hpp>

#include <sstream>

#include <orm/mapping.hpp>

SiPrefix::SiPrefix(Session* s, const String& name, const String& code, const String& symbol, const Numeric& factor, const String& description, const Integer& id)
        : StandardEntity(s, id, name, code, description), _symbol(symbol), _factor(factor) {
    setSymbol(symbol);
    setFactor(factor);
}

SiPrefix::~SiPrefix() {}

const bool SiPrefix::hasSymbol() const {
    return isNotEmpty(symbol());
}

const bool SiPrefix::hasFactor() const {
    return (0 != factor());
}

void SiPrefix::setSymbol(const String& s) {
    _symbol = s;
}

void SiPrefix::setFactor(const Numeric& f) {
    _factor = f;
}

String SiPrefix::symbol() const {
    return _symbol;
}

Numeric SiPrefix::factor() const {
    return _factor;
}

String SiPrefix::toString() const {
    std::stringstream s;
    s << name() << bracket(symbol(), "[", "]") << ": " << factor();
    return s.str();
}

Mapping* SiPrefix::createMapping() {
    return new Mapping(0);
}