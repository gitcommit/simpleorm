/* 
 * File:   databaseconstantdefaultgenerator.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 13:41
 */

#ifndef DATABASECONSTANTDEFAULTGENERATOR_HPP
#define	DATABASECONSTANTDEFAULTGENERATOR_HPP

#include <dbmodel/defaultgenerator.hpp>

#include "databaseconstant.hpp"

class DatabaseConstant;

class DatabaseConstantDefaultGenerator: public DefaultGenerator {
public:
    DatabaseConstantDefaultGenerator(TableColumn* col, DatabaseConstant* c);
    DatabaseConstantDefaultGenerator(const DatabaseConstantDefaultGenerator& o);
    virtual ~DatabaseConstantDefaultGenerator();

    virtual String value() const;
    
private:
    DatabaseConstant* _c;
};

#endif	/* DATABASECONSTANTDEFAULTGENERATOR_HPP */

