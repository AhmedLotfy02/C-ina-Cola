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
[(){}:=;]        {return yytext[0];}
{SPACE}     ; /*ignore spaces*/
{DIGIT}+ { yylval.TYPE_INT = atoi(yytext); return INTEGER;}
{arithmeticOps} {return *yytext;} /*just return the operator*/
"if"        {return IF;}
"else"      {return ELSE;}
"=="        {return EQ;}
"switch"    {return SWITCH;}
"case"      {return CASE;}
"while"     {return WHILE;}
"for"       {return FOR;}
"int"       {return INT_DATA_TYPE;}
"float"     {return FLOAT_DATA_TYPE;}
"string"    {return STRING_DATA_TYPE;}
"bool"      {return BOOL_DATA_TYPE;}
"void"      {return VOID_DATA_TYPE;}

[a-zA-Z_][a-zA-Z0-9_]* {yylval.TYPE_INT = yytext[0]; return IDENTIFIER; }

.           yyerror("Unknown character");
%%

int yywrap(void) {
    return 1;
}