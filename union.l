    
%{
#include "union.tab.h"
#include <stdlib.h>
#include <stdio.h>
%}

%%
[\r\t]		;
[\n]		return newline;

[0-9]+\.[^0-9]		return invalid_num;
[0-9]+\.[0-9]\..*		return invalid_num;
[0-9]+\.[0-9]+[e][^0-9][^ \t \n \r]*	return invalid_num;
[0-9]+\.[0-9]+[E][^-+].*		return invalid_num;

[+]			{ return PLUS;}
[-]			return MINUS;
[*]			return MULT;
[/]			return DIVIDE;
[%]			return MODULO;

[(]			return LPAREN;
[)]			return RPAREN;
[=]			return EQUALS;
"</"		{ return 	ENDTAGHEAD;} 
[<]			return LTHAN;
[>]			return GTHAN;




[[]			{yylval.str = yytext; return LBRACE;}
[]]			{yylval.str = yytext; return RBRACE;}
[0-9][0-9]*		{ yylval.num.ival = atoi(yytext); yylval.num.type = 1; return INTEGER;}
[0-9]+\.[0-9]+		{ yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}

[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\t]?		{ yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}
[0-9]+\.[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\t]?	{ yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}

[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\t]?	{yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}
[0-9]+\.[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\t]? 	{ yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}

[a-zA-Z]+			{yylval.str = yytext; return IDENT;}
[<][a-zA-Z]+		{yylval.str = yytext; return TAGIDENT;}
%%

int yywrap(void)
{
	return 1;
}