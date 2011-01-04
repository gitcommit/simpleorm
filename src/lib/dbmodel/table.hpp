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

class Table: public InSchemaComponent {
public:
    Table(Schema* s, const String& n);
    Table(const Table& o);
    virtual ~Table();

    void visit(ComponentVisitor* v);

    TableColumn* createTableColumn(const String& name, DataType* t);
    TableColumn* add(TableColumn* c);
    TableColumn* column(const String& n) const;
    TableColumnMap columns() const;
    
private:
    TableColumnMap _columns;
};

typedef std::map<String, Table*> TableMap;
typedef TableMap::const_iterator TableMapConstIterator;

#endif	/* TABLE_HPP */

