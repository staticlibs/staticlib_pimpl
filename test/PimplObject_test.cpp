/* 
 * File:   test_PimplObject.cpp
 * Author: alex
 * 
 * Created on October 3, 2014, 7:35 PM
 */

#include <iostream>
#include <vector>
#include <cassert>

#include "staticlib/pimpl/PimplException.hpp"

#include "unique/Abstract.cpp"
#include "unique/Base.cpp"
#include "unique/Intermediate.cpp"
#include "unique/Derived.cpp"

namespace { // anonymous

using std::vector;
using staticlib::pimpl::PimplException;
using unique::Abstract;
using unique::Base;
using unique::Base2;
using unique::Intermediate;
using unique::Derived;

void test_size() {
    // instantiation
    Base base = Base("foo");
    Intermediate intermediate = Intermediate("foo");
    Derived derived = Derived("foo");
    // size check
//    std::cout << sizeof(base) << std::endl;
//    std::cout << sizeof(intermediate) << std::endl;
//    std::cout << sizeof(derived) << std::endl;
    auto ptr_size = sizeof(void*);
    (void) ptr_size;
    assert(2*ptr_size == sizeof (base));
    assert(4*ptr_size == sizeof (intermediate));
    assert(4*ptr_size == sizeof (derived));
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
    assert("derived_foo" == derived.get_str_derived());
}

void test_nocopy() {
    // instantiation
    Base base = Base("foo");
    Intermediate intermediate = Intermediate("foo");
    Derived derived = Derived("foo");
    // lack of copy semantics
    auto vec = vector<Abstract>();
    vec.push_back(std::move(base));
    vec.push_back(std::move(intermediate));
    vec.push_back(std::move(derived));
    assert("Base::foo" == vec[0].get_str());
    assert("Intermediate::foo" == vec[1].get_str());
    assert("Derived::foo" == vec[2].get_str());
}

void test_downcast() {
    Derived derived = Derived("foo");
    auto vec = vector<Abstract>();
    vec.push_back(std::move(derived));
    // downcast
    Derived downcasted = Derived(std::move(vec[0].get_impl_ptr()));
    assert("Derived::foo" == downcasted.get_str());
    assert("intermediate_foo" == downcasted.get_str_intermediate());
    assert("derived_foo" == downcasted.get_str_derived());
}

void test_move() {
    // move semantics
    Intermediate source = Intermediate("bar");
    Intermediate move_constructed = std::move(source);
    Intermediate moved = Intermediate("baz");
    moved = std::move(move_constructed);
    assert("Intermediate::bar" == moved.get_str());
    assert("intermediate_bar" == moved.get_str_intermediate());
    bool catched_source = false;
    try {
        auto tmp = std::move(source.get_impl_ptr());
        (void) tmp;
    } catch (const PimplException& e) {
        (void) e;
        catched_source = true;
    }
    assert(true == catched_source);
    bool catched_mc = false;
    try {
        auto tmp = std::move(move_constructed.get_impl_ptr());
        (void) tmp;
    } catch (const PimplException& e) {
        (void) e;
        catched_mc = true;
    }
    assert(true == catched_mc);
}

void takes_iface(const Base2& b2) {
    (void) b2;
    assert("424242" == b2.get_str_from_base2());
}

void test_interfaces() {
    Derived der = Derived("foo");
    takes_iface(der);
}

void test_stacktrace() {
    std::string expected{R"(foo
    at unique::Derived::Impl::throw_something(Derived.cpp:35)
    at unique::Derived::throw_something(Derived.cpp:47))"};
    bool catched = false;
    try {
        Derived der = Derived("foo");
        der.throw_something();
    } catch(const std::exception& e) {
        catched = true;
//        assert(expected == e.what());
    }
    assert(catched);
}

void test_to_string() {
    Derived der = Derived("foo");
    auto st = der.to_string();
    assert("I am derived" == st);
}

} // namespace

int main() {
    test_size();
    test_polymorphic();
    test_nocopy();
    test_downcast();
    test_move();
    test_interfaces();
    test_stacktrace();
    test_to_string();
    
    return 0;
}
