#include <dbconn/error.hpp>

Error::Error(const String& msg)
: std::runtime_error(msg) {
}

Error::Error(const Error& o)
: std::runtime_error(o) {
}

Error::~Error() throw() {
}

String Error::toString() const {
    return what();
}

void Error::printOn(std::ostream& strm) {
    strm << toString();
}

std::ostream& operator<<(std::ostream& strm, Error& e) {
    e.printOn(strm);
    return strm;
}