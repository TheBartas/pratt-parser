#ifndef PRATT_PARSING_EXPR_CONTEXT_H
#define PRATT_PARSING_EXPR_CONTEXT_H

#include <iostream>

namespace pratt::ast {
    namespace context {
        struct ASTPrintableContextCfg {
            std::string open{"( "};
            std::string close{" )"};
            std::string space{" "};
        };
    }; // pratt::ast::context
}; // pratt::ast

#endif