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

        } value;

    };
    // Functions
    struct nodeType* arithmatic(struct nodeType* op1, struct nodeType* op2, char op);
    struct nodeType* createIntNode(int value);

%}
/* Yacc definitions */

// Union here defines the expected values in symbol table 
%union {
        int TYPE_INT; 
        void* TYPE_VOID;
        struct nodeType* TYPE_NODE;
;}

//Precedence of Operators (the upper is the lower precedence)
%left  '+' '-' 
%left  '*' '/' 


// Data Types
%token <TYPE_INT> INTEGER
// Return Types
%type <TYPE_VOID> program
%type <TYPE_NODE> expr
%%
program:
        program expr '\n' { printf("%d\n", $2->value.intVal); }
        |  {;}
        ;

/* Decleration */
expr:
        INTEGER                   { $$ = createIntNode($1); } 
        | expr '+' expr           { $$ = arithmatic($1,$3,'+'); }
        | expr '-' expr           { $$ = arithmatic($1,$3,'-');}
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
// Create Int Node
struct nodeType* createIntNode(int value) {
    struct nodeType* node = malloc(sizeof(struct nodeType));
    node->type = "int";
    node->value.intVal = value;
    return node;
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