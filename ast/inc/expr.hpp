#ifndef PRATT_PARSING_AST_EXPR
#define PRATT_PARSING_AST_EXPR

namespace pratt::ast::expr {
    class Expr {
        public:
            virtual ~Expr() = default;
    };

    using BaseExpr = ::pratt::ast::expr::Expr;
}; // pratt::ast::expr

#endif