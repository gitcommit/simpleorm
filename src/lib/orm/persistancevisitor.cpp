#include <orm/persistancevisitor.hpp>

PersistanceVisitor::PersistanceVisitor()
: EntityVisitor(), _query(0), _entity(0) {
}

PersistanceVisitor::PersistanceVisitor(const PersistanceVisitor& o)
: EntityVisitor(o), _query(o._query), _entity(o._entity) {
}

PersistanceVisitor::~PersistanceVisitor() {
}

Query* PersistanceVisitor::query() const {
    return _query;
}

Entity* PersistanceVisitor::entity() const {
    return _entity;
}

const bool PersistanceVisitor::hasEntity() const {
    return (0 != entity());
}

const bool PersistanceVisitor::hasQuery() const {
    return (0 != query());
}

void PersistanceVisitor::setQuery(Query* q) {
    if (hasQuery()) {
        delete _query;
    }
    _query = q;
}