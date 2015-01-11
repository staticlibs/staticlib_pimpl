/* 
 * File:   RefObjectMovedFromException.hpp
 * Author: alex
 *
 * Created on October 3, 2014, 6:29 PM
 */

#ifndef REFOBJECTMOVEDFROMEXCEPTION_HPP
#define	REFOBJECTMOVEDFROMEXCEPTION_HPP

#include "staticlib/exceptions/StaticlibException.hpp"

namespace staticlib {
namespace refobjects {

/**
 * Module specific exception
 */
class RefObjectMovedFromException : public staticlib::exceptions::StaticlibException {
public:
    /**
     * Default constructor
     */
    RefObjectMovedFromException() = default;

    /**
     * Constructor with message
     * 
     * @param msg error message
     */
    RefObjectMovedFromException(const std::string& msg) :
    staticlib::exceptions::StaticlibException(msg) { }

};

} // namespace
}

#endif	/* REFOBJECTMOVEDFROMEXCEPTION_HPP */

