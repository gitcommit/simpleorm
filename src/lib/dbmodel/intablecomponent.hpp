/* 
 * File:   intablecomponent.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 14:29
 */

#ifndef INTABLECOMPONENT_HPP
#define	INTABLECOMPONENT_HPP

#include <dbmodel/component.hpp>

class Table;

class InTableComponent: public Component {
public:
    InTableComponent(Table* t, const String& name);
    InTableComponent(const InTableComponent& o);
    virtual ~InTableComponent();

    virtual Table* table() const;
    virtual String qualifiedName() const;
};

#endif	/* INTABLECOMPONENT_HPP */

