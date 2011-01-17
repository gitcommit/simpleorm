/* 
 * File:   custom_types.hpp
 * Author: jolo
 *
 * Created on 29. Dezember 2010, 17:27
 */

#ifndef CUSTOM_TYPES_HPP
#define	CUSTOM_TYPES_HPP

#include <string>
#include <sstream>
#include <vector>

typedef std::string String;
typedef std::vector<String> StringVector;
typedef StringVector::const_iterator StringVectorConstIterator;
typedef StringVector::iterator StringVectorIterator;
typedef std::stringstream StringStream;
typedef double Numeric;
typedef long unsigned int Integer;

#endif	/* CUSTOM_TYPES_HPP */

