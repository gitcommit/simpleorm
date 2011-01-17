/* 
 * File:   entityvisitor.hpp
 * Author: jolo
 *
 * Created on 16. Januar 2011, 10:47
 */

#ifndef ENTITYVISITOR_HPP
#define	ENTITYVISITOR_HPP

class Entity;

class EntityVisitor {
public:
    EntityVisitor();
    EntityVisitor(const EntityVisitor& o);
    virtual ~EntityVisitor();

    virtual void perform(Entity* e);
};

#endif	/* ENTITYVISITOR_HPP */

