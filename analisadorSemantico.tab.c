/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "analisadorSemantico.y"

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


#line 125 "analisadorSemantico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "analisadorSemantico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAMA_TOK = 3,               /* PROGRAMA_TOK  */
  YYSYMBOL_INICIO_TOK = 4,                 /* INICIO_TOK  */
  YYSYMBOL_FIM_TOK = 5,                    /* FIM_TOK  */
  YYSYMBOL_DECLARACOES_TOK = 6,            /* DECLARACOES_TOK  */
  YYSYMBOL_ALGORITMO_TOK = 7,              /* ALGORITMO_TOK  */
  YYSYMBOL_INTEIRO_TOK = 8,                /* INTEIRO_TOK  */
  YYSYMBOL_REAL_TOK = 9,                   /* REAL_TOK  */
  YYSYMBOL_CARACTER_TOK = 10,              /* CARACTER_TOK  */
  YYSYMBOL_CADEIA_TOK = 11,                /* CADEIA_TOK  */
  YYSYMBOL_LISTA_INT_TOK = 12,             /* LISTA_INT_TOK  */
  YYSYMBOL_LISTA_REAL_TOK = 13,            /* LISTA_REAL_TOK  */
  YYSYMBOL_LEIA_TOK = 14,                  /* LEIA_TOK  */
  YYSYMBOL_ESCREVA_TOK = 15,               /* ESCREVA_TOK  */
  YYSYMBOL_SE_TOK = 16,                    /* SE_TOK  */
  YYSYMBOL_ENTAO_TOK = 17,                 /* ENTAO_TOK  */
  YYSYMBOL_FIM_SE_TOK = 18,                /* FIM_SE_TOK  */
  YYSYMBOL_ENQUANTO_TOK = 19,              /* ENQUANTO_TOK  */
  YYSYMBOL_FIM_ENQUANTO_TOK = 20,          /* FIM_ENQUANTO_TOK  */
  YYSYMBOL_ATRIBUICAO_TOK = 21,            /* ATRIBUICAO_TOK  */
  YYSYMBOL_MAIS_TOK = 22,                  /* MAIS_TOK  */
  YYSYMBOL_MENOS_TOK = 23,                 /* MENOS_TOK  */
  YYSYMBOL_MULTIPLICA_TOK = 24,            /* MULTIPLICA_TOK  */
  YYSYMBOL_DIVIDE_TOK = 25,                /* DIVIDE_TOK  */
  YYSYMBOL_RESTO_TOK = 26,                 /* RESTO_TOK  */
  YYSYMBOL_MAIOR_TOK = 27,                 /* MAIOR_TOK  */
  YYSYMBOL_IGUAL_TOK = 28,                 /* IGUAL_TOK  */
  YYSYMBOL_NUM_INT_TOK = 29,               /* NUM_INT_TOK  */
  YYSYMBOL_NUM_REAL_TOK = 30,              /* NUM_REAL_TOK  */
  YYSYMBOL_IDENT_TOK = 31,                 /* IDENT_TOK  */
  YYSYMBOL_STRING_TOK = 32,                /* STRING_TOK  */
  YYSYMBOL_VIRGULA_TOK = 33,               /* VIRGULA_TOK  */
  YYSYMBOL_ABRE_COLCHETE_TOK = 34,         /* ABRE_COLCHETE_TOK  */
  YYSYMBOL_FECHA_COLCHETE_TOK = 35,        /* FECHA_COLCHETE_TOK  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_programa = 37,                  /* programa  */
  YYSYMBOL_corpo = 38,                     /* corpo  */
  YYSYMBOL_declaracoes = 39,               /* declaracoes  */
  YYSYMBOL_lista_declaracoes = 40,         /* lista_declaracoes  */
  YYSYMBOL_tipo = 41,                      /* tipo  */
  YYSYMBOL_lista_variaveis = 42,           /* lista_variaveis  */
  YYSYMBOL_algoritmo = 43,                 /* algoritmo  */
  YYSYMBOL_lista_comandos = 44,            /* lista_comandos  */
  YYSYMBOL_comando = 45,                   /* comando  */
  YYSYMBOL_lista_escreva = 46,             /* lista_escreva  */
  YYSYMBOL_expressao = 47,                 /* expressao  */
  YYSYMBOL_termo = 48,                     /* termo  */
  YYSYMBOL_fator = 49,                     /* fator  */
  YYSYMBOL_expressao_relacional = 50       /* expressao_relacional  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   65

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  74

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    83,    89,    92,    98,   102,   109,   113,
     117,   121,   125,   129,   136,   140,   144,   151,   157,   160,
     166,   169,   172,   177,   180,   186,   190,   193,   204,   208,
     212,   219,   223,   227,   234,   242,   246,   250,   262,   267
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAMA_TOK",
  "INICIO_TOK", "FIM_TOK", "DECLARACOES_TOK", "ALGORITMO_TOK",
  "INTEIRO_TOK", "REAL_TOK", "CARACTER_TOK", "CADEIA_TOK", "LISTA_INT_TOK",
  "LISTA_REAL_TOK", "LEIA_TOK", "ESCREVA_TOK", "SE_TOK", "ENTAO_TOK",
  "FIM_SE_TOK", "ENQUANTO_TOK", "FIM_ENQUANTO_TOK", "ATRIBUICAO_TOK",
  "MAIS_TOK", "MENOS_TOK", "MULTIPLICA_TOK", "DIVIDE_TOK", "RESTO_TOK",
  "MAIOR_TOK", "IGUAL_TOK", "NUM_INT_TOK", "NUM_REAL_TOK", "IDENT_TOK",
  "STRING_TOK", "VIRGULA_TOK", "ABRE_COLCHETE_TOK", "FECHA_COLCHETE_TOK",
  "$accept", "programa", "corpo", "declaracoes", "lista_declaracoes",
  "tipo", "lista_variaveis", "algoritmo", "lista_comandos", "comando",
  "lista_escreva", "expressao", "termo", "fator", "expressao_relacional", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,   -17,    16,    15,   -30,    23,    31,    48,    29,   -30,
     -30,   -30,   -30,   -30,   -30,    31,    24,   -30,   -13,   -30,
      24,   -22,   -30,    24,     3,    -6,    -6,    33,   -30,   -13,
     -30,    24,    27,   -30,    26,   -30,   -30,   -30,   -30,    28,
      10,    21,   -30,    40,   -13,    -6,   -30,   -30,    30,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,   -13,    38,    25,
     -30,   -18,   -15,    21,    21,    25,    25,   -30,   -30,    41,
     -30,   -30,   -30,   -30
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     0,     0,     0,     8,
       9,    10,    11,    12,    13,     4,     0,     2,    19,     3,
       0,    14,     6,     0,     0,     0,     0,     0,    17,    19,
       7,     0,     0,    20,    25,    26,    21,    35,    36,    34,
       0,    30,    33,     0,    19,     0,    18,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,    22,
      15,     0,     0,    28,    29,    38,    39,    31,    32,     0,
      24,    27,    37,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,   -30,   -30,    46,   -10,   -30,   -29,   -30,
     -30,   -23,    -2,    -4,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,     8,    15,    16,    22,    19,    28,    29,
      36,    40,    41,    42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      46,    23,    24,    25,    51,    52,    26,    51,    52,     1,
      30,    31,    32,    33,     3,    58,     4,    71,    27,     5,
      72,    47,    59,    37,    38,    39,    61,    62,    69,     6,
      65,    66,    51,    52,    34,    35,    18,    53,    54,     9,
      10,    11,    12,    13,    14,    55,    56,    51,    52,    63,
      64,    67,    68,    17,    45,    21,    48,    57,    70,    73,
      49,    20,    50,    44,     0,    60
};

static const yytype_int8 yycheck[] =
{
      29,    14,    15,    16,    22,    23,    19,    22,    23,     3,
      20,    33,    34,    23,    31,    44,     0,    35,    31,     4,
      35,    31,    45,    29,    30,    31,    49,    50,    57,     6,
      53,    54,    22,    23,    31,    32,     7,    27,    28,     8,
       9,    10,    11,    12,    13,    24,    25,    22,    23,    51,
      52,    55,    56,     5,    21,    31,    29,    17,    20,    18,
      34,    15,    34,    26,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    37,    31,     0,     4,     6,    38,    39,     8,
       9,    10,    11,    12,    13,    40,    41,     5,     7,    43,
      41,    31,    42,    14,    15,    16,    19,    31,    44,    45,
      42,    33,    34,    42,    31,    32,    46,    29,    30,    31,
      47,    48,    49,    50,    50,    21,    44,    42,    29,    34,
      34,    22,    23,    27,    28,    24,    25,    17,    44,    47,
      35,    47,    47,    48,    48,    47,    47,    49,    49,    44,
      20,    35,    35,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    39,    39,    40,    40,    41,    41,
      41,    41,    41,    41,    42,    42,    42,    43,    44,    44,
      45,    45,    45,    45,    45,    46,    46,    46,    47,    47,
      47,    48,    48,    48,    49,    49,    49,    49,    50,    50
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     0,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     2,     2,     0,
       2,     2,     3,     5,     4,     1,     1,     4,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     4,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: PROGRAMA_TOK IDENT_TOK INICIO_TOK corpo FIM_TOK  */
