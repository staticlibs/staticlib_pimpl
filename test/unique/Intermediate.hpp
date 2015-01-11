/* 
 * File:   Intermediate.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 12:04 PM
 */

#ifndef UNIQUE_INTERMEDIATE_HPP
#define	UNIQUE_INTERMEDIATE_HPP

#include "unique/Base.hpp"
#include "unique/Base2.hpp"
#include "unique/Base3.hpp"

namespace unique {

class Intermediate : public Base, public Base2, public Base3 {
protected:    
    class Impl;
    
public:
//    using Base::Base;
    REFOBJ_INHERIT_CONSTRUCTOR(Intermediate, Base)
    
    Intermediate(const std::string& str);

    virtual const std::string get_str() override;

    virtual const std::string get_str_intermediate();
    
    virtual const std::string get_str_from_base2() const override;
    
    virtual const std::string get_str_from_base3() override;
};

} // namespace

#endif	/* UNIQUE_INTERMEDIATE_HPP */

