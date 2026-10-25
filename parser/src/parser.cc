#include "parser.hpp"

namespace pratt::parser {
    // public
    Parser::Parser(const std::vector<AToken> _tokens)
        : tokens{std::move(_tokens)} {}

    ASTNode Parser::parse() {
        return Parser::parseExpression(NUD);
    }

    // private
    ASTNode Parser::parseExpression(uint16_t min_bp) {
        auto lhs = Parser::parsePrefix();
        
        while (true) {
            const auto& op = Parser::peek();
            if (!Parser::parseInfix(op.getType())) break;
            
            const auto& [l_bp, r_bp] = Parser::infixBindingPower(op.getType());
            if (l_bp < min_bp) break;

            (void)Parser::advance();

            auto rhs = Parser::parseExpression(r_bp);
            lhs = std::make_unique<BinaryNode>(op.getLexeme(), std::move(lhs), std::move(rhs));
        }
        return lhs;
    }

    ASTNode Parser::parsePrefix() {
        const auto& token = Parser::advance();
        switch (token.getType()) {
            case ATokenType::INT:
            case ATokenType::FLOAT:
                return std::make_unique<NumberNode>(token.getLexeme());
            case ATokenType::IDENTIFIER:
                return std::make_unique<IdentifierNode>(token.getLexeme());
        }
        throw std::runtime_error("[Error] Bad token in <parsePrefix>!"); // [TODO:0x0001]
    } 

    bool Parser::parseInfix(const ATokenType type) {
        switch (type) {
            case ATokenType::PLUS:
            case ATokenType::MINUS:
            case ATokenType::ASTERISK:
            case ATokenType::SLASH:
                return true;
            case ATokenType::EoF:
                return false;
            default:
                throw std::runtime_error("[Error] Bad operator"); // [TODO:0x0001]
        }
    }
}; // pratt::parser