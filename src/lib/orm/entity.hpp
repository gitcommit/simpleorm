#ifndef ENTITY_H
#define ENTITY_H

#include <common/customtypes.hpp>
#include <ostream>
#include <vector>

#include <orm/property.hpp>

class Session;
class Mapping;

class Entity {
public:
    Entity(Session* s, Entity* parent = 0);
    Entity(Entity* p);
    
    virtual ~Entity();
    
    Session* session() const;
    virtual void setSession(Session* s);
    virtual const bool hasSession() const;
    
    virtual String toString() const;
    virtual void printOn(std::ostream& o);

    virtual Entity* parent() const;
    virtual const bool hasParent() const;
    virtual const bool isChildOf(Entity* e) const;
    virtual void setParent(Entity* e);
    virtual void addChild(Entity* e);
    virtual void removeChild(Entity* e);
    virtual const Integer childCount() const;

    virtual StringVector path() const;
    virtual String pathString(const String& sep = "/") const;

    virtual Mapping* mapping() const = 0;

    virtual void persist() = 0;
    virtual void deleteFromDatabase();
    virtual void reload();

    virtual void setProperty(const String& name, const boost::any& value);
    virtual void setProperty(const String& name, const String& value);
    virtual void setProperty(const String& name, const Integer& value);
    virtual void setProperty(const String& name, const Numeric& value);
    virtual void setProperty(const Property& p);

    virtual Property property(const String& name) const;
    virtual const bool hasProperty(const String& name) const;
    virtual PropertyMap properties() const;
    virtual StringVector propertyNames() const;

protected:
    virtual void insert();
    virtual void update();
    
    virtual const bool isNotEmpty(const String& s) const;
    virtual String bracket(const String& s, const String& left = "[", const String& right = "]") const;
private:
    Entity(const Entity& o);
    
    Session* _session;
    Entity* _parent;
    std::vector<Entity*> _children;

    PropertyMap _properties;
};

std::ostream& operator<<(std::ostream& strm, Entity& e);

#endif
