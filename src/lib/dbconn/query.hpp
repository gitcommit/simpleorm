/* 
 * File:   query.hpp
 * Author: jolo
 *
 * Created on 13. Januar 2011, 19:47
 */

#ifndef QUERY_HPP
#define	QUERY_HPP

#include <common/customtypes.hpp>

#include <map>

class Session;

class Query {
public:
    Query(Session* s, const String& sql = "");
    Query(const Query& q);
    virtual ~Query();

    virtual void setSql(const String& sql);
    virtual String sql() const;
    virtual void addValue(const String& key, const String& value);
    std::map<String, String> values() const;
    std::vector<String> keys() const;
    String value(const String& key) const;
private:
    Session* _session;
    String _sql;
    std::map<String, String> _values;
};

#endif	/* QUERY_HPP */

