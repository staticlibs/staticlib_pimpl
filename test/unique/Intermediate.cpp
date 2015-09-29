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
 * File:   Intermediate.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 12:04 PM
 */

#include "staticlib/pimpl/pimpl_forward_macros.hpp"
#include "unique/TestException.hpp"
#include "unique/IntermediateImpl.hpp"

namespace unique {

using std::string;

Intermediate::Impl::Impl(const string& str) : 
Base::Impl(str), str_intermediate(string("intermediate_").append(str)) { }
PIMPL_FORWARD_CONSTRUCTOR(Intermediate, (const string&), (), TestException)

string Intermediate::Impl::get_str() {
    string res = string();
    res.append("Intermediate::");
    res.append(this->str_base);
    return res;
}
PIMPL_FORWARD_METHOD(Intermediate, string, get_str, (void), (), TestException)

string Intermediate::Impl::get_str_intermediate() {
    return this->str_intermediate;
}
PIMPL_FORWARD_METHOD(Intermediate, string, get_str_intermediate, (void), (), TestException)

string Intermediate::Impl::get_str_from_base2() const {
    return "424242";
}
PIMPL_FORWARD_METHOD(Intermediate, string, get_str_from_base2, (void), (const), TestException)

string Intermediate::Impl::get_str_from_base3() {
    return "434343";
}
PIMPL_FORWARD_METHOD(Intermediate, string, get_str_from_base3, (void), (), TestException)

} // namespace

