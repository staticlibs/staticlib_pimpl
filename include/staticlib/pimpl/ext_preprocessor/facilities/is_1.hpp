# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2003.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef STATICLIB_PREPROCESSOR_FACILITIES_IS_1_HPP
# define STATICLIB_PREPROCESSOR_FACILITIES_IS_1_HPP
#
# include "staticlib/pimpl/ext_preprocessor/cat.hpp"
# include "staticlib/pimpl/ext_preprocessor/facilities/is_empty.hpp"
#
# /* STATICLIB_PP_IS_1 */
#
# define STATICLIB_PP_IS_1(x) STATICLIB_PP_IS_EMPTY(STATICLIB_PP_CAT(STATICLIB_PP_IS_1_HELPER_, x))
# define STATICLIB_PP_IS_1_HELPER_1
#
# endif
