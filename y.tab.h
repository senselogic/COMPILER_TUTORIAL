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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TOKEN_TYPE_And = 258,
    TOKEN_TYPE_Bool = 259,
    TOKEN_TYPE_Colon = 260,
    TOKEN_TYPE_Comma = 261,
    TOKEN_TYPE_Else = 262,
    TOKEN_TYPE_ClosingBrace = 263,
    TOKEN_TYPE_ClosingParenthesis = 264,
    TOKEN_TYPE_Equal = 265,
    TOKEN_TYPE_EqualEqual = 266,
    TOKEN_TYPE_False = 267,
    TOKEN_TYPE_For = 268,
    TOKEN_TYPE_Func = 269,
    TOKEN_TYPE_Identifier = 270,
    TOKEN_TYPE_If = 271,
    TOKEN_TYPE_Int = 272,
    TOKEN_TYPE_Minus = 273,
    TOKEN_TYPE_Integer = 274,
    TOKEN_TYPE_Not = 275,
    TOKEN_TYPE_OpeningBrace = 276,
    TOKEN_TYPE_OpeningParenthesis = 277,
    TOKEN_TYPE_Or = 278,
    TOKEN_TYPE_Plus = 279,
    TOKEN_TYPE_Read = 280,
    TOKEN_TYPE_Ref = 281,
    TOKEN_TYPE_Return = 282,
    TOKEN_TYPE_Semicolon = 283,
    TOKEN_TYPE_Slash = 284,
    TOKEN_TYPE_SmallerEqual = 285,
    TOKEN_TYPE_Smaller = 286,
    TOKEN_TYPE_Star = 287,
    TOKEN_TYPE_To = 288,
    TOKEN_TYPE_True = 289,
    TOKEN_TYPE_Var = 290,
    TOKEN_TYPE_Void = 291,
    TOKEN_TYPE_While = 292,
    TOKEN_TYPE_Write = 293
  };
#endif
/* Tokens.  */
#define TOKEN_TYPE_And 258
#define TOKEN_TYPE_Bool 259
#define TOKEN_TYPE_Colon 260
#define TOKEN_TYPE_Comma 261
#define TOKEN_TYPE_Else 262
#define TOKEN_TYPE_ClosingBrace 263
#define TOKEN_TYPE_ClosingParenthesis 264
#define TOKEN_TYPE_Equal 265
#define TOKEN_TYPE_EqualEqual 266
#define TOKEN_TYPE_False 267
#define TOKEN_TYPE_For 268
#define TOKEN_TYPE_Func 269
#define TOKEN_TYPE_Identifier 270
#define TOKEN_TYPE_If 271
#define TOKEN_TYPE_Int 272
#define TOKEN_TYPE_Minus 273
#define TOKEN_TYPE_Integer 274
#define TOKEN_TYPE_Not 275
#define TOKEN_TYPE_OpeningBrace 276
#define TOKEN_TYPE_OpeningParenthesis 277
#define TOKEN_TYPE_Or 278
#define TOKEN_TYPE_Plus 279
#define TOKEN_TYPE_Read 280
#define TOKEN_TYPE_Ref 281
#define TOKEN_TYPE_Return 282
#define TOKEN_TYPE_Semicolon 283
#define TOKEN_TYPE_Slash 284
#define TOKEN_TYPE_SmallerEqual 285
#define TOKEN_TYPE_Smaller 286
#define TOKEN_TYPE_Star 287
#define TOKEN_TYPE_To 288
#define TOKEN_TYPE_True 289
#define TOKEN_TYPE_Var 290
#define TOKEN_TYPE_Void 291
#define TOKEN_TYPE_While 292
#define TOKEN_TYPE_Write 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:1909  */

    char
        * String;
    struct _TOKEN
        * Token;
    struct _RULE
        * Rule;

#line 139 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
