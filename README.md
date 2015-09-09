Staticlibs PIMPL library
========================

This project is a part of [Staticlibs](http://staticlibs.net/).

This project contains implementation of [PIMPL idiom](http://herbsutter.com/gotw/_100/).
This implementation deliberately does not use templates, template-based implementation can be found [here](http://herbsutter.com/gotw/_101/).

Link to [API documentation](http://staticlibs.github.io/staticlib_pimpl/docs/html/namespacestaticlib_1_1pimpl.html).

PIMPL implementation
--------------------

This library implements PIMPL idiom (also known as "opaque pointers" or "compilation firewall").
The main part is a `PimplObject` class that declares an inner protected `PimplObject::Impl` class
and a `std::unique_ptr<PimplObject::Impl>` pointing to the instance of `Impl` class. `PimplObject`
also implements move-constructor and move-assigning-operator that effectively move the `Impl` pointer.
"moved-from" `PimplObject` (or its inheritor) will contain a "moved-from" `unique_ptr` pointer to `Impl`.
To prevent access to `nullptr` `Impl` pointer access to it is checked on every call and `PimplException`
is thrown if the object is in "moved-from" state.

This implementation supports single-inheritance PIMPL hierarchies, where single pointer to `Impl` objects
will always be stored in top `PimplObject` object. It also supports "downcasting" objects to
classes lower in hierarchy, so you can have a `std::vector<Shape>` where on futher processing
each element can be downcasted to `Circle` or `Rectangle` classes. Implementation does not support
multiple inheritance (neither normal nor virtual one) 

To use your class as a move-only opaque-pointer object you should extend it from `PimplObject`
and declare inside protected `Impl` class that will hold all the object state and will implement all 
the business logic. That class should also implement constructor specific to `PimplObject` 
that will take `std::unique_ptr<PimplObject::Impl>` and forward it to the parent class constructor.
For MSVC implementation of move-constructor and move-assigning-operator (forwarding to parent one) is also required (other 
compiler can generate them based on parent class).

All business-specific constructors and methods of that class will need to be implemented in `Impl`
class and then declared and implemented as a "forward arguments" call in main class. To simplify this
task a set of macros is implemented. Some of the macros use a private partial copy of 
[Boost.Preprocessor](http://www.boost.org/doc/libs/1_58_0/libs/preprocessor/doc/index.html)
library (with all elements renamed with `STATICLIB_PP_` prefix so it won't conflict with different versions
of Boost.Preprocessor). All the macros are completely optional (see their usage in example below):

 - `PIMPL_CONSTRUCTOR` and `PIMPL_INHERIT_CONSTRUCTOR`: creates a "technical" constructor for the first
`PimplObject` or some of its descendants, move-constructor and move-assignment-operator;
it is roughly equivalent to C++11 constructor inheritance but also supports MSVC compiler.
 - `PIMPL_FORWARD_METHOD` and `PIMPL_FORWARD_METHOD_STATIC`: forwards a method call from main object to `Impl` one;
this macros also will catch and rethrow the exceptions to produce a partial stack trace.
 - `PIMPL_FORWARD_CONSTRUCTOR`: forwards business constructor call from main object to `Impl` one

Usage example
-------------

This is an example of a single PIMPL class, you can find the hierarchy example in `test` directory.

Class declaration `HttpResponse.hpp`:

    class HttpResponse : public staticlib::pimpl::PimplObject {
    protected:
        class Impl;
    public:
        PIMPL_CONSTRUCTOR(HttpResponse)

        HttpResponse(const string& response);

        unsigned int get_status_code() const noexcept;

        virtual void add_header(const std::string& key, const std::string& value);
        ...
    };

Class definition `HttpResponse.cpp`:

    // `Impl` class definition
    class HttpResponse::Impl : public Intermediate::Impl {
        unsigned int status_code = 200;
        std::string response;
        ...
    public:
        Impl(const string& response):
        response(response) { }

        unsigned int get_status_code() const noexcept {
            return this->status_code;
        }

        virtual void add_header(const std::string& key, const std::string& value) {
            ...
        }
    };
    // HttpResponse class definition

    // the last argument is for modifiers that are empty here
    PIMPL_FORWARD_CONSTRUCTOR(HttpResponse, (const string&), ())
    // no arguments and two modifiers here
    PIMPL_FORWARD_METHOD(Derived, unsigned int, get_status_code, (void), (const)(noexcept))
    // two arguments and no modifiers
    PIMPL_FORWARD_METHOD(Derived, void, add_header, (const std::string&)(const std::string&), ())


For PIMPL hierarchy additional private header file will be required for each intermediate class 
in hierarchy to allow `Impl` classes inheritance.

How to build
------------

[CMake](http://cmake.org/) is required for building.

[TODO]

License information
-------------------

This project is released under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0)

Changelog
---------

**2015-09-05**

 * version 1.0.4 - remove dependency on `staticlib_utils`

**2015-07-30**

 * version 1.0.3 - disambiguate internal constructor from business ones

**2015-07-08**

 * version 1.0.2 - toolchains update

**2015-06-30**

 * version 1.0.1 - toolchains update

**2015-05-19**

 * 1.0.0, initial public version
