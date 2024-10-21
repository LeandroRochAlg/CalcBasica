%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"

typedef struct Node {
    char *token;
    struct Node **children;
    int child_count;
} Node;

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

    for (int i = 0; i < node->child_count; i++) {
        save_tree(node->children[i], file, depth + 1, i == node->child_count - 1);
    }
}

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

FILE *outFile;
FILE *treeFile; 
Node *root;  
TreeStack *tree_stack;  

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
    push(tree_stack, root);
    fprintf(outFile, "PROGRAMA\n");
}

INICIO {
    Node *node = create_node("INICIO");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "INICIO\n");
}

FIM {
    Node *node = create_node("FIM");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "FIM\n");
}

DECLARACOES {
    Node *node = create_node("DECLARACOES");
    add_child(peek(tree_stack), node);
    push(tree_stack, node);
    fprintf(outFile, "DECLARACOES\n");
}

FIM_DECLARACOES {
    Node *node = create_node("FIM_DECLARACOES");
    add_child(peek(tree_stack), node);
    pop(tree_stack);
    fprintf(outFile, "FIM_DECLARACOES\n");
}

ALGORITMO {
    Node *node = create_node("ALGORITMO");
    add_child(peek(tree_stack), node);
    push(tree_stack, node);
    fprintf(outFile, "ALGORITMO\n");
}

FIM_ALGORITMO {
    Node *node = create_node("FIM_ALGORITMO");
    add_child(peek(tree_stack), node);
    pop(tree_stack);
    fprintf(outFile, "FIM_ALGORITMO\n");
}

SE {
    Node *node = create_node("SE");
    add_child(peek(tree_stack), node);
    push(tree_stack, node);
    fprintf(outFile, "SE\n");
}

FIM_SE {
    Node *node = create_node("FIM_SE");
    add_child(peek(tree_stack), node);
    pop(tree_stack);
    fprintf(outFile, "FIM_SE\n");
}

ENQUANTO {
    Node *node = create_node("ENQUANTO");
    add_child(peek(tree_stack), node);
    push(tree_stack, node);
    fprintf(outFile, "ENQUANTO\n");
}

FIM_ENQUANTO {
    Node *node = create_node("FIM_ENQUANTO");
    add_child(peek(tree_stack), node);
    pop(tree_stack);
    fprintf(outFile, "FIM_ENQUANTO\n");
}

INTEIRO {
    Node *node = create_node("INTEIRO");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "INTEIRO\n");
}

REAL {
    Node *node = create_node("REAL");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "REAL\n");
}

LEIA {
    Node *node = create_node("LEIA");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "LEIA\n");
}

ESCREVA {
    Node *node = create_node("ESCREVA");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "ESCREVA\n");
}

":=" {
    Node *node = create_node("ATRIBUICAO");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "ATRIBUICAO\n");
}

[0-9]+ {
    Node *node = create_node("NUM_INT");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "NUM_INT: %d\n", yylval.inteiro = atoi(yytext));
}

[0-9]+"."[0-9]+ {
    Node *node = create_node("NUM_REAL");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "NUM_REAL: %f\n", yylval.real = atof(yytext));
}

[a-zA-Z][a-zA-Z0-9]* {
    Node *node = create_node("IDENT");
    add_child(peek(tree_stack), node);
    fprintf(outFile, "IDENT_TOK: %s\n", yylval.str = strdup(yytext));
}

\n {
}

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Erro ao abrir arquivo %s\n", argv[1]);
        return 1;
    }

    char outFileName[256];
    snprintf(outFileName, sizeof(outFileName), "%s_saida.txt", argv[1]);

    outFile = fopen(outFileName, "w");
    if (!outFile) {
        fprintf(stderr, "Erro ao criar arquivo de saída %s\n", outFileName);
        return 1;
    }

    char treeFileName[256];
    snprintf(treeFileName, sizeof(treeFileName), "%s_arvore_sintatica.txt", argv[1]);

    FILE *treeFile = fopen(treeFileName, "w");
    if (!treeFile) {
        fprintf(stderr, "Erro ao criar arquivo de árvore sintática %s\n", treeFileName);
        fclose(outFile);
        return 1;
    }

    tree_stack = create_stack(100);

    yylex();

    save_tree(root, treeFile, 0, 1);

    fclose(outFile);
    fclose(treeFile);
    fclose(yyin);

    free_tree(root);
    free_stack(tree_stack);

    return 0;
}
