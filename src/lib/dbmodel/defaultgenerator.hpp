/* 
 * File:   defaultgenerator.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 13:12
 */

#ifndef DEFAULTGENERATOR_HPP
#define	DEFAULTGENERATOR_HPP

#include <dbmodel/intablecolumncomponent.hpp>

class TableColumn;
class ComponentVisitor;

class DefaultGenerator: public InTableColumnComponent {
public:
    DefaultGenerator(TableColumn* c);
    DefaultGenerator(const DefaultGenerator& o);
    virtual ~DefaultGenerator();

    virtual String value() const = 0;
    virtual void visit(ComponentVisitor* v);
};
#endif	/* DEFAULTGENERATOR_HPP */

