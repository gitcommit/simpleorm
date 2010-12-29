/* 
 * File:   database.hpp
 * Author: jolo
 *
 * Created on 29. Dezember 2010, 20:37
 */

#ifndef DATABASE_HPP
#define	DATABASE_HPP

#include <dbmodel/component.hpp>

class Database: public Component {
public:
    Database(const String& name);
    Database(const Database& orig);
    virtual ~Database();
private:

};

#endif	/* DATABASE_HPP */

