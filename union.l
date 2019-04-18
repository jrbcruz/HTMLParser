    
%{
#include "union.tab.h"
#include <stdlib.h>
#include <stdio.h>
%}

%%
[\r\t ]		;
\<![ \r\n\t]*(--([^\-]|[\r\n]|-[^\-])*--[ \r\n\t]*)\>			;
\<![ \r\n\t]*--.*[ \r\n\t]*[^--\> \r\n\t]+.*		return INVALID_COMMENT;
[\n]		return newline;


[0-9]+\.[^0-9]		return invalid_num;
[0-9]+\.[0-9]+[e][^0-9][^ \t \n \r]*	return invalid_num;
[0-9]+\.[0-9]+[E][^-+].*		return invalid_num;

[+]			{ return yytext[0];}
[-]			{ return yytext[0];}
[*]			{ return yytext[0];}
[/]			{ return yytext[0];}
[%]			{ return yytext[0];}
"**"		return EXP;
[(]			return LPAREN;
[)]			return RPAREN;
[=]			return EQUALS;
"</"		{ return 	ENDTAGHEAD;} 
[<]			return LTHAN;
[>]			return GTHAN;
[:]			return COLON;
[,]			{return COMMA; }
[;]			return SCOLON;
[.]			return PERIOD;
[']			return QUOTE;
["]			return DQUOTE;




[[]			{yylval.str = yytext; return LBRACE;}
[]]			{yylval.str = yytext; return RBRACE;}


[0-9][0-9]*[ \r\t]*[,."':;]		{yylval.str = yytext; return INT_PUNC;}
[0-9]+\.[0-9]+[ \r\t]*[,."':;]		{yylval.str = yytext; return FLOAT_PUNC;}


[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\t]*[,."':;]	{yylval.str = yytext; return FLOAT_PUNC;}
[0-9]+\.[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\t]*[,."':;]	{yylval.str = yytext; return FLOAT_PUNC;}

[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\n\t]*[,."':;]		{yylval.str = yytext; return FLOAT_PUNC;}
[0-9]+\.[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\t]*[,."':;]	{yylval.str = yytext; return FLOAT_PUNC;}


[0-9][0-9]*		{ yylval.num.ival = atoi(yytext); yylval.num.type = 1; return INTEGER;}
[0-9]+\.[0-9]+		{ yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}

[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\t]?		{ yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}
[0-9]+\.[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\t]?	{ yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}

[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\t]?	{yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}
[0-9]+\.[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\t]? 	{ yylval.num.fval = atof(yytext); yylval.num.type = 2; return FLOAT;}

[a-zA-Z]+[ \r\t]*[,."':;]		{ yylval.str = yytext; return IDENT_PUNC;}

[a-zA-Z]+			{yylval.str = yytext; return IDENT;}
[<][a-zA-Z]+		{yylval.str = yytext; return TAGIDENT;}
%%

int yywrap(void)
{
	return 1;
}