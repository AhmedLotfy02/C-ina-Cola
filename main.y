%{
    /*////////////////////////////////
    TODO: add Enum - typedef - repeat until - semanticError -checkConstIF in all expr rules - printList & conccatenate strings
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
    
    void semanticError(int semanticErr,char* c){
        int errLine=line;
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
    void quadJumpFalseLabel(int labelNum);
    void quadJumpEndLabel();
    void quadPopLabel();
    void quadPushEndLabel(int endLabelNum);
    void quadPopEndLabel();
    
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
    //intialize the scopes table 
    for (int i = 0; i < 100; i++) {
        scopes[i] = 0; //default scope = 0 (No scope)
    }
    void enterScope();
    void exitScope();
    ///////////////////////////////////////////////
    // Functions
    int argCount = 0;
    struct nodeType* arithmatic(struct nodeType* op1, struct nodeType* op2, char op); //TODO: Continue Implement of arithmatic() 
    struct nodeType* logical(struct nodeType* op1, struct nodeType* op2, char op); //TODO: Continue Implement of logical()
    struct nodeType* doComparison(struct nodeType* op1, struct nodeType*op2, char* op); //TODO: Continue Implement of doComparison()
    struct nodeType* castingTo(struct nodeType* term, char *type); //TODO: Implement castingTo($4, $2->type) $$->isConst = $4->isConst;
    struct nodeType* Negation(struct nodeType* term);     //TODO: Implement Negation($2) $$->isConst=$2->isConst;
    struct nodeType* createIntNode(int value);
    struct nodeType* createNode(char* type);
    void identifierNodeTypeCheck(char* name , struct nodeType* node);//TODO: 
    void nodeNodeTypeCheck(struct nodeType* node1, struct nodeType* node2);//TODO: 
    void updateIdentifierValue(char* name, struct nodeType* node);//TODO: 
    struct nodeType* identifierValue(char* name) //TODO: & create nodeType* p.value-> & p.type-> 
    void setInit(char* name); //TODO:
    void setUsed(char* name); //TODO:
    void printNode(struct nodeType* node); //TODO:
    void returnNode(struct nodeType* node); //TODO:    
    void checkInitialized(char* name); //TODO:
    void checkUsed(char* name); //TODO:
    void checkSameScope(char* name);
    void checkOutOfScope(char* name);
    void checkConst(char* name);
    void checkConstIF(struct nodeType* node);
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
%type <TYPE_NODE> term expr assignment


//------------------------
// Flow Statements
%type <TYPE_VOID> ifCondition switchCase case caseList dummyNonTerminal while forLoop

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
decleration: dataType IDENTIFIER  {checkSameScope($2);  insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]); } {printf("inside decleration \n");} {printSymbolTable();}
           | dataType IDENTIFIER  '='  expr {checkSameScope($2);  nodeNodeTypeCheck($1, $4); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]);  updateIdentifierValue($2,$4); setInit($2); } {printf("inside decleration \n");} {printSymbolTable();} 
           | dataModifier dataType IDENTIFIER  '='  expr {checkSameScope($3);  nodeNodeTypeCheck($2, $5); insert($3, $2->type, 1, 0, 0, scopes[scope_idx-1]);  updateIdentifierValue($3,$5); setInit($3); } {printf("inside decleration \n");} {printSymbolTable();} {printSymbolTable();}            
           ;
assignment: IDENTIFIER '='  expr {printf("inside assignment \n");}     {checkOutOfScope($1); checkConst($1); identifierNodeTypeCheck($1, $3); setInit($1); setUsed($1); updateIdentifierValue($1,$3); $$ = $3;} {printSymbolTable();}
          ;
        ;
expr:
        term                      { $$ = $1; } 
        | '(' dataType ')' term   { $$ = castingTo($4, $2->type);}
        | '-' term                { $$ = Negation($2); }
        | expr '+' expr           { $$ = arithmatic($1,$3,'+'); } 
        | expr '-' expr           { $$ = arithmatic($1,$3,'-'); }
        | expr '*' expr           { $$ = arithmatic($1,$3,'*'); }
        | expr '/' expr           { $$ = arithmatic($1,$3,'/'); }
        | expr '%' expr           { $$ = arithmatic($1,$3,'%'); }
        | expr EQ expr            { $$ = doComparison($1,$3,"==");} 
        | expr NEQ expr           { $$ = doComparison($1,$3,"!=");}
        | expr LT expr            { $$ = doComparison($1,$3,"<"); }
        | expr GT expr            { $$ = doComparison($1,$3,">"); }
        | expr GEQ expr           { $$ = doComparison($1,$3,">="); }
        | expr LEQ expr           { $$ = doComparison($1,$3,"<="); }
        | expr AND expr           { $$ = logical($1,$3,'&'); } 
        | expr OR expr            { $$ = logical($1,$3,'|'); }
        | NOT expr                { $$ = logical($2,NULL,'!'); }
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
ifCondition  : IF '(' expr {checkConstIF($3); quadJumpFalseLabel(++labelNum)} {printf("IF () is detected \n");} ')' '{' {enterScope();} {printf("IF (){} is detected \n");} codeBlock '}' {printf("asdasd");} {exitScope();quadJumpEndLabel();quadPopLabel();} elseCondition {;}
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
while: WHILE '(' expr ')' {printf("Found a while loop!\n")} '{' codeBlock  '}' 
      ;
forLoop: FOR '(' {printf("for \n");} assignment ';' {printf("for \n");} expr ';' assignment ')' '{' codeBlock '}'
        | FOR '(' IDENTIFIER ':' expr '->' expr ')' '{' codeBlock '}' //TODO: implement This assignment
        | FOR '(' IDENTIFIER ':' expr '<-' expr ')' '{' codeBlock '}' //TODO: implement This assignment
        
       ;// for (i : 0 -> 4)

/*---------------------------------------*/

/* ------------Statement----------------- */
// printList:  expr
//             | printList ',' expr {/*TODO:*/}
//             ;
statement: assignment {;}
            | expr {printf("aloo\n");}
            | decleration {;}
            | EXIT 		                        {exit(EXIT_SUCCESS);}
            | BREAK 		                    {break;} //TODO: check this 
            | CONTINUE 		                    {continue;} 
            | RETURN 		                    {return;} 
            | RETURN expr 		                {returnNode($2);} //TODO: $$ =(struct nodeType* )returnNode($2);node with return value & type >> How to handle X = func()
            | PRINT '(' expr ')' 		        {printNode($3);}
            // | PRINT '(' printList ')' 		    {$$ = $3;} 
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

/* ------------Functions----------------- */
functionArgs: dataType IDENTIFIER   {checkSameScope($2); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]) ; argCount = sym_table_idx-argCount;}
            | dataType IDENTIFIER {checkSameScope($2); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]) ;} ','  functionArgs
            ;   
