#ifndef PRATT_PARSING_AST_EXPR_BINARY
#define PRATT_PARSING_AST_EXPR_BINARY

#include <memory>

#include "expr.hpp"

namespace pratt::ast::expr {
    class BinaryExpr final : public BaseExpr {
        public:
            using ASTNode = std::unique_ptr<BaseExpr>;

            BinaryExpr(
                char _op,
                ASTNode _lhs,
                ASTNode _rhs
            ) 
                : op{_op}, lhs{std::move(_lhs)}, rhs{std::move(_rhs)} {}
        private:
            char op;
            ASTNode lhs;
            ASTNode rhs;

    };
}; // pratt::ast::expr

#endif