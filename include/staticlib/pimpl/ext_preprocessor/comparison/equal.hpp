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
# ifndef STATICLIB_PREPROCESSOR_COMPARISON_EQUAL_HPP
# define STATICLIB_PREPROCESSOR_COMPARISON_EQUAL_HPP
#
# include "staticlib/pimpl/ext_preprocessor/comparison/not_equal.hpp"
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
# include "staticlib/pimpl/ext_preprocessor/logical/compl.hpp"
#
# /* STATICLIB_PP_EQUAL */
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_EDG()
#    define STATICLIB_PP_EQUAL(x, y) STATICLIB_PP_COMPL(STATICLIB_PP_NOT_EQUAL(x, y))
# else
#    define STATICLIB_PP_EQUAL(x, y) STATICLIB_PP_EQUAL_I(x, y)
#    define STATICLIB_PP_EQUAL_I(x, y) STATICLIB_PP_COMPL(STATICLIB_PP_NOT_EQUAL(x, y))
# endif
#
# /* STATICLIB_PP_EQUAL_D */
#
# define STATICLIB_PP_EQUAL_D(d, x, y) STATICLIB_PP_EQUAL(x, y)
#
# endif