#line 77 "analisadorSemantico.y"
                                                    {
        printf("Programa sintaticamente e semanticamente correto.\n");
    }
#line 1207 "analisadorSemantico.tab.c"
    break;

  case 3: /* corpo: declaracoes algoritmo  */
#line 83 "analisadorSemantico.y"
                          {
        printf("Reconhecido corpo.\n");
    }
#line 1215 "analisadorSemantico.tab.c"
    break;

  case 4: /* declaracoes: DECLARACOES_TOK lista_declaracoes  */
#line 89 "analisadorSemantico.y"
                                      {
        printf("Reconhecidas declarações.\n");
    }
#line 1223 "analisadorSemantico.tab.c"
    break;

  case 5: /* declaracoes: %empty  */
#line 92 "analisadorSemantico.y"
                  {
        printf("Declarações vazias.\n");
    }
#line 1231 "analisadorSemantico.tab.c"
    break;

  case 6: /* lista_declaracoes: tipo lista_variaveis  */
#line 98 "analisadorSemantico.y"
                         {
        (yyval.tipo) = (yyvsp[-1].tipo);
        printf("Reconhecida lista de declarações.\n");
    }
#line 1240 "analisadorSemantico.tab.c"
    break;

  case 7: /* lista_declaracoes: lista_declaracoes tipo lista_variaveis  */
