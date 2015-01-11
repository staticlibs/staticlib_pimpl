/* 
 * File:   Base3.cpp
 * Author: alex
 * 
 * Created on October 4, 2014, 5:15 PM
 */

#include "staticlib/refobjects/refobjects_macros.hpp"
#include "refcount/Base3Impl.hpp"

namespace refcount {
using std::string;

Base3::Impl::Impl() :
Abstract::Impl() { }

REFOBJ_FORWARD_FUNCTION(const string, Base3, get_str_from_base3)

} // namespace     
