
set(PART 01)

set(PUZZLE puzzle${DAY}${PART})
set(TEST test${DAY}${PART})
set(SOLVER solver${DAY})

add_executable(${TEST} test.cc)
target_link_libraries(${TEST} PRIVATE CONAN_PKG::gtest)
target_link_libraries(${TEST} PRIVATE ${SOLVER})
gtest_discover_tests(${TEST})

add_executable(${PUZZLE} puzzle.cc ../data.hh)
target_link_libraries(${PUZZLE} PRIVATE CONAN_PKG::fmt)
target_link_libraries(${PUZZLE} PRIVATE ${SOLVER})