#line 102 "analisadorSemantico.y"
                                             {
        (yyval.tipo) = (yyvsp[-1].tipo);
        printf("Reconhecida lista de declarações com múltiplos tipos.\n");
    }
#line 1249 "analisadorSemantico.tab.c"
    break;

  case 8: /* tipo: INTEIRO_TOK  */
#line 109 "analisadorSemantico.y"
                {
        (yyval.tipo) = strdup("inteiro");
        printf("Reconhecido tipo inteiro.\n");
    }
#line 1258 "analisadorSemantico.tab.c"
    break;

  case 9: /* tipo: REAL_TOK  */
#line 113 "analisadorSemantico.y"
               {
        (yyval.tipo) = strdup("real");
        printf("Reconhecido tipo real.\n");
    }
#line 1267 "analisadorSemantico.tab.c"
    break;

  case 10: /* tipo: CARACTER_TOK  */
#line 117 "analisadorSemantico.y"
                   {
        (yyval.tipo) = strdup("caracter");
        printf("Reconhecido tipo caracter.\n");
    }
#line 1276 "analisadorSemantico.tab.c"
    break;

  case 11: /* tipo: CADEIA_TOK  */
#line 121 "analisadorSemantico.y"
                 {
        (yyval.tipo) = strdup("cadeia");
        printf("Reconhecido tipo cadeia.\n");
    }
#line 1285 "analisadorSemantico.tab.c"
    break;

  case 12: /* tipo: LISTA_INT_TOK  */
#line 125 "analisadorSemantico.y"
                    {
        (yyval.tipo) = strdup("lista_int");
        printf("Reconhecido tipo lista de inteiros.\n");
    }
#line 1294 "analisadorSemantico.tab.c"
    break;

  case 13: /* tipo: LISTA_REAL_TOK  */
#line 129 "analisadorSemantico.y"
                     {
        (yyval.tipo) = strdup("lista_real");
        printf("Reconhecido tipo lista de reais.\n");
    }
#line 1303 "analisadorSemantico.tab.c"
    break;

  case 14: /* lista_variaveis: IDENT_TOK  */
#line 136 "analisadorSemantico.y"
              {
        adicionar_simbolo((yyvsp[0].tipo), (yyvsp[0].tipo), 0);
        printf("Reconhecida variável '%s' do tipo '%s'.\n", (yyvsp[0].tipo), (yyvsp[0].tipo));
    }
#line 1312 "analisadorSemantico.tab.c"
    break;

  case 15: /* lista_variaveis: IDENT_TOK ABRE_COLCHETE_TOK NUM_INT_TOK FECHA_COLCHETE_TOK  */
