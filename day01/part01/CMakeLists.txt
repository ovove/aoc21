
set(PART 01)

set(PUZZLE puzzle${DAY}${PART})
set(TEST test${DAY}${PART})

add_executable(${TEST} test.cc)
target_link_libraries(${TEST} PRIVATE CONAN_PKG::gtest)
gtest_discover_tests(${TEST})

add_executable(${PUZZLE} puzzle.cc)
target_link_libraries(${PUZZLE} PRIVATE CONAN_PKG::fmt)
