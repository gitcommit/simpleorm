/* 
 * File:   fgeosession.hpp
 * Author: jolo
 *
 * Created on 12. Januar 2011, 12:28
 */

#ifndef FGEOSESSION_HPP
#define	FGEOSESSION_HPP

#include <orm/session.hpp>

class SiPrefix;

class FGeoSession: public Session {
public:
    FGeoSession();
    virtual ~FGeoSession();

    Mapping* mapping(const SiPrefix* o);
};

#endif	/* FGEOSESSION_HPP */

