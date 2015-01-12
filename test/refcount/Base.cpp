/* 
 * File:   Base.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 9:20 AM
 */

#include "staticlib/refobjects/refobjects_macros.hpp"
#include "refcount/Base.hpp"
#include "refcount/AbstractImpl.hpp"
#include "refcount/BaseImpl.hpp"

namespace refcount {
using std::string;

Base::Impl::Impl(const string& str) : 
Abstract::Impl(), str_base(str) { }
REFOBJ_FORWARD_CONSTRUCTOR_REFCOUNT(Base, (const string&))

const string Base::Impl::get_str() {
    string res = string();
    res.append("Base::");
    res.append(this->str_base);
    return res;
}
REFOBJ_FORWARD_FUNCTION(Base, const string, get_str)

} // namespace
