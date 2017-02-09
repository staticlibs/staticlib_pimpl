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
 * File:   pimpl_object.cpp
 * Author: alex
 * 
 * Created on October 3, 2014, 6:21 PM
 */

#include "staticlib/pimpl/pimpl_object.hpp"

namespace staticlib {
namespace pimpl {

pimpl_object::~pimpl_object() STATICLIB_NOEXCEPT = default;

pimpl_object::pimpl_object(pimpl_object&& other) STATICLIB_NOEXCEPT :
pimpl(std::move(other.pimpl)) { }

pimpl_object& pimpl_object::operator=(pimpl_object&& other) STATICLIB_NOEXCEPT {
    this->pimpl = std::move(other.pimpl);
    return *this;
}

pimpl_object::pimpl_object(std::nullptr_t, std::unique_ptr<pimpl_object::Impl> pimpl) STATICLIB_NOEXCEPT :
pimpl(std::move(pimpl)) { };

std::unique_ptr<pimpl_object::Impl>& pimpl_object::get_impl_ptr() const {
    if (nullptr != this->pimpl.get()) {
        return this->pimpl;
    }
    throw pimpl_exception();
}

pimpl_object::Impl::~Impl() STATICLIB_NOEXCEPT = default;

pimpl_object::Impl::Impl() STATICLIB_NOEXCEPT = default;

} // namespace
}
