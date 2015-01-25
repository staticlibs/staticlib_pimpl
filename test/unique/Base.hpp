/* 
 * File:   Base.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 9:20 AM
 */

#ifndef UNIQUE_BASE_HPP
#define	UNIQUE_BASE_HPP

#include "unique/Abstract.hpp"

namespace unique {

class Base : public Abstract {    
protected:        
    class Impl;
    
public:
//    using Abstract::Abstract;
    PIMPL_INHERIT_CONSTRUCTOR(Base, Abstract)
    
    Base(const std::string& str);
    
    virtual std::string get_str() override;
};

} // namespace

#endif	/* UNIQUE_BASE_HPP */

