#include <stdio.h>
#include "lexer1.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "PLUS", "MINUS", "MULT", "DIVIDE", "MODULO", "EXP", "LPAREN", "RPAREN", "EQUALS", "LTHAN", "GTHAN", "COLON", "COMMA", "SCOLON", "PERIOD", "QUOTE", "DQUOTE", "NUMBER", "IDENT", "TAGIDENT", "ENDTAGHEAD", "EOF"};

int main(void){
	int ntoken, n;
	n = sizeof(names);
	ntoken = -999;
	ntoken = yylex();
	
	while(ntoken){
		//printf("ntoken: %d\n", ntoken);		
		//printf("lineno: %d\n", yylineno);
		if(ntoken > 0 && ntoken < n){
			printf("%s				%s\n", names[ntoken], yytext);
		}
		else if(ntoken <= -5 && ntoken != -100){
			//printf("Badly formed number error at line %d because of token '%s' \n", yylineno, yytext);
			//printf("ntoken: %d\n", ntoken);
			printf("***lexical error: badly formed number %s at line %d\n", yytext, yylineno);
			printf("%s				%s\n", "NUMBER", yytext);
			//return 1;
		}
		else if(ntoken == -100){
			printf("***lexical error: un-expected end of file\n");
			//printf("token: %s\n", yytext);
		}
		else{
			printf("***lexical error: illegal character (%s) at line %d\n", yytext, yylineno);
			//return 1;
		}
		ntoken = yylex();
	}
	
	return 0;
}