#include <stdio.h>
#include "lexer1.h"
#include <string.h>
#include <stdlib.h>

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "PLUS", "MINUS", "MULT", "DIVIDE", "MODULO", "EXP", "LPAREN", "RPAREN", "EQUALS", "LTHAN", "GTHAN", "COLON", "COMMA", "SCOLON", "PERIOD", "QUOTE", "DQUOTE", "NUMBER", "IDENT", "TAGIDENT", "ENDTAGHEAD", "IDENT_PUNC", "INT_PUNC", "FLOAT_PUNC" ,"EOF"};

void RemoveChars(char *s, char c)
{
    int writer = 0, reader = 0;

    while (s[reader])
    {
        if (s[reader]!=c) 
        {   
            s[writer++] = s[reader];
        }

        reader++;       
    }

    s[writer]=0;
}

void RemoveLast(char *s)
{
    int writer = 0, reader = 0;

    while (s[reader])
    {
        if (s[reader]!=',' && s[reader]!=';' && s[reader]!=':' && s[reader]!='.' && s[reader]!='\'' && s[reader]!='\"' && s[reader]!=' ') 
        {   
            s[writer++] = s[reader];
        }

        reader++;       
    }

    s[writer]=0;
}

void TrimFloat(char *s){
    int writer = 0, reader = 0;
    while (s[reader])
    {
        if (s[reader]!=',' && s[reader]!=';' && s[reader]!=':' && s[reader]!='\'' && s[reader]!='\"' && s[reader]!=' ') 
        {   
			if(reader != (strlen(s) - 1) && s[reader]=='.'){
				s[writer++]	= s[reader];
			}
			else if(s[reader] != '.'){
				s[writer++] = s[reader];
			}
            //s[writer++] = s[reader];
        }

        reader++;       
    }

    s[writer]=0;
}

int main(void){
	int ntoken, n;
	n = sizeof(names);
	ntoken = -999;
	ntoken = yylex();
	
	while(ntoken){
		//printf("ntoken: %d\n", ntoken);		
		//printf("lineno: %d\n", yylineno);
		if(ntoken > 0 && ntoken < n && ntoken != 22 && ntoken != 23 && ntoken != 24){
			printf("%s				%s\n", names[ntoken], yytext);
		}
		else if(ntoken <= -5 && ntoken != -100){
			//printf("Badly formed number error at line %d because of token '%s' \n", yylineno, yytext);
			//printf("ntoken: %d\n", ntoken);
			printf("***lexical error: badly formed number %s at line %d\n", yytext, yylineno);
			printf("%s				%s\n", "NUMBER", yytext);
			//return 1;
		}
		else if(ntoken == 22){
			char* currText = yytext;
			char* ident = malloc(strlen(currText) + 1);
			char punc = 'a';
			punc = currText[strlen(currText) - 1];
			RemoveLast(currText);
			printf("%s				%s\n", "IDENT", currText);
			if(punc == ','){
				printf("%s				%c\n", "COMMA", punc);
			}
			else if(punc == '.'){
				printf("%s				%c\n", "PERIOD", punc);
			}
			else if(punc == '\''){
				printf("%s				%c\n", "QUOTE", punc);
			}
			else if(punc == '\"'){
				printf("%s				%c\n", "DQUOTE", punc);
			}
			else if(punc == ':'){
				printf("%s				%c\n", "COLON", punc);
			}
			else if(punc == ';'){
				printf("%s				%c\n", "SCOLON", punc);
			}
			
			//printf("%s				%s\n", "IDENT", yytext);
		}
		else if (ntoken == 23){
			char* currText = yytext;
			char* ident = malloc(strlen(currText) + 1);
			char punc = 'a';
			punc = currText[strlen(currText) - 1];
			RemoveLast(currText);
			printf("%s				%s\n", "NUMBER", currText);
			if(punc == ','){
				printf("%s				%c\n", "COMMA", punc);
			}
			else if(punc == '.'){
				printf("%s				%c\n", "PERIOD", punc);
			}
			else if(punc == '\''){
				printf("%s				%c\n", "QUOTE", punc);
			}
			else if(punc == '\"'){
				printf("%s				%c\n", "DQUOTE", punc);
			}
			else if(punc == ':'){
				printf("%s				%c\n", "COLON", punc);
			}
			else if(punc == ';'){
				printf("%s				%c\n", "SCOLON", punc);
			}			
		}
		else if(ntoken == 24){
			//printf("FLOAT_PUNC\n");
			char* currText = yytext;
			char* ident = malloc(strlen(currText) + 1);
			char punc = 'a';
			punc = currText[strlen(currText) - 1];
			TrimFloat(currText);
			printf("%s				%s\n", "NUMBER", currText);
			if(punc == ','){
				printf("%s				%c\n", "COMMA", punc);
			}
			else if(punc == '.'){
				printf("%s				%c\n", "PERIOD", punc);
			}
			else if(punc == '\''){
				printf("%s				%c\n", "QUOTE", punc);
			}
			else if(punc == '\"'){
				printf("%s				%c\n", "DQUOTE", punc);
			}
			else if(punc == ':'){
				printf("%s				%c\n", "COLON", punc);
			}
			else if(punc == ';'){
				printf("%s				%c\n", "SCOLON", punc);
			}				
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