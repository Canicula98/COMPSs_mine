/*
 *  Copyright 2002-2025 Barcelona Supercomputing Center (www.bsc.es)
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

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
#line 1 "corba-gram.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "param_metadata.h"
#include "semantic.h"

#if 0
#define YYERROR_VERBOSE
#endif
#define YYERROR_VERBOSE

int yylex(void);
void yyerror(char *s);

#line 82 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TOK_INTERFACE = 258,
    TOK_LEFT_CUR_BRAKET = 259,
    TOK_RIGHT_CUR_BRAKET = 260,
    TOK_LEFT_PARENTHESIS = 261,
    TOK_LEFT_BRAKET = 262,
    TOK_RIGHT_BRAKET = 263,
    TOK_RIGHT_PARENTHESIS = 264,
    TOK_COMMA = 265,
    TOK_SEMICOLON = 266,
    TOK_IN = 267,
    TOK_OUT = 268,
    TOK_INOUT = 269,
    TOK_FILE = 270,
    TOK_STATIC = 271,
    TOK_UNSIGNED = 272,
    TOK_VOID = 273,
    TOK_SHORT = 274,
    TOK_LONG = 275,
    TOK_LONGLONG = 276,
    TOK_INT = 277,
    TOK_FLOAT = 278,
    TOK_DOUBLE = 279,
    TOK_CHAR = 280,
    TOK_WCHAR = 281,
    TOK_BOOLEAN = 282,
    TOK_STRING = 283,
    TOK_WSTRING = 284,
    TOK_ANY = 285,
    TOK_ERROR = 286,
    TOK_EQUAL = 287,
    TOK_DBLQUOTE = 288,
    TOK_ENUM = 289,
    TOK_INCLUDE = 290,
    TOK_IDENTIFIER = 291,
    TOK_HEADER = 292,
    NUMBER = 293
  };
#endif
/* Tokens.  */
#define TOK_INTERFACE 258
#define TOK_LEFT_CUR_BRAKET 259
#define TOK_RIGHT_CUR_BRAKET 260
#define TOK_LEFT_PARENTHESIS 261
#define TOK_LEFT_BRAKET 262
#define TOK_RIGHT_BRAKET 263
#define TOK_RIGHT_PARENTHESIS 264
#define TOK_COMMA 265
#define TOK_SEMICOLON 266
#define TOK_IN 267
#define TOK_OUT 268
#define TOK_INOUT 269
#define TOK_FILE 270
#define TOK_STATIC 271
#define TOK_UNSIGNED 272
#define TOK_VOID 273
#define TOK_SHORT 274
#define TOK_LONG 275
#define TOK_LONGLONG 276
#define TOK_INT 277
#define TOK_FLOAT 278
#define TOK_DOUBLE 279
#define TOK_CHAR 280
#define TOK_WCHAR 281
#define TOK_BOOLEAN 282
#define TOK_STRING 283
#define TOK_WSTRING 284
#define TOK_ANY 285
#define TOK_ERROR 286
#define TOK_EQUAL 287
#define TOK_DBLQUOTE 288
#define TOK_ENUM 289
#define TOK_INCLUDE 290
#define TOK_IDENTIFIER 291
#define TOK_HEADER 292
#define NUMBER 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "corba-gram.y" /* yacc.c:355  */

    char		*elements;
	char		*name;
	char		*classname;
	enum datatype	dtype;
	enum direction	dir;

#line 206 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 223 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

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
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    43,    46,    47,    47,    50,    50,    55,
      56,    59,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    64,    64,    64,    64,
      64,    65,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    67,    71,    72,    76,    77,    78,    79,    82,    83,
      84,    85,    86,    89,    90,    91,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   106,   109,   110,   111,
     112,   113,   114,   117,   118,   119,   120,   121,   122,   123
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_INTERFACE", "TOK_LEFT_CUR_BRAKET",
  "TOK_RIGHT_CUR_BRAKET", "TOK_LEFT_PARENTHESIS", "TOK_LEFT_BRAKET",
  "TOK_RIGHT_BRAKET", "TOK_RIGHT_PARENTHESIS", "TOK_COMMA",
  "TOK_SEMICOLON", "TOK_IN", "TOK_OUT", "TOK_INOUT", "TOK_FILE",
  "TOK_STATIC", "TOK_UNSIGNED", "TOK_VOID", "TOK_SHORT", "TOK_LONG",
  "TOK_LONGLONG", "TOK_INT", "TOK_FLOAT", "TOK_DOUBLE", "TOK_CHAR",
  "TOK_WCHAR", "TOK_BOOLEAN", "TOK_STRING", "TOK_WSTRING", "TOK_ANY",
  "TOK_ERROR", "TOK_EQUAL", "TOK_DBLQUOTE", "TOK_ENUM", "TOK_INCLUDE",
  "TOK_IDENTIFIER", "TOK_HEADER", "NUMBER", "$accept", "start", "includes",
  "$@1", "interface", "$@2", "prototypes", "prototype", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "$@23", "$@24", "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31",
  "$@32", "$@33", "$@34", "arguments0", "arguments1", "argument",
  "direction", "data_type", "enum_type", "numeric_type", "array_type", YY_NULLPTR
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

