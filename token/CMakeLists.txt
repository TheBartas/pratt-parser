add_library(Token
    src/token.cc
)

target_include_directories(Token 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)