functionDefinition: dataType IDENTIFIER {checkSameScope($2); insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]); argCount = sym_table_idx; enterScope();} {printf("here \n");} functionDefinitionAfter '{' codeBlock '}' {exitScope();}
                  ;
functionDefinitionAfter: '(' functionArgs ')' {printf("definitions with params  \n");}
                        | '(' ')' {printf("definitions without params  \n");}
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
// Create Node
struct nodeType* createNode(char* type) {
    struct nodeType* p = malloc(sizeof(struct nodeType));
    p->type = type;
    node->isConst = 1;
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
   //TODO: Set P->isCont (($1->isConst)&&($3->isConst))
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
            // Gohst Varible
            symbol_Table[i].scope = -1;     // -1: means was in scope but cleaned ,but, 0: means no scope     
        }
    }
}
// Exit the scope
void exitScope() {
    cleanedUpScope(scope_idx)
    scope_idx--;
}
// Check if the variable is declared in the same scope
void checkSameScope(char* name) {
    int lvl;
    for(int i=0; i<sym_table_idx ;i++) {
        if(symbol_Table[i].name == name) {
            lvl = symbol_Table[i].scope;
            if(lvl == scopes[scope_idx-1]) {
                 printf("Error: variable %s already declared in the same scope\n", name); 
              
            }
        }
    }
}

// Check if the variable is declared in the same scope
void checkOutOfScope(char* name) {
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
    printf("Error: variable %s is out of scope\n", name);

}


// this function checks if a variable is used before initialized
void checkInitialized(char* name) {
    int lvl;
    for(int i=sym_table_idx-1;i>=0;i--) {
        //TODO: check Ghoast variable
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
        semanticError(CONSTANT_IF, node->value.boolVal !=0);
    }

}

// Print the symbol table
void printSymbolTable() {
    for(int i=0; i<sym_table_idx ;i++) {
        printf("SymbolTable() : %s, declared:%d, const:%d, Symbol table idx:%d\n", symbol_Table [i].name, symbol_Table [i].isDecl, symbol_Table [i].isConst, i); 
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