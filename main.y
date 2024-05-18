%{
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

%}
/* Yacc definitions */

%start program // defines the starting symbol

// Union here defines the expected values in symbol table 
%union {
        int TYPE_INT; 
        int TYPE_BOOL;
        float TYPE_FLOAT;
        char* TYPE_STR;
        void* TYPE_VOID;
        char* TYPE_DATA_TYPE;
        struct nodeType* TYPE_NODE;
        char* TYPE_DATA_MODIFIER;
;}

//Precedence of Operators (the upper is the lower precedence)
%right '='
%left  AND OR 
%left EQ NEQ
%left GT GEQ LT LEQ 
%left  '+' '-' 
%right NOT 
%left  '*' '/' '%' 

//-----------TOKENS-------------
// Data Types
%token <TYPE_INT> INTEGER
%token <TYPE_FLOAT> FLOAT_
%token <TYPE_STR> STRING
%token <TYPE_BOOL> TRUE_VAL 
%token <TYPE_BOOL> FALSE_VAL 
%token RETURN ENUM 

//------------------------
//Control Commands
%token PRINT
%token ASSERT
%token EXIT

//------------------------
//Flow Statements
%token IF ELSE
%token SWITCH CASE DEFAULT

//------------------------
// LOOPS
%token WHILE FOR BREAK CONTINUE REPEAT UNTIL

//------------------------
// Return Types
%type <TYPE_VOID> program codeBlock controlStatement statement stmts
%type <TYPE_NODE> term expr assignment printList


//------------------------
// Flow Statements
%type <TYPE_VOID> ifCondition switchCase case caseList dummyNonTerminal while forLoop repeatUntil

//------------------------
// Decleration
%token <TYPE_DATA_MODIFIER> CONST
%token <TYPE_DATA_TYPE> INT_DATA_TYPE FLOAT_DATA_TYPE STRING_DATA_TYPE BOOL_DATA_TYPE VOID_DATA_TYPE
%type <TYPE_NODE> dataType decleration functionCall
%token <TYPE_STR> IDENTIFIER

//------------------------
// Functions
%type <TYPE_VOID> functionArgs functionDefinition functionDefinitionAfter

%%
program:
        // program expr '\n' { printf("%d\n", $2->value.intVal); }
        | functionDefinition {printf("{*inside Rule*} program -> functionDefinition : \n");} {printf("{*outside Rule*} program -> functionDefinition : \n---------------------------------\n");}
        | stmts {printf("{*inside Rule*} program -> statements : \n");}{printf("{*outside Rule*} program -> statements : \n---------------------------------\n");}
        | stmts program {printf("{*inside Rule*} program -> statements program : \n");}{printf("{*outside Rule*} program -> statements program : \n---------------------------------\n");}
        | functionDefinition program {printf("{*inside Rule*} program -> functionDefinition program : \n");}     {printf("{*outside Rule*} program -> functionDefinition program : \n---------------------------------\n");}   
        |  {;}
        ;

/*------Control Statements----------*/
controlStatement: {quadPushStartLabel(++startLabelNum);} while {quadPopStartLabel();}
                | forLoop {quadPopStartLabel();}
                | {quadPushEndLabel(++endLabelNum);} ifCondition {quadPopEndLabel();}
                | {quadPushEndLabel(++endLabelNum);} switchCase {quadPopEndLabel();}
                | {quadPushStartLabel(++startLabelNum);} repeatUntil {quadPopStartLabel();}
                ;


/* Decleration */
dataModifier: CONST        {printf("{*inside Rule*} dataModifier -> CONST . : \n");}{printf("{*outside Rule*} dataModifier -> CONST . : \n---------------------------------\n");}

