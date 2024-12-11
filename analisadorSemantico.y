%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin; // Arquivo de entrada
void yyerror(const char *s); // Função de erro
int yylex();

// Estrutura para a tabela de símbolos
typedef struct {
    char nome[100];
    char tipo[20];
    int tamanho; // Para listas
} Simbolo;

Simbolo tabela_simbolos[100];
int num_simbolos = 0;

// Função para adicionar um símbolo na tabela
void adicionar_simbolo(const char *nome, const char *tipo, int tamanho) {
    for (int i = 0; i < num_simbolos; i++) {
        if (strcmp(tabela_simbolos[i].nome, nome) == 0) {
            fprintf(stderr, "Erro semântico: Variável '%s' já declarada.\n", nome);
            exit(1);
        }
    }
    strcpy(tabela_simbolos[num_simbolos].nome, nome);
    strcpy(tabela_simbolos[num_simbolos].tipo, tipo);
    tabela_simbolos[num_simbolos].tamanho = tamanho;
    num_simbolos++;
}

// Função para buscar o tipo de uma variável na tabela
char* buscar_tipo(const char *nome) {
    for (int i = 0; i < num_simbolos; i++) {
        if (strcmp(tabela_simbolos[i].nome, nome) == 0) {
            return tabela_simbolos[i].tipo;
        }
    }
    fprintf(stderr, "Erro semântico: Variável '%s' não declarada.\n", nome);
    exit(1);
}

// Função para verificar compatibilidade de tipos
void verificar_tipos(const char *tipo1, const char *tipo2) {
    if (strcmp(tipo1, tipo2) != 0) {
        fprintf(stderr, "Erro semântico: Tipos incompatíveis ('%s' e '%s').\n", tipo1, tipo2);
        exit(1);
    }
}

%}

%union {
    char* tipo;
    int tamanho;
}

%type <tipo> programa corpo declaracoes lista_declaracoes tipo lista_variaveis lista_escreva
%type <tipo> algoritmo lista_comandos comando expressao termo fator expressao_relacional

/* Declaração dos tokens */
%token <tipo> PROGRAMA_TOK INICIO_TOK FIM_TOK DECLARACOES_TOK ALGORITMO_TOK
%token <tipo> INTEIRO_TOK REAL_TOK CARACTER_TOK CADEIA_TOK LISTA_INT_TOK LISTA_REAL_TOK
%token <tipo> LEIA_TOK ESCREVA_TOK SE_TOK ENTAO_TOK FIM_SE_TOK ENQUANTO_TOK FIM_ENQUANTO_TOK
%token <tipo> ATRIBUICAO_TOK MAIS_TOK MENOS_TOK MULTIPLICA_TOK DIVIDE_TOK RESTO_TOK
%token <tipo> MAIOR_TOK IGUAL_TOK NUM_INT_TOK NUM_REAL_TOK IDENT_TOK STRING_TOK VIRGULA_TOK
%token <tipo> ABRE_COLCHETE_TOK FECHA_COLCHETE_TOK

%start programa

%%

/* Regras da gramática */
programa:
    PROGRAMA_TOK IDENT_TOK INICIO_TOK corpo FIM_TOK {
        printf("Programa sintaticamente e semanticamente correto.\n");
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
        $$ = $1;
        printf("Reconhecida lista de declarações.\n");
    }
    | lista_declaracoes tipo lista_variaveis {
        $$ = $2;
        printf("Reconhecida lista de declarações com múltiplos tipos.\n");
    }
    ;

tipo:
    INTEIRO_TOK {
        $$ = strdup("inteiro");
        printf("Reconhecido tipo inteiro.\n");
    }
    | REAL_TOK {
        $$ = strdup("real");
        printf("Reconhecido tipo real.\n");
    }
    | CARACTER_TOK {
        $$ = strdup("caracter");
        printf("Reconhecido tipo caracter.\n");
    }
    | CADEIA_TOK {
        $$ = strdup("cadeia");
        printf("Reconhecido tipo cadeia.\n");
    }
    | LISTA_INT_TOK {
        $$ = strdup("lista_int");
        printf("Reconhecido tipo lista de inteiros.\n");
    }
    | LISTA_REAL_TOK {
        $$ = strdup("lista_real");
        printf("Reconhecido tipo lista de reais.\n");
    }
    ;

