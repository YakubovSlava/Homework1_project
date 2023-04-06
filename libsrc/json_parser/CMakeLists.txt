project(json_parser)

set(JSON_PARSER_SRC_FILES
        src/json_parser.cpp
)

add_library(json_parser_lib STATIC ${JSON_PARSER_SRC_FILES})
