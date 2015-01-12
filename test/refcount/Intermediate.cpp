/* 
 * File:   Intermediate.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 12:04 PM
 */

#include "staticlib/refobjects/refobjects_macros.hpp"
#include "refcount/BaseImpl.hpp"
#include "refcount/Intermediate.hpp"
#include "refcount/IntermediateImpl.hpp"

namespace refcount {
using std::string;
using std::make_shared;
using std::to_string;


Intermediate::Impl::Impl(const string& str) : 
Base::Impl(str), str_intermediate(string("intermediate_").append(str)) { }
//Intermediate::Intermediate(const std::string& str) :
//Intermediate::Intermediate(make_shared<Intermediate::Impl>(str)) { }
REFOBJ_FORWARD_CONSTRUCTOR_REFCOUNT(Intermediate, (const string&))

Intermediate::Impl::Impl(const string& str, int32_t num) :
Base::Impl(str), str_intermediate(string("intermediate_").append(str)), num(num) { }
//Intermediate::Intermediate(const std::string& str, int32_t num) :
//Intermediate::Intermediate(make_shared<Intermediate::Impl>(str, num)) { }
REFOBJ_FORWARD_CONSTRUCTOR_REFCOUNT(Intermediate, (const string&) (int32_t))

Intermediate::Impl::Impl() :
Impl::Impl("noarg") { }
//Intermediate::Intermediate() :
//Intermediate::Intermediate(make_shared<Intermediate::Impl>()) { }
REFOBJ_FORWARD_CONSTRUCTOR_REFCOUNT_NOARG(Intermediate)

const string Intermediate::Impl::get_str() {
    string res = string();
    res.append("Intermediate::");    
    res.append(this->str_base);
    if (0 != this->num) {
        res.append(to_string(this->num));
    }
    return res;
}
REFOBJ_FORWARD_FUNCTION(Intermediate, const string, get_str)

const string Intermediate::Impl::get_str_intermediate() {
    return this->str_intermediate;
}
REFOBJ_FORWARD_FUNCTION(Intermediate, const string, get_str_intermediate)

const string Intermediate::Impl::get_str_from_base2() const {
    return "4242";
}
REFOBJ_FORWARD_FUNCTION_CONST(Intermediate, const string, get_str_from_base2)
        
const string Intermediate::Impl::get_str_from_base3() {
    return "4343";
}
REFOBJ_FORWARD_FUNCTION(Intermediate, const string, get_str_from_base3)
        
        
} // namespace

