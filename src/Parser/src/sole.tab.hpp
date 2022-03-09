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

#ifndef YY_YY_SOLE_TAB_HPP_INCLUDED
# define YY_YY_SOLE_TAB_HPP_INCLUDED
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
    SOLE_IDENTIFIER = 258,
    SOLE_CONST_INTEGER = 259,
    SOLE_CONST_FLOAT = 260,
    SOLE_CONST_ARRAY = 261,
    SOLE_CONST_OBJECT = 262,
    SOLE_FALSE = 263,
    SOLE_TRUE = 264,
    SOLE_STRING_LITERAL = 265,
    SOLE_CONST = 266,
    BAD_CHAR = 267,
    SOLE_VAR = 268,
    SOLE_ALIAS = 269,
    SOLE_FLOW = 270,
    SOLE_IF = 271,
    SOLE_ELSE = 272,
    SOLE_FOR = 273,
    SOLE_EVENT = 274,
    SOLE_END = 275,
    SOLE_THEN = 276,
    SOLE_ELSE_IF = 277,
    LE_OP = 278,
    GE_OP = 279,
    EQ_OP = 280,
    NE_OP = 281,
    OR_OP = 282,
    AND_OP = 283,
    UMINUS = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SOLE_TAB_HPP_INCLUDED  */
