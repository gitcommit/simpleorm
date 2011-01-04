/* 
 * File:   primarykeyconstraint.hpp
 * Author: jolo
 *
 * Created on 4. Januar 2011, 19:25
 */

#ifndef PRIMARYKEYCONSTRAINT_HPP
#define	PRIMARYKEYCONSTRAINT_HPP

#include <dbmodel/tableconstraint.hpp>

class ComponentVisitor;

class PrimaryKeyConstraint: public TableConstraint {
public:
    PrimaryKeyConstraint(Table* t, const String& n);
    PrimaryKeyConstraint(const PrimaryKeyConstraint& c);
    virtual ~PrimaryKeyConstraint();

    virtual void visit(ComponentVisitor* v);
};

typedef std::map<String, PrimaryKeyConstraint*> PrimaryKeyConstraintMap;
typedef PrimaryKeyConstraintMap::const_iterator PrimaryKeyConstraintMapConstIterator;

#endif	/* PRIMARYKEYCONSTRAINT_HPP */

