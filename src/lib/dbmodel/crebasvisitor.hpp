/* 
 * File:   crebasvisitor.hpp
 * Author: jolo
 *
 * Created on 29. Dezember 2010, 21:06
 */

#ifndef CREBASVISITOR_HPP
#define	CREBASVISITOR_HPP

#include "notnullconstraint.hpp"


#include <dbmodel/componentvisitor.hpp>

#include <dbmodel/component.hpp>

#include "defaultgenerator.hpp"
#include "uniqueconstraint.hpp"
#include "primarykeyconstraint.hpp"
#include "table.hpp"

class Database;
class DataType;
class Schema;

class CrebasVisitor: public ComponentVisitor {
public:
    CrebasVisitor();
    CrebasVisitor(const CrebasVisitor& orig);
    virtual ~CrebasVisitor();
    StringVector result() const;
    String formattedResult() const;
    virtual void perform(Database* db);
    virtual void perform(DataType* t);
    virtual void perform(DatabaseConstant* c);
    virtual void perform(Schema* s);
    virtual void perform(Sequence* s);
    virtual void perform(Table* t);
    virtual void perform(DefaultGenerator* g);
    virtual void perform(TableColumn* c);
    virtual void perform(NotNullConstraint* c);
    virtual void perform(UniqueConstraint* c);
    virtual void perform(PrimaryKeyConstraint* c);
protected:
    virtual void add(const String& res);
    virtual String comment(const String& s) const;
    virtual String command(const String& s) const;
private:
    StringVector _res;
};


#endif	/* CREBASVISITOR_HPP */

