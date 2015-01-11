/* 
 * File:   IntermediateImpl.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 12:54 PM
 */

#ifndef REFCOUNT_INTERMEDIATEIMPL_HPP
#define	REFCOUNT_INTERMEDIATEIMPL_HPP

#include "refcount/BaseImpl.hpp"
#include "refcount/Base2Impl.hpp"
#include "refcount/Base3Impl.hpp"
#include "refcount/Intermediate.hpp"

namespace refcount {

class Intermediate::Impl : public virtual Base::Impl, public virtual Base2::Impl, public virtual Base3::Impl {
    const std::string str_intermediate;
    int32_t num = 0;
    
public:
    Impl();
    
    Impl(const std::string& str);
    
    Impl(const std::string& str, int32_t num);

    virtual const std::string get_str() override;
    
    virtual const std::string get_str_intermediate();
    
    virtual const std::string get_str_from_base2() const override;
    
    virtual const std::string get_str_from_base3() override;
};


} // namespace

#endif	/* REFCOUNT_INTERMEDIATEIMPL_HPP */

