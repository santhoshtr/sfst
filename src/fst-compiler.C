/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "fst-compiler.yy"

/*******************************************************************/
/*                                                                 */
/*  FILE     fst-compiler.yy                                       */
/*  MODULE   fst-compiler                                          */
/*  PROGRAM  SFST                                                  */
/*  AUTHOR   Helmut Schmid, IMS, University of Stuttgart           */
/*                                                                 */
/*******************************************************************/

#include <stdio.h>

#include "make-compact.h"
#include "scanner.h"
#include "interface.h"

using std::cerr;
using namespace SFST;

extern int  yylineno;
extern char *yytext;

void yyerror( const char *text );
void warn( const char *text );
void warn2( const char *text, const char *text2);
int yylex( void );
int yyparse( void );

static int Switch=0;
Interface interface;
Transducer *Result;

#line 104 "fst-compiler.C"

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

#include "fst-compiler.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NEWLINE = 3,                    /* NEWLINE  */
  YYSYMBOL_ALPHA = 4,                      /* ALPHA  */
  YYSYMBOL_COMPOSE = 5,                    /* COMPOSE  */
  YYSYMBOL_PRINT = 6,                      /* PRINT  */
  YYSYMBOL_POS = 7,                        /* POS  */
  YYSYMBOL_INSERT = 8,                     /* INSERT  */
  YYSYMBOL_SWITCH = 9,                     /* SWITCH  */
  YYSYMBOL_ARROW = 10,                     /* ARROW  */
  YYSYMBOL_REPLACE = 11,                   /* REPLACE  */
  YYSYMBOL_SYMBOL = 12,                    /* SYMBOL  */
  YYSYMBOL_VAR = 13,                       /* VAR  */
  YYSYMBOL_SVAR = 14,                      /* SVAR  */
  YYSYMBOL_RVAR = 15,                      /* RVAR  */
  YYSYMBOL_RSVAR = 16,                     /* RSVAR  */
  YYSYMBOL_STRING = 17,                    /* STRING  */
  YYSYMBOL_STRING2 = 18,                   /* STRING2  */
  YYSYMBOL_UTF8CHAR = 19,                  /* UTF8CHAR  */
  YYSYMBOL_CHARACTER = 20,                 /* CHARACTER  */
  YYSYMBOL_21_ = 21,                       /* '|'  */
  YYSYMBOL_22_ = 22,                       /* '-'  */
  YYSYMBOL_23_ = 23,                       /* '&'  */
  YYSYMBOL_SEQ = 24,                       /* SEQ  */
  YYSYMBOL_25_ = 25,                       /* '!'  */
  YYSYMBOL_26_ = 26,                       /* '^'  */
  YYSYMBOL_27___ = 27,                     /* '_'  */
  YYSYMBOL_28_ = 28,                       /* '*'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '?'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_36_ = 36,                       /* ':'  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_39_ = 39,                       /* '.'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_ALL = 42,                       /* ALL  */
  YYSYMBOL_ASSIGNMENTS = 43,               /* ASSIGNMENTS  */
  YYSYMBOL_ASSIGNMENT = 44,                /* ASSIGNMENT  */
  YYSYMBOL_RE = 45,                        /* RE  */
  YYSYMBOL_RANGES = 46,                    /* RANGES  */
  YYSYMBOL_RANGE = 47,                     /* RANGE  */
  YYSYMBOL_CONTEXTS2 = 48,                 /* CONTEXTS2  */
  YYSYMBOL_CONTEXTS = 49,                  /* CONTEXTS  */
  YYSYMBOL_CONTEXT2 = 50,                  /* CONTEXT2  */
  YYSYMBOL_CONTEXT = 51,                   /* CONTEXT  */
  YYSYMBOL_VALUES = 52,                    /* VALUES  */
  YYSYMBOL_VALUE = 53,                     /* VALUE  */
  YYSYMBOL_LCHAR = 54,                     /* LCHAR  */
  YYSYMBOL_CODE = 55,                      /* CODE  */
  YYSYMBOL_NEWLINES = 56                   /* NEWLINES  */
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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   900

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,    25,     2,     2,     2,     2,    23,     2,
      32,    33,    28,    29,    40,    22,    39,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,    26,    27,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,    21,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    77,    78,    79,    82,    83,    84,    85,
      86,    87,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   127,   128,   131,
     132,   133,   134,   135,   138,   139,   142,   143,   146,   147,
     150,   151,   152,   155,   156,   159,   160,   161,   162,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   186,   187,
     188,   192,   193
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
  "\"end of file\"", "error", "\"invalid token\"", "NEWLINE", "ALPHA",
  "COMPOSE", "PRINT", "POS", "INSERT", "SWITCH", "ARROW", "REPLACE",
  "SYMBOL", "VAR", "SVAR", "RVAR", "RSVAR", "STRING", "STRING2",
  "UTF8CHAR", "CHARACTER", "'|'", "'-'", "'&'", "SEQ", "'!'", "'^'", "'_'",
  "'*'", "'+'", "'='", "'?'", "'('", "')'", "'{'", "'}'", "':'", "'['",
  "']'", "'.'", "','", "$accept", "ALL", "ASSIGNMENTS", "ASSIGNMENT", "RE",
  "RANGES", "RANGE", "CONTEXTS2", "CONTEXTS", "CONTEXT2", "CONTEXT",
  "VALUES", "VALUE", "LCHAR", "CODE", "NEWLINES", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   124,    45,    38,   276,    33,    94,    95,    42,    43,
      61,    63,    40,    41,   123,   125,    58,    91,    93,    46,
      44
};
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -109,    11,   183,  -109,  -109,   727,   727,  -109,   -21,   -18,
     -17,    -6,  -109,  -109,  -109,  -109,   727,   727,   727,   727,
     193,   780,  -109,  -109,   151,    -4,  -109,  -109,  -109,   315,
     315,   727,   809,   727,   809,   756,   756,   756,   249,   -10,
     193,  -109,   -20,  -109,  -109,  -109,  -109,  -109,  -109,   838,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,    12,   809,     5,  -109,    25,   727,    17,    36,
     462,   375,   727,   727,   727,   667,   698,  -109,  -109,  -109,
     636,     9,  -109,   193,    42,   315,  -109,  -109,   315,  -109,
    -109,    13,  -109,  -109,    15,  -109,  -109,   860,  -109,   549,
    -109,    21,   727,   491,   282,  -109,  -109,     7,   520,   404,
    -109,  -109,   578,   607,   636,   462,   462,   193,   727,   193,
    -109,   743,  -109,  -109,  -109,  -109,    36,   315,   216,    26,
     727,   491,   433,  -109,  -109,    27,  -109,  -109,   727,   346,
      29,   193,  -109,  -109,  -109,   315,  -109,  -109,  -109,   346,
    -109,    31,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     4,     0,     0,    90,    31,     0,
      32,     0,    45,    46,    89,    88,     0,     0,     0,     0,
      48,     0,    52,     3,    92,    30,    53,    31,    32,    11,
      38,     0,     0,     0,     0,    37,    39,    40,     0,     0,
      48,    66,     0,    70,    69,    79,    87,    78,    72,    86,
      85,    80,    81,    84,    73,    77,    76,    74,    75,    82,
      71,    83,     0,    64,    67,    68,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    30,     2,     0,     0,     6,    86,     8,     7,     9,
      44,     0,    47,    51,     0,    49,    63,     0,    91,    23,
      10,    28,     0,     0,     0,    12,    54,    57,     0,     0,
      15,    58,    43,    42,    41,     0,     0,     0,    22,    48,
      29,     0,    50,    70,    69,    65,     0,    61,     0,     0,
      62,     0,     0,    16,    17,     0,    13,    14,    20,    21,
       0,    48,    26,    27,    55,    60,    56,    18,    59,    19,
      25,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -109,  -109,  -109,  -109,    -2,   -39,     6,  -108,   -98,   -41,
     -69,   -12,  -109,   -22,   -11,    16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    23,    80,    39,    25,   105,   106,   110,
     107,    62,    63,    64,    26,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,    92,   111,    29,    30,   129,    83,   136,   137,    31,
      65,     3,    32,    33,    35,    36,    37,    38,    93,   117,
      87,    65,    89,    65,    34,    91,    40,    97,    66,    85,
      81,    88,    84,   146,   100,    81,    81,    94,    65,   111,
     135,    81,    81,    81,    81,    84,    40,   131,     7,   121,
      95,    96,    65,   122,     7,    14,    15,   126,   101,   144,
     148,    14,    15,   135,   150,    99,   152,   133,   104,   104,
     112,   113,   114,    36,    37,   125,   119,     0,     0,    21,
     140,    22,    98,     0,     0,     0,    81,     0,     0,   118,
     120,    81,     0,     0,    81,     0,     0,     0,     0,     0,
     127,   128,   151,     0,     0,    81,   104,   128,     0,     0,
      81,     0,     0,   104,   104,   143,   139,     0,    81,    81,
      81,     0,     0,   138,     0,    40,     0,   142,   145,   104,
     128,     0,     0,    81,    81,     0,   149,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,    40,     0,     0,
       0,    81,     0,     0,    66,    81,    67,    68,     0,    69,
       6,    70,    71,     7,    27,     0,    28,     0,    12,    13,
      14,    15,    72,    73,    74,     0,    16,    75,    76,    77,
      78,     0,    79,    19,     0,    20,     4,     5,    21,     0,
      22,     0,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     7,     0,     0,    16,    17,
      18,     0,    14,    15,     0,    19,     0,    20,     0,     0,
      21,    67,    22,   130,    69,     6,    70,    71,     7,    27,
      21,    28,    22,    12,    13,    14,    15,    72,    73,    74,
       0,    16,    75,    76,    77,    78,     0,    79,    19,    90,
      20,     0,     0,    21,    67,    22,     0,    69,     6,    70,
      71,     7,    27,     0,    28,     0,    12,    13,    14,    15,
      72,    73,    74,     0,    16,    75,    76,    77,    78,     0,
      79,    19,    90,    20,     0,     0,    21,    67,    22,   130,
      69,     6,    70,    71,     7,    27,     0,    28,     0,    12,
      13,    14,    15,    72,    73,    74,     0,    16,    75,    76,
      77,    78,     0,    79,    19,     0,    20,     0,     0,    21,
      67,    22,     0,    69,     6,    70,    71,     7,    27,     0,
      28,     0,    12,    13,    14,    15,    72,    73,    74,     0,
      16,    75,    76,    77,    78,     0,    79,    19,     0,    20,
       0,    67,    21,     0,    22,     6,     0,     0,     7,    27,
       0,    28,     0,    12,    13,    14,    15,    72,    73,    74,
       0,    16,    75,    76,    77,    78,     0,    79,    19,     0,
      20,     0,   102,    21,     6,    22,     0,     7,    27,     0,
      28,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,    18,     0,     0,     0,   108,   109,     0,    20,
       0,   102,    21,     6,    22,     0,     7,    27,     0,    28,
       0,    12,    13,    14,    15,     0,     0,     0,     0,    16,
      17,    18,     0,     0,     0,     0,    19,   134,    20,     0,
     102,    21,     6,    22,     0,     7,    27,     0,    28,     0,
      12,    13,    14,    15,     0,     0,     0,     0,    16,    17,
      18,     0,     0,     0,     0,    19,   147,    20,     0,   102,
      21,     6,    22,     0,     7,    27,     0,    28,     0,    12,
      13,    14,    15,     0,     0,     0,     0,    16,    17,    18,
       0,     0,     0,     0,   103,     0,    20,     0,   102,    21,
       6,    22,     0,     7,    27,     0,    28,     0,    12,    13,
      14,    15,     0,     0,     0,     0,    16,    17,    18,     0,
       0,     0,     0,    19,     0,    20,     0,   102,    21,     6,
      22,     0,     7,    27,     0,    28,     0,    12,    13,    14,
      15,     0,     0,     0,     0,    16,    17,    18,     0,     0,
       0,     0,   132,     0,    20,     0,     0,    21,     6,    22,
       0,     7,    27,     0,    28,     0,    12,    13,    14,    15,
      72,    73,    74,     0,    16,    75,    76,    77,    78,     0,
      79,    19,     0,    20,     0,     0,    21,     6,    22,     0,
       7,    27,     0,    28,     0,    12,    13,    14,    15,     0,
      73,    74,     0,    16,    75,    76,    77,    78,     0,    79,
      19,     0,    20,     0,     0,    21,     6,    22,     0,     7,
      27,     0,    28,     0,    12,    13,    14,    15,     0,     0,
      74,     0,    16,    75,    76,    77,    78,     0,    79,    19,
       0,    20,     0,     0,    21,     6,    22,     0,     7,    27,
       0,    28,     0,    12,    13,    14,    15,     0,     0,     0,
       0,    16,    75,    76,    77,    78,     0,    79,    19,     0,
      20,     0,     0,    21,     0,    22,     6,   115,     0,     7,
      27,     0,    28,     0,    12,    13,    14,    15,     0,     0,
       0,     0,    16,    17,    18,     0,     0,     0,     0,    19,
       0,    20,     0,     0,    21,     0,    22,     6,   116,     0,
       7,    27,     0,    28,     0,    12,    13,    14,    15,     0,
       0,     0,     0,    16,    17,    18,     0,     0,     0,     0,
      19,     0,    20,     0,     0,    21,     6,    22,     0,     7,
      27,     0,    28,     0,    12,    13,    14,    15,     0,     0,
       0,     0,    16,    17,    18,     7,     0,     0,     0,    19,
       0,    20,    14,    15,    21,     6,    22,     0,     7,    27,
       0,    28,     0,    12,    13,    14,    15,   141,     0,     0,
      21,     0,    22,     0,    77,    78,     0,    79,    19,     0,
      20,     0,     7,    21,    41,    22,    42,     0,     0,    43,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
      61,     7,     0,    41,     0,     0,     0,     0,    43,    44,
      45,    46,    47,     0,    48,    86,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    60,    61,
       7,     0,    41,     0,     0,     0,     0,    43,    44,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    60,    61,   123,
     124,    45,    46,    47,     0,    48,    86,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
      61
};

