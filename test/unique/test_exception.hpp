/* 
 * File:   test_exception.hpp
 * Author: alex
 *
 * Created on September 29, 2015, 3:34 PM
 */

#ifndef TEST_EXCEPTION_HPP
#define TEST_EXCEPTION_HPP

#include "staticlib/support/exception.hpp"

namespace unique {

/**
 * Module specific exception
 */
class test_exception : public sl::support::exception {
public:
    /**
     * Default constructor
     */
    test_exception() = default;

    /**
     * Constructor with message
     * 
     * @param msg error message
     */
    test_exception(const std::string& msg) :
    sl::support::exception(msg) { }
};

} // namespace

#endif /* TEST_EXCEPTION_HPP */

