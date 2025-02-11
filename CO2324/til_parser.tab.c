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
#line 1 "til_parser.y"

//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#line 85 "til_parser.tab.c"

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

#include "til_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tINTEGER = 3,                   /* tINTEGER  */
  YYSYMBOL_tDOUBLE = 4,                    /* tDOUBLE  */
  YYSYMBOL_tIDENTIFIER = 5,                /* tIDENTIFIER  */
  YYSYMBOL_tSTRING = 6,                    /* tSTRING  */
  YYSYMBOL_tTYPE_INT = 7,                  /* tTYPE_INT  */
  YYSYMBOL_tTYPE_DOUBLE = 8,               /* tTYPE_DOUBLE  */
  YYSYMBOL_tTYPE_STRING = 9,               /* tTYPE_STRING  */
  YYSYMBOL_tTYPE_VOID = 10,                /* tTYPE_VOID  */
  YYSYMBOL_tEXTERNAL = 11,                 /* tEXTERNAL  */
  YYSYMBOL_tFORWARD = 12,                  /* tFORWARD  */
  YYSYMBOL_tPUBLIC = 13,                   /* tPUBLIC  */
  YYSYMBOL_tPRIVATE = 14,                  /* tPRIVATE  */
  YYSYMBOL_tVAR = 15,                      /* tVAR  */
  YYSYMBOL_tBLOCK = 16,                    /* tBLOCK  */
  YYSYMBOL_tLOOP = 17,                     /* tLOOP  */
  YYSYMBOL_tSTOP = 18,                     /* tSTOP  */
  YYSYMBOL_tNEXT = 19,                     /* tNEXT  */
  YYSYMBOL_tRETURN = 20,                   /* tRETURN  */
  YYSYMBOL_tIF = 21,                       /* tIF  */
  YYSYMBOL_tREAD = 22,                     /* tREAD  */
  YYSYMBOL_tNULL = 23,                     /* tNULL  */
  YYSYMBOL_tSET = 24,                      /* tSET  */
  YYSYMBOL_tINDEX = 25,                    /* tINDEX  */
  YYSYMBOL_tOBJECTS = 26,                  /* tOBJECTS  */
  YYSYMBOL_tSIZEOF = 27,                   /* tSIZEOF  */
  YYSYMBOL_tFUNCTION = 28,                 /* tFUNCTION  */
  YYSYMBOL_tPROGRAM = 29,                  /* tPROGRAM  */
  YYSYMBOL_tPRINT = 30,                    /* tPRINT  */
  YYSYMBOL_tPRINTLN = 31,                  /* tPRINTLN  */
  YYSYMBOL_tAND = 32,                      /* tAND  */
  YYSYMBOL_tOR = 33,                       /* tOR  */
  YYSYMBOL_34_ = 34,                       /* '~'  */
  YYSYMBOL_tGE = 35,                       /* tGE  */
  YYSYMBOL_tLE = 36,                       /* tLE  */
  YYSYMBOL_tEQ = 37,                       /* tEQ  */
  YYSYMBOL_tNE = 38,                       /* tNE  */
  YYSYMBOL_39_ = 39,                       /* '>'  */
  YYSYMBOL_40_ = 40,                       /* '<'  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_45_ = 45,                       /* '%'  */
  YYSYMBOL_tUNARY = 46,                    /* tUNARY  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* '!'  */
  YYSYMBOL_50_ = 50,                       /* '?'  */
  YYSYMBOL_51_ = 51,                       /* '@'  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_file = 53,                      /* file  */
  YYSYMBOL_fdecls = 54,                    /* fdecls  */
  YYSYMBOL_fdecl = 55,                     /* fdecl  */
  YYSYMBOL_type = 56,                      /* type  */
  YYSYMBOL_referable_type = 57,            /* referable_type  */
  YYSYMBOL_function_type = 58,             /* function_type  */
  YYSYMBOL_function_return_type = 59,      /* function_return_type  */
  YYSYMBOL_types = 60,                     /* types  */
  YYSYMBOL_ref_type = 61,                  /* ref_type  */
  YYSYMBOL_ref_type_void = 62,             /* ref_type_void  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_decls_insts = 64,               /* decls_insts  */
  YYSYMBOL_decls = 65,                     /* decls  */
  YYSYMBOL_decl = 66,                      /* decl  */
  YYSYMBOL_insts = 67,                     /* insts  */
  YYSYMBOL_inst = 68,                      /* inst  */
  YYSYMBOL_block = 69,                     /* block  */
  YYSYMBOL_exprs = 70,                     /* exprs  */
  YYSYMBOL_expr = 71,                      /* expr  */
  YYSYMBOL_lval = 72,                      /* lval  */
  YYSYMBOL_function_def = 73,              /* function_def  */
  YYSYMBOL_function_args = 74,             /* function_args  */
  YYSYMBOL_function_arg = 75               /* function_arg  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 66 "til_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 198 "til_parser.tab.c"


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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   525

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
       2,     2,     2,    49,     2,     2,     2,    45,     2,     2,
      47,    48,    43,    41,     2,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,     2,    39,    50,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    34,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    35,
      36,    37,    38,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    71,    71,    72,    73,    74,    77,    78,    81,    82,
      83,    84,    85,    86,    87,    90,    91,    94,    95,    96,
      97,    98,   101,   102,   105,   106,   109,   110,   113,   117,
     118,   121,   124,   125,   126,   127,   130,   131,   134,   135,
     136,   139,   140,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   159,   162,   163,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     199,   200,   204,   205,   208,   209,   212
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
  "\"end of file\"", "error", "\"invalid token\"", "tINTEGER", "tDOUBLE",
  "tIDENTIFIER", "tSTRING", "tTYPE_INT", "tTYPE_DOUBLE", "tTYPE_STRING",
  "tTYPE_VOID", "tEXTERNAL", "tFORWARD", "tPUBLIC", "tPRIVATE", "tVAR",
  "tBLOCK", "tLOOP", "tSTOP", "tNEXT", "tRETURN", "tIF", "tREAD", "tNULL",
  "tSET", "tINDEX", "tOBJECTS", "tSIZEOF", "tFUNCTION", "tPROGRAM",
  "tPRINT", "tPRINTLN", "tAND", "tOR", "'~'", "tGE", "tLE", "tEQ", "tNE",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "tUNARY", "'('", "')'",
  "'!'", "'?'", "'@'", "$accept", "file", "fdecls", "fdecl", "type",
  "referable_type", "function_type", "function_return_type", "types",
  "ref_type", "ref_type_void", "program", "decls_insts", "decls", "decl",
  "insts", "inst", "block", "exprs", "expr", "lval", "function_def",
  "function_args", "function_arg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -26,   478,    30,   -26,   -66,   -66,   -66,   -66,   -66,   -66,
     -16,   211,   211,   459,    27,   432,   268,    29,   -12,   -66,
     -66,   -11,   -66,   -66,   -66,   -66,    34,    36,   436,    40,
      46,   436,   -66,   -66,   -66,   -66,   -66,   161,    31,   432,
     -66,   457,   -66,   -66,   -66,   -66,   -66,   -16,   -66,   -33,
       0,   -66,   -66,    33,    38,   308,    43,   436,    79,    45,
     432,   436,     4,    26,    84,   436,    47,    -3,   436,   436,
     436,    50,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   259,    -3,
     314,   360,   -66,   -66,   457,   210,   -66,   211,   -66,   -66,
      52,   -66,   -66,   -66,    53,   -66,    55,   -66,    58,   457,
      60,   -66,    62,   -66,   -66,    66,   457,   -66,    69,   436,
     436,    81,    90,   268,   364,   -66,   368,   436,   436,    92,
     436,   436,   436,   436,   436,   436,   372,   376,   436,   436,
     436,    93,   -66,   398,   -66,   424,   -66,   127,   -66,   -66,
     -66,   -66,    94,   -66,   -66,   -66,   428,    95,    96,   -66,
     -66,   -29,   -66,   -66,   -66,    97,    99,   -66,   100,   101,
     102,   103,   104,   106,   -66,   107,   -66,   108,   109,   110,
     111,   -66,   -66,   -66,   112,   -66,   -66,   -66,   113,   -66,
     -66,   211,   432,   -20,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
      73,   114,   432,   -66,   115,   -66,   124,   -66,   -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     3,     7,     4,    14,    17,    18,    19,
       0,     0,     0,     0,     0,    35,     0,     0,    15,    20,
      21,    16,     1,     6,     2,    30,     0,     0,     0,     0,
       0,     0,    59,    60,    90,    61,    62,     0,     0,    33,
      37,    34,    42,    55,    43,    82,    89,    25,    24,     0,
       0,    28,    29,     0,     0,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    36,    32,     0,    41,     0,    22,    38,
       0,     8,     9,    13,     0,    10,     0,    40,     0,     0,
       0,    47,     0,    49,    51,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,     0,    88,     0,    27,     0,    39,    12,
      11,    56,     0,    46,    48,    50,     0,     0,     0,    80,
      81,     0,    44,    57,    45,     0,     0,    66,     0,     0,
       0,     0,     0,     0,    65,     0,    64,     0,     0,     0,
       0,    84,    85,    87,     0,    26,    54,    52,     0,    83,
      91,     0,    35,     0,    95,    78,    79,    74,    75,    77,
      76,    73,    72,    67,    68,    69,    70,    71,    23,    53,
       0,     0,    35,    94,     0,    92,     0,    96,    93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   170,    -1,   -66,   -66,   -25,   -66,   -66,
     -66,   204,   -59,   -66,    17,   171,   -17,   -66,   -65,   -15,
     -58,   -66,   -66,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    48,    18,    19,    49,   147,    20,
      21,     5,    38,    39,    40,    41,    42,    43,   124,    44,
      45,    46,   193,   194
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      17,   108,    34,    32,    33,    34,    35,   110,   126,   119,
      26,    27,    30,    56,    97,    98,    59,     6,   191,   192,
       6,     1,    91,    36,    96,   143,   145,   191,   212,   112,
      22,   141,    31,    25,    50,   100,    17,    51,    52,    53,
      91,    54,   104,   106,   118,    57,   109,    55,    99,   115,
     116,    58,   111,   120,   121,   122,    93,   125,   125,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    91,   113,   125,   125,    96,   214,    92,
      91,   101,    32,    33,    34,    35,   102,    32,    33,    34,
      35,   103,   152,   107,    68,   117,   146,   123,   161,   156,
     148,   149,    36,   150,   157,   158,   151,    36,   153,   163,
     154,   163,   165,   166,   155,   168,   169,   170,   171,   172,
     173,   175,   177,   178,   179,   180,    55,   105,   163,   159,
     163,    55,   114,   211,     7,     8,     9,    10,   160,   188,
     167,   181,   186,   189,   190,   195,   185,   196,   197,   198,
     199,   200,   201,   216,   202,   203,   204,   205,   206,   207,
     208,   209,   215,   217,    32,    33,    34,    35,     7,     8,
       9,    10,   218,    23,    16,   184,    14,    60,    61,    62,
      63,    64,    65,    66,    36,    67,    68,    69,    70,    71,
     210,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    24,    88,   213,
      94,    89,    90,    32,    33,    34,    35,     0,     7,     8,
       9,    10,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,    66,    36,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,    55,    16,     0,
      89,    90,    32,    33,    34,    35,     7,     8,     9,    47,
       0,     0,     0,     0,     0,     7,     8,     9,    47,     0,
       0,    66,    36,    67,    68,    69,    70,    71,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,    88,     0,     0,    89,
      90,    32,    33,    34,    35,    16,     0,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    36,    67,    68,    69,    70,    71,    36,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,    55,     0,     0,    89,    90,
       0,    55,   142,    32,    33,    34,    35,    32,    33,    34,
      35,    32,    33,    34,    35,    32,    33,    34,    35,    32,
      33,    34,    35,    36,     0,     0,     0,    36,     0,     0,
       0,    36,     0,     0,     0,    36,     0,     0,     0,    36,
       0,    32,    33,    34,    35,     0,     0,    55,   144,     0,
       0,    55,   162,     0,     0,    55,   164,     0,     0,    55,
     174,    36,     0,    55,   176,     0,     0,    32,    33,    34,
      35,    32,    33,    34,    35,    32,    33,    34,    35,    32,
      33,    34,    35,     0,     0,    55,   182,    36,     0,     0,
       0,    36,     0,     0,     0,    36,     0,     0,     0,    36,
      32,    33,    34,    35,    28,     0,     7,     8,     9,    10,
       0,    55,   183,     0,    29,    95,   187,     0,     0,    37,
      36,     0,     0,    55,     0,     7,     8,     9,    10,    11,
      12,    13,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,    16,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16
};

static const yytype_int16 yycheck[] =
{
       1,    60,     5,     3,     4,     5,     6,     3,    73,    67,
      11,    12,    13,    28,    47,    48,    31,     0,    47,    48,
       3,    47,    37,    23,    41,    90,    91,    47,    48,     3,
       0,    89,     5,    49,     5,    50,    37,    49,    49,     5,
      55,     5,    57,    58,    47,     5,    61,    47,    48,    64,
      65,     5,    48,    68,    69,    70,    39,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    48,    90,    91,    94,     5,    48,
      95,    48,     3,     4,     5,     6,    48,     3,     4,     5,
       6,    48,   109,    48,    25,    48,    97,    47,   123,   116,
      48,    48,    23,    48,   119,   120,    48,    23,    48,   124,
      48,   126,   127,   128,    48,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    47,    48,   143,    48,
     145,    47,    48,   192,     7,     8,     9,    10,    48,   156,
      48,    48,    48,    48,    48,    48,   147,    48,    48,    48,
      48,    48,    48,   212,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,     3,     4,     5,     6,     7,     8,
       9,    10,    48,     3,    47,    48,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     191,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     3,    47,   193,
      39,    50,    51,     3,     4,     5,     6,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    47,    47,    -1,
      50,    51,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,     7,     8,     9,    10,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    47,    -1,    -1,    50,
      51,     3,     4,     5,     6,    47,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    23,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    -1,    50,    51,
      -1,    47,    48,     3,     4,     5,     6,     3,     4,     5,
       6,     3,     4,     5,     6,     3,     4,     5,     6,     3,
       4,     5,     6,    23,    -1,    -1,    -1,    23,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    23,    -1,    -1,    -1,    23,
      -1,     3,     4,     5,     6,    -1,    -1,    47,    48,    -1,
      -1,    47,    48,    -1,    -1,    47,    48,    -1,    -1,    47,
      48,    23,    -1,    47,    48,    -1,    -1,     3,     4,     5,
       6,     3,     4,     5,     6,     3,     4,     5,     6,     3,
       4,     5,     6,    -1,    -1,    47,    48,    23,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    23,    -1,    -1,    -1,    23,
       3,     4,     5,     6,     5,    -1,     7,     8,     9,    10,
      -1,    47,    48,    -1,    15,    47,    48,    -1,    -1,    47,
      23,    -1,    -1,    47,    -1,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    47,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    53,    54,    55,    63,    66,     7,     8,     9,
      10,    11,    12,    13,    15,    29,    47,    56,    57,    58,
      61,    62,     0,    55,    63,    49,    56,    56,     5,    15,
      56,     5,     3,     4,     5,     6,    23,    47,    64,    65,
      66,    67,    68,    69,    71,    72,    73,    10,    56,    59,
       5,    49,    49,     5,     5,    47,    71,     5,     5,    71,
      16,    17,    18,    19,    20,    21,    22,    24,    25,    26,
      27,    28,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    47,    50,
      51,    71,    48,    66,    67,    47,    68,    47,    48,    48,
      71,    48,    48,    48,    71,    48,    71,    48,    64,    71,
       3,    48,     3,    48,    48,    71,    71,    48,    47,    72,
      71,    71,    71,    47,    70,    71,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    48,    70,    48,    70,    56,    60,    48,    48,
      48,    48,    68,    48,    48,    48,    68,    71,    71,    48,
      48,    59,    48,    71,    48,    71,    71,    48,    71,    71,
      71,    71,    71,    71,    48,    71,    48,    71,    71,    71,
      71,    48,    48,    48,    48,    56,    48,    48,    68,    48,
      48,    47,    48,    74,    75,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      56,    64,    48,    75,     5,    48,    64,    48,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    54,    54,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    60,    60,    61,    62,
      62,    63,    64,    64,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     2,     1,     5,     5,
       5,     6,     6,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     6,     1,     1,     2,     1,     2,     2,
       2,     4,     2,     1,     1,     0,     2,     1,     4,     5,
       5,     2,     1,     1,     4,     4,     4,     3,     4,     3,
       4,     3,     5,     6,     5,     1,     4,     2,     1,     1,
       1,     1,     1,     3,     4,     4,     4,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       4,     4,     1,     5,     4,     4,     3,     4,     3,     1,
       1,     5,     7,     8,     2,     1,     4
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
        yyerror (compiler, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (compiler);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, compiler);
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
                 int yyrule, std::shared_ptr<cdk::compiler> compiler)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YY_USE (yyvaluep);
  YY_USE (compiler);
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
yyparse (std::shared_ptr<cdk::compiler> compiler)
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
  case 2: /* file: fdecls program  */
