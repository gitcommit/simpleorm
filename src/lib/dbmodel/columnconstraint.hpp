/* 
 * File:   columnconstraint.hpp
 * Author: jolo
 *
 * Created on 4. Januar 2011, 09:34
 */

#ifndef COLUMNCONSTRAINT_HPP
#define	COLUMNCONSTRAINT_HPP

#include <dbmodel/intablecolumncomponent.hpp>

class ColumnConstraint: public InTableColumnComponent {
public:
    ColumnConstraint(TableColumn* c, const String& n);
    ColumnConstraint(const ColumnConstraint& c);
    virtual ~ColumnConstraint();
};

#endif	/* COLUMNCONSTRAINT_HPP */

