# causal-sets-explorer

[![Linux Clang](https://github.com/acgetchell/causal-sets-explorer/actions/workflows/linux-clang.yml/badge.svg)](https://github.com/acgetchell/causal-sets-explorer/actions/workflows/linux-clang.yml)
[![Linux GCC](https://github.com/acgetchell/causal-sets-explorer/actions/workflows/linux-gcc.yml/badge.svg)](https://github.com/acgetchell/causal-sets-explorer/actions/workflows/linux-gcc.yml)
[![macOS](https://github.com/acgetchell/causal-sets-explorer/actions/workflows/macos.yml/badge.svg)](https://github.com/acgetchell/causal-sets-explorer/actions/workflows/macos.yml)
[![Windows](https://github.com/acgetchell/causal-sets-explorer/actions/workflows/windows-msvc.yml/badge.svg)](https://github.com/acgetchell/causal-sets-explorer/actions/workflows/windows-msvc.yml)
[![CodeQL](https://github.com/acgetchell/causal-sets-explorer/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/acgetchell/causal-sets-explorer/actions/workflows/codeql-analysis.yml)

[Causal sets][causets] explorer will eventually perform graph-theoretic calculations on Causal sets.

It's also a test-bed for [CDT-plusplus].

## Initial Set Up

This project uses [vcpkg].
To get started, first install `vcpkg`.

~~~zsh
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg integrate install
~~~

[vcpkg] is then invoked by [CMake] in [vcpkg manifest][vcpkg-manifest] mode to install project dependencies listed in `vcpkg.json` into the local `vcpkg_installed` directory.

Next, clone this repo:

~~~zsh
git clone https://github.com/acgetchell/causal-sets-explorer.git
cd causal-sets-explorer
~~~

Now we'll install dependencies:

~~~zsh
vcpkg install --feature-flags=manifests
~~~

Finally, you can build with `CMake`:

~~~zsh
cmake -S . -B build
cmake --build build
~~~

The executable will be in the `build` directory.

If you want to run tests, you can do:

~~~zsh
cd build
ctest --output-on-failure -j2
~~~

This is mostly automated in `scripts/build.sh`.

## Contributing

Please ensure you do the following:

- Whitespace formatting using `git diff --check HEAD^`
- [clang-format] with project settings using `git-clang-format`
- Address Sanitzer with `asan.sh`
- [clang-tidy] with `clang-tidy.sh`
- [cppcheck] with `cppcheck.sh`

[causets]: https://en.wikipedia.org/wiki/Causal_sets
[cdt-plusplus]: https://github.com/acgetchell/CDT-plusplus
[vcpkg]: https://vcpkg.io/en/index.html
[CMake]: https://cmake.org
[vcpkg-manifest]: https://github.com/microsoft/vcpkg/blob/master/docs/users/manifests.md
[clang-format]: https://clang.llvm.org/docs/ClangFormat.html
[clang-tidy]: https://clang.llvm.org/extra/clang-tidy/
[cppcheck]: https://cppcheck.sourceforge.io
