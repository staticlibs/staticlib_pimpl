/* 
 * File:   RefCountObject.hpp
 * Author: alex
 *
 * Created on September 4, 2014, 9:22 PM
 */

#ifndef REFCOUNTOBJECT_HPP
#define	REFCOUNTOBJECT_HPP
// https://connect.microsoft.com/VisualStudio/feedback/details/774986/codename-milan-delegating-constructors-causes-warning-c4100-initvbases-unreferenced-formal-parameter-w4-when-derived-class-uses-virtual-inheritance
#if defined _MSC_VER
    #pragma warning (disable : 4100)
#endif

#include <memory>

#include "staticlib/refobjects/RefObjectException.hpp"

namespace staticlib {
namespace refobjects {

/**
 * PIMPL implementation based on 'std::shared_ptr'.
 * Based on `dynamic_cast`, use with caution, consider using `RefUniqueObject` instead.
 * `CopyConstructible`, `CopyAssignable` and `MoveConstructible`, but NOT `MoveAssignable`.
 * Should be used with virtual inheritance. Multiple inheritance is supported.
 */
class RefCountObject {
public:
    /**
     * Virtual destructor
     */
    virtual ~RefCountObject() BOOST_NOEXCEPT;
    /**
     * Copy constructor
     * 
     * @param other other instance
     */
    RefCountObject(const RefCountObject& other) BOOST_NOEXCEPT;
    /**
     * Copy assignment operator
     * 
     * @param other other instance
     * @return reference to this instance
     */
    RefCountObject& operator=(const RefCountObject& other) BOOST_NOEXCEPT;
    /**
     * Move constructor
     * 
     * @param other other instance
     */
    RefCountObject(RefCountObject&& other) BOOST_NOEXCEPT;    
    // move assignment operator broken due to virtual base class
    /**
     * Deleted move assignment operator, broken due to virtual base class
     * 
     * @param other other instance
     * @return reference to this instance
     */
    RefCountObject& operator=(RefCountObject&& other) = delete;
    
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
        return dynamic_cast<T*> (this->get_impl_ptr().get());
    }
    /**
     * Auxiliary Impl pointer accessor for const methods forwarding
     * 
     * @return pointer to Impl instance
     */
    template <typename T> T* get_impl_const() const {
        return dynamic_cast<T*> (this->get_impl_ptr_const().get());
    }
    
public:
    /**
     * Constructor to be called from other constructors
     */
    RefCountObject(std::shared_ptr<RefCountObject::Impl> pimpl) BOOST_NOEXCEPT;
    /**
     * Unique pointer access, made public only for downcast support,
     * should NOT be used in normal client code
     * 
     * @return unique_ptr to Impl instance
     */
    std::shared_ptr<RefCountObject::Impl>& get_impl_ptr();
    
private:
    /**
     * Pointer to Impl instance
     */
    std::shared_ptr<RefCountObject::Impl> pimpl = nullptr;
    /**
     * Auxiliary method for const methods forwarding
     * 
     * @return 
     */
    const std::shared_ptr<RefCountObject::Impl>& get_impl_ptr_const() const;
    
};

} // namespace
}

#endif	/* REFCOUNTOBJECT_HPP */

