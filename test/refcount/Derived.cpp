/* 
 * File:   Derived.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 2:22 PM
 */

#include <unordered_map>

#include "staticlib/refobjects/refobjects_macros.hpp"
#include "refcount/Intermediate.hpp"
#include "refcount/IntermediateImpl.hpp"
#include "refcount/Derived.hpp"

namespace refcount {
using std::string;
using std::make_shared;
using std::unordered_map;
//using std::function;

class Derived::Impl : public virtual Intermediate::Impl {
    const string str_derived;
//    unordered_map<string, function<const string(Impl*)>> func_map;    
public:
    Impl(const string& str):
    Base::Impl(str),
	Intermediate::Impl(str), str_derived(string("derived_").append(str)) { }
//    func_map({
//        {"get_str", &Impl::get_str},
//        {"get_str_derived_zeroarg", &Impl::get_str_derived_zeroarg}
//    }) { }

    virtual const std::string get_str() override {
        string res = string();
        res.append("Derived::");
        res.append(this->str_base);
        return res;
    }

    virtual const std::string get_str_derived(string foo, int bar) {
        (void) foo;
        (void) bar;
        return str_derived;
    }
    
    virtual const std::string get_str_derived_zeroarg() {
        return "get_str_derived_zeroarg";
    }
    
    virtual void do_something_derived(bool bb) {
        (void) bb;
    }

    virtual std::string call_by_name(string name) {
        (void) name;
		return "disabled for MSVC";
//        return this->func_map[name](this);
    }

};

Derived::Derived(const string& str) :
Derived::Derived(make_shared<Derived::Impl>(str)) { }
//REFOBJ_FORWARD_CONSTRUCTOR_REFCOUNT(Derived, (const string&))

REFOBJ_FORWARD_FUNCTION(Derived, const string , get_str)
REFOBJ_FORWARD_FUNCTION(Derived, const string, get_str_derived, (string) (int))
REFOBJ_FORWARD_FUNCTION(Derived, const string, get_str_derived_zeroarg)
REFOBJ_FORWARD_FUNCTION(Derived, void, do_something_derived, (bool))
REFOBJ_FORWARD_FUNCTION(Derived, string, call_by_name, (string))

} // namespace

