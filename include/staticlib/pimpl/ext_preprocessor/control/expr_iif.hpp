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
# ifndef STATICLIB_PREPROCESSOR_CONTROL_EXPR_IIF_HPP
# define STATICLIB_PREPROCESSOR_CONTROL_EXPR_IIF_HPP
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
#
# /* STATICLIB_PP_EXPR_IIF */
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MWCC()
#    define STATICLIB_PP_EXPR_IIF(bit, expr) STATICLIB_PP_EXPR_IIF_I(bit, expr)
# else
#    define STATICLIB_PP_EXPR_IIF(bit, expr) STATICLIB_PP_EXPR_IIF_OO((bit, expr))
#    define STATICLIB_PP_EXPR_IIF_OO(par) STATICLIB_PP_EXPR_IIF_I ## par
# endif
#
# define STATICLIB_PP_EXPR_IIF_I(bit, expr) STATICLIB_PP_EXPR_IIF_ ## bit(expr)
#
# define STATICLIB_PP_EXPR_IIF_0(expr)
# define STATICLIB_PP_EXPR_IIF_1(expr) expr
#
# endif
