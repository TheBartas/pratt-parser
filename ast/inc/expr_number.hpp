#ifndef PRATT_PARSING_AST_EXPR_NUMBER
#define PRATT_PARSING_AST_EXPR_NUMBER

#include <string_view>

#include "expr.hpp"

namespace pratt::ast::expr {
    class NumberExpr final : public BaseExpr {
        public:
            NumberExpr(std::string_view _value) 
                : value{_value} {}

            void printExpr() const override {
                std::cout << this->value;
            }
            
        private:
            std::string_view value{};   
    };
}; // pratt::ast::expr

#endif