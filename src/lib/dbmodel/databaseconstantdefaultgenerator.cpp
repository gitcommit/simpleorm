#include <dbmodel/databaseconstantdefaultgenerator.hpp>

#include <dbmodel/tablecolumn.hpp>
#include <boost/assert.hpp>

#include <iostream>

DatabaseConstantDefaultGenerator::DatabaseConstantDefaultGenerator(TableColumn* col, DatabaseConstant* c)
: DefaultGenerator(col), _c(c) {
    std::cout << std::endl << "constant: " << col->name() << ": " << _c->name() << std::endl;
}

DatabaseConstantDefaultGenerator::DatabaseConstantDefaultGenerator(const DatabaseConstantDefaultGenerator& o)
: DefaultGenerator(o), _c(o._c) {
}

DatabaseConstantDefaultGenerator::~DatabaseConstantDefaultGenerator() {

}

String DatabaseConstantDefaultGenerator::value() const {
    return _c->name();
}