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
{NEW_LINE}  {return yytext[0];} /*ignore new lines and processed to the next line*/ 
[(){}:]        {return yytext[0];}
{SPACE}     ; /*ignore spaces*/
{DIGIT}+ { yylval.TYPE_INT = atoi(yytext); return INTEGER;}
{arithmeticOps} {return *yytext;} /*just return the operator*/
"if"        {return IF;}
"else"      {return ELSE;}
"=="        {return EQ;}
"switch"    {return SWITCH;}
"case"      {return CASE;}
[a-zA-Z_][a-zA-Z0-9_]* {yylval.TYPE_INT = yytext[0]; return IDENTIFIER; }
.           yyerror("Unknown character");
%%

int yywrap(void) {
    return 1;
}