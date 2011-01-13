#include <lib/core/siprefix.hpp>

#include <sstream>

#include <boost/assert.hpp>

#include <orm/mapping.hpp>

#include <fgeosession.hpp>


SiPrefix::SiPrefix(Session* s, const String& name, const String& code, const String& symbol, const Numeric& factor, const String& description, const Integer& id)
        : StandardEntity(s, id, name, code, description) {
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
    setProperty("symbol", s);
}

void SiPrefix::setFactor(const Numeric& f) {
    setProperty("factor", f);
}

String SiPrefix::symbol() const {
    return property("symbol").toString();
}

Numeric SiPrefix::factor() const {
    return property("factor").toNumeric();
}

String SiPrefix::toString() const {
    std::stringstream s;
    s << name() << bracket(symbol(), "[", "]") << ": " << factor();
    return s.str();
}

Mapping* SiPrefix::mapping() const {
    BOOST_ASSERT(hasSession());
    return dynamic_cast<FGeoSession*>(session())->mapping(this);
}
