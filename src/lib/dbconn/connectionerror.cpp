#include <dbconn/connectionerror.hpp>

ConnectionError::ConnectionError(const String& what, const ConnStatusType& t)
: Error(what), _connStatus(t) {
}

ConnectionError::ConnectionError(const ConnectionError& o)
: Error(o) {
}

ConnectionError::~ConnectionError() throw () {
}

ConnStatusType ConnectionError::connStatus() const {
    return _connStatus;
}