#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"

// Define YYSTYPE union with the data types used
typedef union {
    int inteiro;
    float real;
    char* str;
} YYSTYPE;

extern YYSTYPE yylval; // Declare yylval to be used from the lexer

// Declare the yylex function, which Flex will generate
int yylex(void);  // Declaration for the Flex-generated lexer function

// Function prototypes
void program();
void declarations();
void declaration();
void statements();
void statement();
void expression();
void term();
void factor();

// Global variable to hold the current token
int current_token;

// Function to match the current token and advance to the next one
void match(int expected_token) {
    if (current_token == expected_token) {
        current_token = yylex(); // Advance to the next token
    } else {
        printf("Syntax error: expected %d, got %d\n", expected_token, current_token);
        exit(1);
    }
}

// Entry point for the parser
void program() {
    printf("Parsing program\n");
    match(PROGRAMA_TOK);   // Match 'PROGRAMA'
    match(IDENT_TOK);         // Match program name (ID)
    match(INICIO_TOK);     // Match 'INICIO'
    declarations();        // Parse declarations
    statements();          // Parse statements
    match(FIM_TOK);        // Match 'FIM'
    printf("Program parsed successfully\n");
}

// Parse multiple declarations
void declarations() {
    printf("Parsing declarations\n");
    while (current_token == INTEIRO_TOK || current_token == REAL_TOK) {
        declaration();
    }
}

// Parse a single declaration
void declaration() {
    if (current_token == INTEIRO_TOK) {
        match(INTEIRO_TOK);
        match(IDENT_TOK);
        printf("Declared integer: %s\n", yylval.str); // Print declared variable
    } else if (current_token == REAL_TOK) {
        match(REAL_TOK);
        match(IDENT_TOK);
        printf("Declared real: %s\n", yylval.str); // Print declared variable
    } else {
        printf("Syntax error in declaration\n");
        exit(1);
    }
}

// Parse multiple statements
void statements() {
    printf("Parsing statements\n");
    while (current_token == LEIA_TOK || current_token == ESCREVA_TOK || current_token == IDENT_TOK || current_token == SE_TOK) {
        statement();
    }
}

// Parse a single statement
void statement() {
    if (current_token == LEIA_TOK) {
        match(LEIA_TOK);
        match(IDENT_TOK);
        printf("Reading variable: %s\n", yylval.str); // Print read variable
    } else if (current_token == ESCREVA_TOK) {
        match(ESCREVA_TOK);
        match(IDENT_TOK);
        printf("Writing variable: %s\n", yylval.str); // Print written variable
    } else if (current_token == IDENT_TOK) {
        char* var_name = strdup(yylval.str); // Store the variable name
        match(IDENT_TOK);
        match(':');
        match('=');
        expression();
        printf("Assigned expression to variable: %s\n", var_name); // Print assignment
        free(var_name);
    } else if (current_token == SE_TOK) {
        match(SE_TOK);
        expression();
        match(ENTAO_TOK);
        statement();
        match(FIM_SE_TOK);
    } else {
        printf("Syntax error in statement\n");
        exit(1);
    }
}

// Parse an expression
void expression() {
    term();
    while (current_token == '+' || current_token == '-') {
        if (current_token == '+') {
            match('+');
            term();
        } else if (current_token == '-') {
            match('-');
            term();
        }
    }
}

// Parse a term
void term() {
    factor();
    while (current_token == '*' || current_token == '/') {
        if (current_token == '*') {
            match('*');
            factor();
        } else if (current_token == '/') {
            match('/');
            factor();
        }
    }
}

// Parse a factor
void factor() {
    if (current_token == IDENT_TOK) {
        match(IDENT_TOK);
    } else if (current_token == NUM_INT_TOK) {
        match(NUM_INT_TOK);
    } else if (current_token == '(') {
        match('(');
        expression();
        match(')');
    } else {
        printf("Syntax error in factor\n");
        exit(1);
    }
}

int main(int argc, char **argv) {
    FILE *outFile;
    extern FILE *yyin;
    
    // Check for input file argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open the input file and assign it to Flex's yyin
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return 1;
    }

    // Create the output file
    char outFileName[256];
    snprintf(outFileName, sizeof(outFileName), "%s_output.txt", argv[1]);
    outFile = fopen(outFileName, "w");
    if (!outFile) {
        fprintf(stderr, "Error creating output file.\n");
        fclose(yyin); // Close input file before returning
        return 1;
    }

    // Get the first token from the lexer
    current_token = yylex(); 
    printf("Current token: %d\n", current_token);

    // Start parsing the program
    program(); 

    // Close files
    fclose(yyin);
    fclose(outFile);

    return 0;
}
