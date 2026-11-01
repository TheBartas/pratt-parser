add_library(Trace
    src/trace.cc
)

target_include_directories(Trace
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Trace
    PRIVATE
        Token
    PUBLIC
        AST
)