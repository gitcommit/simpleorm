/* 
 * File:   intablecolumncomponent.hpp
 * Author: jolo
 *
 * Created on 3. Januar 2011, 07:19
 */

#ifndef INTABLECOLUMNCOMPONENT_HPP
#define	INTABLECOLUMNCOMPONENT_HPP

#include <dbmodel/component.hpp>

class TableColumn;

class InTableColumnComponent: public Component {
public:
    InTableColumnComponent(TableColumn* p, const String& n);
    InTableColumnComponent(const InTableColumnComponent& o);
    virtual ~InTableColumnComponent();

    TableColumn* tableColumn() const;
};

#endif	/* INTABLECOLUMNCOMPONENT_HPP */

