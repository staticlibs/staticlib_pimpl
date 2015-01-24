/* 
 * File:   Asbtract.hpp
 * Author: alex
 *
 * Created on September 6, 2014, 11:44 AM
 */

#ifndef UNIQUE_ABSTRACT_HPP
#define	UNIQUE_ABSTRACT_HPP

#include <string>

#include "staticlib/pimpl/PimplObject.hpp"

namespace unique {

class Abstract : public staticlib::pimpl::PimplObject {
protected:    
    class Impl;
    
public:
	//    using staticlib::pimpl::PimplObject::PimplObject;
    PIMPL_INHERIT_CONSTRUCTOR(Abstract, staticlib::pimpl::PimplObject)

    virtual const std::string get_str();
};

} // namespace

#endif	/* UNIQUE_ABSTRACT_HPP */

