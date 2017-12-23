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
 * File:   abstract_impl.hpp
 * Author: alex
 *
 * Created on September 6, 2014, 11:45 AM
 */

#ifndef UNIQUE_ABSTRACT_IMPL_HPP
#define UNIQUE_ABSTRACT_IMPL_HPP

#include "unique/abstract.hpp"

namespace unique {

class abstract::impl : public sl::pimpl::object::impl {
protected:
    impl();

public:
    virtual std::string get_str(abstract& self) = 0;
};

} // namespace

#endif /* UNIQUE_ABSTRACT_IMPL_HPP */

