/* 
 * File:   PimplObject.hpp
 * Author: alex
 *
 * Created on September 6, 2014, 11:47 AM
 */

#ifndef STATICLIB_PIMPLOBJECT_HPP
#define	STATICLIB_PIMPLOBJECT_HPP

#include <string>
#include <memory>
#include <utility>
#include <ostream>

#include "staticlib/utils/config.hpp"

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
    virtual ~PimplObject() STATICLIB_NOEXCEPT;
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
    PimplObject(PimplObject&& other) STATICLIB_NOEXCEPT;
    /**
     * Move assignment operator
     * 
     * @param other other instance
     * @return reference to this instance
     */
    PimplObject& operator=(PimplObject&& other) STATICLIB_NOEXCEPT;

protected:
    /**
     * Implementation class
     */
    class Impl {
        friend PimplObject;
    public:
        /**
         * Virtual destructor
         */
        virtual ~Impl() STATICLIB_NOEXCEPT;  
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
        
    protected:
        /**
         * Default constructor
         */
        Impl() STATICLIB_NOEXCEPT;
        /**
         * String description of this instance,
         * `classname@address` by default
         * 
         * @return string description
         */
        virtual std::string to_string() const;

    };

    /**
     * Constructor to be called from other constructors
     */
    PimplObject(std::unique_ptr<PimplObject::Impl> pimpl) STATICLIB_NOEXCEPT;
    
public:
    /**
     * Unique pointer access, made public only for downcast support,
     * should NOT be used in normal client code
     * 
     * @return unique_ptr to Impl instance
     */
    std::unique_ptr<PimplObject::Impl>& get_impl_ptr() const;
    /**
     * String description of this instance,
     * `classname@address` by default
     * 
     * @return string description
     */
    virtual std::string to_string() const;
    /**
     * Prints string description to ostream
     * 
     * @param stream out stream
     * @param obj instance to print
     */
    friend std::ostream& operator<<(std::ostream& stream, const PimplObject& obj);

private:
    /**
     * Pointer to Impl instance
     */
    mutable std::unique_ptr<PimplObject::Impl> pimpl = nullptr;

};

} // namespace
}

// Optional helper macros, constructor inheritance can be used instead

// for msvc compiler
#define PIMPL_INTERNAL_MOVE_CONSTRUCTORS(class_name, parent_class_name) \
class_name(class_name&& other) STATICLIB_NOEXCEPT : \
parent_class_name(std::forward<class_name>(other)) { } \
\
class_name& operator=(class_name&& other) STATICLIB_NOEXCEPT { \
    parent_class_name::operator=(std::forward<class_name>(other)); \
    return *this; \
}

#define PIMPL_CONSTRUCTOR(class_name) \
class_name(std::unique_ptr<staticlib::pimpl::PimplObject::Impl> pimpl) STATICLIB_NOEXCEPT : \
staticlib::pimpl::PimplObject(std::forward<std::unique_ptr<staticlib::pimpl::PimplObject::Impl>>(pimpl)) { } \
\
PIMPL_INTERNAL_MOVE_CONSTRUCTORS(class_name, staticlib::pimpl::PimplObject)

#define PIMPL_INHERIT_CONSTRUCTOR(class_name, parent_class_name) \
class_name(std::unique_ptr<staticlib::pimpl::PimplObject::Impl> pimpl) STATICLIB_NOEXCEPT : \
parent_class_name(std::forward<std::unique_ptr<staticlib::pimpl::PimplObject::Impl>>(pimpl)) { } \
\
PIMPL_INTERNAL_MOVE_CONSTRUCTORS(class_name, parent_class_name)

#endif	/* STATICLIB_PIMPLOBJECT_HPP */