#line 71 "til_parser.y"
                          { compiler ->ast(new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence))); }
#line 1353 "til_parser.tab.c"
    break;

  case 3: /* file: fdecls  */
#line 72 "til_parser.y"
                          { compiler ->ast((yyvsp[0].sequence)); }
#line 1359 "til_parser.tab.c"
    break;

  case 4: /* file: program  */
#line 73 "til_parser.y"
                          { compiler ->ast(new cdk::sequence_node(LINE, (yyvsp[0].node))); }
#line 1365 "til_parser.tab.c"
    break;

  case 5: /* file: %empty  */
#line 74 "til_parser.y"
                          { compiler ->ast(new cdk::sequence_node(LINE)); }
#line 1371 "til_parser.tab.c"
    break;

  case 6: /* fdecls: fdecls fdecl  */
#line 77 "til_parser.y"
                          { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1377 "til_parser.tab.c"
    break;

  case 7: /* fdecls: fdecl  */
#line 78 "til_parser.y"
                          { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1383 "til_parser.tab.c"
    break;

  case 8: /* fdecl: '(' tEXTERNAL type tIDENTIFIER ')'  */
#line 81 "til_parser.y"
                                                             { (yyval.node) = new til::declaration_node(LINE, tEXTERNAL, (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); delete (yyvsp[-1].s); }
#line 1389 "til_parser.tab.c"
    break;

  case 9: /* fdecl: '(' tFORWARD type tIDENTIFIER ')'  */
#line 82 "til_parser.y"
                                                             { (yyval.node) = new til::declaration_node(LINE, tEXTERNAL, (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); delete (yyvsp[-1].s); }
#line 1395 "til_parser.tab.c"
    break;

  case 10: /* fdecl: '(' tPUBLIC type tIDENTIFIER ')'  */
#line 83 "til_parser.y"
                                                             { (yyval.node) = new til::declaration_node(LINE, tPUBLIC, (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); delete (yyvsp[-1].s); }
#line 1401 "til_parser.tab.c"
    break;

  case 11: /* fdecl: '(' tPUBLIC type tIDENTIFIER expr ')'  */
#line 84 "til_parser.y"
                                                             { (yyval.node) = new til::declaration_node(LINE, tPUBLIC, (yyvsp[-3].type), *(yyvsp[-2].s), (yyvsp[-1].expression)); delete (yyvsp[-2].s); }
#line 1407 "til_parser.tab.c"
    break;

  case 12: /* fdecl: '(' tPUBLIC tVAR tIDENTIFIER expr ')'  */
#line 85 "til_parser.y"
                                                             { (yyval.node) = new til::declaration_node(LINE, tPUBLIC, nullptr, *(yyvsp[-2].s), (yyvsp[-1].expression)); delete (yyvsp[-2].s); }
#line 1413 "til_parser.tab.c"
    break;

  case 13: /* fdecl: '(' tPUBLIC tIDENTIFIER expr ')'  */
#line 86 "til_parser.y"
                                                             { (yyval.node) = new til::declaration_node(LINE, tPUBLIC, nullptr, *(yyvsp[-2].s), (yyvsp[-1].expression)); delete (yyvsp[-2].s); }
#line 1419 "til_parser.tab.c"
    break;

  case 14: /* fdecl: decl  */
#line 87 "til_parser.y"
                                                             { (yyval.node) = (yyvsp[0].node); }
#line 1425 "til_parser.tab.c"
    break;

  case 15: /* type: referable_type  */
#line 90 "til_parser.y"
                                { (yyval.type) = (yyvsp[0].type); }
#line 1431 "til_parser.tab.c"
    break;

  case 16: /* type: ref_type_void  */
#line 91 "til_parser.y"
                                { (yyval.type) = (yyvsp[0].type); }
#line 1437 "til_parser.tab.c"
    break;

  case 17: /* referable_type: tTYPE_INT  */
#line 94 "til_parser.y"
                                        { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT); }
#line 1443 "til_parser.tab.c"
    break;

  case 18: /* referable_type: tTYPE_DOUBLE  */
#line 95 "til_parser.y"
                                        { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
#line 1449 "til_parser.tab.c"
    break;

  case 19: /* referable_type: tTYPE_STRING  */
#line 96 "til_parser.y"
                                        { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
#line 1455 "til_parser.tab.c"
    break;

  case 20: /* referable_type: function_type  */
#line 97 "til_parser.y"
                                        { (yyval.type) = (yyvsp[0].type); }
#line 1461 "til_parser.tab.c"
    break;

  case 21: /* referable_type: ref_type  */
#line 98 "til_parser.y"
                                        { (yyval.type) = (yyvsp[0].type); }
#line 1467 "til_parser.tab.c"
    break;

  case 22: /* function_type: '(' function_return_type ')'  */
#line 101 "til_parser.y"
                                                              { (yyval.type) = cdk::functional_type::create((yyvsp[-1].type)); }
#line 1473 "til_parser.tab.c"
    break;

  case 23: /* function_type: '(' function_return_type '(' types ')' ')'  */
#line 102 "til_parser.y"
                                                              { (yyval.type) = cdk::functional_type::create(*(yyvsp[-2].type_vector), (yyvsp[-4].type)); delete (yyvsp[-2].type_vector); }
#line 1479 "til_parser.tab.c"
    break;

  case 24: /* function_return_type: type  */
#line 105 "til_parser.y"
                                           { (yyval.type) = (yyvsp[0].type); }
#line 1485 "til_parser.tab.c"
    break;

  case 25: /* function_return_type: tTYPE_VOID  */
#line 106 "til_parser.y"
                                           { (yyval.type) = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
#line 1491 "til_parser.tab.c"
    break;

  case 26: /* types: types type  */
#line 109 "til_parser.y"
                                        { (yyval.type_vector) = (yyvsp[-1].type_vector); (yyval.type_vector)->push_back((yyvsp[0].type)); }
#line 1497 "til_parser.tab.c"
    break;

  case 27: /* types: type  */
#line 110 "til_parser.y"
                                        { (yyval.type_vector) = new std::vector<std::shared_ptr<cdk::basic_type>>(1, (yyvsp[0].type)); }
#line 1503 "til_parser.tab.c"
    break;

  case 28: /* ref_type: referable_type '!'  */
#line 113 "til_parser.y"
                                        { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1509 "til_parser.tab.c"
    break;

  case 29: /* ref_type_void: ref_type_void '!'  */
#line 117 "til_parser.y"
                                        { (yyval.type) = (yyvsp[-1].type); }
#line 1515 "til_parser.tab.c"
    break;

  case 30: /* ref_type_void: tTYPE_VOID '!'  */
#line 118 "til_parser.y"
                                        { (yyval.type) = cdk::reference_type::create(4, cdk::primitive_type::create(0, cdk::TYPE_VOID));}
#line 1521 "til_parser.tab.c"
    break;

  case 31: /* program: '(' tPROGRAM decls_insts ')'  */
#line 121 "til_parser.y"
                                                { (yyval.node) = new til::function_node(LINE, (yyvsp[-1].block)); }
#line 1527 "til_parser.tab.c"
    break;

  case 32: /* decls_insts: decls insts  */
#line 124 "til_parser.y"
                                        { (yyval.block) = new til::block_node(LINE, (yyvsp[-1].sequence), (yyvsp[0].sequence)); }
#line 1533 "til_parser.tab.c"
    break;

  case 33: /* decls_insts: decls  */
#line 125 "til_parser.y"
                                        { (yyval.block) = new til::block_node(LINE, (yyvsp[0].sequence), new cdk::sequence_node(LINE)); }
#line 1539 "til_parser.tab.c"
    break;

  case 34: /* decls_insts: insts  */
#line 126 "til_parser.y"
                                        { (yyval.block) = new til::block_node(LINE, new cdk::sequence_node(LINE), (yyvsp[0].sequence)); }
#line 1545 "til_parser.tab.c"
    break;

  case 35: /* decls_insts: %empty  */
#line 127 "til_parser.y"
                                        { (yyval.block) = new til::block_node(LINE, new cdk::sequence_node(LINE), new cdk::sequence_node(LINE)); }
#line 1551 "til_parser.tab.c"
    break;

  case 36: /* decls: decls decl  */
#line 130 "til_parser.y"
                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1557 "til_parser.tab.c"
    break;

  case 37: /* decls: decl  */
#line 131 "til_parser.y"
                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1563 "til_parser.tab.c"
    break;

  case 38: /* decl: '(' type tIDENTIFIER ')'  */
#line 134 "til_parser.y"
                                                 { (yyval.node) = new til::declaration_node(LINE, tPRIVATE, (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); delete (yyvsp[-1].s); }
#line 1569 "til_parser.tab.c"
    break;

  case 39: /* decl: '(' type tIDENTIFIER expr ')'  */
#line 135 "til_parser.y"
                                                 { (yyval.node) = new til::declaration_node(LINE, tPRIVATE, (yyvsp[-3].type), *(yyvsp[-2].s), (yyvsp[-1].expression)); delete (yyvsp[-2].s); }
#line 1575 "til_parser.tab.c"
    break;

  case 40: /* decl: '(' tVAR tIDENTIFIER expr ')'  */
#line 136 "til_parser.y"
                                                 { (yyval.node) = new til::declaration_node(LINE, tPRIVATE, nullptr, *(yyvsp[-2].s), (yyvsp[-1].expression)); delete (yyvsp[-2].s); }
#line 1581 "til_parser.tab.c"
    break;

  case 41: /* insts: insts inst  */
#line 139 "til_parser.y"
                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1587 "til_parser.tab.c"
    break;

  case 42: /* insts: inst  */
#line 140 "til_parser.y"
                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1593 "til_parser.tab.c"
    break;

  case 43: /* inst: expr  */
#line 143 "til_parser.y"
                                                        { (yyval.node) = new til::evaluation_node(LINE, (yyvsp[0].expression)); }
#line 1599 "til_parser.tab.c"
    break;

  case 44: /* inst: '(' tPRINT exprs ')'  */
#line 144 "til_parser.y"
                                                        { (yyval.node) = new til::print_node(LINE, (yyvsp[-1].sequence), false); }
#line 1605 "til_parser.tab.c"
    break;

  case 45: /* inst: '(' tPRINTLN exprs ')'  */
#line 145 "til_parser.y"
                                                        { (yyval.node) = new til::print_node(LINE, (yyvsp[-1].sequence), true); }
#line 1611 "til_parser.tab.c"
    break;

  case 46: /* inst: '(' tSTOP tINTEGER ')'  */
#line 146 "til_parser.y"
                                                        { (yyval.node) = new til::stop_node(LINE, (yyvsp[-1].i)); }
#line 1617 "til_parser.tab.c"
    break;

  case 47: /* inst: '(' tSTOP ')'  */
#line 147 "til_parser.y"
                                                        { (yyval.node) = new til::stop_node(LINE, 1); }
#line 1623 "til_parser.tab.c"
    break;

  case 48: /* inst: '(' tNEXT tINTEGER ')'  */
#line 148 "til_parser.y"
                                                        { (yyval.node) = new til::next_node(LINE, (yyvsp[-1].i)); }
#line 1629 "til_parser.tab.c"
    break;

  case 49: /* inst: '(' tNEXT ')'  */
#line 149 "til_parser.y"
                                                        { (yyval.node) = new til::next_node(LINE, 1); }
#line 1635 "til_parser.tab.c"
    break;

  case 50: /* inst: '(' tRETURN expr ')'  */
#line 150 "til_parser.y"
                                                        { (yyval.node) = new til::return_node(LINE, (yyvsp[-1].expression)); }
#line 1641 "til_parser.tab.c"
    break;

  case 51: /* inst: '(' tRETURN ')'  */
#line 151 "til_parser.y"
                                                        { (yyval.node) = new til::return_node(LINE, nullptr); }
#line 1647 "til_parser.tab.c"
    break;

  case 52: /* inst: '(' tIF expr inst ')'  */
#line 152 "til_parser.y"
                                                        { (yyval.node) = new til::if_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].node)); }
#line 1653 "til_parser.tab.c"
    break;

  case 53: /* inst: '(' tIF expr inst inst ')'  */
#line 153 "til_parser.y"
                                                        { (yyval.node) = new til::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1659 "til_parser.tab.c"
    break;

  case 54: /* inst: '(' tLOOP expr inst ')'  */
#line 154 "til_parser.y"
                                                        { (yyval.node) = new til::loop_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].node)); }
#line 1665 "til_parser.tab.c"
    break;

  case 55: /* inst: block  */
#line 155 "til_parser.y"
                                                        { (yyval.node) = (yyvsp[0].block); }
#line 1671 "til_parser.tab.c"
    break;

  case 56: /* block: '(' tBLOCK decls_insts ')'  */
#line 159 "til_parser.y"
                                                        { (yyval.block) = (yyvsp[-1].block); }
#line 1677 "til_parser.tab.c"
    break;

  case 57: /* exprs: exprs expr  */
#line 162 "til_parser.y"
                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-1].sequence)); }
