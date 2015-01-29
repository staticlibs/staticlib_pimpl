# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef STATICLIB_PREPROCESSOR_FACILITIES_EXPAND_HPP
# define STATICLIB_PREPROCESSOR_FACILITIES_EXPAND_HPP
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MWCC() && ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_DMC()
#    define STATICLIB_PP_EXPAND(x) STATICLIB_PP_EXPAND_I(x)
# else
#    define STATICLIB_PP_EXPAND(x) STATICLIB_PP_EXPAND_OO((x))
#    define STATICLIB_PP_EXPAND_OO(par) STATICLIB_PP_EXPAND_I ## par
# endif
#
# define STATICLIB_PP_EXPAND_I(x) x
#
# endif
