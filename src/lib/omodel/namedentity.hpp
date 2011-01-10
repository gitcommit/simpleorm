/* 
 * File:   namedentity.hpp
 * Author: jolo
 *
 * Created on 10. Januar 2011, 11:47
 */

#ifndef NAMEDENTITY_HPP
#define	NAMEDENTITY_HPP

#include <omodel/identifiedentity.hpp>

class NamedEntity: public IdentifiedEntity {
public:
    NamedEntity(Session* s, const Integer& id = 0, const String& name = "");
    NamedEntity(NamedEntity* p, const Integer& id = 0, const String& name = "");
    
    virtual ~NamedEntity();

    virtual const bool hasName() const;
    virtual String name() const;
    virtual void setName(const String& n);

    virtual String toString() const;
private:
    String _name;
};

#endif	/* NAMEDENTITY_HPP */

