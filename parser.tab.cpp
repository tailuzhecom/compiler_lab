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
#line 4 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "cgen.h"

std::shared_ptr<Program> prog = NULL;

void yyerror(char *s, ...);
int yylex();

#line 79 "parser.tab.cpp" /* yacc.c:339  */

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
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    DOUBLE = 260,
    LONG = 261,
    UNSIGNED = 262,
    CLASS = 263,
    SHORT = 264,
    SIGNED = 265,
    CHAR = 266,
    VOID = 267,
    BREAK = 268,
    SWITCH = 269,
    CASE = 270,
    ELSE = 271,
    FOR = 272,
    WHILE = 273,
    IF = 274,
    RETURN = 275,
    LPAREN = 276,
    RPAREN = 277,
    LBRACKET = 278,
    RBRACKET = 279,
    IDENTITY = 280,
    INT_NUMBER = 281,
    FLOAT_NUMBER = 282,
    STRING = 283,
    OR = 284,
    AND = 285,
    ASSIGN = 286,
    EQUAL = 287,
    LESS = 288,
    LESS_E = 289,
    GREATER = 290,
    GREATER_E = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "parser.y" /* yacc.c:355  */

    int intval;
    double floatval;
    char *strval;
    int subtok;
    ASTNode *node;
    Block *block_ptr;
    Sentence *sentence_ptr;
    IfStmt *ifstmt_ptr;
    WhileStmt *whilestmt_ptr;
    ForStmt *forstmt_ptr;
    DeclStmt *declstmt_ptr;
    AssignStmt *assignstmt_ptr;
    Expr *expr_ptr;
    std::string *str_ptr;
    ArgsList *argslist_ptr;
    IdList *idlist_ptr;
    ExprList *exprlist_ptr;
    CallStmt *callstmt_ptr;
    Factor *factor_ptr;
    BinExpr *binexpr_ptr;
    SingleExpr *singleexpr_ptr;
    ReturnStmt *returnstmt_ptr;
    ObjMember *objmember_ptr;

#line 182 "parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "parser.tab.cpp" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   547

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,    38,     2,     2,
       2,     2,    36,    34,    44,    35,    46,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    47,     2,     2,     2,
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
      26,    27,    28,    29,    30,    31,    32,    39,    40,    41,
      42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   110,   111,   112,   113,   114,   115,   120,
     124,   125,   126,   129,   133,   134,   135,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   152,   161,   165,
     169,   172,   173,   174,   178,   183,   193,   197,   200,   206,
     209,   210,   211,   215,   216,   217,   221,   222,   223,   224,
     228,   229,   233,   234,   237,   240,   243,   247,   248,   249,
     250,   251,   255,   256,   257,   258,   259,   260,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     279,   280,   284,   285,   286,   287,   288,   289,   290,   291
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "DOUBLE", "LONG",
  "UNSIGNED", "CLASS", "SHORT", "SIGNED", "CHAR", "VOID", "BREAK",
  "SWITCH", "CASE", "ELSE", "FOR", "WHILE", "IF", "RETURN", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "':'", "IDENTITY", "INT_NUMBER",
  "FLOAT_NUMBER", "STRING", "OR", "AND", "ASSIGN", "'!'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "EQUAL", "LESS", "LESS_E", "GREATER", "GREATER_E",
  "','", "';'", "'.'", "'~'", "$accept", "beg", "func", "args_list",
  "class_decl", "block", "sentence", "decl_stmt", "global_decl_stmt",
  "class_decl_stmt_list", "if_stmt", "while_stmt", "switch_stmt",
  "for_stmt", "call_stmt", "expr_list", "case_list", "id_list",
  "assign_stmt", "return_stmt", "break_stmt", "obj_member", "obj_call",
  "expr", "factor", "bin_expr", "single_expr", "type_dec", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    58,   280,   281,   282,   283,
     284,   285,   286,    33,    43,    45,    42,    47,    37,   287,
     288,   289,   290,   291,    44,    59,    46,   126
};
# endif

