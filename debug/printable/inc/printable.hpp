#ifndef PRATT_PARSING_PRINTABLE_H
#define PRATT_PARSING_PRINTABEL_H

#include <iostream>
#include <vector>

#include "token.hpp"

namespace pratt::debug {
    class Printable final {
        public:
            using AToken = ::pratt::token::Token;
            using ATokenType = ::pratt::token::TokenType;

            static void showStream(const std::vector<AToken>&, std::ostream&);

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