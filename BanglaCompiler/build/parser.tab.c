/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "src/parser.y"

#include <iostream>
#include <stdbool.h>
#include "ast.h"
extern "C" int yylex();
extern "C" int yyparse();
extern int yylineno;
void yyerror(const char* s) { std::cerr << "Parse Error: " << s << " at line " << yylineno << std::endl; }
extern ASTNode* root;

#line 82 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_BOOL = 6,                       /* BOOL  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FUNCTION = 10,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_PRINT = 12,                     /* PRINT  */
  YYSYMBOL_ASSIGN = 13,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 14,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 15,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 16,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 19,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 20,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_LT = 23,                        /* LT  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_PLUS = 25,                      /* PLUS  */
  YYSYMBOL_MINUS = 26,                     /* MINUS  */
  YYSYMBOL_MUL = 27,                       /* MUL  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_INTEGER = 31,                   /* INTEGER  */
  YYSYMBOL_FLOATVAL = 32,                  /* FLOATVAL  */
  YYSYMBOL_TRUE = 33,                      /* TRUE  */
  YYSYMBOL_FALSE = 34,                     /* FALSE  */
  YYSYMBOL_STRINGVAL = 35,                 /* STRINGVAL  */
  YYSYMBOL_IDENTIFIER = 36,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_stmt = 39,                      /* stmt  */
  YYSYMBOL_optional_else = 40,             /* optional_else  */
  YYSYMBOL_expr = 41,                      /* expr  */
  YYSYMBOL_array = 42,                     /* array  */
  YYSYMBOL_expr_list = 43,                 /* expr_list  */
  YYSYMBOL_func_def = 44,                  /* func_def  */
  YYSYMBOL_param_list = 45,                /* param_list  */
  YYSYMBOL_call_args = 46                  /* call_args  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    42,    42,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    57,    58,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    80,    83,    84,    87,    90,    91,    92,    95,
      96,    97
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "FLOAT",
  "STRING", "BOOL", "IF", "ELSE", "WHILE", "FUNCTION", "RETURN", "PRINT",
  "ASSIGN", "SEMICOLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "COMMA", "GT", "LT", "EQ", "PLUS", "MINUS",
  "MUL", "DIV", "AND", "OR", "INTEGER", "FLOATVAL", "TRUE", "FALSE",
  "STRINGVAL", "IDENTIFIER", "$accept", "program", "stmt", "optional_else",
  "expr", "array", "expr_list", "func_def", "param_list", "call_args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      77,   -18,   -24,   -20,   -17,     0,     2,   -16,    13,     7,
      23,   -78,   -78,    10,    18,    19,    20,    37,    13,    13,
      62,    13,   -78,   -78,   -78,   -78,   -78,    64,    29,    13,
     -78,    54,    13,    13,    13,    13,   120,   135,   102,   150,
      13,   -78,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   165,    78,    46,    71,    88,   105,   103,   104,    86,
     107,   -78,   175,   108,   -21,   -21,    81,   -19,   -19,   -78,
     -78,    39,   194,   111,   118,   -78,   -78,   -78,   -78,    77,
      77,   117,   109,    13,   -78,   -78,    13,   125,   122,   123,
     102,    77,   -78,   185,   132,   -78,   145,   -78,   -78,   136,
      13,   -78,   138,   -78,   -78,   -78,    77,   149,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,    18,    19,    17,    20,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,    36,     0,
      39,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    40,     0,    26,    27,    28,    22,    23,    24,
      25,    29,    30,     0,     0,     3,     4,     5,     6,     0,
       0,    37,     0,    39,    21,     8,     0,     0,     0,     0,
      36,     0,    41,    33,     0,     7,    13,    10,    38,     0,
       0,    32,     0,     9,    35,    34,     0,     0,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -77,   -78,    -8,   -78,    56,   -78,    79,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,   103,    62,    87,    94,    12,    60,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,    13,    88,    89,    45,    46,    47,    48,    47,    48,
      36,    37,    15,    39,    99,    18,    16,    19,    14,    17,
      20,    51,    29,    30,    53,    54,    55,    56,    21,   107,
      31,    32,    33,    34,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    41,    22,    23,    24,    25,    26,    27,
      35,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      75,    42,    43,    44,    45,    46,    47,    48,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    38,    93,    40,
       1,     2,     3,     4,     5,    76,     6,     7,     8,     9,
      52,    74,    93,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    77,    42,    43,    59,    45,    46,    47,    48,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    78,
      79,    80,    81,    82,    84,    85,    91,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    57,    86,    90,    95,
      96,    97,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    58,   101,   102,   104,   106,   105,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    61,   108,    92,    98,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    73,     0,     0,     0,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    83,    42,    43,    44,
      45,    46,    47,    48,    49,    50,   100,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    42,    43,    44,    45,
      46,    47,    48,    49
};

static const yytype_int8 yycheck[] =
{
       8,    19,    79,    80,    25,    26,    27,    28,    27,    28,
      18,    19,    36,    21,    91,    15,    36,    15,    36,    36,
      36,    29,    15,     0,    32,    33,    34,    35,    15,   106,
      20,    13,    13,    13,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    14,    31,    32,    33,    34,    35,    36,
      13,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      14,    22,    23,    24,    25,    26,    27,    28,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    15,    86,    15,
       3,     4,     5,     6,     7,    14,     9,    10,    11,    12,
      36,    13,   100,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    14,    22,    23,     3,    25,    26,    27,    28,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    14,
      17,    17,    36,    16,    16,    14,    17,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    16,    19,    21,    14,
      18,    18,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    16,    20,     8,    18,    17,   100,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    16,    18,    83,    90,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    16,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    22,    23,    24,    25,
      26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      38,    39,    44,    19,    36,    36,    36,    36,    15,    15,
      36,    15,    31,    32,    33,    34,    35,    36,    41,    15,
       0,    20,    13,    13,    13,    13,    41,    41,    15,    41,
      15,    14,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    41,    36,    41,    41,    41,    41,    16,    16,     3,
      45,    16,    41,    46,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    16,    13,    14,    14,    14,    14,    17,
      17,    36,    16,    21,    16,    14,    19,    42,    39,    39,
      21,    17,    46,    41,    43,    14,    18,    18,    45,    39,
      21,    20,     8,    40,    18,    43,    17,    39,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    42,    43,    43,    44,    45,    45,    45,    46,
      46,    46
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     5,     5,     5,     7,     5,     8,
       7,     1,     3,     0,     4,     1,     1,     1,     1,     1,
       1,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     8,     0,     2,     4,     0,
       1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* program: stmt  */
