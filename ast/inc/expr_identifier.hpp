#ifndef PRATT_PARSING_AST_EXPR_IDENTIFIER
#define PRATT_PARSING_AST_EXPR_IDENTIFIER

#include <string_view>

#include "expr.hpp"

namespace pratt::ast::expr {
    class IdentifierExpr final : public BaseExpr {
        public:
            IdentifierExpr(std::string_view _value) 
                : value{_value} {}

            void printExpr() const override {
                std::cout << this->value;
            }
        private:
            std::string_view value{};   
    };
}; // pratt::ast::expr

#endif