dataType: INT_DATA_TYPE    {printf("{*inside Rule*} dataType -> INT_DATA_TYPE : \n");} { $$ = createIntNode(0); printf("{*outside Rule*} dataType -> INT_DATA_TYPE : \n---------------------------------\n");}
        | FLOAT_DATA_TYPE  {printf("{*inside Rule*} dataType -> FLOAT_DATA_TYPE : \n");} { $$ = createNode("float"); printf("{*outside Rule*} dataType -> FLOAT_DATA_TYPE : \n---------------------------------\n");}
        | STRING_DATA_TYPE {printf("{*inside Rule*} dataType -> STRING_DATA_TYPE : \n");} { $$ = createNode("string"); printf("{*outside Rule*} dataType -> STRING_DATA_TYPE : \n---------------------------------\n");}
        | BOOL_DATA_TYPE   {printf("{*inside Rule*} dataType -> BOOL_DATA_TYPE : \n");} { $$ = createNode("bool"); printf("{*outside Rule*} dataType -> BOOL_DATA_TYPE : \n---------------------------------\n");}
        | VOID_DATA_TYPE   {printf("{*inside Rule*} dataType -> VOID_DATA_TYPE : \n");} { ; }{printf("{*outside Rule*} dataType -> VOID_DATA_TYPE : \n---------------------------------\n");}
        ;
/* */
decleration: dataType IDENTIFIER                          {printf("{*inside Rule*} decleration -> dataType IDENTIFIER : \n");} {int updated_scope_level = checkSameScope($2);  insert($2, $1->type, 0, 0, 0, updated_scope_level); } { quadPopIdentifier($2);}{printf("{*outside Rule*} decleration -> dataType IDENTIFIER : \n---------------------------------\n");}
           | dataType IDENTIFIER  '='  expr               {printf("{*inside Rule*} decleration -> dataType IDENTIFIER   '='  expr   : \n");}  {int updated_scope_level = checkSameScope($2);  nodeNodeTypeCheck($1, $4); insert($2, $1->type, 0, 1, 0, updated_scope_level);  if(updated_scope_level != -1){updateIdentifierValue($2,$4);} } { quadPopIdentifier($2);} {printf("{*outside Rule*} decleration -> dataType IDENTIFIER   '='  expr   : \n---------------------------------\n");}
           | dataModifier dataType IDENTIFIER  '='  expr  {printf("{*inside Rule*} decleration -> dataModifier dataType IDENTIFIER  '='  expr : \n");}  {int updated_scope_level = checkSameScope($3);  nodeNodeTypeCheck($2, $5); insert($3, $2->type, 1, 1, 0, updated_scope_level);  if(updated_scope_level != -1){updateIdentifierValue($3,$5);}  }   {  quadPopIdentifier($3);}{printf("{*outside Rule*} decleration -> dataModifier dataType IDENTIFIER  '='  expr : \n---------------------------------\n");}            
           ;
           
/* Assignment */
assignment: 
            IDENTIFIER '='  expr                    {printf("{*inside Rule*} assignment -> IDENTIFIER '='  expr   : \n");} { int Out_of_scope = checkUndeclared_and_OutOfScope($1); if (Out_of_scope == 0 ){ int constant = checkConst($1); if (constant == 0){ identifierNodeTypeCheck($1, $3); setInit($1); setUsed($1); updateIdentifierValue($1,$3); }}} { $$ = $3; quadPopIdentifier($1); printf("{*outside Rule*} assignment -> IDENTIFIER '='  expr   : \n---------------------------------\n");}
            | enumDefinition                               {printf("{*inside Rule*} assignment -> enumDefinition   : \n");}{printf("{*outside Rule*} assignment -> enumDefinition   : \n---------------------------------\n");}             
            | ENUM enumDeclaration                  {printf("{*inside Rule*} assignment -> ENUM enumDeclaration   : \n");}{printf("{*outside Rule*} assignment -> ENUM enumDeclaration   : \n---------------------------------\n");}
            ; 

