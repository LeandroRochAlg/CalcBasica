%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"

// Arquivo de saída para os tokens
FILE *outFile;

%}

%%

PROGRAMA             { fprintf(outFile, "PROGRAMA_TOK\n"); }
INICIO               { fprintf(outFile, "INICIO_TOK\n"); }
FIM                  { fprintf(outFile, "FIM_TOK\n"); }
DECLARACOES          { fprintf(outFile, "DECLARACOES_TOK\n"); }
ALGORITMO            { fprintf(outFile, "ALGORITMO_TOK\n"); }
INTEIRO              { fprintf(outFile, "INTEIRO_TOK\n"); }
REAL                 { fprintf(outFile, "REAL_TOK\n"); }
CARACTER             { fprintf(outFile, "CARACTER_TOK\n"); }
CADEIA               { fprintf(outFile, "CADEIA_TOK\n"); }
LISTA_INT            { fprintf(outFile, "LISTA_INT_TOK\n"); }
LISTA_REAL           { fprintf(outFile, "LISTA_REAL_TOK\n"); }
LEIA                 { fprintf(outFile, "LEIA_TOK\n"); }
ESCREVA              { fprintf(outFile, "ESCREVA_TOK\n"); }
SE                   { fprintf(outFile, "SE_TOK\n"); }
ENTAO                { fprintf(outFile, "ENTAO_TOK\n"); }
FIM_SE               { fprintf(outFile, "FIM_SE_TOK\n"); }
ENQUANTO             { fprintf(outFile, "ENQUANTO_TOK\n"); }
FIM_ENQUANTO         { fprintf(outFile, "FIM_ENQUANTO_TOK\n"); }

":="                 { fprintf(outFile, "ATRIBUICAO_TOK\n"); }
"+"                  { fprintf(outFile, "MAIS_TOK\n"); }
"-"                  { fprintf(outFile, "MENOS_TOK\n"); }
"*"                  { fprintf(outFile, "MULTIPLICA_TOK\n"); }
"/"                  { fprintf(outFile, "DIVIDE_TOK\n"); }
"%"                  { fprintf(outFile, "RESTO_TOK\n"); }
"\.M\."              { fprintf(outFile, "MAIOR_TOK\n"); }
"\.I\."              { fprintf(outFile, "IGUAL_TOK\n"); }

[0-9]+               { fprintf(outFile, "NUM_INT_TOK: %s\n", yytext); }
[0-9]+"."[0-9]+      { fprintf(outFile, "NUM_REAL_TOK: %s\n", yytext); }

[a-zA-Z][a-zA-Z0-9]* { fprintf(outFile, "IDENT_TOK: %s\n", yytext); }

\'[^\']*\'           { fprintf(outFile, "STRING_TOK: %s\n", yytext); }

[ \t]+               { /* Ignorar espaços */ }
\n                   { /* Ignorar quebras de linha */ }

.                    { fprintf(stderr, "Caractere inválido: %s\n", yytext); }

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    // Abrir arquivo de entrada
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Erro ao abrir arquivo %s\n", argv[1]);
        return 1;
    }

    char outFileName[256];
    snprintf(outFileName, sizeof(outFileName), "%s_anLexico_saida.txt", argv[1]);

    // Criar arquivo de saída
    outFile = fopen(outFileName, "w");
    if (!outFile) {
        fprintf(stderr, "Erro ao criar arquivo de saída.\n");
        fclose(yyin);
        return 1;
    }

    // Executar o analisador léxico
    yylex();

    // Fechar arquivos
    fclose(outFile);
    fclose(yyin);

    return 0;
}