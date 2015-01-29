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
# ifndef STATICLIB_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP
# define STATICLIB_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
#
# if STATICLIB_PP_VARIADICS
#
# include "staticlib/pimpl/ext_preprocessor/punctuation/is_begin_parens.hpp"
# include "staticlib/pimpl/ext_preprocessor/facilities/detail/is_empty.hpp"
#
#if STATICLIB_PP_VARIADICS_MSVC && _MSC_VER <= 1400
#
#define STATICLIB_PP_IS_EMPTY(param) \
    STATICLIB_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      STATICLIB_PP_IS_BEGIN_PARENS \
        ( \
        param \
        ) \
      ) \
      ( \
      STATICLIB_PP_IS_EMPTY_ZERO, \
      STATICLIB_PP_DETAIL_IS_EMPTY_PROCESS \
      ) \
    (param) \
/**/
#define STATICLIB_PP_IS_EMPTY_ZERO(param) 0
# else
#define STATICLIB_PP_IS_EMPTY(...) \
    STATICLIB_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      STATICLIB_PP_IS_BEGIN_PARENS \
        ( \
        __VA_ARGS__ \
        ) \
      ) \
      ( \
      STATICLIB_PP_IS_EMPTY_ZERO, \
      STATICLIB_PP_DETAIL_IS_EMPTY_PROCESS \
      ) \
    (__VA_ARGS__) \
/**/
#define STATICLIB_PP_IS_EMPTY_ZERO(...) 0
# endif /* STATICLIB_PP_VARIADICS_MSVC && _MSC_VER <= 1400 */
# endif /* STATICLIB_PP_VARIADICS */
# endif /* STATICLIB_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP */
