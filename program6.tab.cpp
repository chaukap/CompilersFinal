/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 9 "program6.ypp" /* yacc.c:339  */

#include <iostream>
#include "node.hpp"
#include <FlexLexer.h>
#include "symbolTable.hpp"
#include <queue>
#include <stack>

using namespace std;

extern queue<Node*> classes;
extern stack<string> derivations;
extern yyFlexLexer scanner;
extern int row;
extern int column;

#define yylex() scanner.yylex()
#define yytext() scanner.YYText()

void yyerror(const char *);

#line 88 "program6.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "program6.tab.hpp".  */
#ifndef YY_YY_PROGRAM6_TAB_HPP_INCLUDED
# define YY_YY_PROGRAM6_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    SEMI = 259,
    NOT = 260,
    NEQ = 261,
    EQ = 262,
    LT = 263,
    GT = 264,
    LEQ = 265,
    GEQ = 266,
    AND = 267,
    OR = 268,
    PLUS = 269,
    MINUS = 270,
    TIMES = 271,
    DIV = 272,
    MOD = 273,
    INT = 274,
    IDENT = 275,
    COMMA = 276,
    DOT = 277,
    LPAREN = 278,
    RPAREN = 279,
    LBRACK = 280,
    RBRACK = 281,
    LBRACE = 282,
    RBRACE = 283,
    IF = 284,
    ASSIGN = 285,
    COMMENT = 286,
    VOID = 287,
    CLASS = 288,
    NEW = 289,
    PRINT = 290,
    READ = 291,
    RETURN = 292,
    ELSE = 293,
    NULLT = 294,
    THIS = 295,
    WHILE = 296,
    ER_CH = 297,
    ER_WD = 298,
    ERRORS = 299,
    IGNORE = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "program6.ypp" /* yacc.c:355  */

  Node *ttype;

