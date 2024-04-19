%{
    #include <stdio.h>     
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    void yyerror (char *);       
    int yylex(void);
    


    // nodeType as in section
    struct nodeType{
        char *type;
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
    struct nodeType* arithmatic(struct nodeType* op1, struct nodeType* op2, char op);
    struct nodeType* createIntNode(int value);
    struct nodeType* doComparison(struct nodeType* op1, struct nodeType*op2, char* op);
    struct nodeType* createNode(char* type);
    void checkSameScope(char name);

%}
/* Yacc definitions */

// Union here defines the expected values in symbol table 
%union {
        int TYPE_INT; 
        void* TYPE_VOID;
        char* TYPE_DATA_TYPE;
        struct nodeType* TYPE_NODE;

;}

//Precedence of Operators (the upper is the lower precedence)
%left EQ
%left  '+' '-' 
%left  '*' '/' 

//-----------TOKENS-------------
// Data Types
%token <TYPE_INT> INTEGER
%token <TYPE_NODE> IDENTIFIER
//Flow Statements
%token IF ELSE
%token SWITCH CASE DEFAULT
// LOOPS
%token WHILE FOR
//------------------------
// Return Types
%type <TYPE_VOID> program codeBlock controlStatment
%type <TYPE_NODE> expr assignment
// Flow Statements
%type <TYPE_VOID> ifCondition switchCase case caseList dummyNonTerminal while forLoop
// Decleration
%token <TYPE_DATA_TYPE> INT_DATA_TYPE FLOAT_DATA_TYPE STRING_DATA_TYPE BOOL_DATA_TYPE VOID_DATA_TYPE
%type <TYPE_NODE> dataType decleration


%%
program:
        program expr '\n' { printf("%d\n", $2->value.intVal); }
        | controlStatment program
        | assignment
        |dataType
        | decleration
        |  {;}
        ;

/*------Control Statements----------*/
controlStatment: while
                | forLoop
                | ifCondition
                | switchCase
                ;


/* Decleration */

dataType: INT_DATA_TYPE     {printf("int data type \n");} { $$ = createIntNode(0); }
        | FLOAT_DATA_TYPE   {printf("float data type \n");} { $$ = createNode("float"); }
        | STRING_DATA_TYPE  {printf("string data type \n");} { $$ = createNode("string"); }
        | BOOL_DATA_TYPE    {printf("bool data type \n");} { $$ = createNode("bool"); }
        | VOID_DATA_TYPE    {printf("void data type \n");} { ; }
        ;
/* */
decleration: dataType IDENTIFIER  {checkSameScope($2);  insert($2, $1->type, 0, 0, 0, scopes[scope_idx-1]); } {printf("inside decleration \n");}
           ;
assignment: IDENTIFIER '='  expr {printf("inside assignment \n");}     {;}
        ;
expr:
        INTEGER   {printf("integer");}                { $$ = createIntNode($1); } 
        | expr '+' expr           { $$ = arithmatic($1,$3,'+'); }
        | expr '-' expr           { $$ = arithmatic($1,$3,'-');}
        | expr EQ expr            { $$ = doComparison($1,$3,"==");}
        | '(' expr ')'             {$$ = $2;}
        | IDENTIFIER               {printf("hello identifier  \n");}
        ;



dummyNonTerminal:  {printf("inside dummy  \n");}
                ;

/* ----------------Conditions--------------- */
ifCondition  : IF {printf("IF is detected \n");}  '(' expr {printf("IF () is detected \n");} ')' '{' {printf("IF (){} is detected \n");} codeBlock '}'  elseCondition {;}
             ;
elseCondition: {;} {printf("inside bare else  \n");}
             | ELSE {;} {printf("inside else  \n");} ifCondition {;}
             | ELSE '{' codeBlock '}' {printf("else {} detected \n");} 
             ;

switchCase: SWITCH '(' IDENTIFIER ')' {printf("switch case passed  \n");} '{' caseList '}'
          ;
caseList : caseList case 
         | case 
         ;

case    : CASE {printf("before case \n");} expr  ':' {printf("inside case  \n");} expr
        | DEFAULT ':'    dummyNonTerminal {;}
        ;


/*---------------------------------------*/

/* ----------------Loops--------------- */
while : WHILE '(' expr ')' {printf("Found a while loop!\n")} '{' codeBlock  '}' 
      ;
forLoop: FOR '(' {printf("for \n");} assignment ';' {printf("for \n");} expr ';' assignment ')' '{' codeBlock '}'
       ;

/*---------------------------------------*/
/* ------------Code Block----------------- */
codeBlock:  expr {printf("inside code block \n");}
         ;

%%

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
struct nodeType* createNode(char* type) {
    struct nodeType* p = malloc(sizeof(struct nodeType));
    p->type = type;
    p->value.intVal = 0;
    return p;
}


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


struct nodeType* doComparison(struct nodeType* op1, struct nodeType*op2, char* op){
    printf("Comparing %d %s %d\n", op1->value.intVal, op, op2->value.intVal);
    struct nodeType* p = malloc(sizeof(struct nodeType));
    p->type = "bool";
    if(strcmp(op, "==") == 0){
        p->value.boolVal = op1->value.intVal == op2->value.intVal;
    }
    return p;
}


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
void enterScope() {
    scopes[scope_idx] = scope_lvl;
    scope_idx++;
    scope_lvl++;
}

void exitScope() {
    scope_idx--;
}
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
int main(void) {
    yyparse();
    return 0;
}