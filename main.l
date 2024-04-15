%{

    #include "main.tab.h"
    #include <stdio.h>
    void yyerror(char *);
%}
/*--Some Definitions--*/
DIGIT [0-9]
SPACE [ \r\t]
NEW_LINE \n
arithmeticOps   [/+*%-]
%%


{NEW_LINE}  ; /*ignore new lines and processed to the next line*/ 
{SPACE}     ; /*ignore spaces*/
{DIGIT}+ { yylval = atoi(yytext); return INTEGER;}
{arithmeticOps} {return *yytext;} /*just return the operator*/
.           yyerror("Unknown character");
%%

int yywrap(void) {
    return 1;
}