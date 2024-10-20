%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>  // Para atoi() e atof()
#include <string.h>  // Para strdup()
#include "tokens.h"

FILE *outFile;  // Ponteiro para o arquivo de saída

// Definir a união yylval com os tipos de dados usados
typedef union {
    int inteiro;
    float real;
    char* str;
} YYSTYPE;

YYSTYPE yylval;  // Declaração da variável yylval

// Função strdup para sistemas que não a suportam nativamente
char* strdup(const char* s) {
    char* d = malloc(strlen(s) + 1);  // Aloca espaço suficiente
    if (d == NULL) return NULL;       // Verifica erro de alocação
    strcpy(d, s);                     // Copia a string original
    return d;
}
%}

%%

PROGRAMA                { printf("Token PROGRAMA encontrado\n"); fprintf(outFile, "PROGRAMA_TOK\n"); return PROGRAMA_TOK; }
INICIO                  { printf("Token INICIO encontrado\n"); fprintf(outFile, "INICIO_TOK\n"); return INICIO_TOK; }
FIM                     { printf("Token FIM encontrado\n"); fprintf(outFile, "FIM_TOK\n"); return FIM_TOK; }
DECLARACOES             { printf("Token DECLARACOES encontrado\n"); fprintf(outFile, "DECLARACOES_TOK\n"); return DECLARACOES_TOK; }
ALGORITMO               { printf("Token ALGORITMO encontrado\n"); fprintf(outFile, "ALGORITMO_TOK\n"); return ALGORITMO_TOK; }
INTEIRO                 { printf("Token INTEIRO encontrado\n"); fprintf(outFile, "INTEIRO_TOK\n"); return INTEIRO_TOK; }
REAL                    { printf("Token REAL encontrado\n"); fprintf(outFile, "REAL_TOK\n"); return REAL_TOK; }
CARACTER                { printf("Token CARACTER encontrado\n"); fprintf(outFile, "CARACTER_TOK\n"); return CARACTER_TOK; }
CADEIA                  { printf("Token CADEIA encontrado\n"); fprintf(outFile, "CADEIA_TOK\n"); return CADEIA_TOK; }
LISTA_INT               { printf("Token LISTA_INT encontrado\n"); fprintf(outFile, "LISTA_INT_TOK\n"); return LISTA_INT_TOK; }
LISTA_REAL              { printf("Token LISTA_REAL encontrado\n"); fprintf(outFile, "LISTA_REAL_TOK\n"); return LISTA_REAL_TOK; }
LEIA                    { printf("Token LEIA encontrado\n"); fprintf(outFile, "LEIA_TOK\n"); return LEIA_TOK; }
ESCREVA                 { printf("Token ESCREVA encontrado\n"); fprintf(outFile, "ESCREVA_TOK\n"); return ESCREVA_TOK; }
SE                      { printf("Token SE encontrado\n"); fprintf(outFile, "SE_TOK\n"); return SE_TOK; }
ENTAO                   { printf("Token ENTAO encontrado\n"); fprintf(outFile, "ENTAO_TOK\n"); return ENTAO_TOK; }
FIM_SE                  { printf("Token FIM_SE encontrado\n"); fprintf(outFile, "FIM_SE_TOK\n"); return FIM_SE_TOK; }
ENQUANTO                { printf("Token ENQUANTO encontrado\n"); fprintf(outFile, "ENQUANTO_TOK\n"); return ENQUANTO_TOK; }
FIM_ENQUANTO            { printf("Token FIM_ENQUANTO encontrado\n"); fprintf(outFile, "FIM_ENQUANTO_TOK\n"); return FIM_ENQUANTO_TOK; }

":="                    { printf("Token ATRIBUICAO encontrado\n"); fprintf(outFile, "ATRIBUICAO_TOK\n"); return ATRIBUICAO_TOK; }
"+"                     { printf("Token MAIS encontrado\n"); fprintf(outFile, "MAIS_TOK\n"); return MAIS_TOK; }
"-"                     { printf("Token MENOS encontrado\n"); fprintf(outFile, "MENOS_TOK\n"); return MENOS_TOK; }
"*"                     { printf("Token MULTIPLICA encontrado\n"); fprintf(outFile, "MULTIPLICA_TOK\n"); return MULTIPLICA_TOK; }
"/"                     { printf("Token DIVIDE encontrado\n"); fprintf(outFile, "DIVIDE_TOK\n"); return DIVIDE_TOK; }
"%"                     { printf("Token RESTO encontrado\n"); fprintf(outFile, "RESTO_TOK\n"); return RESTO_TOK; }

"\.M\."                 { printf("Token MAIOR encontrado\n"); fprintf(outFile, "MAIOR_TOK\n"); return MAIOR_TOK; }
"\.I\."                 { printf("Token IGUAL encontrado\n"); fprintf(outFile, "IGUAL_TOK\n"); return IGUAL_TOK; }

[0-9]+                  { printf("Token NUM_INT encontrado: %s\n", yytext); fprintf(outFile, "NUM_INT_TOK: %d\n", yylval.inteiro = atoi(yytext)); return NUM_INT_TOK; }
[0-9]+\.[0-9]+          { printf("Token NUM_REAL encontrado: %s\n", yytext); fprintf(outFile, "NUM_REAL_TOK: %f\n", yylval.real = atof(yytext)); return NUM_REAL_TOK; }

[a-zA-Z][a-zA-Z0-9]*    { printf("Token IDENT encontrado: %s\n", yytext); fprintf(outFile, "IDENT_TOK: %s\n", yylval.str = strdup(yytext)); return IDENT_TOK; }

\'[^\']*\'              { printf("Token CADEIA encontrado: %s\n", yytext); fprintf(outFile, "CADEIA_TOK: %s\n", yylval.str = strdup(yytext)); return CADEIA_TOK; }

\{[^\}]*\}              { printf("Comentário encontrado\n");        /*Ignorar comentários*/  }

[ \t]+                  { printf("Espaço em branco encontrado\n");  /*Ignorar espaços em branco*/  }
\n                      { printf("Quebra de linha encontrada\n");   /*Ignorar quebras de linha*/  }
%%
