Staticlibs PIMPL library
========================

This project is part of [Staticlibs](http://staticlibs.net/).

This project contains implementation of [PIMPL idiom](http://herbsutter.com/gotw/_100/).

Link to [API documentation](http://staticlibs.github.com/staticlib_pimpl/docs/html/namespacestaticlib_1_1pimpl.html).

PIMPL implementation
--------------------

TODO: description and example

How to build
------------

[CMake](http://cmake.org/) is required for building.

Staticlib toolchain name must be specified as a `STATICLIB_TOOLCHAIN` parameter to `cmake` command
unless you are using GCC on Linux x86_64 (`linux_amd64_gcc` toolchain) that is default.

Example build for Windows x86_64 with Visual Studio 2013 Express, run the following commands 
from the development shell `C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013 x64 Cross Tools Command Prompt` :

    git clone https://github.com/staticlibs/staticlib_pimpl.git
    cd staticlib_utils
    git submodule update --init --recursive
    mkdir build
    cd build
    cmake .. -DSTATICLIB_TOOLCHAIN=windows_amd64_msvc -G "NMake Makefiles"
    nmake
    nmake test

License information
-------------------

This project is released under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0)

Changelog
---------

**2015-05-19**

 * 1.0.0, initial public version
