%option yylineno

%{
#include "lexer1.h"
%}

%%
[ \t \n]	;
\<![ \r\n\t]*(--([^\-]|[\r\n]|-[^\-])*--[ \r\n\t]*)\>			;
\<![ \r\n\t]*--.*[ \r\n\t]*[^--\> \r\n\t]+.*		return -100;
[0-9]+\.[^0-9]		return -5;
[0-9]+\.[0-9]\..*		return -6;
[0-9]+\.[0-9]+[e][^0-9][^ \t \n \r]*	return -8;
[0-9]+\.[0-9]+[E][^-+].*		return -10;
[+]			return PLUS;
[-]			return MINUS;
[*]			return MULT;
[/]			return DIVIDE;
[%]			return MODULO;
"**"		return EXP;
[(]			return LPAREN;
[)]			return RPAREN;
[=]			return EQUALS;
"</"		return 	ENDTAGHEAD; 
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
[0-9]+[e][\-]?[ \r\n\t]*[0-9]+		return NUMBER;
[0-9]+\.[0-9]+[e][\-]?[ \r\n\t]*[0-9]+	return NUMBER;
[0-9]+[E][-+][0-9]+		return NUMBER;
[0-9]+\.[0-9]+[E][-+][ \r\n\t]*[0-9]+ 	return NUMBER;	
[a-zA-Z]+			return IDENT;
[<][a-zA-Z]+		return TAGIDENT;


.			return -1;

%%


int yywrap(void){
	return 1;
}