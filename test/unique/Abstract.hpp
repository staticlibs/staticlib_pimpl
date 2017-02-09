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
 * File:   Asbtract.hpp
 * Author: alex
 *
 * Created on September 6, 2014, 11:44 AM
 */

#ifndef UNIQUE_ABSTRACT_HPP
#define	UNIQUE_ABSTRACT_HPP

#include <string>

#include "staticlib/pimpl.hpp"

namespace unique {

class Abstract : public staticlib::pimpl::pimpl_object {
protected:    
    class Impl;
    
public:
	//    using staticlib::pimpl::pimpl_object::pimpl_object;
    PIMPL_CONSTRUCTOR(Abstract)

    virtual std::string get_str();
};

} // namespace

#endif	/* UNIQUE_ABSTRACT_HPP */

