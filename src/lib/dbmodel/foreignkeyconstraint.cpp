#include <dbmodel/foreignkeyconstraint.hpp>

#include <dbmodel/table.hpp>
#include <dbmodel/componentvisitor.hpp>
#include <boost/assert.hpp>

#include <sstream>

ForeignKeyConstraint::ForeignKeyConstraint(Table* t, const String& name, Table* referencedT)
: SimpleTableConstraint(t, name), _referencedTable(referencedT) {
}

ForeignKeyConstraint::ForeignKeyConstraint(const ForeignKeyConstraint& o)
: SimpleTableConstraint(o), _referencedTable(o._referencedTable), _columnPairs(o._columnPairs) {
}

ForeignKeyConstraint::~ForeignKeyConstraint() {
}

void ForeignKeyConstraint::visit(ComponentVisitor* v) {
    v->perform(this);
}

Table* ForeignKeyConstraint::referencedTable() const {
    return _referencedTable;
}

TableColumnPair ForeignKeyConstraint::add(TableColumn* local, TableColumn* referenced) {
    BOOST_ASSERT(0 != local);
    BOOST_ASSERT(0 != referenced);
    BOOST_ASSERT(local->table() == table());
    _columnPairs.push_back(std::make_pair(local, referenced));
    return std::make_pair(local, referenced);
}

TableColumnMap ForeignKeyConstraint::localColumns() const {
    TableColumnMap ret;
    for (TableColumnPairVectorConstIterator i = _columnPairs.begin(); i != _columnPairs.end(); ++i) {
        ret.insert(std::make_pair(i->first->pathString(), i->first));
    }
    return ret;
}

TableColumnMap ForeignKeyConstraint::referencedColumns() const {
    TableColumnMap ret;
    for (TableColumnPairVectorConstIterator i = _columnPairs.begin(); i != _columnPairs.end(); ++i) {
        ret.insert(std::make_pair(i->second->pathString(), i->second));
    }
    return ret;
}

StringVector ForeignKeyConstraint::localColumnNames() const {
    StringVector ret;
    TableColumnMap m = localColumns();
    for (TableColumnMapConstIterator i = m.begin(); i != m.end(); ++i) {
        ret.push_back(i->second->name());
    }
    return ret;
}

StringVector ForeignKeyConstraint::referencedColumnNames() const {
    StringVector ret;
    TableColumnMap m = referencedColumns();
    for (TableColumnMapConstIterator i = m.begin(); i != m.end(); ++i) {
        ret.push_back(i->second->name());
    }
    return ret;
}

String ForeignKeyConstraint::joinedReferencedColumnNames(const String& sep) const {
    StringVector v = referencedColumnNames();
    std::stringstream ss;
    for (StringVectorConstIterator i = v.begin(); i != v.end(); ++i) {
        if (i != v.begin()) {
            ss << sep;
        }
        ss << (*i);
    }
    return ss.str();
}

String ForeignKeyConstraint::joinedLocalColumnNames(const String& sep) const {
    StringVector v = localColumnNames();
    std::stringstream ss;
    for (StringVectorConstIterator i = v.begin(); i != v.end(); ++i) {
        if (i != v.begin()) {
            ss << sep;
        }
        ss << (*i);
    }
    return ss.str();
}