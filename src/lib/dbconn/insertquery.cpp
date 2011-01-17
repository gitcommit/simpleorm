#include <dbconn/insertquery.hpp>

InsertQuery::InsertQuery(Session* s, const String& sql)
: Query(s, sql) {
}

InsertQuery::InsertQuery(const InsertQuery& o)
: Query(o) {
}

InsertQuery::~InsertQuery() {
}

