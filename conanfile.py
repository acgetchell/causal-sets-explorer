from conans import ConanFile, CMake

class CausalSetsExplorer(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "Boost/1.64.0@inexorgame/stable", "gmock/1.8.0@meshell/stable"
    generators = "cmake"
    default_options = "Boost:header_only=True"

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib", dst="bin", src="bin")

    def build(self):
        cmake = CMake(self)
        cmake.verbose = True
        cmake.configure(args=["CMAKE_BUILD_TYPE=Release", "GMOCK_TESTS:BOOL=ON"])
        cmake.build()