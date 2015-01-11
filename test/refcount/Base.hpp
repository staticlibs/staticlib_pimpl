/* 
 * File:   Base.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 9:20 AM
 */

#ifndef REFCOUNT_BASE_HPP
#define	REFCOUNT_BASE_HPP

#include "staticlib/refobjects/refobjects_macros.hpp"

#include "refcount/Abstract.hpp"

namespace refcount {

class Base : public virtual Abstract {    
protected:    
    class Impl;

public:
//    Base(std::shared_ptr<RefCountObject::Impl> pimpl) :
//    staticlib::refobjects::RefCountObject::RefCountObject(pimpl),
//    Abstract::Abstract(pimpl) 
//    { }
    REFOBJ_INHERIT_CONSTRUCTOR_REFCOUNT(Base, (staticlib::refobjects::RefCountObject)(Abstract))
    
    Base(const std::string& str);
    
    virtual const std::string get_str() override;
};

} // namespace

#endif	/* REFCOUNT_BASE_HPP */

