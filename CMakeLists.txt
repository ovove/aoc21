cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_COMPILER /opt/local/bin/gcc)
set(CMAKE_CXX_COMPILER /opt/local/bin/g++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(aoc21 CXX)

include(cmake/ProjectSettings.cmake)
include(cmake/RunConan.cmake)
include(cmake/StaticAnalyzers.cmake)

enable_testing()
include(GoogleTest)

add_subdirectory(day01)
add_subdirectory(day02)
add_subdirectory(day03)
add_subdirectory(day04)
add_subdirectory(day05)
add_subdirectory(day06)
add_subdirectory(day07)
