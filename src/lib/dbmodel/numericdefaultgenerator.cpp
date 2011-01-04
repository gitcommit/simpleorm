#include <dbmodel/numericdefaultgenerator.hpp>

#include <dbmodel/tablecolumn.hpp>

#include <sstream>

NumericDefaultGenerator::NumericDefaultGenerator(TableColumn* c, const Numeric& n)
: DefaultGenerator(c), _n(n) {
}

NumericDefaultGenerator::NumericDefaultGenerator(const NumericDefaultGenerator& o)
: DefaultGenerator(o), _n(o._n) {
}

NumericDefaultGenerator::~NumericDefaultGenerator() {
}

String NumericDefaultGenerator::value() const {
    std::stringstream s;
    s << _n;
    return s.str();
}