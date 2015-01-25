/* 
 * File:   Intermediate.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 12:04 PM
 */

#include "staticlib/pimpl/pimpl_forward_macros.hpp"
#include "unique/IntermediateImpl.hpp"

namespace unique {

using std::string;

Intermediate::Impl::Impl(const string& str) : 
Base::Impl(str), str_intermediate(string("intermediate_").append(str)) { }
PIMPL_FORWARD_CONSTRUCTOR(Intermediate, (const string&), ())

string Intermediate::Impl::get_str() {
    string res = string();
    res.append("Intermediate::");
    res.append(this->str_base);
    return res;
}
PIMPL_FORWARD_METHOD(Intermediate, string, get_str, ())

string Intermediate::Impl::get_str_intermediate() {
    return this->str_intermediate;
}
PIMPL_FORWARD_METHOD(Intermediate, string, get_str_intermediate, ())

string Intermediate::Impl::get_str_from_base2() const {
    return "424242";
}
PIMPL_FORWARD_METHOD(Intermediate, string, get_str_from_base2, (const))

string Intermediate::Impl::get_str_from_base3() {
    return "434343";
}
PIMPL_FORWARD_METHOD(Intermediate, string, get_str_from_base3, ())

} // namespace

