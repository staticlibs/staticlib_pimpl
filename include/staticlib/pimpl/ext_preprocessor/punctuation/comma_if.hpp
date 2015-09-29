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
# ifndef STATICLIB_PREPROCESSOR_PUNCTUATION_COMMA_IF_HPP
# define STATICLIB_PREPROCESSOR_PUNCTUATION_COMMA_IF_HPP
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
# include "staticlib/pimpl/ext_preprocessor/control/if.hpp"
# include "staticlib/pimpl/ext_preprocessor/facilities/empty.hpp"
# include "staticlib/pimpl/ext_preprocessor/punctuation/comma.hpp"
#
# /* STATICLIB_PP_COMMA_IF */
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_EDG()
#    define STATICLIB_PP_COMMA_IF(cond) STATICLIB_PP_IF(cond, STATICLIB_PP_COMMA, STATICLIB_PP_EMPTY)()
# else
#    define STATICLIB_PP_COMMA_IF(cond) STATICLIB_PP_COMMA_IF_I(cond)
#    define STATICLIB_PP_COMMA_IF_I(cond) STATICLIB_PP_IF(cond, STATICLIB_PP_COMMA, STATICLIB_PP_EMPTY)()
# endif
#
# endif
