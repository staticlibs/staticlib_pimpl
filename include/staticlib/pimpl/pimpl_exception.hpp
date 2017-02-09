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
 * File:   pimpl_exception.hpp
 * Author: alex
 *
 * Created on October 3, 2014, 6:29 PM
 */

#ifndef STATICLIB_PIMPL_PIMPL_EXCEPTION_HPP
#define	STATICLIB_PIMPL_PIMPL_EXCEPTION_HPP

#include "staticlib/config/staticlib_exception.hpp"

namespace staticlib {
namespace pimpl {

/**
 * Module specific exception
 */
class pimpl_exception : public staticlib::config::staticlib_exception {
public:
    /**
     * Default constructor
     */
    pimpl_exception() = default;

    /**
     * Constructor with message
     * 
     * @param msg error message
     */
    pimpl_exception(const std::string& msg) :
    staticlib::config::staticlib_exception(msg) { }

};

} // namespace
}

#endif	/* STATICLIB_PIMPL_PIMPL_EXCEPTION_HPP */
