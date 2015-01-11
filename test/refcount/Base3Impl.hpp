/* 
 * File:   Base3Impl.hpp
 * Author: alex
 *
 * Created on October 4, 2014, 5:16 PM
 */

#ifndef REFCOUNT_BASE3IMPL_HPP
#define	REFCOUNT_BASE3IMPL_HPP

#include "refcount/AbstractImpl.hpp"
#include "refcount/Base3.hpp"

namespace refcount {

class Base3::Impl : public virtual Abstract::Impl {
protected:
    Impl();

public:

    virtual const std::string get_str_from_base3() = 0;
};

} // namespace


#endif	/* REFCOUNT_BASE3IMPL_HPP */

