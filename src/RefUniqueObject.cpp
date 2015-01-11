/* 
 * File:   RefUniqueObject.cpp
 * Author: alex
 * 
 * Created on October 3, 2014, 6:21 PM
 */

#include "staticlib/refobjects/RefUniqueObject.hpp"

namespace staticlib {
namespace refobjects {

RefUniqueObject::~RefUniqueObject() noexcept = default;

RefUniqueObject::RefUniqueObject(RefUniqueObject&& other) noexcept :
pimpl(std::move(other.pimpl)) { }

RefUniqueObject& RefUniqueObject::operator=(RefUniqueObject&& other) noexcept {
    this->pimpl = std::move(other.pimpl);
    return *this;
}

RefUniqueObject::RefUniqueObject(std::unique_ptr<RefUniqueObject::Impl> pimpl) noexcept :
pimpl(std::move(pimpl)) { };

std::unique_ptr<RefUniqueObject::Impl>& RefUniqueObject::get_impl_ptr() {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw RefObjectMovedFromException();
}

const std::unique_ptr<RefUniqueObject::Impl>& RefUniqueObject::get_impl_ptr_const() const {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw RefObjectMovedFromException();
}

RefUniqueObject::Impl::~Impl() noexcept = default;

RefUniqueObject::Impl::Impl() noexcept = default;

} // namespace
}