#line 1683 "til_parser.tab.c"
    break;

  case 58: /* exprs: expr  */
#line 163 "til_parser.y"
                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression)); }
#line 1689 "til_parser.tab.c"
    break;

  case 59: /* expr: tINTEGER  */
#line 166 "til_parser.y"
                                                { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 1695 "til_parser.tab.c"
    break;

  case 60: /* expr: tDOUBLE  */
#line 167 "til_parser.y"
                                                { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d));  }
#line 1701 "til_parser.tab.c"
    break;

  case 61: /* expr: tSTRING  */
#line 168 "til_parser.y"
                                                { (yyval.expression) = new cdk::string_node(LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1707 "til_parser.tab.c"
    break;

  case 62: /* expr: tNULL  */
#line 169 "til_parser.y"
                                                { (yyval.expression) = new til::null_node(LINE); }
#line 1713 "til_parser.tab.c"
    break;

  case 63: /* expr: '(' tREAD ')'  */
#line 170 "til_parser.y"
                                                { (yyval.expression) = new til::read_node(LINE); }
#line 1719 "til_parser.tab.c"
    break;

  case 64: /* expr: '(' '-' expr ')'  */
#line 171 "til_parser.y"
                                                { (yyval.expression) = new cdk::unary_minus_node(LINE, (yyvsp[-1].expression)); }
#line 1725 "til_parser.tab.c"
    break;

  case 65: /* expr: '(' '+' expr ')'  */
#line 172 "til_parser.y"
                                                { (yyval.expression) = new cdk::unary_plus_node(LINE, (yyvsp[-1].expression)); }
#line 1731 "til_parser.tab.c"
    break;

  case 66: /* expr: '(' '~' expr ')'  */
#line 173 "til_parser.y"
                                                { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[-1].expression)); }
