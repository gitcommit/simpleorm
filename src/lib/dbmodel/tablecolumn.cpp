#include <dbmodel/tablecolumn.hpp>

#include <dbmodel/table.hpp>
#include <dbmodel/componentvisitor.hpp>
#include <dbmodel/databaseconstant.hpp>
#include <dbmodel/sequencedefaultgenerator.hpp>
#include <dbmodel/databaseconstantdefaultgenerator.hpp>
#include <dbmodel/numericdefaultgenerator.hpp>
#include <dbmodel/textdefaultgenerator.hpp>

#include <boost/assert.hpp>

#include <iostream>

TableColumn::TableColumn(Table* tbl, const String& name, DataType* t)
: InTableComponent(tbl, name), _type(t), _defaultGenerator(0) {
    tbl->add(this);
}

TableColumn::TableColumn(const TableColumn& o)
: InTableComponent(o), _type(o._type), _defaultGenerator(o._defaultGenerator) {
}

TableColumn::~TableColumn() {
}

void TableColumn::setType(DataType* t) {
    _type = t;
}

DataType* TableColumn::type() const {
    return _type;
}

bool TableColumn::hasType() const {
    return (0 != type());
}

void TableColumn::visit(ComponentVisitor* v) {
    v->perform(this);
}

DefaultGenerator* TableColumn::createDefault(DatabaseConstant* c) {
    BOOST_ASSERT(0 == _defaultGenerator);
    _defaultGenerator = new DatabaseConstantDefaultGenerator(this, c);
    std::cout << _defaultGenerator->name();
    return defaultGenerator();
}

DefaultGenerator* TableColumn::createDefault(Sequence* s) {
    BOOST_ASSERT(0 == _defaultGenerator);
    _defaultGenerator = new SequenceDefaultGenerator(this, s);
    return defaultGenerator();
}

DefaultGenerator* TableColumn::createDefault(const Numeric& v) {
    BOOST_ASSERT(0 == _defaultGenerator);
    _defaultGenerator = new NumericDefaultGenerator(this, v);
    return defaultGenerator();
}

DefaultGenerator* TableColumn::createDefault(const String& s) {
    BOOST_ASSERT(0 == _defaultGenerator);
    _defaultGenerator = new TextDefaultGenerator(this, s);
    return defaultGenerator();
}

DefaultGenerator* TableColumn::defaultGenerator() const {
    return _defaultGenerator;
}

bool TableColumn::hasDefault() const {
    return (0 != defaultGenerator());
}