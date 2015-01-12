/* 
 * File:   Base2.cpp
 * Author: alex
 * 
 * Created on October 4, 2014, 4:00 PM
 */

#include "staticlib/refobjects/refobjects_macros.hpp"
#include "refcount/Base2Impl.hpp"

namespace refcount {
using std::string;

Base2::Impl::Impl() :
Abstract::Impl() { }

REFOBJ_FORWARD_FUNCTION_CONST(Base2, const string, get_str_from_base2)

} // namespace        
