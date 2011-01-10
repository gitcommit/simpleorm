#include <iostream>

#include <fgeodatabase.hpp>
#include <dbmodel/crebasvisitor.hpp>

#include <orm/session.hpp>
#include <omodel/entity.hpp>

#include "omodel/identifiedentity.hpp"
#include "omodel/namedentity.hpp"

int main(int argc, char** argv) {
    Database* db = new FGeoDatabase("db");
    CrebasVisitor* v = new CrebasVisitor();
    db->visit(v);
    //std::cout << std::endl << v->formattedResult() << std::endl;

    Session* s = new Session();
    NamedEntity* universe = new NamedEntity(s, 1, "Universe");
    NamedEntity* galaxy = new NamedEntity(universe, 2, "Galaxy");
    NamedEntity* solar = new NamedEntity(galaxy, 3, "Solar System");
    NamedEntity* earth = new NamedEntity(solar, 4, "Earth");
    NamedEntity* mercury = new NamedEntity(solar, 5, "Mercury");
    NamedEntity* moon = new NamedEntity(earth, 6, "Moon");
    
    std::cout << *universe  << ": " << universe->pathString() << std::endl;
    std::cout << *galaxy << ": " << galaxy->pathString() << std::endl;
    std::cout << earth->pathString() << std::endl;
    std::cout << moon->pathString() << std::endl;
    
    return 0;
}
