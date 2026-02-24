#ifndef LEXICAL_H
#define LEXICAL_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// List of C keywords
char keywords[][20] = {
    "float","typedef","return","unsigned","goto","auto","volatile","struct",
    "extern","int","register","enum","sizeof","const","while","short",
    "break","for","union","double","if","default","signed","switch",
    "case","long","static","char","do","else","continue","void"
};


/*Prototypes*/
int isKeyword(char *word);
int isOperator(char ch);
int isSpecialSymbol(char ch);
void tokenize(FILE *fptr);
#endif