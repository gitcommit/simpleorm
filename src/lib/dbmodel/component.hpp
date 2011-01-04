#ifndef COMPONENT_H
#define COMPONENT_H

#include <map>

#include <common/common.hpp>

class ComponentVisitor;

class Component {
public:
    Component(Component* p, const String& name);
    Component(const String& name);
    Component(const Component& other);
    
    void setName(const String& name);
    String name() const;
    bool hasParent() const;
    Component* parent() const;

    virtual StringVector path() const;
    virtual String pathString(const String& sep = "/") const;
    virtual void printOn(std::ostream& strm);

    virtual void visit(ComponentVisitor* v) = 0;
protected:
    virtual Component* setParent(Component* p);
    virtual void remove(Component* c);
    Component* add(Component* c);
    Component* child(const String& name) const;
    
private:
    Component* _parent;
    String _name;
    std::map<String, Component*> _children;
};

typedef std::map<String, Component*> ComponentMap;
typedef ComponentMap::iterator ComponentMapIterator;
typedef ComponentMap::const_iterator ComponentMapConstIterator;

std::ostream& operator<< (std::ostream& out, Component& c);

#endif
