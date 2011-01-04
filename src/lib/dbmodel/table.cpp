#include <dbmodel/table.hpp>

#include <dbmodel/schema.hpp>
#include <dbmodel/componentvisitor.hpp>
#include <boost/assert.hpp>

Table::Table(Schema* s, const String& n)
: InSchemaComponent(s, n) {
    s->add(this);
}

Table::Table(const Table& o)
: InSchemaComponent(o) {
}

Table::~Table() {
}

void Table::visit(ComponentVisitor* v) {
    v->perform(this);
}

TableColumn* Table::createTableColumn(const String& name, DataType* t) {
    return add(new TableColumn(this, name, t));
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