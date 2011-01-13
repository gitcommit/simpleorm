/* 
 * File:   standardentity.hpp
 * Author: jolo
 *
 * Created on 10. Januar 2011, 12:53
 */

#ifndef STANDARDENTITY_HPP
#define	STANDARDENTITY_HPP

#include <orm/namedentity.hpp>

class StandardEntity: public NamedEntity {
public:
    StandardEntity(Session* s, const Integer& id = 0, const String& name = "", const String& code = "", const String& description = "");
    StandardEntity(StandardEntity* p, const Integer& id = 0, const String& name = "", const String& code = "", const String& description = "");
    virtual ~StandardEntity();

    virtual const bool hasCode() const;
    virtual const bool hasDescription() const;
    virtual void setCode(const String& code);
    virtual void setDescription(const String& description);
    virtual String code() const;
    virtual String description() const;
    virtual String toString() const;

protected:
    virtual String codeInBrackets(const String& left = "{", const String& right = "}") const;
};

#endif	/* STANDARDENTITY_HPP */

