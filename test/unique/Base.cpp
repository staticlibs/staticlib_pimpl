/* 
 * File:   Base.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 9:20 AM
 */

#include "staticlib/refobjects/refobjects_macros.hpp"
#include "unique/AbstractImpl.hpp"
#include "unique/Base.hpp"
#include "unique/BaseImpl.hpp"

namespace unique {

using std::string;

Base::Impl::Impl(const string& str) : 
Abstract::Impl(), str_base(str) { }
REFOBJ_FORWARD_CONSTRUCTOR(Base, (const string&))

const string Base::Impl::get_str() {
    string res = string();
    res.append("Base::");
    res.append(this->str_base);
    return res;
}
REFOBJ_FORWARD_FUNCTION(Base, const string, get_str)

} // namespace
