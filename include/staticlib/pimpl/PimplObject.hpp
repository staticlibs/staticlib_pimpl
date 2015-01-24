/* 
 * File:   PimplObject.hpp
 * Author: alex
 *
 * Created on September 6, 2014, 11:47 AM
 */

#ifndef PIMPLOBJECT_HPP
#define	PIMPLOBJECT_HPP

#include <memory>

#include <boost/config.hpp>

#include "staticlib/pimpl/PimplException.hpp"

namespace staticlib {
namespace pimpl {

/**
 * PIMPL implementation based on 'std::unique_ptr'.
 * `MoveConstructible`, `MoveAssignable`.
 * NOT `CopyConstructible` and `CopyAssignable`.
 * Multiple inheritance is NOT supported.
 */
class PimplObject {
public:
    /**
     * Virtual destructor
     */
    virtual ~PimplObject() BOOST_NOEXCEPT;
    /**
     * Deleted copy constructor
     * 
     * @param other other instance
     */
    PimplObject(const PimplObject& other) = delete;
    /**
     * Deleted copy assignment operator
     * 
     * @param other other instance
     * @return reference to this instance
     */
    PimplObject& operator=(const PimplObject& other) = delete;
    /**
     * Move constructor
     * 
     * @param other other instance
     */
    PimplObject(PimplObject&& other) BOOST_NOEXCEPT;
    /**
     * Move assignment operator
     * 
     * @param other other instance
     * @return reference to this instance
     */
    PimplObject& operator=(PimplObject&& other) BOOST_NOEXCEPT;

protected:
    /**
     * Implementation class
     */
    class Impl {
    public:
        /**
         * Virtual destructor
         */
        virtual ~Impl() BOOST_NOEXCEPT;       
        
    protected:
        /**
         * Default constructor
         */
        Impl() BOOST_NOEXCEPT;
        
    private:
        /**
         * Deleted copy constructor
         * 
         * @param other other instance
         */
        Impl(const Impl& other) = delete;
        /**
         * Deleted copy assignment operator
         * 
         * @param other other instance
         * @return reference to this instance
         */
        Impl& operator=(const Impl& other) = delete;
        /**
         * Deleted move constructor
         * 
         * @param other other instance
         */
        Impl(Impl&& other) = delete;
        /**
         * Deleted move assignment operator
         * 
         * @param other other instance
         * @return reference to this instance
         */
        Impl& operator=(Impl&& other) = delete;
    };

public:
    /**
     * Constructor to be called from other constructors
     */
    PimplObject(std::unique_ptr<PimplObject::Impl> pimpl) BOOST_NOEXCEPT;
    /**
     * Unique pointer access, made public only for downcast support,
     * should NOT be used in normal client code
     * 
     * @return unique_ptr to Impl instance
     */
    std::unique_ptr<PimplObject::Impl>& get_impl_ptr() const;

private:
    /**
     * Pointer to Impl instance
     */
    mutable std::unique_ptr<PimplObject::Impl> pimpl = nullptr;

};

} // namespace
}

// Optional helper macros

// required for msvc compiler
#define PIMPL_MOVE_CONSTRUCTORS(class_name, parent_class_name) \
class_name(class_name&& other) BOOST_NOEXCEPT : \
parent_class_name(std::move(other)) { } \
\
class_name& operator=(class_name&& other) BOOST_NOEXCEPT { \
    parent_class_name::operator=(std::move(other)); \
    return *this; \
}

#define PIMPL_CONSTRUCTOR(class_name) \
class_name(std::unique_ptr<staticlib::pimpl::PimplObject::Impl> pimpl) BOOST_NOEXCEPT : \
staticlib::pimpl::PimplObject(std::move(pimpl)) { } \
\
PIMPL_MOVE_CONSTRUCTORS(class_name, staticlib::pimpl::PimplObject)

#define PIMPL_INHERIT_CONSTRUCTOR(class_name, parent_class_name) \
class_name(std::unique_ptr<staticlib::pimpl::PimplObject::Impl> pimpl) BOOST_NOEXCEPT : \
parent_class_name(std::move(pimpl)) { } \
\
PIMPL_MOVE_CONSTRUCTORS(class_name, parent_class_name)

#endif	/* PIMPLOBJECT_HPP */

