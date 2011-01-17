#include <orm/mappedproperty.hpp>

#include <boost/assert.hpp>

#include <dbmodel/table.hpp>
#include <dbmodel/tablecolumn.hpp>
#include <orm/mapping.hpp>

MappedProperty::MappedProperty(Mapping* m, const String& propertyName, TableColumn* col)
: _mapping(0), _propertyName(propertyName), _column(col) {
    setMapping(m);
}

MappedProperty::MappedProperty(const MappedProperty& o)
: _mapping(o._mapping), _propertyName(o._propertyName), _column(o._column) {
}

MappedProperty::~MappedProperty() {
}

const bool MappedProperty::hasMapping() const {
    return (0 != mapping());
}

const bool MappedProperty::hasColumn() const {
    return (0 != column());
}

Mapping* MappedProperty::mapping() const {
    return _mapping;
}

TableColumn* MappedProperty::column() const {
    return _column;
}

String MappedProperty::propertyName() const {
    return _propertyName;
}

void MappedProperty::setMapping(Mapping* m) {
    BOOST_ASSERT(0 != m);
    _mapping = m;
    mapping()->add(this);
}