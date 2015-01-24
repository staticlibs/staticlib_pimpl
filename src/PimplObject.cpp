/* 
 * File:   PimplObject.cpp
 * Author: alex
 * 
 * Created on October 3, 2014, 6:21 PM
 */

#include "staticlib/pimpl/PimplObject.hpp"

namespace staticlib {
namespace pimpl {

PimplObject::~PimplObject() BOOST_NOEXCEPT = default;

PimplObject::PimplObject(PimplObject&& other) BOOST_NOEXCEPT :
pimpl(std::move(other.pimpl)) { }

PimplObject& PimplObject::operator=(PimplObject&& other) BOOST_NOEXCEPT {
    this->pimpl = std::move(other.pimpl);
    return *this;
}

PimplObject::PimplObject(std::unique_ptr<PimplObject::Impl> pimpl) BOOST_NOEXCEPT :
pimpl(std::move(pimpl)) { };

std::unique_ptr<PimplObject::Impl>& PimplObject::get_impl_ptr() const {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw PimplException();
}

PimplObject::Impl::~Impl() BOOST_NOEXCEPT = default;

PimplObject::Impl::Impl() BOOST_NOEXCEPT = default;

} // namespace
}