#line 140 "analisadorSemantico.y"
                                                                 {
        adicionar_simbolo((yyvsp[-3].tipo), (yyvsp[-3].tipo), atoi((yyvsp[-1].tipo)));
        printf("Reconhecida lista '%s' do tipo '%s' com tamanho %d.\n", (yyvsp[-3].tipo), (yyvsp[-3].tipo), atoi((yyvsp[-1].tipo)));
    }
#line 1321 "analisadorSemantico.tab.c"
    break;

  case 16: /* lista_variaveis: IDENT_TOK VIRGULA_TOK lista_variaveis  */
#line 144 "analisadorSemantico.y"
                                            {
        adicionar_simbolo((yyvsp[-2].tipo), (yyvsp[-2].tipo), 0);
        printf("Reconhecida variável '%s' do tipo '%s'.\n", (yyvsp[-2].tipo), (yyvsp[-2].tipo));
    }
#line 1330 "analisadorSemantico.tab.c"
    break;

  case 17: /* algoritmo: ALGORITMO_TOK lista_comandos  */
#line 151 "analisadorSemantico.y"
                                 {
        printf("Reconhecido algoritmo.\n");
    }
#line 1338 "analisadorSemantico.tab.c"
    break;

  case 18: /* lista_comandos: comando lista_comandos  */
#line 157 "analisadorSemantico.y"
                           {
        printf("Reconhecida lista de comandos.\n");
    }
#line 1346 "analisadorSemantico.tab.c"
    break;

  case 19: /* lista_comandos: %empty  */
#line 160 "analisadorSemantico.y"
                  {
        printf("Lista de comandos vazia.\n");
    }
#line 1354 "analisadorSemantico.tab.c"
    break;

  case 20: /* comando: LEIA_TOK lista_variaveis  */
#line 166 "analisadorSemantico.y"
                             {
        printf("Reconhecido comando de leitura.\n");
    }
#line 1362 "analisadorSemantico.tab.c"
    break;

  case 21: /* comando: ESCREVA_TOK lista_escreva  */
#line 169 "analisadorSemantico.y"
                                {
        printf("Reconhecido comando de escrita.\n");
    }
#line 1370 "analisadorSemantico.tab.c"
    break;

  case 22: /* comando: IDENT_TOK ATRIBUICAO_TOK expressao  */
#line 172 "analisadorSemantico.y"
                                         {
        char* tipo_var = buscar_tipo((yyvsp[-2].tipo));
        verificar_tipos(tipo_var, (yyvsp[0].tipo));
        printf("Reconhecido comando de atribuição para '%s'.\n", (yyvsp[-2].tipo));
    }
#line 1380 "analisadorSemantico.tab.c"
    break;

  case 23: /* comando: SE_TOK expressao_relacional ENTAO_TOK lista_comandos FIM_SE_TOK  */
#line 177 "analisadorSemantico.y"
                                                                      {
        printf("Reconhecido comando condicional.\n");
    }
#line 1388 "analisadorSemantico.tab.c"
    break;

  case 24: /* comando: ENQUANTO_TOK expressao_relacional lista_comandos FIM_ENQUANTO_TOK  */
#line 180 "analisadorSemantico.y"
                                                                        {
        printf("Reconhecido comando de loop.\n");
    }
#line 1396 "analisadorSemantico.tab.c"
    break;

  case 25: /* lista_escreva: IDENT_TOK  */
#line 186 "analisadorSemantico.y"
              {
        buscar_tipo((yyvsp[0].tipo)); // Verifica se a variável foi declarada
        printf("Reconhecido elemento para escrita: '%s'.\n", (yyvsp[0].tipo));
    }
#line 1405 "analisadorSemantico.tab.c"
    break;

  case 26: /* lista_escreva: STRING_TOK  */
#line 190 "analisadorSemantico.y"
                 {
        printf("Reconhecida string para escrita.\n");
    }
#line 1413 "analisadorSemantico.tab.c"
    break;

  case 27: /* lista_escreva: IDENT_TOK ABRE_COLCHETE_TOK expressao FECHA_COLCHETE_TOK  */
#line 193 "analisadorSemantico.y"
                                                               {
        char* tipo_var = buscar_tipo((yyvsp[-3].tipo));
        if (tipo_var == NULL) {
            yyerror("Variável não declarada.");
            exit(1);
        }
        printf("Reconhecido acesso à lista '%s'.\n", (yyvsp[-3].tipo));
    }
#line 1426 "analisadorSemantico.tab.c"
    break;

  case 28: /* expressao: expressao MAIS_TOK termo  */
