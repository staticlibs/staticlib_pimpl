# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef STATICLIB_PREPROCESSOR_DEBUG_ERROR_HPP
# define STATICLIB_PREPROCESSOR_DEBUG_ERROR_HPP
#
# include "staticlib/pimpl/ext_preprocessor/cat.hpp"
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
#
# /* STATICLIB_PP_ERROR */
#
# if STATICLIB_PP_CONFIG_ERRORS
#    define STATICLIB_PP_ERROR(code) STATICLIB_PP_CAT(STATICLIB_PP_ERROR_, code)
# endif
#
# define STATICLIB_PP_ERROR_0x0000 STATICLIB_PP_ERROR(0x0000, STATICLIB_PP_INDEX_OUT_OF_BOUNDS)
# define STATICLIB_PP_ERROR_0x0001 STATICLIB_PP_ERROR(0x0001, STATICLIB_PP_WHILE_OVERFLOW)
# define STATICLIB_PP_ERROR_0x0002 STATICLIB_PP_ERROR(0x0002, STATICLIB_PP_FOR_OVERFLOW)
# define STATICLIB_PP_ERROR_0x0003 STATICLIB_PP_ERROR(0x0003, STATICLIB_PP_REPEAT_OVERFLOW)
# define STATICLIB_PP_ERROR_0x0004 STATICLIB_PP_ERROR(0x0004, STATICLIB_PP_LIST_FOLD_OVERFLOW)
# define STATICLIB_PP_ERROR_0x0005 STATICLIB_PP_ERROR(0x0005, STATICLIB_PP_SEQ_FOLD_OVERFLOW)
# define STATICLIB_PP_ERROR_0x0006 STATICLIB_PP_ERROR(0x0006, STATICLIB_PP_ARITHMETIC_OVERFLOW)
# define STATICLIB_PP_ERROR_0x0007 STATICLIB_PP_ERROR(0x0007, STATICLIB_PP_DIVISION_BY_ZERO)
#
# endif
