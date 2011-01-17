/* 
 * File:   MappedProperty.hpp
 * Author: jolo
 *
 * Created on 16. Januar 2011, 17:58
 */

#ifndef MAPPEDPROPERTY_HPP
#define	MAPPEDPROPERTY_HPP

#include <common/customtypes.hpp>

class Mapping;
class TableColumn;

class MappedProperty {
public:
    MappedProperty(Mapping* m, const String& propertyName, TableColumn* col);
    MappedProperty(const MappedProperty& o);
    virtual ~MappedProperty();

    virtual String propertyName() const;
    virtual TableColumn* column() const;
    virtual Mapping* mapping() const;
    virtual const bool hasColumn() const;
    virtual const bool hasMapping() const;

protected:
    virtual void setMapping(Mapping* m);
    
private:
    Mapping* _mapping;
    String _propertyName;
    TableColumn* _column;
};

#endif	/* MAPPEDPROPERTY_HPP */

