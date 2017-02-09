/*
 * Copyright 2015, alex at staticlibs.net
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   test_pimpl_object.cpp
 * Author: alex
 * 
 * Created on October 3, 2014, 7:35 PM
 */

#include "staticlib/pimpl/pimpl_object.hpp"

#include <iostream>
#include <vector>

#include "staticlib/config/assert.hpp"

#include "unique/abstract.cpp"
#include "unique/base.cpp"
#include "unique/intermediate.cpp"
#include "unique/derived.cpp"

namespace sp = staticlib::pimpl;
namespace uq = unique;

void test_size() {
    // instantiation
    uq::base base = uq::base("foo");
    uq::intermediate intermediate = uq::intermediate("foo");
    uq::derived derived = uq::derived("foo");
    // size check
//    std::cout << sizeof(base) << std::endl;
//    std::cout << sizeof(intermediate) << std::endl;
//    std::cout << sizeof(derived) << std::endl;
    auto ptr_size = sizeof(void*);
    slassert(2*ptr_size == sizeof (base));
    slassert(4*ptr_size == sizeof (intermediate));
    slassert(4*ptr_size == sizeof (derived));
}

void test_polymorphic() {
    // instantiation
    uq::base base = uq::base("foo");
    uq::intermediate intermediate = uq::intermediate("foo");
    uq::derived derived = uq::derived("foo");
    // polymorphic calls
    slassert("base::foo" == base.get_str());
    slassert("intermediate::foo" == intermediate.get_str());
    slassert("derived::foo" == derived.get_str());
    slassert("intermediate_foo" == intermediate.get_str_intermediate());
    slassert("intermediate_foo" == derived.get_str_intermediate());
    slassert("derived_foo" == derived.get_str_derived());
}

void test_nocopy() {
    // instantiation
    uq::base base = uq::base("foo");
    uq::intermediate intermediate = uq::intermediate("foo");
    uq::derived derived = uq::derived("foo");
    // lack of copy semantics
    auto vec = std::vector<uq::abstract>();
    vec.push_back(std::move(base));
    vec.push_back(std::move(intermediate));
    vec.push_back(std::move(derived));
    slassert("base::foo" == vec[0].get_str());
    slassert("intermediate::foo" == vec[1].get_str());
    slassert("derived::foo" == vec[2].get_str());
}

void test_downcast() {
    uq::derived derived = uq::derived("foo");
    auto vec = std::vector<uq::abstract>();
    vec.push_back(std::move(derived));
    // downcast, nullptr is required by internal pimpl_object constructor
    // to prevent "ambiguous" clash with other constructors
    uq::derived downcasted = uq::derived(nullptr, std::move(vec[0].get_impl_ptr()));
    slassert("derived::foo" == downcasted.get_str());
    slassert("intermediate_foo" == downcasted.get_str_intermediate());
    slassert("derived_foo" == downcasted.get_str_derived());
}

void test_move() {
    // move semantics
    uq::intermediate source = uq::intermediate("bar");
    uq::intermediate move_constructed = std::move(source);
    uq::intermediate moved = uq::intermediate("baz");
    moved = std::move(move_constructed);
    slassert("intermediate::bar" == moved.get_str());
    slassert("intermediate_bar" == moved.get_str_intermediate());
    bool catched_source = false;
    try {
        auto tmp = std::move(source.get_impl_ptr());
        (void) tmp;
    } catch (const sp::pimpl_exception&) {
        catched_source = true;
    }
    slassert(true == catched_source);
    bool catched_mc = false;
    try {
        auto tmp = std::move(move_constructed.get_impl_ptr());
        (void) tmp;
    } catch (const sp::pimpl_exception&) {
        catched_mc = true;
    }
    slassert(true == catched_mc);
}

void takes_iface(const uq::base2& b2) {
    slassert("424242" == b2.get_str_from_base2());
}

void test_interfaces() {
    uq::derived der = uq::derived("foo");
    takes_iface(der);
}

void test_stacktrace() {
    std::string expected{R"(foo
    at unique::derived::Impl::throw_something(derived.cpp:35)
    at unique::derived::throw_something(derived.cpp:47))"};
    bool catched = false;
    try {
        uq::derived der = uq::derived("foo");
        der.throw_something();
    } catch(const std::exception&) {
        catched = true;
//        slassert(expected == e.what());
    }
    slassert(catched);
}

int main() {
    try {
        test_size();
        test_polymorphic();
        test_nocopy();
        test_downcast();
        test_move();
        test_interfaces();
        test_stacktrace();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
