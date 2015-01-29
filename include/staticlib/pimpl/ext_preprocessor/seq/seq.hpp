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
# ifndef STATICLIB_PREPROCESSOR_SEQ_SEQ_HPP
# define STATICLIB_PREPROCESSOR_SEQ_SEQ_HPP
#
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
# include "staticlib/pimpl/ext_preprocessor/seq/elem.hpp"
#
# /* STATICLIB_PP_SEQ_HEAD */
#
# define STATICLIB_PP_SEQ_HEAD(seq) STATICLIB_PP_SEQ_ELEM(0, seq)
#
# /* STATICLIB_PP_SEQ_TAIL */
#
# if STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MWCC()
#    define STATICLIB_PP_SEQ_TAIL(seq) STATICLIB_PP_SEQ_TAIL_1((seq))
#    define STATICLIB_PP_SEQ_TAIL_1(par) STATICLIB_PP_SEQ_TAIL_2 ## par
#    define STATICLIB_PP_SEQ_TAIL_2(seq) STATICLIB_PP_SEQ_TAIL_I ## seq
# elif STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_MSVC()
#    define STATICLIB_PP_SEQ_TAIL(seq) STATICLIB_PP_SEQ_TAIL_ID(STATICLIB_PP_SEQ_TAIL_I seq)
#    define STATICLIB_PP_SEQ_TAIL_ID(id) id
# elif STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_EDG()
#    define STATICLIB_PP_SEQ_TAIL(seq) STATICLIB_PP_SEQ_TAIL_D(seq)
#    define STATICLIB_PP_SEQ_TAIL_D(seq) STATICLIB_PP_SEQ_TAIL_I seq
# else
#    define STATICLIB_PP_SEQ_TAIL(seq) STATICLIB_PP_SEQ_TAIL_I seq
# endif
#
# define STATICLIB_PP_SEQ_TAIL_I(x)
#
# /* STATICLIB_PP_SEQ_NIL */
#
# define STATICLIB_PP_SEQ_NIL(x) (x)
#
# endif
