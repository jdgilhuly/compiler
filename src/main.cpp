#include "lexer.h"
#include "parser.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Helper function to read the contents of a file
std::string readFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char* argv[]) {
    // Check if a source file is provided as a command-line argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <source_file>" << std::endl;
        return 1;
    }

    // Read the source file
    std::string source = readFile(argv[1]);

    // Create a lexer and tokenize the source code
    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    // Print tokens for debugging
    for (const auto& token : tokens) {
        std::cout << "Token: " << static_cast<int>(token.type) << " " << token.lexeme << std::endl;
    }

    // Create a parser and generate the AST
    Parser parser(tokens);
    auto ast = parser.parse();

    // TODO: Implement semantic analysis, code generation, and optimization

    return 0;
}