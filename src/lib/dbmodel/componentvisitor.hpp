/* 
 * File:   componentvisitor.hpp
 * Author: jolo
 *
 * Created on 29. Dezember 2010, 20:22
 */

#ifndef COMPONENTVISITOR_HPP
#define	COMPONENTVISITOR_HPP

class Component;

class ComponentVisitor {
public:
    ComponentVisitor();
    ComponentVisitor(const ComponentVisitor& o);
    virtual ~ComponentVisitor();

    virtual void perform(Component* c);
};

#endif	/* COMPONENTVISITOR_HPP */

