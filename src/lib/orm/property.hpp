/* 
 * File:   property.hpp
 * Author: jolo
 *
 * Created on 12. Januar 2011, 13:20
 */

#ifndef PROPERTY_HPP
#define	PROPERTY_HPP

#include <map>
#include <ostream>

#include <boost/any.hpp>

#include <common/customtypes.hpp>

class Entity;

class Property {
public:
    Property(Entity* entity, const String& name, const boost::any& value);
    
    Property(const Property& o);
    
    virtual ~Property();

    virtual void setValue(const boost::any& value);
    boost::any value() const;
    Integer toInteger() const;
    Numeric toNumeric() const;
    String toString() const;

    const bool isInteger() const;
    const bool isNumeric() const;
    const bool isString() const;
    
    virtual String name() const;

    virtual Entity* entity() const;
    virtual const bool hasEntity() const;    

    virtual void printOn(std::ostream& strm);
private:

    Entity* _entity;
    String _name;
    boost::any _value;
};

typedef std::map<String, Property> PropertyMap;
typedef PropertyMap::const_iterator PropertyMapConstIterator;

std::ostream& operator<<(std::ostream& strm, Property& p);

#endif	/* PROPERTY_HPP */
