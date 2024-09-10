#pragma once
#include <string>

// Enum class representing different types of tokens in our language
enum class TokenType {
    // Keywords
    IF, ELSE, WHILE, FUNCTION, RETURN,

    // Operators
    PLUS, MINUS, MULTIPLY, DIVIDE, ASSIGN, EQUAL,

    // Punctuation
    SEMICOLON, LPAREN, RPAREN, LBRACE, RBRACE,

    // Literals
    IDENTIFIER, NUMBER,

    // Special
    END_OF_FILE
};

// Struct representing a token in our language
struct Token {
    TokenType type;     // The type of the token
    std::string lexeme; // The actual text of the token
    int line;           // The line number where the token appears

    // Constructor for creating a new token
    Token(TokenType t, std::string l, int ln) : type(t), lexeme(std::move(l)), line(ln) {}
};