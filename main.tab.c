
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
#line 1 "main.y"

    // USE THIS FOR TEXT FILES: Get-Content input.txt | .\a.exe
    #include <stdio.h>     
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    void yyerror (char *);       
    int yylex(void);
    void printSymbolTable();
    extern int line;
    #define SHOW_SEMANTIC_ERROR 1
    #define TYPE_MISMATCH 1
    #define UNDECLARED 2
    #define UNINITIALIZED 3
    #define UNUSED 4
    #define REDECLARED 5
    #define CONSTANT 6
    #define OUT_OF_SCOPE 7
    #define CONSTANT_IF 8
    void semanticError(int semanticErr,char c){
        int errLine=line;
        switch(semanticErr){
            case TYPE_MISMATCH:
                printf("Semanic Error: Type mismatch at line %d\n",errLine);
                break;
            case UNDECLARED:
                printf("Semanic Error: Variable %c undeclared at line %d\n",c,errLine);
                break;
            case UNINITIALIZED:
                printf("Semanic Error: Variable %c uninitialized at line %d\n",c,errLine);
                break;
            case UNUSED:
                printf("Warning: Variable %c declared but not used at line %d\n",c,errLine);
                break;
            case REDECLARED:
                printf("Semanic Error: Variable %c redeclared at line %d\n",c,errLine);
                break;
            case CONSTANT:
                printf("Semanic Error: Variable %c is constant at line %d\n",c,errLine);
                break;
            case OUT_OF_SCOPE:
                printf("Semanic Error: Variable %c is out of scope at line %d\n",c,errLine);
                break;
            case CONSTANT_IF:
                printf("Semanic Error: Variable %c is constant in if condition at line %d\n",c,errLine);
                break;
            default:
                printf("Semanic Error: Unknown error at line %d\n",errLine);
                break;
        }
        printSymbolTable();
    }

    // Label Stack for quads generation    
    #define MAX_STACK_SIZE 100
    int labelNum = 0;
    int labelStackPointer = -1;
    int labelStack[MAX_STACK_SIZE];
    // End Label Stack for tracking last label
    int endLabelNum = 0;
    int endLabelstackPointer = -1;
    int endLabelStack[MAX_STACK_SIZE];
    // Quad Functions
    void quadJumpFalseLabel(int labelNum);
    void quadJumpEndLabel();
    void quadPopLabel();
    void quadPushEndLabel(int endLabelNum);
    void quadPopEndLabel();
    // nodeType as in section
    struct nodeType{
        char *type;
        int isConst; // 1 if constant 0 if not constant 
        union{
            int intVal;
            float floatVal;
            char* stringVal;
            int boolVal;

        } value;
        
    };
    // Symbol Table
    struct symbol {
        char name;
        char *type;
        union {
                int intVal;
                float floatVal;
                char* stringVal;
                int boolVal;
        }value;
        int isDecl, isConst, isInit, isUsed, scope;
    };
    struct symbol symbol_Table [100]; // 26 for lower case, 26 for upper case
    int sym_table_idx = 0;
    void insert(char name, char* type, int isConst, int isInit, int isUsed, int scope);
    ///////////////////////////////////////////////
    // Scope Table
    int scope_idx = 1;
    int scope_lvl = 1;
    int scopes[100];
    void enterScope();
    void exitScope();
    ///////////////////////////////////////////////
    // Functions
    int argCount = 0;
    struct nodeType* arithmatic(struct nodeType* op1, struct nodeType* op2, char op);
    struct nodeType* createIntNode(int value);
    struct nodeType* doComparison(struct nodeType* op1, struct nodeType*op2, char* op);
    struct nodeType* createNode(char* type);
    void checkSameScope(char name);
    void checkConst(char name);
    void checkOutOfScope(char name);
    void checkConstIF(struct nodeType* node);


