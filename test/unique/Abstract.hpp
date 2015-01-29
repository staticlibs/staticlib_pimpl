/* 
 * File:   Asbtract.hpp
 * Author: alex
 *
 * Created on September 6, 2014, 11:44 AM
 */

#ifndef UNIQUE_ABSTRACT_HPP
#define	UNIQUE_ABSTRACT_HPP

#include <string>

#include "staticlib/pimpl.hpp"

namespace unique {

class Abstract : public staticlib::pimpl::PimplObject {
protected:    
    class Impl;
    
public:
	//    using staticlib::pimpl::PimplObject::PimplObject;
    PIMPL_CONSTRUCTOR(Abstract)

    virtual std::string get_str();
};

} // namespace

#endif	/* UNIQUE_ABSTRACT_HPP */

