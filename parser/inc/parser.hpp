#ifndef PRATT_PARSING_PARSER_H
#define PRATT_PARSING_PARSER_H

#include <vector>
#include <utility>
#include <stdexcept>
#include <string>

#include "token.hpp"
#include "ast.hpp"

#define NUD 0
#define L1_LEFT_BP 10
#define L1_RIGHT_BP 11
#define L2_LEFT_BP 20
#define L2_RIGHT_BP 21

namespace pratt::parser {
    using AToken = ::pratt::token::Token;
    using ATokenType = ::pratt::token::TokenType;
    using ASTNode = std::unique_ptr<::pratt::ast::expr::Expr>;
    using BinaryNode = ::pratt::ast::expr::BinaryExpr;
    using NumberNode = ::pratt::ast::expr::NumberExpr;
    using IdentifierNode = ::pratt::ast::expr::IdentifierExpr;
}; // pratt::parser

namespace pratt::parser {
    class Parser final {
        public: 
            explicit Parser(const std::vector<AToken>);

            ASTNode parse();
        private:
            const std::vector<AToken> tokens{};
            std::size_t current{};
            AToken eofToken{ATokenType::EoF};

            inline const AToken& peek() const { return current < tokens.size() ? tokens[current] : eofToken; }
            inline const AToken& peek(std::size_t offset) const { return (current + offset < tokens.size()) ? tokens[current + offset] : eofToken;}
            inline const AToken& advance() { return current < tokens.size() ? tokens[current++] : eofToken; }

            inline bool is_at_end() const { return tokens[current].getType() == ATokenType::EoF; }

            ASTNode parseExpression(uint16_t);

            ASTNode parsePrefix();
            bool parseInfix(const ATokenType);
            constexpr std::pair<uint16_t, uint16_t> infixBindingPower(ATokenType type) const {
                switch (type) {
                    case ATokenType::MINUS:
                    case ATokenType::PLUS:
                        return {L1_LEFT_BP, L1_RIGHT_BP};
                    case ATokenType::SLASH:
                    case ATokenType::ASTERISK:
                        return {L2_LEFT_BP, L2_RIGHT_BP};
                    default:
                        return {0, 0};
                }
            }

    };
}; // pratt::parser

#endif