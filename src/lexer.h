#pragma once
#include "token.h"
#include <string>
#include <vector>

class Lexer {
public:
    explicit Lexer(std::string source);
    std::vector<Token> tokenize();

private:
    std::string source;
    int start = 0;
    int current = 0;
    int line = 1;

    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, const std::string& lexeme);
    bool match(char expected);
    char peek();
    void skipWhitespace();
    Token number();
    Token identifier();
    bool isAtEnd();
};