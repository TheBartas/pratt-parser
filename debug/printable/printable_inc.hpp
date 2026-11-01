#ifndef PRATT_PARSING_PRINTABLE_INC_H
#define PRATT_PARSING_PRINTABLE_INC_H

#include "inc/printable.hpp"

#define PRINT_TOKEN_STREAM(tokens) \
    ::pratt::debug::printable::Printable::printStream(tokens, std::cout)

#define PRINT_TOKEN_STREAM_CONFIG(tokens, stream) \
    ::pratt::debug::printable::Printable::printStream(tokens, stream)

#define PRINT_AST(ast) \
    ::pratt::debug::printable::Printable::printAST(ast, {.open = "( ", .close = " )", .space = " "});

#define PRINT_AST_CONFIG(ast, config) \
    ::pratt::debug::printable::Printable::printAST(ast, config);

#endif