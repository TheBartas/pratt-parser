#ifndef PRATT_PARSING_LEXER_H
#define PRATT_PARSING_LEXER_H

#include <vector>
#include <stdexcept>

#include "token.hpp"

namespace pratt::lexer {
    using AToken = ::pratt::token::Token;
    using ATokenType = ::pratt::token::TokenType;

    class Lexer final {
        public:
            explicit Lexer(std::string_view);

            std::vector<AToken> tokenize();

        private:
            std::string_view source{};
            const char* pos{};
            const char* end{};

            inline char peek() const { return *pos; };
            inline char advance() { return *pos++; };

            inline bool is_at_end() const { return pos >= end; }
            inline bool is_whitespace(char c) const { return c == ' ' || c == '\n' || c == '\t'; }
            inline bool is_digit(char c) const { return c >= '0' && c <= '9'; }
            inline bool is_alpha(char c) const { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_'); }
            inline bool is_identifier(char c) const { return is_alpha(c) || is_digit(c); }

            void skipWhitespace();

            AToken handleToken(ATokenType);
            AToken handleNumber();
            AToken handleIdentifier();

            AToken next();
    };
};

#endif