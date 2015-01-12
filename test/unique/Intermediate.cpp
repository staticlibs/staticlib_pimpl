/* 
 * File:   Intermediate.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 12:04 PM
 */

#include "staticlib/refobjects/refobjects_macros.hpp"
#include "unique/IntermediateImpl.hpp"

namespace unique {

using std::string;

Intermediate::Impl::Impl(const string& str) : 
Base::Impl(str), str_intermediate(string("intermediate_").append(str)) { }
REFOBJ_FORWARD_CONSTRUCTOR(Intermediate, (const string&))

const string Intermediate::Impl::get_str() {
    string res = string();
    res.append("Intermediate::");
    res.append(this->str_base);
    return res;
}
REFOBJ_FORWARD_FUNCTION(Intermediate, const string, get_str)

const string Intermediate::Impl::get_str_intermediate() {
    return this->str_intermediate;
}
REFOBJ_FORWARD_FUNCTION(Intermediate, const string, get_str_intermediate)

const string Intermediate::Impl::get_str_from_base2() const {
    return "424242";
}
REFOBJ_FORWARD_FUNCTION_CONST(Intermediate, const string, get_str_from_base2)

const string Intermediate::Impl::get_str_from_base3() {
    return "434343";
}
REFOBJ_FORWARD_FUNCTION(Intermediate, const string, get_str_from_base3)

} // namespace

