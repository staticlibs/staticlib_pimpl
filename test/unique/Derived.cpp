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
 * File:   Derived.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 2:22 PM
 */

#include "staticlib/pimpl/pimpl_forward_macros.hpp"
#include "unique/TestException.hpp"
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

    virtual std::string get_str() override {
        string res = string();
        res.append("Derived::");
        res.append(this->str_base);
        return res;
    }

    virtual std::string get_str_derived() {
        return str_derived;
    }
    
    void throw_something() {
        throw staticlib::pimpl::PimplException(TRACEMSG("foo"));
    }
    
    std::string some_method_with_args(std::string arg1) {
        (void) arg1;
        return "foo";
    }

    std::string some_const_method_with_args(std::string arg1, int arg2) const {
        (void) arg1;
        (void) arg2;
        return "foo";
    }

    std::string some_const_method_noargs() const {
        return "foo";
    }
    
    void self_returning() {
        // some work with args
    }
};

PIMPL_FORWARD_CONSTRUCTOR(Derived, (const string&), (), TestException)

PIMPL_FORWARD_METHOD(Derived, string, get_str, (void), (), TestException)
PIMPL_FORWARD_METHOD(Derived, string, get_str_derived, (void), (), TestException)
PIMPL_FORWARD_METHOD(Derived, void, throw_something, (void), (), TestException)
PIMPL_FORWARD_METHOD(Derived, std::string, some_method_with_args, (std::string), (), TestException)
PIMPL_FORWARD_METHOD(Derived, std::string, some_const_method_with_args, (std::string)(int), (const), TestException)
PIMPL_FORWARD_METHOD(Derived, std::string, some_const_method_noargs, (void), (const), TestException)
PIMPL_FORWARD_METHOD_RETURN_SELF(Derived, Derived&, self_returning, (void), (), TestException)

} // namespace

