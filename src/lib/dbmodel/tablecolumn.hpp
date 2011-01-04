/* 
 * File:   tablecolumn.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 15:11
 */

#ifndef TABLECOLUMN_HPP
#define	TABLECOLUMN_HPP

#include <dbmodel/intablecomponent.hpp>

class DataType;
class DatabaseConstant;
class Sequence;
class DefaultGenerator;

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
    
    virtual void visit(ComponentVisitor* v);
private:
    DataType* _type;
    DefaultGenerator* _defaultGenerator;

};

typedef std::map<String, TableColumn*> TableColumnMap;
typedef TableColumnMap::const_iterator TableColumnMapConstIterator;

#endif	/* TABLECOLUMN_HPP */

