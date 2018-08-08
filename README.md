# causal-sets-explorer
[![Build Status](https://img.shields.io/travis/acgetchell/causal-sets-explorer.svg?label=Linux/MacOS)](https://travis-ci.org/acgetchell/causal-sets-explorer)
[![Windows Build status](https://img.shields.io/appveyor/ci/acgetchell/causal-sets-explorer/master.svg?label=Windows)](https://ci.appveyor.com/project/acgetchell/causal-sets-explorer)

[Causal sets][causets] explorer will eventually perform graph-theoretic calculations on Causal sets.

It's also a test-bed for [CDT-plusplus].

## Initial Set Up
This project uses the [Conan C/C++ package manager][conan]. To get started on MacOS
using [Homebrew][homebrew], for example, do:

~~~
brew install conan
git clone https://github.com/acgetchell/causal-sets-explorer.git
cd causal-sets-explorer
mkdir build && cd build
conan install .. --build=missing -s compiler=apple-clang -s compiler.version=9.1 -s compiler.libcxx=libc++
conan build ..
~~~

Linux and Windows are nearly identical, with `pip install conan` replacing `brew install conan`.

You must also specify compiler options (the above example is for macOS).

(Note that on Linux, you should actually use pip3 and Python 3 in order to avoid [SNIMIssingWarning][sni].)

[conan]: https://www.conan.io
[causets]: https://en.wikipedia.org/wiki/Causal_sets
[homebrew]: https://brew.sh/
[sni]: https://urllib3.readthedocs.io/en/latest/security.html#snimissingwarning
[cdt-plusplus]: https://github.com/acgetchell/CDT-plusplus
