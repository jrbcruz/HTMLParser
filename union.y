%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int INT_TYPE = 1;
int FLOAT_TYPE = 2;



%}

%code requires {
   struct number
	{

	  int ival;
	  float fval;
	  int type;
	} n;
}


%union
{
   struct number num;
   char* str;
}

%start command
%token newline

%token <num>FLOAT 
%token <num>INTEGER
%token PLUS
%token MINUS
%token MULT
%token DIVIDE
%token MODULO
%token EQUALS
%token invalid_num


%token <str>LPAREN
%token <str>RPAREN
%token <str>IDENT
%token <str> TAGIDENT
%token <str> ENDTAGHEAD
%token <str>LTHAN
%token <str>GTHAN
%token <str>LBRACE
%token <str>RBRACE


%type <num> command exp digit math_exp invalid_num text_exp t_exp 
%type <str> word html_statement openB closeB t_OP
%%

command :  newline
	| command newline
	| math_exp newline   
	| command math_exp newline	
	
	| word newline
	| command word newline 
	
	| html_statement newline
	| command html_statement newline
	
	|text_exp newline
	| command text_exp newline
    ;
	
html_statement: TAGIDENT GTHAN word ENDTAGHEAD IDENT GTHAN 
	| TAGIDENT GTHAN html_statement ENDTAGHEAD IDENT GTHAN 
	| html_statement TAGIDENT GTHAN word ENDTAGHEAD IDENT GTHAN 
	| TAGIDENT GTHAN mulline html_statement mulline	ENDTAGHEAD IDENT GTHAN {;}
	;
	
word: IDENT		{$$ = $1; printf("%s\n", $$);}
	;
	
mulline: newline {;}
	|	mulline newline {;}
	;
	

text_exp: openB t_exp closeB {;}
	;
	
openB: LBRACE {
					//memset(global, 0, sizeof(global));
					//memset(curr, 0, sizeof(curr));
					//memset(deleted, 0, sizeof(deleted));
					//memset(temp, 0, sizeof(temp));
					//memset(ops, 0, sizeof(ops));
					//globalC = "";
					//ans = "";
					//ans = strcat(temp, "");
					//globalC = strcat(global, "");
					;
			  }
	;
	
closeB: RBRACE {
				//for(int i = 0; i < strlen(globalC) - 1; i++ ){
				//	currChar = globalC[i];
				//	deleted[i] = currChar;
				//}
				//ans = strcat(ans, deleted);
				//printf("%s\n", ans);
				printf("\n");
				
}
	;


t_exp: t_exp t_OP digit {
							if($1.type == 1 && $3.type == 1){
								//sprintf(curr, "%d", $3.ival);
								//globalC = strcat(globalC, curr);
								printf("%d", $3.ival);
							}
							
							if($1.type == 1 && $3.type == 2){
								//sprintf(curr, "%f", $3.fval);
								//globalC = strcat(globalC, curr);
								printf("%f", $3.fval);
							}
							
							if($1.type == 2 && $3.type == 1){
								//sprintf(curr, "%d", $3.ival);
								//globalC = strcat(globalC, curr);
								printf("%d", $3.ival);
							}
							
							if($1.type == 2 && $3.type == 2){
								//sprintf(curr, "%f", $3.fval);
								//globalC = strcat(globalC, curr);								
								printf("%f", $3.fval);
							}
						}
	
	| digit {
				$$ = $1;
				if($1.type == 1){
					//sprintf(curr, "%d", $1.ival);
					//globalC = strcat(globalC, curr);
					printf("%d", $1.ival);
				}
				else{
					//sprintf(curr, "%f", $1.fval);
					//globalC = strcat(globalC, curr);	
					printf("%f", $1.fval);
				}
				
	} 
	;
	
t_OP: PLUS	{printf("+");}
	|MINUS	{printf("-");}
	|MULT	{printf("*");}
	|DIVIDE	{printf("/");}
	
	
	
math_exp	: EQUALS exp { printf("Expression type = %d\n",$2.type);
							if($2.type == 1){
								printf("Expression of int type single and value: %d\n", $2.ival);
							}
							else{
								printf("Expression of float type single and value: %f\n", $2.fval);
							}
						}

;

exp :	exp PLUS digit 		{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival + $3.ival);
								}
								
								else if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival + $3.fval);
								}
								
								else if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval + $3.ival);
								}
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval + $3.fval);
								}
							}
	| exp MINUS digit   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival - $3.ival);
								}
								
								else if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival - $3.fval);
								}
								
								else if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval - $3.ival);
								}
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval - $3.fval);
								}
							}
	| exp MULT digit   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival * $3.ival);
								}
								
								else if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival * $3.fval);
								}
								
								else if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval * $3.ival);
								}
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval * $3.fval);
								}
							}
	| exp DIVIDE digit   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival / $3.ival);
								}
								
								else if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival / $3.fval);
								}
								
								else if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval / $3.ival);
								}
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval / $3.fval);
								}
							}
	| exp MODULO digit   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival % $3.ival);
								}
							
								/*if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = fmodf((float)$1.ival, $3.fval);
								}*/						
								
								/*if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = fmodf($1.fval, (float)$3.ival);
								} */		
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = fmodf($1.fval, $3.fval);
								}
							}							
	|	digit {$$ = $1;}
    ;
	
digit: INTEGER {$$ = $1; $$.type = $1.type; }
	| FLOAT {$$ = $1; $$.type = $1.type;}
	| invalid_num {printf("Badly formed number\n"); return 1;}
	;





%%

int main()
{ 
  return yyparse();
}


int yyerror(char *s)
{
   fprintf(stderr,"%s\n",s);
   return 0;
}
