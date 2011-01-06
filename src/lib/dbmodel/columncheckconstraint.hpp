/* 
 * File:   columncheckconstraint.hpp
 * Author: jolo
 *
 * Created on 4. Januar 2011, 19:41
 */

#ifndef COLUMNCHECKCONSTRAINT_HPP
#define	COLUMNCHECKCONSTRAINT_HPP

#include <dbmodel/columnconstraint.hpp>

class ComponentVisitor;

class ColumnCheckConstraint: public ColumnConstraint {
public:
    ColumnCheckConstraint(TableColumn* c, const String& name, const String& code);
    ColumnCheckConstraint(const ColumnCheckConstraint& o);
    virtual ~ColumnCheckConstraint();

    virtual void visit(ComponentVisitor* v);

    virtual void setCode(const String& c);
    virtual String code() const;
private:
    String _code;
};

typedef std::map<String, ColumnCheckConstraint*> ColumnCheckConstraintMap;
typedef ColumnCheckConstraintMap::const_iterator ColumnCheckConstraintMapConstIterator;

#endif	/* COLUMNCHECKCONSTRAINT_HPP */

