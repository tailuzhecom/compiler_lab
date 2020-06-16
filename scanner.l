%option noyywrap yylineno

%{
#include <stdio.h>   
#include <stdlib.h>
#include <string.h>
#include "cgen.h"
#include "parser.tab.hpp"
void yyerror(char *s, ...);

%}

%x COMMENT STRING_STATE

%%
int         { return INT; }
float       { return FLOAT; }
double      { return DOUBLE; }
long        { return LONG; }
short       { return SHORT; }
signed      { return SIGNED; }
char        { return CHAR; }
void        { return VOID; }
unsigned    { return UNSIGNED; }
for         { return FOR; }
while       { return WHILE; }
break       { return BREAK; }
if          { return IF; }
else        { return ELSE; }
switch      { return SWITCH; }
case        { return CASE; }
return      { return RETURN; }
class { return CLASS; }
"(" { return LPAREN; }
")" { return RPAREN; }
"{" { return LBRACKET; }
"}" { return RBRACKET; }
	
 /* ident */
[a-zA-Z][a-zA-Z0-9_]* { 
    yylval.strval = strdup(yytext); 
    return IDENTITY; 
}

 /* int const */
-?[0-9]+ { 
    yylval.intval = atoi(yytext); 
    return INT_NUMBER; 
}

 /* float const */
-?[0-9]+\.[0-9]+ { 
    yylval.floatval = atof(yytext); 
    return FLOAT_NUMBER; 
}

 /* string const */
<STRING_STATE>[^\"]* {
    yylval.strval = strdup(yytext); 
    return STRING; 
}

<STRING_STATE>\" {
    BEGIN(INITIAL);
}

\" {
    BEGIN(STRING_STATE);
}

 /* operators */
"==" 			{ return EQUAL; }
"&&"                    { return AND; }
"||"                    { return OR; }
"<"			{ return LESS; }
"<="			{ return LESS_E; }
">"			{ return GREATER; }
">="			{ return GREATER_E; }
"="                     { return ASSIGN; }
[-+/&~:%*,.;!@]       { return yytext[0]; }

 /* comments */
"//" {
    BEGIN(COMMENT);
}

<COMMENT>\n {
   BEGIN(INITIAL);
}

<COMMENT>. 

	/* space & tab */
[ \t\n]
	/* prevent flex jam */
.           { yyerror("error in scanner...\n"); }

%%
