/* 
 * File:   BaseImpl.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 12:41 PM
 */

#ifndef UNIQUE_BASEIMPL_HPP
#define	UNIQUE_BASEIMPL_HPP

#include "unique/AbstractImpl.hpp"
#include "unique/Base.hpp"

namespace unique {

class Base::Impl : public Abstract::Impl {
protected:        
    const std::string str_base;
    
public:
    Impl(const std::string& str);

    virtual const std::string get_str() override;
};


} // namespace

#endif	/* UNIQUE_BASEIMPL_HPP */

