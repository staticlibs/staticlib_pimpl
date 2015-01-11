/* 
 * File:   BaseImpl.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 12:41 PM
 */

#ifndef REFCOUNT_BASEIMPL_HPP
#define	REFCOUNT_BASEIMPL_HPP

#include "refcount/AbstractImpl.hpp"
#include "refcount/Base.hpp"

namespace refcount {

class Base::Impl : public virtual Abstract::Impl {
protected:        
    const std::string str_base;
    
public:
    Impl(const std::string& str);

    virtual const std::string get_str() override;
};

} // namespace

#endif	/* REFCOUNT_BASEIMPL_HPP */

