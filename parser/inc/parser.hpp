#ifndef PRATT_PARSING_PARSER_H
#define PRATT_PARSING_PARSER_H

#include <vector>
#include <stdexcept>
#include <string>
#include <optional>
#include <cstdint>

#include "token.hpp"
#include "ast.hpp"
#include "context/context.hpp"

#define NUD 0
#define L1_LEFT_BP 10
#define L1_RIGHT_BP 11
#define L2_LEFT_BP 20
#define L2_RIGHT_BP 21
#define PREFIX_BP_NEGATIVE_NUMBER 26

namespace pratt::parser {
    using AToken = ::pratt::token::Token;
    using ATokenType = ::pratt::token::TokenType;
    using ASTNode = std::unique_ptr<::pratt::ast::expr::Expr>;
    using BinaryNode = ::pratt::ast::expr::BinaryExpr;
    using NumberNode = ::pratt::ast::expr::NumberExpr;
    using IdentifierNode = ::pratt::ast::expr::IdentifierExpr;
    using UnaryNode = ::pratt::ast::expr::UnaryExpr;
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

            ASTNode parseExpression(std::uint16_t);
            ASTNode parsePrefix(); // Parsing NUD
            
            constexpr context::BindingPower prefixBindingPower(ATokenType type) {
                switch (type) {
                    case ATokenType::MINUS:
                        return context::BindingPower{0, PREFIX_BP_NEGATIVE_NUMBER};
                    default:
                        return context::BindingPower{0, 0};
                }
            }

            constexpr std::optional<context::BindingPower> infixBindingPower(ATokenType type) {
                switch (type) {
                    case ATokenType::MINUS:
                    case ATokenType::PLUS:
                        return context::BindingPower{L1_LEFT_BP, L1_RIGHT_BP};
                    case ATokenType::SLASH:
                    case ATokenType::ASTERISK:
                        return context::BindingPower{L2_LEFT_BP, L2_RIGHT_BP};
                    case ATokenType::ROUND_BRACKET_CLOSE:
                    case ATokenType::EoF:
                        return std::nullopt;
                    default:
                        throw std::runtime_error("[Error] Bad operator!"); // [TODO:0x0001]
                }
            }

    };
}; // pratt::parser

#endif