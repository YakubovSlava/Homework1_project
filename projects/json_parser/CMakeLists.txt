project(main_parser)

set(MAIN_PARSER_SRC_FILES
        src/main_parser.cpp
)

add_executable(main_parser ${MAIN_PARSER_SRC_FILES})
target_link_libraries(main_parser PRIVATE json_parser_lib)
set_target_properties(main_parser PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