/* Expression */
expr:
        term                      {printf("{*inside Rule*} expr -> term   : \n");} { $$ = $1; printf("{*outside Rule*} expr -> term   : \n---------------------------------\n");} 
        | '(' dataType ')' term   {printf("{*inside Rule*} expr ->  '(' dataType ')' term   : \n");} {quadInstruction("CAST"); $$ = castingTo($4, $2->type);printf("{*outside Rule*} expr ->  '(' dataType ')' term   : \n---------------------------------\n");}
        | '-' term                {printf("{*inside Rule*} expr -> '-' term   : \n");} {quadInstruction("NEG"); $$ = Negation($2); printf("{*outside Rule*} expr -> '-' term   : \n---------------------------------\n");}
        | expr '+' expr           {printf("{*inside Rule*} expr -> expr '+' expr   : \n");} {quadInstruction("ADD"); $$ = arithmatic($1,$3,"+"); printf("{*outside Rule*} expr -> expr '+' expr   : \n---------------------------------\n");}
        | expr '-' expr           {printf("{*inside Rule*} expr -> expr '-' expr   : \n");} {quadInstruction("SUB"); $$ = arithmatic($1,$3,"-"); printf("{*outside Rule*} expr -> expr '-' expr   : \n---------------------------------\n");}
        | expr '*' expr           {printf("{*inside Rule*} expr -> expr '*' expr   : \n");} {quadInstruction("MUL"); $$ = arithmatic($1,$3,"*"); printf("{*outside Rule*} expr -> expr '*' expr   : \n---------------------------------\n");}
        | expr '/' expr           {printf("{*inside Rule*} expr -> expr '/' expr   : \n");} {quadInstruction("DIV"); $$ = arithmatic($1,$3,"/"); printf("{*outside Rule*} expr -> expr '/' expr   : \n---------------------------------\n");}
        | expr '%' expr           {printf("{*inside Rule*} expr -> expr '%' expr   : \n");} {quadInstruction("MOD"); $$ = arithmatic($1,$3,"%"); printf("{*outside Rule*} expr -> expr '%' expr   : \n---------------------------------\n");}
        | expr EQ expr            {printf("{*inside Rule*} expr -> expr EQ expr   : \n");} {quadInstruction("EQ");  $$ = doComparison($1,$3,"==");printf("{*outside Rule*} expr -> expr EQ expr   : \n---------------------------------\n");}
        | expr NEQ expr           {printf("{*inside Rule*} expr -> expr NEQ expr   : \n");} {quadInstruction("NEQ");  $$ = doComparison($1,$3,"!=");printf("{*outside Rule*} expr -> expr NEQ expr   : \n---------------------------------\n");} 
        | expr LT expr            {printf("{*inside Rule*} expr -> expr LT expr   : \n");} {quadInstruction("LT");  $$ = doComparison($1,$3,"<"); printf("{*outside Rule*} expr -> expr LT expr   : \n---------------------------------\n");}
        | expr GT expr            {printf("{*inside Rule*} expr -> expr GT expr   : \n");} {quadInstruction("GT");  $$ = doComparison($1,$3,">"); printf("{*outside Rule*} expr -> expr GT expr   : \n---------------------------------\n");}
        | expr GEQ expr           {printf("{*inside Rule*} expr -> expr GEQ expr   : \n");} {quadInstruction("GEQ");  $$ = doComparison($1,$3,">="); printf("{*outside Rule*} expr -> expr GEQ expr   : \n---------------------------------\n");} 
        | expr LEQ expr           {printf("{*inside Rule*} expr -> expr LEQ expr   : \n");} {quadInstruction("LEQ");  $$ = doComparison($1,$3,"<="); printf("{*outside Rule*} expr -> expr LEQ expr   : \n---------------------------------\n");}
        | expr AND expr           {printf("{*inside Rule*} expr -> expr AND expr   : \n");} {quadInstruction("LOGICAL_AND"); $$ = logical($1,$3,"&"); printf("{*outside Rule*} expr -> expr AND expr   : \n---------------------------------\n");} 
        | expr OR expr            {printf("{*inside Rule*} expr -> expr OR expr   : \n");} {quadInstruction("LOGICAL_OR"); $$ = logical($1,$3,"|"); printf("{*outside Rule*} expr -> expr OR expr   : \n---------------------------------\n");}
        | NOT expr                {printf("{*inside Rule*} expr -> NOT expr   : \n");} {quadInstruction("NOT"); $$ = logical($2,NULL,"!"); printf("{*outside Rule*} expr -> NOT expr   : \n---------------------------------\n");}
        | '(' expr ')'            {printf("{*inside Rule*} expr -> '(' expr ')'   : \n");} { $$ = $2;printf("{*outside Rule*} expr -> '(' expr ')'   : \n---------------------------------\n");}
        ;

