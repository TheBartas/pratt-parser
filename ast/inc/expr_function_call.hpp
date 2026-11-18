#ifndef PRATT_PARSING_AST_EXPR_FUNCTION_CALL_H
#define PRATT_PARSING_AST_EXPR_FUNCTION_CALL_H

#include <vector>

#include "expr.hpp"

namespace pratt::ast {
    namespace expr {
        class FunctionCallExpr final : public BaseExpr {
            public:
                FunctionCallExpr(                    
                    ASTNode _callee,
                    std::vector<ASTNode> _args) : callee{std::move(_callee)}, args{std::move(_args)} {}

                void printExpr(const ASTPrintConfig& config) const override {
                    // [TODO:0x0002]
                    callee->printExpr(config);
                    std::cout << config.openFunListArgs;
                    
                    int idx{0};
                    for (const auto& arg : args) {
                        arg->printExpr(config);
                        if (idx + 1 < args.size()) std::cout << config.spBeArgs;
                        ++idx;
                    }

                    std::cout << config.closeFunListArgs;
                }

            private:
                ASTNode callee{};
                std::vector<ASTNode> args{};
        };
    }; // pratt::ast::expr
}; // pratt::ast


#endif
