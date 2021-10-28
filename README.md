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

Now we'll create and activate a named environment to group together the dependencies:
~~~
spack env create causal-sets
spacktivate causal-sets
~~~

And then populate it with the library dependencies:

~~~
spack add boost
spack add catch2
~~~

Verify you have these dependencies:

~~~
spack find
==> In environment causal-sets
==> Root specs
boost   catch2
~~~

Now install the environment:

~~~
spack install
~~~

Finally, you can build with `CMake`:

~~~
cmake -D CMAKE_BUILD_TYPE=Release -S . -B build
cmake --build build
~~~

The executable will be in the `bin` directory.

If you want to run tests, you can do:

~~~
ctest --output-on-failure -j2
~~~

This is mostly automated in `scripts/build.sh`.

[causets]: https://en.wikipedia.org/wiki/Causal_sets
[cdt-plusplus]: https://github.com/acgetchell/CDT-plusplus
[Spack]: https://spack.io