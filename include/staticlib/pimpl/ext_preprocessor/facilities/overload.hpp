# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef STATICLIB_PREPROCESSOR_FACILITIES_OVERLOAD_HPP
# define STATICLIB_PREPROCESSOR_FACILITIES_OVERLOAD_HPP
#
# include "staticlib/pimpl/ext_preprocessor/cat.hpp"
# include "staticlib/pimpl/ext_preprocessor/variadic/size.hpp"
#
# /* STATICLIB_PP_OVERLOAD */
#
# if STATICLIB_PP_VARIADICS
#    define STATICLIB_PP_OVERLOAD(prefix, ...) STATICLIB_PP_CAT(prefix, STATICLIB_PP_VARIADIC_SIZE(__VA_ARGS__))
# endif
#
# endif