#line 178 "program6.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROGRAM6_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 195 "program6.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    58,    62,    69,    75,    81,    87,    96,
     104,   109,   113,   119,   124,   130,   139,   143,   147,   155,
     160,   169,   178,   182,   191,   197,   203,   213,   216,   224,
     228,   236,   240,   248,   255,   264,   271,   275,   284,   288,
     292,   300,   304,   312,   316,   323,   328,   333,   338,   343,
     349,   354,   358,   364,   372,   376,   383,   387,   394,   400,
     413,   417,   421,   426,   430,   435,   440,   445,   449,   454,
     459,   464,   469,   473,   477,   482,   487,   491,   495,   500,
     505,   512,   518,   525,   531,   540,   544,   548,   555,   559,
     567,   571,   578,   582,   586,   590,   597,   601,   605,   609,
     616,   620,   628,   636,   641,   650
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "SEMI", "NOT", "NEQ", "EQ", "LT",
  "GT", "LEQ", "GEQ", "AND", "OR", "PLUS", "MINUS", "TIMES", "DIV", "MOD",
  "INT", "IDENT", "COMMA", "DOT", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "IF", "ASSIGN", "COMMENT", "VOID", "CLASS", "NEW",
  "PRINT", "READ", "RETURN", "ELSE", "NULLT", "THIS", "WHILE", "ER_CH",
  "ER_WD", "ERRORS", "IGNORE", "$accept", "input", "program",
  "classDeclaration", "classBody", "varDeclarations",
  "ConstructorDeclarations", "ConstructorDeclaration",
  "MethodDeclarations", "temp", "MethodDeclaration", "ParametersAndBlock",
  "ParameterList", "MoreParameters", "Parameter", "vardec",
  "identifierSemi", "Block", "InnerBlock", "LocalVarDecs", "Statements",
  "Statement", "LocalVarDec", "Arglist", "OptionalExpression",
  "ConditionalStatement", "exp", "newexp", "UnaryOp", "paramList",
  "newType", "name", "type", "bracketexps", "bracketexp", "multibrackets",
  "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -98

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,     7,    22,   -23,   -93,   -93,   -93,     2,   -93,   -93,
     -93,    85,     5,   -93,    13,     8,    41,    33,   -93,    33,
     -93,   -93,    13,    63,    18,    45,   -93,    35,   -93,   -93,
      33,    33,   -93,   -93,    33,    13,   -93,     5,   -93,   -93,
      20,    48,    45,   -93,    52,    48,    33,   -93,    54,   -93,
      65,    71,    13,   -93,   -93,    83,   -93,    54,   108,   -93,
     -93,   -93,   -93,    76,    78,   146,   -93,    84,   -93,    86,
     184,   218,   -93,   -93,   -93,   132,    13,    51,   -93,    71,
     203,   153,   115,   -93,   -93,   203,   203,   203,   203,   110,
      99,   -93,   -93,   332,   -93,   -93,   100,    60,   -93,   203,
     -93,   218,   -93,   -93,    13,   203,   203,   127,   -93,   128,
     -93,   275,   -93,   -10,   360,   -93,   360,   -93,   -93,   294,
     -93,    78,   109,   -93,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   176,   100,   -93,
      45,   -93,   313,   -93,   254,   347,   -93,   -93,   218,   203,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,    45,   218,
     -93,   -93,   114,   360,   -93,   218,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     8,   105,     0,     1,     4,
       7,     0,    96,     6,     0,     0,     0,    13,    19,    10,
      22,    16,     0,    97,     0,    98,    26,     0,     5,    18,
      12,    15,    17,    20,    14,     0,    23,    97,    25,    34,
       0,     0,    99,   103,     0,     0,     9,    35,     0,    21,
       0,    29,     0,   104,    24,     0,    28,     0,     0,    30,
      33,    52,    37,     0,     0,     0,    92,     0,    51,     0,
      38,    39,    43,    41,    48,     0,     0,    93,    27,    31,
       0,     0,     0,    62,    56,     0,     0,     0,     0,     0,
       0,    61,    50,     0,    80,    72,     0,    60,    93,     0,
      36,    40,    42,    44,     0,     0,     0,     0,    95,     0,
      32,     0,    88,     0,    54,    47,    87,    86,    85,     0,
      90,    91,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,   100,
      84,    63,     0,    94,     0,     0,    46,    53,     0,     0,
      89,    73,    81,    67,    77,    76,    75,    74,    78,    79,
      65,    64,    68,    69,    70,    71,    66,   101,    82,     0,
     102,    45,    58,    55,    49,     0,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   144,   -93,   -93,   137,   -11,    47,   134,
      -6,   118,   -93,    91,   106,   149,   -93,     0,   -93,   -93,
     101,   -69,   102,   -93,   -93,   -93,    10,   -93,   -93,   -66,
     -93,   -54,    -4,   -93,   -92,   -12,     4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    15,    16,    17,    18,    19,    38,
      20,    49,    50,    59,    51,    21,    39,    68,    69,    70,
      71,    72,    73,   113,    92,    74,   144,    94,    95,    82,
      96,    97,    35,   138,   108,    42,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    75,   103,    10,   139,     7,    33,    22,     5,   107,
       1,   149,    22,    36,   150,    23,    75,    75,    27,    33,
      23,    23,     8,    37,    47,    36,    40,     6,    36,    11,
      24,   141,   103,     6,    23,    37,    28,    52,    37,    27,
      36,    52,    29,    45,    43,    37,   167,    75,    56,    37,
      37,    76,    12,     6,    52,   152,    60,    78,    45,    77,
      12,     6,    37,    31,    34,    14,    76,    12,     6,   -11,
      44,   -97,    48,    14,    77,    93,    24,    46,    53,   172,
     109,    55,   104,    81,   140,   105,    41,    61,    24,    57,
     111,   114,    58,   121,    75,   116,   117,   118,   119,    80,
     174,    81,    12,     6,    12,     6,   176,    99,   143,   142,
      55,    62,    63,    13,   100,    75,   145,    14,    64,   115,
      65,    75,   122,    66,    67,   137,   168,    12,     6,   120,
       6,   146,   147,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     9,    26,    83,
      84,    85,   175,    30,   104,    81,    83,   105,    85,   173,
      86,    87,   106,    54,    79,    32,     6,    86,    87,    88,
     110,   101,   102,     6,     0,     0,    88,   112,     0,    83,
      89,    85,    90,     0,     0,    91,    66,    89,    61,    90,
      86,    87,    91,    66,     0,     0,     6,     0,     0,    88,
       0,     0,    43,    12,     6,     0,    83,     0,    85,     0,
      89,    55,    90,    63,     0,    91,    66,    86,    87,    64,
       0,    65,    61,     6,    66,    67,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     6,    90,
       0,     0,    91,    66,     0,    55,     0,    63,     0,     0,
       0,     0,     0,    64,     0,    65,     0,     0,    66,    67,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
     170,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,   148,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,   151,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,   123,   169,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   171,     0,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136
};

