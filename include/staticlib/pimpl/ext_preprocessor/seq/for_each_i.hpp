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
# ifndef STATICLIB_PREPROCESSOR_SEQ_FOR_EACH_I_HPP
# define STATICLIB_PREPROCESSOR_SEQ_FOR_EACH_I_HPP
#
# include "staticlib/pimpl/ext_preprocessor/arithmetic/dec.hpp"
# include "staticlib/pimpl/ext_preprocessor/arithmetic/inc.hpp"
# include "staticlib/pimpl/ext_preprocessor/config/config.hpp"
# include "staticlib/pimpl/ext_preprocessor/repetition/for.hpp"
# include "staticlib/pimpl/ext_preprocessor/seq/seq.hpp"
# include "staticlib/pimpl/ext_preprocessor/seq/size.hpp"
# include "staticlib/pimpl/ext_preprocessor/tuple/elem.hpp"
# include "staticlib/pimpl/ext_preprocessor/tuple/rem.hpp"
#
# /* STATICLIB_PP_SEQ_FOR_EACH_I */
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_EDG()
#    define STATICLIB_PP_SEQ_FOR_EACH_I(macro, data, seq) STATICLIB_PP_FOR((macro, data, seq (nil), 0), STATICLIB_PP_SEQ_FOR_EACH_I_P, STATICLIB_PP_SEQ_FOR_EACH_I_O, STATICLIB_PP_SEQ_FOR_EACH_I_M)
# else
#    define STATICLIB_PP_SEQ_FOR_EACH_I(macro, data, seq) STATICLIB_PP_SEQ_FOR_EACH_I_I(macro, data, seq)
#    define STATICLIB_PP_SEQ_FOR_EACH_I_I(macro, data, seq) STATICLIB_PP_FOR((macro, data, seq (nil), 0), STATICLIB_PP_SEQ_FOR_EACH_I_P, STATICLIB_PP_SEQ_FOR_EACH_I_O, STATICLIB_PP_SEQ_FOR_EACH_I_M)
# endif
#
# define STATICLIB_PP_SEQ_FOR_EACH_I_P(r, x) STATICLIB_PP_DEC(STATICLIB_PP_SEQ_SIZE(STATICLIB_PP_TUPLE_ELEM(4, 2, x)))
#
# if STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_STRICT()
#    define STATICLIB_PP_SEQ_FOR_EACH_I_O(r, x) STATICLIB_PP_SEQ_FOR_EACH_I_O_I x
# else
#    define STATICLIB_PP_SEQ_FOR_EACH_I_O(r, x) STATICLIB_PP_SEQ_FOR_EACH_I_O_I(STATICLIB_PP_TUPLE_ELEM(4, 0, x), STATICLIB_PP_TUPLE_ELEM(4, 1, x), STATICLIB_PP_TUPLE_ELEM(4, 2, x), STATICLIB_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define STATICLIB_PP_SEQ_FOR_EACH_I_O_I(macro, data, seq, i) (macro, data, STATICLIB_PP_SEQ_TAIL(seq), STATICLIB_PP_INC(i))
#
# if STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_STRICT()
#    define STATICLIB_PP_SEQ_FOR_EACH_I_M(r, x) STATICLIB_PP_SEQ_FOR_EACH_I_M_IM(r, STATICLIB_PP_TUPLE_REM_4 x)
#    define STATICLIB_PP_SEQ_FOR_EACH_I_M_IM(r, im) STATICLIB_PP_SEQ_FOR_EACH_I_M_I(r, im)
# else
#    define STATICLIB_PP_SEQ_FOR_EACH_I_M(r, x) STATICLIB_PP_SEQ_FOR_EACH_I_M_I(r, STATICLIB_PP_TUPLE_ELEM(4, 0, x), STATICLIB_PP_TUPLE_ELEM(4, 1, x), STATICLIB_PP_TUPLE_ELEM(4, 2, x), STATICLIB_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define STATICLIB_PP_SEQ_FOR_EACH_I_M_I(r, macro, data, seq, i) macro(r, data, i, STATICLIB_PP_SEQ_HEAD(seq))
#
# /* STATICLIB_PP_SEQ_FOR_EACH_I_R */
#
# if ~STATICLIB_PP_CONFIG_FLAGS() & STATICLIB_PP_CONFIG_EDG()
#    define STATICLIB_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) STATICLIB_PP_FOR_ ## r((macro, data, seq (nil), 0), STATICLIB_PP_SEQ_FOR_EACH_I_P, STATICLIB_PP_SEQ_FOR_EACH_I_O, STATICLIB_PP_SEQ_FOR_EACH_I_M)
# else
#    define STATICLIB_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) STATICLIB_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq)
#    define STATICLIB_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq) STATICLIB_PP_FOR_ ## r((macro, data, seq (nil), 0), STATICLIB_PP_SEQ_FOR_EACH_I_P, STATICLIB_PP_SEQ_FOR_EACH_I_O, STATICLIB_PP_SEQ_FOR_EACH_I_M)
# endif
#
# endif