#line 42 "src/parser.y"
              { root = (yyvsp[0].node); }
#line 1196 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 3: /* stmt: NUMBER IDENTIFIER ASSIGN expr SEMICOLON  */
#line 45 "src/parser.y"
                                              { (yyval.node) = new AssignNode((yyvsp[-3].sval), "int", (yyvsp[-1].node)); }
#line 1202 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 4: /* stmt: FLOAT IDENTIFIER ASSIGN expr SEMICOLON  */
#line 46 "src/parser.y"
                                             { (yyval.node) = new AssignNode((yyvsp[-3].sval), "float", (yyvsp[-1].node)); }
#line 1208 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 5: /* stmt: STRING IDENTIFIER ASSIGN expr SEMICOLON  */
#line 47 "src/parser.y"
                                              { (yyval.node) = new AssignNode((yyvsp[-3].sval), "string", (yyvsp[-1].node)); }
#line 1214 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 6: /* stmt: BOOL IDENTIFIER ASSIGN expr SEMICOLON  */
#line 48 "src/parser.y"
                                            { (yyval.node) = new AssignNode((yyvsp[-3].sval), "bool", (yyvsp[-1].node)); }
#line 1220 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 7: /* stmt: NUMBER LBRACKET RBRACKET IDENTIFIER ASSIGN array SEMICOLON  */
#line 49 "src/parser.y"
                                                                 { (yyval.node) = new ArrayAssignNode((yyvsp[-3].sval), (yyvsp[-1].node)); }
#line 1226 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 8: /* stmt: PRINT LPAREN expr RPAREN SEMICOLON  */
#line 50 "src/parser.y"
                                         { (yyval.node) = new PrintNode((yyvsp[-2].node)); }
