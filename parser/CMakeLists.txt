add_library(Parser
    src/parser.cc
)

target_include_directories(Parser
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(Parser
    PUBLIC
        Lexer
        AST
)