static const yytype_int16 yycheck[] =
{
      12,    55,    71,     1,    96,     1,    17,    11,     1,    75,
      33,    21,    16,    19,    24,    11,    70,    71,    14,    30,
      16,    17,     0,    19,     4,    31,    22,    20,    34,    27,
      25,    97,   101,    20,    30,    31,    28,    41,    34,    35,
      46,    45,     1,    23,    26,    41,   138,   101,    48,    45,
      46,    55,    19,    20,    58,   121,    52,    57,    23,    55,
      19,    20,    58,    16,    17,    32,    70,    19,    20,    28,
      25,    20,    24,    32,    70,    65,    25,    30,    26,   148,
      76,    27,    22,    23,    96,    25,    23,     4,    25,    24,
      80,    81,    21,    89,   148,    85,    86,    87,    88,    23,
     169,    23,    19,    20,    19,    20,   175,    23,   104,    99,
      27,    28,    29,    28,    28,   169,   106,    32,    35,     4,
      37,   175,    23,    40,    41,    25,   138,    19,    20,    19,
      20,     4,     4,    24,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,     3,    14,     3,
       4,     5,    38,    16,    22,    23,     3,    25,     5,   149,
      14,    15,    30,    45,    58,    16,    20,    14,    15,    23,
      79,    70,    70,    20,    -1,    -1,    23,    24,    -1,     3,
      34,     5,    36,    -1,    -1,    39,    40,    34,     4,    36,
      14,    15,    39,    40,    -1,    -1,    20,    -1,    -1,    23,
      -1,    -1,    26,    19,    20,    -1,     3,    -1,     5,    -1,
      34,    27,    36,    29,    -1,    39,    40,    14,    15,    35,
      -1,    37,     4,    20,    40,    41,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    20,    36,
      -1,    -1,    39,    40,    -1,    27,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    37,    -1,    -1,    40,    41,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,     4,    24,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     4,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    47,    48,    49,     1,    20,    82,     0,    49,
       1,    27,    19,    28,    32,    50,    51,    52,    53,    54,
      56,    61,    78,    82,    25,    81,    55,    82,    28,     1,
      52,    54,    61,    53,    54,    78,    56,    82,    55,    62,
      82,    23,    81,    26,    25,    23,    54,     4,    24,    57,
      58,    60,    78,    26,    57,    27,    63,    24,    21,    59,
      82,     4,    28,    29,    35,    37,    40,    41,    63,    64,
      65,    66,    67,    68,    71,    77,    78,    82,    63,    60,
      23,    23,    75,     3,     4,     5,    14,    15,    23,    34,
      36,    39,    70,    72,    73,    74,    76,    77,    82,    23,
      28,    66,    68,    67,    22,    25,    30,    75,    80,    82,
      59,    72,    24,    69,    72,     4,    72,    72,    72,    72,
      19,    82,    23,     4,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    25,    79,    80,
      81,    75,    72,    82,    72,    72,     4,     4,    24,    21,
      24,    24,    75,    24,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    80,    81,    24,
      26,     4,    67,    72,    67,    38,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    51,    52,
      52,    53,    54,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    61,    62,    63,    63,    64,    64,
      64,    65,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    78,    78,    78,    78,
      79,    79,    80,    81,    81,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     4,     3,     2,     3,
       1,     1,     2,     1,     2,     2,     1,     2,     2,     1,
       2,     3,     1,     2,     3,     2,     2,     3,     2,     1,
       2,     2,     3,     2,     2,     2,     3,     2,     1,     1,
       2,     1,     2,     1,     2,     4,     3,     3,     1,     5,
       2,     1,     1,     3,     1,     3,     1,     2,     5,     7,
       1,     1,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     2,     2,     2,     2,     2,     2,     3,
       2,     2,     1,     1,     3,     2,     1,     1,     2,     2,
       1,     2,     3,     2,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 52 "program6.ypp" /* yacc.c:1646  */
    {
                derivations.push("<input> --> <program>");
                }
#line 1445 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "program6.ypp" /* yacc.c:1646  */
    {
                            classes.push((yyvsp[0].ttype));
                            derivations.push("<program> --> <classDeclaration>");
                            }
#line 1454 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "program6.ypp" /* yacc.c:1646  */
    {
                            classes.push((yyvsp[0].ttype));
                            derivations.push("<program> --> <program> <classDeclaration>");
                            }
#line 1463 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "program6.ypp" /* yacc.c:1646  */
    {
                                          (yyval.ttype)=new NodeClass((yyvsp[-3].ttype), (yyvsp[-1].ttype));
                                          derivations.push("<classDeclaration> --> "
                                                           "CLASS <identifier> LBRACE "
                                                           "<classBody> RBRACE");
                                          }
#line 1474 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 75 "program6.ypp" /* yacc.c:1646  */
    {
                                          (yyval.ttype)=new NodeClass((yyvsp[-2].ttype), 0);
                                          derivations.push("<classDeclaration> --> "
                                                           "CLASS <identifier> LBRACE "
                                                           "RBRACE");
                                          }
#line 1485 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "program6.ypp" /* yacc.c:1646  */
    {
                                          cout << "(" << row << ", " << column
                                               << ") Error in class";
                                          (yyvsp[-1].ttype)->prettyPrint(&cout);
                                          (yyval.ttype)=new NodeError(); // prevent a seg fault.
                                          }
#line 1496 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 87 "program6.ypp" /* yacc.c:1646  */
    {
                                          cout << "(" << row << ", " << column
                                               << ") Poorly defined class " 
                                               << endl;
                                          (yyval.ttype)=new NodeError(); // prevent a seg fault.
                                          }
#line 1507 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 96 "program6.ypp" /* yacc.c:1646  */
    {
                                                            (yyval.ttype)=new NodeClassBody((yyvsp[-2].ttype), 
                                                                            (yyvsp[-1].ttype), (yyvsp[0].ttype));
                                                            derivations.push("<classBody> --> "
                                                                             "<varDeclarations> "
                                                                             "<ConstructorDeclarations> "
                                                                             "<MethodDeclarations>");
                                                            }
#line 1520 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 104 "program6.ypp" /* yacc.c:1646  */
    {
                                              (yyval.ttype)=new NodeClassBody(0, 0, (yyvsp[0].ttype));
                                              derivations.push("<classBody> --> "
                                                               "<MethodDeclarations>");
                                              }
#line 1530 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 109 "program6.ypp" /* yacc.c:1646  */
    {
                                              (yyval.ttype)=new NodeClassBody((yyvsp[0].ttype));
                                              derivations.push("<classBody> --> <varDeclarations>");
                                              }
#line 1539 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 113 "program6.ypp" /* yacc.c:1646  */
    {
                                              (yyval.ttype)=new NodeClassBody((yyvsp[-1].ttype), (yyvsp[0].ttype));
                                              derivations.push("<classBody> --> "
                                                               "<varDeclarations> "
                                                               "<ConstructorDeclarations>");
                                              }
#line 1550 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 119 "program6.ypp" /* yacc.c:1646  */
    {
                                              (yyval.ttype)=new NodeClassBody(0, (yyvsp[0].ttype));
                                              derivations.push("<classBody> --> "
                                                               "<ConstructorDeclarations>");
                                              }
#line 1560 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 124 "program6.ypp" /* yacc.c:1646  */
    {
                                              (yyval.ttype)=new NodeClassBody(0, (yyvsp[-1].ttype), (yyvsp[0].ttype));
                                              derivations.push("<classBody> --> "
                                                               "<ConstructorDeclarations> "
                                                               "<MethodDeclarations>");
                                              }
#line 1571 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "program6.ypp" /* yacc.c:1646  */
    {
                                              (yyval.ttype)=new NodeClassBody((yyvsp[-1].ttype), 0, (yyvsp[0].ttype));
                                              derivations.push("<classBody> --> "
                                                               "<varDeclarations> "
                                                               "<MethodDeclarations>");
                                              }
#line 1582 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 139 "program6.ypp" /* yacc.c:1646  */
    {
                          (yyval.ttype)=(yyvsp[0].ttype);
                          derivations.push("<varDeclarations> --> <vardec>");
                          }
#line 1591 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 143 "program6.ypp" /* yacc.c:1646  */
    {
                          (yyval.ttype)=new Node((yyvsp[-1].ttype), (yyvsp[0].ttype));
                          derivations.push("<varDeclarations> --> <varDeclarations> <vardec>");
                          }
#line 1600 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 147 "program6.ypp" /* yacc.c:1646  */
    {
                          cout << "(" << row << ", " << column << ")"
                               << " Bad variable declaration around ("
                               << yytext() << ")" << endl;
                          }
#line 1610 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 155 "program6.ypp" /* yacc.c:1646  */
    {
                                                  (yyval.ttype)=(yyvsp[0].ttype);
                                                  derivations.push("<ConstructorDeclarations> --> "
                                                                   "<ConstructorDeclaration>");
                                                  }
#line 1620 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 160 "program6.ypp" /* yacc.c:1646  */
    {
                                                  (yyval.ttype)=new Node((yyvsp[-1].ttype), (yyvsp[0].ttype));
                                                  derivations.push("<ConstructorDeclarations> --> "
                                                                   "<ConstructorDeclarations> "
                                                                   "<ConstructorDeclaration>");
                                                  }
#line 1631 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 169 "program6.ypp" /* yacc.c:1646  */
    {
                                      (yyval.ttype)=new NodeConstructorDec((yyvsp[-2].ttype), (yyvsp[0].ttype));
                                      derivations.push("<ConstructorDeclaration> --> <identifier> "
                                                       "LPAREN <ParameterList> RPAREN <Block>");

                                      }
#line 1642 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "program6.ypp" /* yacc.c:1646  */
    {
                                      (yyval.ttype)=(yyvsp[0].ttype);
                                      derivations.push("<MethodDeclarations> --> <MethodDeclaration>");
                                      }
#line 1651 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 182 "program6.ypp" /* yacc.c:1646  */
    {
                                      (yyval.ttype)=new Node((yyvsp[-1].ttype), (yyvsp[0].ttype));
                                      derivations.push("<MethodDeclarations> --> <MethodDeclarations> "
                                                       "<MethodDeclaration>");
                                      }
#line 1661 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 191 "program6.ypp" /* yacc.c:1646  */
    {
                                      (yyval.ttype)=new NodeTemp((yyvsp[-2].ttype), (yyvsp[0].ttype));
                                      }
#line 1669 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 197 "program6.ypp" /* yacc.c:1646  */
    {
              (yyval.ttype)=new NodeMethodDec((yyvsp[-1].ttype), (yyvsp[0].ttype));
              derivations.push("<MethodDeclaration> --> "
                               "<ResultType> <identifier> "
                               "LPAREN <ParameterList> RPAREN <Block>");
              }
#line 1680 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 203 "program6.ypp" /* yacc.c:1646  */
    {
              (yyval.ttype)=new NodeMethodDec(0, (yyvsp[0].ttype));
              derivations.push("<MethodDeclaration> --> "
                               "VOID <identifier> "
                               "LPAREN <ParameterList> RPAREN <Block>");
              }
#line 1691 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 213 "program6.ypp" /* yacc.c:1646  */
    {
                            (yyval.ttype)=new NodeParamListAndBlock((yyvsp[-2].ttype), (yyvsp[0].ttype));
                            }
#line 1699 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 216 "program6.ypp" /* yacc.c:1646  */
    {
                            derivations.push("<ParameterList --> EMPTY");
                            (yyval.ttype)=new NodeParamListAndBlock(0, (yyvsp[0].ttype));
                            }
#line 1708 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "program6.ypp" /* yacc.c:1646  */
    {
                                  derivations.push("<ParameterList> --> <Parameter>");
                                  (yyval.ttype)=(yyvsp[0].ttype);
                                  }
#line 1717 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 228 "program6.ypp" /* yacc.c:1646  */
    {
                                  (yyval.ttype)=new NodeParameterList((yyvsp[-1].ttype), (yyvsp[0].ttype));
                                  derivations.push("<ParameterList> --> <Parameter> "
                                                   "<MoreParameters>");
                                  }
#line 1727 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 236 "program6.ypp" /* yacc.c:1646  */
    {
                                  (yyval.ttype)=(yyvsp[0].ttype);
                                  derivations.push("<MoreParameters> --> COMMA <Parameter>");
                                  }
#line 1736 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 240 "program6.ypp" /* yacc.c:1646  */
    {
                                  (yyval.ttype)=new NodeParameterList((yyvsp[-1].ttype), (yyvsp[0].ttype));
                                  derivations.push("<MoreParameters> --> COMMA <Parameter> "
                                                   "<MoreParameters>");
                                  }
#line 1746 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 248 "program6.ypp" /* yacc.c:1646  */
    {
                (yyval.ttype)=new NodeParameter((yyvsp[-1].ttype), (yyvsp[0].ttype));
                derivations.push("<Parameter> --> <type> <identifier>");
                }
#line 1755 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 255 "program6.ypp" /* yacc.c:1646  */
    {
                                      (yyval.ttype)=new nodeVardec((yyvsp[-1].ttype),(yyvsp[0].ttype));
                                      derivations.push("<vardec> --> <type> "
                                                       "<multibrackets> "
                                                       "<identifierSemi>");
                                      }
#line 1766 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 264 "program6.ypp" /* yacc.c:1646  */
    {
                  derivations.push("<identifierSemi> --> <identifier> SEMI");
                  (yyval.ttype)=(yyvsp[-1].ttype);
                  }
#line 1775 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 271 "program6.ypp" /* yacc.c:1646  */
    {
                          derivations.push("<Block> --> LBRACE <InnerBlock> RBRACE");
                          (yyval.ttype)=new NodeBlock((yyvsp[-1].ttype));
                          }
#line 1784 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 275 "program6.ypp" /* yacc.c:1646  */
    {
                          (yyval.ttype)=0;
                          derivations.push("<Block> --> LBRACE RBRACE");
                          }
#line 1793 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 284 "program6.ypp" /* yacc.c:1646  */
    {
                          (yyval.ttype)=new Node((yyvsp[0].ttype));
                          derivations.push("<InnerBlock> --> <LocalVardecs>");
                          }
#line 1802 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 288 "program6.ypp" /* yacc.c:1646  */
    {
                          (yyval.ttype)=new Node(0, (yyvsp[0].ttype));
                          derivations.push("<InnerBlock> --> <Statements>");
                          }
#line 1811 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 292 "program6.ypp" /* yacc.c:1646  */
    {
                          (yyval.ttype)=new Node((yyvsp[-1].ttype), (yyvsp[0].ttype));
                          derivations.push("<InnerBlock> --> <LocalVarDecs> "
                                           "<Statements>");
                          }
#line 1821 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 300 "program6.ypp" /* yacc.c:1646  */
    {
                            (yyval.ttype)=(yyvsp[0].ttype);
                            derivations.push("<LocalVardecs> --> <LocalVarDec>");
                            }
#line 1830 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 304 "program6.ypp" /* yacc.c:1646  */
    {
                            (yyval.ttype)=new Node((yyvsp[-1].ttype), (yyvsp[0].ttype));
                            derivations.push("<LocalVarDecs> --> <LocalVarDecs> "
                                             "<LocalVarDec>");
                            }
#line 1840 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 312 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=(yyvsp[0].ttype);
                      derivations.push("<Statements> --> <Statement>");
                      }
