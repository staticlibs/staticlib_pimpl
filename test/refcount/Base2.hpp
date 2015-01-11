/* 
 * File:   Base2.hpp
 * Author: alex
 *
 * Created on October 4, 2014, 4:00 PM
 */

#ifndef REFCOUNT_BASE2_HPP
#define	REFCOUNT_BASE2_HPP

#include "refcount/Abstract.hpp"

namespace refcount {

class Base2 : public virtual Abstract {
protected:
    class Impl;

//    Base2(std::shared_ptr<RefCountObject::Impl> pimpl) :
//    staticlib::refobjects::RefCountObject::RefCountObject(pimpl),
//    Abstract::Abstract(pimpl) { }
    REFOBJ_INHERIT_CONSTRUCTOR_REFCOUNT(Base2, (staticlib::refobjects::RefCountObject)(Abstract))
public:

    virtual const std::string get_str_from_base2() const;
};

} // namespace

#endif	/* REFCOUNT_BASE2_HPP */