term: 
        INTEGER                {printf("======================================\n");}    {printf("{*inside Rule*} term -> INTEGER   %d  : \n",$1);}  {quadPushInt($1); }  { $$ = createIntNode($1);    $$->value.intVal = $1; printf("{*outside Rule*} term -> INTEGER   %d  : \n",$1);}
                               
        | FLOAT_         {printf("======================================\n");}    {printf("{*inside Rule*} term -> FLOAT_     %f  : \n",$1);} {quadPushFloat($1); }    { $$ = createNode("float");  $$->value.floatVal = $1 ;printf("{*outside Rule*} term -> FLOAT_     %f  : \n",$1);}
        | STRING              {printf("======================================\n");}     {printf("{*inside Rule*} term -> STRING    %s  : \n",$1);} {quadPushString($1);} { $$ = createNode("string"); $$->value.stringVal = strdup($1);printf("{*outside Rule*} term -> STRING    %s  : \n",$1);}
        | TRUE_VAL            {printf("======================================\n");}     {printf("{*inside Rule*} term -> TRUE_VAL   %d     : \n",$1);} {quadPushInt(1);}   { $$ = createNode("bool");   $$->value.boolVal = 1;printf("{*outside Rule*} term -> TRUE_VAL  %d      : \n---------------------------------\n",$1);}
        | FALSE_VAL           {printf("======================================\n");}     {printf("{*inside Rule*} term -> FALSE_VAL  %d     : \n",$1);} {quadPushInt(0);}   { $$ = createNode("bool");   $$->value.boolVal = 0;printf("{*outside Rule*} term -> FALSE_VAL    %d        : \n---------------------------------\n",$1);}
        | IDENTIFIER          {printf("======================================\n");}     {printf("{*inside Rule*} term -> IDENTIFIER  %s  : \n",$1);} {quadPushIdentifier($1);} {int Out_of_scope = checkUndeclared_and_OutOfScope($1); if (Out_of_scope == 0 ){int Initialized = checkInitialized($1); if ( Initialized == 1 ) {setUsed($1); $$ = identifierValue($1);} else {$$ = NULL;}} printf("{*outside Rule*} term -> IDENTIFIER  %s  : \n",$1);} 
        | '(' term ')'        {printf("======================================\n");}     {printf("{*inside Rule*} term -> '(' term ')'    : \n");} { $$ = $2; printf("{*outside Rule*} term -> '(' term ')'    : \n---------------------------------\n");}
        ;



dummyNonTerminal:  {printf("inside dummy  \n");}
                ;

/* ----------------Conditions--------------- */
ifCondition  : IF '(' {ifCon=1;} expr {checkConstIF($4); quadJumpFalseLabel(++labelNum);} {printf("IF () is detected \n");} ')' '{' {enterScope();} {printf("IF (){} is detected \n");} codeBlock '}' {quadJumpEndLabel(); exitScope(); quadPopLabel();} elseCondition {;}
             ;
elseCondition: {printf("inside bare else  \n");}  {;}
             | ELSE {;} {printf("inside else  \n");} ifCondition {;}
             | ELSE '{' {fromElse=1;}  {enterScope();} codeBlock '}' {exitScope();} {printf("else {} detected \n");} 
             ;

switchCase: SWITCH '(' IDENTIFIER {setUsed($3); switchC=1;} ')' {printf("switch case passed  \n");} {quadPushLastIdentifierStack($3);setInit($3);} '{' {enterScope();} caseList '}' {exitScope();} {quadPopLastIdentifierStack();}
          ;
caseList : caseList case 
         | case  
         ;

