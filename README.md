# causal-sets-explorer
[![Build Status](https://img.shields.io/travis/acgetchell/causal-sets-explorer.svg?label=Linux/MacOS)](https://travis-ci.org/acgetchell/causal-sets-explorer)
[![Windows Build status](https://img.shields.io/appveyor/ci/acgetchell/causal-sets-explorer/master.svg?label=Windows)](https://ci.appveyor.com/project/acgetchell/causal-sets-explorer)

[Causal sets][causets] explorer will eventually perform graph-theoretic calculations on Causal sets.

It's also a test-bed for [CDT-plusplus].

## Initial Set Up
This project uses the [Conan C/C++ package manager][conan].
To get started, first install `Conan`.

On MacOS using [Homebrew][homebrew], for example, do:

~~~
brew install conan
~~~

On Windows/Linux:
~~~
pip install conan
~~~

Next, clone this repo:

~~~
git clone https://github.com/acgetchell/causal-sets-explorer.git
cd causal-sets-explorer
~~~

Next, we'll let `Conan` auto-detect your compiler settings:

~~~
conan profile new default --detect
~~~

Now, `Conan` will build and link all the dependencies and compile:

~~~
mkdir build && cd build
conan install .. -pr default
conan build ..
~~~

The executable will be in the `bin` directory.

If you want to run tests, you can do:

~~~
ctest -C Release
~~~

This is mostly automated in the `build.sh` script.

[conan]: https://www.conan.io
[causets]: https://en.wikipedia.org/wiki/Causal_sets
[homebrew]: https://brew.sh/
[cdt-plusplus]: https://github.com/acgetchell/CDT-plusplus
[profile]: https://github.com/acgetchell/causal-sets-explorer/blob/devel/.ci/gcc