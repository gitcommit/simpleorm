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

    Mapping* m = createMapping(mn);
    m->setTable(connection()->database()->table("core.si_prefixes"));
    return mapping(o);
}