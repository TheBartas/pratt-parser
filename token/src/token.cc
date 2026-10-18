#include "token.hpp"

namespace pratt::token {
    // public:
    Token::Token(TokenType _type) 
        : type{_type} {}

    Token::Token(TokenType _type, std::string_view _lexeme) 
        : type{_type}, lexeme{_lexeme} {}

    bool Token::isTypeOf(std::initializer_list<TokenType> types) const {
        for (auto t : types) 
            if (type == t) return true;
        return false;
    }
        
}; // pratt::token