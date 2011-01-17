/* 
 * File:   persistancevisitor.hpp
 * Author: jolo
 *
 * Created on 13. Januar 2011, 17:23
 */

#ifndef PERSISTANCEVISITOR_HPP
#define	PERSISTANCEVISITOR_HPP

#include <orm/entityvisitor.hpp>

#include <common/customtypes.hpp>
#include <dbconn/query.hpp>

#include "entity.hpp"

class PersistanceVisitor: public EntityVisitor {
public:
    PersistanceVisitor();
    PersistanceVisitor(const PersistanceVisitor& o);
    virtual ~PersistanceVisitor();

    virtual void perform(Entity* e) = 0;
    Query* query() const;
    Entity* entity() const;

    virtual const bool hasQuery() const;
    virtual const bool hasEntity() const;
protected:
    virtual void setQuery(Query* q);
private:
    Entity* _entity;
    Query* _query;
};

#endif	/* PERSISTANCEVISITOR_HPP */

