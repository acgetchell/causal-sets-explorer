from conans import ConanFile, CMake

class CausalSetsExplorer(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "boost/1.68.0@conan/stable", "catch2/2.3.0@bincrafters/stable"
    generators = "cmake"
    default_options = "Boost:header_only=True"

    def build(self):
        cmake = CMake(self)
        cmake.verbose = True
        cmake.configure(args=["CMAKE_BUILD_TYPE=Release"])
        cmake.build()

    def build_requirements(self):
        self.build_requires("cmake_installer/3.11.3@conan/stable")