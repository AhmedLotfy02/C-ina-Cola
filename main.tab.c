
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
    TODO: add  typedef   
    TODO: Check  enum 
    ////////////////////////////////*/
    // USE THIS FOR TEXT FILES: Get-Content input.txt | .\a.exe
    #include <stdio.h>     
    #include <stdlib.h> 
    #include <string.h>
    #include <ctype.h>
    
    
    void yyerror (char*);       
    int yylex(void);
    void printSymbolTable();
    extern int line;
    
    // Semantic Erros:
    #define UNDECLARED 1 /*
    //in-Case: use of IDENTIFIER in Rules: {assignment: IDENTIFIER '='  expr},{term: IDENTIFIER} ,
    to Check if:
        1) the IDENTIFIER is Not Declared before.
    */
    #define REDECLARED 2/*
    //in-Case: Declare New IDENTIFIER in Rules: {decleration: .... IDENTIFIER ....},{...: ...IDENTIFIER...} ,
    to Check if:
        1) the IDENTIFIER is declared in and only in the current Scope of Program.
    */
    #define OUT_OF_SCOPE 3 /*
    //in-Case: use of IDENTIFIER in Rules: {assignment: IDENTIFIER '='  expr},{term: IDENTIFIER} ,
    to Check if:
        1) Declared out of the current Scope and downstream to the Base scope{0} 
        2) or Declared but Removed when Exit it's Scope and become Ghost Variable 
    */
    #define UNINITIALIZED 4/*
    //in-Case: use of IDENTIFIER in Rules: {term: IDENTIFIER} ,
    to Check if:
        1) IDENTIFIER Variable is used before initialized 
    */
    #define CONSTANT 5/*
    //in-Case: use of IDENTIFIER in Rules: {assignment: IDENTIFIER '='  expr} 
    to Check if:
        1) IDENTIFIER Variable is Constant in the Nearest Scope from the current Scope and downstream to the Base scope{0} 
    */
    #define TYPE_MISMATCH 6/*
    //in-Case: use of IDENTIFIER in Rules: {assignment: IDENTIFIER '='  expr},{decleration: dataType IDENTIFIER  '='  expr} ,{decleration: dataModifier dataType IDENTIFIER  '='  expr }
    //in-Case: use of IDENTIFIER in Functions: { arithmatic(struct nodeType* op1, struct nodeType*op2, char* op),doComparison(struct nodeType* op1, struct nodeType*op2, char* op),logical(struct nodeType* op1, struct nodeType* op2, char* op),identifierNodeTypeCheck(char* name , struct nodeType* node),nodeNodeTypeCheck(struct nodeType* node1, struct nodeType* node2) },Negation(struct nodeType* term).
    to Check if:
        1) IDENTIFIER->type !=  expr->type in assignment or decleration
        2) Using Negation() but term->type == String type.
        3) Using arithmatic() or doComparison() or logical() ,and op1->type != op2->type passed to function.
        4) Using arithmatic() with op1->type = Sting ,and op = {'-','*','/'}  passed to function.
    */
    #define UNUSED 7/*
    //in-Case: Declare or Intialize IDENTIFIER in Rules: {assignment: IDENTIFIER '='  expr},{decleration: dataType IDENTIFIER  '='  expr} But not used ever in {term: IDENTIFIER} 
    to Check if:
        1) All IDENTIFIER Varibles are Declared or Intialized But not used ever in {term: IDENTIFIER, ...}  
    */
    #define CONSTANT_IF 8/*
    //in-Case: use of expr in Rules: {ifCondition  : IF '(' expr ')' ...} ,
    to Check if:
        1) expr is Constant expression and = False
        2) or expr is Constant expression and = True 
        3) when expr => Constant{0} * Varible{expr} or Varible{expr} * Constant{0} 
        4) when expr => Constant{0} / Varible{expr} 
        5) when expr => Constant{0} % Varible{expr}
        6) when expr => Constant{0} AND Varible{expr} or Varible{expr} AND Constant{0}
        7) when expr => Constant{1} OR Varible{expr} or Varible{expr} OR Constant{1}
    */
    
    void Show_Semantic_Error(int Semantic_Error,char* Variable_Name){
        int Error_Line_Number = line;
        switch(Semantic_Error){
            case UNDECLARED:
                printf("Semantic Error: Variable { %s } is Undeclared at line : { %d }\n",Variable_Name,Error_Line_Number);
                break;
            case REDECLARED:
                printf("Semantic Error: Variable { %s } is Redeclared at line : { %d }\n",Variable_Name,Error_Line_Number);
                break;
            case OUT_OF_SCOPE:
                printf("Semantic Error: Variable { %s } is Out of Scope at line : { %d }\n",Variable_Name,Error_Line_Number);
                break;
            case UNINITIALIZED:
                printf("Semantic Error: Variable { %s } is Uninitialized at line : { %d }\n",Variable_Name,Error_Line_Number);
                break;
            case CONSTANT:
                printf("Semantic Error: Variable { %s } is Constant at line : { %d }\n",Variable_Name,Error_Line_Number);
                break;
            case TYPE_MISMATCH:
                printf("Semantic Error: Type Mismatch at line : { %d }\n",Error_Line_Number);
                break;
            case UNUSED:
                printf("Semantic Error: Variable { %s } is Declared but not Used at line : { %d }\n",Variable_Name,Error_Line_Number);
                break;
            case CONSTANT_IF:
                printf("Semantic Error: Expression is Constant in if condition at line : { %d } , and is always { %s }\n",Error_Line_Number,(Variable_Name ? "True" : "False"));
                break;
            default:
                printf("Semantic Error: Unknown error at line : { %d }\n",Error_Line_Number);
                break;
        }
      
    }

    //if
    int ifCon=0;
    int ifConMatch=0;
    int fromElse=0;

    int switchC=0;
    int switchMatch=0;
    int funcFirstarg=0;
    int funcArgCnt=0;
    int forLoopFound=0;
    int forLoopCnt=0;
    int whileLoopFound=0;
    int whileLoopCnt=0;
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
    void quadPopIdentifier(char* symbol);
    void quadPushIdentifier(char* symbol);
    void quadInstruction(const char* instruction);
    void quadPushFloat(float val);
    void quadPushString(char* str);
    void quadStartFunction(char* function);
    void quadEndFunction(char* function);
    void quadCallFunction(char* function);
    void quadReturn();

    void quadPushLastIdentifierStack(char* identifier);
    void quadPeakLastIdentifierStack(); 
    void quadPopLastIdentifierStack();

    int argCount = 0;
    int enumCounter = 0;
    int funcPointer = -1;
    int paramCount = 0;


    int lastIdentifierStackPointer = -1;
    char* lastIdentifierStack[MAX_STACK_SIZE];

    void quadJumpStartLabel();
    void quadPushStartLabel(int startLabelNum);
    void quadPopStartLabel();

    int startLabelNum = 0;
    int startLabelstackPointer = -1;
    int startLabelStack[MAX_STACK_SIZE];

    void quadStartEnum(char* enumName);
    void quadEndEnum(char* enumName);

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
    int checkInitialized(char* name); 
    int checkSameScope(char* name);
    int checkUndeclared_and_OutOfScope(char* name);
    int checkConst(char* name);
    void checkConstIF(struct nodeType* node);
    void updateSymbolParam(char* symbol, int param);



