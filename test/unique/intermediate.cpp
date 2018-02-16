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

intermediate::impl::impl(const std::string& str) : 
base::impl(str),
str_intermediate(std::string("intermediate_").append(str)) { }
PIMPL_FORWARD_CONSTRUCTOR(intermediate, (const std::string&), (), test_exception)

std::string intermediate::impl::get_str(abstract&) {
    auto res = std::string();
    res.append("intermediate::");
    res.append(this->str_base);
    return res;
}

std::string intermediate::impl::get_str_intermediate(intermediate&) {
    return this->str_intermediate;
}
PIMPL_FORWARD_METHOD(intermediate, std::string, get_str_intermediate, (), (), test_exception)

std::string intermediate::impl::get_str_from_base2(const intermediate&) const {
    return "424242";
}
PIMPL_FORWARD_METHOD(intermediate, std::string, get_str_from_base2, (), (const), test_exception)

} // namespace

