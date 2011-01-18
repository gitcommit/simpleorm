#include <dbconn/query.hpp>

#include <map>

#include <boost/assert.hpp>

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

void Query::addValue(const String& key, const String& value) {
    _values.insert(std::make_pair(key, value));
}

std::map<String, String> Query::values() const {
    return _values;
}

StringVector Query::keys() const {
    StringVector v;
    for (std::map<String, String>::const_iterator i = _values.begin(); i != _values.end(); ++i) {
        v.push_back(i->first);
    }
    return v;
}

String Query::value(const String& key) const {
    std::map<String, String>::const_iterator i = _values.find(key);
    BOOST_ASSERT(_values.end() != i);
    return i->second;
}