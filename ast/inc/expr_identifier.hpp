#ifndef PRATT_PARSING_AST_EXPR_IDENTIFIER_H
#define PRATT_PARSING_AST_EXPR_IDENTIFIER_H

#include <string_view>

#include "expr.hpp"

namespace pratt::ast {
    namespace expr {
        class IdentifierExpr final : public BaseExpr {
            public:
                explicit IdentifierExpr(std::string_view _value) 
                    : value{_value} {}

                void printExpr(const ASTPrintConfig&) const override {
                    std::cout << this->value;
                }
            private:
                std::string_view value{};   
        };
    }; // pratt::ast::expr
}; // pratt::ast

#endif