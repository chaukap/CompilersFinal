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
#line 31 "program6.ypp" /* yacc.c:1909  */

  Node *ttype;

#line 104 "program6.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROGRAM6_TAB_HPP_INCLUDED  */
