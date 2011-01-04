/* 
 * File:   databaseconstant.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 12:53
 */

#ifndef DATABASECONSTANT_HPP
#define	DATABASECONSTANT_HPP

#include <dbmodel/indatabasecomponent.hpp>

class DataType;

class DatabaseConstant: public InDatabaseComponent {
public:
    DatabaseConstant(Database* db, const String& name, DataType* t);
    DatabaseConstant(const DatabaseConstant& o);
    virtual ~DatabaseConstant();

    void setType(DataType* t);
    bool hasType() const;
    DataType* type() const;

    virtual void visit(ComponentVisitor* v);
private:
    DataType* _type;
};

typedef std::map<String, DatabaseConstant*> DatabaseConstantMap;
typedef DatabaseConstantMap::const_iterator DatabaseConstantMapConstIterator;

#endif	/* DATABASECONSTANT_HPP */

