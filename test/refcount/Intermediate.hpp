/* 
 * File:   Intermediate.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 12:04 PM
 */

#ifndef REFCOUNT_INTERMEDIATE_HPP
#define	REFCOUNT_INTERMEDIATE_HPP

#include "refcount/Base.hpp"
#include "refcount/Base2.hpp"
#include "refcount/Base3.hpp"

namespace refcount {

class Intermediate : public virtual Base, public virtual Base2, public virtual Base3 {
protected:
    class Impl;

public:
//    Intermediate(std::shared_ptr<RefCountObject::Impl> pimpl) :
//    staticlib::refobjects::RefCountObject::RefCountObject(pimpl),
//    Abstract(pimpl),
//    Base2::Base2(pimpl),
//    Base3::Base3(pimpl),
//    Base::Base(pimpl) { }
    REFOBJ_INHERIT_CONSTRUCTOR_REFCOUNT(Intermediate, (staticlib::refobjects::RefCountObject)(Abstract) \
            (Base) (Base2) (Base3) )
    
    Intermediate();
    
    Intermediate(const std::string& str);
    
    Intermediate(const std::string& str, int32_t num);

    virtual const std::string get_str() override;

    virtual const std::string get_str_intermediate();
    
    virtual const std::string get_str_from_base2() const override;
    
    virtual const std::string get_str_from_base3() override;
};

} // namespace

#endif	/* REFCOUNT_INTERMEDIATE_HPP */

