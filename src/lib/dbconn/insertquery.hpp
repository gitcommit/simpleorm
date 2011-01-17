/* 
 * File:   insertquery.hpp
 * Author: jolo
 *
 * Created on 13. Januar 2011, 20:25
 */

#ifndef INSERTQUERY_HPP
#define	INSERTQUERY_HPP

#include <dbconn/query.hpp>

class InsertQuery: public Query {
public:
    InsertQuery(Session* s, const String& sql = "");
    InsertQuery(const InsertQuery& o);
    virtual ~InsertQuery();
};

#endif	/* INSERTQUERY_HPP */

