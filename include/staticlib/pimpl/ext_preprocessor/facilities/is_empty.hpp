# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2003.
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef STATICLIB_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP
# define STATICLIB_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
#
# if STATICLIB_PP_VARIADICS
#
# include "staticlib/pimpl/ext_preprocessor/facilities/is_empty_variadic.hpp"
#
# else
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MSVC() && ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MWCC()
# include "staticlib/pimpl/ext_preprocessor/tuple/elem.hpp"
# include "staticlib/pimpl/ext_preprocessor/facilities/identity.hpp"
# else
# include "staticlib/pimpl/ext_preprocessor/cat.hpp"
# include "staticlib/pimpl/ext_preprocessor/detail/split.hpp"
# endif
#
# /* STATICLIB_PP_IS_EMPTY */
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MSVC() && ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MWCC()
#    define STATICLIB_PP_IS_EMPTY(x) STATICLIB_PP_IS_EMPTY_I(x STATICLIB_PP_IS_EMPTY_HELPER)
#    define STATICLIB_PP_IS_EMPTY_I(contents) STATICLIB_PP_TUPLE_ELEM(2, 1, (STATICLIB_PP_IS_EMPTY_DEF_ ## contents()))
#    define STATICLIB_PP_IS_EMPTY_DEF_STATICLIB_PP_IS_EMPTY_HELPER 1, STATICLIB_PP_IDENTITY(1)
#    define STATICLIB_PP_IS_EMPTY_HELPER() , 0
# else
#    if STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MSVC()
#        define STATICLIB_PP_IS_EMPTY(x) STATICLIB_PP_IS_EMPTY_I(STATICLIB_PP_IS_EMPTY_HELPER x ())
#        define STATICLIB_PP_IS_EMPTY_I(test) STATICLIB_PP_IS_EMPTY_II(STATICLIB_PP_SPLIT(0, STATICLIB_PP_CAT(STATICLIB_PP_IS_EMPTY_DEF_, test)))
#        define STATICLIB_PP_IS_EMPTY_II(id) id
#    else
#        define STATICLIB_PP_IS_EMPTY(x) STATICLIB_PP_IS_EMPTY_I((STATICLIB_PP_IS_EMPTY_HELPER x ()))
#        define STATICLIB_PP_IS_EMPTY_I(par) STATICLIB_PP_IS_EMPTY_II ## par
#        define STATICLIB_PP_IS_EMPTY_II(test) STATICLIB_PP_SPLIT(0, STATICLIB_PP_CAT(STATICLIB_PP_IS_EMPTY_DEF_, test))
#    endif
#    define STATICLIB_PP_IS_EMPTY_HELPER() 1
#    define STATICLIB_PP_IS_EMPTY_DEF_1 1, STATICLIB_PP_NIL
#    define STATICLIB_PP_IS_EMPTY_DEF_STATICLIB_PP_IS_EMPTY_HELPER 0, STATICLIB_PP_NIL
# endif
#
# endif /* STATICLIB_PP_VARIADICS */
#
# endif /* STATICLIB_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP */
