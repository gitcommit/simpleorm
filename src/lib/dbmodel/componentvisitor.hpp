/* 
 * File:   componentvisitor.hpp
 * Author: jolo
 *
 * Created on 29. Dezember 2010, 20:22
 */

#ifndef COMPONENTVISITOR_HPP
#define	COMPONENTVISITOR_HPP

class TableColumn;
class Component;
class Database;
class DataType;
class Schema;
class Sequence;
class Table;
class DatabaseConstant;
class DefaultGenerator;
class TableColumn;
class NotNullConstraint;
class UniqueConstraint;
class PrimaryKeyConstraint;
class ColumnCheckConstraint;
class ForeignKeyConstraint;

class ComponentVisitor {
public:
    ComponentVisitor();
    ComponentVisitor(const ComponentVisitor& o);
    virtual ~ComponentVisitor();

    virtual void perform(Database* db) = 0;
    virtual void perform(DataType* t) = 0;
    virtual void perform(Schema* s) = 0;
    virtual void perform(Sequence* s) = 0;
    virtual void perform(Table* t) = 0;
    virtual void perform(DatabaseConstant* c) = 0;
    virtual void perform(DefaultGenerator* g) = 0;
    virtual void perform(TableColumn* c) = 0;
    virtual void perform(NotNullConstraint* c) = 0;
    virtual void perform(UniqueConstraint* c) = 0;
    virtual void perform(PrimaryKeyConstraint* c) = 0;
    virtual void perform(ColumnCheckConstraint* c) = 0;
    virtual void perform(ForeignKeyConstraint* c) = 0;
};

#endif	/* COMPONENTVISITOR_HPP */

