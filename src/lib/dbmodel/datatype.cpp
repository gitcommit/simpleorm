#include <dbmodel/datatype.hpp>

#include <dbmodel/database.hpp>
#include <dbmodel/componentvisitor.hpp>

DataType::DataType(Database* db, const String& name, const String& sqlName)
: InDatabaseComponent(db, name), _sqlName(sqlName) {
    setSqlName(sqlName);
    db->add(this);
}

DataType::DataType(const DataType& orig)
: InDatabaseComponent(orig), _sqlName(orig._sqlName)
{
}

DataType::~DataType() {
}

Database* DataType::database() const {
    return dynamic_cast<Database*>(parent());
}

void DataType::setSqlName(const String& n) {
    _sqlName = n;
}

String DataType::sqlName() const {
    return _sqlName;
}

void DataType::visit(ComponentVisitor* v) {
    v->perform(this);
}