/* 
 * File:   session.hpp
 * Author: jolo
 *
 * Created on 8. Januar 2011, 16:35
 */

#ifndef SESSION_HPP
#define	SESSION_HPP

#include <common/customtypes.hpp>

#include <vector>
#include <map>

class Entity;
class Conn;
class Mapping;
class Table;

class Session {
public:
    Session();
    virtual ~Session();
    virtual void add(Entity* e);
    virtual void remove(Entity* e);
    virtual bool contains(Entity* e) const;
    std::vector<Entity*> entities() const;

    virtual void setConnection(Conn* c);
    virtual const bool hasConnection() const;
    virtual Conn* connection() const;

    virtual const bool hasMapping(const String& mappingName) const;
    virtual Mapping* createMapping(const String& mappingName, Table* t = 0);
    virtual Mapping* add(const String& mappingName, Mapping* m);
    virtual Mapping* mappingByName(const String& mappingName) const;

    virtual void deleteFromDatabase(Entity* e);
    virtual void reload(Entity* e);
    virtual void insert(Entity* e);
    virtual void update(Entity* e);

protected:
    virtual void debugEntity(Entity* e);
private:
    Session(const Session& o);
    std::vector<Entity*> _entities;
    std::map<String, Mapping*> _mappings;
    Conn* _conn;
};

#endif	/* SESSION_HPP */

