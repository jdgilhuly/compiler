# Simple Compiler Project

This project is a simple compiler implementation for a custom programming language. It demonstrates the basic components of a compiler, including lexical analysis, parsing, and (to be implemented) semantic analysis, code generation, and optimization.

## Project Structure

- `src/`: Contains the source code for the compiler
  - `token.h`: Defines the Token structure and TokenType enum
  - `lexer.h` and `lexer.cpp`: Implement the lexical analyzer (tokenizer)
  - `parser.h`: Defines the parser class (to be implemented)
  - `main.cpp`: The entry point of the compiler

## Building the Project

To build the project, you need a C++ compiler that supports C++11 or later. The project uses a Makefile for easy compilation.

1. Make sure you have `make` and a C++ compiler (e.g., g++) installed on your system.
2. Open a terminal and navigate to the project root directory.
3. Run the following command to build the project:

```
make
```

This will compile the source files and create an executable named `compiler` in the project root directory.

## Running the Compiler

To run the compiler on a source file:

1. Create a text file with your source code (e.g., `example.txt`).
2. Run the compiler with the following command:

```
./compiler example.txt
```

The compiler will tokenize the input file and print the tokens for debugging purposes. As you implement more features (parsing, semantic analysis, code generation), you can extend the output accordingly.

## TODO

-