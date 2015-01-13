/* 
 * File:   RefObjectMovedFromException.hpp
 * Author: alex
 *
 * Created on October 3, 2014, 6:29 PM
 */

#ifndef REFOBJECTEXCEPTION_HPP
#define	REFOBJECTEXCEPTION_HPP

#include "staticlib/stdlib/BaseException.hpp"

namespace staticlib {
namespace refobjects {

/**
 * Module specific exception
 */
class RefObjectException : public staticlib::stdlib::BaseException {
public:
    /**
     * Default constructor
     */
    RefObjectException() = default;

    /**
     * Constructor with message
     * 
     * @param msg error message
     */
    RefObjectException(const std::string& msg) :
    staticlib::stdlib::BaseException(msg) { }

};

} // namespace
}

#endif	/* REFOBJECTEXCEPTION_HPP */

