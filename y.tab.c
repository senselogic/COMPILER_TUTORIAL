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
#line 1 "parser.y" /* yacc.c:339  */


// -- IMPORTS

#include "program.h"
#include "rule.h"
#include "string.h"
#include "system.h"
#include "token.h"

// ~~

int yylex(
    void
    );

// -- FUNCTIONS

int yyerror(
    STRING string
    )
{
    PrintProgramError( string, yytext );

    return 0;
}


#line 95 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
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
#line 31 "parser.y" /* yacc.c:355  */

    char
        * String;
    struct _TOKEN
        * Token;
    struct _RULE
        * Rule;

#line 220 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   173,   181,   189,   197,   205,   213,   221,
     229,   237,   245,   258,   266,   274,   287,   295,   303,   311,
     318,   326,   334,   342,   350,   358,   366,   374,   382,   388,
     397,   403,   415,   424,   433,   439,   445,   454,   460,   469,
     478,   486,   493,   501,   508,   523,   532,   542,   552,   562,
     572,   582,   592,   602,   610,   620,   630,   636,   642,   652,
     658,   666,   678,   691,   699,   706,   714,   721,   734,   742,
     749,   760,   775,   781,   790,   798,   805,   820,   832,   839,
     857,   874,   899,   912,   925,   938,   949,   955,   961,   967,
     973,   979,   985,   991,  1000,  1008,  1015,  1027,  1036,  1059
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_TYPE_And", "TOKEN_TYPE_Bool",
  "TOKEN_TYPE_Colon", "TOKEN_TYPE_Comma", "TOKEN_TYPE_Else",
  "TOKEN_TYPE_ClosingBrace", "TOKEN_TYPE_ClosingParenthesis",
  "TOKEN_TYPE_Equal", "TOKEN_TYPE_EqualEqual", "TOKEN_TYPE_False",
  "TOKEN_TYPE_For", "TOKEN_TYPE_Func", "TOKEN_TYPE_Identifier",
  "TOKEN_TYPE_If", "TOKEN_TYPE_Int", "TOKEN_TYPE_Minus",
  "TOKEN_TYPE_Integer", "TOKEN_TYPE_Not", "TOKEN_TYPE_OpeningBrace",
  "TOKEN_TYPE_OpeningParenthesis", "TOKEN_TYPE_Or", "TOKEN_TYPE_Plus",
  "TOKEN_TYPE_Read", "TOKEN_TYPE_Ref", "TOKEN_TYPE_Return",
  "TOKEN_TYPE_Semicolon", "TOKEN_TYPE_Slash", "TOKEN_TYPE_SmallerEqual",
  "TOKEN_TYPE_Smaller", "TOKEN_TYPE_Star", "TOKEN_TYPE_To",
  "TOKEN_TYPE_True", "TOKEN_TYPE_Var", "TOKEN_TYPE_Void",
  "TOKEN_TYPE_While", "TOKEN_TYPE_Write", "$accept", "BoolToken",
  "EqualToken", "ClosingBraceToken", "ClosingParenthesisToken",
  "ColonToken", "CommaToken", "ElseToken", "FalseToken", "ForToken",
  "FuncToken", "IdentifierToken", "IfToken", "IntToken", "IntegerToken",
  "OpeningBraceToken", "OpeningParenthesisToken", "ReadToken", "RefToken",
  "ReturnToken", "SemicolonToken", "ToToken", "TrueToken", "VarToken",
  "VoidToken", "WhileToken", "WriteToken", "BooleanConstantRule",
  "IntegerConstantRule", "FunctionNameRule", "VariableNameRule",
  "FunctionTypeRule", "VariableTypeRule", "FunctionArgumentRule",
  "NextFunctionArgumentRule", "FunctionArgumentListRule",
  "FunctionCallRule", "VariableExpressionRule", "ExpressionRule",
  "FunctionParameterRule", "NextFunctionParameterRule",
  "FunctionParameterListRule", "VariableRule", "NextVariableRule",
  "VariableListRule", "VariableDeclarationRule", "LocalDeclarationRule",
  "LocalDeclarationListRule", "AssignmentStatementRule",
  "ElseStatementRule", "IfStatementRule", "WhileStatementRule",
  "ForStatementRule", "WriteStatementRule", "ReadStatementRule",
  "ReturnStatementRule", "ExpressionStatementRule", "StatementRule",
  "StatementListRule", "FunctionBlockRule", "FunctionDeclarationRule",
  "ProgramRule", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -33

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -92,    15,   -92,    35,   -92,   -92,    26,   -92,   -92,
      50,   -92,   -92,    15,    47,    60,    59,    47,   -92,    20,
     -92,    50,   -92,   -92,    47,    20,   -92,   -92,   -92,   -92,
     -92,   -92,    46,   -92,   -92,   -92,   -92,   -92,     6,   -92,
     -92,    -4,   -92,   -92,   -92,    15,   -92,    -4,   176,   -92,
      47,    60,   -92,   -92,   -92,   -92,    56,   -92,   187,   -92,
     -92,   -92,   -92,   -92,   -92,    15,    65,   187,   -92,   187,
      15,   187,   -92,   187,   187,   -92,   -92,    26,   -92,   -92,
      71,   107,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     176,    80,    20,    15,    62,   -92,   -92,    74,    71,   123,
     139,    62,   107,   123,   107,   187,   -92,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   -92,   -92,   -92,
     -92,   -92,    60,   -92,   -92,   187,   176,   -92,   -92,   -92,
     176,   -92,    60,    59,   155,   107,    74,     4,    41,    74,
      41,   -92,     4,     4,   -92,   -92,    90,    80,    80,   187,
     -92,   -92,   -92,   -92,   187,    84,   -92,   -92,   123,   -92,
      73,   -92,   176,   176,    80,    80,   -92,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,     0,    99,     0,    12,    32,     0,     1,    17,
      66,    19,    33,     0,     0,    64,     0,     0,     6,     0,
       7,    66,    65,     5,     0,     0,     2,    14,    37,    38,
      62,    63,     0,    61,    25,    35,    36,    34,     0,    16,
      21,    75,    97,    98,    24,     0,    72,    75,    95,    73,
       0,    69,    74,     9,    10,    13,     0,    15,     0,    18,
      20,    23,    26,    27,    28,     0,    33,     0,    30,     0,
       0,     0,    29,     0,     0,    56,    57,     0,    45,    59,
      60,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      95,     0,     0,     0,     0,    31,    60,    53,     0,     0,
       0,     0,     0,     0,     0,    43,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    94,     4,
      96,    67,    69,    68,    71,     0,    95,    58,    83,    84,
      95,    82,    41,     0,    39,     0,    54,    50,    49,    55,
      48,    47,    51,    52,    46,    70,     0,     0,     0,    43,
      42,    44,    76,    22,     0,    78,    80,    40,     0,     8,
       0,    79,    95,    95,     0,     0,    81,    77
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,    64,    -1,    12,   -89,    -8,   -15,   -92,   -92,   -92,
     -92,    19,   -92,    67,    51,   -91,    -5,   -92,   -92,   -92,
     -55,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   100,
      -7,   -92,   -18,   -92,   -92,   -40,   -92,   -47,   -54,   -92,
     -92,   103,    18,     5,   -92,   -92,   -92,    81,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -85,   -92,
     129,   -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,   107,   120,    24,    19,    93,   160,    64,    65,
       2,    66,    67,    29,    68,    41,    69,    70,    13,    71,
      42,   154,    72,    45,    37,    73,    74,    75,    76,    77,
      78,    38,    30,   132,   150,   133,    79,    96,    81,    15,
      22,    16,    51,    94,   123,    46,    47,    48,    82,   161,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    43,
      49,     4
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    80,    10,    14,    97,   118,    17,    33,   126,    25,
       1,   127,   130,    99,    14,   100,    32,   102,    98,   103,
     104,     6,   110,   101,    26,     1,   117,    39,   112,    12,
       5,    44,    12,   113,    40,     8,   116,    27,    50,   124,
      12,   147,    92,    80,   151,   148,   128,   129,     9,   131,
      26,   134,    18,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    27,    12,     5,    20,   162,    23,   163,
     113,   146,   105,   116,   121,    57,    11,   164,   165,    80,
     152,   106,    34,    80,    12,   109,    50,   -32,   119,    12,
      40,   159,   110,   108,    39,   134,    35,   125,   112,    36,
     158,   109,     7,   113,   114,   115,   116,    95,   110,   157,
     108,   122,    12,   111,   112,    80,    80,   149,   109,   113,
     114,   115,   116,   153,    31,   110,   108,   145,    52,     3,
     111,   112,     0,     0,   109,    40,   113,   114,   115,   116,
       0,   110,   108,     0,    39,     0,   111,   112,    23,     0,
     109,     0,   113,   114,   115,   116,     0,   110,   108,   155,
     156,     0,   111,   112,     0,     0,   109,     0,   113,   114,
     115,   116,     0,   110,     0,     0,   166,   167,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,    53,    54,
       0,     5,    55,     0,    56,    57,    58,     0,     9,    53,
       0,    59,     5,    60,     0,    56,    57,    58,     0,     9,
      61,     0,     0,    62,    63,     0,     0,     0,     0,     0,
       0,    61
};

