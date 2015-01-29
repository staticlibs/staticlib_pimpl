# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
#ifndef STATICLIB_PREPROCESSOR_DETAIL_IS_EMPTY_HPP
#define STATICLIB_PREPROCESSOR_DETAIL_IS_EMPTY_HPP

#include "staticlib/pimpl/ext_preprocessor/punctuation/is_begin_parens.hpp"

#if STATICLIB_PP_VARIADICS_MSVC

# pragma warning(once:4002)

#define STATICLIB_PP_DETAIL_IS_EMPTY_IIF_0(t, b) b
#define STATICLIB_PP_DETAIL_IS_EMPTY_IIF_1(t, b) t

#else

#define STATICLIB_PP_DETAIL_IS_EMPTY_IIF_0(t, ...) __VA_ARGS__
#define STATICLIB_PP_DETAIL_IS_EMPTY_IIF_1(t, ...) t

#endif

#if STATICLIB_PP_VARIADICS_MSVC && _MSC_VER <= 1400

#define STATICLIB_PP_DETAIL_IS_EMPTY_PROCESS(param) \
	STATICLIB_PP_IS_BEGIN_PARENS \
    	( \
        STATICLIB_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C param () \
        ) \
/**/

#else

#define STATICLIB_PP_DETAIL_IS_EMPTY_PROCESS(...) \
	STATICLIB_PP_IS_BEGIN_PARENS \
        ( \
        STATICLIB_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C __VA_ARGS__ () \
        ) \
/**/

#endif

#define STATICLIB_PP_DETAIL_IS_EMPTY_PRIMITIVE_CAT(a, b) a ## b
#define STATICLIB_PP_DETAIL_IS_EMPTY_IIF(bit) STATICLIB_PP_DETAIL_IS_EMPTY_PRIMITIVE_CAT(STATICLIB_PP_DETAIL_IS_EMPTY_IIF_,bit)
#define STATICLIB_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C(...) ()

#endif /* STATICLIB_PREPROCESSOR_DETAIL_IS_EMPTY_HPP */
