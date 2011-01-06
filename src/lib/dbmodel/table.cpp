#include <dbmodel/table.hpp>

#include <dbmodel/schema.hpp>
#include <dbmodel/componentvisitor.hpp>
#include <boost/assert.hpp>

Table::Table(Schema* s, const String& n)
: InSchemaComponent(s, n) {
    s->add(this);
}

Table::Table(const Table& o)
: InSchemaComponent(o), _columns(o._columns), _uniqueConstraints(o._uniqueConstraints) {
}

Table::~Table() {
}

void Table::visit(ComponentVisitor* v) {
    v->perform(this);
}

TableColumn* Table::createTableColumn(const String& name, DataType* t, const bool& createNotNullC) {
    TableColumn* c = new TableColumn(this, name, t);
    if (createNotNullC) {
        c->createNotNullConstraint();
    }
    return c;
}

TableColumn* Table::createTableColumn(const String& name, DataType* t, Sequence* s) {
    TableColumn* c = createTableColumn(name, t, true);
    c->createDefault(s);
    return c;
}

TableColumn* Table::createTableColumn(const String& name, DataType* t, const String& txt) {
    TableColumn* c = createTableColumn(name, t, true);
    c->createDefault(txt);
    return c;
}

TableColumn* Table::createTableColumn(const String& name, DataType* t, DatabaseConstant* cnst) {
    TableColumn* c = createTableColumn(name, t, true);
    c->createDefault(cnst);
    return c;
}

TableColumn* Table::createTableColumn(const String& name, DataType* t, const Numeric& n) {
    TableColumn* c = createTableColumn(name, t);
    c->createDefault(n);
    return c;
}

TableColumn* Table::createTableColumn(const String& name, TableColumn* ref, const String& conName, const bool& createNotNullConstraint) {
    TableColumn* c = createTableColumn(name, ref->type(), createNotNullConstraint);
    ForeignKeyConstraint* fk = createForeignKeyConstraint(ref->table(), conName);
    fk->add(c, ref);
    return c;
}

TableColumn* Table::add(TableColumn* c) {
    _columns.insert(std::make_pair(c->name(), c));
    schema()->add(c);
    return column(c->name());
}

TableColumn* Table::column(const String& n) const {
    TableColumnMapConstIterator i = _columns.find(n);
    BOOST_ASSERT(i != _columns.end());
    return i->second;
}

TableColumnMap Table::columns() const {
    return _columns;
}

UniqueConstraint* Table::createUniqueConstraint(const String& name) {
    return add(new UniqueConstraint(this, name));
}

UniqueConstraint* Table::add(UniqueConstraint* u) {
    BOOST_ASSERT(0 != u);
    _uniqueConstraints.insert(std::make_pair(u->name(), u));
    schema()->add(u);
    return uniqueConstraint(u->name());
}

UniqueConstraint* Table::uniqueConstraint(const String& n) const {
    UniqueConstraintMapConstIterator i = _uniqueConstraints.find(n);
    BOOST_ASSERT(i != _uniqueConstraints.end());
    return i->second;
}

UniqueConstraintMap Table::uniqueConstraints() const {
    return _uniqueConstraints;
}

PrimaryKeyConstraint* Table::createPrimaryKeyConstraint(const String& name) {
    BOOST_ASSERT(0 == _primaryKeyConstraint);
    _primaryKeyConstraint = new PrimaryKeyConstraint(this, name);
    schema()->add(_primaryKeyConstraint);
    return _primaryKeyConstraint;
}

bool Table::hasPrimaryKeyConstraint() const {
    return (0 != _primaryKeyConstraint);
}

PrimaryKeyConstraint* Table::primaryKeyConstraint() const {
    return _primaryKeyConstraint;
}

ForeignKeyConstraint* Table::createForeignKeyConstraint(Table* t, const String& name) {
    BOOST_ASSERT(0 != t);
    return add(new ForeignKeyConstraint(this, name, t));
}

ForeignKeyConstraint* Table::add(ForeignKeyConstraint* c) {
    BOOST_ASSERT(0 != c);
    _foreignKeyConstraints.insert(std::make_pair(c->name(), c));
    schema()->add(c);
    return foreignKeyConstraint(c->name());
}

ForeignKeyConstraint* Table::foreignKeyConstraint(const String& name) const {
    ForeignKeyConstraintMapConstIterator i = _foreignKeyConstraints.find(name);
    BOOST_ASSERT(i != _foreignKeyConstraints.end());
    return i->second;
}

ForeignKeyConstraintMap Table::foreignKeyConstraints() const {
    return _foreignKeyConstraints;
}

ColumnCheckConstraint* Table::add(ColumnCheckConstraint* c) {
    BOOST_ASSERT(0 != c);
    _columnCheckConstraints.insert(std::make_pair(c->name(), c));
    schema()->add(c);
    return columnCheckConstraint(c->name());
}

ColumnCheckConstraint* Table::columnCheckConstraint(const String& name) const {
    ColumnCheckConstraintMapConstIterator i = _columnCheckConstraints.find(name);
    BOOST_ASSERT(i != _columnCheckConstraints.end());
    return i->second;
}

ColumnCheckConstraintMap Table::columnCheckConstraints() const {
    return _columnCheckConstraints;
}