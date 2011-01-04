/* 
 * File:   sequence.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 10:21
 */

#ifndef SEQUENCE_HPP
#define	SEQUENCE_HPP

#include <dbmodel/inschemacomponent.hpp>

class Sequence: public InSchemaComponent {
public:
    Sequence(Schema* s, const String& name);
    Sequence(const Sequence& o);
    virtual ~Sequence();

    virtual void visit(ComponentVisitor* v);
};

typedef std::map<String, Sequence*> SequenceMap;
typedef SequenceMap::const_iterator SequenceMapConstIterator;

#endif	/* SEQUENCE_HPP */