#line 1849 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 316 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new Node((yyvsp[-1].ttype), (yyvsp[0].ttype));
                      derivations.push("<Statements> --> <Statements> <Statement>");
                      }
#line 1858 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 323 "program6.ypp" /* yacc.c:1646  */
    {
                                    (yyval.ttype)=new NodeAssign((yyvsp[-3].ttype), (yyvsp[-1].ttype));
                                    derivations.push("<Statement> --> <name> "
                                                     "ASSIGN <exp> SEMI");
                                    }
#line 1868 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 328 "program6.ypp" /* yacc.c:1646  */
    {
                                    (yyval.ttype)=new NodeFunct((yyvsp[-2].ttype), (yyvsp[-1].ttype));
                                    derivations.push("<Statement> --> <name> "
                                                     "<paramList> SEMI");
                                    }
#line 1878 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 333 "program6.ypp" /* yacc.c:1646  */
    {
                                    (yyval.ttype)=new NodePrint((yyvsp[-1].ttype));
                                    derivations.push("<Statement> --> PRINT "
                                                     "<paramList> SEMI");
                                    }
#line 1888 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 338 "program6.ypp" /* yacc.c:1646  */
    {
                                    (yyval.ttype)=(yyvsp[0].ttype);
                                    derivations.push("<Statement> --> "
                                                     "<ConditionalStatement>");
                                    }