case    : CASE {printf("before case \n");} expr  {quadPeakLastIdentifierStack(); quadJumpFalseLabel(++labelNum);} ':' {printf("inside case  \n");}  stmts {quadPopLabel();}
        | DEFAULT ':'  {switchC=0; switchMatch=0;}  stmts {;}
        ;


/*---------------------------------------*/

/* ----------------Loops--------------- */
while: 
        WHILE '(' expr {whileLoopFound=1; }')' {printf("Found a while loop!\n");} {quadJumpFalseLabel(++labelNum);} '{'{enterScope();} codeBlock  '}' {/*end*/ exitScope(); quadJumpStartLabel(); quadPopLabel();} { whileLoopFound=0;}    {;}
        ;
forLoop: 
        FOR '(' {printf("for \n"); forLoopFound=1;} decleration ';' {printf("for \n");}  {quadPushStartLabel(++startLabelNum);} expr ';' {quadJumpFalseLabel(++labelNum);} assignment ')' '{'{enterScope();} codeBlock '}'{exitScope(); quadJumpStartLabel(); quadPopLabel();} {;}
        // | FOR '(' IDENTIFIER ':' expr '->' expr ')' '{' codeBlock '}' //TODO: implement This assignment
        // | FOR '(' IDENTIFIER ':' expr '<-' expr ')' '{' codeBlock '}' //TODO: implement This assignment
        
       ;// for (i : 0 -> 4)
repeatUntil: 
        REPEAT '{' {enterScope();} codeBlock '}'{exitScope();} UNTIL '(' expr ')' ';' {quadJumpFalseLabel(++labelNum); quadJumpStartLabel(); quadPopLabel();} //TODO: implement This assignment
        ;
/*---------------------------------------*/

/* ----------------Enumerations--------------- */
enumDefinition:	           
        ENUM IDENTIFIER {printf("{*inside Rule*} enumDefinition -> ENUM IDENTIFIER   : \n");}{quadStartEnum($2); checkSameScope($2); insert($2, "enum", 1, 1, 0, scopes[scope_idx-1]);} '{' enumBody '}' {quadEndEnum($2); enumCounter=0;}{printf("{*outside Rule*} enumDefinition -> ENUM IDENTIFIER   : \n---------------------------------\n");}
        ;
                        
enumBody:
        IDENTIFIER                               {printf("{*inside Rule*} enumBody -> IDENTIFIER   : \n");} {checkSameScope($1); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue($1,enumValues); enumValues->value.intVal = 0; quadPushInt(++enumCounter); quadPopIdentifier($1);}{printf("{*outside Rule*} enumBody -> IDENTIFIER   : \n---------------------------------\n");}
        | IDENTIFIER '=' expr                    {printf("{*inside Rule*} enumBody -> IDENTIFIER '=' expr    : \n");} {checkSameScope($1); nodeNodeTypeCheck(enumValues,$3); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo($3, "int")->value.intVal; updateIdentifierValue($1, enumValues); quadPopIdentifier($1);}{printf("{*outside Rule*} enumBody -> IDENTIFIER '=' expr    : \n---------------------------------\n");} 
        | IDENTIFIER ',' enumBody                {printf("{*inside Rule*} enumBody -> IDENTIFIER ',' enumBody    : \n");} {checkSameScope($1); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue($1, enumValues); enumValues->value.intVal++; quadPushInt(++enumCounter); quadPopIdentifier($1);}{printf("{*outside Rule*} enumBody -> IDENTIFIER ',' enumBody    : \n---------------------------------\n");}
        | IDENTIFIER '=' expr ',' enumBody       {printf("{*inside Rule*} enumBody -> IDENTIFIER '=' expr ',' enumBody    : \n");} {checkSameScope($1); nodeNodeTypeCheck(enumValues,$3); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo($3, "int")->value.intVal; updateIdentifierValue($1, enumValues); quadPopIdentifier($1);} {printf("{*outside Rule*} enumBody -> IDENTIFIER '=' expr ',' enumBody    : \n---------------------------------\n");} 
        