#define YYPACT_NINF -71

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-71)))

#define YYTABLE_NINF -90

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -71,    15,   -71,     1,    -2,     0,   -71,   -71,   -71,    36,
      31,   -71,   -71,     2,    32,    33,   -71,    57,   -11,   -71,
      38,    41,    42,    46,    61,    82,    83,   -71,   -71,   -71,
     -71,   -71,    56,   -71,    58,   -71,    88,   -71,   -71,    62,
      69,    99,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -22,   -71,   -71,    -3,    91,   101,   100,   102,   103,
     105,   104,   106,   -71,   -71,    77,    79,   -71,   -71,    80,
      81,    87,    87,   -71,   -71,    87,    87,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   108,   -71,    37,   -71,   113,   114,
     -71,   -71,   115,   116,   117,    90,   -71,    89,    92,    93,
     120,   121,   -71,   -71,   122,   123,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,    97,     3,   -71,    87,    87,   -71,   -71,
      87,    87,   112,   -71,   126,   127,   125,   -71,   -71,   128,
     129,   -71,   -71,   -71,   107,   109,   -71,   132,   133,   -71,
     -71,   135,   137,   -71,   -71,   -71,   -71,   -71,   -71,   136,
     138,   139,   140,   -71,   -71,   -71,   -71
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     1,     0,     0,     0,     3,     7,     5,     0,
       0,     9,     6,     0,     0,     0,    75,     0,     0,    74,
      77,    78,    79,    80,    81,    82,    68,    69,    70,    71,
      72,    73,     0,    10,     0,    67,     0,    51,     8,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    66,    26,
      11,     0,    31,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    12,     0,     0,    32,    47,     0,
       0,     0,     0,    16,    21,     0,     0,    36,    41,    57,
      63,    64,    65,    28,    53,    54,     0,    13,     0,     0,
      33,    48,     0,     0,     0,     0,    76,     0,     0,     0,
       0,     0,    17,    22,     0,     0,    37,    42,    29,    56,
      55,    61,    58,     0,     0,    14,     0,     0,    34,    49,
       0,     0,     0,    62,     0,     0,     0,    18,    23,     0,
       0,    38,    43,    30,     0,     0,    15,     0,     0,    35,
      50,     0,     0,    59,    60,    19,    24,    39,    44,     0,
       0,     0,     0,    20,    25,    40,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -70,   -71,    29,   -71,   -17,   -71,   119,   -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     3,    10,     6,     9,    13,    33,    56,    72,
     101,   126,    88,   116,   137,   149,    89,   117,   138,   150,
      55,    71,    94,   122,    59,    75,   104,   129,    92,   120,
     141,   151,    93,   121,   142,   152,    60,    76,   105,   130,
      83,    84,    85,    86,    34,    99,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    41,    87,    14,     4,    90,    91,    15,    42,    43,
      44,    45,    46,    47,    57,     2,    58,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    61,     7,    62,     5,     8,    32,   124,
      11,   125,    12,    37,    38,   -83,   127,   128,   -84,   -85,
     131,   132,    16,   -86,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   -87,    98,
     100,    96,    16,    97,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    79,   -88,
     -89,   109,    49,    39,    50,    51,   -52,    63,    52,    80,
      81,    82,    80,    81,    82,    53,    54,    64,    65,    67,
      66,    68,    69,    73,    70,    74,    77,    78,    95,   102,
     103,   106,   107,   133,   110,   111,   108,   114,   112,   113,
     115,   118,   119,   123,   134,   135,   136,    48,     0,   139,
     140,   145,   146,   143,   147,   144,   148,   153,     0,   154,
     155,   156
};

