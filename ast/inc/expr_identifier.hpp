#ifndef PRATT_PARSING_AST_EXPR_
#define PRATT_PARSING_AST_EXPR_NUMBER

#include <string_view>

#include "expr.hpp"

namespace pratt::ast::expr {
    class IdentifierExpr final : public BaseExpr {
        public:
            IdentifierExpr(std::string_view _value) 
                : value{_value} {}
        private:
            std::string_view value{};   
    };
}; // pratt::ast::expr

#endif