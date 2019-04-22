
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int INT_TYPE = 1;
int FLOAT_TYPE = 2;


char* prevWord = "";

void RemoveChars(char *s, char c)
{
    int writer = 0, reader = 0;

    while (s[reader])
    {
        if (s[reader]!=c) 
        {   
            s[writer++] = s[reader];
        }

        reader++;       
    }

    s[writer]=0;
}




/* Line 189 of yacc.c  */
#line 109 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 36 "parser.y"

   struct number
	{

	  int ival;
	  float fval;
	  int type;
	} n;



/* Line 209 of yacc.c  */
#line 145 "parser.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     newline = 258,
     FLOAT = 259,
     INTEGER = 260,
     PLUS = 261,
     MINUS = 262,
     MULT = 263,
     DIVIDE = 264,
     MODULO = 265,
     EQUALS = 266,
     invalid_num = 267,
     EXP = 268,
     IDENT_PUNC = 269,
     INT_PUNC = 270,
     FLOAT_PUNC = 271,
     COLON = 272,
     COMMA = 273,
     SCOLON = 274,
     PERIOD = 275,
     QUOTE = 276,
     DQUOTE = 277,
     LPAREN = 278,
     RPAREN = 279,
     IDENT = 280,
     TAGIDENT = 281,
     ENDTAGHEAD = 282,
     LTHAN = 283,
     GTHAN = 284,
     LBRACE = 285,
     RBRACE = 286,
     INVALID_COMMENT = 287,
     INVALID_TOKEN = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 48 "parser.y"

   struct number num;
   char* str;



