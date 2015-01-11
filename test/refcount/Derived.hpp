/* 
 * File:   Derived.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 2:22 PM
 */

#ifndef REFCOUNT_DERIVED_HPP
#define	REFCOUNT_DERIVED_HPP

#include "refcount/Intermediate.hpp"

namespace refcount {

class Derived : public virtual Intermediate {
protected:
    class Impl;
        
public:
//    Derived(std::shared_ptr<RefCountObject::Impl> pimpl) :
//    staticlib::refobjects::RefCountObject::RefCountObject(pimpl),
//    Abstract(pimpl),
//    Base2(pimpl),
//    Base3(pimpl),
//    Intermediate::Intermediate(pimpl) { }
    REFOBJ_INHERIT_CONSTRUCTOR_REFCOUNT(Derived, (staticlib::refobjects::RefCountObject)(Abstract) \
            (Base) (Base2)(Base3)(Intermediate))
    
    Derived(const std::string& str);
    
    virtual const std::string get_str() override;

    virtual const std::string get_str_derived(std::string foo, int bar);
    
    virtual const std::string get_str_derived_zeroarg();
    
    virtual void do_something_derived(bool bb);
    
    virtual std::string call_by_name(std::string);
};

} // namespace

#endif	/* REFCOUNT_DERIVED_HPP */

