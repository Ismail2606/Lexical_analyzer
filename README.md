# Lexical Analyzer in C

## Description
This project implements a lexical analyzer in C that reads a C source file (`sample.c`) and breaks it into meaningful tokens. It identifies keywords, identifiers, numbers, operators, special symbols, and string literals.

## Features
- Detects **Keywords** (using predefined keyword list)
- Identifies **Identifiers**
- Recognizes **Numbers** (including floating point)
- Supports **Operators** (including ==, !=, <=, >=)
- Detects **Special Symbols** like `() { } ; , []`
- Handles **String Literals**
- Skips whitespace efficiently

## Concepts Used
- Compiler Design (Lexical Analysis Phase)
- Tokenization
- File Handling in C (`fopen`, `fgetc`, `ungetc`)
- String Handling (`strcmp`)
- Character Classification (`isalpha`, `isdigit`, `isalnum`)
