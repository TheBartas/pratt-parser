add_subdirectory(Printable)
add_subdirectory(trace)

add_library(Debug INTERFACE)

target_include_directories(Debug INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Debug INTERFACE
    Printable
    Trace
)