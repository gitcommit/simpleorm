/* 
 * File:   foreignkeyconstraint.hpp
 * Author: jolo
 *
 * Created on 5. Januar 2011, 10:13
 */

#ifndef FOREIGNKEYCONSTRAINT_HPP
#define	FOREIGNKEYCONSTRAINT_HPP

#include <dbmodel/simpletableconstraint.hpp>
#include <dbmodel/tablecolumn.hpp>

class ForeignKeyConstraint: public SimpleTableConstraint {
public:
    ForeignKeyConstraint(Table* t, const String& name, Table* referencedT);
    ForeignKeyConstraint(const ForeignKeyConstraint& o);
    virtual ~ForeignKeyConstraint();

    Table* referencedTable() const;
    void visit(ComponentVisitor* v);

    TableColumnPair add(TableColumn* local, TableColumn* referenced);

    TableColumnMap localColumns() const;
    TableColumnMap referencedColumns() const;

    StringVector localColumnNames() const;
    StringVector referencedColumnNames() const;

    String joinedLocalColumnNames(const String& seq = ", ") const;
    String joinedReferencedColumnNames(const String& sep = ", ") const;
    
    TableColumnPairVector columnPairs() const;

private:
    Table* _referencedTable;
    TableColumnPairVector _columnPairs;

};

typedef std::map<String, ForeignKeyConstraint*> ForeignKeyConstraintMap;
typedef ForeignKeyConstraintMap::const_iterator ForeignKeyConstraintMapConstIterator;

#endif	/* FOREIGNKEYCONSTRAINT_HPP */

