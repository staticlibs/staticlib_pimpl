# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.                                    *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef STATICLIB_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP
# define STATICLIB_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
#
# /* STATICLIB_PP_TUPLE_IS_SINGLE_RETURN */
#
# if STATICLIB_PP_VARIADICS && STATICLIB_PP_VARIADICS_MSVC
# include "staticlib/pimpl/ext_preprocessor/control/iif.hpp"
# include "staticlib/pimpl/ext_preprocessor/facilities/is_1.hpp"
# include "staticlib/pimpl/ext_preprocessor/tuple/size.hpp"
# define STATICLIB_PP_TUPLE_IS_SINGLE_RETURN(sr,nsr,tuple)	\
	STATICLIB_PP_IIF(STATICLIB_PP_IS_1(STATICLIB_PP_TUPLE_SIZE(tuple)),sr,nsr) \
	/**/
# endif /* STATICLIB_PP_VARIADICS && STATICLIB_PP_VARIADICS_MSVC */
#
# endif /* STATICLIB_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP */
