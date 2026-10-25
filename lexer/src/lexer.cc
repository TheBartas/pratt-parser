#include "lexer.hpp"

namespace pratt::lexer {
    // private
    void Lexer::skipWhitespace() {
        while (!is_at_end() && is_whitespace(Lexer::peek())) ++pos;
    }

    AToken Lexer::handleToken(ATokenType type) {
        return AToken(type, std::string_view{pos++, 1});
    }

    AToken Lexer::handleNumber() {
        const char* start = pos; 
        Lexer::advance();

        bool has_decimal = false;

        while (true) {
            if (Lexer::is_digit(Lexer::peek())) {
                Lexer::advance();
                continue;
            } 
            
            if (Lexer::peek() == '.' && !has_decimal) {
                Lexer::advance();
                has_decimal = true;
                continue;
            } 
            
            if (has_decimal) return AToken(ATokenType::FLOAT, std::string_view{start, static_cast<std::size_t>(pos - start)});
            
            break;
        }

        return AToken(ATokenType::INT, std::string_view{start, static_cast<std::size_t>(pos - start)});
    }

    AToken Lexer::handleIdentifier() {
        const char* start = pos;
        Lexer::advance();

        while (Lexer::is_identifier(Lexer::peek())) advance();

        const std::size_t length = pos - start;
        std::string_view lexeme(start, length);

        return AToken(ATokenType::IDENTIFIER, lexeme);
    }

    AToken Lexer::next() {
        Lexer::skipWhitespace();

        if (is_at_end())
            return Lexer::handleToken(ATokenType::EoF);

        char c = Lexer::peek();

        if (Lexer::is_alpha(c)) return Lexer::handleIdentifier();
        if (Lexer::is_digit(c)) return Lexer::handleNumber();

        switch (c) {
            default:
                return Lexer::handleToken(ATokenType::UNEXCEPTED);
            case '+':
                return Lexer::handleToken(ATokenType::PLUS);
            case '-':
                return Lexer::handleToken(ATokenType::MINUS);
            case '*':
                return Lexer::handleToken(ATokenType::ASTERISK);
            case '/':
                return Lexer::handleToken(ATokenType::SLASH);
            case '=':
                return Lexer::handleToken(ATokenType::EQUAL);        
        }

        return Lexer::handleToken(ATokenType::UNEXCEPTED);
    }

    // public
    Lexer::Lexer(std::string_view _source)
        : source{_source}, pos{_source.data()}, end{_source.data() + _source.size()} {}

    std::vector<AToken> Lexer::tokenize() {
        std::vector<AToken> tokens;
        for (
            auto token = Lexer::next();
            !token.isTypeOf({
                ATokenType::UNEXCEPTED,
                ATokenType::EoF
            });
            token = Lexer::next()
        ) {
            tokens.push_back(token);
        }
        if (tokens.empty()) throw std::runtime_error("[Error] No tokens in stream <Lexer>"); // [TODO:0x0001]
        tokens.push_back(AToken{ATokenType::EoF});
        return tokens;
    }
};