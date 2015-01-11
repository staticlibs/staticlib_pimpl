/* 
 * File:   Base2Impl.hpp
 * Author: alex
 *
 * Created on October 4, 2014, 4:00 PM
 */

#ifndef BASE2IMPL_HPP
#define	BASE2IMPL_HPP

#include "refcount/AbstractImpl.hpp"
#include "refcount/Base2.hpp"

namespace refcount {

class Base2::Impl : public virtual Abstract::Impl {
protected:
    Impl();    
    
public:

    virtual const std::string get_str_from_base2() const = 0;
};

} // namespace

#endif	/* BASE2IMPL_HPP */

