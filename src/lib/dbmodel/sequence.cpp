#include <dbmodel/sequence.hpp>

#include <dbmodel/schema.hpp>
#include <dbmodel/componentvisitor.hpp>

Sequence::Sequence(Schema* s, const String& n)
: InSchemaComponent(s, n) {
}

Sequence::Sequence(const Sequence& o)
: InSchemaComponent(o) {
}

Sequence::~Sequence() {
}

void Sequence::visit(ComponentVisitor* v) {
    v->perform(this);
}