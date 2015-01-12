/* 
 * File:   Asbtract.cpp
 * Author: alex
 * 
 * Created on September 6, 2014, 11:44 AM
 */

#include "staticlib/refobjects/refobjects_macros.hpp"
#include "unique/Abstract.hpp"
#include "unique/AbstractImpl.hpp"

namespace unique {

using std::string;

Abstract::Impl::Impl() :
RefUniqueObject::Impl() { }

REFOBJ_FORWARD_FUNCTION(Abstract, const string, get_str)

} // namespace
