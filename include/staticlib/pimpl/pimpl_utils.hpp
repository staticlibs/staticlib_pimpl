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
 * File:   pimpl_utils.hpp
 * Author: alex
 *
 * Created on September 5, 2015, 6:54 PM
 */

#ifndef STATICLIB_PIMPL_UTILS_HPP
#define	STATICLIB_PIMPL_UTILS_HPP

#include <sstream>
#include <typeinfo>

#include "staticlib/pimpl/PimplException.hpp"

// https://github.com/boostorg/assert/blob/94ebde8bcff31752b7ffe7fcd58ad4d783bf958c/include/boost/current_function.hpp
#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
#define PIMPL_CURRENT_FUNCTION __PRETTY_FUNCTION__
#elif defined(__DMC__) && (__DMC__ >= 0x810)
#define PIMPL_CURRENT_FUNCTION __PRETTY_FUNCTION__
#elif defined(__FUNCSIG__)
#define PIMPL_CURRENT_FUNCTION __FUNCSIG__
#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
#define PIMPL_CURRENT_FUNCTION __FUNCTION__
#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
#define PIMPL_CURRENT_FUNCTION __FUNC__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#define PIMPL_CURRENT_FUNCTION __func__
#elif defined(__cplusplus) && (__cplusplus >= 201103)
#define PIMPL_CURRENT_FUNCTION __func__
#else
#define PIMPL_CURRENT_FUNCTION "(unknown)"
#endif

#define PIMPL_TRACEMSG(message) staticlib::pimpl::pimpl_tracemsg(message, __FILE__, PIMPL_CURRENT_FUNCTION, __LINE__)

namespace staticlib {
namespace pimpl {

/**
 * Prepends specified message with formatted current function name, source file name and line number.
 * Can be used through macro shortcut as `PIMPL_TRACEMSG("Hi")`
 * 
 * @param message input message
 * @param file source filename, `__FILE__` macro is used in `PIMPL_TRACEMSG` macro
 * @param func current function name, `PIMPL_CURRENT_FUNCTION` macro is used in `PIMPL_TRACEMSG` macro
 * @param line current line in source file, `__LINE__` macro is used in `PIMPL_TRACEMSG` macro
 * @return message string prepended with specified data
 */
std::string pimpl_tracemsg(const std::string& message, const std::string& file, const std::string& func, int line);

/**
 * Generic `to_string` implementation, already exists as `std::to_string`
 * in most C++11 compilers except GCC 4.8
 * 
 * @param t value to stringify
 * @return string representation of specified value
 */
template<typename T>
std::string pimpl_to_string(T t) {
    try {
        std::stringstream ss{};
        ss << t;
        return ss.str();
    } catch (const std::exception& e) {
        std::string tname{typeid (t).name()};
        throw PimplException(PIMPL_TRACEMSG(std::string(e.what()) +
                "\nError stringifying object, type: [" + tname + "]"));
    }
}

} // namespace
}

#endif	/* STATICLIB_PIMPL_UTILS_HPP */

