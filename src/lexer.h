#pragma once
#include "token.h"
#include <string>
#include <vector>

// Class responsible for breaking down source code into tokens
class Lexer {
public:
    // Constructor that takes the source code as input
    explicit Lexer(std::string source);

    // Main method to tokenize the entire source code
    std::vector<Token> tokenize();

private:
    std::string source; // The source code to be tokenized
    int start = 0;      // Start index of the current lexeme
    int current = 0;    // Current position in the source code
    int line = 1;       // Current line number

    // Helper methods for tokenization
    char advance();     // Move to the next character
    void addToken(TokenType type); // Add a token without lexeme
    void addToken(TokenType type, const std::string& lexeme); // Add a token with lexeme
    bool match(char expected); // Check if current character matches expected
    char peek();        // Look at the current character without consuming it
    void skipWhitespace(); // Skip over any whitespace characters
    Token number();     // Handle number literals
    Token identifier(); // Handle identifiers and keywords
    bool isAtEnd();     // Check if we've reached the end of the source code
};