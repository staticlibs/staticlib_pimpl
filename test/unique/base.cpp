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

#include "staticlib/pimpl/forward_macros.hpp"
#include "unique/test_exception.hpp"
#include "unique/abstract_impl.hpp"
#include "unique/base.hpp"
#include "unique/base_impl.hpp"

namespace unique {

base::impl::impl(const std::string& str) :
abstract::impl(),
str_base(str) { }
PIMPL_FORWARD_CONSTRUCTOR(base, (const std::string&), (), test_exception)

// this method doesn't need to be forwarded to the
// corresponding method of facade class, because
// it is used only as an overloaded variant of
// pure virual method 'get_str', that is declared and
// forwarded to facade inside 'abstract_impl.hpp'
std::string base::impl::get_str(abstract&) {
    auto res = std::string();
    res.append("base::");
    res.append(this->str_base);
    return res;
}

} // namespace
