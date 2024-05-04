%{
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
%token <TYPE_FLOAT> FLOAT_NUMBER
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
%type <TYPE_VOID> program codeBlock controlStatement statement statements
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
        | functionDefinition {printf("{*inside Rule*} program -> functionDefinition : \n");}
        | statements {printf("{*inside Rule*} program -> statements : \n");}
        | statements program {printf("{*inside Rule*} program -> statements program : \n");}
        | functionDefinition program {printf("{*inside Rule*} program -> functionDefinition program : \n");;}        
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
dataModifier: CONST        {printf("{*inside Rule*} dataModifier -> CONST : \n");}

dataType: INT_DATA_TYPE    {printf("{*inside Rule*} dataModifier -> INT_DATA_TYPE : \n");} { $$ = createIntNode(0); }
        | FLOAT_DATA_TYPE  {printf("{*inside Rule*} dataModifier -> FLOAT_DATA_TYPE : \n");} { $$ = createNode("float"); }
        | STRING_DATA_TYPE {printf("{*inside Rule*} dataModifier -> STRING_DATA_TYPE : \n");} { $$ = createNode("string"); }
        | BOOL_DATA_TYPE   {printf("{*inside Rule*} dataModifier -> BOOL_DATA_TYPE : \n");} { $$ = createNode("bool"); }
        | VOID_DATA_TYPE   {printf("{*inside Rule*} dataModifier -> VOID_DATA_TYPE : \n");} { ; }
        ;
/* */
decleration: dataType IDENTIFIER                          {printf("{*inside Rule*} decleration -> dataType IDENTIFIER : \n");} {checkSameScope($2);  insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]); } {printSymbolTable(); quadPopIdentifier($2);}
           | dataType IDENTIFIER  '='  expr               {printf("{*inside Rule*} decleration -> dataType IDENTIFIER   '='  expr   : \n");}  {checkSameScope($2);  nodeNodeTypeCheck($1, $4); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]);  updateIdentifierValue($2,$4); setInit($2); } {printSymbolTable(); quadPopIdentifier($2);} 
           | dataModifier dataType IDENTIFIER  '='  expr  {printf("{*inside Rule*} decleration -> dataModifier dataType IDENTIFIER  '='  expr : \n");}  {checkSameScope($3);  nodeNodeTypeCheck($2, $5); insert($3, $2->type, 1, 0, 0, scopes[scope_idx-1]);  updateIdentifierValue($3,$5); setInit($3); }  {printSymbolTable();} {printSymbolTable();  quadPopIdentifier($3);}            
           ;
           
/* Assignment */
assignment: 
            IDENTIFIER '='  expr                    {printf("{*inside Rule*} assignment -> IDENTIFIER '='  expr   : \n");} { checkOutOfScope($1); checkConst($1); identifierNodeTypeCheck($1, $3); setInit($1); setUsed($1); updateIdentifierValue($1,$3); } {printSymbolTable();}{printf(castingTo($3,"string")->value.stringVal); $$ = $3; quadPopIdentifier($1);}
            | enumDef                               {printf("{*inside Rule*} assignment -> enumDef   : \n");}            
            | ENUM enumDeclaration                  {printf("{*inside Rule*} assignment -> ENUM enumDeclaration   : \n");}
            ;

