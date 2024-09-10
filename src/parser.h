#pragma once
#include "token.h"
#include <vector>
#include <memory>

// Forward declarations for AST nodes
struct Expr;
struct Stmt;

// Class responsible for parsing tokens into an Abstract Syntax Tree (AST)
class Parser {
public:
    // Constructor that takes a vector of tokens as input
    explicit Parser(std::vector<Token> tokens);

    // Main parsing method that returns a vector of statements (AST)
    std::vector<std::unique_ptr<Stmt>> parse();

private:
    std::vector<Token> tokens; // The tokens to be parsed
    int current = 0;           // Current position in the token list

    // Recursive descent parsing methods for different grammar rules
    std::unique_ptr<Expr> expression();
    std::unique_ptr<Expr> equality();
    std::unique_ptr<Expr> comparison();
    std::unique_ptr<Expr> term();
    std::unique_ptr<Expr> factor();
    std::unique_ptr<Expr> primary();

    std::unique_ptr<Stmt> statement();
    std::unique_ptr<Stmt> ifStatement();
    std::unique_ptr<Stmt> whileStatement();
    std::unique_ptr<Stmt> expressionStatement();

    // Helper methods for parsing
    bool match(TokenType type);  // Check if current token matches the given type
    bool check(TokenType type);  // Check if current token is of the given type without consuming
    Token advance();             // Move to the next token
    Token peek();                // Look at the current token without consuming it
    Token previous();            // Get the previously consumed token
    bool isAtEnd();              // Check if we've reached the end of the token list
};