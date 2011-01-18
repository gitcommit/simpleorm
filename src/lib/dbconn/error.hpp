/* 
 * File:   error.hpp
 * Author: jolo
 *
 * Created on 17. Januar 2011, 22:14
 */

#ifndef ERROR_HPP
#define	ERROR_HPP

#include <common/customtypes.hpp>

#include <ostream>
#include <stdexcept>

class Error: public std::runtime_error {
public:
    Error(const String& msg);
    Error(const Error& o);
    virtual ~Error() throw();

    virtual String toString() const;
    virtual void printOn(std::ostream& strm);
};

std::ostream& operator<<(std::ostream& strm, Error& e);

#endif	/* ERROR_HPP */

