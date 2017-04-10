Staticlibs PIMPL library
========================

This project is a part of [Staticlibs](http://staticlibs.net/).

This project contains an implementation of the [PIMPL idiom](http://herbsutter.com/gotw/_100/).
This implementation deliberately does not use templates, 
existing template-based implementation can be found [here](http://herbsutter.com/gotw/_101/).

Link to the [API documentation](http://staticlibs.github.io/staticlib_pimpl/docs/html/namespacestaticlib_1_1pimpl.html).

PIMPL implementation
--------------------

This library implements a PIMPL idiom (also known as "opaque pointers" or "compilation firewall").
The main part is a `sl::pimpl::object` class that declares an inner protected `sl::pimpl::object::impl` class
and a `std::unique_ptr<sl::pimpl::object::impl>` pointing to the instance of `impl` class. `sl::pimpl::object`
also implements move-constructor and move-assigning-operator that effectively move the `impl` pointer.
"moved-from" `sl::pimpl::object` (or its inheritor) will contain a "moved-from" `unique_ptr` pointer to `impl`.
To prevent access to `nullptr` `impl` pointer access to it is checked on every call and `pimpl_exception`
is thrown if the object is in "moved-from" state.

This implementation supports single-inheritance PIMPL hierarchies, where single pointer to `impl` objects
will always be stored in top `sl::pimpl::object` object. It also supports "downcasting" objects to
classes lower in hierarchy, so you can have a `std::vector<Shape>` where on futher processing
each element can be downcasted to `Circle` or `Rectangle` classes. Implementation does not support
multiple inheritance (neither normal nor virtual one) 

To use your class as a move-only opaque-pointer object you should extend it from `sl::pimpl::object`
and declare inside protected `impl` class that will hold all the object state and will implement all 
the business logic. That class should also implement constructor specific to `sl::pimpl::object` 
that will take `std::unique_ptr<sl::pimpl::object::impl>` and forward it to the parent class constructor.
For MSVC implementation of move-constructor and move-assigning-operator (forwarding to parent one) is also required (other 
compiler can generate them based on parent class).

All business-specific constructors and methods of that class will need to be implemented in `impl`
class and then declared and implemented as a "forward arguments" call in main class. To simplify this
task a set of macros is implemented. Some of the macros use a private partial copy of 
[Boost.Preprocessor](http://www.boost.org/doc/libs/1_58_0/libs/preprocessor/doc/index.html)
library (with all elements renamed with `STATICLIB_PP_` prefix so it won't conflict with different versions
of Boost.Preprocessor). All the macros are completely optional (see their usage in example below):

 - `PIMPL_CONSTRUCTOR` and `PIMPL_INHERIT_CONSTRUCTOR`: creates a "technical" constructor for the first
`sl::pimpl::object` or some of its descendants, move-constructor and move-assignment-operator;
it is roughly equivalent to C++11 constructor inheritance but also supports MSVC compiler.
 - `PIMPL_FORWARD_METHOD` and `PIMPL_FORWARD_METHOD_STATIC`: forwards a method call from main object to `impl` one;
"impl" method must take an extra (first) argument - a reference to a facade class instance 
(to ease access to this facade from inside impl method);
 this macros also will catch and rethrow the exceptions to produce a partial stack trace.
 - `PIMPL_FORWARD_CONSTRUCTOR`: forwards business constructor call from main object to `impl` one;
it also with catch and rethrow possible exceptions

Usage example
-------------

This is an example of a single PIMPL class, you can find the hierarchy example in `test` directory.

Class declaration `http_response.hpp`:

    class http_response : public sl::pimpl::object {
    protected:
        class impl;
    public:
        PIMPL_CONSTRUCTOR(http_response)

        http_response(const string& response);

        unsigned int get_status_code() const noexcept;

        void add_header(const std::string& key, const std::string& value);
        ...
    };

Class definition `http_response.cpp`:

    // `impl` class definition
    class http_response::impl : public intermediate::impl {
        unsigned int status_code = 200;
        std::string response;
        ...
    public:
        impl(const string& response):
        response(response) { }

        unsigned int get_status_code(const http_response&) const noexcept {
            return this->status_code;
        }

        void add_header(http_response&, const std::string& key, const std::string& value) {
            ...
        }
    };
    // http_response class definition

    // the empty parenthesis argument is for modifiers that are empty here
    PIMPL_FORWARD_CONSTRUCTOR(http_response, (const string&), (), http_exception)
    // no arguments and two modifiers here
    PIMPL_FORWARD_METHOD(http_response, unsigned int, get_status_code, (), (const)(noexcept), http_exception)
    // two arguments and no modifiers
    PIMPL_FORWARD_METHOD(http_response, void, add_header, (const std::string&)(const std::string&), (), http_exception)

For PIMPL hierarchy additional private header file will be required for each intermediate class 
in hierarchy to allow `impl` classes inheritance.

How to build
------------

[CMake](http://cmake.org/) is required for building.

[pkg-config](http://www.freedesktop.org/wiki/Software/pkg-config/) utility is used for dependency management.
For Windows users ready-to-use binary version of `pkg-config` can be obtained from [tools_windows_pkgconfig](https://github.com/staticlibs/tools_windows_pkgconfig) repository.
See [StaticlibPkgConfig](https://github.com/staticlibs/wiki/wiki/StaticlibPkgConfig) for Staticlibs-specific details about `pkg-config` usage.

To build the library on Windows using Visual Studio 2013 Express run the following commands using
Visual Studio development command prompt 
(`C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013 x86 Native Tools Command Prompt`):

    git clone https://github.com/staticlibs/staticlib_config.git
    git clone https://github.com/staticlibs/staticlib_support.git
    git clone https://github.com/staticlibs/staticlib_pimpl.git
    cd staticlib_pimpl
    mkdir build
    cd build
    cmake ..
    msbuild staticlib_pimpl.sln

To build on other platforms using GCC or Clang with GNU Make:

    cmake .. -DCMAKE_CXX_FLAGS="--std=c++11"
    make

See [StaticlibsToolchains](https://github.com/staticlibs/wiki/wiki/StaticlibsToolchains) for 
more information about the CMake toolchains setup and cross-compilation.

License information
-------------------

This project is released under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Changelog
---------

**2017-04-10**

 * version 1.2.0
 * classes renamed

**2016-01-16**

 * version 1.1.4
 * minor CMake changes

**2015-12-03**

 * version 1.1.3
 * depend on `staticlib_config` instead of `staticlib_utils`

**2015-11-17**

 * version 1.1.2
 * deplibs cache support

**2015-10-20**

 * version 1.1.1
 * made included macros project-local

**2015-10-19**

 * version 1.1.0
 * forward macros enhancements
 * `pkg-config` integration

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
