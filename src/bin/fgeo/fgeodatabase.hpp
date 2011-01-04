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
    DataType* _int;
    DataType* _numeric;
    DataType* _text;
    DataType* _timestamp;
    DataType* _date;
    DataType* _code;
    DataType* _none;

    Schema* _core;
    Schema* _geology;
    Schema* _chemistry;
    Schema* _palaeontology;

    Table* _siPrefixes;
    Table* _units;
    Table* _unitConversions;

    DatabaseConstant* _currentUser;
    DatabaseConstant* _currentTimestamp;
    DatabaseConstant* _null;
};


#endif	/* FGEODATABASE_HPP */

