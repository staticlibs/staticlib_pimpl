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
 * File:   derived.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 2:22 PM
 */

#ifndef UNIQUE_DERIVED_HPP
#define UNIQUE_DERIVED_HPP

#include "unique/intermediate.hpp"

namespace unique {

class derived : public intermediate {
protected:    
    class impl;

public:
//    using intermediate::intermediate;
    PIMPL_INHERIT_CONSTRUCTOR(derived, intermediate)
    
    derived(const std::string& str);
    
    virtual std::string get_str() override;

    virtual std::string get_str_derived();
    
    std::string some_method_with_args(std::string arg1);
    
    std::string some_const_method_with_args(std::string arg1, int arg2) const;
    
    std::string some_const_method_noargs() const;
    
    void throw_something();
    
    derived& self_returning();
    
};

} // namespace

#endif /* UNIQUE_DERIVED_HPP */

