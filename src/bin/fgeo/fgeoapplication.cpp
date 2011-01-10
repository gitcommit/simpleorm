#include <fgeoapplication.hpp>

#include <iostream>

#include <fgeodatabase.hpp>
#include <dbmodel/database.hpp>
#include <dbmodel/crebasvisitor.hpp>
#include <orm/session.hpp>
#include <orm/standardentity.hpp>

FGeoApplication::FGeoApplication()
        : Application() {
    setDatabase(new FGeoDatabase("db"));
    setSession(new Session());
}
FGeoApplication::~FGeoApplication() {}

Integer FGeoApplication::exec() {
    CrebasVisitor crebas;
    database()->visit(&crebas);
    
    std::cout << std::endl << crebas.formattedResult() << std::endl;

    StandardEntity* universe = new StandardEntity(session(), 1, "Universe", "U");

    StandardEntity* galaxy = new StandardEntity(universe, 2, "Galaxy", "G");
    StandardEntity* solar = new StandardEntity(galaxy, 3, "Solar System", "S");
    StandardEntity* earth = new StandardEntity(solar, 4, "Earth", "E");
    (void) new StandardEntity(solar, 5, "Mercury", "M");
    (void) new StandardEntity(earth, 6, "Moon", "MN");


    std::vector<Entity*> entities = session()->entities();
    for (std::vector<Entity*>::const_iterator i = entities.begin(); i != entities.end(); ++i) {
        std::cout << (*i)->pathString() << std::endl;
    }
    return 0;
}
