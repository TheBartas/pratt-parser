#ifndef PRATT_PARSING_PRINTABLE_H
#define PRATT_PARSING_PRINTABEL_H

#include <iostream>
#include <vector>

#include "token.hpp"
#include "ast.hpp"

namespace pratt::debug {
    using AToken = ::pratt::token::Token;
    using ATokenType = ::pratt::token::TokenType;
    using AExpr = ::pratt::ast::expr::Expr;
}; // pratt::debug

namespace pratt::debug {
    class Printable final {
        public:
            static void printStream(const std::vector<AToken>&, std::ostream&);
            static void printAST(const AExpr&);

        private:
            static constexpr std::string_view getTokenName(ATokenType type) noexcept {
                switch(type) {
                    case ATokenType::UNEXCEPTED: return "UNEXCEPTED";
                    case ATokenType::EoF: return "EoF";
                    case ATokenType::IDENTIFIER: return "IDENTIFIER";
                    case ATokenType::FLOAT: return "FLOAT";
                    case ATokenType::INT: return "INT";
                    case ATokenType::EQUAL: return "EQUAL";
                    case ATokenType::PLUS: return "PLUS";
                    case ATokenType::MINUS: return "MINUS";
                    case ATokenType::ASTERISK: return "ASTERISK";
                    case ATokenType::SLASH: return "SLASH";
                }
                return "UNKNOWN";
            }
    };
}; // pratt::debug

#endif