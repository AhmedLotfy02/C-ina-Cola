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
    int sym_table_idx = 0;

    int funcPointer = -1;
    int paramCount = 0;

    #define MAX_STACK_SIZE 100
    int labelNum = 0;
    int labelStackPointer = -1;
    int labelStack[MAX_STACK_SIZE];

    int endLabelNum = 0;
    int endLabelstackPointer = -1;
    int endLabelStack[MAX_STACK_SIZE];

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
    int enumCounter = 0;

                // 23
    
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

    void updateSymbolParam(char symbol, int param);

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
%type <TYPE_NODE> dataType decleration
%token <TYPE_STR> IDENTIFIER

//------------------------
// Functions
%type <TYPE_VOID> functionArgs functionDefinition functionDefinitionAfter

%%
program:
        // program expr '\n' { printf("%d\n", $2->value.intVal); }
        
        | functionDefinition {;}
        | statements {printf("hi1");}
        | statements program {printf("hi2");}
        | functionDefinition program {;}        
        |  {;}
        ;

/*------Control Statements----------*/
controlStatement: while
                | forLoop
                | {quadPushEndLabel(++endLabelNum);} ifCondition {quadPopEndLabel();}
                | switchCase
                | repeatUntil
                ;


/* Decleration */
dataModifier: CONST         {;}

dataType: INT_DATA_TYPE     {printf("int data type \n");} { $$ = createIntNode(0); }
        | FLOAT_DATA_TYPE   {printf("float data type \n");} { $$ = createNode("float"); }
        | STRING_DATA_TYPE  {printf("string data type \n");} { $$ = createNode("string"); }
        | BOOL_DATA_TYPE    {printf("bool data type \n");} { $$ = createNode("bool"); }
        | VOID_DATA_TYPE    {printf("void data type \n");} { ; }
        ;
/* */
decleration: dataType IDENTIFIER                            {checkSameScope($2);  insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]); } {printf("inside decleration \n");} {printSymbolTable();}
           | dataType IDENTIFIER  '='  expr                 {checkSameScope($2);  nodeNodeTypeCheck($1, $4); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]);  updateIdentifierValue($2,$4); setInit($2); } {printf("inside decleration \n");} {printSymbolTable();} 
           | dataModifier dataType IDENTIFIER  '='  expr    {checkSameScope($3);  nodeNodeTypeCheck($2, $5); insert($3, $2->type, 1, 0, 0, scopes[scope_idx-1]);  updateIdentifierValue($3,$5); setInit($3); } {printf("inside decleration \n");} {printSymbolTable();} {printSymbolTable();}            
           ;
           
/* Assignment */
assignment: 
            IDENTIFIER '='  expr                         {printf("inside assignment \n"); checkOutOfScope($1); checkConst($1); identifierNodeTypeCheck($1, $3); setInit($1); setUsed($1); updateIdentifierValue($1,$3); } {printSymbolTable();}{printf(castingTo($3,"string")->value.stringVal); $$ = $3;}
            | enumDef                               {;}            
            | ENUM enumDeclaration              {/*Check declared*/;}
            ;

/* Expression */
expr:
        term                      { $$ = $1; } 
        | '(' dataType ')' term   { $$ = castingTo($4, $2->type);}
        | '-' term                { $$ = Negation($2); }
        | expr '+' expr           { $$ = arithmatic($1,$3,"+"); } 
        | expr '-' expr           { $$ = arithmatic($1,$3,"-"); }
        | expr '*' expr           { $$ = arithmatic($1,$3,"*"); }
        | expr '/' expr           { $$ = arithmatic($1,$3,"/"); }
        | expr '%' expr           { $$ = arithmatic($1,$3,"%"); }
        | expr EQ expr            { $$ = doComparison($1,$3,"==");} 
        | expr NEQ expr           { $$ = doComparison($1,$3,"!=");}
        | expr LT expr            { $$ = doComparison($1,$3,"<"); }
        | expr GT expr            { $$ = doComparison($1,$3,">"); }
        | expr GEQ expr           { $$ = doComparison($1,$3,">="); }
        | expr LEQ expr           { $$ = doComparison($1,$3,"<="); }
        | expr AND expr           { $$ = logical($1,$3,"&"); } 
        | expr OR expr            { $$ = logical($1,$3,"|"); }
        | NOT expr                { $$ = logical($2,NULL,"!"); }
        | '(' expr ')'            { $$ = $2;}
        ;

term: 
        INTEGER                   {printf("integer");}  { $$ = createIntNode($1);    $$->value.intVal = $1;}
        | FLOAT_NUMBER            {printf("float");}    { $$ = createNode("float");  $$->value.floatVal = $1;}
        | STRING                  {printf("string\n");} { $$ = createNode("string"); $$->value.stringVal = strdup($1);}
        | TRUE_VAL                {printf("bool\n");}   { $$ = createNode("bool");   $$->value.boolVal = 1;}
        | FALSE_VAL               {printf("bool\n");}   { $$ = createNode("bool");   $$->value.boolVal = 0;}
        | IDENTIFIER              {printf("hello identifier  \n");} {checkOutOfScope($1); checkInitialized($1); $$ = identifierValue($1); setUsed($1);}   
        | '(' term ')'            { $$ = $2; }
        ;



