/* 
 * File:   RefCountObject.cpp
 * Author: alex
 * 
 * Created on October 3, 2014, 6:21 PM
 */

#include "staticlib/refobjects/RefObjectException.hpp"
#include "staticlib/refobjects/RefCountObject.hpp"

namespace staticlib {
namespace refobjects {

RefCountObject::~RefCountObject() BOOST_NOEXCEPT = default;

RefCountObject::RefCountObject(const RefCountObject& other) BOOST_NOEXCEPT :
pimpl(other.pimpl) { }

RefCountObject& RefCountObject::operator=(const RefCountObject& other) BOOST_NOEXCEPT {
    this->pimpl = other.pimpl;
    return *this;
}

RefCountObject::RefCountObject(RefCountObject&& other) BOOST_NOEXCEPT :
pimpl(std::move(other.pimpl)) { }

RefCountObject::RefCountObject(std::shared_ptr<RefCountObject::Impl> pimpl) BOOST_NOEXCEPT :
pimpl(pimpl) { }

std::shared_ptr<RefCountObject::Impl>& RefCountObject::get_impl_ptr() {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw RefObjectException();
}

const std::shared_ptr<RefCountObject::Impl>& RefCountObject::get_impl_ptr_const() const {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw RefObjectException();
}

RefCountObject::Impl::~Impl() BOOST_NOEXCEPT = default;

RefCountObject::Impl::Impl() BOOST_NOEXCEPT = default;


} // namespace
}
