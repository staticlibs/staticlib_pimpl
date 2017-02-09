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

    virtual std::string get_str(Abstract& self) override {
        (void) self;
        string res = string();
        res.append("Derived::");
        res.append(this->str_base);
        return res;
    }

    virtual std::string get_str_derived(Derived& self) {
        (void) self;
        return str_derived;
    }
    
    void throw_something(Derived& self) {
        (void) self;
        throw staticlib::pimpl::pimpl_exception(TRACEMSG("foo"));
    }
    
    std::string some_method_with_args(Derived& self, std::string arg1) {
        (void) self;
        (void) arg1;
        return "foo";
    }

    std::string some_const_method_with_args(const Derived& self, std::string arg1, int arg2) const {
        (void) self;
        (void) arg1;
        (void) arg2;
        return "foo";
    }

    std::string some_const_method_noargs(const Derived& self) const {
        (void) self;
        return "foo";
    }
    
    void self_returning(Derived& self) {
        (void) self;
        // some work with args
    }
};

PIMPL_FORWARD_CONSTRUCTOR(Derived, (const string&), (), TestException)

PIMPL_FORWARD_METHOD(Derived, string, get_str, (), (), TestException)
PIMPL_FORWARD_METHOD(Derived, string, get_str_derived, (), (), TestException)
PIMPL_FORWARD_METHOD(Derived, void, throw_something, (), (), TestException)
PIMPL_FORWARD_METHOD(Derived, std::string, some_method_with_args, (std::string), (), TestException)
PIMPL_FORWARD_METHOD(Derived, std::string, some_const_method_with_args, (std::string)(int), (const), TestException)
PIMPL_FORWARD_METHOD(Derived, std::string, some_const_method_noargs, (), (const), TestException)
PIMPL_FORWARD_METHOD_RETURN_SELF(Derived, Derived&, self_returning, (), (), TestException)
        

} // namespace

