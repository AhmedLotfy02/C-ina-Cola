
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

    /*////////////////////////////////
    TODO: add  typedef  - semanticError 
    ////////////////////////////////*/
    // USE THIS FOR TEXT FILES: Get-Content input.txt | .\a.exe
    #include <stdio.h>     
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    
    void yyerror (char*);       
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
    int enumCounter = 0;
    
    void semanticError(int semanticErr,char* c){
        int errLine = line;
        switch(semanticErr){
            case TYPE_MISMATCH:
                printf("Semanic Error: Type mismatch at line %d\n",errLine);
                break;
            case UNDECLARED:
                printf("Semanic Error: Variable %s undeclared at line %d\n",c,errLine);
                break;
            case UNINITIALIZED:
                printf("Semanic Error: Variable %s uninitialized at line %d\n",c,errLine);
                break;
            case UNUSED:
                printf("Warning: Variable %s declared but not used at line %d\n",c,errLine);
                break;
            case REDECLARED:
                printf("Semanic Error: Variable %s redeclared at line %d\n",c,errLine);
                break;
            case CONSTANT:
                printf("Semanic Error: Variable %s is constant at line %d\n",c,errLine);
                break;
            case OUT_OF_SCOPE:
                printf("Semanic Error: Variable %s is out of scope at line %d\n",c,errLine);
                break;
            case CONSTANT_IF:
                printf("Semanic Error: Variable %s is constant in if condition at line %d\n",c,errLine);
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
    #define SHOW_Quads 1
    void quadJumpFalseLabel(int labelNum);
    void quadJumpEndLabel();
    void quadPopLabel();
    void quadPushEndLabel(int endLabelNum);
    void quadPopEndLabel();
    void quadPushInt(int val);
    
    ////////////////////////////////////////////////////////////////////////
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
        char *name;
        char *type;
        union {
                int intVal;
                float floatVal;
                char* stringVal;
                int boolVal;
        }value;
        int isDecl, isConst, isInit, isUsed, scope;
    };
    struct symbol symbol_Table [100]; //Max number of symbols(Varibles) = 100 
    int sym_table_idx = 0;
    void insert(char* name, char* type, int isConst, int isInit, int isUsed, int scope);
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
    // used to fill enum values
    struct nodeType* enumValues;
    struct nodeType*  printStringValues;
    struct nodeType* arithmatic(struct nodeType* op1, struct nodeType* op2, char* op); 
    struct nodeType* logical(struct nodeType* op1, struct nodeType* op2, char* op); 
    struct nodeType* doComparison(struct nodeType* op1, struct nodeType*op2, char* op); 
    struct nodeType* castingTo(struct nodeType* term, char *type);
    struct nodeType* Negation(struct nodeType* term);     
    struct nodeType* createIntNode(int value);
    struct nodeType* createNode(char* type);
    void identifierNodeTypeCheck(char* name , struct nodeType* node); 
    void nodeNodeTypeCheck(struct nodeType* node1, struct nodeType* node2); 
    void updateIdentifierValue(char* name, struct nodeType* node);
    struct nodeType* identifierValue(char* name);
    void setInit(char* name); 
    void setUsed(char* name); 
    // char* valueString(struct nodeType* node);
    void printNode(struct nodeType* node); 
    void checkInitialized(char* name); 
    void checkSameScope(char* name);
    void checkOutOfScope(char* name);
    void checkConst(char* name);
    void checkConstIF(struct nodeType* node);


/* Line 189 of yacc.c  */
#line 218 "main.tab.c"

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
     LEQ = 262,
     LT = 263,
     GEQ = 264,
     GT = 265,
     NOT = 266,
     INTEGER = 267,
     FLOAT_NUMBER = 268,
     STRING = 269,
     TRUE_VAL = 270,
     FALSE_VAL = 271,
     RETURN = 272,
     ENUM = 273,
     PRINT = 274,
     ASSERT = 275,
     EXIT = 276,
     IF = 277,
     ELSE = 278,
     SWITCH = 279,
     CASE = 280,
     DEFAULT = 281,
     WHILE = 282,
     FOR = 283,
     BREAK = 284,
     CONTINUE = 285,
     REPEAT = 286,
     UNTIL = 287,
     CONST = 288,
     INT_DATA_TYPE = 289,
     FLOAT_DATA_TYPE = 290,
     STRING_DATA_TYPE = 291,
     BOOL_DATA_TYPE = 292,
     VOID_DATA_TYPE = 293,
     IDENTIFIER = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 149 "main.y"

        int TYPE_INT; 
        int TYPE_BOOL;
        float TYPE_FLOAT;
        char* TYPE_STR;
        void* TYPE_VOID;
        char* TYPE_DATA_TYPE;
        struct nodeType* TYPE_NODE;
        char* TYPE_DATA_MODIFIER;
;


/* Line 214 of yacc.c  */
#line 306 "main.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 318 "main.tab.c"

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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   556

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNRULES -- Number of states.  */
#define YYNSTATES  261

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    17,     2,     2,
      46,    47,    15,    12,    53,    13,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    51,
      52,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     8,     9,    10,    11,    14,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    14,    15,    17,
      19,    20,    23,    25,    27,    29,    30,    33,    34,    37,
      38,    41,    42,    45,    46,    49,    50,    51,    56,    57,
      58,    65,    66,    67,    68,    77,    78,    79,    85,    87,
      90,    92,    97,   100,   104,   108,   112,   116,   120,   124,
     128,   132,   136,   140,   144,   148,   152,   155,   159,   160,
     163,   164,   167,   168,   171,   172,   175,   176,   179,   180,
     183,   187,   188,   189,   190,   191,   192,   193,   208,   209,
     211,   212,   213,   218,   219,   220,   227,   228,   229,   239,
     242,   244,   245,   246,   253,   257,   258,   267,   268,   269,
     283,   295,   307,   308,   309,   321,   322,   329,   331,   335,
     339,   345,   348,   353,   355,   359,   361,   363,   365,   367,
     369,   371,   373,   376,   381,   386,   389,   391,   395,   396,
     401,   404,   405,   406,   413,   415,   418,   419,   425,   426,
     427,   436,   440
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      55,     0,    -1,    -1,   125,    -1,   118,    -1,   118,    55,
      -1,   125,    55,    -1,    -1,   104,    -1,   106,    -1,    -1,
      57,    84,    -1,    97,    -1,   109,    -1,    39,    -1,    -1,
      40,    60,    -1,    -1,    41,    61,    -1,    -1,    42,    62,
      -1,    -1,    43,    63,    -1,    -1,    44,    64,    -1,    -1,
      -1,    59,    45,    66,    67,    -1,    -1,    -1,    59,    45,
       3,    76,    68,    69,    -1,    -1,    -1,    -1,    58,    59,
      45,     3,    76,    70,    71,    72,    -1,    -1,    -1,    45,
       3,    76,    74,    75,    -1,   112,    -1,    24,   115,    -1,
      77,    -1,    46,    59,    47,    77,    -1,    13,    77,    -1,
      76,    12,    76,    -1,    76,    13,    76,    -1,    76,    15,
      76,    -1,    76,    16,    76,    -1,    76,    17,    76,    -1,
      76,     7,    76,    -1,    76,     6,    76,    -1,    76,     9,
      76,    -1,    76,    11,    76,    -1,    76,    10,    76,    -1,
      76,     8,    76,    -1,    76,     5,    76,    -1,    76,     4,
      76,    -1,    14,    76,    -1,    46,    76,    47,    -1,    -1,
      18,    78,    -1,    -1,    19,    79,    -1,    -1,    20,    80,
      -1,    -1,    21,    81,    -1,    -1,    22,    82,    -1,    -1,
      45,    83,    -1,    46,    77,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    46,    76,    85,    86,    47,    48,
      87,    88,   122,    49,    89,    90,    91,    -1,    -1,    92,
      -1,    -1,    -1,    29,    93,    94,    84,    -1,    -1,    -1,
      29,    48,    95,   122,    49,    96,    -1,    -1,    -1,    30,
      46,    45,    47,    98,    48,    99,   100,    49,    -1,   100,
     101,    -1,   101,    -1,    -1,    -1,    31,   102,    76,    50,
     103,    76,    -1,    32,    50,   118,    -1,    -1,    33,    46,
      76,    47,   105,    48,   122,    49,    -1,    -1,    -1,    34,
      46,   107,    73,    51,   108,    76,    51,    73,    47,    48,
     122,    49,    -1,    34,    46,    45,    50,    76,    13,    76,
      47,    48,   122,    49,    -1,    34,    46,    45,    50,    76,
      52,    76,    47,    48,   122,    49,    -1,    -1,    -1,    37,
      48,   110,   122,    49,   111,    38,    46,    76,    47,    51,
      -1,    -1,    24,    45,    48,   114,    49,   113,    -1,    45,
      -1,    45,     3,    76,    -1,    45,    53,   114,    -1,    45,
       3,    76,    53,   114,    -1,    45,    45,    -1,    45,    45,
       3,    76,    -1,    76,    -1,   116,    53,    76,    -1,    73,
      -1,    76,    -1,    65,    -1,    27,    -1,    35,    -1,    36,
      -1,    23,    -1,    23,    76,    -1,    25,    46,    76,    47,
      -1,    25,    46,   116,    47,    -1,   117,    51,    -1,    56,
      -1,   118,   117,    51,    -1,    -1,    48,   119,   122,    49,
      -1,   118,    56,    -1,    -1,    -1,   118,    48,   120,   122,
      49,   121,    -1,   118,    -1,    59,    45,    -1,    -1,    59,
      45,   124,    53,   123,    -1,    -1,    -1,    59,    45,   126,
     127,   128,    48,   122,    49,    -1,    46,   123,    47,    -1,
      46,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   215,   215,   218,   219,   220,   221,   222,   226,   227,
     228,   228,   229,   230,   235,   237,   237,   238,   238,   239,
     239,   240,   240,   241,   241,   244,   244,   244,   245,   245,
     245,   246,   246,   246,   246,   251,   251,   251,   252,   253,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   279,   279,
     280,   280,   281,   281,   282,   282,   283,   283,   284,   284,
     285,   294,   294,   294,   294,   294,   294,   294,   296,   296,
     297,   297,   297,   298,   298,   298,   301,   301,   301,   303,
     304,   307,   307,   307,   308,   316,   316,   319,   319,   319,
     320,   321,   325,   325,   325,   331,   331,   335,   336,   337,
     338,   341,   342,   347,   348,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   364,   365,   366,   367,   367,
     368,   369,   369,   369,   374,   379,   380,   380,   382,   382,
     382,   384,   385
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "OR", "AND", "NEQ", "EQ", "LEQ",
  "LT", "GEQ", "GT", "'+'", "'-'", "NOT", "'*'", "'/'", "'%'", "INTEGER",
  "FLOAT_NUMBER", "STRING", "TRUE_VAL", "FALSE_VAL", "RETURN", "ENUM",
  "PRINT", "ASSERT", "EXIT", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT",
  "WHILE", "FOR", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "CONST",
  "INT_DATA_TYPE", "FLOAT_DATA_TYPE", "STRING_DATA_TYPE", "BOOL_DATA_TYPE",
  "VOID_DATA_TYPE", "IDENTIFIER", "'('", "')'", "'{'", "'}'", "':'", "';'",
  "'<'", "','", "$accept", "program", "controlStatement", "$@1",
  "dataModifier", "dataType", "$@2", "$@3", "$@4", "$@5", "$@6",
  "decleration", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "assignment", "$@14", "$@15", "expr", "term", "$@16", "$@17", "$@18",
  "$@19", "$@20", "$@21", "ifCondition", "$@22", "$@23", "$@24", "$@25",
  "$@26", "$@27", "elseCondition", "$@28", "$@29", "$@30", "$@31", "$@32",
  "switchCase", "$@33", "$@34", "caseList", "case", "$@35", "$@36",
  "while", "$@37", "forLoop", "$@38", "$@39", "repeatUntil", "$@40",
  "$@41", "enumDef", "$@42", "enumBody", "enumDeclaration", "printList",
  "statement", "statements", "$@43", "$@44", "$@45", "codeBlock",
  "functionArgs", "$@46", "functionDefinition", "$@47", "$@48",
  "functionDefinitionAfter", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,   258,   259,   260,   261,   262,   263,
     264,   265,    43,    45,   266,    42,    47,    37,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,    40,    41,   123,   125,
      58,    59,    60,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    55,    55,    56,    56,
      57,    56,    56,    56,    58,    60,    59,    61,    59,    62,
      59,    63,    59,    64,    59,    66,    67,    65,    68,    69,
      65,    70,    71,    72,    65,    74,    75,    73,    73,    73,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    78,    77,
      79,    77,    80,    77,    81,    77,    82,    77,    83,    77,
      77,    85,    86,    87,    88,    89,    90,    84,    92,    91,
      93,    94,    91,    95,    96,    91,    98,    99,    97,   100,
     100,   102,   103,   101,   101,   105,   104,   107,   108,   106,
     106,   106,   110,   111,   109,   113,   112,   114,   114,   114,
     114,   115,   115,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   118,   118,   118,   119,   118,
     118,   120,   121,   118,   122,   123,   124,   123,   126,   127,
     125,   128,   128
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     0,     1,     1,
       0,     2,     1,     1,     1,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     0,     4,     0,     0,
       6,     0,     0,     0,     8,     0,     0,     5,     1,     2,
       1,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       3,     0,     0,     0,     0,     0,     0,    14,     0,     1,
       0,     0,     4,     0,     0,     6,     0,     0,     9,     2,
       1,     0,     0,     6,     3,     0,     8,     0,     0,    13,
      11,    11,     0,     0,    11,     0,     6,     1,     3,     3,
       5,     2,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     2,     1,     3,     0,     4,
       2,     0,     0,     6,     1,     2,     0,     5,     0,     0,
       8,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,    58,    60,    62,    64,    66,   121,     0,
       0,   118,     0,     0,     0,   119,   120,     0,    14,    15,
      17,    19,    21,    23,    68,     0,   128,     0,   126,     0,
       0,     0,   117,   115,   116,    40,    12,     8,     9,    13,
      38,     0,     2,     2,    68,     0,    42,    56,    59,    61,
      63,    65,    67,   122,     0,    39,     0,     0,     0,    97,
     102,    16,    18,    20,    22,    24,     0,    69,     0,     0,
      40,    10,     1,     0,    11,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,   128,     5,   126,     0,     6,     0,   111,     0,   113,
       0,     0,     0,     0,     0,    10,    35,     0,    57,    70,
       0,    10,     0,     0,     0,     0,    26,   139,    55,    54,
      49,    48,    53,    50,    52,    51,    43,    44,    45,    46,
      47,    10,   125,     0,   107,     0,   123,   124,     0,    86,
      95,     0,     0,     0,     0,    36,    41,    25,   131,   130,
       0,   129,    71,     0,    28,    27,     0,     0,   112,     0,
       0,   105,   114,     0,     0,     0,    98,   103,    37,   127,
      72,    31,    29,     0,     0,   132,   108,   109,   106,    87,
      10,     0,     0,     0,     0,     0,    32,    30,   142,     0,
       0,    10,   133,     0,     0,     0,    44,     0,     0,     0,
       0,    33,   135,   141,     0,   110,    91,     0,     0,    90,
      96,     0,     0,     0,     0,    73,    34,     0,   140,     0,
      10,    88,    89,    10,    10,     0,     0,    74,     0,     0,
      94,     0,     0,     0,     0,    10,   137,    92,   100,   101,
      10,   104,     0,     0,     0,    75,    93,    99,    76,    78,
      80,    77,    79,    83,    81,    10,     0,     0,    82,    84,
      85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,    28,    29,    30,   110,    61,    62,    63,    64,
      65,    32,   116,   155,   172,   187,   186,   201,   216,    33,
     145,   168,    34,    35,    48,    49,    50,    51,    52,    67,
      74,   170,   185,   227,   235,   248,   249,   251,   252,   254,
     256,   255,   260,    36,   163,   194,   208,   209,   219,   243,
      37,   164,    38,   104,   183,    39,   105,   184,    40,   178,
     135,    55,   100,    41,   111,    71,   131,   192,   112,   190,
     217,    43,   117,   156,   174
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -146
static const yytype_int16 yypact[] =
{
     366,   140,    16,  -146,  -146,  -146,  -146,  -146,    16,   -29,
     -19,  -146,   -14,     6,     9,  -146,  -146,   -20,  -146,  -146,
    -146,  -146,  -146,  -146,    38,   510,  -146,    47,  -146,    35,
     167,    27,  -146,  -146,   529,  -146,  -146,  -146,  -146,  -146,
    -146,    23,   402,   366,  -146,   140,  -146,    43,  -146,  -146,
    -146,  -146,  -146,   529,   -28,  -146,    16,    59,    16,    81,
    -146,  -146,  -146,  -146,  -146,  -146,    16,  -146,    41,   252,
      63,   474,  -146,    84,  -146,    89,     5,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
    -146,  -146,  -146,  -146,    90,  -146,    63,   132,    92,   266,
     -34,    93,   285,    95,    -6,   474,   529,   140,  -146,  -146,
      97,   329,    94,    16,   143,    16,  -146,  -146,   160,   160,
     222,   222,    53,    53,    53,    53,    43,    43,  -146,  -146,
    -146,   474,  -146,    16,     4,    98,  -146,  -146,    16,  -146,
    -146,    16,    38,    99,   103,  -146,  -146,   145,  -146,  -146,
     102,  -146,   529,    16,   529,  -146,   108,   106,   529,    16,
      92,  -146,   529,   115,   130,    86,  -146,  -146,  -146,  -146,
    -146,   529,  -146,    65,   134,  -146,   112,  -146,  -146,  -146,
     474,    16,    16,    16,   118,   136,  -146,  -146,  -146,   139,
     141,   474,  -146,    92,   -10,   138,    -5,   299,   189,   157,
     165,  -146,   161,  -146,   142,  -146,  -146,   166,    18,  -146,
    -146,   170,   171,    -6,    16,  -146,  -146,   162,  -146,    16,
     474,  -146,  -146,   474,   474,   173,   313,  -146,   167,   238,
     438,   172,   175,   174,   176,   474,  -146,  -146,  -146,  -146,
     474,  -146,   177,    16,   179,  -146,   529,  -146,  -146,   196,
     188,  -146,  -146,  -146,  -146,   474,    35,   203,  -146,  -146,
    -146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,   -18,   -40,  -146,  -146,     1,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,   -99,
    -146,  -146,    -2,     8,  -146,  -146,  -146,  -146,  -146,  -146,
     -67,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,    58,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -145,  -146,  -146,   -38,     3,  -146,  -146,  -146,   -91,    52,
    -146,  -146,  -146,  -146,  -146
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -139
static const yytype_int16 yytable[] =
{
      47,    31,    93,    42,    94,   143,    53,   159,   115,    46,
      87,    88,    89,   137,   144,   177,    54,    97,     9,   138,
      98,   206,   207,    69,    92,    95,    68,    56,    60,     1,
       2,    75,    57,    70,     3,     4,     5,     6,     7,   142,
     157,    66,   211,    31,    31,    42,    42,    72,   205,   206,
     207,  -138,    58,    96,    99,    59,   102,   160,    87,    88,
      89,    44,    25,    73,   106,    85,    86,   221,    87,    88,
      89,   149,    76,   150,    90,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   107,   195,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   181,
     204,    87,    88,    89,   101,    19,    20,    21,    22,    23,
     109,   152,   188,   154,   225,   146,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   103,    87,    88,    89,
     113,   158,   231,   232,   114,   133,   162,   134,   182,   165,
     139,   132,   147,   151,   242,   141,   153,   161,   115,   244,
     166,   171,   167,   169,   173,   175,   199,   176,     3,     4,
       5,     6,     7,   179,   257,   193,    79,    80,    81,    82,
      83,    84,    85,    86,   189,    87,    88,    89,   180,   196,
     197,   198,   191,   200,   202,    44,    45,   210,   203,   258,
     149,   218,   150,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,   214,    87,    88,    89,    19,    20,    21,
      22,    23,   226,   215,  -136,   228,   220,   229,   223,   224,
     233,   238,   240,   230,   239,   250,   245,   241,   247,   189,
      81,    82,    83,    84,    85,    86,   253,    87,    88,    89,
     213,   246,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,   259,    87,    88,    89,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   222,    87,    88,    89,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
     236,    87,    88,    89,     0,     0,     0,     0,   237,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   108,
      87,    88,    89,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,   136,    87,    88,    89,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,    87,    88,
      89,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     0,     0,   212,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,    12,
     234,     0,    13,    14,    15,    16,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,   148,  -134,     1,
       2,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,   -10,     0,    12,     0,     0,    13,
      14,    15,    16,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,     1,     2,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
     -10,     0,    12,     0,     0,    13,    14,    15,    16,    17,
       0,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      91,     1,     2,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,   -10,     0,    12,     0,
       0,    13,    14,    15,    16,    17,     0,    18,    19,    20,
      21,    22,    23,    24,    25,     0,   148,     1,     2,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,    12,     0,     0,    13,    14,    15,
      16,    17,     0,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,     1,     2,     0,     0,     0,     3,     4,
       5,     6,     7,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,    87,    88,    89,     0,     0,     0,
      19,    20,    21,    22,    23,    44,    25
};

static const yytype_int16 yycheck[] =
{
       2,     0,    42,     0,    42,   104,     8,     3,     3,     1,
      15,    16,    17,    47,   105,   160,    45,    45,    24,    53,
      48,    31,    32,    25,    42,    43,    25,    46,    48,    13,
      14,    30,    46,    25,    18,    19,    20,    21,    22,    45,
     131,     3,    47,    42,    43,    42,    43,     0,   193,    31,
      32,    46,    46,    45,    56,    46,    58,    53,    15,    16,
      17,    45,    46,    28,    66,    12,    13,    49,    15,    16,
      17,   111,    45,   111,    51,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    47,   180,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
     191,    15,    16,    17,    45,    40,    41,    42,    43,    44,
      47,   113,    47,   115,   213,   107,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    45,    15,    16,    17,
      46,   133,   223,   224,    45,     3,   138,    45,    52,   141,
      47,    51,    45,    49,   235,    50,     3,    49,     3,   240,
      51,   153,    49,    51,    46,    49,    38,   159,    18,    19,
      20,    21,    22,    48,   255,    53,     6,     7,     8,     9,
      10,    11,    12,    13,   173,    15,    16,    17,    48,   181,
     182,   183,    48,    47,    45,    45,    46,    49,    47,   256,
     230,    49,   230,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    46,    15,    16,    17,    40,    41,    42,
      43,    44,   214,    48,    53,    53,    50,   219,    48,    48,
      47,    49,    48,   220,    49,    29,    49,    51,    49,   228,
       8,     9,    10,    11,    12,    13,    48,    15,    16,    17,
      51,   243,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    49,    15,    16,    17,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,   208,    15,    16,    17,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
     228,    15,    16,    17,    -1,    -1,    -1,    -1,    50,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    47,
      15,    16,    17,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    47,    15,    16,    17,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    47,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    30,
      47,    -1,    33,    34,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    13,
      14,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    13,    14,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    -1,    30,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    13,    14,    -1,    -1,    -1,    18,    19,
      20,    21,    22,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    16,    17,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    18,    19,    20,    21,    22,    23,    24,
      25,    27,    30,    33,    34,    35,    36,    37,    39,    40,
      41,    42,    43,    44,    45,    46,    48,    55,    56,    57,
      58,    59,    65,    73,    76,    77,    97,   104,   106,   109,
     112,   117,   118,   125,    45,    46,    77,    76,    78,    79,
      80,    81,    82,    76,    45,   115,    46,    46,    46,    46,
      48,    60,    61,    62,    63,    64,     3,    83,    59,    76,
      77,   119,     0,    28,    84,    59,    45,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    15,    16,    17,
      51,    48,    55,    56,   117,    55,    77,    45,    48,    76,
     116,    45,    76,    45,   107,   110,    76,    47,    47,    47,
      59,   118,   122,    46,    45,     3,    66,   126,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,   120,    51,     3,    45,   114,    47,    47,    53,    47,
      47,    50,    45,    73,   122,    74,    77,    45,    48,    56,
     117,    49,    76,     3,    76,    67,   127,   122,    76,     3,
      53,    49,    76,    98,   105,    76,    51,    49,    75,    51,
      85,    76,    68,    46,   128,    49,    76,   114,   113,    48,
      48,    13,    52,   108,   111,    86,    70,    69,    47,    59,
     123,    48,   121,    53,    99,   122,    76,    76,    76,    38,
      47,    71,    45,    47,   122,   114,    31,    32,   100,   101,
      49,    47,    47,    51,    46,    48,    72,   124,    49,   102,
      50,    49,   101,    48,    48,    73,    76,    87,    53,    76,
     118,   122,   122,    47,    47,    88,   123,    50,    49,    49,
      48,    51,   122,   103,   122,    49,    76,    49,    89,    90,
      29,    91,    92,    48,    93,    95,    94,   122,    84,    49,
      96
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
        case 3:

/* Line 1455 of yacc.c  */
#line 218 "main.y"
    {;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 219 "main.y"
    {printf("hi1");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 220 "main.y"
    {printf("hi2");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 221 "main.y"
    {;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 222 "main.y"
    {;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 228 "main.y"
    {quadPushEndLabel(++endLabelNum);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 228 "main.y"
    {quadPopEndLabel();;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 235 "main.y"
    {;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 237 "main.y"
    {printf("int data type \n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 237 "main.y"
    { (yyval.TYPE_NODE) = createIntNode(0); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 238 "main.y"
    {printf("float data type \n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 238 "main.y"
    { (yyval.TYPE_NODE) = createNode("float"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 239 "main.y"
    {printf("string data type \n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 239 "main.y"
    { (yyval.TYPE_NODE) = createNode("string"); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 240 "main.y"
    {printf("bool data type \n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 240 "main.y"
    { (yyval.TYPE_NODE) = createNode("bool"); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 241 "main.y"
    {printf("void data type \n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 241 "main.y"
    { ; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 244 "main.y"
    {checkSameScope((yyvsp[(2) - (2)].TYPE_STR));  insert((yyvsp[(2) - (2)].TYPE_STR), (yyvsp[(1) - (2)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 244 "main.y"
    {printf("inside decleration \n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 244 "main.y"
    {printSymbolTable();;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 245 "main.y"
    {checkSameScope((yyvsp[(2) - (4)].TYPE_STR));  nodeNodeTypeCheck((yyvsp[(1) - (4)].TYPE_NODE), (yyvsp[(4) - (4)].TYPE_NODE)); insert((yyvsp[(2) - (4)].TYPE_STR), (yyvsp[(1) - (4)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]);  updateIdentifierValue((yyvsp[(2) - (4)].TYPE_STR),(yyvsp[(4) - (4)].TYPE_NODE)); setInit((yyvsp[(2) - (4)].TYPE_STR)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 245 "main.y"
    {printf("inside decleration \n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 245 "main.y"
    {printSymbolTable();;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 246 "main.y"
    {checkSameScope((yyvsp[(3) - (5)].TYPE_STR));  nodeNodeTypeCheck((yyvsp[(2) - (5)].TYPE_NODE), (yyvsp[(5) - (5)].TYPE_NODE)); insert((yyvsp[(3) - (5)].TYPE_STR), (yyvsp[(2) - (5)].TYPE_NODE)->type, 1, 0, 0, scopes[scope_idx-1]);  updateIdentifierValue((yyvsp[(3) - (5)].TYPE_STR),(yyvsp[(5) - (5)].TYPE_NODE)); setInit((yyvsp[(3) - (5)].TYPE_STR)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 246 "main.y"
    {printf("inside decleration \n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 246 "main.y"
    {printSymbolTable();;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 246 "main.y"
    {printSymbolTable();;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 251 "main.y"
    {printf("inside assignment \n"); checkOutOfScope((yyvsp[(1) - (3)].TYPE_STR)); checkConst((yyvsp[(1) - (3)].TYPE_STR)); identifierNodeTypeCheck((yyvsp[(1) - (3)].TYPE_STR), (yyvsp[(3) - (3)].TYPE_NODE)); setInit((yyvsp[(1) - (3)].TYPE_STR)); setUsed((yyvsp[(1) - (3)].TYPE_STR)); updateIdentifierValue((yyvsp[(1) - (3)].TYPE_STR),(yyvsp[(3) - (3)].TYPE_NODE)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 251 "main.y"
    {printSymbolTable();;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 251 "main.y"
    {printf(castingTo((yyvsp[(3) - (5)].TYPE_NODE),"string")->value.stringVal); (yyval.TYPE_NODE) = (yyvsp[(3) - (5)].TYPE_NODE);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 252 "main.y"
    {;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 253 "main.y"
    {/*Check declared*/;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 258 "main.y"
    { (yyval.TYPE_NODE) = (yyvsp[(1) - (1)].TYPE_NODE); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 259 "main.y"
    { (yyval.TYPE_NODE) = castingTo((yyvsp[(4) - (4)].TYPE_NODE), (yyvsp[(2) - (4)].TYPE_NODE)->type);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 260 "main.y"
    { (yyval.TYPE_NODE) = Negation((yyvsp[(2) - (2)].TYPE_NODE)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 261 "main.y"
    { (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"+"); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 262 "main.y"
    { (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"-"); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 263 "main.y"
    { (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"*"); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 264 "main.y"
    { (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"/"); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 265 "main.y"
    { (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"%"); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 266 "main.y"
    { (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"==");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 267 "main.y"
    { (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"!=");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 268 "main.y"
    { (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"<"); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 269 "main.y"
    { (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),">"); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 270 "main.y"
    { (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),">="); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 271 "main.y"
    { (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"<="); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 272 "main.y"
    { (yyval.TYPE_NODE) = logical((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"&"); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 273 "main.y"
    { (yyval.TYPE_NODE) = logical((yyvsp[(1) - (3)].TYPE_NODE),(yyvsp[(3) - (3)].TYPE_NODE),"|"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 274 "main.y"
    { (yyval.TYPE_NODE) = logical((yyvsp[(2) - (2)].TYPE_NODE),NULL,"!"); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 275 "main.y"
    { (yyval.TYPE_NODE) = (yyvsp[(2) - (3)].TYPE_NODE);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 279 "main.y"
    {printf("integer");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 279 "main.y"
    { (yyval.TYPE_NODE) = createIntNode((yyvsp[(1) - (2)].TYPE_INT));    (yyval.TYPE_NODE)->value.intVal = (yyvsp[(1) - (2)].TYPE_INT);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 280 "main.y"
    {printf("float");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 280 "main.y"
    { (yyval.TYPE_NODE) = createNode("float");  (yyval.TYPE_NODE)->value.floatVal = (yyvsp[(1) - (2)].TYPE_FLOAT);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 281 "main.y"
    {printf("string\n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 281 "main.y"
    { (yyval.TYPE_NODE) = createNode("string"); (yyval.TYPE_NODE)->value.stringVal = strdup((yyvsp[(1) - (2)].TYPE_STR));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 282 "main.y"
    {printf("bool\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 282 "main.y"
    { (yyval.TYPE_NODE) = createNode("bool");   (yyval.TYPE_NODE)->value.boolVal = 1;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 283 "main.y"
    {printf("bool\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 283 "main.y"
    { (yyval.TYPE_NODE) = createNode("bool");   (yyval.TYPE_NODE)->value.boolVal = 0;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 284 "main.y"
    {printf("hello identifier  \n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 284 "main.y"
    {checkOutOfScope((yyvsp[(1) - (2)].TYPE_STR)); checkInitialized((yyvsp[(1) - (2)].TYPE_STR)); (yyval.TYPE_NODE) = identifierValue((yyvsp[(1) - (2)].TYPE_STR)); setUsed((yyvsp[(1) - (2)].TYPE_STR));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 285 "main.y"
    { (yyval.TYPE_NODE) = (yyvsp[(2) - (3)].TYPE_NODE); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 294 "main.y"
    {checkConstIF((yyvsp[(3) - (3)].TYPE_NODE)); quadJumpFalseLabel(++labelNum);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 294 "main.y"
    {printf("IF () is detected \n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 294 "main.y"
    {enterScope();;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 294 "main.y"
    {printf("IF (){} is detected \n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 294 "main.y"
    {printf("asdasd");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 294 "main.y"
    {exitScope();quadJumpEndLabel();quadPopLabel();;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 294 "main.y"
    {;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 296 "main.y"
    {printf("inside bare else  \n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 296 "main.y"
    {;;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 297 "main.y"
    {;;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 297 "main.y"
    {printf("inside else  \n");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 297 "main.y"
    {;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 298 "main.y"
    {enterScope();;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 298 "main.y"
    {exitScope();;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 298 "main.y"
    {printf("else {} detected \n");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 301 "main.y"
    {printf("switch case passed  \n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 301 "main.y"
    {enterScope();;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 301 "main.y"
    {exitScope();;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 307 "main.y"
    {printf("before case \n");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 307 "main.y"
    {printf("inside case  \n");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 308 "main.y"
    {;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 316 "main.y"
    {printf("Found a while loop!\n");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 319 "main.y"
    {printf("for \n");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 319 "main.y"
    {printf("for \n");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 325 "main.y"
    {enterScope();;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 325 "main.y"
    {exitScope();;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 325 "main.y"
    {;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 331 "main.y"
    {checkSameScope((yyvsp[(2) - (5)].TYPE_STR)); insert((yyvsp[(2) - (5)].TYPE_STR), "enum", 1, 1, 0, scopes[scope_idx-1]);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 331 "main.y"
    {enumCounter=0;;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 335 "main.y"
    {checkSameScope((yyvsp[(1) - (1)].TYPE_STR)); insert((yyvsp[(1) - (1)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue((yyvsp[(1) - (1)].TYPE_STR),enumValues); enumValues->value.intVal = 0; quadPushInt(++enumCounter);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 336 "main.y"
    {checkSameScope((yyvsp[(1) - (3)].TYPE_STR)); nodeNodeTypeCheck(enumValues,(yyvsp[(3) - (3)].TYPE_NODE)); insert((yyvsp[(1) - (3)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo((yyvsp[(3) - (3)].TYPE_NODE), "int")->value.intVal; updateIdentifierValue((yyvsp[(1) - (3)].TYPE_STR), enumValues);;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 337 "main.y"
    {checkSameScope((yyvsp[(1) - (3)].TYPE_STR)); insert((yyvsp[(1) - (3)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue((yyvsp[(1) - (3)].TYPE_STR), enumValues); enumValues->value.intVal++; quadPushInt(++enumCounter);;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 338 "main.y"
    {checkSameScope((yyvsp[(1) - (5)].TYPE_STR)); nodeNodeTypeCheck(enumValues,(yyvsp[(3) - (5)].TYPE_NODE)); insert((yyvsp[(1) - (5)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo((yyvsp[(3) - (5)].TYPE_NODE), "int")->value.intVal; updateIdentifierValue((yyvsp[(1) - (5)].TYPE_STR), enumValues);;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 341 "main.y"
    {checkOutOfScope((yyvsp[(1) - (2)].TYPE_STR)); identifierNodeTypeCheck((yyvsp[(1) - (2)].TYPE_STR),createNode("enum")); checkSameScope((yyvsp[(2) - (2)].TYPE_STR)); insert((yyvsp[(2) - (2)].TYPE_STR), "int", 0, 0, 0, scopes[scope_idx-1]);;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 342 "main.y"
    {checkOutOfScope((yyvsp[(1) - (4)].TYPE_STR)); identifierNodeTypeCheck((yyvsp[(1) - (4)].TYPE_STR),createNode("enum")); checkSameScope((yyvsp[(2) - (4)].TYPE_STR)); insert((yyvsp[(2) - (4)].TYPE_STR), "int", 0, 1, 0, scopes[scope_idx-1]); nodeNodeTypeCheck((yyvsp[(4) - (4)].TYPE_NODE),createIntNode(0)); updateIdentifierValue((yyvsp[(2) - (4)].TYPE_STR),castingTo((yyvsp[(4) - (4)].TYPE_NODE), "int"));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 348 "main.y"
    {char* str1 = castingTo((yyvsp[(3) - (3)].TYPE_NODE), "string")->value.stringVal; char* str2 = printStringValues->value.stringVal;  strcat(str1, str2); printStringValues->value.stringVal =  str1;;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 350 "main.y"
    {;;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 351 "main.y"
    {printf("aloo\n");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 352 "main.y"
    {;;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 353 "main.y"
    {exit(EXIT_SUCCESS);;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 354 "main.y"
    {;;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 355 "main.y"
    {;;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 356 "main.y"
    {;;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 357 "main.y"
    {(yyval.TYPE_VOID) = (yyvsp[(2) - (2)].TYPE_NODE);;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 358 "main.y"
    {printNode((yyvsp[(3) - (4)].TYPE_NODE));;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 359 "main.y"
    {(yyval.TYPE_VOID) = (yyvsp[(3) - (4)].TYPE_NODE);;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 364 "main.y"
    {;;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 365 "main.y"
    {;;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 366 "main.y"
    {;;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 367 "main.y"
    {enterScope();;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 367 "main.y"
    {exitScope();;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 368 "main.y"
    {printf("state+controlState");;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 369 "main.y"
    {enterScope();;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 369 "main.y"
    {exitScope();;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 369 "main.y"
    {;;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 374 "main.y"
    {printf("inside code block \n");;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 379 "main.y"
    {checkSameScope((yyvsp[(2) - (2)].TYPE_STR)); insert((yyvsp[(2) - (2)].TYPE_STR), (yyvsp[(1) - (2)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]) ; argCount = sym_table_idx-argCount;;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 380 "main.y"
    {checkSameScope((yyvsp[(2) - (2)].TYPE_STR)); insert((yyvsp[(2) - (2)].TYPE_STR), (yyvsp[(1) - (2)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]) ;;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 382 "main.y"
    {checkSameScope((yyvsp[(2) - (2)].TYPE_STR)); insert((yyvsp[(2) - (2)].TYPE_STR), (yyvsp[(1) - (2)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]); argCount = sym_table_idx; enterScope();;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 382 "main.y"
    {printf("here \n");;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 382 "main.y"
    {exitScope();;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 384 "main.y"
    {printf("definitions with params  \n");;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 385 "main.y"
    {printf("definitions without params  \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2712 "main.tab.c"
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
#line 388 "main.y"


void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}


// Create Int Node
struct nodeType* createIntNode(int value) {
    struct nodeType* node = malloc(sizeof(struct nodeType));
    node->type = "int";
    node->isConst = 1;
    node->value.intVal = value;
    return node;
}

// Create String Node

struct nodeType* createStringNode(char* value) {
    struct nodeType* node = malloc(sizeof(struct nodeType));
    node->type = "string";
    node->isConst = 0;
    node->value.stringVal = strdup(value);
}
// Create Node
struct nodeType* createNode(char* type) {
    struct nodeType* p = malloc(sizeof(struct nodeType));
    p->type = type;
    p->isConst = 1;
    p->value.intVal = 0;
    return p;
}

//------------------------------------------------------------------------------- 
// Op functions 
//-------------------------------------------------------------------------------  

struct nodeType* castingTo(struct nodeType* term, char *type){ //TODO: Implement //Log_SEMANTIC_ERROR(TYPE_MISMATCH)
    struct nodeType* casted_ptr = malloc(sizeof(struct nodeType));
    casted_ptr->isConst = term->isConst;
    if(strcmp(type, "int") == 0){   // convert to int
        casted_ptr->type = "int";
        if(strcmp(term->type, "float") == 0){
            casted_ptr->value.intVal = (int)term->value.floatVal;
        }
        else if(strcmp(term->type, "bool") == 0){
            casted_ptr->value.intVal = (int)term->value.boolVal;
        }
        else if(strcmp(term->type, "string") == 0){
            // remove double quotes from start and end of string
            char *str = strdup(term->value.stringVal);
            casted_ptr->value.intVal = atoi(str);
        }
        else{
            /* printf("Invalid type\n"); */
            //Log_SEMANTIC_ERROR(TYPE_MISMATCH, term->type);
        }
    }
    else if(strcmp(type, "float") == 0){  // convert to float
        casted_ptr->type = "float";
        if(strcmp(term->type, "int") == 0){
            casted_ptr->value.floatVal = (float)term->value.intVal;
        }
        else if(strcmp(term->type, "bool") == 0){
            casted_ptr->value.floatVal = (float)term->value.boolVal;
        }
        else if(strcmp(term->type, "string") == 0){
            // remove double quotes from start and end of string
            char *str = strdup(term->value.stringVal);
            casted_ptr->value.floatVal = atof(str);
        }
        else{
            //Log_SEMANTIC_ERROR(TYPE_MISMATCH, term->type);
        }
    }
    else if(strcmp(type, "bool") == 0){  // convert to bool
        casted_ptr->type = "bool";
        if(strcmp(term->type, "int") == 0){
            casted_ptr->value.boolVal = (int)term->value.intVal != 0;
        }
        else if(strcmp(term->type, "float") == 0){
            casted_ptr->value.boolVal = (int)term->value.floatVal !=0 ;
        }
        else if(strcmp(term->type, "string") == 0){
            // remove double quotes from start and end of string
            char *str = strdup(term->value.stringVal);
            if (strcmp("", str) == 0) {//Only EMPTY string
                casted_ptr->value.boolVal = 1;
            }
            else{
                casted_ptr->value.boolVal = 0;
            }
        }
        else{
            //Log_SEMANTIC_ERROR(TYPE_MISMATCH, term->type);
        }
    }
    else if(strcmp(type, "string") == 0){ // convert to string
        casted_ptr->type = "string";
        if(strcmp(term->type, "int") == 0){
            char t[100];
            sprintf(t, "%d", term->value.intVal);
            casted_ptr->value.stringVal = strdup(t);
        }
        else if(strcmp(term->type, "float") == 0){
            char t[100];
            sprintf(t, "%f", term->value.floatVal);
            casted_ptr->value.stringVal = strdup(t);
        }
        else if(strcmp(term->type, "bool") == 0){
            char t[100];
            sprintf(t, "%d", term->value.boolVal);
            casted_ptr->value.stringVal = strdup(t);
        }
        else{
            //Log_SEMANTIC_ERROR(TYPE_MISMATCH, term->type);
        }
    } 
    return casted_ptr;    
}


// Arithmatic
struct nodeType* arithmatic(struct nodeType* op1, struct nodeType*op2, char* op){
    struct nodeType* final_result = malloc(sizeof(struct nodeType));
    final_result->isConst=((op1->isConst)&&(op2->isConst));
    
    if(strcmp(op1->type, "int") == 0){
        if(op2->type == "float"){
            struct nodeType* float_op1 = malloc(sizeof(struct nodeType));
            float_op1 = castingTo(op1,"float");
            final_result->type = "float";
            
            if(strcmp(op, "+") == 0){
                final_result->value.floatVal = float_op1->value.floatVal + op2->value.floatVal;
                }
            else if(strcmp(op, "-") == 0){
                final_result->value.floatVal = float_op1->value.floatVal - op2->value.floatVal;
                }
            else if(strcmp(op, "*") == 0){
                final_result->value.floatVal = float_op1->value.floatVal * op2->value.floatVal;
                }
            else if(strcmp(op, "/") == 0){
                final_result->value.floatVal = float_op1->value.floatVal / op2->value.floatVal;
                }   
               
        }
        else{
            struct nodeType*int_op2 = malloc(sizeof(struct nodeType));
            int_op2 = castingTo(op2,"int");
            final_result->type = "int";
            
            if(strcmp(op, "+") == 0){
                final_result->value.intVal = op1->value.intVal + int_op2->value.intVal;
                }
            else if(strcmp(op, "-") == 0){
                final_result->value.intVal = op1->value.intVal - int_op2->value.intVal;
                }
            else if(strcmp(op, "*") == 0){
                final_result->value.intVal = op1->value.intVal * int_op2->value.intVal;
                }
            else if(strcmp(op, "/") == 0){
                final_result->value.intVal = op1->value.intVal / int_op2->value.intVal;
                }  
            else if(strcmp(op, "%") == 0){
                final_result->value.intVal = op1->value.intVal % int_op2->value.intVal;
            } 
             
        }
    }
    else if(strcmp(op1->type, "float") == 0){
        struct nodeType* float_op2 = malloc(sizeof(struct nodeType));
        float_op2 = castingTo(op1,"float");
        final_result->type = "float";
        
        if(strcmp(op, "+") == 0){
            final_result->value.floatVal = op1->value.floatVal + float_op2->value.floatVal;
            }
        else if(strcmp(op, "-") == 0){
            final_result->value.floatVal = op1->value.floatVal - float_op2->value.floatVal;
            }
        else if(strcmp(op, "*") == 0){
            final_result->value.floatVal = op1->value.floatVal * float_op2->value.floatVal;
            }
        else if(strcmp(op, "/") == 0){
            final_result->value.floatVal = op1->value.floatVal / float_op2->value.floatVal;
            }     
    
    }
    else if(strcmp(op1->type, "bool") == 0){
        struct nodeType* bool_op2 = malloc(sizeof(struct nodeType));
        bool_op2 = castingTo(op1,"bool");
        final_result->type = "bool";
         //TODO: check
        if(strcmp(op, "+") == 0){
            final_result->value.boolVal = op1->value.boolVal || bool_op2->value.boolVal;
            }
        else if(strcmp(op, "-") == 0){
            final_result->value.boolVal = op1->value.boolVal || bool_op2->value.boolVal;
            }
        else if(strcmp(op, "*") == 0){
            final_result->value.boolVal = op1->value.boolVal && bool_op2->value.boolVal;
            }
        else if(strcmp(op, "/") == 0){
            final_result->value.boolVal = op1->value.boolVal && bool_op2->value.boolVal;
            }     
    
    }
    else if(strcmp(op1->type, "string") == 0){
        struct nodeType* string_op2 = malloc(sizeof(struct nodeType));
        string_op2 = castingTo(op1,"string");
        final_result->type = "string";
         //TODO: check
        if(strcmp(op, "+") == 0){{
            char* str1 = op1->value.stringVal;
            strcat(str1, string_op2->value.stringVal);
            final_result->value.stringVal = str1;
            }
        }
        else if(strcmp(op, "-") == 0){
        }
        else if(strcmp(op, "*") == 0){
        }
        else if(strcmp(op, "/") == 0){
        }     
    
    }
    else{
        ////Log_SEMANTIC_ERROR(TYPE_MISMATCH)
    }
    return final_result;
}

// Comparison
struct nodeType* doComparison(struct nodeType* op1, struct nodeType*op2, char* op){
    struct nodeType* bool_op1 = malloc(sizeof(struct nodeType));
    bool_op1 = castingTo(op1,"bool");
    struct nodeType* bool_op2 = malloc(sizeof(struct nodeType));
    bool_op2 = castingTo(op2,"bool");    
    
    struct nodeType* final_result = malloc(sizeof(struct nodeType));
    final_result->isConst=((op1->isConst)&&(op2->isConst));
    final_result->type = "bool";
 
    if(strcmp(op, "==") == 0){
        final_result->value.boolVal = op1->value.boolVal == op2->value.boolVal;
    }
    else if(strcmp(op, "!=") == 0){
        final_result->value.boolVal = op1->value.boolVal != op2->value.boolVal;
    }
    else if(strcmp(op, "<") == 0){
        final_result->value.boolVal = op1->value.boolVal < op2->value.boolVal;
    }
    else if(strcmp(op, ">") == 0){
        final_result->value.boolVal = op1->value.boolVal > op2->value.boolVal;
    }
    else if(strcmp(op, "<=") == 0){
        final_result->value.boolVal = op1->value.boolVal <= op2->value.boolVal;
    }
    else if(strcmp(op, ">=") == 0){
        final_result->value.boolVal = op1->value.boolVal >= op2->value.boolVal;
    }
    else{
        //Log_SEMANTIC_ERROR(INVALID_OPERATOR, op);
    }
    return final_result;
}

// Logical
struct nodeType* logical(struct nodeType* op1, struct nodeType* op2, char* op){
    struct nodeType* bool_op1 = malloc(sizeof(struct nodeType));
    bool_op1 = castingTo(op1,"bool");
    struct nodeType* bool_op2 = malloc(sizeof(struct nodeType));
    if (op2 != NULL){
        bool_op2 = castingTo(op2,"bool");  
    }
    
    struct nodeType* final_result = malloc(sizeof(struct nodeType));
    final_result->isConst=((op1->isConst)&&(op2->isConst));
    final_result->type = "bool";
    
    if(strcmp(op, "!") == 0){
        final_result->value.boolVal = !op1->value.boolVal;
    }
    else if(strcmp(op, "&") == 0){
        final_result->value.boolVal = op1->value.boolVal && op2->value.boolVal;
    }
    else if(strcmp(op, "|") == 0){
        final_result->value.boolVal = op1->value.boolVal || op2->value.boolVal;
    }
    else{
        //Log_SEMANTIC_ERROR(INVALID_OPERATOR, op);
    }
}

// Unary
struct nodeType* Negation(struct nodeType* term){
    struct nodeType* final_result = malloc(sizeof(struct nodeType));
    final_result->type = term->type;
    final_result->isConst = term->isConst;
    if(strcmp(term->type, "int") == 0){
        final_result->value.intVal = -term->value.intVal;
    }
    else if(strcmp(term->type, "float") == 0){
        final_result->value.floatVal = -term->value.floatVal;
    }
    return final_result;
}

int computeIdentifierIndex(char* name){
    int lvl;
    for(int i=sym_table_idx-1; i>=0 ;i--) {
        if(symbol_Table[i].name == name) {
            lvl = symbol_Table[i].scope;
            for(int j=scope_idx-1;j>=0;j--) {
                if(lvl == scopes[j]) {
                    return i;
                }
            }
        }
    }
    return -1;
}

void identifierNodeTypeCheck(char* name , struct nodeType* node){
    int identifier_sym_table_index = computeIdentifierIndex(name);
    if (identifier_sym_table_index < 0){
        //Log_SEMANTIC_ERROR(UNDEFINED_VARIABLE, name);
        return ;
    }
    
    if(strcmp(symbol_Table[identifier_sym_table_index].type, node->type) != 0) {
        //Log_SEMANTIC_ERROR(TYPE_MISMATCH, symbol_Table[identifier_sym_table_index].name);
    }
}

void nodeNodeTypeCheck(struct nodeType* node1, struct nodeType* node2){
    if(strcmp(node1->type, node2->type) != 0) {
        //Log_SEMANTIC_ERROR(TYPE_MISMATCH, node->type); 
    }
    return;
}


struct nodeType* identifierValue(char* name){
    int identifier_sym_table_index = computeIdentifierIndex(name);
    if (identifier_sym_table_index < 0){
        //Log_SEMANTIC_ERROR(UNDEFINED_VARIABLE, name);
        return NULL;
    }
    
    struct nodeType* final_result = malloc(sizeof(struct nodeType));;
    final_result->type = symbol_Table[identifier_sym_table_index].type;
    final_result->isConst = symbol_Table[identifier_sym_table_index].isConst;

    if(strcmp(symbol_Table[identifier_sym_table_index].type, "int") == 0)
        final_result->value.intVal = symbol_Table[identifier_sym_table_index].value.intVal;
    else if(strcmp(symbol_Table[identifier_sym_table_index].type, "float") == 0)
        final_result->value.floatVal = symbol_Table[identifier_sym_table_index].value.floatVal;
    else if(strcmp(symbol_Table[identifier_sym_table_index].type, "bool") == 0)
        final_result->value.boolVal = symbol_Table[identifier_sym_table_index].value.boolVal;
    else if(strcmp(symbol_Table[identifier_sym_table_index].type, "string") == 0)
        final_result->value.stringVal = symbol_Table[identifier_sym_table_index].value.stringVal;

    return final_result;
}  

// This function call after check that Identifier(name) is same type as node type 
void updateIdentifierValue(char* name, struct nodeType* node){
    int identifier_sym_table_index = computeIdentifierIndex(name);
    if (identifier_sym_table_index < 0){
        //Log_SEMANTIC_ERROR(UNDEFINED_VARIABLE, name);
        return;
    }
    
    if(strcmp(symbol_Table[identifier_sym_table_index].type, "int") == 0)
        symbol_Table [identifier_sym_table_index].value.intVal = castingTo(node, "int")->value.intVal;
    else if(strcmp(symbol_Table[identifier_sym_table_index].type, "float") == 0)
        symbol_Table[identifier_sym_table_index].value.floatVal = castingTo(node, "float")->value.floatVal;
    else if(strcmp(symbol_Table[identifier_sym_table_index].type, "bool") == 0)
        symbol_Table[identifier_sym_table_index].value.boolVal = castingTo(node, "bool")->value.boolVal;
    else if(strcmp(symbol_Table[identifier_sym_table_index].type, "string") == 0)
        symbol_Table[identifier_sym_table_index].value.stringVal = castingTo(node, "string")->value.stringVal;
}

// char* valueString(struct nodeType* node){
//     struct nodeType* str_p = malloc(sizeof(struct nodeType));
//     str_p = castingTo(node,"string")
//     return str_p->value.stringVal;
// }

void printNode(struct nodeType* node){
    struct nodeType* str_p = malloc(sizeof(struct nodeType));
    str_p = castingTo(node,"string");
    printf( str_p->value.stringVal);  
}

    

// Insert the variable in the symbol table
void insert(char* name, char* type, int isConst, int isInit, int isUsed, int scope){

    symbol_Table [sym_table_idx].name = name;
    symbol_Table [sym_table_idx].type = type;
    symbol_Table [sym_table_idx].isDecl = 1;
    symbol_Table [sym_table_idx].isConst = isConst;

    symbol_Table [sym_table_idx].isInit = isInit;
    symbol_Table [sym_table_idx].isUsed = isUsed;
    symbol_Table [sym_table_idx].scope = scope;
    ++sym_table_idx;

    printf("SymbolTable() inserted: %s, declared:%d, const:%d, Symbol table idx:%d\n", symbol_Table [sym_table_idx-1].name, symbol_Table [sym_table_idx-1].isDecl, symbol_Table [sym_table_idx-1].isConst, sym_table_idx); 
}
// Enter the scope
void enterScope() {
    scopes[scope_idx] = scope_lvl;
    scope_idx++;
    scope_lvl++;
}
//Deallocating the memory for those local variables declared within a scope 
void cleanedUpScope(int scope_idx) {
    for(int i=0; i<sym_table_idx ;i++) {
        if(symbol_Table[i].scope == scopes[scope_idx-1]) {
            // Ghost Varible
            symbol_Table[i].scope = -1;     // -1: means was in scope but cleaned ,but, 0: means no scope     
        }
    }
}
// Exit the scope
void exitScope() {
    cleanedUpScope(scope_idx);
    scope_idx--;
}
// Check if the variable is declared in the same scope
void checkSameScope(char* name) {
    int lvl;
    for(int i=0; i<sym_table_idx ;i++) {
        if(symbol_Table[i].name == name) { //checks if a Variable is declared before 
            lvl = symbol_Table[i].scope;
            if(lvl == scopes[scope_idx-1]) {
                 printf("Error: variable %s already declared in the same scope\n", name); 
              
            }
        }
    }
}

// Check if the variable is undeclared or removed out of scope
void checkOutOfScope(char* name) {
    int lvl;
    for(int i=sym_table_idx-1; i>=0 ;i--) {
        if(symbol_Table[i].name == name) { //checks if a Variable is declared before 
            lvl = symbol_Table[i].scope;
            for(int j=scope_idx-1;j>=0;j--) { //Loop through current scope of program downstream to base scope (0)
                if(lvl == scopes[j]) { //Find Variable in current scope or in any downstream to base scope (0)
                    return;
                }
            }
        }
    }
    printf("Error: variable %s is out of scope\n", name);

}


// this function checks if a variable is used before initialized
void checkInitialized(char* name) {
    int lvl;
    for(int i=sym_table_idx-1;i>=0;i--) {
        if(symbol_Table[i].name == name) { //checks if a Variable is declared before 
            lvl = symbol_Table[i].scope;
            for(int j=scope_idx-1;j>=0;j--) { //Loop through current scope of program downstream to base scope (0)
                if(lvl == scopes[j]) { //Find Variable in current scope or in any downstream to base scope (0)
                    if(symbol_Table[i].isInit == 1) {
                        //Every thing is OK
                        return;
                    }
                }
            }
        }
    }
    printf("Error: variable %s is used before initialized\n", name);
}

// Check if the node is constant or not
void checkConst(char* name) {
    for(int i=0; i<sym_table_idx ;i++) {
        if(symbol_Table[i].name == name) {
             for(int j=scope_idx-1;j>=0;j--) {
                if(symbol_Table[i].scope == scopes[j]) {
                    if(symbol_Table[i].isConst == 1) {
                        printf("Error: variable %s is constant\n", name);
                    }
                    else{
                        printf("Variable %s is not constant\n", name);
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
        semanticError(CONSTANT_IF, node->type/*node->value.boolVal !=0*/); //TODO: check warning about expected 'char *' but argument is of type 'int'
    }

}

// Print the symbol table
void printSymbolTable() {
    for(int i=0; i<sym_table_idx ;i++) {
        printf("SymbolTable() : %s, declared:%d, const:%d, Symbol table idx:%d\n", symbol_Table [i].name, symbol_Table [i].isDecl, symbol_Table [i].isConst, i); 
    }
}


// ------------------------------------------------------------------------------- 
// Setter functions 
// -------------------------------------------------------------------------------  
void setInit(char* name) {
    int lvl;
    for(int i=sym_table_idx-1;i>=0;i--) {
        if(symbol_Table[i].name == name) { //checks if a Variable is declared before 
            lvl = symbol_Table[i].scope;
            for(int j=scope_idx-1;j>=0;j--) { //Loop through current scope of program downstream to base scope (0)
                if(lvl == scopes[j]) { //Find Variable in current scope or in any downstream to base scope (0)
                    symbol_Table[i].isInit = 1;
                    return;
                }
            }
        }
    }
}

void setUsed(char* name) {
    int lvl;
    for(int i=sym_table_idx-1;i>=0;i--) {
        if(symbol_Table[i].name == name) { //checks if a Variable is declared before 
            lvl = symbol_Table[i].scope;
            for(int j=scope_idx-1;j>=0;j--) { //Loop through current scope of program downstream to base scope (0)
                if(lvl == scopes[j]) { //Find Variable in current scope or in any downstream to base scope (0)
                    symbol_Table[i].isUsed = 1;
                    return;
                    
                }
            }
        }
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
void quadPushInt(int val)
{
       if (SHOW_Quads) {
               printf("Quads(%d) \tPUSH %d\n", line, val);
       }
}

int main(void) {
    //enumValues = createIntNode(0); //TODO: test this
    //printStringValues = createStringNode("");
        //intialize the scopes table 
    for (int i = 0; i < 100; i++) {
        scopes[i] = 0; //default scope = 0 (No scope)
    }
    yyparse();
    return 0;
}
