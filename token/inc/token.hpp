#ifndef PRATT_PARSING_TOKEN_H
#define PRATT_PARSING_TOKEN_H

#include <string>
#include <initializer_list>

namespace pratt::token {
    enum class TokenType {
        UNEXCEPTED,
        EoF,
        IDENTIFIER,
        FLOAT,
        INT,
        EQUAL,
        PLUS,
        MINUS,
        ASTERISK,
        SLASH,
    };

    class Token final {
        public:
            explicit Token(TokenType);
            Token(TokenType, std::string_view);

            inline TokenType getType() const noexcept { return type; }
            inline std::string_view getLexeme() const noexcept { return lexeme; }

            bool isTypeOf(std::initializer_list<TokenType>) const;

        private:
            TokenType type{TokenType::UNEXCEPTED};
            std::string_view lexeme{};
    };

}; // pratt::token

#endif