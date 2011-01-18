/* 
 * File:   connectionerror.hpp
 * Author: jolo
 *
 * Created on 18. Januar 2011, 09:17
 */

#ifndef CONNECTIONERROR_HPP
#define	CONNECTIONERROR_HPP

#include <dbconn/error.hpp>

#include <libpq-fe.h>

class ConnectionError: public Error {
public:
    ConnectionError(const String& what, const ConnStatusType& t);
    ConnectionError(const ConnectionError& o);
    virtual ~ConnectionError() throw();

    ConnStatusType connStatus() const;
    
private:
    ConnStatusType _connStatus;
};

#endif	/* CONNECTIONERROR_HPP */

