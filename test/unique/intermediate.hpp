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
 * File:   intermediate.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 12:04 PM
 */

#ifndef UNIQUE_INTERMEDIATE_HPP
#define UNIQUE_INTERMEDIATE_HPP

#include "unique/base.hpp"
#include "unique/base2.hpp"

namespace unique {

class intermediate : public base, public base2 {
protected:
    class impl;

public:
//    using base::base;
    PIMPL_INHERIT_CONSTRUCTOR(intermediate, base)

    intermediate(const std::string& str);

    virtual std::string get_str_intermediate();

    virtual std::string get_str_from_base2() const override;
};

} // namespace

#endif /* UNIQUE_INTERMEDIATE_HPP */