lista_variaveis:
    IDENT_TOK {
        adicionar_simbolo($1, $<tipo>1, 0);
        printf("Reconhecida variável '%s' do tipo '%s'.\n", $1, $<tipo>1);
    }
    | IDENT_TOK ABRE_COLCHETE_TOK NUM_INT_TOK FECHA_COLCHETE_TOK {
        adicionar_simbolo($1, $<tipo>1, atoi($3));
        printf("Reconhecida lista '%s' do tipo '%s' com tamanho %d.\n", $1, $<tipo>1, atoi($3));
    }
    | IDENT_TOK VIRGULA_TOK lista_variaveis {
        adicionar_simbolo($1, $<tipo>1, 0);
        printf("Reconhecida variável '%s' do tipo '%s'.\n", $1, $<tipo>1);
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
        char* tipo_var = buscar_tipo($1);
        verificar_tipos(tipo_var, $<tipo>expressao);
        printf("Reconhecido comando de atribuição para '%s'.\n", $1);
    }
    | SE_TOK expressao_relacional ENTAO_TOK lista_comandos FIM_SE_TOK {
        printf("Reconhecido comando condicional.\n");
    }
    | ENQUANTO_TOK expressao_relacional lista_comandos FIM_ENQUANTO_TOK {
        printf("Reconhecido comando de loop.\n");
    }
    ;

lista_escreva:
    IDENT_TOK {
        buscar_tipo($1); // Verifica se a variável foi declarada
        printf("Reconhecido elemento para escrita: '%s'.\n", $1);
    }
    | STRING_TOK {
        printf("Reconhecida string para escrita.\n");
    }
    | IDENT_TOK ABRE_COLCHETE_TOK expressao FECHA_COLCHETE_TOK {
        char* tipo_var = buscar_tipo($1);
        if (tipo_var == NULL) {
            yyerror("Variável não declarada.");
            exit(1);
        }
        printf("Reconhecido acesso à lista '%s'.\n", $1);
    }
    ;

expressao:
    expressao MAIS_TOK termo {
        $$ = $1; // Herda o tipo do lado esquerdo
        printf("Reconhecida expressão de adição.\n");
    }
    | expressao MENOS_TOK termo {
        $$ = $1; // Herda o tipo do lado esquerdo
        printf("Reconhecida expressão de subtração.\n");
    }
    | termo {
        $$ = $1; // Herda o tipo diretamente
        printf("Reconhecido termo.\n");
    }
    ;

termo:
    termo MULTIPLICA_TOK fator {
        $$ = $1; // Herda o tipo do lado esquerdo
        printf("Reconhecida expressão de multiplicação.\n");
    }
    | termo DIVIDE_TOK fator {
        $$ = $1; // Herda o tipo do lado esquerdo
        printf("Reconhecida expressão de divisão.\n");
    }
    | fator {
        $$ = $1; // Herda o tipo diretamente
        printf("Reconhecido fator.\n");
    }
    ;

fator:
    IDENT_TOK {
        $$ = buscar_tipo($1);
        if ($$ == NULL) {
            yyerror("Variável não declarada.");
            exit(1);
        }
        printf("Reconhecido identificador '%s'.\n", $1);
    }
    | NUM_INT_TOK {
        $$ = strdup("inteiro");
        printf("Reconhecido número inteiro.\n");
    }
    | NUM_REAL_TOK {
        $$ = strdup("real");
        printf("Reconhecido número real.\n");
    }
    | IDENT_TOK ABRE_COLCHETE_TOK expressao FECHA_COLCHETE_TOK {
        char* tipo_lista = buscar_tipo($1);
        if (tipo_lista == NULL) {
            yyerror("Lista não declarada.");
            exit(1);
        }
        $$ = tipo_lista;
        printf("Reconhecido acesso à lista '%s'.\n", $1);
    }
    ;

expressao_relacional:
    expressao MAIOR_TOK expressao {
        verificar_tipos($1, $3);
        $$ = strdup("booleano");
        printf("Reconhecida expressão relacional de maior.\n");
    }
    | expressao IGUAL_TOK expressao {
        verificar_tipos($1, $3);
        $$ = strdup("booleano");
        printf("Reconhecida expressão relacional de igualdade.\n");
    }
    ;

%%

/* Funções auxiliares */

void yyerror(const char *s) {
    fprintf(stderr, "Erro semântico: %s\n", s);
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
        printf("Análise semântica concluída com sucesso.\n");
    } else {
        printf("Falha na análise semântica.\n");
    }

    fclose(yyin);
    return 0;
}
#endif