%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin; // Declaração da entrada do Flex
void yyerror(const char *s);
int yylex();
%}

/* Declaração dos tokens */
%token PROGRAMA_TOK INICIO_TOK FIM_TOK DECLARACOES_TOK ALGORITMO_TOK
%token INTEIRO_TOK REAL_TOK CARACTER_TOK CADEIA_TOK LISTA_INT_TOK LISTA_REAL_TOK
%token LEIA_TOK ESCREVA_TOK SE_TOK ENTAO_TOK FIM_SE_TOK ENQUANTO_TOK FIM_ENQUANTO_TOK
%token ATRIBUICAO_TOK MAIS_TOK MENOS_TOK MULTIPLICA_TOK DIVIDE_TOK RESTO_TOK
%token MAIOR_TOK IGUAL_TOK NUM_INT_TOK NUM_REAL_TOK IDENT_TOK STRING_TOK VIRGULA_TOK
%token ABRE_COLCHETE_TOK FECHA_COLCHETE_TOK

%start programa

%%

/* Regras da gramática */

programa:
    PROGRAMA_TOK IDENT_TOK INICIO_TOK corpo FIM_TOK {
        printf("Programa sintaticamente correto.\n");
    }
    ;

corpo:
    declaracoes algoritmo {
        printf("Reconhecido corpo.\n");
    }
    ;

declaracoes:
    DECLARACOES_TOK lista_declaracoes {
        printf("Reconhecidas declarações.\n");
    }
    | /* vazio */ {
        printf("Declarações vazias.\n");
    }
    ;

lista_declaracoes:
    tipo lista_variaveis {
        printf("Reconhecida lista de declarações.\n");
    }
    | lista_declaracoes tipo lista_variaveis {
        printf("Reconhecida lista de declarações com múltiplos tipos.\n");
    }
    ;

tipo:
    INTEIRO_TOK {
        printf("Reconhecido tipo inteiro.\n");
    }
    | REAL_TOK {
        printf("Reconhecido tipo real.\n");
    }
    | CARACTER_TOK {
        printf("Reconhecido tipo caracter.\n");
    }
    | CADEIA_TOK {
        printf("Reconhecido tipo cadeia.\n");
    }
    | LISTA_INT_TOK {
        printf("Reconhecido tipo lista de inteiros.\n");
    }
    | LISTA_REAL_TOK {
        printf("Reconhecido tipo lista de reais.\n");
    }
    ;

lista_variaveis:
    IDENT_TOK {
        printf("Reconhecida variável.\n");
    }
    | IDENT_TOK ABRE_COLCHETE_TOK NUM_INT_TOK FECHA_COLCHETE_TOK {
        printf("Reconhecida declaração de lista.\n");
    }
    | IDENT_TOK VIRGULA_TOK lista_variaveis {
        printf("Reconhecida variável.\n");
    }
    ;

lista_escreva:
    IDENT_TOK {
        printf("Reconhecido elemento.\n");
    }
    | STRING_TOK {
        printf("Reconhecido elemento.\n");
    }
    | IDENT_TOK ABRE_COLCHETE_TOK expressao FECHA_COLCHETE_TOK {
        printf("Reconhecido acesso a lista.\n");
    }
    | IDENT_TOK VIRGULA_TOK lista_escreva {
        printf("Reconhecido elemento.\n");
    }
    | STRING_TOK VIRGULA_TOK lista_escreva {
        printf("Reconhecido elemento.\n");
    }
    | IDENT_TOK ABRE_COLCHETE_TOK expressao FECHA_COLCHETE_TOK VIRGULA_TOK lista_escreva {
        printf("Reconhecido acesso a lista.\n");
    }
    ;

algoritmo:
    ALGORITMO_TOK lista_comandos {
        printf("Reconhecido algoritmo.\n");
    }
    ;

lista_comandos:
    comando lista_comandos {
        printf("Reconhecida lista de comandos.\n");
    }
    | /* vazio */ {
        printf("Lista de comandos vazia.\n");
    }
    ;

comando:
    LEIA_TOK lista_variaveis {
        printf("Reconhecido comando de leitura.\n");
    }
    | ESCREVA_TOK lista_escreva {
        printf("Reconhecido comando de escrita.\n");
    }
    | IDENT_TOK ATRIBUICAO_TOK expressao {
        printf("Reconhecido comando de atribuição.\n");
    }
    | SE_TOK expressao_relacional ENTAO_TOK lista_comandos FIM_SE_TOK {
        printf("Reconhecido comando condicional.\n");
    }
    | ENQUANTO_TOK expressao_relacional lista_comandos FIM_ENQUANTO_TOK {
        printf("Reconhecido comando de loop.\n");
    }
    | LEIA_TOK fator {
        printf("Reconhecido comando de leitura.\n");
    }
    | ESCREVA_TOK fator {
        printf("Reconhecido comando de escrita.\n");
    }
    ;

expressao:
    expressao MAIS_TOK termo {
        printf("Reconhecida expressão de adição.\n");
    }
    | expressao MENOS_TOK termo {
        printf("Reconhecida expressão de subtração.\n");
    }
    | termo {
        printf("Reconhecido termo.\n");
    }
    ;

termo:
    termo MULTIPLICA_TOK fator {
        printf("Reconhecida expressão de multiplicação.\n");
    }
    | termo DIVIDE_TOK fator {
        printf("Reconhecida expressão de divisão.\n");
    }
    | fator {
        printf("Reconhecido fator.\n");
    }
    ;

fator:
    IDENT_TOK {
        printf("Reconhecido identificador.\n");
    }
    | IDENT_TOK ABRE_COLCHETE_TOK expressao FECHA_COLCHETE_TOK {
        printf("Reconhecido acesso a lista.\n");
    }
    | NUM_INT_TOK {
        printf("Reconhecido número inteiro.\n");
    }
    | NUM_REAL_TOK {
        printf("Reconhecido número real.\n");
    }
    ;

expressao_relacional:
    expressao MAIOR_TOK expressao {
        printf("Reconhecida expressão relacional de maior.\n");
    }
    | expressao IGUAL_TOK expressao {
        printf("Reconhecida expressão relacional de igualdade.\n");
    }
    ;

%%

/* Funções auxiliares */

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}

#ifndef YY_MAIN
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    // Abrir o arquivo de entrada para o Flex
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Erro ao abrir arquivo %s\n", argv[1]);
        return 1;
    }

    // Iniciar o analisador sintático
    if (yyparse() == 0) {
        printf("Análise sintática concluída com sucesso.\n");
    } else {
        printf("Falha na análise sintática.\n");
        printf("%d\n", yyparse());
    }

    fclose(yyin);
    return 0;
}
#endif