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
 * File:   base.hpp
 * Author: alex
 *
 * Created on July 1, 2014, 9:20 AM
 */

#ifndef UNIQUE_BASE_HPP
#define	UNIQUE_BASE_HPP

#include "unique/abstract.hpp"

namespace unique {

class base : public abstract {    
protected:        
    class impl;
    
public:
//    using abstract::abstract;
    PIMPL_INHERIT_CONSTRUCTOR(base, abstract)
    
    base(const std::string& str);
    
    virtual std::string get_str() override;
};

} // namespace

#endif	/* UNIQUE_BASE_HPP */

