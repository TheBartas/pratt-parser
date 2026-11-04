#ifndef PRATT_PARSING_AST_EXPR_BINARY_H
#define PRATT_PARSING_AST_EXPR_BINARY_H

#include "expr.hpp"

namespace pratt::ast {
    namespace expr {
        class BinaryExpr final : public BaseExpr {
            public:
                BinaryExpr(
                    std::string_view _op,
                    ASTNode _lhs,
                    ASTNode _rhs
                )
                    : op{_op}, lhs{std::move(_lhs)}, rhs{std::move(_rhs)} {}

                void printExpr(const ASTPrintConfig& config) const override {
                    std::cout << config.open << this->op << config.space;
                    this->lhs->printExpr(config);
                    std::cout << config.space;
                    this->rhs->printExpr(config);
                    std::cout << config.close;
                }
                
            private:
                std::string_view op{};
                ASTNode lhs{};
                ASTNode rhs{};

        };
    }; // pratt::ast::expr
}; // pratt::ast

#endif