#line 204 "analisadorSemantico.y"
                             {
        (yyval.tipo) = (yyvsp[-2].tipo); // Herda o tipo do lado esquerdo
        printf("Reconhecida expressão de adição.\n");
    }
#line 1435 "analisadorSemantico.tab.c"
    break;

  case 29: /* expressao: expressao MENOS_TOK termo  */
#line 208 "analisadorSemantico.y"
                                {
        (yyval.tipo) = (yyvsp[-2].tipo); // Herda o tipo do lado esquerdo
        printf("Reconhecida expressão de subtração.\n");
    }
#line 1444 "analisadorSemantico.tab.c"
    break;

  case 30: /* expressao: termo  */
#line 212 "analisadorSemantico.y"
            {
        (yyval.tipo) = (yyvsp[0].tipo); // Herda o tipo diretamente
        printf("Reconhecido termo.\n");
    }
#line 1453 "analisadorSemantico.tab.c"
    break;

  case 31: /* termo: termo MULTIPLICA_TOK fator  */
#line 219 "analisadorSemantico.y"
                               {
        (yyval.tipo) = (yyvsp[-2].tipo); // Herda o tipo do lado esquerdo
        printf("Reconhecida expressão de multiplicação.\n");
    }
#line 1462 "analisadorSemantico.tab.c"
    break;

  case 32: /* termo: termo DIVIDE_TOK fator  */
#line 223 "analisadorSemantico.y"
                             {
        (yyval.tipo) = (yyvsp[-2].tipo); // Herda o tipo do lado esquerdo
        printf("Reconhecida expressão de divisão.\n");
    }
#line 1471 "analisadorSemantico.tab.c"
    break;

  case 33: /* termo: fator  */
#line 227 "analisadorSemantico.y"
            {
        (yyval.tipo) = (yyvsp[0].tipo); // Herda o tipo diretamente
        printf("Reconhecido fator.\n");
    }
#line 1480 "analisadorSemantico.tab.c"
    break;

  case 34: /* fator: IDENT_TOK  */
#line 234 "analisadorSemantico.y"
              {
        (yyval.tipo) = buscar_tipo((yyvsp[0].tipo));
        if ((yyval.tipo) == NULL) {
            yyerror("Variável não declarada.");
            exit(1);
        }
        printf("Reconhecido identificador '%s'.\n", (yyvsp[0].tipo));
    }
#line 1493 "analisadorSemantico.tab.c"
    break;

  case 35: /* fator: NUM_INT_TOK  */
#line 242 "analisadorSemantico.y"
                  {
        (yyval.tipo) = strdup("inteiro");
        printf("Reconhecido número inteiro.\n");
    }
#line 1502 "analisadorSemantico.tab.c"
    break;

  case 36: /* fator: NUM_REAL_TOK  */
#line 246 "analisadorSemantico.y"
                   {
        (yyval.tipo) = strdup("real");
        printf("Reconhecido número real.\n");
    }
#line 1511 "analisadorSemantico.tab.c"
    break;

  case 37: /* fator: IDENT_TOK ABRE_COLCHETE_TOK expressao FECHA_COLCHETE_TOK  */
#line 250 "analisadorSemantico.y"
                                                               {
        char* tipo_lista = buscar_tipo((yyvsp[-3].tipo));
        if (tipo_lista == NULL) {
            yyerror("Lista não declarada.");
            exit(1);
        }
        (yyval.tipo) = tipo_lista;
        printf("Reconhecido acesso à lista '%s'.\n", (yyvsp[-3].tipo));
    }
#line 1525 "analisadorSemantico.tab.c"
    break;

  case 38: /* expressao_relacional: expressao MAIOR_TOK expressao  */
#line 262 "analisadorSemantico.y"
                                  {
        verificar_tipos((yyvsp[-2].tipo), (yyvsp[0].tipo));
        (yyval.tipo) = strdup("booleano");
        printf("Reconhecida expressão relacional de maior.\n");
    }
#line 1535 "analisadorSemantico.tab.c"
    break;

  case 39: /* expressao_relacional: expressao IGUAL_TOK expressao  */
#line 267 "analisadorSemantico.y"
                                    {
        verificar_tipos((yyvsp[-2].tipo), (yyvsp[0].tipo));
        (yyval.tipo) = strdup("booleano");
        printf("Reconhecida expressão relacional de igualdade.\n");
    }
#line 1545 "analisadorSemantico.tab.c"
    break;


#line 1549 "analisadorSemantico.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 274 "analisadorSemantico.y"


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
