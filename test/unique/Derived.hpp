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
    PIMPL_INHERIT_CONSTRUCTOR(Derived, Intermediate)
    
    Derived(const std::string& str);
    
    virtual std::string get_str() override;

    virtual std::string get_str_derived();
    
    std::string some_method_with_args(std::string arg1);
    
    std::string some_const_method_with_args(std::string arg1, int arg2) const;
    
    std::string some_const_method_noargs() const;
    
    void throw_something();
};

} // namespace

#endif	/* UNIQUE_DERIVED_HPP */

