#include "lexer.h"
#include <cctype>
#include <unordered_map>

static std::unordered_map<std::string, TokenType> keywords = {
    {"if", TokenType::IF},
    {"else", TokenType::ELSE},
    {"while", TokenType::WHILE},
    {"function", TokenType::FUNCTION},
    {"return", TokenType::RETURN}
};

Lexer::Lexer(std::string source) : source(std::move(source)) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (!isAtEnd()) {
        start = current;
        char c = advance();
        switch (c) {
            case '(': addToken(TokenType::LPAREN); break;
            case ')': addToken(TokenType::RPAREN); break;
            case '{': addToken(TokenType::LBRACE); break;
            case '}': addToken(TokenType::RBRACE); break;
            case ';': addToken(TokenType::SEMICOLON); break;
            case '+': addToken(TokenType::PLUS); break;
            case '-': addToken(TokenType::MINUS); break;
            case '*': addToken(TokenType::MULTIPLY); break;
            case '/': addToken(TokenType::DIVIDE); break;
            case '=':
                addToken(match('=') ? TokenType::EQUAL : TokenType::ASSIGN);
                break;
            case ' ':
            case '\r':
            case '\t':
                // Ignore whitespace
                break;
            case '\n':
                line++;
                break;
            default:
                if (std::isdigit(c)) {
                    tokens.push_back(number());
                } else if (std::isalpha(c)) {
                    tokens.push_back(identifier());
                } else {
                    // Handle error: unexpected character
                }
        }
    }
    tokens.emplace_back(TokenType::END_OF_FILE, "", line);
    return tokens;
}

// Implement other Lexer methods here...

Token Lexer::number() {
    while (std::isdigit(peek())) advance();
    return Token(TokenType::NUMBER, source.substr(start, current - start), line);
}

Token Lexer::identifier() {
    while (std::isalnum(peek())) advance();
    std::string text = source.substr(start, current - start);
    TokenType type = keywords.count(text) ? keywords[text] : TokenType::IDENTIFIER;
    return Token(type, text, line);
}

// Implement other helper methods (advance, match, peek, isAtEnd, etc.)