/* Line 189 of yacc.c  */
#line 308 "main.tab.c"

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
     FLOAT_ = 268,
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
#line 239 "main.y"

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
#line 396 "main.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 408 "main.tab.c"

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  186
/* YYNRULES -- Number of rules.  */
#define YYNRULES  251
/* YYNRULES -- Number of states.  */
#define YYNSTATES  357

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
      46,    47,    15,    12,    52,    13,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    51,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,     0,     3,     4,     5,     8,     9,    12,    13,    17,
      18,    22,    23,    24,    27,    29,    30,    33,    34,    37,
      38,    41,    42,    45,    46,    49,    50,    53,    54,    57,
      58,    61,    62,    63,    67,    68,    69,    70,    76,    77,
      78,    79,    87,    88,    89,    90,    99,   100,   101,   107,
     108,   111,   112,   116,   117,   120,   121,   127,   128,   132,
     133,   138,   139,   144,   145,   150,   151,   156,   157,   162,
     163,   168,   169,   174,   175,   180,   181,   186,   187,   192,
     193,   198,   199,   204,   205,   210,   211,   215,   216,   221,
     222,   223,   224,   229,   230,   231,   232,   237,   238,   239,
     240,   245,   246,   247,   248,   253,   254,   255,   256,   261,
     262,   263,   264,   269,   270,   271,   277,   278,   279,   280,
     281,   282,   283,   298,   299,   301,   302,   303,   308,   309,
     310,   311,   319,   320,   321,   322,   323,   324,   337,   340,
     342,   343,   344,   345,   353,   354,   359,   360,   361,   362,
     363,   364,   365,   379,   380,   381,   382,   383,   384,   385,
     403,   404,   405,   417,   418,   419,   420,   429,   430,   431,
     435,   436,   437,   443,   444,   445,   451,   452,   453,   461,
     462,   463,   468,   469,   470,   477,   478,   479,   483,   484,
     485,   491,   492,   493,   497,   498,   501,   502,   503,   507,
     508,   509,   513,   514,   515,   519,   520,   521,   525,   526,
     527,   531,   532,   536,   537,   538,   545,   546,   552,   553,
     554,   559,   560,   561,   565,   566,   567,   573,   574,   575,
     576,   583,   584,   588,   589,   590,   591,   592,   601,   602,
     603,   607,   608,   612,   613,   614,   621,   622,   623,   624,
     634,   638
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      54,     0,    -1,    -1,    -1,   234,    55,    -1,    -1,   212,
      56,    -1,    -1,   212,    54,    57,    -1,    -1,   234,    54,
      58,    -1,    -1,    -1,    60,   154,    -1,   161,    -1,    -1,
      61,   128,    -1,    -1,    62,   142,    -1,    -1,    63,   168,
      -1,    -1,    39,    65,    -1,    -1,    40,    67,    -1,    -1,
      41,    68,    -1,    -1,    42,    69,    -1,    -1,    43,    70,
      -1,    -1,    -1,    44,    71,    72,    -1,    -1,    -1,    -1,
      66,    45,    74,    75,    76,    -1,    -1,    -1,    -1,    66,
      45,     3,    88,    77,    78,    79,    -1,    -1,    -1,    -1,
      64,    66,    45,     3,    88,    80,    81,    82,    -1,    -1,
      -1,    45,     3,    88,    84,    85,    -1,    -1,   171,    86,
      -1,    -1,    24,   184,    87,    -1,    -1,   107,    89,    -1,
      -1,    46,    66,    47,   107,    90,    -1,    -1,    13,   107,
      91,    -1,    -1,    88,    12,    88,    92,    -1,    -1,    88,
      13,    88,    93,    -1,    -1,    88,    15,    88,    94,    -1,
      -1,    88,    16,    88,    95,    -1,    -1,    88,    17,    88,
      96,    -1,    -1,    88,     7,    88,    97,    -1,    -1,    88,
       6,    88,    98,    -1,    -1,    88,     9,    88,    99,    -1,
      -1,    88,    11,    88,   100,    -1,    -1,    88,    10,    88,
     101,    -1,    -1,    88,     8,    88,   102,    -1,    -1,    88,
       5,    88,   103,    -1,    -1,    88,     4,    88,   104,    -1,
      -1,    14,    88,   105,    -1,    -1,    46,    88,    47,   106,
      -1,    -1,    -1,    -1,    18,   108,   109,   110,    -1,    -1,
      -1,    -1,    19,   111,   112,   113,    -1,    -1,    -1,    -1,
      20,   114,   115,   116,    -1,    -1,    -1,    -1,    21,   117,
     118,   119,    -1,    -1,    -1,    -1,    22,   120,   121,   122,
      -1,    -1,    -1,    -1,    45,   123,   124,   125,    -1,    -1,
      -1,    46,   107,    47,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    46,   129,    88,   130,   131,    47,
      48,   132,   133,   227,    49,   134,   135,    -1,    -1,   136,
      -1,    -1,    -1,    29,   137,   138,   128,    -1,    -1,    -1,
      -1,    29,    48,   139,   140,   227,    49,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    46,    45,   143,    47,   144,
     145,    48,   146,   148,    49,   147,    -1,   148,   149,    -1,
     149,    -1,    -1,    -1,    -1,    31,   150,    88,   151,    50,
     152,   212,    -1,    -1,    32,    50,   153,   212,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    46,    88,   155,    47,
     156,   157,    48,   158,   227,    49,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    46,   162,    73,    51,
     163,   164,    88,    51,   165,    83,    47,    48,   166,   227,
      49,   167,    -1,    -1,    -1,    37,    48,   169,   227,    49,
     170,    38,    46,    88,    47,    51,    -1,    -1,    -1,    -1,
      24,    45,   172,   173,    48,   175,    49,   174,    -1,    -1,
      -1,    45,   176,   177,    -1,    -1,    -1,    45,     3,    88,
     178,   179,    -1,    -1,    -1,    45,    52,   175,   180,   181,
      -1,    -1,    -1,    45,     3,    88,    52,   175,   182,   183,
      -1,    -1,    -1,    45,    45,   185,   186,    -1,    -1,    -1,
      45,    45,     3,    88,   187,   188,    -1,    -1,    -1,    88,
     190,   191,    -1,    -1,    -1,   189,    52,    88,   192,   193,
      -1,    -1,    -1,    83,   195,   196,    -1,    -1,    88,   197,
      -1,    -1,    -1,    73,   198,   199,    -1,    -1,    -1,    27,
     200,   201,    -1,    -1,    -1,    35,   202,   203,    -1,    -1,
      -1,    36,   204,   205,    -1,    -1,    -1,    23,   206,   207,
      -1,    -1,    23,    88,   208,    -1,    -1,    -1,    25,    46,
      88,    47,   209,   210,    -1,    -1,    25,    46,   189,    47,
     211,    -1,    -1,    -1,   194,    51,   213,   214,    -1,    -1,
      -1,    59,   215,   216,    -1,    -1,    -1,   212,   194,    51,
     217,   218,    -1,    -1,    -1,    -1,    48,   219,   227,    49,
     220,   221,    -1,    -1,   212,    59,   222,    -1,    -1,    -1,
      -1,    -1,   212,    48,   223,   227,    49,   224,   225,   226,
      -1,    -1,    -1,   212,   228,   229,    -1,    -1,    66,    45,
     231,    -1,    -1,    -1,    66,    45,   232,   233,    52,   230,
      -1,    -1,    -1,    -1,    66,    45,   235,   236,   237,   238,
      48,   227,    49,    -1,    46,   230,    47,    -1,    46,    47,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   305,   305,   307,   307,   308,   308,   309,   309,   310,
     310,   311,   315,   315,   316,   317,   317,   318,   318,   319,
     319,   324,   324,   326,   326,   327,   327,   328,   328,   329,
     329,   330,   330,   330,   333,   333,   333,   333,   334,   334,
     334,   334,   335,   335,   335,   335,   340,   340,   340,   341,
     341,   342,   342,   347,   347,   348,   348,   349,   349,   350,
     350,   351,   351,   352,   352,   353,   353,   354,   354,   355,
     355,   356,   356,   357,   357,   358,   358,   359,   359,   360,
     360,   361,   361,   362,   362,   363,   363,   364,   364,   368,
     368,   368,   368,   370,   370,   370,   370,   371,   371,   371,
     371,   372,   372,   372,   372,   373,   373,   373,   373,   374,
     374,   374,   374,   375,   375,   375,   384,   384,   384,   384,
     384,   384,   384,   386,   386,   387,   387,   387,   388,   388,
     388,   388,   391,   391,   391,   391,   391,   391,   393,   394,
     397,   397,   397,   397,   398,   398,   406,   406,   406,   406,
     406,   406,   406,   409,   409,   409,   409,   409,   409,   409,
     415,   415,   415,   421,   421,   421,   421,   425,   425,   425,
     426,   426,   426,   427,   427,   427,   428,   428,   428,   431,
     431,   431,   432,   432,   432,   438,   438,   438,   439,   439,
     439,   442,   442,   442,   443,   443,   444,   444,   444,   445,
     445,   445,   446,   446,   446,   447,   447,   447,   448,   448,
     448,   449,   449,   450,   450,   450,   451,   451,   456,   456,
     456,   457,   457,   457,   458,   458,   458,   459,   459,   459,
     459,   460,   460,   461,   461,   461,   461,   461,   466,   466,
     466,   471,   471,   472,   472,   472,   477,   477,   478,   477,
     480,   481
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "OR", "AND", "NEQ", "EQ", "LEQ",
  "LT", "GEQ", "GT", "'+'", "'-'", "NOT", "'*'", "'/'", "'%'", "INTEGER",
  "FLOAT_", "STRING", "TRUE_VAL", "FALSE_VAL", "RETURN", "ENUM", "PRINT",
  "ASSERT", "EXIT", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "WHILE",
  "FOR", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "CONST", "INT_DATA_TYPE",
  "FLOAT_DATA_TYPE", "STRING_DATA_TYPE", "BOOL_DATA_TYPE",
  "VOID_DATA_TYPE", "IDENTIFIER", "'('", "')'", "'{'", "'}'", "':'", "';'",
  "','", "$accept", "program", "$@1", "$@2", "$@3", "$@4",
  "controlStatement", "$@5", "$@6", "$@7", "$@8", "dataModifier", "$@9",
  "dataType", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "decleration", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "$@23", "$@24", "assignment", "$@25", "$@26", "$@27", "$@28", "expr",
  "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "$@37",
  "$@38", "$@39", "$@40", "$@41", "$@42", "$@43", "$@44", "$@45", "$@46",
  "term", "$@47", "$@48", "$@49", "$@50", "$@51", "$@52", "$@53", "$@54",
  "$@55", "$@56", "$@57", "$@58", "$@59", "$@60", "$@61", "$@62", "$@63",
  "$@64", "$@65", "$@66", "ifCondition", "$@67", "$@68", "$@69", "$@70",
  "$@71", "$@72", "elseCondition", "$@73", "$@74", "$@75", "$@76", "$@77",
  "$@78", "switchCase", "$@79", "$@80", "$@81", "$@82", "$@83", "caseList",
  "case", "$@84", "$@85", "$@86", "$@87", "while", "$@88", "$@89", "$@90",
  "$@91", "$@92", "$@93", "forLoop", "$@94", "$@95", "$@96", "$@97",
  "$@98", "$@99", "repeatUntil", "$@100", "$@101", "enumDefinition",
  "$@102", "$@103", "$@104", "enumBody", "$@105", "$@106", "$@107",
  "$@108", "$@109", "$@110", "$@111", "$@112", "enumDeclaration", "$@113",
  "$@114", "$@115", "$@116", "printList", "$@117", "$@118", "$@119",
  "$@120", "statement", "$@121", "$@122", "$@123", "$@124", "$@125",
  "$@126", "$@127", "$@128", "$@129", "$@130", "$@131", "$@132", "$@133",
  "$@134", "$@135", "$@136", "$@137", "stmts", "$@138", "$@139", "$@140",
  "$@141", "$@142", "$@143", "$@144", "$@145", "$@146", "$@147", "$@148",
  "$@149", "$@150", "$@151", "codeBlock", "$@152", "$@153", "functionArgs",
  "$@154", "$@155", "$@156", "functionDefinition", "$@158", "$@159",
  "$@160", "functionDefinitionAfter", 0
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
      58,    59,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    54,    56,    54,    57,    54,    58,
      54,    54,    60,    59,    59,    61,    59,    62,    59,    63,
      59,    65,    64,    67,    66,    68,    66,    69,    66,    70,
      66,    71,    72,    66,    74,    75,    76,    73,    77,    78,
      79,    73,    80,    81,    82,    73,    84,    85,    83,    86,
      83,    87,    83,    89,    88,    90,    88,    91,    88,    92,
      88,    93,    88,    94,    88,    95,    88,    96,    88,    97,
      88,    98,    88,    99,    88,   100,    88,   101,    88,   102,
      88,   103,    88,   104,    88,   105,    88,   106,    88,   108,
     109,   110,   107,   111,   112,   113,   107,   114,   115,   116,
     107,   117,   118,   119,   107,   120,   121,   122,   107,   123,
     124,   125,   107,   126,   127,   107,   129,   130,   131,   132,
     133,   134,   128,   136,   135,   137,   138,   135,   139,   140,
     141,   135,   143,   144,   145,   146,   147,   142,   148,   148,
     150,   151,   152,   149,   153,   149,   155,   156,   157,   158,
     159,   160,   154,   162,   163,   164,   165,   166,   167,   161,
     169,   170,   168,   172,   173,   174,   171,   176,   177,   175,
     178,   179,   175,   180,   181,   175,   182,   183,   175,   185,
     186,   184,   187,   188,   184,   190,   191,   189,   192,   193,
     189,   195,   196,   194,   197,   194,   198,   199,   194,   200,
     201,   194,   202,   203,   194,   204,   205,   194,   206,   207,
     194,   208,   194,   209,   210,   194,   211,   194,   213,   214,
     212,   215,   216,   212,   217,   218,   212,   219,   220,   221,
     212,   222,   212,   223,   224,   225,   226,   212,   228,   229,
     227,   231,   230,   232,   233,   230,   235,   236,   237,   234,
     238,   238
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     2,     0,     2,     0,     3,     0,
       3,     0,     0,     2,     1,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     0,     3,     0,     0,     0,     5,     0,     0,
       0,     7,     0,     0,     0,     8,     0,     0,     5,     0,
       2,     0,     3,     0,     2,     0,     5,     0,     3,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     3,     0,     4,     0,
       0,     0,     4,     0,     0,     0,     4,     0,     0,     0,
       4,     0,     0,     0,     4,     0,     0,     0,     4,     0,
       0,     0,     4,     0,     0,     5,     0,     0,     0,     0,
       0,     0,    14,     0,     1,     0,     0,     4,     0,     0,
       0,     7,     0,     0,     0,     0,     0,    12,     2,     1,
       0,     0,     0,     7,     0,     4,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,    17,
       0,     0,    11,     0,     0,     0,     8,     0,     0,     3,
       0,     0,     5,     0,     0,     5,     0,     0,     7,     0,
       0,     4,     0,     0,     6,     0,     0,     3,     0,     0,
       5,     0,     0,     3,     0,     2,     0,     0,     3,     0,
       0,     3,     0,     0,     3,     0,     0,     3,     0,     0,
       3,     0,     3,     0,     0,     6,     0,     5,     0,     0,
       4,     0,     0,     3,     0,     0,     5,     0,     0,     0,
       6,     0,     3,     0,     0,     0,     0,     8,     0,     0,
       3,     0,     3,     0,     0,     6,     0,     0,     0,     9,
       3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,    89,    93,    97,   101,   105,   208,     0,
       0,   199,     0,   202,   205,    21,    23,    25,    27,    29,
      31,   109,     0,   227,     0,   221,     0,     0,     0,     0,
       0,     0,   196,   191,   194,    53,    14,    49,     0,     2,
       2,   109,     0,    57,    85,    90,    94,    98,   102,   106,
     211,   209,   163,    51,     0,   200,   153,   203,   206,    22,
      24,    26,    28,    30,    32,     0,   110,     0,     0,    53,
      12,     1,   222,     0,    13,     0,    16,     0,    18,     0,
      20,     0,    34,   197,   192,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   195,    54,
      50,   218,   227,     7,     6,   221,     0,     9,     4,     0,
      58,    86,    91,    95,    99,   103,   107,   212,   210,   179,
     164,    52,   185,     0,   201,     0,   204,   207,    33,    46,
     111,     0,    87,   113,     0,    12,     0,   223,     0,   116,
       0,   160,     0,     0,    35,   247,   198,   193,    83,    81,
      71,    69,    79,    73,    77,    75,    59,    61,    63,    65,
      67,   219,    12,     8,   232,   218,    10,    92,    96,   100,
     104,   108,     0,   180,     0,   213,   186,   216,     0,     0,
      47,   112,    55,    88,   114,    34,   233,   231,     0,   239,
     228,   146,     0,   132,    12,     0,    38,    36,   248,    84,
      82,    72,    70,    80,    74,    78,    76,    60,    62,    64,
      66,    68,   220,     0,   225,   182,   181,     0,   214,   187,
     217,   188,   154,    48,    56,   115,   224,   240,   229,     0,
     117,     0,     0,    42,    39,    37,     0,   234,   226,   183,
     167,     0,   215,   189,   155,   230,   147,   118,   133,   161,
      43,    40,     0,     0,   235,   184,     0,     0,   168,   165,
     190,     0,   148,     0,   134,     0,    44,    41,   251,     0,
       0,    12,   236,   170,   173,   169,   166,     0,     0,     0,
       0,     0,    45,   241,   250,     0,   237,     0,   171,   174,
     156,   149,   119,   135,     0,   242,   244,   249,   176,   172,
     175,     0,    12,   120,     0,     0,     0,   177,     0,     0,
       0,    12,   140,     0,     0,   139,     0,     0,   178,     0,
     150,     0,     0,   144,   136,   138,   162,   245,   157,   151,
     121,   141,    12,   137,    12,   152,   123,     0,   145,     0,
     125,   122,   124,   142,   158,   128,   126,    12,   159,   129,
       0,   143,    12,   127,     0,   130,   131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,   108,   104,   163,   166,    25,    26,    27,    28,
      29,    30,    59,   134,    60,    61,    62,    63,    64,   128,
      32,   144,   197,   235,   234,   251,   267,   250,   266,   282,
      33,   180,   223,   100,   121,    34,    99,   224,   110,   207,
     208,   209,   210,   211,   202,   201,   204,   206,   205,   203,
     200,   199,   111,   183,    35,    45,   112,   167,    46,   113,
     168,    47,   114,   169,    48,   115,   170,    49,   116,   171,
      66,   130,   181,   184,   225,    76,   192,   247,   263,   303,
     311,   336,   341,   342,   346,   350,   349,   352,   356,    78,
     231,   264,   280,   304,   333,   314,   315,   322,   337,   347,
     332,    74,   229,   262,   278,   302,   329,   335,    36,   125,
     244,   261,   301,   334,   348,    80,   194,   265,    37,   120,
     174,   276,   241,   258,   275,   288,   299,   289,   300,   307,
     318,    53,   173,   216,   239,   255,   123,   176,   219,   243,
     260,    38,    84,   147,    98,    83,   146,    55,   124,    57,
     126,    58,   127,    51,   118,   117,   218,   242,   220,   135,
     161,   212,    72,   137,   214,   238,    70,   228,   245,   164,
     162,   254,   272,   286,   136,   189,   227,   270,   295,   296,
     306,    40,   145,   198,   236,   253
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -243
static const yytype_int16 yypact[] =
{
     244,     9,    -2,  -243,  -243,  -243,  -243,  -243,    -2,   -31,
     -21,  -243,   -13,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,    34,   139,  -243,    10,  -243,    23,    31,    45,    43,
       7,    15,  -243,  -243,   469,  -243,  -243,  -243,    32,   352,
     244,  -243,     9,  -243,   469,  -243,  -243,  -243,  -243,  -243,
     469,  -243,    36,  -243,    -2,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,    -2,  -243,    35,   193,    50,
     424,  -243,  -243,    52,  -243,    55,  -243,    64,  -243,    59,
    -243,    63,     6,  -243,  -243,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,    60,  -243,  -243,    50,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,   109,
    -243,  -243,   209,    11,  -243,   125,  -243,  -243,  -243,   469,
    -243,     9,  -243,  -243,    69,   315,    77,  -243,    -2,  -243,
      85,  -243,   128,    -2,  -243,  -243,  -243,  -243,   469,   469,
     469,   469,   469,   469,   469,   469,   469,   469,   469,   469,
     469,  -243,   424,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,    -2,  -243,    84,  -243,  -243,  -243,    -2,    82,
    -243,  -243,  -243,  -243,  -243,   131,  -243,  -243,    87,  -243,
    -243,   469,    -2,  -243,   424,    -2,   469,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,    90,  -243,   469,  -243,    91,  -243,  -243,
    -243,   469,  -243,  -243,  -243,  -243,  -243,  -243,  -243,    93,
     469,    94,    95,   469,  -243,  -243,    97,  -243,  -243,  -243,
       5,    96,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,    62,    99,  -243,  -243,    -2,    91,  -243,  -243,
    -243,    -2,  -243,   101,  -243,   111,  -243,  -243,  -243,   105,
     104,   424,  -243,    61,  -243,  -243,  -243,   112,   106,   108,
     114,   124,  -243,   120,  -243,   126,  -243,    91,  -243,  -243,
    -243,  -243,  -243,  -243,    -2,  -243,  -243,  -243,  -243,  -243,
    -243,   -11,   424,  -243,    -9,   226,   121,  -243,    34,   127,
     137,   424,  -243,   138,    30,  -243,   136,     7,  -243,   141,
    -243,   143,    -2,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,   469,   424,  -243,   424,  -243,   147,   140,   388,   144,
     159,  -243,  -243,  -243,  -243,  -243,  -243,   424,  -243,  -243,
      31,   388,   424,  -243,   146,  -243,  -243
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,    -4,  -243,  -243,  -243,  -243,   -36,  -243,  -243,  -243,
    -243,  -243,  -243,     2,  -243,  -243,  -243,  -243,  -243,  -243,
      86,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
     -89,  -243,  -243,  -243,  -243,    -1,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,     4,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -127,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,   -87,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -242,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,   -35,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,     0,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -156,  -243,  -243,   -88,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -247
static const yytype_int16 yytable[] =
{
      39,    44,    31,   105,   106,    43,   213,    50,   256,   143,
      71,     1,     2,     9,    52,   274,     3,     4,     5,     6,
       7,    68,   312,   313,    67,    54,    69,     3,     4,     5,
       6,     7,    81,    56,   308,   103,   107,    65,   232,    39,
      39,    31,    31,    41,    22,   298,   109,    16,    17,    18,
      19,    20,  -246,   122,    41,    42,    73,   257,   177,    75,
      82,   312,   313,   178,   129,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    77,    95,    96,    97,   324,
      79,   119,   131,   101,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   133,   138,   187,
     188,   139,    16,    17,    18,    19,    20,   141,   142,   268,
     140,   165,   172,   287,   185,   285,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,   190,    95,    96,    97,
     193,   195,   217,   222,   143,   182,   240,   191,   226,   237,
     246,   248,   196,   252,   249,   259,   310,   271,   279,   281,
     283,   284,     1,     2,   291,   321,   292,     3,     4,     5,
       6,     7,   293,   290,    15,    16,    17,    18,    19,    20,
     294,   215,  -243,   317,   319,   297,   340,   221,   339,    16,
      17,    18,    19,    20,    41,    22,   320,   326,   323,   328,
     343,   230,   330,   344,   233,   355,   354,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   345,    95,    96,
      97,   179,   309,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,   353,    95,    96,    97,   325,     0,   327,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
     132,    95,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,   273,   175,     1,     2,     0,
     277,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,   -15,   316,   -17,     0,     0,   -12,    12,    13,
      14,   -19,     0,    15,    16,    17,    18,    19,    20,    21,
      22,     0,    23,   305,     0,     0,     0,     0,     0,     0,
       0,     0,   187,   188,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,   188,     0,     0,   269,
       0,   331,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     0,   338,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,   -15,     0,   -17,     0,   351,     0,    12,
      13,    14,   -19,     0,    15,    16,    17,    18,    19,    20,
      21,    22,     0,   186,  -238,     1,     2,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
     -15,     0,   -17,     0,     0,   -12,    12,    13,    14,   -19,
       0,    15,    16,    17,    18,    19,    20,    21,    22,     0,
     102,     1,     2,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,   -15,     0,   -17,     0,
       0,   -12,    12,    13,    14,   -19,     0,    15,    16,    17,
      18,    19,    20,    21,    22,     0,   186,     1,     2,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,   -15,     0,   -17,     0,     0,     0,    12,    13,
      14,   -19,     0,    15,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97
};

static const yytype_int16 yycheck[] =
{
       0,     2,     0,    39,    39,     1,   162,     8,     3,     3,
       0,    13,    14,    24,    45,   257,    18,    19,    20,    21,
      22,    22,    31,    32,    22,    46,    22,    18,    19,    20,
      21,    22,    30,    46,    45,    39,    40,     3,   194,    39,
      40,    39,    40,    45,    46,   287,    42,    40,    41,    42,
      43,    44,    46,    54,    45,    46,    33,    52,    47,    28,
      45,    31,    32,    52,    65,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    30,    15,    16,    17,    49,
      37,    45,    47,    51,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    47,    46,   135,
     135,    46,    40,    41,    42,    43,    44,    48,    45,    47,
      46,    51,     3,    52,    45,   271,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    49,    15,    16,    17,
      45,     3,    48,    51,     3,   131,    45,   138,    51,    49,
      47,    47,   143,    46,    49,    49,   302,    48,    47,    38,
      45,    47,    13,    14,    48,   311,    48,    18,    19,    20,
      21,    22,    48,    51,    39,    40,    41,    42,    43,    44,
      46,   172,    52,    52,    47,    49,    29,   178,   334,    40,
      41,    42,    43,    44,    45,    46,    49,    51,    50,    48,
      50,   192,    49,    49,   195,    49,   352,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    48,    15,    16,
      17,   125,   301,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,   350,    15,    16,    17,   314,    -1,   317,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      47,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   252,   256,    47,    13,    14,    -1,
     261,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    47,    30,    -1,    -1,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,   294,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   338,   338,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   351,   351,    -1,    -1,   317,
      -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,   332,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    -1,    30,    -1,   347,    -1,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    13,    14,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    -1,    30,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    18,    19,    20,    21,    22,    23,    24,
      25,    27,    34,    35,    36,    39,    40,    41,    42,    43,
      44,    45,    46,    48,    54,    59,    60,    61,    62,    63,
      64,    66,    73,    83,    88,   107,   161,   171,   194,   212,
     234,    45,    46,   107,    88,   108,   111,   114,   117,   120,
      88,   206,    45,   184,    46,   200,    46,   202,   204,    65,
      67,    68,    69,    70,    71,     3,   123,    66,    88,   107,
     219,     0,   215,    33,   154,    28,   128,    30,   142,    37,
     168,    66,    45,   198,   195,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    15,    16,    17,   197,    89,
      86,    51,    48,    54,    56,    59,   194,    54,    55,   107,
      91,   105,   109,   112,   115,   118,   121,   208,   207,    45,
     172,    87,    88,   189,   201,   162,   203,   205,    72,    88,
     124,    47,    47,    47,    66,   212,   227,   216,    46,    46,
      46,    48,    45,     3,    74,   235,   199,   196,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,   213,   223,    57,   222,    51,    58,   110,   113,   116,
     119,   122,     3,   185,   173,    47,   190,    47,    52,    73,
      84,   125,   107,   106,   126,    45,    48,    59,   194,   228,
      49,    88,   129,    45,   169,     3,    88,    75,   236,   104,
     103,    98,    97,   102,    99,   101,   100,    92,    93,    94,
      95,    96,   214,   227,   217,    88,   186,    48,   209,   191,
     211,    88,    51,    85,    90,   127,    51,   229,   220,   155,
      88,   143,   227,    88,    77,    76,   237,    49,   218,   187,
      45,   175,   210,   192,   163,   221,    47,   130,    47,    49,
      80,    78,    46,   238,   224,   188,     3,    52,   176,    49,
     193,   164,   156,   131,   144,   170,    81,    79,    47,    66,
     230,    48,   225,    88,   175,   177,   174,    88,   157,    47,
     145,    38,    82,    45,    47,   227,   226,    52,   178,   180,
      51,    48,    48,    48,    46,   231,   232,    49,   175,   179,
     181,   165,   158,   132,   146,    88,   233,   182,    45,    83,
     227,   133,    31,    32,   148,   149,    47,    52,   183,    47,
      49,   227,   150,    50,    49,   149,    51,   230,    48,   159,
      49,    88,   153,   147,   166,   160,   134,   151,   212,   227,
      29,   135,   136,    50,    49,    48,   137,   152,   167,   139,
     138,   212,   140,   128,   227,    49,   141
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
#line 307 "main.y"
    {printf("{*inside Rule*} program -> functionDefinition : \n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 307 "main.y"
    {printf("{*outside Rule*} program -> functionDefinition : \n---------------------------------\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 308 "main.y"
    {printf("{*inside Rule*} program -> statements : \n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 308 "main.y"
    {printf("{*outside Rule*} program -> statements : \n---------------------------------\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 309 "main.y"
    {printf("{*inside Rule*} program -> statements program : \n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 309 "main.y"
    {printf("{*outside Rule*} program -> statements program : \n---------------------------------\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 310 "main.y"
    {printf("{*inside Rule*} program -> functionDefinition program : \n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 310 "main.y"
    {printf("{*outside Rule*} program -> functionDefinition program : \n---------------------------------\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 311 "main.y"
    {;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 315 "main.y"
    {quadPushStartLabel(++startLabelNum);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 315 "main.y"
    {quadPopStartLabel();;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 316 "main.y"
    {quadPopStartLabel();;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 317 "main.y"
    {quadPushEndLabel(++endLabelNum);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 317 "main.y"
    {quadPopEndLabel();;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 318 "main.y"
    {quadPushEndLabel(++endLabelNum);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 318 "main.y"
    {quadPopEndLabel();;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 319 "main.y"
    {quadPushStartLabel(++startLabelNum);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 319 "main.y"
    {quadPopStartLabel();;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 324 "main.y"
    {printf("{*inside Rule*} dataModifier -> CONST . : \n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 324 "main.y"
    {printf("{*outside Rule*} dataModifier -> CONST . : \n---------------------------------\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 326 "main.y"
    {printf("{*inside Rule*} dataType -> INT_DATA_TYPE : \n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 326 "main.y"
    { (yyval.TYPE_NODE) = createIntNode(0); printf("{*outside Rule*} dataType -> INT_DATA_TYPE : \n---------------------------------\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 327 "main.y"
    {printf("{*inside Rule*} dataType -> FLOAT_DATA_TYPE : \n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 327 "main.y"
    { (yyval.TYPE_NODE) = createNode("float"); printf("{*outside Rule*} dataType -> FLOAT_DATA_TYPE : \n---------------------------------\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 328 "main.y"
    {printf("{*inside Rule*} dataType -> STRING_DATA_TYPE : \n");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 328 "main.y"
    { (yyval.TYPE_NODE) = createNode("string"); printf("{*outside Rule*} dataType -> STRING_DATA_TYPE : \n---------------------------------\n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 329 "main.y"
    {printf("{*inside Rule*} dataType -> BOOL_DATA_TYPE : \n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 329 "main.y"
    { (yyval.TYPE_NODE) = createNode("bool"); printf("{*outside Rule*} dataType -> BOOL_DATA_TYPE : \n---------------------------------\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 330 "main.y"
    {printf("{*inside Rule*} dataType -> VOID_DATA_TYPE : \n");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 330 "main.y"
    { ; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 330 "main.y"
    {printf("{*outside Rule*} dataType -> VOID_DATA_TYPE : \n---------------------------------\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 333 "main.y"
    {printf("{*inside Rule*} decleration -> dataType IDENTIFIER : \n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 333 "main.y"
    {int updated_scope_level = checkSameScope((yyvsp[(2) - (3)].TYPE_STR));  insert((yyvsp[(2) - (3)].TYPE_STR), (yyvsp[(1) - (3)].TYPE_NODE)->type, 0, 0, 0, updated_scope_level); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 333 "main.y"
    { quadPopIdentifier((yyvsp[(2) - (4)].TYPE_STR));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 333 "main.y"
    {printf("{*outside Rule*} decleration -> dataType IDENTIFIER : \n---------------------------------\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 334 "main.y"
    {printf("{*inside Rule*} decleration -> dataType IDENTIFIER   '='  expr   : \n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 334 "main.y"
    {int updated_scope_level = checkSameScope((yyvsp[(2) - (5)].TYPE_STR));  nodeNodeTypeCheck((yyvsp[(1) - (5)].TYPE_NODE), (yyvsp[(4) - (5)].TYPE_NODE)); insert((yyvsp[(2) - (5)].TYPE_STR), (yyvsp[(1) - (5)].TYPE_NODE)->type, 0, 1, 0, updated_scope_level);  if(updated_scope_level != -1){updateIdentifierValue((yyvsp[(2) - (5)].TYPE_STR),(yyvsp[(4) - (5)].TYPE_NODE));} ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 334 "main.y"
    { quadPopIdentifier((yyvsp[(2) - (6)].TYPE_STR));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 334 "main.y"
    {printf("{*outside Rule*} decleration -> dataType IDENTIFIER   '='  expr   : \n---------------------------------\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 335 "main.y"
    {printf("{*inside Rule*} decleration -> dataModifier dataType IDENTIFIER  '='  expr : \n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 335 "main.y"
    {int updated_scope_level = checkSameScope((yyvsp[(3) - (6)].TYPE_STR));  nodeNodeTypeCheck((yyvsp[(2) - (6)].TYPE_NODE), (yyvsp[(5) - (6)].TYPE_NODE)); insert((yyvsp[(3) - (6)].TYPE_STR), (yyvsp[(2) - (6)].TYPE_NODE)->type, 1, 1, 0, updated_scope_level);  if(updated_scope_level != -1){updateIdentifierValue((yyvsp[(3) - (6)].TYPE_STR),(yyvsp[(5) - (6)].TYPE_NODE));}  ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 335 "main.y"
    {  quadPopIdentifier((yyvsp[(3) - (7)].TYPE_STR));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 335 "main.y"
    {printf("{*outside Rule*} decleration -> dataModifier dataType IDENTIFIER  '='  expr : \n---------------------------------\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 340 "main.y"
    {printf("{*inside Rule*} assignment -> IDENTIFIER '='  expr   : \n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 340 "main.y"
    { int Out_of_scope = checkUndeclared_and_OutOfScope((yyvsp[(1) - (4)].TYPE_STR)); if (Out_of_scope == 0 ){ int constant = checkConst((yyvsp[(1) - (4)].TYPE_STR)); if (constant == 0){ identifierNodeTypeCheck((yyvsp[(1) - (4)].TYPE_STR), (yyvsp[(3) - (4)].TYPE_NODE)); setInit((yyvsp[(1) - (4)].TYPE_STR)); setUsed((yyvsp[(1) - (4)].TYPE_STR)); updateIdentifierValue((yyvsp[(1) - (4)].TYPE_STR),(yyvsp[(3) - (4)].TYPE_NODE)); }};}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 340 "main.y"
    { (yyval.TYPE_NODE) = (yyvsp[(3) - (5)].TYPE_NODE); quadPopIdentifier((yyvsp[(1) - (5)].TYPE_STR)); printf("{*outside Rule*} assignment -> IDENTIFIER '='  expr   : \n---------------------------------\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 341 "main.y"
    {printf("{*inside Rule*} assignment -> enumDefinition   : \n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 341 "main.y"
    {printf("{*outside Rule*} assignment -> enumDefinition   : \n---------------------------------\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 342 "main.y"
    {printf("{*inside Rule*} assignment -> ENUM enumDeclaration   : \n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 342 "main.y"
    {printf("{*outside Rule*} assignment -> ENUM enumDeclaration   : \n---------------------------------\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 347 "main.y"
    {printf("{*inside Rule*} expr -> term   : \n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 347 "main.y"
    { (yyval.TYPE_NODE) = (yyvsp[(1) - (2)].TYPE_NODE); printf("{*outside Rule*} expr -> term   : \n---------------------------------\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 348 "main.y"
    {printf("{*inside Rule*} expr ->  '(' dataType ')' term   : \n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 348 "main.y"
    {quadInstruction("CAST"); (yyval.TYPE_NODE) = castingTo((yyvsp[(4) - (5)].TYPE_NODE), (yyvsp[(2) - (5)].TYPE_NODE)->type);printf("{*outside Rule*} expr ->  '(' dataType ')' term   : \n---------------------------------\n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 349 "main.y"
    {printf("{*inside Rule*} expr -> '-' term   : \n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 349 "main.y"
    {quadInstruction("NEG"); (yyval.TYPE_NODE) = Negation((yyvsp[(2) - (3)].TYPE_NODE)); printf("{*outside Rule*} expr -> '-' term   : \n---------------------------------\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 350 "main.y"
    {printf("{*inside Rule*} expr -> expr '+' expr   : \n");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 350 "main.y"
    {quadInstruction("ADD"); (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"+"); printf("{*outside Rule*} expr -> expr '+' expr   : \n---------------------------------\n");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 351 "main.y"
    {printf("{*inside Rule*} expr -> expr '-' expr   : \n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 351 "main.y"
    {quadInstruction("SUB"); (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"-"); printf("{*outside Rule*} expr -> expr '-' expr   : \n---------------------------------\n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 352 "main.y"
    {printf("{*inside Rule*} expr -> expr '*' expr   : \n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 352 "main.y"
    {quadInstruction("MUL"); (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"*"); printf("{*outside Rule*} expr -> expr '*' expr   : \n---------------------------------\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 353 "main.y"
    {printf("{*inside Rule*} expr -> expr '/' expr   : \n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 353 "main.y"
    {quadInstruction("DIV"); (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"/"); printf("{*outside Rule*} expr -> expr '/' expr   : \n---------------------------------\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 354 "main.y"
    {printf("{*inside Rule*} expr -> expr '%' expr   : \n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 354 "main.y"
    {quadInstruction("MOD"); (yyval.TYPE_NODE) = arithmatic((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"%"); printf("{*outside Rule*} expr -> expr '%' expr   : \n---------------------------------\n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 355 "main.y"
    {printf("{*inside Rule*} expr -> expr EQ expr   : \n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 355 "main.y"
    {quadInstruction("EQ");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"==");printf("{*outside Rule*} expr -> expr EQ expr   : \n---------------------------------\n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 356 "main.y"
    {printf("{*inside Rule*} expr -> expr NEQ expr   : \n");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 356 "main.y"
    {quadInstruction("NEQ");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"!=");printf("{*outside Rule*} expr -> expr NEQ expr   : \n---------------------------------\n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 357 "main.y"
    {printf("{*inside Rule*} expr -> expr LT expr   : \n");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 357 "main.y"
    {quadInstruction("LT");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"<"); printf("{*outside Rule*} expr -> expr LT expr   : \n---------------------------------\n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 358 "main.y"
    {printf("{*inside Rule*} expr -> expr GT expr   : \n");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 358 "main.y"
    {quadInstruction("GT");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),">"); printf("{*outside Rule*} expr -> expr GT expr   : \n---------------------------------\n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 359 "main.y"
    {printf("{*inside Rule*} expr -> expr GEQ expr   : \n");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 359 "main.y"
    {quadInstruction("GEQ");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),">="); printf("{*outside Rule*} expr -> expr GEQ expr   : \n---------------------------------\n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 360 "main.y"
    {printf("{*inside Rule*} expr -> expr LEQ expr   : \n");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 360 "main.y"
    {quadInstruction("LEQ");  (yyval.TYPE_NODE) = doComparison((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"<="); printf("{*outside Rule*} expr -> expr LEQ expr   : \n---------------------------------\n");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 361 "main.y"
    {printf("{*inside Rule*} expr -> expr AND expr   : \n");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 361 "main.y"
    {quadInstruction("LOGICAL_AND"); (yyval.TYPE_NODE) = logical((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"&"); printf("{*outside Rule*} expr -> expr AND expr   : \n---------------------------------\n");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 362 "main.y"
    {printf("{*inside Rule*} expr -> expr OR expr   : \n");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 362 "main.y"
    {quadInstruction("LOGICAL_OR"); (yyval.TYPE_NODE) = logical((yyvsp[(1) - (4)].TYPE_NODE),(yyvsp[(3) - (4)].TYPE_NODE),"|"); printf("{*outside Rule*} expr -> expr OR expr   : \n---------------------------------\n");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 363 "main.y"
    {printf("{*inside Rule*} expr -> NOT expr   : \n");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 363 "main.y"
    {quadInstruction("NOT"); (yyval.TYPE_NODE) = logical((yyvsp[(2) - (3)].TYPE_NODE),NULL,"!"); printf("{*outside Rule*} expr -> NOT expr   : \n---------------------------------\n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 364 "main.y"
    {printf("{*inside Rule*} expr -> '(' expr ')'   : \n");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 364 "main.y"
    { (yyval.TYPE_NODE) = (yyvsp[(2) - (4)].TYPE_NODE);printf("{*outside Rule*} expr -> '(' expr ')'   : \n---------------------------------\n");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 368 "main.y"
    {printf("======================================\n");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 368 "main.y"
    {printf("{*inside Rule*} term -> INTEGER   %d  : \n",(yyvsp[(1) - (2)].TYPE_INT));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 368 "main.y"
    {quadPushInt((yyvsp[(1) - (3)].TYPE_INT)); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 368 "main.y"
    { (yyval.TYPE_NODE) = createIntNode((yyvsp[(1) - (4)].TYPE_INT));    (yyval.TYPE_NODE)->value.intVal = (yyvsp[(1) - (4)].TYPE_INT); printf("{*outside Rule*} term -> INTEGER   %d  : \n",(yyvsp[(1) - (4)].TYPE_INT));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 370 "main.y"
    {printf("======================================\n");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 370 "main.y"
    {printf("{*inside Rule*} term -> FLOAT_     %f  : \n",(yyvsp[(1) - (2)].TYPE_FLOAT));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 370 "main.y"
    {quadPushFloat((yyvsp[(1) - (3)].TYPE_FLOAT)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 370 "main.y"
    { (yyval.TYPE_NODE) = createNode("float");  (yyval.TYPE_NODE)->value.floatVal = (yyvsp[(1) - (4)].TYPE_FLOAT) ;printf("{*outside Rule*} term -> FLOAT_     %f  : \n",(yyvsp[(1) - (4)].TYPE_FLOAT));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 371 "main.y"
    {printf("======================================\n");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 371 "main.y"
    {printf("{*inside Rule*} term -> STRING    %s  : \n",(yyvsp[(1) - (2)].TYPE_STR));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 371 "main.y"
    {quadPushString((yyvsp[(1) - (3)].TYPE_STR));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 371 "main.y"
    { (yyval.TYPE_NODE) = createNode("string"); (yyval.TYPE_NODE)->value.stringVal = strdup((yyvsp[(1) - (4)].TYPE_STR));printf("{*outside Rule*} term -> STRING    %s  : \n",(yyvsp[(1) - (4)].TYPE_STR));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 372 "main.y"
    {printf("======================================\n");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 372 "main.y"
    {printf("{*inside Rule*} term -> TRUE_VAL   %d     : \n",(yyvsp[(1) - (2)].TYPE_BOOL));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 372 "main.y"
    {quadPushInt(1);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 372 "main.y"
    { (yyval.TYPE_NODE) = createNode("bool");   (yyval.TYPE_NODE)->value.boolVal = 1;printf("{*outside Rule*} term -> TRUE_VAL  %d      : \n---------------------------------\n",(yyvsp[(1) - (4)].TYPE_BOOL));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 373 "main.y"
    {printf("======================================\n");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 373 "main.y"
    {printf("{*inside Rule*} term -> FALSE_VAL  %d     : \n",(yyvsp[(1) - (2)].TYPE_BOOL));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 373 "main.y"
    {quadPushInt(0);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 373 "main.y"
    { (yyval.TYPE_NODE) = createNode("bool");   (yyval.TYPE_NODE)->value.boolVal = 0;printf("{*outside Rule*} term -> FALSE_VAL    %d        : \n---------------------------------\n",(yyvsp[(1) - (4)].TYPE_BOOL));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 374 "main.y"
    {printf("======================================\n");;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 374 "main.y"
    {printf("{*inside Rule*} term -> IDENTIFIER  %s  : \n",(yyvsp[(1) - (2)].TYPE_STR));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 374 "main.y"
    {quadPushIdentifier((yyvsp[(1) - (3)].TYPE_STR));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 374 "main.y"
    {int Out_of_scope = checkUndeclared_and_OutOfScope((yyvsp[(1) - (4)].TYPE_STR)); if (Out_of_scope == 0 ){int Initialized = checkInitialized((yyvsp[(1) - (4)].TYPE_STR)); if ( Initialized == 1 ) {setUsed((yyvsp[(1) - (4)].TYPE_STR)); (yyval.TYPE_NODE) = identifierValue((yyvsp[(1) - (4)].TYPE_STR));} else {(yyval.TYPE_NODE) = NULL;}}else {(yyval.TYPE_NODE) = NULL;} printf("{*outside Rule*} term -> IDENTIFIER  %s  : \n",(yyvsp[(1) - (4)].TYPE_STR));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 375 "main.y"
    {printf("======================================\n");;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 375 "main.y"
    {printf("{*inside Rule*} term -> '(' term ')'    : \n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 375 "main.y"
    { (yyval.TYPE_NODE) = (yyvsp[(2) - (5)].TYPE_NODE); printf("{*outside Rule*} term -> '(' term ')'    : \n---------------------------------\n");;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 384 "main.y"
    {ifCon=1;;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 384 "main.y"
    {checkConstIF((yyvsp[(4) - (4)].TYPE_NODE)); quadJumpFalseLabel(++labelNum);;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 384 "main.y"
    {printf("IF () is detected \n");;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 384 "main.y"
    {enterScope();;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 384 "main.y"
    {printf("IF (){} is detected \n");;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 384 "main.y"
    {quadJumpEndLabel(); exitScope(); quadPopLabel();;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 384 "main.y"
    {;;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 386 "main.y"
    {printf("inside bare else  \n");;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 386 "main.y"
    {;;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 387 "main.y"
    {;;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 387 "main.y"
    {printf("inside else  \n");;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 387 "main.y"
    {;;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 388 "main.y"
    {fromElse=1;;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 388 "main.y"
    {enterScope();;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 388 "main.y"
    {exitScope();;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 388 "main.y"
    {printf("else {} detected \n");;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 391 "main.y"
    {setUsed((yyvsp[(3) - (3)].TYPE_STR)); switchC=1;;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 391 "main.y"
    {printf("switch case passed  \n");;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 391 "main.y"
    {quadPushLastIdentifierStack((yyvsp[(3) - (6)].TYPE_STR));setInit((yyvsp[(3) - (6)].TYPE_STR));;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 391 "main.y"
    {enterScope();;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 391 "main.y"
    {exitScope();;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 391 "main.y"
    {quadPopLastIdentifierStack();;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 397 "main.y"
    {printf("before case \n");;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 397 "main.y"
    {quadPeakLastIdentifierStack(); quadJumpFalseLabel(++labelNum);;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 397 "main.y"
    {printf("inside case  \n");;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 397 "main.y"
    {quadPopLabel();;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 398 "main.y"
    {switchC=0; switchMatch=0;;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 398 "main.y"
    {;;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 406 "main.y"
    {whileLoopFound=1; ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 406 "main.y"
    {printf("Found a while loop!\n");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 406 "main.y"
    {quadJumpFalseLabel(++labelNum);;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 406 "main.y"
    {enterScope();;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 406 "main.y"
    {/*end*/ exitScope(); quadJumpStartLabel(); quadPopLabel();;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 406 "main.y"
    { whileLoopFound=0;;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 406 "main.y"
    {;;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 409 "main.y"
    {printf("for \n"); forLoopFound=1;;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 409 "main.y"
    {printf("for \n");;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 409 "main.y"
    {quadPushStartLabel(++startLabelNum);;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 409 "main.y"
    {quadJumpFalseLabel(++labelNum);;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 409 "main.y"
    {enterScope();;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 409 "main.y"
    {exitScope(); quadJumpStartLabel(); quadPopLabel();;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 409 "main.y"
    {;;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 415 "main.y"
    {enterScope();;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 415 "main.y"
    {exitScope();;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 415 "main.y"
    {quadJumpFalseLabel(++labelNum); quadJumpStartLabel(); quadPopLabel();;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 421 "main.y"
    {printf("{*inside Rule*} enumDefinition -> ENUM IDENTIFIER   : \n");;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 421 "main.y"
    {quadStartEnum((yyvsp[(2) - (3)].TYPE_STR)); checkSameScope((yyvsp[(2) - (3)].TYPE_STR)); insert((yyvsp[(2) - (3)].TYPE_STR), "enum", 1, 1, 0, scopes[scope_idx-1]);;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 421 "main.y"
    {quadEndEnum((yyvsp[(2) - (7)].TYPE_STR)); enumCounter=0;;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 421 "main.y"
    {printf("{*outside Rule*} enumDefinition -> ENUM IDENTIFIER   : \n---------------------------------\n");;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 425 "main.y"
    {printf("{*inside Rule*} enumBody -> IDENTIFIER   : \n");;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 425 "main.y"
    {checkSameScope((yyvsp[(1) - (2)].TYPE_STR)); insert((yyvsp[(1) - (2)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue((yyvsp[(1) - (2)].TYPE_STR),enumValues); enumValues->value.intVal = 0; quadPushInt(++enumCounter); quadPopIdentifier((yyvsp[(1) - (2)].TYPE_STR));;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 425 "main.y"
    {printf("{*outside Rule*} enumBody -> IDENTIFIER   : \n---------------------------------\n");;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 426 "main.y"
    {printf("{*inside Rule*} enumBody -> IDENTIFIER '=' expr    : \n");;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 426 "main.y"
    {checkSameScope((yyvsp[(1) - (4)].TYPE_STR)); nodeNodeTypeCheck(enumValues,(yyvsp[(3) - (4)].TYPE_NODE)); insert((yyvsp[(1) - (4)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo((yyvsp[(3) - (4)].TYPE_NODE), "int")->value.intVal; updateIdentifierValue((yyvsp[(1) - (4)].TYPE_STR), enumValues); quadPopIdentifier((yyvsp[(1) - (4)].TYPE_STR));;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 426 "main.y"
    {printf("{*outside Rule*} enumBody -> IDENTIFIER '=' expr    : \n---------------------------------\n");;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 427 "main.y"
    {printf("{*inside Rule*} enumBody -> IDENTIFIER ',' enumBody    : \n");;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 427 "main.y"
    {checkSameScope((yyvsp[(1) - (4)].TYPE_STR)); insert((yyvsp[(1) - (4)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue((yyvsp[(1) - (4)].TYPE_STR), enumValues); enumValues->value.intVal++; quadPushInt(++enumCounter); quadPopIdentifier((yyvsp[(1) - (4)].TYPE_STR));;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 427 "main.y"
    {printf("{*outside Rule*} enumBody -> IDENTIFIER ',' enumBody    : \n---------------------------------\n");;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 428 "main.y"
    {printf("{*inside Rule*} enumBody -> IDENTIFIER '=' expr ',' enumBody    : \n");;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 428 "main.y"
    {checkSameScope((yyvsp[(1) - (6)].TYPE_STR)); nodeNodeTypeCheck(enumValues,(yyvsp[(3) - (6)].TYPE_NODE)); insert((yyvsp[(1) - (6)].TYPE_STR), "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo((yyvsp[(3) - (6)].TYPE_NODE), "int")->value.intVal; updateIdentifierValue((yyvsp[(1) - (6)].TYPE_STR), enumValues); quadPopIdentifier((yyvsp[(1) - (6)].TYPE_STR));;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 428 "main.y"
    {printf("{*outside Rule*} enumBody -> IDENTIFIER '=' expr ',' enumBody    : \n---------------------------------\n");;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 431 "main.y"
    {printf("{*inside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER   : \n");;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 431 "main.y"
    {checkUndeclared_and_OutOfScope((yyvsp[(1) - (3)].TYPE_STR)); identifierNodeTypeCheck((yyvsp[(1) - (3)].TYPE_STR),createNode("enum")); checkSameScope((yyvsp[(2) - (3)].TYPE_STR)); insert((yyvsp[(2) - (3)].TYPE_STR), "int", 0, 0, 0, scopes[scope_idx-1]);;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 431 "main.y"
    {printf("{*outside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER   : \n---------------------------------\n");;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 432 "main.y"
    {printf("{*inside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER  '=' expr    : \n");;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 432 "main.y"
    {checkUndeclared_and_OutOfScope((yyvsp[(1) - (5)].TYPE_STR)); identifierNodeTypeCheck((yyvsp[(1) - (5)].TYPE_STR),createNode("enum")); checkSameScope((yyvsp[(2) - (5)].TYPE_STR)); insert((yyvsp[(2) - (5)].TYPE_STR), "int", 0, 1, 0, scopes[scope_idx-1]); nodeNodeTypeCheck((yyvsp[(4) - (5)].TYPE_NODE),createIntNode(0)); updateIdentifierValue((yyvsp[(2) - (5)].TYPE_STR),castingTo((yyvsp[(4) - (5)].TYPE_NODE), "int")); quadPopIdentifier((yyvsp[(2) - (5)].TYPE_STR));;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 432 "main.y"
    {printf("{*outside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER  '=' expr    : \n---------------------------------\n");;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 438 "main.y"
    {printf("{*inside Rule*} printList -> expr      : \n");;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 438 "main.y"
    {char* str1 = printStringValues->value.stringVal; printf("str1 : { %s }\n",str1); char* str2 = castingTo((yyvsp[(1) - (2)].TYPE_NODE), "string")->value.stringVal;  printf("str2 : { %s }\n",str2); strcat(str1, str2); printStringValues->value.stringVal =  str1; printf("printStringValues : { %s }\n",printStringValues->value.stringVal);;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 438 "main.y"
    {printf("{*outside Rule*} printList -> expr      : \n---------------------------------\n");;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 439 "main.y"
    {printf("{*inside Rule*} printList -> printList ',' expr      : \n");;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 439 "main.y"
    {char* str1 = printStringValues->value.stringVal; printf("str1 : { %s }\n",str1); char* str2 = castingTo((yyvsp[(3) - (4)].TYPE_NODE), "string")->value.stringVal; printf("str2 : { %s }\n",str2);  strcat(str1, str2); printStringValues->value.stringVal =  str1; printf("printStringValues : { %s }\n",printStringValues->value.stringVal);;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 439 "main.y"
    {printf("{*outside Rule*} printList -> printList ',' expr      : \n---------------------------------\n");;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 442 "main.y"
    {printf("{*inside Rule*} statement -> assignment  : \n");;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 442 "main.y"
    {;;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 442 "main.y"
    {printf("{*outside Rule*} statement -> assignment  : \n---------------------------------\n");;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 443 "main.y"
    {printf("{*inside Rule*} statement ->  expr  : \n");;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 443 "main.y"
    {printf("{*outside Rule*} statement ->  expr  : \n---------------------------------\n");;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 444 "main.y"
    {printf("{*inside Rule*} statement ->  decleration  : \n");;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 444 "main.y"
    {;;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 444 "main.y"
    {printf("{*outside Rule*} statement ->  decleration  : \n---------------------------------\n");;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 445 "main.y"
    {printf("{*inside Rule*} statement ->  EXIT  : \n");;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 445 "main.y"
    {exit(EXIT_SUCCESS);;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 445 "main.y"
    {printf("{*outside Rule*} statement ->  EXIT  : \n---------------------------------\n");;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 446 "main.y"
    {printf("{*inside Rule*} statement ->  BREAK  : \n");;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 446 "main.y"
    {quadJumpEndLabel();;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 446 "main.y"
    {printf("{*outside Rule*} statement ->  BREAK  : \n---------------------------------\n");;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 447 "main.y"
    {printf("{*inside Rule*} statement ->  CONTINUE  : \n");;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 447 "main.y"
    {;;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 447 "main.y"
    {printf("{*outside Rule*} statement ->  CONTINUE  : \n---------------------------------\n");;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 448 "main.y"
    {printf("{*inside Rule*} statement ->  RETURN  : \n");;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 448 "main.y"
    {quadReturn();;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 448 "main.y"
    {printf("{*outside Rule*} statement ->  RETURN  : \n---------------------------------\n");;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 449 "main.y"
    {printf("{*inside Rule*} statement ->  RETURN expr  : \n");;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 449 "main.y"
    {quadReturn(); (yyval.TYPE_VOID) = (yyvsp[(2) - (3)].TYPE_NODE); printf("{*outside Rule*} statement ->  RETURN expr  : \n---------------------------------\n");;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 450 "main.y"
    {printf("{*inside Rule*} statement ->  PRINT  '(' expr ')' : \n");;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 450 "main.y"
    {printNode((yyvsp[(3) - (5)].TYPE_NODE));;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 450 "main.y"
    {printf("{*outside Rule*} statement ->  PRINT  '(' expr ')': \n");;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 451 "main.y"
    {printf("{*inside Rule*} statement ->  PRINT  '(' printList ')': \n");;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 451 "main.y"
    {(yyval.TYPE_VOID) = (yyvsp[(3) - (5)].TYPE_NODE);  printNode(printStringValues); printf("{*outside Rule*} statement ->  PRINT  '(' printList ')': \n");;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 456 "main.y"
    {printf("{*inside Rule*} statements -> statement ';' : \n---------------------------------\n");;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 456 "main.y"
    {;;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 456 "main.y"
    {printf("{*outside Rule*} statements -> statement ';' : \n");;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 457 "main.y"
    {printf("{*inside Rule*} statements -> controlStatement  : \n---------------------------------\n");;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 457 "main.y"
    {;;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 457 "main.y"
    {printf("{*outside Rule*} statements -> controlStatement  : \n");;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 458 "main.y"
    {printf("{*inside Rule*} statements -> statements statement ';'  : \n---------------------------------\n");;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 458 "main.y"
    {;;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 458 "main.y"
    {printf("{*outside Rule*} statements -> statements statement ';'  :   \n");;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 459 "main.y"
    {enterScope();;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 459 "main.y"
    {printf("{*inside Rule*} statements -> '{' codeBlock '}'   : \n");;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 459 "main.y"
    {exitScope();;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 459 "main.y"
    {printf("{*outside Rule*} statements -> '{' codeBlock '}' : \n---------------------------------\n");;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 460 "main.y"
    {printf("{*inside Rule*} statements -> statements controlStatement : \n");;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 460 "main.y"
    {printf("{*outside Rule*} statements -> statements controlStatement : \n---------------------------------\n");;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 461 "main.y"
    {enterScope();;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 461 "main.y"
    {printf("{*inside Rule*} statements -> statements '{' codeBlock '}'  : \n");;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 461 "main.y"
    {exitScope();;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 461 "main.y"
    {;;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 461 "main.y"
    {printf("{*outside Rule*} statements -> statements '{' codeBlock '}'  : \n---------------------------------\n");;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 466 "main.y"
    {printf("======================================\n");;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 466 "main.y"
    {printf("{*inside Rule*} codeBlock -> statements ';' : \n");;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 466 "main.y"
    {printf("{*outside Rule*} codeBlock -> statements ';' : \n---------------------------------\n");;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 471 "main.y"
    {quadPopIdentifier((yyvsp[(2) - (2)].TYPE_STR));;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 471 "main.y"
    {checkSameScope((yyvsp[(2) - (3)].TYPE_STR)); insert((yyvsp[(2) - (3)].TYPE_STR), (yyvsp[(1) - (3)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]) ;funcFirstarg=sym_table_idx-1;   argCount = sym_table_idx-argCount; setInit((yyvsp[(2) - (3)].TYPE_STR));;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 472 "main.y"
    {quadPopIdentifier((yyvsp[(2) - (2)].TYPE_STR));;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 472 "main.y"
    {checkSameScope((yyvsp[(2) - (3)].TYPE_STR)); insert((yyvsp[(2) - (3)].TYPE_STR), (yyvsp[(1) - (3)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]);setInit((yyvsp[(2) - (3)].TYPE_STR)); ;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 477 "main.y"
    {quadStartFunction((yyvsp[(2) - (2)].TYPE_STR));;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 477 "main.y"
    {checkSameScope((yyvsp[(2) - (3)].TYPE_STR)); insert((yyvsp[(2) - (3)].TYPE_STR), (yyvsp[(1) - (3)].TYPE_NODE)->type, 0, 0, 0, scopes[scope_idx-1]); argCount = sym_table_idx; enterScope(); setInit((yyvsp[(2) - (3)].TYPE_STR));;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 478 "main.y"
    {printf("here \n");;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 478 "main.y"
    {exitScope(); quadEndFunction((yyvsp[(2) - (9)].TYPE_STR)); updateSymbolParam((yyvsp[(2) - (9)].TYPE_STR), argCount);;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 480 "main.y"
    {printf("definitions with params  \n");;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 481 "main.y"
    {printf("definitions without params  \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 3747 "main.tab.c"
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
#line 488 "main.y"


void yyerror(char *s) {
    fprintf(stderr, "%s at line %d \n", s,line);
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

struct nodeType* castingTo(struct nodeType* term, char *type){ 
    if (term == NULL) {
        printf("Syntax Error: NULL pointer Referencing.\n");
        return NULL;
    }
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
            //TODO: More checking for printf("strlen(string_without_quotes) => %d\n",strlen(string_without_quotes)); != char string_without_quotes[string_length]; & check //If the conversion is not valid, the function returns 0.
            // remove double quotes from start and end of string
            char *string_with_quotes = strdup(term->value.stringVal);
            //printf("string_with_quotes: %s\n", string_with_quotes);
            //printf("strlen(string_with_quotes) => %d\n",strlen(string_with_quotes));
            int string_length = strlen(string_with_quotes) - 2; // remove 2 quotes
            //printf("string_length => %d\n",string_length);
            char string_without_quotes[string_length];
            for(int i = 0; i < string_length; i++){
                string_without_quotes[i] = string_with_quotes[i+1];
            }
            //printf("string_without_quotes :%s\n", string_without_quotes);
            //printf("strlen(string_without_quotes) => %d\n",strlen(string_without_quotes));

            //printf("atoi(string_without_quotes) => %d\n", atoi(string_without_quotes));
            casted_ptr->value.intVal = atoi(string_without_quotes); //If the conversion is not valid, the function returns 0.
            //printf("else if(strcmp(term->type, string) == 0)  str=> %s , casted_ptr->value.intVal => %d\n", string_without_quotes,casted_ptr->value.intVal);
        }
        else{
            casted_ptr->value.intVal = term->value.intVal;
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
            char *string_with_quotes = strdup(term->value.stringVal);
            int string_length = strlen(string_with_quotes) - 2; // remove 2 quotes
            char string_without_quotes[string_length];
            for(int i = 0; i < string_length; i++){
                string_without_quotes[i] = string_with_quotes[i+1];
            }
            casted_ptr->value.floatVal = atof(string_without_quotes); //If the conversion is not valid, the function returns 0.
        }
        else{
            casted_ptr->value.floatVal =  term->value.floatVal;
        }
    }
    else if(strcmp(type, "bool") == 0){  // convert to bool
        casted_ptr->type = "bool";
        if(strcmp(term->type, "int") == 0){
            casted_ptr->value.boolVal = term->value.intVal != 0;
        }
        else if(strcmp(term->type, "float") == 0){
            casted_ptr->value.boolVal = (int)term->value.floatVal !=0 ;
        }
        else if(strcmp(term->type, "string") == 0){
            // remove double quotes from start and end of string
            char *str = strdup(term->value.stringVal);
            if (strlen(str) == 2) {//Only EMPTY string
                casted_ptr->value.boolVal = 0;
            }
            else{
                casted_ptr->value.boolVal = 1;
            }
        }
        else{
            casted_ptr->value.boolVal =  term->value.boolVal;
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
            casted_ptr->value.stringVal =  term->value.stringVal;
        }
    } 
    return casted_ptr;    
}


// Arithmatic
struct nodeType* arithmatic(struct nodeType* op1, struct nodeType*op2, char* op){ //TODO: Handle divide by zero
    if (op1 == NULL || op2 == NULL) {
        printf("Syntax Error: NULL pointer Referencing.\n");
        return NULL;
    }
    printf("{*inside Function*} arithmatic(struct nodeType* op1 = %s NodeType,struct nodeType* op2 = %s NodeType, char *op = %s) :\n", op1->type ,op2->type , op);
    if(strcmp(op1->type, op2->type) != 0) {
        Show_Semantic_Error(TYPE_MISMATCH, ""); 
    }
    struct nodeType* final_result = malloc(sizeof(struct nodeType));
    final_result->isConst=((op1->isConst)&&(op2->isConst));
    
    printf("DEBUG: HERE ARITHEMATIC whileLoopFound %d , whileLoopCnt = %d\n ",whileLoopFound,whileLoopCnt);
    if(whileLoopFound==1){
      
        if(strcmp(op1->type, "int") == 0){
            final_result->value.intVal = 0;
             final_result->type = "int";
             int acc=0;
              struct nodeType*int_op2 = malloc(sizeof(struct nodeType));
            int_op2 = castingTo(op2,"int");
       for (int i=0;i<whileLoopCnt;i++){
           
           
            
            if(strcmp(op, "+") == 0){
                printf("op1->value.intVal = %d\n",op1->value.intVal);
                printf("int_op2->value.intVal = %d\n",int_op2->value.intVal);
                acc =acc+ op1->value.intVal + int_op2->value.intVal;
                printf("final_result->value.intVal = %d\n",final_result->value.intVal);
                }
       }
      
             if(strcmp(op, "-") == 0){
                final_result->value.intVal = op1->value.intVal - int_op2->value.intVal;
                }
            else if(strcmp(op, "*") == 0){
                if (((op1->isConst == 1) && (op1->value.intVal == 0)) || ((int_op2->isConst == 1) && (int_op2->value.intVal == 0))) {
                    final_result->isConst = 1;
                }                
                final_result->value.intVal = op1->value.intVal * int_op2->value.intVal;
                }
            else if(strcmp(op, "/") == 0){
                if ((op1->isConst == 1) && (op1->value.intVal == 0)) {
                    final_result->isConst = 1;
                }                 
                final_result->value.intVal = op1->value.intVal / int_op2->value.intVal;
                }  
            else if(strcmp(op, "%") == 0){
                if ((op1->isConst == 1) && (op1->value.intVal == 0)) {
                    final_result->isConst = 1;
                }                  
                final_result->value.intVal = op1->value.intVal % int_op2->value.intVal;
            
            } 
             final_result->value.intVal = acc;

             
    
        }
    }
    else{
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
                    if (((float_op1->isConst == 1) && (float_op1->value.floatVal == 0)) || ((op2->isConst == 1) && (op2->value.floatVal == 0))) {
                        final_result->isConst = 1;
                    }
                    final_result->value.floatVal = float_op1->value.floatVal * op2->value.floatVal;
                    }
                else if(strcmp(op, "/") == 0){
                    if ((float_op1->isConst == 1) && (float_op1->value.floatVal == 0)) {
                        final_result->isConst = 1;
                    }                
                    final_result->value.floatVal = float_op1->value.floatVal / op2->value.floatVal;
                    }
                else if(strcmp(op, "%") == 0){   
                    Show_Semantic_Error(TYPE_MISMATCH, "");
                    if ((float_op1->isConst == 1) && (float_op1->value.floatVal == 0)) {
                        final_result->isConst = 1;
                    }                     
                    final_result->value.intVal = op1->value.intVal;
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
                    if (((op1->isConst == 1) && (op1->value.intVal == 0)) || ((int_op2->isConst == 1) && (int_op2->value.intVal == 0))) {
                        final_result->isConst = 1;
                    }                
                    final_result->value.intVal = op1->value.intVal * int_op2->value.intVal;
                    }
                else if(strcmp(op, "/") == 0){
                    if ((op1->isConst == 1) && (op1->value.intVal == 0)) {
                        final_result->isConst = 1;
                    }                 
                    final_result->value.intVal = op1->value.intVal / int_op2->value.intVal;
                    }  
                else if(strcmp(op, "%") == 0){
                    if ((op1->isConst == 1) && (op1->value.intVal == 0)) {
                        final_result->isConst = 1;
                    }                  
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
                if (((op1->isConst == 1) && (op1->value.floatVal == 0)) || ((float_op2->isConst == 1) && (float_op2->value.floatVal == 0))) {
                    final_result->isConst = 1;
                }            
                final_result->value.floatVal = op1->value.floatVal * float_op2->value.floatVal;
                }
            else if(strcmp(op, "/") == 0){
                if ((op1->isConst == 1) && (op1->value.floatVal == 0)) {
                    final_result->isConst = 1;
                }            
                final_result->value.floatVal = op1->value.floatVal / float_op2->value.floatVal;
                }
            else if(strcmp(op, "%") == 0){   
                Show_Semantic_Error(TYPE_MISMATCH, "");
                if ((op1->isConst == 1) && (op1->value.floatVal == 0)) {
                    final_result->isConst = 1;
                }              
                final_result->value.floatVal = op1->value.floatVal ; 
            }      
        
        }
        else if(strcmp(op1->type, "bool") == 0){
            struct nodeType* bool_op2 = malloc(sizeof(struct nodeType));
            bool_op2 = castingTo(op1,"bool");
            final_result->type = "bool";
            //TODO: check
            if(strcmp(op, "+") == 0){
                if (((op1->isConst == 1) && (op1->value.boolVal == 1)) || ((bool_op2->isConst == 1) && (bool_op2->value.boolVal == 1))) {
                    final_result->isConst = 1;
                }              
                final_result->value.boolVal = op1->value.boolVal || bool_op2->value.boolVal;
                }
            else if(strcmp(op, "-") == 0){
                if (((op1->isConst == 1) && (op1->value.boolVal == 1)) || ((bool_op2->isConst == 1) && (bool_op2->value.boolVal == 1))) {
                    final_result->isConst = 1;
                }                 
                final_result->value.boolVal = op1->value.boolVal || bool_op2->value.boolVal;
                }
            else if(strcmp(op, "*") == 0){
                if (((op1->isConst == 1) && (op1->value.boolVal == 0)) || ((bool_op2->isConst == 1) && (bool_op2->value.boolVal == 0))) {
                    final_result->isConst = 1;
                }
                final_result->value.boolVal = op1->value.boolVal && bool_op2->value.boolVal;
                }
            else if(strcmp(op, "/") == 0){
                if (((op1->isConst == 1) && (op1->value.boolVal == 0)) || ((bool_op2->isConst == 1) && (bool_op2->value.boolVal == 0))) {
                    final_result->isConst = 1;
                }            
                final_result->value.boolVal = op1->value.boolVal && bool_op2->value.boolVal;
                }
            else if(strcmp(op, "%") == 0){
                Show_Semantic_Error(TYPE_MISMATCH, ""); 
                if ((op1->isConst == 1) && (op1->value.boolVal == 0)) {
                    final_result->isConst = 1;
                }              
                final_result->value.boolVal = op1->value.boolVal;
            }     
        
        }
        else if(strcmp(op1->type, "string") == 0){
            struct nodeType* string_op2 = malloc(sizeof(struct nodeType));
            string_op2 = castingTo(op2,"string");
            final_result->type = "string";
            //TODO: check
            if(strcmp(op, "+") == 0){
                char* str1 = op1->value.stringVal;
                strcat(str1, string_op2->value.stringVal);
                final_result->value.stringVal = str1;    
            }
            else if(strcmp(op, "-") == 0){
                Show_Semantic_Error(TYPE_MISMATCH, ""); 
                final_result->value.stringVal = op1->value.stringVal;
            }
            else if(strcmp(op, "*") == 0){
                Show_Semantic_Error(TYPE_MISMATCH, ""); 
                final_result->value.stringVal = op1->value.stringVal;
            }
            else if(strcmp(op, "/") == 0){
                Show_Semantic_Error(TYPE_MISMATCH, ""); 
                final_result->value.stringVal = op1->value.stringVal;
            } 
            else if(strcmp(op, "%") == 0){
                Show_Semantic_Error(TYPE_MISMATCH, ""); 
                final_result->value.stringVal = op1->value.stringVal;
            }    
        
        }
    }
    return final_result;
}

// Comparison
struct nodeType* doComparison(struct nodeType* op1, struct nodeType*op2, char* op){
    if(strcmp(op,"<")==0){
        forLoopCnt=op2->value.intVal-op1->value.intVal;
        printf("forLoopCnt: %d\n",forLoopCnt);
        whileLoopCnt=op2->value.intVal-op1->value.intVal;
        printf("whileLoopCnt: %d\n",whileLoopCnt);
    }
    if (op1 == NULL || op2 == NULL) {
        printf("Syntax Error: NULL pointer Referencing.\n");
        return NULL;
    }
    printf("{*inside Function*} doComparison(struct nodeType* op1 = %s NodeType,struct nodeType* op2 = %s NodeType, char *op = %s) :\n", op1->type ,op2->type , op);
    if(strcmp(op1->type, op2->type) != 0) {
        Show_Semantic_Error(TYPE_MISMATCH, ""); 
    }    
    struct nodeType* bool_op1 = malloc(sizeof(struct nodeType));
    bool_op1 = castingTo(op1,"bool");
    struct nodeType* bool_op2 = malloc(sizeof(struct nodeType));
    bool_op2 = castingTo(op2,"bool");    
    
    struct nodeType* final_result = malloc(sizeof(struct nodeType));
    final_result->isConst=((op1->isConst)&&(op2->isConst));
    final_result->type = "bool";
    int foundMatch=0;
    if(strcmp(op, "==") == 0){
        printf("OMAR op1->value.intVal = %d\n",op1->value.intVal);
        printf("OMAR op2->value.intVal = %d\n",op2->value.intVal);

        if(op1->value.intVal == op2->value.intVal)
            final_result->value.boolVal = 1;
        else
            final_result->value.boolVal = 0;
        
        printf("OMAR final_result->value.boolVal = %d\n",final_result->value.boolVal);
        
    }
    else if(strcmp(op, "!=") == 0){
        final_result->value.boolVal = op1->value.boolVal != op2->value.boolVal;
        foundMatch=1;
    }
    else if(strcmp(op, "<") == 0){
        printf("DEBUG OMAR\n");
        printf("op1->value.boolVal = %d\n",op1->value.boolVal);
        printf("op2->value.boolVal = %d\n",op2->value.boolVal);
        final_result->value.boolVal = op1->value.boolVal < op2->value.boolVal;
        printf("final_result->value.boolVal = %d\n",final_result->value.boolVal);
        foundMatch=1;
    }
    else if(strcmp(op, ">") == 0){
        printf("OMAR op1->value.boolVal = %d\n",op1->value.boolVal);
        printf("OMAR op2->value.boolVal = %d\n",op2->value.boolVal);
        if(op1->value.boolVal > op2->value.boolVal)
             final_result->value.boolVal = 1;
        else
            final_result->value.boolVal = 0;
        printf("OMAR final_result->value.boolVal = %d\n",final_result->value.boolVal);
        foundMatch=1;
    }
    else if(strcmp(op, "<=") == 0){
        final_result->value.boolVal = op1->value.boolVal <= op2->value.boolVal;
        foundMatch=1;

    }
    else if(strcmp(op, ">=") == 0){
        final_result->value.boolVal = op1->value.boolVal >= op2->value.boolVal;
        foundMatch=1;

    }
    if (final_result->value.boolVal==1&&ifCon==1){
        foundMatch=0;
        ifConMatch=1;
      
    }
    else{
        ifConMatch=0;
    }
    if(switchC==1&&final_result->value.boolVal==1){
        switchMatch=1;
    }
    if(forLoopFound==1&&final_result->value.boolVal==0){
        forLoopCnt=0;
    }
    return final_result;
}

// Logical
struct nodeType* logical(struct nodeType* op1, struct nodeType* op2, char* op){
    if (op1 == NULL) {
        printf("Syntax Error: NULL pointer Referencing.\n");
        return NULL;
    }
    struct nodeType* bool_op1 = malloc(sizeof(struct nodeType));
    bool_op1 = castingTo(op1,"bool");
    printf("bool_op1 = %d\n",bool_op1->value.boolVal);
    struct nodeType* bool_op2 = malloc(sizeof(struct nodeType));
    if (op2 != NULL){
        printf("{*inside Function*} logical(struct nodeType* op1 = %s NodeType,struct nodeType* op2 = %s NodeType, char *op = %s) :\n", op1->type ,op2->type , op);
        if(strcmp(op1->type, op2->type) != 0) {
            Show_Semantic_Error(TYPE_MISMATCH, ""); 
        }
        bool_op2 = castingTo(op2,"bool");  
    }
    else{
        printf("{*inside Function*} logical(struct nodeType* op1 = %s NodeType,struct nodeType* op2 = NULL NodeType, char *op = %s) :\n", op1->type , op);
        bool_op2 = NULL;
    }
    
    struct nodeType* final_result = malloc(sizeof(struct nodeType));
    final_result->type = "bool";
    if(op2 == NULL){
        final_result->isConst=(op1->isConst);
    }
    else{
        final_result->isConst=((op1->isConst)&&(op2->isConst));
    }
    
    
    if(strcmp(op, "!") == 0){
        final_result->value.boolVal = (! (bool_op1->value.boolVal));
    }
    else if(strcmp(op, "&") == 0){
        if (bool_op2 == NULL) {
            printf("Syntax Error: NULL pointer Referencing.\n");
            return NULL;
        }
        if (((bool_op1->isConst == 1) && (bool_op1->value.boolVal == 0)) || ((bool_op2->isConst == 1) && (bool_op2->value.boolVal == 0))) {
            final_result->isConst = 1;
        }
        final_result->value.boolVal = bool_op1->value.boolVal && bool_op2->value.boolVal;
    }
    else if(strcmp(op, "|") == 0){
        if (bool_op2 == NULL) {
            printf("Syntax Error: NULL pointer Referencing.\n");
            return NULL;
        }
        if (((bool_op1->isConst == 1) && (bool_op1->value.boolVal == 1)) || ((bool_op2->isConst == 1) && (bool_op2->value.boolVal == 1))) {
            final_result->isConst = 1;
        }                
        final_result->value.boolVal = bool_op1->value.boolVal || bool_op2->value.boolVal;
    }
}

// Unary
struct nodeType* Negation(struct nodeType* term){
    if (term == NULL) {
        printf("Syntax Error: NULL pointer Referencing.\n");
        return NULL;
    }
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
    else if(strcmp(term->type, "bool") == 0){
        if (term->value.boolVal == 0){
            final_result->value.intVal = 0;
        }
        else {
            final_result->value.intVal = -1;
        }
    }
    else{
        final_result->type = "int";
        final_result->value.intVal = 0;
        Show_Semantic_Error(TYPE_MISMATCH, "");
    }
    return final_result;
}

int computeIdentifierIndex(char* name){
    printf("{*inside Function*} computeIdentifierIndex(char* name = %s) :\n", name);
    int lvl;
    for(int i=sym_table_idx-1; i>=0 ;i--) {
        if(strcmp(symbol_Table[i].name ,name)==0) { //checks if a Variable is declared before 
            lvl = symbol_Table[i].scope;
            for(int j=scope_idx-1;j>=0;j--) { //Loop through current scope of program downstream to base scope (0)
                if(lvl == scopes[j]) { //Find Nearest Variable in current scope or in any downstream to base scope (0)
                    printf("{*               *}  => Varible: {%s} Index in Symbol_Table= {%d}\n",name, i);
                    printf("{*               *}  => Varible: {%s} Scope Level = {%d}\n",name, lvl);
                    return i;
                }
            }
        }
    }
    printf("Syntax Error:  => Ghost Varible: {%s} Scope Level = -1 {Not Found}\n",name);
    Show_Semantic_Error(UNDECLARED, name);
    return -1;
}

void identifierNodeTypeCheck(char* name , struct nodeType* node){
    if (node == NULL) {
        printf("Syntax Error: NULL pointer Referencing.\n");
        return ;
    }
    printf("{*inside Function*} identifierNodeTypeCheck(char* name = %s, struct nodeType* node = %s NodeType) :\n", name ,node->type);
    int identifier_sym_table_index = computeIdentifierIndex(name); 
    if (identifier_sym_table_index < 0){
        return ;
    }
    
    if(strcmp(symbol_Table[identifier_sym_table_index].type, node->type) != 0) {
        Show_Semantic_Error(TYPE_MISMATCH, "");
    }
}

void nodeNodeTypeCheck(struct nodeType* node1, struct nodeType* node2){
    if (node1 == NULL || node2 == NULL) {
        //TODO: Show_Semantic_Error(NULL, "");
        return ;
    }
    printf("{*inside Function*} nodeNodeTypeCheck(struct nodeType* node1 = %s NodeType, struct nodeType* node2 = %s NodeType) :\n", node1->type, node2->type);
    if(strcmp(node1->type, node2->type) != 0) {
        Show_Semantic_Error(TYPE_MISMATCH, ""); 
    }
    return;
}//

void updateSymbolParam(char* symbol, int param){
    int bucket = computeIdentifierIndex(symbol);

    printf("{*inside Function*} updateSymbolParam(char* symbol = %s, int param = %d )\n", symbol , param);
    symbol_Table [bucket].value.intVal = param;
}

struct nodeType* identifierValue(char* name){
    printf("{*inside Function*} identifierValue(char* name = %s) :\n", name);
    int identifier_sym_table_index = computeIdentifierIndex(name);
    if (identifier_sym_table_index < 0){
        struct nodeType* final_result = malloc(sizeof(struct nodeType));
        final_result->value.intVal = -1;
        return final_result; //NULL;
    }
    
    struct nodeType* final_result = malloc(sizeof(struct nodeType));
    final_result->type = symbol_Table[identifier_sym_table_index].type;
    final_result->isConst = symbol_Table[identifier_sym_table_index].isConst;

    if(strcmp(symbol_Table[identifier_sym_table_index].type, "int") == 0){
        final_result->value.intVal = symbol_Table[identifier_sym_table_index].value.intVal;
        printf("{*               *} Value() = { %d }\n", final_result->value.intVal);
    }
    else if(strcmp(symbol_Table[identifier_sym_table_index].type, "float") == 0){
        final_result->value.floatVal = symbol_Table[identifier_sym_table_index].value.floatVal;
        printf("{*               *} Value() = { %f }\n", final_result->value.floatVal);
    }
    else if(strcmp(symbol_Table[identifier_sym_table_index].type, "bool") == 0){
        final_result->value.boolVal = symbol_Table[identifier_sym_table_index].value.boolVal;
        printf("{*               *} Value() = { %d }\n", final_result->value.boolVal);
    }
    else if(strcmp(symbol_Table[identifier_sym_table_index].type, "string") == 0){
        final_result->value.stringVal = symbol_Table[identifier_sym_table_index].value.stringVal;
        printf("{*               *} Value()  = { %s }\n", final_result->value.stringVal);
    }
    
    return final_result;
}  

// This function call after check that Identifier(name) is same type as node type 
void updateIdentifierValue(char* name, struct nodeType* node){
    if(switchC=1&&switchMatch==2){
        
        return;
    }
    printf("DEBUG:  ifCon = %d ifConMatch = %d , fromElse= %d \n", ifCon,ifConMatch,fromElse);
    if((ifCon == 1 && ifConMatch == 1&&fromElse==1)){
       
        return;
    }
    if (node == NULL) {
        printf("Syntax Error: NULL pointer Referencing.\n");
        return ;
    }
    printf("{*inside Function*} updateIdentifierValue(char* name = %s, struct nodeType * node = %s NodeType =>Value = {%s})\n", name, node->type,castingTo(node, "string")->value.stringVal);
    int identifier_sym_table_index = computeIdentifierIndex(name);
    if (identifier_sym_table_index < 0){
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

    if(switchC==1&&switchMatch==1){
        switchMatch=2;
    }
}

// char* valueString(struct nodeType* node){
//     struct nodeType* str_p = malloc(sizeof(struct nodeType));
//     str_p = castingTo(node,"string")
//     return str_p->value.stringVal;
// }

void printNode(struct nodeType* node){
    printf("DEBUG:  switchC = %d switchMatch = %d \n", switchC,switchMatch);
    printf("DEBUG:  forLoopFound = %d forLoopCnt = %d \n", forLoopFound,forLoopCnt);
    if(switchC==1&&switchMatch==2){
        return;
    }
    if (node == NULL) {
        printf("Syntax Error: NULL pointer Referencing.\n");
        return ;
    }
    printf("{*inside Function*} printNode(struct nodeType* node = %s NodeType)\n", node->type);
    struct nodeType* str_p = malloc(sizeof(struct nodeType));
    str_p = castingTo(node,"string");
    if(forLoopFound==1){
        forLoopFound=0;
        for(int i=0;i<forLoopCnt;i++){
            printf( "{**Print Result**} :  { %s }.\n",str_p->value.stringVal);
        }
    }
    else if(whileLoopFound==1){
       
        for(int i=0;i<whileLoopCnt;i++){
            printf( "{**Print Result**} :  { %s }.\n",str_p->value.stringVal);
        }
    }
    else
        printf( "{**Print Result**} :  { %s }.\n",str_p->value.stringVal);
    printStringValues->value.stringVal = strdup("");  //Free for later use
    if(switchC==1&&switchMatch==1){
        switchMatch=2;
    }
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

    //printf("SymbolTable() inserted: %s, declared:%d, intialized:%d, const:%d, Symbol table idx:%d\n", symbol_Table [sym_table_idx-1].name, symbol_Table [sym_table_idx-1].isDecl,symbol_Table [sym_table_idx-1].isInit, symbol_Table [sym_table_idx-1].isConst, sym_table_idx); 
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
    printf("{*inside Function*} exitScope() \n");
    cleanedUpScope(scope_idx);
    scope_idx--;
}
// Check if the variable is declared in the same scope
int checkSameScope(char* name) {
    printf("{*inside Function*} checkSameScope(char* name = %s)\n", name );
    int lvl;
    int updated_scope_level = scopes[scope_idx-1]; // For insertion of a new IDENTIFIER after Checking there no Redeclarion before
    for(int i=0; i<sym_table_idx ;i++) {
        if(strcmp(symbol_Table[i].name ,name)==0 ) { //checks if a Variable is declared before 
            lvl = symbol_Table[i].scope;
            if(lvl == scopes[scope_idx-1]) { //Check if a variable is declared in the current scope of program
                printf("Syntax Error: Variable { %s } is already declared in the same scope.\n", name); 
                Show_Semantic_Error(REDECLARED, name);
                // Ghost Varible
                updated_scope_level = -1;     // -1: means was in scope but cleaned ,but, 0: means no scope  
                return updated_scope_level;
            }
        }
    }
    return updated_scope_level;
}

// Check if the variable is undeclared or removed out of scope
int checkUndeclared_and_OutOfScope(char* name) {
    printf("{*inside Function*} checkUndeclared_and_OutOfScope(char* name = %s)\n", name );
    int lvl;
    int Out_of_scope = 0;
    int not_declared = 1;
    for(int i=sym_table_idx-1; i>=0 ;i--) { //Start Search from {sym_table_idx} which represent current count of Variabls in  symbol_Table, its index = {sym_table_idx -1} which start at 0 means that exist only 1 variable in symbol_Table list

        //printf("Symbol Instance :%s\n",symbol_Table[i].name);
        if(strcmp(symbol_Table[i].name ,name)==0) { //checks if a Variable is declared before 
            not_declared = 0; //Already Declared
            lvl = symbol_Table[i].scope;
            //printf("lvl : %d\n",lvl);
            for(int j=scope_idx-1;j>=0;j--) { //Loop through current scope of program and Similar to it downstream to base scope (0)
                //printf("scopes[j] : %d\n",scopes[j]);
                if(lvl == scopes[j]) { //Find Variable in current scope or in any downstream to base scope (0)
                    return Out_of_scope;
                }
            }
            printf("Syntax Error: Variable { %s } is declared out of scope.\n", name);  
            Show_Semantic_Error(OUT_OF_SCOPE, name);       
        }
    }
    if(not_declared == 1) {
        printf("Syntax Error: Variable { %s } is not declared before.\n", name);
        Show_Semantic_Error(UNDECLARED, name);
    }
    Out_of_scope = 1;
    return Out_of_scope; 
}


// this function checks if a variable is used before initialized
int checkInitialized(char* name) {
    printf("{*inside Function*} checkInitialized(char* name = %s)\n", name );
    int lvl;
    int Initialized = 0;
    for(int i=sym_table_idx-1;i>=0;i--) {//Start Search from {sym_table_idx} which represent current count of Variabls in  symbol_Table, its index = {sym_table_idx -1} which start at 0 means that exist only 1 variable in symbol_Table list
        if(strcmp(symbol_Table[i].name ,name)==0) { //checks if a Variable is declared before 
            lvl = symbol_Table[i].scope;
            for(int j=scope_idx-1;j>=0;j--) { //Loop through current scope of program downstream to base scope (0)
                if(lvl == scopes[j]) { //Find Variable in current scope or in any downstream to base scope (0)
                    if(symbol_Table[i].isInit == 1) {
                        //Every thing is OK
                        Initialized = 1;
                        return Initialized;
                    }
                }
            }
        }
    }
    printf("Syntax Error: Variable { %s } is used before initialized.\n", name);
    Show_Semantic_Error(UNINITIALIZED, name);
    return Initialized;
}

// Check if the variable is constant or not
int checkConst(char* name) {
    int constant = 0;
    int lvl;
    printf("{*inside Function*} checkConst(char* name = %s)\n", name );
    for(int i=sym_table_idx-1; i>=0 ;i--) { //Start Search from {sym_table_idx} which represent current count of Variabls in  symbol_Table, its index = {sym_table_idx -1} which start at 0 means that exist only 1 variable in symbol_Table list
        if(strcmp(symbol_Table[i].name ,name)==0) { //checks if a Variable is declared before 
            lvl = symbol_Table[i].scope;
            for(int j=scope_idx-1;j>=0;j--) {//Loop through current scope of program downstream to base scope (0)
                if(lvl == scopes[j]) { //Find Only Nearest Variable in current scope or in any downstream to base scope (0)
                    if(symbol_Table[i].isConst == 1) {
                        printf("Syntax Error: Variable { %s } is constant.\n", name);
                        Show_Semantic_Error(CONSTANT, name);
                        constant = 1;
                        return constant;
                    }
                    else{
                        //printf("Variable %s is not constant\n", name);
                        return constant;
                    }
                }
              }
        }
    }
    return constant;
}
//check if the if conditions is constant or not
void checkConstIF(struct nodeType* exprNode){
    printf("{*inside Function*} checkConstIF(struct nodeType* node = %s NodeType \n", exprNode->type);
    if(exprNode->isConst==1){
        struct nodeType* bool_exprNode = malloc(sizeof(struct nodeType));
        bool_exprNode = castingTo(exprNode,"bool");
        Show_Semantic_Error(CONSTANT_IF, bool_exprNode->value.boolVal);
    }

}

// Print the symbol table
void printSymbolTable() {
    
    for(int i=0; i<sym_table_idx ;i++) {
        char* str_value = "";
        if(strcmp(symbol_Table[i].type, "int") == 0){
            char t[100];
            sprintf(t, "%d", symbol_Table [i].value.intVal);
            str_value = strdup(t);
        }
        else if(strcmp(symbol_Table[i].type, "float") == 0){
            char t[100];
            sprintf(t, "%f", symbol_Table [i].value.floatVal);
            str_value = strdup(t);
        }
        else if(strcmp(symbol_Table[i].type, "bool") == 0){
            char t[100];
            sprintf(t, "%d", symbol_Table [i].value.boolVal);
            str_value = strdup(t);
        }
        else if(strcmp(symbol_Table[i].type, "string") == 0){
            str_value = symbol_Table [i].value.stringVal;
        }
        printf("SymbolTable() : Name: { %s }, Type: { %s }, Value: { %s }, isDeclared: { %d }, isConst: { %d }, isInit: { %d }, isUsed: { %d }, Symbol table idx: { %d } , Scope Level: { %d }\n", symbol_Table [i].name, symbol_Table [i].type, str_value, symbol_Table [i].isDecl, symbol_Table [i].isConst,symbol_Table [i].isInit, symbol_Table [i].isUsed, i,symbol_Table [i].scope); 
    }
}


// ------------------------------------------------------------------------------- 
// Setter functions 
// -------------------------------------------------------------------------------  
void setInit(char* name) {
    printf("{*inside Function*} setInit(char* name = %s)\n", name );
    int lvl;
    for(int i=sym_table_idx-1;i>=0;i--) {
        if(strcmp(symbol_Table[i].name ,name)==0) { //checks if a Variable is declared before 
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
        if(strcmp(symbol_Table[i].name ,name)==0) { //checks if a Variable is declared before 
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

// this function checks that all variables are used
void UnusedVaribles() {
    for(int i=0;i<sym_table_idx;i++) {
        if(symbol_Table[i].isUsed == 0) {
            Show_Semantic_Error(UNUSED, symbol_Table[i].name);
        }
    }
}

////////////////  QUAD GENERATION //////////////////////

void quadStartFunction(char* function) // TODO: make it string isnetad of char
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tPROC %s\n", line, function);
        }
}
void quadEndFunction(char* function)
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tENDPROC %s\n", line, function);
        }
}
void quadCallFunction(char* function)
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tCALL %s\n", line, function);
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
void quadPushIdentifier(char* symbol)
{
       if (SHOW_Quads) {
               printf("Quads(%d) \tPUSH %s\n", line, symbol);
       }
}
void quadPushString(char* str)
{
       if (SHOW_Quads) {
               printf("Quads(%d) \tPUSH %s\n", line, str);
       }
}
void quadPopIdentifier(char* symbol)
{
       if (SHOW_Quads) {
            printf("Quads(%d) \tPOP %s\n\n", line, symbol);
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
void quadPushLastIdentifierStack(char* identifier){
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
    char* identifier = lastIdentifierStack[lastIdentifierStackPointer];
    if (SHOW_Quads) {
            printf("Quads(%d) \tPUSH %s\n", line, identifier);
    }
}
void quadPopLastIdentifierStack(){
    if (lastIdentifierStackPointer < 0){
        printf("Quads(%d) Error: No last identifier to pop. Segmenration Fault\n", line);
        return;
    }
    /* get the last IDENTIFIER from the stack */
    char* identifier = lastIdentifierStack[lastIdentifierStackPointer--];
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

void quadStartEnum(char* enumName) 
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tENUM %s\n", line, enumName);
        }
}
void quadEndEnum(char* enumName) 
{
        if (SHOW_Quads) {
                printf("Quads(%d) \tENDENUM %s\n", line, enumName);
        }
}

// ========================================

int main(void) {
    //enumValues = createIntNode(0); //TODO: test this
    // createStringNode("");
    printStringValues = malloc(sizeof(struct nodeType));
    printStringValues->type = "string";
    printStringValues->isConst = 0;
    printStringValues->value.stringVal = strdup("");
    //////////
    //intialize the scopes table 
    for (int i = 0; i < 100; i++) {
        scopes[i] = 0; //default scope = 0 (No scope)
    }
    yyparse();
    UnusedVaribles();
    printSymbolTable();
    return 0;
}