#line 1898 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 343 "program6.ypp" /* yacc.c:1646  */
    {
                                    (yyval.ttype)=new NodeWhile((yyvsp[-2].ttype), (yyvsp[0].ttype));
                                    derivations.push("<Statement> --> WHILE "
                                                     "LPAREN <exp> RPAREN "
                                                     "<Statement>");
                                    }
#line 1909 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 349 "program6.ypp" /* yacc.c:1646  */
    {
                                    (yyval.ttype)=new NodeOptional((yyvsp[0].ttype));
                                    derivations.push("<Statement> --> RETURN "
                                                     "<OptionalExpressions>");
                                    }
#line 1919 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 354 "program6.ypp" /* yacc.c:1646  */
    {
                                    (yyval.ttype)=(yyvsp[0].ttype);
                                    derivations.push("<Statement> --> <Block>");
                                    }
#line 1928 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 358 "program6.ypp" /* yacc.c:1646  */
    {
                                    derivations.push("<Statement> --> SEMI");
                                    }
#line 1936 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 364 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new nodeVardec((yyvsp[-2].ttype), (yyvsp[-1].ttype));
                      derivations.push("<LocalVarDec> --> <type> "
                                       "<identifier> SEMI");
                      }
#line 1946 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 372 "program6.ypp" /* yacc.c:1646  */
    {
                    (yyval.ttype)=new Node(0, (yyvsp[0].ttype));
                    derivations.push("<Arglist> --> <exp>");
                    }
