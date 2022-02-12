
set(PART 01)

set(PUZZLE puzzle${DAY}${PART})
set(TEST test${DAY}${PART})

add_executable(${TEST} test.cc solver.hh)
target_link_libraries(${TEST} CONAN_PKG::gtest)
gtest_discover_tests(${TEST})

add_executable(${PUZZLE} puzzle.cc solver.hh ../data.hh)
target_link_libraries(${PUZZLE} CONAN_PKG::fmt)
