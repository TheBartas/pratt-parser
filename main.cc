#include <memory>

#include "lexer.hpp"
#include "parser.hpp"
#include "debug.hpp"
#include "ast.hpp"

int main() {
    // Aliases
    using ALexer = ::pratt::lexer::Lexer;
    using ASTNode = ::pratt::ast::expr::Expr;

    // Examples
    std::string ex1 = "4 + 5 * 5 / var";

    // Lexer
    ALexer lexer(std::string_view{ex1});
    const auto tokens = lexer.tokenize();

    PRINT_TOKEN_STREAM(tokens);

    // Example AST
    const auto AST = ::pratt::ast::expr::BinaryExpr(
        "+",
        std::make_unique<::pratt::ast::expr::NumberExpr>("5"),
        std::make_unique<::pratt::ast::expr::BinaryExpr>(
            "*",
            std::make_unique<::pratt::ast::expr::NumberExpr>("3"),
            std::make_unique<::pratt::ast::expr::NumberExpr>("7")
        )
    );

    PRINT_AST(AST);

    // Parser
    ::pratt::parser::Parser parser{tokens};
    const std::unique_ptr<::pratt::ast::expr::Expr> AST_TEST = parser.parse();

    PRINT_AST(*AST_TEST);
}