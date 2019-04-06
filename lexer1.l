%option yylineno

%{
#include "lexer1.h"
%}

%%
[ \t \n]	;
[0-9]+\.[^0-9].*		return -5;
[0-9]+\.[0-9]\..*		return -6;
[0-9]+\.[0-9][^eE0-9].*		return -7;
[0-9]+\.[0-9]+[e][^0-9].*	return -8;
[0-9]+\.[0-9]+[e][0-9]+[^0-9 \t \n]+	return -9;
[0-9]+\.[0-9]+[E][^-+].*		return -10;
[0-9]+\.[0-9]+[E][-+][0-9]+[^0-9 \t \n]+	return -11;
[+]			return PLUS;
[-]			return MINUS;
[*]			return MULT;
[/]			return DIVIDE;
[%]			return MODULO;
"**"		return EXP;
[(]			return LPAREN;
[)]			return RPAREN;
[=]			return EQUALS;
[<]			return LTHAN;
[>]			return GTHAN;
[:]			return COLON;
[,]			return COMMA;
[;]			return SCOLON;
[.]			return PERIOD;
[']			return QUOTE;
["]			return DQUOTE;
[0-9][0-9]*		return NUMBER;
[0-9]+\.[0-9]+		return NUMBER;
[0-9]+[e][0-9]+		return NUMBER;
[0-9]+\.[0-9]+[e][0-9]+	return NUMBER;
[0-9]+[E][-+][0-9]+		return NUMBER;
[0-9]+\.[0-9]+[E][-+][0-9]+ 	return NUMBER;	



.			return -1;

%%


int yywrap(void){
	return 1;
}

