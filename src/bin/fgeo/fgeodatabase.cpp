#include <fgeodatabase.hpp>

FGeoDatabase::FGeoDatabase(const std::string& name)
: Database(name) {

}

FGeoDatabase::FGeoDatabase(const FGeoDatabase& orig)
: Database(orig) {
}

FGeoDatabase::~FGeoDatabase() {
}

