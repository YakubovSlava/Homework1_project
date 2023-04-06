project(json_test)

set(JSON_TEST_SRC_FILES
        src/json_unit_test.cpp
)

add_executable(json_test ${JSON_TEST_SRC_FILES})
target_link_libraries(json_test PRIVATE json_parser_lib
        GTest::gtest_main)

#set (CMAKE_CXX_FLAGS "-g -pthread -lgtest_main  -lgtest -lpthread")
set_target_properties(json_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
