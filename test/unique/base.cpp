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
 * File:   base.cpp
 * Author: alex
 * 
 * Created on July 1, 2014, 9:20 AM
 */

#include "staticlib/pimpl/pimpl_forward_macros.hpp"
#include "unique/test_exception.hpp"
#include "unique/abstract_impl.hpp"
#include "unique/base.hpp"
#include "unique/base_impl.hpp"

namespace unique {

using std::string;

base::impl::impl(const string& str) : 
abstract::impl(), str_base(str) { }
PIMPL_FORWARD_CONSTRUCTOR(base, (const string&), (), test_exception)

string base::impl::get_str(abstract& self) {
    (void) self;
    string res = string();
    res.append("base::");
    res.append(this->str_base);
    return res;
}
PIMPL_FORWARD_METHOD(base, string, get_str, (), (), test_exception)

} // namespace
