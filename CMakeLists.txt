cmake_minimum_required(VERSION 3.20)

project(PrattParser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(ast)
add_subdirectory(debug)
add_subdirectory(lexer)
add_subdirectory(token)
add_subdirectory(parser)

add_executable(PrattParser main.cc)

target_link_libraries(PrattParser
    PRIVATE
        Lexer
        Parser
        Printable
)