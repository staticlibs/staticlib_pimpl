/* 
 * File:   Abstract.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 9:20 AM
 */

#include "staticlib/refobjects/refobjects_macros.hpp"
#include "refcount/Abstract.hpp"
#include "AbstractImpl.hpp"

namespace refcount {
using std::string;


Abstract::Impl::Impl():
RefCountObject::Impl() { }

REFOBJ_FORWARD_FUNCTION(const string, Abstract, get_str)

} // namespace
