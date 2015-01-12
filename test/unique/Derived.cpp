/* 
 * File:   Derived.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 2:22 PM
 */

#include "staticlib/refobjects/refobjects_macros.hpp"
#include "unique/Intermediate.hpp"
#include "unique/IntermediateImpl.hpp"
#include "unique/Derived.hpp"

namespace unique {

using std::string;

class Derived::Impl : public Intermediate::Impl {
    const string str_derived;
public:
    Impl(const string& str):
    Intermediate::Impl(str), str_derived(string("derived_").append(str)) { }

    virtual const std::string get_str() override {
        string res = string();
        res.append("Derived::");
        res.append(this->str_base);
        return res;
    }

    virtual const std::string get_str_derived() {
        return str_derived;
    }
    
    void throw_something() {
        throw staticlib::refobjects::RefObjectException(TRACEMSG("foo"));
    }
};

REFOBJ_FORWARD_CONSTRUCTOR(Derived, (const string&))

REFOBJ_FORWARD_FUNCTION(Derived, const string, get_str)
REFOBJ_FORWARD_FUNCTION(Derived, const string, get_str_derived)
REFOBJ_FORWARD_FUNCTION(Derived, void, throw_something)

} // namespace