dummyNonTerminal:  {printf("inside dummy  \n");}
                ;

/* ----------------Conditions--------------- */
ifCondition  : IF '(' expr {checkConstIF($3); quadJumpFalseLabel(++labelNum);} {printf("IF () is detected \n");} ')' '{' {enterScope();} {printf("IF (){} is detected \n");} codeBlock '}' {printf("asdasd");} {exitScope();quadJumpEndLabel();quadPopLabel();} elseCondition {;}
             ;
elseCondition: {printf("inside bare else  \n");}  {;}
             | ELSE {;} {printf("inside else  \n");} ifCondition {;}
             | ELSE '{' {enterScope();} codeBlock '}' {exitScope();} {printf("else {} detected \n");} 
             ;

switchCase: SWITCH '(' IDENTIFIER ')' {printf("switch case passed  \n");} '{' {enterScope();} caseList '}' {exitScope();}
          ;
caseList : caseList case 
         | case 
         ;

case    : CASE {printf("before case \n");} expr  ':' {printf("inside case  \n");} expr
        | DEFAULT ':'    statements {;}
        ;


/*---------------------------------------*/

/* ----------------Loops--------------- */
while: 
        WHILE '(' expr ')' {printf("Found a while loop!\n");} '{' codeBlock  '}' 
        ;
forLoop: 
        FOR '(' {printf("for \n");} assignment ';' {printf("for \n");} expr ';' assignment ')' '{' codeBlock '}'
        | FOR '(' IDENTIFIER ':' expr '->' expr ')' '{' codeBlock '}' //TODO: implement This assignment
        | FOR '(' IDENTIFIER ':' expr '<-' expr ')' '{' codeBlock '}' //TODO: implement This assignment
        
       ;// for (i : 0 -> 4)
repeatUntil: 
        REPEAT '{' {enterScope();} codeBlock '}'{exitScope();} UNTIL '(' expr ')' ';' {} //TODO: implement This assignment
        ;
/*---------------------------------------*/

/* ----------------Enumerations--------------- */
enumDef:	           
        ENUM IDENTIFIER '{' enumBody '}'        {checkSameScope($2); insert($2, "enum", 1, 1, 0, scopes[scope_idx-1]);} {enumCounter=0;}
        ;
                        
enumBody:
        IDENTIFIER                              {checkSameScope($1); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue($1,enumValues); enumValues->value.intVal = 0; quadPushInt(++enumCounter);}
        | IDENTIFIER '=' expr                    {checkSameScope($1); nodeNodeTypeCheck(enumValues,$3); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo($3, "int")->value.intVal; updateIdentifierValue($1, enumValues);}
        | IDENTIFIER ',' enumBody                {checkSameScope($1); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); updateIdentifierValue($1, enumValues); enumValues->value.intVal++; quadPushInt(++enumCounter);}
        | IDENTIFIER '=' expr ',' enumBody        {checkSameScope($1); nodeNodeTypeCheck(enumValues,$3); insert($1, "int", 1, 1, 0, scopes[scope_idx-1]); enumValues->value.intVal = castingTo($3, "int")->value.intVal; updateIdentifierValue($1, enumValues);}
        
enumDeclaration: 
        IDENTIFIER IDENTIFIER                   {checkOutOfScope($1); identifierNodeTypeCheck($1,createNode("enum")); checkSameScope($2); insert($2, "int", 0, 0, 0, scopes[scope_idx-1]);}
        | IDENTIFIER IDENTIFIER '=' expr         {checkOutOfScope($1); identifierNodeTypeCheck($1,createNode("enum")); checkSameScope($2); insert($2, "int", 0, 1, 0, scopes[scope_idx-1]); nodeNodeTypeCheck($4,createIntNode(0)); updateIdentifierValue($2,castingTo($4, "int"));}
        ;


/* ------------Statement----------------- */
printList:  expr
            | printList ',' expr                {char* str1 = castingTo($3, "string")->value.stringVal; char* str2 = printStringValues->value.stringVal;  strcat(str1, str2); printStringValues->value.stringVal =  str1;} // Concatenate str2 to str1 (result is stored in str1)
            ;
statement: assignment {;}
            | expr {printf("aloo\n");}
            | decleration {;}
            | EXIT 		                        {exit(EXIT_SUCCESS);}
            | BREAK 		                    {;} //TODO: 
            | CONTINUE 		                    {;} 
            | RETURN 		                    {;} 
            | RETURN expr 		                {$$ = $2;} 
            | PRINT '(' expr ')' 		        {printNode($3);}
            | PRINT '(' printList ')' 		    {$$ = $3;} 
            ;            
/*---------------------------------------*/

/* ------------Statements----------------- */
statements: statement ';' {;}
            | controlStatement {;}
            | statements statement ';' {;}
            |'{'{enterScope();} codeBlock '}'{exitScope();}
            | statements controlStatement {printf("state+controlState");}
            | statements '{'{enterScope();} codeBlock '}'{exitScope();} {;}
        ;
/*---------------------------------------*/

/* ------------Code Block----------------- */
codeBlock:  statements {printf("inside code block \n");}
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

void updateSymbolParam(char symbol, int param){
    int bucket = computeSymbolIndex(symbol);
    symbol_Table [bucket].value.intVal = param;
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