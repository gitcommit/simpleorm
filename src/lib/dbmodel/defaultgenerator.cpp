#include <dbmodel/defaultgenerator.hpp>

#include <dbmodel/componentvisitor.hpp>
#include <dbmodel/tablecolumn.hpp>

DefaultGenerator::DefaultGenerator(TableColumn* c)
: InTableColumnComponent(c, c->name() + "_default_value") {
}

DefaultGenerator::DefaultGenerator(const DefaultGenerator& o)
: InTableColumnComponent(o) {
}

DefaultGenerator::~DefaultGenerator() {
}

void DefaultGenerator::visit(ComponentVisitor* v) {
    v->perform(this);
}