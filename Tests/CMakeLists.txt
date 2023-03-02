cmake_minimum_required(VERSION 3.24)
project(Tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(true_solution true_solution.cpp)
add_executable(main main.cpp)
add_executable(test_generator test_generator.cpp)
add_executable(fake_solution fake_solution.cpp)

