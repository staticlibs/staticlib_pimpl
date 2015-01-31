/* 
 * File:   PimplException.hpp
 * Author: alex
 *
 * Created on October 3, 2014, 6:29 PM
 */

#ifndef STATICLIB_PIMPLEXCEPTION_HPP
#define	STATICLIB_PIMPLEXCEPTION_HPP

#include "staticlib/stdlib/BaseException.hpp"

namespace staticlib {
namespace pimpl {

/**
 * Module specific exception
 */
class PimplException : public staticlib::stdlib::BaseException {
public:
    /**
     * Default constructor
     */
    PimplException() = default;

    /**
     * Constructor with message
     * 
     * @param msg error message
     */
    PimplException(const std::string& msg) :
    staticlib::stdlib::BaseException(msg) { }

};

} // namespace
}

#endif	/* STATICLIB_PIMPLEXCEPTION_HPP */

