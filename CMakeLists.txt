cmake_minimum_required(VERSION 3.20)

project(PrattParser LANGUAGES CXX)

add_subdirectory(debug)
add_subdirectory(lexer)
add_subdirectory(token)

add_executable(PrattParser main.cc)

target_link_libraries(PrattParser
    PRIVATE
        Lexer
        Printable
)