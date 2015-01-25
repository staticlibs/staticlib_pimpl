/* 
 * File:   IntermediateImpl.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 12:54 PM
 */

#ifndef UNIQUE_INTERMEDIATEIMPL_HPP
#define	UNIQUE_INTERMEDIATEIMPL_HPP

#include "unique/BaseImpl.hpp"
#include "unique/Intermediate.hpp"

namespace unique {

class Intermediate::Impl : public Base::Impl {
    const std::string str_intermediate;    
public:
    Impl(const std::string& str);

    virtual std::string get_str() override;
    
    virtual std::string get_str_intermediate();
    
    virtual std::string get_str_from_base2() const;
    
    virtual std::string get_str_from_base3();
};


} // namespace

#endif	/* UNIQUE_INTERMEDIATEIMPL_HPP */