/* Expression */
expr:
        term                      {printf("{*inside Rule*} expr -> term   : \n");} { $$ = $1; } 
        | '(' dataType ')' term   {printf("{*inside Rule*} expr ->  '(' dataType ')' term   : \n");} {quadInstruction("CAST"); $$ = castingTo($4, $2->type);}
        | '-' term                {printf("{*inside Rule*} expr -> '-' term   : \n");} {quadInstruction("NEG"); $$ = Negation($2); }
        | expr '+' expr           {printf("{*inside Rule*} expr -> expr '+' expr   : \n");} {quadInstruction("ADD"); $$ = arithmatic($1,$3,"+"); } 
        | expr '-' expr           {printf("{*inside Rule*} expr -> expr '-' expr   : \n");} {quadInstruction("SUB"); $$ = arithmatic($1,$3,"-"); }
        | expr '*' expr           {printf("{*inside Rule*} expr -> expr '*' expr   : \n");} {quadInstruction("MUL"); $$ = arithmatic($1,$3,"*"); }
        | expr '/' expr           {printf("{*inside Rule*} expr -> expr '/' expr   : \n");} {quadInstruction("DIV"); $$ = arithmatic($1,$3,"/"); }
        | expr '%' expr           {printf("{*inside Rule*} expr -> expr '%' expr   : \n");} {quadInstruction("MOD"); $$ = arithmatic($1,$3,"%"); }
        | expr EQ expr            {printf("{*inside Rule*} expr -> expr EQ expr   : \n");} {quadInstruction("EQ");  $$ = doComparison($1,$3,"==");} 
        | expr NEQ expr           {printf("{*inside Rule*} expr -> expr NEQ expr   : \n");} {quadInstruction("NEQ");  $$ = doComparison($1,$3,"!=");}
        | expr LT expr            {printf("{*inside Rule*} expr -> expr LT expr   : \n");} {quadInstruction("LT");  $$ = doComparison($1,$3,"<"); }
        | expr GT expr            {printf("{*inside Rule*} expr -> expr GT expr   : \n");} {quadInstruction("GT");  $$ = doComparison($1,$3,">"); }
        | expr GEQ expr           {printf("{*inside Rule*} expr -> expr GEQ expr   : \n");} {quadInstruction("GEQ");  $$ = doComparison($1,$3,">="); }
        | expr LEQ expr           {printf("{*inside Rule*} expr -> expr LEQ expr   : \n");} {quadInstruction("LEQ");  $$ = doComparison($1,$3,"<="); }
        | expr AND expr           {printf("{*inside Rule*} expr -> expr AND expr   : \n");} {quadInstruction("LOGICAL_AND"); $$ = logical($1,$3,"&"); } 
        | expr OR expr            {printf("{*inside Rule*} expr -> expr OR expr   : \n");} {quadInstruction("LOGICAL_OR"); $$ = logical($1,$3,"|"); }
        | NOT expr                {printf("{*inside Rule*} expr -> NOT expr   : \n");} {quadInstruction("NOT"); $$ = logical($2,NULL,"!"); }
        | '(' expr ')'            {printf("{*inside Rule*} expr -> '(' expr ')'   : \n");} { $$ = $2;}
        ;

term: 
        INTEGER                   {printf("{*inside Rule*} term -> INTEGER   : \n");} {quadPushInt($1); }  { $$ = createIntNode($1);    $$->value.intVal = $1;}
        | FLOAT_NUMBER            {printf("{*inside Rule*} term -> FLOAT_NUMBER    : \n");} {quadPushFloat($1); }    { $$ = createNode("float");  $$->value.floatVal = $1;}
        | STRING                  {printf("{*inside Rule*} term -> STRING    : \n");} {quadPushString($1);} { $$ = createNode("string"); $$->value.stringVal = strdup($1);}
        | TRUE_VAL                {printf("{*inside Rule*} term -> TRUE_VAL    : \n");} {quadPushInt(1);}   { $$ = createNode("bool");   $$->value.boolVal = 1;}
        | FALSE_VAL               {printf("{*inside Rule*} term -> FALSE_VAL    : \n");} {quadPushInt(0);}   { $$ = createNode("bool");   $$->value.boolVal = 0;}
        | IDENTIFIER              {printf("{*inside Rule*} term -> IDENTIFIER    : \n");} {quadPushIdentifier($1);} {checkOutOfScope($1); checkInitialized($1); $$ = identifierValue($1); setUsed($1);}   
        | '(' term ')'            {printf("{*inside Rule*} term -> '(' term ')'    : \n");} { $$ = $2; }
        ;



dummyNonTerminal:  {printf("inside dummy  \n");}
                ;

/* ----------------Conditions--------------- */
ifCondition  : IF '(' expr {checkConstIF($3); quadJumpFalseLabel(++labelNum);} {printf("IF () is detected \n");} ')' '{' {enterScope();} {printf("IF (){} is detected \n");} codeBlock '}' {printf("asdasd");} {quadJumpEndLabel(); exitScope(); quadPopLabel();} elseCondition {;}
             ;
elseCondition: {printf("inside bare else  \n");}  {;}
             | ELSE {;} {printf("inside else  \n");} ifCondition {;}
             | ELSE '{' {enterScope();} codeBlock '}' {exitScope();} {printf("else {} detected \n");} 
             ;

switchCase: SWITCH '(' IDENTIFIER ')' {printf("switch case passed  \n");} {quadPushLastIdentifierStack($3);setInit($3);} '{' {enterScope();} caseList '}' {exitScope();} {quadPopLastIdentifierStack();}
          ;
