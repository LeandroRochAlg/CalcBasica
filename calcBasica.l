%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"

// Definição do nó da árvore
typedef struct Node {
    char *token;
    struct Node **children;
    int child_count;
} Node;

// Funções para manipular a árvore
Node* create_node(const char *token) {
    Node *new_node = malloc(sizeof(Node));
    new_node->token = strdup(token);
    new_node->children = NULL;
    new_node->child_count = 0;
    return new_node;
}

void add_child(Node *parent, Node *child) {
    parent->children = realloc(parent->children, sizeof(Node*) * (parent->child_count + 1));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

void free_tree(Node *node) {
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->token);
    free(node->children);
    free(node);
}

void save_tree(Node *node, FILE *file, int depth, int is_last) {
    if (node == NULL) return;

    // Print the current node
    for (int i = 0; i < depth - 1; i++) {
        fprintf(file, "│   ");
    }

    if (depth > 0) {
        if (is_last) {
            fprintf(file, "└── ");
        } else {
            fprintf(file, "├── ");
        }
    }

    fprintf(file, "%s\n", node->token);

    // Process children
    for (int i = 0; i < node->child_count; i++) {
        save_tree(node->children[i], file, depth + 1, i == node->child_count - 1);
    }
}

// Função para empilhar subárvores
typedef struct TreeStack {
    Node **nodes;
    int top;
    int capacity;
} TreeStack;

TreeStack* create_stack(int capacity) {
    TreeStack *stack = malloc(sizeof(TreeStack));
    stack->nodes = malloc(sizeof(Node*) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int is_empty(TreeStack *stack) {
    return stack->top == -1;
}

void push(TreeStack *stack, Node *node) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity *= 2;
        stack->nodes = realloc(stack->nodes, sizeof(Node*) * stack->capacity);
    }
    stack->nodes[++stack->top] = node;
}

Node* pop(TreeStack *stack) {
    if (is_empty(stack)) return NULL;
    return stack->nodes[stack->top--];
}

Node* peek(TreeStack *stack) {
    if (is_empty(stack)) return NULL;
    return stack->nodes[stack->top];
}

void free_stack(TreeStack *stack) {
    free(stack->nodes);
    free(stack);
}

// Variáveis globais
FILE *outFile;
FILE *treeFile; // Arquivo para salvar a árvore
Node *root;  // Raiz da árvore
TreeStack *tree_stack;  // Pilha para gerenciar subárvores

typedef union {
    int inteiro;
    float real;
    char* str;
} YYSTYPE;

YYSTYPE yylval;

char* strdup(const char* s) {
    char* d = malloc(strlen(s) + 1);
    if (d == NULL) return NULL;
    strcpy(d, s);
    return d;
}

%}

%%

PROGRAMA {
    root = create_node("PROGRAMA");
    push(tree_stack, root); // Empilha o nó raiz
}

INICIO {
    Node *node = create_node("INICIO");
    add_child(peek(tree_stack), node);
}

FIM {
    Node *node = create_node("FIM");
    add_child(peek(tree_stack), node);
}

DECLARACOES {
    Node *node = create_node("DECLARACOES");
    add_child(peek(tree_stack), node);
    push(tree_stack, node); // Inicia nova subárvore
}

FIM_DECLARACOES {
    pop(tree_stack); // Fecha a subárvore de declarações
}

SE {
    Node *node = create_node("SE");
    add_child(peek(tree_stack), node);
    push(tree_stack, node); // Inicia nova subárvore
}

FIM_SE {
    pop(tree_stack); // Fecha a subárvore SE
}

ENQUANTO {
    Node *node = create_node("ENQUANTO");
    add_child(peek(tree_stack), node);
    push(tree_stack, node); // Inicia nova subárvore
}

FIM_ENQUANTO {
    pop(tree_stack); // Fecha a subárvore ENQUANTO
}

INTEIRO {
    Node *node = create_node("INTEIRO");
    add_child(peek(tree_stack), node);
}
REAL {
    Node *node = create_node("REAL");
    add_child(peek(tree_stack), node);
}

LEIA {
    Node *node = create_node("LEIA");
    add_child(peek(tree_stack), node);
}

ESCREVA {
    Node *node = create_node("ESCREVA");
    add_child(peek(tree_stack), node);
}

":=" {
    Node *node = create_node("ATRIBUICAO");
    add_child(peek(tree_stack), node);
}

[0-9]+ {
    Node *node = create_node("NUM_INT");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "NUM_INT_TOK: %d\n", yylval.inteiro = atoi(yytext));
}

[0-9]+"."[0-9]+ {
    Node *node = create_node("NUM_REAL");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "NUM_REAL_TOK: %f\n", yylval.real = atof(yytext));
}

[a-zA-Z][a-zA-Z0-9]* {
    Node *node = create_node("IDENT");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "IDENT_TOK: %s\n", yylval.str = strdup(yytext));
}

\n {
    /* Ignorar quebras de linha */
}

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    // Abrir o arquivo de entrada
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Erro ao abrir arquivo %s\n", argv[1]);
        return 1;
    }

    // Criar o nome do arquivo de saída
    char outFileName[256];
    snprintf(outFileName, sizeof(outFileName), "%s_saida.txt", argv[1]);

    // Abrir o arquivo de saída
    outFile = fopen(outFileName, "w");
    if (!outFile) {
        fprintf(stderr, "Erro ao criar arquivo de saída.\n");
        return 1;
    }

    // Criar o nome do arquivo para salvar a árvore
    char treeFileName[256];
    snprintf(treeFileName, sizeof(treeFileName), "%s_arvore.txt", argv[1]);

    // Abrir o arquivo para salvar a árvore
    treeFile = fopen(treeFileName, "w");
    if (!treeFile) {
        fprintf(stderr, "Erro ao criar arquivo para salvar a árvore.\n");
        return 1;
    }

    // Inicializa a raiz da árvore e a pilha de subárvores
    root = create_node("PROGRAMA");
    tree_stack = create_stack(10);
    push(tree_stack, root); // Empilhar a raiz

    // Executar o lexer
    yylex();

    // Salvar a árvore no arquivo
    save_tree(root, treeFile, 0, 1);

    // Liberar memória
    free_tree(root);
    free_stack(tree_stack);

    // Fechar arquivos
    fclose(outFile);
    fclose(treeFile);
    fclose(yyin);

    return 0;
}
