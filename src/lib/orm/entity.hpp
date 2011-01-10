#ifndef ENTITY_H
#define ENTITY_H

#include <common/common.hpp>
#include <ostream>
#include <vector>

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

    virtual Mapping* mapping() const;
    virtual const bool hasMapping() const;
    virtual void setMapping(Mapping* m);
protected:
    virtual Mapping* createMapping();
    virtual const bool isNotEmpty(const String& s) const;
    virtual String bracket(const String& s, const String& left = "[", const String& right = "]") const;
private:
    Entity(const Entity& o);
    
    Session* _session;
    Entity* _parent;
    Mapping* _mapping;
    std::vector<Entity*> _children;
};

std::ostream& operator<<(std::ostream& strm, Entity& e);

#endif
