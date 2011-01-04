/* 
 * File:   datatype.hpp
 * Author: jolo
 *
 * Created on 29. Dezember 2010, 20:52
 */

#ifndef DATATYPE_HPP
#define	DATATYPE_HPP

#include <dbmodel/indatabasecomponent.hpp>

class DataType: public InDatabaseComponent {
public:
    DataType(Database* db, const String& name, const String& sqlName);
    DataType(const DataType& orig);
    virtual ~DataType();
    virtual void setSqlName(const String& n);
    virtual String sqlName() const;
    Database* database() const;
    virtual void visit(ComponentVisitor* c);
private:
    String _sqlName;
};

typedef std::map<String, DataType*> DataTypeMap;
typedef DataTypeMap::const_iterator DataTypeMapConstIterator;
typedef DataTypeMap::iterator DataTypeMapIterator;

#endif	/* DATATYPE_HPP */

