#include <dbmodel/tableconstraint.hpp>

#include <dbmodel/table.hpp>

#include <sstream>

TableConstraint::TableConstraint(Table* t, const String& n)
: SimpleTableConstraint(t, n) {
}

TableConstraint::TableConstraint(const TableConstraint& o)
: SimpleTableConstraint(o), _cols(o._cols) {
}

TableConstraint::~TableConstraint() {
}

TableColumn* TableConstraint::add(TableColumn* c) {
    _cols.push_back(c);
    return c;
}

std::vector<TableColumn*> TableConstraint::columns() const {
    return _cols;
}

StringVector TableConstraint::columnNames() const {
    StringVector ret;
    for (std::vector<TableColumn*>::const_iterator i = _cols.begin(); i != _cols.end(); ++i) {
        ret.push_back((*i)->name());
    }
    return ret;
}

String TableConstraint::joinedColumnNames(const String& sep) const {
    std::stringstream s;
    StringVector v = columnNames();
    for (StringVector::const_iterator i = v.begin(); i != v.end(); ++i) {
        if (i != v.begin()) {
            s << sep;
        }
        s << (*i);
    }
    return s.str();
}

TableColumn* TableConstraint::add(const String& colName) {
    return add(table()->column(colName));
}