#line 1232 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 9: /* stmt: IF LPAREN expr RPAREN LBRACE stmt RBRACE optional_else  */
#line 51 "src/parser.y"
                                                             { (yyval.node) = new IfNode((yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1238 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 10: /* stmt: WHILE LPAREN expr RPAREN LBRACE stmt RBRACE  */
#line 52 "src/parser.y"
                                                  { (yyval.node) = new WhileNode((yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1244 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 11: /* stmt: func_def  */
#line 53 "src/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1250 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 12: /* stmt: RETURN expr SEMICOLON  */
#line 54 "src/parser.y"
                            { (yyval.node) = new ReturnNode((yyvsp[-1].node)); }
#line 1256 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 13: /* optional_else: %empty  */
#line 57 "src/parser.y"
                           { (yyval.node) = nullptr; }
#line 1262 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 14: /* optional_else: ELSE LBRACE stmt RBRACE  */
#line 58 "src/parser.y"
                                       { (yyval.node) = (yyvsp[-1].node); }
#line 1268 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 15: /* expr: INTEGER  */
#line 61 "src/parser.y"
                    { (yyval.node) = new IntNode((yyvsp[0].ival)); }
#line 1274 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 16: /* expr: FLOATVAL  */
#line 62 "src/parser.y"
                    { (yyval.node) = new FloatNode((yyvsp[0].fval)); }
#line 1280 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 17: /* expr: STRINGVAL  */
#line 63 "src/parser.y"
                    { (yyval.node) = new StringNode((yyvsp[0].sval)); }
#line 1286 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 18: /* expr: TRUE  */
#line 64 "src/parser.y"
                    { (yyval.node) = new BoolNode((yyvsp[0].bval)); }
#line 1292 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 19: /* expr: FALSE  */
#line 65 "src/parser.y"
                    { (yyval.node) = new BoolNode((yyvsp[0].bval)); }
#line 1298 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 20: /* expr: IDENTIFIER  */
#line 66 "src/parser.y"
                    { (yyval.node) = new VarNode((yyvsp[0].sval)); }
#line 1304 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 21: /* expr: IDENTIFIER LPAREN call_args RPAREN  */
#line 67 "src/parser.y"
                                         { (yyval.node) = new CallNode((yyvsp[-3].sval), (yyvsp[-1].node)); }
#line 1310 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 22: /* expr: expr PLUS expr  */
#line 68 "src/parser.y"
                     { (yyval.node) = new BinaryOpNode((yyvsp[-2].node), "+", (yyvsp[0].node)); }
#line 1316 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 23: /* expr: expr MINUS expr  */
#line 69 "src/parser.y"
                      { (yyval.node) = new BinaryOpNode((yyvsp[-2].node), "-", (yyvsp[0].node)); }
#line 1322 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 24: /* expr: expr MUL expr  */
#line 70 "src/parser.y"
                     { (yyval.node) = new BinaryOpNode((yyvsp[-2].node), "*", (yyvsp[0].node)); }
#line 1328 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 25: /* expr: expr DIV expr  */
#line 71 "src/parser.y"
                     { (yyval.node) = new BinaryOpNode((yyvsp[-2].node), "/", (yyvsp[0].node)); }
#line 1334 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 26: /* expr: expr GT expr  */
#line 72 "src/parser.y"
                     { (yyval.node) = new BinaryOpNode((yyvsp[-2].node), ">", (yyvsp[0].node)); }
#line 1340 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 27: /* expr: expr LT expr  */
#line 73 "src/parser.y"
                     { (yyval.node) = new BinaryOpNode((yyvsp[-2].node), "<", (yyvsp[0].node)); }
#line 1346 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 28: /* expr: expr EQ expr  */
#line 74 "src/parser.y"
                     { (yyval.node) = new BinaryOpNode((yyvsp[-2].node), "==", (yyvsp[0].node)); }
#line 1352 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 29: /* expr: expr AND expr  */
#line 75 "src/parser.y"
                     { (yyval.node) = new BinaryOpNode((yyvsp[-2].node), "&&", (yyvsp[0].node)); }
#line 1358 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 30: /* expr: expr OR expr  */
#line 76 "src/parser.y"
                     { (yyval.node) = new BinaryOpNode((yyvsp[-2].node), "||", (yyvsp[0].node)); }
#line 1364 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 31: /* expr: LPAREN expr RPAREN  */
#line 77 "src/parser.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 1370 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 32: /* array: LBRACKET expr_list RBRACKET  */
#line 80 "src/parser.y"
                                   { (yyval.node) = (yyvsp[-1].node); }
#line 1376 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 33: /* expr_list: expr  */
#line 83 "src/parser.y"
                { (yyval.node) = new ExprListNode((yyvsp[0].node)); }
#line 1382 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 34: /* expr_list: expr COMMA expr_list  */
#line 84 "src/parser.y"
                                { (yyval.node) = new ExprListNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1388 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 35: /* func_def: FUNCTION IDENTIFIER LPAREN param_list RPAREN LBRACE stmt RBRACE  */
#line 87 "src/parser.y"
                                                                          { (yyval.node) = new FunctionNode((yyvsp[-6].sval), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1394 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 36: /* param_list: %empty  */
#line 90 "src/parser.y"
                        { (yyval.node) = nullptr; }
#line 1400 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 37: /* param_list: NUMBER IDENTIFIER  */
#line 91 "src/parser.y"
                              { (yyval.node) = new ParamNode((yyvsp[0].sval), "int"); }
#line 1406 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 38: /* param_list: NUMBER IDENTIFIER COMMA param_list  */
#line 92 "src/parser.y"
                                               { (yyval.node) = new ParamNode((yyvsp[-2].sval), "int", (yyvsp[0].node)); }
#line 1412 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 39: /* call_args: %empty  */
#line 95 "src/parser.y"
                       { (yyval.node) = nullptr; }
#line 1418 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 40: /* call_args: expr  */
#line 96 "src/parser.y"
                { (yyval.node) = new ExprListNode((yyvsp[0].node)); }
#line 1424 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;

  case 41: /* call_args: expr COMMA call_args  */
#line 97 "src/parser.y"
                                { (yyval.node) = new ExprListNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1430 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"
    break;


#line 1434 "/home/j47/Documents/Compiler/Compiler-design/BanglaCompiler/build/parser.tab.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 99 "src/parser.y"