/* Line 189 of yacc.c  */
#line 190 "main.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OR = 258,
     AND = 259,
     NEQ = 260,
     EQ = 261,
     NOT = 262,
     INTEGER = 263,
     FLOAT_NUMBER = 264,
     IDENTIFIER = 265,
     CONST = 266,
     RETURN = 267,
     IF = 268,
     ELSE = 269,
     SWITCH = 270,
     CASE = 271,
     DEFAULT = 272,
     TRUE_VAL = 273,
     FALSE_VAL = 274,
     WHILE = 275,
     FOR = 276,
     BREAK = 277,
     INT_DATA_TYPE = 278,
     FLOAT_DATA_TYPE = 279,
     STRING_DATA_TYPE = 280,
     BOOL_DATA_TYPE = 281,
     VOID_DATA_TYPE = 282
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 119 "main.y"

        int TYPE_INT; 
        void* TYPE_VOID;
        char* TYPE_DATA_TYPE;
        struct nodeType* TYPE_NODE;
        char* TYPE_DATA_MODIFIER;
        int TYPE_BOOL;
        float TYPE_FLOAT;
;


/* Line 214 of yacc.c  */
#line 265 "main.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 277 "main.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,    10,     7,    39,     8,     2,    11,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    38,
       2,    32,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
       5,     6,     9,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     6,     7,     9,    11,    12,    15,
      17,    18,    21,    22,    25,    26,    29,    30,    33,    34,
      37,    38,    39,    44,    45,    46,    52,    53,    56,    60,
      64,    68,    72,    74,    75,    76,    77,    78,    79,    80,
      95,    96,    98,    99,   100,   105,   106,   107,   114,   115,
     116,   126,   129,   131,   132,   133,   140,   144,   145,   154,
     155,   156,   170,   172,   174,   176,   179,   181,   185,   186,
     191,   194
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    -1,    58,    -1,    -1,    78,    -1,    80,
      -1,    -1,    43,    58,    -1,    71,    -1,    -1,    27,    45,
      -1,    -1,    28,    46,    -1,    -1,    29,    47,    -1,    -1,
      30,    48,    -1,    -1,    31,    49,    -1,    -1,    -1,    44,
      14,    51,    52,    -1,    -1,    -1,    14,    32,    56,    54,
      55,    -1,    -1,    12,    57,    -1,    56,     7,    56,    -1,
      56,     8,    56,    -1,    56,     6,    56,    -1,    33,    56,
      34,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    33,    56,    59,    60,    34,    35,    61,    62,    86,
      36,    63,    64,    65,    -1,    -1,    66,    -1,    -1,    -1,
      18,    67,    68,    58,    -1,    -1,    -1,    18,    35,    69,
      86,    36,    70,    -1,    -1,    -1,    19,    33,    14,    34,
      72,    35,    73,    74,    36,    -1,    74,    75,    -1,    75,
      -1,    -1,    -1,    20,    76,    56,    37,    77,    56,    -1,
      21,    37,    84,    -1,    -1,    24,    33,    56,    34,    79,
      35,    86,    36,    -1,    -1,    -1,    25,    33,    81,    53,
      38,    82,    56,    38,    53,    34,    35,    86,    36,    -1,
      53,    -1,    56,    -1,    50,    -1,    83,    38,    -1,    42,
      -1,    84,    83,    38,    -1,    -1,    35,    85,    86,    36,
      -1,    84,    42,    -1,    84,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   163,   163,   165,   171,   175,   176,   177,   177,   178,
     184,   184,   185,   185,   186,   186,   187,   187,   188,   188,
     191,   191,   191,   193,   193,   193,   197,   197,   198,   199,
     200,   201,   202,   211,   211,   211,   211,   211,   211,   211,
     213,   213,   214,   214,   214,   215,   215,   215,   218,   218,
     218,   220,   221,   224,   224,   224,   225,   232,   232,   234,
     234,   234,   240,   241,   242,   247,   248,   249,   250,   250,
     251,   255
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OR", "AND", "NEQ", "EQ", "'+'", "'-'",
  "NOT", "'*'", "'/'", "INTEGER", "FLOAT_NUMBER", "IDENTIFIER", "CONST",
  "RETURN", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "TRUE_VAL",
  "FALSE_VAL", "WHILE", "FOR", "BREAK", "INT_DATA_TYPE", "FLOAT_DATA_TYPE",
  "STRING_DATA_TYPE", "BOOL_DATA_TYPE", "VOID_DATA_TYPE", "'='", "'('",
  "')'", "'{'", "'}'", "':'", "';'", "','", "$accept", "program",
  "controlStatement", "$@1", "dataType", "$@2", "$@3", "$@4", "$@5", "$@6",
  "decleration", "$@7", "$@8", "assignment", "$@9", "$@10", "expr", "$@11",
  "ifCondition", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17",
  "elseCondition", "$@18", "$@19", "$@20", "$@21", "$@22", "switchCase",
  "$@23", "$@24", "caseList", "case", "$@25", "$@26", "while", "$@27",
  "forLoop", "$@28", "$@29", "statement", "statements", "$@30",
  "codeBlock", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,    43,    45,   262,
      42,    47,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,    61,    40,    41,   123,   125,    58,    59,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    41,    42,    42,    43,    42,    42,
      45,    44,    46,    44,    47,    44,    48,    44,    49,    44,
      51,    52,    50,    54,    55,    53,    57,    56,    56,    56,
      56,    56,    56,    59,    60,    61,    62,    63,    64,    58,
      66,    65,    67,    68,    65,    69,    70,    65,    72,    73,
      71,    74,    74,    76,    77,    75,    75,    79,    78,    81,
      82,    80,    83,    83,    83,    84,    84,    84,    85,    84,
      84,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     0,     1,     1,     0,     2,     1,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     0,     4,     0,     0,     5,     0,     2,     3,     3,
       3,     3,     1,     0,     0,     0,     0,     0,     0,    14,
       0,     1,     0,     0,     4,     0,     0,     6,     0,     0,
       9,     2,     1,     0,     0,     6,     3,     0,     8,     0,
       0,    13,     1,     1,     1,     2,     1,     3,     0,     4,
       2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     3,     0,     1,    26,    32,     0,    33,
      27,     0,     0,     0,     0,    34,    31,    30,    28,    29,
       0,     0,    35,    36,     7,    32,     0,     0,     0,    10,
      12,    14,    16,    18,    68,    66,     0,     0,    64,    62,
      63,     9,     5,     6,     0,     7,     0,     0,     0,     0,
      59,    11,    13,    15,    17,    19,     7,     8,    20,    65,
      70,     0,    37,    23,     0,     0,     0,     0,    21,    67,
      38,    24,    48,    57,     0,     0,    69,    22,    40,    25,
       0,     0,    60,    42,    39,    41,    49,     7,     0,    45,
      43,     0,     0,     0,     7,     0,    53,     0,     0,    52,
      58,     0,     0,    44,     0,     7,    50,    51,     0,    46,
       0,    56,     0,    47,    54,     7,     0,     0,    55,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    35,    36,    37,    51,    52,    53,    54,    55,
      38,    68,    77,    39,    71,    79,    40,    10,     3,    15,
      20,    23,    24,    70,    78,    84,    85,    90,    95,    94,
     113,    41,    80,    91,    98,    99,   104,   116,    42,    81,
      43,    66,    88,    44,    45,    56,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int8 yypact[] =
{
     -11,   -22,    28,   -60,    15,   -60,   -60,   -60,    15,    24,
     -60,    13,    15,    15,    15,   -60,   -60,    18,   -60,   -60,
     -16,    -2,   -60,   -60,    66,     3,    21,    22,    23,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -11,    35,   -60,   -60,
      24,   -60,   -60,   -60,    14,    46,     0,    15,    37,    15,
     -60,   -60,   -60,   -60,   -60,   -60,    66,   -60,   -60,   -60,
     -60,    25,   -60,    24,    27,    16,    43,    30,   -60,   -60,
     -60,   -60,   -60,   -60,     3,    31,   -60,   -60,    41,   -60,
      48,    51,   -60,    52,   -60,   -60,   -60,    66,    15,   -60,
     -60,    19,    36,     6,    66,   -11,   -60,    44,    17,   -60,
     -60,    43,    53,   -60,    15,    66,   -60,   -60,    54,   -60,
       9,    90,    57,   -60,   -60,    66,    15,    62,    24,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -44,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -59,   -60,   -60,    -4,   -60,   -31,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,     5,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -43,     1,   -60,   -53
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -72
static const yytype_int8 yytable[] =
{
       9,    60,    61,    67,    11,    57,     1,    75,    17,    18,
      19,     4,    12,    13,    14,    12,    13,    14,    21,    12,
      13,    14,    12,    13,    14,    13,    14,     6,     5,     7,
      12,    13,    14,    22,    92,    47,    62,    96,    97,    96,
      97,   102,   108,    63,   101,    65,   114,    16,     8,    58,
      73,    64,    59,   106,    48,    49,    50,    74,     6,    83,
      25,    72,   117,    69,   103,    26,    76,    60,    61,    82,
      27,    28,   100,    29,    30,    31,    32,    33,     6,     8,
      25,   105,   -71,    86,    93,    26,    87,    89,   112,   109,
      27,    28,   115,    29,    30,    31,    32,    33,   119,     8,
     110,    34,     6,   107,    25,     0,   111,    -7,     0,    26,
       0,     0,   118,     0,    27,    28,     0,    29,    30,    31,
      32,    33,     0,     8
};

static const yytype_int8 yycheck[] =
{
       4,    45,    45,    56,     8,    36,    17,    66,    12,    13,
      14,    33,     6,     7,     8,     6,     7,     8,    34,     6,
       7,     8,     6,     7,     8,     7,     8,    12,     0,    14,
       6,     7,     8,    35,    87,    32,    36,    20,    21,    20,
      21,    94,   101,    47,    38,    49,    37,    34,    33,    14,
      34,    14,    38,    36,    33,    33,    33,    14,    12,    18,
      14,    34,   115,    38,    95,    19,    36,   111,   111,    38,
      24,    25,    36,    27,    28,    29,    30,    31,    12,    33,
      14,    37,    36,    35,    88,    19,    35,    35,    34,    36,
      24,    25,    35,    27,    28,    29,    30,    31,    36,    33,
     104,    35,    12,    98,    14,    -1,   105,    17,    -1,    19,
      -1,    -1,   116,    -1,    24,    25,    -1,    27,    28,    29,
      30,    31,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    41,    58,    33,     0,    12,    14,    33,    56,
      57,    56,     6,     7,     8,    59,    34,    56,    56,    56,
      60,    34,    35,    61,    62,    14,    19,    24,    25,    27,
      28,    29,    30,    31,    35,    42,    43,    44,    50,    53,
      56,    71,    78,    80,    83,    84,    86,    32,    33,    33,
      33,    45,    46,    47,    48,    49,    85,    58,    14,    38,
      42,    83,    36,    56,    14,    56,    81,    86,    51,    38,
      63,    54,    34,    34,    14,    53,    36,    52,    64,    55,
      72,    79,    38,    18,    65,    66,    35,    35,    82,    35,
      67,    73,    86,    56,    69,    68,    20,    21,    74,    75,
      36,    38,    86,    58,    76,    37,    36,    75,    53,    36,
      56,    84,    34,    70,    37,    35,    77,    86,    56,    36
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
        case 4:

/* Line 1455 of yacc.c  */
#line 171 "main.y"
    {;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 177 "main.y"
    {quadPushEndLabel(++endLabelNum);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 177 "main.y"
    {quadPopEndLabel();;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 184 "main.y"
    {printf("int data type \n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 184 "main.y"
    { (yyval.TYPE_NODE) = createIntNode(0); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 185 "main.y"
    {printf("float data type \n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 185 "main.y"
    { (yyval.TYPE_NODE) = createNode("float"); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 186 "main.y"
    {printf("string data type \n");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 186 "main.y"
    { (yyval.TYPE_NODE) = createNode("string"); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 187 "main.y"
    {printf("bool data type \n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 187 "main.y"
    { (yyval.TYPE_NODE) = createNode("bool"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 188 "main.y"
    {printf("void data type \n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 188 "main.y"
    { ; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 191 "main.y"
    {checkSameScope((yyvsp[(2) - (2)].TYPE_NODE));  insert((yyvsp[(2) - (2)].TYPE_NODE), (yyvsp[(1) - (2)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 191 "main.y"
    {printf("inside decleration \n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 191 "main.y"
    {printSymbolTable();;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 193 "main.y"
    {printf("inside assignment \n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 193 "main.y"
    {checkOutOfScope((yyvsp[(1) - (4)].TYPE_NODE)); checkConst((yyvsp[(1) - (4)].TYPE_NODE)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 193 "main.y"
    {printSymbolTable();;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 197 "main.y"
    {printf("integer");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 197 "main.y"
    { (yyval.TYPE_NODE) = createIntNode((yyvsp[(1) - (2)].TYPE_INT)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 198 "main.y"
    { (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),'+'); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 199 "main.y"
    { (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),'-');;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 200 "main.y"
    { (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"==");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 201 "main.y"
    {(yyval.TYPE_NODE) = (yyvsp[(2) - (3)].TYPE_NODE);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 202 "main.y"
    {printf("hello identifier  \n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 211 "main.y"
    {checkConstIF((yyvsp[(3) - (3)].TYPE_NODE)); quadJumpFalseLabel(++labelNum);}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 211 "main.y"
    {printf("IF () is detected \n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 211 "main.y"
    {enterScope();;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 211 "main.y"
    {printf("IF (){} is detected \n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 211 "main.y"
    {printf("asdasd");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 211 "main.y"
    {exitScope();quadJumpEndLabel();quadPopLabel();;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 211 "main.y"
    {;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 213 "main.y"
    {printf("inside bare else  \n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 213 "main.y"
    {;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 214 "main.y"
    {;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 214 "main.y"
    {printf("inside else  \n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 214 "main.y"
    {;;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 215 "main.y"
    {enterScope();;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 215 "main.y"
    {exitScope();;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 215 "main.y"
    {printf("else {} detected \n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 218 "main.y"
    {printf("switch case passed  \n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 218 "main.y"
    {enterScope();;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 218 "main.y"
    {exitScope();;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 224 "main.y"
    {printf("before case \n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 224 "main.y"
    {printf("inside case  \n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 225 "main.y"
    {;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 232 "main.y"
    {printf("Found a while loop!\n");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 234 "main.y"
    {printf("for \n");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 234 "main.y"
    {printf("for \n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 240 "main.y"
    {;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 241 "main.y"
    {printf("aloo");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 242 "main.y"
    {;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 247 "main.y"
    {;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 248 "main.y"
    {;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 249 "main.y"
    {;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 250 "main.y"
    {enterScope();;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 250 "main.y"
    {exitScope();;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 251 "main.y"
    {printf("state+controlState");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 255 "main.y"
    {printf("inside code block \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2003 "main.tab.c"
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
#line 267 "main.y"


void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}


// Create Int Node
struct nodeType* createIntNode(int value) {
    struct nodeType* node = malloc(sizeof(struct nodeType));
    node->type = "int";
    node->value.intVal = value;
    return node;
}
// Create Node
struct nodeType* createNode(char* type) {
    struct nodeType* p = malloc(sizeof(struct nodeType));
    p->type = type;
    p->value.intVal = 0;
    return p;
}

// Arithmatic
struct nodeType* arithmatic(struct nodeType* op1, struct nodeType*op2, char op){
    struct nodeType* p = malloc(sizeof(struct nodeType));
    if(strcmp(op1->type, "int") == 0 && strcmp(op2->type, "int") == 0){
        p->type = "int";
        switch(op){
            case '+':
                p->value.intVal = op1->value.intVal + op2->value.intVal;
                break;
            case '-':
                p->value.intVal = op1->value.intVal - op2->value.intVal;
                break;
            case '*':
                p->value.intVal = op1->value.intVal * op2->value.intVal;
                break;
            case '/':
                p->value.intVal = op1->value.intVal / op2->value.intVal;
                break;
            case '%':
                p->value.intVal = op1->value.intVal % op2->value.intVal;
                break;
          
        }
    }
   
    return p;
}

// Comparison
struct nodeType* doComparison(struct nodeType* op1, struct nodeType*op2, char* op){
    printf("Comparing %d %s %d\n", op1->value.intVal, op, op2->value.intVal);
    struct nodeType* p = malloc(sizeof(struct nodeType));
    p->type = "bool";
    if(strcmp(op, "==") == 0){
        p->value.boolVal = op1->value.intVal == op2->value.intVal;
    }
    return p;
}

// Insert the variable in the symbol table
void insert(char name, char* type, int isConst, int isInit, int isUsed, int scope){

    symbol_Table [sym_table_idx].name = name;
    symbol_Table [sym_table_idx].type = type;
    symbol_Table [sym_table_idx].isDecl = 1;
    symbol_Table [sym_table_idx].isConst = isConst;

    symbol_Table [sym_table_idx].isInit = isInit;
    symbol_Table [sym_table_idx].isUsed = isUsed;
    symbol_Table [sym_table_idx].scope = scope;
    ++sym_table_idx;

    printf("SymbolTable() inserted: %c, declared:%d, const:%d, Symbol table idx:%d\n", symbol_Table [sym_table_idx-1].name, symbol_Table [sym_table_idx-1].isDecl, symbol_Table [sym_table_idx-1].isConst, sym_table_idx); 
}
// Enter the scope
void enterScope() {
    scopes[scope_idx] = scope_lvl;
    scope_idx++;
    scope_lvl++;
}
// Exit the scope
void exitScope() {
    scope_idx--;
}
// Check if the variable is declared in the same scope
void checkSameScope(char name) {
    int lvl;
    for(int i=0; i<sym_table_idx ;i++) {
        if(symbol_Table[i].name == name) {
            lvl = symbol_Table[i].scope;
            if(lvl == scopes[scope_idx-1]) {
                 printf("Error: variable %c already declared in the same scope\n", name); 
              
            }
        }
    }
}

// Check if the variable is declared in the same scope
void checkOutOfScope(char name) {
    int lvl;
    for(int i=sym_table_idx-1; i>=0 ;i--) {
        if(symbol_Table[i].name == name) {
            lvl = symbol_Table[i].scope;
            for(int j=scope_idx-1;j>=0;j--) {
                if(lvl == scopes[j]) {
                    return;
                }
            }
        }
    }
    printf("Error: variable %c is out of scope\n", name);

}

// Check if the node is constant or not
void checkConst(char name) {
    for(int i=0; i<sym_table_idx ;i++) {
        if(symbol_Table[i].name == name) {
             for(int j=scope_idx-1;j>=0;j--) {
                if(symbol_Table[i].scope == scopes[j]) {
                    if(symbol_Table[i].isConst == 1) {
                        printf("Error: variable %c is constant\n", name);
                    }
                    else{
                        printf("Variable %c is not constant\n", name);
                        return;
                    }
                }
              }
        }
    }
}
//check if the if conditions is constant or not
void checkConstIF(struct nodeType* node){
    if(node->isConst==1){
        semanticError(CONSTANT_IF, node->value.boolVal !=0);
    }

}

// Print the symbol table
void printSymbolTable() {
    for(int i=0; i<sym_table_idx ;i++) {
        printf("SymbolTable() : %c, declared:%d, const:%d, Symbol table idx:%d\n", symbol_Table [i].name, symbol_Table [i].isDecl, symbol_Table [i].isConst, i); 
    }
}

////////////////  QUAD GENERATION //////////////////////
// jump to the first false label in the stack
void quadJumpFalseLabel(int labelNum)
{
    printf("Quads(%d) \tJF Label_%d\n", line, labelNum);
    /* push the labelNum to the stack */
    labelStack[labelStackPointer++] = labelNum;
}
// jump to the first end label in the stack
void quadJumpEndLabel()
{
    /* get last  endLabelNum from the stack*/
    int endLabelNum = endLabelStack[endLabelstackPointer];
    printf("Quads(%d) \tJMP EndLabel_%d\n", line, endLabelNum);   
}
// pop the last label from the stack as condition is true
void quadPopLabel(){
    if (labelStackPointer < 0){
            printf("Quads(%d) Error: No end label to add. Segmenration Fault\n", line);
            return;
    }
    /* get the last labelNum from the stack */
    int labelNum = labelStack[--labelStackPointer];
    
    printf("Quads(%d) Label_%d:\n",line, labelNum);
       
}
// push the end label to the stack
void quadPushEndLabel(int endLabelNum)
{
    /* push the labelNum to the stack */
    endLabelStack[++endLabelstackPointer] = endLabelNum;    
}
// pop the last end label from the stack
void quadPopEndLabel(){
    if (endLabelstackPointer < 0){
        printf("Quads(%d) Error: No end label to add. Segmenration Fault\n", line);
        return;
    }
    /* get the last endLabelNum from the stack */
    int endLabelNum = endLabelStack[endLabelstackPointer--];
    
    printf("Quads(%d) EndLabel_%d:\n", line, endLabelNum);
      
}
int main(void) {
    yyparse();
    return 0;
}
