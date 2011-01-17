#include <dbconn/query.hpp>

Query::Query(Session* s, const String& sql)
: _session(s), _sql(sql) {
    setSql(sql);
}

Query::Query(const Query& o)
: _session(o._session), _sql(o._sql) {
}

Query::~Query() {
}

void Query::setSql(const String& sql) {
    _sql = sql;
}

String Query::sql() const {
    return _sql;
}