#line 1955 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 376 "program6.ypp" /* yacc.c:1646  */
    {
                    (yyval.ttype)=new Node((yyvsp[-2].ttype), (yyvsp[0].ttype));
                    derivations.push("<Arglist> --> <Arglist> COMMA <exp>");
                    }
#line 1964 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 383 "program6.ypp" /* yacc.c:1646  */
    {
            (yyval.ttype)=0;
            derivations.push("<OptionalExpression> --> SEMI");
            }
#line 1973 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 387 "program6.ypp" /* yacc.c:1646  */
    {
            (yyval.ttype)=(yyvsp[-1].ttype);
            derivations.push("<OptionalExpression> --> <exp> SEMI");
            }
#line 1982 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 394 "program6.ypp" /* yacc.c:1646  */
    {
                                (yyval.ttype)=new NodeConditional((yyvsp[-2].ttype), (yyvsp[0].ttype), 0);
                                derivations.push("<ConditionalStatement> --> "
                                                "IF LPAREN <exp> RPAREN "
                                                "<Statement>");
                                }
#line 1993 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 400 "program6.ypp" /* yacc.c:1646  */
    {
                                                (yyval.ttype)=new NodeConditional((yyvsp[-4].ttype), (yyvsp[-2].ttype), 
                                                                       (yyvsp[0].ttype));
                                                derivations.push("<ConditionalStatement>"
                                                                 " --> "
                                                                 "IF LPAREN exp"
                                                                 " RPAREN <State"
                                                                 "ment> ELSE <St"
                                                                 "atement>");
                                                }
#line 2008 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 413 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=(yyvsp[0].ttype);
                      derivations.push("<exp> --> <name>");
                      }
#line 2017 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 417 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new NodeNull();
                      derivations.push("<exp> --> NULLT");
                      }
#line 2026 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 421 "program6.ypp" /* yacc.c:1646  */
    {
                      derivations.push("NUM --> " + to_string((yyvsp[0].ttype)->getint()));
                      derivations.push("<exp> --> NUM");
                      (yyval.ttype)=new nodeNum((yyvsp[0].ttype)->getint()); delete (yyvsp[0].ttype); 
                      }
#line 2036 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 426 "program6.ypp" /* yacc.c:1646  */
    {
                      derivations.push("<exp> --> <name> <paramList>");
                      (yyval.ttype)=new NodeFunct((yyvsp[-1].ttype), (yyvsp[0].ttype));
                      }
#line 2045 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 430 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new NodeOr((yyvsp[-2].ttype),(yyvsp[0].ttype));
                      (yyval.ttype)->setval(" || ");
                      derivations.push("<exp> --> <exp> OR <exp>");
                      }
#line 2055 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 435 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new NodeAnd((yyvsp[-2].ttype),(yyvsp[0].ttype));
                      (yyval.ttype)->setval(" && ");
                      derivations.push("<exp> --> <exp> AND <exp>");
                      }
#line 2065 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 440 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new NodeMod((yyvsp[-2].ttype),(yyvsp[0].ttype));
                      (yyval.ttype)->setval(" % "); 
                      derivations.push("<exp> --> <exp> MOD <exp>");
                      }
#line 2075 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 445 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new NodeRead();
                      derivations.push("<exp> --> READ LPAREN RPAREN");
                      }
