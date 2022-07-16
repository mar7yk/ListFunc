include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(TEST_FILES
        EngineTest.cpp
        LexerTest.cpp
        )

add_executable(test ${TEST_FILES})

add_subdirectory(lib/googletest-master)

target_link_libraries(test gtest gtest_main)
target_link_libraries(test src)