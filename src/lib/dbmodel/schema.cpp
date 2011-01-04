#include <dbmodel/schema.hpp>

#include <dbmodel/indatabasecomponent.hpp>
#include <dbmodel/database.hpp>
#include <dbmodel/schema.hpp>
#include <dbmodel/componentvisitor.hpp>

#include <boost/assert.hpp>

Schema::Schema(Database* db, const String& name)
: InDatabaseComponent(db, name) {
    db->add(this);
}

Schema::Schema(const Schema& o)
: InDatabaseComponent(o) {
}

Schema::~Schema() {
}

void Schema::visit(ComponentVisitor* v) {
    v->perform(this);
}

Sequence* Schema::createSequence(const String& name) {
    return add(new Sequence(this, name));
}

Sequence* Schema::add(Sequence* s) {
    _sequences.insert(std::make_pair(s->qualifiedName(), s));
    database()->add(s);
    return sequence(s->qualifiedName());
}

Sequence* Schema::sequence(const String& name) const {
    SequenceMapConstIterator i = _sequences.begin();
    BOOST_ASSERT(_sequences.end() != i);
    return i->second;
}

SequenceMap Schema::sequences() const {
    return _sequences;
}

Table* Schema::createTable(const String& n) {
    return add(new Table(this, n));
}

Table* Schema::add(Table* t) {
    _tables.insert(std::make_pair(t->name(), t));
    database()->add(t);
    return table(t->name());
}

Table* Schema::table(const String& n) const {
    TableMapConstIterator i = _tables.find(n);
    BOOST_ASSERT(i != _tables.end());
    return i->second;
}

TableMap Schema::tables() const {
    return _tables;
}

TableColumn* Schema::add(TableColumn* c) {
    _tableColumns.insert(std::make_pair(c->qualifiedName(), c));
    database()->add(c);
    return tableColumn(c->qualifiedName());
}

TableColumn* Schema::tableColumn(const String& qualifiedName) {
    TableColumnMapConstIterator i = _tableColumns.find(qualifiedName);
    BOOST_ASSERT(i != _tableColumns.end());
    return i->second;
}

TableColumnMap Schema::tableColumns() const {
    return _tableColumns;
}