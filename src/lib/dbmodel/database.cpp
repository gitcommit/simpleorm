#include <dbmodel/database.hpp>
#include <dbmodel/componentvisitor.hpp>

#include <boost/assert.hpp>

Database::Database(const String& name)
: Component(name) {
}

Database::Database(const Database& orig)
: Component(orig), _dataTypes(orig._dataTypes) {
}

Database::~Database() {
}

DataType* Database::add(DataType* t) {
    _dataTypes.insert(std::make_pair(t->name(), t));
    return dataType(t->name());
}

DataType* Database::dataType(const String& name) {
    DataTypeMapConstIterator i = _dataTypes.find(name);
    BOOST_ASSERT(_dataTypes.end() != i);
    return i->second;
}

DataType* Database::createDataType(const String& name, const String& sqlName) {
    return add(new DataType(this, name, sqlName));
}

DataTypeMap Database::dataTypes() const {
    return _dataTypes;
}

void Database::visit(ComponentVisitor* v) {
    v->perform(this);
}

Schema* Database::createSchema(const String& name) {
    return add(new Schema(this, name));
}

Schema* Database::schema(const String& name) const {
    SchemaMapConstIterator i = _schemata.find(name);
    BOOST_ASSERT(_schemata.end() != i);
    return i->second;
}

Schema* Database::add(Schema* s) {
    _schemata.insert(std::make_pair(s->name(), s));
    return schema(s->name());
}

SchemaMap Database::schemata() const {
    return _schemata;
}

Sequence* Database::add(Sequence* s) {
    _sequences.insert(std::make_pair(s->qualifiedName(), s));
    return sequence(s->qualifiedName());
}

Sequence* Database::sequence(const String& qualifiedName) const {
    SequenceMapConstIterator i = _sequences.find(qualifiedName);
    BOOST_ASSERT(_sequences.end() != i);
    return i->second;
}

SequenceMap Database::sequences() const {
    return _sequences;
}

Table* Database::add(Table* t) {
    _tables.insert(std::make_pair(t->qualifiedName(), t));
    return table(t->qualifiedName());
}

Table* Database::table(const String& qn) const {
    TableMapConstIterator i = _tables.find(qn);
    BOOST_ASSERT(i != _tables.end());
    return i->second;
}

TableMap Database::tables() const {
    return _tables;
}

DatabaseConstant* Database::createDatabaseConstant(const String& name, DataType* t) {
    return add(new DatabaseConstant(this, name, t));
}

DatabaseConstant* Database::add(DatabaseConstant* c) {
    _databaseConstants.insert(std::make_pair(c->name(), c));
    return databaseConstant(c->name());
}

DatabaseConstant* Database::databaseConstant(const String& name) const {
    DatabaseConstantMapConstIterator i = _databaseConstants.find(name);
    BOOST_ASSERT(i != _databaseConstants.end());
    return i->second;
}

DatabaseConstantMap Database::databaseConstants() const {
    return _databaseConstants;
}

TableColumn* Database::add(TableColumn* c) {
    BOOST_ASSERT(0 != c);
    _tableColumns.insert(std::make_pair(c->pathString(), c));
    return tableColumn(c->pathString());
}

TableColumn* Database::tableColumn(const String& namePath) const {
    TableColumnMapConstIterator i = _tableColumns.find(namePath);
    BOOST_ASSERT(i != _tableColumns.end());
    return i->second;
}

TableColumnMap Database::tableColumns() const {
    return _tableColumns;
}

UniqueConstraint* Database::add(UniqueConstraint* u) {
    BOOST_ASSERT(0 != u);
    _uniqueConstraints.insert(std::make_pair(u->pathString(), u));
    return uniqueConstraint(u->pathString());
}

UniqueConstraint* Database::uniqueConstraint(const String& namePath) const {
    UniqueConstraintMapConstIterator i = _uniqueConstraints.find(namePath);
    BOOST_ASSERT(i != _uniqueConstraints.end());
    return i->second;
}

UniqueConstraintMap Database::uniqueConstraints() const {
    return _uniqueConstraints;
}

PrimaryKeyConstraint* Database::add(PrimaryKeyConstraint* c) {
    BOOST_ASSERT(0 != c);
    _primaryKeyConstraints.insert(std::make_pair(c->pathString(), c));
    return primaryKeyConstraint(c->pathString());
}

PrimaryKeyConstraint* Database::primaryKeyConstraint(const String& namePath) const {
    PrimaryKeyConstraintMapConstIterator i = _primaryKeyConstraints.find(namePath);
    BOOST_ASSERT(i != _primaryKeyConstraints.end());
    return i->second;
}

PrimaryKeyConstraintMap Database::primaryKeyConstraints() const {
    return _primaryKeyConstraints;
}