#define YYPACT_NINF -94

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-94)))

#define YYTABLE_NINF -90

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,   -94,   -94,   -94,   -94,    -1,   -18,   -94,   -94,   -94,
     108,   -94,   -94,   -35,   -94,     5,   -94,     3,   -94,   -94,
     -94,   -94,   -94,    -7,   -10,   -94,    -5,   384,   384,    50,
      16,    31,    50,   384,   368,    35,     0,    41,    50,   -14,
     -94,   -94,   -94,    50,    50,   -94,   -94,   -94,   473,   -94,
     -94,   -94,   -94,    -9,   -94,   473,   384,    24,    46,   -17,
      57,   384,   -94,   377,    50,    58,   496,   473,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
     -94,    28,   -94,   337,    65,   -94,    18,   473,    71,   -94,
     486,   496,   504,   504,    47,    47,    47,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,    72,    75,    79,    80,    50,    -8,
     182,    59,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
      -5,   473,    83,   -94,   -94,    50,    50,   384,    50,    50,
     473,   -94,    73,   -94,    -9,   473,   399,    84,   421,   443,
     -94,   112,    50,   117,   119,   116,   457,   337,   337,    38,
     122,   115,   213,   244,   126,   -94,    -9,   121,   -94,   131,
     337,   136,   138,   151,   337,   337,   -94,   275,   306,   -94,
     -94
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,    82,    84,    83,    86,     0,     0,    85,    88,    89,
       0,     2,     6,     0,     4,     0,    87,     0,     1,     3,
       7,     5,    28,    46,    27,    48,     0,    33,    12,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,    65,
      62,    63,    61,     0,     0,    64,    66,    67,    50,    58,
      59,    60,    55,    47,    49,    51,    32,     0,     0,     0,
       0,     0,    10,     0,    42,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,    29,    16,     0,    57,     0,    40,    55,    56,
      79,    78,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    30,    54,     0,     0,     0,     0,    53,    65,
      26,     0,    17,    19,    22,    24,    23,    18,    20,    21,
      66,    25,     0,    11,    39,     0,     0,     0,     0,     0,
      52,     9,     0,    14,    46,    41,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    45,     0,    16,    16,     0,
       0,     0,    26,    26,     0,    37,     0,     0,    36,    34,
      16,     0,     0,    26,    16,    16,    44,    26,    26,    38,
      35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,    33,   -94,   152,   -66,   -93,     1,   157,   140,
     -94,   -94,   -94,   -94,   109,   -94,    13,   -94,   -12,   -94,
     -94,   -15,   -94,   -23,    32,   -94,   -94,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    33,    36,    12,   110,   111,   112,    14,    34,
     113,   114,   115,   116,    45,    86,   150,    24,   117,   118,
     119,    46,    47,   121,    49,    50,    51,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    13,    15,    25,    28,    16,    48,    64,    17,    55,
      22,    13,    15,    64,    28,    63,    26,   132,   -89,    54,
      66,    67,    60,    29,    29,    29,    27,    32,    82,    35,
      37,    23,    65,    11,    31,    35,    58,    30,    65,    30,
     124,    87,    52,    19,    61,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    53,    58,   132,
     132,    59,   125,    84,    39,    40,    41,    62,   120,    80,
     132,    38,    81,   102,   132,   132,    39,    40,    41,    42,
      83,   152,   153,    43,    88,   130,    75,    76,    77,    78,
      79,   123,    64,   126,   163,   120,   127,    44,   167,   168,
     128,   129,   135,   136,   133,   138,   139,    26,    18,   134,
      25,     1,     2,     3,     4,     5,     6,     7,   140,   146,
       8,     1,     2,     3,     4,     5,     6,     7,   137,   142,
       8,   149,   120,   120,     9,   145,    26,   120,   120,   157,
     147,   156,   148,   161,     9,   120,   155,   162,   120,   120,
     120,   160,   120,   120,     1,     2,     3,     4,     5,   164,
       7,   165,    20,     8,   103,   104,   149,    21,   105,   106,
     107,   108,    38,    56,    89,   -43,   166,   109,    40,    41,
      42,   154,     0,     0,    43,     1,     2,     3,     4,     5,
       0,     7,     0,     0,     8,   103,   104,     0,    44,   105,
     106,   107,   108,    38,     0,     0,   131,     0,   109,    40,
      41,    42,     0,     0,     0,    43,     1,     2,     3,     4,
       5,     0,     7,     0,     0,     8,   103,   104,     0,    44,
     105,   106,   107,   108,    38,     0,     0,   158,     0,   109,
      40,    41,    42,     0,     0,     0,    43,     1,     2,     3,
       4,     5,     0,     7,     0,     0,     8,   103,   104,     0,
      44,   105,   106,   107,   108,    38,     0,     0,   159,     0,
     109,    40,    41,    42,     0,     0,     0,    43,     1,     2,
       3,     4,     5,     0,     7,     0,     0,     8,   103,   104,
       0,    44,   105,   106,   107,   108,    38,     0,     0,   169,
       0,   109,    40,    41,    42,     0,     0,     0,    43,     1,
       2,     3,     4,     5,     0,     7,     0,     0,     8,   103,
     104,     0,    44,   105,   106,   107,   108,    38,     0,     0,
     170,     0,   109,    40,    41,    42,     0,     0,     0,    43,
       1,     2,     3,     4,     5,     0,     7,     0,     0,     8,
     103,   104,     0,    44,   105,   106,   107,   108,    38,     0,
       0,     0,     0,   109,    40,    41,    42,     0,     0,     0,
      43,     1,     2,     3,     4,     5,     0,     7,     0,     0,
       8,     0,     0,     0,    44,     0,     0,     1,     2,     3,
       4,     5,    57,     7,     9,     0,     8,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,    68,    69,     0,
       9,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,   141,     0,     0,     0,     0,     0,     0,     0,    68,
      69,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,   143,     0,     0,     0,     0,     0,     0,
       0,    68,    69,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   144,     0,     0,     0,     0,
       0,     0,     0,    68,    69,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    68,    69,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,   151,    68,    69,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    69,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      72,    73,    74,    75,    76,    77,    78,    79
};

