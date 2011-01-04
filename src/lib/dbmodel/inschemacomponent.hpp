/* 
 * File:   inschemacomponent.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 10:22
 */

#ifndef INSCHEMACOMPONENT_HPP
#define	INSCHEMACOMPONENT_HPP

#include <dbmodel/component.hpp>

class Schema;

class InSchemaComponent: public Component {
public:
    InSchemaComponent(Schema* s, const String& name);
    InSchemaComponent(const InSchemaComponent& o);
    virtual ~InSchemaComponent();
    Schema* schema() const;
    virtual String qualifiedName() const;
};

#endif	/* INSCHEMACOMPONENT_HPP */

