#include <dbmodel/indatabasecomponent.hpp>

#include <dbmodel/database.hpp>

InDatabaseComponent::InDatabaseComponent(Database* db, const String& name)
: Component(db, name) {

}

InDatabaseComponent::InDatabaseComponent(const InDatabaseComponent& orig)
: Component(orig) {
}

InDatabaseComponent::~InDatabaseComponent() {
}

Database* InDatabaseComponent::database() const {
    return dynamic_cast<Database*>(parent());
}