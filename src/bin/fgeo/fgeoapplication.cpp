#include <fgeoapplication.hpp>

#include <iostream>

#include <fgeodatabase.hpp>
#include <fgeosession.hpp>

#include <dbmodel/database.hpp>
#include <dbmodel/crebasvisitor.hpp>
#include <orm/session.hpp>
#include <orm/mapping.hpp>

#include <dbconn/conn.hpp>

#include <dbconn/connectiondata.hpp>
#include <application/settings.hpp>

#include <lib/core/siprefix.hpp>

FGeoApplication::FGeoApplication()
        : Application() {
    settings()->connectionData()->setHost("localhost");
    settings()->connectionData()->setPort(5432);
    settings()->connectionData()->setDatabase("fgeo");
    settings()->connectionData()->setUser("jolo");
    settings()->connectionData()->setPassword("nix");

    setConnection(new Conn());
    setDatabase(new FGeoDatabase("db"));
    connection()->setDatabase(database());
    setSession(new FGeoSession());
    session()->setConnection(connection());
}

FGeoApplication::~FGeoApplication() {
}

Integer FGeoApplication::exec() {
    CrebasVisitor crebas;
    database()->visit(&crebas);
    
    std::cout << std::endl << crebas.formattedResult() << std::endl;

    (void) new SiPrefix(session(), "Mega", "M", "M", 1000);
    (void) new SiPrefix(session(), "Milli", "m", "m", 0.001);

    std::vector<Entity*> entities = session()->entities();
    for (std::vector<Entity*>::const_iterator i = entities.begin(); i != entities.end(); ++i) {
        std::cout << (*i)->pathString() << " --> " << (*i)->mapping()->table()->qualifiedName() << std::endl;
    }
    return 0;
}