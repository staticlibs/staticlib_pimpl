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
 * File:   base_impl.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 12:41 PM
 */

#ifndef UNIQUE_BASE_IMPL_HPP
#define UNIQUE_BASE_IMPL_HPP

#include "unique/abstract_impl.hpp"
#include "unique/base.hpp"

namespace unique {

class base::impl : public abstract::impl {
protected:
    const std::string str_base;

public:
    impl(const std::string& str);

    virtual std::string get_str(abstract& self) override;
};


} // namespace

#endif /* UNIQUE_BASE_IMPL_HPP */

