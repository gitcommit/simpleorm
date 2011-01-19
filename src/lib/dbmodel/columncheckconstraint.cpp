#include <dbmodel/columncheckconstraint.hpp>

#include <dbmodel/componentvisitor.hpp>
#include <dbmodel/table.hpp>

ColumnCheckConstraint::ColumnCheckConstraint(TableColumn* c, const String& name, const String& code)
: ColumnConstraint(c, name), _code(code) {
    c->add(this);
}

ColumnCheckConstraint::ColumnCheckConstraint(const ColumnCheckConstraint& o)
: ColumnConstraint(o), _code(o._code) {
}

ColumnCheckConstraint::~ColumnCheckConstraint() {
}

void ColumnCheckConstraint::setCode(const String& c) {
    _code = c;
}

String ColumnCheckConstraint::code() const {
    return _code;
}

void ColumnCheckConstraint::visit(ComponentVisitor* v) {
    v->perform(this);
}