/* Line 214 of yacc.c  */
#line 202 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 214 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   591

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNRULES -- Number of states.  */
#define YYNSTATES  230

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    38,     2,     2,
       2,     2,    36,    34,     2,    35,     2,    37,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    15,    18,    22,    25,
      29,    32,    36,    40,    45,    48,    52,    56,    61,    64,
      68,    72,    75,    78,    82,    84,    87,    91,    93,    96,
      98,   101,   104,   106,   108,   116,   124,   133,   142,   144,
     148,   152,   162,   173,   183,   194,   204,   215,   225,   236,
     238,   241,   245,   248,   255,   263,   270,   278,   285,   287,
     289,   291,   293,   296,   298,   300,   302,   304,   307,   309,
     311,   313,   315,   317,   319,   321,   323,   325,   327,   329,
     331,   333,   335,   337,   339,   341,   343,   345,   347,   349,
     351,   354,   357,   360,   363,   366,   369,   372,   375,   378,
     381,   384,   386,   388,   390,   392,   394,   396,   398,   400,
     402,   404,   406,   408,   410,   412,   414,   416,   418,   420,
     422,   424,   428,   432,   436,   438,   440,   442,   444,   446,
     448,   450,   453,   457,   461,   465,   469,   473,   477,   481,
     483,   485,   487,   490,   493
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,     3,    -1,    40,     3,    -1,    67,     3,
      -1,    40,    67,     3,    -1,    64,     3,    -1,    40,    64,
       3,    -1,    52,     3,    -1,    40,    52,     3,    -1,    44,
       3,    -1,    40,    44,     3,    -1,    40,    52,    44,    -1,
      40,    52,    44,     3,    -1,    26,     3,    -1,    40,    26,
       3,    -1,    40,    52,    26,    -1,    40,    52,    26,     3,
      -1,    33,     3,    -1,    40,    33,     3,    -1,    40,    52,
      33,    -1,    32,     3,    -1,    40,    32,    -1,    40,    32,
       3,    -1,    45,    -1,    40,    45,    -1,    40,    45,     3,
      -1,     3,    -1,    41,     3,    -1,    26,    -1,    26,    50,
      -1,    26,    41,    -1,    29,    -1,    27,    -1,    42,    43,
      41,    52,    44,    25,    43,    -1,    42,    43,    41,    45,
      44,    25,    43,    -1,    42,    43,    41,    52,    41,    44,
      25,    43,    -1,    42,    43,    41,    45,    41,    44,    25,
      43,    -1,    46,    -1,    45,     3,    46,    -1,    45,    41,
      46,    -1,    45,     3,    42,    43,    41,    52,    44,    25,
      43,    -1,    45,     3,    42,    43,    41,    52,    41,    44,
      25,    43,    -1,    45,     3,    42,    43,    41,    45,    44,
      25,    43,    -1,    45,     3,    42,    43,    41,    45,    41,
      44,    25,    43,    -1,    45,    41,    42,    43,    41,    52,
      44,    25,    43,    -1,    45,    41,    42,    43,    41,    52,
      41,    44,    25,    43,    -1,    45,    41,    42,    43,    41,
      45,    44,    25,    43,    -1,    45,    41,    42,    43,    41,
      45,    41,    44,    25,    43,    -1,    48,    -1,    46,    48,
      -1,    46,    47,    48,    -1,    47,    48,    -1,    42,    43,
      46,    44,    25,    43,    -1,    46,    42,    43,    46,    44,
      25,    43,    -1,    42,    43,    49,    44,    25,    43,    -1,
      47,    42,    43,    49,    44,    25,    43,    -1,    42,    43,
      49,    44,    25,    43,    -1,    52,    -1,    67,    -1,    64,
      -1,    51,    -1,    50,    51,    -1,    25,    -1,    69,    -1,
      11,    -1,    53,    -1,    54,    53,    -1,    56,    -1,    57,
      -1,    55,    -1,    34,    -1,    35,    -1,    36,    -1,    37,
      -1,    38,    -1,    13,    -1,    11,    -1,    69,    -1,    56,
      -1,    57,    -1,    55,    -1,    34,    -1,    35,    -1,    36,
      -1,    37,    -1,    38,    -1,    13,    -1,    11,    -1,    69,
      -1,    54,    56,    -1,    54,    57,    -1,    54,    55,    -1,
      54,    34,    -1,    54,    35,    -1,    54,    36,    -1,    54,
      37,    -1,    54,    38,    -1,    54,    13,    -1,    54,    11,
      -1,    54,    69,    -1,    17,    -1,    18,    -1,    19,    -1,
      20,    -1,    21,    -1,    22,    -1,    60,    -1,    61,    -1,
      29,    -1,    28,    -1,    25,    -1,    14,    -1,    15,    -1,
      16,    -1,    30,    -1,    31,    -1,    23,    -1,    24,    -1,
      23,    -1,    24,    -1,    58,    65,    59,    -1,    65,    66,
      65,    -1,    62,    65,    63,    -1,    69,    -1,    34,    -1,
      35,    -1,    36,    -1,    37,    -1,    38,    -1,    13,    -1,
      11,    68,    -1,    68,    34,    68,    -1,    68,    35,    68,
      -1,    68,    36,    68,    -1,    68,    37,    68,    -1,    68,
      38,    68,    -1,    68,    13,    68,    -1,    60,    68,    61,
      -1,    69,    -1,     5,    -1,     4,    -1,    35,     5,    -1,
      35,     4,    -1,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   101,   102,   103,   105,   106,   108,   109,
     112,   113,   114,   115,   117,   118,   119,   120,   122,   123,
     124,   126,   127,   128,   131,   132,   133,   138,   139,   142,
     143,   144,   147,   150,   153,   154,   155,   156,   159,   160,
     162,   165,   166,   167,   168,   170,   171,   172,   173,   178,
     180,   181,   184,   185,   186,   189,   190,   193,   196,   197,
     198,   201,   202,   205,   206,   207,   211,   212,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   226,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   246,   247,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     266,   278,   279,   282,   283,   284,   285,   286,   287,   288,
     289,   293,   296,   302,   308,   318,   323,   328,   331,   334,
     337,   341,   344,   374,   375,   391,   392,   393,   394,   395,
     396,   400,   412,   437,   462,   487,   512,   537,   562,   563,
     566,   567,   568,   569,   570
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "newline", "FLOAT", "INTEGER", "PLUS",
  "MINUS", "MULT", "DIVIDE", "MODULO", "EQUALS", "invalid_num", "EXP",
  "IDENT_PUNC", "INT_PUNC", "FLOAT_PUNC", "COLON", "COMMA", "SCOLON",
  "PERIOD", "QUOTE", "DQUOTE", "LPAREN", "RPAREN", "IDENT", "TAGIDENT",
  "ENDTAGHEAD", "LTHAN", "GTHAN", "LBRACE", "RBRACE", "INVALID_COMMENT",
  "INVALID_TOKEN", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept", "command",
  "mulline", "open_tag", "close_tag", "end_tag", "html_list",
  "html_statement", "html_statement_other", "html_statement_end",
  "html_contents", "inner_words", "inner_word", "tokens", "token_end",
  "token_other", "annotator", "word", "word_annon", "openB", "closeB",
  "openP", "closeP", "t_openP", "t_closeP", "text_exp", "t_exp", "t_OP",
  "math_exp", "exp", "digit", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    43,    45,    42,    47,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    41,    41,    42,
      42,    42,    43,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      46,    46,    46,    46,    46,    47,    47,    48,    49,    49,
      49,    50,    50,    51,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    57,    57,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     3,     2,     3,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     2,     3,
       3,     2,     2,     3,     1,     2,     3,     1,     2,     1,
       2,     2,     1,     1,     7,     7,     8,     8,     1,     3,
       3,     9,    10,     9,    10,     9,    10,     9,    10,     1,
       2,     3,     2,     6,     7,     6,     7,     6,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     2,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,   141,   140,    88,   144,    87,   112,   113,   114,
     101,   102,   103,   104,   105,   106,   117,   118,   111,    29,
      33,   110,   109,   115,     0,     0,    82,    83,    84,    85,
      86,     0,     0,     0,    24,    38,     0,    49,     0,    66,
       0,    81,    79,    80,     0,   107,   108,     0,     0,    89,
       0,     0,   131,   139,    14,    65,    63,    31,    30,    61,
      64,    21,    18,   143,   142,     1,     3,    29,    22,     0,
       0,    25,     0,     0,     0,    32,     0,    10,    27,     0,
      29,     0,     0,    50,     0,    52,     8,    99,    98,    93,
      94,    95,    96,    97,    67,    92,    90,    91,   100,   119,
       0,     0,   124,     6,     4,     0,     0,     0,     0,     0,
       0,     0,    28,    62,    15,    23,    19,    11,    26,     9,
      16,    20,    12,     7,     5,    27,     0,     0,     0,     0,
      58,    60,    59,     0,    39,     0,    40,     0,    51,     0,
       0,   130,   116,   125,   126,   127,   128,   129,   121,     0,
     138,   137,   132,   133,   134,   135,   136,    17,    13,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     123,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    57,     0,     0,
       0,     0,     0,     0,     0,    35,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    57,    37,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,    41,     0,    47,     0,    45,    44,    42,    48,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    57,    32,    76,    33,    34,    35,    36,    37,
     129,    58,    59,   130,    39,    40,    41,    42,    43,    44,
     148,    45,    46,   100,   170,   131,   101,   149,   132,    52,
      49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -97