static const yytype_int16 yycheck[] =
{
      15,     0,     0,    15,    21,     6,    29,    21,    26,    32,
      45,    10,    10,    21,    21,    38,    31,   110,    26,    31,
      43,    44,    22,    32,    32,    32,    23,    32,    45,    27,
      28,    26,    46,     0,    44,    33,    34,    46,    46,    46,
      22,    64,    26,    10,    44,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    26,    56,   152,
     153,    26,    44,    61,    26,    27,    28,    26,    83,    45,
     163,    21,    26,    45,   167,   168,    26,    27,    28,    29,
      23,   147,   148,    33,    26,   108,    39,    40,    41,    42,
      43,    26,    21,    21,   160,   110,    21,    47,   164,   165,
      21,    21,   125,   126,    45,   128,   129,   122,     0,    26,
     122,     3,     4,     5,     6,     7,     8,     9,    45,   142,
      12,     3,     4,     5,     6,     7,     8,     9,   127,    45,
      12,    15,   147,   148,    26,    23,   151,   152,   153,   151,
      23,    26,    23,    22,    26,   160,    24,    16,   163,   164,
     165,    25,   167,   168,     3,     4,     5,     6,     7,    23,
       9,    23,    10,    12,    13,    14,    15,    10,    17,    18,
      19,    20,    21,    33,    65,    24,   163,    26,    27,    28,
      29,   149,    -1,    -1,    33,     3,     4,     5,     6,     7,
      -1,     9,    -1,    -1,    12,    13,    14,    -1,    47,    17,
      18,    19,    20,    21,    -1,    -1,    24,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,    33,     3,     4,     5,     6,
       7,    -1,     9,    -1,    -1,    12,    13,    14,    -1,    47,
      17,    18,    19,    20,    21,    -1,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    33,     3,     4,     5,
       6,     7,    -1,     9,    -1,    -1,    12,    13,    14,    -1,
      47,    17,    18,    19,    20,    21,    -1,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    -1,    -1,    33,     3,     4,
       5,     6,     7,    -1,     9,    -1,    -1,    12,    13,    14,
      -1,    47,    17,    18,    19,    20,    21,    -1,    -1,    24,
      -1,    26,    27,    28,    29,    -1,    -1,    -1,    33,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,    12,    13,
      14,    -1,    47,    17,    18,    19,    20,    21,    -1,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    33,
       3,     4,     5,     6,     7,    -1,     9,    -1,    -1,    12,
      13,    14,    -1,    47,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    -1,
      33,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
      12,    -1,    -1,    -1,    47,    -1,    -1,     3,     4,     5,
       6,     7,    24,     9,    26,    -1,    12,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      26,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    30,    31,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    30,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    31,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      36,    37,    38,    39,    40,    41,    42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    12,    26,
      49,    50,    52,    55,    56,    75,     6,    26,     0,    50,
      52,    56,    45,    26,    65,    66,    69,    23,    21,    32,
      46,    44,    32,    50,    57,    75,    51,    75,    21,    26,
      27,    28,    29,    33,    47,    62,    69,    70,    71,    72,
      73,    74,    26,    26,    66,    71,    57,    24,    75,    26,
      22,    44,    26,    71,    21,    46,    71,    71,    30,    31,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      45,    26,    45,    23,    75,    22,    63,    71,    26,    62,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    45,    13,    14,    17,    18,    19,    20,    26,
      53,    54,    55,    58,    59,    60,    61,    66,    67,    68,
      69,    71,    75,    26,    22,    44,    21,    21,    21,    21,
      71,    24,    54,    45,    26,    71,    71,    55,    71,    71,
      45,    22,    45,    22,    22,    23,    71,    23,    23,    15,
      64,    45,    53,    53,    72,    24,    26,    66,    24,    24,
      25,    22,    16,    53,    23,    23,    64,    53,    53,    24,
      24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    49,    49,    49,    49,    49,    50,
      51,    51,    51,    52,    53,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    56,    57,
      57,    57,    57,    57,    58,    58,    59,    60,    61,    62,
      63,    63,    63,    64,    64,    64,    65,    65,    65,    65,
      66,    66,    67,    67,    68,    69,    70,    71,    71,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     0,     8,
       2,     4,     0,     6,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     2,     3,
       4,     1,     2,     0,     7,    11,     7,     7,    11,     4,
       1,     3,     0,     4,     5,     0,     1,     3,     1,     3,
       3,     3,     2,     1,     1,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     2,     1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 109 "parser.y" /* yacc.c:1646  */
    { prog->Append(std::shared_ptr<ASTNode>((yyvsp[0].node))); }
#line 1578 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "parser.y" /* yacc.c:1646  */
    { prog->Append(std::shared_ptr<ASTNode>((yyvsp[0].node))); }
#line 1584 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 111 "parser.y" /* yacc.c:1646  */
    { prog->Append(std::shared_ptr<ASTNode>((yyvsp[0].declstmt_ptr))); }
#line 1590 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 112 "parser.y" /* yacc.c:1646  */
    { prog->Append(std::shared_ptr<ASTNode>((yyvsp[0].declstmt_ptr))); }
#line 1596 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 113 "parser.y" /* yacc.c:1646  */
    { prog->Append(std::shared_ptr<ASTNode>((yyvsp[0].node))); }
#line 1602 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 114 "parser.y" /* yacc.c:1646  */
    { prog->Append(std::shared_ptr<ASTNode>((yyvsp[0].node))); }
#line 1608 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Func((yyvsp[-7].strval), (yyvsp[-6].strval), std::shared_ptr<ArgsList>((yyvsp[-4].argslist_ptr)), std::shared_ptr<Block>((yyvsp[-1].block_ptr))); }
#line 1614 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.argslist_ptr) = new ArgsList; (yyval.argslist_ptr)->Append(VariableDef((yyvsp[-1].strval), (yyvsp[0].strval))); printf("arg name: %s\n", (yyvsp[0].strval)); }
#line 1620 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-3].argslist_ptr)->Append(VariableDef((yyvsp[-1].strval), (yyvsp[0].strval))); printf("arg name: %s\n", (yyvsp[0].strval)); }
#line 1626 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.argslist_ptr) = new ArgsList; }
#line 1632 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Class((yyvsp[-4].strval), std::shared_ptr<ArgsList>((yyvsp[-2].argslist_ptr))); printf("class %s\n", (yyvsp[-4].strval)); }
#line 1638 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.block_ptr) = new Block; (yyval.block_ptr)->Append(std::shared_ptr<Sentence>((yyvsp[-1].sentence_ptr))); }
#line 1644 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].block_ptr)->Append(std::shared_ptr<Sentence>((yyvsp[-1].sentence_ptr))); }
#line 1650 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.block_ptr) = new Block; }
#line 1656 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = (yyvsp[0].declstmt_ptr); }
#line 1662 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = (yyvsp[0].assignstmt_ptr); }
#line 1668 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = (yyvsp[0].ifstmt_ptr); }
#line 1674 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = (yyvsp[0].returnstmt_ptr); }
#line 1680 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = (yyvsp[0].sentence_ptr); }
#line 1686 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = (yyvsp[0].whilestmt_ptr); }
#line 1692 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = (yyvsp[0].forstmt_ptr); }
#line 1698 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = (yyvsp[0].sentence_ptr); }
#line 1704 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = (yyvsp[0].expr_ptr); }
#line 1710 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = new Sentence; }
#line 1716 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 152 "parser.y" /* yacc.c:1646  */
    {
    	(yyval.declstmt_ptr) = new DeclStmt((yyvsp[0].idlist_ptr)->GetIds());
    	(yyval.declstmt_ptr)->SetTypeForAllVariables((yyvsp[-1].strval));
    	printf("declare statement\n");
    }
#line 1726 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.declstmt_ptr) = (yyvsp[-1].declstmt_ptr); printf("global declare statement\n"); }
#line 1732 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 165 "parser.y" /* yacc.c:1646  */
    {
			(yyval.argslist_ptr) = new ArgsList;
		    	(yyval.argslist_ptr)->Append(VariableDef((yyvsp[-2].strval), (yyvsp[-1].strval)));
		    }
#line 1741 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 169 "parser.y" /* yacc.c:1646  */
    {
		    	(yyvsp[-3].argslist_ptr)->Append(VariableDef((yyvsp[-2].strval), (yyvsp[-1].strval)));
		    }
#line 1749 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 178 "parser.y" /* yacc.c:1646  */
    {
		(yyval.ifstmt_ptr) = new IfStmt; (yyval.ifstmt_ptr)->SetBoolExpr(std::shared_ptr<Expr>((yyvsp[-4].expr_ptr)));
		(yyval.ifstmt_ptr)->SetTrueBlock(std::shared_ptr<Block>((yyvsp[-1].block_ptr)));
		printf("if statement\n");
	}
#line 1759 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 183 "parser.y" /* yacc.c:1646  */
    {
        	(yyval.ifstmt_ptr) = new IfStmt;
        	(yyval.ifstmt_ptr)->SetBoolExpr(std::shared_ptr<Expr>((yyvsp[-8].expr_ptr)));
        	(yyval.ifstmt_ptr)->SetTrueBlock(std::shared_ptr<Block>((yyvsp[-5].block_ptr)));
        	(yyval.ifstmt_ptr)->SetFalseBlock(std::shared_ptr<Block>((yyvsp[-1].block_ptr)));
        	printf("if-else statement\n");
        }
#line 1771 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.whilestmt_ptr) = new WhileStmt(std::shared_ptr<Expr>((yyvsp[-4].expr_ptr)), std::shared_ptr<Block>((yyvsp[-1].block_ptr))); printf("while statement\n"); }
#line 1777 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr) = new SwitchStmt; printf("switch statement\n"); }
#line 1783 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 200 "parser.y" /* yacc.c:1646  */
    {
		(yyval.forstmt_ptr) = new ForStmt(std::shared_ptr<DeclStmt>((yyvsp[-8].declstmt_ptr)), std::shared_ptr<Expr>((yyvsp[-6].expr_ptr)), std::shared_ptr<AssignStmt>((yyvsp[-4].assignstmt_ptr)), std::shared_ptr<Block>((yyvsp[-1].block_ptr)));
		printf("for statement\n");
	}
#line 1792 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.callstmt_ptr) = new CallStmt((yyvsp[-3].strval), (yyvsp[-1].exprlist_ptr)->GetExprList()); printf("call %s\n", (yyvsp[-3].strval)); }
#line 1798 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist_ptr) = new ExprList; (yyval.exprlist_ptr)->Append(std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); }
#line 1804 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].exprlist_ptr)->Append(std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); }
#line 1810 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 215 "parser.y" /* yacc.c:1646  */
    { printf("case list\n"); }
#line 1816 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 216 "parser.y" /* yacc.c:1646  */
    { printf("case list\n"); }
#line 1822 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.idlist_ptr) = new IdList; (yyval.idlist_ptr)->Append(Variable("", (yyvsp[0].strval))); printf("iden: %s\n", (yyvsp[0].strval));  }
#line 1828 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].idlist_ptr)->Append(Variable("", (yyvsp[0].strval))); printf("iden: %s\n", (yyvsp[0].strval));  }
#line 1834 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.idlist_ptr) = new IdList; (yyval.idlist_ptr)->Append(Variable("", (yyvsp[0].assignstmt_ptr)->GetName(), (yyvsp[0].assignstmt_ptr)->GetVal())); }
#line 1840 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].idlist_ptr)->Append(Variable("", (yyvsp[0].assignstmt_ptr)->GetName(), (yyvsp[0].assignstmt_ptr)->GetVal())); }
#line 1846 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.assignstmt_ptr) = new AssignStmt((yyvsp[-2].strval), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("id: %s\n assignment\n", (yyvsp[-2].strval)); }
#line 1852 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.assignstmt_ptr) = new AssignStmt(std::shared_ptr<ObjMember>((yyvsp[-2].objmember_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); (yyvsp[-2].objmember_ptr)->SetIsVar(true); }
#line 1858 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.returnstmt_ptr) = new ReturnStmt(std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("return statement\n"); }
#line 1864 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.returnstmt_ptr) = new ReturnStmt(NULL); }
#line 1870 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.sentence_ptr)= new BreakStmt; printf("break statement\n"); }
#line 1876 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.objmember_ptr) = new ObjMember((yyvsp[-2].strval), (yyvsp[0].strval)); printf("obj: %s mem: %s\n", (yyvsp[-2].strval), (yyvsp[0].strval)); }
#line 1882 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 243 "parser.y" /* yacc.c:1646  */
    { printf("obj: %s\n", (yyvsp[-2].strval)); }
#line 1888 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_ptr) = (yyvsp[-1].expr_ptr); }
#line 1894 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_ptr) = (yyvsp[0].factor_ptr); }
#line 1900 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_ptr) = (yyvsp[0].binexpr_ptr); }
#line 1906 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_ptr) = (yyvsp[0].singleexpr_ptr); }
#line 1912 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_ptr) = new StringConst((yyvsp[0].strval)); printf("string const: %s\n", (yyvsp[0].strval)); }
#line 1918 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval.factor_ptr) = new IntConst((yyvsp[0].intval)); printf("int const: %d\n", (yyvsp[0].intval)); }
#line 1924 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.factor_ptr) = new FloatConst((yyvsp[0].floatval)); printf("float const: %d\n", (yyvsp[0].floatval)); }
#line 1930 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 257 "parser.y" /* yacc.c:1646  */
    { (yyval.factor_ptr) = (yyvsp[0].callstmt_ptr); }
#line 1936 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.factor_ptr) = new Identity((yyvsp[0].strval)); printf("iden factor: %s\n", (yyvsp[0].strval)); }
#line 1942 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval.factor_ptr) = (yyvsp[0].objmember_ptr); }
#line 1948 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(add_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("+\n"); }
#line 1954 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(sub_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("-\n"); }
#line 1960 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(mul_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("*\n"); }
#line 1966 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 267 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(div_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("/\n"); }
#line 1972 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(mod_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("%\n"); }
#line 1978 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(eq_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("==\n"); }
#line 1984 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(less_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("<\n"); }
#line 1990 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 271 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(lesseq_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("<=\n"); }
#line 1996 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 272 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(greater_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf(">\n"); }
#line 2002 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(greatereq_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf(">=\n"); }
#line 2008 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(and_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("&&\n"); }
#line 2014 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.binexpr_ptr) = new BinExpr(or_op, std::shared_ptr<Expr>((yyvsp[-2].expr_ptr)), std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("||\n"); }
#line 2020 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval.singleexpr_ptr) = new SingleExpr(not_op, std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("not expr\n"); }
#line 2026 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval.singleexpr_ptr) = new SingleExpr(neg_op, std::shared_ptr<Expr>((yyvsp[0].expr_ptr))); printf("neg expr\n"); }
#line 2032 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 284 "parser.y" /* yacc.c:1646  */
    { printf("type: int\n"); (yyval.strval) = "int"; }
#line 2038 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 285 "parser.y" /* yacc.c:1646  */
    { printf("type: double\n"); (yyval.strval) = "double"; }
#line 2044 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 286 "parser.y" /* yacc.c:1646  */
    { printf("type: float\n");  (yyval.strval) = "float"; }
#line 2050 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 287 "parser.y" /* yacc.c:1646  */
    { printf("type: short\n"); (yyval.strval) = "short"; }
#line 2056 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 288 "parser.y" /* yacc.c:1646  */
    { printf("type: long\n"); (yyval.strval) = "long"; }
#line 2062 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 289 "parser.y" /* yacc.c:1646  */
    { printf("type: unsigned\n"); (yyval.strval) = "unsigned long"; }
#line 2068 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 290 "parser.y" /* yacc.c:1646  */
    { printf("type: void\n"); (yyval.strval) = "void"; }
#line 2074 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 291 "parser.y" /* yacc.c:1646  */
    { printf("type: class\n"); (yyval.strval) = (yyvsp[0].strval); }
#line 2080 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2084 "parser.tab.cpp" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 293 "parser.y" /* yacc.c:1906  */


int main(int argc, const char *args[])
{
	/* 将注释去掉就能看到stack具体是怎么工作的.. */
    	//yydebug = 1;

	extern FILE *yyin;
	if(argc > 1 && (yyin = fopen(args[1], "r")) == NULL) {
		fprintf(stderr, "can not open %s\n", args[1]);
		exit(1);
	}

	printf("input file: %s", args[1]);

	prog = std::make_shared<Program>(args[1]);

	if(yyparse()) {
		exit(-1);
	}

	printf("\n\n");
	prog->Cgen();
    return 0;
}

void yyerror(char *s, ...)
{
    extern int yylineno;

    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "%d: error: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}
