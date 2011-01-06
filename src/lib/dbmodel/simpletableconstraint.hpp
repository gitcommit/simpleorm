/* 
 * File:   simpletableconstraint.hpp
 * Author: jolo
 *
 * Created on 6. Januar 2011, 11:15
 */

#ifndef SIMPLETABLECONSTRAINT_HPP
#define	SIMPLETABLECONSTRAINT_HPP

#include <dbmodel/intablecomponent.hpp>

class TableColumn;

class SimpleTableConstraint: public InTableComponent {
public:
    SimpleTableConstraint(Table* t, const String& n);
    SimpleTableConstraint(const SimpleTableConstraint& o);
    virtual ~SimpleTableConstraint();
};

#endif	/* SIMPLETABLECONSTRAINT_HPP */

