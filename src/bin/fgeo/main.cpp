#include <iostream>

#include <fgeodatabase.hpp>
#include <dbmodel/crebasvisitor.hpp>

int main(int argc, char** argv) {
    Database* db = new FGeoDatabase("db");
    CrebasVisitor* v = new CrebasVisitor();
    db->visit(v);
    std::cout << std::endl << v->formattedResult() << std::endl;
    return 0;
}
