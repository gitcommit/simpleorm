#include <dbmodel/simpletableconstraint.hpp>

#include <dbmodel/table.hpp>

SimpleTableConstraint::SimpleTableConstraint(Table* t, const String& n)
: InTableComponent(t, n) {
}

SimpleTableConstraint::SimpleTableConstraint(const SimpleTableConstraint& o)
: InTableComponent(o) {
}

SimpleTableConstraint::~SimpleTableConstraint() {
}
