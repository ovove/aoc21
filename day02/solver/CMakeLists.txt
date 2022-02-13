
set(SOLVER solver${DAY})
add_library(${SOLVER} OBJECT)
target_sources(${SOLVER} PUBLIC solver.hh)
target_include_directories(${SOLVER} PUBLIC .)
set_target_properties(${SOLVER} PROPERTIES LINKER_LANGUAGE CXX)
