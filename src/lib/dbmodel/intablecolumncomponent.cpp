#include <dbmodel/intablecolumncomponent.hpp>

#include <dbmodel/tablecolumn.hpp>

InTableColumnComponent::InTableColumnComponent(TableColumn* p, const String& n)
: Component(p, n) {
}

InTableColumnComponent::InTableColumnComponent(const InTableColumnComponent& o)
: Component(o) {
}

InTableColumnComponent::~InTableColumnComponent() {
}

TableColumn* InTableColumnComponent::tableColumn() const {
    return dynamic_cast<TableColumn*> (parent());
}
