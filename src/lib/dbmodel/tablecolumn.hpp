/* 
 * File:   tablecolumn.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 15:11
 */

#ifndef TABLECOLUMN_HPP
#define	TABLECOLUMN_HPP

#include <dbmodel/intablecomponent.hpp>

#include <vector>

#include <dbmodel/columncheckconstraint.hpp>

class DataType;
class DatabaseConstant;
class Sequence;
class DefaultGenerator;
class NotNullConstraint;

class TableColumn: public InTableComponent {
public:
    TableColumn(Table* table, const String& name, DataType* t);
    TableColumn(const TableColumn& o);
    virtual ~TableColumn();

    DataType* type() const;
    void setType(DataType* t);
    bool hasType() const;

    DefaultGenerator* createDefault(DatabaseConstant* c);
    DefaultGenerator* createDefault(Sequence* s);
    DefaultGenerator* createDefault(const Numeric& v);
    DefaultGenerator* createDefault(const String& s);
    
    virtual bool hasDefault() const;
    DefaultGenerator* defaultGenerator() const;

    virtual bool hasNotNullConstraint() const;
    NotNullConstraint* notNullConstraint() const;
    virtual NotNullConstraint* createNotNullConstraint();

    ColumnCheckConstraint* createCheckConstraint(const String& code, const String& name);
    ColumnCheckConstraint* add(ColumnCheckConstraint* c);
    ColumnCheckConstraint* checkConstraint(const String& n) const;
    ColumnCheckConstraintMap checkConstraints() const;

    virtual void visit(ComponentVisitor* v);
private:
    DataType* _type;
    DefaultGenerator* _defaultGenerator;
    NotNullConstraint* _notNullConstraint;
    ColumnCheckConstraintMap _checkConstraints;
};

typedef std::map<String, TableColumn*> TableColumnMap;
typedef TableColumnMap::const_iterator TableColumnMapConstIterator;
typedef std::pair<TableColumn*, TableColumn*> TableColumnPair;
typedef std::vector<TableColumnPair> TableColumnPairVector;
typedef TableColumnPairVector::const_iterator TableColumnPairVectorConstIterator;

#endif	/* TABLECOLUMN_HPP */

