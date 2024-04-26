%{

    #include "main.tab.h"
    #include <stdio.h>
    void yyerror(char *);
    extern int line =1;
%}
/*--Some Definitions--*/
DIGIT [0-9]
SPACE [ \r\t]
NEW_LINE \n
arithmeticOps   [/+*%-]
%%
{NEW_LINE}   line++; /*ignore new lines and processed to the next line*/ 
[(){}:=;]        {return yytext[0];}
{SPACE}     ; /*ignore spaces*/
{DIGIT}+ { yylval.TYPE_INT = atoi(yytext); return INTEGER;}
{DIGIT}*"."{DIGIT}+ {yylval.TYPE_FLOAT = atof(yytext); return FLOAT_NUMBER;}
{arithmeticOps} {return *yytext;} /*just return the operator*/
"if"        {return IF;}
"else"      {return ELSE;}
"=="        {return EQ;}
"!="        {return NEQ;}
"&&"        {return AND;}
"||"        {return OR;}
"!"         {return NOT;}
"switch"    {return SWITCH;}
"case"      {return CASE;}
"default"   {return DEFAULT;}
"while"     {return WHILE;}
"for"       {return FOR;}
"return"    {return RETURN;}
"int"       {return INT_DATA_TYPE;}
"float"     {return FLOAT_DATA_TYPE;}
"string"    {return STRING_DATA_TYPE;}
"bool"      {return BOOL_DATA_TYPE;}
"const"     {return CONST;}
"void"      {return VOID_DATA_TYPE;}
"break"     {return BREAK;}
[a-zA-Z_][a-zA-Z0-9_]* {yylval.TYPE_INT = yytext[0]; return IDENTIFIER; }
"true"      {return  yylval.TYPE_BOOL=1; return TRUE_VAL;}
"false"     {return  yylval.TYPE_BOOL=0; return FALSE_VAL;}

.           yyerror("Unknown character");
%%

int yywrap(void) {
    return 1;
}