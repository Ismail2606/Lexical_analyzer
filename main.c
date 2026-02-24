/*
Project: Lexical Analyzer in C
Author: Ismail Pasha (2025)
Description: This program performs lexical analysis on a C source file,
identifying keywords, identifiers, operators, special symbols, and numbers.
*/

#include "lexical.h"

int main() {
    FILE *fptr = fopen("sample.c", "r");
    if (!fptr) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n");
    printf("-------------------------\n\n");

    tokenize(fptr);

    fclose(fptr);
    return 0;
}

int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    char operators[] = "+-*/%=<>!";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int isSpecialSymbol(char ch) {
    char symbols[] = "(),;{}[]";
    for (int i = 0; i < strlen(symbols); i++) {
        if (ch == symbols[i])
            return 1;
    }
    return 0;
}

void tokenize(FILE *fptr) {
    char ch, buffer[MAX];
    int i = 0;

    while ((ch = fgetc(fptr)) != EOF) {
        // Skip whitespace
        if (isspace(ch))
            continue;

        // Identifiers or Keywords
        if (isalpha(ch) || ch == '_') {
            i = 0;
            buffer[i++] = ch;
            while (isalnum(ch = fgetc(fptr)) || ch == '_')
                buffer[i++] = ch;
            buffer[i] = '\0';
            ungetc(ch, fptr); // push back last read char

            if (isKeyword(buffer))
                printf("Keyword\t\t: %s\n", buffer);
            else
                printf("Identifier\t: %s\n", buffer);
        }

        // Numbers
        else if (isdigit(ch)) {
            i = 0;
            buffer[i++] = ch;
            while (isdigit(ch = fgetc(fptr)) || ch == '.')
                buffer[i++] = ch;
            buffer[i] = '\0';
            ungetc(ch, fptr);
            printf("Number\t\t: %s\n", buffer);
        }

        // Operators
        else if (isOperator(ch)) {
            char next = fgetc(fptr);
            if ((ch == '=' && next == '=') || (ch == '!' && next == '=') ||
                (ch == '<' && next == '=') || (ch == '>' && next == '=')) {
                printf("Operator\t: %c%c\n", ch, next);
            } else {
                printf("Operator\t: %c\n", ch);
                ungetc(next, fptr);
            }
        }

        // Special Symbols
        else if (isSpecialSymbol(ch)) {
            printf("Special Symbol\t: %c\n", ch);
        }

        // String literals
        else if (ch == '"') {
            i = 0;
            while ((ch = fgetc(fptr)) != '"' && ch != EOF)
                buffer[i++] = ch;
            buffer[i] = '\0';
            printf("String Literal\t: \"%s\"\n", buffer);
        }

        // Characters we ignore or don't classify
        else {
            // Ignore comments or unexpected characters
        }
    }
}


