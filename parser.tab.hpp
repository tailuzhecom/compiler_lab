/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 21 "parser.y" /* yacc.c:1909  */

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

#line 115 "parser.tab.hpp" /* yacc.c:1909  */
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
