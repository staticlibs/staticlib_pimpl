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
 * File:   asbtract.cpp
 * Author: alex
 * 
 * Created on September 6, 2014, 11:44 AM
 */

#include "staticlib/pimpl/forward_macros.hpp"
#include "unique/test_exception.hpp"
#include "unique/abstract.hpp"
#include "unique/abstract_impl.hpp"

namespace unique {

using std::string;

abstract::impl::impl() :
object::impl() { }

PIMPL_FORWARD_METHOD(abstract, string, get_str, (), (), test_exception)

} // namespace