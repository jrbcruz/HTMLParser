%{
#include "union.tab.h"
#include <stdlib.h>
#include <stdio.h>
%}

%%

[\r\t]		;
[\n]		return newline;
[+]			return PLUS;
[-]			return MINUS;
[*]			return MULT;
[/]			return DIVIDE;
[%]			return MODULO;
[0-9][0-9]*		{printf("received int\n"); yylval.num.ival = atoi(yytext); yylval.num.type = 1; return INTEGER;}
[0-9]+\.[0-9]+		{printf("received float\n"); yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}

[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\n\t]*		{printf("received float\n"); yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}
[0-9]+\.[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\n\t]*	{printf("received float\n"); yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}

[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\n\t]*	{printf("received float\n"); yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}
[0-9]+\.[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\n\t]* 	{printf("received float\n"); yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}
%%

int yywrap(void)
{
	return 1;
}