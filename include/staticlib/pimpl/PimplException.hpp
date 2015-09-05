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
 * File:   PimplException.hpp
 * Author: alex
 *
 * Created on October 3, 2014, 6:29 PM
 */

#ifndef STATICLIB_PIMPLEXCEPTION_HPP
#define	STATICLIB_PIMPLEXCEPTION_HPP

#include <exception>

// http://stackoverflow.com/a/18387764/314015
#ifndef _MSC_VER
#define PIMPL_NOEXCEPT noexcept
#else
#define PIMPL_NOEXCEPT
#endif // _MSC_VER

namespace staticlib {
namespace pimpl {

/**
 * Module specific exception
 */
class PimplException : public std::exception {
    /**
     * Error message
     */
    std::string message;    
public:

    /**
     * Constructor with message
     * 
     * @param msg error message
     */
    PimplException(const std::string& msg) :
    message(msg) { }
    
    const char* what() const PIMPL_NOEXCEPT {
        return message.c_str();
    }

};

} // namespace
}

#endif	/* STATICLIB_PIMPLEXCEPTION_HPP */

