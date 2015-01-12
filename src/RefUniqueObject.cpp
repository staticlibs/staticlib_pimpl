/* 
 * File:   RefUniqueObject.cpp
 * Author: alex
 * 
 * Created on October 3, 2014, 6:21 PM
 */

#include "staticlib/refobjects/RefUniqueObject.hpp"

namespace staticlib {
namespace refobjects {

RefUniqueObject::~RefUniqueObject() BOOST_NOEXCEPT = default;

RefUniqueObject::RefUniqueObject(RefUniqueObject&& other) BOOST_NOEXCEPT :
pimpl(std::move(other.pimpl)) { }

RefUniqueObject& RefUniqueObject::operator=(RefUniqueObject&& other) BOOST_NOEXCEPT {
    this->pimpl = std::move(other.pimpl);
    return *this;
}

RefUniqueObject::RefUniqueObject(std::unique_ptr<RefUniqueObject::Impl> pimpl) BOOST_NOEXCEPT :
pimpl(std::move(pimpl)) { };

std::unique_ptr<RefUniqueObject::Impl>& RefUniqueObject::get_impl_ptr() {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw RefObjectException();
}

const std::unique_ptr<RefUniqueObject::Impl>& RefUniqueObject::get_impl_ptr_const() const {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw RefObjectException();
}

RefUniqueObject::Impl::~Impl() BOOST_NOEXCEPT = default;

RefUniqueObject::Impl::Impl() BOOST_NOEXCEPT = default;

} // namespace
}

