/* 
 * File:   Base.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 9:20 AM
 */

#include "staticlib/pimpl/pimpl_forward_macros.hpp"
#include "unique/AbstractImpl.hpp"
#include "unique/Base.hpp"
#include "unique/BaseImpl.hpp"

namespace unique {

using std::string;

Base::Impl::Impl(const string& str) : 
Abstract::Impl(), str_base(str) { }
PIMPL_FORWARD_CONSTRUCTOR(Base, (const string&), ())

string Base::Impl::get_str() {
    string res = string();
    res.append("Base::");
    res.append(this->str_base);
    return res;
}
PIMPL_FORWARD_METHOD(Base, string, get_str, (void), ())

} // namespace
