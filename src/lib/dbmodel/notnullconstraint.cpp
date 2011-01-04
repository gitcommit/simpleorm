#include <dbmodel/notnullconstraint.hpp>

#include <dbmodel/tablecolumn.hpp>
#include <dbmodel/componentvisitor.hpp>

NotNullConstraint::NotNullConstraint(TableColumn* c)
: ColumnConstraint(c, c->name() + "_not_null") {
}

NotNullConstraint::NotNullConstraint(const NotNullConstraint& o)
: ColumnConstraint(o) {
}

NotNullConstraint::~NotNullConstraint() {
}

void NotNullConstraint::visit(ComponentVisitor* v) {
    v->perform(this);
}