enumDeclaration: /*TODO:[Add] int Out_of_scope = checkUndeclared_and_OutOfScope($1); if (Out_of_scope == 0 ){...}*/
        IDENTIFIER IDENTIFIER                    {printf("{*inside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER   : \n");} {checkUndeclared_and_OutOfScope($1); identifierNodeTypeCheck($1,createNode("enum")); checkSameScope($2); insert($2, "int", 0, 0, 0, scopes[scope_idx-1]);}{printf("{*outside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER   : \n---------------------------------\n");}
        | IDENTIFIER IDENTIFIER '=' expr         {printf("{*inside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER  '=' expr    : \n");} {checkUndeclared_and_OutOfScope($1); identifierNodeTypeCheck($1,createNode("enum")); checkSameScope($2); insert($2, "int", 0, 1, 0, scopes[scope_idx-1]); nodeNodeTypeCheck($4,createIntNode(0)); updateIdentifierValue($2,castingTo($4, "int")); quadPopIdentifier($2);}{printf("{*outside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER  '=' expr    : \n---------------------------------\n");} 
        ;


/* ------------Statement----------------- */
printList: 
            expr                                {printf("{*inside Rule*} printList -> expr      : \n");} {char* str1 = printStringValues->value.stringVal; printf("str1 : { %s }\n",str1); char* str2 = castingTo($1, "string")->value.stringVal;  printf("str2 : { %s }\n",str2); strcat(str1, str2); printStringValues->value.stringVal =  str1; printf("printStringValues : { %s }\n",printStringValues->value.stringVal);}{printf("{*outside Rule*} printList -> expr      : \n---------------------------------\n");}
            | printList  ',' expr            {printf("{*inside Rule*} printList -> printList ',' expr      : \n");} {char* str1 = printStringValues->value.stringVal; printf("str1 : { %s }\n",str1); char* str2 = castingTo($3, "string")->value.stringVal; printf("str2 : { %s }\n",str2);  strcat(str1, str2); printStringValues->value.stringVal =  str1; printf("printStringValues : { %s }\n",printStringValues->value.stringVal);} {printf("{*outside Rule*} printList -> printList ',' expr      : \n---------------------------------\n");}// Concatenate str2 to str1 (result is stored in str1)
            ;
statement: 
            assignment                          {printf("{*inside Rule*} statement -> assignment  : \n");} {;}{printf("{*outside Rule*} statement -> assignment  : \n---------------------------------\n");} 
            | expr                              {printf("{*inside Rule*} statement ->  expr  : \n");}{printf("{*outside Rule*} statement ->  expr  : \n---------------------------------\n");}
            | decleration                       {printf("{*inside Rule*} statement ->  decleration  : \n");} {;}{printf("{*outside Rule*} statement ->  decleration  : \n---------------------------------\n");}
            | EXIT 		                        {printf("{*inside Rule*} statement ->  EXIT  : \n");} {exit(EXIT_SUCCESS);}{printf("{*outside Rule*} statement ->  EXIT  : \n---------------------------------\n");}
            | BREAK 		                    {printf("{*inside Rule*} statement ->  BREAK  : \n");} {quadJumpEndLabel();}{printf("{*outside Rule*} statement ->  BREAK  : \n---------------------------------\n");}
            | CONTINUE 		                    {printf("{*inside Rule*} statement ->  CONTINUE  : \n");} {;}{printf("{*outside Rule*} statement ->  CONTINUE  : \n---------------------------------\n");} 
            | RETURN 		                    {printf("{*inside Rule*} statement ->  RETURN  : \n");} {quadReturn();}{printf("{*outside Rule*} statement ->  RETURN  : \n---------------------------------\n");} 
            | RETURN expr 		                {printf("{*inside Rule*} statement ->  RETURN expr  : \n");} {quadReturn(); $$ = $2; printf("{*outside Rule*} statement ->  RETURN expr  : \n---------------------------------\n");}
            | PRINT  '(' expr ')' 		        {printf("{*inside Rule*} statement ->  PRINT  '(' expr ')' : \n");} {printNode($3);}{printf("{*outside Rule*} statement ->  PRINT  '(' expr ')': \n");} //TODO: Implement quadPrint();
            | PRINT  '(' printList ')' 		    {printf("{*inside Rule*} statement ->  PRINT  '(' printList ')': \n");} {$$ = $3;  printNode(printStringValues); printf("{*outside Rule*} statement ->  PRINT  '(' printList ')': \n");} //TODO: Implement quadPrint();
            ;            
