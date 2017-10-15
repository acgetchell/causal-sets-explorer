# causal-sets-explorer
[![Build Status](https://travis-ci.org/acgetchell/causal-sets-explorer.svg?branch=master)](https://travis-ci.org/acgetchell/causal-sets-explorer)
[![Build status](https://ci.appveyor.com/api/projects/status/3fhdjahof4d19ue0?svg=true)](https://ci.appveyor.com/project/acgetchell/causal-sets-explorer)

[Causal set][3] explorer will eventually perform graph-theoretic calculations on Causal sets.

## Initial Set Up
This project uses the [Conan C/C++ package manager][1]. To get started on MacOS
using [Homebrew][4], for example, do:

~~~
brew install conan
git clone https://github.com/acgetchell/causal-sets-explorer.git
cd causal-sets-explorer
mkdir build && cd build
conan install .. --build=missing
conan build ..
~~~

Linux and Windows are nearly identical, with `pip install conan` replacing `brew install conan`.

You also need [CMake][cmake], at least until I figure out how to [get Conan to install it][5].

If you get a message like:

~~~
zlib/1.2.8@lasote/stable: WARN: Forced build from source
ERROR: Error while trying to get recipe sources for zlib/1.2.8@lasote/stable. No remote defined
~~~

Then you've already exported that recipe, and [need to do][2], e.g.:

~~~
conan remove zlib/1.2.8@lasote/stable
~~~

Before re-running `conan install`.

[1]: https://www.conan.io
[2]: https://github.com/conan-io/conan/issues/1067#issuecomment-284219916
[3]: https://en.wikipedia.org/wiki/Causal_sets
[4]: https://brew.sh/
[5]: http://conanio.readthedocs.io/en/latest/mastering/build_requires.html#build-requires
[cmake]: https://cmake.org/
