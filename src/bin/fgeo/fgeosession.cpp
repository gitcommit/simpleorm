#include <fgeosession.hpp>

#include <orm/mapping.hpp>

#include <dbconn/conn.hpp>

#include <dbmodel/database.hpp>
#include <dbmodel/schema.hpp>
#include <dbmodel/table.hpp>

#include <lib/core/siprefix.hpp>

FGeoSession::FGeoSession()
: Session() {
}

FGeoSession::~FGeoSession() {
}

Mapping* FGeoSession::mapping(const SiPrefix* o) {
    (void) o;
    String mn = "SiPrefix";
    
    if (hasMapping(mn)) {
        return mappingByName(mn);
    }

    Table* t = connection()->database()->table("core.si_prefixes");
    Mapping* m = createMapping(mn, t);

    m->createProperty("id", t->column("id"));
    m->createProperty("name", t->column("name"));
    m->createProperty("code", t->column("code"));
    m->createProperty("symbol", t->column("symbol"));
    m->createProperty("description", t->column("description"));
    m->createProperty("factor", t->column("factor"));
    
    return mapping(o);
}