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
 * File:   intermediate.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 12:04 PM
 */

#include "staticlib/pimpl/forward_macros.hpp"
#include "unique/test_exception.hpp"
#include "unique/intermediate_impl.hpp"

namespace unique {

using std::string;

intermediate::impl::impl(const string& str) : 
base::impl(str), str_intermediate(string("intermediate_").append(str)) { }
PIMPL_FORWARD_CONSTRUCTOR(intermediate, (const string&), (), test_exception)

string intermediate::impl::get_str(abstract& self) {
    (void) self;
    string res = string();
    res.append("intermediate::");
    res.append(this->str_base);
    return res;
}
PIMPL_FORWARD_METHOD(intermediate, string, get_str, (), (), test_exception)

string intermediate::impl::get_str_intermediate(intermediate& self) {
    (void) self;
    return this->str_intermediate;
}
PIMPL_FORWARD_METHOD(intermediate, string, get_str_intermediate, (), (), test_exception)

string intermediate::impl::get_str_from_base2(const intermediate& self) const {
    (void) self;
    return "424242";
}
PIMPL_FORWARD_METHOD(intermediate, string, get_str_from_base2, (), (const), test_exception)

string intermediate::impl::get_str_from_base3(intermediate& self) {
    (void) self;
    return "434343";
}
PIMPL_FORWARD_METHOD(intermediate, string, get_str_from_base3, (), (), test_exception)

} // namespace

