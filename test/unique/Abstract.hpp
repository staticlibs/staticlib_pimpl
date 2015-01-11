/* 
 * File:   Asbtract.hpp
 * Author: alex
 *
 * Created on September 6, 2014, 11:44 AM
 */

#ifndef UNIQUE_ABSTRACT_HPP
#define	UNIQUE_ABSTRACT_HPP

#include <string>

#include "staticlib/refobjects/RefUniqueObject.hpp"

namespace unique {

class Abstract : public staticlib::refobjects::RefUniqueObject {
protected:    
    class Impl;
    
public:
	//    using staticlib::refobjects::RefUniqueObject::RefUniqueObject;
	REFOBJ_INHERIT_CONSTRUCTOR(Abstract, staticlib::refobjects::RefUniqueObject)

    virtual const std::string get_str();
};

} // namespace

#endif	/* UNIQUE_ABSTRACT_HPP */

