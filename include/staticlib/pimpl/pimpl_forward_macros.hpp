/* 
 * File:   pimpl_forward_macros.hpp
 * Author: alex
 *
 * Created on September 10, 2014, 8:33 PM
 */

#ifndef PIMPL_FORWARD_MACROS_HPP
#define	PIMPL_FORWARD_MACROS_HPP

#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <boost/preprocessor/comparison/equal.hpp>

#include "staticlib/stdlib/tracemsg.hpp"
#include "staticlib/pimpl/PimplException.hpp"

#define PIMPL_FORWARD_RET_TYPE_void 1)(1
#define PIMPL_FORWARD_IS_NOT_VOID(type) BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE((PIMPL_FORWARD_RET_TYPE_##type)),1)

#define PIMPL_FORWARD_PARAMS(r, data, i, elem) (elem p##i)
#define PIMPL_FORWARD_ARGS_PASS(r, data, i, elem) (std::move(p##i))

#define PIMPL_FORWARD_CREATE_PARAMS_LIST(PARAMS) BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_FOR_EACH_I(PIMPL_FORWARD_PARAMS,_,PARAMS))
#define PIMPL_FORWARD_CREATE_ARG_PASS_LIST(PARAMS) BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_FOR_EACH_I(PIMPL_FORWARD_ARGS_PASS, _, PARAMS))      
#define PIMPL_FORWARD_CREATE_RETURN(function_return) BOOST_PP_EXPR_IF(PIMPL_FORWARD_IS_NOT_VOID(function_return),return)

#define PIMPL_FORWARD_FUNCTION_ARG(class_name, function_return, function_name, PARAMS) \
function_return class_name::function_name(PIMPL_FORWARD_CREATE_PARAMS_LIST(PARAMS)) { \
    try { \
        auto ptr = static_cast<class_name::Impl*> (this->get_impl_ptr().get()); \
        PIMPL_FORWARD_CREATE_RETURN(function_return) ptr->function_name(PIMPL_FORWARD_CREATE_ARG_PASS_LIST(PARAMS)); \
    } catch (const std::exception& e) { \
        throw staticlib::pimpl::PimplException(TRACEMSG(e.what())); \
    } \
}

#define PIMPL_FORWARD_FUNCTION_ARG_CONST(class_name, function_return, function_name, PARAMS) \
function_return class_name::function_name(PIMPL_FORWARD_CREATE_PARAMS_LIST(PARAMS)) const { \
    try { \
        auto ptr = static_cast<class_name::Impl*> (this->get_impl_ptr().get()); \
        PIMPL_FORWARD_CREATE_RETURN(function_return) ptr->function_name(PIMPL_FORWARD_CREATE_ARG_PASS_LIST(PARAMS)); \
    } catch (const std::exception& e) { \
        throw staticlib::pimpl::PimplException(TRACEMSG(e.what())); \
    } \
}

#define PIMPL_FORWARD_FUNCTION_NOARG(class_name, function_return, function_name) \
function_return class_name::function_name() { \
    try { \
        auto ptr = static_cast<class_name::Impl*> (this->get_impl_ptr().get()); \
        PIMPL_FORWARD_CREATE_RETURN(function_return) ptr->function_name(); \
    } catch (const std::exception& e) { \
        throw staticlib::pimpl::PimplException(TRACEMSG(e.what())); \
    } \
}

#define PIMPL_FORWARD_FUNCTION_NOARG_CONST(class_name, function_return, function_name) \
function_return class_name::function_name() const { \
    try { \
        auto ptr = static_cast<class_name::Impl*> (this->get_impl_ptr().get()); \
        PIMPL_FORWARD_CREATE_RETURN(function_return) ptr->function_name(); \
    } catch (const std::exception& e) { \
        throw staticlib::pimpl::PimplException(TRACEMSG(e.what())); \
    } \
}

#define PIMPL_FORWARD_CONSTRUCTOR_ARG(class_name, PARAMS) \
class_name::class_name(PIMPL_FORWARD_CREATE_PARAMS_LIST(PARAMS)) : \
class_name::class_name(std::unique_ptr<class_name::Impl>(new class_name::Impl(PIMPL_FORWARD_CREATE_ARG_PASS_LIST(PARAMS)))) { }

#define PIMPL_FORWARD_CONSTRUCTOR_NOARG(class_name) \
class_name::class_name() : \
class_name::class_name(std::unique_ptr<class_name::Impl>(new class_name::Impl())) { }

// http://stackoverflow.com/a/5530998/314015
#define PIMPL_FORWARD_EXPAND(x) x
// http://stackoverflow.com/a/11763277
#define PIMPL_FORWARD_GET_FUNCTION_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define PIMPL_FORWARD_FUNCTION(...) PIMPL_FORWARD_EXPAND(PIMPL_FORWARD_GET_FUNCTION_MACRO(__VA_ARGS__, PIMPL_FORWARD_FUNCTION_ARG, PIMPL_FORWARD_FUNCTION_NOARG, _dummy)(__VA_ARGS__))

#define PIMPL_FORWARD_GET_FUNCTION_CONST_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define PIMPL_FORWARD_FUNCTION_CONST(...) PIMPL_FORWARD_EXPAND(PIMPL_FORWARD_GET_FUNCTION_CONST_MACRO(__VA_ARGS__, PIMPL_FORWARD_FUNCTION_ARG_CONST, PIMPL_FORWARD_FUNCTION_NOARG_CONST, _dummy)(__VA_ARGS__))

#define PIMPL_FORWARD_GET_CONSTRUCTOR_MACRO(_1,_2,NAME,...) NAME
#define PIMPL_FORWARD_CONSTRUCTOR(...) PIMPL_FORWARD_EXPAND(PIMPL_FORWARD_GET_CONSTRUCTOR_MACRO(__VA_ARGS__, PIMPL_FORWARD_CONSTRUCTOR_ARG, PIMPL_FORWARD_CONSTRUCTOR_NOARG, _dummy)(__VA_ARGS__))

#endif	/* PIMPL_FORWARD_MACROS_HPP */
