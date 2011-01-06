/* 
 * File:   table.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 10:47
 */

#ifndef TABLE_HPP
#define	TABLE_HPP

#include <dbmodel/inschemacomponent.hpp>

#include <dbmodel/tablecolumn.hpp>
#include <dbmodel/uniqueconstraint.hpp>
#include <dbmodel/primarykeyconstraint.hpp>
#include <dbmodel/foreignkeyconstraint.hpp>

class Table: public InSchemaComponent {
public:
    Table(Schema* s, const String& n);
    Table(const Table& o);
    virtual ~Table();

    void visit(ComponentVisitor* v);

    TableColumn* createTableColumn(const String& name, DataType* t, const bool& createNotNullConstraint=false);
    TableColumn* createTableColumn(const String& name, DataType* t, DatabaseConstant* c);
    TableColumn* createTableColumn(const String& name, DataType* t, const String& txt);
    TableColumn* createTableColumn(const String& name, DataType* t, const Numeric& n);
    TableColumn* createTableColumn(const String& name, DataType* t, Sequence* s);
    TableColumn* createTableColumn(const String& name, TableColumn* ref, 
        const String& conName, const bool& createNotNullConstraint=true);
    TableColumn* add(TableColumn* c);
    TableColumn* column(const String& n) const;
    TableColumnMap columns() const;

    UniqueConstraint* createUniqueConstraint(const String& name);
    UniqueConstraint* add(UniqueConstraint* u);
    UniqueConstraint* uniqueConstraint(const String& n) const;
    UniqueConstraintMap uniqueConstraints() const;

    PrimaryKeyConstraint* createPrimaryKeyConstraint(const String& name);
    bool hasPrimaryKeyConstraint() const;
    PrimaryKeyConstraint* primaryKeyConstraint() const;

    ForeignKeyConstraint* createForeignKeyConstraint(Table* t, const String& name);
    ForeignKeyConstraint* add(ForeignKeyConstraint* c);
    ForeignKeyConstraint* foreignKeyConstraint(const String& name) const;
    ForeignKeyConstraintMap foreignKeyConstraints() const;

    ColumnCheckConstraint* add(ColumnCheckConstraint* c);
    ColumnCheckConstraint* columnCheckConstraint(const String& name) const;
    ColumnCheckConstraintMap columnCheckConstraints() const;

private:
    TableColumnMap _columns;
    UniqueConstraintMap _uniqueConstraints;
    PrimaryKeyConstraint* _primaryKeyConstraint;
    ForeignKeyConstraintMap _foreignKeyConstraints;
    ColumnCheckConstraintMap _columnCheckConstraints;
};

typedef std::map<String, Table*> TableMap;
typedef TableMap::const_iterator TableMapConstIterator;

#endif	/* TABLE_HPP */

