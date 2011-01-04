/* 
 * File:   sequencedefaultgenerator.hpp
 * Author: jolo
 *
 * Created on 1. Januar 2011, 14:24
 */

#ifndef SEQUENCEDEFAULTGENERATOR_HPP
#define	SEQUENCEDEFAULTGENERATOR_HPP

#include <dbmodel/defaultgenerator.hpp>

class Sequence;

class SequenceDefaultGenerator: public DefaultGenerator {
public:
    SequenceDefaultGenerator(TableColumn* col, Sequence* s);
    SequenceDefaultGenerator(const SequenceDefaultGenerator& o);
    virtual ~SequenceDefaultGenerator();

    virtual String value() const;
private:
    Sequence* _s;
};

#endif	/* SEQUENCEDEFAULTGENERATOR_HPP */

