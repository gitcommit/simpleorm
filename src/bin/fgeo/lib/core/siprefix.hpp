/* 
 * File:   siprefix.hpp
 * Author: jolo
 *
 * Created on 10. Januar 2011, 13:58
 */

#ifndef SIPREFIX_HPP
#define	SIPREFIX_HPP

#include <orm/standardentity.hpp>

class SiPrefix: public StandardEntity {
public:
    SiPrefix(Session* s, const String& name, const String& code,
            const String& symbol, const Numeric& factor, const String& description,
            const Integer& id = 0);
    virtual ~SiPrefix();

    virtual const bool hasSymbol() const;
    virtual const bool hasFactor() const;
    virtual void setSymbol(const String& s);
    virtual void setFactor(const Numeric& f);
    virtual String symbol() const;
    virtual Numeric factor() const;

    virtual String toString() const;
protected:
    virtual Mapping* createMapping();
private:
    String _symbol;
    Numeric _factor;
};

#endif	/* SIPREFIX_HPP */

