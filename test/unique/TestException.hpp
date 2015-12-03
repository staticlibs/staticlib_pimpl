/* 
 * File:   TestException.hpp
 * Author: alex
 *
 * Created on September 29, 2015, 3:34 PM
 */

#ifndef TESTEXCEPTION_HPP
#define	TESTEXCEPTION_HPP

namespace unique {

/**
 * Module specific exception
 */
class TestException : public staticlib::config::BaseException {
public:
    /**
     * Default constructor
     */
    TestException() = default;

    /**
     * Constructor with message
     * 
     * @param msg error message
     */
    TestException(const std::string& msg) :
    staticlib::config::BaseException(msg) { }
};

} // namespace

#endif	/* TESTEXCEPTION_HPP */

