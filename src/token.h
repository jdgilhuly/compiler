#pragma once
#include <string>

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

struct Token {
    TokenType type;
    std::string lexeme;
    int line;

    Token(TokenType t, std::string l, int ln) : type(t), lexeme(std::move(l)), line(ln) {}
};