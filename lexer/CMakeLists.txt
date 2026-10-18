add_library(Lexer
    src/lexer.cc
)

target_include_directories(Lexer
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(Lexer
    PUBLIC
        Token
)