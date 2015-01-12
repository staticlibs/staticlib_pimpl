/* 
 * File:   RefUniqueObject.hpp
 * Author: alex
 *
 * Created on September 6, 2014, 11:47 AM
 */

#ifndef REFUNIQUEOBJECT_HPP
#define	REFUNIQUEOBJECT_HPP

#include <memory>

#include "staticlib/refobjects/RefObjectException.hpp"

#define REFOBJ_INHERIT_CONSTRUCTOR(class_name, parent_class_name) \
class_name(std::unique_ptr<staticlib::refobjects::RefUniqueObject::Impl> pimpl) BOOST_NOEXCEPT : \
parent_class_name(std::move(pimpl)) { } \
\
class_name(class_name&& other) BOOST_NOEXCEPT : \
parent_class_name(std::move(other)) { } \
\
class_name& operator=(class_name&& other) BOOST_NOEXCEPT { \
    parent_class_name::operator=(std::move(other)); \
    return *this; \
}

namespace staticlib {
namespace refobjects {

/**
 * PIMPL implementation based on 'std::unique_ptr'.
 * `MoveConstructible`, `MoveAssignable`.
 * NOT `CopyConstructible` and `CopyAssignable`.
 * Multiple inheritance is NOT supported.
 */
class RefUniqueObject {
public:
    /**
     * Virtual destructor
     */
    virtual ~RefUniqueObject() BOOST_NOEXCEPT;
    /**
     * Deleted copy constructor
     * 
     * @param other other instance
     */
    RefUniqueObject(const RefUniqueObject& other) = delete;
    /**
     * Deleted copy assignment operator
     * 
     * @param other other instance
     * @return reference to this instance
     */
    RefUniqueObject& operator=(const RefUniqueObject& other) = delete;
    /**
     * Move constructor
     * 
     * @param other other instance
     */
    RefUniqueObject(RefUniqueObject&& other) BOOST_NOEXCEPT;
    /**
     * Move assignment operator
     * 
     * @param other other instance
     * @return reference to this instance
     */
    RefUniqueObject& operator=(RefUniqueObject&& other) BOOST_NOEXCEPT;

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

    /**
     * Impl pointer accessor for inheritors
     * 
     * @return pointer to Impl instance
     */
    template <typename T> T* get_impl() {
        return static_cast<T*> (this->get_impl_ptr().get());
    }
    /**
     * Auxiliary Impl pointer accessor for const methods forwarding
     * 
     * @return pointer to Impl instance
     */
    template <typename T> T* get_impl_const() const {
        return static_cast<T*> (this->get_impl_ptr_const().get());
    }

public:
    /**
     * Constructor to be called from other constructors
     */
    RefUniqueObject(std::unique_ptr<RefUniqueObject::Impl> pimpl) BOOST_NOEXCEPT;
    /**
     * Unique pointer access, made public only for downcast support,
     * should NOT be used in normal client code
     * 
     * @return unique_ptr to Impl instance
     */
    std::unique_ptr<RefUniqueObject::Impl>& get_impl_ptr();

private:
    /**
     * Pointer to Impl instance
     */
    std::unique_ptr<RefUniqueObject::Impl> pimpl = nullptr;
    /**
     * Auxiliary method for const methods forwarding
     * 
     * @return 
     */
    const std::unique_ptr<RefUniqueObject::Impl>& get_impl_ptr_const() const;

};

} // namespace
}

#endif	/* REFUNIQUEOBJECT_HPP */

