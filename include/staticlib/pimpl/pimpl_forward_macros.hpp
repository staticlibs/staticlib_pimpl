/* 
 * File:   pimpl_forward_macros.hpp
 * Author: alex
 *
 * Created on September 10, 2014, 8:33 PM
 */

#ifndef STATICLIB_PIMPL_FORWARD_MACROS_HPP
#define	STATICLIB_PIMPL_FORWARD_MACROS_HPP

#ifdef _MSC_VER
    //http://lists.boost.org/boost-users/2014/11/83291.php
    #pragma warning (disable: 4003)
#endif //_MSC_VER

#include "staticlib/pimpl/ext_preprocessor/ext_preprocessor.hpp"

#include "staticlib/utils/tracemsg.hpp"
#include "staticlib/pimpl/PimplException.hpp"

#define PIMPL_FORWARD_INTERNAL_RET_TYPE_void 1)(1
#define PIMPL_FORWARD_INTERNAL_IS_NOT_VOID(type) STATICLIB_PP_EQUAL(STATICLIB_PP_SEQ_SIZE((PIMPL_FORWARD_INTERNAL_RET_TYPE_##type)),1)

#define PIMPL_FORWARD_INTERNAL_PARAMS(r, data, i, elem) STATICLIB_PP_IF(PIMPL_FORWARD_INTERNAL_IS_NOT_VOID(elem), (elem p##i), ())
#define PIMPL_FORWARD_INTERNAL_ARGS_PASS(r, data, i, elem) STATICLIB_PP_IF(PIMPL_FORWARD_INTERNAL_IS_NOT_VOID(elem), (std::move(p##i)), ())
#define PIMPL_FORWARD_INTERNAL_MODIFIERS(r, data, i, elem) (elem)

#define PIMPL_FORWARD_INTERNAL_CREATE_PARAMS_LIST(PARAMS) STATICLIB_PP_SEQ_ENUM(STATICLIB_PP_SEQ_FOR_EACH_I(PIMPL_FORWARD_INTERNAL_PARAMS,_,PARAMS))
#define PIMPL_FORWARD_INTERNAL_CREATE_ARG_PASS_LIST(PARAMS) STATICLIB_PP_SEQ_ENUM(STATICLIB_PP_SEQ_FOR_EACH_I(PIMPL_FORWARD_INTERNAL_ARGS_PASS, _, PARAMS))      
#define PIMPL_FORWARD_INTERNAL_CREATE_MODIFIERS_LIST(MODIFIERS) STATICLIB_PP_SEQ_ENUM(STATICLIB_PP_SEQ_FOR_EACH_I(PIMPL_FORWARD_INTERNAL_MODIFIERS, _, MODIFIERS))      
#define PIMPL_FORWARD_INTERNAL_CREATE_RETURN(method_return) STATICLIB_PP_EXPR_IF(PIMPL_FORWARD_INTERNAL_IS_NOT_VOID(method_return),return)

#define PIMPL_FORWARD_METHOD(class_name, method_return, method_name, PARAMS, MODIFIERS) \
method_return class_name::method_name(PIMPL_FORWARD_INTERNAL_CREATE_PARAMS_LIST(PARAMS)) PIMPL_FORWARD_INTERNAL_CREATE_MODIFIERS_LIST(MODIFIERS) { \
    try { \
        auto ptr = static_cast<class_name::Impl*> (this->get_impl_ptr().get()); \
        PIMPL_FORWARD_INTERNAL_CREATE_RETURN(method_return) ptr->method_name(PIMPL_FORWARD_INTERNAL_CREATE_ARG_PASS_LIST(PARAMS)); \
    } catch (const std::exception& e) { \
        throw staticlib::pimpl::PimplException(TRACEMSG(e.what())); \
    } \
}

#define PIMPL_FORWARD_METHOD_STATIC(class_name, method_return, method_name, PARAMS, MODIFIERS) \
method_return class_name::method_name(PIMPL_FORWARD_INTERNAL_CREATE_PARAMS_LIST(PARAMS)) PIMPL_FORWARD_INTERNAL_CREATE_MODIFIERS_LIST(MODIFIERS) { \
    try { \
        PIMPL_FORWARD_INTERNAL_CREATE_RETURN(method_return) class_name::Impl::method_name(PIMPL_FORWARD_INTERNAL_CREATE_ARG_PASS_LIST(PARAMS)); \
    } catch (const std::exception& e) { \
        throw staticlib::pimpl::PimplException(TRACEMSG(e.what())); \
    } \
}

#define PIMPL_FORWARD_CONSTRUCTOR(class_name, PARAMS, MODIFIERS) \
class_name::class_name(PIMPL_FORWARD_INTERNAL_CREATE_PARAMS_LIST(PARAMS)) PIMPL_FORWARD_INTERNAL_CREATE_MODIFIERS_LIST(MODIFIERS) : \
class_name::class_name(std::unique_ptr<class_name::Impl>(new class_name::Impl(PIMPL_FORWARD_INTERNAL_CREATE_ARG_PASS_LIST(PARAMS)))) { }

#endif	/* STATICLIB_PIMPL_FORWARD_MACROS_HPP */
