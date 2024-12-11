/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ANALISADORSEMANTICO_TAB_H_INCLUDED
# define YY_YY_ANALISADORSEMANTICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAMA_TOK = 258,            /* PROGRAMA_TOK  */
    INICIO_TOK = 259,              /* INICIO_TOK  */
    FIM_TOK = 260,                 /* FIM_TOK  */
    DECLARACOES_TOK = 261,         /* DECLARACOES_TOK  */
    ALGORITMO_TOK = 262,           /* ALGORITMO_TOK  */
    INTEIRO_TOK = 263,             /* INTEIRO_TOK  */
    REAL_TOK = 264,                /* REAL_TOK  */
    CARACTER_TOK = 265,            /* CARACTER_TOK  */
    CADEIA_TOK = 266,              /* CADEIA_TOK  */
    LISTA_INT_TOK = 267,           /* LISTA_INT_TOK  */
    LISTA_REAL_TOK = 268,          /* LISTA_REAL_TOK  */
    LEIA_TOK = 269,                /* LEIA_TOK  */
    ESCREVA_TOK = 270,             /* ESCREVA_TOK  */
    SE_TOK = 271,                  /* SE_TOK  */
    ENTAO_TOK = 272,               /* ENTAO_TOK  */
    FIM_SE_TOK = 273,              /* FIM_SE_TOK  */
    ENQUANTO_TOK = 274,            /* ENQUANTO_TOK  */
    FIM_ENQUANTO_TOK = 275,        /* FIM_ENQUANTO_TOK  */
    ATRIBUICAO_TOK = 276,          /* ATRIBUICAO_TOK  */
    MAIS_TOK = 277,                /* MAIS_TOK  */
    MENOS_TOK = 278,               /* MENOS_TOK  */
    MULTIPLICA_TOK = 279,          /* MULTIPLICA_TOK  */
    DIVIDE_TOK = 280,              /* DIVIDE_TOK  */
    RESTO_TOK = 281,               /* RESTO_TOK  */
    MAIOR_TOK = 282,               /* MAIOR_TOK  */
    IGUAL_TOK = 283,               /* IGUAL_TOK  */
    NUM_INT_TOK = 284,             /* NUM_INT_TOK  */
    NUM_REAL_TOK = 285,            /* NUM_REAL_TOK  */
    IDENT_TOK = 286,               /* IDENT_TOK  */
    STRING_TOK = 287,              /* STRING_TOK  */
    VIRGULA_TOK = 288,             /* VIRGULA_TOK  */
    ABRE_COLCHETE_TOK = 289,       /* ABRE_COLCHETE_TOK  */
    FECHA_COLCHETE_TOK = 290       /* FECHA_COLCHETE_TOK  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "analisadorSemantico.y"

    char* tipo;
    int tamanho;

#line 104 "analisadorSemantico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ANALISADORSEMANTICO_TAB_H_INCLUDED  */
