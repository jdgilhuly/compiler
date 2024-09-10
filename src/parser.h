#pragma once
#include "token.h"
#include <vector>
#include <memory>

// Forward declarations for AST nodes
struct Expr;
struct Stmt;

class Parser {
public:
    explicit Parser(std::vector<Token> tokens);
    std::vector<std::unique_ptr<Stmt>> parse();

private:
    std::vector<Token> tokens;
    int current = 0;

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

    bool match(TokenType type);
    bool check(TokenType type);
    Token advance();
    Token peek();
    Token previous();
    bool isAtEnd();
};