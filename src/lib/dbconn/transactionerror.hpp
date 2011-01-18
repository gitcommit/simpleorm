/* 
 * File:   transactionerror.hpp
 * Author: jolo
 *
 * Created on 18. Januar 2011, 18:21
 */

#ifndef TRANSACTIONERROR_HPP
#define	TRANSACTIONERROR_HPP

#include <dbconn/error.hpp>

#include <libpq-fe.h>

class TransactionError: public Error {
public:
    TransactionError(const String& msg, const ExecStatusType& t);
    TransactionError(const TransactionError& o);
    virtual ~TransactionError() throw();

    ExecStatusType execStatus() const;
private:
    ExecStatusType _t;
};

#endif	/* TRANSACTIONERROR_HPP */

