
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
    // =====================
    void quadPopIdentifier(char symbol);
    void quadPushIdentifier(char symbol);
    void quadInstruction(const char* instruction);
    void quadPushFloat(float val);
    void quadPushString(char* str);
    void quadStartFunction(char function);
    void quadEndFunction(char function);
    void quadCallFunction(char function);
    void quadReturn();

    void quadPushLastIdentifierStack(char identifier);
    void quadPeakLastIdentifierStack(); 
    void quadPopLastIdentifierStack();

    int argCount = 0;

    int funcPointer = -1;
    int paramCount = 0;


    int lastIdentifierStackPointer = -1;
    char lastIdentifierStack[MAX_STACK_SIZE];

    void quadJumpStartLabel();
    void quadPushStartLabel(int startLabelNum);
    void quadPopStartLabel();

    int startLabelNum = 0;
    int startLabelstackPointer = -1;
    int startLabelStack[MAX_STACK_SIZE];

    void quadStartEnum(char enumName);
    void quadEndEnum(char enumName);

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

    void updateSymbolParam(char* symbol, int param);



/* Line 189 of yacc.c  */
#line 253 "main.tab.c"

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
#line 184 "main.y"

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
#line 341 "main.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 353 "main.tab.c"

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  207
/* YYNRULES -- Number of states.  */
#define YYNSTATES  329

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
       0,     0,     3,     4,     6,     8,    11,    14,    15,    16,
      19,    21,    22,    25,    26,    29,    30,    33,    35,    36,
      39,    40,    43,    44,    47,    48,    51,    52,    55,    56,
      57,    62,    63,    64,    71,    72,    73,    74,    83,    84,
      85,    86,    93,    95,    98,    99,   102,   103,   109,   110,
     114,   115,   120,   121,   126,   127,   132,   133,   138,   139,
     144,   145,   150,   151,   156,   157,   162,   163,   168,   169,
     174,   175,   180,   181,   186,   187,   192,   193,   197,   198,
     203,   204,   205,   209,   210,   211,   215,   216,   217,   221,
     222,   223,   227,   228,   229,   233,   234,   235,   239,   240,
     245,   246,   247,   248,   249,   250,   251,   266,   267,   269,
     270,   271,   276,   277,   278,   285,   286,   287,   288,   289,
     301,   304,   306,   307,   308,   309,   318,   322,   323,   324,
     325,   326,   338,   339,   340,   341,   342,   343,   344,   362,
     374,   386,   387,   388,   400,   401,   402,   410,   411,   414,
     415,   420,   421,   426,   427,   434,   435,   439,   440,   446,
     447,   450,   451,   456,   457,   460,   462,   463,   466,   467,
     470,   471,   474,   475,   478,   479,   482,   483,   487,   488,
     494,   495,   501,   502,   506,   507,   510,   511,   516,   517,
     518,   524,   527,   528,   529,   530,   538,   540,   541,   545,
     546,   547,   554,   555,   556,   557,   567,   571
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      55,     0,    -1,    -1,   189,    -1,   175,    -1,   175,    55,
      -1,   189,    55,    -1,    -1,    -1,    57,   136,    -1,   141,
      -1,    -1,    58,   113,    -1,    -1,    59,   126,    -1,    -1,
      60,   148,    -1,    39,    -1,    -1,    40,    63,    -1,    -1,
      41,    64,    -1,    -1,    42,    65,    -1,    -1,    43,    66,
      -1,    -1,    44,    67,    -1,    -1,    -1,    62,    45,    69,
      70,    -1,    -1,    -1,    62,    45,     3,    80,    71,    72,
      -1,    -1,    -1,    -1,    61,    62,    45,     3,    80,    73,
      74,    75,    -1,    -1,    -1,    -1,    45,     3,    80,    77,
      78,    79,    -1,   151,    -1,    24,   159,    -1,    -1,    99,
      81,    -1,    -1,    46,    62,    47,    99,    82,    -1,    -1,
      13,    99,    83,    -1,    -1,    80,    12,    80,    84,    -1,
      -1,    80,    13,    80,    85,    -1,    -1,    80,    15,    80,
      86,    -1,    -1,    80,    16,    80,    87,    -1,    -1,    80,
      17,    80,    88,    -1,    -1,    80,     7,    80,    89,    -1,
      -1,    80,     6,    80,    90,    -1,    -1,    80,     9,    80,
      91,    -1,    -1,    80,    11,    80,    92,    -1,    -1,    80,
      10,    80,    93,    -1,    -1,    80,     8,    80,    94,    -1,
      -1,    80,     5,    80,    95,    -1,    -1,    80,     4,    80,
      96,    -1,    -1,    14,    80,    97,    -1,    -1,    46,    80,
      47,    98,    -1,    -1,    -1,    18,   100,   101,    -1,    -1,
      -1,    19,   102,   103,    -1,    -1,    -1,    20,   104,   105,
      -1,    -1,    -1,    21,   106,   107,    -1,    -1,    -1,    22,
     108,   109,    -1,    -1,    -1,    45,   110,   111,    -1,    -1,
      46,    99,    47,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    46,    80,   114,   115,    47,    48,   116,   117,
     184,    49,   118,   119,   120,    -1,    -1,   121,    -1,    -1,
      -1,    29,   122,   123,   113,    -1,    -1,    -1,    29,    48,
     124,   184,    49,   125,    -1,    -1,    -1,    -1,    -1,    30,
      46,    45,    47,   127,   128,    48,   129,   131,    49,   130,
      -1,   131,   132,    -1,   132,    -1,    -1,    -1,    -1,    31,
     133,    80,   134,    50,   135,    80,   175,    -1,    32,    50,
     175,    -1,    -1,    -1,    -1,    -1,    33,    46,    80,    47,
     137,   138,    48,   139,   184,    49,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    46,   142,    76,    51,   143,
     144,    80,    51,   145,    76,    47,    48,   146,   184,    49,
     147,    -1,    34,    46,    45,    50,    80,    13,    80,    47,
      48,   184,    49,    -1,    34,    46,    45,    50,    80,    52,
      80,    47,    48,   184,    49,    -1,    -1,    -1,    37,    48,
     149,   184,    49,   150,    38,    46,    80,    47,    51,    -1,
      -1,    -1,    24,    45,   152,   153,    48,   154,    49,    -1,
      -1,    45,   155,    -1,    -1,    45,     3,    80,   156,    -1,
      -1,    45,    53,   154,   157,    -1,    -1,    45,     3,    80,
      53,   154,   158,    -1,    -1,    45,    45,   160,    -1,    -1,
      45,    45,     3,    80,   161,    -1,    -1,    80,   163,    -1,
      -1,   162,    53,    80,   164,    -1,    -1,    76,   166,    -1,
      80,    -1,    -1,    68,   167,    -1,    -1,    27,   168,    -1,
      -1,    35,   169,    -1,    -1,    36,   170,    -1,    -1,    23,
     171,    -1,    -1,    23,    80,   172,    -1,    -1,    25,    46,
      80,    47,   173,    -1,    -1,    25,    46,   162,    47,   174,
      -1,    -1,   165,    51,   176,    -1,    -1,    56,   177,    -1,
      -1,   175,   165,    51,   178,    -1,    -1,    -1,    48,   179,
     184,    49,   180,    -1,   175,    56,    -1,    -1,    -1,    -1,
     175,    48,   181,   184,    49,   182,   183,    -1,   175,    -1,
      -1,    62,    45,   186,    -1,    -1,    -1,    62,    45,   187,
     188,    53,   185,    -1,    -1,    -1,    -1,    62,    45,   190,
     191,   192,   193,    48,   184,    49,    -1,    46,   185,    47,
      -1,    46,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   250,   250,   252,   253,   254,   255,   256,   260,   260,
     261,   262,   262,   263,   263,   264,   264,   269,   271,   271,
     272,   272,   273,   273,   274,   274,   275,   275,   278,   278,
     278,   279,   279,   279,   280,   280,   280,   280,   285,   285,
     285,   285,   286,   287,   292,   292,   293,   293,   294,   294,
     295,   295,   296,   296,   297,   297,   298,   298,   299,   299,
     300,   300,   301,   301,   302,   302,   303,   303,   304,   304,
     305,   305,   306,   306,   307,   307,   308,   308,   309,   309,
     313,   313,   313,   314,   314,   314,   315,   315,   315,   316,
     316,   316,   317,   317,   317,   318,   318,   318,   319,   319,
     328,   328,   328,   328,   328,   328,   328,   330,   330,   331,
     331,   331,   332,   332,   332,   335,   335,   335,   335,   335,
     337,   338,   341,   341,   341,   341,   342,   350,   350,   350,
     350,   350,   353,   353,   353,   353,   353,   353,   353,   354,
     355,   359,   359,   359,   365,   365,   365,   369,   369,   370,
     370,   371,   371,   372,   372,   375,   375,   376,   376,   382,
     382,   383,   383,   386,   386,   387,   388,   388,   389,   389,
     390,   390,   391,   391,   392,   392,   393,   393,   394,   394,
     395,   395,   400,   400,   401,   401,   402,   402,   403,   403,
     403,   404,   405,   405,   405,   405,   410,   415,   415,   416,
     416,   416,   421,   421,   422,   421,   424,   425
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
  "'<'", "','", "$accept", "program", "controlStatement", "$@1", "$@2",
  "$@3", "$@4", "dataModifier", "dataType", "$@5", "$@6", "$@7", "$@8",
  "$@9", "decleration", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "$@16", "assignment", "$@17", "$@18", "$@19", "expr", "$@20", "$@21",
  "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28", "$@29", "$@30",
  "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "$@37", "term", "$@38",
  "$@39", "$@40", "$@41", "$@42", "$@43", "$@44", "$@45", "$@46", "$@47",
  "$@48", "$@49", "$@50", "ifCondition", "$@51", "$@52", "$@53", "$@54",
  "$@55", "$@56", "elseCondition", "$@57", "$@58", "$@59", "$@60", "$@61",
  "switchCase", "$@62", "$@63", "$@64", "$@65", "caseList", "case", "$@66",
  "$@67", "$@68", "while", "$@69", "$@70", "$@71", "$@72", "forLoop",
  "$@73", "$@74", "$@75", "$@76", "$@77", "$@78", "repeatUntil", "$@79",
  "$@80", "enumDef", "$@81", "$@82", "enumBody", "$@83", "$@84", "$@85",
  "$@86", "enumDeclaration", "$@87", "$@88", "printList", "$@89", "$@90",
  "statement", "$@91", "$@92", "$@93", "$@94", "$@95", "$@96", "$@97",
  "$@98", "$@99", "statements", "$@100", "$@101", "$@102", "$@103",
  "$@104", "$@105", "$@106", "$@107", "codeBlock", "functionArgs", "$@108",
  "$@109", "$@110", "functionDefinition", "$@112", "$@113", "$@114",
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
       0,    54,    55,    55,    55,    55,    55,    55,    57,    56,
      56,    58,    56,    59,    56,    60,    56,    61,    63,    62,
      64,    62,    65,    62,    66,    62,    67,    62,    69,    70,
      68,    71,    72,    68,    73,    74,    75,    68,    77,    78,
      79,    76,    76,    76,    81,    80,    82,    80,    83,    80,
      84,    80,    85,    80,    86,    80,    87,    80,    88,    80,
      89,    80,    90,    80,    91,    80,    92,    80,    93,    80,
      94,    80,    95,    80,    96,    80,    97,    80,    98,    80,
     100,   101,    99,   102,   103,    99,   104,   105,    99,   106,
     107,    99,   108,   109,    99,   110,   111,    99,   112,    99,
     114,   115,   116,   117,   118,   119,   113,   121,   120,   122,
     123,   120,   124,   125,   120,   127,   128,   129,   130,   126,
     131,   131,   133,   134,   135,   132,   132,   137,   138,   139,
     140,   136,   142,   143,   144,   145,   146,   147,   141,   141,
     141,   149,   150,   148,   152,   153,   151,   155,   154,   156,
     154,   157,   154,   158,   154,   160,   159,   161,   159,   163,
     162,   164,   162,   166,   165,   165,   167,   165,   168,   165,
     169,   165,   170,   165,   171,   165,   172,   165,   173,   165,
     174,   165,   176,   175,   177,   175,   178,   175,   179,   180,
     175,   175,   181,   182,   183,   175,   184,   186,   185,   187,
     188,   185,   190,   191,   192,   189,   193,   193
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     0,     0,     2,
       1,     0,     2,     0,     2,     0,     2,     1,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     0,
       4,     0,     0,     6,     0,     0,     0,     8,     0,     0,
       0,     6,     1,     2,     0,     2,     0,     5,     0,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     3,     0,     4,
       0,     0,     3,     0,     0,     3,     0,     0,     3,     0,
       0,     3,     0,     0,     3,     0,     0,     3,     0,     4,
       0,     0,     0,     0,     0,     0,    14,     0,     1,     0,
       0,     4,     0,     0,     6,     0,     0,     0,     0,    11,
       2,     1,     0,     0,     0,     8,     3,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,    17,    11,
      11,     0,     0,    11,     0,     0,     7,     0,     2,     0,
       4,     0,     4,     0,     6,     0,     3,     0,     5,     0,
       2,     0,     4,     0,     2,     1,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     3,     0,     5,
       0,     5,     0,     3,     0,     2,     0,     4,     0,     0,
       5,     2,     0,     0,     0,     7,     1,     0,     3,     0,
       0,     6,     0,     0,     0,     9,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,    80,    83,    86,    89,    92,   174,     0,
       0,   168,     0,   170,   172,    17,    18,    20,    22,    24,
      26,    95,     0,   188,     0,   184,     0,     0,     0,     0,
       0,     0,   166,   163,   165,    44,    10,    42,     0,     2,
       2,    95,     0,    48,    76,    81,    84,    87,    90,    93,
     176,   175,   144,    43,     0,   169,   132,   171,   173,    19,
      21,    23,    25,    27,     0,    96,     0,     0,    44,     8,
       1,   185,     0,     9,     0,    12,     0,    14,     0,    16,
       0,    28,   167,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,   182,   188,
       5,   184,     0,     6,     0,    49,    77,    82,    85,    88,
      91,    94,   177,   155,   145,   159,     0,     0,     0,    38,
      97,     0,    78,    98,     0,     8,     0,     0,     0,     0,
     141,     0,     0,    29,   203,    74,    72,    62,    60,    70,
      64,    68,    66,    50,    52,    54,    56,    58,   183,     8,
     182,     0,   156,     0,   178,   160,   180,     0,     0,     0,
       0,    39,    46,    79,    99,    28,   192,   191,     0,   189,
       0,   100,     0,     8,     0,    31,    30,   204,    75,    73,
      63,    61,    71,    65,    69,    67,    51,    53,    55,    57,
      59,     0,   187,   157,     0,   179,   181,   161,     0,   133,
      40,    47,   186,   190,   127,   101,   115,     0,    34,    32,
       0,   193,   158,   147,     0,   162,     0,     0,   134,    41,
     128,     0,   116,   142,    35,    33,     0,     0,   194,     0,
       0,   148,   146,    52,     0,     0,     0,     0,     0,     0,
      36,   207,     0,     0,     8,   195,   149,   151,     0,     0,
       0,   129,   102,   117,     0,    37,   197,   206,     0,     0,
     150,   152,     8,     8,   135,     8,   103,     0,     0,   198,
     200,   205,   153,     0,     0,     0,     0,     8,   122,     0,
       0,   121,     0,     0,   154,   139,   140,     0,   130,     0,
       0,     8,   118,   120,     0,     0,     0,   131,   104,   123,
     126,   119,   143,   201,   136,   105,     0,     8,   107,   124,
       0,   109,   106,   108,     0,   137,   112,   110,     8,   138,
       8,     0,     0,   125,     0,   111,    44,   113,   114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,    26,    27,    28,    29,    30,   124,    59,
      60,    61,    62,    63,    32,   133,   176,   209,   225,   224,
     240,   255,    33,   161,   200,   219,    34,    97,   201,   105,
     186,   187,   188,   189,   190,   181,   180,   183,   185,   184,
     182,   179,   178,   106,   163,    35,    45,   107,    46,   108,
      47,   109,    48,   110,    49,   111,    65,   120,   164,    75,
     205,   221,   266,   277,   305,   308,   312,   313,   317,   321,
     320,   328,    77,   222,   238,   267,   301,   280,   281,   290,
     306,   314,    73,   220,   236,   265,   297,    36,   118,   218,
     235,   275,   307,   319,    79,   173,   239,    37,   114,   153,
     214,   231,   260,   261,   284,    53,   152,   212,   116,   155,
     215,    38,    83,    82,    55,    57,    58,    51,   112,   195,
     196,   125,   148,    71,   192,    69,   203,   149,   228,   245,
     126,   243,   269,   270,   283,    40,   134,   177,   210,   227
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -221
static const yytype_int16 yypact[] =
{
     428,    -3,    88,  -221,  -221,  -221,  -221,  -221,    88,   -17,
     -34,  -221,   -16,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,    28,   164,  -221,    32,  -221,     1,    10,    18,    13,
      39,    -5,  -221,  -221,   248,  -221,  -221,  -221,     9,   464,
     428,  -221,    -3,  -221,   248,  -221,  -221,  -221,  -221,  -221,
     248,  -221,    16,  -221,    88,  -221,    30,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,    88,  -221,    51,   215,    53,   536,
    -221,  -221,     6,  -221,    17,  -221,    57,  -221,    63,  -221,
      60,     3,  -221,  -221,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,  -221,  -221,  -221,
    -221,  -221,    62,  -221,    53,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,   109,  -221,   234,   -33,    65,   -20,   248,
    -221,    -3,  -221,  -221,    71,   264,    68,    88,    88,    73,
    -221,   116,    88,  -221,  -221,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,  -221,   536,
    -221,    88,  -221,    76,  -221,  -221,  -221,    88,    88,    28,
      70,  -221,  -221,  -221,  -221,   123,  -221,  -221,    78,  -221,
     365,   248,    83,   536,    88,   248,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,    82,  -221,   248,    90,  -221,  -221,   248,   137,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,    87,   248,  -221,
      92,  -221,  -221,    -2,    91,  -221,    88,    88,  -221,  -221,
    -221,   108,  -221,  -221,  -221,  -221,    15,   111,  -221,    88,
      90,  -221,  -221,   379,   393,    88,   113,   114,   115,   101,
    -221,  -221,   119,   118,   536,  -221,    61,  -221,   120,   121,
     186,  -221,  -221,  -221,   110,  -221,   117,  -221,   122,    90,
    -221,  -221,   536,   536,  -221,   536,  -221,    -8,    88,  -221,
    -221,  -221,  -221,   124,   126,   -20,   127,   536,  -221,   129,
       4,  -221,   412,   128,  -221,  -221,  -221,   125,  -221,   138,
      88,   536,  -221,  -221,   149,    39,   140,  -221,  -221,   248,
     500,  -221,  -221,  -221,  -221,  -221,   161,   536,   183,  -221,
     165,   167,  -221,  -221,    88,  -221,  -221,  -221,   320,  -221,
     536,    10,    88,   500,   169,  -221,   162,  -221,  -221
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,   -13,   -28,  -221,  -221,  -221,  -221,  -221,     7,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -115,  -221,  -221,  -221,     0,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,    -1,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -155,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,   -46,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -220,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,   -26,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,     5,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -140,   -59,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -203
static const yytype_int16 yytable[] =
{
      43,   229,    44,   160,     9,    39,   132,    31,    50,   191,
     247,   101,    54,   102,   156,     3,     4,     5,     6,     7,
     157,    68,    67,   278,   279,   159,   100,   103,    52,    66,
      56,    64,    70,   207,    72,   278,   279,    80,    74,   272,
      81,   104,    41,    42,    39,    39,    31,    31,    76,  -202,
      78,   230,   127,   292,   115,    16,    17,    18,    19,    20,
      98,   113,   241,   128,   119,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   117,    94,    95,    96,    16,
      17,    18,    19,    20,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   167,   121,   168,
     123,     1,     2,   129,   258,   131,     3,     4,     5,     6,
       7,   130,   151,   150,   259,   158,   165,   169,   172,   174,
     162,   199,   273,   274,   194,   276,   132,   170,   171,   202,
     206,   211,   175,    41,    22,   213,   223,   289,   226,   254,
     232,    84,    85,    86,    87,    88,    89,    90,    91,    92,
     216,   193,    94,    95,    96,   237,   268,   197,   198,   244,
     287,   251,   252,   253,   256,   257,   325,   310,   262,   263,
    -199,   271,   296,   285,   208,   286,   288,     1,     2,   291,
     324,   295,     3,     4,     5,     6,     7,   298,   304,   217,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
     302,    94,    95,    96,    16,    17,    18,    19,    20,    41,
      22,   309,   311,   -48,   315,   316,   233,   234,   327,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,   246,
      94,    95,    96,   242,   293,   250,   303,   264,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    94,
      95,    96,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   122,    94,    95,    96,     0,     0,   282,     0,
       0,     0,   167,     0,   168,     0,     0,     1,     2,     0,
       0,   154,     3,     4,     5,     6,     7,     8,     9,    10,
     299,    11,   -11,     0,   -13,   167,   300,   168,    12,    13,
      14,   -15,   242,    15,    16,    17,    18,    19,    20,    21,
      22,     0,   166,  -196,   318,     0,     0,     0,     0,     0,
       0,   326,   144,   323,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   322,     2,    94,    95,    96,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,   -11,     0,
     -13,     0,     0,     0,    12,    13,    14,   -15,     0,    15,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,    94,    95,    96,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,   204,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,   248,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     1,     2,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,   -11,     0,   -13,   294,
       0,    -8,    12,    13,    14,   -15,     0,    15,    16,    17,
      18,    19,    20,    21,    22,     0,    23,     1,     2,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,   -11,     0,   -13,     0,     0,    -8,    12,    13,
      14,   -15,     0,    15,    16,    17,    18,    19,    20,    21,
      22,     0,    99,     1,     2,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,   -11,     0,
     -13,     0,     0,    -8,    12,    13,    14,   -15,     0,    15,
      16,    17,    18,    19,    20,    21,    22,     0,   166,     1,
       2,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,   -11,     0,   -13,     0,     0,     0,
      12,    13,    14,   -15,     0,    15,    16,    17,    18,    19,
      20,    21,    22,     0,    23
};

static const yytype_int16 yycheck[] =
{
       1,     3,     2,   118,    24,     0,     3,     0,     8,   149,
     230,    39,    46,    39,    47,    18,    19,    20,    21,    22,
      53,    22,    22,    31,    32,    45,    39,    40,    45,    22,
      46,     3,     0,   173,    33,    31,    32,    30,    28,   259,
      45,    42,    45,    46,    39,    40,    39,    40,    30,    46,
      37,    53,    46,    49,    54,    40,    41,    42,    43,    44,
      51,    45,    47,    46,    64,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    45,    15,    16,    17,    40,
      41,    42,    43,    44,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,   125,    47,   125,
      47,    13,    14,    46,   244,    45,    18,    19,    20,    21,
      22,    48,     3,    51,    53,    50,    45,    49,    45,     3,
     121,    51,   262,   263,    48,   265,     3,   127,   128,    51,
      47,    49,   132,    45,    46,    45,    49,   277,    46,    38,
      49,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,   151,    15,    16,    17,    47,    46,   157,   158,    48,
     275,    48,    48,    48,    45,    47,   321,   307,    48,    48,
      53,    49,    47,    49,   174,    49,    49,    13,    14,    50,
     320,    53,    18,    19,    20,    21,    22,    49,    48,    52,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      51,    15,    16,    17,    40,    41,    42,    43,    44,    45,
      46,    50,    29,    51,    49,    48,   216,   217,    49,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,   229,
      15,    16,    17,   226,   280,   235,   295,    51,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    47,    15,    16,    17,    -1,    -1,   268,    -1,
      -1,    -1,   300,    -1,   300,    -1,    -1,    13,    14,    -1,
      -1,    47,    18,    19,    20,    21,    22,    23,    24,    25,
     290,    27,    28,    -1,    30,   323,   291,   323,    34,    35,
      36,    37,   295,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,   314,    -1,    -1,    -1,    -1,    -1,
      -1,   322,   322,   318,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    -1,
      30,    -1,    -1,    -1,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    16,    17,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    16,    17,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    -1,    47,    -1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    47,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    30,    47,
      -1,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    13,    14,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    13,
      14,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    18,    19,    20,    21,    22,    23,    24,
      25,    27,    34,    35,    36,    39,    40,    41,    42,    43,
      44,    45,    46,    48,    55,    56,    57,    58,    59,    60,
      61,    62,    68,    76,    80,    99,   141,   151,   165,   175,
     189,    45,    46,    99,    80,   100,   102,   104,   106,   108,
      80,   171,    45,   159,    46,   168,    46,   169,   170,    63,
      64,    65,    66,    67,     3,   110,    62,    80,    99,   179,
       0,   177,    33,   136,    28,   113,    30,   126,    37,   148,
      62,    45,   167,   166,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    15,    16,    17,    81,    51,    48,
      55,    56,   165,    55,    99,    83,    97,   101,   103,   105,
     107,   109,   172,    45,   152,    80,   162,    45,   142,    80,
     111,    47,    47,    47,    62,   175,   184,    46,    46,    46,
      48,    45,     3,    69,   190,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,   176,   181,
      51,     3,   160,   153,    47,   163,    47,    53,    50,    45,
      76,    77,    99,    98,   112,    45,    48,    56,   165,    49,
      80,    80,    45,   149,     3,    80,    70,   191,    96,    95,
      90,    89,    94,    91,    93,    92,    84,    85,    86,    87,
      88,   184,   178,    80,    48,   173,   174,    80,    80,    51,
      78,    82,    51,   180,    47,   114,    47,   184,    80,    71,
     192,    49,   161,    45,   154,   164,    13,    52,   143,    79,
     137,   115,   127,    49,    73,    72,    46,   193,   182,     3,
      53,   155,    49,    80,    80,   144,   138,    47,   128,   150,
      74,    47,    62,   185,    48,   183,    80,   154,    47,    47,
      80,    48,    48,    48,    38,    75,    45,    47,   184,    53,
     156,   157,    48,    48,    51,   139,   116,   129,    46,   186,
     187,    49,   154,   184,   184,   145,   184,   117,    31,    32,
     131,   132,    80,   188,   158,    49,    49,    76,    49,   184,
     133,    50,    49,   132,    47,    53,    47,   140,    49,    80,
     175,   130,    51,   185,    48,   118,   134,   146,   119,    50,
     184,    29,   120,   121,   135,    49,    48,   122,    80,   147,
     124,   123,    13,   175,   184,   113,    99,    49,   125
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
#line 252 "main.y"
    {printf("{*inside Rule*} program -> functionDefinition : \n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 253 "main.y"
    {printf("{*inside Rule*} program -> statements : \n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 254 "main.y"
    {printf("{*inside Rule*} program -> statements program : \n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 255 "main.y"
    {printf("{*inside Rule*} program -> functionDefinition program : \n");;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 256 "main.y"
    {;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 260 "main.y"
    {quadPushStartLabel(++startLabelNum);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 260 "main.y"
    {quadPopStartLabel();;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 261 "main.y"
    {quadPopStartLabel();;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 262 "main.y"
    {quadPushEndLabel(++endLabelNum);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 262 "main.y"
    {quadPopEndLabel();;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 263 "main.y"
    {quadPushEndLabel(++endLabelNum);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 263 "main.y"
    {quadPopEndLabel();;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 264 "main.y"
    {quadPushStartLabel(++startLabelNum);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 264 "main.y"
    {quadPopStartLabel();;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 269 "main.y"
    {printf("{*inside Rule*} dataModifier -> CONST : \n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 271 "main.y"
    {printf("{*inside Rule*} dataModifier -> INT_DATA_TYPE : \n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 271 "main.y"
    { (yyval.TYPE_NODE) = createIntNode(0); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 272 "main.y"
    {printf("{*inside Rule*} dataModifier -> FLOAT_DATA_TYPE : \n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 272 "main.y"
    { (yyval.TYPE_NODE) = createNode("float"); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 273 "main.y"
    {printf("{*inside Rule*} dataModifier -> STRING_DATA_TYPE : \n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 273 "main.y"
    { (yyval.TYPE_NODE) = createNode("string"); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 274 "main.y"
    {printf("{*inside Rule*} dataModifier -> BOOL_DATA_TYPE : \n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 274 "main.y"
    { (yyval.TYPE_NODE) = createNode("bool"); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 275 "main.y"
    {printf("{*inside Rule*} dataModifier -> VOID_DATA_TYPE : \n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 275 "main.y"
    { ; ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 278 "main.y"
    {printf("{*inside Rule*} decleration -> dataType IDENTIFIER : \n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 278 "main.y"
    {checkSameScope((yyvsp[(2) - (3)].TYPE_STR));  insert((yyvsp[(2) - (3)].TYPE_STR), (yyvsp[(1) - (3)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 278 "main.y"
    {printSymbolTable(); quadPopIdentifier((yyvsp[(2) - (4)].TYPE_STR));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 279 "main.y"
    {printf("{*inside Rule*} decleration -> dataType IDENTIFIER   '='  expr   : \n");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 279 "main.y"
    {checkSameScope((yyvsp[(2) - (5)].TYPE_STR));  nodeNodeTypeCheck((yyvsp[(1) - (5)].TYPE_NODE), (yyvsp[(4) - (5)].TYPE_NODE)); insert((yyvsp[(2) - (5)].TYPE_STR), (yyvsp[(1) - (5)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]);  updateIdentifierValue((yyvsp[(2) - (5)].TYPE_STR),(yyvsp[(4) - (5)].TYPE_NODE)); setInit((yyvsp[(2) - (5)].TYPE_STR)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 279 "main.y"
    {printSymbolTable(); quadPopIdentifier((yyvsp[(2) - (6)].TYPE_STR));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 280 "main.y"
    {printf("{*inside Rule*} decleration -> dataModifier dataType IDENTIFIER  '='  expr : \n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 280 "main.y"
    {checkSameScope((yyvsp[(3) - (6)].TYPE_STR));  nodeNodeTypeCheck((yyvsp[(2) - (6)].TYPE_NODE), (yyvsp[(5) - (6)].TYPE_NODE)); insert((yyvsp[(3) - (6)].TYPE_STR), (yyvsp[(2) - (6)].TYPE_NODE)->type, 1, 0, 0, scopes[scope_idx-1]);  updateIdentifierValue((yyvsp[(3) - (6)].TYPE_STR),(yyvsp[(5) - (6)].TYPE_NODE)); setInit((yyvsp[(3) - (6)].TYPE_STR)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 280 "main.y"
    {printSymbolTable();;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 280 "main.y"
    {printSymbolTable();  quadPopIdentifier((yyvsp[(3) - (8)].TYPE_STR));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 285 "main.y"
    {printf("{*inside Rule*} assignment -> IDENTIFIER '='  expr   : \n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 285 "main.y"
    { checkOutOfScope((yyvsp[(1) - (4)].TYPE_STR)); checkConst((yyvsp[(1) - (4)].TYPE_STR)); identifierNodeTypeCheck((yyvsp[(1) - (4)].TYPE_STR), (yyvsp[(3) - (4)].TYPE_NODE)); setInit((yyvsp[(1) - (4)].TYPE_STR)); setUsed((yyvsp[(1) - (4)].TYPE_STR)); updateIdentifierValue((yyvsp[(1) - (4)].TYPE_STR),(yyvsp[(3) - (4)].TYPE_NODE)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 285 "main.y"
    {printSymbolTable();;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 285 "main.y"
    {printf(castingTo((yyvsp[(3) - (6)].TYPE_NODE),"string")->value.stringVal); (yyval.TYPE_NODE) = (yyvsp[(3) - (6)].TYPE_NODE); quadPopIdentifier((yyvsp[(1) - (6)].TYPE_STR));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 286 "main.y"
    {printf("{*inside Rule*} assignment -> enumDef   : \n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 287 "main.y"
    {printf("{*inside Rule*} assignment -> ENUM enumDeclaration   : \n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 292 "main.y"
    {printf("{*inside Rule*} expr -> term   : \n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 292 "main.y"
    { (yyval.TYPE_NODE) = (yyvsp[(1) - (2)].TYPE_NODE); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 293 "main.y"
    {printf("{*inside Rule*} expr ->  '(' dataType ')' term   : \n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 293 "main.y"
    {quadInstruction("CAST"); (yyval.TYPE_NODE) = castingTo((yyvsp[(4) - (5)].TYPE_NODE), (yyvsp[(2) - (5)].TYPE_NODE)->type);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 294 "main.y"
    {printf("{*inside Rule*} expr -> '-' term   : \n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 294 "main.y"
    {quadInstruction("NEG"); (yyval.TYPE_NODE) = Negation((yyvsp[(2) - (3)].TYPE_NODE)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 295 "main.y"
    {printf("{*inside Rule*} expr -> expr '+' expr   : \n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 295 "main.y"
    {quadInstruction("ADD"); (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"+"); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 296 "main.y"
    {printf("{*inside Rule*} expr -> expr '-' expr   : \n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 296 "main.y"
    {quadInstruction("SUB"); (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"-"); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 297 "main.y"
    {printf("{*inside Rule*} expr -> expr '*' expr   : \n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 297 "main.y"
    {quadInstruction("MUL"); (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"*"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 298 "main.y"
    {printf("{*inside Rule*} expr -> expr '/' expr   : \n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 298 "main.y"
    {quadInstruction("DIV"); (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"/"); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 299 "main.y"
    {printf("{*inside Rule*} expr -> expr '%' expr   : \n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 299 "main.y"
    {quadInstruction("MOD"); (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"%"); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 300 "main.y"
    {printf("{*inside Rule*} expr -> expr EQ expr   : \n");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 300 "main.y"
    {quadInstruction("EQ");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"==");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 301 "main.y"
    {printf("{*inside Rule*} expr -> expr NEQ expr   : \n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 301 "main.y"
    {quadInstruction("NEQ");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"!=");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 302 "main.y"
    {printf("{*inside Rule*} expr -> expr LT expr   : \n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 302 "main.y"
    {quadInstruction("LT");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"<"); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 303 "main.y"
    {printf("{*inside Rule*} expr -> expr GT expr   : \n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 303 "main.y"
    {quadInstruction("GT");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),">"); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 304 "main.y"
    {printf("{*inside Rule*} expr -> expr GEQ expr   : \n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 304 "main.y"
    {quadInstruction("GEQ");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),">="); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 305 "main.y"
    {printf("{*inside Rule*} expr -> expr LEQ expr   : \n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 305 "main.y"
    {quadInstruction("LEQ");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"<="); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 306 "main.y"
    {printf("{*inside Rule*} expr -> expr AND expr   : \n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 306 "main.y"
    {quadInstruction("LOGICAL_AND"); (yyval.TYPE_NODE) = logical((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"&"); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 307 "main.y"
    {printf("{*inside Rule*} expr -> expr OR expr   : \n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 307 "main.y"
    {quadInstruction("LOGICAL_OR"); (yyval.TYPE_NODE) = logical((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"|"); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 308 "main.y"
    {printf("{*inside Rule*} expr -> NOT expr   : \n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 308 "main.y"
    {quadInstruction("NOT"); (yyval.TYPE_NODE) = logical((yyvsp[(2) - (3)].TYPE_NODE),NULL,"!"); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 309 "main.y"
    {printf("{*inside Rule*} expr -> '(' expr ')'   : \n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 309 "main.y"
    { (yyval.TYPE_NODE) = (yyvsp[(2) - (4)].TYPE_NODE);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 313 "main.y"
    {printf("{*inside Rule*} term -> INTEGER   : \n");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 313 "main.y"
    {quadPushInt((yyvsp[(1) - (2)].TYPE_INT)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 313 "main.y"
    { (yyval.TYPE_NODE) = createIntNode((yyvsp[(1) - (3)].TYPE_INT));    (yyval.TYPE_NODE)->value.intVal = (yyvsp[(1) - (3)].TYPE_INT);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 314 "main.y"
    {printf("{*inside Rule*} term -> FLOAT_NUMBER    : \n");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 314 "main.y"
    {quadPushFloat((yyvsp[(1) - (2)].TYPE_FLOAT)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 314 "main.y"
    { (yyval.TYPE_NODE) = createNode("float");  (yyval.TYPE_NODE)->value.floatVal = (yyvsp[(1) - (3)].TYPE_FLOAT);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 315 "main.y"
    {printf("{*inside Rule*} term -> STRING    : \n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 315 "main.y"
    {quadPushString((yyvsp[(1) - (2)].TYPE_STR));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 315 "main.y"
    { (yyval.TYPE_NODE) = createNode("string"); (yyval.TYPE_NODE)->value.stringVal = strdup((yyvsp[(1) - (3)].TYPE_STR));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 316 "main.y"
    {printf("{*inside Rule*} term -> TRUE_VAL    : \n");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 316 "main.y"
    {quadPushInt(1);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 316 "main.y"
    { (yyval.TYPE_NODE) = createNode("bool");   (yyval.TYPE_NODE)->value.boolVal = 1;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 317 "main.y"
    {printf("{*inside Rule*} term -> FALSE_VAL    : \n");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 317 "main.y"
    {quadPushInt(0);;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 317 "main.y"
    { (yyval.TYPE_NODE) = createNode("bool");   (yyval.TYPE_NODE)->value.boolVal = 0;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 318 "main.y"
    {printf("{*inside Rule*} term -> IDENTIFIER    : \n");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 318 "main.y"
    {quadPushIdentifier((yyvsp[(1) - (2)].TYPE_STR));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 318 "main.y"
    {checkOutOfScope((yyvsp[(1) - (3)].TYPE_STR)); checkInitialized((yyvsp[(1) - (3)].TYPE_STR)); (yyval.TYPE_NODE) = identifierValue((yyvsp[(1) - (3)].TYPE_STR)); setUsed((yyvsp[(1) - (3)].TYPE_STR));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 319 "main.y"
    {printf("{*inside Rule*} term -> '(' term ')'    : \n");;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 319 "main.y"
    { (yyval.TYPE_NODE) = (yyvsp[(2) - (4)].TYPE_NODE); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 328 "main.y"
    {checkConstIF((yyvsp[(3) - (3)].TYPE_NODE)); quadJumpFalseLabel(++labelNum);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 328 "main.y"
    {printf("IF () is detected \n");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 328 "main.y"
    {enterScope();;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 328 "main.y"
    {printf("IF (){} is detected \n");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 328 "main.y"
    {printf("asdasd");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 328 "main.y"
    {quadJumpEndLabel(); exitScope(); quadPopLabel();;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 328 "main.y"
    {;;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 330 "main.y"
    {printf("inside bare else  \n");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 330 "main.y"
    {;;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 331 "main.y"
    {;;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 331 "main.y"
    {printf("inside else  \n");;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 331 "main.y"
    {;;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 332 "main.y"
    {enterScope();;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 332 "main.y"
    {exitScope();;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 332 "main.y"
    {printf("else {} detected \n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 335 "main.y"
    {printf("switch case passed  \n");;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 335 "main.y"
    {quadPushLastIdentifierStack((yyvsp[(3) - (5)].TYPE_STR));setInit((yyvsp[(3) - (5)].TYPE_STR));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 335 "main.y"
    {enterScope();;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 335 "main.y"
    {exitScope();;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 335 "main.y"
    {quadPopLastIdentifierStack();;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 341 "main.y"
    {printf("before case \n");;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 341 "main.y"
    {quadPeakLastIdentifierStack(); quadJumpFalseLabel(++labelNum);;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 341 "main.y"
    {printf("inside case  \n");;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 341 "main.y"
    {quadPopLabel();;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 342 "main.y"
    {;;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 350 "main.y"
    {printf("Found a while loop!\n");;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 350 "main.y"
    {quadJumpFalseLabel(++labelNum);;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 350 "main.y"
    {enterScope();;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 350 "main.y"
    {/*end*/ exitScope(); quadJumpStartLabel(); quadPopLabel();;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 350 "main.y"
    {;;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 353 "main.y"
    {printf("for \n");;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 353 "main.y"
    {printf("for \n");;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 353 "main.y"
    {quadPushStartLabel(++startLabelNum);;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 353 "main.y"
    {quadJumpFalseLabel(++labelNum);;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 353 "main.y"
    {enterScope();;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 353 "main.y"
    {exitScope(); quadJumpStartLabel(); quadPopLabel();;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 353 "main.y"
    {;;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 359 "main.y"
    {enterScope();;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 359 "main.y"
    {exitScope();;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 359 "main.y"
    {quadJumpFalseLabel(++labelNum); quadJumpStartLabel(); quadPopLabel();;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 365 "main.y"
    {printf("{*inside Rule*} enumDef -> ENUM IDENTIFIER   : \n");;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 365 "main.y"
    {quadStartEnum((yyvsp[(2) - (3)].TYPE_STR)); checkSameScope((yyvsp[(2) - (3)].TYPE_STR)); insert((yyvsp[(2) - (3)].TYPE_STR), "enum", 1, 1, 0, scopes[scope_idx-1]);;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 365 "main.y"
    {quadEndEnum((yyvsp[(2) - (7)].TYPE_STR)); enumCounter=0;;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 369 "main.y"
    {printf("{*inside Rule*} enumBody -> IDENTIFIER   : \n");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 369 "main.y"
    {checkSameScope((yyvsp[(1) - (2)].TYPE_STR)); insert((yyvsp[(1) - (2)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue((yyvsp[(1) - (2)].TYPE_STR),enumValues); enumValues->value.intVal = 0; quadPushInt(++enumCounter); quadPopIdentifier((yyvsp[(1) - (2)].TYPE_STR));;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 370 "main.y"
    {printf("{*inside Rule*} enumBody -> IDENTIFIER '=' expr    : \n");;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 370 "main.y"
    {checkSameScope((yyvsp[(1) - (4)].TYPE_STR)); nodeNodeTypeCheck(enumValues,(yyvsp[(3) - (4)].TYPE_NODE)); insert((yyvsp[(1) - (4)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo((yyvsp[(3) - (4)].TYPE_NODE), "int")->value.intVal; updateIdentifierValue((yyvsp[(1) - (4)].TYPE_STR), enumValues); quadPopIdentifier((yyvsp[(1) - (4)].TYPE_STR));;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 371 "main.y"
    {printf("{*inside Rule*} enumBody -> IDENTIFIER ',' enumBody    : \n");;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 371 "main.y"
    {checkSameScope((yyvsp[(1) - (4)].TYPE_STR)); insert((yyvsp[(1) - (4)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue((yyvsp[(1) - (4)].TYPE_STR), enumValues); enumValues->value.intVal++; quadPushInt(++enumCounter); quadPopIdentifier((yyvsp[(1) - (4)].TYPE_STR));;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 372 "main.y"
    {printf("{*inside Rule*} enumBody -> IDENTIFIER '=' expr ',' enumBody    : \n");;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 372 "main.y"
    {checkSameScope((yyvsp[(1) - (6)].TYPE_STR)); nodeNodeTypeCheck(enumValues,(yyvsp[(3) - (6)].TYPE_NODE)); insert((yyvsp[(1) - (6)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo((yyvsp[(3) - (6)].TYPE_NODE), "int")->value.intVal; updateIdentifierValue((yyvsp[(1) - (6)].TYPE_STR), enumValues); quadPopIdentifier((yyvsp[(1) - (6)].TYPE_STR));;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 375 "main.y"
    {printf("{*inside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER   : \n");;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 375 "main.y"
    {checkOutOfScope((yyvsp[(1) - (3)].TYPE_STR)); identifierNodeTypeCheck((yyvsp[(1) - (3)].TYPE_STR),createNode("enum")); checkSameScope((yyvsp[(2) - (3)].TYPE_STR)); insert((yyvsp[(2) - (3)].TYPE_STR), "int", 0, 0, 0, scopes[scope_idx-1]);;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 376 "main.y"
    {printf("{*inside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER  '=' expr    : \n");;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 376 "main.y"
    {checkOutOfScope((yyvsp[(1) - (5)].TYPE_STR)); identifierNodeTypeCheck((yyvsp[(1) - (5)].TYPE_STR),createNode("enum")); checkSameScope((yyvsp[(2) - (5)].TYPE_STR)); insert((yyvsp[(2) - (5)].TYPE_STR), "int", 0, 1, 0, scopes[scope_idx-1]); nodeNodeTypeCheck((yyvsp[(4) - (5)].TYPE_NODE),createIntNode(0)); updateIdentifierValue((yyvsp[(2) - (5)].TYPE_STR),castingTo((yyvsp[(4) - (5)].TYPE_NODE), "int")); quadPopIdentifier((yyvsp[(2) - (5)].TYPE_STR));;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 382 "main.y"
    {printf("{*inside Rule*} printList -> expr      : \n");;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 382 "main.y"
    {printNode((yyvsp[(1) - (2)].TYPE_NODE));;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 383 "main.y"
    {printf("{*inside Rule*} printList -> printList ',' expr      : \n");;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 383 "main.y"
    {char* str1 = castingTo((yyvsp[(3) - (4)].TYPE_NODE), "string")->value.stringVal; char* str2 = printStringValues->value.stringVal;  strcat(str1, str2); printStringValues->value.stringVal =  str1;;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 386 "main.y"
    {printf("{*inside Rule*} statement -> assignment  : \n");;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 386 "main.y"
    {;;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 387 "main.y"
    {printf("{*inside Rule*} statement ->  expr  : \n");;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 388 "main.y"
    {printf("{*inside Rule*} statement ->  decleration  : \n");;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 388 "main.y"
    {;;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 389 "main.y"
    {printf("{*inside Rule*} statement ->  EXIT  : \n");;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 389 "main.y"
    {exit(EXIT_SUCCESS);;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 390 "main.y"
    {printf("{*inside Rule*} statement ->  BREAK  : \n");;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 390 "main.y"
    {quadJumpEndLabel();;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 391 "main.y"
    {printf("{*inside Rule*} statement ->  CONTINUE  : \n");;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 391 "main.y"
    {;;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 392 "main.y"
    {printf("{*inside Rule*} statement ->  RETURN  : \n");;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 392 "main.y"
    {quadReturn();;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 393 "main.y"
    {printf("{*inside Rule*} statement ->  RETURN expr  : \n");;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 393 "main.y"
    {quadReturn(); (yyval.TYPE_VOID) = (yyvsp[(2) - (3)].TYPE_NODE);;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 394 "main.y"
    {printf("{*inside Rule*} statement ->  PRINT  '(' expr ')' : \n");;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 394 "main.y"
    {printNode((yyvsp[(3) - (5)].TYPE_NODE));;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 395 "main.y"
    {printf("{*inside Rule*} statement ->  PRINT  '(' printList ')': \n");;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 395 "main.y"
    {(yyval.TYPE_VOID) = (yyvsp[(3) - (5)].TYPE_NODE);;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 400 "main.y"
    {printf("{*inside Rule*} statements -> statement ';' : \n");;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 400 "main.y"
    {;;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 401 "main.y"
    {printf("{*inside Rule*} statements -> controlStatement  : \n");;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 401 "main.y"
    {;;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 402 "main.y"
    {printf("{*inside Rule*} statements -> statements statement ';'  : \n");;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 402 "main.y"
    {;;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 403 "main.y"
    {enterScope();;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 403 "main.y"
    {printf("{*inside Rule*} statements -> '{' codeBlock '}'   : \n");;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 403 "main.y"
    {exitScope();;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 404 "main.y"
    {printf("{*inside Rule*} statements -> statements controlStatement : \n");;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 405 "main.y"
    {enterScope();;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 405 "main.y"
    {printf("{*inside Rule*} statements -> statements '{' codeBlock '}'  : \n");;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 405 "main.y"
    {exitScope();;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 405 "main.y"
    {;;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 410 "main.y"
    {printf("{*inside Rule*} codeBlock -> statements ';' : \n");;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 415 "main.y"
    {quadPopIdentifier((yyvsp[(2) - (2)].TYPE_STR));;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 415 "main.y"
    {checkSameScope((yyvsp[(2) - (3)].TYPE_STR)); insert((yyvsp[(2) - (3)].TYPE_STR), (yyvsp[(1) - (3)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]) ; argCount = sym_table_idx-argCount;;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 416 "main.y"
    {quadPopIdentifier((yyvsp[(2) - (2)].TYPE_STR));;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 416 "main.y"
    {checkSameScope((yyvsp[(2) - (3)].TYPE_STR)); insert((yyvsp[(2) - (3)].TYPE_STR), (yyvsp[(1) - (3)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]) ;;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 421 "main.y"
    {quadStartFunction((yyvsp[(2) - (2)].TYPE_STR));;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 421 "main.y"
    {checkSameScope((yyvsp[(2) - (3)].TYPE_STR)); insert((yyvsp[(2) - (3)].TYPE_STR), (yyvsp[(1) - (3)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]); argCount = sym_table_idx; enterScope();;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 422 "main.y"
    {printf("here \n");;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 422 "main.y"
    {exitScope(); quadEndFunction((yyvsp[(2) - (9)].TYPE_STR)); updateSymbolParam((yyvsp[(2) - (9)].TYPE_STR), argCount);;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 424 "main.y"
    {printf("definitions with params  \n");;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 425 "main.y"
    {printf("definitions without params  \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 3338 "main.tab.c"
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
#line 432 "main.y"


void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}


// Create Int Node
struct nodeType* createIntNode(int value) {
    printf("{*inside Function*} createIntNode(int value = %d): \n",value);
    struct nodeType* node = malloc(sizeof(struct nodeType));
    node->type = "int";
    node->isConst = 1;
    node->value.intVal = value;
    return node;
}

// Create String Node

struct nodeType* createStringNode(char* value) {
    printf("{*inside Function*} createStringNode(char* value = %s): \n",value);
    struct nodeType* node = malloc(sizeof(struct nodeType));
    node->type = "string";
    node->isConst = 0;
    node->value.stringVal = strdup(value);
}
// Create Node
struct nodeType* createNode(char* type) {
    printf("{*inside Function*} createNode(char* type = %s): \n",type);
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
    printf("{*inside Function*} castingTo(struct nodeType* term = %s NodeType, char *type = %s) :\n", term->type , type);
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
    printf("{*inside Function*} arithmatic(struct nodeType* op1 = %s NodeType,struct nodeType* op2 = %s NodeType, char *op = %s) :\n", op1->type ,op2->type , op);
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
    printf("{*inside Function*} doComparison(struct nodeType* op1 = %s NodeType,struct nodeType* op2 = %s NodeType, char *op = %s) :\n", op1->type ,op2->type , op);
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
        printf("{*inside Function*} logical(struct nodeType* op1 = %s NodeType,struct nodeType* op2 = %s NodeType, char *op = %s) :\n", op1->type ,op2->type , op);
        bool_op2 = castingTo(op2,"bool");  
    }
    else{
        printf("{*inside Function*} logical(struct nodeType* op1 = %s NodeType,struct nodeType* op2 = NULL NodeType, char *op = %s) :\n", op1->type , op);
        bool_op2 = NULL;
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
    printf("{*inside Function*} Negation(struct nodeType* term = %s NodeType) :\n", term->type);
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
    printf("{*inside Function*} computeIdentifierIndex(char* name = %s) :\n", name);
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
    printf("{*inside Function*} identifierNodeTypeCheck(char* name = %s, struct nodeType* node = %s NodeType) :\n", name ,node->type);
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
    printf("{*inside Function*} nodeNodeTypeCheck(struct nodeType* node1 = %s NodeType, struct nodeType* node2 = %s NodeType) :\n", node1->type, node2->type);
    if(strcmp(node1->type, node2->type) != 0) {
        //Log_SEMANTIC_ERROR(TYPE_MISMATCH, node->type); 
    }
    return;
}

void updateSymbolParam(char* symbol, int param){
    int bucket = computeIdentifierIndex(symbol);

    printf("{*inside Function*} updateSymbolParam(char* symbol = %s, int param = %d )\n", symbol , param);
    symbol_Table [bucket].value.intVal = param;
}

struct nodeType* identifierValue(char* name){
    printf("{*inside Function*} identifierValue(char* name = %s) :\n", name);
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
    printf("{*inside Function*} updateIdentifierValue(char* name = %s, struct nodeType * node = %s NodeType)\n", name, node->type);
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
    printf("{*inside Function*} printNode(struct nodeType* node = %s NodeType)\n", node->type);
    struct nodeType* str_p = malloc(sizeof(struct nodeType));
    str_p = castingTo(node,"string");
    printf( str_p->value.stringVal);  
}

    

// Insert the variable in the symbol table
void insert(char* name, char* type, int isConst, int isInit, int isUsed, int scope){
    printf("{*inside Function*} insert(char* name = %s, char* type = %s, int isConst = %d, int isInit = %d, int isUsed = %d, int scope = %d )\n", name, type, isConst, isInit, isUsed ,scope);

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
    printf("{*inside Function*} enterScope() ");
    scopes[scope_idx] = scope_lvl;
    scope_idx++;
    scope_lvl++;
}
//Deallocating the memory for those local variables declared within a scope 
void cleanedUpScope(int scope_idx) {
    printf("{*inside Function*} cleanedUpScope(int scope_idx = %d)\n", scope_idx);
    for(int i=0; i<sym_table_idx ;i++) {
        if(symbol_Table[i].scope == scopes[scope_idx-1]) {
            // Ghost Varible
            symbol_Table[i].scope = -1;     // -1: means was in scope but cleaned ,but, 0: means no scope     
        }
    }
}
// Exit the scope
void exitScope() {
    printf("{*inside Function*} exitScope() ");
    cleanedUpScope(scope_idx);
    scope_idx--;
}
// Check if the variable is declared in the same scope
void checkSameScope(char* name) {
    printf("{*inside Function*} checkSameScope(char* name = %s)\n", name );
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
    printf("{*inside Function*} checkOutOfScope(char* name = %s)\n", name );
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
    printf("{*inside Function*} checkInitialized(char* name = %s)\n", name );
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
    printf("{*inside Function*} checkConst(char* name = %s)\n", name );
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
    printf("{*inside Function*} checkConstIF(struct nodeType* node = %s NodeType \n", node->type);
    if(node->isConst==1){
        semanticError(CONSTANT_IF, node->type/*node->value.boolVal !=0*/); //TODO: check warning about expected 'char *' but argument is of type 'int'
    }

}

// Print the symbol table
void printSymbolTable() {
    printf("{*inside Function*} printSymbolTable() \n");
    for(int i=0; i<sym_table_idx ;i++) {
        printf("SymbolTable() : %s, declared:%d, const:%d, Symbol table idx:%d\n", symbol_Table [i].name, symbol_Table [i].isDecl, symbol_Table [i].isConst, i); 
    }
}


// ------------------------------------------------------------------------------- 
// Setter functions 
// -------------------------------------------------------------------------------  
void setInit(char* name) {
    printf("{*inside Function*} setInit(char* name = %s)\n", name );
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
    printf("{*inside Function*} setUsed(char* name = %s)\n", name );
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

void quadStartFunction(char function) // TODO: make it string isnetad of char
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tPROC %c\n", line, function);
        }
}
void quadEndFunction(char function)
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tENDPROC %c\n", line, function);
        }
}
void quadCallFunction(char function)
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tCALL %c\n", line, function);
        }
}
void quadReturn()
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tRET\n", line);
        }
}
void quadInstruction(const char* instruction)
{
        if (SHOW_Quads) {
               
                printf("Quads(%d) \t%s\n", line, instruction);
        }
}
void quadPushInt(int val)
{
       if (SHOW_Quads) {
               printf("Quads(%d) \tPUSH %d\n", line, val);
       }
}
void quadPushFloat(float val)
{
       if (SHOW_Quads) {
               printf("Quads(%d) \tPUSH %f\n", line, val);
       }
}
void quadPushIdentifier(char symbol)
{
       if (SHOW_Quads) {
               printf("Quads(%d) \tPUSH %c\n", line, symbol);
       }
}
void quadPushString(char* str)
{
       if (SHOW_Quads) {
               printf("Quads(%d) \tPUSH %s\n", line, str);
       }
}
void quadPopIdentifier(char symbol)
{
       if (SHOW_Quads) {
            printf("Quads(%d) \tPOP %c\n\n", line, symbol);
       }
}
void quadPushEndLabel(int endLabelNum)
{
       if (SHOW_Quads) {
            /* push the labelNum to the stack */
            endLabelStack[++endLabelstackPointer] = endLabelNum;
       }
}
void quadJumpEndLabel() // jump to the first end label in the stack
{
      if (SHOW_Quads) {
        /* get last  endLabelNum from the stack*/
        int endLabelNum = endLabelStack[endLabelstackPointer];
        printf("Quads(%d) \tJMP EndLabel_%d\n", line, endLabelNum);
       }
}
void quadPopEndLabel(){
        if (endLabelstackPointer < 0){
            printf("Quads(%d) Error: No end label to add. Segmenration Fault\n", line);
            return;
        }
        /* get the last endLabelNum from the stack */
        int endLabelNum = endLabelStack[endLabelstackPointer--];
        if (SHOW_Quads) {
                printf("Quads(%d) EndLabel_%d:\n", line, endLabelNum);
        }
}
void quadJumpFalseLabel(int labelNum)
{
       if (SHOW_Quads) {
               printf("Quads(%d) \tJF Label_%d\n", line, labelNum);
               /* push the labelNum to the stack */
                labelStack[labelStackPointer++] = labelNum;
       }
}
void quadPopLabel(){
        if (labelStackPointer < 0){
            printf("Quads(%d) Error: No end label to add. Segmenration Fault\n", line);
            return;
        }
        /* get the last labelNum from the stack */
        int labelNum = labelStack[--labelStackPointer];
        if (SHOW_Quads) {
                printf("Quads(%d) Label_%d:\n",line, labelNum);
        }
}
void quadPushLastIdentifierStack(char identifier){
        if (SHOW_Quads) {
            /* add the IDENTIFIER to the stack */
            lastIdentifierStack[++lastIdentifierStackPointer] = identifier;
        }
}
void quadPeakLastIdentifierStack(){
    if (lastIdentifierStackPointer < 0){
        printf("Quads(%d) Error: No last identifier to peak. Segmenration Fault\n", line);
        return;
    }
    /* get the last identifier from the stack */
    char identifier = lastIdentifierStack[lastIdentifierStackPointer];
    if (SHOW_Quads) {
            printf("Quads(%d) \tPUSH %c\n", line, identifier);
    }
}
void quadPopLastIdentifierStack(){
    if (lastIdentifierStackPointer < 0){
        printf("Quads(%d) Error: No last identifier to pop. Segmenration Fault\n", line);
        return;
    }
    /* get the last IDENTIFIER from the stack */
    char identifier = lastIdentifierStack[lastIdentifierStackPointer--];
}


void quadPushStartLabel(int startLabelNum){
        if (SHOW_Quads) {
            /* push the labelNum to the stack */
            startLabelStack[++startLabelstackPointer] = startLabelNum;
            if (SHOW_Quads) {
                printf("Quads(%d) StartLabel_%d:\n", line, startLabelNum);
            }
        }
}
void quadJumpStartLabel(){
        if (SHOW_Quads) {
        /* get last  startLabelNum from the stack*/
        int startLabelNum = startLabelStack[startLabelstackPointer];
        printf("Quads(%d) \tJMP StartLabel_%d\n", line, startLabelNum);
       }
}
void quadPopStartLabel(){
    if (startLabelstackPointer < 0){
            printf("Quads(%d) Error: No start label to add. Segmenration Fault\n", line);
            return;
        }
    /* get the last endLabelNum from the stack */
    int startLabelNum = startLabelStack[startLabelstackPointer--];
}

void quadStartEnum(char enumName) 
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tENUM %c\n", line, enumName);
        }
}
void quadEndEnum(char enumName) 
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tENDENUM %c\n", line, enumName);
        }
}

// ========================================

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
