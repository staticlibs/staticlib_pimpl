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
 * File:   derived.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 2:22 PM
 */

#include "staticlib/pimpl/forward_macros.hpp"
#include "unique/test_exception.hpp"
#include "unique/intermediate.hpp"
#include "unique/intermediate_impl.hpp"
#include "unique/derived.hpp"

namespace unique {

class derived::impl : public intermediate::impl {
    const std::string str_derived;

public:
    impl(const std::string& str):
    intermediate::impl(str),
    str_derived(std::string("derived_").append(str)) { }

    virtual std::string get_str(abstract&) override {
        auto res = std::string();
        res.append("derived::");
        res.append(this->str_base);
        return res;
    }

    virtual std::string get_str_derived(derived&) {
        return str_derived;
    }
    
    void throw_something(derived&) {
        throw sl::pimpl::pimpl_exception(TRACEMSG("foo"));
    }
    
    std::string some_method_with_args(derived&, std::string arg1) {
        (void) arg1;
        return "foo";
    }

    std::string some_const_method_with_args(const derived&, std::string arg1, int arg2) const {
        (void) arg1;
        (void) arg2;
        return "foo";
    }

    std::string some_const_method_noargs(const derived&) const {
        return "foo";
    }
    
    void self_returning(derived&) {
        // some work with args
    }
};

PIMPL_FORWARD_CONSTRUCTOR(derived, (const std::string&), (), test_exception)

PIMPL_FORWARD_METHOD(derived, std::string, get_str_derived, (), (), test_exception)
PIMPL_FORWARD_METHOD(derived, void, throw_something, (), (), test_exception)
PIMPL_FORWARD_METHOD(derived, std::string, some_method_with_args, (std::string), (), test_exception)
PIMPL_FORWARD_METHOD(derived, std::string, some_const_method_with_args, (std::string)(int), (const), test_exception)
PIMPL_FORWARD_METHOD(derived, std::string, some_const_method_noargs, (), (const), test_exception)
PIMPL_FORWARD_METHOD_RETURN_SELF(derived, derived&, self_returning, (), (), test_exception)

} // namespace
