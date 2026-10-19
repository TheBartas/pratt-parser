#include "lexer.hpp"
#include "debug.hpp"

int main() {
    // Aliases
    using ALexer = ::pratt::lexer::Lexer;

    // Examples
    std::string ex1 = "4 - 5 * 6.1 + var";

    // Lexer
    ALexer lexer(std::string_view{ex1});
    const auto tokens = lexer.tokenize();

    PRINT_TOKEN_STREAM(tokens);
}