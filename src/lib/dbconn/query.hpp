/* 
 * File:   query.hpp
 * Author: jolo
 *
 * Created on 13. Januar 2011, 19:47
 */

#ifndef QUERY_HPP
#define	QUERY_HPP

#include <common/customtypes.hpp>

class Session;

class Query {
public:
    Query(Session* s, const String& sql = "");
    Query(const Query& q);
    virtual ~Query();

    virtual void setSql(const String& sql);
    virtual String sql() const;
private:
    Session* _session;
    String _sql;
};

#endif	/* QUERY_HPP */

