#include <dbmodel/component.hpp>
#include <dbmodel/componentvisitor.hpp>

#include <boost/assert.hpp>

#include <ostream>
#include <vector>

Component::Component(Component* p, const String& n)
: _parent(p), _name(n) {
    setParent(p);
    setName(n);
}

Component::Component(const Component& o)
: _parent(o._parent), _name(o._name) {
    setParent(o.parent());
    setName(o.name());
}

Component::Component(const String& name)
: _parent(0), _name(name) {
    setParent(0);
    setName(name);
}

void Component::setName(const String& name) {
    _name = name;
}

String Component::name() const {
    return _name;
}

Component* Component::add(Component* c) {
    _children.insert(std::make_pair(c->name(), c));
    return child(c->name());
}

Component* Component::child(const String& name) const {
    ComponentMapConstIterator i = _children.find(name);
    BOOST_ASSERT(_children.end() != i);
    return i->second;
}

Component* Component::parent() const {
    return _parent;
}

bool Component::hasParent() const {
    return (0 != parent());
}

Component* Component::setParent(Component* c) {
    if (hasParent()) {
        parent()->remove(this);
    }
    _parent = c;
    if (0 != _parent) {
        parent()->add(this);
    }
    return parent();
}

void Component::remove(Component* c) {
    if (_children.count(c->name()) > 0) {
        ComponentMapIterator i = _children.find(c->name());
        _children.erase(i);
    }
}

void Component::printOn(std::ostream& out) {
    out << pathString();
}

std::ostream& operator<< (std::ostream& out, Component& c) {
    c.printOn(out);
    return out;
}

StringVector Component::path() const {
    StringVector ret;
    if (hasParent()) {
        StringVector b = parent()->path();
        ret.insert(ret.begin(), b.begin(), b.end());
    }
    ret.push_back(name());
    return ret;
}

String Component::pathString(const String& sep) const {
    String ret;
    StringVector p = path();
    for (StringVectorConstIterator i = p.begin(); i != p.end(); ++i) {
        if (i != p.begin()) {
            ret += sep;
        }
        ret += (*i);
    }
    return ret;
}
