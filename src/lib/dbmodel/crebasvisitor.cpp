#include <dbmodel/crebasvisitor.hpp>

#include <boost/assert.hpp>

#include <iostream>

#include "datatype.hpp"
#include "database.hpp"
#include "databaseconstant.hpp"

CrebasVisitor::CrebasVisitor()
: ComponentVisitor() {
}

CrebasVisitor::CrebasVisitor(const CrebasVisitor& orig)
: ComponentVisitor(orig), _res(orig._res) {
}

CrebasVisitor::~CrebasVisitor() {
}


StringVector CrebasVisitor::result() const {
    return _res;
}

String CrebasVisitor::formattedResult() const {
    String ret;
    StringVector v = result();
    for (StringVectorConstIterator i = v.begin(); i != v.end(); ++i) {
        if (v.end() != i) {
            ret += "\n";
        }
        ret += (*i);
    }
    return ret;
}

String CrebasVisitor::command(const String& s) const {
    return s + ";";
}

String CrebasVisitor::comment(const String& s) const {
    return "-- " + s;
}

void CrebasVisitor::add(const String& res) {
    _res.push_back(res);
}

void CrebasVisitor::perform(Database* d) {
    BOOST_ASSERT(0 != d);
    add(command("CREATE DATABASE " + d->name()));

    DataTypeMap dtm = d->dataTypes();
    for (DataTypeMapConstIterator i = dtm.begin(); i != dtm.end(); ++i) {
        i->second->visit(this);
    }

    DatabaseConstantMap cm = d->databaseConstants();
    for (DatabaseConstantMapConstIterator i = cm.begin(); i != cm.end(); ++i) {
        i->second->visit(this);
    }

    SchemaMap sm = d->schemata();
    for (SchemaMapConstIterator i = sm.begin(); i != sm.end(); ++i) {
        i->second->visit(this);
    }

    SequenceMap seqm = d->sequences();
    for (SequenceMapConstIterator i = seqm.begin(); i != seqm.end(); ++i) {
        i->second->visit(this);
    }

    TableMap tm = d->tables();
    for (TableMapConstIterator i = tm.begin(); i != tm.end(); ++i) {
        i->second->visit(this);
    }

    TableColumnMap tcm = d->tableColumns();
    for (TableColumnMapConstIterator i = tcm.begin(); i != tcm.end(); ++i) {
        i->second->visit(this);
    }
}

void CrebasVisitor::perform(DataType* t) {
    BOOST_ASSERT(0 != t);
    add(comment("DATA TYPE: " + t->sqlName()));
}

void CrebasVisitor::perform(Schema* s) {
    BOOST_ASSERT(0 != s);
    add(command("CREATE SCHEMA " + s->name()));
}

void CrebasVisitor::perform(Sequence* s) {
    BOOST_ASSERT(0 != s);
    add(command("CREATE SEQUENCE " + s->qualifiedName()));
}

void CrebasVisitor::perform(Table* t) {
    BOOST_ASSERT(0 != t);
    add(command("CREATE TABLE " + t->qualifiedName() + "()"));
}

void CrebasVisitor::perform(DatabaseConstant* c) {
    BOOST_ASSERT(0 != c);
    add(comment("DATABASE CONSTANT: " + c->name() + ": " + c->type()->sqlName()));
}

void CrebasVisitor::perform(DefaultGenerator* g) {
    BOOST_ASSERT(0 != g);
    add(command("ALTER TABLE " + g->tableColumn()->table()->qualifiedName()
        + " ALTER COLUMN " + g->tableColumn()->name() + " SET DEFAULT " + g->value()));
}

void CrebasVisitor::perform(TableColumn* c) {
    BOOST_ASSERT(0 != c);
    add(command("ALTER TABLE " + c->table()->qualifiedName() + " ADD COLUMN " + c->name() + " " + c->type()->sqlName()));
    if (c->hasDefault()) {
        c->defaultGenerator()->visit(this);
    }
}