static const yytype_int8 yycheck[] =
{
      17,    17,    72,     1,     3,    75,    76,     5,    19,    20,
      21,    22,    23,    24,    36,     0,    38,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    36,    36,    38,    35,    37,    36,    36,
       4,    38,    11,    11,    11,     7,   116,   117,     7,     7,
     120,   121,    15,     7,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     7,    86,
      86,    34,    15,    36,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     1,     7,
       7,     1,    36,    36,    36,     7,     9,     6,    36,    12,
      13,    14,    12,    13,    14,    36,     7,     6,     8,     6,
       8,     6,     8,    36,     8,    36,    36,    36,    10,     6,
       6,     6,     6,    11,    95,    36,     9,     7,    36,    36,
       9,     9,     9,    36,     8,     8,    11,    18,    -1,    11,
      11,     9,     9,    36,     9,    36,     9,    11,    -1,    11,
      11,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,     0,    41,     3,    35,    43,    36,    37,    44,
      42,     4,    11,    45,     1,     5,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    36,    46,    83,    85,    86,    11,    11,    36,
      83,    86,    19,    20,    21,    22,    23,    24,    85,    36,
      36,     7,    36,    36,     7,    59,    47,    36,    38,    63,
      75,    36,    38,     6,     6,     8,     8,     6,     6,     8,
       8,    60,    48,    36,    36,    64,    76,    36,    36,     1,
      12,    13,    14,    79,    80,    81,    82,    79,    51,    55,
      79,    79,    67,    71,    61,    10,    34,    36,    83,    84,
      86,    49,     6,     6,    65,    77,     6,     6,     9,     1,
      81,    36,    36,    36,     7,     9,    52,    56,     9,     9,
      68,    72,    62,    36,    36,    38,    50,    79,    79,    66,
      78,    79,    79,    11,     8,     8,    11,    53,    57,    11,
      11,    69,    73,    36,    36,     9,     9,     9,     9,    54,
      58,    70,    74,    11,    11,    11,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    41,    42,    41,    44,    43,    45,
      45,    47,    48,    49,    50,    46,    51,    52,    53,    54,
      46,    55,    56,    57,    58,    46,    59,    60,    61,    62,
      46,    63,    64,    65,    66,    46,    67,    68,    69,    70,
      46,    71,    72,    73,    74,    46,    75,    76,    77,    78,
      46,    46,    79,    79,    80,    80,    80,    80,    81,    81,
      81,    81,    81,    82,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    85,    85,    85,
      85,    85,    85,    86,    86,    86,    86,    86,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     0,     5,     0,     7,     0,
       2,     0,     0,     0,     0,    10,     0,     0,     0,     0,
      13,     0,     0,     0,     0,    13,     0,     0,     0,     0,
      10,     0,     0,     0,     0,    11,     0,     0,     0,     0,
      14,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      11,     2,     0,     1,     1,     3,     3,     1,     3,     6,
       6,     3,     4,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
        case 5:
#line 47 "corba-gram.y" /* yacc.c:1646  */
    { add_header((yyvsp[0].name)); }
#line 1415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 50 "corba-gram.y" /* yacc.c:1646  */
    { begin_interface((yyvsp[0].name)); }
#line 1421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 52 "corba-gram.y" /* yacc.c:1646  */
    { end_interface(); }
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 59 "corba-gram.y" /* yacc.c:1646  */
    {  begin_function((yyvsp[0].name)); add_static(0); add_return_type((yyvsp[-1].dtype), "", NULL); }
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 59 "corba-gram.y" /* yacc.c:1646  */
    { begin_arguments(); }
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 59 "corba-gram.y" /* yacc.c:1646  */
    { end_arguments(); }
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 59 "corba-gram.y" /* yacc.c:1646  */
    { end_function(); }
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 60 "corba-gram.y" /* yacc.c:1646  */
    {  begin_function((yyvsp[0].name)); add_static(0); add_return_type((yyvsp[-4].dtype), "", (yyvsp[-2].name)); }
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 60 "corba-gram.y" /* yacc.c:1646  */
    { begin_arguments(); }
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 60 "corba-gram.y" /* yacc.c:1646  */
    { end_arguments(); }
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 60 "corba-gram.y" /* yacc.c:1646  */
    { end_function(); }
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 61 "corba-gram.y" /* yacc.c:1646  */
    {  begin_function((yyvsp[0].name)); add_static(0); add_return_type((yyvsp[-4].dtype), "", (yyvsp[-2].elements)); }
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 61 "corba-gram.y" /* yacc.c:1646  */
    { begin_arguments(); }
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 61 "corba-gram.y" /* yacc.c:1646  */
    { end_arguments(); }
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 61 "corba-gram.y" /* yacc.c:1646  */
    { end_function(); }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 62 "corba-gram.y" /* yacc.c:1646  */
    { begin_function((yyvsp[0].name)); add_static(0); add_return_type(object_dt, (yyvsp[-1].name), NULL); }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 62 "corba-gram.y" /* yacc.c:1646  */
    { begin_arguments(); }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 62 "corba-gram.y" /* yacc.c:1646  */
    { end_arguments(); }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 62 "corba-gram.y" /* yacc.c:1646  */
    { end_function(); }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 63 "corba-gram.y" /* yacc.c:1646  */
    { begin_function((yyvsp[0].name)); add_static(1); add_return_type(object_dt, (yyvsp[-1].name), NULL); }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 63 "corba-gram.y" /* yacc.c:1646  */
    { begin_arguments(); }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 63 "corba-gram.y" /* yacc.c:1646  */
    { end_arguments(); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 63 "corba-gram.y" /* yacc.c:1646  */
    { end_function(); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 64 "corba-gram.y" /* yacc.c:1646  */
    { begin_function((yyvsp[0].name)); add_static(1); add_return_type((yyvsp[-4].dtype), "", (yyvsp[-2].name)); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 64 "corba-gram.y" /* yacc.c:1646  */
    { begin_arguments(); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 64 "corba-gram.y" /* yacc.c:1646  */
    { end_arguments(); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 64 "corba-gram.y" /* yacc.c:1646  */
    { end_function(); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 65 "corba-gram.y" /* yacc.c:1646  */
    { begin_function((yyvsp[0].name)); add_static(1); add_return_type((yyvsp[-4].dtype), "", (yyvsp[-2].elements)); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 65 "corba-gram.y" /* yacc.c:1646  */
    { begin_arguments(); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 65 "corba-gram.y" /* yacc.c:1646  */
    { end_arguments(); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 65 "corba-gram.y" /* yacc.c:1646  */
    { end_function(); }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 66 "corba-gram.y" /* yacc.c:1646  */
    { begin_function((yyvsp[0].name)); add_static(1); add_return_type((yyvsp[-1].dtype), "", NULL); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 66 "corba-gram.y" /* yacc.c:1646  */
    { begin_arguments(); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 66 "corba-gram.y" /* yacc.c:1646  */
    { end_arguments(); }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 66 "corba-gram.y" /* yacc.c:1646  */
    { end_function(); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 82 "corba-gram.y" /* yacc.c:1646  */
    { add_argument((yyvsp[-2].dir), (yyvsp[-1].dtype), "", (yyvsp[0].name), NULL); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 83 "corba-gram.y" /* yacc.c:1646  */
    { add_argument((yyvsp[-5].dir), (yyvsp[-4].dtype), "", (yyvsp[0].name), (yyvsp[-2].name));}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 84 "corba-gram.y" /* yacc.c:1646  */
    { add_argument((yyvsp[-5].dir), (yyvsp[-4].dtype), "", (yyvsp[0].name), (yyvsp[-2].elements));}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 85 "corba-gram.y" /* yacc.c:1646  */
    { add_argument((yyvsp[-2].dir), object_dt, (yyvsp[-1].name), (yyvsp[0].name), NULL); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 86 "corba-gram.y" /* yacc.c:1646  */
    { add_argument((yyvsp[-3].dir), (yyvsp[-2].dtype), (yyvsp[-1].name), (yyvsp[0].name), NULL); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 89 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dir) = in_dir; }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 90 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dir) = out_dir; }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 91 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dir) = inout_dir; }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 94 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = (yyvsp[0].dtype); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 95 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = (yyvsp[0].dtype); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 96 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = char_dt; }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 97 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = wchar_dt; }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 98 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = boolean_dt; }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 99 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = string_dt; }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 100 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = wstring_dt; }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 101 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = any_dt; }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 102 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = void_dt; }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 103 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = file_dt; }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 106 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = enum_dt; }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 109 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = short_dt; }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 110 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = long_dt; }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 111 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = longlong_dt; }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 112 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = int_dt; }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 113 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = float_dt; }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 114 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = double_dt; }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 117 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = short_dt; }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 118 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = long_dt; }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 119 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = longlong_dt; }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 120 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = int_dt; }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 121 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = float_dt; }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 122 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = double_dt; }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 123 "corba-gram.y" /* yacc.c:1646  */
    { (yyval.dtype) = char_dt; }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1815 "y.tab.c" /* yacc.c:1646  */
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
#line 126 "corba-gram.y" /* yacc.c:1906  */


extern int line;


void yyerror(char *s)
{
	char const *function_name;
	
	fprintf(stderr, "%s:%i: ", get_filename(), line);
	fprintf(stderr, "%s", s);
	function_name = get_current_function_name();
	if (function_name != NULL) {
		fprintf(stderr, " in function '%s'", function_name);
		if (began_arguments) {
			fprintf(stderr, " parameter %i", get_next_argnum());
		}
	}
	fprintf(stderr,"\n");
	set_serious_error();
}
