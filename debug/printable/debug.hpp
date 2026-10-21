#include "inc/printable.hpp"

#define PRINT_TOKEN_STREAM(tokens) \
    ::pratt::debug::Printable::printStream(tokens, std::cout)

#define PRINT_TOKEN_CSTREAM(tokens, stream) \
    ::pratt::debug::Printable::printStream(tokens, stream)

#define PRINT_AST(ast) \
    ::pratt::debug::Printable::printAST(ast);
