#ifndef PRATT_PARSING_AST_EXPR_BINARY
#define PRATT_PARSING_AST_EXPR_BINARY

#include "expr.hpp"

namespace pratt::ast::expr {
    class BinaryExpr final : public BaseExpr {
        public:
            BinaryExpr(
                std::string_view _op,
                ASTNode _lhs,
                ASTNode _rhs
            ) 
                : op{_op}, lhs{std::move(_lhs)}, rhs{std::move(_rhs)} {}

            void printExpr() const override {
                std::cout << "( " << this->op << " ";
                this->lhs->printExpr();
                std::cout << " ";
                this->rhs->printExpr();
                std::cout << ")";
            }
            
        private:
            std::string_view op{};
            ASTNode lhs;
            ASTNode rhs;

    };
}; // pratt::ast::expr

#endif