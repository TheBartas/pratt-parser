#include "inc/printable.hpp"

namespace pratt::debug {
    // public
    void Printable::printStream(
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

    void Printable::printAST(const AExpr& root) {
        root.printExpr();
        std::cout << std::endl;
    }
}; // pratt::debug