/*---------------------------------------*/

/* ------------Statements----------------- */
stmts:   statement ';'                                 {printf("{*inside Rule*} statements -> statement ';' : \n---------------------------------\n");}{;}{printf("{*outside Rule*} statements -> statement ';' : \n");}     
            | controlStatement                              {printf("{*inside Rule*} statements -> controlStatement  : \n---------------------------------\n");}{;}{printf("{*outside Rule*} statements -> controlStatement  : \n");}
            | stmts statement ';'                      {printf("{*inside Rule*} statements -> statements statement ';'  : \n---------------------------------\n");}{;}{printf("{*outside Rule*} statements -> statements statement ';'  :   \n");}
            | '{'{enterScope();} codeBlock '}'              {printf("{*inside Rule*} statements -> '{' codeBlock '}'   : \n");}{exitScope();}{printf("{*outside Rule*} statements -> '{' codeBlock '}' : \n---------------------------------\n");}
            | stmts controlStatement                   {printf("{*inside Rule*} statements -> statements controlStatement : \n");}{printf("{*outside Rule*} statements -> statements controlStatement : \n---------------------------------\n");}    
            | stmts '{'{enterScope();} codeBlock '}'   {printf("{*inside Rule*} statements -> statements '{' codeBlock '}'  : \n");}{exitScope();} {;}{printf("{*outside Rule*} statements -> statements '{' codeBlock '}'  : \n---------------------------------\n");}
        ;
/*---------------------------------------*/

/* ------------Code Block----------------- */
codeBlock:  stmts                                    {printf("======================================\n");}  {printf("{*inside Rule*} codeBlock -> statements ';' : \n");} {printf("{*outside Rule*} codeBlock -> statements ';' : \n---------------------------------\n");}
         ;
/*---------------------------------------*/

/* ------------Functions----------------- */ //TODO: How to handle X = func() 
functionArgs            : dataType IDENTIFIER                   {quadPopIdentifier($2);} {checkSameScope($2); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]) ;funcFirstarg=sym_table_idx-1;   argCount = sym_table_idx-argCount; setInit($2);}
                        | dataType IDENTIFIER  {quadPopIdentifier($2);} {checkSameScope($2); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]);setInit($2); } ',' functionArgs
                        ;  
functionParams          : term   {typeCheck3($1->type, symbol_Table[++funcPointer].type); paramCount--; }
                        | term   {typeCheck3($1->type, symbol_Table[++funcPointer].type); paramCount--;} ',' functionParams
                        ;
functionDefinition: dataType IDENTIFIER {quadStartFunction($2);} {checkSameScope($2); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]); argCount = sym_table_idx; enterScope(); setInit($2);}
                     {printf("here \n");} functionDefinitionAfter '{' codeBlock '}'  {exitScope(); quadEndFunction($2); updateSymbolParam($2, argCount);}
                  ;
functionDefinitionAfter: '(' functionArgs ')' {printf("definitions with params  \n");}
                        | '(' ')' {printf("definitions without params  \n");}
                        ;
functionCall            : IDENTIFIER { paramCount = symbolVal($1)->value.intVal; funcPointer = getSymbolIndex($1); } functionCallRest {checkUndeclared_and_OutOfScope($1); $$ = symbolVal($1); quadCallFunction($1); if(paramCount != 0){Show_Semantic_Error(UNDECLARED, $1);}}
                        ;
functionCallRest        : '(' functionParams ')'             {;}
                        | '('              ')'               {;}
                        ;
%%

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