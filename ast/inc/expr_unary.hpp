#ifndef PRATT_PARSING_AST_EXPR_UNARY_H
#define PRATT_PARSING_AST_EXPR_UNARY_H

#include "expr.hpp"

namespace pratt::ast {
    namespace expr {
        class UnaryExpr final : public BaseExpr {
            public:
                UnaryExpr(
                    std::string_view _op,
                    ASTNode _lhs
                ) : op{_op}, rhs{std::move(_lhs)} {}

                void printExpr(const ASTPrintConfig& config) const override {
                    std::cout << config.open << this->op;
                    this->rhs->printExpr(config);
                    std::cout << config.close;
                }
                
            private:
                std::string_view op{};
                ASTNode rhs{};
        };
    }; // pratt::ast::expr
}; // pratt::ast

#endif