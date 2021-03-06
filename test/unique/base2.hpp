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
 * File:   base2.hpp
 * Author: alex
 *
 * Created on October 4, 2014, 1:39 PM
 */

#ifndef UNIQUE_BASE2_HPP
#define UNIQUE_BASE2_HPP

namespace unique {

class base2 {
public:
    // addtional pure method implemented by 'intermediate'
    // may be called only if 'intermediate'
    // object is passed by reference/pointer
    virtual std::string get_str_from_base2() const = 0;
};

} // namespace

#endif /* UNIQUE_BASE2_HPP */

