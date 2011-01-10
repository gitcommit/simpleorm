/* 
 * File:   fgeoapplication.hpp
 * Author: jolo
 *
 * Created on 10. Januar 2011, 14:24
 */

#ifndef FGEOAPPLICATION_HPP
#define	FGEOAPPLICATION_HPP

#include <application/application.hpp>

class FGeoApplication: public Application {
public:
    FGeoApplication();
    virtual ~FGeoApplication();
    virtual Integer exec();
};

#endif	/* FGEOAPPLICATION_HPP */

