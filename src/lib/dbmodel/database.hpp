/* 
 * File:   database.hpp
 * Author: jolo
 *
 * Created on 29. Dezember 2010, 20:37
 */

#ifndef DATABASE_HPP
#define	DATABASE_HPP

#include <dbmodel/component.hpp>
#include <dbmodel/datatype.hpp>
#include <dbmodel/databaseconstant.hpp>
#include <dbmodel/schema.hpp>
#include <dbmodel/sequence.hpp>
#include <dbmodel/table.hpp>
#include <dbmodel/tablecolumn.hpp>
#include <dbmodel/uniqueconstraint.hpp>
#include <dbmodel/primarykeyconstraint.hpp>

class PrimaryKeyConstraint;
typedef std::map<String, PrimaryKeyConstraint*> PrimaryKeyConstraintMap;

class Database : public Component {
public:
    Database(const String& name);
    Database(const Database& orig);
    virtual ~Database();

    virtual DataType* add(DataType* t);
    DataType* dataType(const String& name);
    DataType* createDataType(const String& name, const String& sqlName);
    DataTypeMap dataTypes() const;

    virtual DatabaseConstant* add(DatabaseConstant* c);
    DatabaseConstant* databaseConstant(const String& name) const;
    DatabaseConstant* createDatabaseConstant(const String& name, DataType* t);
    DatabaseConstantMap databaseConstants() const;

    virtual Schema* add(Schema* s);
    Schema* schema(const String& name) const;
    Schema* createSchema(const String& name);
    SchemaMap schemata() const;

    virtual Sequence* add(Sequence* s);
    virtual Sequence* sequence(const String& qualifiedName) const;
    SequenceMap sequences() const;

    virtual Table* add(Table* t);
    virtual Table* table(const String& name) const;
    TableMap tables() const;

    virtual TableColumn* add(TableColumn* c);
    virtual TableColumn* tableColumn(const String& namePath) const;
    TableColumnMap tableColumns() const;

    virtual UniqueConstraint* add(UniqueConstraint* c);
    virtual UniqueConstraint* uniqueConstraint(const String& namePath) const;
    UniqueConstraintMap uniqueConstraints() const;

    virtual PrimaryKeyConstraint* add(PrimaryKeyConstraint* c);
    virtual PrimaryKeyConstraint* primaryKeyConstraint(const String& namePath) const;
    PrimaryKeyConstraintMap primaryKeyConstraints() const;

    virtual void visit(ComponentVisitor* v);
private:
    DataTypeMap _dataTypes;
    SchemaMap _schemata;
    SequenceMap _sequences;
    TableMap _tables;
    DatabaseConstantMap _databaseConstants;
    TableColumnMap _tableColumns;
    UniqueConstraintMap _uniqueConstraints;
    PrimaryKeyConstraintMap _primaryKeyConstraints;
};

#endif	/* DATABASE_HPP */

