/* 
 * File:   insertvisitor.hpp
 * Author: jolo
 *
 * Created on 13. Januar 2011, 17:26
 */

#ifndef INSERTVISITOR_HPP
#define	INSERTVISITOR_HPP

#include <orm/persistancevisitor.hpp>

class InsertVisitor: public PersistanceVisitor {
public:
    InsertVisitor();
    InsertVisitor(const InsertVisitor& o);
    virtual ~InsertVisitor();

    virtual void perform(Entity* e);
};


#endif	/* INSERTVISITOR_HPP */

