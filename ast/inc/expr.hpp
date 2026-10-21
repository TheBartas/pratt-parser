#ifndef PRATT_PARSING_AST_EXPR
#define PRATT_PARSING_AST_EXPR

#include <memory>
#include <iostream>

namespace pratt::ast::expr {
    class Expr {
        public:
            virtual ~Expr() = default;
            virtual void printExpr() const = 0;
    };
}; // pratt::ast::expr

namespace pratt::ast::expr {
    using BaseExpr = ::pratt::ast::expr::Expr;
    using ASTNode = std::unique_ptr<BaseExpr>;
}; // pratt::ast::expr

#endif