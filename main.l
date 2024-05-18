%{

    #include "main.tab.h"
    #include <stdio.h>
    #include <string.h>
    void yyerror(char *); //called by the parser whenever it encounters a syntax error.
    int yylex(); // called by the parser whenever it needs a token.
    extern int line =1; //TODO: solve warning: 'line' initialized and declared 'extern' ==> Ans.(extern int line;)
%}

/*--Some Definitions--*/
DIGIT [0-9]
FLOAT_NUM [+-]?[0-9]+(\.[0-9]*)?[eE][+-]?[0-9]+|[+-]?[0-9]*(\.[0-9]*)+[eE][+-]?[0-9]+|[+-]?[0-9]*\.[0-9]+|[+-]?[0-9]+\.[0-9]*
STR \"[^\"]*\"|\'[^\']*\'
SPACE [ \r\t]
NEW_LINE \n
INLINE_COMMENT  \/\/.*
MULTILINE_COMMENT \/\*(.*\n?)*\*\/
arithmeticOps   [/+*%-]

%%
{NEW_LINE}   line++; /*ignore new lines and processed to the next line*/ 
{SPACE}     ; /*ignore spaces*/
{INLINE_COMMENT}      ; /*Ignore Comments*/
{MULTILINE_COMMENT}     ; /*Ignore Comments*/

[(){}:=,;]              {return yytext[0];}

{DIGIT}+                { yylval.TYPE_INT = atoi(yytext); return INTEGER;}
{FLOAT_NUM}             { yylval.TYPE_FLOAT = atof(yytext); return FLOAT_;} 
{STR}		            { yylval.TYPE_STR = strdup(yytext); return STRING;} //TODO: return Str without Qutoes

{arithmeticOps}         {return *yytext;} /*just return the operator*/

"=="                    {return EQ;}
"!="                    {return NEQ;}
"<="                    {return LEQ;} 
">="                    {return GEQ;} 
"<"                     {return LT;} 
">"                     {return GT;} 

"&&"                    {return AND;}
"||"                    {return OR;}
"!"                     {return NOT;}

"const"                 {return CONST;}
"int"                   {return INT_DATA_TYPE;}
"float"                 {return FLOAT_DATA_TYPE;}
"string"                {return STRING_DATA_TYPE;}
"bool"                  {return BOOL_DATA_TYPE;}
"void"                  {return VOID_DATA_TYPE;}
"enum"                  {return ENUM;}

"if"                    {return IF;}
"else"                  {return ELSE;}

"switch"                {return SWITCH;}
"case"                  {return CASE;}
"default"               {return DEFAULT;}

"while"                 {return WHILE;}

"repeat"				{return REPEAT;}
"until"				    {return UNTIL;}

"for"                   {return FOR;}

"break"                 {return BREAK;}
"continue"              {return CONTINUE;}

"print"				    {return PRINT;} 
"assert"                {return ASSERT;} 
"exit"				    {return EXIT;} 
"return"                {return RETURN;}

"true"                  {yylval.TYPE_BOOL=1; return TRUE_VAL;}
"True"                  {yylval.TYPE_BOOL=1; return TRUE_VAL;}
"false"                 {yylval.TYPE_BOOL=0; return FALSE_VAL;}
"False"                 {yylval.TYPE_BOOL=0; return FALSE_VAL;}

[a-zA-Z_][a-zA-Z0-9_]*  {yylval.TYPE_STR = strdup(yytext); return IDENTIFIER;}

.                       yyerror("Unknown character");/*Unexpected Token*/
%%

int yywrap(void) {
    return 1;
}