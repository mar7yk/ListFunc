cmake_minimum_required(VERSION 3.21)
project(ListFunc)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

add_executable(run ${SOURCE_FILES})

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(run src)