static const yytype_int16 yypact[] =
{
     345,   -97,   -97,   -97,     3,   -97,    80,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    29,
     -97,   -97,   -97,   -97,     6,    11,   241,   159,   244,   260,
     272,   309,   -18,    22,    25,    35,    35,   -97,    62,   -97,
     493,   275,   277,   516,    74,   -97,   -97,    71,    73,   520,
      14,   261,   547,   -97,   -97,   -97,   -97,    77,    12,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   215,    90,    91,
     107,   108,   529,   120,   122,   -97,   381,   -97,    35,   102,
     234,   -18,    35,   -97,   -18,   -97,   -97,   531,    80,   241,
     159,   244,   260,   272,   -97,   275,   277,   516,   520,   -97,
      74,   177,   -97,   -97,   -97,   535,   261,   261,   261,   261,
     261,   261,   -97,   -97,   -97,   -97,   -97,   -97,    35,   -97,
     124,   -97,   132,   -97,   -97,   -97,   409,   -18,    -5,    50,
     -97,   -97,   -97,   -18,    35,   -18,    35,   437,   -97,   465,
     541,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    74,
     -97,   547,   109,   109,    -3,    -3,    99,   -97,   -97,    17,
      54,    57,   437,    95,   111,   381,   381,    -5,    50,   -97,
     -97,   553,    36,   115,    64,   116,   -18,   -18,   409,   409,
     125,   126,   130,   -18,   141,   -18,   -97,   123,    54,    57,
      54,    57,   -18,   -18,   -18,   -97,   -18,   -97,    36,   146,
      64,   155,    36,   163,    64,   169,   -97,   158,   -97,   -97,
     172,   -18,   184,   -18,   185,   -18,   196,   -18,   -18,   -97,
     -18,   -97,   -18,   -97,   -18,   -97,   -97,   -97,   -97,   -97
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,    16,   -33,    40,   -30,   -26,   117,    55,    20,
      85,   -97,   170,     0,   189,   -97,   190,   191,   201,   -97,
     -97,    92,   137,   -97,   -97,    51,   -96,   -97,    58,   -38,
       8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -79
static const yytype_int16 yytable[] =
{
      38,    70,    81,    84,   140,    71,   -77,     2,     3,    61,
     106,    75,    53,   105,    62,     5,     2,     3,    63,    64,
     -77,    80,    20,    55,     5,    77,    16,    60,    78,   -77,
     -77,    72,    54,     2,     3,   111,   -77,    56,    50,   112,
      55,     5,   122,   127,   -77,   133,   135,    50,    98,    84,
      79,    47,   102,   171,    56,    83,    85,    78,    48,    53,
     125,    80,    80,    20,    50,    86,    60,   112,   151,   152,
     153,   154,   155,   156,   103,    60,   104,    20,     2,     3,
     112,    20,    73,   -76,    20,   133,     5,    79,    60,    74,
      82,    20,   126,   115,   116,    81,    51,    99,   163,   164,
     160,    81,   138,    81,   127,   112,   -76,   -76,   102,    50,
     117,   118,   106,   -76,    53,    53,    53,    53,    53,    53,
     176,   137,   106,   123,   139,   124,   161,   157,    80,   127,
     173,   175,   127,   127,    81,   158,   177,   180,   181,   135,
     183,   185,   182,    51,   184,   109,   110,   111,    83,   -55,
     192,   193,   188,   190,    83,   194,    83,   102,   199,   201,
     203,   205,   -72,    63,    64,   135,   196,   162,   210,   135,
     212,   211,   214,   165,   216,   166,   172,   174,   189,   191,
     213,   178,   179,    82,   -56,   -72,   -72,    83,   215,    82,
     141,    82,   -72,   128,   217,   134,   136,   218,    51,    51,
      51,    51,    51,    51,   198,   200,   202,   204,   142,   220,
     222,   143,   144,   145,   146,   147,   186,   187,   114,     2,
       3,   224,    82,   195,   168,   197,    55,     5,   113,    94,
      95,    96,   206,   207,   208,   134,   209,   125,     2,     3,
      56,    97,   150,     0,   -71,    55,     5,   -73,     0,     0,
      50,   219,     0,   221,   167,   223,     0,   225,   226,    56,
     227,     0,   228,   -74,   229,     2,     3,   -71,   -71,    50,
     -73,   -73,     0,     5,   -71,   -75,     0,   -73,   -70,   128,
     -68,     0,   128,   128,    16,     0,   -74,   -74,     0,   136,
       0,     0,     0,   -74,     0,     0,    50,     0,   -75,   -75,
       0,   -70,   -70,   -68,   -68,   -75,     0,     0,   -70,    65,
     -68,     0,    66,     2,     3,   136,     0,     0,     0,   136,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    67,    20,    21,    22,    23,
       0,    68,    69,    26,    27,    28,    29,    30,     1,     2,
       3,     0,     0,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,    24,    25,    26,
      27,    28,    29,    30,   125,     2,     3,     0,     0,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    80,     0,    21,
      22,    23,   112,     2,     3,    26,    27,    28,    29,    30,
     159,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    80,     0,    21,    22,     0,
       0,     2,     3,    26,    27,    28,    29,    30,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    80,     0,    21,    22,    23,     0,     2,
       3,    26,    27,    28,    29,    30,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,    21,    22,    23,     0,     2,     3,    26,
      27,    28,    29,    30,    87,     5,    88,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,   -69,
       0,    21,    22,   -78,     0,     0,     0,    89,    90,    91,
      92,    93,   119,     0,   -77,     0,     0,     0,     0,     0,
       0,     0,   -69,   -69,     0,     0,   -78,   -78,   106,   -69,
       0,     0,     0,   -78,   141,   120,    20,   -77,   -77,    17,
     106,     0,   121,     0,   -77,   169,   141,     0,     0,   107,
     108,   109,   110,   111,     0,   143,   144,   145,   146,   147,
       0,   107,   108,   109,   110,   111,     0,   143,   144,   145,
     146,   147
};

static const yytype_int16 yycheck[] =
{
       0,    31,    35,    36,   100,    31,     3,     4,     5,     3,
      13,    29,     4,    51,     3,    12,     4,     5,     4,     5,
       3,    26,    27,    11,    12,     3,    23,    19,     3,    26,
      27,    31,     3,     4,     5,    38,    33,    25,    35,     3,
      11,    12,    72,    76,    27,    78,    79,    35,    40,    82,
      34,     0,    44,   149,    25,    35,    36,     3,     0,    51,
       3,    26,    26,    27,    35,     3,    58,     3,   106,   107,
     108,   109,   110,   111,     3,    67,     3,    27,     4,     5,
       3,    27,    31,     3,    27,   118,    12,    71,    80,    31,
      35,    27,    76,     3,     3,   128,     4,    23,   128,   129,
     126,   134,    82,   136,   137,     3,    26,    27,   100,    35,
       3,     3,    13,    33,   106,   107,   108,   109,   110,   111,
      25,    81,    13,     3,    84,     3,   126,     3,    26,   162,
     160,   161,   165,   166,   167,     3,    25,   167,   168,   172,
      25,    25,   172,    51,   174,    36,    37,    38,   128,    26,
      25,    25,   178,   179,   134,    25,   136,   149,   188,   189,
     190,   191,     3,     4,     5,   198,    25,   127,   198,   202,
     200,    25,   202,   133,   204,   135,   160,   161,   178,   179,
      25,   165,   166,   128,    26,    26,    27,   167,    25,   134,
      13,   136,    33,    76,    25,    78,    79,    25,   106,   107,
     108,   109,   110,   111,   188,   189,   190,   191,    31,    25,
      25,    34,    35,    36,    37,    38,   176,   177,     3,     4,
       5,    25,   167,   183,   139,   185,    11,    12,    58,    40,
      40,    40,   192,   193,   194,   118,   196,     3,     4,     5,
      25,    40,   105,    -1,     3,    11,    12,     3,    -1,    -1,
      35,   211,    -1,   213,   137,   215,    -1,   217,   218,    25,
     220,    -1,   222,     3,   224,     4,     5,    26,    27,    35,
      26,    27,    -1,    12,    33,     3,    -1,    33,     3,   162,
       3,    -1,   165,   166,    23,    -1,    26,    27,    -1,   172,
      -1,    -1,    -1,    33,    -1,    -1,    35,    -1,    26,    27,
      -1,    26,    27,    26,    27,    33,    -1,    -1,    33,     0,
      33,    -1,     3,     4,     5,   198,    -1,    -1,    -1,   202,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,     3,     4,     5,    34,    35,    36,    37,    38,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    -1,
      -1,     4,     5,    34,    35,    36,    37,    38,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    -1,     4,
       5,    34,    35,    36,    37,    38,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    -1,     4,     5,    34,
      35,    36,    37,    38,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     3,
      -1,    28,    29,     3,    -1,    -1,    -1,    34,    35,    36,
      37,    38,     3,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    26,    27,    13,    33,
      -1,    -1,    -1,    33,    13,    26,    27,    26,    27,    24,
      13,    -1,    33,    -1,    33,    24,    13,    -1,    -1,    34,
      35,    36,    37,    38,    -1,    34,    35,    36,    37,    38,
      -1,    34,    35,    36,    37,    38,    -1,    34,    35,    36,
      37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    32,    33,    34,    35,    36,    37,
      38,    40,    42,    44,    45,    46,    47,    48,    52,    53,
      54,    55,    56,    57,    58,    60,    61,    64,    67,    69,
      35,    60,    68,    69,     3,    11,    25,    41,    50,    51,
      69,     3,     3,     4,     5,     0,     3,    26,    32,    33,
      44,    45,    52,    64,    67,    29,    43,     3,     3,    41,
      26,    42,    47,    48,    42,    48,     3,    11,    13,    34,
      35,    36,    37,    38,    53,    55,    56,    57,    69,    23,
      62,    65,    69,     3,     3,    68,    13,    34,    35,    36,
      37,    38,     3,    51,     3,     3,     3,     3,     3,     3,
      26,    33,    44,     3,     3,     3,    41,    42,    46,    49,
      52,    64,    67,    42,    46,    42,    46,    43,    48,    43,
      65,    13,    31,    34,    35,    36,    37,    38,    59,    66,
      61,    68,    68,    68,    68,    68,    68,     3,     3,    11,
      45,    52,    43,    44,    44,    43,    43,    46,    49,    24,
      63,    65,    41,    44,    41,    44,    25,    25,    41,    41,
      44,    44,    44,    25,    44,    25,    43,    43,    45,    52,
      45,    52,    25,    25,    25,    43,    25,    43,    41,    44,
      41,    44,    41,    44,    41,    44,    43,    43,    43,    43,
      44,    25,    44,    25,    44,    25,    44,    25,    25,    43,
      25,    43,    25,    43,    25,    43,    43,    43,    43,    43
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    {;;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {printf(",\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {printf(",\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {printf("</\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {printf("</\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {printf("</");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {printf("</\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {printf("%s\n", (yyvsp[(1) - (2)].str));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {printf("%s\n", (yyvsp[(2) - (3)].str));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {printf("%s", (yyvsp[(3) - (3)].str));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {printf("%s\n", (yyvsp[(3) - (4)].str));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {printf("(invalid:%s)", (yyvsp[(1) - (2)].str));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {printf("(invalid:%s)", (yyvsp[(2) - (3)].str));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {printf("(invalid:%s)", (yyvsp[(3) - (3)].str));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {printf("Un-expected end of file\n"); return 1;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    {printf("Un-expected end of file"); return 1;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {printf("Un-expected end of file\n"); return 1;;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    {;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {;;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {;;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {;;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {;;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {printf("\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {printf("\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {printf("\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {printf("");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {printf("");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {printf("");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {printf("");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {printf("");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {printf("");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {printf("");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {printf("");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {printf("");;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {printf("");;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    {printf("");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {printf(",");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {printf(",");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {printf(",");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    {printf("");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {printf(" ");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {printf(" ");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {printf("");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {printf("");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {;;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {;;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {printf("+");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {printf("-");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {printf("*");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {printf("/");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {printf("%c", '%');;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {printf("**");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {printf("=");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    { 
			if((yyvsp[(1) - (1)].num).type == 1){
				printf("%d ", (yyvsp[(1) - (1)].num).ival);
			}
			else if((yyvsp[(1) - (1)].num).type == 2){
				printf("%.2f ", (yyvsp[(1) - (1)].num).fval);
			}
		;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {printf(" ");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    {printf(" ");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {printf(" ");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    {printf("+ ");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    {printf("- ");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    {printf("*");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    {printf("/");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    {printf("%c", '%');;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {printf("**");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    {printf("=");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    { 
			if((yyvsp[(1) - (1)].num).type == 1){
				printf("%d ", (yyvsp[(1) - (1)].num).ival);
			}
			else if((yyvsp[(1) - (1)].num).type == 2){
				printf("%.2f ", (yyvsp[(1) - (1)].num).fval);
			}
		;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    {printf(" ");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    {printf(" ");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {printf(" ");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {printf("+ ");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    {printf("- ");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 260 "parser.y"
    {printf("* ");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    {printf("/ ");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    {printf("%c ", '%');;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    {printf("** ");;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    {printf("= ");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    { 
			if((yyvsp[(2) - (2)].num).type == 1){
				printf("%d ", (yyvsp[(2) - (2)].num).ival);
			}
			else if((yyvsp[(2) - (2)].num).type == 2){
				printf("%.2f ", (yyvsp[(2) - (2)].num).fval);
			}
		;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    { printf(":");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    { 
			 printf(",");
		;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 282 "parser.y"
    { printf(";");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    {printf(".");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    { printf("'");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 285 "parser.y"
    {printf("\"");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 286 "parser.y"
    {printf("(");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    {printf(")");;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {printf(">");;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 289 "parser.y"
    {printf("<");;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str); printf("%s", (yyvsp[(1) - (1)].str));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    {
							(yyval.str) = (yyvsp[(1) - (1)].str); 
							char* currText = (yyval.str);
							RemoveChars(currText, ' ');
							printf("%s", currText);
						;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    {
					(yyval.str) = (yyvsp[(1) - (1)].str);
					char* currText = (yyval.str);
					RemoveChars(currText, ' ');
					printf("%s", currText);					
			   ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 308 "parser.y"
    {
					(yyval.str) = (yyvsp[(1) - (1)].str);
					char* currText = (yyval.str);
					RemoveChars(currText, ' ');
					printf("%s", currText);					
			   ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    {
					;
			  ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    {
				printf("");
			   ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 328 "parser.y"
    {;;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 331 "parser.y"
    {;;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 334 "parser.y"
    {printf("(");;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    {printf(")");;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 341 "parser.y"
    {;;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 344 "parser.y"
    {
							if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 1){
								//sprintf(curr, "%d", $3.ival);
								//globalC = strcat(globalC, curr);
								//printf("%d", $3.ival);
								;
							}
							
							if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 2){
								//sprintf(curr, "%.2f", $3.fval);
								//globalC = strcat(globalC, curr);
								//printf("%.2f", $3.fval);
								;
							}
							
							if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 1){
								//sprintf(curr, "%d", $3.ival);
								//globalC = strcat(globalC, curr);
								//printf("%d", $3.ival);
								;
							}
							
							if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 2){
								//sprintf(curr, "%.2f", $3.fval);
								//globalC = strcat(globalC, curr);								
								//printf("%.2f", $3.fval);
								;
							}
						;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 374 "parser.y"
    {;;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 375 "parser.y"
    {
				(yyval.num) = (yyvsp[(1) - (1)].num);
				if((yyvsp[(1) - (1)].num).type == 1){
					//sprintf(curr, "%d", $1.ival);
					//globalC = strcat(globalC, curr);
					printf("%d", (yyvsp[(1) - (1)].num).ival);
				}
				else if((yyvsp[(1) - (1)].num).type == 2){
					//sprintf(curr, "%.2f", $1.fval);
					//globalC = strcat(globalC, curr);	
					printf("%.2f", (yyvsp[(1) - (1)].num).fval);
				}
				
	;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 391 "parser.y"
    {printf("+");;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 392 "parser.y"
    {printf("-");;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 393 "parser.y"
    {printf("*");;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 394 "parser.y"
    {printf("/");;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 395 "parser.y"
    {printf("%c", '%');;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 396 "parser.y"
    {printf("**");;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 400 "parser.y"
    { //printf("Expression type = %d\n",$2.type);
							if((yyvsp[(2) - (2)].num).type == 1){
								printf("%d", (yyvsp[(2) - (2)].num).ival);
							}
							else if((yyvsp[(2) - (2)].num).type == 2){
								printf("%.2f", (yyvsp[(2) - (2)].num).fval);
							} 
							
						;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 412 "parser.y"
    {	
								if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("both are integers\n");
									(yyval.num).type = 1;
									(yyval.num).ival = ((yyvsp[(1) - (3)].num).ival + (yyvsp[(3) - (3)].num).ival);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("first is int second is float\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).ival + (yyvsp[(3) - (3)].num).fval);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("first is float second is int\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).fval + (yyvsp[(3) - (3)].num).ival);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("both are floats\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).fval + (yyvsp[(3) - (3)].num).fval);
								}
							;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 437 "parser.y"
    {	
								if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("both are integers\n");
									(yyval.num).type = 1;
									(yyval.num).ival = ((yyvsp[(1) - (3)].num).ival - (yyvsp[(3) - (3)].num).ival);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("first is int second is float\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).ival - (yyvsp[(3) - (3)].num).fval);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("first is float second is int\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).fval - (yyvsp[(3) - (3)].num).ival);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("both are floats\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).fval - (yyvsp[(3) - (3)].num).fval);
								}
							;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 462 "parser.y"
    {	
								if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("both are integers\n");
									(yyval.num).type = 1;
									(yyval.num).ival = ((yyvsp[(1) - (3)].num).ival * (yyvsp[(3) - (3)].num).ival);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("first is int second is float\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).ival * (yyvsp[(3) - (3)].num).fval);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("first is float second is int\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).fval * (yyvsp[(3) - (3)].num).ival);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("both are floats\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).fval * (yyvsp[(3) - (3)].num).fval);
								}
							;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 487 "parser.y"
    {	
								if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("both are integers\n");
									(yyval.num).type = 1;
									(yyval.num).ival = ((yyvsp[(1) - (3)].num).ival / (yyvsp[(3) - (3)].num).ival);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("first is int second is float\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).ival / (yyvsp[(3) - (3)].num).fval);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("first is float second is int\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).fval / (yyvsp[(3) - (3)].num).ival);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("both are floats\n");
									(yyval.num).type = 2;
									(yyval.num).fval = ((yyvsp[(1) - (3)].num).fval / (yyvsp[(3) - (3)].num).fval);
								}
							;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 512 "parser.y"
    {	
								if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("both are integers\n");
									(yyval.num).type = 1;
									(yyval.num).ival = ((yyvsp[(1) - (3)].num).ival % (yyvsp[(3) - (3)].num).ival);
								}
							
								/*if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = fmodf((float)$1.ival, $3.fval);
								}*/						
								
								/*if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = fmodf($1.fval, (float)$3.ival);
								} */		
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("both are floats\n");
									(yyval.num).type = 2;
									(yyval.num).fval = fmodf((yyvsp[(1) - (3)].num).fval, (yyvsp[(3) - (3)].num).fval);
								}
							;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 537 "parser.y"
    {	
								if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("both are integers\n");
									(yyval.num).type = 1;
									(yyval.num).ival = pow((yyvsp[(1) - (3)].num).ival, (yyvsp[(3) - (3)].num).ival);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 1 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("first is int second is float\n");
									(yyval.num).type = 2;
									(yyval.num).fval = pow((yyvsp[(1) - (3)].num).ival, (yyvsp[(3) - (3)].num).fval);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 1){
									//printf("first is float second is int\n");
									(yyval.num).type = 2;
									(yyval.num).fval = pow((yyvsp[(1) - (3)].num).fval, (yyvsp[(3) - (3)].num).ival);
								}
								
								else if((yyvsp[(1) - (3)].num).type == 2 && (yyvsp[(3) - (3)].num).type == 2){
									//printf("both are floats\n");
									(yyval.num).type = 2;
									(yyval.num).fval = pow((yyvsp[(1) - (3)].num).fval, (yyvsp[(3) - (3)].num).fval);
								}
							;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 562 "parser.y"
    {(yyval.num) = (yyvsp[(2) - (3)].num);;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 563 "parser.y"
    {(yyval.num) = (yyvsp[(1) - (1)].num);;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 566 "parser.y"
    {(yyval.num) = (yyvsp[(1) - (1)].num); (yyval.num).type = (yyvsp[(1) - (1)].num).type; ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 567 "parser.y"
    {(yyval.num) = (yyvsp[(1) - (1)].num); (yyval.num).type = (yyvsp[(1) - (1)].num).type;;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 568 "parser.y"
    {(yyval.num).ival = -(yyvsp[(2) - (2)].num).ival; (yyval.num).type = (yyvsp[(2) - (2)].num).type;;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 569 "parser.y"
    {(yyval.num).fval = -(yyvsp[(2) - (2)].num).fval; (yyval.num).type = (yyvsp[(2) - (2)].num).type;;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 570 "parser.y"
    {printf("Badly formed number"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2938 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 577 "parser.y"


int main()
{ 

  return yyparse();
}


int yyerror(char *s)
{
   fprintf(stderr,"%s\n",s);
   return 0;
}

