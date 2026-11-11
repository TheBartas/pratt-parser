#ifndef PRATT_PARSING_PARSER_CONTEXT_H
#define PRATT_PARSING_PARSER_CONTEXT_H

#include <cstdint>

namespace pratt::parser {
    namespace context {
        struct BindingPower {
            std::uint16_t left;
            std::uint16_t right;
        };
    };
};

#endif