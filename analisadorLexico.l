%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analisadorSemantico.tab.h"

// Arquivo de saída para os tokens
FILE *outFile;

%}

%%

PROGRAMA             { printf("Token: PROGRAMA\n"); return PROGRAMA_TOK;  }
INICIO               { printf("Token: INICIO\n"); return INICIO_TOK; }
FIM                  { printf("Token: FIM\n"); return FIM_TOK; }
DECLARACOES          { printf("Token: DECLARACOES\n"); return DECLARACOES_TOK; }
ALGORITMO            { printf("Token: ALGORITMO\n"); return ALGORITMO_TOK; }
INTEIRO              { printf("Token: INTEIRO\n"); return INTEIRO_TOK; }
REAL                 { printf("Token: REAL\n"); return REAL_TOK; }
CARACTER             { printf("Token: CARACTER\n"); return CARACTER_TOK; }
CADEIA               { printf("Token: CADEIA\n"); return CADEIA_TOK; }
LISTA_INT            { printf("Token: LISTA_INT\n"); return LISTA_INT_TOK; }
LISTA_REAL           { printf("Token: LISTA_REAL\n"); return LISTA_REAL_TOK; }
LEIA                 { printf("Token: LEIA\n"); return LEIA_TOK; }
ESCREVA              { printf("Token: ESCREVA\n"); return ESCREVA_TOK; }
SE                   { printf("Token: SE\n"); return SE_TOK; }
ENTAO                { printf("Token: ENTAO\n"); return ENTAO_TOK; }
FIM_SE               { printf("Token: FIM_SE\n"); return FIM_SE_TOK; }
ENQUANTO             { printf("Token: ENQUANTO\n"); return ENQUANTO_TOK; }
FIM_ENQUANTO         { printf("Token: FIM_ENQUANTO\n"); return FIM_ENQUANTO_TOK; }

","                  { printf("Token: VIRGULA\n"); return VIRGULA_TOK; }
":="                 { printf("Token: ATRIBUICAO\n"); return ATRIBUICAO_TOK; }
"+"                  { printf("Token: MAIS\n"); return MAIS_TOK; }
"-"                  { printf("Token: MENOS\n"); return MENOS_TOK; }
"*"                  { printf("Token: MULTIPLICA\n"); return MULTIPLICA_TOK; }
"/"                  { printf("Token: DIVIDE\n"); return DIVIDE_TOK; }
"%"                  { printf("Token: RESTO\n"); return RESTO_TOK; }
"\.M\."              { printf("Token: MAIOR\n"); return MAIOR_TOK; }
"\.I\."              { printf("Token: IGUAL\n"); return IGUAL_TOK; }
"\["                { printf("Token: ABRE_COLCHETE\n"); return ABRE_COLCHETE_TOK; }
"\]"                { printf("Token: FECHA_COLCHETE\n"); return FECHA_COLCHETE_TOK; }

[0-9]+               { printf("Token: NUM_INT\n"); return NUM_INT_TOK; }
[0-9]+"\\."[0-9]+    { printf("Token: NUM_REAL\n"); return NUM_REAL_TOK; }

[a-zA-Z_][a-zA-Z0-9_]* { printf("Token: IDENT\n"); return IDENT_TOK; }

\'[^\']*\'           { printf("Token: STRING\n"); return STRING_TOK; }

\{[^\}]*\}           { printf("Ignorando comentário\n"); }

[ \t]+               { printf("Ignorando espaços em branco\n"); }
\n                   { printf("Ignorando quebras de linha\n"); }

.                    { printf("Caractere inválido\n"); }

%%