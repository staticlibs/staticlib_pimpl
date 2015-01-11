/* 
 * File:   AbstractImpl.hpp
 * Author: alex
 *
 * Created on July 2, 2014, 9:58 PM
 */

#ifndef REFCOUNT_ABSTRACTIMPL_HPP
#define	REFCOUNT_ABSTRACTIMPL_HPP

#include "refcount/Abstract.hpp"

namespace refcount {

class Abstract::Impl : public virtual RefCountObject::Impl {
protected:
    Impl();
    
public:
    virtual const std::string get_str() = 0;    
};

} // namespace

#endif	/* REFCOUNT_ABSTRACTIMPL_HPP */

