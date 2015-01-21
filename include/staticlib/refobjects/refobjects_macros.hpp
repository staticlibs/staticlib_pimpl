/* 
 * File:   refobjects_macros.hpp
 * Author: alex
 *
 * Created on September 10, 2014, 8:33 PM
 */

#ifndef FUNFORWARDMACRO_HPP
#define	FUNFORWARDMACRO_HPP

// http://stackoverflow.com/a/13095111/314015
// http://boost.2283326.n4.nabble.com/preprocessor-enabling-variadics-support-tp4642468p4642535.html
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <boost/preprocessor/comparison/equal.hpp>

#include "staticlib/stdlib/memory_utils.hpp"
#include "staticlib/stdlib/tracemsg.hpp"
#include "staticlib/refobjects/RefObjectException.hpp"

#define REFOBJ_FORWARD_RET_TYPE_void 1)(1
#define REFOBJ_FORWARD_IS_NOT_VOID(type) BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE((REFOBJ_FORWARD_RET_TYPE_##type)),1)

#define REFOBJ_FORWARD_PARAMS(r, data, i, elem) (elem p##i)
#define REFOBJ_FORWARD_ARGS_PASS(r, data, i, elem) (std::move(p##i))

#define REFOBJ_FORWARD_CREATE_PARAMS_LIST(PARAMS) BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_FOR_EACH_I(REFOBJ_FORWARD_PARAMS,_,PARAMS))
#define REFOBJ_FORWARD_CREATE_ARG_PASS_LIST(PARAMS) BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_FOR_EACH_I(REFOBJ_FORWARD_ARGS_PASS, _, PARAMS))      
#define REFOBJ_FORWARD_CREATE_RETURN(function_return) BOOST_PP_EXPR_IF(REFOBJ_FORWARD_IS_NOT_VOID(function_return),return)

#define REFOBJ_FORWARD_FUNCTION_ARG(class_name, function_return, function_name, PARAMS) \
function_return class_name::function_name(REFOBJ_FORWARD_CREATE_PARAMS_LIST(PARAMS)) { \
    try { \
        REFOBJ_FORWARD_CREATE_RETURN(function_return) this->get_impl<class_name::Impl>()->function_name(REFOBJ_FORWARD_CREATE_ARG_PASS_LIST(PARAMS)); \
    } catch (const std::exception& e) { \
        throw staticlib::refobjects::RefObjectException(TRACEMSG(e.what())); \
    } \
}

#define REFOBJ_FORWARD_FUNCTION_ARG_CONST(class_name, function_return, function_name, PARAMS) \
function_return class_name::function_name(REFOBJ_FORWARD_CREATE_PARAMS_LIST(PARAMS)) const { \
    try { \
        REFOBJ_FORWARD_CREATE_RETURN(function_return) this->get_impl_const<class_name::Impl>()->function_name(REFOBJ_FORWARD_CREATE_ARG_PASS_LIST(PARAMS)); \
    } catch (const std::exception& e) { \
        throw staticlib::refobjects::RefObjectException(TRACEMSG(e.what())); \
    } \
}

#define REFOBJ_FORWARD_FUNCTION_NOARG(class_name, function_return, function_name) \
function_return class_name::function_name() { \
    try { \
        REFOBJ_FORWARD_CREATE_RETURN(function_return) this->get_impl<class_name::Impl>()->function_name(); \
    } catch (const std::exception& e) { \
        throw staticlib::refobjects::RefObjectException(TRACEMSG(e.what())); \
    } \
}

#define REFOBJ_FORWARD_FUNCTION_NOARG_CONST(class_name, function_return, function_name) \
function_return class_name::function_name() const { \
    try { \
        REFOBJ_FORWARD_CREATE_RETURN(function_return) this->get_impl_const<class_name::Impl>()->function_name(); \
    } catch (const std::exception& e) { \
        throw staticlib::refobjects::RefObjectException(TRACEMSG(e.what())); \
    } \
}

#define REFOBJ_FORWARD_CONSTRUCTOR_REFCOUNT_ARG(class_name, PARAMS) \
class_name::class_name(REFOBJ_FORWARD_CREATE_PARAMS_LIST(PARAMS)) : \
class_name::class_name(std::make_shared<class_name::Impl>(REFOBJ_FORWARD_CREATE_ARG_PASS_LIST(PARAMS))) { }

