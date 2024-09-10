#include "lexer.h"
#include "parser.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string readFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <source_file>" << std::endl;
        return 1;
    }

    std::string source = readFile(argv[1]);
    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    // Print tokens for debugging
    for (const auto& token : tokens) {
        std::cout << "Token: " << static_cast<int>(token.type) << " " << token.lexeme << std::endl;
    }

    Parser parser(tokens);
    auto ast = parser.parse();

    // TODO: Implement semantic analysis, code generation, and optimization

    return 0;
}