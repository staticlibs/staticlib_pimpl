/* 
 * File:   AbstractInherit.hpp
 * Author: alex
 *
 * Created on September 6, 2014, 11:45 AM
 */

#ifndef UNIQUE_ABSTRACTIMPL_HPP
#define	UNIQUE_ABSTRACTIMPL_HPP

#include "unique/Abstract.hpp"

namespace unique {

class Abstract::Impl : public PimplObject::Impl {
protected:
    Impl();

public:
    virtual const std::string get_str() = 0;
};

} // namespace

#endif	/* UNIQUE_ABSTRACTIMPL_HPP */

