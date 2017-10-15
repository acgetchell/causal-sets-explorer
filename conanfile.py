from conans import ConanFile, CMake

class CausalSetsExplorer(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "Boost/1.64.0@eliaskousk/stable", "gmock/1.8.0@meshell/stable"
    generators = "cmake"

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib", dst="bin", src="bin")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()