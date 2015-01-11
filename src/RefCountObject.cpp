/* 
 * File:   RefCountObject.cpp
 * Author: alex
 * 
 * Created on October 3, 2014, 6:21 PM
 */

#include "staticlib/refobjects/RefObjectEmptyException.hpp"
#include "staticlib/refobjects/RefCountObject.hpp"

namespace staticlib {
namespace refobjects {

RefCountObject::~RefCountObject() noexcept = default;

RefCountObject::RefCountObject(const RefCountObject& other) noexcept :
pimpl(other.pimpl) { }

RefCountObject& RefCountObject::operator=(const RefCountObject& other) noexcept {
    this->pimpl = other.pimpl;
    return *this;
}

RefCountObject::RefCountObject(RefCountObject&& other) noexcept :
pimpl(std::move(other.pimpl)) { }

RefCountObject::RefCountObject(std::shared_ptr<RefCountObject::Impl> pimpl) noexcept :
pimpl(pimpl) { }

std::shared_ptr<RefCountObject::Impl>& RefCountObject::get_impl_ptr() {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw RefObjectMovedFromException();
}

const std::shared_ptr<RefCountObject::Impl>& RefCountObject::get_impl_ptr_const() const {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw RefObjectMovedFromException();
}

RefCountObject::Impl::~Impl() noexcept = default;

RefCountObject::Impl::Impl() noexcept = default;


} // namespace
}