#define REFOBJ_FORWARD_CONSTRUCTOR_REFCOUNT_NOARG(class_name) \
class_name::class_name() : \
class_name::class_name(std::make_shared<class_name::Impl>()) { }

#define REFOBJ_FORWARD_CONSTRUCTOR_ARG(class_name, PARAMS) \
class_name::class_name(REFOBJ_FORWARD_CREATE_PARAMS_LIST(PARAMS)) : \
class_name::class_name(staticlib::stdlib::make_unique<class_name::Impl>(REFOBJ_FORWARD_CREATE_ARG_PASS_LIST(PARAMS))) { }

#define REFOBJ_FORWARD_CONSTRUCTOR_NOARG(class_name) \
class_name::class_name() : \
class_name::class_name(staticlib::stdlib::make_unique<class_name::Impl>()) { }

// http://stackoverflow.com/a/5530998/314015
#define REFOBJ_EXPAND(x) x
// http://stackoverflow.com/a/11763277
#define REFOBJ_FORWARD_GET_FUNCTION_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define REFOBJ_FORWARD_FUNCTION(...) REFOBJ_EXPAND(REFOBJ_FORWARD_GET_FUNCTION_MACRO(__VA_ARGS__, REFOBJ_FORWARD_FUNCTION_ARG, REFOBJ_FORWARD_FUNCTION_NOARG, _dummy)(__VA_ARGS__))

#define REFOBJ_FORWARD_GET_FUNCTION_CONST_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define REFOBJ_FORWARD_FUNCTION_CONST(...) REFOBJ_EXPAND(REFOBJ_FORWARD_GET_FUNCTION_CONST_MACRO(__VA_ARGS__, REFOBJ_FORWARD_FUNCTION_ARG_CONST, REFOBJ_FORWARD_FUNCTION_NOARG_CONST, _dummy)(__VA_ARGS__))

#define REFOBJ_FORWARD_GET_CONSTRUCTOR_MACRO(_1,_2,NAME,...) NAME
#define REFOBJ_FORWARD_CONSTRUCTOR(...) REFOBJ_EXPAND(REFOBJ_FORWARD_GET_CONSTRUCTOR_MACRO(__VA_ARGS__, REFOBJ_FORWARD_CONSTRUCTOR_ARG, REFOBJ_FORWARD_CONSTRUCTOR_NOARG, _dummy)(__VA_ARGS__))

#define REFOBJ_FORWARD_GET_CONSTRUCTOR_REFCOUNT_MACRO(_1,_2,NAME,...) NAME
#define REFOBJ_FORWARD_CONSTRUCTOR_REFCOUNT(...) REFOBJ_EXPAND(REFOBJ_FORWARD_GET_CONSTRUCTOR_REFCOUNT_MACRO(__VA_ARGS__, REFOBJ_FORWARD_CONSTRUCTOR_REFCOUNT_ARG, REFOBJ_FORWARD_CONSTRUCTOR_REFCOUNT_NOARG, _dummy)(__VA_ARGS__))

#define REFOBJ_INHERIT_CONSTRUCTOR_REFCOUNT_MACRO(r, data, i, elem) (elem(pimpl))
#define REFOBJ_INHERIT_MOVE_CONSTRUCTOR_REFCOUNT_MACRO(r, data, i, elem) (elem(std::move(other)))
#define REFOBJ_INHERIT_CONSTRUCTOR_REFCOUNT(class_name, PARENTS) \
class_name(std::shared_ptr<staticlib::refobjects::RefCountObject::Impl> pimpl) : \
BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_FOR_EACH_I(REFOBJ_INHERIT_CONSTRUCTOR_REFCOUNT_MACRO, _, PARENTS)) \
{ } \
\
class_name(const class_name& other) BOOST_NOEXCEPT : \
BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_FOR_EACH_I(REFOBJ_INHERIT_MOVE_CONSTRUCTOR_REFCOUNT_MACRO, _, PARENTS)) \
{ } \
\
class_name(class_name&& other) BOOST_NOEXCEPT : \
BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_FOR_EACH_I(REFOBJ_INHERIT_MOVE_CONSTRUCTOR_REFCOUNT_MACRO, _, PARENTS)) \
{ }


#endif	/* FUNFORWARDMACRO_HPP */
