# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef STATICLIB_PREPROCESSOR_TUPLE_SIZE_HPP
# define STATICLIB_PREPROCESSOR_TUPLE_SIZE_HPP
#
# include "staticlib/pimpl/ext_preprocessor/cat.hpp"
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
# include "staticlib/pimpl/ext_preprocessor/variadic/size.hpp"
#
# if STATICLIB_PP_VARIADICS
#    if STATICLIB_PP_VARIADICS_MSVC
#        define STATICLIB_PP_TUPLE_SIZE(tuple) STATICLIB_PP_CAT(STATICLIB_PP_VARIADIC_SIZE tuple,)
#    else
#        define STATICLIB_PP_TUPLE_SIZE(tuple) STATICLIB_PP_VARIADIC_SIZE tuple
#    endif
# endif
#
# endif
