/* 
 * File:   Base3.hpp
 * Author: alex
 *
 * Created on October 4, 2014, 5:15 PM
 */

#ifndef REFCOUNT_BASE3_HPP
#define	REFCOUNT_BASE3_HPP

#include "refcount/Abstract.hpp"

namespace refcount {

class Base3 : public virtual Abstract {
protected:
    class Impl;

//    Base3(std::shared_ptr<RefCountObject::Impl> pimpl) :
//    staticlib::refobjects::RefCountObject::RefCountObject(pimpl),
//    Abstract::Abstract(pimpl) { }
    REFOBJ_INHERIT_CONSTRUCTOR_REFCOUNT(Base3, (staticlib::refobjects::RefCountObject)(Abstract))
public:

    virtual const std::string get_str_from_base3();
};

} // namespace


#endif	/* REFCOUNT_BASE3_HPP */

