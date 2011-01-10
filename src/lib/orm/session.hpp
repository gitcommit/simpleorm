/* 
 * File:   session.hpp
 * Author: jolo
 *
 * Created on 8. Januar 2011, 16:35
 */

#ifndef SESSION_HPP
#define	SESSION_HPP

#include <vector>

class Entity;

class Session {
public:
    Session();
    virtual ~Session();
    virtual void add(Entity* e);
    virtual void remove(Entity* e);
    virtual bool contains(Entity* e) const;
    std::vector<Entity*> entities() const;
    
private:
    Session(const Session& o);
    std::vector<Entity*> _entities;
};

#endif	/* SESSION_HPP */

