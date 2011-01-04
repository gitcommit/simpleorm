#include <dbmodel/intablecomponent.hpp>

#include <dbmodel/table.hpp>

InTableComponent::InTableComponent(Table* t, const String& name)
: Component(t, name) {
}

InTableComponent::InTableComponent(const InTableComponent& o)
: Component(o) {
}

InTableComponent::~InTableComponent() {
}

Table* InTableComponent::table() const {
    return dynamic_cast<Table*> (parent());
}

String InTableComponent::qualifiedName() const {
    return table()->name() + "." + name();
}
