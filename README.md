# causal-sets-explorer
[![Build Status](https://travis-ci.org/acgetchell/causal-sets-explorer.svg?branch=master)](https://travis-ci.org/acgetchell/causal-sets-explorer)

[Causal set][3] explorer performs graph-theoretic calculations on Causal sets.

## Initial Set Up
This project uses the [Conan C/C++ package manager][1]. To get started on MacOS using [Homebrew][4],
for example, do:

~~~
brew install conan
git clone https://github.com/acgetchell/causal-sets-explorer.git
cd causal-sets-explorer
mkdir build && cd build
conan install .. -s compiler=apple-clang -s compiler.version=8.0 -s compiler.libcxx=libc++ --build=missing
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
~~~

Replace the `compiler`, `compiler.version`, and `compiler.libcxx` options with
the ones appropriate to your settings.

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
