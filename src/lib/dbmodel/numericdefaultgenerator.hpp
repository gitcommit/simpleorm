/* 
 * File:   numericdefaultgenerator.hpp
 * Author: jolo
 *
 * Created on 3. Januar 2011, 12:52
 */

#ifndef NUMERICDEFAULTGENERATOR_HPP
#define	NUMERICDEFAULTGENERATOR_HPP

#include <dbmodel/defaultgenerator.hpp>

class NumericDefaultGenerator: public DefaultGenerator {
public:
    NumericDefaultGenerator(TableColumn* c, const Numeric& n);
    NumericDefaultGenerator(const NumericDefaultGenerator& o);
    virtual ~NumericDefaultGenerator();

    virtual String value() const;
private:
    Numeric _n;
};

#endif	/* NUMERICDEFAULTGENERATOR_HPP */

