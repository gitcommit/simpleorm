#include <dbmodel/primarykeyconstraint.hpp>

#include <dbmodel/table.hpp>
#include <dbmodel/componentvisitor.hpp>

PrimaryKeyConstraint::PrimaryKeyConstraint(Table* t, const String& n)
: TableConstraint(t, n) {
}

PrimaryKeyConstraint::PrimaryKeyConstraint(const PrimaryKeyConstraint& o)
: TableConstraint(o) {
}

PrimaryKeyConstraint::~PrimaryKeyConstraint() {
}

void PrimaryKeyConstraint::visit(ComponentVisitor* v) {
    v->perform(this);
}