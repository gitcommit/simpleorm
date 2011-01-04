#include <dbmodel/textdefaultgenerator.hpp>

#include <dbmodel/tablecolumn.hpp>

TextDefaultGenerator::TextDefaultGenerator(TableColumn* c, const String& s)
: DefaultGenerator(c), _str(s) {
}

TextDefaultGenerator::TextDefaultGenerator(const TextDefaultGenerator& o)
: DefaultGenerator(o), _str(o._str) {
}

TextDefaultGenerator::~TextDefaultGenerator() {
}

String TextDefaultGenerator::value() const {
    return "'" + _str + "'";
}