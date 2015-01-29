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
# ifndef STATICLIB_PREPROCESSOR_IS_BEGIN_PARENS_HPP
# define STATICLIB_PREPROCESSOR_IS_BEGIN_PARENS_HPP

# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"

#if STATICLIB_PP_VARIADICS

#include "staticlib/pimpl/ext_preprocessor/punctuation/detail/is_begin_parens.hpp"

#if STATICLIB_PP_VARIADICS_MSVC && _MSC_VER <= 1400

#define STATICLIB_PP_IS_BEGIN_PARENS(param) \
    STATICLIB_PP_DETAIL_IBP_SPLIT \
      ( \
      0, \
      STATICLIB_PP_DETAIL_IBP_CAT \
        ( \
        STATICLIB_PP_DETAIL_IBP_IS_VARIADIC_R_, \
        STATICLIB_PP_DETAIL_IBP_IS_VARIADIC_C param \
        ) \
      ) \
/**/

#else

#define STATICLIB_PP_IS_BEGIN_PARENS(...) \
    STATICLIB_PP_DETAIL_IBP_SPLIT \
      ( \
      0, \
      STATICLIB_PP_DETAIL_IBP_CAT \
        ( \
        STATICLIB_PP_DETAIL_IBP_IS_VARIADIC_R_, \
        STATICLIB_PP_DETAIL_IBP_IS_VARIADIC_C __VA_ARGS__ \
        ) \
      ) \
/**/

#endif /* STATICLIB_PP_VARIADICS_MSVC && _MSC_VER <= 1400 */
#endif /* STATICLIB_PP_VARIADICS */
#endif /* STATICLIB_PREPROCESSOR_IS_BEGIN_PARENS_HPP */
