/* 
 * File:   test_RefCountObject.cpp
 * Author: alex
 * 
 * Created on October 3, 2014, 7:34 PM
 */

#include <vector>
#include <iostream>
#include <cassert>

#include "staticlib/refobjects/RefObjectEmptyException.hpp"

#include "refcount/Abstract.cpp"
#include "refcount/Base.cpp"
#include "refcount/Base2.cpp"
#include "refcount/Base3.cpp"
#include "refcount/Intermediate.cpp"
#include "refcount/Derived.cpp"

namespace { // anonymous

using std::vector;
using staticlib::refobjects::RefObjectMovedFromException;
using refcount::Abstract;
using refcount::Base;
using refcount::Base2;
using refcount::Intermediate;
using refcount::Derived;

void test_size() {
    // instantiation
    Base base = Base("foo");
    Intermediate intermediate = Intermediate("foo");
    Derived derived = Derived("foo");
    // size check
    std::cout << sizeof(base) << std::endl;
    std::cout << sizeof(intermediate) << std::endl;
    std::cout << sizeof(derived) << std::endl;
    // gcc/clang values, different on msvc
    //auto ptr_size = sizeof(void*);
    //assert(4*ptr_size == sizeof (base));
    //assert(6*ptr_size == sizeof (intermediate));
    //assert(6*ptr_size == sizeof (derived));
    assert(sizeof (base) < sizeof (intermediate));
    assert(sizeof (intermediate) <= sizeof (derived));
}

void test_polymorphic() {
    // instantiation
    Base base = Base("foo");
    Intermediate intermediate = Intermediate("foo");
    Derived derived = Derived("foo");
    // polymorphic calls
    assert("Base::foo" == base.get_str());
    assert("Intermediate::foo" == intermediate.get_str());
    assert("Derived::foo" == derived.get_str());
    assert("intermediate_foo" == intermediate.get_str_intermediate());
    assert("intermediate_foo" == derived.get_str_intermediate());
    assert("derived_foo" == derived.get_str_derived("f", 1));
    derived.do_something_derived(true);
    derived.get_str_derived_zeroarg();
}

void test_copy() {
    // instantiation
    Base base = Base("foo");
    Intermediate intermediate = Intermediate("foo");
    Derived derived = Derived("foo");
    // copy semantics
    auto vec = vector<Abstract>();
    vec.push_back(base);
    vec.push_back(intermediate);
    vec.push_back(derived);
    assert("Base::foo" == vec[0].get_str());
    assert("Intermediate::foo" == vec[1].get_str());
    assert("Derived::foo" == vec[2].get_str());
}

void test_downcast() {
    Derived derived = Derived("foo");
    auto vec = vector<Abstract>();
    vec.push_back(derived);
    // downcast
    Derived downcasted = Derived(vec[0].get_impl_ptr());
    assert("Derived::foo" == downcasted.get_str());
    assert("intermediate_foo" == downcasted.get_str_intermediate());
    assert("derived_foo" == downcasted.get_str_derived("f", 2));
}

void test_move() {
    // move semantics
    Intermediate source = Intermediate("bar");
    Intermediate move_constructed = std::move(source);
    assert("Intermediate::bar" == move_constructed.get_str());
    assert("intermediate_bar" == move_constructed.get_str_intermediate());
    bool catched = false;
    try {
        auto tmp = source.get_impl_ptr();
        (void) tmp;
    } catch (const RefObjectMovedFromException& e) {
        (void) e;
        catched = true;
    }
    assert(true == catched);
}

/*
void test_reflection() {
    // reflection
    Derived refl = Derived("refl");
    assert("Derived::refl" == refl.call_by_name("get_str"));
    assert("get_str_derived_zeroarg" == refl.call_by_name("get_str_derived_zeroarg"));
}
*/

void test_empty() {
    // use after move
    Base bmoved = Base("moveme");
    Base target = std::move(bmoved);
    (void) target;
    bool catched = false;
    try {
        std::cout << bmoved.get_str() << std::endl;
    } catch (const RefObjectMovedFromException& e) {
        (void) e;
        catched = true;
        // std::cout << "Caught exception from moved object" << std::endl;
    }
    assert(catched);
}

void test_forwarded_constructor() {
    // forwarded constructor
    Intermediate fwd = Intermediate("fwd", 42);
    assert("Intermediate::fwd42" == fwd.get_str());
    Intermediate noarg = Intermediate();
    assert("Intermediate::noarg" == noarg.get_str());
}

void takes_iface(Base2 b2) {
    assert("4242" == b2.get_str_from_base2());
}

void test_interfaces() {
    Derived der = Derived("foo");
    takes_iface(der);
}

} // namespace

int main() {
    test_size();
    test_polymorphic();
    test_copy();
    test_downcast();
    test_move();
    // disabled for msvc
    //test_reflection();
    test_empty();
    test_forwarded_constructor();
    test_interfaces();
    
    return 0;
}

