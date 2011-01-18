#ifndef MAPPING_H
#define MAPPING_H

#include <map>

#include <common/customtypes.hpp>

class MappedProperty;
class Table;
class TableColumn;

class Mapping {
public:
    Mapping(Table* t = 0);
    virtual ~Mapping();

    const bool hasTable() const;
    Table* table() const;
    void setTable(Table* t);

    MappedProperty* createProperty(const String& propertyName, TableColumn* col);
    MappedProperty* add(MappedProperty* p);
    virtual const bool hasMappedProperty(const String& propertyName) const;
    virtual const bool hasMappedProperty(TableColumn* col) const;
    MappedProperty* mappedProperty(const String& propertyName) const;
    std::map<String, MappedProperty*> mappedPropertiesMap() const;
    StringVector propertyNames() const;
    std::vector<MappedProperty*> mappedProperties() const;
private:
    Mapping(const Mapping& o);
    
    Table* _table;
    std::map<String, MappedProperty*> _mappedProperties;
};

#endif // MAPPING_H
