#include "inc/printable.hpp"

namespace pratt::debug {
    // public
    void Printable::showStream(
        const std::vector<AToken>& tokens,
        std::ostream& out
    ) {
        out << "====== TOKENS ======" << std::endl;
        for (const auto& token : tokens) {
            out << "[ " << Printable::getTokenName(token.getType()) << " ]"    
                << " \""
                << token.getLexeme()
                << "\"" << std::endl;
        }
        out << "====================" << std::endl;
    } 
}; // pratt::debug