#include <dbmodel/sequencedefaultgenerator.hpp>

#include <dbmodel/sequence.hpp>
#include <dbmodel/tablecolumn.hpp>

SequenceDefaultGenerator::SequenceDefaultGenerator(TableColumn* col, Sequence* s)
: DefaultGenerator(col), _s(s) {
}

SequenceDefaultGenerator::SequenceDefaultGenerator(const SequenceDefaultGenerator& o)
: DefaultGenerator(o), _s(o._s) {
}

SequenceDefaultGenerator::~SequenceDefaultGenerator() {
}

String SequenceDefaultGenerator::value() const {
    return "NEXTVAL('" + _s->qualifiedName() + "')";
}