#line 2084 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 449 "program6.ypp" /* yacc.c:1646  */
    { 
                      (yyval.ttype)=new NodePlus((yyvsp[-2].ttype),(yyvsp[0].ttype));
                      (yyval.ttype)->setval(" + ");
                      derivations.push("<exp> --> <exp> PLUS <exp>");
                      }
#line 2094 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 454 "program6.ypp" /* yacc.c:1646  */
    { 
                      (yyval.ttype)=new NodeMinus((yyvsp[-2].ttype),(yyvsp[0].ttype));
                      (yyval.ttype)->setval(" - ");
                      derivations.push("<exp> --> <exp> MINUS <exp>");
                      }
#line 2104 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 459 "program6.ypp" /* yacc.c:1646  */
    { 
                      (yyval.ttype)=new NodeTimes((yyvsp[-2].ttype),(yyvsp[0].ttype));
                      (yyval.ttype)->setval(" * ");
                      derivations.push("<exp> --> <exp> TIMES <exp>");
                      }
#line 2114 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 464 "program6.ypp" /* yacc.c:1646  */
    { 
                      (yyval.ttype)=new NodeDivide((yyvsp[-2].ttype),(yyvsp[0].ttype));
                      (yyval.ttype)->setval(" / ");
                      derivations.push("<exp> --> <exp> DIV <exp>");
                      }
#line 2124 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 469 "program6.ypp" /* yacc.c:1646  */
    { 
                      (yyval.ttype)=(yyvsp[0].ttype);
                      derivations.push("<exp> --> <UnaryOp>");
                      }
#line 2133 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 473 "program6.ypp" /* yacc.c:1646  */
    { 
                      (yyval.ttype)=new nodeParExp((yyvsp[-1].ttype));
                      derivations.push("<exp> --> LPAREN <exp> RPAREN");
                      }
#line 2142 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 477 "program6.ypp" /* yacc.c:1646  */
    {
                (yyval.ttype)=new nodeComparatorExp(
                  nodeComparatorExp::Comparator::GT, (yyvsp[-2].ttype), (yyvsp[0].ttype));
                derivations.push("<exp> --> <exp> GT <exp>");
                }
#line 2152 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 482 "program6.ypp" /* yacc.c:1646  */
    {
                (yyval.ttype)=new nodeComparatorExp(
                  nodeComparatorExp::Comparator::LT, (yyvsp[-2].ttype), (yyvsp[0].ttype));
                derivations.push("<exp> --> <exp> LT <exp>");
                }
#line 2162 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 487 "program6.ypp" /* yacc.c:1646  */
    {
                (yyval.ttype)=new NodeEquality((yyvsp[-2].ttype), (yyvsp[0].ttype));
                derivations.push("<exp> --> <exp> EQ <exp>");
                }
#line 2171 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 491 "program6.ypp" /* yacc.c:1646  */
    {
                (yyval.ttype)=new NodeNotEquality((yyvsp[-2].ttype), (yyvsp[0].ttype));
                derivations.push("<exp> --> <exp> NEQ <exp>");
                }
#line 2180 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 495 "program6.ypp" /* yacc.c:1646  */
    {
                (yyval.ttype)=new nodeComparatorExp(
                  nodeComparatorExp::Comparator::LEQ, (yyvsp[-2].ttype), (yyvsp[0].ttype));
                derivations.push("<exp> --> <exp> LEQ <exp>");
                }
#line 2190 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 500 "program6.ypp" /* yacc.c:1646  */
    {
                (yyval.ttype)=new nodeComparatorExp(
                  nodeComparatorExp::Comparator::GEQ, (yyvsp[-2].ttype), (yyvsp[0].ttype));
                derivations.push("<exp> --> <exp> GEQ <exp>");
                }
#line 2200 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 505 "program6.ypp" /* yacc.c:1646  */
    {
                (yyval.ttype)=(yyvsp[0].ttype);
                derivations.push("<exp> --> <newexp>");
                }
#line 2209 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 512 "program6.ypp" /* yacc.c:1646  */
    {
                                      (yyval.ttype)=new NodeNewConstructor((yyvsp[-1].ttype), (yyvsp[0].ttype));
                                      derivations.push("<newexp> --> NEW "
                                                       "<identifier> "
                                                       "<paramList>");
                                      }
#line 2220 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 518 "program6.ypp" /* yacc.c:1646  */
    {
                                      (yyval.ttype)=new NodeNewExpBrack((yyvsp[-2].ttype), (yyvsp[-1].ttype), (yyvsp[0].ttype));
                                      derivations.push("<newexp> --> "
                                                       "<newType> "
                                                       "<bracketexps> "
                                                       "<multibrackets>");
                                      }
#line 2232 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 525 "program6.ypp" /* yacc.c:1646  */
    {
                                      (yyval.ttype)=new nodeNewExp((yyvsp[-1].ttype), (yyvsp[0].ttype));
                                      derivations.push("<newexp> --> "
                                                       "<newType> "
                                                       "<bracketexps>");
                                      }
#line 2243 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 531 "program6.ypp" /* yacc.c:1646  */
    {
                                      (yyval.ttype)=new NodeNewBrack((yyvsp[-1].ttype), (yyvsp[0].ttype));
                                      derivations.push("<newexp> --> "
                                                       "<newType> "
                                                       "<multibrackets>");
                                      }
