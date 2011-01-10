/* 
 * File:   identifiedentity.hpp
 * Author: jolo
 *
 * Created on 10. Januar 2011, 11:17
 */

#ifndef IDENTIFIEDENTITY_HPP
#define	IDENTIFIEDENTITY_HPP

#include <omodel/entity.hpp>

class IdentifiedEntity: public Entity {
public:
    IdentifiedEntity(Session* s, const Integer& id = 0);
    IdentifiedEntity(Entity* p, const Integer& id = 0);
    virtual ~IdentifiedEntity();

    virtual const bool hasId() const;
    virtual void setId(const Integer& id);
    virtual const Integer id() const;

    virtual String toString() const;
    virtual String idInBrackets(const String& leftBracket = "[", const String& rightBracket = "]") const;
private:
    Integer _id;
};

#endif	/* IDENTIFIEDENTITY_HPP */

