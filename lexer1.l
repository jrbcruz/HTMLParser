%option yylineno

%{
#include "lexer1.h"
%}

%%
[ \t \n]	;
\<![ \r\n\t]*(--([^\-]|[\r\n]|-[^\-])*--[ \r\n\t]*)\>			;
\<![ \r\n\t]*--.*[ \r\n\t]*[^--\> \r\n\t]+.*		return -100;
[0-9]+\.[^0-9]		return -5;
[0-9]+\.[0-9]+[e][-]?[^0-9]	return -8;
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

[0-9][0-9]*[ \r\t]*[,."':;]		return INT_PUNC;
[0-9]+\.[0-9]+[,."':;]		return FLOAT_PUNC;

[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\t]*[,."':;]	return FLOAT_PUNC;
[0-9]+\.[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\t]*[,."':;]	return FLOAT_PUNC;

[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\n\t]*[,."':;]		return FLOAT_PUNC;
[0-9]+\.[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\t]*[,."':;]	return FLOAT_PUNC;


[0-9][0-9]*		return NUMBER;
[0-9]+\.[0-9]+		return NUMBER;



[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\t]*		return NUMBER;
[0-9]+\.[0-9]+[e][\-]?[ \r\n\t]*[0-9]+[ \r\t]*	return NUMBER;

[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\n\t]*		return NUMBER;
[0-9]+\.[0-9]+[E][-+][ \r\n\t]*[0-9]+[ \r\t]* 	return NUMBER;	

[a-zA-Z]+[ \r\t]*[,."':;]		return IDENT_PUNC;

[a-zA-Z]+			return IDENT;
[<][a-zA-Z]+		return TAGIDENT;


.			return -1;

%%


int yywrap(void){
	return 1;
}

