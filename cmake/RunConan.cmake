
# Run conan to download 3:rd part dependencies

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "*** Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD
    "https://github.com/conan-io/cmake-conan/raw/v0.16.1/conan.cmake"
    "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

set (ENV{CONAN_REVISIONS_ENABLED} 1)
include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(
  SETTINGS compiler=gcc
  SETTINGS compiler.version=11.2
#  SETTINGS compiler.libcxx=libstdc++
  SETTINGS compiler.libcxx=libstdc++11
  SETTINGS compiler.cppstd=20
  REQUIRES fmt/8.1.1
  REQUIRES gtest/1.11.0
  OPTIONS
  BASIC_SETUP
  CMAKE_TARGETS # Generate CONAN_PKG:: targets.
  BUILD missing
  ENV CC=${CMAKE_C_COMPILER} CXX=${CMAKE_CXX_COMPILER}
  )
