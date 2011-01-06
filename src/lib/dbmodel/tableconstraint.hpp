/* 
 * File:   tableconstraint.hpp
 * Author: jolo
 *
 * Created on 4. Januar 2011, 10:40
 */

#ifndef TABLECONSTRAINT_HPP
#define	TABLECONSTRAINT_HPP

#include <dbmodel/simpletableconstraint.hpp>

class TableColumn;

class TableConstraint: public SimpleTableConstraint {
public:
    TableConstraint(Table* t, const String& n);
    TableConstraint(const TableConstraint& o);
    virtual ~TableConstraint();

    TableColumn* add(TableColumn* c);
    TableColumn* add(const String& colName);
    std::vector<TableColumn*> columns() const;
    StringVector columnNames() const;
    String joinedColumnNames(const String& sep = ".") const;
private:
    std::vector<TableColumn*> _cols;
};

#endif	/* TABLECONSTRAINT_HPP */

