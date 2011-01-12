#ifndef MAPPING_H
#define MAPPING_H

class Table;

class Mapping {
public:
    Mapping(Table* t = 0);
    virtual ~Mapping();

    const bool hasTable() const;
    Table* table() const;
    void setTable(Table* t);

private:
    Mapping(const Mapping& o);
    
    Table* _table;
};

#endif // MAPPING_H
