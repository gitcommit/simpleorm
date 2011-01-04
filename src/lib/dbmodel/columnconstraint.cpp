#include <dbmodel/columnconstraint.hpp>

#include <dbmodel/tablecolumn.hpp>

ColumnConstraint::ColumnConstraint(TableColumn* c, const String& n)
: InTableColumnComponent(c, n) {
}

ColumnConstraint::ColumnConstraint(const ColumnConstraint& other)
: InTableColumnComponent(other) {
}

ColumnConstraint::~ColumnConstraint() {
}