static const yytype_int16 yycheck[] =
{
      15,    48,     7,    10,    58,    90,    13,    25,    99,    17,
      14,   100,   103,    67,    21,    69,    24,    71,    65,    73,
      74,     2,    18,    70,     4,    14,    81,    21,    24,    10,
      15,    35,    13,    29,    28,     0,    32,    17,    45,    94,
      21,   126,    50,    90,   133,   130,   101,   102,    22,   104,
       4,   105,     5,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    17,    45,    15,     6,   158,     9,   160,
      29,   125,    77,    32,    92,    19,    26,   162,   163,   126,
     135,    10,    36,   130,    65,    11,    93,    22,     8,    70,
      28,     7,    18,     3,    21,   149,    32,    98,    24,    32,
     154,    11,     2,    29,    30,    31,    32,    56,    18,   149,
       3,    93,    93,    23,    24,   162,   163,   132,    11,    29,
      30,    31,    32,    33,    21,    18,     3,   122,    47,     0,
      23,    24,    -1,    -1,    11,    28,    29,    30,    31,    32,
      -1,    18,     3,    -1,    21,    -1,    23,    24,     9,    -1,
      11,    -1,    29,    30,    31,    32,    -1,    18,     3,   147,
     148,    -1,    23,    24,    -1,    -1,    11,    -1,    29,    30,
      31,    32,    -1,    18,    -1,    -1,   164,   165,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    12,    13,
      -1,    15,    16,    -1,    18,    19,    20,    -1,    22,    12,
      -1,    25,    15,    27,    -1,    18,    19,    20,    -1,    22,
      34,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    49,    99,   100,    15,    50,    68,     0,    22,
      55,    26,    50,    57,    69,    78,    80,    69,     5,    44,
       6,    45,    79,     9,    43,    44,     4,    17,    40,    52,
      71,    80,    44,    71,    36,    40,    52,    63,    70,    21,
      28,    54,    59,    98,    35,    62,    84,    85,    86,    99,
      69,    81,    86,    12,    13,    16,    18,    19,    20,    25,
      27,    34,    37,    38,    47,    48,    50,    51,    53,    55,
      56,    58,    61,    64,    65,    66,    67,    68,    69,    75,
      76,    77,    87,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    44,    45,    82,    53,    76,    77,    76,    77,
      77,    76,    77,    77,    77,    55,    10,    41,     3,    11,
      18,    23,    24,    29,    30,    31,    32,    59,    97,     8,
      42,    71,    81,    83,    59,    41,    54,    43,    59,    59,
      54,    59,    72,    74,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    82,    77,    97,    97,    45,
      73,    43,    59,    33,    60,    42,    42,    74,    77,     7,
      46,    88,    54,    54,    97,    97,    42,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    66,
      67,    67,    68,    69,    70,    70,    70,    71,    71,    72,
      73,    73,    74,    74,    75,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    82,    82,
      83,    84,    85,    85,    86,    86,    87,    88,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    96,    96,    96,
      96,    96,    96,    96,    97,    97,    98,    98,    99,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     2,     0,     4,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     1,     1,     3,     1,
       1,     4,     3,     2,     0,     2,     0,     3,     2,     0,
       2,     4,     1,     1,     2,     0,     4,     4,     0,     6,
       5,     9,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     4,     1,     8,     1
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
#line 166 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Bool );
    }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 174 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Equal );
    }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 182 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_ClosingBrace );
    }
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 190 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_ClosingParenthesis );
    }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 198 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Colon );
    }
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 206 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Comma );
    }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 214 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Else );
    }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 222 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_False );
    }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 230 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_For );
    }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 238 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Func );
    }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 246 "parser.y" /* yacc.c:1646  */
    {
        char
            * string;

        string = yyval.String;
        (yyval.Token) = MakeToken( TOKEN_TYPE_Identifier );
        (yyval.Token)->String = string;
    }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 259 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_If );
    }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 267 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Int );
    }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 275 "parser.y" /* yacc.c:1646  */
    {
        char
            * string;

        string = yyval.String;
        (yyval.Token) = MakeToken( TOKEN_TYPE_Integer );
        (yyval.Token)->String = string;
    }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 288 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_OpeningBrace );
    }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 296 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_OpeningParenthesis );
    }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 304 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Read );
    }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 312 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Ref );
    }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 319 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Return );
    }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 327 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Semicolon );
    }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 335 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_To );
    }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 343 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_True );
    }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 351 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Var );
    }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 359 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Void );
    }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 367 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_While );
    }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 375 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Token) = MakeToken( TOKEN_TYPE_Write );
    }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 383 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_BooleanConstant );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 389 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_BooleanConstant );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 398 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_IntegerConstant );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 405 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_IntegerConstant );
        AddLastToken( (yyval.Rule), MakeToken( TOKEN_TYPE_Integer ) );
        (yyval.Rule)->FirstToken->String = MakeString2( "-", (yyvsp[0].Token)->String );
        FreeToken( (yyvsp[0].Token) );
    }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 416 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionName );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 425 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_VariableName );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 434 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionType );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 440 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionType );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 446 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionType );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 455 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_VariableType );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 461 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_VariableType );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 470 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionArgument );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 480 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_NextFunctionArgument );
        AddLastToken( (yyval.Rule), (yyvsp[-1].Token) );
        AddSkippedSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 486 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_NextFunctionArgument );
    }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 495 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionArgumentList );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddSkippedSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 501 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionArgumentList );
    }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 512 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionCall );
        AddLastSubRule( (yyval.Rule), (yyvsp[-3].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-2].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 524 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_VariableExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 535 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_StarExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastTokenType( (yyval.Rule), TOKEN_TYPE_Star );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 545 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_SlashExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastTokenType( (yyval.Rule), TOKEN_TYPE_Slash );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 555 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_PlusExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastTokenType( (yyval.Rule), TOKEN_TYPE_Plus );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 565 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_MinusExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastTokenType( (yyval.Rule), TOKEN_TYPE_Minus );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 575 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_EqualEqualExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastTokenType( (yyval.Rule), TOKEN_TYPE_EqualEqual );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 585 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_SmallerEqualExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastTokenType( (yyval.Rule), TOKEN_TYPE_SmallerEqual );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 595 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_SmallerExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastTokenType( (yyval.Rule), TOKEN_TYPE_Smaller );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 604 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_NotExpression );
        AddLastTokenType( (yyval.Rule), TOKEN_TYPE_Not );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 613 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_AndExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastTokenType( (yyval.Rule), TOKEN_TYPE_And );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 623 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_OrExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastTokenType( (yyval.Rule), TOKEN_TYPE_Or );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 631 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_BooleanConstantExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 637 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_IntegerConstantExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 645 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_ParenthesisExpression );
        AddLastToken( (yyval.Rule), (yyvsp[-2].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 653 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionCallExpression );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 659 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = (yyvsp[0].Rule);
    }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 670 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionParameter );
        AddLastToken( (yyval.Rule), (yyvsp[-3].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-1].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 681 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionParameter );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-1].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 693 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_NextFunctionParameter );
        AddLastToken( (yyval.Rule), (yyvsp[-1].Token) );
        AddSkippedSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 699 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_NextFunctionParameter );
    }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 708 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionParameterList );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddSkippedSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 714 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionParameterList );
    }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 724 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_Variable );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-1].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 736 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_NextVariable );
        AddLastToken( (yyval.Rule), (yyvsp[-1].Token) );
        AddSkippedSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 742 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_NextVariable );
    }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 751 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_VariableList );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddSkippedSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 764 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_VariableDeclaration );
        AddLastToken( (yyval.Rule), (yyvsp[-3].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddSkippedSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 776 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_LocalDeclaration );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 782 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_LocalDeclaration );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 792 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_LocalDeclarationList );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddSkippedSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 798 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_LocalDeclarationList );
    }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 809 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_AssignmentStatement );
        AddLastSubRule( (yyval.Rule), (yyvsp[-3].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-2].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 824 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_ElseStatement );
        AddLastToken( (yyval.Rule), (yyvsp[-3].Token) );
        AddLastToken( (yyval.Rule), (yyvsp[-2].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 832 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_ElseStatement );
    }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 845 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_IfStatement );
        AddLastToken( (yyval.Rule), (yyvsp[-5].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-4].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-3].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-1].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 862 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_WhileStatement );
        AddLastToken( (yyval.Rule), (yyvsp[-4].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-3].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-2].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 883 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_ForStatement );
        AddLastToken( (yyval.Rule), (yyvsp[-8].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-7].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-6].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-5].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-4].Token) );
		AddLastSubRule( (yyval.Rule), (yyvsp[-3].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-2].Token) );       
		AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 902 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_WriteStatement );
        AddLastToken( (yyval.Rule), (yyvsp[-2].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 915 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_ReadStatement );
        AddLastToken( (yyval.Rule), (yyvsp[-2].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 928 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_ReturnStatement );
        AddLastToken( (yyval.Rule), (yyvsp[-2].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 940 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_ExpressionStatement );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 950 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 956 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 962 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 968 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 974 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 980 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 986 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 992 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1002 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_StatementList );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddSkippedSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1008 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_StatementList );
    }
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1019 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionBlock );
        AddLastToken( (yyval.Rule), (yyvsp[-3].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-2].Rule) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1028 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionBlock );
        AddLastToken( (yyval.Rule), (yyvsp[0].Token) );
    }
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1044 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_FunctionDeclaration );
        AddLastToken( (yyval.Rule), (yyvsp[-7].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-6].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-5].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-4].Rule) );
        AddLastToken( (yyval.Rule), (yyvsp[-3].Token) );
        AddLastToken( (yyval.Rule), (yyvsp[-2].Token) );
        AddLastSubRule( (yyval.Rule), (yyvsp[-1].Rule) );
        AddSkippedSubRule( (yyval.Rule), (yyvsp[0].Rule) );
    }
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1060 "parser.y" /* yacc.c:1646  */
    {
        (yyval.Rule) = MakeRule( RULE_TYPE_Program );
        AddLastSubRule( (yyval.Rule), (yyvsp[0].Rule) );
        Program->Rule = (yyval.Rule);
    }
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2410 "y.tab.c" /* yacc.c:1646  */
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
#line 1067 "parser.y" /* yacc.c:1906  */

