/* 
 * File:   Derived.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 2:22 PM
 */

#ifndef UNIQUE_DERIVED_HPP
#define	UNIQUE_DERIVED_HPP

#include "unique/Intermediate.hpp"

namespace unique {

class Derived : public Intermediate {
protected:    
    class Impl;

public:
//    using Intermediate::Intermediate;
    REFOBJ_INHERIT_CONSTRUCTOR(Derived, Intermediate)
    
    Derived(const std::string& str);
    
    virtual const std::string get_str() override;

    virtual const std::string get_str_derived();
    
    void throw_something();
};

} // namespace

#endif	/* UNIQUE_DERIVED_HPP */

