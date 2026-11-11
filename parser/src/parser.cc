#include "parser.hpp"

namespace pratt::parser {
    // public
    Parser::Parser(const std::vector<AToken> _tokens)
        : tokens{std::move(_tokens)} {}

    ASTNode Parser::parse() {
        return Parser::parseExpression(NUD);
    }

    // private
    ASTNode Parser::parseExpression(std::uint16_t min_bp) {
        auto lhs = Parser::parsePrefix();
        
        while (true) {
            const auto& op = Parser::peek();
            const auto type = op.getType();

            const auto bp = Parser::infixBindingPower(type);

            if (!bp || bp->left < min_bp) break;

            (void)Parser::advance();

            auto rhs = Parser::parseExpression(bp->right);
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
            case ATokenType::ROUND_BRACKET_OPEN: {
                auto expr = Parser::parseExpression(NUD);

                if (Parser::peek().getType() != ATokenType::ROUND_BRACKET_CLOSE) throw std::runtime_error("[Error] Expected \")\"");

                (void)Parser::advance();
                return expr;
            }
            case ATokenType::MINUS: {
                const auto [_, r_bp] = Parser::prefixBindingPower(token.getType());
                auto expr = Parser::parseExpression(r_bp);

                return std::make_unique<UnaryNode>(token.getLexeme(), std::move(expr));
            }   
        }
        throw std::runtime_error("[Error] Bad token in <parsePrefix>!"); // [TODO:0x0001]
    }
}; // pratt::parser