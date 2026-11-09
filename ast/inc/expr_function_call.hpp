#ifndef PRATT_PARSING_AST_EXPR_FUNCTION_CALL_H
#define PRATT_PARSING_AST_EXPR_FUNCTION_CALL_H

#include <vector>

#include "expr.hpp"

namespace pratt::ast {
    namespace expr {
        class FunctionCallExpr final : public BaseExpr {
            public:
                FunctionCallExpr(                    
                    std::string_view _name,
                    std::vector<ASTNode> _args) : name{_name}, args{std::move(_args)} {}

                void printExpr(const ASTPrintConfig& config) const override {
                    // [TODO:0x0002]
                }

            private:
                std::string_view name{};
                std::vector<ASTNode> args{};
        };
    }; // pratt::ast::expr
}; // pratt::ast


#endif
