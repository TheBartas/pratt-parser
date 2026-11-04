#include <memory>

#include <lexer.hpp>
#include <parser.hpp>
#include <ast.hpp>
#include <debug.hpp>

int main() {
    // Aliases
    using ALexer = ::pratt::lexer::Lexer;
    using ASTNode = ::pratt::ast::expr::Expr;
    using AConfig = ::pratt::ast::context::ASTPrintableContextCfg;

    // Examples
    std::string ex1 = "(4 + 5) * 5 / var"; // ( / ( * ( + 4 5 ) 5 ) var )
    std::string ex2 = "(4 * (var - 34) / 5 + 2)"; // + ( / ( * ( - ( var 34 ) ) 4 ) 5 ) 2
    std::string ex3 = "-3";
    std::string ex4 = "- 3";
    std::string ex5 = "-3 * 5";
    std::string ex6 = "(-3) + 4 * 6 -4";

    // Lexer
    ALexer lexer(std::string_view{ex3});
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
    const AConfig cfg{.open = "{ ", .close = " }"};
    PRINT_AST_CONFIG(AST, cfg);

    // Parser
    ::pratt::parser::Parser parser{tokens};
    const std::unique_ptr<::pratt::ast::expr::Expr> AST_TEST = parser.parse();

    PRINT_AST(*AST_TEST);
}