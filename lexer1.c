#include <stdio.h>
#include "lexer1.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "PLUS", "MINUS", "MULT", "DIVIDE", "MODULO", "EXP", "LPAREN", "RPAREN", "EQUALS", "LTHAN", "GTHAN", "COLON", "COMMA", "SCOLON", "PERIOD", "QUOTE", "DQUOTE", "NUMBER", "IDENT", "TAGIDENT", "EOF"};

int main(void){
	int ntoken, n;
	n = sizeof(names);
	ntoken = -999;
	ntoken = yylex();
	
	while(ntoken){
		printf("ntoken: %d\n", ntoken);
		printf("lineno: %d\n", yylineno);
		if(ntoken > 0 && ntoken < n){
			printf("%s				%s\n", names[ntoken], yytext);
		}
		else if(ntoken == -5){
			printf("Badly formed number error at line %d\n because of token '%s' ", yylineno, yytext);
			return 1;
		}
		else{
			printf("Illegal character found at line %d. Expected operator found %s\n", yylineno, yytext);
			return 1;
		}
		ntoken = yylex();
	}
	
	return 0;
}