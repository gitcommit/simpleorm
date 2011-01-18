#include <dbconn/transactionerror.hpp>

TransactionError::TransactionError(const String& msg, const ExecStatusType& t)
: Error(msg), _t(t) {
}

TransactionError::TransactionError(const TransactionError& o)
: Error(o), _t(o._t) {
}

TransactionError::~TransactionError() throw() {
}

ExecStatusType TransactionError::execStatus() const {
    return _t;
}