#include <orm/mapping.hpp>

Mapping::Mapping(Table* t)
: _table(0) {
    setTable(t);
}

Mapping::Mapping(const Mapping& o) {
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