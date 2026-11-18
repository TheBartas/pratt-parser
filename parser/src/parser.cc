#include "parser.hpp"

namespace pratt::parser {
    // public
    Parser::Parser(const std::vector<AToken> _tokens)
        : tokens{std::move(_tokens)} {}

    ASTNode Parser::parse() {
        auto expr = Parser::parseExpression(NUD);

        if (Parser::peek().getType() != ATokenType::EoF) {
            std::string msg = "[Error] Unexpected token <" + std::string(Parser::peek().getLexeme()) + ">!";
            throw std::runtime_error(msg); // [TODO:0x0001]
        }

        return expr;
    }

    // private
    ASTNode Parser::parseExpression(std::uint16_t minBp) {
        ASTNode lhs = Parser::parsePrefix();
        
        while (true) {
            const auto& op = Parser::peek();
            const auto type = op.getType();

            if (const auto& postfixBp = Parser::postfixBindingPower(type)) {
                if (postfixBp->left < minBp) break;
                (void)Parser::advance();

                if (type == ATokenType::ROUND_BRACKET_OPEN) {
                    lhs = std::move(Parser::parseFunctionCall(std::move(lhs), postfixBp->right));
                }
                continue;
            }

            if (const auto& infixBp = Parser::infixBindingPower(type)) {
                if (infixBp->left < minBp) break;
                (void)Parser::advance();

                auto rhs = Parser::parseExpression(infixBp->right);
                lhs = std::make_unique<BinaryNode>(op.getLexeme(), std::move(lhs), std::move(rhs));

                continue;
            }

            break;
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

    std::unique_ptr<FunctionCallNode> Parser::parseFunctionCall(ASTNode callee, std::uint16_t bp) {
        std::vector<ASTNode> args{};
        while(true) {
            args.emplace_back(Parser::parseExpression(bp));
            if (Parser::advance().getType() == ATokenType::ROUND_BRACKET_CLOSE) break;
        }
        return std::make_unique<FunctionCallNode>(std::move(callee), std::move(args));
    }
}; // pratt::parser