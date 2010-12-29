
#include <database.hpp>

Database::Database(const String& name)
: Component(name) {
}

Database::Database(const Database& orig)
: Component(orig) {
}

Database::~Database() {
}

