/* 
 * File:   schema.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 10:07
 */

#ifndef SCHEMA_HPP
#define	SCHEMA_HPP

#include <dbmodel/indatabasecomponent.hpp>
#include <dbmodel/sequence.hpp>
#include <dbmodel/table.hpp>
#include <dbmodel/tablecolumn.hpp>

class Schema: public InDatabaseComponent {
public:
    Schema(Database* db, const String& name);
    Schema(const Schema& o);
    virtual ~Schema();
    virtual void visit(ComponentVisitor* v);

    Sequence* createSequence(const String& name);
    Sequence* add(Sequence* s);
    Sequence* sequence(const String& name) const;
    SequenceMap sequences() const;

    Table* createTable(const String& name);
    Table* add(Table* t);
    Table* table(const String& name) const;
    TableMap tables() const;

    TableColumn* add(TableColumn* c);
    TableColumn* tableColumn(const String& qualifiedName);
    TableColumnMap tableColumns() const;
    
private:
    SequenceMap _sequences;
    TableMap _tables;
    TableColumnMap _tableColumns;
};

typedef std::map<String, Schema*> SchemaMap;
typedef SchemaMap::const_iterator SchemaMapConstIterator;

#endif	/* SCHEMA_HPP */

