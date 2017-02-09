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
 * File:   pimpl_forward_macros.hpp
 * Author: alex
 *
 * Created on September 10, 2014, 8:33 PM
 */

#ifndef STATICLIB_PIMPL_PIMPL_FORWARD_MACROS_HPP
#define	STATICLIB_PIMPL_PIMPL_FORWARD_MACROS_HPP

#include <memory>
#include <utility>

#include "staticlib/config.hpp"

#ifdef STATICLIB_WINDOWS
//http://lists.boost.org/boost-users/2014/11/83291.php
#pragma warning (disable: 4003)
#endif // STATICLIB_WINDOWS

#include "staticlib/pimpl/pimpl_exception.hpp"
#include "staticlib/pimpl/ext_preprocessor/ext_preprocessor.hpp"

#define PIMPL_FORWARD_INTERNAL_RET_TYPE_void 1)(1
#define PIMPL_FORWARD_INTERNAL_EMPTY_TYPE_ 1)(1
#define PIMPL_FORWARD_INTERNAL_IS_NOT_VOID(type) STATICLIB_PP_EQUAL(STATICLIB_PP_SEQ_SIZE((PIMPL_FORWARD_INTERNAL_RET_TYPE_##type)),1)
#define PIMPL_FORWARD_INTERNAL_IS_NOT_EMPTY(type) STATICLIB_PP_EQUAL(STATICLIB_PP_SEQ_SIZE((PIMPL_FORWARD_INTERNAL_EMPTY_TYPE_##type)),1)

#define PIMPL_FORWARD_INTERNAL_PARAMS(r, data, i, elem) STATICLIB_PP_IF(PIMPL_FORWARD_INTERNAL_IS_NOT_EMPTY(elem), (elem p##i), ())
#define PIMPL_FORWARD_INTERNAL_ARGS_PASS(r, data, i, elem) STATICLIB_PP_IF(PIMPL_FORWARD_INTERNAL_IS_NOT_EMPTY(elem), (std::forward<elem>(p##i)), ())
#define PIMPL_FORWARD_INTERNAL_MODIFIERS(r, data, i, elem) (elem)
#define PIMPL_FORWARD_INTERNAL_EMPTY_CONV(r, data, i, elem) STATICLIB_PP_IF(PIMPL_FORWARD_INTERNAL_IS_NOT_EMPTY(elem), (2), (1))

#define PIMPL_FORWARD_INTERNAL_CREATE_PARAMS_LIST(PARAMS) STATICLIB_PP_SEQ_ENUM(STATICLIB_PP_SEQ_FOR_EACH_I(PIMPL_FORWARD_INTERNAL_PARAMS,_,PARAMS))
#define PIMPL_FORWARD_INTERNAL_CREATE_ARG_PASS_LIST(PARAMS) STATICLIB_PP_SEQ_ENUM(STATICLIB_PP_SEQ_FOR_EACH_I(PIMPL_FORWARD_INTERNAL_ARGS_PASS, _, PARAMS))      
#define PIMPL_FORWARD_INTERNAL_CREATE_MODIFIERS_LIST(MODIFIERS) STATICLIB_PP_SEQ_ENUM(STATICLIB_PP_SEQ_FOR_EACH_I(PIMPL_FORWARD_INTERNAL_MODIFIERS, _, MODIFIERS))      
#define PIMPL_FORWARD_INTERNAL_CREATE_RETURN(method_return) STATICLIB_PP_EXPR_IF(PIMPL_FORWARD_INTERNAL_IS_NOT_VOID(method_return),return)
#define PIMPL_FORWARD_INTERNAL_NOT_EMPTY_ARGS(PARAMS) STATICLIB_PP_NOT_EQUAL(1, STATICLIB_PP_SEQ_ELEM(0, STATICLIB_PP_SEQ_FOR_EACH_I(PIMPL_FORWARD_INTERNAL_EMPTY_CONV, _, PARAMS)))

#define PIMPL_FORWARD_METHOD(class_name, method_return, method_name, PARAMS, MODIFIERS, exception_class_name) \
method_return class_name::method_name(PIMPL_FORWARD_INTERNAL_CREATE_PARAMS_LIST(PARAMS)) \
        PIMPL_FORWARD_INTERNAL_CREATE_MODIFIERS_LIST(MODIFIERS) { \
    try { \
        auto ptr = static_cast<class_name::Impl*> (this->get_impl_ptr().get()); \
        PIMPL_FORWARD_INTERNAL_CREATE_RETURN(method_return) ptr->method_name( \
                *this STATICLIB_PP_COMMA_IF(PIMPL_FORWARD_INTERNAL_NOT_EMPTY_ARGS(PARAMS)) \
                PIMPL_FORWARD_INTERNAL_CREATE_ARG_PASS_LIST(PARAMS) \
        ); \
    } catch (const std::exception& e) { \
        throw exception_class_name(TRACEMSG(e.what())); \
    } \
}

#define PIMPL_FORWARD_METHOD_STATIC(class_name, method_return, method_name, PARAMS, MODIFIERS, exception_class_name) \
method_return class_name::method_name(PIMPL_FORWARD_INTERNAL_CREATE_PARAMS_LIST(PARAMS)) \
        PIMPL_FORWARD_INTERNAL_CREATE_MODIFIERS_LIST(MODIFIERS) { \
    try { \
        PIMPL_FORWARD_INTERNAL_CREATE_RETURN(method_return) class_name::Impl::method_name( \
                PIMPL_FORWARD_INTERNAL_CREATE_ARG_PASS_LIST(PARAMS) \
        ); \
    } catch (const std::exception& e) { \
        throw exception_class_name(TRACEMSG(e.what())); \
    } \
}

#define PIMPL_FORWARD_METHOD_RETURN_SELF(class_name, method_return, method_name, PARAMS, MODIFIERS, exception_class_name) \
method_return class_name::method_name(PIMPL_FORWARD_INTERNAL_CREATE_PARAMS_LIST(PARAMS)) \
        PIMPL_FORWARD_INTERNAL_CREATE_MODIFIERS_LIST(MODIFIERS) { \
    try { \
        auto ptr = static_cast<class_name::Impl*> (this->get_impl_ptr().get()); \
        ptr->method_name( \
                *this STATICLIB_PP_COMMA_IF(PIMPL_FORWARD_INTERNAL_NOT_EMPTY_ARGS(PARAMS)) \
                PIMPL_FORWARD_INTERNAL_CREATE_ARG_PASS_LIST(PARAMS) \
        ); \
        return *this; \
    } catch (const std::exception& e) { \
        throw exception_class_name(TRACEMSG(e.what())); \
    } \
}

#define PIMPL_FORWARD_CONSTRUCTOR(class_name, PARAMS, MODIFIERS, exception_class_name) \
class_name::class_name(PIMPL_FORWARD_INTERNAL_CREATE_PARAMS_LIST(PARAMS)) \
        PIMPL_FORWARD_INTERNAL_CREATE_MODIFIERS_LIST(MODIFIERS) try : \
class_name::class_name(nullptr, std::unique_ptr<class_name::Impl>( \
        new class_name::Impl(PIMPL_FORWARD_INTERNAL_CREATE_ARG_PASS_LIST(PARAMS)) \
)) { } \
catch (const std::exception& e) { \
    throw exception_class_name(TRACEMSG(e.what())); \
}

#endif	/* STATICLIB_PIMPL_PIMPL_FORWARD_MACROS_HPP */
