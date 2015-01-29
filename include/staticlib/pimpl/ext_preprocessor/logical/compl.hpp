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
# ifndef STATICLIB_PREPROCESSOR_LOGICAL_COMPL_HPP
# define STATICLIB_PREPROCESSOR_LOGICAL_COMPL_HPP
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
#
# /* STATICLIB_PP_COMPL */
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MWCC()
#    define STATICLIB_PP_COMPL(x) STATICLIB_PP_COMPL_I(x)
# else
#    define STATICLIB_PP_COMPL(x) STATICLIB_PP_COMPL_OO((x))
#    define STATICLIB_PP_COMPL_OO(par) STATICLIB_PP_COMPL_I ## par
# endif
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MSVC()
#    define STATICLIB_PP_COMPL_I(x) STATICLIB_PP_COMPL_ ## x
# else
#    define STATICLIB_PP_COMPL_I(x) STATICLIB_PP_COMPL_ID(STATICLIB_PP_COMPL_ ## x)
#    define STATICLIB_PP_COMPL_ID(id) id
# endif
#
# define STATICLIB_PP_COMPL_0 1
# define STATICLIB_PP_COMPL_1 0
#
# endif
