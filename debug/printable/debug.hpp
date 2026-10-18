#include "inc/printable.hpp"

#define PRINT_TOKEN_STREAM(tokens) \
    ::pratt::debug::Printable::showStream(tokens, std::cout)

#define PRINT_TOKEN_CSTREAM(tokens, stream) \
    ::pratt::debug::Printable::showStream(tokens, stream)