static const yytype_int16 yycheck[] =
{
       2,    40,    71,     5,     6,   103,    10,   115,   116,    30,
      21,     0,    30,    30,    16,    17,    18,    19,    38,    10,
      32,    32,    34,    34,    30,    35,    20,    22,     3,    31,
      24,    33,    36,   131,    17,    29,    30,    49,    49,   108,
     109,    35,    36,    37,    38,    36,    40,    40,    12,    36,
      38,    63,    63,    38,    12,    19,    20,    36,    69,    33,
      33,    19,    20,   132,    35,    67,    35,   108,    70,    71,
      72,    73,    74,    75,    76,    97,    34,    -1,    -1,    37,
     119,    39,    66,    -1,    -1,    -1,    80,    -1,    -1,    83,
      84,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
     102,   103,   141,    -1,    -1,    99,   108,   109,    -1,    -1,
     104,    -1,    -1,   115,   116,   126,   118,    -1,   112,   113,
     114,    -1,    -1,   117,    -1,   119,    -1,   121,   130,   131,
     132,    -1,    -1,   127,   128,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,   141,    -1,    -1,
      -1,   145,    -1,    -1,     3,   149,     5,     6,    -1,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    -1,    31,    32,    -1,    34,     3,     4,    37,    -1,
      39,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    12,    -1,    -1,    25,    26,
      27,    -1,    19,    20,    -1,    32,    -1,    34,    -1,    -1,
      37,     5,    39,     7,     8,     9,    10,    11,    12,    13,
      37,    15,    39,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    -1,    -1,    37,     5,    39,    -1,     8,     9,    10,
      11,    12,    13,    -1,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    37,     5,    39,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    -1,    31,    32,    -1,    34,    -1,    -1,    37,
       5,    39,    -1,     8,     9,    10,    11,    12,    13,    -1,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    -1,    31,    32,    -1,    34,
      -1,     5,    37,    -1,    39,     9,    -1,    -1,    12,    13,
      -1,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    -1,
      34,    -1,     7,    37,     9,    39,    -1,    12,    13,    -1,
      15,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      25,    26,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      -1,     7,    37,     9,    39,    -1,    12,    13,    -1,    15,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    -1,    -1,    -1,    -1,    32,    33,    34,    -1,
       7,    37,     9,    39,    -1,    12,    13,    -1,    15,    -1,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    -1,     7,
      37,     9,    39,    -1,    12,    13,    -1,    15,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      -1,    -1,    -1,    -1,    32,    -1,    34,    -1,     7,    37,
       9,    39,    -1,    12,    13,    -1,    15,    -1,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,
      -1,    -1,    -1,    32,    -1,    34,    -1,     7,    37,     9,
      39,    -1,    12,    13,    -1,    15,    -1,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    -1,    37,     9,    39,
      -1,    12,    13,    -1,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    -1,
      31,    32,    -1,    34,    -1,    -1,    37,     9,    39,    -1,
      12,    13,    -1,    15,    -1,    17,    18,    19,    20,    -1,
      22,    23,    -1,    25,    26,    27,    28,    29,    -1,    31,
      32,    -1,    34,    -1,    -1,    37,     9,    39,    -1,    12,
      13,    -1,    15,    -1,    17,    18,    19,    20,    -1,    -1,
      23,    -1,    25,    26,    27,    28,    29,    -1,    31,    32,
      -1,    34,    -1,    -1,    37,     9,    39,    -1,    12,    13,
      -1,    15,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    -1,
      34,    -1,    -1,    37,    -1,    39,     9,    10,    -1,    12,
      13,    -1,    15,    -1,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,    -1,    37,    -1,    39,     9,    10,    -1,
      12,    13,    -1,    15,    -1,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,
      32,    -1,    34,    -1,    -1,    37,     9,    39,    -1,    12,
      13,    -1,    15,    -1,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    12,    -1,    -1,    -1,    32,
      -1,    34,    19,    20,    37,     9,    39,    -1,    12,    13,
      -1,    15,    -1,    17,    18,    19,    20,    34,    -1,    -1,
      37,    -1,    39,    -1,    28,    29,    -1,    31,    32,    -1,
      34,    -1,    12,    37,    14,    39,    16,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,    12,    -1,    14,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    40,
      12,    -1,    14,    -1,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,     3,     4,     9,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    25,    26,    27,    32,
      34,    37,    39,    44,    45,    47,    55,    13,    15,    45,
      45,    30,    30,    30,    30,    45,    45,    45,    45,    46,
      47,    14,    16,    19,    20,    21,    22,    23,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      39,    40,    52,    53,    54,    55,     3,     5,     6,     8,
      10,    11,    21,    22,    23,    26,    27,    28,    29,    31,
      45,    47,    56,    10,    36,    45,    26,    52,    45,    52,
      33,    35,    46,    38,    52,    38,    52,    22,    56,    45,
      17,    55,     7,    32,    45,    48,    49,    51,    31,    32,
      50,    51,    45,    45,    45,    10,    10,    10,    47,    34,
      47,    36,    38,    19,    20,    54,    36,    45,    45,    49,
       7,    40,    32,    50,    33,    51,    48,    48,    47,    45,
      46,    34,    47,    55,    33,    45,    49,    33,    33,    45,
      35,    46,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    44,    44,    44,    44,
      44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    47,
      47,    47,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    52,    52,    53,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    55,
      55,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     0,     3,     3,     3,     3,
       3,     2,     3,     4,     4,     3,     4,     4,     5,     5,
       4,     4,     3,     3,     7,     5,     5,     5,     3,     3,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     1,     1,     2,     0,     3,
       4,     3,     1,     1,     1,     3,     3,     1,     1,     3,
       3,     2,     2,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* ALL: ASSIGNMENTS RE NEWLINES  */
#line 74 "fst-compiler.yy"
                                    { Result=interface.result((yyvsp[-1].expression), Switch); }
#line 1394 "fst-compiler.C"
    break;

  case 3: /* ASSIGNMENTS: ASSIGNMENTS ASSIGNMENT  */
#line 77 "fst-compiler.yy"
                                    {}
#line 1400 "fst-compiler.C"
    break;

  case 4: /* ASSIGNMENTS: ASSIGNMENTS NEWLINE  */
#line 78 "fst-compiler.yy"
                                    {}
#line 1406 "fst-compiler.C"
    break;

  case 5: /* ASSIGNMENTS: %empty  */
#line 79 "fst-compiler.yy"
                                    {}
#line 1412 "fst-compiler.C"
    break;

  case 6: /* ASSIGNMENT: VAR '=' RE  */
#line 82 "fst-compiler.yy"
                                    { if (interface.def_var((yyvsp[-2].name),(yyvsp[0].expression))) warn2("assignment of empty transducer to",(yyvsp[-2].name)); }
#line 1418 "fst-compiler.C"
    break;

  case 7: /* ASSIGNMENT: RVAR '=' RE  */
#line 83 "fst-compiler.yy"
                                    { if (interface.def_rvar((yyvsp[-2].name),(yyvsp[0].expression))) warn2("assignment of empty transducer to",(yyvsp[-2].name)); }
#line 1424 "fst-compiler.C"
    break;

  case 8: /* ASSIGNMENT: SVAR '=' VALUES  */
#line 84 "fst-compiler.yy"
                                    { if (interface.def_svar((yyvsp[-2].name),(yyvsp[0].range))) warn2("assignment of empty symbol range to",(yyvsp[-2].name)); }
#line 1430 "fst-compiler.C"
    break;

  case 9: /* ASSIGNMENT: RSVAR '=' VALUES  */
#line 85 "fst-compiler.yy"
                                    { if (interface.def_svar((yyvsp[-2].name),(yyvsp[0].range))) warn2("assignment of empty symbol range to",(yyvsp[-2].name)); }
#line 1436 "fst-compiler.C"
    break;

  case 10: /* ASSIGNMENT: RE PRINT STRING  */
#line 86 "fst-compiler.yy"
                                    { interface.write_to_file((yyvsp[-2].expression), (yyvsp[0].value)); }
#line 1442 "fst-compiler.C"
    break;

  case 11: /* ASSIGNMENT: ALPHA RE  */
#line 87 "fst-compiler.yy"
                                    { interface.def_alphabet((yyvsp[0].expression)); }
#line 1448 "fst-compiler.C"
    break;

  case 12: /* RE: RE ARROW CONTEXTS2  */
#line 90 "fst-compiler.yy"
                                    { (yyval.expression) = interface.restriction((yyvsp[-2].expression),(yyvsp[-1].type),(yyvsp[0].contexts),0); }
#line 1454 "fst-compiler.C"
    break;

  case 13: /* RE: RE '^' ARROW CONTEXTS2  */
#line 91 "fst-compiler.yy"
                                    { (yyval.expression) = interface.restriction((yyvsp[-3].expression),(yyvsp[-1].type),(yyvsp[0].contexts),1); }
#line 1460 "fst-compiler.C"
    break;

  case 14: /* RE: RE '_' ARROW CONTEXTS2  */
#line 92 "fst-compiler.yy"
                                    { (yyval.expression) = interface.restriction((yyvsp[-3].expression),(yyvsp[-1].type),(yyvsp[0].contexts),-1); }
#line 1466 "fst-compiler.C"
    break;

  case 15: /* RE: RE REPLACE CONTEXT2  */
#line 93 "fst-compiler.yy"
                                    { (yyval.expression) = interface.replace_in_context(interface.minimise(interface.explode((yyvsp[-2].expression))),(yyvsp[-1].rtype),(yyvsp[0].contexts),false); }
#line 1472 "fst-compiler.C"
    break;

  case 16: /* RE: RE REPLACE '?' CONTEXT2  */
#line 94 "fst-compiler.yy"
                                    { (yyval.expression) = interface.replace_in_context(interface.minimise(interface.explode((yyvsp[-3].expression))),(yyvsp[-2].rtype),(yyvsp[0].contexts),true);}
#line 1478 "fst-compiler.C"
    break;

  case 17: /* RE: RE REPLACE '(' ')'  */
#line 95 "fst-compiler.yy"
                                    { (yyval.expression) = interface.replace(interface.minimise(interface.explode((yyvsp[-3].expression))), (yyvsp[-2].rtype), false); }
#line 1484 "fst-compiler.C"
    break;

  case 18: /* RE: RE REPLACE '?' '(' ')'  */
#line 96 "fst-compiler.yy"
                                    { (yyval.expression) = interface.replace(interface.minimise(interface.explode((yyvsp[-4].expression))), (yyvsp[-3].rtype), true); }
#line 1490 "fst-compiler.C"
    break;

  case 19: /* RE: RE RANGE ARROW RANGE RE  */
#line 97 "fst-compiler.yy"
                                    { (yyval.expression) = interface.make_rule((yyvsp[-4].expression),(yyvsp[-3].range),(yyvsp[-2].type),(yyvsp[-1].range),(yyvsp[0].expression)); }
#line 1496 "fst-compiler.C"
    break;

  case 20: /* RE: RE RANGE ARROW RANGE  */
#line 98 "fst-compiler.yy"
                                    { (yyval.expression) = interface.make_rule((yyvsp[-3].expression),(yyvsp[-2].range),(yyvsp[-1].type),(yyvsp[0].range),NULL); }
#line 1502 "fst-compiler.C"
    break;

  case 21: /* RE: RANGE ARROW RANGE RE  */
#line 99 "fst-compiler.yy"
                                    { (yyval.expression) = interface.make_rule(NULL,(yyvsp[-3].range),(yyvsp[-2].type),(yyvsp[-1].range),(yyvsp[0].expression)); }
#line 1508 "fst-compiler.C"
    break;

  case 22: /* RE: RANGE ARROW RANGE  */
#line 100 "fst-compiler.yy"
                                    { (yyval.expression) = interface.make_rule(NULL,(yyvsp[-2].range),(yyvsp[-1].type),(yyvsp[0].range),NULL); }
#line 1514 "fst-compiler.C"
    break;

  case 23: /* RE: RE COMPOSE RE  */
#line 101 "fst-compiler.yy"
                             { (yyval.expression) = interface.composition((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1520 "fst-compiler.C"
    break;

  case 24: /* RE: '{' RANGES '}' ':' '{' RANGES '}'  */
#line 102 "fst-compiler.yy"
                                              { (yyval.expression) = interface.make_mapping((yyvsp[-5].ranges),(yyvsp[-1].ranges)); }
#line 1526 "fst-compiler.C"
    break;

  case 25: /* RE: RANGE ':' '{' RANGES '}'  */
#line 103 "fst-compiler.yy"
                                     { (yyval.expression) = interface.make_mapping(interface.add_range((yyvsp[-4].range),NULL),(yyvsp[-1].ranges)); }
#line 1532 "fst-compiler.C"
    break;

  case 26: /* RE: '{' RANGES '}' ':' RANGE  */
#line 104 "fst-compiler.yy"
                                     { (yyval.expression) = interface.make_mapping((yyvsp[-3].ranges),interface.add_range((yyvsp[0].range),NULL)); }
#line 1538 "fst-compiler.C"
    break;

  case 27: /* RE: RE INSERT CODE ':' CODE  */
#line 105 "fst-compiler.yy"
                                     { (yyval.expression) = interface.freely_insert((yyvsp[-4].expression), (yyvsp[-2].character), (yyvsp[0].character)); }
#line 1544 "fst-compiler.C"
    break;

  case 28: /* RE: RE INSERT CODE  */
#line 106 "fst-compiler.yy"
                                     { (yyval.expression) = interface.freely_insert((yyvsp[-2].expression), (yyvsp[0].character), (yyvsp[0].character)); }
#line 1550 "fst-compiler.C"
    break;

  case 29: /* RE: RANGE ':' RANGE  */
#line 107 "fst-compiler.yy"
                             { (yyval.expression) = interface.new_transducer((yyvsp[-2].range),(yyvsp[0].range)); }
#line 1556 "fst-compiler.C"
    break;

  case 30: /* RE: RANGE  */
#line 108 "fst-compiler.yy"
                             { (yyval.expression) = interface.new_transducer((yyvsp[0].range),(yyvsp[0].range)); }
#line 1562 "fst-compiler.C"
    break;

  case 31: /* RE: VAR  */
#line 109 "fst-compiler.yy"
                             { (yyval.expression) = interface.var_value((yyvsp[0].name)); }
#line 1568 "fst-compiler.C"
    break;

  case 32: /* RE: RVAR  */
#line 110 "fst-compiler.yy"
                             { (yyval.expression) = interface.rvar_value((yyvsp[0].name)); }
#line 1574 "fst-compiler.C"
    break;

  case 33: /* RE: RE '*'  */
#line 111 "fst-compiler.yy"
                             { (yyval.expression) = interface.repetition((yyvsp[-1].expression)); }
#line 1580 "fst-compiler.C"
    break;

  case 34: /* RE: RE '+'  */
#line 112 "fst-compiler.yy"
                             { (yyval.expression) = interface.repetition2((yyvsp[-1].expression)); }
#line 1586 "fst-compiler.C"
    break;

  case 35: /* RE: RE '?'  */
#line 113 "fst-compiler.yy"
                             { (yyval.expression) = interface.optional((yyvsp[-1].expression)); }
#line 1592 "fst-compiler.C"
    break;

  case 36: /* RE: RE RE  */
#line 114 "fst-compiler.yy"
                             { (yyval.expression) = interface.catenate((yyvsp[-1].expression), (yyvsp[0].expression)); }
#line 1598 "fst-compiler.C"
    break;

  case 37: /* RE: '!' RE  */
#line 115 "fst-compiler.yy"
                             { (yyval.expression) = interface.negation((yyvsp[0].expression)); }
#line 1604 "fst-compiler.C"
    break;

  case 38: /* RE: SWITCH RE  */
#line 116 "fst-compiler.yy"
                             { (yyval.expression) = interface.switch_levels((yyvsp[0].expression)); }
#line 1610 "fst-compiler.C"
    break;

  case 39: /* RE: '^' RE  */
#line 117 "fst-compiler.yy"
                             { (yyval.expression) = interface.upper_level((yyvsp[0].expression)); }
#line 1616 "fst-compiler.C"
    break;

  case 40: /* RE: '_' RE  */
#line 118 "fst-compiler.yy"
                             { (yyval.expression) = interface.lower_level((yyvsp[0].expression)); }
#line 1622 "fst-compiler.C"
    break;

  case 41: /* RE: RE '&' RE  */
#line 119 "fst-compiler.yy"
                             { (yyval.expression) = interface.conjunction((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1628 "fst-compiler.C"
    break;

  case 42: /* RE: RE '-' RE  */
#line 120 "fst-compiler.yy"
                             { (yyval.expression) = interface.subtraction((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1634 "fst-compiler.C"
    break;

  case 43: /* RE: RE '|' RE  */
#line 121 "fst-compiler.yy"
                             { (yyval.expression) = interface.disjunction((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1640 "fst-compiler.C"
    break;

  case 44: /* RE: '(' RE ')'  */
#line 122 "fst-compiler.yy"
                             { (yyval.expression) = (yyvsp[-1].expression); }
#line 1646 "fst-compiler.C"
    break;

  case 45: /* RE: STRING  */
#line 123 "fst-compiler.yy"
                             { (yyval.expression) = interface.read_words((yyvsp[0].value)); }
#line 1652 "fst-compiler.C"
    break;

  case 46: /* RE: STRING2  */
#line 124 "fst-compiler.yy"
                             { (yyval.expression) = interface.read_transducer((yyvsp[0].value)); }
#line 1658 "fst-compiler.C"
    break;

  case 47: /* RANGES: RANGE RANGES  */
#line 127 "fst-compiler.yy"
                             { (yyval.ranges) = interface.add_range((yyvsp[-1].range),(yyvsp[0].ranges)); }
#line 1664 "fst-compiler.C"
    break;

  case 48: /* RANGES: %empty  */
#line 128 "fst-compiler.yy"
                             { (yyval.ranges) = NULL; }
#line 1670 "fst-compiler.C"
    break;

  case 49: /* RANGE: '[' VALUES ']'  */
#line 131 "fst-compiler.yy"
                             { (yyval.range)=(yyvsp[-1].range); }
#line 1676 "fst-compiler.C"
    break;

  case 50: /* RANGE: '[' '^' VALUES ']'  */
#line 132 "fst-compiler.yy"
                               { (yyval.range)=interface.complement_range((yyvsp[-1].range)); }
#line 1682 "fst-compiler.C"
    break;

  case 51: /* RANGE: '[' RSVAR ']'  */
#line 133 "fst-compiler.yy"
                             { (yyval.range)=interface.rsvar_value((yyvsp[-1].name)); }
#line 1688 "fst-compiler.C"
    break;

  case 52: /* RANGE: '.'  */
#line 134 "fst-compiler.yy"
                             { (yyval.range)=NULL; }
#line 1694 "fst-compiler.C"
    break;

  case 53: /* RANGE: CODE  */
#line 135 "fst-compiler.yy"
                             { (yyval.range)=interface.add_value((yyvsp[0].character),NULL); }
#line 1700 "fst-compiler.C"
    break;

  case 54: /* CONTEXTS2: CONTEXTS  */
#line 138 "fst-compiler.yy"
                                   { (yyval.contexts) = (yyvsp[0].contexts); }
#line 1706 "fst-compiler.C"
    break;

  case 55: /* CONTEXTS2: '(' CONTEXTS ')'  */
#line 139 "fst-compiler.yy"
                                   { (yyval.contexts) = (yyvsp[-1].contexts); }
#line 1712 "fst-compiler.C"
    break;

  case 56: /* CONTEXTS: CONTEXT ',' CONTEXTS  */
#line 142 "fst-compiler.yy"
                                   { (yyval.contexts) = interface.add_context((yyvsp[-2].contexts),(yyvsp[0].contexts)); }
#line 1718 "fst-compiler.C"
    break;

  case 57: /* CONTEXTS: CONTEXT  */
#line 143 "fst-compiler.yy"
                                   { (yyval.contexts) = (yyvsp[0].contexts); }
#line 1724 "fst-compiler.C"
    break;

  case 58: /* CONTEXT2: CONTEXT  */
#line 146 "fst-compiler.yy"
                                   { (yyval.contexts) = (yyvsp[0].contexts); }
#line 1730 "fst-compiler.C"
    break;

  case 59: /* CONTEXT2: '(' CONTEXT ')'  */
#line 147 "fst-compiler.yy"
                                   { (yyval.contexts) = (yyvsp[-1].contexts); }
#line 1736 "fst-compiler.C"
    break;

  case 60: /* CONTEXT: RE POS RE  */
#line 150 "fst-compiler.yy"
                                   { (yyval.contexts) = interface.make_context((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1742 "fst-compiler.C"
    break;

  case 61: /* CONTEXT: POS RE  */
#line 151 "fst-compiler.yy"
                                   { (yyval.contexts) = interface.make_context(NULL, (yyvsp[0].expression)); }
#line 1748 "fst-compiler.C"
    break;

  case 62: /* CONTEXT: RE POS  */
#line 152 "fst-compiler.yy"
                                   { (yyval.contexts) = interface.make_context((yyvsp[-1].expression), NULL); }
#line 1754 "fst-compiler.C"
    break;

  case 63: /* VALUES: VALUE VALUES  */
#line 155 "fst-compiler.yy"
                                   { (yyval.range)=interface.append_values((yyvsp[-1].range),(yyvsp[0].range)); }
#line 1760 "fst-compiler.C"
    break;

  case 64: /* VALUES: VALUE  */
#line 156 "fst-compiler.yy"
                                   { (yyval.range) = (yyvsp[0].range); }
#line 1766 "fst-compiler.C"
    break;

  case 65: /* VALUE: LCHAR '-' LCHAR  */
#line 159 "fst-compiler.yy"
                                   { (yyval.range)=interface.add_values((yyvsp[-2].longchar),(yyvsp[0].longchar),NULL); }
#line 1772 "fst-compiler.C"
    break;

  case 66: /* VALUE: SVAR  */
#line 160 "fst-compiler.yy"
                                   { (yyval.range)=interface.svar_value((yyvsp[0].name)); }
#line 1778 "fst-compiler.C"
    break;

  case 67: /* VALUE: LCHAR  */
#line 161 "fst-compiler.yy"
                                   { (yyval.range)=interface.add_value(interface.character_code((yyvsp[0].longchar)),NULL); }
#line 1784 "fst-compiler.C"
    break;

  case 68: /* VALUE: CODE  */
#line 162 "fst-compiler.yy"
                                   { (yyval.range)=interface.add_value((yyvsp[0].character),NULL); }
#line 1790 "fst-compiler.C"
    break;

  case 69: /* LCHAR: CHARACTER  */
#line 165 "fst-compiler.yy"
                        { (yyval.longchar)=(yyvsp[0].uchar); }
#line 1796 "fst-compiler.C"
    break;

  case 70: /* LCHAR: UTF8CHAR  */
#line 166 "fst-compiler.yy"
                        { (yyval.longchar)=utf8toint((yyvsp[0].value)); free((yyvsp[0].value)); }
#line 1802 "fst-compiler.C"
    break;

  case 71: /* LCHAR: '.'  */
#line 167 "fst-compiler.yy"
                        { (yyval.longchar)='.'; }
#line 1808 "fst-compiler.C"
    break;

  case 72: /* LCHAR: '!'  */
#line 168 "fst-compiler.yy"
                        { (yyval.longchar)='!'; }
#line 1814 "fst-compiler.C"
    break;

  case 73: /* LCHAR: '?'  */
#line 169 "fst-compiler.yy"
                        { (yyval.longchar)='?'; }
#line 1820 "fst-compiler.C"
    break;

  case 74: /* LCHAR: '{'  */
#line 170 "fst-compiler.yy"
                        { (yyval.longchar)='{'; }
#line 1826 "fst-compiler.C"
    break;

  case 75: /* LCHAR: '}'  */
#line 171 "fst-compiler.yy"
                        { (yyval.longchar)='}'; }
#line 1832 "fst-compiler.C"
    break;

  case 76: /* LCHAR: ')'  */
#line 172 "fst-compiler.yy"
                        { (yyval.longchar)=')'; }
#line 1838 "fst-compiler.C"
    break;

  case 77: /* LCHAR: '('  */
#line 173 "fst-compiler.yy"
                        { (yyval.longchar)='('; }
#line 1844 "fst-compiler.C"
    break;

  case 78: /* LCHAR: '&'  */
#line 174 "fst-compiler.yy"
                        { (yyval.longchar)='&'; }
#line 1850 "fst-compiler.C"
    break;

  case 79: /* LCHAR: '|'  */
#line 175 "fst-compiler.yy"
                        { (yyval.longchar)='|'; }
#line 1856 "fst-compiler.C"
    break;

  case 80: /* LCHAR: '*'  */
#line 176 "fst-compiler.yy"
                        { (yyval.longchar)='*'; }
#line 1862 "fst-compiler.C"
    break;

  case 81: /* LCHAR: '+'  */
#line 177 "fst-compiler.yy"
                        { (yyval.longchar)='+'; }
#line 1868 "fst-compiler.C"
    break;

  case 82: /* LCHAR: ':'  */
#line 178 "fst-compiler.yy"
                        { (yyval.longchar)=':'; }
#line 1874 "fst-compiler.C"
    break;

  case 83: /* LCHAR: ','  */
#line 179 "fst-compiler.yy"
                        { (yyval.longchar)=','; }
#line 1880 "fst-compiler.C"
    break;

  case 84: /* LCHAR: '='  */
#line 180 "fst-compiler.yy"
                        { (yyval.longchar)='='; }
#line 1886 "fst-compiler.C"
    break;

  case 85: /* LCHAR: '_'  */
#line 181 "fst-compiler.yy"
                        { (yyval.longchar)='_'; }
#line 1892 "fst-compiler.C"
    break;

  case 86: /* LCHAR: '^'  */
#line 182 "fst-compiler.yy"
                        { (yyval.longchar)='^'; }
#line 1898 "fst-compiler.C"
    break;

  case 87: /* LCHAR: '-'  */
#line 183 "fst-compiler.yy"
                        { (yyval.longchar)='-'; }
#line 1904 "fst-compiler.C"
    break;

  case 88: /* CODE: CHARACTER  */
#line 186 "fst-compiler.yy"
                        { (yyval.character)=interface.character_code((yyvsp[0].uchar)); }
#line 1910 "fst-compiler.C"
    break;

  case 89: /* CODE: UTF8CHAR  */
#line 187 "fst-compiler.yy"
                        { (yyval.character)=interface.symbol_code((yyvsp[0].value)); }
#line 1916 "fst-compiler.C"
    break;

  case 90: /* CODE: SYMBOL  */
#line 188 "fst-compiler.yy"
                        { (yyval.character)=interface.symbol_code((yyvsp[0].name)); }
#line 1922 "fst-compiler.C"
    break;

  case 91: /* NEWLINES: NEWLINE NEWLINES  */
#line 192 "fst-compiler.yy"
                                 {}
#line 1928 "fst-compiler.C"
    break;

  case 92: /* NEWLINES: %empty  */
#line 193 "fst-compiler.yy"
                                 {}
#line 1934 "fst-compiler.C"
    break;


#line 1938 "fst-compiler.C"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 196 "fst-compiler.yy"


extern FILE  *yyin;
static int Compact=0;
static int LowMem=0;

/*******************************************************************/
/*                                                                 */
/*  yyerror                                                        */
/*                                                                 */
/*******************************************************************/

void yyerror( const char *text )

{
  cerr << "\n" << FileName << ":" << yylineno << ": " << text << " at: ";
  cerr << yytext << "\naborted.\n";
  exit(1);
}


/*******************************************************************/
/*                                                                 */
/*  warn                                                           */
/*                                                                 */
/*******************************************************************/

void warn( const char *text )

{
  if (Verbose)
    cerr << "\n";
  cerr << FileName << ":" << yylineno << ": warning: " << text << "!\n";
}


/*******************************************************************/
/*                                                                 */
/*  warn2                                                          */
/*                                                                 */
/*******************************************************************/

void warn2( const char *text, const char *text2)

{
  if (Verbose)
    cerr << "\n";
  cerr << FileName << ":" << yylineno << ": warning: " << text << ": ";
  cerr << text2 << "\n";
}


/*******************************************************************/
/*                                                                 */
/*  get_flags                                                      */
/*                                                                 */
/*******************************************************************/

void get_flags( int *argc, char **argv )

{
  for( int i=1; i<*argc; i++ ) {
    if (strcmp(argv[i],"-c") == 0) {
      Compact = 1;
      argv[i] = NULL;
    }
    else if (strcmp(argv[i],"-l") == 0) {
      LowMem = 1;
      argv[i] = NULL;
    }
    else if (strcmp(argv[i],"-q") == 0) {
      Verbose = 0;
      argv[i] = NULL;
    }
    else if (strcmp(argv[i],"-v") == 0) {
      printf("fst-compiler version %s\n", SFSTVersion);
      exit(0);
    }
    else if (strcmp(argv[i],"-s") == 0) {
      Switch = 1;
      argv[i] = NULL;
    }
    else if (strcmp(argv[i],"-lc") == 0) {
      interface.allow_lexicon_comments();
      argv[i] = NULL;
    }
  }
  // remove flags from the argument list
  int k;
  for( int i=k=1; i<*argc; i++)
    if (argv[i] != NULL)
      argv[k++] = argv[i];
  *argc = k;
}


/*******************************************************************/
/*                                                                 */
/*  main                                                           */
/*                                                                 */
/*******************************************************************/

int main( int argc, char *argv[] )

{
  FILE *file;

  get_flags(&argc, argv);
  if (argc < 3) {
    fprintf(stderr,"\nUsage: %s [options] infile outfile\n", argv[0]);
    fprintf(stderr,"\nOPTIONS:\n");
    fprintf(stderr,"-c\tStore the transducer in fst-infl2 format.\n");
    fprintf(stderr,"-l\tStore the transducer in fst-infl3 format.\n");
    fprintf(stderr,"-s\tSwitch the upper and lower levels producing a transducer for generation rather than recognition.\n");
    fprintf(stderr,"-lc\tallow comments starting with '%%' in the lexicon files.\n");
    fprintf(stderr,"-v\tprint version information\n");
    fprintf(stderr,"-q\tquiet mode\n\n");
    exit(1);
  }
  if ((file = fopen(argv[1],"rt")) == NULL) {
    fprintf(stderr,"\nError: Cannot open source file \"%s\"\n\n", argv[1]);
    exit(1);
  }
  FileName = argv[1];
  Result = NULL;
  interface.TheAlphabet.utf8 = UTF8;
  interface.Verbose = Verbose;
  yyin = file;
  try {
    yyparse();
    Result->alphabet.utf8 = UTF8;
    if (Verbose)
      cerr << "\n";
    if (Result->is_empty()) 
      warn("result transducer is empty"); 
    if ((file = fopen(argv[2],"wb")) == NULL) {
	fprintf(stderr,"\nError: Cannot open output file %s\n\n", argv[2]);
	exit(1);
    }
    if (Compact) {
      MakeCompactTransducer ca(*Result);
      delete Result;
      ca.store(file);
    }
    else if (LowMem)
      Result->store_lowmem(file);
    else
      Result->store(file);
    fclose(file);
  }
  catch(const char* p) {
      cerr << "\n" << p << "\n\n";
      exit(1);
  }
}
