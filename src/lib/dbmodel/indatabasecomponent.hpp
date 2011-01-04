/* 
 * File:   indatabasecomponent.hpp
 * Author: jolo
 *
 * Created on 29. Dezember 2010, 20:49
 */

#ifndef INDATABASECOMPONENT_HPP
#define	INDATABASECOMPONENT_HPP

#include <dbmodel/component.hpp>

class Database;

class InDatabaseComponent: public Component {
public:
    InDatabaseComponent(Database* db, const String& name);
    InDatabaseComponent(const InDatabaseComponent& orig);
    virtual ~InDatabaseComponent();
    Database* database() const;
private:

};

#endif	/* INDATABASECOMPONENT_HPP */

