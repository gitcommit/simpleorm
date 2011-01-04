/* 
 * File:   uniqueconstraint.hpp
 * Author: jolo
 *
 * Created on 4. Januar 2011, 10:44
 */

#ifndef UNIQUECONSTRAINT_HPP
#define	UNIQUECONSTRAINT_HPP

#include <dbmodel/tableconstraint.hpp>

class UniqueConstraint: public TableConstraint {
public:
    UniqueConstraint(Table* t, const String& name);
    UniqueConstraint(const UniqueConstraint& o);
    virtual ~UniqueConstraint();

    virtual void visit(ComponentVisitor* v);
};

typedef std::map<String, UniqueConstraint*> UniqueConstraintMap;
typedef UniqueConstraintMap::const_iterator UniqueConstraintMapConstIterator;

#endif	/* UNIQUECONSTRAINT_HPP */

