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
 * File:   intermediate_impl.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 12:54 PM
 */

#ifndef UNIQUE_INTERMEDIATEIMPL_HPP
#define UNIQUE_INTERMEDIATEIMPL_HPP

#include "unique/base_impl.hpp"
#include "unique/intermediate.hpp"

namespace unique {

class intermediate::impl : public base::impl {
    const std::string str_intermediate;

public:
    impl(const std::string& str);

    virtual std::string get_str(abstract& self) override;

    virtual std::string get_str_intermediate(intermediate& self);

    virtual std::string get_str_from_base2(const intermediate& self) const;
};


} // namespace

#endif /* UNIQUE_INTERMEDIATEIMPL_HPP */

