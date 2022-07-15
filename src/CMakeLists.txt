project(ListFunc_src)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Engine.cpp Engine.hpp
        )

add_library(src STATIC ${SOURCE_FILES})