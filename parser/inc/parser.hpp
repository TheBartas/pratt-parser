#ifndef PRATT_PARSING_PARSER_H
#define PRATT_PARSING_PARSER_H

#include <vector>

#include "token.hpp"
#include "ast.hpp"

namespace pratt::parser {
    using AToken = ::pratt::token::Token;
    using ATokenType = ::pratt::token::TokenType;

    class Parser final {
        public: 
            explicit Parser(const std::vector<AToken>&);

        private:
            const std::vector<AToken> tokens{};
            std::size_t current{};

            inline const AToken& peek() const { return tokens[current]; }
            inline const AToken& advance() { return tokens[current++]; }

            inline bool is_at_end() const { return tokens[current].getType() == ATokenType::EoF; }
    };
}; // pratt::parser

#endif