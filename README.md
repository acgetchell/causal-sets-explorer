# causal-sets-explorer
[![Build Status](https://img.shields.io/travis/acgetchell/causal-sets-explorer.svg?label=Linux/MacOS)](https://travis-ci.org/acgetchell/causal-sets-explorer)
[![Windows Build status](https://img.shields.io/appveyor/ci/acgetchell/causal-sets-explorer/master.svg?label=Windows)](https://ci.appveyor.com/project/acgetchell/causal-sets-explorer)

[Causal sets][causets] explorer will eventually perform graph-theoretic calculations on Causal sets.

It's also a test-bed for [CDT-plusplus].

## Initial Set Up
This project uses [Spack].
To get started, first install `Spack`.

~~~
git clone https://github.com/spack/spack.git
~~~

You'll need to add `Spack` to your environment, e.g. in `.zshrc` append:

~~~
. ~/projects/spack/share/spack/setup-env.sh
~~~

(Or wherever you cloned `Spack`). Next, clone this repo:

~~~
git clone https://github.com/acgetchell/causal-sets-explorer.git
cd causal-sets-explorer
~~~

Now we'll install a dependencies:
~~~
spack install boost
spack install catch2
~~~

And then load into our `$CMAKE_PREFIX_PATH`:

~~~
spack load boost
spack load catch2
~~~

Verify you have the dependencies installed:

~~~
$ spack find
==> 14 installed packages
-- darwin-monterey-skylake / apple-clang@13.0.0 -----------------
berkeley-db@18.1.40  boost@1.77.0  bzip2@1.0.8  catch2@2.13.7  cmake@3.21.4  diffutils@3.8  gdbm@1.19  libiconv@1.16  ncurses@6.2  openssl@1.1.1l  perl@5.34.0  pkgconf@1.8.0  readline@8.1  zlib@1.2.11

~~~

Finally, you can build with `CMake`:

~~~
cmake -S . -B build
cmake --build build
~~~

The executable will be in the `build` directory.

If you want to run tests, you can do:

~~~
cd build
ctest --output-on-failure -j2
~~~

This is mostly automated in `scripts/build.sh`.

[causets]: https://en.wikipedia.org/wiki/Causal_sets
[cdt-plusplus]: https://github.com/acgetchell/CDT-plusplus
[Spack]: https://spack.io