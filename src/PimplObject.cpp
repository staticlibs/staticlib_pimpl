/*
 * Copyright 2015, alex at staticlibs.net
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   PimplObject.cpp
 * Author: alex
 * 
 * Created on October 3, 2014, 6:21 PM
 */

#include <string>
#include <ostream>

#include "staticlib/pimpl/pimpl_utils.hpp"
#include "staticlib/pimpl/PimplObject.hpp"

namespace staticlib {
namespace pimpl {

PimplObject::~PimplObject() PIMPL_NOEXCEPT = default;

PimplObject::PimplObject(PimplObject&& other) PIMPL_NOEXCEPT :
pimpl(std::move(other.pimpl)) { }

PimplObject& PimplObject::operator=(PimplObject&& other) PIMPL_NOEXCEPT {
    this->pimpl = std::move(other.pimpl);
    return *this;
}

PimplObject::PimplObject(std::nullptr_t, std::unique_ptr<PimplObject::Impl> pimpl) PIMPL_NOEXCEPT :
pimpl(std::move(pimpl)) { };

std::unique_ptr<PimplObject::Impl>& PimplObject::get_impl_ptr() const {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw PimplException("Impl pointer is empty");
}

std::string PimplObject::to_string() const {
    return pimpl->to_string();
}

std::string PimplObject::Impl::to_string() const {
    return std::string(typeid(*this).name()) + '@' + pimpl_to_string(this);
}

std::ostream& operator<<(std::ostream& stream, const PimplObject& obj) {
    stream << obj.to_string();
    return stream;
}


PimplObject::Impl::~Impl() PIMPL_NOEXCEPT = default;

PimplObject::Impl::Impl() PIMPL_NOEXCEPT = default;

} // namespace
}

