# causal-sets-explorer
[![Build Status](https://travis-ci.org/acgetchell/causal-sets-explorer.svg?branch=master)](https://travis-ci.org/acgetchell/causal-sets-explorer)
[![Build status](https://ci.appveyor.com/api/projects/status/3fhdjahof4d19ue0?svg=true)](https://ci.appveyor.com/project/acgetchell/causal-sets-explorer)

[Causal set][causets] explorer will eventually perform graph-theoretic calculations on Causal sets.

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