caseList : caseList case 
         | case 
         ;

case    : CASE {printf("before case \n");} expr {quadPeakLastIdentifierStack(); quadJumpFalseLabel(++labelNum);} ':' {printf("inside case  \n");} expr statements {quadPopLabel();}
        | DEFAULT ':'    statements {;}
        ;


/*---------------------------------------*/

/* ----------------Loops--------------- */
while: 
        WHILE '(' expr ')' {printf("Found a while loop!\n");} {quadJumpFalseLabel(++labelNum);} '{'{enterScope();} codeBlock  '}' {/*end*/ exitScope(); quadJumpStartLabel(); quadPopLabel();}    {;}
        ;
forLoop: 
        FOR '(' {printf("for \n");} assignment ';' {printf("for \n");}  {quadPushStartLabel(++startLabelNum);} expr ';' {quadJumpFalseLabel(++labelNum);} assignment ')' '{'{enterScope();} codeBlock '}'{exitScope(); quadJumpStartLabel(); quadPopLabel();} {;}
        | FOR '(' IDENTIFIER ':' expr '->' expr ')' '{' codeBlock '}' //TODO: implement This assignment
        | FOR '(' IDENTIFIER ':' expr '<-' expr ')' '{' codeBlock '}' //TODO: implement This assignment
        
       ;// for (i : 0 -> 4)
repeatUntil: 
        REPEAT '{' {enterScope();} codeBlock '}'{exitScope();} UNTIL '(' expr ')' ';' {quadJumpFalseLabel(++labelNum); quadJumpStartLabel(); quadPopLabel();} //TODO: implement This assignment
        ;
/*---------------------------------------*/

/* ----------------Enumerations--------------- */
enumDef:	           
        ENUM IDENTIFIER {printf("{*inside Rule*} enumDef -> ENUM IDENTIFIER   : \n");}{quadStartEnum($2); checkSameScope($2); insert($2, "enum", 1, 1, 0, scopes[scope_idx-1]);} '{' enumBody '}' {quadEndEnum($2); enumCounter=0;}
        ;
                        
enumBody:
        IDENTIFIER                               {printf("{*inside Rule*} enumBody -> IDENTIFIER   : \n");} {checkSameScope($1); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue($1,enumValues); enumValues->value.intVal = 0; quadPushInt(++enumCounter); quadPopIdentifier($1);}
        | IDENTIFIER '=' expr                    {printf("{*inside Rule*} enumBody -> IDENTIFIER '=' expr    : \n");} {checkSameScope($1); nodeNodeTypeCheck(enumValues,$3); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo($3, "int")->value.intVal; updateIdentifierValue($1, enumValues); quadPopIdentifier($1);}
        | IDENTIFIER ',' enumBody                {printf("{*inside Rule*} enumBody -> IDENTIFIER ',' enumBody    : \n");} {checkSameScope($1); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue($1, enumValues); enumValues->value.intVal++; quadPushInt(++enumCounter); quadPopIdentifier($1);}
        | IDENTIFIER '=' expr ',' enumBody       {printf("{*inside Rule*} enumBody -> IDENTIFIER '=' expr ',' enumBody    : \n");} {checkSameScope($1); nodeNodeTypeCheck(enumValues,$3); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo($3, "int")->value.intVal; updateIdentifierValue($1, enumValues); quadPopIdentifier($1);}
        
enumDeclaration: 
        IDENTIFIER IDENTIFIER                    {printf("{*inside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER   : \n");} {checkOutOfScope($1); identifierNodeTypeCheck($1,createNode("enum")); checkSameScope($2); insert($2, "int", 0, 0, 0, scopes[scope_idx-1]);}
        | IDENTIFIER IDENTIFIER '=' expr         {printf("{*inside Rule*} enumDeclaration -> IDENTIFIER IDENTIFIER  '=' expr    : \n");} {checkOutOfScope($1); identifierNodeTypeCheck($1,createNode("enum")); checkSameScope($2); insert($2, "int", 0, 1, 0, scopes[scope_idx-1]); nodeNodeTypeCheck($4,createIntNode(0)); updateIdentifierValue($2,castingTo($4, "int")); quadPopIdentifier($2);}
        ;


