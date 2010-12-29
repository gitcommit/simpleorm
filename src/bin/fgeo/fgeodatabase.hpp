/* 
 * File:   fgeodatabase.hpp
 * Author: jolo
 *
 * Created on 29. Dezember 2010, 20:41
 */

#ifndef FGEODATABASE_HPP
#define	FGEODATABASE_HPP

#include <dbmodel/database.hpp>

class FGeoDatabase: public Database {
public:
    FGeoDatabase(const std::string& name);
    FGeoDatabase(const FGeoDatabase& orig);
    virtual ~FGeoDatabase();
private:

};


#endif	/* FGEODATABASE_HPP */

