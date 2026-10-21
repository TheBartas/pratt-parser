add_library(Printable
    src/printable.cc
)

target_include_directories(Printable
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Printable
    PRIVATE
        Token
    PUBLIC
        AST
)