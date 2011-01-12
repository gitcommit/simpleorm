#include <orm/entity.hpp>

#include <sstream>

#include <boost/assert.hpp>
#include <orm/session.hpp>

Entity::Entity(Session* s, Entity* p)
: _session(0), _parent(0) {
    BOOST_ASSERT(0 != s);
    setSession(s);
    session()->add(this);
    setParent(p);
}

Entity::Entity(Entity* p)
: _session(0), _parent(0) {
    BOOST_ASSERT(0 != p);
    setSession(p->session());
    session()->add(this);
    setParent(p);
}

Entity::Entity(const Entity& o) {
}

Entity::~Entity() {
}

const bool Entity::hasSession() const {
    return (0 != _session);
}

Session* Entity::session() const {
    return _session;
}

void Entity::setSession(Session* s) {
    BOOST_ASSERT(! hasSession());
    _session = s;
}

String Entity::toString() const {
    return "Entity";
}

void Entity::printOn(std::ostream& s) {
    s << toString();
}

std::ostream& operator<<(std::ostream& strm, Entity& e) {
    e.printOn(strm);
    return strm;
}

Entity* Entity::parent() const {
    return _parent;
}

const bool Entity::hasParent() const {
    return (0 != parent());
}

const bool Entity::isChildOf(Entity* e) const {
    BOOST_ASSERT(0 != e);
    return (e->parent() != this);
}

void Entity::addChild(Entity* e) {
    BOOST_ASSERT(0 != e);
    BOOST_ASSERT(! e->isChildOf(this));
    _children.push_back(e);
}

void Entity::removeChild(Entity* e) {
    BOOST_ASSERT(0 != e);
    BOOST_ASSERT(e->isChildOf(this));
    for (std::vector<Entity*>::iterator i = _children.begin(); i != _children.end(); ++i) {
        if (e == (*i)) {
            _children.erase(i);
            return;
        }
    }
}

void Entity::setParent(Entity* e) {
    if (0 == e) {
        _parent = 0;
        return;
    }

    if (hasParent()) {
        Entity* parentE = e->parent();
        parentE->removeChild(e);
    }

    _parent = e;
    addChild(e);
}

const Integer Entity::childCount() const {
    return _children.size();
}

StringVector Entity::path() const {
    StringVector v;
    if (hasParent()) {
        StringVector buf = parent()->path();
        v.insert(v.begin(), buf.begin(), buf.end());
    }
    v.push_back(toString());
    return v;
}

String Entity::pathString(const String& sep) const {
    std::stringstream s;
    StringVector buf = path();
    for (StringVectorConstIterator i = buf.begin(); i != buf.end(); ++i) {
        if (i != buf.begin()) {
            s << sep;
        }
        s << *i;
    }
    return s.str();
}

const bool Entity::isNotEmpty(const String& s) const {
    return (s.size() > 0);
}

String Entity::bracket(const String& s, const String& left, const String& right) const {
    std::stringstream ss;
    ss << left << s << right;
    return ss.str();
}