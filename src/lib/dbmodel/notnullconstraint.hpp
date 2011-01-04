/* 
 * File:   notnullconstraint.hpp
 * Author: jolo
 *
 * Created on 4. Januar 2011, 09:40
 */

#ifndef NOTNULLCONSTRAINT_HPP
#define	NOTNULLCONSTRAINT_HPP

#include <dbmodel/columnconstraint.hpp>

class NotNullConstraint: public ColumnConstraint {
public:
    NotNullConstraint(TableColumn* c);
    NotNullConstraint(const NotNullConstraint& o);
    virtual ~NotNullConstraint();
    virtual void visit(ComponentVisitor* v);
};

#endif	/* NOTNULLCONSTRAINT_HPP */

