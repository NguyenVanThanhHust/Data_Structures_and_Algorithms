project(main)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-O2")

add_executable(main main.cpp)

add_executable(brute_force brute_force.cpp)

add_executable(generate_test_case generate_test_case.cpp)

add_executable(compare compare.cpp)