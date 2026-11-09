#ifndef PRATT_PARSING_AST_EXPR_H
#define PRATT_PARSING_AST_EXPR_H

#include <memory>
#include <iostream>

#include "context/context.hpp"

namespace pratt::ast {
    using ASTPrintConfig = ::pratt::ast::context::ASTPrintableContextCfg;
}; 

namespace pratt::ast {
    namespace expr {
        class Expr {
            public:
                virtual ~Expr() = default;
                virtual void printExpr(const ASTPrintConfig&) const = 0;
        };
    }; // pratt::ast::expr
}; // pratt::ast

namespace pratt::ast {
    using BaseExpr = ::pratt::ast::expr::Expr;
    using ASTNode = std::unique_ptr<BaseExpr>;
}; // pratt::ast::expr

#endif