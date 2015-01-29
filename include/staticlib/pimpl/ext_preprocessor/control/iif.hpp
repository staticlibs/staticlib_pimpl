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
# ifndef STATICLIB_PREPROCESSOR_CONTROL_IIF_HPP
# define STATICLIB_PREPROCESSOR_CONTROL_IIF_HPP
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MWCC()
#    define STATICLIB_PP_IIF(bit, t, f) STATICLIB_PP_IIF_I(bit, t, f)
# else
#    define STATICLIB_PP_IIF(bit, t, f) STATICLIB_PP_IIF_OO((bit, t, f))
#    define STATICLIB_PP_IIF_OO(par) STATICLIB_PP_IIF_I ## par
# endif
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MSVC()
#    define STATICLIB_PP_IIF_I(bit, t, f) STATICLIB_PP_IIF_ ## bit(t, f)
# else
#    define STATICLIB_PP_IIF_I(bit, t, f) STATICLIB_PP_IIF_II(STATICLIB_PP_IIF_ ## bit(t, f))
#    define STATICLIB_PP_IIF_II(id) id
# endif
#
# define STATICLIB_PP_IIF_0(t, f) f
# define STATICLIB_PP_IIF_1(t, f) t
#
# endif
