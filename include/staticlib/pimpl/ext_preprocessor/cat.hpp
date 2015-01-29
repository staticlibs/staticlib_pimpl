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
# ifndef STATICLIB_PREPROCESSOR_CAT_HPP
# define STATICLIB_PREPROCESSOR_CAT_HPP
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
#
# /* STATICLIB_PP_CAT */
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MWCC()
#    define STATICLIB_PP_CAT(a, b) STATICLIB_PP_CAT_I(a, b)
# else
#    define STATICLIB_PP_CAT(a, b) STATICLIB_PP_CAT_OO((a, b))
#    define STATICLIB_PP_CAT_OO(par) STATICLIB_PP_CAT_I ## par
# endif
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MSVC()
#    define STATICLIB_PP_CAT_I(a, b) a ## b
# else
#    define STATICLIB_PP_CAT_I(a, b) STATICLIB_PP_CAT_II(~, a ## b)
#    define STATICLIB_PP_CAT_II(p, res) res
# endif
#
# endif