#line 2254 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 540 "program6.ypp" /* yacc.c:1646  */
    {
            (yyval.ttype)=new NodeNegative((yyvsp[0].ttype));
            derivations.push("<UnaryOp> --> MINUS <exp>");
            }
#line 2263 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 544 "program6.ypp" /* yacc.c:1646  */
    {
            (yyval.ttype)=new NodePositive((yyvsp[0].ttype));
            derivations.push("<UnaryOp> --> PLUS <exp>");
            }
#line 2272 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 548 "program6.ypp" /* yacc.c:1646  */
    {
            (yyval.ttype)=new NodeNot((yyvsp[0].ttype));
            derivations.push("<UnaryOp> --> NOT <exp>");
            }
#line 2281 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 555 "program6.ypp" /* yacc.c:1646  */
    {
                        (yyval.ttype)=new NodeParamList(0);
                        derivations.push("<paramList> --> LPAREN RPAREN");
                        }
#line 2290 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 559 "program6.ypp" /* yacc.c:1646  */
    {
                        (yyval.ttype)=new NodeParamList((yyvsp[-1].ttype));
                        derivations.push("<paramList> --> LPAREN"
                                         " <Arglist> RPAREN");
                        }
#line 2300 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 567 "program6.ypp" /* yacc.c:1646  */
    {
              (yyval.ttype)=new NodeNewType();
              derivations.push("<newType> --> NEW INT");
              }
#line 2309 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 571 "program6.ypp" /* yacc.c:1646  */
    {
              (yyval.ttype)=new NodeNewType((yyvsp[0].ttype));
              derivations.push("<newType> --> NEW <identifier>");
              }
#line 2318 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 578 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new NodeThis();
                      derivations.push("<name> --> THIS");
                      }
#line 2327 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 582 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=(yyvsp[0].ttype);
                      derivations.push("<name> --> <identifier>");
                      }
#line 2336 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 586 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new nodeDot((yyvsp[-2].ttype),(yyvsp[0].ttype));
                      derivations.push("<name> --> <name> DOT <identifier>");
                      }
#line 2345 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 590 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new NodeNameBrack((yyvsp[-1].ttype),(yyvsp[0].ttype));
                      derivations.push("<name> --> <name> <bracketexps>");
                      }
#line 2354 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 597 "program6.ypp" /* yacc.c:1646  */
    {
              (yyval.ttype)=new NodeType();
              derivations.push("<type> --> INT");
              }
#line 2363 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 601 "program6.ypp" /* yacc.c:1646  */
    {
              (yyval.ttype)=new NodeType((yyvsp[0].ttype));
              derivations.push("<type> --> <identifier>");
              }
#line 2372 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 605 "program6.ypp" /* yacc.c:1646  */
    {
                      (yyval.ttype)=new NodeType(0, (yyvsp[0].ttype));
                      derivations.push("<type> --> INT <multibrackets>");
                      }
#line 2381 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 609 "program6.ypp" /* yacc.c:1646  */
    {
                            (yyval.ttype)=new NodeType((yyvsp[-1].ttype), (yyvsp[0].ttype));
                            derivations.push("<type> --> <identifier> <multibrackets>");
                            }
#line 2390 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 616 "program6.ypp" /* yacc.c:1646  */
    {
                          (yyval.ttype)=(yyvsp[0].ttype);
                          derivations.push("<bracketexps> --> <bracketexp>");
                          }
#line 2399 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 620 "program6.ypp" /* yacc.c:1646  */
    {
                          (yyval.ttype)=new Node((yyvsp[-1].ttype),(yyvsp[0].ttype));
                          derivations.push("<bracketexps> --> <bracketexps>"
                                           " <bracketexp>");
                          }
#line 2409 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 628 "program6.ypp" /* yacc.c:1646  */
    {
                        (yyval.ttype)=new nodeBracketExp((yyvsp[-1].ttype));
                        derivations.push("<bracketexp> --> "
                                         "LBRACK <exp> RBRACK");
                        }
#line 2419 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 636 "program6.ypp" /* yacc.c:1646  */
    {
                              (yyval.ttype)=new NodeEmptyBrackets();
                              derivations.push("<multibrackets> --> "
                                               "LBRACK RBRACK");
                              }
#line 2429 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 641 "program6.ypp" /* yacc.c:1646  */
    {
                              (yyval.ttype)=new NodeEmptyBrackets((yyvsp[-2].ttype));
                              derivations.push("<multibrackets> --> "
                                               "<multibrackets> "
                                               "LBRACK RBRACK");
                              }
#line 2440 "program6.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 650 "program6.ypp" /* yacc.c:1646  */
    {
                (yyval.ttype)=new NodeIdentifier(yytext());
                string s("IDENT --> ");
                s.append(yytext());
                derivations.push(s);
                derivations.push("<identifier> --> IDENT");
                }
#line 2452 "program6.tab.cpp" /* yacc.c:1646  */
    break;


#line 2456 "program6.tab.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 658 "program6.ypp" /* yacc.c:1906  */

