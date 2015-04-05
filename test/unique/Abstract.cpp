/* 
 * File:   Asbtract.cpp
 * Author: alex
 * 
 * Created on September 6, 2014, 11:44 AM
 */

#include "staticlib/pimpl/pimpl_forward_macros.hpp"
#include "unique/Abstract.hpp"
#include "unique/AbstractImpl.hpp"

namespace unique {

using std::string;

Abstract::Impl::Impl() :
PimplObject::Impl() { }

PIMPL_FORWARD_METHOD(Abstract, string, get_str, (void), ())

} // namespace
