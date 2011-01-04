#include <dbmodel/inschemacomponent.hpp>
#include <dbmodel/schema.hpp>

InSchemaComponent::InSchemaComponent(Schema* s, const String& name)
: Component(s, name) {
}

InSchemaComponent::InSchemaComponent(const InSchemaComponent& o)
: Component(o) {
}

InSchemaComponent::~InSchemaComponent() {
}

Schema* InSchemaComponent::schema() const {
    return dynamic_cast<Schema*> (parent());
}

String InSchemaComponent::qualifiedName() const {
    return schema()->name() + "." + name();
}