#line 1737 "til_parser.tab.c"
    break;

  case 67: /* expr: '(' '+' expr expr ')'  */
#line 174 "til_parser.y"
                                                { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1743 "til_parser.tab.c"
    break;

  case 68: /* expr: '(' '-' expr expr ')'  */
#line 175 "til_parser.y"
                                                { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1749 "til_parser.tab.c"
    break;

  case 69: /* expr: '(' '*' expr expr ')'  */
#line 176 "til_parser.y"
                                                { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1755 "til_parser.tab.c"
    break;

  case 70: /* expr: '(' '/' expr expr ')'  */
#line 177 "til_parser.y"
                                                { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1761 "til_parser.tab.c"
    break;

  case 71: /* expr: '(' '%' expr expr ')'  */
#line 178 "til_parser.y"
                                                { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1767 "til_parser.tab.c"
    break;

  case 72: /* expr: '(' '<' expr expr ')'  */
#line 179 "til_parser.y"
                                                { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1773 "til_parser.tab.c"
    break;

  case 73: /* expr: '(' '>' expr expr ')'  */
#line 180 "til_parser.y"
                                                { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1779 "til_parser.tab.c"
    break;

  case 74: /* expr: '(' tGE expr expr ')'  */
#line 181 "til_parser.y"
                                                { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1785 "til_parser.tab.c"
    break;

  case 75: /* expr: '(' tLE expr expr ')'  */
#line 182 "til_parser.y"
                                                { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1791 "til_parser.tab.c"
    break;

  case 76: /* expr: '(' tNE expr expr ')'  */
#line 183 "til_parser.y"
                                                { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1797 "til_parser.tab.c"
    break;

  case 77: /* expr: '(' tEQ expr expr ')'  */
#line 184 "til_parser.y"
                                                { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1803 "til_parser.tab.c"
    break;

  case 78: /* expr: '(' tAND expr expr ')'  */
#line 185 "til_parser.y"
                                                { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1809 "til_parser.tab.c"
    break;

  case 79: /* expr: '(' tOR expr expr ')'  */
#line 186 "til_parser.y"
                                                { (yyval.expression) = new cdk::or_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1815 "til_parser.tab.c"
    break;

  case 80: /* expr: '(' tOBJECTS expr ')'  */
#line 187 "til_parser.y"
                                                { (yyval.expression) = new til::alloc_node(LINE, (yyvsp[-1].expression)); }
#line 1821 "til_parser.tab.c"
    break;

  case 81: /* expr: '(' tSIZEOF expr ')'  */
#line 188 "til_parser.y"
                                                { (yyval.expression) = new til::sizeof_node(LINE, (yyvsp[-1].expression)); }
#line 1827 "til_parser.tab.c"
    break;

  case 82: /* expr: lval  */
#line 189 "til_parser.y"
                                                { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 1833 "til_parser.tab.c"
    break;

  case 83: /* expr: '(' tSET lval expr ')'  */
#line 190 "til_parser.y"
                                                { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[-1].expression)); }
#line 1839 "til_parser.tab.c"
    break;

  case 84: /* expr: '(' '?' lval ')'  */
#line 191 "til_parser.y"
                                                { (yyval.expression) = new til::address_node(LINE, (yyvsp[-1].lvalue)); }
#line 1845 "til_parser.tab.c"
    break;

  case 85: /* expr: '(' '@' exprs ')'  */
#line 192 "til_parser.y"
                                                { (yyval.expression) = new til::function_call_node(LINE, nullptr, (yyvsp[-1].sequence)); }
#line 1851 "til_parser.tab.c"
    break;

  case 86: /* expr: '(' '@' ')'  */
#line 193 "til_parser.y"
                                                { (yyval.expression) = new til::function_call_node(LINE, nullptr, new cdk::sequence_node(LINE)); }
#line 1857 "til_parser.tab.c"
    break;

  case 87: /* expr: '(' expr exprs ')'  */
#line 194 "til_parser.y"
                                                { (yyval.expression) = new til::function_call_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].sequence)); }
#line 1863 "til_parser.tab.c"
    break;

  case 88: /* expr: '(' expr ')'  */
#line 195 "til_parser.y"
                                                { (yyval.expression) = new til::function_call_node(LINE, (yyvsp[-1].expression), new cdk::sequence_node(LINE)); }
#line 1869 "til_parser.tab.c"
    break;

  case 89: /* expr: function_def  */
#line 196 "til_parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 1875 "til_parser.tab.c"
    break;

  case 90: /* lval: tIDENTIFIER  */
#line 199 "til_parser.y"
                                    { (yyval.lvalue) = new cdk::variable_node(LINE, (yyvsp[0].s)); }
#line 1881 "til_parser.tab.c"
    break;

  case 91: /* lval: '(' tINDEX expr expr ')'  */
#line 200 "til_parser.y"
                                    { (yyval.lvalue) = new til::pointer_index_node(LINE, (yyvsp[-2].expression), (yyvsp[-1].expression)); }
#line 1887 "til_parser.tab.c"
    break;

  case 92: /* function_def: '(' tFUNCTION '(' function_return_type ')' decls_insts ')'  */
#line 204 "til_parser.y"
                                                                                                { (yyval.expression) = new til::function_node(LINE, new cdk::sequence_node(LINE), (yyvsp[-3].type), (yyvsp[-1].block)); }
#line 1893 "til_parser.tab.c"
    break;

  case 93: /* function_def: '(' tFUNCTION '(' function_return_type function_args ')' decls_insts ')'  */
#line 205 "til_parser.y"
                                                                                                { (yyval.expression) = new til::function_node(LINE, (yyvsp[-3].sequence), (yyvsp[-4].type), (yyvsp[-1].block)); }
#line 1899 "til_parser.tab.c"
    break;

  case 94: /* function_args: function_args function_arg  */
#line 208 "til_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1905 "til_parser.tab.c"
    break;

  case 95: /* function_args: function_arg  */
#line 209 "til_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1911 "til_parser.tab.c"
    break;

  case 96: /* function_arg: '(' type tIDENTIFIER ')'  */
#line 212 "til_parser.y"
                                                  { (yyval.node) = new til::declaration_node(LINE, tPRIVATE, (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); delete (yyvsp[-1].s); }
#line 1917 "til_parser.tab.c"
    break;


#line 1921 "til_parser.tab.c"

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
      yyerror (compiler, YY_("syntax error"));
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
                      yytoken, &yylval, compiler);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, compiler);
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
  yyerror (compiler, YY_("memory exhausted"));
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
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 215 "til_parser.y"

