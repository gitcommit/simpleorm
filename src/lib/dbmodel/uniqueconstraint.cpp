#include <dbmodel/uniqueconstraint.hpp>

#include <dbmodel/componentvisitor.hpp>
#include <dbmodel/table.hpp>

UniqueConstraint::UniqueConstraint(Table* t, const String& name)
: TableConstraint(t, name) {
    t->add(this);
}

UniqueConstraint::UniqueConstraint(const UniqueConstraint& o)
: TableConstraint(o) {
}

UniqueConstraint::~UniqueConstraint() {
}

void UniqueConstraint::visit(ComponentVisitor* v) {
    v->perform(this);
}