/* ------------Statement----------------- */
printList: 
            expr                                {printf("{*inside Rule*} printList -> expr      : \n");} {printNode($1);}
            | printList ',' expr                {printf("{*inside Rule*} printList -> printList ',' expr      : \n");} {char* str1 = castingTo($3, "string")->value.stringVal; char* str2 = printStringValues->value.stringVal;  strcat(str1, str2); printStringValues->value.stringVal =  str1;} // Concatenate str2 to str1 (result is stored in str1)
            ;
statement: 
            assignment                          {printf("{*inside Rule*} statement -> assignment  : \n");} {;}
            | expr                              {printf("{*inside Rule*} statement ->  expr  : \n");} 
            | decleration                       {printf("{*inside Rule*} statement ->  decleration  : \n");} {;}
            | EXIT 		                        {printf("{*inside Rule*} statement ->  EXIT  : \n");} {exit(EXIT_SUCCESS);}
            | BREAK 		                    {printf("{*inside Rule*} statement ->  BREAK  : \n");} {quadJumpEndLabel();} //TODO: 
            | CONTINUE 		                    {printf("{*inside Rule*} statement ->  CONTINUE  : \n");} {;} 
            | RETURN 		                    {printf("{*inside Rule*} statement ->  RETURN  : \n");} {quadReturn();} 
            | RETURN expr 		                {printf("{*inside Rule*} statement ->  RETURN expr  : \n");} {quadReturn(); $$ = $2;} 
            | PRINT  '(' expr ')' 		        {printf("{*inside Rule*} statement ->  PRINT  '(' expr ')' : \n");} {printNode($3);}
            | PRINT  '(' printList ')' 		    {printf("{*inside Rule*} statement ->  PRINT  '(' printList ')': \n");} {$$ = $3;} 
            ;            
/*---------------------------------------*/

/* ------------Statements----------------- */
statements:   statement ';'                                 {printf("{*inside Rule*} statements -> statement ';' : \n");}{;}
            | controlStatement                              {printf("{*inside Rule*} statements -> controlStatement  : \n");}{;}
            | statements statement ';'                      {printf("{*inside Rule*} statements -> statements statement ';'  : \n");}{;}
            | '{'{enterScope();} codeBlock '}'              {printf("{*inside Rule*} statements -> '{' codeBlock '}'   : \n");}{exitScope();}
            | statements controlStatement                   {printf("{*inside Rule*} statements -> statements controlStatement : \n");}
            | statements '{'{enterScope();} codeBlock '}'   {printf("{*inside Rule*} statements -> statements '{' codeBlock '}'  : \n");}{exitScope();} {;}
        ;
/*---------------------------------------*/

/* ------------Code Block----------------- */
codeBlock:  statements                                      {printf("{*inside Rule*} codeBlock -> statements ';' : \n");}
         ;
/*---------------------------------------*/

/* ------------Functions----------------- */ //TODO: How to handle X = func() 
functionArgs            : dataType IDENTIFIER                   {quadPopIdentifier($2);} {checkSameScope($2); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]) ; argCount = sym_table_idx-argCount;}
                        | dataType IDENTIFIER  {quadPopIdentifier($2);} {checkSameScope($2); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]) ;} ',' functionArgs
                        ;  
functionParams          : term   {typeCheck3($1->type, symbol_Table[++funcPointer].type); paramCount--;}
                        | term   {typeCheck3($1->type, symbol_Table[++funcPointer].type); paramCount--;} ',' functionParams
                        ;
functionDefinition: dataType IDENTIFIER {quadStartFunction($2);} {checkSameScope($2); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]); argCount = sym_table_idx; enterScope();}
                     {printf("here \n");} functionDefinitionAfter '{' codeBlock '}'  {exitScope(); quadEndFunction($2); updateSymbolParam($2, argCount);}
                  ;
functionDefinitionAfter: '(' functionArgs ')' {printf("definitions with params  \n");}
                        | '(' ')' {printf("definitions without params  \n");}
                        ;
functionCall            : IDENTIFIER { paramCount = symbolVal($1)->value.intVal; funcPointer = getSymbolIndex($1); } functionCallRest {checkOutOfScope($1); $$ = symbolVal($1); quadCallFunction($1); if(paramCount != 0){Log_SEMANTIC_ERROR(UNDECLARED, $1);}}
                        ;
functionCallRest        : '(' functionParams ')'             {;}
                        | '('              ')'               {;}
                        ;
%%

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