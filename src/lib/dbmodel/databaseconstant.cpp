#include <dbmodel/databaseconstant.hpp>

#include <dbmodel/database.hpp>
#include <dbmodel/componentvisitor.hpp>

DatabaseConstant::DatabaseConstant(Database* db, const String& name, DataType* t)
: InDatabaseComponent(db, name), _type(t) {
    db->add(this);
    setType(t);
}

DatabaseConstant::DatabaseConstant(const DatabaseConstant& o)
: InDatabaseComponent(o), _type(o._type) {
}

DatabaseConstant::~DatabaseConstant() {
}

void DatabaseConstant::setType(DataType* t) {
    _type = t;
}

bool DatabaseConstant::hasType() const {
    return (0 != type());
}

DataType* DatabaseConstant::type() const {
    return _type;
}

void DatabaseConstant::visit(ComponentVisitor* v) {
    v->perform(this);
}