/* 
 * File:   Asbtract.hpp
 * Author: alex
 *
 * Created on July 2, 2014, 9:56 PM
 */

#ifndef REFCOUNT_ABSTRACT_HPP
#define	REFCOUNT_ABSTRACT_HPP

#include <string>

#include "staticlib/refobjects/RefCountObject.hpp"
#include "staticlib/refobjects/refobjects_macros.hpp"

namespace refcount {

class Abstract : public virtual staticlib::refobjects::RefCountObject {        
protected:
    class Impl;

//    Abstract(std::shared_ptr<RefCountObject::Impl> pimpl) :
//    staticlib::refobjects::RefCountObject::RefCountObject(pimpl) { }    
    REFOBJ_INHERIT_CONSTRUCTOR_REFCOUNT(Abstract, (staticlib::refobjects::RefCountObject))
public:
    
    virtual const std::string get_str();
};

} // namespace

#endif	/* REFCOUNT_ABSTRACT_HPP */

