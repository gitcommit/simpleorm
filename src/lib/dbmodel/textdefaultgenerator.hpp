/* 
 * File:   textdefaultgenerator.hpp
 * Author: jolo
 *
 * Created on 3. Januar 2011, 13:01
 */

#ifndef TEXTDEFAULTGENERATOR_HPP
#define	TEXTDEFAULTGENERATOR_HPP

#include <dbmodel/defaultgenerator.hpp>

class TextDefaultGenerator: public DefaultGenerator {
public:
    TextDefaultGenerator(TableColumn* c, const String& s);
    TextDefaultGenerator(const TextDefaultGenerator& o);
    virtual ~TextDefaultGenerator();

    virtual String value() const;
private:
    String _str;
};
#endif	/* TEXTDEFAULTGENERATOR_HPP */

